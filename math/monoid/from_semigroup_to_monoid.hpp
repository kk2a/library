#ifndef KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP
#define KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class SM> struct FromSemigroupToMonoid {
    static constexpr bool commutative = SM::commutative;
    using M = FromSemigroupToMonoid;
    SM a;
    bool is_unit;

    FromSemigroupToMonoid() : is_unit(true) {}
    template <class... Args> FromSemigroupToMonoid(Args... args) : a(args...), is_unit(false) {}

    inline static M op(M l, M r) {
        if (l.is_unit or r.is_unit) return l.is_unit ? r : l;
        return M(SM::op(l.a, r.a));
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
        if (x.is_unit) return os << "unit";
        return os << x.a;
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

#endif // KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP
