---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/auxiliary_tree.hpp
    title: graph/tree/auxiliary_tree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\n\n\n\nnamespace\
    \ kk2 {\n\ntemplate <typename G>\nstruct HeavyLightDecomposition {\n    G& g;\n\
    \    int root, id;\n    vector<int> sz, in, out, head, par, dep;\n    HeavyLightDecomposition(G&\
    \ g_, int root_ = 0) \n        : g(g_),\n          root(root_),\n          id(0),\n\
    \          sz(g.size(), 0),\n          in(g.size(), -1),\n          out(g.size(),\
    \ -1),\n          head(g.size(), root),\n          par(g.size(), root),\n    \
    \      dep(g.size(), 0) {\n        init();\n    }\n\n    int lca(int u, int v)\
    \ const {\n        while (head[u] != head[v]) {\n            if (in[u] < in[v])\
    \ swap(u, v);\n            u = par[head[u]];\n        }\n        return dep[u]\
    \ < dep[v] ? u : v;\n    }\n\n    int dist(int u, int v) const {\n        return\
    \ dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n  private:\n    void init()\
    \ {\n        auto dfs_sz = [&](auto self, int now) -> void {\n            sz[now]\
    \ = 1;\n            for (auto& e : g[now]) {\n                if ((int)e == par[now])\
    \ {\n                    if (g[now].size() >= 2 and e == g[now][0])\n        \
    \                swap(e, g[now][1]);\n                    else \n            \
    \            continue;\n                }\n                par[(int)e] = now;\n\
    \                dep[(int)e] = dep[now] + 1;\n                self(self, (int)e);\n\
    \                sz[now] += sz[(int)e];\n                if (sz[(int)e] > sz[(int)g[now][0]])\n\
    \                    swap(e, g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz,\
    \ root);\n\n        auto dfs_hld = [&](auto self, int now) -> void {\n       \
    \     in[now] = id++;\n            for (auto& e : g[now]) {\n                if\
    \ ((int)e == par[now]) continue;\n                head[(int)e] = ((int)e == (int)g[now][0]\
    \ ? head[now] : (int)e);\n                self(self, (int)e);\n            }\n\
    \            out[now] = id;\n        };\n        dfs_hld(dfs_hld, root);\n   \
    \ }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\
    \ 1\n\nnamespace kk2 {\n\ntemplate <typename G>\nstruct HeavyLightDecomposition\
    \ {\n    G& g;\n    int root, id;\n    vector<int> sz, in, out, head, par, dep;\n\
    \    HeavyLightDecomposition(G& g_, int root_ = 0) \n        : g(g_),\n      \
    \    root(root_),\n          id(0),\n          sz(g.size(), 0),\n          in(g.size(),\
    \ -1),\n          out(g.size(), -1),\n          head(g.size(), root),\n      \
    \    par(g.size(), root),\n          dep(g.size(), 0) {\n        init();\n   \
    \ }\n\n    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n\
    \            if (in[u] < in[v]) swap(u, v);\n            u = par[head[u]];\n \
    \       }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int\
    \ u, int v) const {\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  \
    \  }\n\n  private:\n    void init() {\n        auto dfs_sz = [&](auto self, int\
    \ now) -> void {\n            sz[now] = 1;\n            for (auto& e : g[now])\
    \ {\n                if ((int)e == par[now]) {\n                    if (g[now].size()\
    \ >= 2 and e == g[now][0])\n                        swap(e, g[now][1]);\n    \
    \                else \n                        continue;\n                }\n\
    \                par[(int)e] = now;\n                dep[(int)e] = dep[now] +\
    \ 1;\n                self(self, (int)e);\n                sz[now] += sz[(int)e];\n\
    \                if (sz[(int)e] > sz[(int)g[now][0]])\n                    swap(e,\
    \ g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz, root);\n\n  \
    \      auto dfs_hld = [&](auto self, int now) -> void {\n            in[now] =\
    \ id++;\n            for (auto& e : g[now]) {\n                if ((int)e == par[now])\
    \ continue;\n                head[(int)e] = ((int)e == (int)g[now][0] ? head[now]\
    \ : (int)e);\n                self(self, (int)e);\n            }\n           \
    \ out[now] = id;\n        };\n        dfs_hld(dfs_hld, root);\n    }\n};\n\n}\
    \ // namespace kk2\n\n#endif // GRAPH_TREE_HEAVY_LIGHT_DECOMPOSITION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/heavy_light_decomposition.hpp
  requiredBy:
  - graph/tree/auxiliary_tree.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/graph/tree/heavy_light_decomposition.hpp
- /library/graph/tree/heavy_light_decomposition.hpp.html
title: graph/tree/heavy_light_decomposition.hpp
---
