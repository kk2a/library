#ifndef MATH_FLOOR_CEIL_HPP
#define MATH_FLOOR_CEIL_HPP 1

// long long floor
long long fracfloor(long long a, long long b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b;
    return -((-a) / b) - 1;
} 

// long long ceil
long long fracceil(long long a, long long b) {
    assert(b != 0);
    if (a % b == 0) return a / b;
    if (a >= 0) return a / b + 1;
    return -((-a) / b);
}

#endif // MATH_FLOOR_CEIL_HPP
