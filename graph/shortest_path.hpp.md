---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace\
    \ shortest_path {\n\nstruct edge {\n    int to, id;\n};\n\ntemplate <class T>\n\
    struct Result {\n    std::vector<T> dist;\n    std::vector<edge> prev;\n    Result(std::vector<T>\
    \ dist_, std::vector<edge> prev_)\n        : dist(dist_), prev(prev_) {}\n};\n\
    \ntemplate <class WG, class T = typename WG::value_type> \nResult<T> ShortestPath(const\
    \ WG &g, int start) {\n    T alt;\n    int n = g.size();\n    std::vector<T> dist(n,\
    \ std::numeric_limits<T>::max());\n    std::vector<edge> prev(n, {-1, -1});\n\n\
    \    std::priority_queue<std::pair<T, int>,\n                        std::vector<std::pair<T,\
    \ int>>,\n                        std::greater<std::pair<T, int>>>\n        pq;\n\
    \    dist[start] = 0;\n    pq.push({T(), start});\n\n    while (!pq.empty()) {\n\
    \        auto q = pq.top();\n        pq.pop();\n        if (dist[q.second] < q.first)\
    \ continue;\n        for (auto edge : g[q.second]) {\n            alt = q.first\
    \ + edge.cost;\n            if (alt < dist[edge.to]) {\n                pq.push({alt,\
    \ edge.to});\n                dist[edge.to] = alt;\n                prev[edge.to]\
    \ = {edge.from, edge.id};\n            }\n        }\n    }\n\n    return {dist,\
    \ prev};\n}\n\n} // namespace shortest_path\n\nusing shortest_path::ShortestPath;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_DIJKSTRA_HPP\n#define GRAPH_DIJKSTRA_HPP 1\n\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\n\
    namespace shortest_path {\n\nstruct edge {\n    int to, id;\n};\n\ntemplate <class\
    \ T>\nstruct Result {\n    std::vector<T> dist;\n    std::vector<edge> prev;\n\
    \    Result(std::vector<T> dist_, std::vector<edge> prev_)\n        : dist(dist_),\
    \ prev(prev_) {}\n};\n\ntemplate <class WG, class T = typename WG::value_type>\
    \ \nResult<T> ShortestPath(const WG &g, int start) {\n    T alt;\n    int n =\
    \ g.size();\n    std::vector<T> dist(n, std::numeric_limits<T>::max());\n    std::vector<edge>\
    \ prev(n, {-1, -1});\n\n    std::priority_queue<std::pair<T, int>,\n         \
    \               std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        pq;\n    dist[start] = 0;\n    pq.push({T(), start});\n\n  \
    \  while (!pq.empty()) {\n        auto q = pq.top();\n        pq.pop();\n    \
    \    if (dist[q.second] < q.first) continue;\n        for (auto edge : g[q.second])\
    \ {\n            alt = q.first + edge.cost;\n            if (alt < dist[edge.to])\
    \ {\n                pq.push({alt, edge.to});\n                dist[edge.to] =\
    \ alt;\n                prev[edge.to] = {edge.from, edge.id};\n            }\n\
    \        }\n    }\n\n    return {dist, prev};\n}\n\n} // namespace shortest_path\n\
    \nusing shortest_path::ShortestPath;\n\n} // namespace kk2\n\n#endif // GRAPH_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path.hpp
  requiredBy: []
  timestamp: '2024-10-08 15:38:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/shortest_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path.hpp
- /library/graph/shortest_path.hpp.html
title: graph/shortest_path.hpp
---
