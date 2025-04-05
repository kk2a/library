#ifndef KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP
#define KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP 1

namespace kk2 {

namespace monoid {

template <class SM> struct FromSemigroupToMonoid {
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

    bool operator!=(const M &rhs) const { return !(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_FROM_SEMIGROUP_TO_MONOID_HPP
