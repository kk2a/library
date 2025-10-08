---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/graph.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <vector>\n\n#line 1 \"graph/graph.hpp\"\n\n\n\n#include <cassert>\n#line 6 \"\
    graph/graph.hpp\"\n#include <utility>\n#line 8 \"graph/graph.hpp\"\n\n#line 1\
    \ \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n#line\
    \ 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
    \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate\
    \ <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
    \ graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line 11 \"graph/graph.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace graph {\n\ntemplate <class T, bool is_directed>\
    \ struct AdjacencyList {\n    using value_type = T;\n    using out_edge_type =\
    \ _Edge<T>;\n    using out_edges = _Edges<T>;\n    using adjacency_container =\
    \ std::vector<out_edges>;\n    using edge_type = _Edge<T>;\n    using edge_collection\
    \ = _Edges<T>;\n\n    static constexpr bool directed = is_directed;\n    static\
    \ constexpr bool weighted = !std::is_same_v<T, empty>;\n    static constexpr bool\
    \ adjacency_list = true;\n    static constexpr bool adjacency_matrix = false;\n\
    \    static constexpr bool static_graph = false;\n\n    adjacency_container data;\n\
    \    edge_collection edges;\n\n    AdjacencyList() = default;\n    AdjacencyList(int\
    \ n_) : data(n_) {}\n    // input \u3092\u4F7F\u3046\u3053\u3068\u304C\u524D\u63D0\
    \n    AdjacencyList(int n_, int m_) : data(n_), edges(m_) {}\n    AdjacencyList(int\
    \ n_, const edge_collection &edges_) : data(n_), edges(edges_.size()) {\n    \
    \    for (auto &&e : edges_) _add_edge<true>(e.from, e.to, e.cost, e.id);\n  \
    \  }\n\n    inline int num_vertices() const { return data.size(); }\n    inline\
    \ int size() const { return data.size(); }\n    inline int num_edges() const {\
    \ return edges.size(); }\n    out_edges &operator[](int k) { return data[k]; }\n\
    \    const out_edges &operator[](int k) const { return data[k]; }\n    void edge_clear()\
    \ { *this = AdjacencyList(num_vertices()); }\n    void add_edge(int from, int\
    \ to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }\n    void\
    \ add_vertex(int n = 1) { data.insert(data.end(), n, out_edges()); }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    AdjacencyList &input(IStream\
    \ &is, bool oneindexed = false) {\n        for (int i = 0; i < num_edges(); i++)\
    \ {\n            int u, v;\n            T w{};\n            is >> u >> v;\n  \
    \          if constexpr (weighted) is >> w;\n            if (oneindexed) --u,\
    \ --v;\n            _add_edge<true>(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n  \
    \  void debug_output(OStream &os) const {\n        os << \"[\\n\";\n        for\
    \ (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" << i << \"\
    : [\";\n            for (size_t j = 0; j < data[i].size(); j++) {\n          \
    \      if (j) os << \", \";\n                data[i][j].debug_output(os);\n  \
    \          }\n            os << \"]\\n\";\n        }\n        os << \"]\\n\";\n\
    \    }\n\n  private:\n    template <bool update = false> void _add_edge(int from,\
    \ int to, T cost, int id) {\n        data[from].emplace_back(to, cost, from, id);\n\
    \        if (!is_directed and from != to) data[to].emplace_back(from, cost, to,\
    \ id);\n        if constexpr (update) edges[id] = edge_type(to, cost, from, id);\n\
    \        else edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n  \
    \  AdjacencyList reverse() const {\n        AdjacencyList res(num_vertices(),\
    \ num_edges());\n        for (auto &&e : edges) res._add_edge<true>(e.to, e.from,\
    \ e.cost, e.id);\n        return res;\n    }\n};\n\ntemplate <class T, bool is_directed>\
    \ struct AdjacencyMatrix {\n    using value_type = T;\n    using out_edge_type\
    \ = _pair<T>;\n    using out_edges = _pairs<T>;\n    using adjacency_container\
    \ = std::vector<out_edges>;\n    using edge_type = _Edge<T>;\n    using edge_collection\
    \ = _Edges<T>;\n\n    static constexpr bool directed = is_directed;\n    static\
    \ constexpr bool weighted = !std::is_same_v<T, empty>;\n    static constexpr bool\
    \ adjacency_list = false;\n    static constexpr bool adjacency_matrix = true;\n\
    \    static constexpr bool static_graph = false;\n\n    adjacency_container data;\n\
    \    edge_collection edges;\n\n    AdjacencyMatrix() = default;\n    AdjacencyMatrix(int\
    \ n_) : data(n_, out_edges(n_)) {}\n    // input \u3092\u4F7F\u3046\u3053\u3068\
    \u304C\u524D\u63D0\n    AdjacencyMatrix(int n_, int m_) : data(n_, out_edges(n_)),\
    \ edges(m_) {}\n    AdjacencyMatrix(int n_, const edge_collection &edges_)\n \
    \       : data(n_, out_edges(n_)),\n          edges(edges_.size()) {\n       \
    \ for (auto &&e : edges_) _add_edge<true>(e.from, e.to, e.cost, e.id);\n    }\n\
    \n    inline int num_vertices() const { return data.size(); }\n    inline int\
    \ size() const { return data.size(); }\n    inline int num_edges() const { return\
    \ edges.size(); }\n    out_edges &operator[](int k) { return data[k]; }\n    const\
    \ out_edges &operator[](int k) const { return data[k]; }\n    void edge_clear()\
    \ { *this = AdjacencyMatrix(num_vertices()); }\n    void add_edge(int from, int\
    \ to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges()); }\n    void\
    \ add_vertex(int n = 1) {\n        int now = num_vertices();\n        data.resize(now\
    \ + n);\n        for (auto &&d : data) d.resize(now + n);\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    AdjacencyMatrix &input(IStream\
    \ &is, bool oneindexed = false) {\n        for (int i = 0; i < num_edges(); i++)\
    \ {\n            int u, v;\n            T w{};\n            is >> u >> v;\n  \
    \          if constexpr (weighted) is >> w;\n            if (oneindexed) --u,\
    \ --v;\n            _add_edge<true>(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n  \
    \  void debug_output(OStream &os) const {\n        os << \"[\\n\";\n        for\
    \ (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" << i << \"\
    : [\";\n            for (size_t j = 0; j < data[i].size(); j++) {\n          \
    \      if (j) os << \", \";\n                os << \"(\" << data[i][j].id << \"\
    , \" << i << \"->\" << j;\n                if constexpr (weighted) os << \": \"\
    \ << data[i][j].cost;\n                os << \")\";\n            }\n         \
    \   os << \"]\\n\";\n        }\n        os << \"]\\n\";\n    }\n\n  private:\n\
    \    template <bool update = false> void _add_edge(int from, int to, T cost, int\
    \ id) {\n        data[from][to] = out_edge_type(cost, id);\n        if constexpr\
    \ (!is_directed) data[to][from] = out_edge_type(cost, id);\n        if constexpr\
    \ (update) edges[id] = edge_type(to, cost, from, id);\n        else edges.emplace_back(to,\
    \ cost, from, id);\n    }\n\n  public:\n    AdjacencyMatrix reverse() const {\n\
    \        AdjacencyMatrix res(num_vertices(), num_edges());\n        for (auto\
    \ &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n        return\
    \ res;\n    }\n};\n\n} // namespace graph\n\ntemplate <typename T> using WAdjList\
    \ = graph::AdjacencyList<T, false>;\ntemplate <typename T> using DWAdjList = graph::AdjacencyList<T,\
    \ true>;\nusing AdjList = graph::AdjacencyList<graph::empty, false>;\nusing DAdjList\
    \ = graph::AdjacencyList<graph::empty, true>;\n\ntemplate <typename T> using WAdjMat\
    \ = graph::AdjacencyMatrix<T, false>;\ntemplate <typename T> using DWAdjMat =\
    \ graph::AdjacencyMatrix<T, true>;\nusing AdjMat = graph::AdjacencyMatrix<graph::empty,\
    \ false>;\nusing DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"random/gen.hpp\"\n#include <numeric>\n#include <random>\n#include <unordered_set>\n\
    #line 10 \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\
    \nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\n\
    inline u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
    \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
    \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
    }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
    \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
    \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T>\
    \ random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64>\
    \ distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n   \
    \ std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n        i64 m =\
    \ rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r - i;\n       \
    \ st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first,\
    \ Iter last) {\n    if (first == last) return;\n    int len = 1;\n    for (auto\
    \ it = first + 1; it != last; ++it) {\n        len++;\n        int j = rng(0,\
    \ len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\n\
    template <class T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int l, int r,\
    \ int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r - l);\n\
    \    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(), res.end());\n\
    \    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\n} // namespace\
    \ kk2\n\n\n#line 9 \"random/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace random\
    \ {\n\ntemplate <bool is_weighted, bool is_directed, class T = int> using adjlist\
    \ =\n    std::conditional<is_weighted, WAdjList<T, is_directed>, AdjList<is_directed>>;\n\
    \ntemplate <bool is_weighted, bool is_directed, class T = int>\nvoid add_edge(adjlist<is_weighted,\
    \ is_directed, T> &g, int from, int to, T l = 0, T r = 1e9) {\n    if constexpr\
    \ (is_weighted) {\n        T w = rng(l, r);\n        g.add_edge(from, to, w);\n\
    \    } else {\n        g.add_edge(from, to);\n    }\n}\n\ntemplate <bool is_weighted,\
    \ bool is_directed, class T = int>\nadjlist<is_weighted, is_directed, T> Graph(int\
    \ n, int m, T l = 0, T r = 1e9) {\n    adjlist<is_weighted, is_directed, T> g(n,\
    \ false);\n    for (int i = 0; i < m; i++) {\n        int u = rng(0, n), v = rng(0,\
    \ n);\n        add_edge<is_weighted, is_directed, T>(g, u, v, l, r);\n    }\n\
    \    return g;\n}\n\ntemplate <bool is_weighted, class T = int>\nadjlist<is_weighted,\
    \ false, T> Tree(int n, T l = 0, T r = 1e9) {\n    adjlist<is_weighted, false,\
    \ T> g(n, false);\n    std::vector<int> p = perm<int>(n);\n    for (int i = 1;\
    \ i < n; i++) {\n        int u = rng(0, i), v = i;\n        add_edge<is_weighted,\
    \ false, T>(g, p[u], p[v], l, r);\n    }\n    return g;\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_RANDOM_GRAPH_HPP\n#define KK2_RANDOM_GRAPH_HPP 1\n\n#include\
    \ <type_traits>\n#include <vector>\n\n#include \"../graph/graph.hpp\"\n#include\
    \ \"gen.hpp\"\n\nnamespace kk2 {\n\nnamespace random {\n\ntemplate <bool is_weighted,\
    \ bool is_directed, class T = int> using adjlist =\n    std::conditional<is_weighted,\
    \ WAdjList<T, is_directed>, AdjList<is_directed>>;\n\ntemplate <bool is_weighted,\
    \ bool is_directed, class T = int>\nvoid add_edge(adjlist<is_weighted, is_directed,\
    \ T> &g, int from, int to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted)\
    \ {\n        T w = rng(l, r);\n        g.add_edge(from, to, w);\n    } else {\n\
    \        g.add_edge(from, to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed,\
    \ class T = int>\nadjlist<is_weighted, is_directed, T> Graph(int n, int m, T l\
    \ = 0, T r = 1e9) {\n    adjlist<is_weighted, is_directed, T> g(n, false);\n \
    \   for (int i = 0; i < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n\
    \        add_edge<is_weighted, is_directed, T>(g, u, v, l, r);\n    }\n    return\
    \ g;\n}\n\ntemplate <bool is_weighted, class T = int>\nadjlist<is_weighted, false,\
    \ T> Tree(int n, T l = 0, T r = 1e9) {\n    adjlist<is_weighted, false, T> g(n,\
    \ false);\n    std::vector<int> p = perm<int>(n);\n    for (int i = 1; i < n;\
    \ i++) {\n        int u = rng(0, i), v = i;\n        add_edge<is_weighted, false,\
    \ T>(g, p[u], p[v], l, r);\n    }\n    return g;\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n#endif // KK2_RANDOM_GRAPH_HPP\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/io.hpp
  - graph/edge.hpp
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: random/graph.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
redirect_from:
- /library/random/graph.hpp
- /library/random/graph.hpp.html
title: random/graph.hpp
---
