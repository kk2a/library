#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include <algorithm>
#include <bit>
#include <cstdint>
#include <memory>
#include <ranges>

namespace kk2 {

enum class FPSOperation {
    CONVOLUTION,
    LOG,
    POWER,
    DIVISION,
    POLYNOMIAL_DIVISION,
    INVERSE,
    EXP,
    SQRT
};

namespace fps::sparsity_detail {

// E(n): the leading FFT evaluation cost, up to the common field-operation
// constant that cancels when dense and sparse leading terms are compared.
inline std::int64_t evaluation_work(int n) {
    if (n <= 1) return 1;
    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));
    return static_cast<std::int64_t>(z) * std::countr_zero(z);
}

inline int transform_size(int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));
}

inline std::int64_t convolution_dense_work(int n, int m, int deg, bool same, bool ntt_friendly) {
    n = std::min(n, deg);
    m = std::min(m, deg);
    const int z = transform_size(n, m);
    if (z == 0) return 0;

    // A different pair needs two forward and one inverse transform. Squaring
    // reuses the forward transform and needs only one forward transform.
    const int transforms = same ? 2 : 3;
    // Arbitrary-modulus convolution uses three NTT-friendly moduli.
    const int moduli = ntt_friendly ? 1 : 3;
    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);
}

inline std::int64_t inverse_dense_work(int deg, bool ntt_friendly) {
    if (deg <= 1) return 0;
    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));
    // NTT-friendly uses five transforms per Newton level, whose geometric
    // sum has leading term 10 E(z). The arbitrary-modulus implementation
    // performs two fresh convolutions per level, giving 60 E(z).
    return (ntt_friendly ? 10 : 60) * evaluation_work(z);
}

inline std::int64_t log_dense_work(int n, int deg, bool ntt_friendly) {
    return inverse_dense_work(deg, ntt_friendly)
           + convolution_dense_work(std::max(0, n - 1), deg, deg, false, ntt_friendly);
}

inline long double exp_dense_work(int deg, bool ntt_friendly) {
    if (deg <= 1) return 0;
    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));
    if (ntt_friendly) {
        if (deg <= 2) return 0;
        // Bostan--Schost, Theorem 1: (33/2) E(z) + (97/4) z.  Only
        // the leading E(z) term matters for the sparsity threshold.
        return 16.5L * evaluation_work(z);
    }
    // FPSArb recomputes a logarithm and a product at every Newton level.
    return 192 * evaluation_work(z);
}

inline long double power_dense_work(int n, int deg, bool ntt_friendly) {
    return log_dense_work(n, deg, ntt_friendly) + exp_dense_work(deg, ntt_friendly);
}

inline std::int64_t division_dense_work(int n, int deg, bool ntt_friendly) {
    return inverse_dense_work(deg, ntt_friendly)
           + convolution_dense_work(std::min(n, deg), deg, deg, false, ntt_friendly);
}

inline std::int64_t polynomial_division_dense_work(int quotient_size, bool ntt_friendly) {
    return inverse_dense_work(quotient_size, ntt_friendly)
           + convolution_dense_work(
               quotient_size, quotient_size, quotient_size, false, ntt_friendly);
}

inline std::int64_t sqrt_dense_work(int deg, bool ntt_friendly) {
    if (deg <= 1) return 0;
    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));
    // Newton uses an inverse and one product at every level. The implementation
    // computes the complete next power-of-two block even at the last level.
    return (ntt_friendly ? 32 : 156) * evaluation_work(z);
}

inline long double
sparse_work(FPSOperation op, int target, std::int64_t nonzero_a, std::int64_t nonzero_b) {
    switch (op) {
    case FPSOperation::CONVOLUTION:
        return static_cast<long double>(nonzero_a) * nonzero_b;
    case FPSOperation::DIVISION:
    case FPSOperation::POLYNOMIAL_DIVISION:
        return static_cast<long double>(target) * nonzero_b;
    case FPSOperation::LOG:
    case FPSOperation::POWER:
    case FPSOperation::INVERSE:
    case FPSOperation::EXP:
    case FPSOperation::SQRT:
        return static_cast<long double>(target) * nonzero_a;
    }
    return 0;
}

inline long double sparse_work_constant(FPSOperation op, bool ntt_friendly) {
    // Calibrated against the simplified sparse-work model at degrees 1024
    // and 4096.  Values are rounded upward near the measured crossover so a
    // close decision favors the dense implementation.
    switch (op) {
    case FPSOperation::CONVOLUTION:
        return ntt_friendly ? 0.90L : 0.55L;
    case FPSOperation::DIVISION:
    case FPSOperation::POLYNOMIAL_DIVISION:
        return ntt_friendly ? 0.90L : 0.40L;
    case FPSOperation::LOG:
        return ntt_friendly ? 2.70L : 1.00L;
    case FPSOperation::POWER:
        return ntt_friendly ? 1.35L : 0.70L;
    case FPSOperation::INVERSE:
        return ntt_friendly ? 1.00L : 0.40L;
    case FPSOperation::EXP:
        return ntt_friendly ? 1.05L : 0.45L;
    case FPSOperation::SQRT:
        return ntt_friendly ? 1.40L : 0.65L;
    }
    return 1.00L;
}

} // namespace fps::sparsity_detail

template <class FPS, class mint = typename FPS::value_type>
bool is_sparse_operation(
    FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(), int deg = -1) {
    const int n = a.size(), m = b.size();
    if (n + m == 0) return false;

    const bool convolution = op == FPSOperation::CONVOLUTION;
    const bool division = op == FPSOperation::DIVISION;
    const bool polynomial_division = op == FPSOperation::POLYNOMIAL_DIVISION;
    const int requested = deg < 0 ? (convolution ? std::max(0, n + m - 1) : n) : std::max(0, deg);
    const int target = convolution ? std::min(requested, std::max(0, n + m - 1)) : requested;
    const int limit_a = convolution                       ? std::min(n, target) :
                        (division || polynomial_division) ? 0 :
                                                            std::min(n, target);
    const int limit_b = convolution         ? std::min(m, target) :
                        division            ? std::min(m, target) :
                        polynomial_division ? m :
                                              0;
    const auto is_nonzero = [](const mint &x) {
        return x != mint(0);
    };
    const std::int64_t nonzero_a = std::ranges::count_if(a | std::views::take(limit_a), is_nonzero);
    const std::int64_t nonzero_b = std::ranges::count_if(b | std::views::take(limit_b), is_nonzero);

    long double dense_work = 0;
    switch (op) {
    case FPSOperation::CONVOLUTION:
        dense_work = fps::sparsity_detail::convolution_dense_work(
            n, m, target, std::addressof(a) == std::addressof(b), is_ntt_friendly);
        break;
    case FPSOperation::LOG:
        dense_work = fps::sparsity_detail::log_dense_work(n, target, is_ntt_friendly);
        break;
    case FPSOperation::POWER:
        dense_work = fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);
        break;
    case FPSOperation::DIVISION:
        dense_work = fps::sparsity_detail::division_dense_work(n, target, is_ntt_friendly);
        break;
    case FPSOperation::POLYNOMIAL_DIVISION:
        dense_work = fps::sparsity_detail::polynomial_division_dense_work(target, is_ntt_friendly);
        break;
    case FPSOperation::INVERSE:
        dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);
        break;
    case FPSOperation::EXP:
        dense_work = fps::sparsity_detail::exp_dense_work(target, is_ntt_friendly);
        break;
    case FPSOperation::SQRT:
        dense_work = fps::sparsity_detail::sqrt_dense_work(target, is_ntt_friendly);
        break;
    }

    const long double sparse_work =
        fps::sparsity_detail::sparse_work(op, target, nonzero_a, nonzero_b);
    return dense_work
           > fps::sparsity_detail::sparse_work_constant(op, is_ntt_friendly) * sparse_work;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
