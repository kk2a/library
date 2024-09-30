#ifndef CONVOLUTION_LCM
#define CONVOLUTION_LCM 1

#include <cassert>

#include "divisor_multiple_transform.hpp"

namespace kk2 {

// 1-indexed
template <class FPS>
FPS convolution_lcm(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());
    Erato::set_upper(n);

    DivisorTransform(a);
    DivisorTransform(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    InverseDivisorTransform(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_LCM
