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
  bundledCode: "#line 1 \"fps/bbb.hpp\"\n\n\n\n// f(X) / \\prod (X - a_i) = \\sum\
    \ c_i / (X - a_i)\n// return {c_i}\ntemplate <class mint, class FPS>\nvector<mint>\
    \ BBB(const vector<mint> &a, const FPS &f) {\n    if (a.empty() || f.empty())\
    \ return vector<mint>(a.size(), mint(0));\n    int n = (int)a.size();\n    MultiPointEvaluation<mint,\
    \ FPS> mpe(a);\n    FPS gp = mpe.pr[1].diff();\n    vector<mint> gpv = mpe.query(gp);\n\
    \    vector<mint> fv = mpe.query(f);\n    vector<mint> ret(n);\n    for (int i\
    \ = 0; i < n; i++) ret[i] = fv[i] / gpv[i];\n    return ret;\n}\n\n// f(X) / \\\
    prod (1 - a_i X) = \\sum c_i / (1- a_i X)\n// return {c_i}\ntemplate <class mint,\
    \ class FPS>\nvector<mint> BBB1(const vector<mint> &a, const FPS &f) {\n    if\
    \ (a.empty() || f.empty()) return vector<mint>(a.size(), mint(0));\n    int n\
    \ = (int)a.size();\n    vector<mint> ima(a.size());\n    mint prod = 1;\n    for\
    \ (int i = 0; i < (int)a.size(); i++) {\n        ima[i] = a[i].inv();\n      \
    \  prod *= -ima[i];\n    }\n    vector<mint> ret = BBB(ima, f);\n    for (int\
    \ i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n    return ret;\n}\n\n\n"
  code: "#ifndef FPS_BBB_HPP\n#define FPS_BBB_HPP 1\n\n// f(X) / \\prod (X - a_i)\
    \ = \\sum c_i / (X - a_i)\n// return {c_i}\ntemplate <class mint, class FPS>\n\
    vector<mint> BBB(const vector<mint> &a, const FPS &f) {\n    if (a.empty() ||\
    \ f.empty()) return vector<mint>(a.size(), mint(0));\n    int n = (int)a.size();\n\
    \    MultiPointEvaluation<mint, FPS> mpe(a);\n    FPS gp = mpe.pr[1].diff();\n\
    \    vector<mint> gpv = mpe.query(gp);\n    vector<mint> fv = mpe.query(f);\n\
    \    vector<mint> ret(n);\n    for (int i = 0; i < n; i++) ret[i] = fv[i] / gpv[i];\n\
    \    return ret;\n}\n\n// f(X) / \\prod (1 - a_i X) = \\sum c_i / (1- a_i X)\n\
    // return {c_i}\ntemplate <class mint, class FPS>\nvector<mint> BBB1(const vector<mint>\
    \ &a, const FPS &f) {\n    if (a.empty() || f.empty()) return vector<mint>(a.size(),\
    \ mint(0));\n    int n = (int)a.size();\n    vector<mint> ima(a.size());\n   \
    \ mint prod = 1;\n    for (int i = 0; i < (int)a.size(); i++) {\n        ima[i]\
    \ = a[i].inv();\n        prod *= -ima[i];\n    }\n    vector<mint> ret = BBB(ima,\
    \ f);\n    for (int i = 0; i < n; i++) ret[i] *= -a[i] * prod;\n    return ret;\n\
    }\n\n#endif // FPS_BBB_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/bbb.hpp
  requiredBy: []
  timestamp: '2024-05-11 18:03:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/bbb.hpp
layout: document
redirect_from:
- /library/fps/bbb.hpp
- /library/fps/bbb.hpp.html
title: fps/bbb.hpp
---
