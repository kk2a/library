---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/multiplicative_function/arbitrary_table.hpp
    title: math/multiplicative_function/arbitrary_table.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/counting_square_free.hpp
    title: math/multiplicative_function/counting_square_free.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/famous_function.hpp
    title: math/multiplicative_function/famous_function.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/famous_function_table.hpp
    title: math/multiplicative_function/famous_function_table.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/sigma.hpp
    title: math/multiplicative_function/sigma.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - math/multiplicative_function/famous_function_table.hpp
  - math/multiplicative_function/famous_function.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/arbitrary_table.hpp
  - math/multiplicative_function/sigma.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
