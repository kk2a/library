#ifndef KK2_CONVOLUTION_CONVOLUTION_AND_HPP
#define KK2_CONVOLUTION_CONVOLUTION_AND_HPP 1

#include <cassert>

#include "zeta_mobius_transfrom.hpp"

namespace kk2 {

template <class FPS>
FPS convolution_and(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b.begin(), b.end());

    superset_zeta_transform(a);
    superset_zeta_transform(c);
    for (int i = 0; i < n; i++) a[i] *= c[i];
    inverse_superset_zeta_transform(a);

    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_AND_HPP
