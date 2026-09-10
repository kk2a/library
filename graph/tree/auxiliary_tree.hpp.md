---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: heavy_light_decomposition.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/heavy_light_decomposition.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - graph/tree/heavy_light_decomposition.hpp
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\n#define KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
      \ <stack>\n#include <utility>\n#include <vector>\n\n#include \"heavy_light_decomposition.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct AuxiliaryTree\
      \ {\n\n    G g;\n    HeavyLightDecomposition<G> hld;\n\n    AuxiliaryTree(const\
      \ G &g_, int root_ = 0) : g(g_), hld(g, root_) {}\n\n    std::pair<std::vector<std::vector<int>>,\
      \ std::vector<int>> get(std::vector<int> ps) {\n        if (ps.empty()) return\
      \ {};\n        std::sort(\n            std::begin(ps), std::end(ps), [&](int\
      \ i, int j) { return hld.in[i] < hld.in[j]; });\n        for (int i = 0, ps_size\
      \ = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
      \ ps[i + 1]));\n        }\n        std::sort(\n            std::begin(ps), std::end(ps),\
      \ [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n        ps.erase(std::unique(std::begin(ps),\
      \ std::end(ps)), std::end(ps));\n\n        std::vector<std::vector<int>> aux(ps.size());\n\
      \        std::stack<int> st;\n        st.emplace(0);\n        for (int i = 1;\
      \ i < (int)ps.size(); i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n\
      \            while (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
      \            st.emplace(i);\n        }\n        return std::make_pair(aux, ps);\n\
      \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_AUXILIARY_TREE_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/auxiliary_tree.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <functional>\n#include <stack>\n#include <utility>\n\
      #include <vector>\n\n#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\
      \n\n#line 8 \"graph/tree/heavy_light_decomposition.hpp\"\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n#line\
      \ 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class E>\n\
      concept Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class R>\nconcept EdgeRange = std::ranges::input_range<R>\
      \ && Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept WeightedEdgeRange\
      \ = EdgeRange<R> && WeightedEdge<std::ranges::range_value_t<R>>;\n\ntemplate\
      \ <class R>\nconcept ForwardWeightedEdgeRange = std::ranges::forward_range<R>\
      \ && WeightedEdgeRange<R>;\n\ntemplate <class G>\nconcept Graph = requires(const\
      \ G &g, int v) {\n    typename G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n\
      \    { G::weighted } -> std::convertible_to<bool>;\n    { G::adjacency_list\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_matrix } -> std::convertible_to<bool>;\n\
      \    { G::static_graph } -> std::convertible_to<bool>;\n    { g.num_vertices()\
      \ } -> std::integral;\n    { g.num_edges() } -> std::integral;\n    g[v];\n\
      \    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph = Graph<G> &&\
      \ requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
      \    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n};\n\ntemplate\
      \ <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const G &g, int v)\
      \ {\n    requires std::ranges::range<decltype(g[v])>;\n    requires Edge<std::ranges::range_value_t<decltype(g[v])>>;\n\
      };\n\ntemplate <class G>\nconcept WeightedGraph =\n    AdjacencyGraph<G> &&\
      \ G::weighted\n    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>()[0])>>;\n\ntemplate <class G>\nconcept WeightedEdgeListGraph =\n   \
      \ EdgeListGraph<G> && G::weighted\n    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
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
      \ {\n        auto swap_edges = [&](int v, int i, int j) {\n            if constexpr\
      \ (requires { g.swap_edges(v, i, j); }) g.swap_edges(v, i, j);\n           \
      \ else std::swap(g[v][i], g[v][j]);\n        };\n        auto dfs_sz = [&](auto\
      \ self, int now) -> void {\n            sz[now] = 1;\n            for (int i\
      \ = 0; i < (int)g[now].size(); ++i) {\n                if (g[now][i].to == par[now])\
      \ {\n                    if (g[now].size() >= 2 and g[now][i].id == g[now][0].id)\
      \ {\n                        swap_edges(now, i, 1);\n                    } else\
      \ {\n                        continue;\n                    }\n            \
      \    }\n                const int child = g[now][i].to;\n                par[child]\
      \ = now;\n                dep[child] = dep[now] + 1;\n                self(self,\
      \ child);\n                sz[now] += sz[child];\n                if (sz[child]\
      \ > sz[g[now][0].to]) swap_edges(now, i, 0);\n            }\n        };\n  \
      \      dfs_sz(dfs_sz, root);\n\n        auto dfs_hld = [&](auto self, int now)\
      \ -> void {\n            in[now] = id++;\n            for (auto e : g[now])\
      \ {\n                if ((int)e == par[now]) continue;\n                head[(int)e]\
      \ = ((int)e == (int)g[now][0] ? head[now] : (int)e);\n                edge_idx[e.id]\
      \ = id;\n                self(self, (int)e);\n            }\n            out[now]\
      \ = id;\n        };\n        dfs_hld(dfs_hld, root);\n    }\n\n    // [u, v)\n\
      \    std::vector<std::pair<int, int>> ascend(int u, int v) const {\n       \
      \ std::vector<std::pair<int, int>> res;\n        while (head[u] != head[v])\
      \ {\n            res.emplace_back(in[u], in[head[u]]);\n            u = par[head[u]];\n\
      \        }\n        if (u != v) res.emplace_back(in[u], in[v] + 1);\n      \
      \  return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int, int>>\
      \ descend(int u, int v) const {\n        if (u == v) return {};\n        if\
      \ (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n        auto\
      \ res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]], in[v]);\n\
      \        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 12 \"graph/tree/auxiliary_tree.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct AuxiliaryTree\
      \ {\n\n    G g;\n    HeavyLightDecomposition<G> hld;\n\n    AuxiliaryTree(const\
      \ G &g_, int root_ = 0) : g(g_), hld(g, root_) {}\n\n    std::pair<std::vector<std::vector<int>>,\
      \ std::vector<int>> get(std::vector<int> ps) {\n        if (ps.empty()) return\
      \ {};\n        std::sort(\n            std::begin(ps), std::end(ps), [&](int\
      \ i, int j) { return hld.in[i] < hld.in[j]; });\n        for (int i = 0, ps_size\
      \ = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
      \ ps[i + 1]));\n        }\n        std::sort(\n            std::begin(ps), std::end(ps),\
      \ [&](int i, int j) { return hld.in[i] < hld.in[j]; });\n        ps.erase(std::unique(std::begin(ps),\
      \ std::end(ps)), std::end(ps));\n\n        std::vector<std::vector<int>> aux(ps.size());\n\
      \        std::stack<int> st;\n        st.emplace(0);\n        for (int i = 1;\
      \ i < (int)ps.size(); i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n\
      \            while (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
      \            st.emplace(i);\n        }\n        return std::make_pair(aux, ps);\n\
      \    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/auxiliary_tree.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/auxiliary_tree.hpp
layout: document
---
