#ifndef FPS_MOD_POW_HPP
#define FPS_MOD_POW_HPP 1

#include <cassert>
#include <functional>

namespace kk2 {

// return f ^ k mod g
template <class FPS, class mint = typename FPS::value_type, class T>
FPS mod_pow(T k, const FPS &f, const FPS &g) {
    // assert(!is_signed_v<T> || k >= 0);
    assert(!g.empty());

    auto inv = g.rev().inv();
    auto quo = [&](const FPS &poly) {
        if (poly.size() < g.size()) return FPS{};
        int n = poly.size() - g.size() + 1;
        return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();
    };
    FPS res{1}, b(f);
    while (k) {
        if (k & 1) {
            res *= b;
            res -= quo(res) * g;
            res.shrink();
        }
        b *= b;
        b -= quo(b) * g;
        b.shrink();
        k >>= 1;
    }
    return res;
}

} // namespace kk2

#endif // FPS_MOD_POW_HPP
