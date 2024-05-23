#ifndef FPS_COMPOSITION_INVERSION_HPP
#define FPS_COMPOSITION_INVERSION_HPP 1

#include "power_projection.hpp"

// calculate f ^ {-1} (X)  mod X ^ deg
template <class FPS, class mint = FPS::value_type>
FPS compositional_inv(FPS f, int deg = -1) {
    assert(int(size(f)) >= 2 and f[1] != 0);
    if (deg == -1) deg = int(size(f));
    if (deg < 2) return FPS{0, f[1].inv()}.pre(deg);
    int n = deg - 1;
    FPS h = power_projection(f) * n;

    for (int k = 1; k <= n; k++) h[k] /= k;
    h.inplace_rev();
    h *= h[0].inv();
    FPS g = (h.log() * mint(-n).inv()).exp();
    g *= f[1].inv();
    return (g << 1).pre(deg);
}

#endif // FPS_COMPOSITION_INVERSION_HPP
