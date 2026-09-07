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
  - files:
    - filename: static_rmq.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/static_rmq.hpp
    - filename: euler_tour.hpp
      icon: LIBRARY_ALL_AC
      path: graph/tree/euler_tour.hpp
    type: Required by
  - files:
    - filename: ds_static_rmq.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq.test.cpp
    - filename: tree_vertex_add_path_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    - filename: tree_vertex_add_subtree_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\n#define KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\
      \ 1\n\n#include <cassert>\n#include <vector>\n\n#include \"../type_traits/algebra.hpp\"\
      \n\nnamespace kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <algebra::Monoid\
      \ M> struct SparseTable {\n    SparseTable() = default;\n\n    SparseTable(int\
      \ n) : _n(n) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n \
      \       table.assign(log + 1, std::vector<M>(_n));\n    }\n\n    SparseTable(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<M>(_n));\n\
      \        for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        build();\n\
      \    }\n\n    void build() {\n        assert(!is_built);\n        is_built =\
      \ true;\n        for (int i = 1; i <= log; i++) {\n            for (int j =\
      \ 0; j + (1 << i) <= _n; j++) {\n                table[i][j] = M::op(table[i\
      \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n  \
      \  }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        table[0][p]\
      \ = M(args...);\n    }\n\n    using Monoid = M;\n\n    static M Op(M l, M r)\
      \ { return M::op(l, r); }\n\n    static M MonoidUnit() { return M::unit(); }\n\
      \n    M prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        assert(is_built);\n        if (l == r) return M::unit();\n \
      \       int i = 31 ^ __builtin_clz(r - l);\n        return M::op(table[i][l],\
      \ table[i][r - (1 << i)]);\n    }\n\n    M get(int i) const {\n        assert(0\
      \ <= i && i < _n);\n        assert(is_built);\n        return table[0][i];\n\
      \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
      \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
      \ <bool (*f)(M)> int max_right(int l) const {\n        return max_right(l, [](M\
      \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
      \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (l == _n) return _n;\n        int left\
      \ = l - 1, right = _n;\n        while (right - left > 1) {\n            int\
      \ mid = (left + right) >> 1;\n            if (f(prod(l, mid))) left = mid;\n\
      \            else right = mid;\n        }\n        return right;\n    }\n\n\
      \    // return l s.t.\n    // l = r or f(op(a[l], a[l+1], ..., a[r-1])) == false\n\
      \    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true\n    template <bool\
      \ (*f)(M)> int min_left(int r) const {\n        return min_left(r, [](M x) {\
      \ return f(x); });\n    }\n\n    template <class F> int min_left(int r, F f)\
      \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (r == 0) return 0;\n        int left\
      \ = -1, right = r;\n        while (right - left > 1) {\n            int mid\
      \ = (left + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n  \
      \          else left = mid;\n        }\n        return right;\n    }\n\n  private:\n\
      \    int _n, log;\n    std::vector<std::vector<M>> table;\n    bool is_built\
      \ = false;\n};\n\n} // namespace kk2\n\n#endif // KK2_DATA_STRUCTURE_SPARSE_TABLE_HPP\n"
    name: default
  - code: "#line 1 \"data_structure/sparse_table.hpp\"\n\n\n\n#include <cassert>\n\
      #include <vector>\n\n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\
      \nnamespace kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static\
      \ interface expected by the library.\n// Algebraic laws such as associativity\
      \ cannot be checked by the type system.\n//\n// A user-defined monoid therefore\
      \ needs only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const\
      \ MyMonoid &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n\
      //\n// The return types are intentionally exact, so a typo such as returning\
      \ the\n// underlying scalar instead of MyMonoid is diagnosed at the concept\
      \ boundary.\ntemplate <class T>\nconcept Semigroup = requires(const T &x, const\
      \ T &y) {\n    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\n\
      concept Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
      };\n\ntemplate <class T>\nconcept Group = Monoid<T> && requires(const T &x)\
      \ {\n    { T::inv(x) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ CommutativeMonoid = Monoid<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\ntemplate <class T>\nconcept CommutativeGroup =\
      \ Group<T> && requires {\n    { T::commutative } -> std::convertible_to<bool>;\n\
      } && bool(T::commutative);\n\n// An action specification owns the pair of algebraic\
      \ types and the mapping\n// between them. It is the interface required by lazy\
      \ propagation structures.\ntemplate <class T>\nconcept Action = requires {\n\
      \    typename T::A;\n    typename T::S;\n} && Monoid<typename T::A> && Monoid<typename\
      \ T::S>\n    && requires(const typename T::A &f, const typename T::S &x) {\n\
      \           { T::act(f, x) } -> std::same_as<typename T::S>;\n       };\n\n\
      } // namespace algebra\n\n} // namespace kk2\n\n\n#line 8 \"data_structure/sparse_table.hpp\"\
      \n\nnamespace kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <algebra::Monoid\
      \ M> struct SparseTable {\n    SparseTable() = default;\n\n    SparseTable(int\
      \ n) : _n(n) {\n        log = 0;\n        while ((1 << log) < _n) log++;\n \
      \       table.assign(log + 1, std::vector<M>(_n));\n    }\n\n    SparseTable(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1 << log) < _n) log++;\n        table.assign(log + 1, std::vector<M>(_n));\n\
      \        for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        build();\n\
      \    }\n\n    void build() {\n        assert(!is_built);\n        is_built =\
      \ true;\n        for (int i = 1; i <= log; i++) {\n            for (int j =\
      \ 0; j + (1 << i) <= _n; j++) {\n                table[i][j] = M::op(table[i\
      \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n  \
      \  }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        table[0][p]\
      \ = M(args...);\n    }\n\n    using Monoid = M;\n\n    static M Op(M l, M r)\
      \ { return M::op(l, r); }\n\n    static M MonoidUnit() { return M::unit(); }\n\
      \n    M prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        assert(is_built);\n        if (l == r) return M::unit();\n \
      \       int i = 31 ^ __builtin_clz(r - l);\n        return M::op(table[i][l],\
      \ table[i][r - (1 << i)]);\n    }\n\n    M get(int i) const {\n        assert(0\
      \ <= i && i < _n);\n        assert(is_built);\n        return table[0][i];\n\
      \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
      \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
      \ <bool (*f)(M)> int max_right(int l) const {\n        return max_right(l, [](M\
      \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
      \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (l == _n) return _n;\n        int left\
      \ = l - 1, right = _n;\n        while (right - left > 1) {\n            int\
      \ mid = (left + right) >> 1;\n            if (f(prod(l, mid))) left = mid;\n\
      \            else right = mid;\n        }\n        return right;\n    }\n\n\
      \    // return l s.t.\n    // l = r or f(op(a[l], a[l+1], ..., a[r-1])) == false\n\
      \    // l = 0 or f(op(a[l], a[l+1], ..., a[r]))   == true\n    template <bool\
      \ (*f)(M)> int min_left(int r) const {\n        return min_left(r, [](M x) {\
      \ return f(x); });\n    }\n\n    template <class F> int min_left(int r, F f)\
      \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(M::unit()));\n\
      \        assert(is_built);\n        if (r == 0) return 0;\n        int left\
      \ = -1, right = r;\n        while (right - left > 1) {\n            int mid\
      \ = (left + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n  \
      \          else left = mid;\n        }\n        return right;\n    }\n\n  private:\n\
      \    int _n, log;\n    std::vector<std::vector<M>> table;\n    bool is_built\
      \ = false;\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  pathExtension: hpp
  requiredBy:
  - data_structure/static_rmq.hpp
  - graph/tree/euler_tour.hpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
---
