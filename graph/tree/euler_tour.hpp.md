---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':warning:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/euler_tour.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <functional>\n#include <utility>\n#include <vector>\n\n#line 1 \"data_structure/static_rmq.hpp\"\
    \n\n\n\n#line 1 \"math/monoid/min.hpp\"\n\n\n\n#line 5 \"math/monoid/min.hpp\"\
    \n#include <iostream>\n#line 7 \"math/monoid/min.hpp\"\n\nnamespace kk2 {\n\n\
    namespace monoid {\n\ntemplate <class S> struct Min {\n    S a;\n    bool inf;\n\
    \n    constexpr Min() : a(S()), inf(true) {}\n\n    constexpr Min(S a_, bool inf_\
    \ = false) : a(a_), inf(inf_) {}\n\n    operator S() const { return a; }\n\n \
    \   friend std::ostream &operator<<(std::ostream &os, const Min &min) {\n    \
    \    if (min.inf) os << \"inf\";\n        else os << min.a;\n        return os;\n\
    \    }\n\n    friend std::istream &operator>>(std::istream &is, Min &min) {\n\
    \        is >> min.a;\n        min.inf = false;\n        return is;\n    }\n\n\
    \    constexpr Min &operator=(const S &rhs) {\n        a = rhs;\n        inf =\
    \ false;\n        return *this;\n    }\n\n    constexpr Min &add(const S &rhs)\
    \ {\n        if (inf) return *this;\n        a += rhs;\n        return *this;\n\
    \    }\n\n    constexpr Min &update(const S &rhs) {\n        a = rhs;\n      \
    \  inf = false;\n        return *this;\n    }\n\n    constexpr bool is_inf() {\
    \ return inf; }\n};\n\ntemplate <class S> constexpr Min<S> MinOp(Min<S> l, Min<S>\
    \ r) {\n    if (r.inf) return l;\n    if (l.inf) return r;\n    l.a = std::min(l.a,\
    \ r.a);\n    return l;\n}\n\ntemplate <class S> constexpr Min<S> MinUnit() {\n\
    \    constexpr static Min<S> e = Min<S>();\n    return e;\n}\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nconstexpr std::vector<monoid::Min<S>>\
    \ GetVecMin(int n, Args... args) {\n    return std::vector<monoid::Min<S>>(n,\
    \ monoid::Min<S>(args...));\n}\n\ntemplate <class S, class... Args>\nconstexpr\
    \ std::vector<std::vector<monoid::Min<S>>> GetVecMin2D(int h, int w, Args... args)\
    \ {\n    return std::vector<std::vector<monoid::Min<S>>>(h, GetVecMin(w, args...));\n\
    }\n\n} // namespace kk2\n\n\n#line 1 \"data_structure/sparse_table.hpp\"\n\n\n\
    \n#include <cassert>\n#line 6 \"data_structure/sparse_table.hpp\"\n\nnamespace\
    \ kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct SparseTable {\n    SparseTable() = default;\n\n    SparseTable(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1\
    \ << log) < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n \
    \       for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        for (int i =\
    \ 1; i <= log; i++) {\n            for (int j = 0; j + (1 << i) <= _n; j++) {\n\
    \                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n\n    using Monoid = S;\n\n    static\
    \ S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit() { return e();\
    \ }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r\
    \ <= _n);\n        if (l == r) return e();\n        int i = 31 ^ __builtin_clz(r\
    \ - l);\n        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n  \
    \  S get(int i) const {\n        assert(0 <= i && i < _n);\n        return table[0][i];\n\
    \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
    \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
    \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        int left = l - 1, right = _n;\n    \
    \    while (right - left > 1) {\n            int mid = (left + right) >> 1;\n\
    \            if (f(prod(l, mid))) left = mid;\n            else right = mid;\n\
    \        }\n        return right;\n    }\n\n    // return l s.t.\n    // l = r\
    \ or f(op(a[l], a[l+1], ..., a[r-1])) == false\n    // l = 0 or f(op(a[l], a[l+1],\
    \ ..., a[r]))   == true\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        int left = -1,\
    \ right = r;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n            else\
    \ left = mid;\n        }\n        return right;\n    }\n\n  private:\n    int\
    \ _n, log;\n    std::vector<std::vector<S>> table;\n};\n\n} // namespace kk2\n\
    \n\n#line 6 \"data_structure/static_rmq.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S>\nusing StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;\n\
    \n} // namespace kk2\n\n\n#line 10 \"graph/tree/euler_tour.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <typename G> struct EulerTour {\n    const G &g;\n    int\
    \ root, id;\n    std::vector<int> in, out, par;\n    std::vector<int> edge_in,\
    \ edge_out;\n\n    EulerTour(const G &g_, int root_ = 0)\n        : g(g_),\n \
    \         root(root_),\n          id(0),\n          in(g.size(), -1),\n      \
    \    out(g.size(), -1),\n          par(g.size(), root),\n          edge_in(g.size()\
    \ - 1, -1),\n          edge_out(g.size() - 1, -1) {\n        init();\n    }\n\n\
    \    std::pair<int, int> get_edge_idx(int i) const {\n        return std::make_pair(edge_in[i],\
    \ edge_out[i]);\n    }\n\n    std::pair<int, int> get_node_idx(int u) const {\
    \ return std::make_pair(in[u], out[u]); }\n\n    int lca(int u, int v) const {\n\
    \        if (in[u] > in[v]) std::swap(u, v);\n        return std::pair<int, int>(rmq.prod(in[u],\
    \ in[v] + 1)).second;\n    }\n\n    int dist(int u, int v) const {\n        int\
    \ depu = std::pair<int, int>(rmq.get(in[u])).first;\n        int depv = std::pair<int,\
    \ int>(rmq.get(in[v])).first;\n        return depu + depv - 2 * std::pair<int,\
    \ int>(rmq.get(in[lca(u, v)])).first;\n    }\n\n    template <typename F> void\
    \ path_query(int u, int v, bool is_node_query, const F &f) {\n        int l =\
    \ lca(u, v);\n        f(in[l] + (int)!is_node_query, in[u] + 1);\n        f(in[l]\
    \ + 1, in[v] + 1);\n    }\n\n    template <typename F> void subtree_query(int\
    \ u, bool is_node_query, const F &f) {\n        f(in[u] + (int)!is_node_query,\
    \ out[u]);\n    }\n\n  private:\n    StaticRMQ<std::pair<int, int>> rmq;\n\n \
    \   void init() {\n        auto rmq_init = GetVecMin<std::pair<int, int>>(2 *\
    \ g.size());\n        auto dfs = [&](auto self, int now, int pre, int dep) ->\
    \ void {\n            in[now] = id;\n            rmq_init[id++] = {dep, now};\n\
    \            for (auto &&e : g[now]) {\n                if ((int)e == pre) continue;\n\
    \                par[(int)e] = now;\n                edge_in[e.id] = id;\n   \
    \             self(self, e, now, dep + 1);\n                edge_out[e.id] = id++;\n\
    \            }\n            out[now] = id;\n            rmq_init[id] = {dep -\
    \ 1, pre};\n        };\n        dfs(dfs, root, -1, 0);\n        for (int i = 0;\
    \ i < (int)g.size(); i++) {\n            if (in[i] == -1) dfs(dfs, i, -1, 0);\n\
    \        }\n        rmq = StaticRMQ<std::pair<int, int>>(rmq_init);\n    }\n};\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TREE_EULER_TOUR_HPP\n#define GRAPH_TREE_EULER_TOUR_HPP 1\n\n\
    #include <algorithm>\n#include <functional>\n#include <utility>\n#include <vector>\n\
    \n#include \"../../data_structure/static_rmq.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename G> struct EulerTour {\n    const G &g;\n    int root, id;\n    std::vector<int>\
    \ in, out, par;\n    std::vector<int> edge_in, edge_out;\n\n    EulerTour(const\
    \ G &g_, int root_ = 0)\n        : g(g_),\n          root(root_),\n          id(0),\n\
    \          in(g.size(), -1),\n          out(g.size(), -1),\n          par(g.size(),\
    \ root),\n          edge_in(g.size() - 1, -1),\n          edge_out(g.size() -\
    \ 1, -1) {\n        init();\n    }\n\n    std::pair<int, int> get_edge_idx(int\
    \ i) const {\n        return std::make_pair(edge_in[i], edge_out[i]);\n    }\n\
    \n    std::pair<int, int> get_node_idx(int u) const { return std::make_pair(in[u],\
    \ out[u]); }\n\n    int lca(int u, int v) const {\n        if (in[u] > in[v])\
    \ std::swap(u, v);\n        return std::pair<int, int>(rmq.prod(in[u], in[v] +\
    \ 1)).second;\n    }\n\n    int dist(int u, int v) const {\n        int depu =\
    \ std::pair<int, int>(rmq.get(in[u])).first;\n        int depv = std::pair<int,\
    \ int>(rmq.get(in[v])).first;\n        return depu + depv - 2 * std::pair<int,\
    \ int>(rmq.get(in[lca(u, v)])).first;\n    }\n\n    template <typename F> void\
    \ path_query(int u, int v, bool is_node_query, const F &f) {\n        int l =\
    \ lca(u, v);\n        f(in[l] + (int)!is_node_query, in[u] + 1);\n        f(in[l]\
    \ + 1, in[v] + 1);\n    }\n\n    template <typename F> void subtree_query(int\
    \ u, bool is_node_query, const F &f) {\n        f(in[u] + (int)!is_node_query,\
    \ out[u]);\n    }\n\n  private:\n    StaticRMQ<std::pair<int, int>> rmq;\n\n \
    \   void init() {\n        auto rmq_init = GetVecMin<std::pair<int, int>>(2 *\
    \ g.size());\n        auto dfs = [&](auto self, int now, int pre, int dep) ->\
    \ void {\n            in[now] = id;\n            rmq_init[id++] = {dep, now};\n\
    \            for (auto &&e : g[now]) {\n                if ((int)e == pre) continue;\n\
    \                par[(int)e] = now;\n                edge_in[e.id] = id;\n   \
    \             self(self, e, now, dep + 1);\n                edge_out[e.id] = id++;\n\
    \            }\n            out[now] = id;\n            rmq_init[id] = {dep -\
    \ 1, pre};\n        };\n        dfs(dfs, root, -1, 0);\n        for (int i = 0;\
    \ i < (int)g.size(); i++) {\n            if (in[i] == -1) dfs(dfs, i, -1, 0);\n\
    \        }\n        rmq = StaticRMQ<std::pair<int, int>>(rmq_init);\n    }\n};\n\
    \n} // namespace kk2\n\n#endif // GRAPH_TREE_EULER_TOUR_HPP\n"
  dependsOn:
  - data_structure/static_rmq.hpp
  - math/monoid/min.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/tree/euler_tour.hpp
- /library/graph/tree/euler_tour.hpp.html
title: graph/tree/euler_tour.hpp
---
