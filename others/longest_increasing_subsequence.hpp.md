---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_others/longest_increasing_subsequence.test.cpp
    title: verify/yosupo_others/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/longest_increasing_subsequence.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\n//\
    \ return indices of longest increasing subsequence\ntemplate <class T> std::vector<int>\
    \ longest_increasing_subsequence(const std::vector<T> &a) {\n    int n = a.size();\n\
    \    std::vector<std::pair<T, int>> dp;\n    std::vector<int> prev(n, -1);\n \
    \   for (int i = 0; i < n; ++i) {\n        auto it = std::lower_bound(dp.begin(),\
    \ dp.end(), std::make_pair(a[i], -i));\n        if (it != dp.begin()) {\n    \
    \        prev[i] = -std::prev(it)->second;\n        }\n        if (it == dp.end())\
    \ {\n            dp.emplace_back(a[i], -i);\n        } else {\n            *it\
    \ = std::make_pair(a[i], -i);\n        }\n    } \n\n    std::vector<int> res;\n\
    \    for (int i = -std::prev(dp.end())->second; i >= 0; i = prev[i]) {\n     \
    \   res.push_back(i);\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP\n#define KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP\
    \ 1\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\n// return indices of longest increasing subsequence\ntemplate <class\
    \ T> std::vector<int> longest_increasing_subsequence(const std::vector<T> &a)\
    \ {\n    int n = a.size();\n    std::vector<std::pair<T, int>> dp;\n    std::vector<int>\
    \ prev(n, -1);\n    for (int i = 0; i < n; ++i) {\n        auto it = std::lower_bound(dp.begin(),\
    \ dp.end(), std::make_pair(a[i], -i));\n        if (it != dp.begin()) {\n    \
    \        prev[i] = -std::prev(it)->second;\n        }\n        if (it == dp.end())\
    \ {\n            dp.emplace_back(a[i], -i);\n        } else {\n            *it\
    \ = std::make_pair(a[i], -i);\n        }\n    } \n\n    std::vector<int> res;\n\
    \    for (int i = -std::prev(dp.end())->second; i >= 0; i = prev[i]) {\n     \
    \   res.push_back(i);\n    }\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n}\n\n} // namespace kk2\n\n#endif // KK2_OTHERS_LONGEST_INCREASING_SUBSEQUENCE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2025-01-05 08:24:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_others/longest_increasing_subsequence.test.cpp
documentation_of: others/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/others/longest_increasing_subsequence.hpp
- /library/others/longest_increasing_subsequence.hpp.html
title: others/longest_increasing_subsequence.hpp
---
