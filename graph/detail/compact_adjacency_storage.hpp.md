---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: compact_edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/compact_edge.hpp
    - filename: adjacency_storage_common.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/adjacency_storage_common.hpp
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
    type: Required by
  - files:
    - filename: graph.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/graph/graph.test.cpp
    type: Verified with
  dependsOn:
  - graph/compact_edge.hpp
  - graph/detail/adjacency_storage_common.hpp
  - graph/edge.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP\n#define KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP\
      \ 1\n\n#include <span>\n#include <utility>\n#include <vector>\n\n#include \"\
      ../compact_edge.hpp\"\n#include \"adjacency_storage_common.hpp\"\n\nnamespace\
      \ kk2::graph::detail {\n\ntemplate <class T, bool is_directed> struct CompactAdjacencyStorage\
      \ {\n    using edge_type = _Edge<T>;\n    using out_edge_type = _AdjacencyEdgeProxy<T,\
      \ false>;\n    using out_edges = std::vector<int>;\n    using adjacency_container\
      \ = std::vector<out_edges>;\n\n    adjacency_container data;\n\n    CompactAdjacencyStorage()\
      \ = default;\n    explicit CompactAdjacencyStorage(int n) : data(n) {}\n\n \
      \   int num_vertices() const { return data.size(); }\n    std::span<const int>\
      \ edge_ids(int k) const { return data[k]; }\n    void swap_edges(int v, int\
      \ i, int j) { std::swap(data[v][i], data[v][j]); }\n    void add_vertex(int\
      \ n) { data.insert(data.end(), n, out_edges()); }\n\n    _AdjacencyView<T, false>\
      \ view(int k, _Edges<T> *edges) {\n        return {std::span<int>(data[k]),\
      \ edges, k};\n    }\n    _AdjacencyView<T, true> view(int k, const _Edges<T>\
      \ *edges) const {\n        return {std::span<const int>(data[k]), edges, k};\n\
      \    }\n\n    void reset() { data.assign(data.size(), out_edges()); }\n\n  \
      \  void reserve(const _Edges<T> &edges) {\n        const auto degree = adjacency_degrees<T,\
      \ is_directed>(num_vertices(), edges);\n        for (int i = 0; i < num_vertices();\
      \ ++i) data[i].reserve(data[i].size() + degree[i]);\n    }\n\n    void add_edge(int\
      \ from, int to, T, int id) {\n        data[from].emplace_back(id);\n       \
      \ if constexpr (!is_directed) {\n            if (from != to) data[to].emplace_back(id);\n\
      \        }\n    }\n};\n\n} // namespace kk2::graph::detail\n\n#endif // KK2_GRAPH_DETAIL_COMPACT_ADJACENCY_STORAGE_HPP\n"
    name: default
  - code: "#line 1 \"graph/detail/compact_adjacency_storage.hpp\"\n\n\n\n#include\
      \ <span>\n#include <utility>\n#include <vector>\n\n#line 1 \"graph/compact_edge.hpp\"\
      \n\n\n\n#include <compare>\n#include <iterator>\n#line 7 \"graph/compact_edge.hpp\"\
      \n#include <type_traits>\n#line 9 \"graph/compact_edge.hpp\"\n\n#line 1 \"graph/edge.hpp\"\
      \n\n\n\n#line 6 \"graph/edge.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n\
      #include <concepts>\n#include <fstream>\n#include <istream>\n#include <ostream>\n\
      #line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\
      \nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T>\nusing is_standard_istream = typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                                   \
      \       || std::is_same<T, std::ifstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T>\n\
      using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ofstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \ 11 \"graph/compact_edge.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class\
      \ T, bool is_const> struct _AdjacencyEdgeProxy {\n  private:\n    using edge_type\
      \ = _Edge<T>;\n    using edge_reference = std::conditional_t<is_const, const\
      \ edge_type &, edge_type &>;\n    using id_reference = std::conditional_t<is_const,\
      \ const int &, int &>;\n    using cost_reference = std::conditional_t<is_const,\
      \ const T &, T &>;\n\n  public:\n    int from;\n    int to;\n    id_reference\
      \ id;\n    cost_reference cost;\n\n  private:\n    static cost_reference get_cost(edge_reference\
      \ edge) {\n        if constexpr (std::is_same_v<T, empty>) {\n            static\
      \ T unused{};\n            return unused;\n        } else {\n            return\
      \ edge.cost;\n        }\n    }\n\n  public:\n    _AdjacencyEdgeProxy(int from_,\
      \ id_reference id_, edge_reference edge)\n        : from(from_),\n         \
      \ to(edge.from == from_ ? edge.to : edge.from),\n          id(id_),\n      \
      \    cost(get_cost(edge)) {}\n\n    operator int() const { return to; }\n\n\
      \    template <class OStream> void debug_output(OStream &os) const {\n     \
      \   os << '(' << id << \", \" << from << \"->\" << to;\n        if constexpr\
      \ (!std::is_same_v<T, empty>) os << \":\" << cost;\n        os << ')';\n   \
      \ }\n\n    friend bool operator==(const _AdjacencyEdgeProxy &lhs, const _AdjacencyEdgeProxy\
      \ &rhs) {\n        return lhs.id == rhs.id;\n    }\n\n    friend void swap(_AdjacencyEdgeProxy\
      \ &lhs, _AdjacencyEdgeProxy &rhs) {\n        std::swap(lhs.id, rhs.id);\n  \
      \  }\n};\n\ntemplate <class T, bool is_const> class _AdjacencyView;\n\ntemplate\
      \ <class T, bool is_const> class _AdjacencyEdgeIterator {\n    using edge_collection\
      \ = _Edges<T>;\n    using slot_span = std::conditional_t<is_const, std::span<const\
      \ int>, std::span<int>>;\n\n  public:\n    using difference_type = std::ptrdiff_t;\n\
      \    using value_type = _AdjacencyEdgeProxy<T, is_const>;\n    using reference\
      \ = value_type;\n    using iterator_category = std::random_access_iterator_tag;\n\
      \    using iterator_concept = std::random_access_iterator_tag;\n\n  private:\n\
      \    using slot_iterator = decltype(std::declval<slot_span>().begin());\n  \
      \  using edge_pointer = std::conditional_t<is_const, const edge_collection *,\
      \ edge_collection *>;\n\n    slot_iterator it;\n    int from;\n    edge_pointer\
      \ edges;\n\n    _AdjacencyEdgeIterator(slot_iterator it_, int from_, edge_pointer\
      \ edges_)\n        : it(it_),\n          from(from_),\n          edges(edges_)\
      \ {}\n\n    friend class _AdjacencyView<T, is_const>;\n\n  public:\n    _AdjacencyEdgeIterator()\
      \ = default;\n    _AdjacencyEdgeIterator(const _AdjacencyEdgeIterator &) = default;\n\
      \n    struct arrow_proxy {\n        value_type value;\n        value_type *operator->()\
      \ { return &value; }\n        const value_type *operator->() const { return\
      \ &value; }\n    };\n\n    value_type operator*() const {\n        const int\
      \ id = *it;\n        return {from, *it, (*edges)[id]};\n    }\n    arrow_proxy\
      \ operator->() const { return {operator*()}; }\n\n    _AdjacencyEdgeIterator\
      \ &operator++() {\n        ++it;\n        return *this;\n    }\n    _AdjacencyEdgeIterator\
      \ operator++(int) {\n        auto result = *this;\n        ++*this;\n      \
      \  return result;\n    }\n    _AdjacencyEdgeIterator &operator--() {\n     \
      \   --it;\n        return *this;\n    }\n    _AdjacencyEdgeIterator operator--(int)\
      \ {\n        auto result = *this;\n        --*this;\n        return result;\n\
      \    }\n    _AdjacencyEdgeIterator &operator+=(difference_type n) {\n      \
      \  it += n;\n        return *this;\n    }\n    _AdjacencyEdgeIterator &operator-=(difference_type\
      \ n) {\n        it -= n;\n        return *this;\n    }\n    value_type operator[](difference_type\
      \ n) const {\n        auto result = *this;\n        result += n;\n        return\
      \ *result;\n    }\n\n    friend _AdjacencyEdgeIterator operator+(_AdjacencyEdgeIterator\
      \ it, difference_type n) {\n        it += n;\n        return it;\n    }\n  \
      \  friend _AdjacencyEdgeIterator operator+(difference_type n, _AdjacencyEdgeIterator\
      \ it) {\n        it += n;\n        return it;\n    }\n    friend _AdjacencyEdgeIterator\
      \ operator-(_AdjacencyEdgeIterator it, difference_type n) {\n        it -= n;\n\
      \        return it;\n    }\n    friend difference_type operator-(const _AdjacencyEdgeIterator\
      \ &lhs,\n                                     const _AdjacencyEdgeIterator &rhs)\
      \ {\n        return lhs.it - rhs.it;\n    }\n    friend bool operator==(const\
      \ _AdjacencyEdgeIterator &lhs, const _AdjacencyEdgeIterator &rhs) {\n      \
      \  return lhs.it == rhs.it;\n    }\n    friend auto operator<=>(const _AdjacencyEdgeIterator\
      \ &lhs, const _AdjacencyEdgeIterator &rhs) {\n        return lhs.it <=> rhs.it;\n\
      \    }\n};\n\ntemplate <class T, bool is_const> class _AdjacencyView {\n   \
      \ using edge_collection = _Edges<T>;\n    using slot_span = std::conditional_t<is_const,\
      \ std::span<const int>, std::span<int>>;\n    using edge_pointer = std::conditional_t<is_const,\
      \ const edge_collection *, edge_collection *>;\n\n  public:\n    using value_type\
      \ = _AdjacencyEdgeProxy<T, is_const>;\n    using const_value_type = _AdjacencyEdgeProxy<T,\
      \ true>;\n    using iterator = _AdjacencyEdgeIterator<T, is_const>;\n    using\
      \ const_iterator = _AdjacencyEdgeIterator<T, true>;\n\n  private:\n    slot_span\
      \ slots;\n    edge_pointer edges;\n    int from;\n\n  public:\n    _AdjacencyView(slot_span\
      \ slots_, edge_pointer edges_, int from_)\n        : slots(slots_),\n      \
      \    edges(edges_),\n          from(from_) {}\n\n    iterator begin() { return\
      \ iterator(slots.begin(), from, edges); }\n    iterator end() { return iterator(slots.end(),\
      \ from, edges); }\n    const_iterator begin() const {\n        return const_iterator(std::span<const\
      \ int>(slots).begin(), from, edges);\n    }\n    const_iterator end() const\
      \ {\n        return const_iterator(std::span<const int>(slots).end(), from,\
      \ edges);\n    }\n    int size() const { return slots.size(); }\n    bool empty()\
      \ const { return slots.empty(); }\n\n    value_type operator[](int i) {\n  \
      \      const int id = slots[i];\n        return value_type(from, slots[i], (*edges)[id]);\n\
      \    }\n    const_value_type operator[](int i) const {\n        const int id\
      \ = slots[i];\n        return const_value_type(from, slots[i], (*edges)[id]);\n\
      \    }\n\n    void swap(int i, int j)\n        requires(!is_const)\n    {\n\
      \        std::swap(slots[i], slots[j]);\n    }\n};\n\n} // namespace kk2::graph\n\
      \n\n#line 1 \"graph/detail/adjacency_storage_common.hpp\"\n\n\n\n#line 5 \"\
      graph/detail/adjacency_storage_common.hpp\"\n\n#line 7 \"graph/detail/adjacency_storage_common.hpp\"\
      \n\nnamespace kk2::graph::detail {\n\ntemplate <class T, bool is_directed>\n\
      std::vector<int> adjacency_degrees(int n, const _Edges<T> &edges) {\n    std::vector<int>\
      \ degree(n);\n    for (const auto &e : edges) {\n        ++degree[e.from];\n\
      \        if constexpr (!is_directed) {\n            if (e.from != e.to) ++degree[e.to];\n\
      \        }\n    }\n    return degree;\n}\n\ntemplate <bool is_directed> void\
      \ count_adjacency_edge(std::vector<int> &head, int from, int to) {\n    ++head[from];\n\
      \    if constexpr (!is_directed) {\n        if (from != to) ++head[to];\n  \
      \  }\n}\n\n} // namespace kk2::graph::detail\n\n\n#line 10 \"graph/detail/compact_adjacency_storage.hpp\"\
      \n\nnamespace kk2::graph::detail {\n\ntemplate <class T, bool is_directed> struct\
      \ CompactAdjacencyStorage {\n    using edge_type = _Edge<T>;\n    using out_edge_type\
      \ = _AdjacencyEdgeProxy<T, false>;\n    using out_edges = std::vector<int>;\n\
      \    using adjacency_container = std::vector<out_edges>;\n\n    adjacency_container\
      \ data;\n\n    CompactAdjacencyStorage() = default;\n    explicit CompactAdjacencyStorage(int\
      \ n) : data(n) {}\n\n    int num_vertices() const { return data.size(); }\n\
      \    std::span<const int> edge_ids(int k) const { return data[k]; }\n    void\
      \ swap_edges(int v, int i, int j) { std::swap(data[v][i], data[v][j]); }\n \
      \   void add_vertex(int n) { data.insert(data.end(), n, out_edges()); }\n\n\
      \    _AdjacencyView<T, false> view(int k, _Edges<T> *edges) {\n        return\
      \ {std::span<int>(data[k]), edges, k};\n    }\n    _AdjacencyView<T, true> view(int\
      \ k, const _Edges<T> *edges) const {\n        return {std::span<const int>(data[k]),\
      \ edges, k};\n    }\n\n    void reset() { data.assign(data.size(), out_edges());\
      \ }\n\n    void reserve(const _Edges<T> &edges) {\n        const auto degree\
      \ = adjacency_degrees<T, is_directed>(num_vertices(), edges);\n        for (int\
      \ i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size() + degree[i]);\n\
      \    }\n\n    void add_edge(int from, int to, T, int id) {\n        data[from].emplace_back(id);\n\
      \        if constexpr (!is_directed) {\n            if (from != to) data[to].emplace_back(id);\n\
      \        }\n    }\n};\n\n} // namespace kk2::graph::detail\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/detail/compact_adjacency_storage.hpp
  pathExtension: hpp
  requiredBy:
  - graph/compact_graph.hpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/graph/graph.test.cpp
documentation_of: graph/detail/compact_adjacency_storage.hpp
layout: document
---
