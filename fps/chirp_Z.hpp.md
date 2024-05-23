---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/poly_interpolation.hpp
    title: fps/poly_interpolation.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/chirp_Z.hpp\"\n\n\n\n// return f(a w ^ 0), f(a w ^ 1),\
    \ ..., f(a w ^ (n - 1))\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    vector<mint> ChirpZ(FPS f, mint w, int n = -1, mint a = 1) {\n    if (n == -1)\
    \ n = f.size();\n    if (f.empty() || n == 0) return vector<mint>(n, mint(0));\n\
    \    int m = f.size();\n    if (a != 1) {\n        mint x = 1;\n        for (int\
    \ i = 0; i < m; i++) {\n            f[i] *= x;\n            x *= a;\n        }\n\
    \    }\n    if (w == 0) {\n        vector<mint> g(n, f[0]);\n        for (int\
    \ i = 1; i < m; i++) g[0] += f[i];\n        return g;\n    }\n    FPS wc(n + m),\
    \ iwc(max(n, m));\n    mint ws = 1, iw = w.inv(), iws = 1;\n    wc[0] = iwc[0]\
    \ = 1;\n    for (int i = 1; i < n + m; i++) {\n        wc[i] = ws * wc[i - 1];\n\
    \        ws *= w;\n    }\n    for (int i = 1; i < max(n, m); i++) {\n        iwc[i]\
    \ = iws * iwc[i - 1];\n        iws *= iw;\n    }\n    for (int i = 0; i < m; i++)\
    \ f[i] *= iwc[i];\n    reverse(begin(f), end(f));\n    FPS g = f * wc;\n    vector<mint>\
    \ ret{begin(g) + m - 1, begin(g) + m + n - 1};\n    for (int i = 0; i < n; i++)\
    \ ret[i] *= iwc[i];\n    return ret; \n}\n\n\n"
  code: "#ifndef FPS_CHIRP_Z_HPP\n#define FPS_CHIRP_Z_HPP 1\n\n// return f(a w ^ 0),\
    \ f(a w ^ 1), ..., f(a w ^ (n - 1))\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nvector<mint> ChirpZ(FPS f, mint w, int n = -1, mint a = 1)\
    \ {\n    if (n == -1) n = f.size();\n    if (f.empty() || n == 0) return vector<mint>(n,\
    \ mint(0));\n    int m = f.size();\n    if (a != 1) {\n        mint x = 1;\n \
    \       for (int i = 0; i < m; i++) {\n            f[i] *= x;\n            x *=\
    \ a;\n        }\n    }\n    if (w == 0) {\n        vector<mint> g(n, f[0]);\n\
    \        for (int i = 1; i < m; i++) g[0] += f[i];\n        return g;\n    }\n\
    \    FPS wc(n + m), iwc(max(n, m));\n    mint ws = 1, iw = w.inv(), iws = 1;\n\
    \    wc[0] = iwc[0] = 1;\n    for (int i = 1; i < n + m; i++) {\n        wc[i]\
    \ = ws * wc[i - 1];\n        ws *= w;\n    }\n    for (int i = 1; i < max(n, m);\
    \ i++) {\n        iwc[i] = iws * iwc[i - 1];\n        iws *= iw;\n    }\n    for\
    \ (int i = 0; i < m; i++) f[i] *= iwc[i];\n    reverse(begin(f), end(f));\n  \
    \  FPS g = f * wc;\n    vector<mint> ret{begin(g) + m - 1, begin(g) + m + n -\
    \ 1};\n    for (int i = 0; i < n; i++) ret[i] *= iwc[i];\n    return ret; \n}\n\
    \n#endif  // FPS_CHIRP_Z_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/chirp_Z.hpp
  requiredBy:
  - fps/poly_interpolation.hpp
  timestamp: '2024-05-23 16:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/chirp_Z.hpp
layout: document
redirect_from:
- /library/fps/chirp_Z.hpp
- /library/fps/chirp_Z.hpp.html
title: fps/chirp_Z.hpp
---
