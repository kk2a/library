---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_expr.hpp
    title: math_mod/pow_expr.hpp
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
    path: convolution/multi_convo_truncated.hpp
    title: convolution/multi_convo_truncated.hpp
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
  bundledCode: "#line 1 \"math_mod/primitive_rt_expr.hpp\"\n\n\n\n#line 1 \"math_mod/pow_expr.hpp\"\
    \n\n\n\nconstexpr long long pow_mod_constexpr(long long x, long long n, long long\
    \ m) {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned long\
    \ long)(m);\n    unsigned long long r = 1;\n    unsigned long long y = (x % m\
    \ + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y\
    \ = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n#line 5 \"math_mod/primitive_rt_expr.hpp\"\
    \n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n\
    \    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if\
    \ (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m ==\
    \ 1107296257) return 10;\n    int divs[20] = {}; \n    divs[0] = 2;\n    int cnt\
    \ = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int\
    \ i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n       \
    \     divs[cnt++] = i;\n            while (x % i == 0) {\n                x /=\
    \ i;\n            }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] =\
    \ x;\n    }\n    for (int g = 2;; g++) {\n        bool ok = true;\n        for\
    \ (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) /\
    \ divs[i], m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\ntemplate <int m>\
    \ static constexpr int primitive_root = primitive_root_constexpr(m);\n\n\n"
  code: "#ifndef MOD_PRIMITIVE_ROOT_EXPR_HPP\n#define MOD_PRIMITIVE_ROOT_EXPR_HPP\
    \ 1\n\n#include \"pow_expr.hpp\"\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {}; \n  \
    \  divs[0] = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2\
    \ == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n      \
    \  if (x % i == 0) {\n            divs[cnt++] = i;\n            while (x % i ==\
    \ 0) {\n                x /= i;\n            }\n        }\n    }\n    if (x >\
    \ 1) {\n        divs[cnt++] = x;\n    }\n    for (int g = 2;; g++) {\n       \
    \ bool ok = true;\n        for (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\ntemplate\
    \ <int m> static constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n#endif // MOD_PRIMITIVE_ROOT_EXPR_HPP\n"
  dependsOn:
  - math_mod/pow_expr.hpp
  isVerificationFile: false
  path: math_mod/primitive_rt_expr.hpp
  requiredBy:
  - convolution/convolution.hpp
  - convolution/multi_convo_truncated.hpp
  - convolution/butterfly.hpp
  - convolution/convo_arb.hpp
  - math_mod/comb_large.hpp
  - math_mod/comb_large_arb.hpp
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-06-13 21:51:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: math_mod/primitive_rt_expr.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_rt_expr.hpp
- /library/math_mod/primitive_rt_expr.hpp.html
title: math_mod/primitive_rt_expr.hpp
---
