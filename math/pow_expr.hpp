#ifndef MATH_POW_EXPR_HPP
#define MATH_POW_EXPR_HPP 1

#include <cassert>
#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <class S, class T, class U>
constexpr S pow_constexpr(T x, U n) {
    assert(!is_signed_extended<U>::value || n >= 0);
    S r = 1, y = x;
    while (n) {
        if (n & 1) r *= y;
        y *= y;
        n >>= 1;
    }
    return r;
}

} // namespace kk2

#endif // MATH_POW_EXPR_HPP
