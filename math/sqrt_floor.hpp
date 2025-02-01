#ifndef KK2_MATH_SQRT_FLOOR_HPP
#define KK2_MATH_SQRT_FLOOR_HPP 1

#include <cmath>

#include "frac_floor.hpp"

namespace kk2 {

template <typename T> T sqrt_floor(T n) {
    assert(n >= 0);
    if (n == T(0)) return 0;
    T x = std::sqrt(n);
    if (x == T(0)) ++x;
    while (x > kk2::fracfloor(n, x)) --x;
    while (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;
    return x;
}

template <typename T> T sqrt_ceil(T n) {
    assert(n >= 0);
    if (n <= T(1)) return n;
    T x = std::sqrt(n);
    if (x == T(0)) ++x;
    while (x < kk2::fracceil(n, x)) ++x;
    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;
    return x;
}

} // namespace kk2

#endif // KK2_MATH_SQRT_FLOOR_HPP
