#ifndef KK2_CONVOLUTION_CONVOLUTION_LCM_HPP
#define KK2_CONVOLUTION_CONVOLUTION_LCM_HPP 1

#include <cassert>

#include "divisor_multiple_transform.hpp"

namespace kk2 {

// 1-indexed
template <class FPS> FPS convolution_lcm(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());
    Erato::set_upper(n);

    divisor_transform(a);
    divisor_transform(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    inverse_divisor_transform(a);

    return a;
}

} // namespace kk2

#endif // KK2_CONVOLUTION_CONVOLUTION_LCM_HPP
