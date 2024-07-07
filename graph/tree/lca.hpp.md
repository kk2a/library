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
  bundledCode: "#line 1 \"graph/tree/lca.hpp\"\n\n\n\ntemplate <class G>\n\nstruct\
    \ LCA {\n    vector<vector<int>> parent;\n    vector<int> depth, perm;\n    const\
    \ G &g;\n    int root;\n    LCA(const G &g_, int root_=0) : g(g_), root(root_)\
    \ { init(root_); }\n\n    void init(int root) {\n        int n = g.size(), h =\
    \ 1;\n        while ((1 << h) < n) h++;\n        parent.assign(h, vector<int>(n,\
    \ -1));\n        depth.assign(n, -1);\n        perm.assign(n, -1);\n        int\
    \ p = 0;\n        auto dfs = [&](auto self, int now, int pre, int d) -> void {\n\
    \            perm[p++] = now;\n            parent[0][now] = pre;\n           \
    \ depth[now] = d;\n            for (auto &e : g[now]) if ((int)e != pre) self(self,\
    \ (int)e, now, d + 1);\n        };\n        dfs(dfs, root, -1, 0);\n        for\
    \ (int i = 0; i < h - 1; i++) {\n            for (int j = 0; j < n; j++) {\n \
    \               if (parent[i][j] == -1) continue;\n                parent[i +\
    \ 1][j] = parent[i][parent[i][j]];\n            }\n        }\n    }\n\n    int\
    \ lca(int u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n        int\
    \ h = parent.size();\n        for (int i = 0; i < h; i++) {\n            if ((depth[v]\
    \ - depth[u]) >> i & 1) {\n                v = parent[i][v];\n            }\n\
    \        }\n        if (u == v) return u;\n        for (int i = h - 1; i >= 0;\
    \ i--) {\n            if (parent[i][u] != parent[i][v]) {\n                u =\
    \ parent[i][u];\n                v = parent[i][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n\n    int dist(int u, int v) {\n       \
    \ return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n};\n\n\n"
  code: "#ifndef LCA_HPP\n#define LCA_HPP 1\n\ntemplate <class G>\n\nstruct LCA {\n\
    \    vector<vector<int>> parent;\n    vector<int> depth, perm;\n    const G &g;\n\
    \    int root;\n    LCA(const G &g_, int root_=0) : g(g_), root(root_) { init(root_);\
    \ }\n\n    void init(int root) {\n        int n = g.size(), h = 1;\n        while\
    \ ((1 << h) < n) h++;\n        parent.assign(h, vector<int>(n, -1));\n       \
    \ depth.assign(n, -1);\n        perm.assign(n, -1);\n        int p = 0;\n    \
    \    auto dfs = [&](auto self, int now, int pre, int d) -> void {\n          \
    \  perm[p++] = now;\n            parent[0][now] = pre;\n            depth[now]\
    \ = d;\n            for (auto &e : g[now]) if ((int)e != pre) self(self, (int)e,\
    \ now, d + 1);\n        };\n        dfs(dfs, root, -1, 0);\n        for (int i\
    \ = 0; i < h - 1; i++) {\n            for (int j = 0; j < n; j++) {\n        \
    \        if (parent[i][j] == -1) continue;\n                parent[i + 1][j] =\
    \ parent[i][parent[i][j]];\n            }\n        }\n    }\n\n    int lca(int\
    \ u, int v) {\n        if (depth[u] > depth[v]) swap(u, v);\n        int h = parent.size();\n\
    \        for (int i = 0; i < h; i++) {\n            if ((depth[v] - depth[u])\
    \ >> i & 1) {\n                v = parent[i][v];\n            }\n        }\n \
    \       if (u == v) return u;\n        for (int i = h - 1; i >= 0; i--) {\n  \
    \          if (parent[i][u] != parent[i][v]) {\n                u = parent[i][u];\n\
    \                v = parent[i][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    int dist(int u, int v) {\n        return depth[u] + depth[v] - 2\
    \ * depth[lca(u, v)];\n    }\n};\n\n#endif // LCA_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lca.hpp
  requiredBy: []
  timestamp: '2024-07-07 23:49:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/lca.hpp
layout: document
redirect_from:
- /library/graph/tree/lca.hpp
- /library/graph/tree/lca.hpp.html
title: graph/tree/lca.hpp
---
