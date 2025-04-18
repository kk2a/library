#ifndef KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
#define KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP 1

#include <vector>

#include "convolution.hpp"

namespace kk2 {

// reference: https://rushcheyo.blog.uoj.ac/blog/6547
// 日本語:
// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
template <class FPS, class mint = typename FPS::value_type>
FPS multi_convolution_truncated(FPS &a, const FPS &b, const std::vector<int> &base) {
    int n = int(a.size());
    if (!n) return {};
    int k = base.size();
    if (!k) return convolution(a, b);
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

} // namespace kk2

#endif // KK2_CONVOLUTION_MULTI_CONVOLUTION_TRUNCATED_HPP
