#ifndef KK2_MATH_MOD_MOD_SQRT_HPP
#define KK2_MATH_MOD_MOD_SQRT_HPP 1

#include <cassert>

#include "../modint/mont_arb.hpp"

namespace kk2 {

// ref: https://37zigen.com/tonelli-shanks-algorithm/
template <class T, class U> long long mod_sqrt(const T &a, const U &p) {
    assert(0 <= a && a < p);
    if (a < 2) return a;
    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;
    Mint::setmod(p);

    // euler's criterion
    if (Mint(a).pow((p - 1) / 2) != Mint(1)) return -1;

    // find b: non quadratic residue
    Mint b = 1;
    while (b.pow((p - 1) / 2) == Mint(1)) b += 1;

    // (Z/pZ)^*
    // ≅ Z/(p-1)Z
    // ≅ Z/2^eZ * Z/mZ (m: odd)
    long long m = p - 1, e = 0;
    while (m % 2 == 0) m >>= 1, e++;

    Mint x = Mint(a).pow((m - 1) / 2);
    Mint y = Mint(a) * x * x;
    x *= a;
    Mint z = Mint(b).pow(m);
    while (y != Mint(1)) {
        // x -> (x_1, x_2) in Z/2^eZ * Z/mZ
        // a -> (a_1, a_2) in Z/2^eZ * Z/mZ
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
