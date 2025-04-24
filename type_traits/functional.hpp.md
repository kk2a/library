---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: functional/reverse_args.hpp
    title: functional/reverse_args.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/functional.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n#define KK2_TYPE_TRAITS_FUNCTIONAL_HPP\
    \ 1\n\n#pragma once // oj-verify\n\n#include <type_traits>\n\nnamespace kk2 {\n\
    \ntemplate <typename T> using is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T>\
    \ && std::is_function_v<std::remove_pointer_t<T>>,\n                         \
    \     std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>\n\
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
  timestamp: '2025-04-06 00:07:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
