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
    path: template/fastio.hpp
    title: template/fastio.hpp
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
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define rep1(a) for (i64 _\
    \ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n\
    #define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a)\
    \ for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdio>\n#line 9 \"template/fastio.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace fastio {\n\n#define INPUT_FILE \"in.txt\"\n#define\
    \ OUTPUT_FILE \"out.txt\"\n\nstruct Scanner {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = INPUT_BUF;\n    static char buf[INPUT_BUF];\n\
    \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
    \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (pos == INPUT_BUF)\
    \ {\n            size_t len = fread(buf, 1, INPUT_BUF, fp);\n            if (len\
    \ != INPUT_BUF) buf[len] = '\\0';\n            pos = 0;\n        }\n        return\
    \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
    \ ++pos;\n    }\n\n    uint32_t next_u32() {\n        skip_space();\n        uint32_t\
    \ res = 0;\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    int32_t\
    \ next_i32() {\n        skip_space();\n        if (now() == '-') {\n         \
    \   ++pos;\n            return (int32_t)(-next_u32());\n        } else return\
    \ (int32_t)next_u32();\n    }\n\n    uint64_t next_u64() {\n        skip_space();\n\
    \        uint64_t res = 0;\n        while (isdigit(now())) {\n            res\
    \ = res * 10 + (now() - '0');\n            ++pos;\n        }\n        return res;\n\
    \    }\n\n    int64_t next_i64() {\n        skip_space();\n        if (now() ==\
    \ '-') {\n            ++pos;\n            return (int64_t)(-next_u64());\n   \
    \     } else return (int64_t)next_u64();\n    }\n\n    __uint128_t next_u128()\
    \ {\n        skip_space();\n        __uint128_t res = 0;\n        while (isdigit(now()))\
    \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n       \
    \ }\n        return res;\n    }\n\n    __int128_t next_i128() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return (__int128_t)(-next_u128());\n\
    \        } else return (__int128_t)next_u128();\n    }\n\n    char next_char()\
    \ {\n        skip_space();\n        auto res = now();\n        ++pos;\n      \
    \  return res;\n    }\n\n    std::string next_string() {\n        skip_space();\n\
    \        std::string res;\n        while (true) {\n            char c = now();\n\
    \            if (isspace(c) or c == '\\0') break;\n            res.push_back(now());\n\
    \            ++pos;\n        }\n        return res;\n    }\n\n    Scanner &operator>>(int\
    \ &x) {\n        x = next_i32();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned int &x) {\n        x = next_u32();\n        return *this;\n\
    \    }\n\n    Scanner &operator>>(long &x) {\n        x = next_i64();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(long long &x) {\n        x\
    \ = next_i64();\n        return *this;\n    }\n\n    Scanner &operator>>(unsigned\
    \ long &x) {\n        x = next_u64();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned long long &x) {\n        x = next_u64();\n        return\
    \ *this;\n    }\n\n    Scanner &operator>>(__int128_t &x) {\n        x = next_i128();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(__uint128_t &x) {\n \
    \       x = next_u128();\n        return *this;\n    }\n\n    Scanner &operator>>(char\
    \ &x) {\n        x = next_char();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(std::string &x) {\n        x = next_string();\n        return *this;\n\
    \    }\n};\n\nstruct Printer {\n  private:\n    static char helper[1000][4];\n\
    \    static char leading_zero[1000][4];\n    constexpr static size_t OUTPUT_BUF\
    \ = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos = 0;\n    FILE\
    \ *fp;\n\n    static constexpr uint32_t pow10_32(uint32_t n) { return n == 0 ?\
    \ 1 : pow10_32(n - 1) * 10; }\n\n    static constexpr uint64_t pow10_64(uint32_t\
    \ n) { return n == 0 ? 1 : pow10_64(n - 1) * 10; }\n\n    static constexpr __uint128_t\
    \ pow10_128(uint32_t n) {\n        return n == 0 ? 1 : pow10_128(n - 1) * 10;\n\
    \    }\n\n    template <class T, class U> static constexpr void div_mod(T &a,\
    \ U &b, U mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n    static\
    \ void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0; i < 1000;\
    \ ++i) {\n            leading_zero[i][0] = i / 100 + '0';\n            leading_zero[i][1]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][2] = i % 10 + '0';\n     \
    \       leading_zero[i][3] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 100) helper[i][j++] = i / 100 + '0';\n            if (i >= 10) helper[i][j++]\
    \ = i / 10 % 10 + '0';\n            helper[i][j++] = i % 10 + '0';\n         \
    \   helper[i][j] = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout)\
    \ { init(); }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init();\
    \ }\n\n    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n\
    \    }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos =\
    \ 0;\n    }\n\n    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n\
    \        buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n      \
    \  while (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n   \
    \     uint32_t y;\n        if (x >= pow10_32(9)) {\n            div_mod(y, x,\
    \ pow10_32(9));\n            put_cstr(helper[y]);\n            div_mod(y, x, pow10_32(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_32(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_32(6)) {\n            div_mod(y, x, pow10_32(6));\n\
    \            put_cstr(helper[y]);\n            div_mod(y, x, pow10_32(3));\n \
    \           put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_32(3)) {\n            div_mod(y, x, pow10_32(3));\n\
    \            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n  \
    \      } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n \
    \       if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n \
    \       } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n        uint64_t\
    \ y;\n        if (x >= pow10_64(18)) {\n            div_mod(y, x, pow10_64(18));\n\
    \            put_cstr(helper[y]);\n            div_mod(y, x, pow10_64(15));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(12));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(9));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_64(9)) {\n            div_mod(y, x, pow10_64(9));\n\
    \            put_u32(uint32_t(y));\n            div_mod(y, x, pow10_64(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_u32(uint32_t(x));\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     __uint128_t y;\n        if (x >= pow10_128(36)) {\n            div_mod(y,\
    \ x, pow10_128(36));\n            put_cstr(helper[y]);\n            div_mod(y,\
    \ x, pow10_128(33));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(30));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(27));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(24));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(21));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(18));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(15));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(12));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(9));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(6));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(3));\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_128(18)) {\n            div_mod(y, x, pow10_128(18));\n\
    \            put_u64(uint64_t(y));\n            div_mod(y, x, pow10_128(15));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(12));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(9));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_u64(uint64_t(x));\n    }\n\n    void put_i128(__int128_t x)\
    \ {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
    \        } else put_u128(x);\n    }\n\n    Printer &operator<<(int x) {\n    \
    \    put_i32(x);\n        return *this;\n    }\n\n    Printer &operator<<(unsigned\
    \ int x) {\n        put_u32(x);\n        return *this;\n    }\n\n    Printer &operator<<(long\
    \ x) {\n        put_i64(x);\n        return *this;\n    }\n\n    Printer &operator<<(long\
    \ long x) {\n        put_i64(x);\n        return *this;\n    }\n\n    Printer\
    \ &operator<<(unsigned long x) {\n        put_u64(x);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(unsigned long long x) {\n        put_u64(x);\n\
    \        return *this;\n    }\n\n    Printer &operator<<(__int128_t x) {\n   \
    \     put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(__uint128_t\
    \ x) {\n        put_u128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar\
    \ Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[1000][4];\nchar Printer::leading_zero[1000][4];\n\
    \n} // namespace fastio\n\n} // namespace kk2\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\n\
    struct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \    }\n} iosetup;\n#define kin std::cin\n#define kout std::cout\n#elif defined(KK2)\n\
    kk2::fastio::Scanner kin(INPUT_FILE);\nkk2::fastio::Printer kout(OUTPUT_FILE);\n\
    #define endl '\\n'\n#else\nkk2::fastio::Scanner kin;\nkk2::fastio::Printer kout;\n\
    #define endl '\\n'\n#endif\n\n\n#line 112 \"template/template.hpp\"\n\ntemplate\
    \ <class OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\nvoid Yes(bool b = 1) {\n    kout << (b ? \"Yes\\n\" : \"\
    No\\n\");\n}\n\nvoid No(bool b = 1) {\n    kout << (b ? \"No\\n\" : \"Yes\\n\"\
    );\n}\n\nvoid YES(bool b = 1) {\n    kout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\
    \nvoid NO(bool b = 1) {\n    kout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid\
    \ yes(bool b = 1) {\n    kout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool\
    \ b = 1) {\n    kout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n\n#line 6 \"verify/yosupo_graph/tree_lca.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  kk2::AdjList g(n, false);\n    rep (i, n - 1) {\n        int p;\n        kin\
    \ >> p;\n        g.add_edge(i + 1, p);\n    }\n    kk2::HeavyLightDecomposition<kk2::AdjList>\
    \ hld(g);\n    rep (q) {\n        int u, v;\n        kin >> u >> v;\n        kout\
    \ << hld.lca(u, v) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\" \n\n#include \"../../graph/graph.hpp\"\
    \n#include \"../../graph/tree/heavy_light_decomposition.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  kk2::AdjList g(n, false);\n    rep (i, n - 1) {\n        int p;\n        kin\
    \ >> p;\n        g.add_edge(i + 1, p);\n    }\n    kk2::HeavyLightDecomposition<kk2::AdjList>\
    \ hld(g);\n    rep (q) {\n        int u, v;\n        kin >> u >> v;\n        kout\
    \ << hld.lca(u, v) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - graph/tree/heavy_light_decomposition.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/tree_lca.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 04:00:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_graph/tree_lca.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/tree_lca.test.cpp
- /verify/verify/yosupo_graph/tree_lca.test.cpp.html
title: verify/yosupo_graph/tree_lca.test.cpp
---
