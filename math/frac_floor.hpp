#ifndef MATH_FLOOR_CEIL_HPP
#define MATH_FLOOR_CEIL_HPP 1

// if x \notin Z, then floor(x) = ceil(x) - 1 ...(1)
// for all x \in R, floor(x) = -ceil(-x)      ...(2)

// return floor(a / b)
template <typename T, typename U, typename R = T>
R fracfloor(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b;

    // if x \notin Z,
    // floor(x) = -ceil(-x)      by (2)
    //          = -floor(-x) - 1 by (1)
    return -((-a) / b) - 1;
}

// return ceil(a / b)
template <typename T, typename U, typename R = T>
R fracceil(T a, U b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b + 1;

    // if x \notin Z,
    // ceil(x) = -floor(-x)      by (2)
    return -((-a) / b);
}

#endif // MATH_FLOOR_CEIL_HPP
