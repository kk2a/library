---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/find_root.hpp
    title: fps/find_root.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/poly_gcd.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace poly_gcd\
    \ {\n\ntemplate <class FPS>\nusing Vec = array<FPS, 2>;\n\ntemplate <class FPS>\n\
    struct mat_poly {\n    FPS a00, a01, a10, a11;\n\n    mat_poly() = default;\n\
    \    mat_poly(FPS a00_, FPS a01_, FPS a10_, FPS a11_)\n        : a00(a00_), a01(a01_),\
    \ a10(a10_), a11(a11_) {}\n    \n    mat_poly& operator*=(const mat_poly& r) {\n\
    \        FPS A00 = a00 * r.a00 + a01 * r.a10;\n        FPS A01 = a00 * r.a01 +\
    \ a01 * r.a11;\n        FPS A10 = a10 * r.a00 + a11 * r.a10;\n        FPS A11\
    \ = a10 * r.a01 + a11 * r.a11;\n        A00.shrink(); A01.shrink();\n        A10.shrink();\
    \ A11.shrink();\n        swap(a00, A00); swap(a01, A01);\n        swap(a10, A10);\
    \ swap(a11, A11);\n        return *this;\n    }\n\n    static mat_poly identity()\
    \ {\n        return mat_poly(FPS{1}, FPS(), FPS(), FPS{1});\n    }\n\n    mat_poly\
    \ operator*(const mat_poly& r) const {\n        return mat_poly(*this) *= r;\n\
    \    }\n};\n\ntemplate <class FPS>\nVec<FPS> operator*(const mat_poly<FPS>& a,\
    \ const Vec<FPS>& b) {\n    FPS x0 = a.a00 * b[0] + a.a01 * b[1];\n    FPS x1\
    \ = a.a10 * b[0] + a.a11 * b[1];\n    x0.shrink(); x1.shrink();\n    return {x0,\
    \ x1};\n};\n\ntemplate <class FPS>\nvoid InnerNaiveGcd(mat_poly<FPS>& a, Vec<FPS>&\
    \ b) {\n    FPS quo = b[0] / b[1];\n    FPS rem = b[0] - quo * b[1];\n    FPS\
    \ x10 = a.a00 - quo * a.a10;\n    FPS x11 = a.a01 - quo * a.a11;\n    rem.shrink();\n\
    \    x10.shrink(); x11.shrink();\n    swap(x10, a.a10); swap(x11, a.a11);\n  \
    \  swap(x10, a.a00); swap(x11, a.a01);\n    b = {b[1], rem};\n}\n\ntemplate <class\
    \ FPS>\nmat_poly<FPS> InnerHalfGcd(Vec<FPS> b) {\n    int n = (int)b[0].size(),\
    \ m = (int)b[1].size();\n    int k = (n + 1) >> 1;\n    if (m <= k) return mat_poly<FPS>::identity();\n\
    \    mat_poly<FPS> m1 = InnerHalfGcd(Vec<FPS>{b[0] >> k, b[1] >> k});\n    b =\
    \ m1 * b;\n    if ((int)b[1].size() <= k) return m1;\n    InnerNaiveGcd(m1, b);\n\
    \    if ((int)b[1].size() <= k) return m1;\n    int l = (int)b[0].size() - 1;\n\
    \    int j = 2 * k - l;\n    b[0] = b[0] >> j;\n    b[1] = b[1] >> j;\n    return\
    \ InnerHalfGcd(b) * m1;\n}\n\ntemplate <class FPS>\nmat_poly<FPS> InnerPolyGcd(const\
    \ FPS& a, const FPS& b) {\n    Vec<FPS> c{a, b};\n    c[0].shrink(); c[1].shrink();\n\
    \    int n = (int)c[0].size(), m = (int)c[1].size();\n    if (n < m) {\n     \
    \   mat_poly<FPS> ret = InnerPolyGcd(c[1], c[0]);\n        swap(ret.a00, ret.a01);\n\
    \        swap(ret.a10, ret.a11);\n        return ret;\n    }\n\n    mat_poly<FPS>\
    \ res = mat_poly<FPS>::identity();\n    while (1) {\n        mat_poly<FPS> m1\
    \ = InnerHalfGcd(c);\n        c = m1 * c;\n        if (c[1].empty()) return m1\
    \ * res;\n        InnerNaiveGcd(m1, c);\n        if (c[1].empty()) return m1 *\
    \ res;\n        res = m1 * res;\n    }\n}\n\ntemplate <class FPS>\nFPS PolyGcd(FPS\
    \ a, FPS b) {\n    Vec<FPS> c{a, b};\n    mat_poly<FPS> m = InnerPolyGcd(a, b);\n\
    \    c = m * c;\n    if (!c[0].empty()) {\n        auto coeff = c[0].back().inv();\n\
    \        for (auto &x : c[0]) x *= coeff;\n    }\n    return c[0];\n}\n\n\n//\
    \ f ^ {-1} mod g\ntemplate <class FPS>\npair<bool, FPS> PolyInv(FPS f, FPS g)\
    \ {\n    Vec<FPS> c{f, g};\n    mat_poly<FPS> m = InnerPolyGcd(f, g);\n    FPS\
    \ gcd_ = (m * c)[0];\n    if (gcd_.size() != 1) return {0, FPS()};\n    Vec<FPS>\
    \ x{FPS{1}, g};\n    return {1, ((m * x)[0] % g) * gcd_[0].inv()};\n}\n\n} //\
    \ namespace poly_gcd\nusing poly_gcd::PolyGcd;\nusing poly_gcd::PolyInv;\n\n}\
    \ // namespace kk2\n\n\n"
  code: "#ifndef POLY_GCD_HPP\n#define POLY_GCD_HPP 1\n\nnamespace kk2 {\n\nnamespace\
    \ poly_gcd {\n\ntemplate <class FPS>\nusing Vec = array<FPS, 2>;\n\ntemplate <class\
    \ FPS>\nstruct mat_poly {\n    FPS a00, a01, a10, a11;\n\n    mat_poly() = default;\n\
    \    mat_poly(FPS a00_, FPS a01_, FPS a10_, FPS a11_)\n        : a00(a00_), a01(a01_),\
    \ a10(a10_), a11(a11_) {}\n    \n    mat_poly& operator*=(const mat_poly& r) {\n\
    \        FPS A00 = a00 * r.a00 + a01 * r.a10;\n        FPS A01 = a00 * r.a01 +\
    \ a01 * r.a11;\n        FPS A10 = a10 * r.a00 + a11 * r.a10;\n        FPS A11\
    \ = a10 * r.a01 + a11 * r.a11;\n        A00.shrink(); A01.shrink();\n        A10.shrink();\
    \ A11.shrink();\n        swap(a00, A00); swap(a01, A01);\n        swap(a10, A10);\
    \ swap(a11, A11);\n        return *this;\n    }\n\n    static mat_poly identity()\
    \ {\n        return mat_poly(FPS{1}, FPS(), FPS(), FPS{1});\n    }\n\n    mat_poly\
    \ operator*(const mat_poly& r) const {\n        return mat_poly(*this) *= r;\n\
    \    }\n};\n\ntemplate <class FPS>\nVec<FPS> operator*(const mat_poly<FPS>& a,\
    \ const Vec<FPS>& b) {\n    FPS x0 = a.a00 * b[0] + a.a01 * b[1];\n    FPS x1\
    \ = a.a10 * b[0] + a.a11 * b[1];\n    x0.shrink(); x1.shrink();\n    return {x0,\
    \ x1};\n};\n\ntemplate <class FPS>\nvoid InnerNaiveGcd(mat_poly<FPS>& a, Vec<FPS>&\
    \ b) {\n    FPS quo = b[0] / b[1];\n    FPS rem = b[0] - quo * b[1];\n    FPS\
    \ x10 = a.a00 - quo * a.a10;\n    FPS x11 = a.a01 - quo * a.a11;\n    rem.shrink();\n\
    \    x10.shrink(); x11.shrink();\n    swap(x10, a.a10); swap(x11, a.a11);\n  \
    \  swap(x10, a.a00); swap(x11, a.a01);\n    b = {b[1], rem};\n}\n\ntemplate <class\
    \ FPS>\nmat_poly<FPS> InnerHalfGcd(Vec<FPS> b) {\n    int n = (int)b[0].size(),\
    \ m = (int)b[1].size();\n    int k = (n + 1) >> 1;\n    if (m <= k) return mat_poly<FPS>::identity();\n\
    \    mat_poly<FPS> m1 = InnerHalfGcd(Vec<FPS>{b[0] >> k, b[1] >> k});\n    b =\
    \ m1 * b;\n    if ((int)b[1].size() <= k) return m1;\n    InnerNaiveGcd(m1, b);\n\
    \    if ((int)b[1].size() <= k) return m1;\n    int l = (int)b[0].size() - 1;\n\
    \    int j = 2 * k - l;\n    b[0] = b[0] >> j;\n    b[1] = b[1] >> j;\n    return\
    \ InnerHalfGcd(b) * m1;\n}\n\ntemplate <class FPS>\nmat_poly<FPS> InnerPolyGcd(const\
    \ FPS& a, const FPS& b) {\n    Vec<FPS> c{a, b};\n    c[0].shrink(); c[1].shrink();\n\
    \    int n = (int)c[0].size(), m = (int)c[1].size();\n    if (n < m) {\n     \
    \   mat_poly<FPS> ret = InnerPolyGcd(c[1], c[0]);\n        swap(ret.a00, ret.a01);\n\
    \        swap(ret.a10, ret.a11);\n        return ret;\n    }\n\n    mat_poly<FPS>\
    \ res = mat_poly<FPS>::identity();\n    while (1) {\n        mat_poly<FPS> m1\
    \ = InnerHalfGcd(c);\n        c = m1 * c;\n        if (c[1].empty()) return m1\
    \ * res;\n        InnerNaiveGcd(m1, c);\n        if (c[1].empty()) return m1 *\
    \ res;\n        res = m1 * res;\n    }\n}\n\ntemplate <class FPS>\nFPS PolyGcd(FPS\
    \ a, FPS b) {\n    Vec<FPS> c{a, b};\n    mat_poly<FPS> m = InnerPolyGcd(a, b);\n\
    \    c = m * c;\n    if (!c[0].empty()) {\n        auto coeff = c[0].back().inv();\n\
    \        for (auto &x : c[0]) x *= coeff;\n    }\n    return c[0];\n}\n\n\n//\
    \ f ^ {-1} mod g\ntemplate <class FPS>\npair<bool, FPS> PolyInv(FPS f, FPS g)\
    \ {\n    Vec<FPS> c{f, g};\n    mat_poly<FPS> m = InnerPolyGcd(f, g);\n    FPS\
    \ gcd_ = (m * c)[0];\n    if (gcd_.size() != 1) return {0, FPS()};\n    Vec<FPS>\
    \ x{FPS{1}, g};\n    return {1, ((m * x)[0] % g) * gcd_[0].inv()};\n}\n\n} //\
    \ namespace poly_gcd\nusing poly_gcd::PolyGcd;\nusing poly_gcd::PolyInv;\n\n}\
    \ // namespace kk2\n\n#endif // poly_gcd.hpp\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/poly_gcd.hpp
  requiredBy:
  - fps/find_root.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/poly_gcd.hpp
layout: document
redirect_from:
- /library/fps/poly_gcd.hpp
- /library/fps/poly_gcd.hpp.html
title: fps/poly_gcd.hpp
---
