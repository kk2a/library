#ifndef KK2_TEMPLATE_FUNCTION_UTIL_HPP
#define KK2_TEMPLATE_FUNCTION_UTIL_HPP 1

#include <algorithm>
#include <vector>

namespace kk2 {

template <class T, class... Sizes> auto make_vector(int first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0) {
        return std::vector<T>(first);
    } else {
        return std::vector<decltype(make_vector<T>(sizes...))>(first, make_vector<T>(sizes...));
    }
}

template <class T, class U> void fill_all(std::vector<T> &v, const U &x) {
    std::fill(std::begin(v), std::end(v), T(x));
}

template <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {
    for (auto &u : v) fill_all(u, x);
}

template <class C> int mysize(const C &c) { return size(c); }

// T: comutative monoid
template <class T, class U> U all_sum(const std::vector<T> &v, U unit = U()) {
    U res = unit;
    for (const auto &x : v) res += x;
    return res;
}

template <class T, class U> U all_sum(const std::vector<std::vector<T>> &v, U unit = U()) {
    U res = unit;
    for (const auto &u : v) res += all_sum(u, unit);
    return res;
}

// T: commutative monoid, F: (U, T) -> U
template <class T, class U, class F>
U all_monoid_prod(const std::vector<T> &v, U unit, const F &f) {
    U res = unit;
    for (const auto &x : v) res = f(res, x);
    return res;
}

template <class T, class U, class F>
U all_monoid_prod(const std::vector<std::vector<T>> &v, U unit, const F &f) {
    U res = unit;
    for (const auto &u : v) res = f(res, all_monoid_prod(u, unit, f));
    return res;
}


} // namespace kk2

#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP
