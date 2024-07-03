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
  bundledCode: "#line 1 \"graph/graph_utility.hpp\"\n\n\n\ntemplate <class G>\nvector<int>\
    \ get_degree_sequence(const G &g) {\n    vector<int> degree(g.num_vertices());\n\
    \    for (int i = 0; i < g.num_vertices(); i++) {\n        degree[i] = g[i].size();\n\
    \    }\n    return degree;\n}\n\n\n"
  code: "#ifndef GRAPH_UTILITY_HPP\n#define GRAPH_UTILITY_HPP 1\n\ntemplate <class\
    \ G>\nvector<int> get_degree_sequence(const G &g) {\n    vector<int> degree(g.num_vertices());\n\
    \    for (int i = 0; i < g.num_vertices(); i++) {\n        degree[i] = g[i].size();\n\
    \    }\n    return degree;\n}\n\n#endif // GRAPH_UTILITY_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_utility.hpp
  requiredBy: []
  timestamp: '2024-07-03 14:07:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_utility.hpp
layout: document
redirect_from:
- /library/graph/graph_utility.hpp
- /library/graph/graph_utility.hpp.html
title: graph/graph_utility.hpp
---
