#ifndef CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP
#define CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP 1

#include <cassert>

namespace kk2 {

template <class FPS> void walsh_hadamard_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) != 0) {
                auto x = a[j], y = a[i ^ j];
                a[j] = -x + y, a[i ^ j] = x + y;
            }
        }
    }
}

template <class FPS> void inverse_walsh_hadamard_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    assert((n & -n) == n);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((i & j) != 0) {
                auto x = a[j], y = a[i ^ j];
                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;
            }
        }
    }
}

} // namespace kk2

#endif // CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP
