#ifndef KK2_CONVOLUTION_CONVOLUTION_INT_HPP
#define KK2_CONVOLUTION_CONVOLUTION_INT_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

#include "../fps/fps_sparsity_detector.hpp"
#include "../math_mod/garner.hpp"
#include "../modint/mont.hpp"
#include "convolution.hpp"

namespace kk2 {

template <class FPS> FPS sparse_convolution_int(const FPS &a, const FPS &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    std::vector<int> nonzero_a, nonzero_b;
    nonzero_a.reserve(std::ranges::count_if(a, [](const auto &x) { return x != 0; }));
    nonzero_b.reserve(std::ranges::count_if(b, [](const auto &x) { return x != 0; }));
    for (int i = 0; i < n; ++i)
        if (a[i] != 0) nonzero_a.push_back(i);
    for (int i = 0; i < m; ++i)
        if (b[i] != 0) nonzero_b.push_back(i);
    FPS result(n + m - 1);
    for (int i : nonzero_a)
        for (int j : nonzero_b) result[i + j] += a[i] * b[j];
    return result;
}

template <class FPS> FPS &inplace_sparse_convolution_int(FPS &a, const FPS &b) {
    return a = sparse_convolution_int(std::as_const(a), b);
}

template <class FPS> FPS &inplace_dense_convolution_int(FPS &a, const FPS &b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) {
        a.clear();
        return a;
    }

    static constexpr long long MOD1 = 754974721; // 2^24
    static constexpr long long MOD2 = 167772161; // 2^25
    static constexpr long long MOD3 = 469762049; // 2^26
    using mint1 = LazyMontgomeryModInt<MOD1>;
    using mint2 = LazyMontgomeryModInt<MOD2>;
    using mint3 = LazyMontgomeryModInt<MOD3>;

    auto a1 = std::vector<mint1>(a.begin(), a.end());
    auto b1 = std::vector<mint1>(b.begin(), b.end());
    inplace_dense_convolution(a1, b1);
    auto a2 = std::vector<mint2>(a.begin(), a.end());
    auto b2 = std::vector<mint2>(b.begin(), b.end());
    inplace_dense_convolution(a2, b2);
    auto a3 = std::vector<mint3>(a.begin(), a.end());
    auto b3 = std::vector<mint3>(b.begin(), b.end());
    inplace_dense_convolution(a3, b3);
    const std::vector<long long> ps = {MOD1, MOD2, MOD3, 1ll << 31};
    a.resize(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        a[i] = garner({a1[i].val(), a2[i].val(), a3[i].val()}, ps);
    }
    return a;
}

template <class FPS> FPS dense_convolution_int(const FPS &a, const FPS &b) {
    FPS result = a;
    inplace_dense_convolution_int(result, b);
    return result;
}

template <class FPS> FPS &inplace_convolution_int(FPS &a, const FPS &b) {
    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION, false, a, b);
    if (use_sparse) return inplace_sparse_convolution_int(a, b);
    return inplace_dense_convolution_int(a, b);
}

template <class FPS> FPS convolution_int(const FPS &a, const FPS &b) {
    if (is_sparse_operation(FPSOperation::CONVOLUTION, false, a, b))
        return sparse_convolution_int(a, b);
    return dense_convolution_int(a, b);
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_INT_HPP
