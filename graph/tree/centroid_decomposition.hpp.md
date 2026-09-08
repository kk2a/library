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
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\n#define KK2_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\
      \ 1\n\n#include <cassert>\n#include <vector>\n\n#include \"../../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct CentroidDecomposition\
      \ {\n\n    const G &g;\n    std::vector<int> parent;\n    std::vector<int> subsize;\n\
      \    std::vector<bool> used;\n    std::vector<std::vector<int>> children;\n\
      \    int root;\n\n    CentroidDecomposition(const G &g_, bool isbuild = true)\n\
      \        : g(g_),\n          parent(g.size(), -1),\n          subsize(g.size(),\
      \ 0),\n          used(g.size(), false),\n          children(g.size()) {\n  \
      \      if (isbuild) build();\n    }\n\n    void build() { root = build_dfs(0);\
      \ }\n\n    int get_size(int now, int par) {\n        subsize[now] = 1;\n   \
      \     for (auto e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n\
      \            subsize[now] += get_size(e.to, now);\n        }\n        return\
      \ subsize[now];\n    }\n\n    int get_centroid(int now, int par, int mid) {\n\
      \        for (auto e : g[now]) {\n            if (e.to == par or used[e.to])\
      \ continue;\n            if (subsize[e.to] > mid) return get_centroid(e.to,\
      \ now, mid);\n        }\n        return now;\n    }\n\n    int build_dfs(int\
      \ v) {\n        int centroid = get_centroid(v, -1, get_size(v, -1) / 2);\n \
      \       used[centroid] = true;\n        for (auto e : g[centroid]) {\n     \
      \       if (used[e.to]) continue;\n            int nxt = build_dfs(e.to);\n\
      \            if (centroid != nxt) {\n                children[centroid].emplace_back(nxt);\n\
      \                parent[nxt] = centroid;\n            }\n        }\n       \
      \ used[centroid] = false;\n        return centroid;\n    }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/centroid_decomposition.hpp\"\n\n\n\n#include <cassert>\n\
      #include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n\
      #include <ranges>\n#include <type_traits>\n#include <utility>\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E>\nconcept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 8 \"graph/tree/centroid_decomposition.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct CentroidDecomposition\
      \ {\n\n    const G &g;\n    std::vector<int> parent;\n    std::vector<int> subsize;\n\
      \    std::vector<bool> used;\n    std::vector<std::vector<int>> children;\n\
      \    int root;\n\n    CentroidDecomposition(const G &g_, bool isbuild = true)\n\
      \        : g(g_),\n          parent(g.size(), -1),\n          subsize(g.size(),\
      \ 0),\n          used(g.size(), false),\n          children(g.size()) {\n  \
      \      if (isbuild) build();\n    }\n\n    void build() { root = build_dfs(0);\
      \ }\n\n    int get_size(int now, int par) {\n        subsize[now] = 1;\n   \
      \     for (auto e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n\
      \            subsize[now] += get_size(e.to, now);\n        }\n        return\
      \ subsize[now];\n    }\n\n    int get_centroid(int now, int par, int mid) {\n\
      \        for (auto e : g[now]) {\n            if (e.to == par or used[e.to])\
      \ continue;\n            if (subsize[e.to] > mid) return get_centroid(e.to,\
      \ now, mid);\n        }\n        return now;\n    }\n\n    int build_dfs(int\
      \ v) {\n        int centroid = get_centroid(v, -1, get_size(v, -1) / 2);\n \
      \       used[centroid] = true;\n        for (auto e : g[centroid]) {\n     \
      \       if (used[e.to]) continue;\n            int nxt = build_dfs(e.to);\n\
      \            if (centroid != nxt) {\n                children[centroid].emplace_back(nxt);\n\
      \                parent[nxt] = centroid;\n            }\n        }\n       \
      \ used[centroid] = false;\n        return centroid;\n    }\n};\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid_decomposition.hpp
layout: document
---
