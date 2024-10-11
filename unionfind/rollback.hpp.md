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
  bundledCode: "#line 1 \"unionfind/rollback.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nstruct UnionFind_rollback {\n    std::vector<int>\
    \ d;\n    std::vector<std::pair<int, int>> hist;\n    std::vector<int> snaps;\n\
    \n    UnionFind_rollback(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int\
    \ y) { return find(x) == find(y); }\n\n    bool unite(int x, int y) {\n      \
    \  x = find(x), y = find(y);\n        if (x == y) return false;\n        if (d[x]\
    \ > d[y]) std::swap(x, y);\n        hist.emplace_back(x, d[x]);\n        d[x]\
    \ += d[y];\n        hist.emplace_back(y, d[y]);\n        d[y] = x;\n        return\
    \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n   \
    \     return find(d[x]);\n    }\n\n    int treesize(int x) { return -d[find(x)];\
    \ }\n\n    void snapshot() { snaps.push_back(size(hist)); }\n\n    void rollback()\
    \ {\n        while (int(size(hist)) > snaps.back()) {\n            auto [i, x]\
    \ = hist.back();\n            hist.pop_back();\n            d[i] = x;\n      \
    \  }\n        snaps.pop_back();\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef UNIONFIND_ROLLBACK_HPP\n#define UNIONFIND_ROLLBACK_HPP 1\n\n#include\
    \ <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct UnionFind_rollback\
    \ {\n    std::vector<int> d;\n    std::vector<std::pair<int, int>> hist;\n   \
    \ std::vector<int> snaps;\n\n    UnionFind_rollback(int n = 0) : d(n, -1) {}\n\
    \n    bool same(int x, int y) { return find(x) == find(y); }\n\n    bool unite(int\
    \ x, int y) {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
    \        if (d[x] > d[y]) std::swap(x, y);\n        hist.emplace_back(x, d[x]);\n\
    \        d[x] += d[y];\n        hist.emplace_back(y, d[y]);\n        d[y] = x;\n\
    \        return true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return\
    \ x;\n        return find(d[x]);\n    }\n\n    int treesize(int x) { return -d[find(x)];\
    \ }\n\n    void snapshot() { snaps.push_back(size(hist)); }\n\n    void rollback()\
    \ {\n        while (int(size(hist)) > snaps.back()) {\n            auto [i, x]\
    \ = hist.back();\n            hist.pop_back();\n            d[i] = x;\n      \
    \  }\n        snaps.pop_back();\n    }\n};\n\n} // namespace kk2\n\n#endif //\
    \ UNIONFIND_ROLLBACK_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/rollback.hpp
  requiredBy: []
  timestamp: '2024-10-11 22:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unionfind/rollback.hpp
layout: document
redirect_from:
- /library/unionfind/rollback.hpp
- /library/unionfind/rollback.hpp.html
title: unionfind/rollback.hpp
---
