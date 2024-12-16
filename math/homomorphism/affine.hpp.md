---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/homomorphism/affine.hpp\"\n\n\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class\
    \ S> struct Affine {\n    S a, b; // x \\mapsto ax + b\n    constexpr Affine()\
    \ : a(1), b(0) {};\n\n    constexpr Affine(S a, S b) : a(a), b(b) {}\n\n    constexpr\
    \ S apply(S x) const { return a * x + b; }\n\n    template <class OStream> friend\
    \ OStream &operator<<(OStream &os, const Affine &aff) {\n        os << aff.a <<\
    \ \" \" << aff.b;\n        return os;\n    }\n\n    template <class IStream> friend\
    \ IStream &operator>>(IStream &is, Affine &aff) {\n        is >> aff.a >> aff.b;\n\
    \        return is;\n    }\n};\n\ntemplate <class S, class T> constexpr T AffineMap(Affine<S>\
    \ f, T x) {\n    return x.multiply(f.a).add(f.b);\n}\n\ntemplate <class S> constexpr\
    \ Affine<S> AffineComposition(Affine<S> l, Affine<S> r) {\n    l.b = l.a * r.b\
    \ + l.b;\n    l.a = l.a * r.a;\n    return l;\n}\n\ntemplate <class S> Affine<S>\
    \ AffineUnit() {\n    constexpr static Affine<S> e = Affine<S>();\n    return\
    \ e;\n}\n\n} // namespace homomorphism\n\ntemplate <class S, class... Args>\n\
    std::vector<homomorphism::Affine<S>> GetVecAffine(int n, Args... args) {\n   \
    \ return std::vector<homomorphism::Affine<S>>(n, homomorphism::Affine<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<homomorphism::Affine<S>>>\
    \ GetVecAffine2D(int h, int w, Args... args) {\n    return std::vector<std::vector<homomorphism::Affine<S>>>(h,\
    \ GetVecAffine<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_HOMOMORPHISM_AFFINE_HPP\n#define MATH_HOMOMORPHISM_AFFINE_HPP\
    \ 1\n\n#include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace\
    \ homomorphism {\n\ntemplate <class S> struct Affine {\n    S a, b; // x \\mapsto\
    \ ax + b\n    constexpr Affine() : a(1), b(0) {};\n\n    constexpr Affine(S a,\
    \ S b) : a(a), b(b) {}\n\n    constexpr S apply(S x) const { return a * x + b;\
    \ }\n\n    template <class OStream> friend OStream &operator<<(OStream &os, const\
    \ Affine &aff) {\n        os << aff.a << \" \" << aff.b;\n        return os;\n\
    \    }\n\n    template <class IStream> friend IStream &operator>>(IStream &is,\
    \ Affine &aff) {\n        is >> aff.a >> aff.b;\n        return is;\n    }\n};\n\
    \ntemplate <class S, class T> constexpr T AffineMap(Affine<S> f, T x) {\n    return\
    \ x.multiply(f.a).add(f.b);\n}\n\ntemplate <class S> constexpr Affine<S> AffineComposition(Affine<S>\
    \ l, Affine<S> r) {\n    l.b = l.a * r.b + l.b;\n    l.a = l.a * r.a;\n    return\
    \ l;\n}\n\ntemplate <class S> Affine<S> AffineUnit() {\n    constexpr static Affine<S>\
    \ e = Affine<S>();\n    return e;\n}\n\n} // namespace homomorphism\n\ntemplate\
    \ <class S, class... Args>\nstd::vector<homomorphism::Affine<S>> GetVecAffine(int\
    \ n, Args... args) {\n    return std::vector<homomorphism::Affine<S>>(n, homomorphism::Affine<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<homomorphism::Affine<S>>>\
    \ GetVecAffine2D(int h, int w, Args... args) {\n    return std::vector<std::vector<homomorphism::Affine<S>>>(h,\
    \ GetVecAffine<S>(w, args...));\n}\n\n} // namespace kk2\n\n#endif // MATH_HOMOMORPHISM_AFFINE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/affine.hpp
  requiredBy:
  - segment_tree/utility/affinesum.hpp
  timestamp: '2024-10-14 15:56:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
documentation_of: math/homomorphism/affine.hpp
layout: document
redirect_from:
- /library/math/homomorphism/affine.hpp
- /library/math/homomorphism/affine.hpp.html
title: math/homomorphism/affine.hpp
---
