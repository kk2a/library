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
    - filename: graph_matching_bipartite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_MAXFLOW_HPP\n#define KK2_GRAPH_MAXFLOW_HPP 1\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
      #include <numeric>\n#include <queue>\n#include <vector>\n\n#include \"../type_traits/graph.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::WeightedDirectedGraph WG> struct MaxFlow\
      \ {\n\n    using Cap = typename WG::value_type;\n\n    WG g;\n    int n, m;\n\
      \    std::vector<int> revi;\n\n    MaxFlow(const WG &g_) : n(g_.num_vertices()),\
      \ m(g_.num_edges()) {\n        if constexpr (WG::static_graph) {\n         \
      \   g = WG(n);\n            for (auto &&e : g_.edges) g.add_edge(e.from, e.to,\
      \ e.cost);\n            for (auto &&e : g_.edges) g.add_edge(e.to, e.from, 0);\n\
      \            g.build();\n        } else {\n            g = g_;\n           \
      \ for (auto &&e : g_.edges) g.add_edge(e.to, e.from, 0);\n        }\n      \
      \  revi.resize(2 * m);\n        for (int i = 0; i < n; ++i) {\n            for\
      \ (int j = 0; j < (int)g[i].size(); ++j)\n                revi[g[i][j].id >=\
      \ m ? g[i][j].id - m : g[i][j].id + m] = j;\n        }\n    }\n\n    template\
      \ <class Edges_> MaxFlow(int n_, const Edges_ &edges) : n(n_), m(edges.size())\
      \ {\n        g = WG(n);\n        for (auto &&e : edges) g.add_edge(e.from, e.to,\
      \ e.cost);\n        for (auto &&e : edges) g.add_edge(e.to, e.from, 0);\n  \
      \      if constexpr (WG::static_graph) g.build();\n        revi.resize(2 * m);\n\
      \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < (int)g[i].size();\
      \ ++j)\n                revi[g[i][j].id >= m ? g[i][j].id - m : g[i][j].id +\
      \ m] = j;\n        }\n    }\n\n    Cap flow(int s, int t) { return flow(s, t,\
      \ std::numeric_limits<Cap>::max()); }\n\n    Cap flow(int s, int t, Cap flow_limit)\
      \ {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n  \
      \      assert(s != t);\n\n        std::vector<int> level(n), iter(n);\n    \
      \    std::queue<int> que;\n\n        auto bfs = [&]() {\n            std::fill(std::begin(level),\
      \ std::end(level), -1);\n            level[s] = 0;\n            que = std::queue<int>();\n\
      \            que.push(s);\n            while (!que.empty()) {\n            \
      \    int v = que.front();\n                que.pop();\n                for (auto\
      \ &e : g[v]) {\n                    if (e.cost == 0 || level[e.to] >= 0) continue;\n\
      \                    level[e.to] = level[v] + 1;\n                    if (e.to\
      \ == t) return;\n                    que.push(e.to);\n                }\n  \
      \          }\n        };\n        auto dfs = [&](auto self, int v, Cap up) {\n\
      \            if (v == s) return up;\n            Cap res = 0;\n            for\
      \ (int &i = iter[v]; i < (int)g[v].size(); i++) {\n                auto &e =\
      \ g[v][i];\n                if (level[v] <= level[e.to] || g[e.to][revi[e.id]].cost\
      \ == 0) continue;\n                Cap d = self(self, e.to, std::min(up - res,\
      \ g[e.to][revi[e.id]].cost));\n                if (d <= 0) continue;\n     \
      \           g[v][i].cost += d;\n                g[e.to][revi[e.id]].cost -=\
      \ d;\n                res += d;\n                if (res == up) break;\n   \
      \         }\n            return res;\n        };\n\n        Cap flow = 0;\n\
      \        while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
      \ == -1) break;\n            std::fill(std::begin(iter), std::end(iter), 0);\n\
      \            while (flow < flow_limit) {\n                Cap f = dfs(dfs, t,\
      \ flow_limit - flow);\n                if (!f) break;\n                flow\
      \ += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
      \ min_cut(int s) {\n        std::vector<bool> visited(n);\n        std::queue<int>\
      \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
      \ p = que.front();\n            que.pop();\n            visited[p] = true;\n\
      \            for (auto &e : g[p]) {\n                if (e.cost && !visited[e.to])\
      \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
      \                }\n            }\n        }\n        return visited;\n    }\n\
      \n    struct edge {\n        int from, to;\n        Cap cap, flow;\n    };\n\
      \n    edge get_edge(int i) {\n        auto e = g.edges[i];\n        return edge{e.from,\
      \ e.to, e.cost + g[e.to][revi[i]].cost, g[e.to][revi[i]].cost};\n    }\n\n \
      \   std::vector<edge> get_edges() {\n        std::vector<edge> result(m);\n\
      \        for (int i = 0; i < m; i++) { result[i] = get_edge(i); }\n        return\
      \ result;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_MAXFLOW_HPP\n"
    name: default
  - code: "#line 1 \"graph/maxflow.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <functional>\n#include <limits>\n#include <numeric>\n#include <queue>\n\
      #include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\n\n#include <concepts>\n\
      #include <ranges>\n#include <type_traits>\n#include <utility>\n\nnamespace kk2::graph\
      \ {\n\ntemplate <class E>\nconcept Edge = requires(const E &e) {\n    { e.from\
      \ } -> std::convertible_to<int>;\n    { e.to } -> std::convertible_to<int>;\n\
      \    { e.id } -> std::convertible_to<int>;\n};\n\ntemplate <class E>\nconcept\
      \ WeightedEdge = Edge<E> && requires(const E &e) { e.cost; };\n\ntemplate <class\
      \ G>\nconcept Graph = requires(const G &g, int v) {\n    typename G::value_type;\n\
      \    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_list } -> std::convertible_to<bool>;\n    { G::adjacency_matrix\
      \ } -> std::convertible_to<bool>;\n    { G::static_graph } -> std::convertible_to<bool>;\n\
      \    { g.num_vertices() } -> std::integral;\n    { g.num_edges() } -> std::integral;\n\
      \    g[v];\n    g.edges;\n};\n\ntemplate <class G>\nconcept EdgeListGraph =\
      \ Graph<G> && requires(const G &g) {\n    requires std::ranges::range<decltype(g.edges)>;\n\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 13 \"graph/maxflow.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <graph::WeightedDirectedGraph WG> struct MaxFlow\
      \ {\n\n    using Cap = typename WG::value_type;\n\n    WG g;\n    int n, m;\n\
      \    std::vector<int> revi;\n\n    MaxFlow(const WG &g_) : n(g_.num_vertices()),\
      \ m(g_.num_edges()) {\n        if constexpr (WG::static_graph) {\n         \
      \   g = WG(n);\n            for (auto &&e : g_.edges) g.add_edge(e.from, e.to,\
      \ e.cost);\n            for (auto &&e : g_.edges) g.add_edge(e.to, e.from, 0);\n\
      \            g.build();\n        } else {\n            g = g_;\n           \
      \ for (auto &&e : g_.edges) g.add_edge(e.to, e.from, 0);\n        }\n      \
      \  revi.resize(2 * m);\n        for (int i = 0; i < n; ++i) {\n            for\
      \ (int j = 0; j < (int)g[i].size(); ++j)\n                revi[g[i][j].id >=\
      \ m ? g[i][j].id - m : g[i][j].id + m] = j;\n        }\n    }\n\n    template\
      \ <class Edges_> MaxFlow(int n_, const Edges_ &edges) : n(n_), m(edges.size())\
      \ {\n        g = WG(n);\n        for (auto &&e : edges) g.add_edge(e.from, e.to,\
      \ e.cost);\n        for (auto &&e : edges) g.add_edge(e.to, e.from, 0);\n  \
      \      if constexpr (WG::static_graph) g.build();\n        revi.resize(2 * m);\n\
      \        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < (int)g[i].size();\
      \ ++j)\n                revi[g[i][j].id >= m ? g[i][j].id - m : g[i][j].id +\
      \ m] = j;\n        }\n    }\n\n    Cap flow(int s, int t) { return flow(s, t,\
      \ std::numeric_limits<Cap>::max()); }\n\n    Cap flow(int s, int t, Cap flow_limit)\
      \ {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n  \
      \      assert(s != t);\n\n        std::vector<int> level(n), iter(n);\n    \
      \    std::queue<int> que;\n\n        auto bfs = [&]() {\n            std::fill(std::begin(level),\
      \ std::end(level), -1);\n            level[s] = 0;\n            que = std::queue<int>();\n\
      \            que.push(s);\n            while (!que.empty()) {\n            \
      \    int v = que.front();\n                que.pop();\n                for (auto\
      \ &e : g[v]) {\n                    if (e.cost == 0 || level[e.to] >= 0) continue;\n\
      \                    level[e.to] = level[v] + 1;\n                    if (e.to\
      \ == t) return;\n                    que.push(e.to);\n                }\n  \
      \          }\n        };\n        auto dfs = [&](auto self, int v, Cap up) {\n\
      \            if (v == s) return up;\n            Cap res = 0;\n            for\
      \ (int &i = iter[v]; i < (int)g[v].size(); i++) {\n                auto &e =\
      \ g[v][i];\n                if (level[v] <= level[e.to] || g[e.to][revi[e.id]].cost\
      \ == 0) continue;\n                Cap d = self(self, e.to, std::min(up - res,\
      \ g[e.to][revi[e.id]].cost));\n                if (d <= 0) continue;\n     \
      \           g[v][i].cost += d;\n                g[e.to][revi[e.id]].cost -=\
      \ d;\n                res += d;\n                if (res == up) break;\n   \
      \         }\n            return res;\n        };\n\n        Cap flow = 0;\n\
      \        while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
      \ == -1) break;\n            std::fill(std::begin(iter), std::end(iter), 0);\n\
      \            while (flow < flow_limit) {\n                Cap f = dfs(dfs, t,\
      \ flow_limit - flow);\n                if (!f) break;\n                flow\
      \ += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
      \ min_cut(int s) {\n        std::vector<bool> visited(n);\n        std::queue<int>\
      \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
      \ p = que.front();\n            que.pop();\n            visited[p] = true;\n\
      \            for (auto &e : g[p]) {\n                if (e.cost && !visited[e.to])\
      \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
      \                }\n            }\n        }\n        return visited;\n    }\n\
      \n    struct edge {\n        int from, to;\n        Cap cap, flow;\n    };\n\
      \n    edge get_edge(int i) {\n        auto e = g.edges[i];\n        return edge{e.from,\
      \ e.to, e.cost + g[e.to][revi[i]].cost, g[e.to][revi[i]].cost};\n    }\n\n \
      \   std::vector<edge> get_edges() {\n        std::vector<edge> result(m);\n\
      \        for (int i = 0; i < m; i++) { result[i] = get_edge(i); }\n        return\
      \ result;\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/maxflow.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
documentation_of: graph/maxflow.hpp
layout: document
---
