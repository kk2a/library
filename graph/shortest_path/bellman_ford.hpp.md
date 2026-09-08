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
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: aoj_grl_1_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_b.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\n#define KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\
      \ 1\n\n#include <limits>\n#include <ranges>\n#include <type_traits>\n#include\
      \ <utility>\n#include <vector>\n\n#include \"../../type_traits/graph.hpp\"\n\
      #include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace shortest_path_impl\
      \ {\n\ntemplate <class T> struct bf_edge {\n    int to, id;\n};\n\ntemplate\
      \ <class T> struct bf_len {\n    T len;\n    bool inf, minf;\n\n    template\
      \ <OutputStream OStream> void debug_output(OStream &os) const {\n        if\
      \ (minf) os << \"MINF\";\n        else if (inf) os << \"INF\";\n        else\
      \ os << len;\n    }\n};\n\ntemplate <class T> struct bf_result {\n    std::vector<bf_len<T>>\
      \ dist;\n    std::vector<bf_edge<T>> prev;\n};\n\ntemplate <\n    graph::ForwardWeightedEdgeRange\
      \ E,\n    class T = std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
      bf_result<T> bellman_ford(int n, const E &edges, int start) {\n\n    std::vector<bf_len<T>>\
      \ dist(n, {0, true, false});\n    std::vector<bf_edge<T>> prev(n, {-1, -1});\n\
      \    dist[start] = {0, false, false};\n\n    int iter = n;\n    while (iter--)\
      \ {\n        bool update = false;\n        for (auto e : edges) {\n        \
      \    if (dist[e.from].inf) continue;\n            if (dist[e.to].inf or dist[e.to].len\
      \ > dist[e.from].len + e.cost) {\n                update = true;\n         \
      \       dist[e.to].len = dist[e.from].len + e.cost;\n                dist[e.to].inf\
      \ = false;\n                prev[e.to] = {e.from, e.id};\n            }\n  \
      \      }\n        if (!update) return {dist, prev};\n    }\n\n    iter = n;\n\
      \    while (iter--) {\n        for (auto e : edges) {\n            if (dist[e.from].inf)\
      \ continue;\n            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len\
      \ + e.cost) {\n                dist[e.to].minf = true;\n                dist[e.to].len\
      \ = dist[e.from].len + e.cost;\n            }\n            if (dist[e.from].minf)\
      \ dist[e.to].minf = true;\n        }\n    }\n\n    return {dist, prev};\n}\n\
      \n} // namespace shortest_path_impl\n\nusing shortest_path_impl::bellman_ford;\n\
      \n} // namespace kk2\n\n\n#endif // KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\n"
    name: default
  - code: "#line 1 \"graph/shortest_path/bellman_ford.hpp\"\n\n\n\n#include <limits>\n\
      #include <ranges>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
      \n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#line 8 \"type_traits/graph.hpp\"\
      \n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge = requires(const\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#line 5 \"type_traits/io.hpp\"\n#include <fstream>\n#include <istream>\n\
      #include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
      \ type_traits\n\ntemplate <typename T>\nusing is_standard_istream = typename\
      \ std::conditional<std::is_same<T, std::istream>::value\n                  \
      \                                        || std::is_same<T, std::ifstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T>\nusing is_standard_ostream = typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                                   \
      \       || std::is_same<T, std::ofstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T> using\
      \ is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;\n\
      template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 12 \"graph/shortest_path/bellman_ford.hpp\"\n\
      \nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <class T> struct\
      \ bf_edge {\n    int to, id;\n};\n\ntemplate <class T> struct bf_len {\n   \
      \ T len;\n    bool inf, minf;\n\n    template <OutputStream OStream> void debug_output(OStream\
      \ &os) const {\n        if (minf) os << \"MINF\";\n        else if (inf) os\
      \ << \"INF\";\n        else os << len;\n    }\n};\n\ntemplate <class T> struct\
      \ bf_result {\n    std::vector<bf_len<T>> dist;\n    std::vector<bf_edge<T>>\
      \ prev;\n};\n\ntemplate <\n    graph::ForwardWeightedEdgeRange E,\n    class\
      \ T = std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
      bf_result<T> bellman_ford(int n, const E &edges, int start) {\n\n    std::vector<bf_len<T>>\
      \ dist(n, {0, true, false});\n    std::vector<bf_edge<T>> prev(n, {-1, -1});\n\
      \    dist[start] = {0, false, false};\n\n    int iter = n;\n    while (iter--)\
      \ {\n        bool update = false;\n        for (auto e : edges) {\n        \
      \    if (dist[e.from].inf) continue;\n            if (dist[e.to].inf or dist[e.to].len\
      \ > dist[e.from].len + e.cost) {\n                update = true;\n         \
      \       dist[e.to].len = dist[e.from].len + e.cost;\n                dist[e.to].inf\
      \ = false;\n                prev[e.to] = {e.from, e.id};\n            }\n  \
      \      }\n        if (!update) return {dist, prev};\n    }\n\n    iter = n;\n\
      \    while (iter--) {\n        for (auto e : edges) {\n            if (dist[e.from].inf)\
      \ continue;\n            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len\
      \ + e.cost) {\n                dist[e.to].minf = true;\n                dist[e.to].len\
      \ = dist[e.from].len + e.cost;\n            }\n            if (dist[e.from].minf)\
      \ dist[e.to].minf = true;\n        }\n    }\n\n    return {dist, prev};\n}\n\
      \n} // namespace shortest_path_impl\n\nusing shortest_path_impl::bellman_ford;\n\
      \n} // namespace kk2\n\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/shortest_path/bellman_ford.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_b.test.cpp
documentation_of: graph/shortest_path/bellman_ford.hpp
layout: document
---
