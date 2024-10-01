---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/two_edge_connected_components.hpp\"\n\n\n\n#include\
    \ <vector>\n\n#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <functional>\n#line 7 \"graph/lowlink.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ G> struct LowLink {\n    int n, m;\n    const G &g;\n    std::vector<int> ord,\
    \ low;\n    std::vector<bool> root, used;\n\n    LowLink(const G &g_)\n      \
    \  : n(g_.n),\n          m(g_.m),\n          g(g_),\n          ord(n, -1),\n \
    \         low(n, -1),\n          root(n, false),\n          used(m, false) {\n\
    \        init();\n    }\n\n  private:\n    void init() {\n        int k = 0;\n\
    \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n            low[u]\
    \ = ord[u] = k++;\n            for (auto &e : g[u]) {\n                if (e.id\
    \ == ei) continue;\n                if (ord[e.to] == -1) {\n                 \
    \   used[e.id] = true;\n                    low[u] = std::min(low[u], self(self,\
    \ e.to, e.id));\n                }\n                // back edge\n           \
    \     else if (ord[e.to] < ord[u]) {\n                    low[u] = std::min(low[u],\
    \ ord[e.to]);\n                }\n            }\n            return low[u];\n\
    \        };\n        for (int u = 0; u < n; u++)\n            if (ord[u] == -1)\
    \ {\n                dfs(dfs, u);\n                root[u] = true;\n         \
    \   }\n    }\n};\n\n} // namespace kk2\n\n\n#line 7 \"graph/two_edge_connected_components.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class G> struct TwoEdgeConnectedComponents :\
    \ LowLink<G> {\n    TwoEdgeConnectedComponents(const G &g_) : LowLink<G>(g_) {\
    \ init_tecc(); }\n\n    std::vector<int> comp;\n    std::vector<std::vector<int>>\
    \ group;\n    G forest;\n\n  private:\n    // v is a child of u in DFS tree\n\
    \    // edge(u, v) is a bridge <=> ord[u] < low[v]\n    void init_tecc() {\n \
    \       comp.resize(this->n, -1);\n        int k = 0;\n        std::vector<typename\
    \ G::edge_type> bridges;\n        auto dfs = [&](auto self, int now, int par,\
    \ int ei) -> void {\n            if (par != -1 && this->ord[par] >= this->low[now])\
    \ comp[now] = comp[par];\n            else {\n                comp[now] = k++;\n\
    \                if (par != -1) bridges.emplace_back((this->g).edges[ei]);\n \
    \           }\n            for (auto &&e : this->g[now]) {\n                if\
    \ (comp[e.to] == -1) self(self, e.to, now, e.id);\n            }\n        };\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (this->root[i]) dfs(dfs,\
    \ i, -1, -1);\n        }\n        group.resize(k);\n        for (int i = 0; i\
    \ < this->n; i++) { group[comp[i]].emplace_back(i); }\n        for (auto &&e :\
    \ bridges) {\n            e.from = comp[e.from];\n            e.to = comp[e.to];\n\
    \        }\n        forest = G(k, bridges, this->g.oneindexed);\n    }\n};\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n#define GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\
    \ 1\n\n#include <vector>\n\n#include \"lowlink.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> struct TwoEdgeConnectedComponents : LowLink<G> {\n    TwoEdgeConnectedComponents(const\
    \ G &g_) : LowLink<G>(g_) { init_tecc(); }\n\n    std::vector<int> comp;\n   \
    \ std::vector<std::vector<int>> group;\n    G forest;\n\n  private:\n    // v\
    \ is a child of u in DFS tree\n    // edge(u, v) is a bridge <=> ord[u] < low[v]\n\
    \    void init_tecc() {\n        comp.resize(this->n, -1);\n        int k = 0;\n\
    \        std::vector<typename G::edge_type> bridges;\n        auto dfs = [&](auto\
    \ self, int now, int par, int ei) -> void {\n            if (par != -1 && this->ord[par]\
    \ >= this->low[now]) comp[now] = comp[par];\n            else {\n            \
    \    comp[now] = k++;\n                if (par != -1) bridges.emplace_back((this->g).edges[ei]);\n\
    \            }\n            for (auto &&e : this->g[now]) {\n                if\
    \ (comp[e.to] == -1) self(self, e.to, now, e.id);\n            }\n        };\n\
    \        for (int i = 0; i < this->n; i++) {\n            if (this->root[i]) dfs(dfs,\
    \ i, -1, -1);\n        }\n        group.resize(k);\n        for (int i = 0; i\
    \ < this->n; i++) { group[comp[i]].emplace_back(i); }\n        for (auto &&e :\
    \ bridges) {\n            e.from = comp[e.from];\n            e.to = comp[e.to];\n\
    \        }\n        forest = G(k, bridges, this->g.oneindexed);\n    }\n};\n\n\
    } // namespace kk2\n\n#endif // GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/two_edge_connected_components.hpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.hpp
- /library/graph/two_edge_connected_components.hpp.html
title: graph/two_edge_connected_components.hpp
---