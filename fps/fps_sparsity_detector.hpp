#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include "../bit/bitcount.hpp"

namespace kk2 {

enum class FPSOperation { CONVOLUTION, EXP };

template <class FPS, class mint = typename FPS::value_type> bool
is_sparse_operation(FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS()) {
    int n = a.size(), m = b.size();
    long long not_zero_a = 0, not_zero_b = 0;
    bool same = a == b;
    int lg = msb(n + m) + 1;
    for (int i = 0; i < n; i++) not_zero_a += a[i] != mint(0);
    for (int i = 0; i < m; i++) not_zero_b += b[i] != mint(0);

    if (op == FPSOperation::CONVOLUTION) {
        return (n + m) * lg * (is_ntt_friendly ? 3.42 : 20.0) * (same ? 0.5 : 1)
               > double(not_zero_a) * not_zero_b;
    }
    if (op == FPSOperation::EXP) {
        return n * lg * (is_ntt_friendly ? 8.2 : 60.0) > double(n) * not_zero_a;
    }
    return false;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
