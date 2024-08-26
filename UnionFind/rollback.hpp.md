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
  bundledCode: "#line 1 \"UnionFind/rollback.hpp\"\n\n\n\nnamespace kk2 {\n\nstruct\
    \ UnionFind_rollback {\n    vector<int> d;\n    vector<pair<int, int>> hist;\n\
    \    vector<int> snaps;\n    UnionFind_rollback(int n = 0) : d(n, -1) {}\n   \
    \ bool same(int x, int y) { return find(x) == find(y); }\n    bool unite(int x,\
    \ int y) {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
    \        if (d[x] > d[y]) swap(x, y);\n        hist.emplace_back(x, d[x]); d[x]\
    \ += d[y];\n        hist.emplace_back(y ,d[y]); d[y] = x;\n        return true;\n\
    \    }\n    int find(int x) {\n        if (d[x] < 0) return x; \n        return\
    \ find(d[x]);\n    }\n    int treesize(int x) { return -d[find(x)]; }\n\n    void\
    \ snapshot() {\n        snaps.push_back(size(hist));\n    }\n    void rollback()\
    \ {\n        while (int(size(hist)) > snaps.back()) {\n            auto [i, x]\
    \ = hist.back(); hist.pop_back();\n            d[i] = x;\n        }\n        snaps.pop_back();\n\
    \    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef UNIONFIND_ROLLBACK_HPP\n#define UNIONFIND_ROLLBACK_HPP 1\n\nnamespace\
    \ kk2 {\n\nstruct UnionFind_rollback {\n    vector<int> d;\n    vector<pair<int,\
    \ int>> hist;\n    vector<int> snaps;\n    UnionFind_rollback(int n = 0) : d(n,\
    \ -1) {}\n    bool same(int x, int y) { return find(x) == find(y); }\n    bool\
    \ unite(int x, int y) {\n        x = find(x), y = find(y);\n        if (x == y)\
    \ return false;\n        if (d[x] > d[y]) swap(x, y);\n        hist.emplace_back(x,\
    \ d[x]); d[x] += d[y];\n        hist.emplace_back(y ,d[y]); d[y] = x;\n      \
    \  return true;\n    }\n    int find(int x) {\n        if (d[x] < 0) return x;\
    \ \n        return find(d[x]);\n    }\n    int treesize(int x) { return -d[find(x)];\
    \ }\n\n    void snapshot() {\n        snaps.push_back(size(hist));\n    }\n  \
    \  void rollback() {\n        while (int(size(hist)) > snaps.back()) {\n     \
    \       auto [i, x] = hist.back(); hist.pop_back();\n            d[i] = x;\n \
    \       }\n        snaps.pop_back();\n    }\n};\n\n} // namespace kk2\n\n#endif\
    \ // UNIONFIND_ROLLBACK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/rollback.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/rollback.hpp
layout: document
redirect_from:
- /library/UnionFind/rollback.hpp
- /library/UnionFind/rollback.hpp.html
title: UnionFind/rollback.hpp
---
