---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/bbb.hpp
    title: fps/bbb.hpp
  - icon: ':warning:'
    path: fps/poly_interpolation.hpp
    title: fps/poly_interpolation.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/multi_eval.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nstruct MultiPointEvaluation\
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
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_MULTI_EVAL_HPP\n#define FPS_MULTI_EVAL_HPP 1\n\nnamespace kk2\
    \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nstruct MultiPointEvaluation\
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
    }\n\n} // namespace kk2\n\n#endif // FPS_MULTI_EVAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/multi_eval.hpp
  requiredBy:
  - fps/bbb.hpp
  - fps/poly_interpolation.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/multi_eval.hpp
layout: document
redirect_from:
- /library/fps/multi_eval.hpp
- /library/fps/multi_eval.hpp.html
title: fps/multi_eval.hpp
---