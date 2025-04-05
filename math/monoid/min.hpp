#ifndef KK2_MATH_MONOID_MIN_HPP
#define KK2_MATH_MONOID_MIN_HPP 1

#include <functional>

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S, class Compare = std::less<S>> struct Min {
    static constexpr bool commutative = true;
    S a;
    bool is_unit;

    Min() : a(S()), is_unit(true) {}

    Min(S a_) : a(a_), is_unit(false) {}

    operator S() const { return a; }

    inline static Min op(Min l, Min r) {
        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;
        return Compare{}(l.a, r.a) ? l : r;
    }

    inline static Min unit() { return Min(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const Min &min) {
        if (min.is_unit) os << "inf";
        else os << min.a;
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, Min &min) {
        is >> min.a;
        min.is_unit = false;
        return is;
    }

    bool operator==(const Min &rhs) const {
        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);
    }

    bool operator!=(const Min &rhs) const { return !(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_MIN_HPP
