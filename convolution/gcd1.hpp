#ifndef CONVOLUTION_GCD
#define CONVOLUTION_GCD 1

#include <cassert>

#include "divisor_multiple_transform.hpp"

namespace kk2 {

// 1-indexed
template <class FPS>
FPS &convolution_gcd(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());

    MultipleTransform(a);
    MultipleTransform(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    InverseMultipleTransform(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_GCD
