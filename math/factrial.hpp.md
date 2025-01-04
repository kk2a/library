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
  bundledCode: "#line 1 \"math/factrial.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate <class\
    \ S, class T> constexpr S fact(T n) {\n    if (n < 0) return 1;\n    S res = 1;\n\
    \    for (T i = 1; i <= n; ++i) res *= i;\n    return res;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_FACTORIAL_HPP\n#define KK2_MATH_FACTORIAL_HPP 1\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, class T> constexpr S fact(T n) {\n    if (n < 0)\
    \ return 1;\n    S res = 1;\n    for (T i = 1; i <= n; ++i) res *= i;\n    return\
    \ res;\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_FACTORIAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factrial.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factrial.hpp
layout: document
redirect_from:
- /library/math/factrial.hpp
- /library/math/factrial.hpp.html
title: math/factrial.hpp
---
