---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/offline_dynamic_connectivity.test.cpp
    title: verify/unit_test/offline_dynamic_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/partial_persitent_unionfind.test.cpp
    title: verify/unit_test/partial_persitent_unionfind.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_unionfind.test.cpp
    title: verify/yosupo_ds/ds_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"unionfind/unionfind.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nstruct UnionFind {\n    std::vector<int> d;\n\
    \n    UnionFind(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int y) { return\
    \ find(x) == find(y); }\n\n    bool unite(int x, int y) {\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return false;\n        if (d[x] > d[y]) std::swap(x,\
    \ y);\n        d[x] += d[y];\n        d[y] = x;\n        return true;\n    }\n\
    \n    int find(int x) {\n        if (d[x] < 0) return x;\n        return d[x]\
    \ = find(d[x]);\n    }\n\n    int size(int x) { return -d[find(x)]; }\n};\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef KK2_UNIONFIND_UNIONFIND_HPP\n#define KK2_UNIONFIND_UNIONFIND_HPP\
    \ 1\n\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct UnionFind\
    \ {\n    std::vector<int> d;\n\n    UnionFind(int n = 0) : d(n, -1) {}\n\n   \
    \ bool same(int x, int y) { return find(x) == find(y); }\n\n    bool unite(int\
    \ x, int y) {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
    \        if (d[x] > d[y]) std::swap(x, y);\n        d[x] += d[y];\n        d[y]\
    \ = x;\n        return true;\n    }\n\n    int find(int x) {\n        if (d[x]\
    \ < 0) return x;\n        return d[x] = find(d[x]);\n    }\n\n    int size(int\
    \ x) { return -d[find(x)]; }\n};\n\n} // namespace kk2\n\n#endif // KK2_UNIONFIND_UNIONFIND_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_unionfind.test.cpp
  - verify/unit_test/partial_persitent_unionfind.test.cpp
  - verify/unit_test/offline_dynamic_connectivity.test.cpp
documentation_of: unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/unionfind/unionfind.hpp
- /library/unionfind/unionfind.hpp.html
title: unionfind/unionfind.hpp
---
