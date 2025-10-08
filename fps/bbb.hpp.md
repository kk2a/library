---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/poly_multi_eval.hpp
    title: fps/poly_multi_eval.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki/yuki_1510.test.cpp
    title: verify/yuki/yuki_1510.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/bbb.hpp\"\n\n\n\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"fps/poly_multi_eval.hpp\"\n\n\n\n#include <functional>\n#line 6 \"\
    fps/poly_multi_eval.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type> struct SubProductTree {\n    int _n, size;\n   \
    \ std::vector<int> l, r;\n    std::vector<FPS> pr;\n    std::vector<mint> v;\n\
    \    FPS f;\n\n    SubProductTree(const std::vector<mint> &v_) : _n(int(v_.size())),\
    \ v(v_) {\n        size = 1;\n        while (size < _n) size <<= 1;\n        pr.resize(size\
    \ << 1);\n        l.resize(size << 1, _n);\n        r.resize(size << 1, _n);\n\
    \        build();\n    }\n\n    SubProductTree(const std::vector<mint> &v_, const\
    \ FPS &f_) : SubProductTree(v_) {\n        this->f = f_;\n    }\n\n    void set(const\
    \ FPS &f_) { this->f = f_; }\n\n    void build() {\n        for (int i = 0; i\
    \ < _n; i++) {\n            l[i + size] = i;\n            r[i + size] = i + 1;\n\
    \            pr[i + size] = {-v[i], 1};\n        }\n        for (int i = size\
    \ - 1; i > 0; i--) {\n            l[i] = l[i << 1 | 0];\n            r[i] = r[i\
    \ << 1 | 1];\n            if (pr[i << 1 | 0].empty()) continue;\n            else\
    \ if (pr[i << 1 | 1].empty()) pr[i] = pr[i << 1 | 0];\n            else pr[i]\
    \ = pr[i << 1 | 0] * pr[i << 1 | 1];\n        }\n    }\n\n    std::vector<mint>\
    \ query(const FPS &f) {\n        this->f = f;\n        return query();\n    }\n\
    \n    std::vector<mint> query() {\n        if (f.empty() || !_n) return FPS(_n,\
    \ mint(0));\n        std::vector<mint> ret;\n        ret.reserve(_n);\n      \
    \  auto rec = [&](auto self, FPS a, int idx) -> void {\n            if (l[idx]\
    \ == r[idx]) return;\n            a %= pr[idx];\n            if (a.size() <= 64u)\
    \ {\n                for (int i = l[idx]; i < r[idx]; i++) { ret.push_back(a.eval(v[i]));\
    \ }\n                return;\n            }\n            self(self, a, idx <<\
    \ 1 | 0);\n            self(self, a, idx << 1 | 1);\n        };\n        rec(rec,\
    \ f, 1);\n        return ret;\n    }\n};\n\ntemplate <class FPS, class mint =\
    \ typename FPS::value_type>\nstd::vector<mint> MultiEval(const std::vector<mint>\
    \ &v, const FPS &f) {\n    SubProductTree<FPS> mpe(v, f);\n    return mpe.query();\n\
    }\n\n} // namespace kk2\n\n\n#line 8 \"fps/bbb.hpp\"\n\nnamespace kk2 {\n\n//\
    \ f(X) / \\prod (X - a_i) = \\sum c_i / (X - a_i)\n// return {c_i}\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nstd::vector<mint> BBB(const std::vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return std::vector<mint>(a.size(),\
    \ mint());\n    int n = (int)a.size();\n    SubProductTree<FPS> mpe(a);\n    FPS\
    \ gp = mpe.pr[1].diff();\n    std::vector<mint> gpv = mpe.query(gp);\n    std::vector<mint>\
    \ fv = mpe.query(f);\n    std::vector<mint> ret(n);\n    for (int i = 0; i < n;\
    \ i++) ret[i] = fv[i] / gpv[i];\n    return ret;\n}\n\n// f(X) / \\prod (1 - a_i\
    \ X) = \\sum c_i / (1- a_i X)\n// return {c_i}\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nstd::vector<mint> BBB1(const std::vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return std::vector<mint>(a.size(),\
    \ mint(0));\n    int n = (int)a.size();\n    std::vector<mint> ima(a.size());\n\
    \    mint prod = 1;\n    for (int i = 0; i < (int)a.size(); i++) {\n        ima[i]\
    \ = a[i].inv();\n        prod *= -ima[i];\n    }\n    std::vector<mint> ret =\
    \ BBB(ima, f);\n    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n    return\
    \ ret;\n}\n\n// f(X) / \\prod (X - a_i)^d_i =  \\sum c_i,j / (X - a_i)^j\n// return\
    \ {c_i,j}\ntemplate <class FPS, class mint = typename FPS::value_type> std::vector<std::vector<mint>>\n\
    BBB(const std::vector<mint> &a, const std::vector<mint> &d, const FPS &f) {\n\
    \    // hoge\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_BBB_HPP\n#define KK2_FPS_BBB_HPP 1\n\n#include <utility>\n\
    #include <vector>\n\n#include \"poly_multi_eval.hpp\"\n\nnamespace kk2 {\n\n//\
    \ f(X) / \\prod (X - a_i) = \\sum c_i / (X - a_i)\n// return {c_i}\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nstd::vector<mint> BBB(const std::vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return std::vector<mint>(a.size(),\
    \ mint());\n    int n = (int)a.size();\n    SubProductTree<FPS> mpe(a);\n    FPS\
    \ gp = mpe.pr[1].diff();\n    std::vector<mint> gpv = mpe.query(gp);\n    std::vector<mint>\
    \ fv = mpe.query(f);\n    std::vector<mint> ret(n);\n    for (int i = 0; i < n;\
    \ i++) ret[i] = fv[i] / gpv[i];\n    return ret;\n}\n\n// f(X) / \\prod (1 - a_i\
    \ X) = \\sum c_i / (1- a_i X)\n// return {c_i}\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nstd::vector<mint> BBB1(const std::vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return std::vector<mint>(a.size(),\
    \ mint(0));\n    int n = (int)a.size();\n    std::vector<mint> ima(a.size());\n\
    \    mint prod = 1;\n    for (int i = 0; i < (int)a.size(); i++) {\n        ima[i]\
    \ = a[i].inv();\n        prod *= -ima[i];\n    }\n    std::vector<mint> ret =\
    \ BBB(ima, f);\n    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n    return\
    \ ret;\n}\n\n// f(X) / \\prod (X - a_i)^d_i =  \\sum c_i,j / (X - a_i)^j\n// return\
    \ {c_i,j}\ntemplate <class FPS, class mint = typename FPS::value_type> std::vector<std::vector<mint>>\n\
    BBB(const std::vector<mint> &a, const std::vector<mint> &d, const FPS &f) {\n\
    \    // hoge\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_BBB_HPP\n"
  dependsOn:
  - fps/poly_multi_eval.hpp
  isVerificationFile: false
  path: fps/bbb.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki/yuki_1510.test.cpp
documentation_of: fps/bbb.hpp
layout: document
redirect_from:
- /library/fps/bbb.hpp
- /library/fps/bbb.hpp.html
title: fps/bbb.hpp
---
