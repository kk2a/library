#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include <algorithm>
#include <bit>
#include <cstdint>

namespace kk2 {

enum class FPSOperation { CONVOLUTION, LOG, INVERSE, EXP };

namespace fps::sparsity_detail {

// The number of butterfly-level operations in one transform of size n.
inline std::int64_t ntt_work(int n) {
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
    return static_cast<std::int64_t>(transforms) * moduli * ntt_work(z);
}

inline std::int64_t inverse_dense_work(int deg, bool ntt_friendly) {
    std::int64_t work = 0;
    for (int d = 1; d < deg; d <<= 1) {
        if (ntt_friendly) {
            // f.but, g.but, f.ibut, f.but, f.ibut
            work += 5 * ntt_work(2 * d);
        } else {
            // (res * res) and f * (...) in the arbitrary-modulus Newton step.
            work += convolution_dense_work(2 * d, 2 * d, true, false);
            work += convolution_dense_work(2 * d, 2 * d, false, false);
        }
    }
    return work;
}

inline std::int64_t log_dense_work(int n, int deg, bool ntt_friendly) {
    return inverse_dense_work(deg, ntt_friendly)
           + convolution_dense_work(std::max(0, n - 1), deg, false, ntt_friendly);
}

inline std::int64_t exp_dense_work(int deg, bool ntt_friendly) {
    std::int64_t work = 0;
    if (ntt_friendly) {
        for (int m = 2; m < deg; m <<= 1) {
            // Five transforms have size 2m and three have size m.
            work += 5 * ntt_work(2 * m) + 3 * ntt_work(m);
        }
    } else {
        // The arbitrary-modulus implementation performs a convolution and a
        // logarithm in each Newton step.
        for (int m = 1; m < deg; m <<= 1) {
            work += convolution_dense_work(m, 2 * m, false, false);
            work += log_dense_work(m, 2 * m, false);
        }
    }
    return work;
}

// NTT work overestimates the useful work for small transforms. These factors
// are deliberately operation-specific and are calibrated against the direct
// implementations; they make the sparse path conservative for small sizes.
inline long double dense_scale(FPSOperation op) {
    switch (op) {
    case FPSOperation::CONVOLUTION: return 0.50L;
    case FPSOperation::LOG: return 0.40L;
    case FPSOperation::INVERSE: return 1.00L;
    case FPSOperation::EXP: return 0.75L;
    }
    return 1.0L;
}

inline long double sparse_scale(FPSOperation op) {
    switch (op) {
    case FPSOperation::CONVOLUTION: return 1.00L;
    // These recurrences perform more than one modular multiplication per
    // support term, unlike sparse convolution.
    case FPSOperation::LOG: return 2.00L;
    case FPSOperation::INVERSE: return 2.00L;
    case FPSOperation::EXP: return 2.00L;
    }
    return 1.0L;
}

} // namespace fps::sparsity_detail

template <class FPS, class mint = typename FPS::value_type>
bool is_sparse_operation(FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(),
                         int deg = -1) {
    const int n = a.size(), m = b.size();
    if (n + m == 0) return false;

    const bool convolution = op == FPSOperation::CONVOLUTION;
    const int target = deg < 0 ? n : std::max(0, deg);
    std::int64_t nonzero_a = 0, nonzero_b = 0;
    long double sparse_work = 0;

    const int limit_a = convolution ? n : std::min(n, target);
    for (int i = 0; i < limit_a; ++i) {
        if (a[i] == mint(0)) continue;
        ++nonzero_a;
        if (!convolution && i > 0) {
            const int terms = op == FPSOperation::LOG ? target - 1 - i : target - i;
            if (terms > 0) sparse_work += terms;
        }
    }

    const int limit_b = convolution ? m : 0;
    for (int i = 0; i < limit_b; ++i) {
        if (b[i] != mint(0)) ++nonzero_b;
    }

    if (convolution) {
        sparse_work = static_cast<long double>(nonzero_a) * nonzero_b;
        // The sparse implementation scans both inputs and initializes the
        // result in addition to the nonzero pair products.
        sparse_work += 2.0L * (n + m);
    } else {
        // The sparse implementations scan the complete input to build their
        // support list. This is additional work after the detector itself.
        sparse_work += n;
    }

    std::int64_t dense_work = 0;
    switch (op) {
    case FPSOperation::CONVOLUTION:
        dense_work = fps::sparsity_detail::convolution_dense_work(n, m, a == b, is_ntt_friendly);
        break;
    case FPSOperation::LOG:
        dense_work = fps::sparsity_detail::log_dense_work(n, target, is_ntt_friendly);
        break;
    case FPSOperation::INVERSE:
        dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);
        break;
    case FPSOperation::EXP:
        dense_work = fps::sparsity_detail::exp_dense_work(target, is_ntt_friendly);
        break;
    }

    return fps::sparsity_detail::dense_scale(op) * dense_work
           > fps::sparsity_detail::sparse_scale(op) * sparse_work;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
