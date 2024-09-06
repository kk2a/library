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
  bundledCode: "#line 1 \"data_structure/disjoint_sparse_table.hpp\"\n\n\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct DisjointSparseTable\
    \ {\n    DisjointSparseTable() = default;\n    DisjointSparseTable(const vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < _n)\
    \ log++;\n        table.assign(log + 1, vector<S>(_n));\n        for (int i =\
    \ 0; i < _n; ++i) table[0][i] = v[i];\n        for (int i = 1; i <= log; ++i)\
    \ {\n            int shift = 1 << i;\n            for (int left = 0; left < _n;\
    \ left += shift << 1) {\n                int cent = min(left + shift, _n);\n \
    \               table[i][cent - 1] = v[cent - 1];\n                for (int j\
    \ = cent - 2; j >= left; --j) {\n                    table[i][j] = op(v[j], table[i][j\
    \ + 1]);\n                }\n                if (cent == _n) break;\n        \
    \        table[i][cent] = v[cent];\n                int right = min(cent + shift,\
    \ _n);\n                for (int j = cent + 1; j < right; ++j) {\n           \
    \         table[i][j] = op(table[i][j - 1], v[j]);\n                }\n      \
    \      }\n        }\n    }\n\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return e();\n        if (l\
    \ + 1 == r) return table[0][l];\n        --r;\n        int pos = 31 ^ __builtin_clz(l\
    \ ^ r);\n        return op(table[pos][l], table[pos][r]);\n    }\n\n  private:\n\
    \    int _n, log;\n    vector<vector<S>> table;\n    vector<int> lookup;\n};\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n#define DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\
    \ 1\n\nnamespace kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nstruct\
    \ DisjointSparseTable {\n    DisjointSparseTable() = default;\n    DisjointSparseTable(const\
    \ vector<S>& v) : _n(int(v.size())) {\n        log = 0;\n        while ((1 <<\
    \ log) < _n) log++;\n        table.assign(log + 1, vector<S>(_n));\n        for\
    \ (int i = 0; i < _n; ++i) table[0][i] = v[i];\n        for (int i = 1; i <= log;\
    \ ++i) {\n            int shift = 1 << i;\n            for (int left = 0; left\
    \ < _n; left += shift << 1) {\n                int cent = min(left + shift, _n);\n\
    \                table[i][cent - 1] = v[cent - 1];\n                for (int j\
    \ = cent - 2; j >= left; --j) {\n                    table[i][j] = op(v[j], table[i][j\
    \ + 1]);\n                }\n                if (cent == _n) break;\n        \
    \        table[i][cent] = v[cent];\n                int right = min(cent + shift,\
    \ _n);\n                for (int j = cent + 1; j < right; ++j) {\n           \
    \         table[i][j] = op(table[i][j - 1], v[j]);\n                }\n      \
    \      }\n        }\n    }\n\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return e();\n        if (l\
    \ + 1 == r) return table[0][l];\n        --r;\n        int pos = 31 ^ __builtin_clz(l\
    \ ^ r);\n        return op(table[pos][l], table[pos][r]);\n    }\n\n  private:\n\
    \    int _n, log;\n    vector<vector<S>> table;\n    vector<int> lookup;\n};\n\
    \n} // namespace kk2\n\n#endif // DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/disjoint_sparse_table.hpp
- /library/data_structure/disjoint_sparse_table.hpp.html
title: data_structure/disjoint_sparse_table.hpp
---