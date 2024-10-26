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
  bundledCode: "#line 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2\
    \ {\n\ntemplate <class S, class T, class U> constexpr S pow(T x, U n) {\n    assert(n\
    \ >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n \
    \       y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef MATH_POW_EXPR_HPP\n#define MATH_POW_EXPR_HPP 1\n\n#include <cassert>\n\
    \nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow(T x,\
    \ U n) {\n    assert(n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if\
    \ (n & 1) r *= y;\n        y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\
    \n} // namespace kk2\n\n#endif // MATH_POW_EXPR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/pow.hpp
  requiredBy: []
  timestamp: '2024-10-26 15:17:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow.hpp
layout: document
redirect_from:
- /library/math/pow.hpp
- /library/math/pow.hpp.html
title: math/pow.hpp
---
