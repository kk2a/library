---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/functional.hpp
    title: type_traits/functional.hpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 1 \"functional/reverse_args.hpp\"\n\n\n\n#line 1 \"type_traits/functional.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T> using\
    \ is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T> &&\
    \ std::is_function_v<std::remove_pointer_t<T>>,\n                            \
    \  std::true_type,\n                              std::false_type>::type;\n\n\
    template <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>\n\
    struct is_two_args_function_pointer : std::false_type {};\n\ntemplate <typename\
    \ R, typename T1, typename T2> struct is_two_args_function_pointer<R (*)(T1, T2)>\n\
    \    : std::true_type {};\n\ntemplate <typename T> using is_two_args_function_pointer_t\
    \ =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"functional/reverse_args.hpp\"\n\nnamespace kk2 {\n\n// reverse_args<f>(y,\
    \ x) = f(x, y)\ntemplate <auto f, is_two_args_function_pointer_t<decltype(f)>\
    \ * = nullptr>\ninline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n#define KK2_FUNCTIONAL_REVERSE_ARGS_HPP\
    \ 1\n\n#include \"../type_traits/functional.hpp\"\n\nnamespace kk2 {\n\n// reverse_args<f>(y,\
    \ x) = f(x, y)\ntemplate <auto f, is_two_args_function_pointer_t<decltype(f)>\
    \ * = nullptr>\ninline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n"
  dependsOn:
  - type_traits/functional.hpp
  isVerificationFile: false
  path: functional/reverse_args.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
documentation_of: functional/reverse_args.hpp
layout: document
redirect_from:
- /library/functional/reverse_args.hpp
- /library/functional/reverse_args.hpp.html
title: functional/reverse_args.hpp
---
