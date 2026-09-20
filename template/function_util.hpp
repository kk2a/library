#ifndef KK2_TEMPLATE_FUNCTION_UTIL_HPP
#define KK2_TEMPLATE_FUNCTION_UTIL_HPP 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>
#include <vector>

#include "../math/monoid/max.hpp"
#include "../math/monoid/min.hpp"
#include "../type_traits/container_traits.hpp"

namespace kk2 {

template <class T, class... Sizes> auto make_vector(int first, Sizes... sizes) {
    if constexpr (sizeof...(sizes) == 0) {
        return std::vector<T>(first);
    } else {
        return std::vector<decltype(make_vector<T>(sizes...))>(first, make_vector<T>(sizes...));
    }
}

template <class T, class U> void fill_all(std::vector<T> &v, const U &x) {
    if constexpr (Vector<T>) {
        for (auto &u : v) fill_all(u, x);
    } else {
        std::ranges::fill(v, T(x));
    }
}

template <class T, class U> int iota_all(std::vector<T> &v, U x, int offset = 0) {
    if constexpr (Vector<T>) {
        for (auto &u : v) offset += iota_all(u, x + offset);
    } else {
        std::ranges::iota(v, x);
        offset += static_cast<int>(std::ranges::ssize(v));
    }
    return offset;
}


// T: commutative monoid, F: (U, T) -> U
template <class U, class T, class F>
U all_monoid_prod(const std::vector<T> &v, U unit, const F &f) {
    if constexpr (Vector<T>) {
        auto subproducts =
            v | std::views::transform([&](const auto &x) { return all_monoid_prod(x, unit, f); });
        return std::ranges::fold_left(subproducts, unit, std::cref(f));
    } else {
        return std::ranges::fold_left(v, unit, std::cref(f));
    }
}

template <class U, class T> U all_sum(const std::vector<T> &v, U unit = U()) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return a + b; });
}
template <class U, class T> U all_prod(const std::vector<T> &v, U unit = U(1)) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return a * b; });
}
template <class U, class T> U all_xor(const std::vector<T> &v, U unit = U()) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return a ^ b; });
}
template <class U, class T> U all_and(const std::vector<T> &v, U unit = U(-1)) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return a & b; });
}
template <class U, class T> U all_or(const std::vector<T> &v, U unit = U()) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return a | b; });
}
template <class U, class T> U all_min(const std::vector<T> &v) {
    return all_monoid_prod<monoid::Min<U>, T>(v, monoid::Min<U>::unit(), monoid::Min<U>::op);
}
template <class U, class T> U all_max(const std::vector<T> &v) {
    return all_monoid_prod<monoid::Max<U>, T>(v, monoid::Max<U>::unit(), monoid::Max<U>::op);
}
template <class U, class T> U all_gcd(const std::vector<T> &v, U unit = U()) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return std::gcd(a, b); });
}
template <class U, class T> U all_lcm(const std::vector<T> &v, U unit = U(1)) {
    return all_monoid_prod<U, T>(v, unit, [](U a, U b) { return std::lcm(a, b); });
}
template <class U, class T> int all_count(const std::vector<T> &v, U x) {
    if constexpr (Vector<T>) {
        auto counts =
            v | std::views::transform([&](const auto &values) { return all_count(values, x); });
        return std::ranges::fold_left(counts, 0, std::plus{});
    } else {
        return static_cast<int>(std::ranges::count(v, x));
    }
}

} // namespace kk2

#endif // KK2_TEMPLATE_FUNCTION_UTIL_HPP
