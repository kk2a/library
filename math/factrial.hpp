#ifndef KK2_MATH_FACTORIAL_HPP
#define KK2_MATH_FACTORIAL_HPP 1

namespace kk2 {

template <class S, class T> constexpr S fact(T n) {
    if (n < 0) return 1;
    S res = 1;
    for (T i = 1; i <= n; ++i) res *= i;
    return res;
}

} // namespace kk2

#endif // KK2_MATH_FACTORIAL_HPP
