---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: fps/multi_eval.hpp
    title: fps/multi_eval.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/bbb.hpp\"\n\n\n\n#line 1 \"fps/multi_eval.hpp\"\n\n\n\
    \n\ntemplate <class FPS, class mint = typename FPS::value_type>\nstruct MultiPointEvaluation\
    \ {\n    int _n, size;\n    vector<int> l, r;\n    vector<FPS> pr;\n    vector<mint>\
    \ v;\n    FPS f;\n\n    MultiPointEvaluation(const vector<mint> &v_) : _n(int(v_.size())),\
    \ v(v_) {\n        size = 1;\n        while (size < (unsigned int)(_n)) size <<=\
    \ 1;\n        pr.resize(size << 1);\n        l.resize(size << 1, _n);\n      \
    \  r.resize(size << 1, _n);\n        build();\n    }\n    MultiPointEvaluation(const\
    \ vector<mint> &v_, const FPS &f_) :\n        MultiPointEvaluation(v_) {\n   \
    \     this->f = f_;\n    }\n\n    void set(const FPS &f_) {\n        this->f =\
    \ f_;\n    }\n\n    void build() {\n        for (int i = 0; i < _n; i++) {\n \
    \           l[i + size] = i;\n            r[i + size] = i + 1;\n            pr[i\
    \ + size] = {-v[i], 1};\n        }\n        for (int i = size - 1; i > 0; i--)\
    \ {\n            l[i] = l[i << 1 | 0];\n            r[i] = r[i << 1 | 1];\n  \
    \          if (pr[i << 1 | 0].empty()) continue;\n            else if (pr[i <<\
    \ 1 | 1].empty()) pr[i] = pr[i << 1 | 0];\n            else pr[i] = pr[i << 1\
    \ | 0] * pr[i << 1 | 1];\n        }\n    }\n\n    vector<mint> query(const FPS\
    \ &f) {\n        this->f = f;\n        return query();\n    }\n\n    vector<mint>\
    \ query() {\n        if (f.empty() || !_n) return FPS(_n, mint(0));\n        vector<mint>\
    \ ret;\n        ret.reserve(_n);\n        auto rec = [&](auto self, FPS a, int\
    \ idx) -> void {\n            if (l[idx] == r[idx]) return;\n            a %=\
    \ pr[idx];\n            if ((int)a.size() <= 64) {\n                for (int i\
    \ = l[idx]; i < r[idx]; i++) {\n                    ret.push_back(a.eval(v[i]));\n\
    \                }\n                return;\n            }\n            self(self,\
    \ a, idx << 1 | 0);\n            self(self, a, idx << 1 | 1);\n        };\n  \
    \      rec(rec, f, 1);\n        return ret;\n    }\n};\n\ntemplate <class FPS,\
    \ class mint = typename FPS::value_type>\nvector<mint> MultiEval(vector<mint>\
    \ v, FPS f) {\n    MultiPointEvaluation<mint, FPS> mpe(v, f);\n    return mpe.query();\n\
    }\n\n\n#line 5 \"fps/bbb.hpp\"\n\n// f(X) / \\prod (X - a_i) = \\sum c_i / (X\
    \ - a_i)\n// return {c_i}\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    vector<mint> BBB(const vector<mint> &a, const FPS &f) {\n    if (a.empty() ||\
    \ f.empty()) return vector<mint>(a.size(), mint(0));\n    int n = (int)a.size();\n\
    \    MultiPointEvaluation<FPS> mpe(a);\n    FPS gp = mpe.pr[1].diff();\n    vector<mint>\
    \ gpv = mpe.query(gp);\n    vector<mint> fv = mpe.query(f);\n    vector<mint>\
    \ ret(n);\n    for (int i = 0; i < n; i++) ret[i] = fv[i] / gpv[i];\n    return\
    \ ret;\n}\n\n// f(X) / \\prod (1 - a_i X) = \\sum c_i / (1- a_i X)\n// return\
    \ {c_i}\ntemplate <class FPS, class mint = typename FPS::value_type>\nvector<mint>\
    \ BBB1(const vector<mint> &a, const FPS &f) {\n    if (a.empty() || f.empty())\
    \ return vector<mint>(a.size(), mint(0));\n    int n = (int)a.size();\n    vector<mint>\
    \ ima(a.size());\n    mint prod = 1;\n    for (int i = 0; i < (int)a.size(); i++)\
    \ {\n        ima[i] = a[i].inv();\n        prod *= -ima[i];\n    }\n    vector<mint>\
    \ ret = BBB(ima, f);\n    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n\
    \    return ret;\n}\n\n\n"
  code: "#ifndef FPS_BBB_HPP\n#define FPS_BBB_HPP 1\n\n#include \"multi_eval.hpp\"\
    \n\n// f(X) / \\prod (X - a_i) = \\sum c_i / (X - a_i)\n// return {c_i}\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvector<mint> BBB(const vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return vector<mint>(a.size(),\
    \ mint(0));\n    int n = (int)a.size();\n    MultiPointEvaluation<FPS> mpe(a);\n\
    \    FPS gp = mpe.pr[1].diff();\n    vector<mint> gpv = mpe.query(gp);\n    vector<mint>\
    \ fv = mpe.query(f);\n    vector<mint> ret(n);\n    for (int i = 0; i < n; i++)\
    \ ret[i] = fv[i] / gpv[i];\n    return ret;\n}\n\n// f(X) / \\prod (1 - a_i X)\
    \ = \\sum c_i / (1- a_i X)\n// return {c_i}\ntemplate <class FPS, class mint =\
    \ typename FPS::value_type>\nvector<mint> BBB1(const vector<mint> &a, const FPS\
    \ &f) {\n    if (a.empty() || f.empty()) return vector<mint>(a.size(), mint(0));\n\
    \    int n = (int)a.size();\n    vector<mint> ima(a.size());\n    mint prod =\
    \ 1;\n    for (int i = 0; i < (int)a.size(); i++) {\n        ima[i] = a[i].inv();\n\
    \        prod *= -ima[i];\n    }\n    vector<mint> ret = BBB(ima, f);\n    for\
    \ (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n    return ret;\n}\n\n#endif\
    \ // FPS_BBB_HPP\n"
  dependsOn:
  - fps/multi_eval.hpp
  isVerificationFile: false
  path: fps/bbb.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/bbb.hpp
layout: document
redirect_from:
- /library/fps/bbb.hpp
- /library/fps/bbb.hpp.html
title: fps/bbb.hpp
---