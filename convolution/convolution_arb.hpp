#ifndef KK2_CONVOLUTION_CONVOLUTION_ARB_HPP
#define KK2_CONVOLUTION_CONVOLUTION_ARB_HPP 1

#include <algorithm>
#include <vector>

#include "../math_mod/garner.hpp"
#include "../modint/mont.hpp"
#include "convolution.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_arb(FPS &a, const FPS &b, bool detect_sparsity = true) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) {
        a.clear();
        return a;
    }
    if (detect_sparsity && is_sparse_operation(FPSOperation::CONVOLUTION, 0, a, b)) {
        std::vector<int> nza, nzb;
        nza.reserve(std::ranges::count_if(a, [](const mint &x) { return x != mint(0); }));
        nzb.reserve(std::ranges::count_if(b, [](const mint &x) { return x != mint(0); }));
        for (int i = 0; i < n; i++)
            if (a[i] != mint(0)) nza.push_back(i);
        for (int i = 0; i < m; i++)
            if (b[i] != mint(0)) nzb.push_back(i);
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

    std::vector<long long> a0(n), b0(m);
    for (int i = 0; i < n; i++) a0[i] = a[i].val();
    for (int i = 0; i < m; i++) b0[i] = b[i].val();
    auto a1 = std::vector<mint1>(a0.begin(), a0.end());
    auto b1 = std::vector<mint1>(b0.begin(), b0.end());
    convolution(a1, b1, false);
    auto a2 = std::vector<mint2>(a0.begin(), a0.end());
    auto b2 = std::vector<mint2>(b0.begin(), b0.end());
    convolution(a2, b2, false);
    auto a3 = std::vector<mint3>(a0.begin(), a0.end());
    auto b3 = std::vector<mint3>(b0.begin(), b0.end());
    convolution(a3, b3, false);
    const std::vector<long long> ps = {MOD1, MOD2, MOD3, mint::getmod()};
    a.resize(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        a[i] = mint(garner({a1[i].val(), a2[i].val(), a3[i].val()}, ps));
    }
    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_ARB_HPP
