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
    path: math_mod/comb_large_arb.hpp
    title: math_mod/comb_large_arb.hpp
  - icon: ':warning:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/inv.hpp\"\n\n\n\ntemplate <class T, class U>\n\
    constexpr long long mod_inversion(T a, U modulo) {\n    long long s = modulo,\
    \ t = a;\n    long long m0 = 0, m1 = 1;\n    while (t) {\n        long long u\
    \ = s / t;\n        swap(s -= t * u, t);\n        swap(m0 -= m1 * u, m1);\n  \
    \  }\n    if (m0 < 0) m0 += modulo / s;\n    return m0;\n}\n\n\n"
  code: "#ifndef MOD_INV_HPP\n#define MOD_INV_HPP 1\n\ntemplate <class T, class U>\n\
    constexpr long long mod_inversion(T a, U modulo) {\n    long long s = modulo,\
    \ t = a;\n    long long m0 = 0, m1 = 1;\n    while (t) {\n        long long u\
    \ = s / t;\n        swap(s -= t * u, t);\n        swap(m0 -= m1 * u, m1);\n  \
    \  }\n    if (m0 < 0) m0 += modulo / s;\n    return m0;\n}\n\n#endif // MOD_INV_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/inv.hpp
  requiredBy:
  - fps/fps_arb.hpp
  - math_mod/comb_large_arb.hpp
  - math_mod/garner.hpp
  - convolution/convo_arb.hpp
  timestamp: '2024-06-13 21:51:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/inv.hpp
layout: document
redirect_from:
- /library/math_mod/inv.hpp
- /library/math_mod/inv.hpp.html
title: math_mod/inv.hpp
---
