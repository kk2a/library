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

template <class C> int mysize(const C &c) {
    return c.size();
}

// T: comutative monoid
template <class T, class U> U all_sum(const std::vector<T> &v, U init, U = U()) {
    U res = init;
    for (const auto &x : v) res += x;
    return res;
}

template <class T, class U> U all_sum(const std::vector<std::vector<T>> &v, U init, U unit = U()) {
    U res = init;
    for (const auto &u : v) res += all_sum(u, unit, unit);
    return res;
}

// T: commutative monoid, F: (U, T) -> U
template <class T, class U, class F> U all_prod(const std::vector<T> &v, U init, const F &f, U = U()) {
    U res = init;
    for (const auto &x : v) res = f(res, x);
    return res;
}

template <class T, class U, class F>
U all_prod(const std::vector<std::vector<T>> &v, U init, const F &f, U unit) {
    U res = init;
    for (const auto &u : v) res = f(res, all_prod(u, unit, f, unit));
    return res;
}

template <class T> T all_min(const std::vector<T> &v) {
    if (v.empty()) return T();
    T res = v[0];
    for (const auto &x : v) res = res > x ? x : res;
    return res;
}

template <class T>
T all_min(const std::vector<std::vector<T>> &v) {
    T res{};
    bool first = true;
    for (const auto &u : v) {
        if (u.empty()) continue;
        if (first) {
            res = all_min(u);
            first = false;
        } else {
            T tmp = all_min(u);
            res = res > tmp ? tmp : res;
        }
    }
    return res;
}

template <class T> T all_max(const std::vector<T> &v) {
    if (v.empty()) return T();
    T res = v[0];
    for (const auto &x : v) res = res < x ? x : res;
    return res;
}

template <class T>
T all_max(const std::vector<std::vector<T>> &v) {
    T res{};
    bool first = true;
    for (const auto &u : v) {
        if (u.empty()) continue;
        if (first) {
            res = all_max(u);
            first = false;
        } else {
            T tmp = all_max(u);
            res = res < tmp ? tmp : res;
        }
    }
    return res;
}

} // namespace kk2

#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP
