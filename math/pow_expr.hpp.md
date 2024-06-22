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
  bundledCode: "#line 1 \"math/pow_expr.hpp\"\n\n\n\ntemplate <class S, class T, class\
    \ U>\nconstexpr S pow_constexpr(T x, U n) {\n    assert(!is_signed_v<U> && n >=\
    \ 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n    \
    \    y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n"
  code: "#ifndef MATH_POW_EXPR_HPP\n#define MATH_POW_EXPR_HPP 1\n\ntemplate <class\
    \ S, class T, class U>\nconstexpr S pow_constexpr(T x, U n) {\n    assert(!is_signed_v<U>\
    \ && n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n\
    \        y *= y;\n        n >>= 1;\n    }\n    return r;\n}\n\n#endif // MATH_POW_EXPR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_expr.hpp
  requiredBy: []
  timestamp: '2024-06-22 12:26:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow_expr.hpp
layout: document
redirect_from:
- /library/math/pow_expr.hpp
- /library/math/pow_expr.hpp.html
title: math/pow_expr.hpp
---
