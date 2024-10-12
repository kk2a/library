#ifndef MATH_HOMOMORPHISM_AFFINE_HPP
#define MATH_HOMOMORPHISM_AFFINE_HPP 1

#include <iostream>

namespace kk2 {

namespace homomorphism {

template <class S> struct Affine {
    S a, b; // x \mapsto ax + b
    constexpr Affine() : a(1), b(0) {};

    constexpr Affine(S a, S b) : a(a), b(b) {}

    template <class OStream>
    friend OStream &operator<<(OStream &os, const Affine &aff) {
        os << aff.a << " " << aff.b;
        return os;
    }
};

template <class S, class T> constexpr T AffineMap(Affine<S> f, T x) {
    return x.multiply(f.a).add(f.b);
}

template <class S> constexpr Affine<S> AffineComposition(Affine<S> l, Affine<S> r) {
    l.b = l.a * r.b + l.b;
    l.a = l.a * r.a;
    return l;
}

template <class S> Affine<S> AffineUnit() {
    constexpr static Affine<S> e = Affine<S>();
    return e;
}

} // namespace homomorphism

} // namespace kk2

#endif // MATH_HOMOMORPHISM_AFFINE_HPP
