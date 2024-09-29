#ifndef MOD_POW_EXPR_HPP
#define MOD_POW_EXPR_HPP 1

#include <cassert>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <class S, class T, class U> constexpr S pow_mod(T x, U n, T m) {
    assert(!is_signed_extended<U>::value || n >= 0);
    if (m == 1) return S(0);
    S _m = S(m), r = 1;
    S y = S(x) % _m;
    if (y < 0) y += _m;
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}

} // namespace kk2

#endif // MOD_POW_EXPR_HPP
