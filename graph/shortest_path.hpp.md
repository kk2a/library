---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/diameter.hpp
    title: graph/tree/diameter.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class WG, class T = typename WG::value_type> struct ShortestPath {\n  public:\n\
    \    ShortestPath(const WG &g) : _n(g.size()), _g(g) {}\n\n    int num_vertices()\
    \ { return _n; }\n\n    std::pair<std::vector<T>, std::vector<int>>\n    query(int\
    \ start, T e = _ZERO, T inf = _INF) {\n        T alt;\n        std::vector<T>\
    \ dist(_n, inf);\n        std::vector<int> prev(_n, -1);\n        dist[start]\
    \ = e;\n\n        std::priority_queue<std::pair<T, int>,\n                   \
    \         std::vector<std::pair<T, int>>,\n                            std::greater<std::pair<T,\
    \ int>>>\n            pq;\n        pq.push({e, start});\n\n        while (!pq.empty())\
    \ {\n            auto q = pq.top();\n            pq.pop();\n            if (dist[q.second]\
    \ < q.first) continue;\n            for (auto edge : _g[q.second]) {\n       \
    \         alt = q.first + edge.cost;\n                if (alt < dist[edge.to])\
    \ {\n                    pq.push({alt, edge.to});\n                    dist[edge.to]\
    \ = alt;\n                    prev[edge.to] = edge.id;\n                }\n  \
    \          }\n        }\n\n        return {dist, prev};\n    }\n\n  private:\n\
    \    int _n;\n    const WG &_g;\n    constexpr static T _INF = std::numeric_limits<T>::max();\n\
    \    constexpr static T _ZERO = T();\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_DIJKSTRA_HPP\n#define GRAPH_DIJKSTRA_HPP 1\n\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\n\
    template <class WG, class T = typename WG::value_type> struct ShortestPath {\n\
    \  public:\n    ShortestPath(const WG &g) : _n(g.size()), _g(g) {}\n\n    int\
    \ num_vertices() { return _n; }\n\n    std::pair<std::vector<T>, std::vector<int>>\n\
    \    query(int start, T e = _ZERO, T inf = _INF) {\n        T alt;\n        std::vector<T>\
    \ dist(_n, inf);\n        std::vector<int> prev(_n, -1);\n        dist[start]\
    \ = e;\n\n        std::priority_queue<std::pair<T, int>,\n                   \
    \         std::vector<std::pair<T, int>>,\n                            std::greater<std::pair<T,\
    \ int>>>\n            pq;\n        pq.push({e, start});\n\n        while (!pq.empty())\
    \ {\n            auto q = pq.top();\n            pq.pop();\n            if (dist[q.second]\
    \ < q.first) continue;\n            for (auto edge : _g[q.second]) {\n       \
    \         alt = q.first + edge.cost;\n                if (alt < dist[edge.to])\
    \ {\n                    pq.push({alt, edge.to});\n                    dist[edge.to]\
    \ = alt;\n                    prev[edge.to] = edge.id;\n                }\n  \
    \          }\n        }\n\n        return {dist, prev};\n    }\n\n  private:\n\
    \    int _n;\n    const WG &_g;\n    constexpr static T _INF = std::numeric_limits<T>::max();\n\
    \    constexpr static T _ZERO = T();\n};\n\n} // namespace kk2\n\n#endif // GRAPH_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path.hpp
  requiredBy:
  - graph/tree/diameter.hpp
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path.hpp
- /library/graph/shortest_path.hpp.html
title: graph/shortest_path.hpp
---
