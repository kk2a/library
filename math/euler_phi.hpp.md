---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/euler_phi.hpp\"\n\n\n\nnamespace kk2 {\n\nlong long\
    \ euler_phi(long long a) {\n    long long res = a, now = a;\n    for (long long\
    \ i = 2; i * i <= a; i++) {\n        if (now % i == 0) {\n            res /= i;\n\
    \            res *= i - 1;\n            while (now % i == 0) now /= i;\n     \
    \   }\n    }\n    if (now > 1) {\n        res /= now;\n        res *= now - 1;\n\
    \    }\n    return res;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_EULER_PHI_HPP\n#define MATH_EULER_PHI_HPP 1\n\nnamespace kk2\
    \ {\n\nlong long euler_phi(long long a) {\n    long long res = a, now = a;\n \
    \   for (long long i = 2; i * i <= a; i++) {\n        if (now % i == 0) {\n  \
    \          res /= i;\n            res *= i - 1;\n            while (now % i ==\
    \ 0) now /= i;\n        }\n    }\n    if (now > 1) {\n        res /= now;\n  \
    \      res *= now - 1;\n    }\n    return res;\n}\n\n} // namespace kk2\n\n#endif\
    \ // MATH_EULER_PHI_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: math/euler_phi.hpp
---
