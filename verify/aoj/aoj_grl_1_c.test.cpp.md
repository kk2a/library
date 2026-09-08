---
data:
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  dependencies:
  - files:
    - filename: graph_base.hpp
      icon: LIBRARY_ALL_AC
      path: graph/detail/graph_base.hpp
    - filename: edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/edge.hpp
    - filename: matrix.hpp
      icon: LIBRARY_ALL_AC
      path: graph/matrix.hpp
    - filename: matrix_edge.hpp
      icon: LIBRARY_ALL_AC
      path: graph/matrix_edge.hpp
    - filename: warshall_floyd.hpp
      icon: LIBRARY_ALL_AC
      path: graph/shortest_path/warshall_floyd.hpp
    - filename: constant.hpp
      icon: LIBRARY_ALL_AC
      path: template/constant.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: io_util.hpp
      icon: LIBRARY_ALL_AC
      path: template/io_util.hpp
    - filename: macros.hpp
      icon: LIBRARY_ALL_AC
      path: template/macros.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: template/type_alias.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - graph/detail/graph_base.hpp
  - graph/edge.hpp
  - graph/matrix.hpp
  - graph/matrix_edge.hpp
  - graph/shortest_path/warshall_floyd.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/template.hpp
  - template/type_alias.hpp
  - type_traits/graph.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\n\
      \n#include \"../../graph/matrix.hpp\"\n#include \"../../graph/shortest_path/warshall_floyd.hpp\"\
      \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
      \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::DWAdjMat<int> g(n, m, kin);\n\
      \    auto dist = kk2::warshall_froyd(n, g.edges, true);\n    rep (i, n) if (dist[i][i].minf)\
      \ {\n        kout << \"NEGATIVE CYCLE\" << kendl;\n        return 0;\n    }\n\
      \n    rep (i, n) {\n        rep (j, n) {\n            if (!dist[i][j].inf) kout\
      \ << dist[i][j].len;\n            else kout << \"INF\";\n            kout <<\
      \ \" \\n\"[j == n - 1];\n        }\n    }\n\n    return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/aoj/aoj_grl_1_c.test.cpp\"\n// competitive-verifier: PROBLEM\
      \ https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\n\n#line\
      \ 1 \"graph/matrix.hpp\"\n\n\n\n#include <span>\n#include <vector>\n\n#line\
      \ 1 \"graph/detail/graph_base.hpp\"\n\n\n\n#include <type_traits>\n\n#line 1\
      \ \"graph/edge.hpp\"\n\n\n\n#line 6 \"graph/edge.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\
      \n\n\n\n#include <concepts>\n#include <fstream>\n#include <istream>\n#include\
      \ <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
      \ type_traits\n\ntemplate <typename T> using is_standard_istream =\n    typename\
      \ std::conditional<std::is_same<T, std::istream>::value\n                  \
      \                || std::is_same<T, std::ifstream>::value,\n               \
      \               std::true_type,\n                              std::false_type>::type;\n\
      template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
      \ std::ostream>::value\n                                  || std::is_same<T,\
      \ std::ofstream>::value,\n                              std::true_type,\n  \
      \                            std::false_type>::type;\ntemplate <typename T>\
      \ using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \n} // namespace kk2\n\n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\n\
      namespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct _Edge {\n\
      \    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int from_\
      \ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n        \
      \  id(id_),\n          cost(cost_) {}\n    _Edge() : from(-1), to(-1), id(-1)\
      \ {}\n    operator int() const { return to; }\n    inline _Edge rev() const\
      \ { return _Edge(from, cost, to, id); }\n\n    template <OutputStream OStream>\n\
      \    void debug_output(OStream &os) const {\n        os << '(' << id << \",\
      \ \" << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T, empty>)\
      \ os << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <> struct\
      \ _Edge<empty> {\n    int from, to, id;\n\n    _Edge(int to_, empty = {}, int\
      \ from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n  \
      \        id(id_) {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator\
      \ int() const { return to; }\n    inline _Edge rev() const { return _Edge(from,\
      \ {}, to, id); }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to <<\
      \ ')';\n    }\n};\n\ntemplate <class T> T _edge_cost(const _Edge<T> &edge) {\n\
      \    if constexpr (std::is_same_v<T, empty>) return {};\n    else return edge.cost;\n\
      }\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>> {\n   \
      \ using std::vector<_Edge<T>>::vector;\n\n    template <InputStream IStream>\n\
      \    _Edges(int m, IStream &is, bool is_one_indexed = false)\n        : std::vector<_Edge<T>>(m)\
      \ {\n        _input(is, is_one_indexed);\n    }\n\n    template <OutputStream\
      \ OStream>\n    void debug_output(OStream &os) const {\n        os << '[';\n\
      \        for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os\
      \ << \", \";\n            (*this)[i].debug_output(os);\n        }\n        os\
      \ << ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n\
      \        this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
      \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
      \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n    \
      \    return edges;\n    }\n\n  private:\n    template <InputStream IStream>\n\
      \    void _input(IStream &is, bool is_one_indexed) {\n        for (int i = 0;\
      \ i < (int)this->size(); ++i) {\n            int u, v;\n            T w{};\n\
      \            is >> u >> v;\n            if (is_one_indexed) --u, --v;\n    \
      \        if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
      \ = _Edge<T>(v, w, u, i);\n        }\n    }\n};\n\n} // namespace graph\n\n\
      template <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T>\
      \ using WEdges = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\n\
      using Edges = graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n\n#line\
      \ 7 \"graph/detail/graph_base.hpp\"\n\nnamespace kk2::graph::detail {\n\n//\
      \ The representation-specific graph classes inherit this base.  Operations\n\
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
      \n#line 1 \"graph/matrix_edge.hpp\"\n\n\n\n#line 6 \"graph/matrix_edge.hpp\"\
      \n\n#line 8 \"graph/matrix_edge.hpp\"\n\nnamespace kk2::graph {\n\ntemplate\
      \ <class T, bool is_const> struct _MatrixEdgeProxy {\n  private:\n    using\
      \ id_reference = std::conditional_t<is_const, const int &, int &>;\n    using\
      \ cost_reference = std::conditional_t<is_const, const T &, T &>;\n\n  public:\n\
      \    int from, to;\n    id_reference id;\n    cost_reference cost;\n\n    _MatrixEdgeProxy(int\
      \ from_, int to_, id_reference id_, cost_reference cost_)\n        : from(from_),\n\
      \          to(to_),\n          id(id_),\n          cost(cost_) {}\n\n    operator\
      \ int() const { return to; }\n\n    template <class OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n\
      \        if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n   \
      \     os << ')';\n    }\n};\n\ntemplate <class T, bool is_const> class _MatrixRowView\
      \ {\n    using edge_collection = _Edges<T>;\n    using slot_span = std::conditional_t<is_const,\
      \ std::span<const int>, std::span<int>>;\n    using edge_pointer = std::conditional_t<is_const,\
      \ const edge_collection *, edge_collection *>;\n    using cost_pointer = std::conditional_t<is_const,\
      \ const T *, T *>;\n\n    slot_span slots;\n    edge_pointer edges;\n    cost_pointer\
      \ null_cost;\n    int from;\n\n  public:\n    using value_type = _MatrixEdgeProxy<T,\
      \ is_const>;\n\n    _MatrixRowView(slot_span slots_, edge_pointer edges_, cost_pointer\
      \ null_cost_, int from_)\n        : slots(slots_),\n          edges(edges_),\n\
      \          null_cost(null_cost_),\n          from(from_) {}\n\n  private:\n\
      \    cost_pointer get_cost(int id) const {\n        if constexpr (std::is_same_v<T,\
      \ empty>) return null_cost;\n        else return id == -1 ? null_cost : &(*edges)[id].cost;\n\
      \    }\n\n  public:\n    value_type operator[](int to) const {\n        const\
      \ int id = slots[to];\n        return {from, to, slots[to], *get_cost(id)};\n\
      \    }\n    int size() const { return slots.size(); }\n};\n\n} // namespace\
      \ kk2::graph\n\n\n#line 9 \"graph/matrix.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ graph {\n\ntemplate <class T, bool is_directed>\nstruct AdjacencyMatrix\n\
      \    : detail::GraphBase<T, is_directed, false, false> {\n    using base = detail::GraphBase<T,\
      \ is_directed, false, false>;\n    using base::edges;\n    using base::num_edges;\n\
      \    using base::weighted;\n\n    using value_type = T;\n    using out_edge_type\
      \ = _MatrixEdgeProxy<T, false>;\n    using out_edges = std::vector<int>;\n \
      \   using adjacency_container = std::vector<out_edges>;\n    using edge_type\
      \ = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n    adjacency_container\
      \ data;\n    mutable T null_cost{};\n\n    AdjacencyMatrix() = default;\n  \
      \  AdjacencyMatrix(int n_) : data(n_, out_edges(n_, -1)) {}\n    template <InputStream\
      \ IStream>\n    AdjacencyMatrix(int n_, int m_, IStream &is, bool oneindexed\
      \ = false)\n        : data(n_, out_edges(n_, -1)) {\n        edges.reserve(m_);\n\
      \        _input(is, m_, oneindexed);\n    }\n    AdjacencyMatrix(int n_, const\
      \ edge_collection &edges_) : data(n_, out_edges(n_, -1)) {\n        edges.reserve(edges_.size());\n\
      \        for (const auto &e : edges_) _add_edge_with_id(e.from, e.to, _edge_cost(e),\
      \ e.id);\n    }\n\n    int num_vertices() const { return data.size(); }\n  \
      \  int size() const { return num_vertices(); }\n    _MatrixRowView<T, false>\
      \ operator[](int k) {\n        return {std::span<int>(data[k]), &edges, &null_cost,\
      \ k};\n    }\n    _MatrixRowView<T, true> operator[](int k) const {\n      \
      \  return {std::span<const int>(data[k]), &edges, &null_cost, k};\n    }\n \
      \   void edge_clear() { *this = AdjacencyMatrix(num_vertices()); }\n    void\
      \ add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to, cost,\
      \ num_edges()); }\n    void add_vertex(int n = 1) {\n        int now = num_vertices();\n\
      \        data.resize(now + n, out_edges(now + n, -1));\n        for (auto &d\
      \ : data) d.resize(now + n, -1);\n    }\n\n    template <InputStream IStream>\n\
      \    AdjacencyMatrix &input(IStream &is, bool oneindexed = false) {\n      \
      \  for (int i = 0; i < num_edges(); ++i) {\n            int u, v;\n        \
      \    T w{};\n            is >> u >> v;\n            if constexpr (weighted)\
      \ is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge<true>(u,\
      \ v, w, i);\n        }\n        return *this;\n    }\n\n    template <InputStream\
      \ IStream>\n    void _input(IStream &is, int m, bool oneindexed) {\n       \
      \ for (int i = 0; i < m; ++i) {\n            int u, v;\n            T w{};\n\
      \            is >> u >> v;\n            if constexpr (weighted) is >> w;\n \
      \           if (oneindexed) --u, --v;\n            _add_edge<false>(u, v, w,\
      \ i);\n        }\n    }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << \"[\\n\";\n        for (int i = 0; i < num_vertices();\
      \ ++i) {\n            os << \"  \" << i << \": [\";\n            for (int j\
      \ = 0; j < (int)data[i].size(); ++j) {\n                if (j) os << \", \"\
      ;\n                (*this)[i][j].debug_output(os);\n            }\n        \
      \    os << \"]\\n\";\n        }\n        os << \"]\\n\";\n    }\n\n  private:\n\
      \    template <bool update = false> void _add_edge(int from, int to, T cost,\
      \ int id) {\n        data[from][to] = id;\n        if constexpr (!is_directed)\
      \ data[to][from] = id;\n        if constexpr (update) edges[id] = edge_type(to,\
      \ cost, from, id);\n        else edges.emplace_back(to, cost, from, id);\n \
      \   }\n\n    void _add_edge_with_id(int from, int to, T cost, int id) {\n  \
      \      data[from][to] = id;\n        if constexpr (!is_directed) data[to][from]\
      \ = id;\n        edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n\
      \    AdjacencyMatrix reverse() const {\n        AdjacencyMatrix result(num_vertices());\n\
      \        result.edges.reserve(edges.size());\n        for (const auto &e : edges)\
      \ result._add_edge_with_id(e.to, e.from, _edge_cost(e), e.id);\n        return\
      \ result;\n    }\n\n};\n\n} // namespace graph\n\ntemplate <typename T> using\
      \ WAdjMat = graph::AdjacencyMatrix<T, false>;\ntemplate <typename T> using DWAdjMat\
      \ = graph::AdjacencyMatrix<T, true>;\nusing AdjMat = graph::AdjacencyMatrix<graph::empty,\
      \ false>;\nusing DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;\n\n}\
      \ // namespace kk2\n\n\n#line 1 \"graph/shortest_path/warshall_floyd.hpp\"\n\
      \n\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
      \ <ranges>\n#line 9 \"graph/shortest_path/warshall_floyd.hpp\"\n#include <utility>\n\
      #line 11 \"graph/shortest_path/warshall_floyd.hpp\"\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#line 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate\
      \ <class E>\nconcept Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class R>\nconcept EdgeRange = std::ranges::input_range<R>\
      \ &&\n                    Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class\
      \ R>\nconcept WeightedEdgeRange = EdgeRange<R> &&\n                        \
      \    WeightedEdge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept\
      \ ForwardWeightedEdgeRange = std::ranges::forward_range<R> && WeightedEdgeRange<R>;\n\
      \ntemplate <class G>\nconcept Graph = requires(const G &g, int v) {\n    typename\
      \ G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_list } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_matrix } -> std::convertible_to<bool>;\n    { G::static_graph\
      \ } -> std::convertible_to<bool>;\n    { g.num_vertices() } -> std::integral;\n\
      \    { g.num_edges() } -> std::integral;\n    g[v];\n    g.edges;\n};\n\ntemplate\
      \ <class G>\nconcept EdgeListGraph = Graph<G> && requires(const G &g) {\n  \
      \  requires std::ranges::range<decltype(g.edges)>;\n    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n\
      };\n\ntemplate <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const\
      \ G &g, int v) {\n    requires std::ranges::range<decltype(g[v])>;\n    requires\
      \ Edge<std::ranges::range_value_t<decltype(g[v])>>;\n};\n\ntemplate <class G>\n\
      concept WeightedGraph = AdjacencyGraph<G> && G::weighted &&\n              \
      \          WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 14 \"graph/shortest_path/warshall_floyd.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename\
      \ T> struct wf_len {\n    T len;\n    bool inf, minf;\n\n    template <OutputStream\
      \ OStream>\n    void debug_output(OStream &os) const {\n        if (minf) os\
      \ << \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n\
      \    }\n};\n\ntemplate <graph::WeightedEdgeRange E,\n          typename T =\
      \ std::remove_cvref_t<decltype(std::declval<std::ranges::range_value_t<E>>().cost)>>\n\
      std::vector<std::vector<wf_len<T>>> warshall_froyd(int n, const E &edges, bool\
      \ directed) {\n\n    std::vector<std::vector<wf_len<T>>> res(n, std::vector<wf_len<T>>(n,\
      \ {0, true, false}));\n    for (int i = 0; i < n; ++i) res[i][i] = {0, false,\
      \ false};\n    for (auto &&e : edges) {\n        {\n            auto &[len,\
      \ inf, minf] = res[e.from][e.to];\n            if (inf or len > e.cost) {\n\
      \                len = e.cost;\n                inf = false;\n            }\n\
      \        }\n        if (!directed) {\n            auto &[len, inf, minf] = res[e.to][e.from];\n\
      \            if (inf or len > e.cost) {\n                len = e.cost;\n   \
      \             inf = false;\n            }\n        }\n    }\n\n    for (int\
      \ k = 0; k < n; ++k) {\n        for (int i = 0; i < n; ++i) {\n            for\
      \ (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
      \ continue;\n                if (res[i][j].inf or res[i][j].len > res[i][k].len\
      \ + res[k][j].len) {\n                    res[i][j].len = res[i][k].len + res[k][j].len;\n\
      \                    res[i][j].inf = false;\n                }\n           \
      \ }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len\
      \ >= 0) continue;\n        res[k][k].minf = true;\n        for (int i = 0; i\
      \ < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n                if\
      \ (res[i][k].inf or res[k][j].inf) continue;\n                res[i][j].minf\
      \ = true;\n            }\n        }\n    }\n\n    return res;\n}\n\n} // namespace\
      \ shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
      \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
      \ <chrono>\n#include <cmath>\n#include <deque>\n#include <functional>\n#include\
      \ <iterator>\n#line 14 \"template/template.hpp\"\n#include <map>\n#include <numeric>\n\
      #include <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include\
      \ <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
      #line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\
      \n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
      \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned\
      \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi\
      \ = std::pair<int, int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int,\
      \ i64>;\nusing pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
      template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using\
      \ vvvc = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
      \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T>\
      \ using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n\
      #line 5 \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty =\
      \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
      \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
      \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
      \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
      \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double\
      \ infty<double> = infty<i64>;\ntemplate <> constexpr long double infty<long\
      \ double> = infty<i64>;\n\nconstexpr int mod = 998244353;\nconstexpr int modu\
      \ = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\n\n#line\
      \ 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include <cstdint>\n#include\
      \ <cstdio>\n#line 8 \"template/fastio.hpp\"\n#include <iostream>\n#line 10 \"\
      template/fastio.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5\
      \ \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_integral =\n \
      \   typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T> using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2\
      \ {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n \
      \ private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos\
      \ = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
      \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
      \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
      \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
      \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
      \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if\
      \ (end == 0) is_eof = true;\n            pos = 0;\n        }\n        return\
      \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
      \ ++pos;\n    }\n\n    template <UnsignedIntegral T> T next_unsigned_integral()\
      \ {\n        skip_space();\n        T res{};\n        while (isdigit(now()))\
      \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n     \
      \   }\n        return res;\n    }\n\n    template <SignedIntegral T> T next_signed_integral()\
      \ {\n        skip_space();\n        if (now() == '-') {\n            ++pos;\n\
      \            return T(-next_unsigned_integral<typename to_unsigned<T>::type>());\n\
      \        } else return (T)next_unsigned_integral<typename to_unsigned<T>::type>();\n\
      \    }\n\n    char next_char() {\n        skip_space();\n        auto res =\
      \ now();\n        ++pos;\n        return res;\n    }\n\n    std::string next_string()\
      \ {\n        skip_space();\n        std::string res;\n        while (true) {\n\
      \            char c = now();\n            if (isspace(c) or c == '\\0') break;\n\
      \            res.push_back(now());\n            ++pos;\n        }\n        return\
      \ res;\n    }\n\n    template <UnsignedIntegral T> Scanner &operator>>(T &x)\
      \ {\n        x = next_unsigned_integral<T>();\n        return *this;\n    }\n\
      \n    template <SignedIntegral T> Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n\
      \        return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n      \
      \  x = next_char();\n        return *this;\n    }\n\n    Scanner &operator>>(std::string\
      \ &x) {\n        x = next_string();\n        return *this;\n    }\n};\n\nstruct\
      \ endl_struct_t {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n\
      \    static char helper[10000][5];\n    static char leading_zero[10000][5];\n\
      \    constexpr static size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n\
      \    size_t pos = 0;\n    FILE *fp;\n\n    template <class T> static constexpr\
      \ void div_mod(T &a, T &b, T mod) {\n        a = b / mod;\n        b -= a *\
      \ mod;\n    }\n\n    static void init() {\n        buf[0] = '\\0';\n       \
      \ for (size_t i = 0; i < 10000; ++i) {\n            leading_zero[i][0] = i /\
      \ 1000 + '0';\n            leading_zero[i][1] = i / 100 % 10 + '0';\n      \
      \      leading_zero[i][2] = i / 10 % 10 + '0';\n            leading_zero[i][3]\
      \ = i % 10 + '0';\n            leading_zero[i][4] = '\\0';\n\n            size_t\
      \ j = 0;\n            if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n    \
      \        if (i >= 100) helper[i][j++] = i / 100 % 10 + '0';\n            if\
      \ (i >= 10) helper[i][j++] = i / 10 % 10 + '0';\n            helper[i][j++]\
      \ = i % 10 + '0';\n            helper[i][j] = '\\0';\n        }\n    }\n\n \
      \ public:\n    Printer() : fp(stdout) { init(); }\n\n    Printer(const char\
      \ *file) : fp(fopen(file, \"w\")) { init(); }\n\n    ~Printer() {\n        write();\n\
      \        if (fp != stdout) fclose(fp);\n    }\n\n    void write() {\n      \
      \  fwrite(buf, 1, pos, fp);\n        pos = 0;\n    }\n\n    void flush() {\n\
      \        write();\n        fflush(fp);\n    }\n\n    void put_char(char c) {\n\
      \        if (pos == OUTPUT_BUF) write();\n        buf[pos++] = c;\n    }\n\n\
      \    void put_cstr(const char *s) {\n        while (*s) put_char(*(s++));\n\
      \    }\n\n    void put_u32(uint32_t x) {\n        uint32_t y;\n        if (x\
      \ >= 100000000) { // 10^8\n            div_mod<uint32_t>(y, x, 100000000);\n\
      \            put_cstr(helper[y]);\n            div_mod<uint32_t>(y, x, 10000);\n\
      \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y,\
      \ x, 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
      \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
      \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n     \
      \   uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n           \
      \ div_mod<uint64_t>(y, x, 1000000000000ull);\n            put_u32(y);\n    \
      \        div_mod<uint64_t>(y, x, 100000000ull);\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<uint64_t>(y, x, 10000ull);\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= 10000ull) {\
      \ // 10^4\n            div_mod<uint64_t>(y, x, 10000ull);\n            put_u32(y);\n\
      \            put_cstr(leading_zero[x]);\n        } else put_cstr(helper[x]);\n\
      \    }\n\n    void put_i64(int64_t x) {\n        if (x < 0) {\n            put_char('-');\n\
      \            put_u64(-x);\n        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t\
      \ x) {\n        constexpr static __uint128_t pow10_10 = 10000000000ull;\n  \
      \      constexpr static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n    \
      \    __uint128_t y;\n        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y,\
      \ x, pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
      \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n  \
      \          put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
      \ __uint128_t(100000000ull));\n            put_cstr(leading_zero[y]);\n    \
      \        div_mod<__uint128_t>(y, x, __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000))\
      \ { // 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n \
      \           put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t\
      \ x) {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
      \        } else put_u128(x);\n    }\n\n    template <UnsignedIntegral T> Printer\
      \ &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4) put_u32(x);\n  \
      \      else if constexpr (sizeof(T) <= 8) put_u64(x);\n        else put_u128(x);\n\
      \        return *this;\n    }\n\n    template <SignedIntegral T> Printer &operator<<(T\
      \ x) {\n        if constexpr (sizeof(T) <= 4) put_i32(x);\n        else if constexpr\
      \ (sizeof(T) <= 8) put_i64(x);\n        else put_i128(x);\n        return *this;\n\
      \    }\n\n    Printer &operator<<(char x) {\n        put_char(x);\n        return\
      \ *this;\n    }\n\n    Printer &operator<<(const std::string &x) {\n       \
      \ for (char c : x) put_char(c);\n        return *this;\n    }\n\n    Printer\
      \ &operator<<(const char *x) {\n        put_cstr(x);\n        return *this;\n\
      \    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\u30DD\u30A4\u30F3\
      \u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\n    Printer &operator<<(endl_struct_t)\
      \ {\n        put_char('\\n');\n        flush();\n        return *this;\n   \
      \ }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar Printer::buf[Printer::OUTPUT_BUF];\n\
      char Printer::helper[10000][5];\nchar Printer::leading_zero[10000][5];\n\n}\
      \ // namespace fastio\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\nauto\
      \ &kin = std::cin;\nauto &kout = std::cout;\nauto (*kendl)(std::ostream &) =\
      \ std::endl<char, std::char_traits<char>>;\n#else\nfastio::Scanner kin;\nfastio::Printer\
      \ kout;\nfastio::endl_struct_t kendl;\n#endif\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n#line\
      \ 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\u30ED\
      \u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace impl\
      \ {\n\nstruct read {\n    template <class IStream, class T> inline static void\
      \ all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream, class\
      \ T, class U>\n    inline static void all_read(IStream &is, std::pair<T, U>\
      \ &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n \
      \   }\n\n    template <class IStream, class T> inline static void all_read(IStream\
      \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\
      \n    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
      \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n   \
      \ }\n};\n\nstruct write {\n    template <class OStream, class T> inline static\
      \ void all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n   \
      \ template <class OStream, class T, class U>\n    inline static void all_write(OStream\
      \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n      \
      \  all_write(os, ' ');\n        all_write(os, p.second);\n    }\n\n    template\
      \ <class OStream, class T>\n    inline static void all_write(OStream &os, const\
      \ std::vector<T> &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n\
      \            if (i) all_write(os, ' ');\n            all_write(os, v[i]);\n\
      \        }\n    }\n\n    template <class OStream, class T, size_t F>\n    inline\
      \ static void all_write(OStream &os, const std::array<T, F> &a) {\n        for\
      \ (int i = 0; i < (int)F; ++i) {\n            if (i) all_write(os, ' ');\n \
      \           all_write(os, a[i]);\n        }\n    }\n};\n\n} // namespace impl\n\
      \ntemplate <kk2::InputStream IStream, class T, class U>\nIStream &operator>>(IStream\
      \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T>\nIStream &operator>>(IStream\
      \ &is, std::vector<T> &v) {\n    impl::read::all_read(is, v);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T, size_t F>\nIStream &operator>>(IStream\
      \ &is, std::array<T, F> &a) {\n    impl::read::all_read(is, a);\n    return\
      \ is;\n}\n\ntemplate <kk2::OutputStream OStream, class T, class U>\nOStream\
      \ &operator<<(OStream &os, const std::pair<T, U> &p) {\n    impl::write::all_write(os,\
      \ p);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T>\n\
      OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    impl::write::all_write(os,\
      \ v);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T, size_t\
      \ F>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n    impl::write::all_write(os,\
      \ a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\n\n\n\n#define\
      \ rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define rep2(i, a)\
      \ for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a, b) for\
      \ (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for (long\
      \ long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long i =\
      \ (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
      #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
      \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
      \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32\
      \ \"template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
      \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
      \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
      \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"\
      NO\\n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"\
      no\\n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\n\
      template <class T, class S> inline bool chmax(T &a, const S &b) { return (a\
      \ < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/aoj/aoj_grl_1_c.test.cpp\"\
      \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n\
      \    kk2::DWAdjMat<int> g(n, m, kin);\n    auto dist = kk2::warshall_froyd(n,\
      \ g.edges, true);\n    rep (i, n) if (dist[i][i].minf) {\n        kout << \"\
      NEGATIVE CYCLE\" << kendl;\n        return 0;\n    }\n\n    rep (i, n) {\n \
      \       rep (j, n) {\n            if (!dist[i][j].inf) kout << dist[i][j].len;\n\
      \            else kout << \"INF\";\n            kout << \" \\n\"[j == n - 1];\n\
      \        }\n    }\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/aoj/aoj_grl_1_c.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 0.0028478230000104077
    environment: g++
    memory: 3.592
    name: 00_sample_00
    status: AC
  - elapsed: 0.002774774000002367
    environment: g++
    memory: 3.784
    name: 00_sample_01
    status: AC
  - elapsed: 0.002630964000005065
    environment: g++
    memory: 3.804
    name: 00_sample_02
    status: AC
  - elapsed: 0.0027551510000023427
    environment: g++
    memory: 3.76
    name: 01_small_00
    status: AC
  - elapsed: 0.0031135480000017424
    environment: g++
    memory: 3.792
    name: 01_small_01
    status: AC
  - elapsed: 0.0023562940000090293
    environment: g++
    memory: 3.792
    name: 02_corner_00
    status: AC
  - elapsed: 0.0023703159999968193
    environment: g++
    memory: 3.644
    name: 02_corner_01
    status: AC
  - elapsed: 0.0023685370000094963
    environment: g++
    memory: 3.78
    name: 02_corner_02
    status: AC
  - elapsed: 0.00228065900000729
    environment: g++
    memory: 3.596
    name: 02_corner_03
    status: AC
  - elapsed: 0.002380928000007998
    environment: g++
    memory: 3.792
    name: 02_corner_04
    status: AC
  - elapsed: 0.0022351869999965857
    environment: g++
    memory: 3.588
    name: 02_corner_05
    status: AC
  - elapsed: 0.0022985220000038
    environment: g++
    memory: 3.748
    name: 02_corner_06
    status: AC
  - elapsed: 0.0022966419999903565
    environment: g++
    memory: 3.748
    name: 03_medium_00
    status: AC
  - elapsed: 0.002284065000011992
    environment: g++
    memory: 3.768
    name: 03_medium_01
    status: AC
  - elapsed: 0.0022809430000023667
    environment: g++
    memory: 3.644
    name: 04_dag_00
    status: AC
  - elapsed: 0.002438424000004602
    environment: g++
    memory: 3.596
    name: 04_dag_01
    status: AC
  - elapsed: 0.0032420019999932492
    environment: g++
    memory: 3.8
    name: 04_dag_02
    status: AC
  - elapsed: 0.006080874000005565
    environment: g++
    memory: 3.772
    name: 04_dag_03
    status: AC
  - elapsed: 0.007997798000005218
    environment: g++
    memory: 3.916
    name: 04_dag_04
    status: AC
  - elapsed: 0.0027172059999998055
    environment: g++
    memory: 3.78
    name: 05_ring_00
    status: AC
  - elapsed: 0.004615925000010179
    environment: g++
    memory: 3.788
    name: 05_ring_01
    status: AC
  - elapsed: 0.007788621999992529
    environment: g++
    memory: 3.9
    name: 05_ring_02
    status: AC
  - elapsed: 0.009478772000008462
    environment: g++
    memory: 3.716
    name: 05_ring_03
    status: AC
  - elapsed: 0.005055083000002014
    environment: g++
    memory: 3.74
    name: 05_ring_04
    status: AC
  - elapsed: 0.0026472090000027038
    environment: g++
    memory: 3.792
    name: 06_grid_00
    status: AC
  - elapsed: 0.002619784000003733
    environment: g++
    memory: 3.816
    name: 06_grid_01
    status: AC
  - elapsed: 0.003401351000007935
    environment: g++
    memory: 3.792
    name: 06_grid_02
    status: AC
  - elapsed: 0.004563754000002973
    environment: g++
    memory: 3.92
    name: 06_grid_03
    status: AC
  - elapsed: 0.007529261000001952
    environment: g++
    memory: 3.724
    name: 06_grid_04
    status: AC
  - elapsed: 0.0028157450000065865
    environment: g++
    memory: 3.784
    name: 07_complete_00
    status: AC
  - elapsed: 0.0033218129999994517
    environment: g++
    memory: 3.784
    name: 07_complete_01
    status: AC
  - elapsed: 0.00984173199999816
    environment: g++
    memory: 3.896
    name: 07_complete_02
    status: AC
  - elapsed: 0.01762502700000823
    environment: g++
    memory: 4.048
    name: 07_complete_03
    status: AC
  - elapsed: 0.028687697999998818
    environment: g++
    memory: 4.14
    name: 07_complete_04
    status: AC
  - elapsed: 0.0031461570000033134
    environment: g++
    memory: 3.596
    name: 08_random_00
    status: AC
  - elapsed: 0.0038966890000011745
    environment: g++
    memory: 3.792
    name: 08_random_01
    status: AC
  - elapsed: 0.002867945000005534
    environment: g++
    memory: 3.784
    name: 08_random_02
    status: AC
  - elapsed: 0.003994843999990394
    environment: g++
    memory: 3.596
    name: 08_random_03
    status: AC
  - elapsed: 0.004708924000013326
    environment: g++
    memory: 3.788
    name: 08_random_04
    status: AC
  - elapsed: 0.003714647999998988
    environment: g++
    memory: 3.8
    name: 08_random_05
    status: AC
  - elapsed: 0.004322290000004614
    environment: g++
    memory: 3.596
    name: 08_random_06
    status: AC
  - elapsed: 0.008821857000000932
    environment: g++
    memory: 3.92
    name: 08_random_07
    status: AC
  - elapsed: 0.019250630000001934
    environment: g++
    memory: 3.928
    name: 08_random_08
    status: AC
  - elapsed: 0.011195825000001491
    environment: g++
    memory: 3.916
    name: 09_maximum_00
    status: AC
  - elapsed: 0.009678375999996547
    environment: g++
    memory: 4.048
    name: 09_maximum_01
    status: AC
  - elapsed: 0.029445327000004795
    environment: g++
    memory: 4.02
    name: 09_maximum_02
    status: AC
  - elapsed: 0.014394119999991517
    environment: g++
    memory: 4.044
    name: 09_maximum_03
    status: AC
  - elapsed: 0.028347922999998332
    environment: g++
    memory: 3.908
    name: 09_maximum_04
    status: AC
  - elapsed: 0.02416220000000635
    environment: g++
    memory: 3.9
    name: 09_maximum_05
    status: AC
  - elapsed: 0.00941124100000934
    environment: g++
    memory: 3.904
    name: 09_maximum_06
    status: AC
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_1_c.test.cpp
layout: document
---
