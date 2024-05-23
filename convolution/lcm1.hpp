#ifndef CONVOLUTION_LCM
#define CONVOLUTION_LCM 1

#include "../math/Eratosthenes.hpp"

// 1-indexed
template <class FPS, class mint = typename FPS::value_type> 
FPS convolution_lcm(FPS& a, FPS b) {
    int n = int(size(a)); // = int(size(b))
    if (!n) return {};
    n--;

    static const constexpr int mx = 1000000;
    Erato pr(mx);

    auto fdt = [&](FPS& a) -> void {
        for (const auto p : pr.primes) {
            if (p > n) break;
            for (int i = 1; i <= n / p; i++) a[i * p] += a[i];
        }
    };
    auto ifdt = [&](FPS& a) -> void {
        for (const auto p : pr.primes) {
            if (p  > n) break;
            for (auto i = n / p; i > 0; i--) a[i * p] -= a[i];
        }
    };

    fdt(a);
    fdt(b);
    for (int i = 1; i <= n; i++) a[i] *= b[i];
    ifdt(a);

    return a;
}

#endif // CONVOLUTION_LCM
