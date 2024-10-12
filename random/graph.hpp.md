---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/graph.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n\n#line 1 \"graph/graph.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <iostream>\n#line 7 \"graph/graph.hpp\"\n#include <utility>\n#line 9 \"graph/graph.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T> struct Edge {\n    int from, to, id;\n\
    \    T cost;\n\n    Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n   \
    \     : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
    \ {}\n\n    Edge() : from(-1), to(-1), id(-1), cost(0) {}\n\n    operator int()\
    \ const { return to; }\n\n    Edge rev() const { return Edge(from, cost, to, id);\
    \ }\n\n    template <class OStream> friend OStream &operator<<(OStream &os, const\
    \ Edge &e) {\n        return os << e.from << \" -> \" << e.to << \" : \" << e.cost;\n\
    \    }\n};\ntemplate <class T> using Edges = std::vector<Edge<T>>;\n\ntemplate\
    \ <class T, bool is_directed, bool is_functional>\nstruct AdjacencyList : std::vector<Edges<T>>\
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
    \ = AdjacencyMatrix<bool, true, true>;\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"random/gen.hpp\"\n#include <numeric>\n\
    #include <unordered_set>\n#line 9 \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\nnamespace random {\n\nusing u64\
    \ = unsigned long long;\n\nu64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 11 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\nu64 xorshift128plus(u64 &x, u64 &y) {\n    u64 t =\
    \ x;\n    t ^= t << 23;\n    t ^= t >> 17;\n    t ^= y ^ (y >> 26);\n    x = y;\n\
    \    y = t;\n    return x + y;\n}\n\nconstexpr int iterations = 100;\n\nvoid warm_up(u64\
    \ &x, u64 &y) {\n    for (int i = 0; i < iterations; i++) xorshift128plus(x, y);\n\
    }\n\nu64 rng() {\n    static bool first = true;\n    static u64 x = seed(), y\
    \ = seed();\n    if (first) {\n        warm_up(x, y);\n        first = false;\n\
    \    }\n    return xorshift128plus(x, y);\n}\n\n// [l, r)\ni64 rng(i64 l, i64\
    \ r) {\n    assert(l < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\n\
    template <class T>\nstd::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T>\
    \ res(n);\n    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n\
    }\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
    \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n; i;\
    \ --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
    \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
    \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
    \ <class Iter> void shuffle(Iter first, Iter last) {\n    if (first == last) return;\n\
    \    int len = 1;\n    for (auto it = first + 1; it != last; ++it) {\n       \
    \ len++;\n        int j = rng(0, len);\n        if (j != len - 1) std::iter_swap(first\
    \ + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T> perm(int n) {\n   \
    \ std::vector<T> res(n);\n    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int\
    \ l, int r, int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r\
    \ - l);\n    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(),\
    \ res.end());\n    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n\n#line 9 \"random/graph.hpp\"\n\nnamespace kk2 {\n\n\
    namespace random {\n\ntemplate <bool is_weighted, bool is_directed, class T =\
    \ int>\nusing adjlist = std::conditional<is_weighted, WAdjList<T, is_directed>,\
    \ AdjList<is_directed>>;\n\ntemplate <bool is_weighted, bool is_directed, class\
    \ T = int>\nvoid add_edge(adjlist<is_weighted, is_directed, T> &g, int from, int\
    \ to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted) {\n        T w = rng(l,\
    \ r);\n        g.add_edge(from, to, w);\n    } else {\n        g.add_edge(from,\
    \ to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed, class T = int>\n\
    adjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T r = 1e9) {\n\
    \    adjlist<is_weighted, is_directed, T> g(n, false);\n    for (int i = 0; i\
    \ < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n        add_edge<is_weighted,\
    \ is_directed, T>(g, u, v, l, r);\n    }\n    return g;\n}\n\ntemplate <bool is_weighted,\
    \ class T = int>\nadjlist<is_weighted, false, T> Tree(int n, T l = 0, T r = 1e9)\
    \ {\n    adjlist<is_weighted, false, T> g(n, false);\n    std::vector<int> p =\
    \ perm<int>(n);\n    for (int i = 1; i < n; i++) {\n        int u = rng(0, i),\
    \ v = i;\n        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);\n    }\n\
    \    return g;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n"
  code: "#ifndef RANDOM_GRAPH_HPP\n#define RANDOM_GRAPH_HPP 1\n\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../graph/graph.hpp\"\n#include \"gen.hpp\"\n\n\
    namespace kk2 {\n\nnamespace random {\n\ntemplate <bool is_weighted, bool is_directed,\
    \ class T = int>\nusing adjlist = std::conditional<is_weighted, WAdjList<T, is_directed>,\
    \ AdjList<is_directed>>;\n\ntemplate <bool is_weighted, bool is_directed, class\
    \ T = int>\nvoid add_edge(adjlist<is_weighted, is_directed, T> &g, int from, int\
    \ to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted) {\n        T w = rng(l,\
    \ r);\n        g.add_edge(from, to, w);\n    } else {\n        g.add_edge(from,\
    \ to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed, class T = int>\n\
    adjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T r = 1e9) {\n\
    \    adjlist<is_weighted, is_directed, T> g(n, false);\n    for (int i = 0; i\
    \ < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n        add_edge<is_weighted,\
    \ is_directed, T>(g, u, v, l, r);\n    }\n    return g;\n}\n\ntemplate <bool is_weighted,\
    \ class T = int>\nadjlist<is_weighted, false, T> Tree(int n, T l = 0, T r = 1e9)\
    \ {\n    adjlist<is_weighted, false, T> g(n, false);\n    std::vector<int> p =\
    \ perm<int>(n);\n    for (int i = 1; i < n; i++) {\n        int u = rng(0, i),\
    \ v = i;\n        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);\n    }\n\
    \    return g;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n#endif //\
    \ RANDOM_GRAPH_HPP\n"
  dependsOn:
  - graph/graph.hpp
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: random/graph.hpp
  requiredBy: []
  timestamp: '2024-10-13 05:57:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
redirect_from:
- /library/random/graph.hpp
- /library/random/graph.hpp.html
title: random/graph.hpp
---
