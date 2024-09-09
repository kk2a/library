---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':warning:'
    path: data_structure/convex_hull_trick_add_monotone.hpp
    title: data_structure/convex_hull_trick_add_monotone.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  - icon: ':warning:'
    path: fps/taylor_shift.hpp
    title: fps/taylor_shift.hpp
  - icon: ':warning:'
    path: math/pow_expr.hpp
    title: math/pow_expr.hpp
  - icon: ':warning:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':warning:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  - icon: ':warning:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':x:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':warning:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
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
  bundledCode: "#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 =\n    typename\
    \ std::conditional<std::is_same<T, __int128_t>::value or\n                   \
    \           std::is_same<T, __int128>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value or\n      \
    \                        std::is_same<T, unsigned __int128>::value,\n        \
    \                      std::true_type, std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or\n                              is_signed_int128<T>::value or\n          \
    \                    is_unsigned_int128<T>::value,\n                         \
    \     std::true_type, std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or\n                              is_signed_int128<T>::value,\n            \
    \                  std::true_type, std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or\n                              is_unsigned_int128<T>::value,\n          \
    \                    std::true_type, std::false_type>::type;\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef TYPE_TRAITS_HPP\n#define TYPE_TRAITS_HPP 1\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 =\n    typename\
    \ std::conditional<std::is_same<T, __int128_t>::value or\n                   \
    \           std::is_same<T, __int128>::value,\n                              std::true_type,\
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value or\n      \
    \                        std::is_same<T, unsigned __int128>::value,\n        \
    \                      std::true_type, std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or\n                              is_signed_int128<T>::value or\n          \
    \                    is_unsigned_int128<T>::value,\n                         \
    \     std::true_type, std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or\n                              is_signed_int128<T>::value,\n            \
    \                  std::true_type, std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or\n                              is_unsigned_int128<T>::value,\n          \
    \                    std::true_type, std::false_type>::type;\n\n} // namespace\
    \ kk2\n\n#endif // TYPE_TRAITS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/type_traits.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - math_mod/mod_sqrt.hpp
  - math_mod/comb.hpp
  - math/pow_expr.hpp
  - fps/fps_sqrt.hpp
  - fps/taylor_shift.hpp
  - fps/fps_arb.hpp
  - convolution/convo_arb.hpp
  - modint/modint.hpp
  - modint/mont_arb.hpp
  - modint/mont.hpp
  - data_structure/convex_hull_trick_add_monotone.hpp
  timestamp: '2024-09-10 07:56:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
documentation_of: type_traits/type_traits.hpp
layout: document
redirect_from:
- /library/type_traits/type_traits.hpp
- /library/type_traits/type_traits.hpp.html
title: type_traits/type_traits.hpp
---
