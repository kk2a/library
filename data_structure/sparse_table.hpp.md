---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_static_rmq.test.cpp
    title: verify/yosupo_ds/ds_static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sparse_table.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace kk2 {\n\n// require: op(x, x) = x for all x\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct SparseTable {\n    SparseTable() =\
    \ default;\n\n    SparseTable(const std::vector<S> &v) : _n(int(v.size())) {\n\
    \        log = 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log\
    \ + 1, std::vector<S>(_n));\n        for (int i = 0; i < _n; i++) table[0][i]\
    \ = v[i];\n        for (int i = 1; i <= log; i++) {\n            for (int j =\
    \ 0; j + (1 << i) <= _n; j++) {\n                table[i][j] = op(table[i - 1][j],\
    \ table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    using\
    \ Monoid = S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static\
    \ S MonoidUnit() { return e(); }\n\n    S prod(int l, int r) const {\n       \
    \ assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n    \
    \    int i = 31 ^ __builtin_clz(r - l);\n        return op(table[i][l], table[i][r\
    \ - (1 << i)]);\n    }\n\n    S get(int i) const {\n        assert(0 <= i && i\
    \ < _n);\n        return table[0][i];\n    }\n\n    // return r s.t.\n    // r\
    \ = l or f(op(a[l], a[l+1], ..., a[r-1])) == true\n    // r = n or f(op(a[l],\
    \ a[l+1], ..., a[r]))   == false\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       int left = l - 1, right = _n;\n        while (right - left > 1) {\n  \
    \          int mid = (left + right) >> 1;\n            if (f(prod(l, mid))) left\
    \ = mid;\n            else right = mid;\n        }\n        return right;\n  \
    \  }\n\n    // return l s.t.\n    // l = r or f(op(a[l], a[l+1], ..., a[r-1]))\
    \ == false\n    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true\n    template\
    \ <bool (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> int min_left(int r, F\
    \ f) const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n  \
    \      if (r == 0) return 0;\n        int left = -1, right = r;\n        while\
    \ (right - left > 1) {\n            int mid = (left + right) >> 1;\n         \
    \   if (f(prod(mid, r))) right = mid;\n            else left = mid;\n        }\n\
    \        return right;\n    }\n\n  private:\n    int _n, log;\n    std::vector<std::vector<S>>\
    \ table;\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\n#define KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\n// require:\
    \ op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SparseTable\
    \ {\n    SparseTable() = default;\n\n    SparseTable(const std::vector<S> &v)\
    \ : _n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n\
    \        table.assign(log + 1, std::vector<S>(_n));\n        for (int i = 0; i\
    \ < _n; i++) table[0][i] = v[i];\n        for (int i = 1; i <= log; i++) {\n \
    \           for (int j = 0; j + (1 << i) <= _n; j++) {\n                table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n  \
    \      }\n    }\n\n    using Monoid = S;\n\n    static S Op(S l, S r) { return\
    \ op(l, r); }\n\n    static S MonoidUnit() { return e(); }\n\n    S prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l\
    \ == r) return e();\n        int i = 31 ^ __builtin_clz(r - l);\n        return\
    \ op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n    S get(int i) const {\n\
    \        assert(0 <= i && i < _n);\n        return table[0][i];\n    }\n\n   \
    \ // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true\n\
    \    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template <bool\
    \ (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S x) {\
    \ return f(x); });\n    }\n\n    template <class F> int max_right(int l, F f)\
    \ const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n     \
    \   if (l == _n) return _n;\n        int left = l - 1, right = _n;\n        while\
    \ (right - left > 1) {\n            int mid = (left + right) >> 1;\n         \
    \   if (f(prod(l, mid))) left = mid;\n            else right = mid;\n        }\n\
    \        return right;\n    }\n\n    // return l s.t.\n    // l = r or f(op(a[l],\
    \ a[l+1], ..., a[r-1])) == false\n    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))\
    \   == true\n    template <bool (*f)(S)> int min_left(int r) const {\n       \
    \ return min_left(r, [](S x) { return f(x); });\n    }\n\n    template <class\
    \ F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n  \
    \      assert(f(e()));\n        if (r == 0) return 0;\n        int left = -1,\
    \ right = r;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n            else\
    \ left = mid;\n        }\n        return right;\n    }\n\n  private:\n    int\
    \ _n, log;\n    std::vector<std::vector<S>> table;\n};\n\n} // namespace kk2\n\
    \n#endif // KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - data_structure/static_rmq.hpp
  - graph/tree/euler_tour.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
