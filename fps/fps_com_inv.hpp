#ifndef FPS_COMPOSITION_INVERSION_HPP
#define FPS_COMPOSITION_INVERSION_HPP 1

#ifdef KK2
#include "fps.hpp"
#include "power_projection.hpp"
#endif

// calculate f ^ {-1} (X)  mod X ^ deg
template <class mint>
FormalPowerSeries<mint> compositionnal_inv(FormalPowerSeries<mint> f,
                                           int deg = -1) {
    assert(int(size(f)) >= 2 and f[1] != 0);
    if (deg == -1) deg = int(size(f));
    if (deg < 2) return FormalPowerSeries<mint>{0, f[1].inv()}.pre(deg);
    int n = deg - 1;
    FormalPowerSeries<mint> h = power_projection(f) * n;

    for (int k = 1; k <= n; k++) h[k] /= k;
    h.inplace_rev();
    h *= h[0].inv();
    FormalPowerSeries<mint> g = (h.log() * mint(-n).inv()).exp();
    g *= f[1].inv();
    return (g << 1).pre(deg);
}

#endif // FPS_COMPOSITION_INVERSION_HPP
