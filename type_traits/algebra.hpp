#ifndef KK2_TYPE_TRAITS_ALGEBRA_HPP
#define KK2_TYPE_TRAITS_ALGEBRA_HPP 1

#include <concepts>

namespace kk2 {

namespace algebra {

// These concepts describe the static interface expected by the library.
// Algebraic laws such as associativity cannot be checked by the type system.
//
// A user-defined monoid therefore needs only:
//
//   struct MyMonoid {
//       static MyMonoid op(const MyMonoid &, const MyMonoid &);
//       static MyMonoid unit();
//   };
//
// The return types are intentionally exact, so a typo such as returning the
// underlying scalar instead of MyMonoid is diagnosed at the concept boundary.
template <class T>
concept Semigroup = requires(const T &x, const T &y) {
    { T::op(x, y) } -> std::same_as<T>;
};

template <class T>
concept Monoid = Semigroup<T> && requires {
    { T::unit() } -> std::same_as<T>;
};

template <class T>
concept Group = Monoid<T> && requires(const T &x) {
    { T::inv(x) } -> std::same_as<T>;
};

template <class T>
concept CommutativeMonoid = Monoid<T> && requires {
    { T::commutative } -> std::convertible_to<bool>;
} && bool(T::commutative);

template <class T>
concept CommutativeGroup = Group<T> && requires {
    { T::commutative } -> std::convertible_to<bool>;
} && bool(T::commutative);

// An action specification owns the pair of algebraic types and the mapping
// between them. It is the interface required by lazy propagation structures.
template <class T>
concept Action =
    requires {
        typename T::A;
        typename T::S;
    } && Monoid<typename T::A> && Monoid<typename T::S>
    && requires(const typename T::A &f, const typename T::S &x) {
           { T::act(f, x) } -> std::same_as<typename T::S>;
       };

} // namespace algebra

} // namespace kk2

#endif // KK2_TYPE_TRAITS_ALGEBRA_HPP
