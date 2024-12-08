---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_scc.test.cpp
    title: verify/yosupo_graph/graph_scc.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/tree_lca.test.cpp
    title: verify/yosupo_graph/tree_lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\
    #include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct\
    \ _Edge {\n    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int\
    \ from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n    \
    \      id(id_),\n          cost(cost_) {}\n\n    _Edge() : from(-1), to(-1), id(-1),\
    \ cost() {}\n\n    operator int() const { return to; }\n\n    _Edge rev() const\
    \ { return _Edge(from, cost, to, id); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const _Edge &e) {\n\
    \        if constexpr (std::is_same_v<T, empty>) return os << e.from << \" ->\
    \ \" << e.to;\n        else return os << e.from << \" -> \" << e.to << \" : \"\
    \ << e.cost;\n    }\n};\ntemplate <class T> using _Edges = std::vector<_Edge<T>>;\n\
    \ntemplate <class T, bool is_directed> struct AdjacencyList : std::vector<_Edges<T>>\
    \ {\n    using value_type = T;\n    using edge_type = _Edge<T>;\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    AdjacencyList() = default;\n\
    \n    AdjacencyList(int n_) : std::vector<_Edges<T>>(n_) {}\n\n    AdjacencyList(int\
    \ n_, int m_) : std::vector<_Edges<T>>(n_), edges(m_) {}\n\n    AdjacencyList(int\
    \ n_, const _Edges<T> &edges_) : std::vector<_Edges<T>>(n_), edges(edges_) {\n\
    \        for (auto &&e : edges) {\n            (*this)[e.from].emplace_back(e);\n\
    \            if constexpr (!is_directed) (*this)[e.to].emplace_back(e);\n    \
    \    }\n    }\n\n    _Edges<T> edges;\n\n    int num_vertices() const { return\
    \ (int)this->size(); }\n\n    int num_edges() const { return (int)edges.size();\
    \ }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n    AdjacencyList\
    \ &input(IStream &is, bool oneindexed = false) {\n        for (int i = 0; i <\
    \ num_edges(); i++) {\n            int u, v;\n            T w{};\n           \
    \ is >> u >> v;\n            if constexpr (!std::is_same_v<T, empty>) is >> w;\n\
    \            if (oneindexed) --u, --v;\n            _add_edge<true>(u, v, w, i);\n\
    \        }\n        return *this;\n    }\n\n    void edge_clear() {\n        for\
    \ (auto &v : *this) v.clear();\n        edges.clear();\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges());\
    \ }\n\n  private:\n    template <bool update = false>\n    void _add_edge(int\
    \ from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to, cost,\
    \ from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        if constexpr (update) edges[id] = _Edge<T>(to, cost,\
    \ from, id);\n        else edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \ntemplate <class T> struct _pair {\n    T cost;\n    int id;\n\n    _pair(T cost_,\
    \ int id_) : cost(cost_), id(id_) {}\n\n    _pair() : cost(), id(-1) {}\n\n  \
    \  operator bool() const { return id != -1; }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const _pair &p) {\n        if constexpr (std::is_same_v<T, empty>) return os;\n\
    \        else return os << p.cost;\n    }\n};\ntemplate <class T> using _pairs\
    \ = std::vector<_pair<T>>;\n\ntemplate <class T, bool is_directed> struct AdjacencyMatrix\
    \ : std::vector<_pairs<T>> {\n    using value_type = T;\n    using edge_type =\
    \ _pair<T>;\n\n    constexpr static bool directed() { return is_directed; }\n\n\
    \    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int n_) : std::vector<_pairs<T>>(n_,\
    \ _pairs<T>(n_)) {}\n\n    AdjacencyMatrix(int n_, int m_) : std::vector<_pairs<T>>(n_,\
    \ _pairs<T>(n_)), edges(m_) {}\n\n    AdjacencyMatrix(int n_, const _Edges<T>\
    \ &edges_)\n        : std::vector<_pairs<T>>(n_, _pairs<T>(n_)),\n          edges(edges_)\
    \ {\n        for (auto &&e : edges) {\n            (*this)[e.from][e.to] = _pair<T>(e.cost,\
    \ e.id);\n            if constexpr (!is_directed) (*this)[e.to][e.from] = _pair<T>(e.cost,\
    \ e.id);\n        }\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    AdjacencyMatrix &input(IStream &is, bool oneindexed = false)\
    \ {\n        for (int i = 0; i < num_edges(); i++) {\n            int u, v;\n\
    \            T w{};\n            is >> u >> v;\n            if constexpr (!std::is_same_v<T,\
    \ empty>) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge<true>(u,\
    \ v, w, i);\n        }\n        return *this;\n    }\n\n    _Edges<T> edges;\n\
    \n    int num_vertices() const { return (int)this->size(); }\n\n    int num_edges()\
    \ const { return (int)edges.size(); }\n\n    void edge_clear() {\n        for\
    \ (auto &&e : edges) {\n            (*this)[e.from][e.to] = _pair<T>(e.cost, e.id);\n\
    \            if constexpr (!is_directed) (*this)[e.to][e.from] = _pair<T>(e.cost,\
    \ e.id);\n        }\n        edges.clear();\n    }\n\n    void add_edge(int from,\
    \ int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }\n\n\
    \  private:\n    template <bool update = false>\n    void _add_edge(int from,\
    \ int to, T cost, int id) {\n        (*this)[from][to] = _pair<T>(cost, id);\n\
    \        if constexpr (!is_directed) (*this)[to][from] = _pair<T>(cost, id);\n\
    \        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);\n   \
    \     else edges.emplace_back(to, cost, from, id);\n    }\n};\n\ntemplate <class\
    \ G>\nG reverse(const G &g) {\n    G res(g.num_vertices());\n    for (auto &&e\
    \ : g.edges) res.add_edge(e.to, e.from, e.cost);\n    return res;\n}\n\ntemplate\
    \ <class T, class IStream, is_istream_t<IStream> * = nullptr>\n_Edges<T> &input(_Edges<T>\
    \ &edges, bool is_one_indexed, IStream &is) {\n    for (int i = 0; i < (int)edges.size();\
    \ i++) {\n        int u, v;\n        T w{};\n        is >> u >> v;\n        if\
    \ (is_one_indexed) --u, --v;\n        if constexpr (!std::is_same_v<T, empty>)\
    \ is >> w;\n        edges[i] = _Edge<T>(v, w, u, i);\n    }\n    return edges;\n\
    }\n\n} // namespace graph\n\ntemplate <typename T> using WAdjList = graph::AdjacencyList<T,\
    \ false>;\ntemplate <typename T> using DWAdjList = graph::AdjacencyList<T, true>;\n\
    using AdjList = graph::AdjacencyList<graph::empty, false>;\nusing DAdjList = graph::AdjacencyList<graph::empty,\
    \ true>;\n\ntemplate <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;\n\
    template <typename T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;\nusing\
    \ AdjMat = graph::AdjacencyMatrix<graph::empty, false>;\nusing DAdjMat = graph::AdjacencyMatrix<graph::empty,\
    \ true>;\n\ntemplate <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename\
    \ T> using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
    using Edges = graph::_Edges<graph::empty>;\nusing graph::input;\nusing graph::reverse;\n\
    \n} // namespace kk2\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - random/graph.hpp
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
