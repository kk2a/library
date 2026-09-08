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
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_INDUCED_SUBGRAPH_HPP\n#define KK2_GRAPH_INDUCED_SUBGRAPH_HPP\
      \ 1\n\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\n#include\
      \ \"../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\ntemplate <graph::EdgeListGraph\
      \ G> G induced_subgraph(const G &g, const std::vector<int> &vs) {\n    G res(g.num_vertices());\n\
      \    using edge_collection = std::remove_cvref_t<decltype(res.edges)>;\n   \
      \ edge_collection res_edges;\n    res_edges.reserve(g.num_edges());\n\n    std::vector<bool>\
      \ used(g.num_vertices(), false);\n    for (int v : vs) used[v] = true;\n\n \
      \   for (auto e : g.edges) {\n        if (!used[e.from] or !used[e.to]) continue;\n\
      \        if constexpr (G::weighted) res_edges.add_edge(e.from, e.to, e.cost);\n\
      \        else res_edges.add_edge(e.from, e.to);\n    }\n\n    res = G(g.num_vertices(),\
      \ res_edges);\n\n    return res;\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_INDUCED_SUBGRAPH_HPP\n"
    name: default
  - code: "#line 1 \"graph/induced_subgraph.hpp\"\n\n\n\n#include <cassert>\n#include\
      \ <type_traits>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\
      \n#include <concepts>\n#include <ranges>\n#line 7 \"type_traits/graph.hpp\"\n\
      #include <utility>\n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept\
      \ Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 9 \"graph/induced_subgraph.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::EdgeListGraph G> G induced_subgraph(const\
      \ G &g, const std::vector<int> &vs) {\n    G res(g.num_vertices());\n    using\
      \ edge_collection = std::remove_cvref_t<decltype(res.edges)>;\n    edge_collection\
      \ res_edges;\n    res_edges.reserve(g.num_edges());\n\n    std::vector<bool>\
      \ used(g.num_vertices(), false);\n    for (int v : vs) used[v] = true;\n\n \
      \   for (auto e : g.edges) {\n        if (!used[e.from] or !used[e.to]) continue;\n\
      \        if constexpr (G::weighted) res_edges.add_edge(e.from, e.to, e.cost);\n\
      \        else res_edges.add_edge(e.from, e.to);\n    }\n\n    res = G(g.num_vertices(),\
      \ res_edges);\n\n    return res;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/induced_subgraph.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/induced_subgraph.hpp
layout: document
---
