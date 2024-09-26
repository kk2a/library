#ifndef MATH_MONOID_MIN_HPP
#define MATH_MONOID_MIN_HPP 1

#include <algorithm>
#include <iostream>
#include <vector>

namespace kk2 {

namespace monoid {

template <class S> struct Min {
    S a;
    bool inf;

    constexpr Min() : a(S()), inf(true) {}

    constexpr Min(S a_, bool inf_ = false) : a(a_), inf(inf_) {}

    operator S() const { return a; }

    friend std::ostream &operator<<(std::ostream &os, const Min &min) {
        if (min.inf) os << "inf";
        else os << min.a;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Min &min) {
        is >> min.a;
        min.inf = false;
        return is;
    }

    constexpr Min &operator=(const S &rhs) {
        a = rhs;
        inf = false;
        return *this;
    }

    constexpr Min &add(const S &rhs) {
        if (inf) return *this;
        a += rhs;
        return *this;
    }

    constexpr Min &update(const S &rhs) {
        a = rhs;
        inf = false;
        return *this;
    }

    constexpr bool is_inf() { return inf; }
};

template <class S> constexpr Min<S> MinOp(Min<S> l, Min<S> r) {
    if (r.inf) return l;
    if (l.inf) return r;
    l.a = std::min(l.a, r.a);
    return l;
}

template <class S> constexpr Min<S> MinUnit() {
    constexpr static Min<S> e = Min<S>();
    return e;
}

} // namespace monoid

template <class S, class... Args>
constexpr std::vector<monoid::Min<S>> GetVecMin(int n, Args... args) {
    return std::vector<monoid::Min<S>>(n, monoid::Min<S>(args...));
}

template <class S, class... Args>
constexpr std::vector<std::vector<monoid::Min<S>>>
GetVecMin2D(int h, int w, Args... args) {
    return std::vector<std::vector<monoid::Min<S>>>(h, GetVecMin(w, args...));
}

} // namespace kk2

#endif // MATH_MONOID_MIN_HPP
