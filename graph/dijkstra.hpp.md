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
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n\ntemplate <class WG, class T\
    \ = typename WG::value_type>\nstruct Dijkstra {\n  public:\n    Dijkstra(const\
    \ WG& g) : _n(g.num_vertices()), _g(g) {}\n\n    int num_vertices() { return _n;\
    \ }\n\n    pair<vector<T>, vector<int>> query(\n        int start, T e = _ZERO,\
    \ T inf = _INF) {\n        T alt;\n        vector<T> dist(_n, inf);\n        vector<int>\
    \ prev(_n, -1);\n        dist[start] = e;\n\n        priority_queue<pair<T, int>,\n\
    \                       vector<pair<T, int>>,\n                       greater<pair<T,\
    \ int>>> pq;\n        pq.push({e, start});\n\n        while (!pq.empty()) {\n\
    \            auto q = pq.top(); pq.pop();\n            if (dist[q.second] < q.first)\
    \ continue;\n            for (auto v : graph[q.second]) {\n                alt\
    \ = q.first + v.first;\n                if (alt < dist[v.second]) {\n        \
    \            pq.push( {alt, v.second} );\n                    dist[v.second] =\
    \ alt;\n                    prev[v.second] = q.second; \n                }\n \
    \           }\n        }\n\n        return {dist, prev};\n    }\n\n  private:\n\
    \    int _n;\n    const WG& _g;\n    constexpr static T _INF = numeric_limits<T>::max();\n\
    \    constexpr static T _ZERO = T(0);\n};\n\n\n"
  code: "#ifndef GRAPH_DIJKSTRA_HPP\n#define GRAPH_DIJKSTRA_HPP 1\n\ntemplate <class\
    \ WG, class T = typename WG::value_type>\nstruct Dijkstra {\n  public:\n    Dijkstra(const\
    \ WG& g) : _n(g.num_vertices()), _g(g) {}\n\n    int num_vertices() { return _n;\
    \ }\n\n    pair<vector<T>, vector<int>> query(\n        int start, T e = _ZERO,\
    \ T inf = _INF) {\n        T alt;\n        vector<T> dist(_n, inf);\n        vector<int>\
    \ prev(_n, -1);\n        dist[start] = e;\n\n        priority_queue<pair<T, int>,\n\
    \                       vector<pair<T, int>>,\n                       greater<pair<T,\
    \ int>>> pq;\n        pq.push({e, start});\n\n        while (!pq.empty()) {\n\
    \            auto q = pq.top(); pq.pop();\n            if (dist[q.second] < q.first)\
    \ continue;\n            for (auto v : graph[q.second]) {\n                alt\
    \ = q.first + v.first;\n                if (alt < dist[v.second]) {\n        \
    \            pq.push( {alt, v.second} );\n                    dist[v.second] =\
    \ alt;\n                    prev[v.second] = q.second; \n                }\n \
    \           }\n        }\n\n        return {dist, prev};\n    }\n\n  private:\n\
    \    int _n;\n    const WG& _g;\n    constexpr static T _INF = numeric_limits<T>::max();\n\
    \    constexpr static T _ZERO = T(0);\n};\n\n#endif // GRAPH_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-15 18:54:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
