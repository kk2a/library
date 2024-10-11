---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bcc.hpp
    title: graph/bcc.hpp
  - icon: ':warning:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct\
    \ LowLink {\n    int n, m;\n    const G &g;\n    std::vector<int> ord, low;\n\
    \    std::vector<bool> root, used;\n\n    LowLink(const G &g_)\n        : n(g_.n),\n\
    \          m(g_.m),\n          g(g_),\n          ord(n, -1),\n          low(n,\
    \ -1),\n          root(n, false),\n          used(m, false) {\n        init();\n\
    \    }\n\n  private:\n    void init() {\n        int k = 0;\n        auto dfs\
    \ = [&](auto self, int u, int ei = -1) -> int {\n            low[u] = ord[u] =\
    \ k++;\n            for (auto &e : g[u]) {\n                if (e.id == ei) continue;\n\
    \                if (ord[e.to] == -1) {\n                    used[e.id] = true;\n\
    \                    low[u] = std::min(low[u], self(self, e.to, e.id));\n    \
    \            }\n                // back edge\n                else if (ord[e.to]\
    \ < ord[u]) {\n                    low[u] = std::min(low[u], ord[e.to]);\n   \
    \             }\n            }\n            return low[u];\n        };\n     \
    \   for (int u = 0; u < n; u++)\n            if (ord[u] == -1) {\n           \
    \     dfs(dfs, u);\n                root[u] = true;\n            }\n    }\n};\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_LOWLINK_HPP\n#define GRAPH_LOWLINK_HPP 1\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G> struct LowLink {\n    int n, m;\n    const G &g;\n    std::vector<int> ord,\
    \ low;\n    std::vector<bool> root, used;\n\n    LowLink(const G &g_)\n      \
    \  : n(g_.n),\n          m(g_.m),\n          g(g_),\n          ord(n, -1),\n \
    \         low(n, -1),\n          root(n, false),\n          used(m, false) {\n\
    \        init();\n    }\n\n  private:\n    void init() {\n        int k = 0;\n\
    \        auto dfs = [&](auto self, int u, int ei = -1) -> int {\n            low[u]\
    \ = ord[u] = k++;\n            for (auto &e : g[u]) {\n                if (e.id\
    \ == ei) continue;\n                if (ord[e.to] == -1) {\n                 \
    \   used[e.id] = true;\n                    low[u] = std::min(low[u], self(self,\
    \ e.to, e.id));\n                }\n                // back edge\n           \
    \     else if (ord[e.to] < ord[u]) {\n                    low[u] = std::min(low[u],\
    \ ord[e.to]);\n                }\n            }\n            return low[u];\n\
    \        };\n        for (int u = 0; u < n; u++)\n            if (ord[u] == -1)\
    \ {\n                dfs(dfs, u);\n                root[u] = true;\n         \
    \   }\n    }\n};\n\n} // namespace kk2\n\n#endif // GRAPH_LOWLINK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/bcc.hpp
  - graph/two_edge_connected_components.hpp
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
