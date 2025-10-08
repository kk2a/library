---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/static_graph.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <type_traits>\n#include <vector>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
    \ <istream>\n#include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\
    \n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 6 \"graph/edge.hpp\"\n\n#line\
    \ 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\nstruct empty\
    \ {};\n\ntemplate <class T> struct _Edge {\n    int from, to, id;\n    T cost;\n\
    \n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n        : from(from_),\n\
    \          to(to_),\n          id(id_),\n          cost(cost_) {}\n    _Edge()\
    \ : from(-1), to(-1), id(-1) {}\n    operator int() const { return to; }\n   \
    \ inline _Edge rev() const { return _Edge(from, cost, to, id); }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
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
    \ graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line 10 \"graph/static_graph.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace graph {\n\ntemplate <class T, bool is_directed>\
    \ struct StaticAdjacencyList {\n    using value_type = T;\n    using out_edge_type\
    \ = _Edge<T>;\n    using out_edges = _Edges<T>;\n    using adjacency_container\
    \ = _Edges<T>;\n    using edge_type = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\
    \n    static constexpr bool directed = is_directed;\n    static constexpr bool\
    \ weighted = !std::is_same_v<T, empty>;\n    static constexpr bool adjacency_list\
    \ = true;\n    static constexpr bool adjacency_matrix = false;\n    static constexpr\
    \ bool static_graph = true;\n\n    std::vector<int> head;\n    edge_collection\
    \ edges;\n    adjacency_container data;\n    bool is_built = false;\n\n    StaticAdjacencyList()\
    \ = default;\n    StaticAdjacencyList(int n_) : head(n_) {}\n    StaticAdjacencyList(int\
    \ n_, int m_) : head(n_), edges(m_) {}\n    StaticAdjacencyList(int n_, const\
    \ edge_collection &edges_) : head(n_), edges(edges_.size()) {\n        for (auto\
    \ &&e : edges) _add_edge<true>(e.from, e.to, e.cost, e.id);\n        build();\n\
    \    }\n\n    inline int num_vertices() const { return head.size(); }\n    inline\
    \ int size() const { return head.size(); }\n    inline int num_edges() const {\
    \ return edges.size(); }\n    void add_edge(int from, int to, T cost = T{}) {\
    \ _add_edge<false>(from, to, cost, num_edges()); }\n    void add_vertex(int n\
    \ = 1) { head.insert(head.end(), n, 0); }\n    void edge_clear() { *this = StaticAdjacencyList(num_vertices());\
    \ }\n\n    template <class It> struct Es {\n        It b, e;\n        It begin()\
    \ const { return b; }\n        It end() const { return e; }\n        int size()\
    \ const { return int(e - b); }\n        auto &&operator[](int k) const { return\
    \ b[k]; }\n    };\n\n    Es<typename _Edges<T>::iterator> operator[](int k) {\n\
    \        assert(is_built);\n        if (k == (int)head.size() - 1)\n         \
    \   return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};\n\
    \        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin()\
    \ + head[k + 1]};\n    }\n\n    const Es<typename _Edges<T>::const_iterator> operator[](int\
    \ k) const {\n        assert(is_built);\n        if (k == (int)head.size() - 1)\n\
    \            return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k],\
    \ data.end()};\n        return Es<typename _Edges<T>::const_iterator>{data.begin()\
    \ + head[k],\n                                                      data.begin()\
    \ + head[k + 1]};\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    StaticAdjacencyList &input(IStream &is, bool oneindexed =\
    \ false) {\n        for (int i = 0; i < num_edges(); i++) {\n            int u,\
    \ v;\n            T w{};\n            is >> u >> v;\n            if constexpr\
    \ (weighted) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge<true>(u,\
    \ v, w, i);\n        }\n\n        build();\n        return *this;\n    }\n\n \
    \   template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        assert(is_built);\n        os << \"[\\n\";\n        for\
    \ (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" << i << \"\
    : [\";\n            for (int j = 0;\n                 j < (i == num_vertices()\
    \ - 1 ? (int)data.size() : head[i + 1]) - head[i];\n                 j++) {\n\
    \                if (j) os << \", \";\n                data[head[i] + j].debug_output(os);\n\
    \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\n\"\
    ;\n    }\n\n    void build() {\n        is_built = true;\n        for (unsigned\
    \ int i = 1; i < head.size(); ++i) head[i] += head[i - 1];\n        data.resize(head.back());\n\
    \        for (auto &&e : edges) {\n            data[--head[e.from]] = e;\n   \
    \         if constexpr (!is_directed) {\n                if (e.from != e.to) data[--head[e.to]]\
    \ = e.rev();\n            }\n        }\n    }\n\n  private:\n    template <bool\
    \ update = false> void _add_edge(int from, int to, T cost, int id) {\n       \
    \ head[from]++;\n        if (!is_directed and from != to) head[to]++;\n      \
    \  if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);\n        else\
    \ edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n    StaticAdjacencyList\
    \ reverse() const {\n        StaticAdjacencyList res(num_vertices(), num_edges());\n\
    \        for (auto &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n\
    \        res.build();\n        return res;\n    }\n};\n\n} // namespace graph\n\
    \ntemplate <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;\n\
    template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;\n\
    using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;\nusing SDAdjList\
    \ = graph::StaticAdjacencyList<graph::empty, true>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_STATIC_GRAPH_HPP\n#define KK2_GRAPH_STATIC_GRAPH_HPP 1\n\
    \n#include <cassert>\n#include <type_traits>\n#include <vector>\n\n#include \"\
    ../type_traits/io.hpp\"\n#include \"edge.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ graph {\n\ntemplate <class T, bool is_directed> struct StaticAdjacencyList {\n\
    \    using value_type = T;\n    using out_edge_type = _Edge<T>;\n    using out_edges\
    \ = _Edges<T>;\n    using adjacency_container = _Edges<T>;\n    using edge_type\
    \ = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n    static constexpr\
    \ bool directed = is_directed;\n    static constexpr bool weighted = !std::is_same_v<T,\
    \ empty>;\n    static constexpr bool adjacency_list = true;\n    static constexpr\
    \ bool adjacency_matrix = false;\n    static constexpr bool static_graph = true;\n\
    \n    std::vector<int> head;\n    edge_collection edges;\n    adjacency_container\
    \ data;\n    bool is_built = false;\n\n    StaticAdjacencyList() = default;\n\
    \    StaticAdjacencyList(int n_) : head(n_) {}\n    StaticAdjacencyList(int n_,\
    \ int m_) : head(n_), edges(m_) {}\n    StaticAdjacencyList(int n_, const edge_collection\
    \ &edges_) : head(n_), edges(edges_.size()) {\n        for (auto &&e : edges)\
    \ _add_edge<true>(e.from, e.to, e.cost, e.id);\n        build();\n    }\n\n  \
    \  inline int num_vertices() const { return head.size(); }\n    inline int size()\
    \ const { return head.size(); }\n    inline int num_edges() const { return edges.size();\
    \ }\n    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from,\
    \ to, cost, num_edges()); }\n    void add_vertex(int n = 1) { head.insert(head.end(),\
    \ n, 0); }\n    void edge_clear() { *this = StaticAdjacencyList(num_vertices());\
    \ }\n\n    template <class It> struct Es {\n        It b, e;\n        It begin()\
    \ const { return b; }\n        It end() const { return e; }\n        int size()\
    \ const { return int(e - b); }\n        auto &&operator[](int k) const { return\
    \ b[k]; }\n    };\n\n    Es<typename _Edges<T>::iterator> operator[](int k) {\n\
    \        assert(is_built);\n        if (k == (int)head.size() - 1)\n         \
    \   return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};\n\
    \        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin()\
    \ + head[k + 1]};\n    }\n\n    const Es<typename _Edges<T>::const_iterator> operator[](int\
    \ k) const {\n        assert(is_built);\n        if (k == (int)head.size() - 1)\n\
    \            return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k],\
    \ data.end()};\n        return Es<typename _Edges<T>::const_iterator>{data.begin()\
    \ + head[k],\n                                                      data.begin()\
    \ + head[k + 1]};\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    StaticAdjacencyList &input(IStream &is, bool oneindexed =\
    \ false) {\n        for (int i = 0; i < num_edges(); i++) {\n            int u,\
    \ v;\n            T w{};\n            is >> u >> v;\n            if constexpr\
    \ (weighted) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge<true>(u,\
    \ v, w, i);\n        }\n\n        build();\n        return *this;\n    }\n\n \
    \   template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        assert(is_built);\n        os << \"[\\n\";\n        for\
    \ (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" << i << \"\
    : [\";\n            for (int j = 0;\n                 j < (i == num_vertices()\
    \ - 1 ? (int)data.size() : head[i + 1]) - head[i];\n                 j++) {\n\
    \                if (j) os << \", \";\n                data[head[i] + j].debug_output(os);\n\
    \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\n\"\
    ;\n    }\n\n    void build() {\n        is_built = true;\n        for (unsigned\
    \ int i = 1; i < head.size(); ++i) head[i] += head[i - 1];\n        data.resize(head.back());\n\
    \        for (auto &&e : edges) {\n            data[--head[e.from]] = e;\n   \
    \         if constexpr (!is_directed) {\n                if (e.from != e.to) data[--head[e.to]]\
    \ = e.rev();\n            }\n        }\n    }\n\n  private:\n    template <bool\
    \ update = false> void _add_edge(int from, int to, T cost, int id) {\n       \
    \ head[from]++;\n        if (!is_directed and from != to) head[to]++;\n      \
    \  if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);\n        else\
    \ edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n    StaticAdjacencyList\
    \ reverse() const {\n        StaticAdjacencyList res(num_vertices(), num_edges());\n\
    \        for (auto &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n\
    \        res.build();\n        return res;\n    }\n};\n\n} // namespace graph\n\
    \ntemplate <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;\n\
    template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;\n\
    using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;\nusing SDAdjList\
    \ = graph::StaticAdjacencyList<graph::empty, true>;\n\n} // namespace kk2\n\n\
    #endif // KK2_GRAPH_STATIC_GRAPH_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/static_graph.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
documentation_of: graph/static_graph.hpp
layout: document
redirect_from:
- /library/graph/static_graph.hpp
- /library/graph/static_graph.hpp.html
title: graph/static_graph.hpp
---
