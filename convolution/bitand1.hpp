#ifndef CONVOLUTION_AND
#define CONVOLUTION_AND 1

#include <cassert>

#include "zeta_mobius_transfrom.hpp"

namespace kk2 {

template <class FPS>
FPS &convolution_and(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b.begin(), b.end());

    SuperSetZetaTransform(a);
    SuperSetZetaTransform(c);
    for (int i = 0; i < n; i++) a[i] *= c[i];
    InverseSuperSetZetaTransform(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_AND
