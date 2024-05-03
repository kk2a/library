#ifndef CONVO_ARB_HPP
#define CONVO_ARB_HPP 1

#include <kk2/modint/mont.hpp>
#include <kk2/convolution/butterfly.hpp>
#include <kk2/convolution/convolution.hpp>

template <class mint, class FPS>
FPS convolution_arb(FPS& a, FPS b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    static constexpr int nm = 3;
    static constexpr long long MOD1 = 1107296257;  // 2^25
    static constexpr long long MOD2 = 167772161;  // 2^25
    static constexpr long long MOD3 = 469762049;  // 2^26
    auto c1 = convolution<LazyMontgomeryModInt<MOD1>>(a, b);
    auto c2 = convolution<LazyMontgomeryModInt<MOD2>>(a, b);
    auto c3 = convolution<LazyMontgomeryModInt<MOD3>>(a, b);
    static const vector<long long> p = {MOD1, MOD2, MOD3, mint::getmod()};
    vector<mint> res(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) {
        res[i] = mint(garner({c1[i].val(), c2[i].val(), c3[i].val()}, p));
    }
    return res;
}

#endif  // CONVO_ARB_HPP
