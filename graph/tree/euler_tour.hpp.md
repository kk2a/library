---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: sparse_table.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/sparse_table.hpp
    - filename: static_rmq.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/static_rmq.hpp
    - filename: min.hpp
      icon: LIBRARY_ALL_AC
      path: math/monoid/min.hpp
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: tree_vertex_add_path_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    - filename: tree_vertex_add_subtree_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    type: Verified with
  dependsOn:
  - data_structure/sparse_table.hpp
  - data_structure/static_rmq.hpp
  - math/monoid/min.hpp
  - type_traits/algebra.hpp
  - type_traits/graph.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_EULER_TOUR_HPP\n#define KK2_GRAPH_TREE_EULER_TOUR_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
      \ <utility>\n#include <vector>\n\n#include \"../../data_structure/static_rmq.hpp\"\
      \n#include \"../../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph\
      \ G> struct EulerTour {\n\n    const G &g;\n    int id;\n    std::vector<int>\
      \ in, out, par;\n\n    EulerTour(const G &g_, int root = 0)\n        : g(g_),\n\
      \          id(0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n\
      \          par(g.size(), -1) {\n        init(root);\n    }\n\n    std::pair<int,\
      \ int> get_edge_idx(int i) const {\n        if (par[i] == -1) return {-1, -1};\n\
      \        return {in[i], out[i]};\n    }\n\n    std::pair<int, int> get_node_idx(int\
      \ u) const { return {in[u], out[u]}; }\n\n    int lca(int u, int v) const {\n\
      \        if (in[u] > in[v]) std::swap(u, v);\n        return rmq.prod(in[u],\
      \ in[v] + 1).a.second;\n    }\n\n    int dist(int u, int v) const {\n      \
      \  int depu = rmq.get(in[u]).a.first;\n        int depv = rmq.get(in[v]).a.first;\n\
      \        return depu + depv - 2 * rmq.get(in[lca(u, v)]).a.first;\n    }\n\n\
      \    template <typename F> void path_query(int u, int v, bool is_node_query,\
      \ const F &f) {\n        int l = lca(u, v);\n        f(in[l] + (int)!is_node_query,\
      \ in[u] + 1);\n        f(in[l] + 1, in[v] + 1);\n    }\n\n    template <typename\
      \ F>\n    void path_noncommutative_query(int u, int v, bool is_node_query, const\
      \ F &f) {\n        int l = lca(u, v);\n        f(in[u] + 1, in[l] + (int)!is_node_query);\n\
      \        f(in[l] + 1, in[v] + 1);\n    }\n\n    template <typename F> void subtree_query(int\
      \ u, bool is_node_query, const F &f) {\n        f(in[u] + (int)!is_node_query,\
      \ out[u]);\n    }\n\n  private:\n    StaticRMQ<std::pair<int, int>> rmq;\n\n\
      \    void init(int root) {\n        using Monoid = typename decltype(rmq)::Monoid;\n\
      \        std::vector<Monoid> rmq_init(2 * g.size());\n        auto dfs = [&](auto\
      \ self, int now, int pre, int dep) -> void {\n            in[now] = id;\n  \
      \          rmq_init[id++] = Monoid({dep, now});\n            for (auto &&e :\
      \ g[now]) {\n                if ((int)e == pre) continue;\n                par[(int)e]\
      \ = now;\n                self(self, e, now, dep + 1);\n            }\n    \
      \        rmq_init[id] = Monoid({dep - 1, pre});\n            out[now] = id++;\n\
      \        };\n        dfs(dfs, root, -1, 0);\n        for (int i = 0; i < (int)g.size();\
      \ i++) {\n            if (in[i] == -1) dfs(dfs, i, -1, 0);\n        }\n    \
      \    rmq = StaticRMQ<std::pair<int, int>>(rmq_init);\n    }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GRAPH_TREE_EULER_TOUR_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/euler_tour.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
      #line 1 \"data_structure/static_rmq.hpp\"\n\n\n\n#line 1 \"math/monoid/min.hpp\"\
      \n\n\n\n#line 5 \"math/monoid/min.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\n\n\
      \n\n#include <concepts>\n#include <fstream>\n#include <istream>\n#include <ostream>\n\
      #include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
      \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\n\
      template <typename T>\nusing is_standard_istream = typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                                   \
      \       || std::is_same<T, std::ifstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T>\n\
      using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ofstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
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
      \n} // namespace kk2\n\n\n#line 7 \"math/monoid/min.hpp\"\n\nnamespace kk2 {\n\
      \nnamespace monoid {\n\ntemplate <class S, class Compare = std::less<S>> struct\
      \ Min {\n    static constexpr bool commutative = true;\n    using M = Min;\n\
      \    S a;\n    bool is_unit;\n\n    Min() : a(S()), is_unit(true) {}\n    Min(S\
      \ a_) : a(a_), is_unit(false) {}\n    operator S() const { return a; }\n\n \
      \   inline static M op(M l, M r) {\n        if (l.is_unit or r.is_unit) return\
      \ l.is_unit ? r : l;\n        return Compare{}(l.a, r.a) ? l : r;\n    }\n\n\
      \    inline static M unit() { return M(); }\n\n    bool operator==(const M &rhs)\
      \ const {\n        return is_unit == rhs.is_unit and (is_unit or a == rhs.a);\n\
      \    }\n\n    bool operator!=(const M &rhs) const {\n        return is_unit\
      \ != rhs.is_unit or (!is_unit and a != rhs.a);\n    }\n\n    template <OutputStream\
      \ OStream> friend OStream &operator<<(OStream &os, const M &x) {\n        if\
      \ (x.is_unit) os << \"inf\";\n        else os << x.a;\n        return os;\n\
      \    }\n\n    template <InputStream IStream> friend IStream &operator>>(IStream\
      \ &is, M &x) {\n        is >> x.a;\n        x.is_unit = false;\n        return\
      \ is;\n    }\n};\n\n} // namespace monoid\n\n} // namespace kk2\n\n\n#line 1\
      \ \"data_structure/sparse_table.hpp\"\n\n\n\n#line 6 \"data_structure/sparse_table.hpp\"\
      \n\n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#line 5 \"type_traits/algebra.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace algebra {\n\n// These concepts describe the\
      \ static interface expected by the library.\n// Algebraic laws such as associativity\
      \ cannot be checked by the type system.\n//\n// A user-defined monoid therefore\
      \ needs only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const\
      \ MyMonoid &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n\
      //\n// The return types are intentionally exact, so a typo such as returning\
      \ the\n// underlying scalar instead of MyMonoid is diagnosed at the concept\
      \ boundary.\ntemplate <class T>\nconcept Semigroup = requires(const T &x, const\
      \ T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\n\
      concept Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Group = Monoid<T> && requires(const T &x)\
      \ {\n    { T::inv(x) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ CommutativeMonoid = Monoid<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\ntemplate <class T>\nconcept CommutativeGroup =\
      \ Group<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\n// An action specification owns the pair of algebraic\
      \ types and the mapping\n// between them. It is the interface required by lazy\
      \ propagation structures.\ntemplate <class T>\nconcept Action =\n    requires\
      \ {\n        typename T::A;\n        typename T::S;\n    } && Monoid<typename\
      \ T::A> && Monoid<typename T::S>\n    && requires(const typename T::A &f, const\
      \ typename T::S &x) {\n           { T::act(f, x) } -> std::same_as<typename\
      \ T::S>;\n       };\n\n} // namespace algebra\n\n} // namespace kk2\n\n\n#line\
      \ 8 \"data_structure/sparse_table.hpp\"\n\nnamespace kk2 {\n\n// require: op(x,\
      \ x) = x for all x\ntemplate <algebra::Monoid M> struct SparseTable {\n    SparseTable()\
      \ = default;\n\n    SparseTable(int n) : _n(n) {\n        log = 0;\n       \
      \ while ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<M>(_n));\n\
      \    }\n\n    SparseTable(const std::vector<M> &v) : _n(int(v.size())) {\n \
      \       log = 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log\
      \ + 1, std::vector<M>(_n));\n        for (int i = 0; i < _n; i++) table[0][i]\
      \ = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = 1; i <= log; i++) {\n      \
      \      for (int j = 0; j + (1 << i) <= _n; j++) {\n                table[i][j]\
      \ = M::op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n\
      \        }\n    }\n\n    template <class... Args> void init_set(int p, Args...\
      \ args) {\n        assert(0 <= p && p < _n);\n        assert(!is_built);\n \
      \       table[0][p] = M(args...);\n    }\n\n    using Monoid = M;\n\n    static\
      \ M Op(M l, M r) { return M::op(l, r); }\n\n    static M MonoidUnit() { return\
      \ M::unit(); }\n\n    M prod(int l, int r) const {\n        assert(0 <= l &&\
      \ l <= r && r <= _n);\n        assert(is_built);\n        if (l == r) return\
      \ M::unit();\n        int i = 31 ^ __builtin_clz(r - l);\n        return M::op(table[i][l],\
      \ table[i][r - (1 << i)]);\n    }\n\n    M get(int i) const {\n        assert(0\
      \ <= i && i < _n);\n        assert(is_built);\n        return table[0][i];\n\
      \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
      \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
      \ <bool (*f)(M)> int max_right(int l) const {\n        return max_right(l, [](M\
      \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
      \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (l == _n) return _n;\n        int left\
      \ = l - 1, right = _n;\n        while (right - left > 1) {\n            int\
      \ mid = (left + right) >> 1;\n            if (f(prod(l, mid))) left = mid;\n\
      \            else right = mid;\n        }\n        return right;\n    }\n\n\
      \    // return l s.t.\n    // l = r or f(op(a[l], a[l+1], ..., a[r-1])) == false\n\
      \    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true\n    template <bool\
      \ (*f)(M)> int min_left(int r) const {\n        return min_left(r, [](M x) {\
      \ return f(x); });\n    }\n\n    template <class F> int min_left(int r, F f)\
      \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (r == 0) return 0;\n        int left\
      \ = -1, right = r;\n        while (right - left > 1) {\n            int mid\
      \ = (left + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n  \
      \          else left = mid;\n        }\n        return right;\n    }\n\n  private:\n\
      \    int _n, log;\n    std::vector<std::vector<M>> table;\n    bool is_built\
      \ = false;\n};\n\n} // namespace kk2\n\n\n#line 6 \"data_structure/static_rmq.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class S> using StaticRMQ = SparseTable<monoid::Min<S>>;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#line 5 \"\
      type_traits/graph.hpp\"\n#include <ranges>\n#line 8 \"type_traits/graph.hpp\"\
      \n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge = requires(const\
      \ E &e) {\n    { e.from } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ R>\nconcept EdgeRange = std::ranges::input_range<R> && Edge<std::ranges::range_value_t<R>>;\n\
      \ntemplate <class R>\nconcept WeightedEdgeRange = EdgeRange<R> && WeightedEdge<std::ranges::range_value_t<R>>;\n\
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
      };\n\ntemplate <class G>\nconcept WeightedGraph =\n    AdjacencyGraph<G> &&\
      \ G::weighted\n    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
      \ G &>()[0])>>;\n\ntemplate <class G>\nconcept WeightedEdgeListGraph =\n   \
      \ EdgeListGraph<G> && G::weighted\n    && WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 12 \"graph/tree/euler_tour.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct EulerTour\
      \ {\n\n    const G &g;\n    int id;\n    std::vector<int> in, out, par;\n\n\
      \    EulerTour(const G &g_, int root = 0)\n        : g(g_),\n          id(0),\n\
      \          in(g.size(), -1),\n          out(g.size(), -1),\n          par(g.size(),\
      \ -1) {\n        init(root);\n    }\n\n    std::pair<int, int> get_edge_idx(int\
      \ i) const {\n        if (par[i] == -1) return {-1, -1};\n        return {in[i],\
      \ out[i]};\n    }\n\n    std::pair<int, int> get_node_idx(int u) const { return\
      \ {in[u], out[u]}; }\n\n    int lca(int u, int v) const {\n        if (in[u]\
      \ > in[v]) std::swap(u, v);\n        return rmq.prod(in[u], in[v] + 1).a.second;\n\
      \    }\n\n    int dist(int u, int v) const {\n        int depu = rmq.get(in[u]).a.first;\n\
      \        int depv = rmq.get(in[v]).a.first;\n        return depu + depv - 2\
      \ * rmq.get(in[lca(u, v)]).a.first;\n    }\n\n    template <typename F> void\
      \ path_query(int u, int v, bool is_node_query, const F &f) {\n        int l\
      \ = lca(u, v);\n        f(in[l] + (int)!is_node_query, in[u] + 1);\n       \
      \ f(in[l] + 1, in[v] + 1);\n    }\n\n    template <typename F>\n    void path_noncommutative_query(int\
      \ u, int v, bool is_node_query, const F &f) {\n        int l = lca(u, v);\n\
      \        f(in[u] + 1, in[l] + (int)!is_node_query);\n        f(in[l] + 1, in[v]\
      \ + 1);\n    }\n\n    template <typename F> void subtree_query(int u, bool is_node_query,\
      \ const F &f) {\n        f(in[u] + (int)!is_node_query, out[u]);\n    }\n\n\
      \  private:\n    StaticRMQ<std::pair<int, int>> rmq;\n\n    void init(int root)\
      \ {\n        using Monoid = typename decltype(rmq)::Monoid;\n        std::vector<Monoid>\
      \ rmq_init(2 * g.size());\n        auto dfs = [&](auto self, int now, int pre,\
      \ int dep) -> void {\n            in[now] = id;\n            rmq_init[id++]\
      \ = Monoid({dep, now});\n            for (auto &&e : g[now]) {\n           \
      \     if ((int)e == pre) continue;\n                par[(int)e] = now;\n   \
      \             self(self, e, now, dep + 1);\n            }\n            rmq_init[id]\
      \ = Monoid({dep - 1, pre});\n            out[now] = id++;\n        };\n    \
      \    dfs(dfs, root, -1, 0);\n        for (int i = 0; i < (int)g.size(); i++)\
      \ {\n            if (in[i] == -1) dfs(dfs, i, -1, 0);\n        }\n        rmq\
      \ = StaticRMQ<std::pair<int, int>>(rmq_init);\n    }\n};\n\n} // namespace kk2\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/euler_tour.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
documentation_of: graph/tree/euler_tour.hpp
layout: document
---
