#ifndef KK2_MATH_POW_HPP
#define KK2_MATH_POW_HPP 1

#include <cassert>

namespace kk2 {

template <class S, class T, class U> constexpr S pow(T x, U n) {
    assert(n >= 0);
    S r = 1, y = x;
    while (n) {
        if (n & 1) r *= y;
        if (n >>= 1) y *= y;
    }
    return r;
}

} // namespace kk2

#endif // KK2_MATH_POW_HPP
