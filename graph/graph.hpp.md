---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate <class\
    \ T>\nstruct WeightedEdge {\n    int from, to, id;\n    T cost;\n\n    WeightedEdge(int\
    \ to_, T cost_, int from_ = -1, int id_ = -1) :\n        from(from_), to(to_),\
    \ id(id_), cost(cost_) {}\n\n    WeightedEdge() : from(-1), to(-1), id(-1), cost(0)\
    \ {}\n\n    operator int() const { return to; }\n\n    WeightedEdge rev() const\
    \ { return WeightedEdge(from, cost, to, id); }\n\n    friend ostream& operator<<(ostream\
    \ &os, const WeightedEdge &e) {\n        if (is_same_v<T, bool>) return os <<\
    \ e.from << \"->\" << e.to;\n        return os << e.from << \"->\" << e.to <<\
    \ \":\" << e.cost;\n    }\n};\ntemplate <class T>\nusing WeightedEdges = vector<WeightedEdge<T>>;\n\
    \ntemplate <class T, bool is_directed = false>\nstruct WeightedGraph : vector<WeightedEdges<T>>\
    \ {\n    WeightedGraph(\n        int n_ = 0,\n        bool is_one_indexed = true\n\
    \    ) :\n        vector<WeightedEdges<T>>(n_),\n        n(n_),\n        m(0),\n\
    \        oneindexed(is_one_indexed) {}\n\n    WeightedGraph(\n        int n_,\n\
    \        int m_,\n        bool is_one_indexed = true\n    ) :\n        vector<WeightedEdges<T>>(n_),\n\
    \        n(n_),\n        m(m_),\n        oneindexed(is_one_indexed) {\n      \
    \  input();\n    }\n\n    WeightedGraph(\n        int n_,\n        const vector<WeightedEdges<T>>&\
    \ g_,\n        bool is_one_indexed = true\n    ) :\n        vector<WeightedEdges<T>>(n_),\n\
    \        n(n_), \n        m(0),\n        oneindexed(is_one_indexed) {\n      \
    \  for (int i = 0; i < n; i++) {\n            for (auto &e : g_[i]) {\n      \
    \          _add_edge(i, e.to, e.cost, m++);\n            }\n        }\n    }\n\
    \n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n\
    \    WeightedEdges<T> edges;\n\n    int num_vertices() const { return n; }\n \
    \   int num_edges() const { return m; }\n\n    void clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n        m =\
    \ 0;\n    }\n\n    WeightedGraph& inplace_rev() {\n        static_assert(is_directed);\n\
    \        WeightedEdges<T> rev(m);\n        for (int i = 0; i < m; i++) {\n   \
    \         rev[i] = edges[i].rev();\n        }\n        clear();\n        for (auto\
    \ &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n   \
    \ }\n\n    WeightedGraph rev() const {\n        static_assert(is_directed);\n\
    \        WeightedGraph res(n);\n        res.m = m;\n        for (int i = 0; i\
    \ < m; i++) {\n            res._add_edge(edges[i].to, edges[i].from, edges[i].cost,\
    \ i);\n        }\n        return res;\n    }\n\n  private:\n    void input() {\n\
    \        for (int i = 0; i < m; i++) {\n            int u, v;\n            T w;\n\
    \            cin >> u >> v >> w;\n            if (oneindexed) { u--; v--; }\n\
    \            _add_edge(u, v, w, i);\n        }\n    }\n\n  public:\n    void add_edge(int\
    \ from, int to, T cost) {\n        if (oneindexed) { from--; to--; }\n       \
    \ _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost) {\n        _add_edge(from, to, cost, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \nstruct UnWeightedEdge {\n    int from, to, id;\n\n    UnWeightedEdge(int to_,\
    \ int from_ = -1, int id_ = -1) :\n        from(from_), to(to_), id(id_) {}\n\n\
    \    UnWeightedEdge() : from(-1), to(-1), id(-1) {}\n\n    operator int() const\
    \ { return to; }\n\n    UnWeightedEdge rev() const { return UnWeightedEdge(from,\
    \ to, id); }\n\n    friend ostream& operator<<(ostream &os, const UnWeightedEdge\
    \ &e) {\n        return os << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges\
    \ = vector<UnWeightedEdge>;\n\ntemplate <bool is_directed = false,\n         \
    \ bool is_functional = false>\nstruct UnWeightedGraph : vector<UnWeightedEdges>\
    \ {\n    UnWeightedGraph(\n        int n_ = 0,\n        bool is_one_indexed =\
    \ true\n    ) :\n        vector<UnWeightedEdges>(n_),\n        n(n_),\n      \
    \  m(0),\n        oneindexed(is_one_indexed) {}\n\n    UnWeightedGraph(\n    \
    \    int n_,\n        int m_,\n        bool is_one_indexed = true\n    ) :\n \
    \       vector<UnWeightedEdges>(n_),\n        n(n_),\n        m(m_),\n       \
    \ oneindexed(is_one_indexed) {\n        input(); \n    }\n\n    UnWeightedGraph(\n\
    \        int n_,\n        const vector<UnWeightedEdges>& g_,\n        bool is_one_indexed\
    \ = true\n    ) :\n        vector<UnWeightedEdges>(n_),\n        n(n_),\n    \
    \    m(0),\n        oneindexed(is_one_indexed) {\n        for (int i = 0; i <\
    \ n; i++) {\n            for (auto &e : g_[i]) {\n                _add_edge(i,\
    \ e.to, m++);\n            }\n        }\n    }\n\n    constexpr static bool directed()\
    \ { return is_directed; }\n    constexpr static bool functional() { return is_functional;\
    \ }\n\n    using edge_type = UnWeightedEdge;\n\n    int n, m;\n    bool oneindexed;\n\
    \    UnWeightedEdges edges;\n\n    int num_vertices() const { return n; }\n  \
    \  int num_edges() const { return m; }\n\n    void clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n        m =\
    \ 0;\n    }\n\n    UnWeightedGraph& inplace_rev() {\n        static_assert(is_directed);\n\
    \        vector<pair<int, int>> rev(m);\n        for (int i = 0; i < m; i++) {\n\
    \            rev[i] = {edges[i].to, edges[i].from};\n        }\n        clear();\n\
    \        for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n        return *this;\n\
    \    }\n\n    UnWeightedGraph rev() const {\n        static_assert(is_directed);\n\
    \        UnWeightedGraph res(n);\n        res.m = m;\n        for (int i = 0;\
    \ i < m; i++) {\n            res._add_edge(edges[i].to, edges[i].from, i);\n \
    \       }\n        return res;\n    }\n\n  private:\n    void input() {\n    \
    \    if constexpr (is_functional) { functional_graph(); return; }\n        for\
    \ (int i = 0; i < m; i++) {\n            int u, v;\n            cin >> u >> v;\n\
    \            if (oneindexed) { u--; v--; }\n            _add_edge(u, v, i);\n\
    \        }\n    }\n\n    void functional_graph() {\n        static_assert(is_directed);\n\
    \        assert(n == m);\n        for (int i = 0; i < n; i++) {\n            int\
    \ u;\n            cin >> u;\n            if (oneindexed) u--;\n            _add_edge(i,\
    \ u, i);\n        }\n    }\n\n  public:\n    void add_edge(int from, int to) {\n\
    \        if (oneindexed) { from--; to--; }\n        _add_edge(from, to, m++);\n\
    \    }\n\n    void add_edge_naive(int from, int to) {\n        _add_edge(from,\
    \ to, m++);\n    }\n\n  private:\n    void _add_edge(int from, int to, int id)\
    \ {\n        (*this)[from].emplace_back(to, from, id);\n        if constexpr (!is_directed)\
    \ (*this)[to].emplace_back(from, to, id);\n        edges.emplace_back(to, from,\
    \ id);\n    }\n};\n\n\ntemplate <class T, bool is_directed = false>\nusing WGraph\
    \ = WeightedGraph<T, is_directed>;\ntemplate <bool is_directed = false,\n    \
    \      bool is_functional = false>\nusing Graph = UnWeightedGraph<is_directed,\
    \ is_functional>;\n\n}  // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\
    namespace kk2 {\n\ntemplate <class T>\nstruct WeightedEdge {\n    int from, to,\
    \ id;\n    T cost;\n\n    WeightedEdge(int to_, T cost_, int from_ = -1, int id_\
    \ = -1) :\n        from(from_), to(to_), id(id_), cost(cost_) {}\n\n    WeightedEdge()\
    \ : from(-1), to(-1), id(-1), cost(0) {}\n\n    operator int() const { return\
    \ to; }\n\n    WeightedEdge rev() const { return WeightedEdge(from, cost, to,\
    \ id); }\n\n    friend ostream& operator<<(ostream &os, const WeightedEdge &e)\
    \ {\n        if (is_same_v<T, bool>) return os << e.from << \"->\" << e.to;\n\
    \        return os << e.from << \"->\" << e.to << \":\" << e.cost;\n    }\n};\n\
    template <class T>\nusing WeightedEdges = vector<WeightedEdge<T>>;\n\ntemplate\
    \ <class T, bool is_directed = false>\nstruct WeightedGraph : vector<WeightedEdges<T>>\
    \ {\n    WeightedGraph(\n        int n_ = 0,\n        bool is_one_indexed = true\n\
    \    ) :\n        vector<WeightedEdges<T>>(n_),\n        n(n_),\n        m(0),\n\
    \        oneindexed(is_one_indexed) {}\n\n    WeightedGraph(\n        int n_,\n\
    \        int m_,\n        bool is_one_indexed = true\n    ) :\n        vector<WeightedEdges<T>>(n_),\n\
    \        n(n_),\n        m(m_),\n        oneindexed(is_one_indexed) {\n      \
    \  input();\n    }\n\n    WeightedGraph(\n        int n_,\n        const vector<WeightedEdges<T>>&\
    \ g_,\n        bool is_one_indexed = true\n    ) :\n        vector<WeightedEdges<T>>(n_),\n\
    \        n(n_), \n        m(0),\n        oneindexed(is_one_indexed) {\n      \
    \  for (int i = 0; i < n; i++) {\n            for (auto &e : g_[i]) {\n      \
    \          _add_edge(i, e.to, e.cost, m++);\n            }\n        }\n    }\n\
    \n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    int n, m;\n    bool oneindexed;\n\
    \    WeightedEdges<T> edges;\n\n    int num_vertices() const { return n; }\n \
    \   int num_edges() const { return m; }\n\n    void clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n        m =\
    \ 0;\n    }\n\n    WeightedGraph& inplace_rev() {\n        static_assert(is_directed);\n\
    \        WeightedEdges<T> rev(m);\n        for (int i = 0; i < m; i++) {\n   \
    \         rev[i] = edges[i].rev();\n        }\n        clear();\n        for (auto\
    \ &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n   \
    \ }\n\n    WeightedGraph rev() const {\n        static_assert(is_directed);\n\
    \        WeightedGraph res(n);\n        res.m = m;\n        for (int i = 0; i\
    \ < m; i++) {\n            res._add_edge(edges[i].to, edges[i].from, edges[i].cost,\
    \ i);\n        }\n        return res;\n    }\n\n  private:\n    void input() {\n\
    \        for (int i = 0; i < m; i++) {\n            int u, v;\n            T w;\n\
    \            cin >> u >> v >> w;\n            if (oneindexed) { u--; v--; }\n\
    \            _add_edge(u, v, w, i);\n        }\n    }\n\n  public:\n    void add_edge(int\
    \ from, int to, T cost) {\n        if (oneindexed) { from--; to--; }\n       \
    \ _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int from,\
    \ int to, T cost) {\n        _add_edge(from, to, cost, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\n\
    \nstruct UnWeightedEdge {\n    int from, to, id;\n\n    UnWeightedEdge(int to_,\
    \ int from_ = -1, int id_ = -1) :\n        from(from_), to(to_), id(id_) {}\n\n\
    \    UnWeightedEdge() : from(-1), to(-1), id(-1) {}\n\n    operator int() const\
    \ { return to; }\n\n    UnWeightedEdge rev() const { return UnWeightedEdge(from,\
    \ to, id); }\n\n    friend ostream& operator<<(ostream &os, const UnWeightedEdge\
    \ &e) {\n        return os << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges\
    \ = vector<UnWeightedEdge>;\n\ntemplate <bool is_directed = false,\n         \
    \ bool is_functional = false>\nstruct UnWeightedGraph : vector<UnWeightedEdges>\
    \ {\n    UnWeightedGraph(\n        int n_ = 0,\n        bool is_one_indexed =\
    \ true\n    ) :\n        vector<UnWeightedEdges>(n_),\n        n(n_),\n      \
    \  m(0),\n        oneindexed(is_one_indexed) {}\n\n    UnWeightedGraph(\n    \
    \    int n_,\n        int m_,\n        bool is_one_indexed = true\n    ) :\n \
    \       vector<UnWeightedEdges>(n_),\n        n(n_),\n        m(m_),\n       \
    \ oneindexed(is_one_indexed) {\n        input(); \n    }\n\n    UnWeightedGraph(\n\
    \        int n_,\n        const vector<UnWeightedEdges>& g_,\n        bool is_one_indexed\
    \ = true\n    ) :\n        vector<UnWeightedEdges>(n_),\n        n(n_),\n    \
    \    m(0),\n        oneindexed(is_one_indexed) {\n        for (int i = 0; i <\
    \ n; i++) {\n            for (auto &e : g_[i]) {\n                _add_edge(i,\
    \ e.to, m++);\n            }\n        }\n    }\n\n    constexpr static bool directed()\
    \ { return is_directed; }\n    constexpr static bool functional() { return is_functional;\
    \ }\n\n    using edge_type = UnWeightedEdge;\n\n    int n, m;\n    bool oneindexed;\n\
    \    UnWeightedEdges edges;\n\n    int num_vertices() const { return n; }\n  \
    \  int num_edges() const { return m; }\n\n    void clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n        m =\
    \ 0;\n    }\n\n    UnWeightedGraph& inplace_rev() {\n        static_assert(is_directed);\n\
    \        vector<pair<int, int>> rev(m);\n        for (int i = 0; i < m; i++) {\n\
    \            rev[i] = {edges[i].to, edges[i].from};\n        }\n        clear();\n\
    \        for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n        return *this;\n\
    \    }\n\n    UnWeightedGraph rev() const {\n        static_assert(is_directed);\n\
    \        UnWeightedGraph res(n);\n        res.m = m;\n        for (int i = 0;\
    \ i < m; i++) {\n            res._add_edge(edges[i].to, edges[i].from, i);\n \
    \       }\n        return res;\n    }\n\n  private:\n    void input() {\n    \
    \    if constexpr (is_functional) { functional_graph(); return; }\n        for\
    \ (int i = 0; i < m; i++) {\n            int u, v;\n            cin >> u >> v;\n\
    \            if (oneindexed) { u--; v--; }\n            _add_edge(u, v, i);\n\
    \        }\n    }\n\n    void functional_graph() {\n        static_assert(is_directed);\n\
    \        assert(n == m);\n        for (int i = 0; i < n; i++) {\n            int\
    \ u;\n            cin >> u;\n            if (oneindexed) u--;\n            _add_edge(i,\
    \ u, i);\n        }\n    }\n\n  public:\n    void add_edge(int from, int to) {\n\
    \        if (oneindexed) { from--; to--; }\n        _add_edge(from, to, m++);\n\
    \    }\n\n    void add_edge_naive(int from, int to) {\n        _add_edge(from,\
    \ to, m++);\n    }\n\n  private:\n    void _add_edge(int from, int to, int id)\
    \ {\n        (*this)[from].emplace_back(to, from, id);\n        if constexpr (!is_directed)\
    \ (*this)[to].emplace_back(from, to, id);\n        edges.emplace_back(to, from,\
    \ id);\n    }\n};\n\n\ntemplate <class T, bool is_directed = false>\nusing WGraph\
    \ = WeightedGraph<T, is_directed>;\ntemplate <bool is_directed = false,\n    \
    \      bool is_functional = false>\nusing Graph = UnWeightedGraph<is_directed,\
    \ is_functional>;\n\n}  // namespace kk2\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy: []
  timestamp: '2024-09-06 13:55:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---