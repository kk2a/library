#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP 1

#include <algorithm>
#include <ranges>

#include "../bit/bitcount.hpp"

namespace kk2 {

enum class FPSOperation { CONVOLUTION, LOG, INVERSE, EXP };

template <class FPS, class mint = typename FPS::value_type> bool
is_sparse_operation(FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS()) {
    int n = a.size(), m = b.size();
    if (n + m == 0) return false;

    const long long not_zero_a = std::ranges::count_if(a, [](const auto &x) { return x != mint(0); });
    const long long not_zero_b = std::ranges::count_if(b, [](const auto &x) { return x != mint(0); });
    bool same = a == b;
    int lg = msb(n + m) + 1;

    if (op == FPSOperation::CONVOLUTION) {
        return (n + m) * lg * (is_ntt_friendly ? 3.42 : 20.0) * (same ? 0.5 : 1)
               > double(not_zero_a) * not_zero_b;
    }

    if (op == FPSOperation::LOG || op == FPSOperation::INVERSE || op == FPSOperation::EXP) {
        return n * lg * (is_ntt_friendly ? 8.2 : 60.0) > double(n) * not_zero_a;
    }
    return false;
}

} // namespace kk2

#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP
