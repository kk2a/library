#ifndef CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP
#define CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP 1

#include "../math/Eratosthenes.hpp"

namespace kk2 {

template <class FPS> void MultipleTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    Erato::set_upper(n);
    for (const auto p : Erato::primes()) {
        if (p > n) break;
        for (int i = n / p; i; i--) a[i] += a[i * p];
    }
}

template <class FPS> void InverseMultipleTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    Erato::set_upper(n);
    for (const auto p : Erato::primes()) {
        if (p > n) break;
        for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];
    }
}

template <class FPS> void DivisorTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    Erato::set_upper(n);
    for (const auto p : Erato::primes()) {
        if (p > n) break;
        for (int i = 1; i <= n / p; i++) a[i * p] += a[i];
    }
}

template <class FPS> void InverseDivisorTransform(FPS &a) {
    int n = int(a.size());
    if (!n) return;
    n--;
    Erato::set_upper(n);
    for (const auto p : Erato::primes()) {
        if (p > n) break;
        for (int i = n / p; i > 0; i--) a[i * p] -= a[i];
    }
}

} // namespace kk2

#endif // CONVLUTION_DIVISOR_MULTIPLE_TRANSFORM_HPP
