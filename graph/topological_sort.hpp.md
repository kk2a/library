---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_scc.test.cpp
    title: verify/yosupo_graph/graph_scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/topological_sort.hpp\"\n\n\n\n#include <queue>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <class G> std::vector<int> topological_sort(const\
    \ G &graph) {\n    int siz = size(graph);\n    std::vector<int> indegree(siz);\n\
    \    for (int i = 0; i < siz; i++)\n        for (int j : graph[i]) indegree[j]++;\n\
    \    std::vector<int> res;\n    std::queue<int> que;\n    for (int i = 0; i <\
    \ siz; i++)\n        if (indegree[i] == 0) que.push(i);\n    while (!que.empty())\
    \ {\n        int ver = que.front();\n        que.pop();\n        res.push_back(ver);\n\
    \        for (int i : graph[ver]) {\n            indegree[i]--;\n            if\
    \ (indegree[i] == 0) que.push(i);\n        }\n    }\n    return res;\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef TOPOLOGICAL_SORT_HPP\n#define TOPOLOGICAL_SORT_HPP 1\n\n#include\
    \ <queue>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> std::vector<int>\
    \ topological_sort(const G &graph) {\n    int siz = size(graph);\n    std::vector<int>\
    \ indegree(siz);\n    for (int i = 0; i < siz; i++)\n        for (int j : graph[i])\
    \ indegree[j]++;\n    std::vector<int> res;\n    std::queue<int> que;\n    for\
    \ (int i = 0; i < siz; i++)\n        if (indegree[i] == 0) que.push(i);\n    while\
    \ (!que.empty()) {\n        int ver = que.front();\n        que.pop();\n     \
    \   res.push_back(ver);\n        for (int i : graph[ver]) {\n            indegree[i]--;\n\
    \            if (indegree[i] == 0) que.push(i);\n        }\n    }\n    return\
    \ res;\n}\n\n} // namespace kk2\n\n#endif // TOPOLOGICAL_SORT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_scc.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
