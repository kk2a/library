#ifndef KK2_MATH_ENUMERATE_QUOTIENTS_HPP
#define KK2_MATH_ENUMERATE_QUOTIENTS_HPP 1

#include <numeric>
#include <vector>

#include "sqrt_floor.hpp"

namespace kk2 {

template <class T>
struct EnumerateQuotients {
    T n;
    int sqrt_n;
    std::vector<T> res;

    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n)) {
        res.resize(sqrt_n + n / (sqrt_n + 1));
        std::iota(res.begin(), res.begin() + sqrt_n, 1);
        for (T i = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j) res[j] = n / i;
    }

    const std::vector<T> &get() const { return res; }

    int size() const { return res.size(); }

    const T &operator[](int i) const { return res[i]; }

    int idx(T x) const {
        if (x <= sqrt_n) return x - 1;
        return size() - n / x;
    }
};

} // namespace kk2

#endif // KK2_MATH_ENUMERATE_QUOTIENTS_HPP
