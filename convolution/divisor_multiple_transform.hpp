#ifndef KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP
#define KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP 1

#include "../math/prime_table.hpp"

namespace kk2 {

template <class FPS> void multiple_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    PrimeTable::set_upper(n);
    for (const auto p : PrimeTable::primes()) {
        if (p > n) break;
        for (int i = n / p; i; i--) a[i] += a[i * p];
    }
}

template <class FPS> void inverse_multiple_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    PrimeTable::set_upper(n);
    for (const auto p : PrimeTable::primes()) {
        if (p > n) break;
        for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];
    }
}

template <class FPS> void divisor_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    PrimeTable::set_upper(n);
    for (const auto p : PrimeTable::primes()) {
        if (p > n) break;
        for (int i = 1; i <= n / p; i++) a[i * p] += a[i];
    }
}

template <class FPS> void inverse_divisor_transform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    PrimeTable::set_upper(n);
    for (const auto p : PrimeTable::primes()) {
        if (p > n) break;
        for (int i = n / p; i > 0; i--) a[i * p] -= a[i];
    }
}

} // namespace kk2

#endif // KK2_CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP
