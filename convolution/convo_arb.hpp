#ifndef CONVO_ARB_HPP
#define CONVO_ARB_HPP 1

#include "../modint/mont.hpp"
#include "convolution.hpp"
#include "../fps/fps.hpp"
#include "../math_mod/garner.hpp"

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_arb(FPS& a, FPS b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    static constexpr long long MOD1 = 754974721;  // 2^24
    static constexpr long long MOD2 = 167772161;  // 2^25
    static constexpr long long MOD3 = 469762049;  // 2^26
    using mint1 = LazyMontgomeryModInt<MOD1>;
    using mint2 = LazyMontgomeryModInt<MOD2>;
    using mint3 = LazyMontgomeryModInt<MOD3>;

    vector<long long> a0(n), b0(m);
    for (int i = 0; i < n; i++) a0[i] = a[i].val();
    for (int i = 0; i < m; i++) b0[i] = b[i].val();
    auto a1 = FormalPowerSeries<mint1>(begin(a0), end(a0));
    auto b1 = FormalPowerSeries<mint1>(begin(b0), end(b0));
    auto c1 = convolution<mint1>(a1, b1);
    auto a2 = FormalPowerSeries<mint2>(begin(a0), end(a0));
    auto b2 = FormalPowerSeries<mint2>(begin(b0), end(b0));
    auto c2 = convolution<mint2>(a2, b2);
    auto a3 = FormalPowerSeries<mint3>(begin(a0), end(a0));
    auto b3 = FormalPowerSeries<mint3>(begin(b0), end(b0));
    auto c3 = convolution<mint3>(a3, b3);
    static const vector<long long> p = {MOD1, MOD2, MOD3, mint::getmod()};
    FPS res(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        res[i] = mint(garner({c1[i].val(), c2[i].val(), c3[i].val()}, p));
    }
    a = res;
    return res;
}

#endif  // CONVO_ARB_HPP
