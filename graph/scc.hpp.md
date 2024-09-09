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
  bundledCode: "#line 1 \"graph/scc.hpp\"\n\n\n\n#include <algorithm>\n#include <functional>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct SCC {\n    int\
    \ n, m;\n    const G &g;\n    std::vector<std::vector<int>> revg;\n    std::vector<int>\
    \ ord, scc_id;\n    std::vector<bool> used;\n    std::vector<std::vector<int>>\
    \ blng, dag;\n\n    SCC(const G &g_) : n(g_.n), m(g_.m), g(g_) { init(); }\n\n\
    \    int operator[](int k) const { return scc_id[k]; }\n\n    std::vector<int>\
    \ same_scc(int u) const { return blng[u]; }\n\n  private:\n    void init() {\n\
    \        auto dfs = [&](auto self, int u) -> void {\n            if (used[u])\
    \ return;\n            used[u] = true;\n            for (auto &e : g[u]) self(self,\
    \ e.to);\n            ord.emplace_back(u);\n        };\n        auto rdfs = [&](auto\
    \ self, int u, int k) -> void {\n            if (scc_id[u] != -1) return;\n  \
    \          scc_id[u] = k;\n            for (auto &e : revg[u]) self(self, e, k);\n\
    \        };\n\n        used.resize(n, false);\n        ord.reserve(n);\n     \
    \   for (int u = 0; u < n; u++) dfs(dfs, u);\n        std::reverse(std::begin(ord),\
    \ std::end(ord));\n\n        scc_id.resize(n, -1);\n        revg.resize(n);\n\
    \        for (int u = 0; u < n; u++)\n            for (auto &e : g[u]) { revg[e.to].emplace_back(u);\
    \ }\n        int k = 0;\n        for (auto &u : ord)\n            if (scc_id[u]\
    \ == -1) rdfs(rdfs, u, k++);\n\n        dag.resize(k);\n        blng.resize(k);\n\
    \        for (int u = 0; u < n; u++) {\n            blng[scc_id[u]].emplace_back(u);\n\
    \            for (auto &e : g[u]) {\n                int v = e.to;\n         \
    \       if (scc_id[u] == scc_id[v]) continue;\n                dag[scc_id[u]].emplace_back(scc_id[v]);\n\
    \            }\n        }\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_SCC_HPP\n#define GRAPH_SCC_HPP 1\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G> struct SCC {\n    int n, m;\n    const G &g;\n    std::vector<std::vector<int>>\
    \ revg;\n    std::vector<int> ord, scc_id;\n    std::vector<bool> used;\n    std::vector<std::vector<int>>\
    \ blng, dag;\n\n    SCC(const G &g_) : n(g_.n), m(g_.m), g(g_) { init(); }\n\n\
    \    int operator[](int k) const { return scc_id[k]; }\n\n    std::vector<int>\
    \ same_scc(int u) const { return blng[u]; }\n\n  private:\n    void init() {\n\
    \        auto dfs = [&](auto self, int u) -> void {\n            if (used[u])\
    \ return;\n            used[u] = true;\n            for (auto &e : g[u]) self(self,\
    \ e.to);\n            ord.emplace_back(u);\n        };\n        auto rdfs = [&](auto\
    \ self, int u, int k) -> void {\n            if (scc_id[u] != -1) return;\n  \
    \          scc_id[u] = k;\n            for (auto &e : revg[u]) self(self, e, k);\n\
    \        };\n\n        used.resize(n, false);\n        ord.reserve(n);\n     \
    \   for (int u = 0; u < n; u++) dfs(dfs, u);\n        std::reverse(std::begin(ord),\
    \ std::end(ord));\n\n        scc_id.resize(n, -1);\n        revg.resize(n);\n\
    \        for (int u = 0; u < n; u++)\n            for (auto &e : g[u]) { revg[e.to].emplace_back(u);\
    \ }\n        int k = 0;\n        for (auto &u : ord)\n            if (scc_id[u]\
    \ == -1) rdfs(rdfs, u, k++);\n\n        dag.resize(k);\n        blng.resize(k);\n\
    \        for (int u = 0; u < n; u++) {\n            blng[scc_id[u]].emplace_back(u);\n\
    \            for (auto &e : g[u]) {\n                int v = e.to;\n         \
    \       if (scc_id[u] == scc_id[v]) continue;\n                dag[scc_id[u]].emplace_back(scc_id[v]);\n\
    \            }\n        }\n    }\n};\n\n} // namespace kk2\n\n#endif // GRAPH_SCC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
