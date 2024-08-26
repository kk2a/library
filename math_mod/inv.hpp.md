---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/inv.hpp\"\n\n\n\nnamespace kk2 {\n\n// require:\
    \ modulo >= 1\ntemplate <class T>\nconstexpr T mod_inversion(T a, T modulo) {\n\
    \    a %= modulo;\n    if (a < 0) a += modulo;\n    T s = modulo, t = a;\n   \
    \ T m0 = 0, m1 = 1;\n    while (t) {\n        T u = s / t;\n        swap(s -=\
    \ t * u, t);\n        swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n\
    \    return m0;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MOD_INV_HPP\n#define MOD_INV_HPP 1\n\nnamespace kk2 {\n\n// require:\
    \ modulo >= 1\ntemplate <class T>\nconstexpr T mod_inversion(T a, T modulo) {\n\
    \    a %= modulo;\n    if (a < 0) a += modulo;\n    T s = modulo, t = a;\n   \
    \ T m0 = 0, m1 = 1;\n    while (t) {\n        T u = s / t;\n        swap(s -=\
    \ t * u, t);\n        swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n\
    \    return m0;\n}\n\n} // namespace kk2\n\n#endif // MOD_INV_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/inv.hpp
  requiredBy:
  - convolution/convo_arb.hpp
  - math_mod/garner.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/inv.hpp
layout: document
redirect_from:
- /library/math_mod/inv.hpp
- /library/math_mod/inv.hpp.html
title: math_mod/inv.hpp
---
