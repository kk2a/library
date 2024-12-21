---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_0233.test.cpp
    title: verify/aoj/aoj_0233.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/convert_base.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> std::vector<T>\
    \ convert_base(T x, T b) {\n    if (x == 0) return {0};\n    assert(b);\n    std::vector<T>\
    \ res;\n    T k = abs(b);\n    while (x) {\n        res.emplace_back(x % k);\n\
    \        if (res.back() < 0) res.back() += k;\n        x -= res.back();\n    \
    \    x /= b;\n    }\n    return res;\n}\n\ntemplate <class T> T from_base(const\
    \ std::vector<T> &v, T b) {\n    assert(b);\n    T res = 0;\n    for (int i =\
    \ v.size() - 1; i >= 0; i--) res = res * b + v[i];\n    return res;\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef MATH_CONVERT_BASE_HPP\n#define MATH_CONVERT_BASE_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class T> std::vector<T> convert_base(T x, T b) {\n    if (x == 0) return {0};\n\
    \    assert(b);\n    std::vector<T> res;\n    T k = abs(b);\n    while (x) {\n\
    \        res.emplace_back(x % k);\n        if (res.back() < 0) res.back() += k;\n\
    \        x -= res.back();\n        x /= b;\n    }\n    return res;\n}\n\ntemplate\
    \ <class T> T from_base(const std::vector<T> &v, T b) {\n    assert(b);\n    T\
    \ res = 0;\n    for (int i = v.size() - 1; i >= 0; i--) res = res * b + v[i];\n\
    \    return res;\n}\n\n} // namespace kk2\n\n#endif // MATH_CONVERT_BASE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convert_base.hpp
  requiredBy: []
  timestamp: '2024-09-28 15:39:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_0233.test.cpp
documentation_of: math/convert_base.hpp
layout: document
redirect_from:
- /library/math/convert_base.hpp
- /library/math/convert_base.hpp.html
title: math/convert_base.hpp
---
