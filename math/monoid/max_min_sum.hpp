#ifndef KK2_MATH_MONOID_MAX_MIN_SUM_HPP
#define KK2_MATH_MONOID_MAX_MIN_SUM_HPP 1

#include <algorithm>
#include <iostream>
#include <vector>

namespace kk2 {

namespace monoid {

template <class S> struct MaxMinSum {
    S sum, max, min;
    int size;
    bool is_unit;

    constexpr MaxMinSum() : sum(0), max(0), min(0), size(0), is_unit(true) {}

    constexpr MaxMinSum(S a, bool is_unit_ = false)
        : sum(a),
          max(a),
          min(a),
          size(1),
          is_unit(is_unit_) {}

    constexpr MaxMinSum(S sum_, S max_, S min_, int size_)
        : sum(sum_),
          max(max_),
          min(min_),
          size(size_),
          is_unit(is_unit_) {}

    template <class OStream> friend OStream &operator<<(OStream &os, const MaxMinSum &maxminSum) {
        os << maxminSum.sum << " " << maxminSum.max << " " << maxminSum.min;
        return os;
    }

    template <class IStream> friend IStream &operator>>(IStream &is, MaxMinSum &maxminSum) {
        S a;
        is >> a;
        maxminSum.sum = maxminSum.max = maxminSum.min = a;
        maxminSum.size = 1;
        return is;
    }

    constexpr MaxMinSum &operator=(const S &rhs) {
        sum = max = min = rhs;
        size = 1;
        is_unit = false;
        return *this;
    }

    constexpr MaxMinSum &add(const S &rhs) {
        if (is_unit) return *this;
        sum += rhs * size;
        max += rhs;
        min += rhs;
        return *this;
    }

    constexpr MaxMinSum &update(const S &rhs) {
        sum = rhs * size;
        max = min = rhs;
        is_unit = false;
        return *this;
    }
};

template <class S> constexpr MaxMinSum<S> MaxMinSumOp(MaxMinSum<S> l, MaxMinSum<S> r) {
    if (l.is_unit) return r;
    if (r.is_unit) return l;
    l.sum += r.sum;
    l.size += r.size;
    l.max = std::max(l.max, r.max);
    l.min = std::min(l.min, r.min);
    return l;
}

template <class S> MaxMinSum<S> MaxMinSumUnit() {
    constexpr static MaxMinSum<S> e = MaxMinSum<S>();
    return e;
}

} // namespace monoid

template <class S, class... Args>
std::vector<monoid::MaxMinSum<S>> GetVecMaxMinSum(int n, Args... args) {
    return std::vector<monoid::MaxMinSum<S>>(n, monoid::MaxMinSum<S>(args...));
}

template <class S, class... Args>
std::vector<std::vector<monoid::MaxMinSum<S>>> GetVecMaxMinSum2D(int h, int w, Args... args) {
    return std::vector<std::vector<monoid::MaxMinSum<S>>>(h, GetVecMaxMinSum<S>(w, args...));
}

} // namespace kk2

#endif // KK2_MATH_MONOID_MAX_MIN_SUM_HPP
