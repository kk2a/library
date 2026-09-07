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
  - files:
    - filename: graph_enumerate_triangle.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\n#define KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\
      \ 1\n\n#include <utility>\n#include <vector>\n\n#include \"../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G, graph::DirectedGraph\
      \ H, class F>\nvoid enumerate_triangle(const G &g, const F &f) {\n\n    H h(g.num_vertices());\n\
      \    for (auto &&e : g.edges) {\n        int u = e.from, v = e.to;\n       \
      \ if ((g[u].size() == g[v].size() and u > v) or g[u].size() > g[v].size()) std::swap(u,\
      \ v);\n        h.add_edge(u, v);\n    }\n    if constexpr (H::static_graph)\
      \ h.build();\n    std::vector<int> buf(g.num_vertices(), -1);\n    for (int\
      \ i = 0; i < g.num_vertices(); i++) {\n        for (auto &&e1 : h[i]) buf[e1.to]\
      \ = i;\n        for (auto &&e1 : h[i])\n            for (auto &&e2 : h[e1.to])\n\
      \                if (buf[e2.to] == i) f(i, e1.to, e2.to);\n    }\n}\n\n} //\
      \ namespace kk2\n\n#endif // KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\n"
    name: default
  - code: "#line 1 \"graph/enumerate_triangle.hpp\"\n\n\n\n#include <utility>\n#include\
      \ <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n\
      #include <ranges>\n#include <type_traits>\n#line 8 \"type_traits/graph.hpp\"\
      \n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge = requires(const\
      \ E &e) {\n    { e.from } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ G>\nconcept Graph = requires(const G &g, int v) {\n    typename G::value_type;\n\
      \    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_list } -> std::convertible_to<bool>;\n    { G::adjacency_matrix\
      \ } -> std::convertible_to<bool>;\n    { G::static_graph } -> std::convertible_to<bool>;\n\
      \    { g.num_vertices() } -> std::integral;\n    { g.num_edges() } -> std::integral;\n\
      \    g[v];\n    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph =\
      \ Graph<G> && requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 8 \"graph/enumerate_triangle.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G, graph::DirectedGraph\
      \ H, class F>\nvoid enumerate_triangle(const G &g, const F &f) {\n\n    H h(g.num_vertices());\n\
      \    for (auto &&e : g.edges) {\n        int u = e.from, v = e.to;\n       \
      \ if ((g[u].size() == g[v].size() and u > v) or g[u].size() > g[v].size()) std::swap(u,\
      \ v);\n        h.add_edge(u, v);\n    }\n    if constexpr (H::static_graph)\
      \ h.build();\n    std::vector<int> buf(g.num_vertices(), -1);\n    for (int\
      \ i = 0; i < g.num_vertices(); i++) {\n        for (auto &&e1 : h[i]) buf[e1.to]\
      \ = i;\n        for (auto &&e1 : h[i])\n            for (auto &&e2 : h[e1.to])\n\
      \                if (buf[e2.to] == i) f(i, e1.to, e2.to);\n    }\n}\n\n} //\
      \ namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/enumerate_triangle.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
documentation_of: graph/enumerate_triangle.hpp
layout: document
---
