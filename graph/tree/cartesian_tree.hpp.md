---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_cartesian.test.cpp
    title: verify/yosupo_graph/tree_cartesian.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/cartesian_tree.hpp\"\n\n\n\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> std::pair<int, std::vector<int>>\
    \ cartesian_tree(const std::vector<T> &a) {\n    int n = a.size();\n    std::vector<int>\
    \ par(n, -1);\n    std::vector<int> stk;\n    for (int i = 0; i < n; ++i) {\n\
    \        int last = -1;\n        while (!stk.empty() && a[stk.back()] > a[i])\
    \ {\n            last = stk.back();\n            stk.pop_back();\n        }\n\
    \        if (last != -1) par[last] = i;\n        if (!stk.empty()) par[i] = stk.back();\n\
    \        stk.push_back(i);\n    }\n    return {stk[0], par};\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_TREE_CARTESIAN_TREE_HPP\n#define KK2_GRAPH_TREE_CARTESIAN_TREE_HPP\
    \ 1\n\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ T> std::pair<int, std::vector<int>> cartesian_tree(const std::vector<T> &a)\
    \ {\n    int n = a.size();\n    std::vector<int> par(n, -1);\n    std::vector<int>\
    \ stk;\n    for (int i = 0; i < n; ++i) {\n        int last = -1;\n        while\
    \ (!stk.empty() && a[stk.back()] > a[i]) {\n            last = stk.back();\n \
    \           stk.pop_back();\n        }\n        if (last != -1) par[last] = i;\n\
    \        if (!stk.empty()) par[i] = stk.back();\n        stk.push_back(i);\n \
    \   }\n    return {stk[0], par};\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_CARTESIAN_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_cartesian.test.cpp
documentation_of: graph/tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/graph/tree/cartesian_tree.hpp
- /library/graph/tree/cartesian_tree.hpp.html
title: graph/tree/cartesian_tree.hpp
---
