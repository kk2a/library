---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bcc.hpp\"\n\n\n\n#line 1 \"graph/lowlink.hpp\"\n\n\
    \n\nnamespace kk2 {\n\ntemplate <class G>\nstruct LowLink {\n    int n, m;\n \
    \   const G &g;\n    vector<int> ord, low;\n    vector<bool> root, used;\n   \
    \ LowLink(const G &g_) : n(g_.n), m(g_.m), g(g_),\n                          \
    \ ord(n, -1), low(n, -1), root(n, false),\n                           used(m,\
    \ false) {\n        init();\n    }\n\n  private:\n    void init() {\n        int\
    \ k = 0;\n        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n   \
    \         low[u] = ord[u] = k++;\n            for (auto &e : g[u]) {\n       \
    \         if (e.id == ei) continue;\n                if (ord[e.to] == -1) {\n\
    \                    used[e.id] = true;\n                    low[u] = min(low[u],\
    \ self(self, e.to, e.id));\n                }\n                // back edge\n\
    \                else if (ord[e.to] < ord[u]) {\n                    low[u] =\
    \ min(low[u], ord[e.to]);\n                }\n            }\n            return\
    \ low[u];\n        };\n        for (int u = 0; u < n; u++) if (ord[u] == -1) {\n\
    \            dfs(dfs, u);\n            root[u] = true;\n        }\n    }\n};\n\
    \n} // namespace kk2\n\n\n#line 5 \"graph/bcc.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class G>\nstruct BCC : LowLink<G> {\n    BCC(const G &g_) : LowLink<G>(g_)\
    \ { init(); }\n\n    vector<vector<int>> bc_e;\n    vector<int> bc_id;\n\n  private:\n\
    \    // v is a child of u in DFS tree\n    // edge(u, v) is a bridge <=> ord[u]\
    \ < low[v]\n    // u is an articulation point <=> u is root and \n    void init()\
    \ {\n        bc_id = vector<int>(this->m, -1);\n        auto add = [&](int ei,\
    \ int k) {\n            bc_e[k].emplace_back(ei);\n            bc_id[ei] = k;\n\
    \        };\n        auto dfs = [&](auto self, int u, int k = -1, int ei = -1)\
    \ -> void {\n            for (auto &e : this->g[u]) {\n                if (e.id\
    \ == ei) continue;\n                if (this->used[e.id]) {\n                \
    \    int nk = k;\n                    if (this->low[e.to] >= this->ord[u]) nk\
    \ = bc_e.size(), bc_e.emplace_back();\n                    add(e.id, nk);\n  \
    \                  self(self, e.to, nk, e.id);\n                }\n          \
    \      // back edge\n                else if (this->ord[e.to] < this->ord[u])\
    \ {\n                    add(e.id, k);\n                }\n            }\n   \
    \     };\n        for (int u = 0; u < this->n; u++) if (this->root[u]) {\n   \
    \         dfs(dfs, u);\n        }\n    }\n\n  public:\n    vector<vector<int>>\
    \ get_bcc_vertices() {\n        vector<bool> buf1(this->n), buf2(this->n);\n \
    \       vector<vector<int>> res;\n        res.reserve(bc_e.size());\n        for\
    \ (auto &bc : bc_e) {\n            if (bc.empty()) continue;\n            int\
    \ k = (int)res.size();\n            res.emplace_back();\n            for (auto\
    \ &ei : bc) {\n                auto e = this->g.edges[ei];\n                int\
    \ fr = e.from, to = e.to;\n                if (!buf2[fr]) {\n                \
    \    res[k].emplace_back(fr);\n                    buf2[fr] = true;\n        \
    \        }\n                if (!buf2[to]) {\n                    res[k].emplace_back(to);\n\
    \                    buf2[to] = true;\n                }\n                buf1[fr]\
    \ = buf1[to] = true;\n            }\n            for (auto &ei : bc) {\n     \
    \           auto e = this->g.edges[ei];\n                int fr = e.from, to =\
    \ e.to;\n                buf2[fr] = buf2[to] = false;\n            }\n       \
    \ }\n        for (int i = 0; i < this->n; i++) if (!buf1[i]) {\n            int\
    \ k = (int)res.size();\n            res.emplace_back();\n            res[k].emplace_back(i);\n\
    \        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_BCC_HPP\n#define GRAPH_BCC_HPP 1\n\n#include \"lowlink.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class G>\nstruct BCC : LowLink<G> {\n    BCC(const\
    \ G &g_) : LowLink<G>(g_) { init(); }\n\n    vector<vector<int>> bc_e;\n    vector<int>\
    \ bc_id;\n\n  private:\n    // v is a child of u in DFS tree\n    // edge(u, v)\
    \ is a bridge <=> ord[u] < low[v]\n    // u is an articulation point <=> u is\
    \ root and \n    void init() {\n        bc_id = vector<int>(this->m, -1);\n  \
    \      auto add = [&](int ei, int k) {\n            bc_e[k].emplace_back(ei);\n\
    \            bc_id[ei] = k;\n        };\n        auto dfs = [&](auto self, int\
    \ u, int k = -1, int ei = -1) -> void {\n            for (auto &e : this->g[u])\
    \ {\n                if (e.id == ei) continue;\n                if (this->used[e.id])\
    \ {\n                    int nk = k;\n                    if (this->low[e.to]\
    \ >= this->ord[u]) nk = bc_e.size(), bc_e.emplace_back();\n                  \
    \  add(e.id, nk);\n                    self(self, e.to, nk, e.id);\n         \
    \       }\n                // back edge\n                else if (this->ord[e.to]\
    \ < this->ord[u]) {\n                    add(e.id, k);\n                }\n  \
    \          }\n        };\n        for (int u = 0; u < this->n; u++) if (this->root[u])\
    \ {\n            dfs(dfs, u);\n        }\n    }\n\n  public:\n    vector<vector<int>>\
    \ get_bcc_vertices() {\n        vector<bool> buf1(this->n), buf2(this->n);\n \
    \       vector<vector<int>> res;\n        res.reserve(bc_e.size());\n        for\
    \ (auto &bc : bc_e) {\n            if (bc.empty()) continue;\n            int\
    \ k = (int)res.size();\n            res.emplace_back();\n            for (auto\
    \ &ei : bc) {\n                auto e = this->g.edges[ei];\n                int\
    \ fr = e.from, to = e.to;\n                if (!buf2[fr]) {\n                \
    \    res[k].emplace_back(fr);\n                    buf2[fr] = true;\n        \
    \        }\n                if (!buf2[to]) {\n                    res[k].emplace_back(to);\n\
    \                    buf2[to] = true;\n                }\n                buf1[fr]\
    \ = buf1[to] = true;\n            }\n            for (auto &ei : bc) {\n     \
    \           auto e = this->g.edges[ei];\n                int fr = e.from, to =\
    \ e.to;\n                buf2[fr] = buf2[to] = false;\n            }\n       \
    \ }\n        for (int i = 0; i < this->n; i++) if (!buf1[i]) {\n            int\
    \ k = (int)res.size();\n            res.emplace_back();\n            res[k].emplace_back(i);\n\
    \        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n#endif //\
    \ GRAPH_BCC_HPP\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/bcc.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bcc.hpp
layout: document
redirect_from:
- /library/graph/bcc.hpp
- /library/graph/bcc.hpp.html
title: graph/bcc.hpp
---
