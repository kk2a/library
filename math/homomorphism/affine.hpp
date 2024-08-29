#ifndef MATH_HOMOMORPHISM_AFFINE_HPP
#define MATH_HOMOMORPHISM_AFFINE_HPP 1

namespace kk2 {

namespace homomorphism {

template <class S>
struct Affine {
    S a, b; // x \mapsto ax + b
    Affine() : a(1), b(0) {};
    Affine(S a, S b) : a(a), b(b) {}
    friend ostream& operator<<(ostream& os, const Affine& aff) {
        os << aff.a << " " << aff.b;
        return os;
    }

    Affine& composition(const Affine& rhs) {
        return *this = Affine(a * rhs.a, a * rhs.b + b);
    }
};

template <class S, class T>
T AffineMap(Affine<S> f, T x) { return x.multiply(f.a).add(f.b); }

template <class S>
Affine<S> AffineComposition(Affine<S> l, Affine<S> r) { return l.composition(r); }

template <class S>
Affine<S> AffineUnit() { return Affine<S>(); }

} // namespace homomorphism

} // namespace kk2

#endif // MATH_HOMOMORPHISM_AFFINE_HPP
