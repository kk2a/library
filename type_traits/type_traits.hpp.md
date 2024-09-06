---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/convex_hull_trick_add_monotone.hpp
    title: data_structure/convex_hull_trick_add_monotone.hpp
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
    path: modint/modint.hpp
    title: modint/modint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type_traits/type_traits.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    template <typename T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value or\n                              std::is_same<T, __int128>::value,\n\
    \                              std::true_type, std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value or\n                              std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type, std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
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
  code: "#ifndef TYPE_TRAITS_HPP\n#define TYPE_TRAITS_HPP 1\n\nnamespace kk2 {\n\n\
    template <typename T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value or\n                              std::is_same<T, __int128>::value,\n\
    \                              std::true_type, std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value or\n                              std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type, std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
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
  - math_mod/comb.hpp
  - math/pow_expr.hpp
  - fps/taylor_shift.hpp
  - modint/modint.hpp
  - data_structure/convex_hull_trick_add_monotone.hpp
  timestamp: '2024-09-06 16:31:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type_traits/type_traits.hpp
layout: document
redirect_from:
- /library/type_traits/type_traits.hpp
- /library/type_traits/type_traits.hpp.html
title: type_traits/type_traits.hpp
---
