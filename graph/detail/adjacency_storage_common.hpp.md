---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/edge.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
    - filename: compact_graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/compact_graph.hpp
    - filename: compact_static_graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/compact_static_graph.hpp
    - filename: compact_adjacency_storage.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/compact_adjacency_storage.hpp
    - filename: compact_static_adjacency_storage.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/compact_static_adjacency_storage.hpp
    - filename: direct_adjacency_storage.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/direct_adjacency_storage.hpp
    - filename: direct_static_adjacency_storage.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/direct_static_adjacency_storage.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/graph.hpp
    - filename: static_graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/static_graph.hpp
    - filename: graph.hpp
      icon: LIBRARY_NO_TESTS
      path: random/graph.hpp
    type: Required by
  - files:
    - filename: aoj_grl_1_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_b.test.cpp
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
  dependsOn:
  - graph/edge.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP\n#define KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP\
      \ 1\n\n#include <vector>\n\n#include \"../edge.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\ntemplate <class T, bool is_directed>\nstd::vector<int> adjacency_degrees(int\
      \ n, const _Edges<T> &edges) {\n    std::vector<int> degree(n);\n    for (const\
      \ auto &e : edges) {\n        ++degree[e.from];\n        if constexpr (!is_directed)\
      \ {\n            if (e.from != e.to) ++degree[e.to];\n        }\n    }\n   \
      \ return degree;\n}\n\ntemplate <bool is_directed> void count_adjacency_edge(std::vector<int>\
      \ &head, int from, int to) {\n    ++head[from];\n    if constexpr (!is_directed)\
      \ {\n        if (from != to) ++head[to];\n    }\n}\n\n} // namespace kk2::graph::detail\n\
      \n#endif // KK2_GRAPH_DETAIL_ADJACENCY_STORAGE_COMMON_HPP\n"
    name: default
  - code: "#line 1 \"graph/detail/adjacency_storage_common.hpp\"\n\n\n\n#include <vector>\n\
      \n#line 1 \"graph/edge.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"graph/edge.hpp\"\
      \n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing is_standard_istream\
      \ = typename std::conditional<std::is_same<T, std::istream>::value\n       \
      \                                                   || std::is_same<T, std::ifstream>::value,\n\
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
      \n} // namespace kk2\n\n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\n\
      namespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct _Edge {\n\
      \    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_\
      \ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n        \
      \  id(id_),\n          cost(cost_) {}\n    _Edge() : from(-1), to(-1), id(-1)\
      \ {}\n    operator int() const { return to; }\n    inline _Edge rev() const\
      \ { return _Edge(from, cost, to, id); }\n\n    template <OutputStream OStream>\
      \ void debug_output(OStream &os) const {\n        os << '(' << id << \", \"\
      \ << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T, empty>)\
      \ os << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <> struct\
      \ _Edge<empty> {\n    int from, to, id;\n\n    _Edge(int to_, empty = {}, int\
      \ from_ = -1, int id_ = -1) : from(from_), to(to_), id(id_) {}\n    _Edge()\
      \ : from(-1), to(-1), id(-1) {}\n    operator int() const { return to; }\n \
      \   inline _Edge rev() const { return _Edge(from, {}, to, id); }\n\n    template\
      \ <OutputStream OStream> void debug_output(OStream &os) const {\n        os\
      \ << '(' << id << \", \" << from << \"->\" << to << ')';\n    }\n};\n\ntemplate\
      \ <class T> T _edge_cost(const _Edge<T> &edge) {\n    if constexpr (std::is_same_v<T,\
      \ empty>) return {};\n    else return edge.cost;\n}\n\ntemplate <class T> struct\
      \ _Edges : public std::vector<_Edge<T>> {\n    using std::vector<_Edge<T>>::vector;\n\
      \n    template <InputStream IStream>\n    _Edges(int m, IStream &is, bool is_one_indexed\
      \ = false) : std::vector<_Edge<T>>(m) {\n        _input(is, is_one_indexed);\n\
      \    }\n\n    template <OutputStream OStream> void debug_output(OStream &os)\
      \ const {\n        os << '[';\n        for (int i = 0; i < (int)this->size();\
      \ i++) {\n            if (i) os << \", \";\n            (*this)[i].debug_output(os);\n\
      \        }\n        os << ']';\n    }\n\n    _Edges &add_edge(int from, int\
      \ to, T cost = T{}) {\n        this->emplace_back(to, cost, from, this->size());\n\
      \        return *this;\n    }\n\n    friend _Edges &add_edge(_Edges &edges,\
      \ int from, int to, T cost = T{}) {\n        edges.emplace_back(to, cost, from,\
      \ edges.size());\n        return edges;\n    }\n\n  private:\n    template <InputStream\
      \ IStream> void _input(IStream &is, bool is_one_indexed) {\n        for (int\
      \ i = 0; i < (int)this->size(); ++i) {\n            int u, v;\n            T\
      \ w{};\n            is >> u >> v;\n            if (is_one_indexed) --u, --v;\n\
      \            if constexpr (!std::is_same_v<T, empty>) is >> w;\n           \
      \ (*this)[i] = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace\
      \ graph\n\ntemplate <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename\
      \ T> using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
      using Edges = graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line\
      \ 7 \"graph/detail/adjacency_storage_common.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\ntemplate <class T, bool is_directed>\nstd::vector<int> adjacency_degrees(int\
      \ n, const _Edges<T> &edges) {\n    std::vector<int> degree(n);\n    for (const\
      \ auto &e : edges) {\n        ++degree[e.from];\n        if constexpr (!is_directed)\
      \ {\n            if (e.from != e.to) ++degree[e.to];\n        }\n    }\n   \
      \ return degree;\n}\n\ntemplate <bool is_directed> void count_adjacency_edge(std::vector<int>\
      \ &head, int from, int to) {\n    ++head[from];\n    if constexpr (!is_directed)\
      \ {\n        if (from != to) ++head[to];\n    }\n}\n\n} // namespace kk2::graph::detail\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/detail/adjacency_storage_common.hpp
  pathExtension: hpp
  requiredBy:
  - graph/compact_graph.hpp
  - graph/compact_static_graph.hpp
  - graph/detail/compact_adjacency_storage.hpp
  - graph/detail/compact_static_adjacency_storage.hpp
  - graph/detail/direct_adjacency_storage.hpp
  - graph/detail/direct_static_adjacency_storage.hpp
  - graph/graph.hpp
  - graph/static_graph.hpp
  - random/graph.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_b.test.cpp
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
documentation_of: graph/detail/adjacency_storage_common.hpp
layout: document
---
