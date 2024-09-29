---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':warning:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':warning:'
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
    \n\nnamespace kk2 {\n\ntemplate <class T> struct WeightedEdge {\n    int from,\
    \ to, id;\n    T cost;\n\n    WeightedEdge(int to_, T cost_, int from_ = -1, int\
    \ id_ = -1)\n        : from(from_),\n          to(to_),\n          id(id_),\n\
    \          cost(cost_) {}\n\n    WeightedEdge() : from(-1), to(-1), id(-1), cost(0)\
    \ {}\n\n    operator int() const { return to; }\n\n    WeightedEdge rev() const\
    \ { return WeightedEdge(from, cost, to, id); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const WeightedEdge &e) {\n        if (std::is_same_v<T, bool>) return os\
    \ << e.from << \"->\" << e.to;\n        return os << e.from << \"->\" << e.to\
    \ << \":\" << e.cost;\n    }\n};\ntemplate <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;\n\
    \ntemplate <class T, bool is_directed = false>\nstruct WeightedAdjacencyList :\
    \ std::vector<WeightedEdges<T>> {\n    WeightedAdjacencyList(int n_ = 0, bool\
    \ is_one_indexed = true, bool is_adjacency_matrix = false)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed),\n  \
    \        adjacency_matrix(is_adjacency_matrix) {\n        if (adjacency_matrix)\
    \ this->assign(n, WeightedEdges<T>(n));\n    }\n\n    WeightedAdjacencyList(int\
    \ n_,\n                          int m_,\n                          bool is_one_indexed\
    \ = true,\n                          bool is_adjacency_matrix = false)\n     \
    \   : std::vector<WeightedEdges<T>>(n_),\n          n(n_),\n          m(m_),\n\
    \          oneindexed(is_one_indexed),\n          adjacency_matrix(is_adjacency_matrix)\
    \ {\n        if (adjacency_matrix) this->assign(n, WeightedEdges<T>(n));\n   \
    \     input();\n    }\n\n    WeightedAdjacencyList(int n_,\n                 \
    \         const WeightedEdges<T> &edges_,\n                          bool is_one_indexed\
    \ = true,\n                          bool is_adjacency_matrix = false)\n     \
    \   : std::vector<WeightedEdges<T>>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed),\n          adjacency_matrix(is_adjacency_matrix)\
    \ {\n        if (adjacency_matrix) this->assign(n, WeightedEdges<T>(n));\n   \
    \     for (auto &e : edges_) { _add_edge(e.from, e.to, e.cost, m++); }\n    }\n\
    \n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    int n, m;\n    bool oneindexed,\
    \ adjacency_matrix;\n    WeightedEdges<T> edges;\n\n    int num_vertices() const\
    \ { return n; }\n\n    int num_edges() const { return m; }\n\n    void clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    WeightedAdjacencyList &inplace_rev() {\n       \
    \ static_assert(is_directed);\n        WeightedEdges<T> rev(m);\n        for (int\
    \ i = 0; i < m; i++) { rev[i] = edges[i].rev(); }\n        clear();\n        for\
    \ (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n\
    \    }\n\n    WeightedAdjacencyList rev() const {\n        static_assert(is_directed);\n\
    \        WeightedAdjacencyList res(n);\n        res.m = m;\n        for (int i\
    \ = 0; i < m; i++) { res._add_edge(edges[i].to, edges[i].from, edges[i].cost,\
    \ i); }\n        return res;\n    }\n\n  private:\n    void input() {\n      \
    \  for (int i = 0; i < m; i++) {\n            int u, v;\n            T w;\n  \
    \          std::cin >> u >> v >> w;\n            if (oneindexed) {\n         \
    \       u--;\n                v--;\n            }\n            _add_edge(u, v,\
    \ w, i);\n        }\n    }\n\n  public:\n    void add_edge(int from, int to, T\
    \ cost) {\n        if (oneindexed) {\n            from--;\n            to--;\n\
    \        }\n        _add_edge(from, to, cost, m++);\n    }\n\n    void add_edge_naive(int\
    \ from, int to, T cost) { _add_edge(from, to, cost, m++); }\n\n  private:\n  \
    \  void _add_edge(int from, int to, T cost, int id) {\n        if (adjacency_matrix)\
    \ {\n            (*this)[from][to] = WeightedEdge<T>(to, cost, from, id);\n  \
    \          if constexpr (!is_directed) (*this)[to][from] = WeightedEdge<T>(from,\
    \ cost, to, id);\n        } else {\n            (*this)[from].emplace_back(to,\
    \ cost, from, id);\n            if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ cost, to, id);\n        }\n        edges.emplace_back(to, cost, from, id);\n\
    \    }\n};\n\nstruct UnWeightedEdge {\n    int from, to, id;\n\n    UnWeightedEdge(int\
    \ to_, int from_ = -1, int id_ = -1) : from(from_), to(to_), id(id_) {}\n\n  \
    \  UnWeightedEdge() : from(-1), to(-1), id(-1) {}\n\n    operator int() const\
    \ { return to; }\n\n    UnWeightedEdge rev() const { return UnWeightedEdge(from,\
    \ to, id); }\n\n    friend std::ostream &operator<<(std::ostream &os, const UnWeightedEdge\
    \ &e) {\n        return os << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges\
    \ = std::vector<UnWeightedEdge>;\n\ntemplate <bool is_directed = false, bool is_functional\
    \ = false>\nstruct UnWeightedAdjacencyList : std::vector<UnWeightedEdges> {\n\
    \    UnWeightedAdjacencyList(int n_ = 0,\n                            bool is_one_indexed\
    \ = true,\n                            bool is_adjacency_matrix = false)\n   \
    \     : std::vector<UnWeightedEdges>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed),\n          adjacency_matrix(is_adjacency_matrix)\
    \ {\n        if (adjacency_matrix) this->assign(n, UnWeightedEdges(n));\n    }\n\
    \n    UnWeightedAdjacencyList(int n_,\n                            int m_,\n \
    \                           bool is_one_indexed = true,\n                    \
    \        bool is_adjacency_matrix = false)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed),\n \
    \         adjacency_matrix(is_adjacency_matrix) {\n        if (adjacency_matrix)\
    \ this->assign(n, UnWeightedEdges(n));\n        input();\n    }\n\n    UnWeightedAdjacencyList(int\
    \ n_,\n                            const UnWeightedEdges &edges_,\n          \
    \                  bool is_one_indexed = true,\n                            bool\
    \ is_adjacency_matrix = false)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed),\n  \
    \        adjacency_matrix(is_adjacency_matrix) {\n        if (adjacency_matrix)\
    \ this->assign(n, UnWeightedEdges(n));\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, m++); }\n    }\n\n    constexpr static bool directed() { return is_directed;\
    \ }\n\n    constexpr static bool functional() { return is_functional; }\n\n  \
    \  using edge_type = UnWeightedEdge;\n\n    int n, m;\n    bool oneindexed, adjacency_matrix;\n\
    \    UnWeightedEdges edges;\n\n    int num_vertices() const { return n; }\n\n\
    \    int num_edges() const { return m; }\n\n    void clear() {\n        for (int\
    \ i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n        m =\
    \ 0;\n    }\n\n    UnWeightedAdjacencyList &inplace_rev() {\n        static_assert(is_directed);\n\
    \        std::vector<std::pair<int, int>> rev(m);\n        for (int i = 0; i <\
    \ m; i++) { rev[i] = {edges[i].to, edges[i].from}; }\n        clear();\n     \
    \   for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n        return *this;\n \
    \   }\n\n    UnWeightedAdjacencyList rev() const {\n        static_assert(is_directed);\n\
    \        UnWeightedAdjacencyList res(n);\n        res.m = m;\n        for (int\
    \ i = 0; i < m; i++) { res._add_edge(edges[i].to, edges[i].from, i); }\n     \
    \   return res;\n    }\n\n  private:\n    void input() {\n        if constexpr\
    \ (is_functional) {\n            functional_graph();\n            return;\n  \
    \      }\n        for (int i = 0; i < m; i++) {\n            int u, v;\n     \
    \       std::cin >> u >> v;\n            if (oneindexed) {\n                u--;\n\
    \                v--;\n            }\n            _add_edge(u, v, i);\n      \
    \  }\n    }\n\n    void functional_graph() {\n        static_assert(is_directed);\n\
    \        assert(n == m);\n        for (int i = 0; i < n; i++) {\n            int\
    \ u;\n            std::cin >> u;\n            if (oneindexed) u--;\n         \
    \   _add_edge(i, u, i);\n        }\n    }\n\n  public:\n    void add_edge(int\
    \ from, int to) {\n        if (oneindexed) {\n            from--;\n          \
    \  to--;\n        }\n        _add_edge(from, to, m++);\n    }\n\n    void add_edge_naive(int\
    \ from, int to) { _add_edge(from, to, m++); }\n\n  private:\n    void _add_edge(int\
    \ from, int to, int id) {\n        if (adjacency_matrix) {\n            (*this)[from][to]\
    \ = UnWeightedEdge(to, from, id);\n\n            if constexpr (!is_directed) (*this)[to][from]\
    \ = UnWeightedEdge(from, to, id);\n        } else {\n            (*this)[from].emplace_back(to,\
    \ from, id);\n            if constexpr (!is_directed) (*this)[to].emplace_back(from,\
    \ to, id);\n        }\n        edges.emplace_back(to, from, id);\n    }\n};\n\n\
    \ntemplate <class T, bool is_directed = false> using WAdjList = WeightedAdjacencyList<T,\
    \ is_directed>;\ntemplate <bool is_directed = false, bool is_functional = false>\n\
    using AdjList = UnWeightedAdjacencyList<is_directed, is_functional>;\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n#line 6 \"\
    random/gen.hpp\"\n#include <numeric>\n#include <unordered_set>\n#line 9 \"random/gen.hpp\"\
    \n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\n\
    namespace random {\n\nusing u64 = unsigned long long;\n\nu64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
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
    std::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <=\
    \ r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n  \
    \      i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r -\
    \ i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\ntemplate <class\
    \ Iter> void shuffle(Iter first, Iter last) {\n    if (first == last) return;\n\
    \    int len = 1;\n    for (auto it = first + 1; it != last; ++it) {\n       \
    \ len++;\n        int j = rng(0, len);\n        if (j != len - 1) std::iter_swap(first\
    \ + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T> perm(int n) {\n   \
    \ std::vecotr<T> res(n);\n    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(),\
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
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
redirect_from:
- /library/random/graph.hpp
- /library/random/graph.hpp.html
title: random/graph.hpp
---
