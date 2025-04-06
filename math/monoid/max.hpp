#ifndef KK2_MATH_MONOID_MAX_HPP
#define KK2_MATH_MONOID_MAX_HPP 1

#include <functional>

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S, class Compare = std::less<S>> struct Max {
    static constexpr bool commutative = true;
    using M = Max;
    S a;
    bool is_unit;

    Max() : a(S()), is_unit(true) {}
    Max(S a_) : a(a_), is_unit(false) {}
    operator S() const { return a; }

    inline static M op(M l, M r) {
        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;
        return Compare{}(l.a, r.a) ? r : l;
    }

    inline static M unit() { return M(); }

    bool operator==(const M &rhs) const {
        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);
    }

    bool operator!=(const M &rhs) const {
        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        if (x.is_unit) os << "-inf";
        else os << x.a;
        return os;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &x) {
        is >> x.a;
        x.is_unit = false;
        return is;
    }
};

} // namespace monoid

} // namespace kk2

#endif // MATH_MONOID_MAX_HPP
