---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: pow.hpp
      icon: LIBRARY_NO_TESTS
      path: math/monoid/pow.hpp
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - math/monoid/pow.hpp
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MONOID_BSGS_HPP\n#define KK2_MATH_MONOID_BSGS_HPP 1\n\n\
      #include <cmath>\n#include <unordered_set>\n\n#include \"pow.hpp\"\n\nnamespace\
      \ kk2 {\n\n// if there exists 0 <= l < n s.t. s^l = t, return min{0 <= l < n\
      \ : s^l = t}\n// otherwise, return -1\ntemplate <class M,\n          M (*op)(M,\
      \ M),\n          M (*e)(),\n          class S,\n          S (*act)(M, S),\n\
      \          class Set = std::unordered_set<S>>\nlong long bsgs(S s, S t, M x,\
      \ long long n) {\n    if (n <= 0) return -1;\n    if (s == t) return 0;\n  \
      \  // \u3053\u3053\u306F\u9069\u5F53\n    long long m = std::sqrt(n);\n    Set\
      \ set;\n    S now = t;\n    for (long long i = 0; i < m; i++) {\n        now\
      \ = act(x, now);\n        set.insert(now);\n    }\n    M x_mth_pw = pow<M, op,\
      \ e>(x, m);\n    now = s;\n    for (long long i = 0; i * m < n; i++) {\n   \
      \     S next = act(x_mth_pw, now);\n        if (set.count(next)) {\n       \
      \     S tmp = now;\n            for (long long j = 0; j < m; j++) {\n      \
      \          if (tmp == t) return i * m + j;\n                if (j != m - 1)\
      \ tmp = act(x, tmp);\n            }\n        }\n        now = next;\n    }\n\
      \    return -1;\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_BSGS_HPP\n"
    name: default
  - code: "#line 1 \"math/monoid/bsgs.hpp\"\n\n\n\n#include <cmath>\n#include <unordered_set>\n\
      \n#line 1 \"math/monoid/pow.hpp\"\n\n\n\n#line 1 \"type_traits/algebra.hpp\"\
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
      template <class T>\nconcept Action = requires {\n    typename T::A;\n    typename\
      \ T::S;\n} && Monoid<typename T::A> && Monoid<typename T::S>\n    && requires(const\
      \ typename T::A &f, const typename T::S &x) {\n           { T::act(f, x) } ->\
      \ std::same_as<typename T::S>;\n       };\n\n} // namespace algebra\n\n} //\
      \ namespace kk2\n\n\n#line 5 \"math/monoid/pow.hpp\"\n\nnamespace kk2 {\n\n\
      namespace monoid {\n\ntemplate <algebra::Monoid M> M pow(M a, long long n) {\n\
      \    M res = M::unit();\n    while (n > 0) {\n        if (n & 1) res = M::op(res,\
      \ a);\n        if (n >>= 1) a = M::op(a, a);\n    }\n    return res;\n}\n\n\
      } // namespace monoid\n\n} // namespace kk2\n\n\n#line 8 \"math/monoid/bsgs.hpp\"\
      \n\nnamespace kk2 {\n\n// if there exists 0 <= l < n s.t. s^l = t, return min{0\
      \ <= l < n : s^l = t}\n// otherwise, return -1\ntemplate <class M,\n       \
      \   M (*op)(M, M),\n          M (*e)(),\n          class S,\n          S (*act)(M,\
      \ S),\n          class Set = std::unordered_set<S>>\nlong long bsgs(S s, S t,\
      \ M x, long long n) {\n    if (n <= 0) return -1;\n    if (s == t) return 0;\n\
      \    // \u3053\u3053\u306F\u9069\u5F53\n    long long m = std::sqrt(n);\n  \
      \  Set set;\n    S now = t;\n    for (long long i = 0; i < m; i++) {\n     \
      \   now = act(x, now);\n        set.insert(now);\n    }\n    M x_mth_pw = pow<M,\
      \ op, e>(x, m);\n    now = s;\n    for (long long i = 0; i * m < n; i++) {\n\
      \        S next = act(x_mth_pw, now);\n        if (set.count(next)) {\n    \
      \        S tmp = now;\n            for (long long j = 0; j < m; j++) {\n   \
      \             if (tmp == t) return i * m + j;\n                if (j != m -\
      \ 1) tmp = act(x, tmp);\n            }\n        }\n        now = next;\n   \
      \ }\n    return -1;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/monoid/bsgs.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/bsgs.hpp
layout: document
---
