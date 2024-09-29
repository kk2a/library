---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
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
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
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
  bundledCode: "#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
    \n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n\
    #include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value\n           \
    \                                            or std::is_same<T, __int128>::value,\n\
    \                                                   std::true_type,\n        \
    \                                           std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(!is_signed_extended<U>::value || n >= 0);\n    if\
    \ (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y = S(x) % _m;\n    if\
    \ (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n  \
    \      y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace kk2 {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    if (m == 1107296257) return\
    \ 10;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) { x /= i; }\n        }\n    }\n    if (x > 1) {\
    \ divs[cnt++] = x; }\n    for (int g = 2;; g++) {\n        bool ok = true;\n \
    \       for (int i = 0; i < cnt; i++) {\n            if (pow_mod<long long>(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\n\ntemplate\
    \ <int m> static constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef MOD_PRIMITIVE_ROOT_EXPR_HPP\n#define MOD_PRIMITIVE_ROOT_EXPR_HPP\
    \ 1\n\n#include \"pow_mod.hpp\"\n\nnamespace kk2 {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {};\n   \
    \ divs[0] = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 ==\
    \ 0) x /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if\
    \ (x % i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0)\
    \ { x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
    \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt;\
    \ i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n#endif\
    \ // MOD_PRIMITIVE_ROOT_EXPR_HPP\n"
  dependsOn:
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math_mod/primitive_root.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - convolution/convo_arb.hpp
  - convolution/multi_convo_truncated.hpp
  - fps/fps_arb.hpp
  - fps/ntt_friendly.hpp
  - fps/multivariate_fps.hpp
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: math_mod/primitive_root.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_root.hpp
- /library/math_mod/primitive_root.hpp.html
title: math_mod/primitive_root.hpp
---
