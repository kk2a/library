#ifndef KK2_FPS_PRODUCT_HPP
#define KK2_FPS_PRODUCT_HPP 1

#include <vector>

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS all_prod(const std::vector<FPS> &a) {
    return inner_all_prod(a, 0, (int)a.size());
}

template <class FPS, class mint = typename FPS::value_type>
FPS inner_all_prod(const std::vector<FPS> &a, int l, int r) {
    if (l == r) return FPS{1};
    if (l + 1 == r) return a[l];
    int m = (l + r) >> 1;
    return inner_all_prod(a, l, m) * inner_all_prod(a, m, r);
}

} // namespace kk2

#endif // KK2_FPS_PRODUCT_HPP
