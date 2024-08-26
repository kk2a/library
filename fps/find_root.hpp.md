---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: fps/mod_pow.hpp
    title: fps/mod_pow.hpp
  - icon: ':warning:'
    path: fps/poly_gcd.hpp
    title: fps/poly_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/find_root.hpp\"\n\n\n\n#line 1 \"fps/poly_gcd.hpp\"\n\
    \n\n\nnamespace kk2 {\n\nnamespace poly_gcd {\n\ntemplate <class FPS>\nusing Vec\
    \ = array<FPS, 2>;\n\ntemplate <class FPS>\nstruct mat_poly {\n    FPS a00, a01,\
    \ a10, a11;\n\n    mat_poly() = default;\n    mat_poly(FPS a00_, FPS a01_, FPS\
    \ a10_, FPS a11_)\n        : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}\n \
    \   \n    mat_poly& operator*=(const mat_poly& r) {\n        FPS A00 = a00 * r.a00\
    \ + a01 * r.a10;\n        FPS A01 = a00 * r.a01 + a01 * r.a11;\n        FPS A10\
    \ = a10 * r.a00 + a11 * r.a10;\n        FPS A11 = a10 * r.a01 + a11 * r.a11;\n\
    \        A00.shrink(); A01.shrink();\n        A10.shrink(); A11.shrink();\n  \
    \      swap(a00, A00); swap(a01, A01);\n        swap(a10, A10); swap(a11, A11);\n\
    \        return *this;\n    }\n\n    static mat_poly identity() {\n        return\
    \ mat_poly(FPS{1}, FPS(), FPS(), FPS{1});\n    }\n\n    mat_poly operator*(const\
    \ mat_poly& r) const {\n        return mat_poly(*this) *= r;\n    }\n};\n\ntemplate\
    \ <class FPS>\nVec<FPS> operator*(const mat_poly<FPS>& a, const Vec<FPS>& b) {\n\
    \    FPS x0 = a.a00 * b[0] + a.a01 * b[1];\n    FPS x1 = a.a10 * b[0] + a.a11\
    \ * b[1];\n    x0.shrink(); x1.shrink();\n    return {x0, x1};\n};\n\ntemplate\
    \ <class FPS>\nvoid InnerNaiveGcd(mat_poly<FPS>& a, Vec<FPS>& b) {\n    FPS quo\
    \ = b[0] / b[1];\n    FPS rem = b[0] - quo * b[1];\n    FPS x10 = a.a00 - quo\
    \ * a.a10;\n    FPS x11 = a.a01 - quo * a.a11;\n    rem.shrink();\n    x10.shrink();\
    \ x11.shrink();\n    swap(x10, a.a10); swap(x11, a.a11);\n    swap(x10, a.a00);\
    \ swap(x11, a.a01);\n    b = {b[1], rem};\n}\n\ntemplate <class FPS>\nmat_poly<FPS>\
    \ InnerHalfGcd(Vec<FPS> b) {\n    int n = (int)b[0].size(), m = (int)b[1].size();\n\
    \    int k = (n + 1) >> 1;\n    if (m <= k) return mat_poly<FPS>::identity();\n\
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
    \ // namespace kk2\n\n\n#line 1 \"fps/mod_pow.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    // return f ^ k mod g\ntemplate <class FPS, class mint = typename FPS::value_type,\
    \ class T>\nFPS mod_pow(T k, FPS f, FPS g) {\n    // assert(!is_signed_v<T> ||\
    \ k >= 0);\n    assert(!g.empty());\n\n    auto inv = g.rev().inv();\n    auto\
    \ quo = [&] (const FPS& poly) {\n        if (poly.size() < g.size()) return FPS{};\n\
    \        int n = poly.size() - g.size() + 1;\n        return (poly.rev().pre(n)\
    \ * inv.pre(n)).pre(n).rev();\n    };\n    FPS res{1}, b(f);\n    while (k) {\n\
    \        if (k & 1) {\n            res *= b;\n            res -= quo(res) * g;\n\
    \            res.shrink();\n        }\n        b *= b;\n        b -= quo(b) *\
    \ g;\n        b.shrink();\n        k >>= 1;\n    }\n    return res;\n}\n\n} //\
    \ namespace kk2\n\n\n#line 6 \"fps/find_root.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvector<mint> find_root(FPS\
    \ f) {\n    long long p = mint::getmod();\n    vector<mint> res;\n    if (p ==\
    \ 2) {\n        for (int i = 0; i < 2; i++) {\n            if (f.eval(mint(i))\
    \ == mint(0)) {\n                res.push_back(mint(i));\n            }\n    \
    \    }\n        return res;\n    }\n\n    vector<FPS> fs;\n    fs.push_back(PolyGcd(mod_pow(p,\
    \ FPS{0, 1}, f) - FPS{0, 1}, f));\n    mt19937_64 rng(time(0));\n    while (!fs.empty())\
    \ {\n        auto g = fs.back();\n        fs.pop_back();\n        if (g.size()\
    \ == 2) res.push_back(-g[0]);\n        if (g.size() <= 2) continue;\n        FPS\
    \ s = FPS{(long long)(rng() % p), 1};\n        FPS t = PolyGcd(mod_pow((p - 1)\
    \ / 2, s, g) - FPS{1}, g);\n        fs.push_back(t);\n        if (g.size() !=\
    \ t.size()) fs.push_back(g / t);\n    }\n    return res;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef FIND_ROOT_HPP\n#define FIND_ROOT_HPP 1\n\n#include \"poly_gcd.hpp\"\
    \n#include \"mod_pow.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nvector<mint> find_root(FPS f) {\n    long long\
    \ p = mint::getmod();\n    vector<mint> res;\n    if (p == 2) {\n        for (int\
    \ i = 0; i < 2; i++) {\n            if (f.eval(mint(i)) == mint(0)) {\n      \
    \          res.push_back(mint(i));\n            }\n        }\n        return res;\n\
    \    }\n\n    vector<FPS> fs;\n    fs.push_back(PolyGcd(mod_pow(p, FPS{0, 1},\
    \ f) - FPS{0, 1}, f));\n    mt19937_64 rng(time(0));\n    while (!fs.empty())\
    \ {\n        auto g = fs.back();\n        fs.pop_back();\n        if (g.size()\
    \ == 2) res.push_back(-g[0]);\n        if (g.size() <= 2) continue;\n        FPS\
    \ s = FPS{(long long)(rng() % p), 1};\n        FPS t = PolyGcd(mod_pow((p - 1)\
    \ / 2, s, g) - FPS{1}, g);\n        fs.push_back(t);\n        if (g.size() !=\
    \ t.size()) fs.push_back(g / t);\n    }\n    return res;\n}\n\n} // namespace\
    \ kk2\n\n#endif // FIND_ROOT_HPP\n"
  dependsOn:
  - fps/poly_gcd.hpp
  - fps/mod_pow.hpp
  isVerificationFile: false
  path: fps/find_root.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/find_root.hpp
layout: document
redirect_from:
- /library/fps/find_root.hpp
- /library/fps/find_root.hpp.html
title: fps/find_root.hpp
---
