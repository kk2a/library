---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    type: Depends on
  - files:
    - filename: auxiliary_tree.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/tree/auxiliary_tree.hpp
    type: Required by
  - files:
    - filename: tree_lca.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca.test.cpp
    - filename: tree_lca_static.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca_static.test.cpp
    - filename: tree_vertex_add_path_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
    - filename: tree_vertex_add_subtree_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    - filename: yuki_1326.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1326.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\
      \ 1\n\n#include <cassert>\n#include <functional>\n#include <utility>\n#include\
      \ <vector>\n\n#include \"../../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\n\
      template <graph::UndirectedGraph G> struct HeavyLightDecomposition {\n\n   \
      \ G &g;\n    int root, id;\n    std::vector<int> sz, in, out, head, par, dep,\
      \ edge_idx;\n\n    // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\u3068\u3044\
      \u3051\u306A\u3044\n    HeavyLightDecomposition(G &g_, int root_ = 0)\n    \
      \    : g(g_),\n          root(root_),\n          id(0),\n          sz(g.size(),\
      \ 0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n         \
      \ head(g.size(), root),\n          par(g.size(), root),\n          dep(g.size(),\
      \ 0),\n          edge_idx(g.size() - 1, -1) {\n        init();\n    }\n\n  \
      \  int get_edge_idx(int i) const { return edge_idx[i]; }\n\n    std::pair<int,\
      \ int> get_node_idx(int u) const { return std::make_pair(in[u], out[u]); }\n\
      \n    template <typename F> void path_query(int u, int v, bool is_node_query,\
      \ const F &f) {\n        int l = lca(u, v);\n        for (auto &[a, b] : ascend(u,\
      \ l)) {\n            int s = a + 1, t = b;\n            s > t ? f(t, s) : f(s,\
      \ t);\n        }\n        if (is_node_query) f(in[l], in[l] + 1);\n        for\
      \ (auto &[a, b] : descend(l, v)) {\n            int s = a, t = b + 1;\n    \
      \        s > t ? f(t, s) : f(s, t);\n        }\n    }\n\n    template <typename\
      \ F>\n    void path_noncommutative_query(int u, int v, bool is_node_query, const\
      \ F &f) {\n        int l = lca(u, v);\n        for (auto &[a, b] : ascend(u,\
      \ l)) f(a + 1, b);\n        if (is_node_query) f(in[l], in[l] + 1);\n      \
      \  for (auto &[a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <typename\
      \ F> void subtree_query(int u, bool is_vertex_query, const F &f) {\n       \
      \ f(in[u] + (int)!is_vertex_query, out[u]);\n    }\n\n    int lca(int u, int\
      \ v) const {\n        while (head[u] != head[v]) {\n            if (in[u] <\
      \ in[v]) std::swap(u, v);\n            u = par[head[u]];\n        }\n      \
      \  return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int u, int v) const\
      \ { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n\n  private:\n    void init()\
      \ {\n        auto dfs_sz = [&](auto self, int now) -> void {\n            sz[now]\
      \ = 1;\n            for (auto &e : g[now]) {\n                if ((int)e ==\
      \ par[now]) {\n                    if (g[now].size() >= 2 and e == g[now][0])\
      \ std::swap(e, g[now][1]);\n                    else continue;\n           \
      \     }\n                par[(int)e] = now;\n                dep[(int)e] = dep[now]\
      \ + 1;\n                self(self, (int)e);\n                sz[now] += sz[(int)e];\n\
      \                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e, g[now][0]);\n\
      \            }\n        };\n        dfs_sz(dfs_sz, root);\n\n        auto dfs_hld\
      \ = [&](auto self, int now) -> void {\n            in[now] = id++;\n       \
      \     for (auto &e : g[now]) {\n                if ((int)e == par[now]) continue;\n\
      \                head[(int)e] = ((int)e == (int)g[now][0] ? head[now] : (int)e);\n\
      \                edge_idx[e.id] = id;\n                self(self, (int)e);\n\
      \            }\n            out[now] = id;\n        };\n        dfs_hld(dfs_hld,\
      \ root);\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
      \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n       \
      \ while (head[u] != head[v]) {\n            res.emplace_back(in[u], in[head[u]]);\n\
      \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
      \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
      \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n    \
      \    if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n  \
      \      auto res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]],\
      \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n#endif //\
      \ KK2_GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#include <cassert>\n\
      #include <functional>\n#include <utility>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n#line\
      \ 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class E>\n\
      concept Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class G>\nconcept Graph = requires(const G &g,\
      \ int v) {\n    typename G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n\
      \    { G::weighted } -> std::convertible_to<bool>;\n    { G::adjacency_list\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_matrix } -> std::convertible_to<bool>;\n\
      \    { G::static_graph } -> std::convertible_to<bool>;\n    { g.num_vertices()\
      \ } -> std::integral;\n    { g.num_edges() } -> std::integral;\n    g[v];\n\
      \    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph = Graph<G> &&\
      \ requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
      \    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n};\n\ntemplate\
      \ <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const G &g, int v)\
      \ {\n    requires std::ranges::range<decltype(g[v])>;\n    requires Edge<std::ranges::range_value_t<decltype(g[v])>>;\n\
      };\n\ntemplate <class G>\nconcept WeightedGraph = AdjacencyGraph<G> && G::weighted\
      \ &&\n                        WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>()[0])>>;\n\ntemplate <class G>\nconcept WeightedEdgeListGraph = EdgeListGraph<G>\
      \ && G::weighted &&\n                                WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>().edges)>>;\n\ntemplate <class G>\nconcept UnweightedGraph = AdjacencyGraph<G>\
      \ && (!G::weighted);\n\ntemplate <class G>\nconcept DirectedGraph = AdjacencyGraph<G>\
      \ && G::directed;\n\ntemplate <class G>\nconcept UndirectedGraph = AdjacencyGraph<G>\
      \ && (!G::directed);\n\ntemplate <class G>\nconcept WeightedDirectedGraph =\
      \ WeightedGraph<G> && DirectedGraph<G>;\n\ntemplate <class G>\nconcept WeightedUndirectedGraph\
      \ = WeightedGraph<G> && UndirectedGraph<G>;\n\ntemplate <class G>\nconcept WeightedDirectedEdgeListGraph\
      \ = WeightedEdgeListGraph<G> && G::directed;\n\ntemplate <class G>\nconcept\
      \ WeightedUndirectedEdgeListGraph = WeightedEdgeListGraph<G> && (!G::directed);\n\
      \ntemplate <class G>\nconcept StaticGraph = Graph<G> && G::static_graph;\n\n\
      // Adjacency over vertices, also usable with vector<vector<int>>.\ntemplate\
      \ <class G>\nconcept VertexAdjacency = requires(const G &g, int v) {\n    {\
      \ g.size() } -> std::integral;\n    requires std::ranges::range<decltype(g[v])>;\n\
      \    requires std::convertible_to<std::ranges::range_value_t<decltype(g[v])>,\
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 10 \"graph/tree/heavy_light_decomposition.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct HeavyLightDecomposition\
      \ {\n\n    G &g;\n    int root, id;\n    std::vector<int> sz, in, out, head,\
      \ par, dep, edge_idx;\n\n    // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\
      \u3068\u3044\u3051\u306A\u3044\n    HeavyLightDecomposition(G &g_, int root_\
      \ = 0)\n        : g(g_),\n          root(root_),\n          id(0),\n       \
      \   sz(g.size(), 0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n\
      \          head(g.size(), root),\n          par(g.size(), root),\n         \
      \ dep(g.size(), 0),\n          edge_idx(g.size() - 1, -1) {\n        init();\n\
      \    }\n\n    int get_edge_idx(int i) const { return edge_idx[i]; }\n\n    std::pair<int,\
      \ int> get_node_idx(int u) const { return std::make_pair(in[u], out[u]); }\n\
      \n    template <typename F> void path_query(int u, int v, bool is_node_query,\
      \ const F &f) {\n        int l = lca(u, v);\n        for (auto &[a, b] : ascend(u,\
      \ l)) {\n            int s = a + 1, t = b;\n            s > t ? f(t, s) : f(s,\
      \ t);\n        }\n        if (is_node_query) f(in[l], in[l] + 1);\n        for\
      \ (auto &[a, b] : descend(l, v)) {\n            int s = a, t = b + 1;\n    \
      \        s > t ? f(t, s) : f(s, t);\n        }\n    }\n\n    template <typename\
      \ F>\n    void path_noncommutative_query(int u, int v, bool is_node_query, const\
      \ F &f) {\n        int l = lca(u, v);\n        for (auto &[a, b] : ascend(u,\
      \ l)) f(a + 1, b);\n        if (is_node_query) f(in[l], in[l] + 1);\n      \
      \  for (auto &[a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <typename\
      \ F> void subtree_query(int u, bool is_vertex_query, const F &f) {\n       \
      \ f(in[u] + (int)!is_vertex_query, out[u]);\n    }\n\n    int lca(int u, int\
      \ v) const {\n        while (head[u] != head[v]) {\n            if (in[u] <\
      \ in[v]) std::swap(u, v);\n            u = par[head[u]];\n        }\n      \
      \  return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int u, int v) const\
      \ { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n\n  private:\n    void init()\
      \ {\n        auto dfs_sz = [&](auto self, int now) -> void {\n            sz[now]\
      \ = 1;\n            for (auto &e : g[now]) {\n                if ((int)e ==\
      \ par[now]) {\n                    if (g[now].size() >= 2 and e == g[now][0])\
      \ std::swap(e, g[now][1]);\n                    else continue;\n           \
      \     }\n                par[(int)e] = now;\n                dep[(int)e] = dep[now]\
      \ + 1;\n                self(self, (int)e);\n                sz[now] += sz[(int)e];\n\
      \                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e, g[now][0]);\n\
      \            }\n        };\n        dfs_sz(dfs_sz, root);\n\n        auto dfs_hld\
      \ = [&](auto self, int now) -> void {\n            in[now] = id++;\n       \
      \     for (auto &e : g[now]) {\n                if ((int)e == par[now]) continue;\n\
      \                head[(int)e] = ((int)e == (int)g[now][0] ? head[now] : (int)e);\n\
      \                edge_idx[e.id] = id;\n                self(self, (int)e);\n\
      \            }\n            out[now] = id;\n        };\n        dfs_hld(dfs_hld,\
      \ root);\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
      \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n       \
      \ while (head[u] != head[v]) {\n            res.emplace_back(in[u], in[head[u]]);\n\
      \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
      \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
      \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n    \
      \    if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n  \
      \      auto res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]],\
      \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/heavy_light_decomposition.hpp
  pathExtension: hpp
  requiredBy:
  - graph/tree/auxiliary_tree.hpp
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: graph/tree/heavy_light_decomposition.hpp
layout: document
---
