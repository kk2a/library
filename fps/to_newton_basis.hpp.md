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
  bundledCode: "#line 1 \"fps/to_newton_basis.hpp\"\n\n\n\n// return b s.t. f(X) =\
    \ \\sum_{i = 0} ^ {n - 1} b_i \\prod_{j = 0} ^ {i - 1} (X - p_j)\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nvector<mint> convert_to_newton_basis(FPS\
    \ f, vector<mint> p) {\n    int n = (int)f.size();\n    assert(n == (int)p.size());\n\
    \n    int m = 1;\n    while (m < n) m <<= 1;\n\n    vector<FPS> buf(m << 1);\n\
    \    for (int i = 0; i < n; i++) {\n        buf[m + i] = {-p[i], 1};\n    }\n\
    \    for (int i = m - 1; i > 0; i--) {\n        if (((i + 1) & -(i + 1)) == i\
    \ + 1) continue;\n        if (buf[i << 1 | 1].empty()) {\n            buf[i] =\
    \ buf[i << 1 | 0];\n        }\n        else {\n            buf[i] = buf[i << 1\
    \ | 0] * buf[i << 1 | 1];\n        }\n    }\n    buf[1] = f;\n    for (int i =\
    \ 1; i < m; i++) {\n        if (buf[i].empty()) continue;\n        buf[i << 1\
    \ | 1] = buf[i] / buf[i << 1 | 0];\n        buf[i << 1 | 0] = buf[i] % buf[i <<\
    \ 1 | 0];\n    }\n    vector<mint> b(n);\n    for (int i = 0; i < n; i++) {\n\
    \        b[i] = buf[m + i].empty() ? 0 : buf[m + i][0];\n    }\n    return b;\n\
    }\n\n\n"
  code: "#ifndef FPS_TO_NEWTON_BASIS_HPP\n#define FPS_TO_NEWTON_BASIS_HPP 1\n\n//\
    \ return b s.t. f(X) = \\sum_{i = 0} ^ {n - 1} b_i \\prod_{j = 0} ^ {i - 1} (X\
    \ - p_j)\ntemplate <class FPS, class mint = typename FPS::value_type>\nvector<mint>\
    \ convert_to_newton_basis(FPS f, vector<mint> p) {\n    int n = (int)f.size();\n\
    \    assert(n == (int)p.size());\n\n    int m = 1;\n    while (m < n) m <<= 1;\n\
    \n    vector<FPS> buf(m << 1);\n    for (int i = 0; i < n; i++) {\n        buf[m\
    \ + i] = {-p[i], 1};\n    }\n    for (int i = m - 1; i > 0; i--) {\n        if\
    \ (((i + 1) & -(i + 1)) == i + 1) continue;\n        if (buf[i << 1 | 1].empty())\
    \ {\n            buf[i] = buf[i << 1 | 0];\n        }\n        else {\n      \
    \      buf[i] = buf[i << 1 | 0] * buf[i << 1 | 1];\n        }\n    }\n    buf[1]\
    \ = f;\n    for (int i = 1; i < m; i++) {\n        if (buf[i].empty()) continue;\n\
    \        buf[i << 1 | 1] = buf[i] / buf[i << 1 | 0];\n        buf[i << 1 | 0]\
    \ = buf[i] % buf[i << 1 | 0];\n    }\n    vector<mint> b(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        b[i] = buf[m + i].empty() ? 0 : buf[m + i][0];\n \
    \   }\n    return b;\n}\n\n#endif  // FPS_TO_NEWTON_BASIS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/to_newton_basis.hpp
  requiredBy: []
  timestamp: '2024-05-23 21:30:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/to_newton_basis.hpp
layout: document
redirect_from:
- /library/fps/to_newton_basis.hpp
- /library/fps/to_newton_basis.hpp.html
title: fps/to_newton_basis.hpp
---
