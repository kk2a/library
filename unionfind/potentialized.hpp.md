---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: ds_potentiailized_uf_non_commutattive.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
    - filename: ds_potentialized_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_UNIONFIND_POTENTIALIZED_HPP\n#define KK2_UNIONFIND_POTENTIALIZED_HPP\
      \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\n// \u5B9F\u88C5\u306E\u65B9\u91DD\
      \u3092\u307B\u304B\u306E\u3082\u306E\u306B\u5408\u308F\u305B\u308B\n\ntemplate\
      \ <class A, bool right = true> struct PotentializedUnionFind {\n  private:\n\
      \    std::vector<int> d;\n    std::vector<A> par_diff;\n\n  public:\n    PotentializedUnionFind(int\
      \ n, A e_ = A()) : d(n, -1), par_diff(n, e_) {}\n\n    // x -> y : w\n    //\
      \ right: a[y]a[x]^-1 = w\n    // !right: a[x]^-1a[y] = w\n    bool unite(int\
      \ x, int y, A w) {\n        if constexpr (right) w = -potential(y) + w + potential(x);\n\
      \        else w = potential(x) + w - potential(y);\n        x = find(x);\n \
      \       y = find(y);\n        if (x == y) return false;\n        if (d[x] >\
      \ d[y]) {\n            std::swap(x, y);\n            w = -w;\n        }\n  \
      \      d[x] += d[y];\n        d[y] = x;\n        par_diff[y] = w;\n        return\
      \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n \
      \       int r = find(d[x]);\n        if constexpr (right) par_diff[x] = par_diff[x]\
      \ + par_diff[d[x]];\n        else par_diff[x] = par_diff[d[x]] + par_diff[x];\n\
      \        return d[x] = r;\n    }\n\n    bool same(int x, int y) { return find(x)\
      \ == find(y); }\n\n    int size(int x) { return -d[find(x)]; }\n\n    // root_x\
      \ -> x\n    A potential(int x) {\n        find(x);\n        return par_diff[x];\n\
      \    }\n\n    // x -> y\n    A diff(int x, int y) {\n        if constexpr (right)\
      \ return potential(y) - potential(x);\n        else return -potential(x) + potential(y);\n\
      \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_UNIONFIND_POTENTIALIZED_HPP\n"
    name: default
  - code: "#line 1 \"unionfind/potentialized.hpp\"\n\n\n\n#include <vector>\n\nnamespace\
      \ kk2 {\n\n// \u5B9F\u88C5\u306E\u65B9\u91DD\u3092\u307B\u304B\u306E\u3082\u306E\
      \u306B\u5408\u308F\u305B\u308B\n\ntemplate <class A, bool right = true> struct\
      \ PotentializedUnionFind {\n  private:\n    std::vector<int> d;\n    std::vector<A>\
      \ par_diff;\n\n  public:\n    PotentializedUnionFind(int n, A e_ = A()) : d(n,\
      \ -1), par_diff(n, e_) {}\n\n    // x -> y : w\n    // right: a[y]a[x]^-1 =\
      \ w\n    // !right: a[x]^-1a[y] = w\n    bool unite(int x, int y, A w) {\n \
      \       if constexpr (right) w = -potential(y) + w + potential(x);\n       \
      \ else w = potential(x) + w - potential(y);\n        x = find(x);\n        y\
      \ = find(y);\n        if (x == y) return false;\n        if (d[x] > d[y]) {\n\
      \            std::swap(x, y);\n            w = -w;\n        }\n        d[x]\
      \ += d[y];\n        d[y] = x;\n        par_diff[y] = w;\n        return true;\n\
      \    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n        int\
      \ r = find(d[x]);\n        if constexpr (right) par_diff[x] = par_diff[x] +\
      \ par_diff[d[x]];\n        else par_diff[x] = par_diff[d[x]] + par_diff[x];\n\
      \        return d[x] = r;\n    }\n\n    bool same(int x, int y) { return find(x)\
      \ == find(y); }\n\n    int size(int x) { return -d[find(x)]; }\n\n    // root_x\
      \ -> x\n    A potential(int x) {\n        find(x);\n        return par_diff[x];\n\
      \    }\n\n    // x -> y\n    A diff(int x, int y) {\n        if constexpr (right)\
      \ return potential(y) - potential(x);\n        else return -potential(x) + potential(y);\n\
      \    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: unionfind/potentialized.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
  - verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
documentation_of: unionfind/potentialized.hpp
layout: document
---
