#ifndef FPS_PRODUCT_HPP
#define FPS_PRODUCT_HPP 1


template <class FPS, class mint = FPS::value_type>
FormalPowerSeries<mint> all_prod(const vector<FPS> &a, int l, int r) {
    if (l == r) return FPS{1};
    if (l + 1 == r) return a[l];
    int m = (l + r) >> 1;
    return all_prod(a, l, m) * all_prod(a, m, r);
}

#endif // FPS_PRODUCT_HPP
