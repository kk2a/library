#ifndef KK2_MATH_MOD_POW_MOD_HPP
#define KK2_MATH_MOD_POW_MOD_HPP 1

#include <cassert>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <class S, class T, class U> constexpr S pow_mod(T x, U n, T m) {
    assert(n >= 0);
    if (m == 1) return S(0);
    S _m = m, r = 1;
    S y = x % _m;
    if (y < 0) y += _m;
    while (n) {
        if (n & 1) r = (r * y) % _m;
        if (n >>= 1) y = (y * y) % _m;
    }
    return r;
}

} // namespace kk2

#endif // KK2_MATH_MOD_POW_MOD_HPP
