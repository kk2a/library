#ifndef CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP
#define CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP 1

#include <cassert>

namespace kk2 {

template <class FPS> void SuperSetZetaTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) == 0) a[j] += a[i ^ j];
        }
    }
}

template <class FPS> void InverseSuperSetZetaTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) == 0) a[j] -= a[i ^ j];
        }
    }
}

template <class FPS> void SubsetZetaTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) != 0) a[j] += a[i ^ j];
        }
    }
}

template <class FPS> void InverseSubsetZetaTransform(FPS &a) {
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
