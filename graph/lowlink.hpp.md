---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bcc.hpp
    title: graph/bcc.hpp
  - icon: ':x:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct\
    \ LowLink {\n    int n, m;\n    const G &g;\n    std::vector<int> ord, low;\n\
    \    std::vector<bool> root, used;\n\n    LowLink(const G &g_)\n        : n(g_.num_vertices()),\n\
    \          m(g_.num_edges()),\n          g(g_),\n          ord(n, -1),\n     \
    \     low(n, -1),\n          root(n, false),\n          used(m, false) {\n   \
    \     init();\n    }\n\n    std::vector<typename G::edge_type> get_bridges() {\n\
    \        std::vector<bool> used(n);\n        std::vector<typename G::edge_type>\
    \ res;\n        auto dfs = [&](auto self, int now) -> void {\n            used[now]\
    \ = true;\n            for (auto &&e : g[now]) {\n                if (used[e.to])\
    \ continue;\n                if (ord[now] < low[e.to]) res.emplace_back(e);\n\
    \                self(self, e.to);\n            }\n        };\n        for (int\
    \ i = 0; i < n; i++) {\n            if (root[i]) dfs(dfs, i);\n        }\n   \
    \     return res;\n    }\n\n  private:\n    void init() {\n        int k = 0;\n\
    \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n            low[u]\
    \ = ord[u] = k++;\n            for (auto &e : g[u]) {\n                if (e.id\
    \ == ei) continue;\n                if (ord[e.to] == -1) {\n                 \
    \   used[e.id] = true;\n                    low[u] = std::min(low[u], self(self,\
    \ e.to, e.id));\n                }\n                // back edge\n           \
    \     else if (ord[e.to] < ord[u]) {\n                    low[u] = std::min(low[u],\
    \ ord[e.to]);\n                }\n            }\n            return low[u];\n\
    \        };\n        for (int u = 0; u < n; u++)\n            if (ord[u] == -1)\
    \ {\n                dfs(dfs, u);\n                root[u] = true;\n         \
    \   }\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_LOWLINK_HPP\n#define GRAPH_LOWLINK_HPP 1\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G> struct LowLink {\n    int n, m;\n    const G &g;\n    std::vector<int> ord,\
    \ low;\n    std::vector<bool> root, used;\n\n    LowLink(const G &g_)\n      \
    \  : n(g_.num_vertices()),\n          m(g_.num_edges()),\n          g(g_),\n \
    \         ord(n, -1),\n          low(n, -1),\n          root(n, false),\n    \
    \      used(m, false) {\n        init();\n    }\n\n    std::vector<typename G::edge_type>\
    \ get_bridges() {\n        std::vector<bool> used(n);\n        std::vector<typename\
    \ G::edge_type> res;\n        auto dfs = [&](auto self, int now) -> void {\n \
    \           used[now] = true;\n            for (auto &&e : g[now]) {\n       \
    \         if (used[e.to]) continue;\n                if (ord[now] < low[e.to])\
    \ res.emplace_back(e);\n                self(self, e.to);\n            }\n   \
    \     };\n        for (int i = 0; i < n; i++) {\n            if (root[i]) dfs(dfs,\
    \ i);\n        }\n        return res;\n    }\n\n  private:\n    void init() {\n\
    \        int k = 0;\n        auto dfs = [&](auto self, int u, int ei = -1) ->\
    \ int {\n            low[u] = ord[u] = k++;\n            for (auto &e : g[u])\
    \ {\n                if (e.id == ei) continue;\n                if (ord[e.to]\
    \ == -1) {\n                    used[e.id] = true;\n                    low[u]\
    \ = std::min(low[u], self(self, e.to, e.id));\n                }\n           \
    \     // back edge\n                else if (ord[e.to] < ord[u]) {\n         \
    \           low[u] = std::min(low[u], ord[e.to]);\n                }\n       \
    \     }\n            return low[u];\n        };\n        for (int u = 0; u < n;\
    \ u++)\n            if (ord[u] == -1) {\n                dfs(dfs, u);\n      \
    \          root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\
    #endif // GRAPH_LOWLINK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/bcc.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-10-22 04:14:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
