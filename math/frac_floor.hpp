#ifndef MATH_FLOOR_CEIL_HPP
#define MATH_FLOOR_CEIL_HPP 1

// return floor(a / b)
template <typename T, typename U, typename R = T>
R fracfloor(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b;
    return -((-a) / b) - 1;
}

// return ceil(a / b)
template <typename T, typename U, typename R = T>
R fracceil(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b + 1;
    return -((-a) / b);
}

#endif // MATH_FLOOR_CEIL_HPP
