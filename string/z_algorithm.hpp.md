---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_string/string_z_algorithm.test.cpp
    title: verify/yosupo_string/string_z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z_algorithm.hpp\"\n\n\n\n#include <string>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <typename T> std::vector<int> z_algorithm(const\
    \ std::vector<T> &s) {\n    int n = s.size();\n    if (n == 0) return {};\n  \
    \  std::vector<int> z(n);\n    z[0] = n;\n    int i = 1, j = 0;\n    while (i\
    \ < n) {\n        while (i + j < n and s[j] == s[i + j]) ++j;\n        z[i] =\
    \ j;\n        if (j == 0) {\n            ++i;\n            continue;\n       \
    \ }\n        int k = 1;\n        while (i + k < n and k + z[k] < j) z[i + k] =\
    \ z[k], ++k;\n        i += k, j -= k;\n    }\n    return z;\n}\n\nstd::vector<int>\
    \ z_algorithm(const std::string &s) {\n    int n = s.size();\n    std::vector<int>\
    \ s2(n);\n    for (int i = 0; i < n; i++) { s2[i] = s[i]; }\n    return z_algorithm(s2);\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_STRING_Z_ALGORITHM_HPP\n#define KK2_STRING_Z_ALGORITHM_HPP 1\n\
    \n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> std::vector<int> z_algorithm(const std::vector<T> &s) {\n    int n = s.size();\n\
    \    if (n == 0) return {};\n    std::vector<int> z(n);\n    z[0] = n;\n    int\
    \ i = 1, j = 0;\n    while (i < n) {\n        while (i + j < n and s[j] == s[i\
    \ + j]) ++j;\n        z[i] = j;\n        if (j == 0) {\n            ++i;\n   \
    \         continue;\n        }\n        int k = 1;\n        while (i + k < n and\
    \ k + z[k] < j) z[i + k] = z[k], ++k;\n        i += k, j -= k;\n    }\n    return\
    \ z;\n}\n\nstd::vector<int> z_algorithm(const std::string &s) {\n    int n = s.size();\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) { s2[i] = s[i];\
    \ }\n    return z_algorithm(s2);\n}\n\n} // namespace kk2\n\n#endif // KK2_STRING_Z_ALGORITHM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_string/string_z_algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
