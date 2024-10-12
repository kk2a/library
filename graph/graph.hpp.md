---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph.hpp\"\n\n\n\n#include <cassert>\n#include <iostream>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace kk2\
    \ {\n\ntemplate <class T> struct Edge {\n    int from, to, id;\n    T cost;\n\n\
    \    Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n        : from(from_),\n\
    \          to(to_),\n          id(id_),\n          cost(cost_) {}\n\n    Edge()\
    \ : from(-1), to(-1), id(-1), cost(0) {}\n\n    operator int() const { return\
    \ to; }\n\n    Edge rev() const { return Edge(from, cost, to, id); }\n\n    template\
    \ <class OStream> friend OStream &operator<<(OStream &os, const Edge &e) {\n \
    \       return os << e.from << \" -> \" << e.to << \" : \" << e.cost;\n    }\n\
    };\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate <class\
    \ T, bool is_directed, bool is_functional>\nstruct AdjacencyList : std::vector<Edges<T>>\
    \ {\n    AdjacencyList() = default;\n\n    AdjacencyList(int n_, bool is_one_indexed)\n\
    \        : std::vector<Edges<T>>(n_),\n          n(n_),\n          m(0),\n   \
    \       oneindexed(is_one_indexed) {}\n\n    AdjacencyList(int n_, int m_, bool\
    \ is_one_indexed)\n        : std::vector<Edges<T>>(n_),\n          n(n_),\n  \
    \        m(m_),\n          oneindexed(is_one_indexed) {}\n\n    AdjacencyList(int\
    \ n_, const Edges<T> &edges_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {\n \
    \       for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }\n   \
    \ }\n\n    template <class IStream> AdjacencyList &input(IStream &is) {\n    \
    \    if constexpr (is_functional) {\n            assert(n == m);\n           \
    \ for (int i = 0; i < n; i++) {\n                int u;\n                is >>\
    \ u;\n                if (oneindexed) --u;\n                _add_edge(i, u, T(),\
    \ i);\n            }\n        } else {\n            for (int i = 0; i < m; i++)\
    \ {\n                int u, v;\n                T w{};\n                is >>\
    \ u >> v;\n                if constexpr (!std::is_same_v<T, bool>) is >> w;\n\
    \                if (oneindexed) --u, --v;\n                _add_edge(u, v, w,\
    \ i);\n            }\n        }\n        return *this;\n    }\n\n    using value_type\
    \ = T;\n    using edge_type = Edge<T>;\n\n    constexpr static bool directed()\
    \ { return is_directed; }\n\n    constexpr static bool functional() { return is_functional;\
    \ }\n\n    int n, m;\n    bool oneindexed;\n    Edges<T> edges;\n\n    int num_vertices()\
    \ const { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    AdjacencyList &inplace_rev() {\n        static_assert(is_directed);\n\
    \        Edges<T> rev(m);\n        for (int i = 0; i < m; i++) rev[i] = edges[i].rev();\n\
    \        edge_clear();\n        for (auto &e : rev) _add_edge(e.from, e.to, e.cost,\
    \ m++);\n        return *this;\n    }\n\n    AdjacencyList rev() const {\n   \
    \     static_assert(is_directed);\n        AdjacencyList res(n);\n        res.m\
    \ = m;\n        for (int i = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from,\
    \ edges[i].cost, i);\n        return res;\n    }\n\n    void add_edge(int from,\
    \ int to, T cost = T()) {\n        if (oneindexed) --from, --to;\n        _add_edge(from,\
    \ to, cost, m++);\n    }\n\n    void add_edge_naive(int from, int to, T cost =\
    \ T()) { _add_edge(from, to, cost, m++); }\n\n  private:\n    void _add_edge(int\
    \ from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to, cost,\
    \ from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \ntemplate <class T, bool is_directed, bool is_functional>\nstruct AdjacencyMatrix\
    \ : std::vector<Edges<T>> {\n    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int\
    \ n_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_, Edges<T>(n_)),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    AdjacencyMatrix(int n_, int m_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_,\
    \ Edges<T>(n_)),\n          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed)\
    \ {}\n\n    AdjacencyMatrix(int n_, const Edges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<Edges<T>>(n_, Edges<T>(n_)),\n          n(n_),\n      \
    \    m(0),\n          oneindexed(is_one_indexed) {\n        for (auto &e : edges_)\
    \ { _add_edge(e.from, e.to, e.cost, m++); }\n    }\n\n    template <class IStream>\
    \ AdjacencyMatrix &input(IStream &is) {\n        if constexpr (is_functional)\
    \ {\n            assert(n == m);\n            for (int i = 0; i < n; i++) {\n\
    \                int u;\n                is >> u;\n                if (oneindexed)\
    \ --u;\n                _add_edge(i, u, T(), i);\n            }\n        } else\
    \ {\n            for (int i = 0; i < m; i++) {\n                int u, v;\n  \
    \              T w{};\n                is >> u >> v;\n                if constexpr\
    \ (!std::is_same_v<T, bool>) is >> w;\n                if (oneindexed) --u, --v;\n\
    \                _add_edge(u, v, w, i);\n            }\n        }\n        return\
    \ *this;\n    }\n\n    using value_type = T;\n    using edge_type = Edge<T>;\n\
    \n    constexpr static bool directed() { return is_directed; }\n\n    constexpr\
    \ static bool functional() { return is_functional; }\n\n    int n, m;\n    bool\
    \ oneindexed;\n    Edges<T> edges;\n\n    int num_vertices() const { return n;\
    \ }\n\n    int num_edges() const { return m; }\n\n    void edge_clear() {\n  \
    \      for (int i = 0; i < n; i++) (*this)[i].clear();\n        m = 0;\n    }\n\
    \n    AdjacencyMatrix &inplace_rev() {\n        static_assert(is_directed);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) { std::swap((*this)[i][j], (*this)[j][i]); }\n        }\n        return\
    \ *this;\n    }\n\n    AdjacencyMatrix rev() const {\n        static_assert(is_directed);\n\
    \        return AdjacencyMatrix(*this).inplace_rev();\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = T()) {\n        if (oneindexed) --from, --to;\n     \
    \   _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost = T()) { _add_edge(from, to, cost, m++); }\n\n  private:\n  \
    \  void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from][to]\
    \ = Edge<T>(to, cost, from, id);\n        if constexpr (!is_directed) (*this)[to][from]\
    \ = Edge<T>(from, cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n\
    \    }\n};\n\ntemplate <typename T> using WAdjList = AdjacencyList<T, false, false>;\n\
    template <typename T> using DWAdjList = AdjacencyList<T, true, false>;\nusing\
    \ AdjList = AdjacencyList<bool, false, false>;\nusing DAdjList = AdjacencyList<bool,\
    \ true, false>;\nusing FAdjList = AdjacencyList<bool, true, true>;\n\ntemplate\
    \ <typename T> using WAdjMat = AdjacencyMatrix<T, false, false>;\ntemplate <typename\
    \ T> using DWAdjMat = AdjacencyMatrix<T, true, false>;\nusing AdjMat = AdjacencyMatrix<bool,\
    \ false, false>;\nusing DAdjMat = AdjacencyMatrix<bool, true, false>;\nusing FAdjMat\
    \ = AdjacencyMatrix<bool, true, true>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\
    #include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> struct Edge {\n   \
    \ int from, to, id;\n    T cost;\n\n    Edge(int to_, T cost_, int from_ = -1,\
    \ int id_ = -1)\n        : from(from_),\n          to(to_),\n          id(id_),\n\
    \          cost(cost_) {}\n\n    Edge() : from(-1), to(-1), id(-1), cost(0) {}\n\
    \n    operator int() const { return to; }\n\n    Edge rev() const { return Edge(from,\
    \ cost, to, id); }\n\n    template <class OStream> friend OStream &operator<<(OStream\
    \ &os, const Edge &e) {\n        return os << e.from << \" -> \" << e.to << \"\
    \ : \" << e.cost;\n    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\
    \ntemplate <class T, bool is_directed, bool is_functional>\nstruct AdjacencyList\
    \ : std::vector<Edges<T>> {\n    AdjacencyList() = default;\n\n    AdjacencyList(int\
    \ n_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_),\n          n(n_),\n\
    \          m(0),\n          oneindexed(is_one_indexed) {}\n\n    AdjacencyList(int\
    \ n_, int m_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_),\n   \
    \       n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\n\
    \    AdjacencyList(int n_, const Edges<T> &edges_, bool is_one_indexed)\n    \
    \    : std::vector<Edges<T>>(n_),\n          n(n_),\n          m(0),\n       \
    \   oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> AdjacencyList &input(IStream\
    \ &is) {\n        if constexpr (is_functional) {\n            assert(n == m);\n\
    \            for (int i = 0; i < n; i++) {\n                int u;\n         \
    \       is >> u;\n                if (oneindexed) --u;\n                _add_edge(i,\
    \ u, T(), i);\n            }\n        } else {\n            for (int i = 0; i\
    \ < m; i++) {\n                int u, v;\n                T w{};\n           \
    \     is >> u >> v;\n                if constexpr (!std::is_same_v<T, bool>) is\
    \ >> w;\n                if (oneindexed) --u, --v;\n                _add_edge(u,\
    \ v, w, i);\n            }\n        }\n        return *this;\n    }\n\n    using\
    \ value_type = T;\n    using edge_type = Edge<T>;\n\n    constexpr static bool\
    \ directed() { return is_directed; }\n\n    constexpr static bool functional()\
    \ { return is_functional; }\n\n    int n, m;\n    bool oneindexed;\n    Edges<T>\
    \ edges;\n\n    int num_vertices() const { return n; }\n\n    int num_edges()\
    \ const { return m; }\n\n    void edge_clear() {\n        for (int i = 0; i <\
    \ n; i++) (*this)[i].clear();\n        edges.clear();\n        m = 0;\n    }\n\
    \n    AdjacencyList &inplace_rev() {\n        static_assert(is_directed);\n  \
    \      Edges<T> rev(m);\n        for (int i = 0; i < m; i++) rev[i] = edges[i].rev();\n\
    \        edge_clear();\n        for (auto &e : rev) _add_edge(e.from, e.to, e.cost,\
    \ m++);\n        return *this;\n    }\n\n    AdjacencyList rev() const {\n   \
    \     static_assert(is_directed);\n        AdjacencyList res(n);\n        res.m\
    \ = m;\n        for (int i = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from,\
    \ edges[i].cost, i);\n        return res;\n    }\n\n    void add_edge(int from,\
    \ int to, T cost = T()) {\n        if (oneindexed) --from, --to;\n        _add_edge(from,\
    \ to, cost, m++);\n    }\n\n    void add_edge_naive(int from, int to, T cost =\
    \ T()) { _add_edge(from, to, cost, m++); }\n\n  private:\n    void _add_edge(int\
    \ from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to, cost,\
    \ from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \ntemplate <class T, bool is_directed, bool is_functional>\nstruct AdjacencyMatrix\
    \ : std::vector<Edges<T>> {\n    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int\
    \ n_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_, Edges<T>(n_)),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    AdjacencyMatrix(int n_, int m_, bool is_one_indexed)\n        : std::vector<Edges<T>>(n_,\
    \ Edges<T>(n_)),\n          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed)\
    \ {}\n\n    AdjacencyMatrix(int n_, const Edges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<Edges<T>>(n_, Edges<T>(n_)),\n          n(n_),\n      \
    \    m(0),\n          oneindexed(is_one_indexed) {\n        for (auto &e : edges_)\
    \ { _add_edge(e.from, e.to, e.cost, m++); }\n    }\n\n    template <class IStream>\
    \ AdjacencyMatrix &input(IStream &is) {\n        if constexpr (is_functional)\
    \ {\n            assert(n == m);\n            for (int i = 0; i < n; i++) {\n\
    \                int u;\n                is >> u;\n                if (oneindexed)\
    \ --u;\n                _add_edge(i, u, T(), i);\n            }\n        } else\
    \ {\n            for (int i = 0; i < m; i++) {\n                int u, v;\n  \
    \              T w{};\n                is >> u >> v;\n                if constexpr\
    \ (!std::is_same_v<T, bool>) is >> w;\n                if (oneindexed) --u, --v;\n\
    \                _add_edge(u, v, w, i);\n            }\n        }\n        return\
    \ *this;\n    }\n\n    using value_type = T;\n    using edge_type = Edge<T>;\n\
    \n    constexpr static bool directed() { return is_directed; }\n\n    constexpr\
    \ static bool functional() { return is_functional; }\n\n    int n, m;\n    bool\
    \ oneindexed;\n    Edges<T> edges;\n\n    int num_vertices() const { return n;\
    \ }\n\n    int num_edges() const { return m; }\n\n    void edge_clear() {\n  \
    \      for (int i = 0; i < n; i++) (*this)[i].clear();\n        m = 0;\n    }\n\
    \n    AdjacencyMatrix &inplace_rev() {\n        static_assert(is_directed);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n;\
    \ j++) { std::swap((*this)[i][j], (*this)[j][i]); }\n        }\n        return\
    \ *this;\n    }\n\n    AdjacencyMatrix rev() const {\n        static_assert(is_directed);\n\
    \        return AdjacencyMatrix(*this).inplace_rev();\n    }\n\n    void add_edge(int\
    \ from, int to, T cost = T()) {\n        if (oneindexed) --from, --to;\n     \
    \   _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost = T()) { _add_edge(from, to, cost, m++); }\n\n  private:\n  \
    \  void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from][to]\
    \ = Edge<T>(to, cost, from, id);\n        if constexpr (!is_directed) (*this)[to][from]\
    \ = Edge<T>(from, cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n\
    \    }\n};\n\ntemplate <typename T> using WAdjList = AdjacencyList<T, false, false>;\n\
    template <typename T> using DWAdjList = AdjacencyList<T, true, false>;\nusing\
    \ AdjList = AdjacencyList<bool, false, false>;\nusing DAdjList = AdjacencyList<bool,\
    \ true, false>;\nusing FAdjList = AdjacencyList<bool, true, true>;\n\ntemplate\
    \ <typename T> using WAdjMat = AdjacencyMatrix<T, false, false>;\ntemplate <typename\
    \ T> using DWAdjMat = AdjacencyMatrix<T, true, false>;\nusing AdjMat = AdjacencyMatrix<bool,\
    \ false, false>;\nusing DAdjMat = AdjacencyMatrix<bool, true, false>;\nusing FAdjMat\
    \ = AdjacencyMatrix<bool, true, true>;\n\n} // namespace kk2\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - random/graph.hpp
  timestamp: '2024-10-13 05:57:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
