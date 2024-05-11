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
  bundledCode: "#line 1 \"UnionFind/weight.hpp\"\n\n\n\n// A is an abelian group\n\
    template <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)>\nstruct UnionFind_weight\
    \ {\n  private:\n    vector<int> d;\n    vector<A> diff_weight;\n  public:\n \
    \   UnionFind_weight(int n = 0) : d(n, -1), diff_weight(n, e()) {}\n    bool unite(int\
    \ x, int y, A w) {\n        w = op(w, op(weight(x), inv(weight(y))));\n      \
    \  x = find(x); y = find(y);\n        if (x == y) return false;\n        if (d[x]\
    \ > d[y]) { swap(x, y); w = inv(w); }\n        d[x] += d[y];\n        d[y] = x;\n\
    \        diff_weight[y] = w;\n        return true;\n    }\n    int find(int x)\
    \ {\n        if (d[x] < 0) return x;\n        int r = find(d[x]);\n        diff_weight[x]\
    \ = op(diff_weight[x], diff_weight[d[x]]);\n        return d[x] = r;\n    }\n\
    \    bool same(int x, int y) { return find(x) == find(y); }\n    int size(int\
    \ x) { return -d[find(x)]; }\n\n    A weight(int x) {\n        find(x);\n    \
    \    return diff_weight[x];\n    }\n    A diff(int a, int b) {\n        return\
    \ op(inv(weight(a)), weight(b));\n    }\n};\n\n\n\n"
  code: "#ifndef UNIONFIND_WEIGHT_HPP\n#define UNIONFIND_WEIGHT_HPP 1\n\n// A is an\
    \ abelian group\ntemplate <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)>\nstruct\
    \ UnionFind_weight {\n  private:\n    vector<int> d;\n    vector<A> diff_weight;\n\
    \  public:\n    UnionFind_weight(int n = 0) : d(n, -1), diff_weight(n, e()) {}\n\
    \    bool unite(int x, int y, A w) {\n        w = op(w, op(weight(x), inv(weight(y))));\n\
    \        x = find(x); y = find(y);\n        if (x == y) return false;\n      \
    \  if (d[x] > d[y]) { swap(x, y); w = inv(w); }\n        d[x] += d[y];\n     \
    \   d[y] = x;\n        diff_weight[y] = w;\n        return true;\n    }\n    int\
    \ find(int x) {\n        if (d[x] < 0) return x;\n        int r = find(d[x]);\n\
    \        diff_weight[x] = op(diff_weight[x], diff_weight[d[x]]);\n        return\
    \ d[x] = r;\n    }\n    bool same(int x, int y) { return find(x) == find(y); }\n\
    \    int size(int x) { return -d[find(x)]; }\n\n    A weight(int x) {\n      \
    \  find(x);\n        return diff_weight[x];\n    }\n    A diff(int a, int b) {\n\
    \        return op(inv(weight(a)), weight(b));\n    }\n};\n\n\n#endif // UNIONFIND_WEIGHT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/weight.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/weight.hpp
layout: document
redirect_from:
- /library/UnionFind/weight.hpp
- /library/UnionFind/weight.hpp.html
title: UnionFind/weight.hpp
---
