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
    - filename: matrix.hpp
      icon: LIBRARY_ALL_AC
      path: graph/matrix.hpp
    type: Required by
  - files:
    - filename: aoj_grl_1_c.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_c.test.cpp
    - filename: graph.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/graph/graph.test.cpp
    type: Verified with
  dependsOn:
  - graph/edge.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_MATRIX_EDGE_HPP\n#define KK2_GRAPH_MATRIX_EDGE_HPP 1\n\
      \n#include <span>\n#include <type_traits>\n\n#include \"edge.hpp\"\n\nnamespace\
      \ kk2::graph {\n\ntemplate <class T, bool is_const> struct _MatrixEdgeProxy\
      \ {\n  private:\n    using id_reference = std::conditional_t<is_const, const\
      \ int &, int &>;\n    using cost_reference = std::conditional_t<is_const, const\
      \ T &, T &>;\n\n  public:\n    int from, to;\n    id_reference id;\n    cost_reference\
      \ cost;\n\n    _MatrixEdgeProxy(int from_, int to_, id_reference id_, cost_reference\
      \ cost_)\n        : from(from_),\n          to(to_),\n          id(id_),\n \
      \         cost(cost_) {}\n\n    operator int() const { return to; }\n\n    template\
      \ <class OStream>\n    void debug_output(OStream &os) const {\n        os <<\
      \ '(' << id << \", \" << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T,\
      \ empty>) os << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <class\
      \ T, bool is_const> class _MatrixRowView {\n    using edge_collection = _Edges<T>;\n\
      \    using slot_span = std::conditional_t<is_const, std::span<const int>, std::span<int>>;\n\
      \    using edge_pointer = std::conditional_t<is_const, const edge_collection\
      \ *, edge_collection *>;\n    using cost_pointer = std::conditional_t<is_const,\
      \ const T *, T *>;\n\n    slot_span slots;\n    edge_pointer edges;\n    cost_pointer\
      \ null_cost;\n    int from;\n\n  public:\n    using value_type = _MatrixEdgeProxy<T,\
      \ is_const>;\n\n    _MatrixRowView(slot_span slots_, edge_pointer edges_, cost_pointer\
      \ null_cost_, int from_)\n        : slots(slots_),\n          edges(edges_),\n\
      \          null_cost(null_cost_),\n          from(from_) {}\n\n  private:\n\
      \    cost_pointer get_cost(int id) const {\n        if constexpr (std::is_same_v<T,\
      \ empty>) return null_cost;\n        else return id == -1 ? null_cost : &(*edges)[id].cost;\n\
      \    }\n\n  public:\n    value_type operator[](int to) const {\n        const\
      \ int id = slots[to];\n        return {from, to, slots[to], *get_cost(id)};\n\
      \    }\n    int size() const { return slots.size(); }\n};\n\n} // namespace\
      \ kk2::graph\n\n#endif // KK2_GRAPH_MATRIX_EDGE_HPP\n"
    name: default
  - code: "#line 1 \"graph/matrix_edge.hpp\"\n\n\n\n#include <span>\n#include <type_traits>\n\
      \n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 5 \"graph/edge.hpp\"\n#include <vector>\n\
      \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
      \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n  \
      \                                || std::is_same<T, std::ifstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ =\n    typename std::conditional<std::is_same<T, std::ostream>::value\n  \
      \                                || std::is_same<T, std::ofstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \n} // namespace kk2\n\n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\n\
      namespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct _Edge {\n\
      \    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_\
      \ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n        \
      \  id(id_),\n          cost(cost_) {}\n    _Edge() : from(-1), to(-1), id(-1)\
      \ {}\n    operator int() const { return to; }\n    inline _Edge rev() const\
      \ { return _Edge(from, cost, to, id); }\n\n    template <OutputStream OStream>\n\
      \    void debug_output(OStream &os) const {\n        os << '(' << id << \",\
      \ \" << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T, empty>)\
      \ os << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <> struct\
      \ _Edge<empty> {\n    int from, to, id;\n\n    _Edge(int to_, empty = {}, int\
      \ from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n  \
      \        id(id_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator\
      \ int() const { return to; }\n    inline _Edge rev() const { return _Edge(from,\
      \ {}, to, id); }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to <<\
      \ ')';\n    }\n};\n\ntemplate <class T> T _edge_cost(const _Edge<T> &edge) {\n\
      \    if constexpr (std::is_same_v<T, empty>) return {};\n    else return edge.cost;\n\
      }\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>> {\n   \
      \ using std::vector<_Edge<T>>::vector;\n\n    template <InputStream IStream>\n\
      \    _Edges(int m, IStream &is, bool is_one_indexed = false)\n        : std::vector<_Edge<T>>(m)\
      \ {\n        _input(is, is_one_indexed);\n    }\n\n    template <OutputStream\
      \ OStream>\n    void debug_output(OStream &os) const {\n        os << '[';\n\
      \        for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os\
      \ << \", \";\n            (*this)[i].debug_output(os);\n        }\n        os\
      \ << ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n\
      \        this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
      \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
      \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n    \
      \    return edges;\n    }\n\n  private:\n    template <InputStream IStream>\n\
      \    void _input(IStream &is, bool is_one_indexed) {\n        for (int i = 0;\
      \ i < (int)this->size(); ++i) {\n            int u, v;\n            T w{};\n\
      \            is >> u >> v;\n            if (is_one_indexed) --u, --v;\n    \
      \        if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
      \ = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace graph\n\n\
      template <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T>\
      \ using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
      using Edges = graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line\
      \ 8 \"graph/matrix_edge.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class T,\
      \ bool is_const> struct _MatrixEdgeProxy {\n  private:\n    using id_reference\
      \ = std::conditional_t<is_const, const int &, int &>;\n    using cost_reference\
      \ = std::conditional_t<is_const, const T &, T &>;\n\n  public:\n    int from,\
      \ to;\n    id_reference id;\n    cost_reference cost;\n\n    _MatrixEdgeProxy(int\
      \ from_, int to_, id_reference id_, cost_reference cost_)\n        : from(from_),\n\
      \          to(to_),\n          id(id_),\n          cost(cost_) {}\n\n    operator\
      \ int() const { return to; }\n\n    template <class OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n\
      \        if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n   \
      \     os << ')';\n    }\n};\n\ntemplate <class T, bool is_const> class _MatrixRowView\
      \ {\n    using edge_collection = _Edges<T>;\n    using slot_span = std::conditional_t<is_const,\
      \ std::span<const int>, std::span<int>>;\n    using edge_pointer = std::conditional_t<is_const,\
      \ const edge_collection *, edge_collection *>;\n    using cost_pointer = std::conditional_t<is_const,\
      \ const T *, T *>;\n\n    slot_span slots;\n    edge_pointer edges;\n    cost_pointer\
      \ null_cost;\n    int from;\n\n  public:\n    using value_type = _MatrixEdgeProxy<T,\
      \ is_const>;\n\n    _MatrixRowView(slot_span slots_, edge_pointer edges_, cost_pointer\
      \ null_cost_, int from_)\n        : slots(slots_),\n          edges(edges_),\n\
      \          null_cost(null_cost_),\n          from(from_) {}\n\n  private:\n\
      \    cost_pointer get_cost(int id) const {\n        if constexpr (std::is_same_v<T,\
      \ empty>) return null_cost;\n        else return id == -1 ? null_cost : &(*edges)[id].cost;\n\
      \    }\n\n  public:\n    value_type operator[](int to) const {\n        const\
      \ int id = slots[to];\n        return {from, to, slots[to], *get_cost(id)};\n\
      \    }\n    int size() const { return slots.size(); }\n};\n\n} // namespace\
      \ kk2::graph\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/matrix_edge.hpp
  pathExtension: hpp
  requiredBy:
  - graph/matrix.hpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/unit_test/type_traits/graph/graph.test.cpp
documentation_of: graph/matrix_edge.hpp
layout: document
---
