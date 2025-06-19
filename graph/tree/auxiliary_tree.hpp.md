---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/auxiliary_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\
    \n#line 8 \"graph/tree/heavy_light_decomposition.hpp\"\n\nnamespace kk2 {\n\n\
    template <typename G> struct HeavyLightDecomposition {\n    static_assert(!G::directed,\
    \ \"HeavyLightDecomposition requires undirected graph\");\n\n    G &g;\n    int\
    \ root, id;\n    std::vector<int> sz, in, out, head, par, dep, edge_idx;\n\n \
    \   // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\
    \n    HeavyLightDecomposition(G &g_, int root_ = 0)\n        : g(g_),\n      \
    \    root(root_),\n          id(0),\n          sz(g.size(), 0),\n          in(g.size(),\
    \ -1),\n          out(g.size(), -1),\n          head(g.size(), root),\n      \
    \    par(g.size(), root),\n          dep(g.size(), 0),\n          edge_idx(g.size()\
    \ - 1, -1) {\n        init();\n    }\n\n    int get_edge_idx(int i) const { return\
    \ edge_idx[i]; }\n\n    std::pair<int, int> get_node_idx(int u) const { return\
    \ std::make_pair(in[u], out[u]); }\n\n    template <typename F> void path_query(int\
    \ u, int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n  \
    \      for (auto &[a, b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n\
    \            s > t ? f(t, s) : f(s, t);\n        }\n        if (is_node_query)\
    \ f(in[l], in[l] + 1);\n        for (auto &[a, b] : descend(l, v)) {\n       \
    \     int s = a, t = b + 1;\n            s > t ? f(t, s) : f(s, t);\n        }\n\
    \    }\n\n    template <typename F>\n    void path_noncommutative_query(int u,\
    \ int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n     \
    \   for (auto &[a, b] : ascend(u, l)) f(a + 1, b);\n        if (is_node_query)\
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
    \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 12\
    \ \"graph/tree/auxiliary_tree.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename G>\
    \ struct AuxiliaryTree {\n    static_assert(!G::directed, \"AuxiliaryTree requires\
    \ undirected graph\");\n\n    G g;\n    HeavyLightDecomposition<G> hld;\n\n  \
    \  AuxiliaryTree(const G &g_, int root_ = 0) : g(g_), hld(g, root_) {}\n\n   \
    \ std::pair<std::vector<std::vector<int>>, std::vector<int>> get(std::vector<int>\
    \ ps) {\n        if (ps.empty()) return {};\n        std::sort(\n            std::begin(ps),\
    \ std::end(ps), [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n      \
    \  for (int i = 0, ps_size = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
    \ ps[i + 1]));\n        }\n        std::sort(\n            std::begin(ps), std::end(ps),\
    \ [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n        ps.erase(std::unique(std::begin(ps),\
    \ std::end(ps)), std::end(ps));\n\n        std::vector<std::vector<int>> aux(ps.size());\n\
    \        std::stack<int> st;\n        st.emplace(0);\n        for (int i = 1;\
    \ i < (int)ps.size(); i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n\
    \            while (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
    \            st.emplace(i);\n        }\n        return std::make_pair(aux, ps);\n\
    \    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\n#define KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n\n#include \"heavy_light_decomposition.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename G> struct AuxiliaryTree {\n    static_assert(!G::directed,\
    \ \"AuxiliaryTree requires undirected graph\");\n\n    G g;\n    HeavyLightDecomposition<G>\
    \ hld;\n\n    AuxiliaryTree(const G &g_, int root_ = 0) : g(g_), hld(g, root_)\
    \ {}\n\n    std::pair<std::vector<std::vector<int>>, std::vector<int>> get(std::vector<int>\
    \ ps) {\n        if (ps.empty()) return {};\n        std::sort(\n            std::begin(ps),\
    \ std::end(ps), [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n      \
    \  for (int i = 0, ps_size = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
    \ ps[i + 1]));\n        }\n        std::sort(\n            std::begin(ps), std::end(ps),\
    \ [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n        ps.erase(std::unique(std::begin(ps),\
    \ std::end(ps)), std::end(ps));\n\n        std::vector<std::vector<int>> aux(ps.size());\n\
    \        std::stack<int> st;\n        st.emplace(0);\n        for (int i = 1;\
    \ i < (int)ps.size(); i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n\
    \            while (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
    \            st.emplace(i);\n        }\n        return std::make_pair(aux, ps);\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\n"
  dependsOn:
  - graph/tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: graph/tree/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/auxiliary_tree.hpp
layout: document
redirect_from:
- /library/graph/tree/auxiliary_tree.hpp
- /library/graph/tree/auxiliary_tree.hpp.html
title: graph/tree/auxiliary_tree.hpp
---
