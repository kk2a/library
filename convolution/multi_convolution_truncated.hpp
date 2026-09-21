#ifndef KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
#define KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP 1

#include <vector>

#include "../type_traits/fps.hpp"
#include "convolution.hpp"
#include "convolution_arb.hpp"

namespace kk2 {

// reference: https://rushcheyo.blog.uoj.ac/blog/6547
// 日本語:
// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
namespace detail {

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated_ntt(FPS &a, const FPS &b, const std::vector<int> &base) {
    int n = int(a.size());
    if (!n) return a;
    int k = base.size();
    if (!k) return inplace_convolution(a, b);
    // chi[i] = \sum_{j} \floor(i / (base[0]...base[j]))
    std::vector<int> chi(n, 0);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
        chi[i] %= k;
    }
    int z = 1;
    while (z < 2 * n - 1) z <<= 1;
    std::vector<FPS> f(k, FPS(z));
    std::vector<FPS> g(k, FPS(z));
    for (int i = 0; i < n; i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];
    for (auto &x : f) butterfly(x);
    for (auto &x : g) butterfly(x);
    std::vector<mint> tmp(k);
    for (int ii = 0; ii < z; ii++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                tmp[i + j - (i + j >= k ? k : 0)] += f[i][ii] * g[j][ii];
            }
        }
        for (int i = 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};
    }
    for (auto &x : f) butterfly_inv(x);
    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i];
    return a;
}

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated_arb(FPS &a, const FPS &b, const std::vector<int> &base) {
    const int n = int(a.size());
    if (!n) return a;
    const int k = base.size();
    if (!k) return inplace_convolution_arb(a, b);

    // The class index records carries between mixed-radix coordinates.  Without
    // an NTT over the flattened index, convolve every pair of classes and keep
    // the class corresponding to the resulting carry.
    std::vector<int> chi(n, 0);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);
        chi[i] %= k;
    }

    std::vector<FPS> f(k, FPS(n)), g(k, FPS(n)), result(k, FPS(n));
    for (int i = 0; i < n; i++) {
        f[chi[i]][i] = a[i];
        g[chi[i]][i] = b[i];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            FPS product = dense_convolution_arb(f[i], g[j], n);
            FPS &target = result[(i + j) % k];
            for (int p = 0; p < static_cast<int>(product.size()); p++) target[p] += product[p];
        }
    }
    for (int i = 0; i < n; i++) a[i] = result[chi[i]][i];
    return a;
}

} // namespace detail

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated(FPS &a, const FPS &b, const std::vector<int> &base) {
    if constexpr (fps::NTTFriendlyFormalPowerSeries<FPS>) {
        return detail::inplace_multi_convolution_truncated_ntt(a, b, base);
    } else {
        static_assert(fps::ArbitraryModulusFormalPowerSeries<FPS>);
        return detail::inplace_multi_convolution_truncated_arb(a, b, base);
    }
}

template <class FPS, class mint = typename FPS::value_type>
FPS multi_convolution_truncated(const FPS &a, const FPS &b, const std::vector<int> &base) {
    FPS result = a;
    inplace_multi_convolution_truncated<FPS, mint>(result, b, base);
    return result;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
