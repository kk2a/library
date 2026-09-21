#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_INVERSE_HPP
#define KK2_FPS_OPERATIONS_MULTIVARIATE_INVERSE_HPP 1

#include <algorithm>
#include <cassert>
#include <ranges>
#include <utility>
#include <vector>

#include "../../../type_traits/fps.hpp"
#include "multiplication.hpp"

namespace kk2::fps::operations {

template <Multivariate FPS> FPS dense_inv(const FPS &f) {
    using mint = typename FPS::value_type;
    using fps_type = typename FPS::fps;
    assert(!f.f.empty() && f.f[0] != mint(0));
    if (f.base.empty()) return FPS(f.base, fps_type{f.f[0].inv()});

    if constexpr (ArbitraryModulusFormalPowerSeries<fps_type>) {
        const int n = f.f.size();
        FPS result(f.base, fps_type(n));
        result.f[0] = f.f[0].inv();
        for (int d = 1; d < n; d <<= 1) {
            const int precision = std::min(2 * d, n);
            FPS lhs(f.base, fps_type(precision));
            FPS rhs(f.base, fps_type(precision));
            std::copy_n(f.f.begin(), precision, lhs.f.begin());
            std::copy_n(result.f.begin(), std::min(d, precision), rhs.f.begin());

            FPS correction(f.base, fps_type(precision));
            correction += mint(2);
            correction -= dense_mul(lhs, rhs);
            inplace_dense_mul(rhs, correction);
            std::copy(rhs.f.begin() + d, rhs.f.end(), result.f.begin() + d);
        }
        return result;
    }

    const int n = f.f.size(), k = f.base.size();
    int z = 1;
    while (z < 2 * n - 1) z <<= 1;
    std::vector<int> chi(z);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < k - 1; j++) chi[i] += (x /= f.base[j]);
        chi[i] %= k;
    }
    auto naive_and_dot = [&k](const std::vector<fps_type> &a,
                              const std::vector<fps_type> &b,
                              std::vector<fps_type> &c) -> void {
        std::vector<mint> tmp(k);
        for (int ii = 0; ii < static_cast<int>(a[0].size()); ii++) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];
                }
            }
            for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};
        }
    };

    // Reference: https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
    // Let g_k := f_k^{-1} mod x^k, deg g_k < k. Then
    // g_1 = f_0^{-1}, g_{2k} = 2g_k - g_k^2 f mod x^{2k}.
    fps_type g(z);
    g[0] = f.f[0].inv();
    for (int d = 1; d < n; d <<= 1) {
        std::vector<fps_type> a(k, fps_type(2 * d)), b(k, fps_type(2 * d)), c(k, fps_type(2 * d));
        for (int i = 0; i < std::min(n, 2 * d); i++) a[chi[i]][i] = f.f[i];
        for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];
        for (auto &x : a) x.but();
        for (auto &x : b) x.but();
        naive_and_dot(a, b, c);
        for (auto &x : c) x.ibut();

        for (auto &x : a) std::ranges::fill(x, mint(0));
        for (int i = d; i < 2 * d; i++) a[chi[i]][i] = c[chi[i]][i];
        for (auto &x : a) x.but();
        naive_and_dot(a, b, c);
        for (auto &x : c) x.ibut();
        for (int i = d; i < 2 * d; i++) g[i] = -c[chi[i]][i];
    }
    FPS result = f;
    result.f = fps_type(std::begin(g), std::begin(g) + n);
    return result;
}

template <Multivariate FPS> FPS &inplace_dense_inv(FPS &f) {
    return f = dense_inv(std::as_const(f));
}

template <Multivariate FPS> FPS sparse_inv(const FPS &f) {
    using mint = typename FPS::value_type;
    assert(!f.f.empty() && f.f[0] != mint(0));
    const int n = f.f.size();
    FPS result(f.base, typename FPS::fps(n));
    result.f[0] = f.f[0].inv();
    for (int i = 1; i < n; ++i) {
        int x = i;
        std::vector<int> target(f.base.size());
        for (int d = 0; d < static_cast<int>(f.base.size()); ++d) {
            target[d] = x % f.base[d];
            x /= f.base[d];
        }

        mint coefficient = 0;
        for (int j = 1; j < n; ++j) {
            if (f.f[j] == mint(0)) continue;
            int y = j, complement = 0, stride = 1;
            bool in_range = true;
            for (int d = 0; d < static_cast<int>(f.base.size()); ++d) {
                const int coordinate = y % f.base[d];
                y /= f.base[d];
                if (coordinate > target[d]) {
                    in_range = false;
                    break;
                }
                complement += (target[d] - coordinate) * stride;
                stride *= f.base[d];
            }
            if (in_range) coefficient += f.f[j] * result.f[complement];
        }
        result.f[i] = -coefficient * result.f[0];
    }
    return result;
}

template <Multivariate FPS> FPS &inplace_sparse_inv(FPS &f) {
    return f = sparse_inv(std::as_const(f));
}

template <Multivariate FPS> FPS inv(const FPS &f) { return dense_inv(f); }

template <Multivariate FPS> FPS &inplace_inv(FPS &f) { return inplace_dense_inv(f); }

} // namespace kk2::fps::operations

#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_INVERSE_HPP
