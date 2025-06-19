---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/dijkstra.hpp\"\n\n\n\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\n\
    namespace shortest_path_impl {\n\nstruct dij_edge {\n    int to, id;\n};\n\ntemplate\
    \ <class T> struct dij_result {\n    std::vector<T> dist;\n    std::vector<dij_edge>\
    \ prev;\n};\n\ntemplate <class WG, class T = typename WG::value_type>\ndij_result<T>\
    \ dijkstra(const WG &g, int start, T inf = std::numeric_limits<T>::max()) {\n\
    \    static_assert(WG::weighted, \"dijkstra requires weighted graph\");\n    T\
    \ alt;\n    int n = g.size();\n    std::vector<T> dist(n, inf);\n    std::vector<dij_edge>\
    \ prev(n, {-1, -1});\n\n    std::priority_queue<std::pair<T, int>,\n         \
    \               std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
    \ int>>>\n        pq;\n    dist[start] = 0;\n    pq.push({T(), start});\n\n  \
    \  while (!pq.empty()) {\n        auto q = pq.top();\n        pq.pop();\n    \
    \    if (dist[q.second] < q.first) continue;\n        for (auto dij_edge : g[q.second])\
    \ {\n            alt = q.first + dij_edge.cost;\n            if (alt < dist[dij_edge.to])\
    \ {\n                pq.push({alt, dij_edge.to});\n                dist[dij_edge.to]\
    \ = alt;\n                prev[dij_edge.to] = {dij_edge.from, dij_edge.id};\n\
    \            }\n        }\n    }\n\n    return {dist, prev};\n}\n\n} // namespace\
    \ shortest_path_impl\n\nusing shortest_path_impl::dijkstra;\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\n#define KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\
    \ 1\n\n#include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\
    \nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\nstruct dij_edge {\n   \
    \ int to, id;\n};\n\ntemplate <class T> struct dij_result {\n    std::vector<T>\
    \ dist;\n    std::vector<dij_edge> prev;\n};\n\ntemplate <class WG, class T =\
    \ typename WG::value_type>\ndij_result<T> dijkstra(const WG &g, int start, T inf\
    \ = std::numeric_limits<T>::max()) {\n    static_assert(WG::weighted, \"dijkstra\
    \ requires weighted graph\");\n    T alt;\n    int n = g.size();\n    std::vector<T>\
    \ dist(n, inf);\n    std::vector<dij_edge> prev(n, {-1, -1});\n\n    std::priority_queue<std::pair<T,\
    \ int>,\n                        std::vector<std::pair<T, int>>,\n           \
    \             std::greater<std::pair<T, int>>>\n        pq;\n    dist[start] =\
    \ 0;\n    pq.push({T(), start});\n\n    while (!pq.empty()) {\n        auto q\
    \ = pq.top();\n        pq.pop();\n        if (dist[q.second] < q.first) continue;\n\
    \        for (auto dij_edge : g[q.second]) {\n            alt = q.first + dij_edge.cost;\n\
    \            if (alt < dist[dij_edge.to]) {\n                pq.push({alt, dij_edge.to});\n\
    \                dist[dij_edge.to] = alt;\n                prev[dij_edge.to] =\
    \ {dij_edge.from, dij_edge.id};\n            }\n        }\n    }\n\n    return\
    \ {dist, prev};\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::dijkstra;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/dijkstra.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/shortest_path/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/dijkstra.hpp
- /library/graph/shortest_path/dijkstra.hpp.html
title: graph/shortest_path/dijkstra.hpp
---
