---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/multiplicative_function/arbitrary_table.hpp
    title: math/multiplicative_function/arbitrary_table.hpp
  - icon: ':x:'
    path: math/multiplicative_function/famous_function.hpp
    title: math/multiplicative_function/famous_function.hpp
  - icon: ':x:'
    path: math/multiplicative_function/famous_function_table.hpp
    title: math/multiplicative_function/famous_function_table.hpp
  - icon: ':x:'
    path: math/multiplicative_function/sigma.hpp
    title: math/multiplicative_function/sigma.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/famous_function_table.test.cpp
    title: verify/unit_test/famous_function_table.test.cpp
  - icon: ':x:'
    path: verify/unit_test/multiplicative_function_table.test.cpp
    title: verify/unit_test/multiplicative_function_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2\
    \ {\n\ntemplate <class S, class T, class U> constexpr S pow(T x, U n) {\n    assert(n\
    \ >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n \
    \       if (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef KK2_MATH_POW_HPP\n#define KK2_MATH_POW_HPP 1\n\n#include <cassert>\n\
    \nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow(T x,\
    \ U n) {\n    assert(n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if\
    \ (n & 1) r *= y;\n        if (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n}\
    \ // namespace kk2\n\n#endif // KK2_MATH_POW_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/pow.hpp
  requiredBy:
  - math/multiplicative_function/sigma.hpp
  - math/multiplicative_function/arbitrary_table.hpp
  - math/multiplicative_function/famous_function.hpp
  - math/multiplicative_function/famous_function_table.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/famous_function_table.test.cpp
  - verify/unit_test/multiplicative_function_table.test.cpp
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
