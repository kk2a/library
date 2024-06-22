---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':warning:'
    path: convolution/multi_zero.hpp
    title: convolution/multi_zero.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':warning:'
    path: math_mod/comb_large_arb.hpp
    title: math_mod/comb_large_arb.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_rt_expr.hpp
    title: math_mod/primitive_rt_expr.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/pow_expr.hpp\"\n\n\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, long long m) {\n    if (m == 1) return 0;\n    unsigned\
    \ long long _m = (unsigned long long)(m);\n    unsigned long long r = 1;\n   \
    \ unsigned long long y = (x % m + m) % m;\n    while (n) {\n        if (n & 1)\
    \ r = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\n\n"
  code: "#ifndef MOD_POW_EXPR_HPP\n#define MOD_POW_EXPR_HPP 1\n\nconstexpr long long\
    \ pow_mod_constexpr(long long x, long long n, long long m) {\n    if (m == 1)\
    \ return 0;\n    unsigned long long _m = (unsigned long long)(m);\n    unsigned\
    \ long long r = 1;\n    unsigned long long y = (x % m + m) % m;\n    while (n)\
    \ {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n       \
    \ n >>= 1;\n    }\n    return r;\n}\n\n#endif // MOD_POW_EXPR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/pow_expr.hpp
  requiredBy:
  - math_mod/primitive_rt_expr.hpp
  - math_mod/comb_large.hpp
  - math_mod/comb_large_arb.hpp
  - fps/fps_arb.hpp
  - fps/ntt_friendly.hpp
  - convolution/butterfly.hpp
  - convolution/multi_zero.hpp
  - convolution/convo_arb.hpp
  - convolution/convolution.hpp
  timestamp: '2024-06-13 21:51:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: math_mod/pow_expr.hpp
layout: document
redirect_from:
- /library/math_mod/pow_expr.hpp
- /library/math_mod/pow_expr.hpp.html
title: math_mod/pow_expr.hpp
---
