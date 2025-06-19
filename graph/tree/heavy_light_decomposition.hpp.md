---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/auxiliary_tree.hpp
    title: graph/tree/auxiliary_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca.test.cpp
    title: verify/yosupo_graph/tree_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_1326.test.cpp
    title: verify/yuki/yuki_1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
    namespace kk2 {\n\ntemplate <typename G> struct HeavyLightDecomposition {\n  \
    \  static_assert(!G::directed, \"HeavyLightDecomposition requires undirected graph\"\
    );\n\n    G &g;\n    int root, id;\n    std::vector<int> sz, in, out, head, par,\
    \ dep, edge_idx;\n\n    // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\u3068\u3044\
    \u3051\u306A\u3044\n    HeavyLightDecomposition(G &g_, int root_ = 0)\n      \
    \  : g(g_),\n          root(root_),\n          id(0),\n          sz(g.size(),\
    \ 0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n          head(g.size(),\
    \ root),\n          par(g.size(), root),\n          dep(g.size(), 0),\n      \
    \    edge_idx(g.size() - 1, -1) {\n        init();\n    }\n\n    int get_edge_idx(int\
    \ i) const { return edge_idx[i]; }\n\n    std::pair<int, int> get_node_idx(int\
    \ u) const { return std::make_pair(in[u], out[u]); }\n\n    template <typename\
    \ F> void path_query(int u, int v, bool is_node_query, const F &f) {\n       \
    \ int l = lca(u, v);\n        for (auto &[a, b] : ascend(u, l)) {\n          \
    \  int s = a + 1, t = b;\n            s > t ? f(t, s) : f(s, t);\n        }\n\
    \        if (is_node_query) f(in[l], in[l] + 1);\n        for (auto &[a, b] :\
    \ descend(l, v)) {\n            int s = a, t = b + 1;\n            s > t ? f(t,\
    \ s) : f(s, t);\n        }\n    }\n\n    template <typename F>\n    void path_noncommutative_query(int\
    \ u, int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n  \
    \      for (auto &[a, b] : ascend(u, l)) f(a + 1, b);\n        if (is_node_query)\
    \ f(in[l], in[l] + 1);\n        for (auto &[a, b] : descend(l, v)) f(a, b + 1);\n\
    \    }\n\n    template <typename F> void subtree_query(int u, bool is_vertex_query,\
    \ const F &f) {\n        f(in[u] + (int)!is_vertex_query, out[u]);\n    }\n\n\
    \    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n   \
    \         if (in[u] < in[v]) std::swap(u, v);\n            u = par[head[u]];\n\
    \        }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int\
    \ u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n\n  private:\n\
    \    void init() {\n        auto dfs_sz = [&](auto self, int now) -> void {\n\
    \            sz[now] = 1;\n            for (auto &e : g[now]) {\n            \
    \    if ((int)e == par[now]) {\n                    if (g[now].size() >= 2 and\
    \ e == g[now][0]) std::swap(e, g[now][1]);\n                    else continue;\n\
    \                }\n                par[(int)e] = now;\n                dep[(int)e]\
    \ = dep[now] + 1;\n                self(self, (int)e);\n                sz[now]\
    \ += sz[(int)e];\n                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e,\
    \ g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz, root);\n\n  \
    \      auto dfs_hld = [&](auto self, int now) -> void {\n            in[now] =\
    \ id++;\n            for (auto &e : g[now]) {\n                if ((int)e == par[now])\
    \ continue;\n                head[(int)e] = ((int)e == (int)g[now][0] ? head[now]\
    \ : (int)e);\n                edge_idx[e.id] = id;\n                self(self,\
    \ (int)e);\n            }\n            out[now] = id;\n        };\n        dfs_hld(dfs_hld,\
    \ root);\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (head[u] != head[v]) {\n            res.emplace_back(in[u], in[head[u]]);\n\
    \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n      \
    \  auto res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]],\
    \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <typename G> struct HeavyLightDecomposition\
    \ {\n    static_assert(!G::directed, \"HeavyLightDecomposition requires undirected\
    \ graph\");\n\n    G &g;\n    int root, id;\n    std::vector<int> sz, in, out,\
    \ head, par, dep, edge_idx;\n\n    // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\
    \u3068\u3044\u3051\u306A\u3044\n    HeavyLightDecomposition(G &g_, int root_ =\
    \ 0)\n        : g(g_),\n          root(root_),\n          id(0),\n          sz(g.size(),\
    \ 0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n          head(g.size(),\
    \ root),\n          par(g.size(), root),\n          dep(g.size(), 0),\n      \
    \    edge_idx(g.size() - 1, -1) {\n        init();\n    }\n\n    int get_edge_idx(int\
    \ i) const { return edge_idx[i]; }\n\n    std::pair<int, int> get_node_idx(int\
    \ u) const { return std::make_pair(in[u], out[u]); }\n\n    template <typename\
    \ F> void path_query(int u, int v, bool is_node_query, const F &f) {\n       \
    \ int l = lca(u, v);\n        for (auto &[a, b] : ascend(u, l)) {\n          \
    \  int s = a + 1, t = b;\n            s > t ? f(t, s) : f(s, t);\n        }\n\
    \        if (is_node_query) f(in[l], in[l] + 1);\n        for (auto &[a, b] :\
    \ descend(l, v)) {\n            int s = a, t = b + 1;\n            s > t ? f(t,\
    \ s) : f(s, t);\n        }\n    }\n\n    template <typename F>\n    void path_noncommutative_query(int\
    \ u, int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n  \
    \      for (auto &[a, b] : ascend(u, l)) f(a + 1, b);\n        if (is_node_query)\
    \ f(in[l], in[l] + 1);\n        for (auto &[a, b] : descend(l, v)) f(a, b + 1);\n\
    \    }\n\n    template <typename F> void subtree_query(int u, bool is_vertex_query,\
    \ const F &f) {\n        f(in[u] + (int)!is_vertex_query, out[u]);\n    }\n\n\
    \    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n   \
    \         if (in[u] < in[v]) std::swap(u, v);\n            u = par[head[u]];\n\
    \        }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int\
    \ u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n\n  private:\n\
    \    void init() {\n        auto dfs_sz = [&](auto self, int now) -> void {\n\
    \            sz[now] = 1;\n            for (auto &e : g[now]) {\n            \
    \    if ((int)e == par[now]) {\n                    if (g[now].size() >= 2 and\
    \ e == g[now][0]) std::swap(e, g[now][1]);\n                    else continue;\n\
    \                }\n                par[(int)e] = now;\n                dep[(int)e]\
    \ = dep[now] + 1;\n                self(self, (int)e);\n                sz[now]\
    \ += sz[(int)e];\n                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e,\
    \ g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz, root);\n\n  \
    \      auto dfs_hld = [&](auto self, int now) -> void {\n            in[now] =\
    \ id++;\n            for (auto &e : g[now]) {\n                if ((int)e == par[now])\
    \ continue;\n                head[(int)e] = ((int)e == (int)g[now][0] ? head[now]\
    \ : (int)e);\n                edge_idx[e.id] = id;\n                self(self,\
    \ (int)e);\n            }\n            out[now] = id;\n        };\n        dfs_hld(dfs_hld,\
    \ root);\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (head[u] != head[v]) {\n            res.emplace_back(in[u], in[head[u]]);\n\
    \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n      \
    \  auto res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]],\
    \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/heavy_light_decomposition.hpp
  requiredBy:
  - graph/tree/auxiliary_tree.hpp
  timestamp: '2025-03-28 03:08:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: graph/tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/graph/tree/heavy_light_decomposition.hpp
- /library/graph/tree/heavy_light_decomposition.hpp.html
title: graph/tree/heavy_light_decomposition.hpp
---
