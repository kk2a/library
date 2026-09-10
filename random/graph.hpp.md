---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: adjacency_list_base.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/adjacency_list_base.hpp
    - filename: adjacency_storage_common.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/adjacency_storage_common.hpp
    - filename: direct_adjacency_storage.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/direct_adjacency_storage.hpp
    - filename: graph_base.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/graph_base.hpp
    - filename: edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/edge.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: graph/graph.hpp
    - filename: gen.hpp
      icon: LIBRARY_ALL_AC
      path: random/gen.hpp
    - filename: seed.hpp
      icon: LIBRARY_ALL_AC
      path: random/seed.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - graph/detail/adjacency_list_base.hpp
  - graph/detail/adjacency_storage_common.hpp
  - graph/detail/direct_adjacency_storage.hpp
  - graph/detail/graph_base.hpp
  - graph/edge.hpp
  - graph/graph.hpp
  - random/gen.hpp
  - random/seed.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_RANDOM_GRAPH_HPP\n#define KK2_RANDOM_GRAPH_HPP 1\n\n#include\
      \ <type_traits>\n#include <vector>\n\n#include \"../graph/graph.hpp\"\n#include\
      \ \"gen.hpp\"\n\nnamespace kk2 {\n\nnamespace random {\n\ntemplate <bool is_weighted,\
      \ bool is_directed, class T = int>\nusing adjlist = std::conditional_t<is_weighted,\n\
      \                                   std::conditional_t<is_directed, DWAdjList<T>,\
      \ WAdjList<T>>,\n                                   std::conditional_t<is_directed,\
      \ DAdjList, AdjList>>;\n\ntemplate <bool is_weighted, bool is_directed, class\
      \ T = int>\nvoid add_edge(adjlist<is_weighted, is_directed, T> &g, int from,\
      \ int to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted) {\n        T\
      \ w = rng(l, r);\n        g.add_edge(from, to, w);\n    } else {\n        g.add_edge(from,\
      \ to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed, class T =\
      \ int>\nadjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T\
      \ r = 1e9) {\n    adjlist<is_weighted, is_directed, T> g(n);\n    for (int i\
      \ = 0; i < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n        add_edge<is_weighted,\
      \ is_directed, T>(g, u, v, l, r);\n    }\n    return g;\n}\n\ntemplate <bool\
      \ is_weighted, class T = int>\nadjlist<is_weighted, false, T> Tree(int n, T\
      \ l = 0, T r = 1e9) {\n    adjlist<is_weighted, false, T> g(n);\n    std::vector<int>\
      \ p = perm<int>(n);\n    for (int i = 1; i < n; i++) {\n        int u = rng(0,\
      \ i), v = i;\n        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);\n\
      \    }\n    return g;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\
      #endif // KK2_RANDOM_GRAPH_HPP\n"
    name: default
  - code: "#line 1 \"random/graph.hpp\"\n\n\n\n#include <type_traits>\n#include <vector>\n\
      \n#line 1 \"graph/graph.hpp\"\n\n\n\n#line 1 \"graph/detail/adjacency_list_base.hpp\"\
      \n\n\n\n#line 5 \"graph/detail/adjacency_list_base.hpp\"\n#include <utility>\n\
      \n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing is_standard_istream\
      \ = typename std::conditional<std::is_same<T, std::istream>::value\n       \
      \                                                   || std::is_same<T, std::ifstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T>\nusing is_standard_ostream = typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                                   \
      \       || std::is_same<T, std::ofstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T> using\
      \ is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;\n\
      template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 6 \"graph/edge.hpp\"\
      \n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\nstruct\
      \ empty {};\n\ntemplate <class T> struct _Edge {\n    int from, to, id;\n  \
      \  T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n  \
      \      : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
      \ {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator int() const {\
      \ return to; }\n    inline _Edge rev() const { return _Edge(from, cost, to,\
      \ id); }\n\n    template <OutputStream OStream> void debug_output(OStream &os)\
      \ const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n    \
      \    if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n       \
      \ os << ')';\n    }\n};\n\ntemplate <> struct _Edge<empty> {\n    int from,\
      \ to, id;\n\n    _Edge(int to_, empty = {}, int from_ = -1, int id_ = -1) :\
      \ from(from_), to(to_), id(id_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n\
      \    operator int() const { return to; }\n    inline _Edge rev() const { return\
      \ _Edge(from, {}, to, id); }\n\n    template <OutputStream OStream> void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to <<\
      \ ')';\n    }\n};\n\ntemplate <class T> T _edge_cost(const _Edge<T> &edge) {\n\
      \    if constexpr (std::is_same_v<T, empty>) return {};\n    else return edge.cost;\n\
      }\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>> {\n   \
      \ using std::vector<_Edge<T>>::vector;\n\n    template <InputStream IStream>\n\
      \    _Edges(int m, IStream &is, bool is_one_indexed = false) : std::vector<_Edge<T>>(m)\
      \ {\n        _input(is, is_one_indexed);\n    }\n\n    template <OutputStream\
      \ OStream> void debug_output(OStream &os) const {\n        os << '[';\n    \
      \    for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os <<\
      \ \", \";\n            (*this)[i].debug_output(os);\n        }\n        os <<\
      \ ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n  \
      \      this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
      \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
      \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n    \
      \    return edges;\n    }\n\n  private:\n    template <InputStream IStream>\
      \ void _input(IStream &is, bool is_one_indexed) {\n        for (int i = 0; i\
      \ < (int)this->size(); ++i) {\n            int u, v;\n            T w{};\n \
      \           is >> u >> v;\n            if (is_one_indexed) --u, --v;\n     \
      \       if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
      \ = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace graph\n\n\
      template <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T>\
      \ using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
      using Edges = graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"graph/detail/graph_base.hpp\"\n\n\n\n#line 5 \"graph/detail/graph_base.hpp\"\
      \n\n#line 7 \"graph/detail/graph_base.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\n// The representation-specific graph classes inherit this base.  Operations\n\
      // here only depend on the public graph interface, so they are shared by\n//\
      \ dynamic/static and direct/compact graphs alike.\ntemplate <class T, bool is_directed,\
      \ bool is_static, bool is_adjacency_list = true>\nstruct GraphBase {\n  public:\n\
      \    // Types and compile-time graph properties.\n    using value_type = T;\n\
      \    using edge_type = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n\
      \    static constexpr bool directed = is_directed;\n    static constexpr bool\
      \ weighted = !std::is_same_v<T, empty>;\n    static constexpr bool adjacency_list\
      \ = is_adjacency_list;\n    static constexpr bool adjacency_matrix = !is_adjacency_list;\n\
      \    static constexpr bool static_graph = is_static;\n\n    // Public graph\
      \ data and common operations.\n    edge_collection edges;\n    int num_edges()\
      \ const { return edges.size(); }\n};\n\n} // namespace kk2::graph::detail\n\n\
      \n#line 10 \"graph/detail/adjacency_list_base.hpp\"\n\nnamespace kk2::graph::detail\
      \ {\n\ntemplate <class T, bool is_directed, class Storage>\nstruct AdjacencyListBase\
      \ : GraphBase<T, is_directed, false>, private Storage {\n    using base = GraphBase<T,\
      \ is_directed, false>;\n\n  public:\n    // Public type interface and graph\
      \ storage.\n    using base::edges;\n    using base::num_edges;\n    using base::weighted;\n\
      \    using Storage::data;\n\n    using storage_type = Storage;\n    using value_type\
      \ = T;\n    using out_edge_type = typename Storage::out_edge_type;\n    using\
      \ out_edges = typename Storage::out_edges;\n    using adjacency_container =\
      \ typename Storage::adjacency_container;\n    using edge_type = _Edge<T>;\n\
      \    using edge_collection = _Edges<T>;\n\n    // Construction and graph operations.\n\
      \    AdjacencyListBase() = default;\n    explicit AdjacencyListBase(int n) :\
      \ Storage(n) {}\n    template <InputStream IStream>\n    AdjacencyListBase(int\
      \ n, int m, IStream &is, bool oneindexed = false) : Storage(n) {\n        edges.reserve(m);\n\
      \        _input(is, m, oneindexed);\n    }\n    AdjacencyListBase(int n, const\
      \ edge_collection &edges_) : Storage(n) {\n        edges.reserve(edges_.size());\n\
      \        this->reserve(edges_);\n        for (const auto &e : edges_) _add_edge_with_id(e.from,\
      \ e.to, _edge_cost(e), e.id);\n    }\n\n    int num_vertices() const { return\
      \ Storage::num_vertices(); }\n    int size() const { return num_vertices();\
      \ }\n\n    decltype(auto) operator[](int k) {\n        if constexpr (requires\
      \ { std::declval<Storage &>().view(k, &edges); }) {\n            return Storage::view(k,\
      \ &edges);\n        } else {\n            return Storage::view(k);\n       \
      \ }\n    }\n\n    decltype(auto) operator[](int k) const {\n        if constexpr\
      \ (requires { std::declval<const Storage &>().view(k, &edges); }) {\n      \
      \      return std::as_const(static_cast<const Storage &>(*this)).view(k, &edges);\n\
      \        } else {\n            return std::as_const(static_cast<const Storage\
      \ &>(*this)).view(k);\n        }\n    }\n\n    auto edge_ids(int k) const\n\
      \        requires requires { std::declval<const Storage &>().edge_ids(k); }\n\
      \    {\n        return static_cast<const Storage &>(*this).edge_ids(k);\n  \
      \  }\n\n    void swap_edges(int v, int i, int j) { Storage::swap_edges(v, i,\
      \ j); }\n    void edge_clear() { *this = AdjacencyListBase(num_vertices());\
      \ }\n\n    template <OutputStream OStream> void debug_output(OStream &os) const\
      \ {\n        os << \"[\\n\";\n        for (int i = 0; i < num_vertices(); ++i)\
      \ {\n            os << \"  \" << i << \": [\";\n            bool first = true;\n\
      \            for (auto &&e : (*this)[i]) {\n                if (!first) os <<\
      \ \", \";\n                first = false;\n                e.debug_output(os);\n\
      \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\\
      n\";\n    }\n\n    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from,\
      \ to, cost, num_edges()); }\n    void add_vertex(int n = 1) { Storage::add_vertex(n);\
      \ }\n\n    AdjacencyListBase reverse() const {\n        AdjacencyListBase result(num_vertices());\n\
      \        result.edges.reserve(edges.size());\n        result.reserve(edges);\n\
      \        for (const auto &e : edges) result._add_edge_with_id(e.to, e.from,\
      \ _edge_cost(e), e.id);\n        return result;\n    }\n\n  private:\n    template\
      \ <InputStream IStream> void _input(IStream &is, int m, bool oneindexed) {\n\
      \        edges.clear();\n        edges.reserve(m);\n        this->reset();\n\
      \        for (int i = 0; i < m; ++i) {\n            int u, v;\n            T\
      \ w{};\n            is >> u >> v;\n            if constexpr (weighted) is >>\
      \ w;\n            if (oneindexed) --u, --v;\n            edges.emplace_back(v,\
      \ w, u, i);\n        }\n        this->reserve(edges);\n        for (const auto\
      \ &e : edges) Storage::add_edge(e.from, e.to, _edge_cost(e), e.id);\n    }\n\
      \n    template <bool update = false> void _add_edge(int from, int to, T cost,\
      \ int id) {\n        Storage::add_edge(from, to, cost, id);\n        if constexpr\
      \ (update) edges[id] = edge_type(to, cost, from, id);\n        else edges.emplace_back(to,\
      \ cost, from, id);\n    }\n\n    void _add_edge_with_id(int from, int to, T\
      \ cost, int id) {\n        Storage::add_edge(from, to, cost, id);\n        edges.emplace_back(to,\
      \ cost, from, id);\n    }\n};\n\n} // namespace kk2::graph::detail\n\n\n#line\
      \ 1 \"graph/detail/direct_adjacency_storage.hpp\"\n\n\n\n#line 6 \"graph/detail/direct_adjacency_storage.hpp\"\
      \n\n#line 1 \"graph/detail/adjacency_storage_common.hpp\"\n\n\n\n#line 5 \"\
      graph/detail/adjacency_storage_common.hpp\"\n\n#line 7 \"graph/detail/adjacency_storage_common.hpp\"\
      \n\nnamespace kk2::graph::detail {\n\ntemplate <class T, bool is_directed>\n\
      std::vector<int> adjacency_degrees(int n, const _Edges<T> &edges) {\n    std::vector<int>\
      \ degree(n);\n    for (const auto &e : edges) {\n        ++degree[e.from];\n\
      \        if constexpr (!is_directed) {\n            if (e.from != e.to) ++degree[e.to];\n\
      \        }\n    }\n    return degree;\n}\n\ntemplate <bool is_directed> void\
      \ count_adjacency_edge(std::vector<int> &head, int from, int to) {\n    ++head[from];\n\
      \    if constexpr (!is_directed) {\n        if (from != to) ++head[to];\n  \
      \  }\n}\n\n} // namespace kk2::graph::detail\n\n\n#line 9 \"graph/detail/direct_adjacency_storage.hpp\"\
      \n\nnamespace kk2::graph::detail {\n\ntemplate <class T, bool is_directed> struct\
      \ DirectAdjacencyStorage {\n    using edge_type = _Edge<T>;\n    using out_edge_type\
      \ = edge_type;\n    using out_edges = _Edges<T>;\n    using adjacency_container\
      \ = std::vector<out_edges>;\n\n    adjacency_container data;\n\n    DirectAdjacencyStorage()\
      \ = default;\n    explicit DirectAdjacencyStorage(int n) : data(n) {}\n\n  \
      \  int num_vertices() const { return data.size(); }\n    out_edges &view(int\
      \ k) { return data[k]; }\n    const out_edges &view(int k) const { return data[k];\
      \ }\n    void swap_edges(int v, int i, int j) { std::swap(data[v][i], data[v][j]);\
      \ }\n    void add_vertex(int n) { data.insert(data.end(), n, out_edges()); }\n\
      \n    void reset() { data.assign(data.size(), out_edges()); }\n\n    void reserve(const\
      \ _Edges<T> &edges) {\n        const auto degree = adjacency_degrees<T, is_directed>(num_vertices(),\
      \ edges);\n        for (int i = 0; i < num_vertices(); ++i) data[i].reserve(data[i].size()\
      \ + degree[i]);\n    }\n\n    void add_edge(int from, int to, T cost, int id)\
      \ {\n        data[from].emplace_back(to, cost, from, id);\n        if constexpr\
      \ (!is_directed) {\n            if (from != to) data[to].emplace_back(from,\
      \ cost, to, id);\n        }\n    }\n};\n\n} // namespace kk2::graph::detail\n\
      \n\n#line 6 \"graph/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\n\
      template <class T, bool is_directed>\nusing AdjacencyList =\n    detail::AdjacencyListBase<T,\
      \ is_directed, detail::DirectAdjacencyStorage<T, is_directed>>;\n\n} // namespace\
      \ graph\n\ntemplate <typename T> using WAdjList = graph::AdjacencyList<T, false>;\n\
      template <typename T> using DWAdjList = graph::AdjacencyList<T, true>;\nusing\
      \ AdjList = graph::AdjacencyList<graph::empty, false>;\nusing DAdjList = graph::AdjacencyList<graph::empty,\
      \ true>;\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <numeric>\n#include <random>\n#include\
      \ <unordered_set>\n#line 10 \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\
      \n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\nnamespace random {\n\nusing\
      \ u64 = unsigned long long;\n\ninline u64 non_deterministic_seed() {\n    u64\
      \ seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n           \
      \        std::chrono::high_resolution_clock::now().time_since_epoch())\n   \
      \                .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n    seed\
      \ ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
      \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
      \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
      \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
      }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
      \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
      \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
      \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T>\
      \ std::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n\
      \    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n\
      // [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
      \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n;\
      \ i; --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
      \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
      \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\n\
      template <class Iter> void shuffle(Iter first, Iter last) {\n    if (first ==\
      \ last) return;\n    int len = 1;\n    for (auto it = first + 1; it != last;\
      \ ++it) {\n        len++;\n        int j = rng(0, len);\n        if (j != len\
      \ - 1) std::iter_swap(first + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T>\
      \ perm(int n) {\n    std::vector<T> res(n);\n    std::iota(res.begin(), res.end(),\
      \ T(0));\n    shuffle(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
      \ <class T> std::vector<T> choices(int l, int r, int k) {\n    assert(l < r\
      \ and k <= r - l);\n    std::vector<T> res(r - l);\n    std::iota(res.begin(),\
      \ res.end(), T(l));\n    shuffle(res.begin(), res.end());\n    res.resize(k);\n\
      \    return res;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line\
      \ 9 \"random/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace random {\n\ntemplate\
      \ <bool is_weighted, bool is_directed, class T = int>\nusing adjlist = std::conditional_t<is_weighted,\n\
      \                                   std::conditional_t<is_directed, DWAdjList<T>,\
      \ WAdjList<T>>,\n                                   std::conditional_t<is_directed,\
      \ DAdjList, AdjList>>;\n\ntemplate <bool is_weighted, bool is_directed, class\
      \ T = int>\nvoid add_edge(adjlist<is_weighted, is_directed, T> &g, int from,\
      \ int to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted) {\n        T\
      \ w = rng(l, r);\n        g.add_edge(from, to, w);\n    } else {\n        g.add_edge(from,\
      \ to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed, class T =\
      \ int>\nadjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T\
      \ r = 1e9) {\n    adjlist<is_weighted, is_directed, T> g(n);\n    for (int i\
      \ = 0; i < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n        add_edge<is_weighted,\
      \ is_directed, T>(g, u, v, l, r);\n    }\n    return g;\n}\n\ntemplate <bool\
      \ is_weighted, class T = int>\nadjlist<is_weighted, false, T> Tree(int n, T\
      \ l = 0, T r = 1e9) {\n    adjlist<is_weighted, false, T> g(n);\n    std::vector<int>\
      \ p = perm<int>(n);\n    for (int i = 1; i < n; i++) {\n        int u = rng(0,\
      \ i), v = i;\n        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);\n\
      \    }\n    return g;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: random/graph.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
---
