#ifndef MATH_POW_EXPR_HPP
#define MATH_POW_EXPR_HPP 1

template <class S, class T, class U>
constexpr S pow_constexpr(T x, U n) {
    assert(!is_signed_v<U> && n >= 0);
    S r = 1, y = x;
    while (n) {
        if (n & 1) r *= y;
        y *= y;
        n >>= 1;
    }
    return r;
}

#endif // MATH_POW_EXPR_HPP
