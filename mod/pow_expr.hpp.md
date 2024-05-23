---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':x:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':warning:'
    path: convolution/multi_zero.hpp
    title: convolution/multi_zero.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':x:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':x:'
    path: mod/primitive_rt_expr.hpp
    title: mod/primitive_rt_expr.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/pow_expr.hpp\"\n\n\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = (x % m + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n"
  code: "#ifndef MOD_POW_EXPR_HPP\n#define MOD_POW_EXPR_HPP 1\n\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, int m) {\n    if (m == 1) return\
    \ 0;\n    unsigned int _m = (unsigned int)(m);\n    unsigned long long r = 1;\n\
    \    unsigned long long y = (x % m + m) % m;\n    while (n) {\n        if (n &\
    \ 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n \
    \   return r;\n}\n\n#endif // MOD_POW_EXPR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/pow_expr.hpp
  requiredBy:
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  - mod/primitive_rt_expr.hpp
  - convolution/convo_arb.hpp
  - convolution/butterfly.hpp
  - convolution/multi_zero.hpp
  - convolution/convolution.hpp
  timestamp: '2024-05-14 00:13:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: mod/pow_expr.hpp
layout: document
redirect_from:
- /library/mod/pow_expr.hpp
- /library/mod/pow_expr.hpp.html
title: mod/pow_expr.hpp
---
