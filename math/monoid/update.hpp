#ifndef KK2_MATH_MONOID_UPDATE_HPP
#define KK2_MATH_MONOID_UPDATE_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S> struct Update {
    static constexpr bool commutative = true;
    using M = Update;
    S a;
    bool is_unit;

    Update() : is_unit(true) {}
    Update(S a_) : a(a_), is_unit(false) {}
    operator S() const { return a; }
    inline static M op(M l, M r) { return l.is_unit ? r : l; }
    inline static M unit() { return M(); }

    bool operator==(const M &rhs) const {
        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);
    }

    bool operator!=(const M &rhs) const {
        return is_unit != rhs.is_unit or (!is_unit and a != rhs.a);
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        if (x.is_unit) os << "unit";
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

#endif // KK2_MATH_MONOID_UPDATE_HPP
