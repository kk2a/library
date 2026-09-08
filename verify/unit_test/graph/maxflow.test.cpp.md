---
data:
  attributes:
    STANDALONE: ''
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
    - filename: maxflow.hpp
      icon: LIBRARY_ALL_AC
      path: graph/maxflow.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
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
  - graph/maxflow.hpp
  - type_traits/graph.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: STANDALONE\n\n#include <cassert>\n\n#include \"\
      ../../../graph/graph.hpp\"\n#include \"../../../graph/maxflow.hpp\"\n\nint main()\
      \ {\n    kk2::WEdges<int> edges;\n    edges.add_edge(0, 1, 3);\n    edges.add_edge(0,\
      \ 2, 2);\n    edges.add_edge(1, 3, 2);\n    edges.add_edge(2, 3, 2);\n\n   \
      \ kk2::MaxFlow<kk2::DWAdjList<int>> flow(4, edges);\n    assert(flow.flow(0,\
      \ 3) == 4);\n    assert(flow.get_edge(0).flow == 2);\n    assert(flow.get_edge(1).flow\
      \ == 2);\n    assert(flow.min_cut(0)[3] == false);\n}\n"
    name: default
  - code: "#line 1 \"verify/unit_test/graph/maxflow.test.cpp\"\n// competitive-verifier:\
      \ STANDALONE\n\n#include <cassert>\n\n#line 1 \"graph/graph.hpp\"\n\n\n\n#line\
      \ 1 \"graph/detail/adjacency_list_base.hpp\"\n\n\n\n#include <type_traits>\n\
      #include <utility>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n\
      #include <fstream>\n#include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T> using\
      \ is_standard_istream =\n    typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                  || std::is_same<T, std::ifstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ =\n    typename std::conditional<std::is_same<T, std::ostream>::value\n  \
      \                                || std::is_same<T, std::ofstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 5 \"graph/edge.hpp\"\
      \n#include <vector>\n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ graph {\n\nstruct empty {};\n\ntemplate <class T> struct _Edge {\n    int\
      \ from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1,\
      \ int id_ = -1)\n        : from(from_),\n          to(to_),\n          id(id_),\n\
      \          cost(cost_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator\
      \ int() const { return to; }\n    inline _Edge rev() const { return _Edge(from,\
      \ cost, to, id); }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n\
      \        if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n   \
      \     os << ')';\n    }\n};\n\ntemplate <> struct _Edge<empty> {\n    int from,\
      \ to, id;\n\n    _Edge(int to_, empty = {}, int from_ = -1, int id_ = -1)\n\
      \        : from(from_),\n          to(to_),\n          id(id_) {}\n    _Edge()\
      \ : from(-1), to(-1), id(-1) {}\n    operator int() const { return to; }\n \
      \   inline _Edge rev() const { return _Edge(from, {}, to, id); }\n\n    template\
      \ <OutputStream OStream>\n    void debug_output(OStream &os) const {\n     \
      \   os << '(' << id << \", \" << from << \"->\" << to << ')';\n    }\n};\n\n\
      template <class T> T _edge_cost(const _Edge<T> &edge) {\n    if constexpr (std::is_same_v<T,\
      \ empty>) return {};\n    else return edge.cost;\n}\n\ntemplate <class T> struct\
      \ _Edges : public std::vector<_Edge<T>> {\n    using std::vector<_Edge<T>>::vector;\n\
      \n    template <InputStream IStream>\n    _Edges(int m, IStream &is, bool is_one_indexed\
      \ = false)\n        : std::vector<_Edge<T>>(m) {\n        _input(is, is_one_indexed);\n\
      \    }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '[';\n        for (int i = 0; i < (int)this->size();\
      \ i++) {\n            if (i) os << \", \";\n            (*this)[i].debug_output(os);\n\
      \        }\n        os << ']';\n    }\n\n    _Edges &add_edge(int from, int\
      \ to, T cost = T{}) {\n        this->emplace_back(to, cost, from, this->size());\n\
      \        return *this;\n    }\n\n    friend _Edges &add_edge(_Edges &edges,\
      \ int from, int to, T cost = T{}) {\n        edges.emplace_back(to, cost, from,\
      \ edges.size());\n        return edges;\n    }\n\n  private:\n    template <InputStream\
      \ IStream>\n    void _input(IStream &is, bool is_one_indexed) {\n        for\
      \ (int i = 0; i < (int)this->size(); ++i) {\n            int u, v;\n       \
      \     T w{};\n            is >> u >> v;\n            if (is_one_indexed) --u,\
      \ --v;\n            if constexpr (!std::is_same_v<T, empty>) is >> w;\n    \
      \        (*this)[i] = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace\
      \ graph\n\ntemplate <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename\
      \ T> using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
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
      \ {\n\ntemplate <class T, bool is_directed, class Storage>\nstruct AdjacencyListBase\n\
      \    : GraphBase<T, is_directed, false>, private Storage {\n    using base =\
      \ GraphBase<T, is_directed, false>;\n\n  public:\n    // Public type interface\
      \ and graph storage.\n    using base::edges;\n    using base::num_edges;\n \
      \   using base::weighted;\n    using Storage::data;\n\n    using storage_type\
      \ = Storage;\n    using value_type = T;\n    using out_edge_type = typename\
      \ Storage::out_edge_type;\n    using out_edges = typename Storage::out_edges;\n\
      \    using adjacency_container = typename Storage::adjacency_container;\n  \
      \  using edge_type = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n \
      \   // Construction and graph operations.\n    AdjacencyListBase() = default;\n\
      \    explicit AdjacencyListBase(int n) : Storage(n) {}\n    template <InputStream\
      \ IStream>\n    AdjacencyListBase(int n, int m, IStream &is, bool oneindexed\
      \ = false) : Storage(n) {\n        edges.reserve(m);\n        _input(is, m,\
      \ oneindexed);\n    }\n    AdjacencyListBase(int n, const edge_collection &edges_)\
      \ : Storage(n) {\n        edges.reserve(edges_.size());\n        this->reserve(edges_);\n\
      \        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e),\
      \ e.id);\n    }\n\n    int num_vertices() const { return Storage::num_vertices();\
      \ }\n    int size() const { return num_vertices(); }\n\n    decltype(auto) operator[](int\
      \ k) {\n        if constexpr (requires { std::declval<Storage &>().view(k, &edges);\
      \ }) {\n            return Storage::view(k, &edges);\n        } else {\n   \
      \         return Storage::view(k);\n        }\n    }\n\n    decltype(auto) operator[](int\
      \ k) const {\n        if constexpr (requires { std::declval<const Storage &>().view(k,\
      \ &edges); }) {\n            return std::as_const(static_cast<const Storage\
      \ &>(*this)).view(k, &edges);\n        } else {\n            return std::as_const(static_cast<const\
      \ Storage &>(*this)).view(k);\n        }\n    }\n\n    auto edge_ids(int k)\
      \ const\n        requires requires { std::declval<const Storage &>().edge_ids(k);\
      \ }\n    {\n        return static_cast<const Storage &>(*this).edge_ids(k);\n\
      \    }\n\n    void swap_edges(int v, int i, int j) { Storage::swap_edges(v,\
      \ i, j); }\n    void edge_clear() { *this = AdjacencyListBase(num_vertices());\
      \ }\n\n    template <OutputStream OStream>\n    void debug_output(OStream &os)\
      \ const {\n        os << \"[\\n\";\n        for (int i = 0; i < num_vertices();\
      \ ++i) {\n            os << \"  \" << i << \": [\";\n            bool first\
      \ = true;\n            for (auto &&e : (*this)[i]) {\n                if (!first)\
      \ os << \", \";\n                first = false;\n                e.debug_output(os);\n\
      \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\\
      n\";\n    }\n\n    void add_edge(int from, int to, T cost = T{}) {\n       \
      \ _add_edge<false>(from, to, cost, num_edges());\n    }\n    void add_vertex(int\
      \ n = 1) { Storage::add_vertex(n); }\n\n    AdjacencyListBase reverse() const\
      \ {\n        AdjacencyListBase result(num_vertices());\n        result.edges.reserve(edges.size());\n\
      \        result.reserve(edges);\n        for (const auto &e : edges) result._add_edge_with_id(e.to,\
      \ e.from, _edge_cost(e), e.id);\n        return result;\n    }\n\n  private:\n\
      \    template <InputStream IStream>\n    void _input(IStream &is, int m, bool\
      \ oneindexed) {\n        edges.clear();\n        edges.reserve(m);\n       \
      \ this->reset();\n        for (int i = 0; i < m; ++i) {\n            int u,\
      \ v;\n            T w{};\n            is >> u >> v;\n            if constexpr\
      \ (weighted) is >> w;\n            if (oneindexed) --u, --v;\n            edges.emplace_back(v,\
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
      \        }\n    }\n    return degree;\n}\n\ntemplate <bool is_directed>\nvoid\
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
      template <class T, bool is_directed>\nusing AdjacencyList = detail::AdjacencyListBase<T,\
      \ is_directed,\n                                                detail::DirectAdjacencyStorage<T,\
      \ is_directed>>;\n\n} // namespace graph\n\ntemplate <typename T> using WAdjList\
      \ = graph::AdjacencyList<T, false>;\ntemplate <typename T> using DWAdjList =\
      \ graph::AdjacencyList<T, true>;\nusing AdjList = graph::AdjacencyList<graph::empty,\
      \ false>;\nusing DAdjList = graph::AdjacencyList<graph::empty, true>;\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"graph/maxflow.hpp\"\n\n\n\n#include <algorithm>\n\
      #line 6 \"graph/maxflow.hpp\"\n#include <functional>\n#include <limits>\n#include\
      \ <numeric>\n#include <queue>\n#include <ranges>\n#line 12 \"graph/maxflow.hpp\"\
      \n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#line 8 \"type_traits/graph.hpp\"\
      \n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge = requires(const\
      \ E &e) {\n    { e.from } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ R>\nconcept EdgeRange = std::ranges::input_range<R> &&\n                 \
      \   Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept WeightedEdgeRange\
      \ = EdgeRange<R> &&\n                            WeightedEdge<std::ranges::range_value_t<R>>;\n\
      \ntemplate <class R>\nconcept ForwardWeightedEdgeRange = std::ranges::forward_range<R>\
      \ && WeightedEdgeRange<R>;\n\ntemplate <class G>\nconcept Graph = requires(const\
      \ G &g, int v) {\n    typename G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n\
      \    { G::weighted } -> std::convertible_to<bool>;\n    { G::adjacency_list\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_matrix } -> std::convertible_to<bool>;\n\
      \    { G::static_graph } -> std::convertible_to<bool>;\n    { g.num_vertices()\
      \ } -> std::integral;\n    { g.num_edges() } -> std::integral;\n    g[v];\n\
      \    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph = Graph<G> &&\
      \ requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
      \    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n};\n\ntemplate\
      \ <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const G &g, int v)\
      \ {\n    requires std::ranges::range<decltype(g[v])>;\n    requires Edge<std::ranges::range_value_t<decltype(g[v])>>;\n\
      };\n\ntemplate <class G>\nconcept WeightedGraph = AdjacencyGraph<G> && G::weighted\
      \ &&\n                        WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>()[0])>>;\n\ntemplate <class G>\nconcept WeightedEdgeListGraph = EdgeListGraph<G>\
      \ && G::weighted &&\n                                WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>().edges)>>;\n\ntemplate <class G>\nconcept UnweightedGraph = AdjacencyGraph<G>\
      \ && (!G::weighted);\n\ntemplate <class G>\nconcept DirectedGraph = AdjacencyGraph<G>\
      \ && G::directed;\n\ntemplate <class G>\nconcept UndirectedGraph = AdjacencyGraph<G>\
      \ && (!G::directed);\n\ntemplate <class G>\nconcept WeightedDirectedGraph =\
      \ WeightedGraph<G> && DirectedGraph<G>;\n\ntemplate <class G>\nconcept WeightedUndirectedGraph\
      \ = WeightedGraph<G> && UndirectedGraph<G>;\n\ntemplate <class G>\nconcept WeightedDirectedEdgeListGraph\
      \ = WeightedEdgeListGraph<G> && G::directed;\n\ntemplate <class G>\nconcept\
      \ WeightedUndirectedEdgeListGraph = WeightedEdgeListGraph<G> && (!G::directed);\n\
      \ntemplate <class G>\nconcept StaticGraph = Graph<G> && G::static_graph;\n\n\
      // Adjacency over vertices, also usable with vector<vector<int>>.\ntemplate\
      \ <class G>\nconcept VertexAdjacency = requires(const G &g, int v) {\n    {\
      \ g.size() } -> std::integral;\n    requires std::ranges::range<decltype(g[v])>;\n\
      \    requires std::convertible_to<std::ranges::range_value_t<decltype(g[v])>,\
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 14 \"graph/maxflow.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class Cap> struct MaxFlowGraph {\n    struct\
      \ arc {\n        int to, rev;\n        Cap cap;\n    };\n    struct edge {\n\
      \        int from, to, index;\n    };\n\n    std::vector<std::vector<arc>> data;\n\
      \    std::vector<edge> edges;\n\n    MaxFlowGraph() = default;\n    explicit\
      \ MaxFlowGraph(int n) : data(n) {}\n\n    template <class E>\n        requires\
      \ graph::WeightedEdgeRange<const E>\n    MaxFlowGraph(int n, const E &input)\
      \ : data(n) {\n        if constexpr (std::ranges::sized_range<const E>) {\n\
      \            edges.reserve(std::ranges::size(input));\n        }\n        if\
      \ constexpr (std::ranges::forward_range<const E>) {\n            std::vector<int>\
      \ degree(n);\n            for (const auto &e : input) {\n                ++degree[e.from];\n\
      \                ++degree[e.to];\n            }\n            for (int v = 0;\
      \ v < n; ++v) data[v].reserve(degree[v]);\n        }\n        for (const auto\
      \ &e : input) add_edge(e.from, e.to, e.cost);\n    }\n\n    void add_edge(int\
      \ from, int to, Cap cap) {\n        const int index = data[from].size();\n \
      \       data[from].push_back({to, -1, cap});\n        const int rev = data[to].size();\n\
      \        data[to].push_back({from, index, Cap(0)});\n        data[from][index].rev\
      \ = rev;\n        edges.push_back({from, to, index});\n    }\n};\n\ntemplate\
      \ <graph::WeightedDirectedGraph WG> struct MaxFlow {\n\n    using Cap = typename\
      \ WG::value_type;\n    using graph_type = MaxFlowGraph<Cap>;\n\n    graph_type\
      \ g;\n    int n, m;\n\n    MaxFlow(const WG &g_) : g(g_.num_vertices(), g_.edges),\
      \ n(g_.num_vertices()), m(g_.num_edges()) {}\n\n    template <class Edges_>\n\
      \        requires graph::WeightedEdgeRange<const Edges_>\n    MaxFlow(int n_,\
      \ const Edges_ &edges) : g(n_, edges), n(n_), m(g.edges.size()) {}\n\n    Cap\
      \ flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }\n\
      \n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s <\
      \ n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n\n       \
      \ std::vector<int> level(n), iter(n);\n        std::queue<int> que;\n\n    \
      \    auto bfs = [&]() {\n            std::fill(std::begin(level), std::end(level),\
      \ -1);\n            level[s] = 0;\n            que = std::queue<int>();\n  \
      \          que.push(s);\n            while (!que.empty()) {\n              \
      \  int v = que.front();\n                que.pop();\n                for (const\
      \ auto &e : g.data[v]) {\n                    if (e.cap == 0 || level[e.to]\
      \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n       \
      \             if (e.to == t) return;\n                    que.push(e.to);\n\
      \                }\n            }\n        };\n        auto dfs = [&](auto self,\
      \ int v, Cap up) {\n            if (v == t) return up;\n            Cap res\
      \ = 0;\n            for (int &i = iter[v]; i < (int)g.data[v].size(); i++) {\n\
      \                auto &e = g.data[v][i];\n                if (e.cap == 0 ||\
      \ level[e.to] != level[v] + 1) continue;\n                Cap d = self(self,\
      \ e.to, std::min(up - res, e.cap));\n                if (d <= 0) continue;\n\
      \                e.cap -= d;\n                g.data[e.to][e.rev].cap += d;\n\
      \                res += d;\n                if (res == up) break;\n        \
      \    }\n            return res;\n        };\n\n        Cap flow = 0;\n     \
      \   while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
      \ == -1) break;\n            std::fill(std::begin(iter), std::end(iter), 0);\n\
      \            while (flow < flow_limit) {\n                Cap f = dfs(dfs, s,\
      \ flow_limit - flow);\n                if (!f) break;\n                flow\
      \ += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
      \ min_cut(int s) {\n        std::vector<bool> visited(n);\n        std::queue<int>\
      \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
      \ p = que.front();\n            que.pop();\n            visited[p] = true;\n\
      \            for (const auto &e : g.data[p]) {\n                if (e.cap &&\
      \ !visited[e.to]) {\n                    visited[e.to] = true;\n           \
      \         que.push(e.to);\n                }\n            }\n        }\n   \
      \     return visited;\n    }\n\n    struct edge {\n        int from, to;\n \
      \       Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        const\
      \ auto &e = g.edges[i];\n        const auto &forward = g.data[e.from][e.index];\n\
      \        const auto &reverse = g.data[forward.to][forward.rev];\n        return\
      \ edge{e.from, e.to, forward.cap + reverse.cap, reverse.cap};\n    }\n\n   \
      \ std::vector<edge> get_edges() {\n        std::vector<edge> result(m);\n  \
      \      for (int i = 0; i < m; i++) { result[i] = get_edge(i); }\n        return\
      \ result;\n    }\n};\n\n} // namespace kk2\n\n\n#line 7 \"verify/unit_test/graph/maxflow.test.cpp\"\
      \n\nint main() {\n    kk2::WEdges<int> edges;\n    edges.add_edge(0, 1, 3);\n\
      \    edges.add_edge(0, 2, 2);\n    edges.add_edge(1, 3, 2);\n    edges.add_edge(2,\
      \ 3, 2);\n\n    kk2::MaxFlow<kk2::DWAdjList<int>> flow(4, edges);\n    assert(flow.flow(0,\
      \ 3) == 4);\n    assert(flow.get_edge(0).flow == 2);\n    assert(flow.get_edge(1).flow\
      \ == 2);\n    assert(flow.min_cut(0)[3] == false);\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/graph/maxflow.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/graph/maxflow.test.cpp
layout: document
---
