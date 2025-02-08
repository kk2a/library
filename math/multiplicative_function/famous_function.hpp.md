---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/pow.hpp
    title: math/pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/famous_function.hpp\"\n\n\n\
    \n#line 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate\
    \ <class S, class T, class U> constexpr S pow(T x, U n) {\n    assert(n >= 0);\n\
    \    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n        if\
    \ (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line\
    \ 5 \"math/multiplicative_function/famous_function.hpp\"\n\nnamespace kk2 {\n\n\
    long long mobius(long long p, long long e) {\n    return e == 1 ? -1 : 0;\n}\n\
    \nlong long sigma0(long long p, long long e) {\n    return e + 1;\n}\n\nlong long\
    \ sigma1(long long p, long long e) {\n    return (pow<long long>(p, e + 1) - 1)\
    \ / (p - 1);\n}\n\nlong long euler_phi(long long p, long long e) {\n    return\
    \ pow(p, e) - pow(p, e - 1);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\
    \ 1\n\n#include \"../pow.hpp\"\n\nnamespace kk2 {\n\nlong long mobius(long long\
    \ p, long long e) {\n    return e == 1 ? -1 : 0;\n}\n\nlong long sigma0(long long\
    \ p, long long e) {\n    return e + 1;\n}\n\nlong long sigma1(long long p, long\
    \ long e) {\n    return (pow<long long>(p, e + 1) - 1) / (p - 1);\n}\n\nlong long\
    \ euler_phi(long long p, long long e) {\n    return pow(p, e) - pow(p, e - 1);\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n"
  dependsOn:
  - math/pow.hpp
  isVerificationFile: false
  path: math/multiplicative_function/famous_function.hpp
  requiredBy: []
  timestamp: '2025-02-08 18:14:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multiplicative_function/famous_function.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/famous_function.hpp
- /library/math/multiplicative_function/famous_function.hpp.html
title: math/multiplicative_function/famous_function.hpp
---
