#ifndef KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_ARB_HPP
#define KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_ARB_HPP 1

#include <vector>

#include "../type_traits/fps.hpp"
#include "convolution_arb.hpp"

namespace kk2 {

namespace detail {

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated_arb_impl(FPS &a,
                                                  const FPS &b,
                                                  const std::vector<int> &base) {
    const int n = int(a.size());
    if (!n) return a;
    const int k = base.size();
    if (!k) return inplace_convolution_arb(a, b);

    // The class index records carries between mixed-radix coordinates. Without
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
FPS &inplace_multi_convolution_truncated_arb(FPS &a, const FPS &b, const std::vector<int> &base) {
    return detail::inplace_multi_convolution_truncated_arb_impl(a, b, base);
}

template <class FPS, class mint = typename FPS::value_type>
FPS multi_convolution_truncated_arb(const FPS &a, const FPS &b, const std::vector<int> &base) {
    FPS result = a;
    inplace_multi_convolution_truncated_arb(result, b, base);
    return result;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_ARB_HPP
