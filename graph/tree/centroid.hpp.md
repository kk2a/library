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
  bundledCode: "#line 1 \"graph/tree/centroid.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <functional>\n#include <numeric>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> int centroid(const G &g) {\n    int n = g.size();\n    std::vector<int>\
    \ sz(n, 0);\n    auto dfs = [&](auto &&self, int u, int p = -1) -> int {\n   \
    \     sz[u] = 1;\n        for (int v : g[u])\n            if (v != p) { sz[u]\
    \ += self(self, v, u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n\
    \    auto find = [&](auto &&self, int u, int p = -1) -> int {\n        bool is_centroid\
    \ = true;\n        for (int v : g[u])\n            if (v != p) {\n           \
    \     int ret = self(self, v, u);\n                if (ret != -1) return ret;\n\
    \                if (sz[v] > n / 2) is_centroid = false;\n            }\n    \
    \    if ((n - sz[u]) > n / 2) is_centroid = false;\n        return is_centroid\
    \ ? u : -1;\n    };\n    return find(find, 0);\n}\n\ntemplate <class G> int centroid(const\
    \ G &g, const std::vector<long long> &weight) {\n    assert((int)g.size() == (int)weight.size());\n\
    \    int n = g.size();\n    std::vector<long long> sz(n, 0);\n    long long sum\
    \ = std::accumulate(std::begin(weight), std::end(weight), 0LL);\n    auto dfs\
    \ = [&](auto &&self, int u, int p = -1) -> long long {\n        sz[u] = weight[u];\n\
    \        for (int v : g[u])\n            if (v != p) { sz[u] += self(self, v,\
    \ u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n    auto find = [&](auto\
    \ &&self, int u, int p = -1) -> int {\n        bool is_centroid = true;\n    \
    \    for (int v : g[u])\n            if (v != p) {\n                int ret =\
    \ self(self, v, u);\n                if (ret != -1) return ret;\n            \
    \    if (sz[v] > sum / 2) is_centroid = false;\n            }\n        if ((sum\
    \ - sz[u]) > sum / 2) is_centroid = false;\n        return is_centroid ? u : -1;\n\
    \    };\n    return find(find, 0);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CENTROID_HPP\n#define CENTROID_HPP 1\n\n#include <cassert>\n#include\
    \ <functional>\n#include <numeric>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> int centroid(const G &g) {\n    int n = g.size();\n    std::vector<int>\
    \ sz(n, 0);\n    auto dfs = [&](auto &&self, int u, int p = -1) -> int {\n   \
    \     sz[u] = 1;\n        for (int v : g[u])\n            if (v != p) { sz[u]\
    \ += self(self, v, u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n\
    \    auto find = [&](auto &&self, int u, int p = -1) -> int {\n        bool is_centroid\
    \ = true;\n        for (int v : g[u])\n            if (v != p) {\n           \
    \     int ret = self(self, v, u);\n                if (ret != -1) return ret;\n\
    \                if (sz[v] > n / 2) is_centroid = false;\n            }\n    \
    \    if ((n - sz[u]) > n / 2) is_centroid = false;\n        return is_centroid\
    \ ? u : -1;\n    };\n    return find(find, 0);\n}\n\ntemplate <class G> int centroid(const\
    \ G &g, const std::vector<long long> &weight) {\n    assert((int)g.size() == (int)weight.size());\n\
    \    int n = g.size();\n    std::vector<long long> sz(n, 0);\n    long long sum\
    \ = std::accumulate(std::begin(weight), std::end(weight), 0LL);\n    auto dfs\
    \ = [&](auto &&self, int u, int p = -1) -> long long {\n        sz[u] = weight[u];\n\
    \        for (int v : g[u])\n            if (v != p) { sz[u] += self(self, v,\
    \ u); }\n        return sz[u];\n    };\n    dfs(dfs, 0);\n\n    auto find = [&](auto\
    \ &&self, int u, int p = -1) -> int {\n        bool is_centroid = true;\n    \
    \    for (int v : g[u])\n            if (v != p) {\n                int ret =\
    \ self(self, v, u);\n                if (ret != -1) return ret;\n            \
    \    if (sz[v] > sum / 2) is_centroid = false;\n            }\n        if ((sum\
    \ - sz[u]) > sum / 2) is_centroid = false;\n        return is_centroid ? u : -1;\n\
    \    };\n    return find(find, 0);\n}\n\n} // namespace kk2\n\n#endif // CENTROID_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/centroid.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/centroid.hpp
layout: document
redirect_from:
- /library/graph/tree/centroid.hpp
- /library/graph/tree/centroid.hpp.html
title: graph/tree/centroid.hpp
---
