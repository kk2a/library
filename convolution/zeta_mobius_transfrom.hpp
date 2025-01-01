#ifndef CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP
#define CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP 1

#include <cassert>

namespace kk2 {

template <class FPS> void superset_zeta_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) == 0) a[j] += a[i ^ j];
        }
    }
}

template <class FPS> void inverse_superset_zeta_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) == 0) a[j] -= a[i ^ j];
        }
    }
}

template <class FPS> void subset_zeta_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) != 0) a[j] += a[i ^ j];
        }
    }
}

template <class FPS> void inverse_subset_zeta_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) != 0) a[j] -= a[i ^ j];
        }
    }
}

} // namespace kk2

#endif // CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP
