---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: lowlink.hpp
      icon: LIBRARY_ALL_AC
      path: graph/lowlink.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: graph_two_edge_connected_components.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    type: Verified with
  dependsOn:
  - graph/lowlink.hpp
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n#define KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\
      \ 1\n\n#include <vector>\n\n#include \"lowlink.hpp\"\n\nnamespace kk2 {\n\n\
      template <graph::UndirectedGraph G> struct TwoEdgeConnectedComponents : LowLink<G>\
      \ {\n    TwoEdgeConnectedComponents(const G &g_) : LowLink<G>(g_) { init_tecc();\
      \ }\n\n    std::vector<int> comp;\n    std::vector<std::vector<int>> group;\n\
      \    G forest;\n\n    int size() const { return group.size(); }\n\n  private:\n\
      \    void init_tecc() {\n        comp.resize(this->n, -1);\n        int k =\
      \ 0;\n        auto dfs = [&](auto self, int now, int par) -> void {\n      \
      \      if (par != -1 && this->ord[par] >= this->low[now]) comp[now] = comp[par];\n\
      \            else comp[now] = k++;\n\n            for (auto &&e : this->g[now])\n\
      \                if (comp[e.to] == -1) self(self, e.to, now);\n        };\n\
      \        for (int i = 0; i < this->n; i++)\n            if (this->root[i]) dfs(dfs,\
      \ i, -1);\n\n        group.resize(k);\n        for (int i = 0; i < this->n;\
      \ i++) { group[comp[i]].emplace_back(i); }\n\n        typename G::edge_collection\
      \ tmp(this->bridges.size());\n        for (int i = 0; i < (int)this->bridges.size();\
      \ i++) {\n            tmp[i] = this->g.edges[this->bridges[i]];\n          \
      \  tmp[i].from = comp[tmp[i].from];\n            tmp[i].to = comp[tmp[i].to];\n\
      \            tmp[i].id = i;\n        }\n        forest = G(k, tmp);\n    }\n\
      };\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TWO_EDGE_CONNECTED_COMPONENTS_HPP\n"
    name: default
  - code: "#line 1 \"graph/two_edge_connected_components.hpp\"\n\n\n\n#include <vector>\n\
      \n#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <functional>\n#include <type_traits>\n#line 9 \"graph/lowlink.hpp\"\
      \n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#include <ranges>\n\
      #line 7 \"type_traits/graph.hpp\"\n#include <utility>\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E>\nconcept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ R>\nconcept EdgeRange = std::ranges::input_range<R> && Edge<std::ranges::range_value_t<R>>;\n\
      \ntemplate <class R>\nconcept WeightedEdgeRange = EdgeRange<R> && WeightedEdge<std::ranges::range_value_t<R>>;\n\
      \ntemplate <class R>\nconcept ForwardWeightedEdgeRange = std::ranges::forward_range<R>\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 11 \"graph/lowlink.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct LowLink {\n\
      \n    int n, m;\n    const G &g;\n    std::vector<int> ord, low;\n    std::vector<bool>\
      \ root, used_on_dfs_tree;\n    std::vector<int> bridges, articulations;\n\n\
      \    LowLink(const G &g_)\n        : n(g_.num_vertices()),\n          m(g_.num_edges()),\n\
      \          g(g_),\n          ord(n, -1),\n          low(n, -1),\n          root(n,\
      \ false),\n          used_on_dfs_tree(m, false) {\n        init();\n    }\n\n\
      \  private:\n    // v is a child of u in DFS tree\n    // edge(u, v) is a bridge\
      \ <=> ord[u] < low[v]\n\n    // u is an articulation point <=> (u is root and\
      \ u has two or more children) or\n    // there exists a v which is a child of\
      \ u in DFS tree and ord[u] <= low[v]\n\n    void init() {\n        int k = 0;\n\
      \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n          \
      \  low[u] = ord[u] = k++;\n            bool is_articulation = false;\n     \
      \       int count = 0;\n            for (auto &&e : g[u]) {\n              \
      \  if (e.id == ei) continue;\n                if (ord[e.to] == -1) {\n     \
      \               ++count;\n                    used_on_dfs_tree[e.id] = true;\n\
      \                    low[u] = std::min(low[u], self(self, e.to, e.id));\n  \
      \                  if (ei != -1 and ord[u] <= low[e.to]) is_articulation = true;\n\
      \                    if (ord[u] < low[e.to]) bridges.emplace_back(e.id);\n \
      \               }\n                // back edge\n                else if (ord[e.to]\
      \ < ord[u]) {\n                    low[u] = std::min(low[u], ord[e.to]);\n \
      \               }\n            }\n            if (ei == -1 and count >= 2) is_articulation\
      \ = true;\n            if (is_articulation) articulations.emplace_back(u);\n\
      \            return low[u];\n        };\n        for (int u = 0; u < n; u++)\n\
      \            if (ord[u] == -1) {\n                dfs(dfs, u);\n           \
      \     root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\n\
      #line 7 \"graph/two_edge_connected_components.hpp\"\n\nnamespace kk2 {\n\ntemplate\
      \ <graph::UndirectedGraph G> struct TwoEdgeConnectedComponents : LowLink<G>\
      \ {\n    TwoEdgeConnectedComponents(const G &g_) : LowLink<G>(g_) { init_tecc();\
      \ }\n\n    std::vector<int> comp;\n    std::vector<std::vector<int>> group;\n\
      \    G forest;\n\n    int size() const { return group.size(); }\n\n  private:\n\
      \    void init_tecc() {\n        comp.resize(this->n, -1);\n        int k =\
      \ 0;\n        auto dfs = [&](auto self, int now, int par) -> void {\n      \
      \      if (par != -1 && this->ord[par] >= this->low[now]) comp[now] = comp[par];\n\
      \            else comp[now] = k++;\n\n            for (auto &&e : this->g[now])\n\
      \                if (comp[e.to] == -1) self(self, e.to, now);\n        };\n\
      \        for (int i = 0; i < this->n; i++)\n            if (this->root[i]) dfs(dfs,\
      \ i, -1);\n\n        group.resize(k);\n        for (int i = 0; i < this->n;\
      \ i++) { group[comp[i]].emplace_back(i); }\n\n        typename G::edge_collection\
      \ tmp(this->bridges.size());\n        for (int i = 0; i < (int)this->bridges.size();\
      \ i++) {\n            tmp[i] = this->g.edges[this->bridges[i]];\n          \
      \  tmp[i].from = comp[tmp[i].from];\n            tmp[i].to = comp[tmp[i].to];\n\
      \            tmp[i].id = i;\n        }\n        forest = G(k, tmp);\n    }\n\
      };\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
---
