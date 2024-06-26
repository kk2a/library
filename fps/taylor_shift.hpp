#ifndef FPS_TAYLOR_SHIFT_HPP
#define FPS_TAYLOR_SHIFT_HPP 1

#include "../math_mod/comb.hpp"

template <class FPS, class mint = typename FPS::value_type>
FPS TaylorShift(FPS f, mint a) {
    int n = f.size();
    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::fact(i);
    reverse(begin(f), end(f));
    FPS g(n, mint(1));
    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * Comb<mint>::inv(i);
    f = (f * g).pre(n).rev();
    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::ifact(i);
    return f;
}

#endif // FPS_TAYLOR_SHIFT_HPP
