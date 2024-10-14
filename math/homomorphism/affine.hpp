#ifndef MATH_HOMOMORPHISM_AFFINE_HPP
#define MATH_HOMOMORPHISM_AFFINE_HPP 1

#include <iostream>
#include <vector>

namespace kk2 {

namespace homomorphism {

template <class S> struct Affine {
    S a, b; // x \mapsto ax + b
    constexpr Affine() : a(1), b(0) {};

    constexpr Affine(S a, S b) : a(a), b(b) {}

    constexpr S apply(S x) const { return a * x + b; }

    template <class OStream> friend OStream &operator<<(OStream &os, const Affine &aff) {
        os << aff.a << " " << aff.b;
        return os;
    }

    template <class IStream> friend IStream &operator>>(IStream &is, Affine &aff) {
        is >> aff.a >> aff.b;
        return is;
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

template <class S, class... Args>
std::vector<homomorphism::Affine<S>> GetVecAffine(int n, Args... args) {
    return std::vector<homomorphism::Affine<S>>(n, homomorphism::Affine<S>(args...));
}

template <class S, class... Args>
std::vector<std::vector<homomorphism::Affine<S>>> GetVecAffine2D(int h, int w, Args... args) {
    return std::vector<std::vector<homomorphism::Affine<S>>>(h, GetVecAffine<S>(w, args...));
}

} // namespace kk2

#endif // MATH_HOMOMORPHISM_AFFINE_HPP
