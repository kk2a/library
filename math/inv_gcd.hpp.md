---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_e.test.cpp
    title: verify/aoj/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/inv_gcd.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <utility>\n\nnamespace kk2 {\n\n// return {gcd(a, b), x} where a * x + b * y\
    \ = gcd(a, b)\nstd::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = a % b;\n    if (a == 0) return {b, 0};\n    long long s = b, t\
    \ = a;\n    long long m0 = 0, m1 = 1;\n\n    while (t) {\n        long long u\
    \ = s / t;\n        std::swap(s -= t * u, t);\n        std::swap(m0 -= u * m1,\
    \ m1);\n    }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef MATH_INV_GCD_HPP\n#define MATH_INV_GCD_HPP 1\n\n#include <algorithm>\n\
    #include <utility>\n\nnamespace kk2 {\n\n// return {gcd(a, b), x} where a * x\
    \ + b * y = gcd(a, b)\nstd::pair<long long, long long> inv_gcd(long long a, long\
    \ long b) {\n    a = a % b;\n    if (a == 0) return {b, 0};\n    long long s =\
    \ b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while (t) {\n        long long\
    \ u = s / t;\n        std::swap(s -= t * u, t);\n        std::swap(m0 -= u * m1,\
    \ m1);\n    }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\n} // namespace\
    \ kk2\n\n#endif // MATH_INV_GCD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv_gcd.hpp
  requiredBy: []
  timestamp: '2024-09-11 08:59:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_e.test.cpp
documentation_of: math/inv_gcd.hpp
layout: document
redirect_from:
- /library/math/inv_gcd.hpp
- /library/math/inv_gcd.hpp.html
title: math/inv_gcd.hpp
---
