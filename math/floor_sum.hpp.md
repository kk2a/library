---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/sum_of_floor_linear.test.cpp
    title: verify/yosupo_math/sum_of_floor_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/editorial/579
  bundledCode: "#line 1 \"math/floor_sum.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ kk2 {\n\n// https://atcoder.jp/contests/practice2/editorial/579\n// sum_{i=0}^{n-1}\
    \ floor((a * i + b) / m)\ntemplate <class T> T sum_of_floor(T n, T m, T a, T b)\
    \ {\n    T res = 0;\n    while (true) {\n        if (a >= m) res += (n - 1) *\
    \ n / 2 * (a / m), a %= m;\n        if (b >= m) res += n * (b / m), b %= m;\n\
    \        T max = a * n + b;\n        if (max < m) break;\n        n = max / m,\
    \ b = max % m;\n        std::swap(a, m);\n    }\n    return res;\n}\n\ntemplate\
    \ <class T> T sum_of_floor(T n, T m, T a, T b, T start) {\n    return sum_of_floor(n\
    \ - start, m, a, b + a * start);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_FLOOR_SUM_HPP\n#define KK2_MATH_FLOOR_SUM_HPP 1\n\n#include\
    \ <algorithm>\n\nnamespace kk2 {\n\n// https://atcoder.jp/contests/practice2/editorial/579\n\
    // sum_{i=0}^{n-1} floor((a * i + b) / m)\ntemplate <class T> T sum_of_floor(T\
    \ n, T m, T a, T b) {\n    T res = 0;\n    while (true) {\n        if (a >= m)\
    \ res += (n - 1) * n / 2 * (a / m), a %= m;\n        if (b >= m) res += n * (b\
    \ / m), b %= m;\n        T max = a * n + b;\n        if (max < m) break;\n   \
    \     n = max / m, b = max % m;\n        std::swap(a, m);\n    }\n    return res;\n\
    }\n\ntemplate <class T> T sum_of_floor(T n, T m, T a, T b, T start) {\n    return\
    \ sum_of_floor(n - start, m, a, b + a * start);\n}\n\n} // namespace kk2\n\n#endif\
    \ // KK2_MATH_FLOOR_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/sum_of_floor_linear.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
redirect_from:
- /library/math/floor_sum.hpp
- /library/math/floor_sum.hpp.html
title: math/floor_sum.hpp
---
