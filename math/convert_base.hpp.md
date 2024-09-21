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
  bundledCode: "#line 1 \"math/convert_base.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <class T> std::vector<T> convert_base(T\
    \ x, T b) {\n    if (x == 0) return {0};\n    assert(b);\n    std::vector<T> res;\n\
    \    T k = abs(b);\n    while (x) {\n        res.emplace_back(x % k);\n      \
    \  if (res.back() < 0) res.back() += k;\n        x -= res.back();\n        x /=\
    \ b;\n    }\n    return res;\n}\n\n\n"
  code: "#ifndef MATH_CONVERT_BASE_HPP\n#define MATH_CONVERT_BASE_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\ntemplate <class T> std::vector<T>\
    \ convert_base(T x, T b) {\n    if (x == 0) return {0};\n    assert(b);\n    std::vector<T>\
    \ res;\n    T k = abs(b);\n    while (x) {\n        res.emplace_back(x % k);\n\
    \        if (res.back() < 0) res.back() += k;\n        x -= res.back();\n    \
    \    x /= b;\n    }\n    return res;\n}\n\n#endif // MATH_CONVERT_BASE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/convert_base.hpp
  requiredBy: []
  timestamp: '2024-09-22 02:51:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convert_base.hpp
layout: document
redirect_from:
- /library/math/convert_base.hpp
- /library/math/convert_base.hpp.html
title: math/convert_base.hpp
---
