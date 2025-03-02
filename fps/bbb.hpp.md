---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
  code: "#ifndef KK2_FPS_BBB_HPP\n#define KK2_FPS_BBB_HPP 1\n\n#include <utility>\n\
    #include <vector>\n\n#include \"multi_eval.hpp\"\n\nnamespace kk2 {\n\n// f(X)\
    \ / \\prod (X - a_i) = \\sum c_i / (X - a_i)\n// return {c_i}\ntemplate <class\
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
    \ {c_i,j}\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<std::vector<mint>>\n\
    BBB(const std::vector<mint> &a, const std::vector<mint> &d, const FPS &f) {\n\
    \    // hoge\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_BBB_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/bbb.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/bbb.hpp
layout: document
redirect_from:
- /library/fps/bbb.hpp
- /library/fps/bbb.hpp.html
title: fps/bbb.hpp
---
