#ifndef CONVOLUTION_GCD
#define CONVOLUTION_GCD 1

#include "../math/Eratosthenes.hpp"

// 1-indexed
template <class FPS, class mint = typename FPS::value_type> 
FPS convolution_gcd(FPS& a, FPS b) {
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;

    static const constexpr int mx = 1000000;
    Erato pr(mx);

    auto fmt = [&](FPS& a) -> void {
        for (const auto p : pr.primes) {
            if (p > n) break;
            for (int i = n / p; i > 0; i--) a[i] += a[i * p];
        }
    };
    auto ifmt = [&](FPS& a) -> void {
        for (const auto p : pr.primes) {
            if (p > n) break;
            for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];
        }
    };

    fmt(a);
    fmt(b);
    for (int i = 1; i <= n; i++) a[i] *= b[i];
    ifmt(a);

    return a;
}

#endif // CONVOLUTION_GCD
