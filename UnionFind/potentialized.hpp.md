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
  bundledCode: "#line 1 \"UnionFind/potentialized.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace kk2 {\n\n// require:\n// A is an abelian group\n// A must have operator+\
    \ and operator-\n// A() must return unit element\ntemplate <class A> struct PotentializedUnionfind\
    \ {\n  private:\n    std::vector<int> d;\n    std::vector<A> diff_weight;\n\n\
    \  public:\n    PotentializedUnionfind(int n = 0) : d(n, -1), diff_weight(n, A())\
    \ {}\n\n    // x -> y : w\n    bool unite(int x, int y, A w) {\n        w = w\
    \ + weight(x) - weight(y);\n        x = find(x);\n        y = find(y);\n     \
    \   if (x == y) return false;\n        if (d[x] > d[y]) {\n            std::swap(x,\
    \ y);\n            w = -w;\n        }\n        d[x] += d[y];\n        d[y] = x;\n\
    \        diff_weight[y] = w;\n        return true;\n    }\n\n    int find(int\
    \ x) {\n        if (d[x] < 0) return x;\n        int r = find(d[x]);\n       \
    \ diff_weight[x] = diff_weight[x] + diff_weight[d[x]];\n        return d[x] =\
    \ r;\n    }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n\n\
    \    int size(int x) { return -d[find(x)]; }\n\n    // root -> x\n    A weight(int\
    \ x) {\n        find(x);\n        return diff_weight[x];\n    }\n\n    // a ->\
    \ b\n    A diff(int a, int b) { return -weight(a) + weight(b); }\n};\n\ntemplate\
    \ <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct EasyAbelianGroup {\n\
    \    A val;\n\n    EasyAbelianGroup() : val(e()) {}\n\n    template <class...\
    \ Args> EasyAbelianGroup(Args... args) : val(args...) {}\n\n    EasyAbelianGroup\
    \ operator+(const EasyAbelianGroup &rhs) const {\n        return EasyAbelianGroup(op(val,\
    \ rhs.val));\n    }\n\n    EasyAbelianGroup operator-(const EasyAbelianGroup &rhs)\
    \ const {\n        return EasyAbelianGroup(op(val, inv(rhs.val)));\n    }\n\n\
    \    EasyAbelianGroup operator-() const { return EasyAbelianGroup(inv(val)); }\n\
    };\n\n} // namespace kk2\n\n\n"
  code: "#ifndef UNIONFIND_POTENTIALIZED_HPP\n#define UNIONFIND_POTENTIALIZED_HPP\
    \ 1\n\n#include <vector>\n\nnamespace kk2 {\n\n// require:\n// A is an abelian\
    \ group\n// A must have operator+ and operator-\n// A() must return unit element\n\
    template <class A> struct PotentializedUnionfind {\n  private:\n    std::vector<int>\
    \ d;\n    std::vector<A> diff_weight;\n\n  public:\n    PotentializedUnionfind(int\
    \ n = 0) : d(n, -1), diff_weight(n, A()) {}\n\n    // x -> y : w\n    bool unite(int\
    \ x, int y, A w) {\n        w = w + weight(x) - weight(y);\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (d[x] > d[y])\
    \ {\n            std::swap(x, y);\n            w = -w;\n        }\n        d[x]\
    \ += d[y];\n        d[y] = x;\n        diff_weight[y] = w;\n        return true;\n\
    \    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n        int\
    \ r = find(d[x]);\n        diff_weight[x] = diff_weight[x] + diff_weight[d[x]];\n\
    \        return d[x] = r;\n    }\n\n    bool same(int x, int y) { return find(x)\
    \ == find(y); }\n\n    int size(int x) { return -d[find(x)]; }\n\n    // root\
    \ -> x\n    A weight(int x) {\n        find(x);\n        return diff_weight[x];\n\
    \    }\n\n    // a -> b\n    A diff(int a, int b) { return -weight(a) + weight(b);\
    \ }\n};\n\ntemplate <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct EasyAbelianGroup\
    \ {\n    A val;\n\n    EasyAbelianGroup() : val(e()) {}\n\n    template <class...\
    \ Args> EasyAbelianGroup(Args... args) : val(args...) {}\n\n    EasyAbelianGroup\
    \ operator+(const EasyAbelianGroup &rhs) const {\n        return EasyAbelianGroup(op(val,\
    \ rhs.val));\n    }\n\n    EasyAbelianGroup operator-(const EasyAbelianGroup &rhs)\
    \ const {\n        return EasyAbelianGroup(op(val, inv(rhs.val)));\n    }\n\n\
    \    EasyAbelianGroup operator-() const { return EasyAbelianGroup(inv(val)); }\n\
    };\n\n} // namespace kk2\n\n#endif // UNIONFIND_POTENTIALIZED_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: UnionFind/potentialized.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: UnionFind/potentialized.hpp
layout: document
redirect_from:
- /library/UnionFind/potentialized.hpp
- /library/UnionFind/potentialized.hpp.html
title: UnionFind/potentialized.hpp
---
