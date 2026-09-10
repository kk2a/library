---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: aoj_ntl_1_e.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_e.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_INV_GCD_HPP\n#define KK2_MATH_INV_GCD_HPP 1\n\n#include\
      \ <algorithm>\n#include <utility>\n\nnamespace kk2 {\n\n// return {gcd(a, b),\
      \ x} where a * x + b * y = gcd(a, b)\nstd::pair<long long, long long> inv_gcd(long\
      \ long a, long long b) {\n    a = a % b;\n    if (a == 0) return {b, 0};\n \
      \   long long s = b, t = a;\n    long long m0 = 0, m1 = 1;\n\n    while (t)\
      \ {\n        long long u = s / t;\n        std::swap(s -= t * u, t);\n     \
      \   std::swap(m0 -= u * m1, m1);\n    }\n    if (m0 < 0) m0 += b / s;\n    return\
      \ {s, m0};\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_INV_GCD_HPP\n"
    name: default
  - code: "#line 1 \"math/inv_gcd.hpp\"\n\n\n\n#include <algorithm>\n#include <utility>\n\
      \nnamespace kk2 {\n\n// return {gcd(a, b), x} where a * x + b * y = gcd(a, b)\n\
      std::pair<long long, long long> inv_gcd(long long a, long long b) {\n    a =\
      \ a % b;\n    if (a == 0) return {b, 0};\n    long long s = b, t = a;\n    long\
      \ long m0 = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n  \
      \      std::swap(s -= t * u, t);\n        std::swap(m0 -= u * m1, m1);\n   \
      \ }\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/inv_gcd.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_e.test.cpp
documentation_of: math/inv_gcd.hpp
layout: document
---
