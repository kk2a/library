---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    - filename: unionfind.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/unionfind.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: graph_minimum_spanning_tree.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  - unionfind/unionfind.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\n#define KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\
      \ 1\n\n#include <algorithm>\n#include <ranges>\n#include <type_traits>\n#include\
      \ <utility>\n#include <vector>\n\n#include \"../../type_traits/graph.hpp\"\n\
      #include \"../../unionfind/unionfind.hpp\"\n\nnamespace kk2 {\n\ntemplate <graph::WeightedEdgeRange\
      \ E> auto minimum_spanning_tree(int n, const E &input_edges) {\n\n    using\
      \ edge_type = std::ranges::range_value_t<E>;\n    using value_type = std::remove_cvref_t<decltype(std::declval<edge_type>().cost)>;\n\
      \n    std::vector<edge_type> edges(std::ranges::begin(input_edges), std::ranges::end(input_edges));\n\
      \    std::sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2)\
      \ {\n        return e1.cost < e2.cost;\n    });\n    UnionFind uf(n);\n    std::vector<int>\
      \ idxs(n - 1);\n    value_type total_cost = 0;\n    int i = 0;\n    for (auto\
      \ &&e : edges) {\n        if (uf.unite(e.from, e.to)) { idxs[i++] = e.id, total_cost\
      \ += e.cost; }\n    }\n\n    return std::make_pair(total_cost, idxs);\n}\n\n\
      } // namespace kk2\n\n#endif // KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/minimum_spanning_tree.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <ranges>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
      \n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#line 8 \"type_traits/graph.hpp\"\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 1 \"unionfind/unionfind.hpp\"\
      \n\n\n\n#line 6 \"unionfind/unionfind.hpp\"\n\nnamespace kk2 {\n\nstruct UnionFind\
      \ {\n    std::vector<int> d;\n\n    UnionFind(int n = 0) : d(n, -1) {}\n\n \
      \   bool same(int x, int y) { return find(x) == find(y); }\n\n    bool unite(int\
      \ x, int y) {\n        x = find(x), y = find(y);\n        if (x == y) return\
      \ false;\n        if (-d[x] < -d[y]) std::swap(x, y);\n        d[x] += d[y];\n\
      \        d[y] = x;\n        return true;\n    }\n\n    template <class F> bool\
      \ unite(int x, int y, const F &f) {\n        x = find(x), y = find(y);\n   \
      \     if (x == y) return false;\n        if (-d[x] < -d[y]) std::swap(x, y);\n\
      \        f(x, y);\n        d[x] += d[y];\n        d[y] = x;\n        return\
      \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n \
      \       return d[x] = find(d[x]);\n    }\n\n    int size(int x) { return -d[find(x)];\
      \ }\n};\n\n} // namespace kk2\n\n\n#line 12 \"graph/tree/minimum_spanning_tree.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::WeightedEdgeRange E> auto minimum_spanning_tree(int\
      \ n, const E &input_edges) {\n\n    using edge_type = std::ranges::range_value_t<E>;\n\
      \    using value_type = std::remove_cvref_t<decltype(std::declval<edge_type>().cost)>;\n\
      \n    std::vector<edge_type> edges(std::ranges::begin(input_edges), std::ranges::end(input_edges));\n\
      \    std::sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2)\
      \ {\n        return e1.cost < e2.cost;\n    });\n    UnionFind uf(n);\n    std::vector<int>\
      \ idxs(n - 1);\n    value_type total_cost = 0;\n    int i = 0;\n    for (auto\
      \ &&e : edges) {\n        if (uf.unite(e.from, e.to)) { idxs[i++] = e.id, total_cost\
      \ += e.cost; }\n    }\n\n    return std::make_pair(total_cost, idxs);\n}\n\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/minimum_spanning_tree.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
documentation_of: graph/tree/minimum_spanning_tree.hpp
layout: document
---
