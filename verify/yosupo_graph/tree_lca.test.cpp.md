---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/yosupo_graph/tree_lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\" \n\n#line 1 \"graph/graph.hpp\"\n\n\n\
    \n#include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> struct WeightedEdge\
    \ {\n    int from, to, id;\n    T cost;\n\n    WeightedEdge(int to_, T cost_,\
    \ int from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n\
    \          id(id_),\n          cost(cost_) {}\n\n    WeightedEdge() : from(-1),\
    \ to(-1), id(-1), cost(0) {}\n\n    operator int() const { return to; }\n\n  \
    \  WeightedEdge rev() const { return WeightedEdge(from, cost, to, id); }\n\n \
    \   template <class OStream> friend OStream &operator<<(OStream &os, const WeightedEdge\
    \ &e) {\n        return os << e.from << \" -> \" << e.to << \" : \" << e.cost;\n\
    \    }\n};\ntemplate <class T> using WeightedEdges = std::vector<WeightedEdge<T>>;\n\
    \ntemplate <class T, bool is_directed = false>\nstruct WeightedAdjacencyList :\
    \ std::vector<WeightedEdges<T>> {\n    WeightedAdjacencyList() = default;\n\n\
    \    WeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    WeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<WeightedEdges<T>>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    WeightedAdjacencyList(int n_, const WeightedEdges<T> &edges_, bool is_one_indexed)\n\
    \        : std::vector<WeightedEdges<T>>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, e.cost, m++); }\n    }\n\n    template <class IStream> WeightedAdjacencyList\
    \ &input(IStream &is) {\n        for (int i = 0; i < m; i++) {\n            int\
    \ u, v;\n            T w;\n            is >> u >> v >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge(u, v, w, i);\n        }\n        return *this;\n\
    \    }\n\n    using value_type = T;\n    using edge_type = WeightedEdge<T>;\n\n\
    \    constexpr static bool directed() { return is_directed; }\n\n    int n, m;\n\
    \    bool oneindexed;\n    WeightedEdges<T> edges;\n\n    int num_vertices() const\
    \ { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    WeightedAdjacencyList &inplace_rev() {\n       \
    \ static_assert(is_directed);\n        WeightedEdges<T> rev(m);\n        for (int\
    \ i = 0; i < m; i++) rev[i] = edges[i].rev();\n        edge_clear();\n       \
    \ for (auto &e : rev) _add_edge(e.from, e.to, e.cost, m++);\n        return *this;\n\
    \    }\n\n    WeightedAdjacencyList rev() const {\n        static_assert(is_directed);\n\
    \        WeightedAdjacencyList res(n);\n        res.m = m;\n        for (int i\
    \ = 0; i < m; i++) res._add_edge(edges[i].to, edges[i].from, edges[i].cost, i);\n\
    \        return res;\n    }\n\n    void add_edge(int from, int to, T cost) {\n\
    \        if (oneindexed) --from, --to;\n        _add_edge(from, to, cost, m++);\n\
    \    }\n\n    void add_edge_naive(int from, int to, T cost) { _add_edge(from,\
    \ to, cost, m++); }\n\n  private:\n    void _add_edge(int from, int to, T cost,\
    \ int id) {\n        (*this)[from].emplace_back(to, cost, from, id);\n       \
    \ if constexpr (!is_directed) (*this)[to].emplace_back(from, cost, to, id);\n\
    \        edges.emplace_back(to, cost, from, id);\n    }\n};\n\nstruct UnWeightedEdge\
    \ {\n    int from, to, id;\n\n    UnWeightedEdge(int to_, int from_ = -1, int\
    \ id_ = -1) : from(from_), to(to_), id(id_) {}\n\n    UnWeightedEdge() : from(-1),\
    \ to(-1), id(-1) {}\n\n    operator int() const { return to; }\n\n    UnWeightedEdge\
    \ rev() const { return UnWeightedEdge(from, to, id); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const UnWeightedEdge &e) {\n        return os\
    \ << e.from << \"->\" << e.to;\n    }\n};\n\nusing UnWeightedEdges = std::vector<UnWeightedEdge>;\n\
    \ntemplate <bool is_directed = false, bool is_functional = false>\nstruct UnWeightedAdjacencyList\
    \ : std::vector<UnWeightedEdges> {\n    UnWeightedAdjacencyList() = default;\n\
    \n    UnWeightedAdjacencyList(int n_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(0),\n          oneindexed(is_one_indexed) {}\n\n\
    \    UnWeightedAdjacencyList(int n_, int m_, bool is_one_indexed)\n        : std::vector<UnWeightedEdges>(n_),\n\
    \          n(n_),\n          m(m_),\n          oneindexed(is_one_indexed) {}\n\
    \n    UnWeightedAdjacencyList(int n_, const UnWeightedEdges &edges_, bool is_one_indexed)\n\
    \        : std::vector<UnWeightedEdges>(n_),\n          n(n_),\n          m(0),\n\
    \          oneindexed(is_one_indexed) {\n        for (auto &e : edges_) { _add_edge(e.from,\
    \ e.to, m++); }\n    }\n\n    template <class IStream> UnWeightedAdjacencyList\
    \ &input(IStream &is) {\n        if constexpr (is_functional) {\n            assert(n\
    \ == m);\n            for (int i = 0; i < n; i++) {\n                int u;\n\
    \                is >> u;\n                if (oneindexed) --u;\n            \
    \    _add_edge(i, u, i);\n            }\n        } else {\n            for (int\
    \ i = 0; i < m; i++) {\n                int u, v;\n                is >> u >>\
    \ v;\n                if (oneindexed) --u, --v;\n                _add_edge(u,\
    \ v, i);\n            }\n        }\n        return *this;\n    }\n\n    constexpr\
    \ static bool directed() { return is_directed; }\n\n    constexpr static bool\
    \ functional() { return is_functional; }\n\n    using edge_type = UnWeightedEdge;\n\
    \n    int n, m;\n    bool oneindexed;\n    UnWeightedEdges edges;\n\n    int num_vertices()\
    \ const { return n; }\n\n    int num_edges() const { return m; }\n\n    void edge_clear()\
    \ {\n        for (int i = 0; i < n; i++) (*this)[i].clear();\n        edges.clear();\n\
    \        m = 0;\n    }\n\n    UnWeightedAdjacencyList &inplace_rev() {\n     \
    \   static_assert(is_directed);\n        std::vector<std::pair<int, int>> rev(m);\n\
    \        for (int i = 0; i < m; i++) rev[i] = {edges[i].to, edges[i].from};\n\
    \        edge_clear();\n        for (auto &&[u, v] : rev) _add_edge(u, v, m++);\n\
    \        return *this;\n    }\n\n    UnWeightedAdjacencyList rev() const {\n \
    \       static_assert(is_directed);\n        UnWeightedAdjacencyList res(n);\n\
    \        res.m = m;\n        for (int i = 0; i < m; i++) res._add_edge(edges[i].to,\
    \ edges[i].from, i);\n        return res;\n    }\n\n    void add_edge(int from,\
    \ int to) {\n        if (oneindexed) --from, --to;\n        _add_edge(from, to,\
    \ m++);\n    }\n\n    void add_edge_naive(int from, int to) { _add_edge(from,\
    \ to, m++); }\n\n  private:\n    void _add_edge(int from, int to, int id) {\n\
    \        (*this)[from].emplace_back(to, from, id);\n        if constexpr (!is_directed)\
    \ (*this)[to].emplace_back(from, to, id);\n        edges.emplace_back(to, from,\
    \ id);\n    }\n};\n\ntemplate <typename T> using WAdjList = WeightedAdjacencyList<T,\
    \ false>;\ntemplate <typename T> using DWAdjList = WeightedAdjacencyList<T, true>;\n\
    \nusing AdjList = UnWeightedAdjacencyList<false, false>;\nusing DAdjList = UnWeightedAdjacencyList<true,\
    \ false>;\nusing FAdjList = UnWeightedAdjacencyList<true, true>;\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\n#include\
    \ <functional>\n#line 7 \"graph/tree/heavy_light_decomposition.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <typename G> struct HeavyLightDecomposition {\n    G &g;\n\
    \    int root, id;\n    std::vector<int> sz, in, out, head, par, dep, edge_idx;\n\
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
    template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n//\
    \ #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #line 11 \"template/template.hpp\"\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#line 17 \"template/template.hpp\"\
    \n#include <iomanip>\n#line 19 \"template/template.hpp\"\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#line 36 \"template/template.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate <class\
    \ T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int> = (1 << 30)\
    \ - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);\n\
    template <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1) << 63);\n\
    template <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \nnamespace kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int first,\
    \ Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return\
    \ std::vector<T>(first);\n    } else {\n        return std::vector<decltype(make_vector(sizes...))>(first,\
    \ make_vector(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b\
    \ ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const\
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n \
    \   std::cout << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n \
    \   std::cout << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n\
    \    std::cout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n\
    \    std::cout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n\
    \    std::cout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n\
    \    std::cout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64\
    \ _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\ntemplate <class OStream, class T, class U>\nOStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << ' ' << p.second;\n  \
    \  return os;\n}\n\ntemplate <class IStream, class T, class U> IStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\n\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::vector<T> &v) {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i]\
    \ << (i + 1 == (int)v.size() ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &v)\
    \ {\n    for (auto &x : v) is >> x;\n    return is;\n}\n\n\n#line 6 \"verify/yosupo_graph/tree_lca.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  kk2::AdjList g(n, false);\n    rep (i, n - 1) {\n        int p;\n        cin\
    \ >> p;\n        g.add_edge(i + 1, p);\n    }\n    kk2::HeavyLightDecomposition<kk2::AdjList>\
    \ hld(g);\n    rep (q) {\n        int u, v;\n        cin >> u >> v;\n        cout\
    \ << hld.lca(u, v) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\" \n\n#include \"../../graph/graph.hpp\"\
    \n#include \"../../graph/tree/heavy_light_decomposition.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  kk2::AdjList g(n, false);\n    rep (i, n - 1) {\n        int p;\n        cin\
    \ >> p;\n        g.add_edge(i + 1, p);\n    }\n    kk2::HeavyLightDecomposition<kk2::AdjList>\
    \ hld(g);\n    rep (q) {\n        int u, v;\n        cin >> u >> v;\n        cout\
    \ << hld.lca(u, v) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - graph/tree/heavy_light_decomposition.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/tree_lca.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 16:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_graph/tree_lca.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/tree_lca.test.cpp
- /verify/verify/yosupo_graph/tree_lca.test.cpp.html
title: verify/yosupo_graph/tree_lca.test.cpp
---
