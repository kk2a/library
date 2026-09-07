---
data:
  attributes:
    STANDALONE: ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: '// competitive-verifier: STANDALONE


      #include <vector>


      #include "../../../../graph/graph.hpp"

      #include "../../../../graph/static_graph.hpp"

      #include "../../../../type_traits/graph.hpp"


      static_assert(kk2::graph::Graph<kk2::AdjList>);

      static_assert(kk2::graph::EdgeListGraph<kk2::AdjList>);

      static_assert(kk2::graph::AdjacencyGraph<kk2::AdjList>);

      static_assert(kk2::graph::UnweightedGraph<kk2::AdjList>);

      static_assert(kk2::graph::UndirectedGraph<kk2::AdjList>);


      static_assert(kk2::graph::WeightedGraph<kk2::DWAdjList<int>>);

      static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjList<int>>);

      static_assert(kk2::graph::WeightedDirectedGraph<kk2::DWAdjList<int>>);

      static_assert(kk2::graph::WeightedDirectedEdgeListGraph<kk2::DWAdjList<int>>);


      static_assert(kk2::graph::StaticGraph<kk2::SAdjList>);

      static_assert(kk2::graph::WeightedEdgeListGraph<kk2::SDWAdjList<int>>);

      static_assert(kk2::graph::WeightedUndirectedEdgeListGraph<kk2::SWAdjList<int>>);


      static_assert(kk2::graph::Graph<kk2::DWAdjMat<int>>);

      static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjMat<int>>);

      static_assert(!kk2::graph::AdjacencyGraph<kk2::DWAdjMat<int>>);

      static_assert(!kk2::graph::WeightedGraph<kk2::DWAdjMat<int>>);


      static_assert(kk2::graph::VertexAdjacency<std::vector<std::vector<int>>>);


      int main() {}

      '
    name: default
  - code: "#line 1 \"verify/unit_test/type_traits/graph/graph.test.cpp\"\n// competitive-verifier:\
      \ STANDALONE\n\n#include <vector>\n\n#line 1 \"graph/graph.hpp\"\n\n\n\n#include\
      \ <cassert>\n#include <type_traits>\n#include <utility>\n#line 8 \"graph/graph.hpp\"\
      \n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n#include <fstream>\n\
      #include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
      \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
      \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n  \
      \                                || std::is_same<T, std::ifstream>::value,\n\
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
      \n} // namespace kk2\n\n\n#line 1 \"graph/edge.hpp\"\n\n\n\n#line 6 \"graph/edge.hpp\"\
      \n\n#line 8 \"graph/edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\nstruct\
      \ empty {};\n\ntemplate <class T> struct _Edge {\n    int from, to, id;\n  \
      \  T cost;\n\n    _Edge(int to_, T cost_, int from_ = -1, int id_ = -1)\n  \
      \      : from(from_),\n          to(to_),\n          id(id_),\n          cost(cost_)\
      \ {}\n    _Edge() : from(-1), to(-1), id(-1) {}\n    operator int() const {\
      \ return to; }\n    inline _Edge rev() const { return _Edge(from, cost, to,\
      \ id); }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '(' << id << \", \" << from << \"->\" << to;\n\
      \        if constexpr (!std::is_same_v<T, empty>) os << \":\" << cost;\n   \
      \     os << ')';\n    }\n};\n\ntemplate <class T> struct _Edges : public std::vector<_Edge<T>>\
      \ {\n    using std::vector<_Edge<T>>::vector;\n\n    template <InputStream IStream>\n\
      \    _Edges &input(IStream &is, bool is_one_indexed = false) {\n        for\
      \ (int i = 0; i < (int)this->size(); i++) {\n            int u, v;\n       \
      \     T w{};\n            is >> u >> v;\n            if (is_one_indexed) --u,\
      \ --v;\n            if constexpr (!std::is_same_v<T, empty>) is >> w;\n    \
      \        (*this)[i] = _Edge<T>(v, w, u, i);\n        }\n        return *this;\n\
      \    }\n\n    template <InputStream IStream>\n    friend _Edges &input(_Edges\
      \ &edges, IStream &is, bool is_one_indexed = false) {\n        return edges.input(is,\
      \ is_one_indexed);\n    }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << '[';\n        for (int i = 0; i < (int)this->size();\
      \ i++) {\n            if (i) os << \", \";\n            (*this)[i].debug_output(os);\n\
      \        }\n        os << ']';\n    }\n\n    _Edges &add_edge(int from, int\
      \ to, T cost = T{}) {\n        this->emplace_back(to, cost, from, this->size());\n\
      \        return *this;\n    }\n\n    friend _Edges &add_edge(_Edges &edges,\
      \ int from, int to, T cost = T{}) {\n        edges.emplace_back(to, cost, from,\
      \ edges.size());\n        return edges;\n    }\n};\n\ntemplate <class T> struct\
      \ _pair {\n    T cost;\n    int id;\n\n    _pair(T cost_, int id_) : cost(cost_),\
      \ id(id_) {}\n    _pair() : cost(), id(-1) {}\n    operator bool() const { return\
      \ id != -1; }\n    template <OutputStream OStream>\n    friend OStream &operator<<(OStream\
      \ &os, const _pair &p) {\n        if constexpr (std::is_same_v<T, empty>) return\
      \ os;\n        else return os << p.cost;\n    }\n};\ntemplate <class T> using\
      \ _pairs = std::vector<_pair<T>>;\n\n} // namespace graph\n\ntemplate <typename\
      \ T> using WEdge = graph::_Edge<T>;\ntemplate <typename T> using WEdges = graph::_Edges<T>;\n\
      using Edge = graph::_Edge<graph::empty>;\nusing Edges = graph::_Edges<graph::empty>;\n\
      \n} // namespace kk2\n\n\n#line 11 \"graph/graph.hpp\"\n\nnamespace kk2 {\n\n\
      namespace graph {\n\ntemplate <class T, bool is_directed> struct AdjacencyList\
      \ {\n    using value_type = T;\n    using out_edge_type = _Edge<T>;\n    using\
      \ out_edges = _Edges<T>;\n    using adjacency_container = std::vector<out_edges>;\n\
      \    using edge_type = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n\
      \    static constexpr bool directed = is_directed;\n    static constexpr bool\
      \ weighted = !std::is_same_v<T, empty>;\n    static constexpr bool adjacency_list\
      \ = true;\n    static constexpr bool adjacency_matrix = false;\n    static constexpr\
      \ bool static_graph = false;\n\n    adjacency_container data;\n    edge_collection\
      \ edges;\n\n    AdjacencyList() = default;\n    AdjacencyList(int n_) : data(n_)\
      \ {}\n    // input \u3092\u4F7F\u3046\u3053\u3068\u304C\u524D\u63D0\n    AdjacencyList(int\
      \ n_, int m_) : data(n_), edges(m_) {}\n    AdjacencyList(int n_, const edge_collection\
      \ &edges_) : data(n_), edges(edges_.size()) {\n        for (auto &&e : edges_)\
      \ _add_edge<true>(e.from, e.to, e.cost, e.id);\n    }\n\n    inline int num_vertices()\
      \ const { return data.size(); }\n    inline int size() const { return data.size();\
      \ }\n    inline int num_edges() const { return edges.size(); }\n    out_edges\
      \ &operator[](int k) { return data[k]; }\n    const out_edges &operator[](int\
      \ k) const { return data[k]; }\n    void edge_clear() { *this = AdjacencyList(num_vertices());\
      \ }\n    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from,\
      \ to, cost, num_edges()); }\n    void add_vertex(int n = 1) { data.insert(data.end(),\
      \ n, out_edges()); }\n\n    template <InputStream IStream>\n    AdjacencyList\
      \ &input(IStream &is, bool oneindexed = false) {\n        for (int i = 0; i\
      \ < num_edges(); i++) {\n            int u, v;\n            T w{};\n       \
      \     is >> u >> v;\n            if constexpr (weighted) is >> w;\n        \
      \    if (oneindexed) --u, --v;\n            _add_edge<true>(u, v, w, i);\n \
      \       }\n        return *this;\n    }\n\n    template <OutputStream OStream>\n\
      \    void debug_output(OStream &os) const {\n        os << \"[\\n\";\n     \
      \   for (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" <<\
      \ i << \": [\";\n            for (size_t j = 0; j < data[i].size(); j++) {\n\
      \                if (j) os << \", \";\n                data[i][j].debug_output(os);\n\
      \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\\
      n\";\n    }\n\n  private:\n    template <bool update = false> void _add_edge(int\
      \ from, int to, T cost, int id) {\n        data[from].emplace_back(to, cost,\
      \ from, id);\n        if (!is_directed and from != to) data[to].emplace_back(from,\
      \ cost, to, id);\n        if constexpr (update) edges[id] = edge_type(to, cost,\
      \ from, id);\n        else edges.emplace_back(to, cost, from, id);\n    }\n\n\
      \  public:\n    AdjacencyList reverse() const {\n        AdjacencyList res(num_vertices(),\
      \ num_edges());\n        for (auto &&e : edges) res._add_edge<true>(e.to, e.from,\
      \ e.cost, e.id);\n        return res;\n    }\n};\n\ntemplate <class T, bool\
      \ is_directed> struct AdjacencyMatrix {\n    using value_type = T;\n    using\
      \ out_edge_type = _pair<T>;\n    using out_edges = _pairs<T>;\n    using adjacency_container\
      \ = std::vector<out_edges>;\n    using edge_type = _Edge<T>;\n    using edge_collection\
      \ = _Edges<T>;\n\n    static constexpr bool directed = is_directed;\n    static\
      \ constexpr bool weighted = !std::is_same_v<T, empty>;\n    static constexpr\
      \ bool adjacency_list = false;\n    static constexpr bool adjacency_matrix =\
      \ true;\n    static constexpr bool static_graph = false;\n\n    adjacency_container\
      \ data;\n    edge_collection edges;\n\n    AdjacencyMatrix() = default;\n  \
      \  AdjacencyMatrix(int n_) : data(n_, out_edges(n_)) {}\n    // input \u3092\
      \u4F7F\u3046\u3053\u3068\u304C\u524D\u63D0\n    AdjacencyMatrix(int n_, int\
      \ m_) : data(n_, out_edges(n_)), edges(m_) {}\n    AdjacencyMatrix(int n_, const\
      \ edge_collection &edges_)\n        : data(n_, out_edges(n_)),\n          edges(edges_.size())\
      \ {\n        for (auto &&e : edges_) _add_edge<true>(e.from, e.to, e.cost, e.id);\n\
      \    }\n\n    inline int num_vertices() const { return data.size(); }\n    inline\
      \ int size() const { return data.size(); }\n    inline int num_edges() const\
      \ { return edges.size(); }\n    out_edges &operator[](int k) { return data[k];\
      \ }\n    const out_edges &operator[](int k) const { return data[k]; }\n    void\
      \ edge_clear() { *this = AdjacencyMatrix(num_vertices()); }\n    void add_edge(int\
      \ from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges());\
      \ }\n    void add_vertex(int n = 1) {\n        int now = num_vertices();\n \
      \       data.resize(now + n);\n        for (auto &&d : data) d.resize(now +\
      \ n);\n    }\n\n    template <InputStream IStream>\n    AdjacencyMatrix &input(IStream\
      \ &is, bool oneindexed = false) {\n        for (int i = 0; i < num_edges();\
      \ i++) {\n            int u, v;\n            T w{};\n            is >> u >>\
      \ v;\n            if constexpr (weighted) is >> w;\n            if (oneindexed)\
      \ --u, --v;\n            _add_edge<true>(u, v, w, i);\n        }\n        return\
      \ *this;\n    }\n\n    template <OutputStream OStream>\n    void debug_output(OStream\
      \ &os) const {\n        os << \"[\\n\";\n        for (int i = 0; i < num_vertices();\
      \ i++) {\n            os << \"  \" << i << \": [\";\n            for (size_t\
      \ j = 0; j < data[i].size(); j++) {\n                if (j) os << \", \";\n\
      \                os << \"(\" << data[i][j].id << \", \" << i << \"->\" << j;\n\
      \                if constexpr (weighted) os << \": \" << data[i][j].cost;\n\
      \                os << \")\";\n            }\n            os << \"]\\n\";\n\
      \        }\n        os << \"]\\n\";\n    }\n\n  private:\n    template <bool\
      \ update = false> void _add_edge(int from, int to, T cost, int id) {\n     \
      \   data[from][to] = out_edge_type(cost, id);\n        if constexpr (!is_directed)\
      \ data[to][from] = out_edge_type(cost, id);\n        if constexpr (update) edges[id]\
      \ = edge_type(to, cost, from, id);\n        else edges.emplace_back(to, cost,\
      \ from, id);\n    }\n\n  public:\n    AdjacencyMatrix reverse() const {\n  \
      \      AdjacencyMatrix res(num_vertices(), num_edges());\n        for (auto\
      \ &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n        return\
      \ res;\n    }\n};\n\n} // namespace graph\n\ntemplate <typename T> using WAdjList\
      \ = graph::AdjacencyList<T, false>;\ntemplate <typename T> using DWAdjList =\
      \ graph::AdjacencyList<T, true>;\nusing AdjList = graph::AdjacencyList<graph::empty,\
      \ false>;\nusing DAdjList = graph::AdjacencyList<graph::empty, true>;\n\ntemplate\
      \ <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;\ntemplate <typename\
      \ T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;\nusing AdjMat = graph::AdjacencyMatrix<graph::empty,\
      \ false>;\nusing DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;\n\n}\
      \ // namespace kk2\n\n\n#line 1 \"graph/static_graph.hpp\"\n\n\n\n#line 7 \"\
      graph/static_graph.hpp\"\n\n#line 10 \"graph/static_graph.hpp\"\n\nnamespace\
      \ kk2 {\n\nnamespace graph {\n\ntemplate <class T, bool is_directed> struct\
      \ StaticAdjacencyList {\n    using value_type = T;\n    using out_edge_type\
      \ = _Edge<T>;\n    using out_edges = _Edges<T>;\n    using adjacency_container\
      \ = _Edges<T>;\n    using edge_type = _Edge<T>;\n    using edge_collection =\
      \ _Edges<T>;\n\n    static constexpr bool directed = is_directed;\n    static\
      \ constexpr bool weighted = !std::is_same_v<T, empty>;\n    static constexpr\
      \ bool adjacency_list = true;\n    static constexpr bool adjacency_matrix =\
      \ false;\n    static constexpr bool static_graph = true;\n\n    std::vector<int>\
      \ head;\n    edge_collection edges;\n    adjacency_container data;\n    bool\
      \ is_built = false;\n\n    StaticAdjacencyList() = default;\n    StaticAdjacencyList(int\
      \ n_) : head(n_) {}\n    StaticAdjacencyList(int n_, int m_) : head(n_), edges(m_)\
      \ {}\n    StaticAdjacencyList(int n_, const edge_collection &edges_) : head(n_),\
      \ edges(edges_.size()) {\n        for (auto &&e : edges) _add_edge<true>(e.from,\
      \ e.to, e.cost, e.id);\n        build();\n    }\n\n    inline int num_vertices()\
      \ const { return head.size(); }\n    inline int size() const { return head.size();\
      \ }\n    inline int num_edges() const { return edges.size(); }\n    void add_edge(int\
      \ from, int to, T cost = T{}) { _add_edge<false>(from, to, cost, num_edges());\
      \ }\n    void add_vertex(int n = 1) { head.insert(head.end(), n, 0); }\n   \
      \ void edge_clear() { *this = StaticAdjacencyList(num_vertices()); }\n\n   \
      \ template <class It> struct Es {\n        It b, e;\n        It begin() const\
      \ { return b; }\n        It end() const { return e; }\n        int size() const\
      \ { return int(e - b); }\n        auto &&operator[](int k) const { return b[k];\
      \ }\n    };\n\n    Es<typename _Edges<T>::iterator> operator[](int k) {\n  \
      \      assert(is_built);\n        if (k == (int)head.size() - 1)\n         \
      \   return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};\n\
      \        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin()\
      \ + head[k + 1]};\n    }\n\n    const Es<typename _Edges<T>::const_iterator>\
      \ operator[](int k) const {\n        assert(is_built);\n        if (k == (int)head.size()\
      \ - 1)\n            return Es<typename _Edges<T>::const_iterator>{data.begin()\
      \ + head[k], data.end()};\n        return Es<typename _Edges<T>::const_iterator>{data.begin()\
      \ + head[k],\n                                                      data.begin()\
      \ + head[k + 1]};\n    }\n\n    template <InputStream IStream>\n    StaticAdjacencyList\
      \ &input(IStream &is, bool oneindexed = false) {\n        for (int i = 0; i\
      \ < num_edges(); i++) {\n            int u, v;\n            T w{};\n       \
      \     is >> u >> v;\n            if constexpr (weighted) is >> w;\n        \
      \    if (oneindexed) --u, --v;\n            _add_edge<true>(u, v, w, i);\n \
      \       }\n\n        build();\n        return *this;\n    }\n\n    template\
      \ <OutputStream OStream>\n    void debug_output(OStream &os) const {\n     \
      \   assert(is_built);\n        os << \"[\\n\";\n        for (int i = 0; i <\
      \ num_vertices(); i++) {\n            os << \"  \" << i << \": [\";\n      \
      \      for (int j = 0;\n                 j < (i == num_vertices() - 1 ? (int)data.size()\
      \ : head[i + 1]) - head[i];\n                 j++) {\n                if (j)\
      \ os << \", \";\n                data[head[i] + j].debug_output(os);\n     \
      \       }\n            os << \"]\\n\";\n        }\n        os << \"]\\n\";\n\
      \    }\n\n    void build() {\n        is_built = true;\n        for (unsigned\
      \ int i = 1; i < head.size(); ++i) head[i] += head[i - 1];\n        data.resize(head.back());\n\
      \        for (auto &&e : edges) {\n            data[--head[e.from]] = e;\n \
      \           if constexpr (!is_directed) {\n                if (e.from != e.to)\
      \ data[--head[e.to]] = e.rev();\n            }\n        }\n    }\n\n  private:\n\
      \    template <bool update = false> void _add_edge(int from, int to, T cost,\
      \ int id) {\n        head[from]++;\n        if (!is_directed and from != to)\
      \ head[to]++;\n        if constexpr (update) edges[id] = _Edge<T>(to, cost,\
      \ from, id);\n        else edges.emplace_back(to, cost, from, id);\n    }\n\n\
      \  public:\n    StaticAdjacencyList reverse() const {\n        StaticAdjacencyList\
      \ res(num_vertices(), num_edges());\n        for (auto &&e : edges) res._add_edge<true>(e.to,\
      \ e.from, e.cost, e.id);\n        res.build();\n        return res;\n    }\n\
      };\n\n} // namespace graph\n\ntemplate <typename T> using SWAdjList = graph::StaticAdjacencyList<T,\
      \ false>;\ntemplate <typename T> using SDWAdjList = graph::StaticAdjacencyList<T,\
      \ true>;\nusing SAdjList = graph::StaticAdjacencyList<graph::empty, false>;\n\
      using SDAdjList = graph::StaticAdjacencyList<graph::empty, true>;\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#line 5 \"type_traits/graph.hpp\"\
      \n#include <ranges>\n#line 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E>\nconcept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ G>\nconcept Graph = requires(const G &g, int v) {\n    typename G::value_type;\n\
      \    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_list } -> std::convertible_to<bool>;\n    { G::adjacency_matrix\
      \ } -> std::convertible_to<bool>;\n    { G::static_graph } -> std::convertible_to<bool>;\n\
      \    { g.num_vertices() } -> std::integral;\n    { g.num_edges() } -> std::integral;\n\
      \    g[v];\n    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph =\
      \ Graph<G> && requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 8 \"verify/unit_test/type_traits/graph/graph.test.cpp\"\
      \n\nstatic_assert(kk2::graph::Graph<kk2::AdjList>);\nstatic_assert(kk2::graph::EdgeListGraph<kk2::AdjList>);\n\
      static_assert(kk2::graph::AdjacencyGraph<kk2::AdjList>);\nstatic_assert(kk2::graph::UnweightedGraph<kk2::AdjList>);\n\
      static_assert(kk2::graph::UndirectedGraph<kk2::AdjList>);\n\nstatic_assert(kk2::graph::WeightedGraph<kk2::DWAdjList<int>>);\n\
      static_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjList<int>>);\nstatic_assert(kk2::graph::WeightedDirectedGraph<kk2::DWAdjList<int>>);\n\
      static_assert(kk2::graph::WeightedDirectedEdgeListGraph<kk2::DWAdjList<int>>);\n\
      \nstatic_assert(kk2::graph::StaticGraph<kk2::SAdjList>);\nstatic_assert(kk2::graph::WeightedEdgeListGraph<kk2::SDWAdjList<int>>);\n\
      static_assert(kk2::graph::WeightedUndirectedEdgeListGraph<kk2::SWAdjList<int>>);\n\
      \nstatic_assert(kk2::graph::Graph<kk2::DWAdjMat<int>>);\nstatic_assert(kk2::graph::WeightedEdgeListGraph<kk2::DWAdjMat<int>>);\n\
      static_assert(!kk2::graph::AdjacencyGraph<kk2::DWAdjMat<int>>);\nstatic_assert(!kk2::graph::WeightedGraph<kk2::DWAdjMat<int>>);\n\
      \nstatic_assert(kk2::graph::VertexAdjacency<std::vector<std::vector<int>>>);\n\
      \nint main() {}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/unit_test/type_traits/graph/graph.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases: []
  timestamp: '2026-09-07 22:25:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/type_traits/graph/graph.test.cpp
layout: document
---
