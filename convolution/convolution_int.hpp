#ifndef KK2_CONVOLUTION_CONVOLUTION_INT_HPP
#define KK2_CONVOLUTION_CONVOLUTION_INT_HPP 1

#include <algorithm>
#include <vector>

#include "../fps/fps_sparsity_detector.hpp"
#include "../math_mod/garner.hpp"
#include "../modint/mont.hpp"
#include "convolution.hpp"

namespace kk2 {

template <class FPS> FPS convolution_int(FPS &a, const FPS &b, bool detect_sparsity = true) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (detect_sparsity && is_sparse_operation(FPSOperation::CONVOLUTION, 0, a, b)) {
        std::vector<int> nza, nzb;
        nza.reserve(std::ranges::count_if(a, [](const auto &x) { return x != 0; }));
        nzb.reserve(std::ranges::count_if(b, [](const auto &x) { return x != 0; }));
        for (int i = 0; i < n; i++)
            if (a[i] != 0) nza.push_back(i);
        for (int i = 0; i < m; i++)
            if (b[i] != 0) nzb.push_back(i);
        FPS res(n + m - 1);
        for (int i : nza)
            for (int j : nzb) res[i + j] += a[i] * b[j];
        return a = res;
    }

    static constexpr long long MOD1 = 754974721; // 2^24
    static constexpr long long MOD2 = 167772161; // 2^25
    static constexpr long long MOD3 = 469762049; // 2^26
    using mint1 = LazyMontgomeryModInt<MOD1>;
    using mint2 = LazyMontgomeryModInt<MOD2>;
    using mint3 = LazyMontgomeryModInt<MOD3>;

    auto a1 = std::vector<mint1>(a.begin(), a.end());
    auto b1 = std::vector<mint1>(b.begin(), b.end());
    convolution(a1, b1, false);
    auto a2 = std::vector<mint2>(a.begin(), a.end());
    auto b2 = std::vector<mint2>(b.begin(), b.end());
    convolution(a2, b2, false);
    auto a3 = std::vector<mint3>(a.begin(), a.end());
    auto b3 = std::vector<mint3>(b.begin(), b.end());
    convolution(a3, b3, false);
    const std::vector<long long> ps = {MOD1, MOD2, MOD3, 1ll << 31};
    a.resize(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        a[i] = garner({a1[i].val(), a2[i].val(), a3[i].val()}, ps);
    }
    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_INT_HPP
