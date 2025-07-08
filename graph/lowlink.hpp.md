---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bcc.hpp
    title: graph/bcc.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/block_cut_tree.hpp
    title: graph/tree/block_cut_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_1326.test.cpp
    title: verify/yuki/yuki_1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <type_traits>\n#include <vector>\n\
    \nnamespace kk2 {\n\ntemplate <class G> struct LowLink {\n    static_assert(!G::directed,\
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
    \   root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_LOWLINK_HPP\n#define KK2_GRAPH_LOWLINK_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct LowLink {\n\
    \    static_assert(!G::directed, \"LowLink requires undirected graph\");\n\n \
    \   int n, m;\n    const G &g;\n    std::vector<int> ord, low;\n    std::vector<bool>\
    \ root, used_on_dfs_tree;\n    std::vector<int> bridges, articulations;\n\n  \
    \  LowLink(const G &g_)\n        : n(g_.num_vertices()),\n          m(g_.num_edges()),\n\
    \          g(g_),\n          ord(n, -1),\n          low(n, -1),\n          root(n,\
    \ false),\n          used_on_dfs_tree(m, false) {\n        init();\n    }\n\n\
    \  private:\n    // v is a child of u in DFS tree\n    // edge(u, v) is a bridge\
    \ <=> ord[u] < low[v]\n\n    // u is an articulation point <=> (u is root and\
    \ u has two or more children) or\n    // there exists a v which is a child of\
    \ u in DFS tree and ord[u] <= low[v]\n\n    void init() {\n        int k = 0;\n\
    \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n            low[u]\
    \ = ord[u] = k++;\n            bool is_articulation = false;\n            int\
    \ count = 0;\n            for (auto &&e : g[u]) {\n                if (e.id ==\
    \ ei) continue;\n                if (ord[e.to] == -1) {\n                    ++count;\n\
    \                    used_on_dfs_tree[e.id] = true;\n                    low[u]\
    \ = std::min(low[u], self(self, e.to, e.id));\n                    if (ei != -1\
    \ and ord[u] <= low[e.to]) is_articulation = true;\n                    if (ord[u]\
    \ < low[e.to]) bridges.emplace_back(e.id);\n                }\n              \
    \  // back edge\n                else if (ord[e.to] < ord[u]) {\n            \
    \        low[u] = std::min(low[u], ord[e.to]);\n                }\n          \
    \  }\n            if (ei == -1 and count >= 2) is_articulation = true;\n     \
    \       if (is_articulation) articulations.emplace_back(u);\n            return\
    \ low[u];\n        };\n        for (int u = 0; u < n; u++)\n            if (ord[u]\
    \ == -1) {\n                dfs(dfs, u);\n                root[u] = true;\n  \
    \          }\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_LOWLINK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/tree/block_cut_tree.hpp
  - graph/bcc.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2025-03-28 03:08:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1326.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
