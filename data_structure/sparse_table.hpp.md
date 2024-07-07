---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/sparse_table.hpp\"\n\n\n\n\n// require: op(x,\
    \ x) = x for all x\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct SparseTable\
    \ {\n    SparseTable() : SparseTable(0) {}\n    SparseTable(int n) : SparseTable(vector<S>(n,\
    \ e())) {}\n    SparseTable(const vector<S>& v) : _n(int(v.size())) {\n      \
    \  log = 1;\n        while ((1u << log) <= (unsigned int)_n) log++;\n        table.assign(log,\
    \ vector<S>(_n));\n        for (int i = 0; i < _n; i++) table[0][i] = v[i];\n\
    \        for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 <<\
    \ i) <= _n; j++) {\n                table[i][j] = op(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    using Monoid\
    \ = S;\n    static S Op(S l, S r) { return op(l, r); }\n    static S MonoidUnit()\
    \ { return e(); }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        if (l == r) return e();\n        int i = 31 - __builtin_clz(r\
    \ - l);\n        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n  private:\n\
    \    int _n, log;\n    vector<vector<S>> table;\n};\n\n\n"
  code: "#ifndef DATA_STRUCTURE_SPARSE_TABLE_HPP\n#define DATA_STRUCTURE_SPARSE_TABLE_HPP\
    \ 1\n\n\n// require: op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()>\nstruct SparseTable {\n    SparseTable() : SparseTable(0) {}\n   \
    \ SparseTable(int n) : SparseTable(vector<S>(n, e())) {}\n    SparseTable(const\
    \ vector<S>& v) : _n(int(v.size())) {\n        log = 1;\n        while ((1u <<\
    \ log) <= (unsigned int)_n) log++;\n        table.assign(log, vector<S>(_n));\n\
    \        for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= _n; j++) {\n\
    \                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n\n    using Monoid = S;\n    static\
    \ S Op(S l, S r) { return op(l, r); }\n    static S MonoidUnit() { return e();\
    \ }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        if (l == r) return e();\n        int i = 31 - __builtin_clz(r - l);\n\
    \        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n  private:\n\
    \    int _n, log;\n    vector<vector<S>> table;\n};\n\n#endif // DATA_STRUCTURE_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - data_structure/static_rmq.hpp
  timestamp: '2024-07-08 00:04:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
