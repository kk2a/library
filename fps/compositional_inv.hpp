#ifndef KK2_FPS_COMPOSITIONAL_INV_HPP
#define KK2_FPS_COMPOSITIONAL_INV_HPP 1

#include <cassert>

#include "power_projection.hpp"

namespace kk2 {

// calculate f ^ {-1} (X)  mod X ^ precision
template <class FPS, class mint = typename FPS::value_type>
FPS compositional_inv(const FPS &f, int precision = -1) {
    assert(size(f) >= 2 and f[1] != mint(0));
    if (precision == -1) precision = int(size(f));
    if (precision < 2) return FPS{0, f[1].inv()}.pre(precision);
    int n = precision - 1;
    FPS h = power_projection(f) * n;

    for (int k = 1; k <= n; k++) h[k] /= k;
    h.inplace_rev();
    h *= h[0].inv();
    FPS g = (h.log() * mint(-n).inv()).exp();
    g *= f[1].inv();
    return (g << 1).pre(precision);
}

} // namespace kk2

#endif // KK2_FPS_COMPOSITIONAL_INV_HPP
