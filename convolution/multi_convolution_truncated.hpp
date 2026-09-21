#ifndef KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
#define KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP 1

#include <utility>
#include <vector>

#include "convolution.hpp"

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

} // namespace detail

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated(FPS &a, const FPS &b, const std::vector<int> &base) {
    return detail::inplace_multi_convolution_truncated_ntt(a, b, base);
}

template <class FPS, class mint = typename FPS::value_type>
FPS &inplace_multi_convolution_truncated_sparse(FPS &a,
                                                const FPS &b,
                                                const std::vector<int> &base) {
    const int n = int(a.size());
    if (!n) return a;
    if (base.empty()) {
        a[0] *= b[0];
        return a;
    }

    FPS result(n);
    for (int i = 0; i < n; ++i) {
        int x = i;
        std::vector<int> lhs_index(base.size());
        for (int d = 0; d < (int)base.size(); ++d) {
            lhs_index[d] = x % base[d];
            x /= base[d];
        }
        if (a[i] == mint(0)) continue;
        for (int j = 0; j < n; ++j) {
            if (b[j] == mint(0)) continue;
            int y = j, index = 0, stride = 1;
            bool in_range = true;
            for (int d = 0; d < (int)base.size(); ++d) {
                const int coordinate = lhs_index[d] + y % base[d];
                y /= base[d];
                if (coordinate >= base[d]) in_range = false;
                index += coordinate * stride;
                stride *= base[d];
            }
            if (in_range && index < n) result[index] += a[i] * b[j];
        }
    }
    a = std::move(result);
    return a;
}

template <class FPS, class mint = typename FPS::value_type>
FPS multi_convolution_truncated(const FPS &a, const FPS &b, const std::vector<int> &base) {
    FPS result = a;
    inplace_multi_convolution_truncated<FPS, mint>(result, b, base);
    return result;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
