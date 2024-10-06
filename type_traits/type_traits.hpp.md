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
    path: data_structure/convex_hull_trick_add_monotone.hpp
    title: data_structure/convex_hull_trick_add_monotone.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: fps/taylor_shift.hpp
    title: fps/taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/pow.hpp
    title: math/pow.hpp
  - icon: ':warning:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':warning:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':warning:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':warning:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':warning:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':warning:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_ntt.test.cpp
    title: verify/yosupo_convolution/convolution_ntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_ntt.test.cpp
    title: verify/yosupo_convolution/convolution_ntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/math_primality_test.test.cpp
    title: verify/yosupo_math/math_primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/math_primality_test.test.cpp
    title: verify/yosupo_math/math_primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/matrix_system_of_linear_equations.test.cpp
    title: verify/yosupo_math/matrix_system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value\n                      \
    \                                 or std::is_same<T, __int128>::value,\n     \
    \                                              std::true_type,\n             \
    \                                      std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
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
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef TYPE_TRAITS_HPP\n#define TYPE_TRAITS_HPP 1\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value\n                      \
    \                                 or std::is_same<T, __int128>::value,\n     \
    \                                              std::true_type,\n             \
    \                                      std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
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
    \ std::false_type>::type;\n\n} // namespace kk2\n\n#endif // TYPE_TRAITS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/type_traits.hpp
  requiredBy:
  - math_mod/primitive_root.hpp
  - math_mod/comb.hpp
  - math_mod/mod_sqrt.hpp
  - math_mod/pow_mod.hpp
  - math_mod/comb_large.hpp
  - math_mod/comb_large.hpp
  - data_structure/convex_hull_trick_add_monotone.hpp
  - string/rolling_hash.hpp
  - math/prime_factorize.hpp
  - math/prime_factorize.hpp
  - math/pow.hpp
  - math/is_prime.hpp
  - math/is_prime.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - convolution/convo_arb.hpp
  - convolution/convo_arb.hpp
  - convolution/multi_convo_truncated.hpp
  - modint/modint.hpp
  - modint/mont_arb.hpp
  - modint/mont.hpp
  - fps/taylor_shift.hpp
  - fps/fps_arb.hpp
  - fps/fps_arb.hpp
  - fps/ntt_friendly.hpp
  - fps/multivariate_fps.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2024-09-29 16:53:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/matrix_system_of_linear_equations.test.cpp
  - verify/yosupo_math/math_primality_test.test.cpp
  - verify/yosupo_math/math_primality_test.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_convolution/convolution_ntt.test.cpp
  - verify/yosupo_convolution/convolution_ntt.test.cpp
documentation_of: type_traits/type_traits.hpp
layout: document
redirect_from:
- /library/type_traits/type_traits.hpp
- /library/type_traits/type_traits.hpp.html
title: type_traits/type_traits.hpp
---
