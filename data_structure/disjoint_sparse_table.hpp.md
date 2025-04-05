---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
    title: verify/yosupo_ds/ds_static_rmq_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/disjoint_sparse_table.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> struct DisjointSparseTable {\n    DisjointSparseTable()\
    \ = default;\n\n    DisjointSparseTable(int n) : _n(n) {\n        log = 0;\n \
    \       while ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n\
    \    }\n\n    DisjointSparseTable(const std::vector<S> &v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log\
    \ + 1, std::vector<S>(_n));\n        for (int i = 0; i < _n; ++i) table[0][i]\
    \ = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
    \        is_built = true;\n        for (int i = 1; i <= log; ++i) {\n        \
    \    int shift = 1 << i;\n            for (int left = 0; left < _n; left += shift\
    \ << 1) {\n                int cent = std::min(left + shift, _n);\n          \
    \      table[i][cent - 1] = table[0][cent - 1];\n                for (int j =\
    \ cent - 2; j >= left; --j) {\n                    table[i][j] = op(table[0][j],\
    \ table[i][j + 1]);\n                }\n                if (cent == _n) break;\n\
    \                table[i][cent] = table[0][cent];\n                int right =\
    \ std::min(cent + shift, _n);\n                for (int j = cent + 1; j < right;\
    \ ++j) {\n                    table[i][j] = op(table[i][j - 1], table[0][j]);\n\
    \                }\n            }\n        }\n    }\n\n    template <class...\
    \ Args> void init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n\
    \        assert(!is_built);\n        table[0][p] = S(args...);\n    }\n\n    S\
    \ prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n \
    \       assert(is_built);\n        if (l == r) return e();\n        if (l + 1\
    \ == r) return table[0][l];\n        --r;\n        int pos = 31 ^ __builtin_clz(l\
    \ ^ r);\n        return op(table[pos][l], table[pos][r]);\n    }\n\n  private:\n\
    \    int _n, log;\n    std::vector<std::vector<S>> table;\n    std::vector<int>\
    \ lookup;\n    bool is_built = false;\n};\n\ntemplate <class M> using DisjointSparseTableS\
    \ = DisjointSparseTable<M, M::op, M::unit>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n#define KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct DisjointSparseTable\
    \ {\n    DisjointSparseTable() = default;\n\n    DisjointSparseTable(int n) :\
    \ _n(n) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log\
    \ + 1, std::vector<S>(_n));\n    }\n\n    DisjointSparseTable(const std::vector<S>\
    \ &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1 << log) < _n)\
    \ log++;\n        table.assign(log + 1, std::vector<S>(_n));\n        for (int\
    \ i = 0; i < _n; ++i) table[0][i] = v[i];\n        build();\n    }\n\n    void\
    \ build() {\n        assert(!is_built);\n        is_built = true;\n        for\
    \ (int i = 1; i <= log; ++i) {\n            int shift = 1 << i;\n            for\
    \ (int left = 0; left < _n; left += shift << 1) {\n                int cent =\
    \ std::min(left + shift, _n);\n                table[i][cent - 1] = table[0][cent\
    \ - 1];\n                for (int j = cent - 2; j >= left; --j) {\n          \
    \          table[i][j] = op(table[0][j], table[i][j + 1]);\n                }\n\
    \                if (cent == _n) break;\n                table[i][cent] = table[0][cent];\n\
    \                int right = std::min(cent + shift, _n);\n                for\
    \ (int j = cent + 1; j < right; ++j) {\n                    table[i][j] = op(table[i][j\
    \ - 1], table[0][j]);\n                }\n            }\n        }\n    }\n\n\
    \    template <class... Args> void init_set(int p, Args... args) {\n        assert(0\
    \ <= p && p < _n);\n        assert(!is_built);\n        table[0][p] = S(args...);\n\
    \    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        assert(is_built);\n        if (l == r) return e();\n    \
    \    if (l + 1 == r) return table[0][l];\n        --r;\n        int pos = 31 ^\
    \ __builtin_clz(l ^ r);\n        return op(table[pos][l], table[pos][r]);\n  \
    \  }\n\n  private:\n    int _n, log;\n    std::vector<std::vector<S>> table;\n\
    \    std::vector<int> lookup;\n    bool is_built = false;\n};\n\ntemplate <class\
    \ M> using DisjointSparseTableS = DisjointSparseTable<M, M::op, M::unit>;\n\n\
    } // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq_2.test.cpp
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/disjoint_sparse_table.hpp
- /library/data_structure/disjoint_sparse_table.hpp.html
title: data_structure/disjoint_sparse_table.hpp
---
