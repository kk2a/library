---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/diameter.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <functional>\n#include <utility>\n#include <vector>\n\nnamespace kk2\
    \ {\n\ntemplate <class G> std::pair<int, std::vector<int>> tree_diameter(const\
    \ G &g) {\n    std::vector<int> dist(g.size(), -1), par(g.size(), -1);\n    auto\
    \ dfs = [&](auto self, int now) -> void {\n        for (auto &e : g[now]) {\n\
    \            if ((int)e == par[now]) continue;\n            par[(int)e] = now;\n\
    \            dist[(int)e] = dist[now] + 1;\n            self(self, (int)e);\n\
    \        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0);\n    int u = std::max_element(std::begin(dist),\
    \ std::end(dist)) - std::begin(dist);\n    dist[u] = 0;\n    std::fill(std::begin(par),\
    \ std::end(par), -1);\n    dfs(dfs, u);\n    int v = std::max_element(std::begin(dist),\
    \ std::end(dist)) - std::begin(dist);\n    std::vector<int> path;\n    for (int\
    \ now = v; now != -1; now = par[now]) { path.emplace_back(now); }\n    return\
    \ std::make_pair(dist[v], path);\n}\n\ntemplate <class WG, typename T = typename\
    \ WG::value_type>\nstd::pair<T, std::vector<int>> weighted_tree_diameter(const\
    \ WG &g) {\n    std::vector<T> dist(g.size(), -1);\n    std::vector<int> par(g.size(),\
    \ -1);\n\n    auto dfs = [&](auto self, int now) -> void {\n        for (auto\
    \ &e : g[now]) {\n            if ((int)e == par[now]) continue;\n            par[(int)e]\
    \ = now;\n            dist[(int)e] = dist[now] + e.cost;\n            self(self,\
    \ (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0);\n    int u =\
    \ std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n   \
    \ dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
    \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
    \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
    \ { path.emplace_back(now); }\n    return std::make_pair(dist[v], path);\n}\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TREE_DIAMETER_HPP\n#define GRAPH_TREE_DIAMETER_HPP 1\n\n#include\
    \ <algorithm>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
    namespace kk2 {\n\ntemplate <class G> std::pair<int, std::vector<int>> tree_diameter(const\
    \ G &g) {\n    std::vector<int> dist(g.size(), -1), par(g.size(), -1);\n    auto\
    \ dfs = [&](auto self, int now) -> void {\n        for (auto &e : g[now]) {\n\
    \            if ((int)e == par[now]) continue;\n            par[(int)e] = now;\n\
    \            dist[(int)e] = dist[now] + 1;\n            self(self, (int)e);\n\
    \        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0);\n    int u = std::max_element(std::begin(dist),\
    \ std::end(dist)) - std::begin(dist);\n    dist[u] = 0;\n    std::fill(std::begin(par),\
    \ std::end(par), -1);\n    dfs(dfs, u);\n    int v = std::max_element(std::begin(dist),\
    \ std::end(dist)) - std::begin(dist);\n    std::vector<int> path;\n    for (int\
    \ now = v; now != -1; now = par[now]) { path.emplace_back(now); }\n    return\
    \ std::make_pair(dist[v], path);\n}\n\ntemplate <class WG, typename T = typename\
    \ WG::value_type>\nstd::pair<T, std::vector<int>> weighted_tree_diameter(const\
    \ WG &g) {\n    std::vector<T> dist(g.size(), -1);\n    std::vector<int> par(g.size(),\
    \ -1);\n\n    auto dfs = [&](auto self, int now) -> void {\n        for (auto\
    \ &e : g[now]) {\n            if ((int)e == par[now]) continue;\n            par[(int)e]\
    \ = now;\n            dist[(int)e] = dist[now] + e.cost;\n            self(self,\
    \ (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs, 0);\n    int u =\
    \ std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n   \
    \ dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
    \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
    \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
    \ { path.emplace_back(now); }\n    return std::make_pair(dist[v], path);\n}\n\n\
    } // namespace kk2\n\n#endif // GRAPH_TREE_DIAMETER_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/diameter.hpp
  requiredBy: []
  timestamp: '2024-10-08 15:38:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_graph/tree_diameter.test.cpp
documentation_of: graph/tree/diameter.hpp
layout: document
redirect_from:
- /library/graph/tree/diameter.hpp
- /library/graph/tree/diameter.hpp.html
title: graph/tree/diameter.hpp
---