#ifndef KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP
#define KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP 1

#include <functional>

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S, class T, class Compare = std::less<S>> struct MaxMinSumWithSize {
    static constexpr bool commutative = true;
    using M = MaxMinSumWithSize;

    S max, min, sum;
    T size;
    bool is_unit;

    MaxMinSumWithSize() : is_unit(true) {}

    MaxMinSumWithSize(S a) : max(a), min(a), sum(a), size(1), is_unit(false) {}

    MaxMinSumWithSize(S max_, S min_, S sum_, T size_)
        : max(max_),
          min(min_),
          sum(sum_),
          size(size_),
          is_unit(false) {}

    inline static M op(M l, M r) {
        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;
        return M(Compare{}(l.max, r.max) ? r.max : l.max,
                 Compare{}(l.min, r.min) ? l.min : r.min,
                 l.sum + r.sum,
                 l.size + r.size);
    }

    inline static M unit() { return M(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        if (x.is_unit) os << "(unit)";
        else
            os << "(max:" << x.max << ", min:" << x.min << ", sum:" << x.sum << ", size:" << x.size
               << ")";
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &x) {
        S a;
        is >> a;
        x = M(a);
        return is;
    }

    bool operator==(const M &rhs) const {
        return is_unit == rhs.is_unit
               and (is_unit
                    or (max == rhs.max and min == rhs.min and sum == rhs.sum and size == rhs.size));
    }

    bool operator!=(const M &rhs) const { return !(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_MAX_MIN_SUMWITHSUM_HPP
