---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: algebra.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/algebra.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: ds_static_rmq_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n#define KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#include\
      \ \"../type_traits/algebra.hpp\"\n\nnamespace kk2 {\n\ntemplate <algebra::Monoid\
      \ M> struct DisjointSparseTable {\n    DisjointSparseTable() = default;\n\n\
      \    DisjointSparseTable(int n) : _n(n) {\n        log = 0;\n        while ((1\
      \ << log) < _n) log++;\n        table.assign(log + 1, std::vector<M>(_n));\n\
      \    }\n\n    DisjointSparseTable(const std::vector<M> &v) : _n(int(v.size()))\
      \ {\n        log = 0;\n        while ((1 << log) < _n) log++;\n        table.assign(log\
      \ + 1, std::vector<M>(_n));\n        for (int i = 0; i < _n; ++i) table[0][i]\
      \ = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = 1; i <= log; ++i) {\n      \
      \      int shift = 1 << i;\n            for (int left = 0; left < _n; left +=\
      \ shift << 1) {\n                int cent = std::min(left + shift, _n);\n  \
      \              table[i][cent - 1] = table[0][cent - 1];\n                for\
      \ (int j = cent - 2; j >= left; --j) {\n                    table[i][j] = M::op(table[0][j],\
      \ table[i][j + 1]);\n                }\n                if (cent == _n) break;\n\
      \                table[i][cent] = table[0][cent];\n                int right\
      \ = std::min(cent + shift, _n);\n                for (int j = cent + 1; j <\
      \ right; ++j) {\n                    table[i][j] = M::op(table[i][j - 1], table[0][j]);\n\
      \                }\n            }\n        }\n    }\n\n    template <class...\
      \ Args> void init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n\
      \        assert(!is_built);\n        table[0][p] = M(args...);\n    }\n\n  \
      \  M prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n\
      \        assert(is_built);\n        if (l == r) return M::unit();\n        if\
      \ (l + 1 == r) return table[0][l];\n        --r;\n        int pos = 31 ^ __builtin_clz(l\
      \ ^ r);\n        return M::op(table[pos][l], table[pos][r]);\n    }\n\n  private:\n\
      \    int _n, log;\n    std::vector<std::vector<M>> table;\n    std::vector<int>\
      \ lookup;\n    bool is_built = false;\n};\n\n} // namespace kk2\n\n#endif //\
      \ KK2_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP\n"
    name: default
  - code: "#line 1 \"data_structure/disjoint_sparse_table.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <vector>\n\n#line 1 \"type_traits/algebra.hpp\"\
      \n\n\n\n#include <concepts>\n\nnamespace kk2 {\n\nnamespace algebra {\n\n//\
      \ These concepts describe the static interface expected by the library.\n//\
      \ Algebraic laws such as associativity cannot be checked by the type system.\n\
      //\n// A user-defined monoid therefore needs only:\n//\n//   struct MyMonoid\
      \ {\n//       static MyMonoid op(const MyMonoid &, const MyMonoid &);\n//  \
      \     static MyMonoid unit();\n//   };\n//\n// The return types are intentionally\
      \ exact, so a typo such as returning the\n// underlying scalar instead of MyMonoid\
      \ is diagnosed at the concept boundary.\ntemplate <class T>\nconcept Semigroup\
      \ = requires(const T &x, const T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> && requires {\n    {\
      \ T::unit() } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept Group =\
      \ Monoid<T> && requires(const T &x) {\n    { T::inv(x) } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept CommutativeMonoid = Monoid<T> && requires\
      \ {\n    { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \ntemplate <class T>\nconcept CommutativeGroup = Group<T> && requires {\n  \
      \  { T::commutative } -> std::convertible_to<bool>;\n} && bool(T::commutative);\n\
      \n// An action specification owns the pair of algebraic types and the mapping\n\
      // between them. It is the interface required by lazy propagation structures.\n\
      template <class T>\nconcept Action =\n    requires {\n        typename T::A;\n\
      \        typename T::S;\n    } && Monoid<typename T::A> && Monoid<typename T::S>\n\
      \    && requires(const typename T::A &f, const typename T::S &x) {\n       \
      \    { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n} // namespace\
      \ algebra\n\n} // namespace kk2\n\n\n#line 9 \"data_structure/disjoint_sparse_table.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <algebra::Monoid M> struct DisjointSparseTable\
      \ {\n    DisjointSparseTable() = default;\n\n    DisjointSparseTable(int n)\
      \ : _n(n) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n    \
      \    table.assign(log + 1, std::vector<M>(_n));\n    }\n\n    DisjointSparseTable(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<M>(_n));\n\
      \        for (int i = 0; i < _n; ++i) table[0][i] = v[i];\n        build();\n\
      \    }\n\n    void build() {\n        assert(!is_built);\n        is_built =\
      \ true;\n        for (int i = 1; i <= log; ++i) {\n            int shift = 1\
      \ << i;\n            for (int left = 0; left < _n; left += shift << 1) {\n \
      \               int cent = std::min(left + shift, _n);\n                table[i][cent\
      \ - 1] = table[0][cent - 1];\n                for (int j = cent - 2; j >= left;\
      \ --j) {\n                    table[i][j] = M::op(table[0][j], table[i][j +\
      \ 1]);\n                }\n                if (cent == _n) break;\n        \
      \        table[i][cent] = table[0][cent];\n                int right = std::min(cent\
      \ + shift, _n);\n                for (int j = cent + 1; j < right; ++j) {\n\
      \                    table[i][j] = M::op(table[i][j - 1], table[0][j]);\n  \
      \              }\n            }\n        }\n    }\n\n    template <class...\
      \ Args> void init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n\
      \        assert(!is_built);\n        table[0][p] = M(args...);\n    }\n\n  \
      \  M prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n\
      \        assert(is_built);\n        if (l == r) return M::unit();\n        if\
      \ (l + 1 == r) return table[0][l];\n        --r;\n        int pos = 31 ^ __builtin_clz(l\
      \ ^ r);\n        return M::op(table[pos][l], table[pos][r]);\n    }\n\n  private:\n\
      \    int _n, log;\n    std::vector<std::vector<M>> table;\n    std::vector<int>\
      \ lookup;\n    bool is_built = false;\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq_2.test.cpp
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
---
