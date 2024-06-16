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
  bundledCode: "#line 1 \"graph/graph_template.hpp\"\n\n\n\n\ntemplate <class T>\n\
    struct Edge {\n    int from, to, id;\n    T cost;\n\n    Edge(int to_, T cost_,\
    \ int from_ = -1, int id_ = -1) :\n        from(from_), to(to_), id(id_), cost(cost_)\
    \ {}\n\n    Edge& operator=(const int &x) {\n        to = x;\n        return *this;\n\
    \    }\n\n    operator int() const { return to; }\n};\ntemplate <class T>\nusing\
    \ Edges = vector<Edge<T>>;\n\ntemplate <class T>\nstruct WeightedGraph : vector<Edges<T>>\
    \ {\n    WeightedGraph(int n_ = 0) : vector<Edges<T>>(n_), n(n_) {}\n    WeightedGraph(int\
    \ n_, int m_, bool is_one_indexed_ = true,\n                  bool is_directed_\
    \ = false) :\n                  vector<Edges<T>>(n_), n(n_), m(m_),\n        \
    \          is_one_indexed(is_one_indexed_),\n                  is_directed(is_directed_)\
    \ {\n        edges.reserve(m);\n        input();\n    }\n    WeightedGraph(int\
    \ n_, vector<Edges<T>> g_,\n                  bool is_one_indexed_ = true,\n \
    \                 bool is_directed_ = false) :\n                  vector<Edges<T>>(n_),\
    \ n(n_), m(0),\n                  is_one_indexed(is_one_indexed_),\n         \
    \         is_directed(is_directed_) {\n        for (int i = 0; i < n; i++) {\n\
    \            for (auto &e : g_[i]) {\n                _add_edge(i, e.to, e.cost,\
    \ m++);\n            }\n        }\n    }\n\n    int n, m;\n    Edges<T> edges;\n\
    \    bool is_one_indexed, is_directed;\n\n    void one_indexed() { is_one_indexed\
    \ = true; }\n    void zero_indexed() { is_one_indexed = false; }\n    void directed()\
    \ { is_directed = true; }\n    void undirected() { is_directed = false; }\n\n\
    \    int num_vertices() const { return n; }\n    int num_edges() const { return\
    \ m; }\n\n    void input() {\n        for (int i = 0; i < m; i++) {\n        \
    \    int u, v;\n            T w;\n            cin >> u >> v >> w;\n          \
    \  if (is_one_indexed) { u--; v--; }\n            _add_edge(u, v, w, i);\n   \
    \     }\n    }\n\n    void add_edge(int from, int to, T cost) {\n        if (is_one_indexed)\
    \ { from--; to--; }\n        _add_edge(from, to, cost, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if (!is_directed) (*this)[to].emplace_back(from, cost,\
    \ to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\ntemplate\
    \ <class T>\nusing WGraph = WeightedGraph<T>;\n\nstruct UnWeightedGraph : vector<Edges<bool>>\
    \ {\n    UnWeightedGraph(int n_ = 0) :\n                    vector<Edges<bool>>(n_),\
    \ n(n_), m(0),\n                    is_one_indexed(true),\n                  \
    \  is_directed(false),\n                    is_functional(false) {}\n\n    UnWeightedGraph(int\
    \ n_, int m_, bool is_one_indexed_ = true,\n                    bool is_directed_\
    \ = false,\n                    bool is_functional_ = false) :\n             \
    \       vector<Edges<bool>>(n_), n(n_), m(m_),\n                    is_one_indexed(is_one_indexed_),\n\
    \                    is_directed(is_directed_),\n                    is_functional(is_functional_)\
    \ {\n        input();\n    }\n\n    UnWeightedGraph(int n_, vector<Edges<bool>>\
    \ g_,\n                    bool is_one_indexed_ = true,\n                    bool\
    \ is_directed_ = false,\n                    bool is_functional_ = false) :\n\
    \                    vector<Edges<bool>>(n_), n(n_), m(0),\n                 \
    \   is_one_indexed(is_one_indexed_),\n                    is_directed(is_directed_),\n\
    \                    is_functional(is_functional_) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (auto &e : g_[i]) {\n                _add_edge(i,\
    \ e.to, m++);\n            }\n        }\n    }\n\n    int n, m;\n    Edges<bool>\
    \ edges;\n    bool is_one_indexed, is_directed, is_functional;\n\n    void one_indexed()\
    \ { is_one_indexed = true; }\n    void zero_indexed() { is_one_indexed = false;\
    \ }\n    void directed() { is_directed = true; }\n    void undirected() { is_directed\
    \ = false; }\n    void functional() { is_functional = true; }\n    void non_functional()\
    \ { is_functional = false; }\n\n    int num_vertices() const { return n; }\n \
    \   int num_edges() const { return m; }\n\n    // void clear() {\n    //     for\
    \ (int i = 0; i < n; i++) (*this)[i].clear();\n    //     edges.clear();\n   \
    \ //     m = 0;\n    // }\n\n    // void inplace_rev() {\n    //     assert(is_directed);\n\
    \    //     vector<vector<int>> rev(n);\n    //     for (int i = 0; i < n; i++)\
    \ {\n    //         for (auto &e : (*this)[i]) {\n    //             rev[e.to].emplace_back(i);\n\
    \    //         }\n    //     }\n    //     clear();\n    //     for (int i =\
    \ 0; i < n; i++) {\n    //         for (auto &to : rev[i]) {\n    //         \
    \    _add_edge(i, to, m++);\n    //         }\n    //     }\n    // }\n\n    //\
    \ UnWeightedGraph rev() {\n    //     UnWeightedGraph res(n);\n    //     res.is_directed\
    \ = is_directed;\n    //     res.is_one_indexed = is_one_indexed;\n    //    \
    \ res.is_functional = is_functional;\n\n    //     for (int i = 0; i < n; i++)\
    \ {\n    //         for (auto &e : (*this)[i]) {\n    //             res._add_edge(e.to,\
    \ i, e.id);\n    //         }\n    //     }\n    //     return res;\n    // }\n\
    \n  private:\n    void input() {\n        if (is_functional) { functional_graph();\
    \ return; }\n        for (int i = 0; i < m; i++) {\n            int u, v;\n  \
    \          cin >> u >> v;\n            if (is_one_indexed) { u--; v--; }\n   \
    \         _add_edge(u, v, i);\n        }\n    }\n\n    void functional_graph()\
    \ {\n        assert(is_directed);\n        assert(n == m);\n        for (int i\
    \ = 0; i < n; i++) {\n            int u;\n            cin >> u;\n            if\
    \ (is_one_indexed) u--;\n            _add_edge(i, u, m++);\n        }\n    }\n\
    \n  public:\n    void add_edge(int from, int to) {\n        if (is_one_indexed)\
    \ { from--; to--; }\n        _add_edge(from, to, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, int id) {\n        (*this)[from].emplace_back(to,\
    \ 0, from, id);\n        if (!is_directed) (*this)[to].emplace_back(from, 0, to,\
    \ id);\n        edges.emplace_back(to, 0, from, id);\n    }\n};\nusing Graph =\
    \ UnWeightedGraph;\n\n\n\n"
  code: "#ifndef GRAPH_GRAPH_TEMPLATE_HPP\n#define GRAPH_GRAPH_TEMPLATE_HPP 1\n\n\n\
    template <class T>\nstruct Edge {\n    int from, to, id;\n    T cost;\n\n    Edge(int\
    \ to_, T cost_, int from_ = -1, int id_ = -1) :\n        from(from_), to(to_),\
    \ id(id_), cost(cost_) {}\n\n    Edge& operator=(const int &x) {\n        to =\
    \ x;\n        return *this;\n    }\n\n    operator int() const { return to; }\n\
    };\ntemplate <class T>\nusing Edges = vector<Edge<T>>;\n\ntemplate <class T>\n\
    struct WeightedGraph : vector<Edges<T>> {\n    WeightedGraph(int n_ = 0) : vector<Edges<T>>(n_),\
    \ n(n_) {}\n    WeightedGraph(int n_, int m_, bool is_one_indexed_ = true,\n \
    \                 bool is_directed_ = false) :\n                  vector<Edges<T>>(n_),\
    \ n(n_), m(m_),\n                  is_one_indexed(is_one_indexed_),\n        \
    \          is_directed(is_directed_) {\n        edges.reserve(m);\n        input();\n\
    \    }\n    WeightedGraph(int n_, vector<Edges<T>> g_,\n                  bool\
    \ is_one_indexed_ = true,\n                  bool is_directed_ = false) :\n  \
    \                vector<Edges<T>>(n_), n(n_), m(0),\n                  is_one_indexed(is_one_indexed_),\n\
    \                  is_directed(is_directed_) {\n        for (int i = 0; i < n;\
    \ i++) {\n            for (auto &e : g_[i]) {\n                _add_edge(i, e.to,\
    \ e.cost, m++);\n            }\n        }\n    }\n\n    int n, m;\n    Edges<T>\
    \ edges;\n    bool is_one_indexed, is_directed;\n\n    void one_indexed() { is_one_indexed\
    \ = true; }\n    void zero_indexed() { is_one_indexed = false; }\n    void directed()\
    \ { is_directed = true; }\n    void undirected() { is_directed = false; }\n\n\
    \    int num_vertices() const { return n; }\n    int num_edges() const { return\
    \ m; }\n\n    void input() {\n        for (int i = 0; i < m; i++) {\n        \
    \    int u, v;\n            T w;\n            cin >> u >> v >> w;\n          \
    \  if (is_one_indexed) { u--; v--; }\n            _add_edge(u, v, w, i);\n   \
    \     }\n    }\n\n    void add_edge(int from, int to, T cost) {\n        if (is_one_indexed)\
    \ { from--; to--; }\n        _add_edge(from, to, cost, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, T cost, int id) {\n        (*this)[from].emplace_back(to,\
    \ cost, from, id);\n        if (!is_directed) (*this)[to].emplace_back(from, cost,\
    \ to, id);\n        edges.emplace_back(to, cost, from, id);\n    }\n};\ntemplate\
    \ <class T>\nusing WGraph = WeightedGraph<T>;\n\nstruct UnWeightedGraph : vector<Edges<bool>>\
    \ {\n    UnWeightedGraph(int n_ = 0) :\n                    vector<Edges<bool>>(n_),\
    \ n(n_), m(0),\n                    is_one_indexed(true),\n                  \
    \  is_directed(false),\n                    is_functional(false) {}\n\n    UnWeightedGraph(int\
    \ n_, int m_, bool is_one_indexed_ = true,\n                    bool is_directed_\
    \ = false,\n                    bool is_functional_ = false) :\n             \
    \       vector<Edges<bool>>(n_), n(n_), m(m_),\n                    is_one_indexed(is_one_indexed_),\n\
    \                    is_directed(is_directed_),\n                    is_functional(is_functional_)\
    \ {\n        input();\n    }\n\n    UnWeightedGraph(int n_, vector<Edges<bool>>\
    \ g_,\n                    bool is_one_indexed_ = true,\n                    bool\
    \ is_directed_ = false,\n                    bool is_functional_ = false) :\n\
    \                    vector<Edges<bool>>(n_), n(n_), m(0),\n                 \
    \   is_one_indexed(is_one_indexed_),\n                    is_directed(is_directed_),\n\
    \                    is_functional(is_functional_) {\n        for (int i = 0;\
    \ i < n; i++) {\n            for (auto &e : g_[i]) {\n                _add_edge(i,\
    \ e.to, m++);\n            }\n        }\n    }\n\n    int n, m;\n    Edges<bool>\
    \ edges;\n    bool is_one_indexed, is_directed, is_functional;\n\n    void one_indexed()\
    \ { is_one_indexed = true; }\n    void zero_indexed() { is_one_indexed = false;\
    \ }\n    void directed() { is_directed = true; }\n    void undirected() { is_directed\
    \ = false; }\n    void functional() { is_functional = true; }\n    void non_functional()\
    \ { is_functional = false; }\n\n    int num_vertices() const { return n; }\n \
    \   int num_edges() const { return m; }\n\n    // void clear() {\n    //     for\
    \ (int i = 0; i < n; i++) (*this)[i].clear();\n    //     edges.clear();\n   \
    \ //     m = 0;\n    // }\n\n    // void inplace_rev() {\n    //     assert(is_directed);\n\
    \    //     vector<vector<int>> rev(n);\n    //     for (int i = 0; i < n; i++)\
    \ {\n    //         for (auto &e : (*this)[i]) {\n    //             rev[e.to].emplace_back(i);\n\
    \    //         }\n    //     }\n    //     clear();\n    //     for (int i =\
    \ 0; i < n; i++) {\n    //         for (auto &to : rev[i]) {\n    //         \
    \    _add_edge(i, to, m++);\n    //         }\n    //     }\n    // }\n\n    //\
    \ UnWeightedGraph rev() {\n    //     UnWeightedGraph res(n);\n    //     res.is_directed\
    \ = is_directed;\n    //     res.is_one_indexed = is_one_indexed;\n    //    \
    \ res.is_functional = is_functional;\n\n    //     for (int i = 0; i < n; i++)\
    \ {\n    //         for (auto &e : (*this)[i]) {\n    //             res._add_edge(e.to,\
    \ i, e.id);\n    //         }\n    //     }\n    //     return res;\n    // }\n\
    \n  private:\n    void input() {\n        if (is_functional) { functional_graph();\
    \ return; }\n        for (int i = 0; i < m; i++) {\n            int u, v;\n  \
    \          cin >> u >> v;\n            if (is_one_indexed) { u--; v--; }\n   \
    \         _add_edge(u, v, i);\n        }\n    }\n\n    void functional_graph()\
    \ {\n        assert(is_directed);\n        assert(n == m);\n        for (int i\
    \ = 0; i < n; i++) {\n            int u;\n            cin >> u;\n            if\
    \ (is_one_indexed) u--;\n            _add_edge(i, u, m++);\n        }\n    }\n\
    \n  public:\n    void add_edge(int from, int to) {\n        if (is_one_indexed)\
    \ { from--; to--; }\n        _add_edge(from, to, m++);\n    }\n\n  private:\n\
    \    void _add_edge(int from, int to, int id) {\n        (*this)[from].emplace_back(to,\
    \ 0, from, id);\n        if (!is_directed) (*this)[to].emplace_back(from, 0, to,\
    \ id);\n        edges.emplace_back(to, 0, from, id);\n    }\n};\nusing Graph =\
    \ UnWeightedGraph;\n\n\n#endif // GRAPH_GRAPH_TEMPLATE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_template.hpp
  requiredBy: []
  timestamp: '2024-06-16 14:35:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_template.hpp
layout: document
redirect_from:
- /library/graph/graph_template.hpp
- /library/graph/graph_template.hpp.html
title: graph/graph_template.hpp
---
