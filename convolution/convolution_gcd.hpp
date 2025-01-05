#ifndef KK2_CONVOLUTION_CONVOLUTION_GCD_HPP
#define KK2_CONVOLUTION_CONVOLUTION_GCD_HPP 1

#include <cassert>

#include "divisor_multiple_transform.hpp"

namespace kk2 {

// 1-indexed
template <class FPS> FPS convolution_gcd(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());

    multiple_transform(a);
    multiple_transform(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    inverse_multiple_transform(a);

    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_GCD_HPP
