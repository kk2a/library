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
    \ {\n\ntemplate <class T> struct WeightedEdge {\n    int from, to, id;\n    T\
    \ cost;\n\n    WeightedEdge(int to_, T cost_, int from_ = -1, int id_ = -1)\n\
    \        : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
    \ {}\n\n    WeightedEdge() : from(-1), to(-1), id(-1), cost(0) {}\n\n    operator\
    \ int() const { return to; }\n\n    WeightedEdge rev() const { return WeightedEdge(from,\
    \ cost, to, id); }\n\n    template <class OStream> friend OStream &operator<<(OStream\
    \ &os, const WeightedEdge &e) {\n        return os << e.from << \" -> \" << e.to\
    \ << \" : \" << e.cost;\n    }\n};\ntemplate <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;\n\
    \ntemplate <class T, bool is_directed = false>\nstruct WeightedAdjacencyList :\
    \ std::vector<WeightedEdges<T>> {\n    WeightedAdjacencyList() = default;\n\n\
    \    WeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    WeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    WeightedAdjacencyList(int n_, const WeightedEdges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<WeightedEdges<T>>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> WeightedAdjacencyList\
    \ &input(IStream &is) {\n        for (int i = 0; i < m; i++) {\n            int\
    \ u, v;\n            T w;\n            is >> u >> v >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n\n\
    \    constexpr static bool directed() { return is_directed; }\n\n    int n, m;\n\
    \    bool oneindexed;\n    WeightedEdges<T> edges;\n\n    int num_vertices() const\
    \ { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    WeightedAdjacencyList &inplace_rev() {\n       \
    \ static_assert(is_directed);\n        WeightedEdges<T> rev(m);\n        for (int\
    \ i = 0; i < m; i++) rev[i] = edges[i].rev();\n        edge_clear();\n       \
    \ for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n\
    \    }\n\n    WeightedAdjacencyList rev() const {\n        static_assert(is_directed);\n\
    \        WeightedAdjacencyList res(n);\n        res.m = m;\n        for (int i\
    \ = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);\n\
    \        return res;\n    }\n\n    void add_edge(int from, int to, T cost) {\n\
    \        if (oneindexed) --from, --to;\n        _add_edge(from, to, cost, m++);\n\
    \    }\n\n    void add_edge_naive(int from, int to, T cost) { _add_edge(from,\
    \ to, cost, m++); }\n\n  private:\n    void _add_edge(int from, int to, T cost,\
    \ int id) {\n        (*this)[from].emplace_back(to, cost, from, id);\n       \
    \ if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);\n\
    \        edges.emplace_back(to, cost, from, id);\n    }\n};\n\nstruct UnWeightedEdge\
    \ {\n    int from, to, id;\n\n    UnWeightedEdge(int to_, int from_ = -1, int\
    \ id_ = -1) : from(from_), to(to_), id(id_) {}\n\n    UnWeightedEdge() : from(-1),\
    \ to(-1), id(-1) {}\n\n    operator int() const { return to; }\n\n    UnWeightedEdge\
    \ rev() const { return UnWeightedEdge(from, to, id); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const UnWeightedEdge &e) {\n        return os\
    \ << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges = std::vector<UnWeightedEdge>;\n\
    \ntemplate <bool is_directed = false, bool is_functional = false>\nstruct UnWeightedAdjacencyList\
    \ : std::vector<UnWeightedEdges> {\n    UnWeightedAdjacencyList() = default;\n\
    \n    UnWeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    UnWeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    UnWeightedAdjacencyList(int n_, const UnWeightedEdges &edges_, bool is_one_indexed)\n\
    \        : std::vector<UnWeightedEdges>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, m++); }\n    }\n\n    template <class IStream> UnWeightedAdjacencyList\
    \ &input(IStream &is) {\n        if constexpr (is_functional) {\n            assert(n\
    \ == m);\n            for (int i = 0; i < n; i++) {\n                int u;\n\
    \                is >> u;\n                if (oneindexed) --u;\n            \
    \    _add_edge(i, u, i);\n            }\n        } else {\n            for (int\
    \ i = 0; i < m; i++) {\n                int u, v;\n                is >> u >>\
    \ v;\n                if (oneindexed) --u, --v;\n                _add_edge(u,\
    \ v, i);\n            }\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    constexpr static bool\
    \ functional() { return is_functional; }\n\n    using edge_type = UnWeightedEdge;\n\
    \n    int n, m;\n    bool oneindexed;\n    UnWeightedEdges edges;\n\n    int num_vertices()\
    \ const { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    UnWeightedAdjacencyList &inplace_rev() {\n     \
    \   static_assert(is_directed);\n        std::vector<std::pair<int, int>> rev(m);\n\
    \        for (int i = 0; i < m; i++) rev[i] = {edges[i].to, edges[i].from};\n\
    \        edge_clear();\n        for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n\
    \        return *this;\n    }\n\n    UnWeightedAdjacencyList rev() const {\n \
    \       static_assert(is_directed);\n        UnWeightedAdjacencyList res(n);\n\
    \        res.m = m;\n        for (int i = 0; i < m; i++) res._add_edge(edges[i].to,\
    \ edges[i].from, i);\n        return res;\n    }\n\n    void add_edge(int from,\
    \ int to) {\n        if (oneindexed) --from, --to;\n        _add_edge(from, to,\
    \ m++);\n    }\n\n    void add_edge_naive(int from, int to) { _add_edge(from,\
    \ to, m++); }\n\n  private:\n    void _add_edge(int from, int to, int id) {\n\
    \        (*this)[from].emplace_back(to, from, id);\n        if constexpr (!is_directed)\
    \ (*this)[to].emplace_back(from, to, id);\n        edges.emplace_back(to, from,\
    \ id);\n    }\n};\n\ntemplate <typename T> using WAdjList = WeightedAdjacencyList<T,\
    \ false>;\ntemplate <typename T> using DWAdjList = WeightedAdjacencyList<T, true>;\n\
    \nusing AdjList = UnWeightedAdjacencyList<false, false>;\nusing DAdjList = UnWeightedAdjacencyList<true,\
    \ false>;\nusing FAdjList = UnWeightedAdjacencyList<true, true>;\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\
    #include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> struct WeightedEdge\
    \ {\n    int from, to, id;\n    T cost;\n\n    WeightedEdge(int to_, T cost_,\
    \ int from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n\
    \          id(id_),\n          cost(cost_) {}\n\n    WeightedEdge() : from(-1),\
    \ to(-1), id(-1), cost(0) {}\n\n    operator int() const { return to; }\n\n  \
    \  WeightedEdge rev() const { return WeightedEdge(from, cost, to, id); }\n\n \
    \   template <class OStream> friend OStream &operator<<(OStream &os, const WeightedEdge\
    \ &e) {\n        return os << e.from << \" -> \" << e.to << \" : \" << e.cost;\n\
    \    }\n};\ntemplate <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;\n\
    \ntemplate <class T, bool is_directed = false>\nstruct WeightedAdjacencyList :\
    \ std::vector<WeightedEdges<T>> {\n    WeightedAdjacencyList() = default;\n\n\
    \    WeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    WeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    WeightedAdjacencyList(int n_, const WeightedEdges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<WeightedEdges<T>>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> WeightedAdjacencyList\
    \ &input(IStream &is) {\n        for (int i = 0; i < m; i++) {\n            int\
    \ u, v;\n            T w;\n            is >> u >> v >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n\n\
    \    constexpr static bool directed() { return is_directed; }\n\n    int n, m;\n\
    \    bool oneindexed;\n    WeightedEdges<T> edges;\n\n    int num_vertices() const\
    \ { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    WeightedAdjacencyList &inplace_rev() {\n       \
    \ static_assert(is_directed);\n        WeightedEdges<T> rev(m);\n        for (int\
    \ i = 0; i < m; i++) rev[i] = edges[i].rev();\n        edge_clear();\n       \
    \ for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n\
    \    }\n\n    WeightedAdjacencyList rev() const {\n        static_assert(is_directed);\n\
    \        WeightedAdjacencyList res(n);\n        res.m = m;\n        for (int i\
    \ = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);\n\
    \        return res;\n    }\n\n    void add_edge(int from, int to, T cost) {\n\
    \        if (oneindexed) --from, --to;\n        _add_edge(from, to, cost, m++);\n\
    \    }\n\n    void add_edge_naive(int from, int to, T cost) { _add_edge(from,\
    \ to, cost, m++); }\n\n  private:\n    void _add_edge(int from, int to, T cost,\
    \ int id) {\n        (*this)[from].emplace_back(to, cost, from, id);\n       \
    \ if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);\n\
    \        edges.emplace_back(to, cost, from, id);\n    }\n};\n\nstruct UnWeightedEdge\
    \ {\n    int from, to, id;\n\n    UnWeightedEdge(int to_, int from_ = -1, int\
    \ id_ = -1) : from(from_), to(to_), id(id_) {}\n\n    UnWeightedEdge() : from(-1),\
    \ to(-1), id(-1) {}\n\n    operator int() const { return to; }\n\n    UnWeightedEdge\
    \ rev() const { return UnWeightedEdge(from, to, id); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const UnWeightedEdge &e) {\n        return os\
    \ << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges = std::vector<UnWeightedEdge>;\n\
    \ntemplate <bool is_directed = false, bool is_functional = false>\nstruct UnWeightedAdjacencyList\
    \ : std::vector<UnWeightedEdges> {\n    UnWeightedAdjacencyList() = default;\n\
    \n    UnWeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    UnWeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    UnWeightedAdjacencyList(int n_, const UnWeightedEdges &edges_, bool is_one_indexed)\n\
    \        : std::vector<UnWeightedEdges>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, m++); }\n    }\n\n    template <class IStream> UnWeightedAdjacencyList\
    \ &input(IStream &is) {\n        if constexpr (is_functional) {\n            assert(n\
    \ == m);\n            for (int i = 0; i < n; i++) {\n                int u;\n\
    \                is >> u;\n                if (oneindexed) --u;\n            \
    \    _add_edge(i, u, i);\n            }\n        } else {\n            for (int\
    \ i = 0; i < m; i++) {\n                int u, v;\n                is >> u >>\
    \ v;\n                if (oneindexed) --u, --v;\n                _add_edge(u,\
    \ v, i);\n            }\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    constexpr static bool\
    \ functional() { return is_functional; }\n\n    using edge_type = UnWeightedEdge;\n\
    \n    int n, m;\n    bool oneindexed;\n    UnWeightedEdges edges;\n\n    int num_vertices()\
    \ const { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    UnWeightedAdjacencyList &inplace_rev() {\n     \
    \   static_assert(is_directed);\n        std::vector<std::pair<int, int>> rev(m);\n\
    \        for (int i = 0; i < m; i++) rev[i] = {edges[i].to, edges[i].from};\n\
    \        edge_clear();\n        for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n\
    \        return *this;\n    }\n\n    UnWeightedAdjacencyList rev() const {\n \
    \       static_assert(is_directed);\n        UnWeightedAdjacencyList res(n);\n\
    \        res.m = m;\n        for (int i = 0; i < m; i++) res._add_edge(edges[i].to,\
    \ edges[i].from, i);\n        return res;\n    }\n\n    void add_edge(int from,\
    \ int to) {\n        if (oneindexed) --from, --to;\n        _add_edge(from, to,\
    \ m++);\n    }\n\n    void add_edge_naive(int from, int to) { _add_edge(from,\
    \ to, m++); }\n\n  private:\n    void _add_edge(int from, int to, int id) {\n\
    \        (*this)[from].emplace_back(to, from, id);\n        if constexpr (!is_directed)\
    \ (*this)[to].emplace_back(from, to, id);\n        edges.emplace_back(to, from,\
    \ id);\n    }\n};\n\ntemplate <typename T> using WAdjList = WeightedAdjacencyList<T,\
    \ false>;\ntemplate <typename T> using DWAdjList = WeightedAdjacencyList<T, true>;\n\
    \nusing AdjList = UnWeightedAdjacencyList<false, false>;\nusing DAdjList = UnWeightedAdjacencyList<true,\
    \ false>;\nusing FAdjList = UnWeightedAdjacencyList<true, true>;\n\n} // namespace\
    \ kk2\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - random/graph.hpp
  timestamp: '2024-10-08 15:38:16+09:00'
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
