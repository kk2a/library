---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/bcc.hpp
    title: graph/bcc.hpp
  - icon: ':question:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"verify/yosupo_graph/graph_bcc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 1 \"graph/bcc.hpp\"\
    \n\n\n\n#include <functional>\n#include <vector>\n\n#line 1 \"graph/lowlink.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#line 7 \"graph/lowlink.hpp\"\
    \n#include <type_traits>\n#line 9 \"graph/lowlink.hpp\"\n\nnamespace kk2 {\n\n\
    template <class G> struct LowLink {\n    static_assert(!G::directed, \"LowLink\
    \ requires undirected graph\");\n\n    int n, m;\n    const G &g;\n    std::vector<int>\
    \ ord, low;\n    std::vector<bool> root, used_on_dfs_tree;\n    std::vector<int>\
    \ bridges, articulations;\n\n    LowLink(const G &g_)\n        : n(g_.num_vertices()),\n\
    \          m(g_.num_edges()),\n          g(g_),\n          ord(n, -1),\n     \
    \     low(n, -1),\n          root(n, false),\n          used_on_dfs_tree(m, false)\
    \ {\n        init();\n    }\n\n  private:\n    // v is a child of u in DFS tree\n\
    \    // edge(u, v) is a bridge <=> ord[u] < low[v]\n\n    // u is an articulation\
    \ point <=> (u is root and u has two or more children) or\n    // there exists\
    \ a v which is a child of u in DFS tree and ord[u] <= low[v]\n\n    void init()\
    \ {\n        int k = 0;\n        auto dfs = [&](auto self, int u, int ei = -1)\
    \ -> int {\n            low[u] = ord[u] = k++;\n            bool is_articulation\
    \ = false;\n            int count = 0;\n            for (auto &&e : g[u]) {\n\
    \                if (e.id == ei) continue;\n                if (ord[e.to] == -1)\
    \ {\n                    ++count;\n                    used_on_dfs_tree[e.id]\
    \ = true;\n                    low[u] = std::min(low[u], self(self, e.to, e.id));\n\
    \                    if (ei != -1 and ord[u] <= low[e.to]) is_articulation = true;\n\
    \                    if (ord[u] < low[e.to]) bridges.emplace_back(e.id);\n   \
    \             }\n                // back edge\n                else if (ord[e.to]\
    \ < ord[u]) {\n                    low[u] = std::min(low[u], ord[e.to]);\n   \
    \             }\n            }\n            if (ei == -1 and count >= 2) is_articulation\
    \ = true;\n            if (is_articulation) articulations.emplace_back(u);\n \
    \           return low[u];\n        };\n        for (int u = 0; u < n; u++)\n\
    \            if (ord[u] == -1) {\n                dfs(dfs, u);\n             \
    \   root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\n#line\
    \ 8 \"graph/bcc.hpp\"\n\nnamespace kk2 {\n\ntemplate <class G> struct BCC : LowLink<G>\
    \ {\n    BCC(const G &g_) : LowLink<G>(g_) { init_bcc(); }\n\n    std::vector<std::vector<int>>\
    \ group_e;\n    std::vector<int> comp_e;\n\n  private:\n    void init_bcc() {\n\
    \        comp_e = std::vector<int>(this->m, -1);\n        auto add = [&](int ei,\
    \ int k) {\n            group_e[k].emplace_back(ei);\n            comp_e[ei] =\
    \ k;\n        };\n        auto dfs = [&](auto self, int u, int k = -1, int ei\
    \ = -1) -> void {\n            for (auto &e : this->g[u]) {\n                if\
    \ (e.id == ei) continue;\n                if (this->used_on_dfs_tree[e.id]) {\n\
    \                    int nk = k;\n                    if (this->low[e.to] >= this->ord[u])\n\
    \                        nk = group_e.size(), group_e.emplace_back();\n      \
    \              add(e.id, nk);\n                    self(self, e.to, nk, e.id);\n\
    \                }\n                // back edge\n                else if (this->ord[e.to]\
    \ < this->ord[u]) {\n                    add(e.id, k);\n                }\n  \
    \          }\n        };\n        for (int u = 0; u < this->n; u++)\n        \
    \    if (this->root[u]) { dfs(dfs, u); }\n    }\n\n  public:\n    std::vector<std::vector<int>>\
    \ get_bcc_vertices() {\n        std::vector<bool> buf1(this->n), buf2(this->n);\n\
    \        std::vector<std::vector<int>> res;\n        res.reserve(group_e.size());\n\
    \        for (auto &bc : group_e) {\n            if (bc.empty()) continue;\n \
    \           int k = (int)res.size();\n            res.emplace_back();\n      \
    \      for (auto &ei : bc) {\n                auto e = this->g.edges[ei];\n  \
    \              int fr = e.from, to = e.to;\n                if (!buf2[fr]) {\n\
    \                    res[k].emplace_back(fr);\n                    buf2[fr] =\
    \ true;\n                }\n                if (!buf2[to]) {\n               \
    \     res[k].emplace_back(to);\n                    buf2[to] = true;\n       \
    \         }\n                buf1[fr] = buf1[to] = true;\n            }\n    \
    \        for (auto &ei : bc) {\n                auto e = this->g.edges[ei];\n\
    \                int fr = e.from, to = e.to;\n                buf2[fr] = buf2[to]\
    \ = false;\n            }\n        }\n        for (int i = 0; i < this->n; i++)\n\
    \            if (!buf1[i]) {\n                int k = (int)res.size();\n     \
    \           res.emplace_back();\n                res[k].emplace_back(i);\n   \
    \         }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 1\
    \ \"graph/graph.hpp\"\n\n\n\n#line 6 \"graph/graph.hpp\"\n#include <utility>\n\
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
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <deque>\n#line 12 \"template/template.hpp\"\
    \n#include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n\
    #include <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n\
    #line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
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
    \ <cctype>\n#include <cstdint>\n#include <cstdio>\n#include <fstream>\n#include\
    \ <iostream>\n#line 10 \"template/fastio.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
    \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
    \ntemplate <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
    \n} // namespace kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\
    \nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n\
    \    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n\
    \    bool is_eof = false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n\
    \  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file,\
    \ \"r\")) {}\n\n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\
    \n    char now() {\n        if (is_eof) return '\\0';\n        if (pos == end)\
    \ {\n            end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF)\
    \ buf[end] = '\\0';\n            if (end == 0) is_eof = true;\n            pos\
    \ = 0;\n        }\n        return buf[pos];\n    }\n\n    void skip_space() {\n\
    \        while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/yosupo_graph/graph_bcc.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n  \
    \  kk2::AdjList g(n, m);\n    g.input(kin);\n    kk2::BCC<kk2::AdjList> bcc(g);\n\
    \    auto res = bcc.get_bcc_vertices();\n\n    kout << res.size() << \"\\n\";\n\
    \    for (auto &v : res) { kout << v.size() << \" \" << v << \"\\n\"; }\n\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../graph/bcc.hpp\"\n#include \"../../graph/graph.hpp\"\n#include\
    \ \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ n, m;\n    kin >> n >> m;\n    kk2::AdjList g(n, m);\n    g.input(kin);\n  \
    \  kk2::BCC<kk2::AdjList> bcc(g);\n    auto res = bcc.get_bcc_vertices();\n\n\
    \    kout << res.size() << \"\\n\";\n    for (auto &v : res) { kout << v.size()\
    \ << \" \" << v << \"\\n\"; }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/bcc.hpp
  - graph/lowlink.hpp
  - graph/graph.hpp
  - type_traits/io.hpp
  - graph/edge.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/graph_bcc.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_graph/graph_bcc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/graph_bcc.test.cpp
- /verify/verify/yosupo_graph/graph_bcc.test.cpp.html
title: verify/yosupo_graph/graph_bcc.test.cpp
---
