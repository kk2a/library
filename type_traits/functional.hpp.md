---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    type: Depends on
  - files:
    - filename: reverse_args.hpp
      icon: LIBRARY_ALL_AC
      path: functional/reverse_args.hpp
    - filename: arbitrary_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/arbitrary_table.hpp
    type: Required by
  - files:
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
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
  dependsOn:
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n#define KK2_TYPE_TRAITS_FUNCTIONAL_HPP\
      \ 1\n\n#include <concepts>\n#include <type_traits>\n\n#include \"integral.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_function_pointer =\n\
      \    typename std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> struct is_two_args_function_pointer\
      \ : std::false_type {};\n\ntemplate <typename R, typename T1, typename T2>\n\
      struct is_two_args_function_pointer<R (*)(T1, T2)> : std::true_type {\n    using\
      \ return_type = R;\n    using first_argument_type = T1;\n    using second_argument_type\
      \ = T2;\n};\n\ntemplate <typename T>\nusing is_two_args_function_pointer_t =\
      \ std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate <class\
      \ T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate <class\
      \ T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \ntemplate <class T>\nconcept UnsignedTwoArgsFunctionPointer = TwoArgsFunctionPointer<T>\
      \ && requires {\n    typename is_two_args_function_pointer<T>::first_argument_type;\n\
      \    typename is_two_args_function_pointer<T>::second_argument_type;\n} && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::first_argument_type> && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::second_argument_type>;\n\n} // namespace\
      \ kk2\n\n#endif // KK2_TYPE_TRAITS_FUNCTIONAL_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/functional.hpp\"\n\n\n\n#include <concepts>\n#include\
      \ <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\
      \n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
      \ = typename std::conditional<std::is_same<T, __int128_t>::value\n         \
      \                                              or std::is_same<T, __int128>::value,\n\
      \                                                   std::true_type,\n      \
      \                                             std::false_type>::type;\n\ntemplate\
      \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value\n                                  or std::is_same<T,\
      \ unsigned __int128>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
      \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed = typename\
      \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
      \                                            std::true_type,\n             \
      \                               std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"type_traits/functional.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <typename T>\nusing is_function_pointer =\n    typename\
      \ std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> struct is_two_args_function_pointer\
      \ : std::false_type {};\n\ntemplate <typename R, typename T1, typename T2>\n\
      struct is_two_args_function_pointer<R (*)(T1, T2)> : std::true_type {\n    using\
      \ return_type = R;\n    using first_argument_type = T1;\n    using second_argument_type\
      \ = T2;\n};\n\ntemplate <typename T>\nusing is_two_args_function_pointer_t =\
      \ std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\ntemplate <class\
      \ T>\nconcept FunctionPointer = is_function_pointer<T>::value;\n\ntemplate <class\
      \ T>\nconcept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      \ntemplate <class T>\nconcept UnsignedTwoArgsFunctionPointer = TwoArgsFunctionPointer<T>\
      \ && requires {\n    typename is_two_args_function_pointer<T>::first_argument_type;\n\
      \    typename is_two_args_function_pointer<T>::second_argument_type;\n} && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::first_argument_type> && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::second_argument_type>;\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/functional.hpp
  pathExtension: hpp
  requiredBy:
  - functional/reverse_args.hpp
  - math/multiplicative_function/arbitrary_table.hpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/unit_test/type_traits/concepts.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
documentation_of: type_traits/functional.hpp
layout: document
---
