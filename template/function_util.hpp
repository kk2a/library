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

template <class C> int size(const C &c) {
    return c.size();
}

} // namespace kk2

template <class T, class S> inline bool chmax(T &a, const S &b) {
    return (a < b ? a = b, 1 : 0);
}

template <class T, class S> inline bool chmin(T &a, const S &b) {
    return (a > b ? a = b, 1 : 0);
}

#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP
