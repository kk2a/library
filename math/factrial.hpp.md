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
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_FACTORIAL_HPP\n#define KK2_MATH_FACTORIAL_HPP 1\n\nnamespace\
      \ kk2 {\n\ntemplate <class S, class T> constexpr S fact(T n) {\n    if (n <\
      \ 0) return 1;\n    S res = 1;\n    for (T i = 1; i <= n; ++i) res *= i;\n \
      \   return res;\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_FACTORIAL_HPP\n"
    name: default
  - code: "#line 1 \"math/factrial.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate <class\
      \ S, class T> constexpr S fact(T n) {\n    if (n < 0) return 1;\n    S res =\
      \ 1;\n    for (T i = 1; i <= n; ++i) res *= i;\n    return res;\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/factrial.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factrial.hpp
layout: document
---
