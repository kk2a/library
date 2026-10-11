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
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
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
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n#define KK2_FUNCTIONAL_REVERSE_ARGS_HPP\
      \ 1\n\n#include \"../type_traits/functional.hpp\"\n\nnamespace kk2 {\n\n// reverse_args<f>(y,\
      \ x) = f(x, y)\ntemplate <auto f>\n    requires TwoArgsFunctionPointer<decltype(f)>\n\
      inline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n}\n\n} // namespace\
      \ kk2\n\n#endif // KK2_FUNCTIONAL_REVERSE_ARGS_HPP\n"
    name: default
  - code: "#line 1 \"functional/reverse_args.hpp\"\n\n\n\n#line 1 \"type_traits/functional.hpp\"\
      \n\n\n\n#include <concepts>\n#include <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
      \ntemplate <typename T> using is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value or std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_unsigned_int128 = typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value or std::is_same<T, unsigned __int128>::value, std::true_type,\
      \ std::false_type>::type;\ntemplate <typename T> using is_integral = typename\
      \ std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\
      \ or is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value, std::true_type, std::false_type>::type;\ntemplate\
      \ <typename T> using is_unsigned = typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using make_unsigned_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\ntemplate <typename T>\
      \ using to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
      \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
      \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\n\n#else\n\ntemplate\
      \ <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      template <class T> concept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      template <class T> concept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      template <class T> concept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"type_traits/functional.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <typename T> using is_function_pointer = typename std::conditional<std::is_pointer_v<T>\
      \ && std::is_function_v<std::remove_pointer_t<T>>, std::true_type, std::false_type>::type;\n\
      template <typename T> struct is_two_args_function_pointer : std::false_type\
      \ {};\ntemplate <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R\
      \ (*)(T1, T2)> : std::true_type {\n    using return_type = R;\n    using first_argument_type\
      \ = T1;\n    using second_argument_type = T2;\n};\ntemplate <typename T> using\
      \ is_two_args_function_pointer_t = std::enable_if_t<is_two_args_function_pointer<T>::value>;\n\
      template <class T> concept FunctionPointer = is_function_pointer<T>::value;\n\
      template <class T> concept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;\n\
      template <class T> concept UnsignedTwoArgsFunctionPointer = TwoArgsFunctionPointer<T>\
      \ && requires {\n    typename is_two_args_function_pointer<T>::first_argument_type;\n\
      \    typename is_two_args_function_pointer<T>::second_argument_type;\n} && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::first_argument_type> && UnsignedIntegral<typename\
      \ is_two_args_function_pointer<T>::second_argument_type>;\n\n} // namespace\
      \ kk2\n\n\n#line 5 \"functional/reverse_args.hpp\"\n\nnamespace kk2 {\n\n//\
      \ reverse_args<f>(y, x) = f(x, y)\ntemplate <auto f>\n    requires TwoArgsFunctionPointer<decltype(f)>\n\
      inline auto reverse_args(auto x, auto y) {\n    return f(y, x);\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: functional/reverse_args.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
documentation_of: functional/reverse_args.hpp
layout: document
---
