#ifndef KK2_MATH_MONOID_AFFINE_HPP
#define KK2_MATH_MONOID_AFFINE_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace monoid {

template <class S> struct Affine {
    static constexpr bool commutative = false;
    using M = Affine;
    S a, b; // x \mapsto ax + b

    Affine() : a(S(1)), b(S(0)) {};
    Affine(S a, S b) : a(a), b(b) {}
    inline S eval(S x) const { return a * x + b; }
    // l \circ r
    inline static M op(M l, M r) { return M(l.a * r.a, l.a * r.b + l.b); }
    inline static M unit() { return M(); }
    inline static M inv(M f) { return M(S(1) / f.a, -f.b / f.a); }
    bool operator==(const M &rhs) const { return a == rhs.a and b == rhs.b; }
    bool operator!=(const M &rhs) const { return a != rhs.a or b != rhs.b; }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        return os << x.a << " " << x.b;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &x) {
        return is >> x.a >> x.b;
    }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_AFFINE_HPP
