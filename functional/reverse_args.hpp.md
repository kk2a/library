---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: functional.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/functional.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/functional.hpp
  embedded:
  - code: "#ifndef KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n#define KK2_FUNCTIONAL_REVERSE_ARGS_HPP\
      \ 1\n\n#include \"../type_traits/functional.hpp\"\n\nnamespace kk2 {\n\n// reverse_args<f>(y,\
      \ x) = f(x, y)\ntemplate <auto f> requires TwoArgsFunctionPointer<decltype(f)>\n\
      inline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n}\n\n} // namespace\
      \ kk2\n\n#endif // KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n"
    name: default
  - code: "#line 1 \"functional/reverse_args.hpp\"\n\n\n\n#line 1 \"type_traits/functional.hpp\"\
      \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T> using\
      \ is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>,\n                       \
      \       std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\n\ntemplate <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R\
      \ (*)(T1, T2)>\n    : std::true_type {};\n\ntemplate <typename T> using is_two_args_function_pointer_t\
      \ =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate\
      \ <class T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate\
      \ <class T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \n} // namespace kk2\n\n\n#line 5 \"functional/reverse_args.hpp\"\n\nnamespace\
      \ kk2 {\n\n// reverse_args<f>(y, x) = f(x, y)\ntemplate <auto f> requires TwoArgsFunctionPointer<decltype(f)>\n\
      inline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: functional/reverse_args.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
documentation_of: functional/reverse_args.hpp
layout: document
---
