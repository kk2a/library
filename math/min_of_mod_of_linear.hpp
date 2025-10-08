#ifndef KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP
#define KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP 1

#include <algorithm>
#include <cassert>
#include <tuple>
#include <vector>

#include "frac_floor.hpp"

namespace kk2 {

/**
 * @brief
 * - `f(x) = min_{y in [0, x]} (a * y + b) mod m (x in [0, m))`
 *
 * - `f`は`O(log b)`個の等差数列で表現できる
 *
 * @param m `0 < m`
 * @param a `0 <= a < m`
 * @param b `0 <= b < m`
 * @return
 * - `std::vector<std::tuple<T, T, T>> `
 *
 * - `(xの公差, yの公差(符号反転), 長さ-1)`の配列
 */
template <class T> std::vector<std::tuple<T, T, T>> min_of_mod_of_linear_segment(T m, T a, T b) {
    T lnum = 0, lden = 1, rnum = 1, rden = 0;
    T x = 0, y = b;
    T nnum = m - a, nden = m;

    std::vector<std::tuple<T, T, T>> res;

    auto go_down = [&](bool left) {
        T q = nnum / nden, r = nnum - nden * q;
        (left ? rnum : lnum) += (left ? lnum : rnum) * (q - (r == 0));
        (left ? rden : lden) += (left ? lden : rden) * (q - (r == 0));
        nnum = nden, nden = r;
        return r;
    };

    do {
        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum - y, nden))) * nden > 0;) {
            nnum -= c * nden, lnum += c * rnum, lden += c * rden;
            c = y / nnum;
            res.emplace_back(lden, nnum, c);
            x += lden * c, y -= nnum * c;
        }
    } while (go_down(0) and go_down(1) and y);
    return res;
}


/**
 * @brief `min_{l <= x < r} (a * x + b) mod m`
 *
 * @param l,r `0 <= l < r`
 * @param m `0 < m`
 * @param a `0 <= a < m`
 * @param b `0 <= b < m`
 * @return `arg, min`
 */
template <class T> std::pair<T, T> min_of_mod_of_linear(T l, T r, T m, T a, T b) {
    assert(0 <= a and a < m);
    assert(0 <= b and b < m);
    assert(0 < m);
    assert(l < r);
    b = (a * l + b) % m;
    r -= l, l = 0;
    T lnum = 0, lden = 1, rnum = 1, rden = 0;
    T x = 0, y = b;
    T nnum = m - a, nden = m;

    auto go_down = [&](bool left) {
        T q = nnum / nden, r = nnum - nden * q;
        (left ? rnum : lnum) += (left ? lnum : rnum) * (q - (r == 0));
        (left ? rden : lden) += (left ? lden : rden) * (q - (r == 0));
        nnum = nden, nden = r;
        return r;
    };

    do {
        for (T c{}; nnum - (c = std::max<T>(0, kk2::fracceil(nnum - y, nden))) * nden > 0;) {
            nnum -= c * nden, lnum += c * rnum, lden += c * rden;
            c = y / nnum;
            if (x + lden * c >= r) {
                c = kk2::fracceil(r - x, lden) - 1;
                return {l + x + lden * c, y - nnum * c};
            }
            x += lden * c, y -= nnum * c;
        }
    } while (go_down(0) and go_down(1) and y);
    return {l + x, y};
}

} // namespace kk2

#endif // KK2_MATH_MIN_OF_MOD_OF_LINEAR_HPP
