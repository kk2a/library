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
    path: convolution/multi_convo_truncated.hpp
    title: convolution/multi_convo_truncated.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':x:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':x:'
    path: math_mod/primitive_rt_expr.hpp
    title: math_mod/primitive_rt_expr.hpp
  - icon: ':warning:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
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
  bundledCode: "#line 1 \"math_mod/pow_expr.hpp\"\n\n\n\nnamespace kk2 {\n\nconstexpr\
    \ long long pow_mod_constexpr(long long x, long long n, long long m) {\n    if\
    \ (m == 1) return 0;\n    unsigned long long _m = (unsigned long long)(m);\n \
    \   unsigned long long r = 1;\n    unsigned long long y = (x % m + m) % m;\n \
    \   while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n\
    \        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MOD_POW_EXPR_HPP\n#define MOD_POW_EXPR_HPP 1\n\nnamespace kk2 {\n\
    \nconstexpr long long pow_mod_constexpr(long long x, long long n, long long m)\
    \ {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned long long)(m);\n\
    \    unsigned long long r = 1;\n    unsigned long long y = (x % m + m) % m;\n\
    \    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) %\
    \ _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n#endif\
    \ // MOD_POW_EXPR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/pow_expr.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - math_mod/primitive_rt_expr.hpp
  - fps/multivariate_fps.hpp
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  - convolution/convolution.hpp
  - convolution/convo_arb.hpp
  - convolution/multi_convo_truncated.hpp
  - convolution/butterfly.hpp
  - string/rolling_hash.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
documentation_of: math_mod/pow_expr.hpp
layout: document
redirect_from:
- /library/math_mod/pow_expr.hpp
- /library/math_mod/pow_expr.hpp.html
title: math_mod/pow_expr.hpp
---
