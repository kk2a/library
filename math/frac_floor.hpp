#ifndef KK2_MATH_FRAC_FLOOR_HPP
#define KK2_MATH_FRAC_FLOOR_HPP 1

#include <cassert>

namespace kk2 {

// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)
// floor(x) = -ceil(-x)   (for all x)          ...(2)

// return floor(a / b)
template <typename T, typename U> constexpr T fracfloor(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b;

    // floor(x) = -ceil(-x)      by (2)
    //          = -floor(-x) - 1 by (1)
    return -((-a) / b) - 1;
}

// return ceil(a / b)
template <typename T, typename U> constexpr T fracceil(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b + 1;

    // ceil(x) = -floor(-x)      by (2)
    return -((-a) / b);
}

} // namespace kk2

#endif // KK2_MATH_FRAC_FLOOR_HPP
