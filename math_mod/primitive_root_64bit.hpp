#ifndef KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP
#define KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP 1

#include "../math/prime_factorize.hpp"
#include "../random/gen.hpp"
#include "pow_mod.hpp"

namespace kk2 {

long long primitive_root_64bit(long long p) {
    if (p == 2) return 1;
    if (p == 3) return 2;

    auto f = factorize(p - 1);
    for (long long g{}; g = random::rng(2, p - 1), 1;) {
        if ([&]() {
                for (auto &&[q, e] : f)
                    if (pow_mod<__int128_t>(g, (p - 1) / q, p) == 1) return false;
                return true;
            }())
            return g;
    }
    return -1;
}

template <class mint> long long primitive_root_mint() {
    if (mint::getmod() == 2u) return 1;
    if (mint::getmod() == 3u) return 2;

    long long p = mint::getmod();

    auto f = factorize(p - 1);
    for (mint g; g = random::rng(2, p - 1), 1;) {
        if ([&]() {
                for (auto &&[q, e] : f)
                    if (g.pow((p - 1) / q) == mint(1)) return false;
                return true;
            }())
            return g.val();
    }
    return -1;
}

} // namespace kk2

#endif // KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP
