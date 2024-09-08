#ifndef CONVOLUTION_AND
#define CONVOLUTION_AND 1

#include <cassert>
#include <functional>

namespace kk2 {

template <class FPS, class mint = typename FPS::value_type>
FPS convolution_and(FPS& a, const FPS& b) {
    assert(size(a) == size(b));
    int n = int(size(a));  // == int(size(b)
    if (!n) return {};
    assert((n & -n) == n);
    FPS c(b.begin(), b.end());

    auto fzt = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) == 0) a[j] += a[i ^ j];
            }
        }
    };
    auto ifzt = [&](FPS& a) -> void {
        for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; j++) {
                if ((i & j) == 0) a[j] -= a[i ^ j];
            }
        }
    };

    fzt(a);
    fzt(c);
    for (int i = 0; i < n; i++) a[i] *= c[i]; 
    ifzt(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_AND
