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
  bundledCode: "#line 1 \"math/floor_ceil.hpp\"\n\n\n\n// long long floor\nlong long\
    \ fracfloor(long long a, long long b) {\n    assert(b != 0);\n    if (a % b ==\
    \ 0) return a / b;\n    if (a >= 0) return a / b;\n    return -((-a) / b) - 1;\n\
    } \n\n// long long ceil\nlong long fracceil(long long a, long long b) {\n    assert(b\
    \ != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\
    \    return -((-a) / b);\n}\n\n\n"
  code: "#ifndef MATH_FLOOR_CEIL_HPP\n#define MATH_FLOOR_CEIL_HPP 1\n\n// long long\
    \ floor\nlong long fracfloor(long long a, long long b) {\n    assert(b != 0);\n\
    \    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n    return\
    \ -((-a) / b) - 1;\n} \n\n// long long ceil\nlong long fracceil(long long a, long\
    \ long b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a\
    \ >= 0) return a / b + 1;\n    return -((-a) / b);\n}\n\n#endif // MATH_FLOOR_CEIL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_ceil.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_ceil.hpp
layout: document
redirect_from:
- /library/math/floor_ceil.hpp
- /library/math/floor_ceil.hpp.html
title: math/floor_ceil.hpp
---
