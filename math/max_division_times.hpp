#ifndef KK2_MATH_MAX_DIVISION_TIMES_HPP
#define KK2_MATH_MAX_DIVISION_TIMES_HPP 1

namespace kk2 {

template <class T, class U>
int max_division_times(T a, U b) {
    int res = 0;
    while (a % b == 0) a /= b, res++;
    return res;
}

template <class T, class U>
int divide_max_times(T &a, U b) {
    int res = 0;
    while (a % b == 0) a /= b, res++;
    return res;
}

} // namespace kk2

#endif // KK2_MATH_MAX_DIVISION_TIMES_HPP
