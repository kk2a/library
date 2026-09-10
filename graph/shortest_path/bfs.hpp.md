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
  - code: "#ifndef KK2_GRAPH_SHORTEST_PATH_BFS_HPP\n#define KK2_GRAPH_SHORTEST_PATH_BFS_HPP\
      \ 1\n\n#include <queue>\n#include <vector>\n\n#include \"../../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UnweightedGraph G>\nvoid bfs(const G\
      \ &g, std::queue<int> &q, std::vector<int> &dist, int init) {\n    while (!q.empty())\
      \ {\n        int now = q.front();\n        q.pop();\n        for (auto e : g[now])\
      \ {\n            if (dist[e.to] != init) continue;\n            dist[e.to] =\
      \ dist[now] + 1;\n            q.push(e.to);\n        }\n    }\n}\n\ntemplate\
      \ <graph::WeightedGraph G>\nvoid bfs(const G &g,\n         std::queue<int> &q,\n\
      \         std::vector<typename G::value_type> &dist,\n         typename G::value_type\
      \ init) {\n    while (!q.empty()) {\n        int now = q.front();\n        q.pop();\n\
      \        for (auto e : g[now]) {\n            if (dist[e.to] != init) continue;\n\
      \            dist[e.to] = dist[now] + e.cost;\n            q.push(e.to);\n \
      \       }\n    }\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_SHORTEST_PATH_BFS_HPP\n"
    name: default
  - code: "#line 1 \"graph/shortest_path/bfs.hpp\"\n\n\n\n#include <queue>\n#include\
      \ <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n\
      #include <ranges>\n#include <type_traits>\n#include <utility>\n\nnamespace kk2::graph\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 8 \"graph/shortest_path/bfs.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UnweightedGraph G>\nvoid bfs(const G\
      \ &g, std::queue<int> &q, std::vector<int> &dist, int init) {\n    while (!q.empty())\
      \ {\n        int now = q.front();\n        q.pop();\n        for (auto e : g[now])\
      \ {\n            if (dist[e.to] != init) continue;\n            dist[e.to] =\
      \ dist[now] + 1;\n            q.push(e.to);\n        }\n    }\n}\n\ntemplate\
      \ <graph::WeightedGraph G>\nvoid bfs(const G &g,\n         std::queue<int> &q,\n\
      \         std::vector<typename G::value_type> &dist,\n         typename G::value_type\
      \ init) {\n    while (!q.empty()) {\n        int now = q.front();\n        q.pop();\n\
      \        for (auto e : g[now]) {\n            if (dist[e.to] != init) continue;\n\
      \            dist[e.to] = dist[now] + e.cost;\n            q.push(e.to);\n \
      \       }\n    }\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/shortest_path/bfs.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/bfs.hpp
layout: document
---
