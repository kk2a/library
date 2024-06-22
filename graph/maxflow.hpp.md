---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/maxflow.hpp\"\n\n\n\n\ntemplate <class WG>\nstruct\
    \ MaxFlow {\n    static_assert(WG::directed(), \"Directed graph required.\");\n\
    \n    using Cap = typename WG::value_type;\n\n    WG g;\n    int n, m;\n    vector<int>\
    \ revi;\n\n    MaxFlow(const WG &g_) : g(g_), n(g.num_vertices()),\n         \
    \                   m(g.num_edges()) { init(); }\n\n    void init() {\n      \
    \  revi.resize(m << 1, -1);\n        vector<int> count(n, 0);\n        for (int\
    \ i = 0; i < m; i++) {\n            auto e = g.edges[i];\n            revi[i]\
    \ = (int)g[e.to].size();\n            revi[m + i] = count[e.from]++;\n       \
    \     g.add_edge_naive(e.to, e.from, 0);\n        }\n    } \n\n    Cap flow(int\
    \ s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n \
    \   }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s &&\
    \ s < n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n\n     \
    \   vector<int> level(n), iter(n);\n        queue<int> que;\n\n        auto bfs\
    \ = [&]() {\n            fill(begin(level), end(level), -1);\n            level[s]\
    \ = 0;\n            que = queue<int>();\n            que.push(s);\n          \
    \  while (!que.empty()) {\n                int v = que.front();\n            \
    \    que.pop();\n                for (auto &e : g[v]) {\n                    if\
    \ (e.cost == 0 || level[e.to] >= 0) continue;\n                    level[e.to]\
    \ = level[v] + 1;\n                    if (e.to == t) return;\n              \
    \      que.push(e.to);\n                }\n            }\n        };\n       \
    \ auto dfs = [&](auto self, int v, Cap up) {\n            if (v == s) return up;\n\
    \            Cap res = 0;\n            for (int &i = iter[v]; i < (int)g[v].size();\
    \ i++) {\n                auto &e = g[v][i];\n                if (level[v] <=\
    \ level[e.to] || g[e.to][revi[e.id]].cost == 0) continue;\n                Cap\
    \ d =\n                    self(self, e.to,\n                         min(up -\
    \ res, g[e.to][revi[e.id]].cost));\n                if (d <= 0) continue;\n  \
    \              g[v][i].cost += d;\n                g[e.to][revi[e.id]].cost -=\
    \ d;\n                res += d;\n                if (res == up) break;\n     \
    \       }\n            return res;\n        };\n\n        Cap flow = 0;\n    \
    \    while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
    \ == -1) break;\n            fill(begin(iter), end(iter), 0);\n            while\
    \ (flow < flow_limit) {\n                Cap f = dfs(dfs, t, flow_limit - flow);\n\
    \                if (!f) break;\n                flow += f;\n            }\n \
    \       }\n        return flow;\n    }\n\n    vector<bool> min_cut(int s) {\n\
    \        vector<bool> visited(n);\n        queue<int> que;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int p = que.front();\n          \
    \  que.pop();\n            visited[p] = true;\n            for (auto &e : g[p])\
    \ {\n                if (e.cost && !visited[e.to]) {\n                    visited[e.to]\
    \ = true;\n                    que.push(e.to);\n                }\n          \
    \  }\n        }\n        return visited;\n    }\n\n    struct edge {\n       \
    \ int from, to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n\
    \        auto e = g.edges[i];\n        return edge{e.from, e.to, e.cost + g[e.to][revi[i]].cost,\n\
    \                    g[e.to][revi[i]].cost};\n    }\n\n    vector<edge> get_edges()\
    \ {\n        vector<edge> result(m);\n        for (int i = 0; i < m; i++) {\n\
    \            result[i] = get_edge(i);\n        }\n        return result;\n   \
    \ }\n};\n\n\n"
  code: "#ifndef GRAPH_MAXFLOW_HPP\n#define GRAPH_MAXFLOW_HPP 1\n\n\ntemplate <class\
    \ WG>\nstruct MaxFlow {\n    static_assert(WG::directed(), \"Directed graph required.\"\
    );\n\n    using Cap = typename WG::value_type;\n\n    WG g;\n    int n, m;\n \
    \   vector<int> revi;\n\n    MaxFlow(const WG &g_) : g(g_), n(g.num_vertices()),\n\
    \                            m(g.num_edges()) { init(); }\n\n    void init() {\n\
    \        revi.resize(m << 1, -1);\n        vector<int> count(n, 0);\n        for\
    \ (int i = 0; i < m; i++) {\n            auto e = g.edges[i];\n            revi[i]\
    \ = (int)g[e.to].size();\n            revi[m + i] = count[e.from]++;\n       \
    \     g.add_edge_naive(e.to, e.from, 0);\n        }\n    } \n\n    Cap flow(int\
    \ s, int t) {\n        return flow(s, t, std::numeric_limits<Cap>::max());\n \
    \   }\n\n    Cap flow(int s, int t, Cap flow_limit) {\n        assert(0 <= s &&\
    \ s < n);\n        assert(0 <= t && t < n);\n        assert(s != t);\n\n     \
    \   vector<int> level(n), iter(n);\n        queue<int> que;\n\n        auto bfs\
    \ = [&]() {\n            fill(begin(level), end(level), -1);\n            level[s]\
    \ = 0;\n            que = queue<int>();\n            que.push(s);\n          \
    \  while (!que.empty()) {\n                int v = que.front();\n            \
    \    que.pop();\n                for (auto &e : g[v]) {\n                    if\
    \ (e.cost == 0 || level[e.to] >= 0) continue;\n                    level[e.to]\
    \ = level[v] + 1;\n                    if (e.to == t) return;\n              \
    \      que.push(e.to);\n                }\n            }\n        };\n       \
    \ auto dfs = [&](auto self, int v, Cap up) {\n            if (v == s) return up;\n\
    \            Cap res = 0;\n            for (int &i = iter[v]; i < (int)g[v].size();\
    \ i++) {\n                auto &e = g[v][i];\n                if (level[v] <=\
    \ level[e.to] || g[e.to][revi[e.id]].cost == 0) continue;\n                Cap\
    \ d =\n                    self(self, e.to,\n                         min(up -\
    \ res, g[e.to][revi[e.id]].cost));\n                if (d <= 0) continue;\n  \
    \              g[v][i].cost += d;\n                g[e.to][revi[e.id]].cost -=\
    \ d;\n                res += d;\n                if (res == up) break;\n     \
    \       }\n            return res;\n        };\n\n        Cap flow = 0;\n    \
    \    while (flow < flow_limit) {\n            bfs();\n            if (level[t]\
    \ == -1) break;\n            fill(begin(iter), end(iter), 0);\n            while\
    \ (flow < flow_limit) {\n                Cap f = dfs(dfs, t, flow_limit - flow);\n\
    \                if (!f) break;\n                flow += f;\n            }\n \
    \       }\n        return flow;\n    }\n\n    vector<bool> min_cut(int s) {\n\
    \        vector<bool> visited(n);\n        queue<int> que;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int p = que.front();\n          \
    \  que.pop();\n            visited[p] = true;\n            for (auto &e : g[p])\
    \ {\n                if (e.cost && !visited[e.to]) {\n                    visited[e.to]\
    \ = true;\n                    que.push(e.to);\n                }\n          \
    \  }\n        }\n        return visited;\n    }\n\n    struct edge {\n       \
    \ int from, to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n\
    \        auto e = g.edges[i];\n        return edge{e.from, e.to, e.cost + g[e.to][revi[i]].cost,\n\
    \                    g[e.to][revi[i]].cost};\n    }\n\n    vector<edge> get_edges()\
    \ {\n        vector<edge> result(m);\n        for (int i = 0; i < m; i++) {\n\
    \            result[i] = get_edge(i);\n        }\n        return result;\n   \
    \ }\n};\n\n#endif // GRAPH_MAXFLOW_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maxflow.hpp
  requiredBy: []
  timestamp: '2024-06-22 19:04:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maxflow.hpp
layout: document
redirect_from:
- /library/graph/maxflow.hpp
- /library/graph/maxflow.hpp.html
title: graph/maxflow.hpp
---
