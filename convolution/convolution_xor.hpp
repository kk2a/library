#ifndef KK2_CONVOLUTION_CONVOLUTION_XOR_HPP
#define KK2_CONVOLUTION_CONVOLUTION_XOR_HPP 1

#include <cassert>

#include "walsh_hadamard_transform.hpp"

namespace kk2 {

template <class FPS> FPS convolution_xor(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b.begin(), b.end());

    walsh_hadamard_transform(a);
    walsh_hadamard_transform(c);
    for (int i = 0; i < n; i++) a[i] *= c[i];
    inverse_walsh_hadamard_transform(a);

    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_XOR_HPP
