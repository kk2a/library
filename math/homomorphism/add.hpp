#ifndef KK2_MATH_HOMOMORPHISM_ADD_HPP
#define KK2_MATH_HOMOMORPHISM_ADD_HPP 1

namespace kk2 {

namespace homomorphism {

template <class S> using Add = S;

template <class S, class T> constexpr T AddMap(Add<S> f, T x) {
    return x.add(f);
}

template <class S> constexpr Add<S> AddComposition(Add<S> l, Add<S> r) {
    return l + r;
}

template <class S> Add<S> AddUnit() {
    constexpr static Add<S> e = Add<S>();
    return e;
}

} // namespace homomorphism

} // namespace kk2

#endif // KK2_MATH_HOMOMORPHISM_ADD_HPP
