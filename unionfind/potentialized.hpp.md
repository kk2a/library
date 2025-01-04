---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
    title: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
    title: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"unionfind/potentialized.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace kk2 {\n\ntemplate <class A, bool right=true> struct PotentializedUnionFind\
    \ {\n  private:\n    std::vector<int> d;\n    std::vector<A> par_diff;\n\n  public:\n\
    \    PotentializedUnionFind(int n, A e_ = A()) : d(n, -1), par_diff(n, e_) {}\n\
    \n    // x -> y : w\n    // right: a[y]a[x]^-1 = w\n    // !right: a[x]^-1a[y]\
    \ = w\n    bool unite(int x, int y, A w) {\n        if constexpr (right) w = -potential(y)\
    \ + w + potential(x);\n        else w = potential(x) + w - potential(y);\n   \
    \     x = find(x);\n        y = find(y);\n        if (x == y) return false;\n\
    \        if (d[x] > d[y]) {\n            std::swap(x, y);\n            w = -w;\n\
    \        }\n        d[x] += d[y];\n        d[y] = x;\n        par_diff[y] = w;\n\
    \        return true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return\
    \ x;\n        int r = find(d[x]);\n        if constexpr (right) par_diff[x] =\
    \ par_diff[x] + par_diff[d[x]];\n        else par_diff[x] = par_diff[d[x]] + par_diff[x];\n\
    \        return d[x] = r;\n    }\n\n    bool same(int x, int y) { return find(x)\
    \ == find(y); }\n\n    int size(int x) { return -d[find(x)]; }\n\n    // root_x\
    \ -> x\n    A potential(int x) {\n        find(x);\n        return par_diff[x];\n\
    \    }\n\n    // x -> y\n    A diff(int x, int y) {\n        if constexpr (right)\
    \ return potential(y) - potential(x);\n        else return -potential(x) + potential(y);\n\
    \    }\n};\n\ntemplate <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct\
    \ EasyAbelianGroup {\n    A val;\n\n    EasyAbelianGroup() : val(e()) {}\n\n \
    \   template <class... Args> EasyAbelianGroup(Args... args) : val(args...) {}\n\
    \n    EasyAbelianGroup operator+(const EasyAbelianGroup &rhs) const {\n      \
    \  return EasyAbelianGroup(op(val, rhs.val));\n    }\n\n    EasyAbelianGroup operator-(const\
    \ EasyAbelianGroup &rhs) const {\n        return EasyAbelianGroup(op(val, inv(rhs.val)));\n\
    \    }\n\n    EasyAbelianGroup operator-() const { return EasyAbelianGroup(inv(val));\
    \ }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_UNIONFIND_POTENTIALIZED_HPP\n#define KK2_UNIONFIND_POTENTIALIZED_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class A, bool right=true>\
    \ struct PotentializedUnionFind {\n  private:\n    std::vector<int> d;\n    std::vector<A>\
    \ par_diff;\n\n  public:\n    PotentializedUnionFind(int n, A e_ = A()) : d(n,\
    \ -1), par_diff(n, e_) {}\n\n    // x -> y : w\n    // right: a[y]a[x]^-1 = w\n\
    \    // !right: a[x]^-1a[y] = w\n    bool unite(int x, int y, A w) {\n       \
    \ if constexpr (right) w = -potential(y) + w + potential(x);\n        else w =\
    \ potential(x) + w - potential(y);\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return false;\n        if (d[x] > d[y]) {\n            std::swap(x,\
    \ y);\n            w = -w;\n        }\n        d[x] += d[y];\n        d[y] = x;\n\
    \        par_diff[y] = w;\n        return true;\n    }\n\n    int find(int x)\
    \ {\n        if (d[x] < 0) return x;\n        int r = find(d[x]);\n        if\
    \ constexpr (right) par_diff[x] = par_diff[x] + par_diff[d[x]];\n        else\
    \ par_diff[x] = par_diff[d[x]] + par_diff[x];\n        return d[x] = r;\n    }\n\
    \n    bool same(int x, int y) { return find(x) == find(y); }\n\n    int size(int\
    \ x) { return -d[find(x)]; }\n\n    // root_x -> x\n    A potential(int x) {\n\
    \        find(x);\n        return par_diff[x];\n    }\n\n    // x -> y\n    A\
    \ diff(int x, int y) {\n        if constexpr (right) return potential(y) - potential(x);\n\
    \        else return -potential(x) + potential(y);\n    }\n};\n\ntemplate <class\
    \ A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct EasyAbelianGroup {\n    A val;\n\
    \n    EasyAbelianGroup() : val(e()) {}\n\n    template <class... Args> EasyAbelianGroup(Args...\
    \ args) : val(args...) {}\n\n    EasyAbelianGroup operator+(const EasyAbelianGroup\
    \ &rhs) const {\n        return EasyAbelianGroup(op(val, rhs.val));\n    }\n\n\
    \    EasyAbelianGroup operator-(const EasyAbelianGroup &rhs) const {\n       \
    \ return EasyAbelianGroup(op(val, inv(rhs.val)));\n    }\n\n    EasyAbelianGroup\
    \ operator-() const { return EasyAbelianGroup(inv(val)); }\n};\n\n} // namespace\
    \ kk2\n\n#endif // KK2_UNIONFIND_POTENTIALIZED_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/potentialized.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  - verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
documentation_of: unionfind/potentialized.hpp
layout: document
redirect_from:
- /library/unionfind/potentialized.hpp
- /library/unionfind/potentialized.hpp.html
title: unionfind/potentialized.hpp
---
