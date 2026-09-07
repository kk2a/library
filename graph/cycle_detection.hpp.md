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
    - filename: graph_cycle_detection.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    - filename: graph_cycle_detection_directed.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_CYCLE_DETECTION_HPP\n#define KK2_GRAPH_CYCLE_DETECTION_HPP\
      \ 1\n\n#include <algorithm>\n#include <optional>\n#include <type_traits>\n#include\
      \ <vector>\n\n#include \"../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace\
      \ cycle_detection_impl {\n\nstruct result {\n    std::vector<int> edges;\n \
      \   std::vector<int> vertices;\n\n    int size() const { return edges.size();\
      \ }\n};\n\ntemplate <graph::UndirectedGraph G>\nstd::optional<result> cycle_detection(const\
      \ G &g) {\n    std::vector<int> edges, vertices;\n    std::vector<int> buf(g.num_vertices(),\
      \ -1);\n    auto dfs = [&](auto self, int now, int ei, int dep) -> int {\n \
      \       buf[now] = dep;\n        for (auto &&e : g[now]) {\n            if (e.id\
      \ == ei) continue;\n            if (buf[e.to] >= 0) {\n                edges.resize(dep\
      \ - buf[e.to] + 1);\n                vertices.resize(dep - buf[e.to] + 1);\n\
      \                edges.back() = e.id;\n                vertices.back() = now;\n\
      \                return buf[e.to];\n            }\n\n            int r = self(self,\
      \ e.to, e.id, dep + 1);\n            if (r >= 0) {\n                if (dep\
      \ < r) return r;\n                edges[dep - r] = e.id;\n                vertices[dep\
      \ - r] = now;\n                return r;\n            }\n        }\n\n     \
      \   return -1;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n\
      \        if (buf[i] != -1) continue;\n        if (dfs(dfs, i, -1, 0) >= 0) return\
      \ result{edges, vertices};\n    }\n\n    return {};\n}\n\ntemplate <graph::DirectedGraph\
      \ G>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
      \ edges, vertices;\n\n    // buf[i] = x\n    // x >= 0 : \u4ECA\u898B\u3089\u308C\
      \u3066\u3044\u308B\u9802\u70B9dfs\u306E\u6DF1\u3055\u306Fx\n    // x = -1 :\
      \ \u672A\u8A2A\u554F\n    // x = -2 : \u8A2A\u554F\u6E08\u307F\uFF0E\u9589\u8DEF\
      \u306B\u542B\u307E\u308C\u306A\u3044\n    std::vector<int> buf(g.num_vertices(),\
      \ -1);\n\n    // \u8FD4\u308A\u5024 x\n    // x = -1 : \u9589\u8DEF\u306A\u3057\
      \n    // x >= 0 : \u9589\u8DEF\u3042\u308A\uFF0C\u304B\u3064\uFF0C\u305D\u306E\
      \u9589\u8DEF\u306E\u59CB\u70B9\u306E\u6DF1\u3055\n    auto dfs = [&](auto self,\
      \ int now, int dep) -> int {\n        buf[now] = dep;\n        for (auto &&e\
      \ : g[now]) {\n            if (buf[e.to] == -2) continue;\n            if (buf[e.to]\
      \ >= 0) {\n                edges.resize(dep - buf[e.to] + 1);\n            \
      \    vertices.resize(dep - buf[e.to] + 1);\n                edges.back() = e.id;\n\
      \                vertices.back() = now;\n                return buf[e.to];\n\
      \            }\n\n            int r = self(self, e.to, dep + 1);\n         \
      \   if (r >= 0) {\n                if (dep < r) return r;\n                edges[dep\
      \ - r] = e.id;\n                vertices[dep - r] = now;\n                return\
      \ r;\n            }\n        }\n        buf[now] = -2;\n        return -1;\n\
      \    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n        if (buf[i]\
      \ == -2) continue;\n        if (dfs(dfs, i, 0) >= 0) return result{edges, vertices};\n\
      \    }\n\n    return {};\n}\n\n} // namespace cycle_detection_impl\n\nusing\
      \ cycle_detection_impl::cycle_detection;\n\n} // namespace kk2\n\n#endif //\
      \ KK2_GRAPH_CYCLE_DETECTION_HPP\n"
    name: default
  - code: "#line 1 \"graph/cycle_detection.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <optional>\n#include <type_traits>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#line 7 \"type_traits/graph.hpp\"\
      \n#include <utility>\n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept\
      \ Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 10 \"graph/cycle_detection.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace cycle_detection_impl {\n\nstruct result {\n\
      \    std::vector<int> edges;\n    std::vector<int> vertices;\n\n    int size()\
      \ const { return edges.size(); }\n};\n\ntemplate <graph::UndirectedGraph G>\n\
      std::optional<result> cycle_detection(const G &g) {\n    std::vector<int> edges,\
      \ vertices;\n    std::vector<int> buf(g.num_vertices(), -1);\n    auto dfs =\
      \ [&](auto self, int now, int ei, int dep) -> int {\n        buf[now] = dep;\n\
      \        for (auto &&e : g[now]) {\n            if (e.id == ei) continue;\n\
      \            if (buf[e.to] >= 0) {\n                edges.resize(dep - buf[e.to]\
      \ + 1);\n                vertices.resize(dep - buf[e.to] + 1);\n           \
      \     edges.back() = e.id;\n                vertices.back() = now;\n       \
      \         return buf[e.to];\n            }\n\n            int r = self(self,\
      \ e.to, e.id, dep + 1);\n            if (r >= 0) {\n                if (dep\
      \ < r) return r;\n                edges[dep - r] = e.id;\n                vertices[dep\
      \ - r] = now;\n                return r;\n            }\n        }\n\n     \
      \   return -1;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n\
      \        if (buf[i] != -1) continue;\n        if (dfs(dfs, i, -1, 0) >= 0) return\
      \ result{edges, vertices};\n    }\n\n    return {};\n}\n\ntemplate <graph::DirectedGraph\
      \ G>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
      \ edges, vertices;\n\n    // buf[i] = x\n    // x >= 0 : \u4ECA\u898B\u3089\u308C\
      \u3066\u3044\u308B\u9802\u70B9dfs\u306E\u6DF1\u3055\u306Fx\n    // x = -1 :\
      \ \u672A\u8A2A\u554F\n    // x = -2 : \u8A2A\u554F\u6E08\u307F\uFF0E\u9589\u8DEF\
      \u306B\u542B\u307E\u308C\u306A\u3044\n    std::vector<int> buf(g.num_vertices(),\
      \ -1);\n\n    // \u8FD4\u308A\u5024 x\n    // x = -1 : \u9589\u8DEF\u306A\u3057\
      \n    // x >= 0 : \u9589\u8DEF\u3042\u308A\uFF0C\u304B\u3064\uFF0C\u305D\u306E\
      \u9589\u8DEF\u306E\u59CB\u70B9\u306E\u6DF1\u3055\n    auto dfs = [&](auto self,\
      \ int now, int dep) -> int {\n        buf[now] = dep;\n        for (auto &&e\
      \ : g[now]) {\n            if (buf[e.to] == -2) continue;\n            if (buf[e.to]\
      \ >= 0) {\n                edges.resize(dep - buf[e.to] + 1);\n            \
      \    vertices.resize(dep - buf[e.to] + 1);\n                edges.back() = e.id;\n\
      \                vertices.back() = now;\n                return buf[e.to];\n\
      \            }\n\n            int r = self(self, e.to, dep + 1);\n         \
      \   if (r >= 0) {\n                if (dep < r) return r;\n                edges[dep\
      \ - r] = e.id;\n                vertices[dep - r] = now;\n                return\
      \ r;\n            }\n        }\n        buf[now] = -2;\n        return -1;\n\
      \    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n        if (buf[i]\
      \ == -2) continue;\n        if (dfs(dfs, i, 0) >= 0) return result{edges, vertices};\n\
      \    }\n\n    return {};\n}\n\n} // namespace cycle_detection_impl\n\nusing\
      \ cycle_detection_impl::cycle_detection;\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
---
