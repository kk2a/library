#ifndef KK2_MATH_MONOID_AFFINE_HPP
#define KK2_MATH_MONOID_AFFINE_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S>
struct Affine {
    static constexpr bool commutative = false;

    S a, b; // x \mapsto ax + b
    Affine() : a(S(1)), b(S(0)) {};

    Affine(S a, S b) : a(a), b(b) {}

    inline S eval(S x) const { return a * x + b; }

    // l \circ r
    inline static Affine op(Affine l, Affine r) { return Affine(l.a * r.a, l.a * r.b + l.b); }

    inline static Affine unit() { return Affine(); }

    inline static Affine inv(Affine f) { return Affine(S(1) / f.a, -f.b / f.a); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const Affine &aff) {
        return os << aff.a << " " << aff.b;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, Affine &aff) {
        return is >> aff.a >> aff.b;
    }

    bool operator==(const Affine &rhs) const { return a == rhs.a and b == rhs.b; }

    bool operator!=(const Affine &rhs) const { return not(*this == rhs); }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_AFFINE_HPP
