---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: bcc.hpp
      icon: LIBRARY_ALL_AC
      path: graph/bcc.hpp
    - filename: cycle_detection.hpp
      icon: LIBRARY_ALL_AC
      path: graph/cycle_detection.hpp
    - filename: enumerate_triangle.hpp
      icon: LIBRARY_ALL_AC
      path: graph/enumerate_triangle.hpp
    - filename: induced_subgraph.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/induced_subgraph.hpp
    - filename: lowlink.hpp
      icon: LIBRARY_ALL_AC
      path: graph/lowlink.hpp
    - filename: maxflow.hpp
      icon: LIBRARY_ALL_AC
      path: graph/maxflow.hpp
    - filename: scc.hpp
      icon: LIBRARY_ALL_AC
      path: graph/scc.hpp
    - filename: bellman_ford.hpp
      icon: LIBRARY_ALL_AC
      path: graph/shortest_path/bellman_ford.hpp
    - filename: bfs.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/shortest_path/bfs.hpp
    - filename: dijkstra.hpp
      icon: LIBRARY_ALL_AC
      path: graph/shortest_path/dijkstra.hpp
    - filename: warshall_floyd.hpp
      icon: LIBRARY_ALL_AC
      path: graph/shortest_path/warshall_floyd.hpp
    - filename: topological_sort.hpp
      icon: LIBRARY_ALL_AC
      path: graph/topological_sort.hpp
    - filename: auxiliary_tree.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/tree/auxiliary_tree.hpp
    - filename: block_cut_tree.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/block_cut_tree.hpp
    - filename: centroid.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/tree/centroid.hpp
    - filename: centroid_decomposition.hpp
      icon: LIBRARY_NO_TESTS
      path: graph/tree/centroid_decomposition.hpp
    - filename: diameter.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/diameter.hpp
    - filename: euler_tour.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/euler_tour.hpp
    - filename: heavy_light_decomposition.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/heavy_light_decomposition.hpp
    - filename: minimum_spanning_tree.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/minimum_spanning_tree.hpp
    - filename: two_edge_connected_components.hpp
      icon: LIBRARY_ALL_AC
      path: graph/two_edge_connected_components.hpp
    type: Required by
  - files:
    - filename: aoj_grl_1_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_b.test.cpp
    - filename: aoj_grl_1_c.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_c.test.cpp
    - filename: maxflow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/graph/maxflow.test.cpp
    - filename: graph.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/graph/graph.test.cpp
    - filename: graph_bcc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_bcc.test.cpp
    - filename: graph_cycle_detection.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    - filename: graph_cycle_detection_directed.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    - filename: graph_enumerate_triangle.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    - filename: graph_matching_bipartite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    - filename: graph_minimum_spanning_tree.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    - filename: graph_scc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_scc.test.cpp
    - filename: graph_shortest_path.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_shortest_path.test.cpp
    - filename: graph_two_edge_connected_components.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    - filename: tree_diameter.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_diameter.test.cpp
    - filename: tree_lca.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca.test.cpp
    - filename: tree_lca_static.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca_static.test.cpp
    - filename: tree_vertex_add_path_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    - filename: tree_vertex_add_path_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
    - filename: tree_vertex_add_subtree_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
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
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_GRAPH_HPP\n#define KK2_TYPE_TRAITS_GRAPH_HPP 1\n\
      \n#include <concepts>\n#include <ranges>\n#include <type_traits>\n#include <utility>\n\
      \nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge = requires(const\
      \ E &e) {\n    { e.from } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n#endif // KK2_TYPE_TRAITS_GRAPH_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#include\
      \ <ranges>\n#include <type_traits>\n#include <utility>\n\nnamespace kk2::graph\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/graph.hpp
  pathExtension: hpp
  requiredBy:
  - graph/bcc.hpp
  - graph/cycle_detection.hpp
  - graph/enumerate_triangle.hpp
  - graph/induced_subgraph.hpp
  - graph/lowlink.hpp
  - graph/maxflow.hpp
  - graph/scc.hpp
  - graph/shortest_path/bellman_ford.hpp
  - graph/shortest_path/bfs.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/shortest_path/warshall_floyd.hpp
  - graph/topological_sort.hpp
  - graph/tree/auxiliary_tree.hpp
  - graph/tree/block_cut_tree.hpp
  - graph/tree/centroid.hpp
  - graph/tree/centroid_decomposition.hpp
  - graph/tree/diameter.hpp
  - graph/tree/euler_tour.hpp
  - graph/tree/heavy_light_decomposition.hpp
  - graph/tree/minimum_spanning_tree.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_b.test.cpp
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/unit_test/graph/maxflow.test.cpp
  - verify/unit_test/type_traits/graph/graph.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: type_traits/graph.hpp
layout: document
---
