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
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n\ntemplate <class T> struct dij_graph\
    \ {\n  public:\n    dij_graph(int n) : _n(n), graph(n) {}\n\n    int num_vertices()\
    \ { return _n; }\n\n    void add_edge(int from, int to, T weight) {\n        graph[from].push_back({weight,\
    \ to});\n    } \n\n    pair<vector<T>, vector<int>> query(const int& start,\n\
    \                                          const T& e,\n                     \
    \                     const T& inf) {\n        T alt;\n        vector<T> dist(_n,\
    \ inf);\n        vector<int> prev(_n, -1);\n        dist[start] = e;\n\n     \
    \   priority_queue<pair<T, int>,\n                       vector<pair<T, int>>,\n\
    \                       greater<pair<T, int>>> pq;\n        pq.push({e, start});\n\
    \n        while (!pq.empty()) {\n            auto q = pq.top(); pq.pop();\n  \
    \          if (dist[q.second] < q.first) continue;\n            for (auto v :\
    \ graph[q.second]) {\n                alt = q.first + v.first;\n             \
    \   if (alt < dist[v.second]) {\n                    pq.push( {alt, v.second}\
    \ );\n                    dist[v.second] = alt;\n                    prev[v.second]\
    \ = q.second; \n                }\n            }\n        }\n\n        return\
    \ {dist, prev};\n    }\n    \n  private:\n    int _n;\n    vector<vector<pair<T,\
    \ int>>> graph;\n};\n\n\n"
  code: "#ifndef GRAPH_DIJKSTRA_HPP\n#define GRAPH_DIJKSTRA_HPP 1\n\ntemplate <class\
    \ T> struct dij_graph {\n  public:\n    dij_graph(int n) : _n(n), graph(n) {}\n\
    \n    int num_vertices() { return _n; }\n\n    void add_edge(int from, int to,\
    \ T weight) {\n        graph[from].push_back({weight, to});\n    } \n\n    pair<vector<T>,\
    \ vector<int>> query(const int& start,\n                                     \
    \     const T& e,\n                                          const T& inf) {\n\
    \        T alt;\n        vector<T> dist(_n, inf);\n        vector<int> prev(_n,\
    \ -1);\n        dist[start] = e;\n\n        priority_queue<pair<T, int>,\n   \
    \                    vector<pair<T, int>>,\n                       greater<pair<T,\
    \ int>>> pq;\n        pq.push({e, start});\n\n        while (!pq.empty()) {\n\
    \            auto q = pq.top(); pq.pop();\n            if (dist[q.second] < q.first)\
    \ continue;\n            for (auto v : graph[q.second]) {\n                alt\
    \ = q.first + v.first;\n                if (alt < dist[v.second]) {\n        \
    \            pq.push( {alt, v.second} );\n                    dist[v.second] =\
    \ alt;\n                    prev[v.second] = q.second; \n                }\n \
    \           }\n        }\n\n        return {dist, prev};\n    }\n    \n  private:\n\
    \    int _n;\n    vector<vector<pair<T, int>>> graph;\n};\n\n#endif // GRAPH_DIJKSTRA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-05-29 18:32:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
