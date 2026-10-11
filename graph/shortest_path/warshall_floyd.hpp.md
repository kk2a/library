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
  - code: "#ifndef KK2_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP\n#define KK2_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
      \ <ranges>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\n\
      #include \"../../type_traits/graph.hpp\"\n#include \"../../type_traits/io.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename\
      \ T> struct wf_len {\n    T len;\n    bool inf, minf;\n\n    template <OutputStream\
      \ OStream> void debug_output(OStream &os) const {\n        if (minf) os << \"\
      MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n   \
      \ }\n};\n\ntemplate <\n    graph::WeightedEdgeRange E,\n    typename T = std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
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
      \ kk2\n\n#endif // KK2_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP\n"
    name: default
  - code: "#line 1 \"graph/shortest_path/warshall_floyd.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <limits>\n#include <ranges>\n#include <type_traits>\n\
      #include <utility>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\
      \n\n\n#include <concepts>\n#line 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E> concept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\ntemplate <class E> concept WeightedEdge\
      \ = Edge<E> && requires(const E &e) { e.cost; };\ntemplate <class R> concept\
      \ EdgeRange = std::ranges::input_range<R> && Edge<std::ranges::range_value_t<R>>;\n\
      template <class R> concept WeightedEdgeRange = EdgeRange<R> && WeightedEdge<std::ranges::range_value_t<R>>;\n\
      template <class R> concept ForwardWeightedEdgeRange = std::ranges::forward_range<R>\
      \ && WeightedEdgeRange<R>;\ntemplate <class G> concept Graph = requires(const\
      \ G &g, int v) {\n    typename G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n\
      \    { G::weighted } -> std::convertible_to<bool>;\n    { G::adjacency_list\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_matrix } -> std::convertible_to<bool>;\n\
      \    { G::static_graph } -> std::convertible_to<bool>;\n    { g.num_vertices()\
      \ } -> std::integral;\n    { g.num_edges() } -> std::integral;\n    g[v];\n\
      \    g.edges;\n};\ntemplate <class G> concept EdgeListGraph = Graph<G> && requires(const\
      \ G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n    requires\
      \ Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n};\ntemplate <class\
      \ G> concept AdjacencyGraph = Graph<G> && requires(const G &g, int v) {\n  \
      \  requires std::ranges::range<decltype(g[v])>;\n    requires Edge<std::ranges::range_value_t<decltype(g[v])>>;\n\
      };\ntemplate <class G> concept WeightedGraph =\n    AdjacencyGraph<G> && G::weighted\n\
      \    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>()[0])>>;\ntemplate <class G> concept WeightedEdgeListGraph =\n    EdgeListGraph<G>\
      \ && G::weighted\n    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>().edges)>>;\ntemplate <class G> concept UnweightedGraph = AdjacencyGraph<G>\
      \ && (!G::weighted);\ntemplate <class G> concept DirectedGraph = AdjacencyGraph<G>\
      \ && G::directed;\ntemplate <class G> concept UndirectedGraph = AdjacencyGraph<G>\
      \ && (!G::directed);\ntemplate <class G> concept WeightedDirectedGraph = WeightedGraph<G>\
      \ && DirectedGraph<G>;\ntemplate <class G> concept WeightedUndirectedGraph =\
      \ WeightedGraph<G> && UndirectedGraph<G>;\ntemplate <class G> concept WeightedDirectedEdgeListGraph\
      \ = WeightedEdgeListGraph<G> && G::directed;\ntemplate <class G> concept WeightedUndirectedEdgeListGraph\
      \ = WeightedEdgeListGraph<G> && (!G::directed);\ntemplate <class G> concept\
      \ StaticGraph = Graph<G> && G::static_graph;\n\n// Adjacency over vertices,\
      \ also usable with vector<vector<int>>.\ntemplate <class G> concept VertexAdjacency\
      \ = requires(const G &g, int v) {\n    { g.size() } -> std::integral;\n    requires\
      \ std::ranges::range<decltype(g[v])>;\n    requires std::convertible_to<std::ranges::range_value_t<decltype(g[v])>,\
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#line 5 \"type_traits/io.hpp\"\n#include <fstream>\n#include <istream>\n\
      #include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
      \ type_traits\n\ntemplate <typename T> using is_standard_istream = typename\
      \ std::conditional<std::is_same<T, std::istream>::value || std::is_same<T, std::ifstream>::value,\
      \ std::true_type, std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ = typename std::conditional<std::is_same<T, std::ostream>::value || std::is_same<T,\
      \ std::ofstream>::value, std::true_type, std::false_type>::type;\ntemplate <typename\
      \ T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\ntemplate <typename T> using is_istream = typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_ostream = typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value, std::true_type, std::false_type>::type;\n\
      template <typename T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\n\
      template <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      template <class T> concept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      template <class T> concept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 14 \"graph/shortest_path/warshall_floyd.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename\
      \ T> struct wf_len {\n    T len;\n    bool inf, minf;\n\n    template <OutputStream\
      \ OStream> void debug_output(OStream &os) const {\n        if (minf) os << \"\
      MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n   \
      \ }\n};\n\ntemplate <\n    graph::WeightedEdgeRange E,\n    typename T = std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
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
  timestamp: '2026-10-11 18:25:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/shortest_path/warshall_floyd.hpp
layout: document
---
