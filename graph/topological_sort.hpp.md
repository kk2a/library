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
  bundledCode: "#line 1 \"graph/topological_sort.hpp\"\n\n\n\ntemplate <class G>\n\
    vector<int> topological_sort(const G& graph) {\n\tint siz = size(graph);\n\tvector<int>\
    \ indegree(siz);\n\tfor (int i = 0; i < siz; i++) for (int j : graph[i]) indegree[j]++;\n\
    \tvector<int> res;\n\tqueue<int> que;\n\tfor (int i = 0; i < siz; i++) if (indegree[i]\
    \ == 0) que.push(i);\n\twhile (!que.empty()) {\n\t\tint ver = que.front(); que.pop();\n\
    \t\tres.push_back(ver);\n\t\tfor (int i : graph[ver]) {\n\t\t\tindegree[i]--;\n\
    \t\t\tif (indegree[i] == 0) que.push(i);\n\t\t}\n\t}\n\treturn res;\n}\n\n\n"
  code: "#ifndef TOPOLOGICAL_SORT_HPP\n#define TOPOLOGICAL_SORT_HPP 1\n\ntemplate\
    \ <class G>\nvector<int> topological_sort(const G& graph) {\n\tint siz = size(graph);\n\
    \tvector<int> indegree(siz);\n\tfor (int i = 0; i < siz; i++) for (int j : graph[i])\
    \ indegree[j]++;\n\tvector<int> res;\n\tqueue<int> que;\n\tfor (int i = 0; i <\
    \ siz; i++) if (indegree[i] == 0) que.push(i);\n\twhile (!que.empty()) {\n\t\t\
    int ver = que.front(); que.pop();\n\t\tres.push_back(ver);\n\t\tfor (int i : graph[ver])\
    \ {\n\t\t\tindegree[i]--;\n\t\t\tif (indegree[i] == 0) que.push(i);\n\t\t}\n\t\
    }\n\treturn res;\n}\n\n#endif // TOPOLOGICAL_SORT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-08-15 23:12:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
