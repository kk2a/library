#ifndef KK2_FPS_POLY_TAYLOR_SHIFT_HPP
#define KK2_FPS_POLY_TAYLOR_SHIFT_HPP 1

#include <algorithm>

#include "../math_mod/comb.hpp"

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type> FPS taylor_shift(const FPS &f_, mint a) {
    FPS f(f_);
    int n = f.size();
    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::fact(i);
    f.inplace_rev();
    FPS g(n, mint(1));
    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * Comb<mint>::inv(i);
    f = (f * g).pre(n).rev();
    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::ifact(i);
    return f;
}

} // namespace kk2

#endif // KK2_FPS_POLY_TAYLOR_SHIFT_HPP
