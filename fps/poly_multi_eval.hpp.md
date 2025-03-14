---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/bbb.hpp
    title: fps/bbb.hpp
  - icon: ':x:'
    path: fps/poly_interpolation.hpp
    title: fps/poly_interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
    title: verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/poly_interpolation.test.cpp
    title: verify/yosupo_fps/poly_interpolation.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/poly_interpolation_geometric.test.cpp
    title: verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - icon: ':x:'
    path: verify/yuki/yuki_1510.test.cpp
    title: verify/yuki/yuki_1510.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/poly_multi_eval.hpp\"\n\n\n\n#include <functional>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type> struct SubProductTree {\n    int _n, size;\n    std::vector<int>\
    \ l, r;\n    std::vector<FPS> pr;\n    std::vector<mint> v;\n    FPS f;\n\n  \
    \  SubProductTree(const std::vector<mint> &v_) : _n(int(v_.size())), v(v_) {\n\
    \        size = 1;\n        while (size < _n) size <<= 1;\n        pr.resize(size\
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
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_POLY_MULTI_EVAL_HPP\n#define KK2_FPS_POLY_MULTI_EVAL_HPP\
    \ 1\n\n#include <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> struct SubProductTree {\n\
    \    int _n, size;\n    std::vector<int> l, r;\n    std::vector<FPS> pr;\n   \
    \ std::vector<mint> v;\n    FPS f;\n\n    SubProductTree(const std::vector<mint>\
    \ &v_) : _n(int(v_.size())), v(v_) {\n        size = 1;\n        while (size <\
    \ _n) size <<= 1;\n        pr.resize(size << 1);\n        l.resize(size << 1,\
    \ _n);\n        r.resize(size << 1, _n);\n        build();\n    }\n\n    SubProductTree(const\
    \ std::vector<mint> &v_, const FPS &f_) : SubProductTree(v_) {\n        this->f\
    \ = f_;\n    }\n\n    void set(const FPS &f_) { this->f = f_; }\n\n    void build()\
    \ {\n        for (int i = 0; i < _n; i++) {\n            l[i + size] = i;\n  \
    \          r[i + size] = i + 1;\n            pr[i + size] = {-v[i], 1};\n    \
    \    }\n        for (int i = size - 1; i > 0; i--) {\n            l[i] = l[i <<\
    \ 1 | 0];\n            r[i] = r[i << 1 | 1];\n            if (pr[i << 1 | 0].empty())\
    \ continue;\n            else if (pr[i << 1 | 1].empty()) pr[i] = pr[i << 1 |\
    \ 0];\n            else pr[i] = pr[i << 1 | 0] * pr[i << 1 | 1];\n        }\n\
    \    }\n\n    std::vector<mint> query(const FPS &f) {\n        this->f = f;\n\
    \        return query();\n    }\n\n    std::vector<mint> query() {\n        if\
    \ (f.empty() || !_n) return FPS(_n, mint(0));\n        std::vector<mint> ret;\n\
    \        ret.reserve(_n);\n        auto rec = [&](auto self, FPS a, int idx) ->\
    \ void {\n            if (l[idx] == r[idx]) return;\n            a %= pr[idx];\n\
    \            if (a.size() <= 64u) {\n                for (int i = l[idx]; i <\
    \ r[idx]; i++) { ret.push_back(a.eval(v[i])); }\n                return;\n   \
    \         }\n            self(self, a, idx << 1 | 0);\n            self(self,\
    \ a, idx << 1 | 1);\n        };\n        rec(rec, f, 1);\n        return ret;\n\
    \    }\n};\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
    \ MultiEval(const std::vector<mint> &v, const FPS &f) {\n    SubProductTree<FPS>\
    \ mpe(v, f);\n    return mpe.query();\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_POLY_MULTI_EVAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/poly_multi_eval.hpp
  requiredBy:
  - fps/bbb.hpp
  - fps/poly_interpolation.hpp
  timestamp: '2025-03-02 17:07:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yuki/yuki_1510.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
documentation_of: fps/poly_multi_eval.hpp
layout: document
redirect_from:
- /library/fps/poly_multi_eval.hpp
- /library/fps/poly_multi_eval.hpp.html
title: fps/poly_multi_eval.hpp
---
