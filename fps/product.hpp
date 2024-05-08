#ifndef FPS_PRODUCT_HPP
#define FPS_PRODUCT_HPP 1

#include <kk2/fps/fps.hpp>

template <class mint>
FormalPowerSeries<mint> all_prod(const vector<FormalPowerSeries<mint>> &a, int l, int r) {
    if (l == r) return FormalPowerSeries<mint>{1};
    if (l + 1 == r) return a[l];
    int m = (l + r) >> 1;
    return all_prod(a, l, m) * all_prod(a, m, r);
}

#endif // FPS_PRODUCT_HPP
