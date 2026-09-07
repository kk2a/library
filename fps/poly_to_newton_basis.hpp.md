---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: poly_to_newton_basis.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_to_newton_basis.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_FPS_POLY_TO_NEWTON_BASIS_HPP\n#define KK2_FPS_POLY_TO_NEWTON_BASIS_HPP\
      \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\n// return\
      \ b s.t.\n// f(X) = \\sum_{i = 0} ^ {n - 1} b_i \\prod_{j = 0} ^ {i - 1} (X\
      \ - p_j)\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
      \ convert_to_newton_basis(const FPS &f, const std::vector<mint> &p) {\n    int\
      \ n = (int)f.size();\n    assert(n == (int)p.size());\n\n    int m = 1;\n  \
      \  while (m < n) m <<= 1;\n\n    std::vector<FPS> buf(m << 1);\n    for (int\
      \ i = 0; i < n; i++) { buf[m + i] = {-p[i], 1}; }\n    for (int i = m - 1; i\
      \ > 0; i--) {\n        if (((i + 1) & -(i + 1)) == i + 1) continue;\n      \
      \  if (buf[i << 1 | 1].empty()) {\n            buf[i] = buf[i << 1 | 0];\n \
      \       } else {\n            buf[i] = buf[i << 1 | 0] * buf[i << 1 | 1];\n\
      \        }\n    }\n    buf[1] = f;\n    for (int i = 1; i < m; i++) {\n    \
      \    if (buf[i].empty()) continue;\n        buf[i << 1 | 1] = buf[i] / buf[i\
      \ << 1 | 0];\n        buf[i << 1 | 0] = buf[i] % buf[i << 1 | 0];\n    }\n \
      \   std::vector<mint> b(n);\n    for (int i = 0; i < n; i++) { b[i] = buf[m\
      \ + i].eval(0); }\n    return b;\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_POLY_TO_NEWTON_BASIS_HPP\n"
    name: default
  - code: "#line 1 \"fps/poly_to_newton_basis.hpp\"\n\n\n\n#include <cassert>\n#include\
      \ <vector>\n\nnamespace kk2 {\n\n// return b s.t.\n// f(X) = \\sum_{i = 0} ^\
      \ {n - 1} b_i \\prod_{j = 0} ^ {i - 1} (X - p_j)\ntemplate <class FPS, class\
      \ mint = typename FPS::value_type>\nstd::vector<mint> convert_to_newton_basis(const\
      \ FPS &f, const std::vector<mint> &p) {\n    int n = (int)f.size();\n    assert(n\
      \ == (int)p.size());\n\n    int m = 1;\n    while (m < n) m <<= 1;\n\n    std::vector<FPS>\
      \ buf(m << 1);\n    for (int i = 0; i < n; i++) { buf[m + i] = {-p[i], 1}; }\n\
      \    for (int i = m - 1; i > 0; i--) {\n        if (((i + 1) & -(i + 1)) ==\
      \ i + 1) continue;\n        if (buf[i << 1 | 1].empty()) {\n            buf[i]\
      \ = buf[i << 1 | 0];\n        } else {\n            buf[i] = buf[i << 1 | 0]\
      \ * buf[i << 1 | 1];\n        }\n    }\n    buf[1] = f;\n    for (int i = 1;\
      \ i < m; i++) {\n        if (buf[i].empty()) continue;\n        buf[i << 1 |\
      \ 1] = buf[i] / buf[i << 1 | 0];\n        buf[i << 1 | 0] = buf[i] % buf[i <<\
      \ 1 | 0];\n    }\n    std::vector<mint> b(n);\n    for (int i = 0; i < n; i++)\
      \ { b[i] = buf[m + i].eval(0); }\n    return b;\n}\n\n} // namespace kk2\n\n\
      \n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/poly_to_newton_basis.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
documentation_of: fps/poly_to_newton_basis.hpp
layout: document
---
