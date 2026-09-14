#ifndef KK2_MATH_MOD_DETAIL_MOD_SQRT_HPP
#define KK2_MATH_MOD_DETAIL_MOD_SQRT_HPP 1

#include "../primitive_root.hpp"

namespace kk2::mod_sqrt_detail {

template <class Mint> long long tonelli_shanks(const Mint &a, Mint z, long long m, long long e) {
    Mint x = a.pow((m - 1) / 2);
    Mint y = a * x * x;
    x *= a;
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

template <bool ntt_friendly = false, class mint> long long mod_sqrt(const mint &a) {
    const auto p = mint::getmod();
    if (a.val() < 2) return a.val();

    // Euler's criterion
    if (a.pow((p - 1) / 2) != mint(1)) return -1;

    mint b;
    if constexpr (ntt_friendly) {
        b = primitive_root<mint::getmod()>;
    } else {
        // Find a quadratic non-residue.
        b = 1;
        while (b.pow((p - 1) / 2) == mint(1)) b += 1;
    }

    long long m = p - 1, e = 0;
    while (m % 2 == 0) m >>= 1, e++;

    mint z = b.pow(m);
    return tonelli_shanks(a, z, m, e);
}

} // namespace kk2::mod_sqrt_detail

#endif // KK2_MATH_MOD_DETAIL_MOD_SQRT_HPP
