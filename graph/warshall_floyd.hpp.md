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
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n\nnamespace kk2 {\n\ntemplate <class WG,\
    \ class T = typename WG::value_type> struct WarshallFroyd {\n    WG d;\n    T\
    \ inf = std::numeric_limits<T>::max();\n    T zero = T();\n\n    WarshallFroyd(const\
    \ WG &g_) : d(g_) { init(); }\n\n    void init() {\n        assert(d.adjacency_matrix);\n\
    \        int n = d.size();\n\n        for (auto &&e : d.edges) {\n           \
    \ d[e.from][e.to].cost = std::min(d[e.from][e.to].cost, e.cost);\n           \
    \ if constexpr (!WG::directed()) {\n                d[e.to][e.from].cost = std::min(d[e.to][e.from].cost,\
    \ e.cost);\n            }\n        }\n\n        for (int i = 0; i < n; i++) {\n\
    \            for (int j = 0; j < n; j++) {\n                if (i == j) {\n  \
    \                  d[i][j].cost = zero;\n                } else if (d[i][j].id\
    \ == -1) {\n                    d[i][j].cost = inf;\n                }\n     \
    \       }\n        }\n\n        for (int k = 0; k < n; k++) {\n            for\
    \ (int i = 0; i < n; i++) {\n                for (int j = 0; j < n; j++) {\n \
    \                   if (d[i][k].cost == inf || d[k][j].cost == inf) continue;\n\
    \                    d[i][j].cost =\n                        std::min(d[i][j].cost,\
    \ d[i][k].cost + d[k][j].cost);\n                }\n            }\n        }\n\
    \    }\n\n    T operator()(int i, int j) const {\n        return d[i][j].cost\
    \ == inf ? -1 : d[i][j].cost;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_WARSHALL_FLOYD_HPP\n#define GRAPH_WARSHALL_FLOYD_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <limits>\n\nnamespace kk2 {\n\
    \ntemplate <class WG, class T = typename WG::value_type> struct WarshallFroyd\
    \ {\n    WG d;\n    T inf = std::numeric_limits<T>::max();\n    T zero = T();\n\
    \n    WarshallFroyd(const WG &g_) : d(g_) { init(); }\n\n    void init() {\n \
    \       assert(d.adjacency_matrix);\n        int n = d.size();\n\n        for\
    \ (auto &&e : d.edges) {\n            d[e.from][e.to].cost = std::min(d[e.from][e.to].cost,\
    \ e.cost);\n            if constexpr (!WG::directed()) {\n                d[e.to][e.from].cost\
    \ = std::min(d[e.to][e.from].cost, e.cost);\n            }\n        }\n\n    \
    \    for (int i = 0; i < n; i++) {\n            for (int j = 0; j < n; j++) {\n\
    \                if (i == j) {\n                    d[i][j].cost = zero;\n   \
    \             } else if (d[i][j].id == -1) {\n                    d[i][j].cost\
    \ = inf;\n                }\n            }\n        }\n\n        for (int k =\
    \ 0; k < n; k++) {\n            for (int i = 0; i < n; i++) {\n              \
    \  for (int j = 0; j < n; j++) {\n                    if (d[i][k].cost == inf\
    \ || d[k][j].cost == inf) continue;\n                    d[i][j].cost =\n    \
    \                    std::min(d[i][j].cost, d[i][k].cost + d[k][j].cost);\n  \
    \              }\n            }\n        }\n    }\n\n    T operator()(int i, int\
    \ j) const {\n        return d[i][j].cost == inf ? -1 : d[i][j].cost;\n    }\n\
    };\n\n} // namespace kk2\n\n#endif // GRAPH_WARSHALL_FLOYD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-09-22 12:32:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
