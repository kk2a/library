---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/homomorphism/affine.hpp\"\n\n\n\n#include <iostream>\n\
    \nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S> struct Affine\
    \ {\n    S a, b; // x \\mapsto ax + b\n    constexpr Affine() : a(1), b(0) {};\n\
    \n    constexpr Affine(S a, S b) : a(a), b(b) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Affine &aff) {\n        os << aff.a << \" \" << aff.b;\n        return\
    \ os;\n    }\n};\n\ntemplate <class S, class T> constexpr T AffineMap(Affine<S>\
    \ f, T x) {\n    return x.multiply(f.a).add(f.b);\n}\n\ntemplate <class S> constexpr\
    \ Affine<S> AffineComposition(Affine<S> l, Affine<S> r) {\n    l.b = l.a * r.b\
    \ + l.b;\n    l.a = l.a * r.a;\n    return l;\n}\n\ntemplate <class S> Affine<S>\
    \ AffineUnit() {\n    constexpr static Affine<S> e = Affine<S>();\n    return\
    \ e;\n}\n\n} // namespace homomorphism\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_HOMOMORPHISM_AFFINE_HPP\n#define MATH_HOMOMORPHISM_AFFINE_HPP\
    \ 1\n\n#include <iostream>\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\n\
    template <class S> struct Affine {\n    S a, b; // x \\mapsto ax + b\n    constexpr\
    \ Affine() : a(1), b(0) {};\n\n    constexpr Affine(S a, S b) : a(a), b(b) {}\n\
    \n    friend std::ostream &operator<<(std::ostream &os, const Affine &aff) {\n\
    \        os << aff.a << \" \" << aff.b;\n        return os;\n    }\n};\n\ntemplate\
    \ <class S, class T> constexpr T AffineMap(Affine<S> f, T x) {\n    return x.multiply(f.a).add(f.b);\n\
    }\n\ntemplate <class S> constexpr Affine<S> AffineComposition(Affine<S> l, Affine<S>\
    \ r) {\n    l.b = l.a * r.b + l.b;\n    l.a = l.a * r.a;\n    return l;\n}\n\n\
    template <class S> Affine<S> AffineUnit() {\n    constexpr static Affine<S> e\
    \ = Affine<S>();\n    return e;\n}\n\n} // namespace homomorphism\n\n} // namespace\
    \ kk2\n\n#endif // MATH_HOMOMORPHISM_AFFINE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/affine.hpp
  requiredBy:
  - segment_tree/utility/affinesum.hpp
  timestamp: '2024-10-11 23:12:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
documentation_of: math/homomorphism/affine.hpp
layout: document
redirect_from:
- /library/math/homomorphism/affine.hpp
- /library/math/homomorphism/affine.hpp.html
title: math/homomorphism/affine.hpp
---
