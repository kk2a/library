#ifndef MATH_MONOID_MAX_HPP
#define MATH_MONOID_MAX_HPP 1

#include <algorithm>
#include <iostream>
#include <vector>

namespace kk2 {

namespace monoid {

template <class S> struct Max {
    S a;
    bool minf;

    constexpr Max() : a(S()), minf(true) {}

    constexpr Max(S a_, bool minf_ = false) : a(a_), minf(minf_) {}

    operator S() const { return a; }

    friend std::ostream &operator<<(std::ostream &os, const Max &max) {
        if (max.minf) os << "minf";
        else os << max.a;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Max &max) {
        is >> max.a;
        max.minf = false;
        return is;
    }

    constexpr Max &operator=(const S &rhs) {
        a = rhs;
        minf = false;
        return *this;
    }

    constexpr Max &add(const S &rhs) {
        if (minf) return *this;
        a += rhs;
        return *this;
    }

    constexpr Max &update(const S &rhs) {
        a = rhs;
        minf = false;
        return *this;
    }

    constexpr bool is_minf() { return minf; }
};

template <class S> constexpr Max<S> MaxOp(Max<S> l, Max<S> r) {
    if (r.minf) return l;
    if (l.minf) return r;
    l.a = std::max(l.a, r.a);
    return l;
}

template <class S> constexpr Max<S> MaxUnit() {
    constexpr static Max<S> e = Max<S>();
    return e;
}

} // namespace monoid

template <class S, class... Args>
constexpr std::vector<monoid::Max<S>> GetVecMax(int n, Args... args) {
    return std::vector<monoid::Max<S>>(n, monoid::Max<S>(args...));
}

template <class S, class... Args>
constexpr std::vector<std::vector<monoid::Max<S>>> GetVecMax2D(int h, int w, Args... args) {
    return std::vector<std::vector<monoid::Max<S>>>(h, GetVecMax<S>(w, args...));
}

} // namespace kk2

#endif // MATH_MONOID_MAX_H
