---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bcc.hpp
    title: graph/bcc.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\n\n\ntemplate <class G>\nstruct LowLink\
    \ {\n    int n, m;\n    const G &g;\n    vector<int> ord, low;\n    vector<bool>\
    \ root, used;\n    LowLink(const G &g_) : n(g_.n), m(g_.m), g(g_),\n         \
    \                  ord(n, -1), low(n, -1), root(n, false),\n                 \
    \          used(m, false) {\n        init();\n    }\n\n    void init() {\n   \
    \     int k = 0;\n        auto dfs = [&](auto self, int u, int ei = -1) -> int\
    \ {\n            low[u] = ord[u] = k++;\n            for (auto &e : g[u]) {\n\
    \                if (e.id == ei) continue;\n                if (ord[e.to] == -1)\
    \ {\n                    used[e.id] = true;\n                    low[u] = min(low[u],\
    \ self(self, e.to, e.id));\n                }\n                // back edge\n\
    \                else if (ord[e.to] < ord[u]) {\n                    low[u] =\
    \ min(low[u], ord[e.to]);\n                }\n            }\n            return\
    \ low[u];\n        };\n        for (int u = 0; u < n; u++) if (ord[u] == -1) {\n\
    \            dfs(dfs, u);\n            root[u] = true;\n        }\n        //\
    \ for (int i = 0; i < n; i++) {\n        //     cout << i << \" \" << ord[i] <<\
    \ \" \" << low[i] << \" \"  << par[i] << endl;\n        // }\n    }\n};\n\n\n"
  code: "#ifndef GRAPH_LOWLINK_HPP\n#define GRAPH_LOWLINK_HPP 1\n\ntemplate <class\
    \ G>\nstruct LowLink {\n    int n, m;\n    const G &g;\n    vector<int> ord, low;\n\
    \    vector<bool> root, used;\n    LowLink(const G &g_) : n(g_.n), m(g_.m), g(g_),\n\
    \                           ord(n, -1), low(n, -1), root(n, false),\n        \
    \                   used(m, false) {\n        init();\n    }\n\n    void init()\
    \ {\n        int k = 0;\n        auto dfs = [&](auto self, int u, int ei = -1)\
    \ -> int {\n            low[u] = ord[u] = k++;\n            for (auto &e : g[u])\
    \ {\n                if (e.id == ei) continue;\n                if (ord[e.to]\
    \ == -1) {\n                    used[e.id] = true;\n                    low[u]\
    \ = min(low[u], self(self, e.to, e.id));\n                }\n                //\
    \ back edge\n                else if (ord[e.to] < ord[u]) {\n                \
    \    low[u] = min(low[u], ord[e.to]);\n                }\n            }\n    \
    \        return low[u];\n        };\n        for (int u = 0; u < n; u++) if (ord[u]\
    \ == -1) {\n            dfs(dfs, u);\n            root[u] = true;\n        }\n\
    \        // for (int i = 0; i < n; i++) {\n        //     cout << i << \" \" <<\
    \ ord[i] << \" \" << low[i] << \" \"  << par[i] << endl;\n        // }\n    }\n\
    };\n\n#endif // GRAPH_LOWLINK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/bcc.hpp
  timestamp: '2024-06-08 15:55:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
