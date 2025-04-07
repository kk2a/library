---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/two_edge_connected_components.hpp\"\n\n\n\n#include\
    \ <vector>\n\n#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <type_traits>\n#line 9 \"graph/lowlink.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class G> struct LowLink {\n    static_assert(!G::directed,\
    \ \"LowLink requires undirected graph\");\n\n    int n, m;\n    const G &g;\n\
    \    std::vector<int> ord, low;\n    std::vector<bool> root, used_on_dfs_tree;\n\
    \    std::vector<int> bridges, articulations;\n\n    LowLink(const G &g_)\n  \
    \      : n(g_.num_vertices()),\n          m(g_.num_edges()),\n          g(g_),\n\
    \          ord(n, -1),\n          low(n, -1),\n          root(n, false),\n   \
    \       used_on_dfs_tree(m, false) {\n        init();\n    }\n\n  private:\n \
    \   // v is a child of u in DFS tree\n    // edge(u, v) is a bridge <=> ord[u]\
    \ < low[v]\n\n    // u is an articulation point <=> (u is root and u has two or\
    \ more children) or\n    // there exists a v which is a child of u in DFS tree\
    \ and ord[u] <= low[v]\n\n    void init() {\n        int k = 0;\n        auto\
    \ dfs = [&](auto self, int u, int ei = -1) -> int {\n            low[u] = ord[u]\
    \ = k++;\n            bool is_articulation = false;\n            int count = 0;\n\
    \            for (auto &&e : g[u]) {\n                if (e.id == ei) continue;\n\
    \                if (ord[e.to] == -1) {\n                    ++count;\n      \
    \              used_on_dfs_tree[e.id] = true;\n                    low[u] = std::min(low[u],\
    \ self(self, e.to, e.id));\n                    if (ei != -1 and ord[u] <= low[e.to])\
    \ is_articulation = true;\n                    if (ord[u] < low[e.to]) bridges.emplace_back(e.id);\n\
    \                }\n                // back edge\n                else if (ord[e.to]\
    \ < ord[u]) {\n                    low[u] = std::min(low[u], ord[e.to]);\n   \
    \             }\n            }\n            if (ei == -1 and count >= 2) is_articulation\
    \ = true;\n            if (is_articulation) articulations.emplace_back(u);\n \
    \           return low[u];\n        };\n        for (int u = 0; u < n; u++)\n\
    \            if (ord[u] == -1) {\n                dfs(dfs, u);\n             \
    \   root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\n#line\
    \ 7 \"graph/two_edge_connected_components.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> struct TwoEdgeConnectedComponents : LowLink<G> {\n    TwoEdgeConnectedComponents(const\
    \ G &g_) : LowLink<G>(g_) { init_tecc(); }\n\n    std::vector<int> comp;\n   \
    \ std::vector<std::vector<int>> group;\n    G forest;\n\n    int size() const\
    \ { return group.size(); }\n\n  private:\n    void init_tecc() {\n        comp.resize(this->n,\
    \ -1);\n        int k = 0;\n        auto dfs = [&](auto self, int now, int par)\
    \ -> void {\n            if (par != -1 && this->ord[par] >= this->low[now]) comp[now]\
    \ = comp[par];\n            else comp[now] = k++;\n\n            for (auto &&e\
    \ : this->g[now])\n                if (comp[e.to] == -1) self(self, e.to, now);\n\
    \        };\n        for (int i = 0; i < this->n; i++)\n            if (this->root[i])\
    \ dfs(dfs, i, -1);\n\n        group.resize(k);\n        for (int i = 0; i < this->n;\
    \ i++) { group[comp[i]].emplace_back(i); }\n\n        typename G::edge_container\
    \ tmp(this->bridges.size());\n        for (int i = 0; i < (int)this->bridges.size();\
    \ i++) {\n            tmp[i] = this->g.edges[this->bridges[i]];\n            tmp[i].from\
    \ = comp[tmp[i].from];\n            tmp[i].to = comp[tmp[i].to];\n           \
    \ tmp[i].id = i;\n        }\n        forest = G(k, tmp);\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n#define KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\
    \ 1\n\n#include <vector>\n\n#include \"lowlink.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> struct TwoEdgeConnectedComponents : LowLink<G> {\n    TwoEdgeConnectedComponents(const\
    \ G &g_) : LowLink<G>(g_) { init_tecc(); }\n\n    std::vector<int> comp;\n   \
    \ std::vector<std::vector<int>> group;\n    G forest;\n\n    int size() const\
    \ { return group.size(); }\n\n  private:\n    void init_tecc() {\n        comp.resize(this->n,\
    \ -1);\n        int k = 0;\n        auto dfs = [&](auto self, int now, int par)\
    \ -> void {\n            if (par != -1 && this->ord[par] >= this->low[now]) comp[now]\
    \ = comp[par];\n            else comp[now] = k++;\n\n            for (auto &&e\
    \ : this->g[now])\n                if (comp[e.to] == -1) self(self, e.to, now);\n\
    \        };\n        for (int i = 0; i < this->n; i++)\n            if (this->root[i])\
    \ dfs(dfs, i, -1);\n\n        group.resize(k);\n        for (int i = 0; i < this->n;\
    \ i++) { group[comp[i]].emplace_back(i); }\n\n        typename G::edge_container\
    \ tmp(this->bridges.size());\n        for (int i = 0; i < (int)this->bridges.size();\
    \ i++) {\n            tmp[i] = this->g.edges[this->bridges[i]];\n            tmp[i].from\
    \ = comp[tmp[i].from];\n            tmp[i].to = comp[tmp[i].to];\n           \
    \ tmp[i].id = i;\n        }\n        forest = G(k, tmp);\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2025-03-28 03:08:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.hpp
- /library/graph/two_edge_connected_components.hpp.html
title: graph/two_edge_connected_components.hpp
---
