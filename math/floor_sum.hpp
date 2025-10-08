#ifndef KK2_MATH_FLOOR_SUM_HPP
#define KK2_MATH_FLOOR_SUM_HPP 1

#include <algorithm>

namespace kk2 {

// https://atcoder.jp/contests/practice2/editorial/579
// a, bは非負でないといけない
// sum_{i=0}^{n-1} floor((a * i + b) / m)
template <class T> T sum_of_floor(T n, T m, T a, T b) {
    T res = 0;
    while (true) {
        if (a >= m) res += (n - 1) * n / 2 * (a / m), a %= m;
        if (b >= m) res += n * (b / m), b %= m;
        T max = a * n + b;
        if (max < m) break;
        n = max / m, b = max % m;
        std::swap(a, m);
    }
    return res;
}

template <class T> T sum_of_floor(T n, T m, T a, T b, T start) {
    return sum_of_floor(n - start, m, a, b + a * start);
}

} // namespace kk2

#endif // KK2_MATH_FLOOR_SUM_HPP
