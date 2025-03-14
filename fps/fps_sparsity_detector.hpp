#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include "../bit/bitcount.hpp"

namespace kk2 {

enum class FPSOperation { CONVOLUTION };

template <class FPS, class mint = typename FPS::value_type>
bool is_sparse_operation(FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b) {
    int n = a.size(), m = b.size();
    long long not_zero_a = 0, not_zero_b = 0;
    for (int i = 0; i < n; i++) not_zero_a += a[i] != mint(0);
    for (int i = 0; i < m; i++) not_zero_b += b[i] != mint(0);

    if (op == FPSOperation::CONVOLUTION) {
        // NTT-friendly -> 3 * FFT
        // Arbitrary    -> 9 * FFT
        // Sparse       -> not_zero(a) * not_zero(b)
        int lg = msb(n + m) / 2 + 1;
        return (n + m) * lg * (is_ntt_friendly ? 3 : 7) > not_zero_a * not_zero_b;
    }
    return false;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
