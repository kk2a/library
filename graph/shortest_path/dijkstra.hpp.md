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
    - filename: graph_shortest_path.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_shortest_path.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\n#define KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\
      \ 1\n\n#include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\
      \n#include \"../../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace shortest_path_impl\
      \ {\n\nstruct dij_edge {\n    int to, id;\n};\n\ntemplate <class T> struct dij_result\
      \ {\n    std::vector<T> dist;\n    std::vector<dij_edge> prev;\n};\n\ntemplate\
      \ <graph::WeightedGraph WG, class T = typename WG::value_type>\ndij_result<T>\
      \ dijkstra(const WG &g, int start, T inf = std::numeric_limits<T>::max()) {\n\
      \    T alt;\n    int n = g.size();\n    std::vector<T> dist(n, inf);\n    std::vector<dij_edge>\
      \ prev(n, {-1, -1});\n\n    std::priority_queue<std::pair<T, int>,\n       \
      \                 std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
      \ int>>>\n        pq;\n    dist[start] = 0;\n    pq.push({T(), start});\n\n\
      \    while (!pq.empty()) {\n        auto q = pq.top();\n        pq.pop();\n\
      \        if (dist[q.second] < q.first) continue;\n        for (auto dij_edge\
      \ : g[q.second]) {\n            alt = q.first + dij_edge.cost;\n           \
      \ if (alt < dist[dij_edge.to]) {\n                pq.push({alt, dij_edge.to});\n\
      \                dist[dij_edge.to] = alt;\n                prev[dij_edge.to]\
      \ = {dij_edge.from, dij_edge.id};\n            }\n        }\n    }\n\n    return\
      \ {dist, prev};\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::dijkstra;\n\
      \n} // namespace kk2\n\n#endif // KK2_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP\n"
    name: default
  - code: "#line 1 \"graph/shortest_path/dijkstra.hpp\"\n\n\n\n#include <limits>\n\
      #include <queue>\n#include <utility>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n#line\
      \ 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class E>\n\
      concept Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class R>\nconcept EdgeRange = std::ranges::input_range<R>\
      \ &&\n                    Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class\
      \ R>\nconcept WeightedEdgeRange = EdgeRange<R> &&\n                        \
      \    WeightedEdge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept\
      \ ForwardWeightedEdgeRange = std::ranges::forward_range<R> && WeightedEdgeRange<R>;\n\
      \ntemplate <class G>\nconcept Graph = requires(const G &g, int v) {\n    typename\
      \ G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_list } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_matrix } -> std::convertible_to<bool>;\n    { G::static_graph\
      \ } -> std::convertible_to<bool>;\n    { g.num_vertices() } -> std::integral;\n\
      \    { g.num_edges() } -> std::integral;\n    g[v];\n    g.edges;\n};\n\ntemplate\
      \ <class G>\nconcept EdgeListGraph = Graph<G> && requires(const G &g) {\n  \
      \  requires std::ranges::range<decltype(g.edges)>;\n    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n\
      };\n\ntemplate <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const\
      \ G &g, int v) {\n    requires std::ranges::range<decltype(g[v])>;\n    requires\
      \ Edge<std::ranges::range_value_t<decltype(g[v])>>;\n};\n\ntemplate <class G>\n\
      concept WeightedGraph = AdjacencyGraph<G> && G::weighted &&\n              \
      \          WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 10 \"graph/shortest_path/dijkstra.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\nstruct dij_edge {\n\
      \    int to, id;\n};\n\ntemplate <class T> struct dij_result {\n    std::vector<T>\
      \ dist;\n    std::vector<dij_edge> prev;\n};\n\ntemplate <graph::WeightedGraph\
      \ WG, class T = typename WG::value_type>\ndij_result<T> dijkstra(const WG &g,\
      \ int start, T inf = std::numeric_limits<T>::max()) {\n    T alt;\n    int n\
      \ = g.size();\n    std::vector<T> dist(n, inf);\n    std::vector<dij_edge> prev(n,\
      \ {-1, -1});\n\n    std::priority_queue<std::pair<T, int>,\n               \
      \         std::vector<std::pair<T, int>>,\n                        std::greater<std::pair<T,\
      \ int>>>\n        pq;\n    dist[start] = 0;\n    pq.push({T(), start});\n\n\
      \    while (!pq.empty()) {\n        auto q = pq.top();\n        pq.pop();\n\
      \        if (dist[q.second] < q.first) continue;\n        for (auto dij_edge\
      \ : g[q.second]) {\n            alt = q.first + dij_edge.cost;\n           \
      \ if (alt < dist[dij_edge.to]) {\n                pq.push({alt, dij_edge.to});\n\
      \                dist[dij_edge.to] = alt;\n                prev[dij_edge.to]\
      \ = {dij_edge.from, dij_edge.id};\n            }\n        }\n    }\n\n    return\
      \ {dist, prev};\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::dijkstra;\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/shortest_path/dijkstra.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/shortest_path/dijkstra.hpp
layout: document
---
