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
  - files:
    - filename: tree_diameter.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_diameter.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_TREE_DIAMETER_HPP\n#define KK2_GRAPH_TREE_DIAMETER_HPP\
      \ 1\n\n#include <algorithm>\n#include <functional>\n#include <type_traits>\n\
      #include <utility>\n#include <vector>\n\n#include \"../../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace tree_diameter_impl {\n\ntemplate <graph::Graph\
      \ G> struct result {\n    std::conditional_t<G::weighted, typename G::value_type,\
      \ int> diameter;\n    std::vector<int> path;\n};\n\ntemplate <graph::UnweightedGraph\
      \ G> result<G> tree_diameter(const G &g) {\n    std::vector<int> dist(g.size(),\
      \ -1), par(g.size(), -1);\n    auto dfs = [&](auto self, int now) -> void {\n\
      \        for (auto e : g[now]) {\n            if ((int)e == par[now]) continue;\n\
      \            par[(int)e] = now;\n            dist[(int)e] = dist[now] + 1;\n\
      \            self(self, (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs,\
      \ 0);\n    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
      \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
      \ { path.emplace_back(now); }\n    return {dist[v], path};\n}\n\ntemplate <graph::WeightedGraph\
      \ G> result<G> tree_diameter(const G &g) {\n    using T = typename G::value_type;\n\
      \    std::vector<T> dist(g.size(), -1);\n    std::vector<int> par(g.size(),\
      \ -1);\n\n    auto dfs = [&](auto self, int now) -> void {\n        for (auto\
      \ e : g[now]) {\n            if ((int)e == par[now]) continue;\n           \
      \ par[(int)e] = now;\n            dist[(int)e] = dist[now] + e.cost;\n     \
      \       self(self, (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs,\
      \ 0);\n    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
      \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
      \ { path.emplace_back(now); }\n    return {dist[v], path};\n}\n\n} // namespace\
      \ tree_diameter_impl\n\nusing tree_diameter_impl::tree_diameter;\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GRAPH_TREE_DIAMETER_HPP\n"
    name: default
  - code: "#line 1 \"graph/tree/diameter.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <functional>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
      \n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#include <ranges>\n\
      #line 8 \"type_traits/graph.hpp\"\n\nnamespace kk2::graph {\n\ntemplate <class\
      \ E>\nconcept Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class R>\nconcept EdgeRange = std::ranges::input_range<R>\
      \ && Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept WeightedEdgeRange\
      \ = EdgeRange<R> && WeightedEdge<std::ranges::range_value_t<R>>;\n\ntemplate\
      \ <class R>\nconcept ForwardWeightedEdgeRange = std::ranges::forward_range<R>\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 11 \"graph/tree/diameter.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace tree_diameter_impl {\n\ntemplate <graph::Graph\
      \ G> struct result {\n    std::conditional_t<G::weighted, typename G::value_type,\
      \ int> diameter;\n    std::vector<int> path;\n};\n\ntemplate <graph::UnweightedGraph\
      \ G> result<G> tree_diameter(const G &g) {\n    std::vector<int> dist(g.size(),\
      \ -1), par(g.size(), -1);\n    auto dfs = [&](auto self, int now) -> void {\n\
      \        for (auto e : g[now]) {\n            if ((int)e == par[now]) continue;\n\
      \            par[(int)e] = now;\n            dist[(int)e] = dist[now] + 1;\n\
      \            self(self, (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs,\
      \ 0);\n    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
      \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
      \ { path.emplace_back(now); }\n    return {dist[v], path};\n}\n\ntemplate <graph::WeightedGraph\
      \ G> result<G> tree_diameter(const G &g) {\n    using T = typename G::value_type;\n\
      \    std::vector<T> dist(g.size(), -1);\n    std::vector<int> par(g.size(),\
      \ -1);\n\n    auto dfs = [&](auto self, int now) -> void {\n        for (auto\
      \ e : g[now]) {\n            if ((int)e == par[now]) continue;\n           \
      \ par[(int)e] = now;\n            dist[(int)e] = dist[now] + e.cost;\n     \
      \       self(self, (int)e);\n        }\n    };\n    dist[0] = 0;\n    dfs(dfs,\
      \ 0);\n    int u = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    dist[u] = 0;\n    std::fill(std::begin(par), std::end(par), -1);\n    dfs(dfs,\
      \ u);\n    int v = std::max_element(std::begin(dist), std::end(dist)) - std::begin(dist);\n\
      \    std::vector<int> path;\n    for (int now = v; now != -1; now = par[now])\
      \ { path.emplace_back(now); }\n    return {dist[v], path};\n}\n\n} // namespace\
      \ tree_diameter_impl\n\nusing tree_diameter_impl::tree_diameter;\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/tree/diameter.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/tree_diameter.test.cpp
documentation_of: graph/tree/diameter.hpp
layout: document
---
