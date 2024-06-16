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
  bundledCode: "#line 1 \"tree/centroid.hpp\"\n\n\n\ntemplate <class G>\nint centroid(const\
    \ G& g, vector<long long> weight = {}) {\n    if (weight.empty()) weight.assign(g.size(),\
    \ 1);\n    assert((int)g.size() == (int)weight.size());\n    int n = g.size();\n\
    \    vector<long long> sz(n, 0);\n    long long sum = accumulate(begin(weight),\
    \ end(weight), 0LL);\n    auto dfs = [&](auto &&self, int u, int p = -1) -> long\
    \ long {\n        sz[u] = weight[u];\n        for (int v : g[u]) if (v != p) {\n\
    \            sz[u] += self(self, v, u);\n        }\n        return sz[u];\n  \
    \  };\n    dfs(dfs, 0);\n\n    auto find = [&](auto &&self, int u, int p = -1)\
    \ -> int {\n        bool is_centroid = true;\n        for (int v : g[u]) if (v\
    \ != p) {\n            int ret = self(self, v, u);\n            if (ret != -1)\
    \ return ret;\n            if (sz[v] > sum / 2) is_centroid = false;\n       \
    \ }\n        if ((sum - sz[u]) > sum / 2) is_centroid = false;\n        return\
    \ is_centroid ? u : -1;\n    };\n    int res = find(find, 0);\n    return res;\n\
    }\n\n\n"
  code: "#ifndef CENTROID_HPP\n#define CENTROID_HPP 1\n\ntemplate <class G>\nint centroid(const\
    \ G& g, vector<long long> weight = {}) {\n    if (weight.empty()) weight.assign(g.size(),\
    \ 1);\n    assert((int)g.size() == (int)weight.size());\n    int n = g.size();\n\
    \    vector<long long> sz(n, 0);\n    long long sum = accumulate(begin(weight),\
    \ end(weight), 0LL);\n    auto dfs = [&](auto &&self, int u, int p = -1) -> long\
    \ long {\n        sz[u] = weight[u];\n        for (int v : g[u]) if (v != p) {\n\
    \            sz[u] += self(self, v, u);\n        }\n        return sz[u];\n  \
    \  };\n    dfs(dfs, 0);\n\n    auto find = [&](auto &&self, int u, int p = -1)\
    \ -> int {\n        bool is_centroid = true;\n        for (int v : g[u]) if (v\
    \ != p) {\n            int ret = self(self, v, u);\n            if (ret != -1)\
    \ return ret;\n            if (sz[v] > sum / 2) is_centroid = false;\n       \
    \ }\n        if ((sum - sz[u]) > sum / 2) is_centroid = false;\n        return\
    \ is_centroid ? u : -1;\n    };\n    int res = find(find, 0);\n    return res;\n\
    }\n\n#endif // CENTROID_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid.hpp
  requiredBy: []
  timestamp: '2024-06-16 14:35:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/centroid.hpp
layout: document
redirect_from:
- /library/tree/centroid.hpp
- /library/tree/centroid.hpp.html
title: tree/centroid.hpp
---
