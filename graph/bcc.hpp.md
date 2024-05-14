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
  bundledCode: "#line 1 \"graph/bcc.hpp\"\n\n\n\nstruct LowLink {\n    struct Edge\
    \ {\n        int to, id;\n        Edge() {}\n        Edge(int to, int id = -1)\
    \ : to(to), id(id) {}\n    };\n    int n, m;\n    vector<vector<Edge>> g;\n  \
    \  LowLink(int n_) : n(n_), m(0), g(n_) {}\n\n    void add_edge(int a, int b)\
    \ {\n        g[a].emplace_back(b, m);\n        g[b].emplace_back(a, m++);\n  \
    \  }\n\n    vector<int> ord, low, par; \n    void init() {\n        ord = low\
    \ = par = vector<int>(n, -1);\n        int k = 0;\n        auto dfs = [&](auto\
    \ self, int v, int ei = -1) -> int {\n            low[v] = ord[v] = k++;\n   \
    \         for (auto ch : g[v]) {\n                if (ch.id == ei) continue;\n\
    \                if (ord[ch.to] == -1) {\n                    par[ch.to] = v;\n\
    \                    low[v] = min(low[v], self(self, ch.to, ch.id));\n       \
    \         }\n                else if (ord[ch.to] < ord[v]) {\n               \
    \     low[v] = min(low[v], ord[ch.to]);\n                }\n            }\n  \
    \          return low[v];\n        };\n        for (int v = 0; v < n; v++) if\
    \ (ord[v] == -1) dfs(dfs, v);\n    }\n\n    vector<vector<int>> bc;\n    vector<int>\
    \ bc_id;\n    void bcc() {\n        bc_id = vector<int>(m, -1);\n        auto\
    \ add = [&](int ei, int k) {\n            bc[k].emplace_back(ei);\n          \
    \  bc_id[ei] = k;\n        };\n        auto dfs = [&](auto self, int v, int k\
    \ = -1) -> void {\n            for (auto e : g[v]) if (e.to != par[v]) {\n   \
    \             if (par[e.to] == v) {\n                    int nk = k;\n       \
    \             if (low[e.to] >= ord[v]) nk = bc.size(), bc.emplace_back();\n  \
    \                  add(e.id, nk);\n                    self(self, e.to, nk);\n\
    \                }\n                else if (ord[e.to] < ord[v]) {\n         \
    \           add(e.id, k);\n                }\n            }\n        };\n    \
    \    for (int v = 0; v < n; v++) if (par[v] == -1) dfs(dfs, v);\n    }\n};\n\n\
    \n"
  code: "#ifndef GRAPH_BCC_HPP\n#define GRAPH_BCC_HPP 1\n\nstruct LowLink {\n    struct\
    \ Edge {\n        int to, id;\n        Edge() {}\n        Edge(int to, int id\
    \ = -1) : to(to), id(id) {}\n    };\n    int n, m;\n    vector<vector<Edge>> g;\n\
    \    LowLink(int n_) : n(n_), m(0), g(n_) {}\n\n    void add_edge(int a, int b)\
    \ {\n        g[a].emplace_back(b, m);\n        g[b].emplace_back(a, m++);\n  \
    \  }\n\n    vector<int> ord, low, par; \n    void init() {\n        ord = low\
    \ = par = vector<int>(n, -1);\n        int k = 0;\n        auto dfs = [&](auto\
    \ self, int v, int ei = -1) -> int {\n            low[v] = ord[v] = k++;\n   \
    \         for (auto ch : g[v]) {\n                if (ch.id == ei) continue;\n\
    \                if (ord[ch.to] == -1) {\n                    par[ch.to] = v;\n\
    \                    low[v] = min(low[v], self(self, ch.to, ch.id));\n       \
    \         }\n                else if (ord[ch.to] < ord[v]) {\n               \
    \     low[v] = min(low[v], ord[ch.to]);\n                }\n            }\n  \
    \          return low[v];\n        };\n        for (int v = 0; v < n; v++) if\
    \ (ord[v] == -1) dfs(dfs, v);\n    }\n\n    vector<vector<int>> bc;\n    vector<int>\
    \ bc_id;\n    void bcc() {\n        bc_id = vector<int>(m, -1);\n        auto\
    \ add = [&](int ei, int k) {\n            bc[k].emplace_back(ei);\n          \
    \  bc_id[ei] = k;\n        };\n        auto dfs = [&](auto self, int v, int k\
    \ = -1) -> void {\n            for (auto e : g[v]) if (e.to != par[v]) {\n   \
    \             if (par[e.to] == v) {\n                    int nk = k;\n       \
    \             if (low[e.to] >= ord[v]) nk = bc.size(), bc.emplace_back();\n  \
    \                  add(e.id, nk);\n                    self(self, e.to, nk);\n\
    \                }\n                else if (ord[e.to] < ord[v]) {\n         \
    \           add(e.id, k);\n                }\n            }\n        };\n    \
    \    for (int v = 0; v < n; v++) if (par[v] == -1) dfs(dfs, v);\n    }\n};\n\n\
    #endif // GRAPH_BCC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bcc.hpp
  requiredBy: []
  timestamp: '2024-05-14 18:36:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bcc.hpp
layout: document
redirect_from:
- /library/graph/bcc.hpp
- /library/graph/bcc.hpp.html
title: graph/bcc.hpp
---
