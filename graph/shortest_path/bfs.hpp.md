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
  bundledCode: "#line 1 \"graph/shortest_path/bfs.hpp\"\n\n\n\n#include <queue>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G, std::enable_if_t<!G::weighted::value> * = nullptr>\nvoid bfs(queue &q, std::vector<int>\
    \ &dist, int init) {\n    while (!q.empty()) {\n        int now = q.front();\n\
    \        q.pop();\n        for (auto e : g[now]) {\n            if (dist[e.to]\
    \ != init) continue;\n            dist[e.to] = dist[now] + 1;\n            q.push(e.to);\n\
    \        }\n    }\n}\n\ntemplate <class G, std::enable_if_t<G::weighted::value>\
    \ * = nullptr>\nvoid bfs(queue &q, std::vector<G::value_type> &dist, G::value_type\
    \ init) {\n    while (!q.empty()) {\n        int now = q.front();\n        q.pop();\n\
    \        for (auto e : g[now]) {\n            if (dist[e.to] != init) continue;\n\
    \            dist[e.to] = dist[now] + e.cost;\n            q.push(e.to);\n   \
    \     }\n    }\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_SHORTEST_PATH_BFS_HPP\n#define KK2_GRAPH_SHORTEST_PATH_BFS_HPP\
    \ 1\n\n#include <queue>\n#include <type_traits>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <class G, std::enable_if_t<!G::weighted::value> * = nullptr>\n\
    void bfs(queue &q, std::vector<int> &dist, int init) {\n    while (!q.empty())\
    \ {\n        int now = q.front();\n        q.pop();\n        for (auto e : g[now])\
    \ {\n            if (dist[e.to] != init) continue;\n            dist[e.to] = dist[now]\
    \ + 1;\n            q.push(e.to);\n        }\n    }\n}\n\ntemplate <class G, std::enable_if_t<G::weighted::value>\
    \ * = nullptr>\nvoid bfs(queue &q, std::vector<G::value_type> &dist, G::value_type\
    \ init) {\n    while (!q.empty()) {\n        int now = q.front();\n        q.pop();\n\
    \        for (auto e : g[now]) {\n            if (dist[e.to] != init) continue;\n\
    \            dist[e.to] = dist[now] + e.cost;\n            q.push(e.to);\n   \
    \     }\n    }\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_SHORTEST_PATH_BFS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/bfs.hpp
  requiredBy: []
  timestamp: '2025-03-02 17:07:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/bfs.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/bfs.hpp
- /library/graph/shortest_path/bfs.hpp.html
title: graph/shortest_path/bfs.hpp
---
