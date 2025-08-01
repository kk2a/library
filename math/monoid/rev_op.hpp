#ifndef KK2_MATH_MONOID_REV_OP_HPP
#define KK2_MATH_MONOID_REV_OP_HPP 1

namespace kk2 {

namespace monoid {

template <class T> struct ReverseOp : public T {
    static constexpr bool commutative = T::commutative;
    using M = ReverseOp;
    using base = T;
    using T::T;
    ReverseOp(const T &t) : T(t) {}
    inline static M op(M l, M r) {
        return static_cast<M>(T::op(static_cast<T>(r), static_cast<T>(l)));
    }
    inline static M unit() { return static_cast<M>(T::unit()); }

    bool operator==(const M &rhs) const { return static_cast<T>(*this) == static_cast<T>(rhs); }
    bool operator!=(const M &rhs) const { return static_cast<T>(*this) != static_cast<T>(rhs); }
    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const M &x) {
        os << static_cast<T>(x);
        return os;
    }
    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, M &x) {
        is >> static_cast<T &>(x);
        return is;
    }
};

} // namespace monoid

} // namespace kk2

#endif // KK2_MATH_MONOID_REV_OP_HPP
