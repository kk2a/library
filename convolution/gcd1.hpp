#ifndef CONVOLUTION_GCD
#define CONVOLUTION_GCD 1

#include <cassert>

#include "../math/Eratosthenes.hpp"

namespace kk2 {

// 1-indexed
template <class FPS, class mint = typename FPS::value_type>
FPS convolution_gcd(FPS &a, const FPS &b) {
    assert(size(a) == size(b));
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;
    FPS c(b.begin(), b.end());
    Erato::set_upper(n);

    auto fmt = [&](FPS &a) -> void {
        for (const auto p : Erato::primes()) {
            if (p > n) break;
            for (int i = n / p; i > 0; i--) a[i] += a[i * p];
        }
    };
    auto ifmt = [&](FPS &a) -> void {
        for (const auto p : Erato::primes()) {
            if (p > n) break;
            for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];
        }
    };

    fmt(a);
    fmt(c);
    for (int i = 1; i <= n; i++) a[i] *= c[i];
    ifmt(a);

    return a;
}

} // namespace kk2

#endif // CONVOLUTION_GCD
