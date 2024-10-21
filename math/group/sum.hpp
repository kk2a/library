#ifndef MATH_GROUP_SUM_HPP
#define MATH_GROUP_SUM_HPP 1

#include <iostream>
#include <vector>

namespace kk2 {

namespace group {

template <class S> struct Sum {
    S a;
    int size;

    constexpr Sum() : a(S{}), size(0) {}

    constexpr Sum(S a, S size = 1) : a(a), size(size) {}

    operator S() const { return a; }

    template <class OStream>
    friend OStream &operator<<(OStream &os, const Sum &sum) {
        os << sum.a;
        return os;
    }

    template <class IStream>
    friend IStream &operator>>(IStream &is, Sum &sum) {
        is >> sum.a;
        sum.size = 1;
        return is;
    }

    constexpr Sum &operator=(const S &rhs) {
        a = rhs;
        size = 1;
        return *this;
    }

    constexpr Sum &add(const S &rhs) {
        a += rhs * size;
        return *this;
    }

    constexpr Sum &update(const S &rhs) {
        a = rhs * size;
        return *this;
    }

    constexpr Sum &multiply(const S &rhs) {
        a *= rhs;
        return *this;
    }
};

template <class S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {
    l.a += r.a;
    l.size += r.size;
    return l;
}

template <class S> Sum<S> SumUnit() {
    constexpr static Sum<S> e = Sum<S>();
    return e;
}

template <class S> constexpr Sum<S> SumInv(Sum<S> x) {
    x.a = -x.a;
    x.size = -x.size;
    return x;
}

} // namespace group

template <class S, class... Args>
std::vector<group::Sum<S>> GetVecSum(int n, Args... args) {
    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));
}

template <class S, class... Args>
std::vector<std::vector<group::Sum<S>>> GetVecSum2D(int h, int w, Args... args) {
    return std::vector<std::vector<group::Sum<S>>>(h, GetVecSum<S>(w, args...));
}

} // namespace kk2

#endif // MATH_GROUP_SUM_HPP
