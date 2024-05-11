---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"topological_sort.cpp\"\n// topological_sort\nvector<int>\
    \ topological_sort(vector<vector<int>> graph) {\n    int siz = size(graph);\n\t\
    vector<int> indegree(siz);\n\tfor (int i = 0; i < siz; i++) for (int j : graph[i])\
    \ indegree[j]++;\n\tvector<int> res;\n\tqueue<int> que;\n\tfor (int i = 0; i <\
    \ siz; i++) if (indegree[i] == 0) que.push(i);\n\twhile (!que.empty()) {\n\t\t\
    int ver = que.front(); que.pop();\n\t\tres.push_back(ver);\n\t\tfor (int i : graph[ver])\
    \ {\n\t\t\tindegree[i]--;\n\t\t\tif (indegree[i] == 0) que.push(i);\n\t\t}\n\t\
    }\n\treturn res;\n}\n\n"
  code: "// topological_sort\nvector<int> topological_sort(vector<vector<int>> graph)\
    \ {\n    int siz = size(graph);\n\tvector<int> indegree(siz);\n\tfor (int i =\
    \ 0; i < siz; i++) for (int j : graph[i]) indegree[j]++;\n\tvector<int> res;\n\
    \tqueue<int> que;\n\tfor (int i = 0; i < siz; i++) if (indegree[i] == 0) que.push(i);\n\
    \twhile (!que.empty()) {\n\t\tint ver = que.front(); que.pop();\n\t\tres.push_back(ver);\n\
    \t\tfor (int i : graph[ver]) {\n\t\t\tindegree[i]--;\n\t\t\tif (indegree[i] ==\
    \ 0) que.push(i);\n\t\t}\n\t}\n\treturn res;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: topological_sort.cpp
  requiredBy: []
  timestamp: '2024-05-03 02:50:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: topological_sort.cpp
layout: document
redirect_from:
- /library/topological_sort.cpp
- /library/topological_sort.cpp.html
title: topological_sort.cpp
---
