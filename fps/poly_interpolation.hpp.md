---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: fps/chirp_Z.hpp
    title: fps/chirp_Z.hpp
  - icon: ':warning:'
    path: fps/multi_eval.hpp
    title: fps/multi_eval.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan
    - https://yukicoder.me/wiki/%E9%80%86%E5%85%83
  bundledCode: "#line 1 \"fps/poly_interpolation.hpp\"\n\n\n\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n#line 1 \"fps/multi_eval.hpp\"\n\n\n\
    \n#line 6 \"fps/multi_eval.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nstruct SubProductTree {\n    int _n, size;\n\
    \    std::vector<int> l, r;\n    std::vector<FPS> pr;\n    std::vector<mint> v;\n\
    \    FPS f;\n\n    SubProductTree(const std::vector<mint> &v_) : _n(int(v_.size())),\
    \ v(v_) {\n        size = 1;\n        while (size < (unsigned int)(_n)) size <<=\
    \ 1;\n        pr.resize(size << 1);\n        l.resize(size << 1, _n);\n      \
    \  r.resize(size << 1, _n);\n        build();\n    }\n    SubProductTree(const\
    \ std::vector<mint> &v_, const FPS &f_) :\n        SubProductTree(v_) {\n    \
    \    this->f = f_;\n    }\n\n    void set(const FPS &f_) {\n        this->f =\
    \ f_;\n    }\n\n    void build() {\n        for (int i = 0; i < _n; i++) {\n \
    \           l[i + size] = i;\n            r[i + size] = i + 1;\n            pr[i\
    \ + size] = {-v[i], 1};\n        }\n        for (int i = size - 1; i > 0; i--)\
    \ {\n            l[i] = l[i << 1 | 0];\n            r[i] = r[i << 1 | 1];\n  \
    \          if (pr[i << 1 | 0].empty()) continue;\n            else if (pr[i <<\
    \ 1 | 1].empty()) pr[i] = pr[i << 1 | 0];\n            else pr[i] = pr[i << 1\
    \ | 0] * pr[i << 1 | 1];\n        }\n    }\n\n    std::vector<mint> query(const\
    \ FPS &f) {\n        this->f = f;\n        return query();\n    }\n\n    std::vector<mint>\
    \ query() {\n        if (f.empty() || !_n) return FPS(_n, mint(0));\n        std::vector<mint>\
    \ ret;\n        ret.reserve(_n);\n        auto rec = [&](auto self, FPS a, int\
    \ idx) -> void {\n            if (l[idx] == r[idx]) return;\n            a %=\
    \ pr[idx];\n            if ((int)a.size() <= 64) {\n                for (int i\
    \ = l[idx]; i < r[idx]; i++) {\n                    ret.push_back(a.eval(v[i]));\n\
    \                }\n                return;\n            }\n            self(self,\
    \ a, idx << 1 | 0);\n            self(self, a, idx << 1 | 1);\n        };\n  \
    \      rec(rec, f, 1);\n        return ret;\n    }\n};\n\ntemplate <class FPS,\
    \ class mint = typename FPS::value_type>\nstd::vector<mint> MultiEval(std::vector<mint>\
    \ v, const FPS& f) {\n    SubProductTree<FPS> mpe(v, f);\n    return mpe.query();\n\
    }\n\n} // namespace kk2\n\n\n#line 1 \"fps/chirp_Z.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"fps/chirp_Z.hpp\"\n\nnamespace kk2 {\n\n// return f(a w ^ 0), f(a w\
    \ ^ 1), ..., f(a w ^ (n - 1))\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    std::vector<mint> ChirpZ(const FPS& f_, mint w, int n = -1, mint a = 1) {\n  \
    \  FPS f(f_.begin(), f_.end());\n    if (n == -1) n = f.size();\n    if (f.empty()\
    \ || n == 0) return std::vector<mint>(n, mint(0));\n    int m = f.size();\n  \
    \  if (a != mint(1)) {\n        mint x = 1;\n        for (int i = 0; i < m; i++)\
    \ {\n            f[i] *= x;\n            x *= a;\n        }\n    }\n    if (w\
    \ == mint(0)) {\n        std::vector<mint> g(n, f[0]);\n        for (int i = 1;\
    \ i < m; i++) g[0] += f[i];\n        return g;\n    }\n    FPS wc(n + m), iwc(std::max(n,\
    \ m));\n    mint ws = 1, iw = w.inv(), iws = 1;\n    wc[0] = iwc[0] = 1;\n   \
    \ for (int i = 1; i < n + m; i++) {\n        wc[i] = ws * wc[i - 1];\n       \
    \ ws *= w;\n    }\n    for (int i = 1; i < std::max(n, m); i++) {\n        iwc[i]\
    \ = iws * iwc[i - 1];\n        iws *= iw;\n    }\n    for (int i = 0; i < m; i++)\
    \ f[i] *= iwc[i];\n    std::reverse(std::begin(f), std::end(f));\n    FPS g =\
    \ f * wc;\n    std::vector<mint> ret{std::begin(g) + m - 1, std::begin(g) + m\
    \ + n - 1};\n    for (int i = 0; i < n; i++) ret[i] *= iwc[i];\n    return ret;\
    \ \n}\n\n} // namespace kk2\n\n\n#line 9 \"fps/poly_interpolation.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS PolyInterpolation(const\
    \ std::vector<mint> &x,\n                      const std::vector<mint> &y) {\n\
    \    assert(x.size() == y.size());\n    SubProductTree<FPS> mpe(x);\n    FPS gp\
    \ = mpe.pr[1].diff();\n    std::vector<mint> vs = mpe.query(gp);\n    auto rec\
    \ = [&](auto self, int idx) -> FPS {\n        if (idx >= mpe.size) {  \n     \
    \       if (idx - mpe.size < (int)y.size()) {\n                return {y[idx -\
    \ mpe.size] / vs[idx - mpe.size]};\n            }\n            else return {mint(1)};\n\
    \        }\n        if (mpe.pr[idx << 1 | 0].empty()) return {};\n        else\
    \ if (mpe.pr[idx << 1 | 1].empty())\n            return self(self, idx << 1 |\
    \ 0);\n        return self(self, idx << 1 | 0) * mpe.pr[idx << 1 | 1] +\n    \
    \           self(self, idx << 1 | 1) * mpe.pr[idx << 1 | 0];\n    };\n    return\
    \ rec(rec, 1);\n}\n\n// reference:\n// https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS PolyInterpolationGeo(const\
    \ mint &a, const mint &r,\n                         const std::vector<mint> &y)\
    \ {\n    if (y.empty()) return {};\n    if (y.size() == 1) return FPS{y[0]};\n\
    \    assert(a != mint(0) && r != mint(0) && r != mint(1));\n\n    int n = (int)y.size();\n\
    \    // https://yukicoder.me/wiki/%E9%80%86%E5%85%83\n    std::vector<mint> s(n\
    \ + 1), invs(n), pre(n + 1);\n    s[0] = pre[0] = invs[0] = 1;\n    mint q = r;\n\
    \    for (int i = 1; i < n + 1; i++) {\n        s[i] = s[i - 1] * (-q + 1);\n\
    \        pre[i] = pre[i - 1] * s[i];\n        q *= r;\n    }\n    mint inv = pre[n\
    \ - 1].inv();\n    for (int i = n - 1; i >= 1; i--) {\n        invs[i] = inv *\
    \ pre[i - 1];\n        inv *= s[i];\n    }\n\n    std::vector<mint> w(n);\n  \
    \  q = 1;\n    int idx1 = n - 1, idx2 = 0;\n    w[n - 1] = r.pow(1ll * (n - 1)\
    \ * (n - 2) / 2).inv() * invs[idx1] * invs[idx2];\n    if ((n - 1) & 1) w[n -\
    \ 1] *= -1;\n    for (int i = n - 1; i > 0; i--) {\n        w[i - 1] = w[i] *\
    \ q * (-1) * \n                   s[idx1] * invs[idx1 - 1] *\n               \
    \    s[idx2] * invs[idx2 + 1];\n        q *= r;\n        idx1--; idx2++;\n   \
    \ }\n    for (int i = 0; i < n; i++) w[i] *= y[i];\n\n    FPS g{begin(w), end(w)};\n\
    \    std::vector<mint> tmp = ChirpZ(g, r, n);\n    FPS gq{begin(tmp), end(tmp)};\n\
    \    FPS prod(n);\n    q = 1;\n    mint plus = r;\n    prod[0] = 1;\n    for (int\
    \ i = 1; i < n; i++) {\n        prod[i] = s[n] * invs[i] * invs[n - i] * q;\n\
    \        if (i & 1) prod[i] *= -1;\n        q *= plus;\n        plus *= r;\n \
    \   }\n\n    FPS ret = (prod * gq).pre(n).rev();\n    if (a != mint(1)) {\n  \
    \      mint x = 1, inva = a.inv();\n        for (int i = 0; i < n; i++) {\n  \
    \          ret[i] *= x;\n            x *= inva;\n        }\n    }\n    return\
    \ ret;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_POLYNOMIAL_INTERPOLATION_HPP\n#define FPS_POLYNOMIAL_INTERPOLATION_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <vector>\n#include\
    \ \"multi_eval.hpp\"\n#include \"chirp_Z.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS PolyInterpolation(const\
    \ std::vector<mint> &x,\n                      const std::vector<mint> &y) {\n\
    \    assert(x.size() == y.size());\n    SubProductTree<FPS> mpe(x);\n    FPS gp\
    \ = mpe.pr[1].diff();\n    std::vector<mint> vs = mpe.query(gp);\n    auto rec\
    \ = [&](auto self, int idx) -> FPS {\n        if (idx >= mpe.size) {  \n     \
    \       if (idx - mpe.size < (int)y.size()) {\n                return {y[idx -\
    \ mpe.size] / vs[idx - mpe.size]};\n            }\n            else return {mint(1)};\n\
    \        }\n        if (mpe.pr[idx << 1 | 0].empty()) return {};\n        else\
    \ if (mpe.pr[idx << 1 | 1].empty())\n            return self(self, idx << 1 |\
    \ 0);\n        return self(self, idx << 1 | 0) * mpe.pr[idx << 1 | 1] +\n    \
    \           self(self, idx << 1 | 1) * mpe.pr[idx << 1 | 0];\n    };\n    return\
    \ rec(rec, 1);\n}\n\n// reference:\n// https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS PolyInterpolationGeo(const\
    \ mint &a, const mint &r,\n                         const std::vector<mint> &y)\
    \ {\n    if (y.empty()) return {};\n    if (y.size() == 1) return FPS{y[0]};\n\
    \    assert(a != mint(0) && r != mint(0) && r != mint(1));\n\n    int n = (int)y.size();\n\
    \    // https://yukicoder.me/wiki/%E9%80%86%E5%85%83\n    std::vector<mint> s(n\
    \ + 1), invs(n), pre(n + 1);\n    s[0] = pre[0] = invs[0] = 1;\n    mint q = r;\n\
    \    for (int i = 1; i < n + 1; i++) {\n        s[i] = s[i - 1] * (-q + 1);\n\
    \        pre[i] = pre[i - 1] * s[i];\n        q *= r;\n    }\n    mint inv = pre[n\
    \ - 1].inv();\n    for (int i = n - 1; i >= 1; i--) {\n        invs[i] = inv *\
    \ pre[i - 1];\n        inv *= s[i];\n    }\n\n    std::vector<mint> w(n);\n  \
    \  q = 1;\n    int idx1 = n - 1, idx2 = 0;\n    w[n - 1] = r.pow(1ll * (n - 1)\
    \ * (n - 2) / 2).inv() * invs[idx1] * invs[idx2];\n    if ((n - 1) & 1) w[n -\
    \ 1] *= -1;\n    for (int i = n - 1; i > 0; i--) {\n        w[i - 1] = w[i] *\
    \ q * (-1) * \n                   s[idx1] * invs[idx1 - 1] *\n               \
    \    s[idx2] * invs[idx2 + 1];\n        q *= r;\n        idx1--; idx2++;\n   \
    \ }\n    for (int i = 0; i < n; i++) w[i] *= y[i];\n\n    FPS g{begin(w), end(w)};\n\
    \    std::vector<mint> tmp = ChirpZ(g, r, n);\n    FPS gq{begin(tmp), end(tmp)};\n\
    \    FPS prod(n);\n    q = 1;\n    mint plus = r;\n    prod[0] = 1;\n    for (int\
    \ i = 1; i < n; i++) {\n        prod[i] = s[n] * invs[i] * invs[n - i] * q;\n\
    \        if (i & 1) prod[i] *= -1;\n        q *= plus;\n        plus *= r;\n \
    \   }\n\n    FPS ret = (prod * gq).pre(n).rev();\n    if (a != mint(1)) {\n  \
    \      mint x = 1, inva = a.inv();\n        for (int i = 0; i < n; i++) {\n  \
    \          ret[i] *= x;\n            x *= inva;\n        }\n    }\n    return\
    \ ret;\n}\n\n} // namespace kk2\n\n#endif // FPS_POLYNOMIAL_INTERPOLATION_HPP\n"
  dependsOn:
  - fps/multi_eval.hpp
  - fps/chirp_Z.hpp
  isVerificationFile: false
  path: fps/poly_interpolation.hpp
  requiredBy: []
  timestamp: '2024-09-09 21:04:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/poly_interpolation.hpp
layout: document
redirect_from:
- /library/fps/poly_interpolation.hpp
- /library/fps/poly_interpolation.hpp.html
title: fps/poly_interpolation.hpp
---
