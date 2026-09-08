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
  - code: "#ifndef KK2_MATH_MAX_DIVISION_TIMES_HPP\n#define KK2_MATH_MAX_DIVISION_TIMES_HPP\
      \ 1\n\nnamespace kk2 {\n\ntemplate <class T, class U> int max_division_times(T\
      \ a, U b) {\n    int res = 0;\n    while (a % b == 0) a /= b, res++;\n    return\
      \ res;\n}\n\ntemplate <class T, class U> int divide_max_times(T &a, U b) {\n\
      \    int res = 0;\n    while (a % b == 0) a /= b, res++;\n    return res;\n\
      }\n\n} // namespace kk2\n\n#endif // KK2_MATH_MAX_DIVISION_TIMES_HPP\n"
    name: default
  - code: "#line 1 \"math/max_division_times.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
      \ <class T, class U> int max_division_times(T a, U b) {\n    int res = 0;\n\
      \    while (a % b == 0) a /= b, res++;\n    return res;\n}\n\ntemplate <class\
      \ T, class U> int divide_max_times(T &a, U b) {\n    int res = 0;\n    while\
      \ (a % b == 0) a /= b, res++;\n    return res;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/max_division_times.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/max_division_times.hpp
layout: document
---
