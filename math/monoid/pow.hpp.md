---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    type: Depends on
  - files:
    - filename: bsgs.hpp
      icon: LIBRARY_NO_TESTS
      path: math/monoid/bsgs.hpp
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MONOID_POW_HPP\n#define KK2_MATH_MONOID_POW_HPP 1\n\n\
      #include \"../../type_traits/algebra.hpp\"\n\nnamespace kk2 {\n\nnamespace monoid\
      \ {\n\ntemplate <algebra::Monoid M> M pow(M a, long long n) {\n    M res = M::unit();\n\
      \    while (n > 0) {\n        if (n & 1) res = M::op(res, a);\n        if (n\
      \ >>= 1) a = M::op(a, a);\n    }\n    return res;\n}\n\n} // namespace monoid\n\
      \n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_POW_HPP\n"
    name: default
  - code: "#line 1 \"math/monoid/pow.hpp\"\n\n\n\n#line 1 \"type_traits/algebra.hpp\"\
      \n\n\n\n#include <concepts>\n\nnamespace kk2 {\n\nnamespace algebra {\n\n//\
      \ These concepts describe the static interface expected by the library.\n//\
      \ Algebraic laws such as associativity cannot be checked by the type system.\n\
      //\n// A user-defined monoid therefore needs only:\n//\n//   struct MyMonoid\
      \ {\n//       static MyMonoid op(const MyMonoid &, const MyMonoid &);\n//  \
      \     static MyMonoid unit();\n//   };\n//\n// The return types are intentionally\
      \ exact, so a typo such as returning the\n// underlying scalar instead of MyMonoid\
      \ is diagnosed at the concept boundary.\ntemplate <class T>\nconcept Semigroup\
      \ = requires(const T &x, const T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> && requires {\n    {\
      \ T::unit() } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept Group =\
      \ Monoid<T> && requires(const T &x) {\n    { T::inv(x) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept CommutativeMonoid = Monoid<T> && requires\
      \ {\n    { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \ntemplate <class T>\nconcept CommutativeGroup = Group<T> && requires {\n  \
      \  { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \n// An action specification owns the pair of algebraic types and the mapping\n\
      // between them. It is the interface required by lazy propagation structures.\n\
      template <class T>\nconcept Action =\n    requires {\n        typename T::A;\n\
      \        typename T::S;\n    } && Monoid<typename T::A> && Monoid<typename T::S>\n\
      \    && requires(const typename T::A &f, const typename T::S &x) {\n       \
      \    { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n} // namespace\
      \ algebra\n\n} // namespace kk2\n\n\n#line 5 \"math/monoid/pow.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace monoid {\n\ntemplate <algebra::Monoid M> M pow(M a, long\
      \ long n) {\n    M res = M::unit();\n    while (n > 0) {\n        if (n & 1)\
      \ res = M::op(res, a);\n        if (n >>= 1) a = M::op(a, a);\n    }\n    return\
      \ res;\n}\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/monoid/pow.hpp
  pathExtension: hpp
  requiredBy:
  - math/monoid/bsgs.hpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/pow.hpp
layout: document
---
