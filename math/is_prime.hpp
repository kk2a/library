#ifndef MATH_MILLER_RABIN_HPP
#define MATH_MILLER_RABIN_HPP 1

#include <vector>

#include "../math_mod/pow_mod.hpp"
#include "../modint/mont_arb.hpp"

namespace kk2 {

namespace number_theory {

template <class T, class U> bool miller_rabin(const T &n, const std::vector<T> &ws) {
    if (n <= 2) return n == 2;
    if (~n & 1) return false;

    T d = n - 1;
    while (~d & 1) d >>= 1;
    U e = 1, rev = n - 1;
    for (T w : ws) {
        if (w % n == 0) continue;
        T t = d;
        U y = pow_mod<T, T, U>(w, t, n);
        while (t != n - 1 and y != e and y != rev) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != rev and ~t & 1) return false;
    }
    return true;
}

bool miller_rabin_u64(unsigned long long n) {
    return miller_rabin<unsigned long long, __uint128_t>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <class mint>
bool miller_rabin_mont(unsigned long long n, const std::vector<unsigned long long> &ws) {
    if (n <= 2) return n == 2;
    if (~n & 1) return false;

    if (mint::getmod() != n) mint::setmod(n);
    unsigned long long d = n - 1;
    while (~d & 1) d >>= 1;
    mint e = 1, rev = n - 1;
    for (unsigned long long w : ws) {
        if (w % n == 0) continue;
        unsigned long long t = d;
        mint y = mint(w).pow(t);
        while (t != n - 1 and y != e and y != rev) {
            y *= y;
            t <<= 1;
        }
        if (y != rev and ~t & 1) return false;
    }
    return true;
}

bool is_prime(unsigned long long n) {
    using mint32 = ArbitraryLazyMontgomeryModInt<54305750>;
    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54305750>;

    if (n <= 2) return n == 2;
    if (~n & 1) return false;
    if (n < (1ull << 30)) {
        return miller_rabin_mont<mint32>(n, {2, 7, 61});
    } else if (n < (1ull << 62)) {
        return miller_rabin_mont<mint64>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
    } else {
        return miller_rabin_u64(n);
    }
}

}; // namespace number_theory

using number_theory::is_prime;

}; // namespace kk2

#endif // MATH_MILLER_RABIN_HPP
