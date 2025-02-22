#ifndef KK2_MATH_MOD_MOD_SQRT_HPP
#define KK2_MATH_MOD_MOD_SQRT_HPP 1

#include <cassert>

#include "../modint/mont_arb.hpp"

namespace kk2 {

template <class T, class U> long long mod_sqrt(const T &a, const U &p) {
    assert(0 <= a && a < p);
    if (a < 2) return a;
    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;
    Mint::setmod(p);
    if (Mint(a).pow((p - 1) >> 1) != Mint(1)) return -1;
    Mint b = 1;
    while (b.pow((p - 1) >> 1) == Mint(1)) b += 1;
    long long m = p - 1, e = 0;
    while (m % 2 == 0) m >>= 1, e++;
    Mint x = Mint(a).pow((m - 1) >> 1);
    Mint y = Mint(a) * x * x;
    x *= a;
    Mint z = Mint(b).pow(m);
    while (y != Mint(1)) {
        long long j = 0;
        Mint t = y;
        while (t != Mint(1)) {
            j++;
            t *= t;
        }
        z = z.pow(1LL << (e - j - 1));
        x *= z;
        z *= z;
        y *= z;
        e = j;
    }
    return x.val();
}

} // namespace kk2

#endif // KK2_MATH_MOD_MOD_SQRT_HPP
