---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: functional/reverse_args.hpp
    title: functional/reverse_args.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type_traits/functional.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\ntemplate <typename T> using is_function_pointer =\n    typename\
    \ std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T, std::enable_if_t<is_function_pointer<T>::value>\
    \ * = nullptr>\nstruct is_two_args_function_pointer : std::false_type {};\n\n\
    template <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R\
    \ (*)(T1, T2)>\n    : std::true_type {};\n\ntemplate <typename T> using is_two_args_function_pointer_t\
    \ =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n#define KK2_TYPE_TRAITS_FUNCTIONAL_HPP\
    \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T> using\
    \ is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T> &&\
    \ std::is_function_v<std::remove_pointer_t<T>>,\n                            \
    \  std::true_type,\n                              std::false_type>::type;\n\n\
    template <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>\n\
    struct is_two_args_function_pointer : std::false_type {};\n\ntemplate <typename\
    \ R, typename T1, typename T2> struct is_two_args_function_pointer<R (*)(T1, T2)>\n\
    \    : std::true_type {};\n\ntemplate <typename T> using is_two_args_function_pointer_t\
    \ =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\n} // namespace\
    \ kk2\n\n#endif // KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/functional.hpp
  requiredBy:
  - functional/reverse_args.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
documentation_of: type_traits/functional.hpp
layout: document
redirect_from:
- /library/type_traits/functional.hpp
- /library/type_traits/functional.hpp.html
title: type_traits/functional.hpp
---
