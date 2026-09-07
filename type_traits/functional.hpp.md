---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: reverse_args.hpp
      icon: LIBRARY_ALL_AC
      path: functional/reverse_args.hpp
    type: Required by
  - files:
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n#define KK2_TYPE_TRAITS_FUNCTIONAL_HPP\
      \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T> using\
      \ is_function_pointer =\n    typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>,\n                       \
      \       std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\n\ntemplate <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R\
      \ (*)(T1, T2)>\n    : std::true_type {};\n\ntemplate <typename T> using is_two_args_function_pointer_t\
      \ =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate\
      \ <class T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate\
      \ <class T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \n} // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/functional.hpp\"\n\n\n\n#include <type_traits>\n\n\
      namespace kk2 {\n\ntemplate <typename T> using is_function_pointer =\n    typename\
      \ std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> struct is_two_args_function_pointer\
      \ : std::false_type {};\n\ntemplate <typename R, typename T1, typename T2> struct\
      \ is_two_args_function_pointer<R (*)(T1, T2)>\n    : std::true_type {};\n\n\
      template <typename T> using is_two_args_function_pointer_t =\n    std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\
      \ntemplate <class T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\
      \ntemplate <class T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/functional.hpp
  pathExtension: hpp
  requiredBy:
  - functional/reverse_args.hpp
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/concepts.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
documentation_of: type_traits/functional.hpp
layout: document
---
