#ifndef MATH_CONVERT_BASE_HPP
#define MATH_CONVERT_BASE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace kk2 {

template <class T> std::vector<T> convert_base(T x, T b) {
    if (x == 0) return {0};
    assert(b);
    std::vector<T> res;
    T k = abs(b);
    while (x) {
        res.emplace_back(x % k);
        if (res.back() < 0) res.back() += k;
        x -= res.back();
        x /= b;
    }
    return res;
}

template <class T> T from_base(const std::vector<T> &v, T b) {
    assert(b);
    T res = 0;
    for (int i = v.size() - 1; i >= 0; i--) res = res * b + v[i];
    return res;
}

} // namespace kk2

#endif // MATH_CONVERT_BASE_HPP
