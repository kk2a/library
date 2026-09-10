---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: lowlink.hpp
      icon: LIBRARY_ALL_AC
      path: graph/lowlink.hpp
    - filename: graph.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/graph.hpp
    type: Depends on
  - files:
    - filename: block_cut_tree.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/block_cut_tree.hpp
    type: Required by
  - files:
    - filename: graph_bcc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_bcc.test.cpp
    - filename: yuki_1326.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1326.test.cpp
    type: Verified with
  dependsOn:
  - graph/lowlink.hpp
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_BCC_HPP\n#define KK2_GRAPH_BCC_HPP 1\n\n#include <functional>\n\
      #include <vector>\n\n#include \"lowlink.hpp\"\n\nnamespace kk2 {\n\ntemplate\
      \ <graph::UndirectedGraph G> struct BCC : LowLink<G> {\n    BCC(const G &g_)\
      \ : LowLink<G>(g_) { init_bcc(); }\n\n    std::vector<std::vector<int>> group_e;\n\
      \    std::vector<int> comp_e;\n\n  private:\n    void init_bcc() {\n       \
      \ comp_e = std::vector<int>(this->m, -1);\n        auto add = [&](int ei, int\
      \ k) {\n            group_e[k].emplace_back(ei);\n            comp_e[ei] = k;\n\
      \        };\n        auto dfs = [&](auto self, int u, int k = -1, int ei = -1)\
      \ -> void {\n            for (auto e : this->g[u]) {\n                if (e.id\
      \ == ei) continue;\n                if (this->used_on_dfs_tree[e.id]) {\n  \
      \                  int nk = k;\n                    if (this->low[e.to] >= this->ord[u])\n\
      \                        nk = group_e.size(), group_e.emplace_back();\n    \
      \                add(e.id, nk);\n                    self(self, e.to, nk, e.id);\n\
      \                }\n                // back edge\n                else if (this->ord[e.to]\
      \ < this->ord[u]) {\n                    add(e.id, k);\n                }\n\
      \            }\n        };\n        for (int u = 0; u < this->n; u++)\n    \
      \        if (this->root[u]) { dfs(dfs, u); }\n    }\n\n  public:\n    std::vector<std::vector<int>>\
      \ get_bcc_vertices() {\n        std::vector<bool> buf1(this->n), buf2(this->n);\n\
      \        std::vector<std::vector<int>> res;\n        res.reserve(group_e.size());\n\
      \        for (auto &bc : group_e) {\n            if (bc.empty()) continue;\n\
      \            int k = (int)res.size();\n            res.emplace_back();\n   \
      \         for (auto &ei : bc) {\n                auto e = this->g.edges[ei];\n\
      \                int fr = e.from, to = e.to;\n                if (!buf2[fr])\
      \ {\n                    res[k].emplace_back(fr);\n                    buf2[fr]\
      \ = true;\n                }\n                if (!buf2[to]) {\n           \
      \         res[k].emplace_back(to);\n                    buf2[to] = true;\n \
      \               }\n                buf1[fr] = buf1[to] = true;\n           \
      \ }\n            for (auto &ei : bc) {\n                auto e = this->g.edges[ei];\n\
      \                int fr = e.from, to = e.to;\n                buf2[fr] = buf2[to]\
      \ = false;\n            }\n        }\n        for (int i = 0; i < this->n; i++)\n\
      \            if (!buf1[i]) {\n                int k = (int)res.size();\n   \
      \             res.emplace_back();\n                res[k].emplace_back(i);\n\
      \            }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n#endif\
      \ // KK2_GRAPH_BCC_HPP\n"
    name: default
  - code: "#line 1 \"graph/bcc.hpp\"\n\n\n\n#include <functional>\n#include <vector>\n\
      \n#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #line 7 \"graph/lowlink.hpp\"\n#include <type_traits>\n#line 9 \"graph/lowlink.hpp\"\
      \n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n#include <ranges>\n\
      #line 7 \"type_traits/graph.hpp\"\n#include <utility>\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E>\nconcept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 11 \"graph/lowlink.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph G> struct LowLink {\n\
      \n    int n, m;\n    const G &g;\n    std::vector<int> ord, low;\n    std::vector<bool>\
      \ root, used_on_dfs_tree;\n    std::vector<int> bridges, articulations;\n\n\
      \    LowLink(const G &g_)\n        : n(g_.num_vertices()),\n          m(g_.num_edges()),\n\
      \          g(g_),\n          ord(n, -1),\n          low(n, -1),\n          root(n,\
      \ false),\n          used_on_dfs_tree(m, false) {\n        init();\n    }\n\n\
      \  private:\n    // v is a child of u in DFS tree\n    // edge(u, v) is a bridge\
      \ <=> ord[u] < low[v]\n\n    // u is an articulation point <=> (u is root and\
      \ u has two or more children) or\n    // there exists a v which is a child of\
      \ u in DFS tree and ord[u] <= low[v]\n\n    void init() {\n        int k = 0;\n\
      \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n          \
      \  low[u] = ord[u] = k++;\n            bool is_articulation = false;\n     \
      \       int count = 0;\n            for (auto &&e : g[u]) {\n              \
      \  if (e.id == ei) continue;\n                if (ord[e.to] == -1) {\n     \
      \               ++count;\n                    used_on_dfs_tree[e.id] = true;\n\
      \                    low[u] = std::min(low[u], self(self, e.to, e.id));\n  \
      \                  if (ei != -1 and ord[u] <= low[e.to]) is_articulation = true;\n\
      \                    if (ord[u] < low[e.to]) bridges.emplace_back(e.id);\n \
      \               }\n                // back edge\n                else if (ord[e.to]\
      \ < ord[u]) {\n                    low[u] = std::min(low[u], ord[e.to]);\n \
      \               }\n            }\n            if (ei == -1 and count >= 2) is_articulation\
      \ = true;\n            if (is_articulation) articulations.emplace_back(u);\n\
      \            return low[u];\n        };\n        for (int u = 0; u < n; u++)\n\
      \            if (ord[u] == -1) {\n                dfs(dfs, u);\n           \
      \     root[u] = true;\n            }\n    }\n};\n\n} // namespace kk2\n\n\n\
      #line 8 \"graph/bcc.hpp\"\n\nnamespace kk2 {\n\ntemplate <graph::UndirectedGraph\
      \ G> struct BCC : LowLink<G> {\n    BCC(const G &g_) : LowLink<G>(g_) { init_bcc();\
      \ }\n\n    std::vector<std::vector<int>> group_e;\n    std::vector<int> comp_e;\n\
      \n  private:\n    void init_bcc() {\n        comp_e = std::vector<int>(this->m,\
      \ -1);\n        auto add = [&](int ei, int k) {\n            group_e[k].emplace_back(ei);\n\
      \            comp_e[ei] = k;\n        };\n        auto dfs = [&](auto self,\
      \ int u, int k = -1, int ei = -1) -> void {\n            for (auto e : this->g[u])\
      \ {\n                if (e.id == ei) continue;\n                if (this->used_on_dfs_tree[e.id])\
      \ {\n                    int nk = k;\n                    if (this->low[e.to]\
      \ >= this->ord[u])\n                        nk = group_e.size(), group_e.emplace_back();\n\
      \                    add(e.id, nk);\n                    self(self, e.to, nk,\
      \ e.id);\n                }\n                // back edge\n                else\
      \ if (this->ord[e.to] < this->ord[u]) {\n                    add(e.id, k);\n\
      \                }\n            }\n        };\n        for (int u = 0; u < this->n;\
      \ u++)\n            if (this->root[u]) { dfs(dfs, u); }\n    }\n\n  public:\n\
      \    std::vector<std::vector<int>> get_bcc_vertices() {\n        std::vector<bool>\
      \ buf1(this->n), buf2(this->n);\n        std::vector<std::vector<int>> res;\n\
      \        res.reserve(group_e.size());\n        for (auto &bc : group_e) {\n\
      \            if (bc.empty()) continue;\n            int k = (int)res.size();\n\
      \            res.emplace_back();\n            for (auto &ei : bc) {\n      \
      \          auto e = this->g.edges[ei];\n                int fr = e.from, to\
      \ = e.to;\n                if (!buf2[fr]) {\n                    res[k].emplace_back(fr);\n\
      \                    buf2[fr] = true;\n                }\n                if\
      \ (!buf2[to]) {\n                    res[k].emplace_back(to);\n            \
      \        buf2[to] = true;\n                }\n                buf1[fr] = buf1[to]\
      \ = true;\n            }\n            for (auto &ei : bc) {\n              \
      \  auto e = this->g.edges[ei];\n                int fr = e.from, to = e.to;\n\
      \                buf2[fr] = buf2[to] = false;\n            }\n        }\n  \
      \      for (int i = 0; i < this->n; i++)\n            if (!buf1[i]) {\n    \
      \            int k = (int)res.size();\n                res.emplace_back();\n\
      \                res[k].emplace_back(i);\n            }\n        return res;\n\
      \    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/bcc.hpp
  pathExtension: hpp
  requiredBy:
  - graph/tree/block_cut_tree.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: graph/bcc.hpp
layout: document
---
