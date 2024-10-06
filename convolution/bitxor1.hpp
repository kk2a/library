#ifndef CONVOLUTION_XOR
#define CONVOLUTION_XOR 1

#include <cassert>

#include "walsh_hadamard_transform.hpp"

namespace kk2 {

template <class FPS>
FPS &convolution_xor(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b.begin(), b.end());

    WalshHadamardTransform(a);
    WalshHadamardTransform(c);
    for (int i = 0; i < n; i++) a[i] *= c[i];
    InverseWalshHadamardTransform(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_XOR
