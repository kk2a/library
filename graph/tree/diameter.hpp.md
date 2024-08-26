---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/shortest_path.hpp
    title: graph/shortest_path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/diameter.hpp\"\n\n\n\n#line 1 \"graph/shortest_path.hpp\"\
    \n\n\n\nnamespace kk2 {\n\ntemplate <class WG, class T = typename WG::value_type>\n\
    struct ShortestPath {\n  public:\n    ShortestPath(const WG& g) : _n(g.size()),\
    \ _g(g) {}\n\n    int num_vertices() { return _n; }\n\n    pair<vector<T>, vector<int>>\
    \ query(\n        int start, T e = _ZERO, T inf = _INF) {\n        T alt;\n  \
    \      vector<T> dist(_n, inf);\n        vector<int> prev(_n, -1);\n        dist[start]\
    \ = e;\n\n        priority_queue<pair<T, int>,\n                       vector<pair<T,\
    \ int>>,\n                       greater<pair<T, int>>> pq;\n        pq.push({e,\
    \ start});\n\n        while (!pq.empty()) {\n            auto q = pq.top(); pq.pop();\n\
    \            if (dist[q.second] < q.first) continue;\n            for (auto edge\
    \ : _g[q.second]) {\n                alt = q.first + edge.cost;\n            \
    \    if (alt < dist[edge.to]) {\n                    pq.push( {alt, edge.to} );\n\
    \                    dist[edge.to] = alt;\n                    prev[edge.to] =\
    \ edge.id;\n                }\n            }\n        }\n\n        return {dist,\
    \ prev};\n    }\n\n  private:\n    int _n;\n    const WG& _g;\n    constexpr static\
    \ T _INF = numeric_limits<T>::max();\n    constexpr static T _ZERO = T(0);\n};\n\
    \n} // namespace kk2\n\n\n#line 5 \"graph/tree/diameter.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <class G>\npair<int, vector<int>> tree_diameter(const G& g) {\n\
    \    vector<int> dist(g.size(), -1), par(g.size(), -1);\n    auto dfs = [&](auto\
    \ self, int now) -> void {\n        for (auto& e : g[now]) {\n            if ((int)e\
    \ == par[now]) continue;\n            par[(int)e] = now;\n            dist[(int)e]\
    \ = dist[now] + 1;\n            self(self, (int)e);\n        }\n    };\n    dist[0]\
    \ = 0;\n    dfs(dfs, 0);\n    int u = max_element(begin(dist), end(dist)) - begin(dist);\n\
    \    dist[u] = 0;\n    fill(begin(par), end(par), -1);\n    dfs(dfs, u);\n   \
    \ int v = max_element(begin(dist), end(dist)) - begin(dist);\n    vector<int>\
    \ path;\n    for (int now = v; now != -1; now = par[now]) {\n        path.emplace_back(now);\n\
    \    }\n    return make_pair(dist[v], path);\n}\n\ntemplate <class WG, typename\
    \ T = typename WG::value_type>\npair<T, vector<int>> weighted_tree_diameter(const\
    \ WG& g) {\n    auto sp = ShortestPath<WG, T>(g);\n    auto [dist, _] = sp.query(0);\n\
    \    int u = max_element(begin(dist), end(dist)) - begin(dist);\n    auto [dist2,\
    \ par] = sp.query(u);\n    int v = max_element(begin(dist2), end(dist2)) - begin(dist2);\n\
    \    vector<int> path;\n    for (int now = v;;) {\n        path.emplace_back(now);\n\
    \        if (par[now] == -1) break;\n        now = g.edges[par[now]].to ^ g.edges[par[now]].from\
    \ ^ now;\n    }\n    return make_pair(dist2[v], path);\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef GRAPH_TREE_DIAMETER_HPP\n#define GRAPH_TREE_DIAMETER_HPP 1\n\n#include\
    \ \"../shortest_path.hpp\"\n\nnamespace kk2 {\n\ntemplate <class G>\npair<int,\
    \ vector<int>> tree_diameter(const G& g) {\n    vector<int> dist(g.size(), -1),\
    \ par(g.size(), -1);\n    auto dfs = [&](auto self, int now) -> void {\n     \
    \   for (auto& e : g[now]) {\n            if ((int)e == par[now]) continue;\n\
    \            par[(int)e] = now;\n            dist[(int)e] = dist[now] + 1;\n \
    \           self(self, (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs,\
    \ 0);\n    int u = max_element(begin(dist), end(dist)) - begin(dist);\n    dist[u]\
    \ = 0;\n    fill(begin(par), end(par), -1);\n    dfs(dfs, u);\n    int v = max_element(begin(dist),\
    \ end(dist)) - begin(dist);\n    vector<int> path;\n    for (int now = v; now\
    \ != -1; now = par[now]) {\n        path.emplace_back(now);\n    }\n    return\
    \ make_pair(dist[v], path);\n}\n\ntemplate <class WG, typename T = typename WG::value_type>\n\
    pair<T, vector<int>> weighted_tree_diameter(const WG& g) {\n    auto sp = ShortestPath<WG,\
    \ T>(g);\n    auto [dist, _] = sp.query(0);\n    int u = max_element(begin(dist),\
    \ end(dist)) - begin(dist);\n    auto [dist2, par] = sp.query(u);\n    int v =\
    \ max_element(begin(dist2), end(dist2)) - begin(dist2);\n    vector<int> path;\n\
    \    for (int now = v;;) {\n        path.emplace_back(now);\n        if (par[now]\
    \ == -1) break;\n        now = g.edges[par[now]].to ^ g.edges[par[now]].from ^\
    \ now;\n    }\n    return make_pair(dist2[v], path);\n}\n\n} // namespace kk2\n\
    \n#endif // GRAPH_TREE_DIAMETER_HPP\n"
  dependsOn:
  - graph/shortest_path.hpp
  isVerificationFile: false
  path: graph/tree/diameter.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:59:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/diameter.hpp
layout: document
redirect_from:
- /library/graph/tree/diameter.hpp
- /library/graph/tree/diameter.hpp.html
title: graph/tree/diameter.hpp
---
