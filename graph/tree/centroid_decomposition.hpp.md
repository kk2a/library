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
  bundledCode: "#line 1 \"graph/tree/centroid_decomposition.hpp\"\n\n\n\n#include\
    \ <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct CentroidDecomposition\
    \ {\n    const G &g;\n    std::vector<int> parent;\n    std::vector<int> subsize;\n\
    \    std::vector<bool> used;\n    std::vector<std::vector<int>> children;\n  \
    \  int root;\n\n    CentroidDecomposition(const G &g_, bool isbuild = true)\n\
    \        : g(g_),\n          parent(g.size(), -1),\n          subsize(g.size(),\
    \ 0),\n          used(g.size(), false),\n          children(g.size()) {\n    \
    \    if (isbuild) build();\n    }\n\n    void build() {\n        root = build_dfs(0);\n\
    \    }\n\n    int get_size(int now, int par) {\n        subsize[now] = 1;\n  \
    \      for (auto &e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n\
    \            subsize[now] += get_size(e.to, now);\n        }\n        return subsize[now];\n\
    \    }\n\n    int get_centroid(int now, int par, int mid) {\n        for (auto\
    \ &e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n     \
    \       if (subsize[e.to] > mid) return get_centroid(e.to, now, mid);\n      \
    \  }\n        return now;\n    }\n\n    int build_dfs(int v) {\n        int centroid\
    \ = get_centroid(v, -1, get_size(v, -1) / 2);\n        used[centroid] = true;\n\
    \        for (auto &e : g[centroid]) {\n            if (used[e.to]) continue;\n\
    \            int nxt = build_dfs(e.to);\n            if (centroid != nxt) {\n\
    \                children[centroid].emplace_back(nxt);\n                parent[nxt]\
    \ = centroid;\n            }\n        }\n        used[centroid] = false;\n   \
    \     return centroid;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\n#define GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> struct CentroidDecomposition\
    \ {\n    const G &g;\n    std::vector<int> parent;\n    std::vector<int> subsize;\n\
    \    std::vector<bool> used;\n    std::vector<std::vector<int>> children;\n  \
    \  int root;\n\n    CentroidDecomposition(const G &g_, bool isbuild = true)\n\
    \        : g(g_),\n          parent(g.size(), -1),\n          subsize(g.size(),\
    \ 0),\n          used(g.size(), false),\n          children(g.size()) {\n    \
    \    if (isbuild) build();\n    }\n\n    void build() {\n        root = build_dfs(0);\n\
    \    }\n\n    int get_size(int now, int par) {\n        subsize[now] = 1;\n  \
    \      for (auto &e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n\
    \            subsize[now] += get_size(e.to, now);\n        }\n        return subsize[now];\n\
    \    }\n\n    int get_centroid(int now, int par, int mid) {\n        for (auto\
    \ &e : g[now]) {\n            if (e.to == par or used[e.to]) continue;\n     \
    \       if (subsize[e.to] > mid) return get_centroid(e.to, now, mid);\n      \
    \  }\n        return now;\n    }\n\n    int build_dfs(int v) {\n        int centroid\
    \ = get_centroid(v, -1, get_size(v, -1) / 2);\n        used[centroid] = true;\n\
    \        for (auto &e : g[centroid]) {\n            if (used[e.to]) continue;\n\
    \            int nxt = build_dfs(e.to);\n            if (centroid != nxt) {\n\
    \                children[centroid].emplace_back(nxt);\n                parent[nxt]\
    \ = centroid;\n            }\n        }\n        used[centroid] = false;\n   \
    \     return centroid;\n    }\n};\n\n} // namespace kk2\n\n#endif // GRAPH_TREE_CENTROID_DECOMPOSITION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-09-25 21:40:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/tree/centroid_decomposition.hpp
- /library/graph/tree/centroid_decomposition.hpp.html
title: graph/tree/centroid_decomposition.hpp
---
