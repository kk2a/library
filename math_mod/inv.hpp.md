---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/inv.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ kk2 {\n\n// require: modulo >= 1\ntemplate <class T> constexpr T mod_inversion(T\
    \ a, T modulo) {\n    a %= modulo;\n    if (a < 0) a += modulo;\n    T s = modulo,\
    \ t = a;\n    T m0 = 0, m1 = 1;\n    while (t) {\n        T u = s / t;\n     \
    \   std::swap(s -= t * u, t);\n        std::swap(m0 -= m1 * u, m1);\n    }\n \
    \   if (m0 < 0) m0 += modulo;\n    return m0;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MOD_INV_HPP\n#define KK2_MATH_MOD_INV_HPP 1\n\n#include\
    \ <algorithm>\n\nnamespace kk2 {\n\n// require: modulo >= 1\ntemplate <class T>\
    \ constexpr T mod_inversion(T a, T modulo) {\n    a %= modulo;\n    if (a < 0)\
    \ a += modulo;\n    T s = modulo, t = a;\n    T m0 = 0, m1 = 1;\n    while (t)\
    \ {\n        T u = s / t;\n        std::swap(s -= t * u, t);\n        std::swap(m0\
    \ -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n    return m0;\n}\n\n\
    } // namespace kk2\n\n#endif // KK2_MATH_MOD_INV_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/inv.hpp
  requiredBy:
  - math_mod/garner.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/inv.hpp
layout: document
redirect_from:
- /library/math_mod/inv.hpp
- /library/math_mod/inv.hpp.html
title: math_mod/inv.hpp
---
