---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: graph_base.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/graph_base.hpp
    - filename: edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/edge.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
    - filename: compact_static_graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/compact_static_graph.hpp
    - filename: static_graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/static_graph.hpp
    type: Required by
  - files:
    - filename: graph.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/graph/graph.test.cpp
    - filename: graph_cycle_detection.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    - filename: graph_cycle_detection_directed.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    - filename: graph_enumerate_triangle.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    - filename: tree_lca_static.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca_static.test.cpp
    type: Verified with
  dependsOn:
  - graph/detail/graph_base.hpp
  - graph/edge.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP\n#define KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP\
      \ 1\n\n#include <span>\n#include <type_traits>\n#include <utility>\n#include\
      \ <vector>\n\n#include \"../../type_traits/io.hpp\"\n#include \"../edge.hpp\"\
      \n#include \"graph_base.hpp\"\n\nnamespace kk2::graph::detail {\n\ntemplate\
      \ <class T, bool is_directed, class Storage>\nstruct StaticAdjacencyListBase\
      \ : GraphBase<T, is_directed, true>, private Storage {\n    using base = GraphBase<T,\
      \ is_directed, true>;\n\n  public:\n    // Public type interface and graph storage.\n\
      \    using base::edges;\n    using base::num_edges;\n    using base::weighted;\n\
      \    using Storage::data;\n\n    using storage_type = Storage;\n    using value_type\
      \ = T;\n    using out_edge_type = typename Storage::out_edge_type;\n    using\
      \ out_edges = typename Storage::out_edges;\n    using adjacency_container =\
      \ typename Storage::adjacency_container;\n\n  private:\n    std::vector<int>\
      \ head;\n\n  public:\n    using edge_type = _Edge<T>;\n    using edge_collection\
      \ = _Edges<T>;\n\n    // Construction and graph operations.\n    StaticAdjacencyListBase()\
      \ = default;\n    explicit StaticAdjacencyListBase(int n) : Storage(), head(n)\
      \ {}\n    template <InputStream IStream>\n    StaticAdjacencyListBase(int n,\
      \ int m, IStream &is, bool oneindexed = false) : head(n) {\n        edges.reserve(m);\n\
      \        _input(is, m, oneindexed);\n        build_storage();\n    }\n    StaticAdjacencyListBase(int\
      \ n, const edge_collection &edges_) : head(n) {\n        edges.reserve(edges_.size());\n\
      \        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e),\
      \ e.id);\n        build_storage();\n    }\n\n    int num_vertices() const {\
      \ return head.size(); }\n    int size() const { return num_vertices(); }\n \
      \   auto operator[](int k) { return Storage::view(head, &edges, k); }\n\n  \
      \  auto operator[](int k) const { return Storage::view(std::as_const(head),\
      \ &edges, k); }\n\n    auto edge_ids(int k) const\n        requires requires\
      \ { std::declval<const Storage &>().edge_ids(head, k); }\n    {\n        return\
      \ static_cast<const Storage &>(*this).edge_ids(head, k);\n    }\n\n    void\
      \ swap_edges(int v, int i, int j) { Storage::swap_edges(head, v, i, j); }\n\
      \    void edge_clear() { *this = StaticAdjacencyListBase(num_vertices()); }\n\
      \n    template <OutputStream OStream> void debug_output(OStream &os) const {\n\
      \        os << \"[\\n\";\n        for (int i = 0; i < num_vertices(); ++i) {\n\
      \            os << \"  \" << i << \": [\";\n            bool first = true;\n\
      \            for (auto &&e : (*this)[i]) {\n                if (!first) os <<\
      \ \", \";\n                first = false;\n                e.debug_output(os);\n\
      \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\\
      n\";\n    }\n\n  private:\n    void build_storage() {\n        for (int i =\
      \ 1; i < (int)head.size(); ++i) head[i] += head[i - 1];\n        Storage::build(head,\
      \ edges);\n    }\n\n  public:\n    StaticAdjacencyListBase reverse() const {\n\
      \        StaticAdjacencyListBase result(num_vertices());\n        result.edges.reserve(edges.size());\n\
      \        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from,\
      \ _edge_cost(e), e.id);\n        result.build_storage();\n        return result;\n\
      \    }\n\n  private:\n    template <InputStream IStream> void _input(IStream\
      \ &is, int m, bool oneindexed) {\n        edges.clear();\n        edges.reserve(m);\n\
      \        head.assign(num_vertices(), 0);\n        for (int i = 0; i < m; ++i)\
      \ {\n            int u, v;\n            T w{};\n            is >> u >> v;\n\
      \            if constexpr (weighted) is >> w;\n            if (oneindexed) --u,\
      \ --v;\n            _add_edge<false>(u, v, w, i);\n        }\n    }\n\n    template\
      \ <bool update = false> void _add_edge(int from, int to, T cost, int id) {\n\
      \        Storage::count_edge(head, from, to, is_directed);\n        if constexpr\
      \ (update) edges[id] = edge_type(to, cost, from, id);\n        else edges.emplace_back(to,\
      \ cost, from, id);\n    }\n\n    void _add_edge_with_id(int from, int to, T\
      \ cost, int id) {\n        Storage::count_edge(head, from, to, is_directed);\n\
      \        edges.emplace_back(to, cost, from, id);\n    }\n};\n\n} // namespace\
      \ kk2::graph::detail\n\n#endif // KK2_GRAPH_DETAIL_STATIC_ADJACENCY_LIST_BASE_HPP\n"
    name: default
  - code: "#line 1 \"graph/detail/static_adjacency_list_base.hpp\"\n\n\n\n#include\
      \ <span>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\n\
      #line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
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
      \n} // namespace kk2\n\n\n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 6 \"graph/edge.hpp\"\
      \n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\nstruct\
      \ empty {};\n\ntemplate <class T> struct _Edge {\n    int from, to, id;\n  \
      \  T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n  \
      \      : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
      \ {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator int() const {\
      \ return to; }\n    inline _Edge rev() const { return _Edge(from, cost, to,\
      \ id); }\n\n    template <OutputStream OStream> void debug_output(OStream &os)\
      \ const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n    \
      \    if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n       \
      \ os << ')';\n    }\n};\n\ntemplate <> struct _Edge<empty> {\n    int from,\
      \ to, id;\n\n    _Edge(int to_, empty = {}, int from_ = -1, int id_ = -1) :\
      \ from(from_), to(to_), id(id_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n\
      \    operator int() const { return to; }\n    inline _Edge rev() const { return\
      \ _Edge(from, {}, to, id); }\n\n    template <OutputStream OStream> void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to <<\
      \ ')';\n    }\n};\n\ntemplate <class T> T _edge_cost(const _Edge<T> &edge) {\n\
      \    if constexpr (std::is_same_v<T, empty>) return {};\n    else return edge.cost;\n\
      }\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>> {\n   \
      \ using std::vector<_Edge<T>>::vector;\n\n    template <InputStream IStream>\n\
      \    _Edges(int m, IStream &is, bool is_one_indexed = false) : std::vector<_Edge<T>>(m)\
      \ {\n        _input(is, is_one_indexed);\n    }\n\n    template <OutputStream\
      \ OStream> void debug_output(OStream &os) const {\n        os << '[';\n    \
      \    for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os <<\
      \ \", \";\n            (*this)[i].debug_output(os);\n        }\n        os <<\
      \ ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n  \
      \      this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
      \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
      \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n    \
      \    return edges;\n    }\n\n  private:\n    template <InputStream IStream>\
      \ void _input(IStream &is, bool is_one_indexed) {\n        for (int i = 0; i\
      \ < (int)this->size(); ++i) {\n            int u, v;\n            T w{};\n \
      \           is >> u >> v;\n            if (is_one_indexed) --u, --v;\n     \
      \       if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
      \ = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace graph\n\n\
      template <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T>\
      \ using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
      using Edges = graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"graph/detail/graph_base.hpp\"\n\n\n\n#line 5 \"graph/detail/graph_base.hpp\"\
      \n\n#line 7 \"graph/detail/graph_base.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\n// The representation-specific graph classes inherit this base.  Operations\n\
      // here only depend on the public graph interface, so they are shared by\n//\
      \ dynamic/static and direct/compact graphs alike.\ntemplate <class T, bool is_directed,\
      \ bool is_static, bool is_adjacency_list = true>\nstruct GraphBase {\n  public:\n\
      \    // Types and compile-time graph properties.\n    using value_type = T;\n\
      \    using edge_type = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n\
      \    static constexpr bool directed = is_directed;\n    static constexpr bool\
      \ weighted = !std::is_same_v<T, empty>;\n    static constexpr bool adjacency_list\
      \ = is_adjacency_list;\n    static constexpr bool adjacency_matrix = !is_adjacency_list;\n\
      \    static constexpr bool static_graph = is_static;\n\n    // Public graph\
      \ data and common operations.\n    edge_collection edges;\n    int num_edges()\
      \ const { return edges.size(); }\n};\n\n} // namespace kk2::graph::detail\n\n\
      \n#line 12 \"graph/detail/static_adjacency_list_base.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\ntemplate <class T, bool is_directed, class Storage>\nstruct StaticAdjacencyListBase\
      \ : GraphBase<T, is_directed, true>, private Storage {\n    using base = GraphBase<T,\
      \ is_directed, true>;\n\n  public:\n    // Public type interface and graph storage.\n\
      \    using base::edges;\n    using base::num_edges;\n    using base::weighted;\n\
      \    using Storage::data;\n\n    using storage_type = Storage;\n    using value_type\
      \ = T;\n    using out_edge_type = typename Storage::out_edge_type;\n    using\
      \ out_edges = typename Storage::out_edges;\n    using adjacency_container =\
      \ typename Storage::adjacency_container;\n\n  private:\n    std::vector<int>\
      \ head;\n\n  public:\n    using edge_type = _Edge<T>;\n    using edge_collection\
      \ = _Edges<T>;\n\n    // Construction and graph operations.\n    StaticAdjacencyListBase()\
      \ = default;\n    explicit StaticAdjacencyListBase(int n) : Storage(), head(n)\
      \ {}\n    template <InputStream IStream>\n    StaticAdjacencyListBase(int n,\
      \ int m, IStream &is, bool oneindexed = false) : head(n) {\n        edges.reserve(m);\n\
      \        _input(is, m, oneindexed);\n        build_storage();\n    }\n    StaticAdjacencyListBase(int\
      \ n, const edge_collection &edges_) : head(n) {\n        edges.reserve(edges_.size());\n\
      \        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e),\
      \ e.id);\n        build_storage();\n    }\n\n    int num_vertices() const {\
      \ return head.size(); }\n    int size() const { return num_vertices(); }\n \
      \   auto operator[](int k) { return Storage::view(head, &edges, k); }\n\n  \
      \  auto operator[](int k) const { return Storage::view(std::as_const(head),\
      \ &edges, k); }\n\n    auto edge_ids(int k) const\n        requires requires\
      \ { std::declval<const Storage &>().edge_ids(head, k); }\n    {\n        return\
      \ static_cast<const Storage &>(*this).edge_ids(head, k);\n    }\n\n    void\
      \ swap_edges(int v, int i, int j) { Storage::swap_edges(head, v, i, j); }\n\
      \    void edge_clear() { *this = StaticAdjacencyListBase(num_vertices()); }\n\
      \n    template <OutputStream OStream> void debug_output(OStream &os) const {\n\
      \        os << \"[\\n\";\n        for (int i = 0; i < num_vertices(); ++i) {\n\
      \            os << \"  \" << i << \": [\";\n            bool first = true;\n\
      \            for (auto &&e : (*this)[i]) {\n                if (!first) os <<\
      \ \", \";\n                first = false;\n                e.debug_output(os);\n\
      \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\\
      n\";\n    }\n\n  private:\n    void build_storage() {\n        for (int i =\
      \ 1; i < (int)head.size(); ++i) head[i] += head[i - 1];\n        Storage::build(head,\
      \ edges);\n    }\n\n  public:\n    StaticAdjacencyListBase reverse() const {\n\
      \        StaticAdjacencyListBase result(num_vertices());\n        result.edges.reserve(edges.size());\n\
      \        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from,\
      \ _edge_cost(e), e.id);\n        result.build_storage();\n        return result;\n\
      \    }\n\n  private:\n    template <InputStream IStream> void _input(IStream\
      \ &is, int m, bool oneindexed) {\n        edges.clear();\n        edges.reserve(m);\n\
      \        head.assign(num_vertices(), 0);\n        for (int i = 0; i < m; ++i)\
      \ {\n            int u, v;\n            T w{};\n            is >> u >> v;\n\
      \            if constexpr (weighted) is >> w;\n            if (oneindexed) --u,\
      \ --v;\n            _add_edge<false>(u, v, w, i);\n        }\n    }\n\n    template\
      \ <bool update = false> void _add_edge(int from, int to, T cost, int id) {\n\
      \        Storage::count_edge(head, from, to, is_directed);\n        if constexpr\
      \ (update) edges[id] = edge_type(to, cost, from, id);\n        else edges.emplace_back(to,\
      \ cost, from, id);\n    }\n\n    void _add_edge_with_id(int from, int to, T\
      \ cost, int id) {\n        Storage::count_edge(head, from, to, is_directed);\n\
      \        edges.emplace_back(to, cost, from, id);\n    }\n};\n\n} // namespace\
      \ kk2::graph::detail\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/detail/static_adjacency_list_base.hpp
  pathExtension: hpp
  requiredBy:
  - graph/compact_static_graph.hpp
  - graph/static_graph.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/graph/graph.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
documentation_of: graph/detail/static_adjacency_list_base.hpp
layout: document
---
