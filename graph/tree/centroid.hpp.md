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
  - code: "#ifndef KK2_GRAPH_TREE_CENTROID_HPP\n#define KK2_GRAPH_TREE_CENTROID_HPP\
      \ 1\n\n#include <cassert>\n#include <functional>\n#include <numeric>\n#include\
      \ <vector>\n\n#include \"../../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\n\
      template <graph::UndirectedGraph G> int centroid(const G &g) {\n\n    int n\
      \ = g.size();\n    std::vector<int> sz(n, 0);\n    auto dfs = [&](auto &&self,\
      \ int u, int p = -1) -> int {\n        sz[u] = 1;\n        for (int v : g[u])\n\
      \            if (v != p) { sz[u] += self(self, v, u); }\n        return sz[u];\n\
      \    };\n    dfs(dfs, 0);\n\n    auto find = [&](auto &&self, int u, int p =\
      \ -1) -> int {\n        bool is_centroid = true;\n        for (int v : g[u])\n\
      \            if (v != p) {\n                int ret = self(self, v, u);\n  \
      \              if (ret != -1) return ret;\n                if (sz[v] > n / 2)\
      \ is_centroid = false;\n            }\n        if ((n - sz[u]) > n / 2) is_centroid\
      \ = false;\n        return is_centroid ? u : -1;\n    };\n    return find(find,\
      \ 0);\n}\n\ntemplate <graph::UndirectedGraph G>\nint centroid(const G &g, const\
      \ std::vector<long long> &weight) {\n    assert((int)g.size() == (int)weight.size());\n\
      \    int n = g.size();\n    std::vector<long long> sz(n, 0);\n    long long\
      \ sum = std::accumulate(std::begin(weight), std::end(weight), 0LL);\n    auto\
      \ dfs = [&](auto &&self, int u, int p = -1) -> long long {\n        sz[u] =\
      \ weight[u];\n        for (int v : g[u])\n            if (v != p) { sz[u] +=\
      \ self(self, v, u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n \
      \   auto find = [&](auto &&self, int u, int p = -1) -> int {\n        bool is_centroid\
      \ = true;\n        for (int v : g[u])\n            if (v != p) {\n         \
      \       int ret = self(self, v, u);\n                if (ret != -1) return ret;\n\
      \                if (sz[v] > sum / 2) is_centroid = false;\n            }\n\
      \        if ((sum - sz[u]) > sum / 2) is_centroid = false;\n        return is_centroid\
      \ ? u : -1;\n    };\n    return find(find, 0);\n}\n\n} // namespace kk2\n\n\
      #endif // KK2_GRAPH_TREE_CENTROID_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/centroid.hpp\"\n\n\n\n#include <cassert>\n#include\
      \ <functional>\n#include <numeric>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n#include\
      \ <utility>\n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept Edge =\
      \ requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n    {\
      \ e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class G>\nconcept Graph = requires(const G &g,\
      \ int v) {\n    typename G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 10 \"graph/tree/centroid.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> int centroid(const\
      \ G &g) {\n\n    int n = g.size();\n    std::vector<int> sz(n, 0);\n    auto\
      \ dfs = [&](auto &&self, int u, int p = -1) -> int {\n        sz[u] = 1;\n \
      \       for (int v : g[u])\n            if (v != p) { sz[u] += self(self, v,\
      \ u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n    auto find =\
      \ [&](auto &&self, int u, int p = -1) -> int {\n        bool is_centroid = true;\n\
      \        for (int v : g[u])\n            if (v != p) {\n                int\
      \ ret = self(self, v, u);\n                if (ret != -1) return ret;\n    \
      \            if (sz[v] > n / 2) is_centroid = false;\n            }\n      \
      \  if ((n - sz[u]) > n / 2) is_centroid = false;\n        return is_centroid\
      \ ? u : -1;\n    };\n    return find(find, 0);\n}\n\ntemplate <graph::UndirectedGraph\
      \ G>\nint centroid(const G &g, const std::vector<long long> &weight) {\n   \
      \ assert((int)g.size() == (int)weight.size());\n    int n = g.size();\n    std::vector<long\
      \ long> sz(n, 0);\n    long long sum = std::accumulate(std::begin(weight), std::end(weight),\
      \ 0LL);\n    auto dfs = [&](auto &&self, int u, int p = -1) -> long long {\n\
      \        sz[u] = weight[u];\n        for (int v : g[u])\n            if (v !=\
      \ p) { sz[u] += self(self, v, u); }\n        return sz[u];\n    };\n    dfs(dfs,\
      \ 0);\n\n    auto find = [&](auto &&self, int u, int p = -1) -> int {\n    \
      \    bool is_centroid = true;\n        for (int v : g[u])\n            if (v\
      \ != p) {\n                int ret = self(self, v, u);\n                if (ret\
      \ != -1) return ret;\n                if (sz[v] > sum / 2) is_centroid = false;\n\
      \            }\n        if ((sum - sz[u]) > sum / 2) is_centroid = false;\n\
      \        return is_centroid ? u : -1;\n    };\n    return find(find, 0);\n}\n\
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/centroid.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid.hpp
layout: document
---
