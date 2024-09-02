#ifndef MATH_HOMOMORPHISM_ADD_HPP
#define MATH_HOMOMORPHISM_ADD_HPP 1

namespace kk2 {

namespace homomorphism {

template <class S>
using Add = S;

template <class S, class T>
T AddMap(Add<S> f, T x) { return x.add(f); }

template <class S>
Add<S> AddComposition(Add<S> l, Add<S> r) { return l + r; }

template <class S>
Add<S> AddUnit() { return Add<S>(); }

} // namespace homomorphism

} // namespace kk2

#endif // MATH_HOMOMORPHISM_ADD_HPP