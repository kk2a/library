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
    while (true) {
        long long g = random::rng(2, p - 1);
        bool ok = true;
        for (auto &&[q, e] : f) {
            if (pow_mod<__int128_t>(g, (p - 1) / q, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

} // namespace kk2

#endif // KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP
