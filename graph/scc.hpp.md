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
    - filename: graph_scc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_scc.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_SCC_HPP\n#define KK2_GRAPH_SCC_HPP 1\n\n#include <algorithm>\n\
      #include <cassert>\n#include <functional>\n#include <vector>\n\n#include \"\
      ../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\ntemplate <graph::DirectedGraph\
      \ G> struct SCC {\n    int n;\n    const G &g;\n    std::vector<std::vector<int>>\
      \ revg;\n    std::vector<int> ord, scc_id;\n    std::vector<bool> used;\n  \
      \  std::vector<std::vector<int>> blng, dag;\n\n    SCC(const G &g_) : n(g_.num_vertices()),\
      \ g(g_) { init(); }\n\n    int operator[](int k) const { return scc_id[k]; }\n\
      \n    const std::vector<int> &same_scc(int u) const { return blng[u]; }\n\n\
      \    int size() const { return dag.size(); }\n\n  private:\n    void init()\
      \ {\n        auto dfs = [&](auto self, int u) -> void {\n            if (used[u])\
      \ return;\n            used[u] = true;\n            for (auto &e : g[u]) self(self,\
      \ e.to);\n            ord.emplace_back(u);\n        };\n        auto rdfs =\
      \ [&](auto self, int u, int k) -> void {\n            if (scc_id[u] != -1) return;\n\
      \            scc_id[u] = k;\n            for (auto &e : revg[u]) self(self,\
      \ e, k);\n        };\n\n        used.resize(n, false);\n        ord.reserve(n);\n\
      \        for (int u = 0; u < n; u++) dfs(dfs, u);\n        std::reverse(std::begin(ord),\
      \ std::end(ord));\n\n        scc_id.resize(n, -1);\n        revg.resize(n);\n\
      \        for (int u = 0; u < n; u++)\n            for (auto &e : g[u]) { revg[e.to].emplace_back(u);\
      \ }\n        int k = 0;\n        for (auto &u : ord)\n            if (scc_id[u]\
      \ == -1) rdfs(rdfs, u, k++);\n\n        dag.resize(k);\n        blng.resize(k);\n\
      \        for (int u = 0; u < n; u++) {\n            blng[scc_id[u]].emplace_back(u);\n\
      \            for (auto &e : g[u]) {\n                int v = e.to;\n       \
      \         if (scc_id[u] == scc_id[v]) continue;\n                dag[scc_id[u]].emplace_back(scc_id[v]);\n\
      \            }\n        }\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_SCC_HPP\n"
    name: default
  - code: "#line 1 \"graph/scc.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <functional>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 10 \"graph/scc.hpp\"\n\n\
      namespace kk2 {\n\ntemplate <graph::DirectedGraph G> struct SCC {\n    int n;\n\
      \    const G &g;\n    std::vector<std::vector<int>> revg;\n    std::vector<int>\
      \ ord, scc_id;\n    std::vector<bool> used;\n    std::vector<std::vector<int>>\
      \ blng, dag;\n\n    SCC(const G &g_) : n(g_.num_vertices()), g(g_) { init();\
      \ }\n\n    int operator[](int k) const { return scc_id[k]; }\n\n    const std::vector<int>\
      \ &same_scc(int u) const { return blng[u]; }\n\n    int size() const { return\
      \ dag.size(); }\n\n  private:\n    void init() {\n        auto dfs = [&](auto\
      \ self, int u) -> void {\n            if (used[u]) return;\n            used[u]\
      \ = true;\n            for (auto &e : g[u]) self(self, e.to);\n            ord.emplace_back(u);\n\
      \        };\n        auto rdfs = [&](auto self, int u, int k) -> void {\n  \
      \          if (scc_id[u] != -1) return;\n            scc_id[u] = k;\n      \
      \      for (auto &e : revg[u]) self(self, e, k);\n        };\n\n        used.resize(n,\
      \ false);\n        ord.reserve(n);\n        for (int u = 0; u < n; u++) dfs(dfs,\
      \ u);\n        std::reverse(std::begin(ord), std::end(ord));\n\n        scc_id.resize(n,\
      \ -1);\n        revg.resize(n);\n        for (int u = 0; u < n; u++)\n     \
      \       for (auto &e : g[u]) { revg[e.to].emplace_back(u); }\n        int k\
      \ = 0;\n        for (auto &u : ord)\n            if (scc_id[u] == -1) rdfs(rdfs,\
      \ u, k++);\n\n        dag.resize(k);\n        blng.resize(k);\n        for (int\
      \ u = 0; u < n; u++) {\n            blng[scc_id[u]].emplace_back(u);\n     \
      \       for (auto &e : g[u]) {\n                int v = e.to;\n            \
      \    if (scc_id[u] == scc_id[v]) continue;\n                dag[scc_id[u]].emplace_back(scc_id[v]);\n\
      \            }\n        }\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/scc.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
---
