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
    - filename: maxflow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/graph/maxflow.test.cpp
    - filename: graph_matching_bipartite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/graph.hpp
  embedded:
  - code: "#ifndef KK2_GRAPH_MAXFLOW_HPP\n#define KK2_GRAPH_MAXFLOW_HPP 1\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
      #include <numeric>\n#include <queue>\n#include <ranges>\n#include <vector>\n\
      \n#include \"../type_traits/graph.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ Cap> struct MaxFlowGraph {\n    struct arc {\n        int to, rev;\n     \
      \   Cap cap;\n    };\n    struct edge {\n        int from, to, index;\n    };\n\
      \n    std::vector<std::vector<arc>> data;\n    std::vector<edge> edges;\n\n\
      \    MaxFlowGraph() = default;\n    explicit MaxFlowGraph(int n) : data(n) {}\n\
      \n    template <class E>\n        requires graph::WeightedEdgeRange<const E>\n\
      \    MaxFlowGraph(int n, const E &input) : data(n) {\n        if constexpr (std::ranges::sized_range<const\
      \ E>) {\n            edges.reserve(std::ranges::size(input));\n        }\n \
      \       if constexpr (std::ranges::forward_range<const E>) {\n            std::vector<int>\
      \ degree(n);\n            for (const auto &e : input) {\n                ++degree[e.from];\n\
      \                ++degree[e.to];\n            }\n            for (int v = 0;\
      \ v < n; ++v) data[v].reserve(degree[v]);\n        }\n        for (const auto\
      \ &e : input) add_edge(e.from, e.to, e.cost);\n    }\n\n    void add_edge(int\
      \ from, int to, Cap cap) {\n        const int index = data[from].size();\n \
      \       data[from].push_back({to, -1, cap});\n        const int rev = data[to].size();\n\
      \        data[to].push_back({from, index, Cap(0)});\n        data[from][index].rev\
      \ = rev;\n        edges.push_back({from, to, index});\n    }\n};\n\ntemplate\
      \ <graph::WeightedDirectedGraph WG> struct MaxFlow {\n\n    using Cap = typename\
      \ WG::value_type;\n    using graph_type = MaxFlowGraph<Cap>;\n\n    graph_type\
      \ g;\n    int n, m;\n\n    MaxFlow(const WG &g_) : g(g_.num_vertices(), g_.edges),\
      \ n(g_.num_vertices()), m(g_.num_edges()) {}\n\n    template <class Edges_>\n\
      \        requires graph::WeightedEdgeRange<const Edges_>\n    MaxFlow(int n_,\
      \ const Edges_ &edges) : g(n_, edges), n(n_), m(g.edges.size()) {}\n\n    Cap\
      \ flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }\n\
      \n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s <\
      \ n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n\n       \
      \ std::vector<int> level(n), iter(n);\n        std::queue<int> que;\n\n    \
      \    auto bfs = [&]() {\n            std::fill(std::begin(level), std::end(level),\
      \ -1);\n            level[s] = 0;\n            que = std::queue<int>();\n  \
      \          que.push(s);\n            while (!que.empty()) {\n              \
      \  int v = que.front();\n                que.pop();\n                for (const\
      \ auto &e : g.data[v]) {\n                    if (e.cap == 0 || level[e.to]\
      \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n       \
      \             if (e.to == t) return;\n                    que.push(e.to);\n\
      \                }\n            }\n        };\n        auto dfs = [&](auto self,\
      \ int v, Cap up) {\n            if (v == t) return up;\n            Cap res\
      \ = 0;\n            for (int &i = iter[v]; i < (int)g.data[v].size(); i++) {\n\
      \                auto &e = g.data[v][i];\n                if (e.cap == 0 ||\
      \ level[e.to] != level[v] + 1) continue;\n                Cap d = self(self,\
      \ e.to, std::min(up - res, e.cap));\n                if (d <= 0) continue;\n\
      \                e.cap -= d;\n                g.data[e.to][e.rev].cap += d;\n\
      \                res += d;\n                if (res == up) break;\n        \
      \    }\n            return res;\n        };\n\n        Cap flow = 0;\n     \
      \   while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
      \ == -1) break;\n            std::fill(std::begin(iter), std::end(iter), 0);\n\
      \            while (flow < flow_limit) {\n                Cap f = dfs(dfs, s,\
      \ flow_limit - flow);\n                if (!f) break;\n                flow\
      \ += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
      \ min_cut(int s) {\n        std::vector<bool> visited(n);\n        std::queue<int>\
      \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
      \ p = que.front();\n            que.pop();\n            visited[p] = true;\n\
      \            for (const auto &e : g.data[p]) {\n                if (e.cap &&\
      \ !visited[e.to]) {\n                    visited[e.to] = true;\n           \
      \         que.push(e.to);\n                }\n            }\n        }\n   \
      \     return visited;\n    }\n\n    struct edge {\n        int from, to;\n \
      \       Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        const\
      \ auto &e = g.edges[i];\n        const auto &forward = g.data[e.from][e.index];\n\
      \        const auto &reverse = g.data[forward.to][forward.rev];\n        return\
      \ edge{e.from, e.to, forward.cap + reverse.cap, reverse.cap};\n    }\n\n   \
      \ std::vector<edge> get_edges() {\n        std::vector<edge> result(m);\n  \
      \      for (int i = 0; i < m; i++) { result[i] = get_edge(i); }\n        return\
      \ result;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_MAXFLOW_HPP\n"
    name: default
  - code: "#line 1 \"graph/maxflow.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <functional>\n#include <limits>\n#include <numeric>\n#include <queue>\n\
      #include <ranges>\n#include <vector>\n\n#line 1 \"type_traits/graph.hpp\"\n\n\
      \n\n#include <concepts>\n#line 6 \"type_traits/graph.hpp\"\n#include <type_traits>\n\
      #include <utility>\n\nnamespace kk2::graph {\n\ntemplate <class E>\nconcept\
      \ Edge = requires(const E &e) {\n    { e.from } -> std::convertible_to<int>;\n\
      \    { e.to } -> std::convertible_to<int>;\n    { e.id } -> std::convertible_to<int>;\n\
      };\n\ntemplate <class E>\nconcept WeightedEdge = Edge<E> && requires(const E\
      \ &e) { e.cost; };\n\ntemplate <class R>\nconcept EdgeRange = std::ranges::input_range<R>\
      \ &&\n                    Edge<std::ranges::range_value_t<R>>;\n\ntemplate <class\
      \ R>\nconcept WeightedEdgeRange = EdgeRange<R> &&\n                        \
      \    WeightedEdge<std::ranges::range_value_t<R>>;\n\ntemplate <class R>\nconcept\
      \ ForwardWeightedEdgeRange = std::ranges::forward_range<R> && WeightedEdgeRange<R>;\n\
      \ntemplate <class G>\nconcept Graph = requires(const G &g, int v) {\n    typename\
      \ G::value_type;\n    { G::directed } -> std::convertible_to<bool>;\n    { G::weighted\
      \ } -> std::convertible_to<bool>;\n    { G::adjacency_list } -> std::convertible_to<bool>;\n\
      \    { G::adjacency_matrix } -> std::convertible_to<bool>;\n    { G::static_graph\
      \ } -> std::convertible_to<bool>;\n    { g.num_vertices() } -> std::integral;\n\
      \    { g.num_edges() } -> std::integral;\n    g[v];\n    g.edges;\n};\n\ntemplate\
      \ <class G>\nconcept EdgeListGraph = Graph<G> && requires(const G &g) {\n  \
      \  requires std::ranges::range<decltype(g.edges)>;\n    requires Edge<std::ranges::range_value_t<decltype(g.edges)>>;\n\
      };\n\ntemplate <class G>\nconcept AdjacencyGraph = Graph<G> && requires(const\
      \ G &g, int v) {\n    requires std::ranges::range<decltype(g[v])>;\n    requires\
      \ Edge<std::ranges::range_value_t<decltype(g[v])>>;\n};\n\ntemplate <class G>\n\
      concept WeightedGraph = AdjacencyGraph<G> && G::weighted &&\n              \
      \          WeightedEdge<std::ranges::range_value_t<decltype(std::declval<const\
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
      \ int>;\n};\n\n} // namespace kk2::graph\n\n\n#line 14 \"graph/maxflow.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class Cap> struct MaxFlowGraph {\n    struct\
      \ arc {\n        int to, rev;\n        Cap cap;\n    };\n    struct edge {\n\
      \        int from, to, index;\n    };\n\n    std::vector<std::vector<arc>> data;\n\
      \    std::vector<edge> edges;\n\n    MaxFlowGraph() = default;\n    explicit\
      \ MaxFlowGraph(int n) : data(n) {}\n\n    template <class E>\n        requires\
      \ graph::WeightedEdgeRange<const E>\n    MaxFlowGraph(int n, const E &input)\
      \ : data(n) {\n        if constexpr (std::ranges::sized_range<const E>) {\n\
      \            edges.reserve(std::ranges::size(input));\n        }\n        if\
      \ constexpr (std::ranges::forward_range<const E>) {\n            std::vector<int>\
      \ degree(n);\n            for (const auto &e : input) {\n                ++degree[e.from];\n\
      \                ++degree[e.to];\n            }\n            for (int v = 0;\
      \ v < n; ++v) data[v].reserve(degree[v]);\n        }\n        for (const auto\
      \ &e : input) add_edge(e.from, e.to, e.cost);\n    }\n\n    void add_edge(int\
      \ from, int to, Cap cap) {\n        const int index = data[from].size();\n \
      \       data[from].push_back({to, -1, cap});\n        const int rev = data[to].size();\n\
      \        data[to].push_back({from, index, Cap(0)});\n        data[from][index].rev\
      \ = rev;\n        edges.push_back({from, to, index});\n    }\n};\n\ntemplate\
      \ <graph::WeightedDirectedGraph WG> struct MaxFlow {\n\n    using Cap = typename\
      \ WG::value_type;\n    using graph_type = MaxFlowGraph<Cap>;\n\n    graph_type\
      \ g;\n    int n, m;\n\n    MaxFlow(const WG &g_) : g(g_.num_vertices(), g_.edges),\
      \ n(g_.num_vertices()), m(g_.num_edges()) {}\n\n    template <class Edges_>\n\
      \        requires graph::WeightedEdgeRange<const Edges_>\n    MaxFlow(int n_,\
      \ const Edges_ &edges) : g(n_, edges), n(n_), m(g.edges.size()) {}\n\n    Cap\
      \ flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }\n\
      \n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s <\
      \ n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n\n       \
      \ std::vector<int> level(n), iter(n);\n        std::queue<int> que;\n\n    \
      \    auto bfs = [&]() {\n            std::fill(std::begin(level), std::end(level),\
      \ -1);\n            level[s] = 0;\n            que = std::queue<int>();\n  \
      \          que.push(s);\n            while (!que.empty()) {\n              \
      \  int v = que.front();\n                que.pop();\n                for (const\
      \ auto &e : g.data[v]) {\n                    if (e.cap == 0 || level[e.to]\
      \ >= 0) continue;\n                    level[e.to] = level[v] + 1;\n       \
      \             if (e.to == t) return;\n                    que.push(e.to);\n\
      \                }\n            }\n        };\n        auto dfs = [&](auto self,\
      \ int v, Cap up) {\n            if (v == t) return up;\n            Cap res\
      \ = 0;\n            for (int &i = iter[v]; i < (int)g.data[v].size(); i++) {\n\
      \                auto &e = g.data[v][i];\n                if (e.cap == 0 ||\
      \ level[e.to] != level[v] + 1) continue;\n                Cap d = self(self,\
      \ e.to, std::min(up - res, e.cap));\n                if (d <= 0) continue;\n\
      \                e.cap -= d;\n                g.data[e.to][e.rev].cap += d;\n\
      \                res += d;\n                if (res == up) break;\n        \
      \    }\n            return res;\n        };\n\n        Cap flow = 0;\n     \
      \   while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
      \ == -1) break;\n            std::fill(std::begin(iter), std::end(iter), 0);\n\
      \            while (flow < flow_limit) {\n                Cap f = dfs(dfs, s,\
      \ flow_limit - flow);\n                if (!f) break;\n                flow\
      \ += f;\n            }\n        }\n        return flow;\n    }\n\n    std::vector<bool>\
      \ min_cut(int s) {\n        std::vector<bool> visited(n);\n        std::queue<int>\
      \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
      \ p = que.front();\n            que.pop();\n            visited[p] = true;\n\
      \            for (const auto &e : g.data[p]) {\n                if (e.cap &&\
      \ !visited[e.to]) {\n                    visited[e.to] = true;\n           \
      \         que.push(e.to);\n                }\n            }\n        }\n   \
      \     return visited;\n    }\n\n    struct edge {\n        int from, to;\n \
      \       Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        const\
      \ auto &e = g.edges[i];\n        const auto &forward = g.data[e.from][e.index];\n\
      \        const auto &reverse = g.data[forward.to][forward.rev];\n        return\
      \ edge{e.from, e.to, forward.cap + reverse.cap, reverse.cap};\n    }\n\n   \
      \ std::vector<edge> get_edges() {\n        std::vector<edge> result(m);\n  \
      \      for (int i = 0; i < m; i++) { result[i] = get_edge(i); }\n        return\
      \ result;\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: graph/maxflow.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/graph/maxflow.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
documentation_of: graph/maxflow.hpp
layout: document
---
