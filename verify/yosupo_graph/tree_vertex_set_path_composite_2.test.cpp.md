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
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/rev_op.hpp
    title: math/monoid/rev_op.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \ \n\n#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#include <cassert>\n\
    #include <functional>\n#include <utility>\n#include <vector>\n\nnamespace kk2\
    \ {\n\ntemplate <typename G> struct HeavyLightDecomposition {\n    static_assert(!G::directed,\
    \ \"HeavyLightDecomposition requires undirected graph\");\n\n    G &g;\n    int\
    \ root, id;\n    std::vector<int> sz, in, out, head, par, dep, edge_idx;\n\n \
    \   // e.id\u306Fedges\u306Eindex\u3067\u306A\u3044\u3068\u3044\u3051\u306A\u3044\
    \n    HeavyLightDecomposition(G &g_, int root_ = 0)\n        : g(g_),\n      \
    \    root(root_),\n          id(0),\n          sz(g.size(), 0),\n          in(g.size(),\
    \ -1),\n          out(g.size(), -1),\n          head(g.size(), root),\n      \
    \    par(g.size(), root),\n          dep(g.size(), 0),\n          edge_idx(g.size()\
    \ - 1, -1) {\n        init();\n    }\n\n    int get_edge_idx(int i) const { return\
    \ edge_idx[i]; }\n\n    std::pair<int, int> get_node_idx(int u) const { return\
    \ std::make_pair(in[u], out[u]); }\n\n    template <typename F> void path_query(int\
    \ u, int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n  \
    \      for (auto &[a, b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n\
    \            s > t ? f(t, s) : f(s, t);\n        }\n        if (is_node_query)\
    \ f(in[l], in[l] + 1);\n        for (auto &[a, b] : descend(l, v)) {\n       \
    \     int s = a, t = b + 1;\n            s > t ? f(t, s) : f(s, t);\n        }\n\
    \    }\n\n    template <typename F>\n    void path_noncommutative_query(int u,\
    \ int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n     \
    \   for (auto &[a, b] : ascend(u, l)) f(a + 1, b);\n        if (is_node_query)\
    \ f(in[l], in[l] + 1);\n        for (auto &[a, b] : descend(l, v)) f(a, b + 1);\n\
    \    }\n\n    template <typename F> void subtree_query(int u, bool is_vertex_query,\
    \ const F &f) {\n        f(in[u] + (int)!is_vertex_query, out[u]);\n    }\n\n\
    \    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n   \
    \         if (in[u] < in[v]) std::swap(u, v);\n            u = par[head[u]];\n\
    \        }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int\
    \ u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n\n  private:\n\
    \    void init() {\n        auto dfs_sz = [&](auto self, int now) -> void {\n\
    \            sz[now] = 1;\n            for (auto &e : g[now]) {\n            \
    \    if ((int)e == par[now]) {\n                    if (g[now].size() >= 2 and\
    \ e == g[now][0]) std::swap(e, g[now][1]);\n                    else continue;\n\
    \                }\n                par[(int)e] = now;\n                dep[(int)e]\
    \ = dep[now] + 1;\n                self(self, (int)e);\n                sz[now]\
    \ += sz[(int)e];\n                if (sz[(int)e] > sz[(int)g[now][0]]) std::swap(e,\
    \ g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz, root);\n\n  \
    \      auto dfs_hld = [&](auto self, int now) -> void {\n            in[now] =\
    \ id++;\n            for (auto &e : g[now]) {\n                if ((int)e == par[now])\
    \ continue;\n                head[(int)e] = ((int)e == (int)g[now][0] ? head[now]\
    \ : (int)e);\n                edge_idx[e.id] = id;\n                self(self,\
    \ (int)e);\n            }\n            out[now] = id;\n        };\n        dfs_hld(dfs_hld,\
    \ root);\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (head[u] != head[v]) {\n            res.emplace_back(in[u], in[head[u]]);\n\
    \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(in[u],\
    \ in[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (head[u] == head[v]) return {std::make_pair(in[u] + 1, in[v])};\n      \
    \  auto res = descend(u, par[head[v]]);\n        res.emplace_back(in[head[v]],\
    \ in[v]);\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"\
    graph/graph.hpp\"\n\n\n\n#line 5 \"graph/graph.hpp\"\n#include <type_traits>\n\
    #line 8 \"graph/graph.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include\
    \ <istream>\n#include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\
    \n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
    \ namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\
    \n#include <cstdint>\n#include <iostream>\n#line 8 \"modint/mont.hpp\"\n\n#line\
    \ 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\
    \nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value\n      \
    \                            or std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T> using is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
    template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, is_integral_t<T> * = nullptr> constexpr\
    \ LazyMontgomeryModInt(T b)\n        : _v(reduce(u64(b % p + p) * n2)) {}\n\n\
    \    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r))\
    \ * p) >> 32; }\n    constexpr mint &operator++() { return *this += 1; }\n   \
    \ constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr bool\
    \ operator==(const mint &b) const {\n        return (_v >= p ? _v - p : _v) ==\
    \ (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
    \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
    \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const mint\
    \ &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const mint\
    \ &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T> constexpr\
    \ mint pow(T n) const {\n        mint ret(1), mul(*this);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const {\n \
    \       assert(*this != mint(0));\n        return pow(p - 2);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"math/monoid/affine.hpp\"\n\n\n\n#line 5 \"math/monoid/affine.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct Affine\
    \ {\n    static constexpr bool commutative = false;\n    using M = Affine;\n \
    \   S a, b; // x \\mapsto ax + b\n\n    Affine() : a(S(1)), b(S(0)) {};\n    Affine(S\
    \ a, S b) : a(a), b(b) {}\n    inline S eval(S x) const { return a * x + b; }\n\
    \    // l \\circ r\n    inline static M op(M l, M r) { return M(l.a * r.a, l.a\
    \ * r.b + l.b); }\n    inline static M unit() { return M(); }\n    inline static\
    \ M inv(M f) { return M(S(1) / f.a, -f.b / f.a); }\n    bool operator==(const\
    \ M &rhs) const { return a == rhs.a and b == rhs.b; }\n    bool operator!=(const\
    \ M &rhs) const { return a != rhs.a or b != rhs.b; }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const M &x) {\n        return os << x.a << \" \" << x.b;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, M &x) {\n        return is >> x.a >> x.b;\n    }\n};\n\n} // namespace\
    \ monoid\n\n} // namespace kk2\n\n\n#line 1 \"math/monoid/rev_op.hpp\"\n\n\n\n\
    namespace kk2 {\n\nnamespace monoid {\n\ntemplate <class T> struct ReverseOp :\
    \ public T {\n    static constexpr bool commutative = T::commutative;\n    using\
    \ M = ReverseOp;\n    using base = T;\n    using T::T;\n    ReverseOp(const T\
    \ &t) : T(t) {}\n    inline static M op(M l, M r) {\n        return static_cast<M>(T::op(static_cast<T>(r),\
    \ static_cast<T>(l)));\n    }\n    inline static M unit() { return static_cast<M>(T::unit());\
    \ }\n\n    bool operator==(const M &rhs) const { return static_cast<T>(*this)\
    \ == static_cast<T>(rhs); }\n    bool operator!=(const M &rhs) const { return\
    \ static_cast<T>(*this) != static_cast<T>(rhs); }\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const M &x) {\n        os << static_cast<T>(x);\n        return os;\n    }\n\
    \    template <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream\
    \ &operator>>(IStream &is, M &x) {\n        is >> static_cast<T &>(x);\n     \
    \   return is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n\
    #line 1 \"segment_tree/seg.hpp\"\n\n\n\n#line 7 \"segment_tree/seg.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegmentTree {\n\
    \  public:\n    SegmentTree() : SegmentTree(0) {}\n\n    SegmentTree(int n) :\
    \ _n(n) {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n))\
    \ log++;\n        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n\
    \    }\n\n    template <class... Args> SegmentTree(int n, Args... args)\n    \
    \    : SegmentTree(std::vector<S>(n, S(args...))){};\n\n    SegmentTree(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1U\
    \ << log) < (unsigned int)(_n)) log++;\n        size = 1 << log;\n        d =\
    \ std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
    \        is_built = true;\n        for (int i = size - 1; i >= 1; i--) { update(i);\
    \ }\n    }\n\n    template <class... Args> void init_set(int p, Args... args)\
    \ {\n        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
    \ + size] = S(args...);\n    }\n\n    using Monoid = S;\n\n    static S Op(S l,\
    \ S r) { return op(l, r); }\n\n    static S MonoidUnit() { return e(); }\n\n \
    \   template <class... Args> void set(int p, Args... args) {\n        assert(0\
    \ <= p && p < _n);\n        assert(is_built);\n        p += size;\n        d[p]\
    \ = S(args...);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\
    \n    S get(int p) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        assert(is_built);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() {\n        assert(is_built);\n\
    \        return d[1];\n    }\n\n    // return r s.t.\n    // r = l or f(op(a[l],\
    \ a[l+1], ..., a[r-1])) == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))\
    \   == false\n    template <bool (*f)(S)> int max_right(int l) {\n        return\
    \ max_right(l, [](S x) { return f(x); });\n    }\n\n    template <class F> int\
    \ max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        assert(is_built);\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    // return l s.t.\n    //\
    \ l = r or f(op(a[l], a[l], ..., a[r-1]))   == true\n    // l = 0 or f(op(a[l-1],\
    \ a[l], ..., a[r-1])) == false\n    template <bool (*f)(S)> int min_left(int r)\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template\
    \ <class F> int min_left(int r, F f) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(f(e()));\n        assert(is_built);\n        if (r == 0) return\
    \ 0;\n        r += size;\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    r = (2 * r + 1);\n\
    \                    if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n    bool is_built = false;\n\n\
    \    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\ntemplate\
    \ <class M> using SegmentTreeS = SegmentTree<M, M::op, M::unit>;\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include <chrono>\n\
    #include <cmath>\n#include <deque>\n#line 12 \"template/template.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#line 26\
    \ \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line\
    \ 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\n\n\
    using u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include\
    \ <cctype>\n#line 6 \"template/fastio.hpp\"\n#include <cstdio>\n#include <fstream>\n\
    #line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n\
    \  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos\
    \ = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n \
    \   FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
    \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
    \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
    \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if (end\
    \ == 0) is_eof = true;\n            pos = 0;\n        }\n        return buf[pos];\n\
    \    }\n\n    void skip_space() {\n        while (isspace(now())) ++pos;\n   \
    \ }\n\n    template <class T, is_unsigned_t<T> * = nullptr> T next_unsigned_integral()\
    \ {\n        skip_space();\n        T res{};\n        while (isdigit(now())) {\n\
    \            res = res * 10 + (now() - '0');\n            ++pos;\n        }\n\
    \        return res;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ T next_signed_integral() {\n        skip_space();\n        if (now() == '-')\
    \ {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 10 \"verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    using mint = kk2::mont998;\n    using\
    \ M1 = kk2::monoid::ReverseOp<kk2::monoid::Affine<mint>>;\n    using M2 = kk2::monoid::Affine<mint>;\n\
    \    \n    int n, q;\n    kin >> n >> q;\n\n    vc<M1> a(n);\n    kin >> a;\n\n\
    \    kk2::AdjList g(n, n - 1);\n    g.input(kin);\n    kk2::HeavyLightDecomposition\
    \ hld(g);\n    kk2::SegmentTreeS<M1> seg1(hld.id);\n    kk2::SegmentTreeS<M2>\
    \ seg2(hld.id);\n    rep (i, n) {\n        auto [l, r] = hld.get_node_idx(i);\n\
    \        seg1.init_set(l, a[i]), seg2.init_set(l, a[i]);\n    }\n    seg1.build(),\
    \ seg2.build();\n\n    rep (q) {\n        int type;\n        kin >> type;\n  \
    \      if (type == 0) {\n            int p;\n            mint c, d;\n        \
    \    kin >> p >> c >> d;\n            auto [l, r] = hld.get_node_idx(p);\n   \
    \         seg1.set(l, c, d), seg2.set(l, c, d);\n        } else {\n          \
    \  int u, v;\n            mint x;\n            kin >> u >> v >> x;\n         \
    \   M1 f = M1::unit();\n            hld.path_noncommutative_query(u, v, 1, [&](int\
    \ l, int r) {\n                if (l > r) f = M1::op(f, seg2.prod(r, l));\n  \
    \              else f = M1::op(f, seg1.prod(l, r));\n            });\n       \
    \     kout << f.eval(x) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \ \n\n#include \"../../graph/tree/heavy_light_decomposition.hpp\"\n#include \"\
    ../../graph/graph.hpp\"\n#include \"../../modint/mont.hpp\"\n#include \"../../math/monoid/affine.hpp\"\
    \n#include \"../../math/monoid/rev_op.hpp\"\n#include \"../../segment_tree/seg.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    using mint = kk2::mont998;\n    using M1 = kk2::monoid::ReverseOp<kk2::monoid::Affine<mint>>;\n\
    \    using M2 = kk2::monoid::Affine<mint>;\n    \n    int n, q;\n    kin >> n\
    \ >> q;\n\n    vc<M1> a(n);\n    kin >> a;\n\n    kk2::AdjList g(n, n - 1);\n\
    \    g.input(kin);\n    kk2::HeavyLightDecomposition hld(g);\n    kk2::SegmentTreeS<M1>\
    \ seg1(hld.id);\n    kk2::SegmentTreeS<M2> seg2(hld.id);\n    rep (i, n) {\n \
    \       auto [l, r] = hld.get_node_idx(i);\n        seg1.init_set(l, a[i]), seg2.init_set(l,\
    \ a[i]);\n    }\n    seg1.build(), seg2.build();\n\n    rep (q) {\n        int\
    \ type;\n        kin >> type;\n        if (type == 0) {\n            int p;\n\
    \            mint c, d;\n            kin >> p >> c >> d;\n            auto [l,\
    \ r] = hld.get_node_idx(p);\n            seg1.set(l, c, d), seg2.set(l, c, d);\n\
    \        } else {\n            int u, v;\n            mint x;\n            kin\
    \ >> u >> v >> x;\n            M1 f = M1::unit();\n            hld.path_noncommutative_query(u,\
    \ v, 1, [&](int l, int r) {\n                if (l > r) f = M1::op(f, seg2.prod(r,\
    \ l));\n                else f = M1::op(f, seg1.prod(l, r));\n            });\n\
    \            kout << f.eval(x) << \"\\n\";\n        }\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - graph/tree/heavy_light_decomposition.hpp
  - graph/graph.hpp
  - type_traits/io.hpp
  - graph/edge.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - math/monoid/rev_op.hpp
  - segment_tree/seg.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
- /verify/verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp.html
title: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
---
