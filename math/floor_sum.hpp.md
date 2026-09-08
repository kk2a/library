---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/practice2/editorial/579
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: sum_of_floor_linear.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_floor_linear.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_FLOOR_SUM_HPP\n#define KK2_MATH_FLOOR_SUM_HPP 1\n\n#include\
      \ <algorithm>\n\nnamespace kk2 {\n\n// https://atcoder.jp/contests/practice2/editorial/579\n\
      // a, b\u306F\u975E\u8CA0\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\n\
      // sum_{i=0}^{n-1} floor((a * i + b) / m)\ntemplate <class T> T sum_of_floor(T\
      \ n, T m, T a, T b) {\n    T res = 0;\n    while (true) {\n        if (a >=\
      \ m) res += (n - 1) * n / 2 * (a / m), a %= m;\n        if (b >= m) res += n\
      \ * (b / m), b %= m;\n        T max = a * n + b;\n        if (max < m) break;\n\
      \        n = max / m, b = max % m;\n        std::swap(a, m);\n    }\n    return\
      \ res;\n}\n\ntemplate <class T> T sum_of_floor(T n, T m, T a, T b, T start)\
      \ {\n    return sum_of_floor(n - start, m, a, b + a * start);\n}\n\n} // namespace\
      \ kk2\n\n#endif // KK2_MATH_FLOOR_SUM_HPP\n"
    name: default
  - code: "#line 1 \"math/floor_sum.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
      \ kk2 {\n\n// https://atcoder.jp/contests/practice2/editorial/579\n// a, b\u306F\
      \u975E\u8CA0\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\n// sum_{i=0}^{n-1}\
      \ floor((a * i + b) / m)\ntemplate <class T> T sum_of_floor(T n, T m, T a, T\
      \ b) {\n    T res = 0;\n    while (true) {\n        if (a >= m) res += (n -\
      \ 1) * n / 2 * (a / m), a %= m;\n        if (b >= m) res += n * (b / m), b %=\
      \ m;\n        T max = a * n + b;\n        if (max < m) break;\n        n = max\
      \ / m, b = max % m;\n        std::swap(a, m);\n    }\n    return res;\n}\n\n\
      template <class T> T sum_of_floor(T n, T m, T a, T b, T start) {\n    return\
      \ sum_of_floor(n - start, m, a, b + a * start);\n}\n\n} // namespace kk2\n\n\
      \n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/floor_sum.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/sum_of_floor_linear.test.cpp
documentation_of: math/floor_sum.hpp
layout: document
---
