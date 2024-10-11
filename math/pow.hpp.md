---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n// #pragma once\n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate\
    \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 7 \"math/pow.hpp\"\n\nnamespace kk2 {\n\ntemplate <class S, class T,\
    \ class U> constexpr S pow(T x, U n) {\n    assert(!is_signed_extended<U>::value\
    \ || n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n\
    \        y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef MATH_POW_EXPR_HPP\n#define MATH_POW_EXPR_HPP 1\n\n#include <cassert>\n\
    \n#include \"../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S, class T, class U> constexpr S pow(T x, U n) {\n    assert(!is_signed_extended<U>::value\
    \ || n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n\
    \        y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n#endif // MATH_POW_EXPR_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math/pow.hpp
  requiredBy: []
  timestamp: '2024-10-12 00:40:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
