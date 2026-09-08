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
    - filename: aoj_0233.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_0233.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_CONVERT_BASE_HPP\n#define KK2_MATH_CONVERT_BASE_HPP 1\n\
      \n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace kk2\
      \ {\n\ntemplate <class T> std::vector<T> convert_base(T x, T b) {\n    if (x\
      \ == 0) return {};\n    assert(b);\n    std::vector<T> res;\n    T k = abs(b);\n\
      \    while (x) {\n        res.emplace_back(x % k);\n        if (res.back() <\
      \ 0) res.back() += k;\n        x -= res.back();\n        x /= b;\n    }\n  \
      \  return res;\n}\n\ntemplate <class T> T from_base(const std::vector<T> &v,\
      \ T b) {\n    assert(b);\n    T res = 0;\n    for (int i = v.size() - 1; i >=\
      \ 0; i--) res = res * b + v[i];\n    return res;\n}\n\n} // namespace kk2\n\n\
      #endif // KK2_MATH_CONVERT_BASE_HPP\n"
    name: default
  - code: "#line 1 \"math/convert_base.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> std::vector<T>\
      \ convert_base(T x, T b) {\n    if (x == 0) return {};\n    assert(b);\n   \
      \ std::vector<T> res;\n    T k = abs(b);\n    while (x) {\n        res.emplace_back(x\
      \ % k);\n        if (res.back() < 0) res.back() += k;\n        x -= res.back();\n\
      \        x /= b;\n    }\n    return res;\n}\n\ntemplate <class T> T from_base(const\
      \ std::vector<T> &v, T b) {\n    assert(b);\n    T res = 0;\n    for (int i\
      \ = v.size() - 1; i >= 0; i--) res = res * b + v[i];\n    return res;\n}\n\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/convert_base.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_0233.test.cpp
documentation_of: math/convert_base.hpp
layout: document
---
