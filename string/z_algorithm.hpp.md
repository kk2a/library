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
    - filename: string_z_algorithm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_algorithm.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_STRING_Z_ALGORITHM_HPP\n#define KK2_STRING_Z_ALGORITHM_HPP\
      \ 1\n\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <typename\
      \ T> std::vector<int> z_algorithm(const std::vector<T> &s) {\n    int n = s.size();\n\
      \    if (n == 0) return {};\n    std::vector<int> z(n);\n    z[0] = n;\n   \
      \ int i = 1, j = 0;\n    while (i < n) {\n        while (i + j < n and s[j]\
      \ == s[i + j]) ++j;\n        z[i] = j;\n        if (j == 0) {\n            ++i;\n\
      \            continue;\n        }\n        int k = 1;\n        while (i + k\
      \ < n and k + z[k] < j) z[i + k] = z[k], ++k;\n        i += k, j -= k;\n   \
      \ }\n    return z;\n}\n\nstd::vector<int> z_algorithm(const std::string &s)\
      \ {\n    int n = s.size();\n    std::vector<int> s2(n);\n    for (int i = 0;\
      \ i < n; i++) { s2[i] = s[i]; }\n    return z_algorithm(s2);\n}\n\n} // namespace\
      \ kk2\n\n#endif // KK2_STRING_Z_ALGORITHM_HPP\n"
    name: default
  - code: "#line 1 \"string/z_algorithm.hpp\"\n\n\n\n#include <string>\n#include <vector>\n\
      \nnamespace kk2 {\n\ntemplate <typename T> std::vector<int> z_algorithm(const\
      \ std::vector<T> &s) {\n    int n = s.size();\n    if (n == 0) return {};\n\
      \    std::vector<int> z(n);\n    z[0] = n;\n    int i = 1, j = 0;\n    while\
      \ (i < n) {\n        while (i + j < n and s[j] == s[i + j]) ++j;\n        z[i]\
      \ = j;\n        if (j == 0) {\n            ++i;\n            continue;\n   \
      \     }\n        int k = 1;\n        while (i + k < n and k + z[k] < j) z[i\
      \ + k] = z[k], ++k;\n        i += k, j -= k;\n    }\n    return z;\n}\n\nstd::vector<int>\
      \ z_algorithm(const std::string &s) {\n    int n = s.size();\n    std::vector<int>\
      \ s2(n);\n    for (int i = 0; i < n; i++) { s2[i] = s[i]; }\n    return z_algorithm(s2);\n\
      }\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: string/z_algorithm.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_string/string_z_algorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
---
