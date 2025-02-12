---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/monoid/bsgs.hpp
    title: math/monoid/bsgs.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/pow.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class M, M (*op)(M, M), M (*e)()>\nM pow(M a, long long\
    \ n) {\n    M res = e();\n    while (n > 0) {\n        if (n & 1) res = op(res,\
    \ a);\n        if (n >>= 1) a = op(a, a);\n    }\n    return res;\n}\n\n} // namespace\
    \ monoid\n\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_POW_HPP\n#define KK2_MATH_MONOID_POW_HPP 1\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class M, M (*op)(M, M), M (*e)()>\n\
    M pow(M a, long long n) {\n    M res = e();\n    while (n > 0) {\n        if (n\
    \ & 1) res = op(res, a);\n        if (n >>= 1) a = op(a, a);\n    }\n    return\
    \ res;\n}\n\n} // namespace monoid\n\n\n} // namespace kk2\n\n#endif // KK2_MATH_MONOID_POW_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/pow.hpp
  requiredBy:
  - math/monoid/bsgs.hpp
  timestamp: '2025-02-12 19:35:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/pow.hpp
layout: document
redirect_from:
- /library/math/monoid/pow.hpp
- /library/math/monoid/pow.hpp.html
title: math/monoid/pow.hpp
---
