#ifndef KK2_CONVOLUTION_CONVOLUTION_ARB_HPP
#define KK2_CONVOLUTION_CONVOLUTION_ARB_HPP 1

#include <algorithm>
#include <vector>

#include "../math_mod/garner.hpp"
#include "../modint/mont.hpp"
#include "convolution.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_dense_convolution_arb(FPS &a, const FPS &b, int deg = -1) {
    const int original_a_size = a.size(), original_b_size = b.size();
    if (!original_a_size || !original_b_size) {
        a.clear();
        return a;
    }
    if (deg == -1) deg = original_a_size + original_b_size - 1;
    const int target = std::min(std::max(0, deg), original_a_size + original_b_size - 1);
    if (target == 0) {
        a.clear();
        return a;
    }
    const int n = std::min(original_a_size, target);
    const int m = std::min(original_b_size, target);
    static constexpr long long MOD1 = 754974721; // 2^24
    static constexpr long long MOD2 = 167772161; // 2^25
    static constexpr long long MOD3 = 469762049; // 2^26
    using mint1 = LazyMontgomeryModInt<MOD1>;
    using mint2 = LazyMontgomeryModInt<MOD2>;
    using mint3 = LazyMontgomeryModInt<MOD3>;

    std::vector<long long> a0(n), b0(m);
    for (int i = 0; i < n; i++) a0[i] = a[i].val();
    for (int i = 0; i < m; i++) b0[i] = b[i].val();
    auto a1 = std::vector<mint1>(a0.begin(), a0.end());
    auto b1 = std::vector<mint1>(b0.begin(), b0.end());
    inplace_dense_convolution(a1, b1, target);
    auto a2 = std::vector<mint2>(a0.begin(), a0.end());
    auto b2 = std::vector<mint2>(b0.begin(), b0.end());
    inplace_dense_convolution(a2, b2, target);
    auto a3 = std::vector<mint3>(a0.begin(), a0.end());
    auto b3 = std::vector<mint3>(b0.begin(), b0.end());
    inplace_dense_convolution(a3, b3, target);
    const std::vector<long long> ps = {MOD1, MOD2, MOD3, mint::getmod()};
    a.resize(target);
    for (int i = 0; i < target; i++) {
        a[i] = mint(garner({a1[i].val(), a2[i].val(), a3[i].val()}, ps));
    }
    return a;
}

template <class FPS> FPS dense_convolution_arb(const FPS &a, const FPS &b, int deg = -1) {
    FPS result = a;
    inplace_dense_convolution_arb(result, b, deg);
    return result;
}

template <class FPS> FPS sparse_convolution_arb(const FPS &a, const FPS &b, int deg = -1) {
    return sparse_convolution(a, b, deg);
}

template <class FPS> FPS &inplace_sparse_convolution_arb(FPS &a, const FPS &b, int deg = -1) {
    return inplace_sparse_convolution(a, b, deg);
}

template <class FPS> FPS &inplace_convolution_arb(FPS &a, const FPS &b, int deg = -1) {
    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION, false, a, b, deg);
    if (use_sparse) return inplace_sparse_convolution_arb(a, b, deg);
    return inplace_dense_convolution_arb(a, b, deg);
}

template <class FPS> FPS convolution_arb(const FPS &a, const FPS &b, int deg = -1) {
    if (is_sparse_operation(FPSOperation::CONVOLUTION, false, a, b, deg))
        return sparse_convolution_arb(a, b, deg);
    return dense_convolution_arb(a, b, deg);
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_ARB_HPP
