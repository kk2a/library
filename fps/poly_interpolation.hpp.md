---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan
    - https://yukicoder.me/wiki/%E9%80%86%E5%85%83
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: multi_eval.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_FPS_POLY_INTERPOLATION_HPP\n#define KK2_FPS_POLY_INTERPOLATION_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\n#include\
    \ \"chirp_Z.hpp\"\n#include \"multi_eval.hpp\"\n\nnamespace kk2 {\n\n// return\
    \ FPS f s.t. f(x[i]) = y[i] for all i\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS poly_interpolation(const std::vector<mint> &x, const std::vector<mint>\
    \ &y) {\n    assert(x.size() == y.size());\n    SubProductTree<FPS> mpe(x);\n\
    \    FPS gp = mpe.pr[1].diff();\n    std::vector<mint> vs = mpe.query(gp);\n \
    \   auto rec = [&](auto self, int idx) -> FPS {\n        if (idx >= mpe.size)\
    \ {\n            if (idx - mpe.size < (int)y.size()) {\n                return\
    \ {y[idx - mpe.size] / vs[idx - mpe.size]};\n            } else return {mint(1)};\n\
    \        }\n        if (mpe.pr[idx << 1 | 0].empty()) return {};\n        else\
    \ if (mpe.pr[idx << 1 | 1].empty()) return self(self, idx << 1 | 0);\n       \
    \ return self(self, idx << 1 | 0) * mpe.pr[idx << 1 | 1]\n               + self(self,\
    \ idx << 1 | 1) * mpe.pr[idx << 1 | 0];\n    };\n    return rec(rec, 1);\n}\n\n\
    // return FPS f s.t. f(ar^i) = y[i] for all i\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nFPS poly_interpolation_geo(const mint &a, const\
    \ mint &r, const std::vector<mint> &y) {\n    // reference:\n    // https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric#fn:Bostan\n\
    \n    if (y.empty()) return {};\n    if (y.size() == 1) return FPS{y[0]};\n  \
    \  assert(a != mint(0) && r != mint(0) && r != mint(1));\n\n    int n = (int)y.size();\n\
    \    // https://yukicoder.me/wiki/%E9%80%86%E5%85%83\n    std::vector<mint> s(n\
    \ + 1), invs(n), pre(n + 1);\n    s[0] = pre[0] = invs[0] = 1;\n    mint q = r;\n\
    \    for (int i = 1; i < n + 1; i++) {\n        s[i] = s[i - 1] * (-q + 1);\n\
    \        pre[i] = pre[i - 1] * s[i];\n        q *= r;\n    }\n    mint inv = pre[n\
    \ - 1].inv();\n    for (int i = n - 1; i >= 1; i--) {\n        invs[i] = inv *\
    \ pre[i - 1];\n        inv *= s[i];\n    }\n\n    std::vector<mint> w(n);\n  \
    \  q = 1;\n    int idx1 = n - 1, idx2 = 0;\n    w[n - 1] = r.pow(1ll * (n - 1)\
    \ * (n - 2) / 2).inv() * invs[idx1] * invs[idx2];\n    if ((n - 1) & 1) w[n -\
    \ 1] *= -1;\n    for (int i = n - 1; i > 0; i--) {\n        w[i - 1] = w[i] *\
    \ q * (-1) * s[idx1] * invs[idx1 - 1] * s[idx2] * invs[idx2 + 1];\n        q *=\
    \ r;\n        idx1--;\n        idx2++;\n    }\n    for (int i = 0; i < n; i++)\
    \ w[i] *= y[i];\n\n    FPS g{begin(w), end(w)};\n    std::vector<mint> tmp = ChirpZ(g,\
    \ r, n);\n    FPS gq{begin(tmp), end(tmp)};\n    FPS prod(n);\n    q = 1;\n  \
    \  mint plus = r;\n    prod[0] = 1;\n    for (int i = 1; i < n; i++) {\n     \
    \   prod[i] = s[n] * invs[i] * invs[n - i] * q;\n        if (i & 1) prod[i] *=\
    \ -1;\n        q *= plus;\n        plus *= r;\n    }\n\n    FPS ret = (prod *\
    \ gq).pre(n).rev();\n    if (a != mint(1)) {\n        mint x = 1, inva = a.inv();\n\
    \        for (int i = 0; i < n; i++) {\n            ret[i] *= x;\n           \
    \ x *= inva;\n        }\n    }\n    return ret;\n}\n\n} // namespace kk2\n\n#endif\
    \ // KK2_FPS_POLY_INTERPOLATION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/poly_interpolation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/poly_interpolation.hpp
layout: document
redirect_from:
- /library/fps/poly_interpolation.hpp
- /library/fps/poly_interpolation.hpp.html
title: fps/poly_interpolation.hpp
---
