#ifndef KK2_MATH_GROUP_PLUS_HPP
#define KK2_MATH_GROUP_PLUS_HPP 1

#include "../../type_traits/io.hpp"

namespace kk2 {

namespace group {

template <class S> struct Add {
    static constexpr bool commutative = true;
    using M = Add;
    S a;

    Add() : a(S()) {}

    Add(S a_) : a(a_) {}

    operator S() const { return a; }

    inline static M op(M l, M r) { return M(l.a + r.a); }

    inline static M inv(M x) { return M(-x.a); }

    inline static M unit() { return M(); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        return os << x.a;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &x) {
        return is >> x.a;
    }

    bool operator==(const M &rhs) const { return a == rhs.a; }

    bool operator!=(const M &rhs) const { return !(*this == rhs); }
};

} // namespace group

} // namespace kk2

#endif // KK2_MATH_GROUP_PLUS_HPP
