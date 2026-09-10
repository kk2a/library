#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include <algorithm>
#include <bit>
#include <cstdint>
#include <memory>

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

inline std::int64_t convolution_dense_work(int n, int m, bool same, bool ntt_friendly) {
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
           + convolution_dense_work(std::max(0, n - 1), deg, false, ntt_friendly);
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
           + convolution_dense_work(std::min(n, deg), deg, false, ntt_friendly);
}

inline std::int64_t polynomial_division_dense_work(int quotient_size, bool ntt_friendly) {
    return inverse_dense_work(quotient_size, ntt_friendly)
           + convolution_dense_work(quotient_size, quotient_size, false, ntt_friendly);
}

inline std::int64_t sqrt_dense_work(int deg, bool ntt_friendly) {
    if (deg <= 1) return 0;
    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));
    // Newton uses an inverse and one product at every level. The implementation
    // computes the complete next power-of-two block even at the last level.
    return (ntt_friendly ? 32 : 156) * evaluation_work(z);
}

inline long double sparse_leading_work(FPSOperation op, long double support_output_pairs) {
    switch (op) {
    case FPSOperation::LOG:
        return 3 * support_output_pairs;
    case FPSOperation::POWER:
    case FPSOperation::SQRT:
        return 4 * support_output_pairs;
    case FPSOperation::CONVOLUTION:
    case FPSOperation::DIVISION:
    case FPSOperation::POLYNOMIAL_DIVISION:
    case FPSOperation::INVERSE:
    case FPSOperation::EXP:
        return 2 * support_output_pairs;
    }
    return 0;
}

inline long double sparse_runtime_factor(FPSOperation op) {
    // Conversion from the field-operation model above to observed running
    // time. Calibrated on powers of two from 256 through 4096 while keeping
    // the threshold conservative when the two implementations are close.
    switch (op) {
    case FPSOperation::POWER:
    case FPSOperation::SQRT:
        return 0.60L;
    case FPSOperation::DIVISION:
    case FPSOperation::POLYNOMIAL_DIVISION:
        return 0.75L;
    case FPSOperation::CONVOLUTION:
        return 1.50L;
    case FPSOperation::LOG:
        return 1.25L;
    case FPSOperation::INVERSE:
        return 0.90L;
    case FPSOperation::EXP:
        return 1.00L;
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
    const int target = deg < 0 ? n : std::max(0, deg);
    std::int64_t nonzero_a = 0, nonzero_b = 0;
    long double pair_work = 0;

    const int limit_a = convolution                       ? n :
                        (division || polynomial_division) ? 0 :
                                                            std::min(n, target);
    for (int i = 0; i < limit_a; ++i) {
        if (a[i] == mint(0)) continue;
        ++nonzero_a;
        if (!convolution && i > 0) {
            const int terms = op == FPSOperation::LOG ? target - 1 - i : target - i;
            if (terms > 0) pair_work += terms;
        }
    }

    const int limit_b = convolution         ? m :
                        division            ? std::min(m, target) :
                        polynomial_division ? m :
                                              0;
    for (int i = 0; i < limit_b; ++i) {
        if (b[i] == mint(0)) continue;
        ++nonzero_b;
        if (division && i > 0) pair_work += target - i;
        if (polynomial_division && i + 1 < m) {
            const int terms = target - (m - 1 - i);
            if (terms > 0) pair_work += terms;
        }
    }

    if (convolution) { pair_work = static_cast<long double>(nonzero_a) * nonzero_b; }

    long double dense_work = 0;
    switch (op) {
    case FPSOperation::CONVOLUTION:
        dense_work = fps::sparsity_detail::convolution_dense_work(
            n, m, std::addressof(a) == std::addressof(b), is_ntt_friendly);
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

    // Count the leading field operations executed for each support/output
    // pair. Linear scans, initialization and per-output normalization are
    // intentionally omitted on both the sparse and dense sides.
    const long double sparse_work = fps::sparsity_detail::sparse_leading_work(op, pair_work);
    return dense_work > fps::sparsity_detail::sparse_runtime_factor(op) * sparse_work;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
