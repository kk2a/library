---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
    title: verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/chirp_Z.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\n// return f(aw^0), f(aw^1), ..., f(aw^(n - 1))\n\
    template <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
    \ ChirpZ(const FPS &f_, mint w, int n = -1, mint a = 1) {\n    FPS f(f_.begin(),\
    \ f_.end());\n    if (n == -1) n = f.size();\n    if (f.empty() || n == 0) return\
    \ std::vector<mint>(n, mint(0));\n    int m = f.size();\n    if (a != mint(1))\
    \ {\n        mint x = 1;\n        for (int i = 0; i < m; i++) {\n            f[i]\
    \ *= x;\n            x *= a;\n        }\n    }\n    if (w == mint(0)) {\n    \
    \    std::vector<mint> g(n, f[0]);\n        for (int i = 1; i < m; i++) g[0] +=\
    \ f[i];\n        return g;\n    }\n    FPS wc(n + m), iwc(std::max(n, m));\n \
    \   mint ws = 1, iw = w.inv(), iws = 1;\n    wc[0] = iwc[0] = 1;\n    for (int\
    \ i = 1; i < n + m; i++) {\n        wc[i] = ws * wc[i - 1];\n        ws *= w;\n\
    \    }\n    for (int i = 1; i < std::max(n, m); i++) {\n        iwc[i] = iws *\
    \ iwc[i - 1];\n        iws *= iw;\n    }\n    for (int i = 0; i < m; i++) f[i]\
    \ *= iwc[i];\n    std::reverse(std::begin(f), std::end(f));\n    FPS g = f * wc;\n\
    \    std::vector<mint> ret{std::begin(g) + m - 1, std::begin(g) + m + n - 1};\n\
    \    for (int i = 0; i < n; i++) ret[i] *= iwc[i];\n    return ret;\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_CHIRP_Z_HPP\n#define KK2_FPS_CHIRP_Z_HPP 1\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace kk2 {\n\n// return f(aw^0), f(aw^1), ..., f(aw^(n\
    \ - 1))\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
    \ ChirpZ(const FPS &f_, mint w, int n = -1, mint a = 1) {\n    FPS f(f_.begin(),\
    \ f_.end());\n    if (n == -1) n = f.size();\n    if (f.empty() || n == 0) return\
    \ std::vector<mint>(n, mint(0));\n    int m = f.size();\n    if (a != mint(1))\
    \ {\n        mint x = 1;\n        for (int i = 0; i < m; i++) {\n            f[i]\
    \ *= x;\n            x *= a;\n        }\n    }\n    if (w == mint(0)) {\n    \
    \    std::vector<mint> g(n, f[0]);\n        for (int i = 1; i < m; i++) g[0] +=\
    \ f[i];\n        return g;\n    }\n    FPS wc(n + m), iwc(std::max(n, m));\n \
    \   mint ws = 1, iw = w.inv(), iws = 1;\n    wc[0] = iwc[0] = 1;\n    for (int\
    \ i = 1; i < n + m; i++) {\n        wc[i] = ws * wc[i - 1];\n        ws *= w;\n\
    \    }\n    for (int i = 1; i < std::max(n, m); i++) {\n        iwc[i] = iws *\
    \ iwc[i - 1];\n        iws *= iw;\n    }\n    for (int i = 0; i < m; i++) f[i]\
    \ *= iwc[i];\n    std::reverse(std::begin(f), std::end(f));\n    FPS g = f * wc;\n\
    \    std::vector<mint> ret{std::begin(g) + m - 1, std::begin(g) + m + n - 1};\n\
    \    for (int i = 0; i < n; i++) ret[i] *= iwc[i];\n    return ret;\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_FPS_CHIRP_Z_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/chirp_Z.hpp
  requiredBy: []
  timestamp: '2025-01-05 07:17:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
documentation_of: fps/chirp_Z.hpp
layout: document
redirect_from:
- /library/fps/chirp_Z.hpp
- /library/fps/chirp_Z.hpp.html
title: fps/chirp_Z.hpp
---
