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
  bundledCode: "#line 1 \"math/max_division_times.hpp\"\n\n\n\nnamespace kk2 {\n\n\
    template <class T, class U> int max_division_times(T a, U b) {\n    int res =\
    \ 0;\n    while (a % b == 0) a /= b, res++;\n    return res;\n}\n\ntemplate <class\
    \ T, class U> int divide_max_times(T &a, U b) {\n    int res = 0;\n    while (a\
    \ % b == 0) a /= b, res++;\n    return res;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MAX_DIVISION_TIMES_HPP\n#define KK2_MATH_MAX_DIVISION_TIMES_HPP\
    \ 1\n\nnamespace kk2 {\n\ntemplate <class T, class U> int max_division_times(T\
    \ a, U b) {\n    int res = 0;\n    while (a % b == 0) a /= b, res++;\n    return\
    \ res;\n}\n\ntemplate <class T, class U> int divide_max_times(T &a, U b) {\n \
    \   int res = 0;\n    while (a % b == 0) a /= b, res++;\n    return res;\n}\n\n\
    } // namespace kk2\n\n#endif // KK2_MATH_MAX_DIVISION_TIMES_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/max_division_times.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/max_division_times.hpp
layout: document
redirect_from:
- /library/math/max_division_times.hpp
- /library/math/max_division_times.hpp.html
title: math/max_division_times.hpp
---
