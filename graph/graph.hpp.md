---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph.hpp\"\n\n\n\n#include <cassert>\n#include <iostream>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace kk2\
    \ {\n\nnamespace graph {\n\ntemplate <class T> struct _Edge {\n    int from, to,\
    \ id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n\
    \        : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
    \ {}\n\n    _Edge() : from(-1), to(-1), id(-1), cost() {}\n\n    operator int()\
    \ const { return to; }\n\n    _Edge rev() const { return _Edge(from, cost, to,\
    \ id); }\n\n    template <class OStream> friend OStream &operator<<(OStream &os,\
    \ const _Edge &e) {\n        return os << e.from << \" -> \" << e.to << \" : \"\
    \ << e.cost;\n    }\n};\ntemplate <class T> using _Edges = std::vector<_Edge<T>>;\n\
    \nstruct empty {};\n\ntemplate <class T, bool is_directed> struct AdjacencyList\
    \ : std::vector<_Edges<T>> {\n    AdjacencyList() = default;\n\n    AdjacencyList(int\
    \ n_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_),\n          n(n_),\n\
    \          m(0),\n          oneindexed(is_one_indexed) {}\n\n    AdjacencyList(int\
    \ n_, int m_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_),\n  \
    \        n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\n\
    \    AdjacencyList(int n_, const _Edges<T> &edges_, bool is_one_indexed)\n   \
    \     : std::vector<_Edges<T>>(n_),\n          n(n_),\n          m(0),\n     \
    \     oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> AdjacencyList &input(IStream\
    \ &is) {\n        for (int i = 0; i < m; i++) {\n            int u, v;\n     \
    \       T w{};\n            is >> u >> v;\n            if constexpr (!std::is_same_v<T,\
    \ empty>) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge(u,\
    \ v, w, i);\n        }\n        return *this;\n    }\n\n    using value_type =\
    \ T;\n    using edge_type = _Edge<T>;\n\n    constexpr static bool directed()\
    \ { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n    _Edges<T>\
    \ edges;\n\n    int num_vertices() const { return n; }\n\n    int num_edges()\
    \ const { return m; }\n\n    void edge_clear() {\n        for (int i = 0; i <\
    \ n; i++) (*this)[i].clear();\n        edges.clear();\n        m = 0;\n    }\n\
    \n    void add_edge(int from, int to, T cost = T{}) {\n        if (oneindexed)\
    \ --from, --to;\n        _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int\
    \ from, int to, T cost = T{}) { _add_edge(from, to, cost, m++); }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \ntemplate <class T, bool is_directed> struct AdjacencyMatrix : std::vector<_Edges<T>>\
    \ {\n    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int n_, bool is_one_indexed)\n\
    \        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n          n(n_),\n    \
    \      m(0),\n          oneindexed(is_one_indexed) {}\n\n    AdjacencyMatrix(int\
    \ n_, int m_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    AdjacencyMatrix(int n_, const _Edges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n          n(n_),\n    \
    \      m(0),\n          oneindexed(is_one_indexed) {\n        for (auto &e : edges_)\
    \ { _add_edge(e.from, e.to, e.cost, m++); }\n    }\n\n    template <class IStream>\
    \ AdjacencyMatrix &input(IStream &is) {\n        for (int i = 0; i < m; i++) {\n\
    \            int u, v;\n            T w{};\n            is >> u >> v;\n      \
    \      if constexpr (!std::is_same_v<T, empty>) is >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    using value_type = T;\n    using edge_type = _Edge<T>;\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n\
    \    _Edges<T> edges;\n\n    int num_vertices() const { return n; }\n\n    int\
    \ num_edges() const { return m; }\n\n    void edge_clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        m = 0;\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = T{}) {\n        if (oneindexed) --from, --to;\n     \
    \   _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost = T{}) { _add_edge(from, to, cost, m++); }\n\n  private:\n  \
    \  void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from][to]\
    \ = _Edge<T>(to, cost, from, id);\n        if constexpr (!is_directed) (*this)[to][from]\
    \ = _Edge<T>(from, cost, to, id);\n        edges.emplace_back(to, cost, from,\
    \ id);\n    }\n};\n\ntemplate <class T, class IStream>\n_Edges<T> &input(_Edges<T>\
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
    using Edges = graph::_Edges<graph::empty>;\nusing graph::input;\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\
    #include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace graph {\n\ntemplate <class T>\
    \ struct _Edge {\n    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_,\
    \ int from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n\
    \          id(id_),\n          cost(cost_) {}\n\n    _Edge() : from(-1), to(-1),\
    \ id(-1), cost() {}\n\n    operator int() const { return to; }\n\n    _Edge rev()\
    \ const { return _Edge(from, cost, to, id); }\n\n    template <class OStream>\
    \ friend OStream &operator<<(OStream &os, const _Edge &e) {\n        return os\
    \ << e.from << \" -> \" << e.to << \" : \" << e.cost;\n    }\n};\ntemplate <class\
    \ T> using _Edges = std::vector<_Edge<T>>;\n\nstruct empty {};\n\ntemplate <class\
    \ T, bool is_directed> struct AdjacencyList : std::vector<_Edges<T>> {\n    AdjacencyList()\
    \ = default;\n\n    AdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    AdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    AdjacencyList(int n_, const _Edges<T> &edges_, bool is_one_indexed)\n  \
    \      : std::vector<_Edges<T>>(n_),\n          n(n_),\n          m(0),\n    \
    \      oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> AdjacencyList &input(IStream\
    \ &is) {\n        for (int i = 0; i < m; i++) {\n            int u, v;\n     \
    \       T w{};\n            is >> u >> v;\n            if constexpr (!std::is_same_v<T,\
    \ empty>) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge(u,\
    \ v, w, i);\n        }\n        return *this;\n    }\n\n    using value_type =\
    \ T;\n    using edge_type = _Edge<T>;\n\n    constexpr static bool directed()\
    \ { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n    _Edges<T>\
    \ edges;\n\n    int num_vertices() const { return n; }\n\n    int num_edges()\
    \ const { return m; }\n\n    void edge_clear() {\n        for (int i = 0; i <\
    \ n; i++) (*this)[i].clear();\n        edges.clear();\n        m = 0;\n    }\n\
    \n    void add_edge(int from, int to, T cost = T{}) {\n        if (oneindexed)\
    \ --from, --to;\n        _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int\
    \ from, int to, T cost = T{}) { _add_edge(from, to, cost, m++); }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \ntemplate <class T, bool is_directed> struct AdjacencyMatrix : std::vector<_Edges<T>>\
    \ {\n    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int n_, bool is_one_indexed)\n\
    \        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n          n(n_),\n    \
    \      m(0),\n          oneindexed(is_one_indexed) {}\n\n    AdjacencyMatrix(int\
    \ n_, int m_, bool is_one_indexed)\n        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    AdjacencyMatrix(int n_, const _Edges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<_Edges<T>>(n_, _Edges<T>(n_)),\n          n(n_),\n    \
    \      m(0),\n          oneindexed(is_one_indexed) {\n        for (auto &e : edges_)\
    \ { _add_edge(e.from, e.to, e.cost, m++); }\n    }\n\n    template <class IStream>\
    \ AdjacencyMatrix &input(IStream &is) {\n        for (int i = 0; i < m; i++) {\n\
    \            int u, v;\n            T w{};\n            is >> u >> v;\n      \
    \      if constexpr (!std::is_same_v<T, empty>) is >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    using value_type = T;\n    using edge_type = _Edge<T>;\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n\
    \    _Edges<T> edges;\n\n    int num_vertices() const { return n; }\n\n    int\
    \ num_edges() const { return m; }\n\n    void edge_clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        m = 0;\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = T{}) {\n        if (oneindexed) --from, --to;\n     \
    \   _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost = T{}) { _add_edge(from, to, cost, m++); }\n\n  private:\n  \
    \  void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from][to]\
    \ = _Edge<T>(to, cost, from, id);\n        if constexpr (!is_directed) (*this)[to][from]\
    \ = _Edge<T>(from, cost, to, id);\n        edges.emplace_back(to, cost, from,\
    \ id);\n    }\n};\n\ntemplate <class T, class IStream>\n_Edges<T> &input(_Edges<T>\
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
    using Edges = graph::_Edges<graph::empty>;\nusing graph::input;\n\n} // namespace\
    \ kk2\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - random/graph.hpp
  timestamp: '2024-10-13 16:54:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
