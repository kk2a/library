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
  bundledCode: "#line 1 \"unionfind/with_monoid.hpp\"\n\n\n\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class M, M (*op)(M, M), M (*e)()>\
    \ struct UnionFindWithMonoid {\n  public:\n    UnionFindWithMonoid() : UnionFindWithMonoid(0)\
    \ {}\n\n    UnionFindWithMonoid(int n) : _n(n), d(n, -1), _monoid(n, e()) {}\n\
    \n    bool same(int x, int y) { return find(x) == find(y); }\n\n    bool unite(int\
    \ x, int y) {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
    \        M m = op(_monoid[x], _monoid[y]);\n        if (d[x] > d[y]) std::swap(x,\
    \ y);\n        d[x] += d[y];\n        d[y] = x;\n        _monoid[x] = m;\n   \
    \     return true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return\
    \ x;\n        return d[x] = find(d[x]);\n    }\n\n    M get(int x) { return _monoid[find(x)];\
    \ }\n\n    void set_to_root(int x, M m) { _monoid[find(x)] = m; }\n\n    int size(int\
    \ x) { return -d[find(x)]; }\n\n  private:\n    int _n;\n    std::vector<int>\
    \ d;\n    std::vector<M> _monoid;\n};\n\n}; // namespace kk2\n\n\n"
  code: "#ifndef KK2_UNIONFIND_WITH_MONOID_HPP\n#define KK2_UNIONFIND_WITH_MONOID_HPP\
    \ 1\n\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ M, M (*op)(M, M), M (*e)()> struct UnionFindWithMonoid {\n  public:\n    UnionFindWithMonoid()\
    \ : UnionFindWithMonoid(0) {}\n\n    UnionFindWithMonoid(int n) : _n(n), d(n,\
    \ -1), _monoid(n, e()) {}\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n\n    bool unite(int x, int y) {\n        x = find(x), y = find(y);\n   \
    \     if (x == y) return false;\n        M m = op(_monoid[x], _monoid[y]);\n \
    \       if (d[x] > d[y]) std::swap(x, y);\n        d[x] += d[y];\n        d[y]\
    \ = x;\n        _monoid[x] = m;\n        return true;\n    }\n\n    int find(int\
    \ x) {\n        if (d[x] < 0) return x;\n        return d[x] = find(d[x]);\n \
    \   }\n\n    M get(int x) { return _monoid[find(x)]; }\n\n    void set_to_root(int\
    \ x, M m) { _monoid[find(x)] = m; }\n\n    int size(int x) { return -d[find(x)];\
    \ }\n\n  private:\n    int _n;\n    std::vector<int> d;\n    std::vector<M> _monoid;\n\
    };\n\n}; // namespace kk2\n\n#endif // KK2_UNIONFIND_WITH_MONOID_HPP"
  dependsOn: []
  isVerificationFile: false
  path: unionfind/with_monoid.hpp
  requiredBy: []
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: unionfind/with_monoid.hpp
layout: document
redirect_from:
- /library/unionfind/with_monoid.hpp
- /library/unionfind/with_monoid.hpp.html
title: unionfind/with_monoid.hpp
---
