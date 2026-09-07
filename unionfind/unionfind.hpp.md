---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: minimum_spanning_tree.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/minimum_spanning_tree.hpp
    type: Required by
  - files:
    - filename: offline_dynamic_connectivity.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
    - filename: partial_persitent_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
    - filename: ds_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_unionfind.test.cpp
    - filename: graph_minimum_spanning_tree.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_UNIONFIND_UNIONFIND_HPP\n#define KK2_UNIONFIND_UNIONFIND_HPP\
      \ 1\n\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct UnionFind\
      \ {\n    std::vector<int> d;\n\n    UnionFind(int n = 0) : d(n, -1) {}\n\n \
      \   bool same(int x, int y) { return find(x) == find(y); }\n\n    bool unite(int\
      \ x, int y) {\n        x = find(x), y = find(y);\n        if (x == y) return\
      \ false;\n        if (-d[x] < -d[y]) std::swap(x, y);\n        d[x] += d[y];\n\
      \        d[y] = x;\n        return true;\n    }\n\n    template <class F> bool\
      \ unite(int x, int y, const F &f) {\n        x = find(x), y = find(y);\n   \
      \     if (x == y) return false;\n        if (-d[x] < -d[y]) std::swap(x, y);\n\
      \        f(x, y);\n        d[x] += d[y];\n        d[y] = x;\n        return\
      \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n \
      \       return d[x] = find(d[x]);\n    }\n\n    int size(int x) { return -d[find(x)];\
      \ }\n};\n\n} // namespace kk2\n\n#endif // KK2_UNIONFIND_UNIONFIND_HPP\n"
    name: default
  - code: "#line 1 \"unionfind/unionfind.hpp\"\n\n\n\n#include <utility>\n#include\
      \ <vector>\n\nnamespace kk2 {\n\nstruct UnionFind {\n    std::vector<int> d;\n\
      \n    UnionFind(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int y) { return\
      \ find(x) == find(y); }\n\n    bool unite(int x, int y) {\n        x = find(x),\
      \ y = find(y);\n        if (x == y) return false;\n        if (-d[x] < -d[y])\
      \ std::swap(x, y);\n        d[x] += d[y];\n        d[y] = x;\n        return\
      \ true;\n    }\n\n    template <class F> bool unite(int x, int y, const F &f)\
      \ {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
      \        if (-d[x] < -d[y]) std::swap(x, y);\n        f(x, y);\n        d[x]\
      \ += d[y];\n        d[y] = x;\n        return true;\n    }\n\n    int find(int\
      \ x) {\n        if (d[x] < 0) return x;\n        return d[x] = find(d[x]);\n\
      \    }\n\n    int size(int x) { return -d[find(x)]; }\n};\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: unionfind/unionfind.hpp
  pathExtension: hpp
  requiredBy:
  - graph/tree/minimum_spanning_tree.hpp
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  - verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
  - verify/yosupo_ds/ds_unionfind.test.cpp
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
documentation_of: unionfind/unionfind.hpp
layout: document
---
