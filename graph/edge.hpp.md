---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/static_graph.hpp
    title: graph/static_graph.hpp
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_b.test.cpp
    title: verify/aoj/aoj_grl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    title: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    title: verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    title: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_scc.test.cpp
    title: verify/yosupo_graph/graph_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca.test.cpp
    title: verify/yosupo_graph/tree_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
    title: verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    title: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - icon: ':x:'
    path: verify/yuki/yuki_1326.test.cpp
    title: verify/yuki/yuki_1326.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/edge.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include\
    \ <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits\
    \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
    \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\
    \nstruct empty {};\n\ntemplate <class T> struct _Edge {\n    int from, to, id;\n\
    \    T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n  \
    \      : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
    \ {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator int() const { return\
    \ to; }\n    inline _Edge rev() const { return _Edge(from, cost, to, id); }\n\n\
    \    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n \
    \       if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n      \
    \  os << ')';\n    }\n};\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>>\
    \ {\n    using std::vector<_Edge<T>>::vector;\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    _Edges &input(IStream &is, bool is_one_indexed\
    \ = false) {\n        for (int i = 0; i < (int)this->size(); i++) {\n        \
    \    int u, v;\n            T w{};\n            is >> u >> v;\n            if\
    \ (is_one_indexed) --u, --v;\n            if constexpr (!std::is_same_v<T, empty>)\
    \ is >> w;\n            (*this)[i] = _Edge<T>(v, w, u, i);\n        }\n      \
    \  return *this;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend _Edges &input(_Edges &edges, IStream &is, bool is_one_indexed\
    \ = false) {\n        return edges.input(is, is_one_indexed);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        os << '[';\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            if (i) os << \", \";\n            (*this)[i].debug_output(os);\n\
    \        }\n        os << ']';\n    }\n\n    _Edges &add_edge(int from, int to,\
    \ T cost = T{}) {\n        this->emplace_back(to, cost, from, this->size());\n\
    \        return *this;\n    }\n\n    friend _Edges &add_edge(_Edges &edges, int\
    \ from, int to, T cost = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n\
    \        return edges;\n    }\n};\n\ntemplate <class T> struct _pair {\n    T\
    \ cost;\n    int id;\n\n    _pair(T cost_, int id_) : cost(cost_), id(id_) {}\n\
    \    _pair() : cost(), id(-1) {}\n    operator bool() const { return id != -1;\
    \ }\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const _pair &p) {\n        if constexpr (std::is_same_v<T,\
    \ empty>) return os;\n        else return os << p.cost;\n    }\n};\ntemplate <class\
    \ T> using _pairs = std::vector<_pair<T>>;\n\n} // namespace graph\n\ntemplate\
    \ <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T> using WEdges\
    \ = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\nusing Edges =\
    \ graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_EDGE_HPP\n#define KK2_GRAPH_EDGE_HPP 1\n\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../type_traits/io.hpp\"\n\nnamespace kk2 {\n\n\
    namespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct _Edge {\n \
    \   int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_ =\
    \ -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n          id(id_),\n\
    \          cost(cost_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator\
    \ int() const { return to; }\n    inline _Edge rev() const { return _Edge(from,\
    \ cost, to, id); }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    void debug_output(OStream &os) const {\n        os << '(' << id << \", \"\
    \ << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T, empty>) os\
    \ << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <class T> struct\
    \ _Edges : public std::vector<_Edge<T>> {\n    using std::vector<_Edge<T>>::vector;\n\
    \n    template <class IStream, is_istream_t<IStream> * = nullptr>\n    _Edges\
    \ &input(IStream &is, bool is_one_indexed = false) {\n        for (int i = 0;\
    \ i < (int)this->size(); i++) {\n            int u, v;\n            T w{};\n \
    \           is >> u >> v;\n            if (is_one_indexed) --u, --v;\n       \
    \     if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
    \ = _Edge<T>(v, w, u, i);\n        }\n        return *this;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend _Edges &input(_Edges\
    \ &edges, IStream &is, bool is_one_indexed = false) {\n        return edges.input(is,\
    \ is_one_indexed);\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << '[';\n\
    \        for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os\
    \ << \", \";\n            (*this)[i].debug_output(os);\n        }\n        os\
    \ << ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n \
    \       this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
    \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
    \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n      \
    \  return edges;\n    }\n};\n\ntemplate <class T> struct _pair {\n    T cost;\n\
    \    int id;\n\n    _pair(T cost_, int id_) : cost(cost_), id(id_) {}\n    _pair()\
    \ : cost(), id(-1) {}\n    operator bool() const { return id != -1; }\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const _pair &p) {\n        if constexpr (std::is_same_v<T, empty>) return\
    \ os;\n        else return os << p.cost;\n    }\n};\ntemplate <class T> using\
    \ _pairs = std::vector<_pair<T>>;\n\n} // namespace graph\n\ntemplate <typename\
    \ T> using WEdge = graph::_Edge<T>;\ntemplate <typename T> using WEdges = graph::_Edges<T>;\n\
    using Edge = graph::_Edge<graph::empty>;\nusing Edges = graph::_Edges<graph::empty>;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_EDGE_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - random/graph.hpp
  - graph/static_graph.hpp
  - graph/graph.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/aoj/aoj_grl_1_b.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: graph/edge.hpp
---
