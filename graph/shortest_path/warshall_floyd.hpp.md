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
    - filename: aoj_grl_1_c.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_c.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_WARSHALL_FLOYD_HPP\n#define KK2_GRAPH_WARSHALL_FLOYD_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
      \ <ranges>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\n\
      #include \"../../type_traits/io.hpp\"\n#include \"../../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename\
      \ T> struct wf_len {\n    T len;\n    bool inf, minf;\n\n    template <OutputStream\
      \ OStream>\n    void debug_output(OStream &os) const {\n        if (minf) os\
      \ << \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n\
      \    }\n};\n\ntemplate <graph::WeightedEdgeRange E,\n          typename T =\
      \ std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
      std::vector<std::vector<wf_len<T>>> warshall_froyd(int n, const E &edges, bool\
      \ directed) {\n\n    std::vector<std::vector<wf_len<T>>> res(n, std::vector<wf_len<T>>(n,\
      \ {0, true, false}));\n    for (int i = 0; i < n; ++i) res[i][i] = {0, false,\
      \ false};\n    for (auto &&e : edges) {\n        {\n            auto &[len,\
      \ inf, minf] = res[e.from][e.to];\n            if (inf or len > e.cost) {\n\
      \                len = e.cost;\n                inf = false;\n            }\n\
      \        }\n        if (!directed) {\n            auto &[len, inf, minf] = res[e.to][e.from];\n\
      \            if (inf or len > e.cost) {\n                len = e.cost;\n   \
      \             inf = false;\n            }\n        }\n    }\n\n    for (int\
      \ k = 0; k < n; ++k) {\n        for (int i = 0; i < n; ++i) {\n            for\
      \ (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
      \ continue;\n                if (res[i][j].inf or res[i][j].len > res[i][k].len\
      \ + res[k][j].len) {\n                    res[i][j].len = res[i][k].len + res[k][j].len;\n\
      \                    res[i][j].inf = false;\n                }\n           \
      \ }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len\
      \ >= 0) continue;\n        res[k][k].minf = true;\n        for (int i = 0; i\
      \ < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n                if\
      \ (res[i][k].inf or res[k][j].inf) continue;\n                res[i][j].minf\
      \ = true;\n            }\n        }\n    }\n\n    return res;\n}\n\n} // namespace\
      \ shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GRAPH_WARSHALL_FLOYD_HPP\n"
    name: default
  - code: "#line 1 \"graph/shortest_path/warshall_floyd.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <limits>\n#include <ranges>\n#include <type_traits>\n\
      #include <utility>\n#include <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\
      \n#include <concepts>\n#include <fstream>\n#include <istream>\n#include <ostream>\n\
      #line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\
      \nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                  || std::is_same<T,\
      \ std::ifstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                  || std::is_same<T,\
      \ std::ofstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#line 8 \"\
      type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept\
      \ Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 14 \"graph/shortest_path/warshall_floyd.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename\
      \ T> struct wf_len {\n    T len;\n    bool inf, minf;\n\n    template <OutputStream\
      \ OStream>\n    void debug_output(OStream &os) const {\n        if (minf) os\
      \ << \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n\
      \    }\n};\n\ntemplate <graph::WeightedEdgeRange E,\n          typename T =\
      \ std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
      std::vector<std::vector<wf_len<T>>> warshall_froyd(int n, const E &edges, bool\
      \ directed) {\n\n    std::vector<std::vector<wf_len<T>>> res(n, std::vector<wf_len<T>>(n,\
      \ {0, true, false}));\n    for (int i = 0; i < n; ++i) res[i][i] = {0, false,\
      \ false};\n    for (auto &&e : edges) {\n        {\n            auto &[len,\
      \ inf, minf] = res[e.from][e.to];\n            if (inf or len > e.cost) {\n\
      \                len = e.cost;\n                inf = false;\n            }\n\
      \        }\n        if (!directed) {\n            auto &[len, inf, minf] = res[e.to][e.from];\n\
      \            if (inf or len > e.cost) {\n                len = e.cost;\n   \
      \             inf = false;\n            }\n        }\n    }\n\n    for (int\
      \ k = 0; k < n; ++k) {\n        for (int i = 0; i < n; ++i) {\n            for\
      \ (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
      \ continue;\n                if (res[i][j].inf or res[i][j].len > res[i][k].len\
      \ + res[k][j].len) {\n                    res[i][j].len = res[i][k].len + res[k][j].len;\n\
      \                    res[i][j].inf = false;\n                }\n           \
      \ }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len\
      \ >= 0) continue;\n        res[k][k].minf = true;\n        for (int i = 0; i\
      \ < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n                if\
      \ (res[i][k].inf or res[k][j].inf) continue;\n                res[i][j].minf\
      \ = true;\n            }\n        }\n    }\n\n    return res;\n}\n\n} // namespace\
      \ shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/shortest_path/warshall_floyd.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/shortest_path/warshall_floyd.hpp
layout: document
---
