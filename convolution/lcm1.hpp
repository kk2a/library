#ifndef CONVOLUTION_LCM
#define CONVOLUTION_LCM 1

#include <cassert>

#include "../math/Eratosthenes.hpp"

namespace kk2 {

// 1-indexed
template <class FPS, class mint = typename FPS::value_type>
FPS convolution_lcm(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());
    Erato::set_upper(n);

    auto fdt = [&](FPS &a) -> void {
        for (const auto p : Erato::primes()) {
            if (p > n) break;
            for (int i = 1; i <= n / p; i++) a[i * p] += a[i];
        }
    };
    auto ifdt = [&](FPS &a) -> void {
        for (const auto p : Erato::primes()) {
            if (p > n) break;
            for (auto i = n / p; i > 0; i--) a[i * p] -= a[i];
        }
    };

    fdt(a);
    fdt(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    ifdt(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_LCM
