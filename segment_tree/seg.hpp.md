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
    - filename: algebra.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/algebra/algebra.test.cpp
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_SEGMENT_TREE_SEG_HPP\n#define KK2_SEGMENT_TREE_SEG_HPP 1\n\n\
      #include <cassert>\n#include <vector>\n\n#include \"../type_traits/algebra.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <algebra::Monoid M> struct SegmentTree {\n \
      \ public:\n    SegmentTree() : SegmentTree(0) {}\n\n    SegmentTree(int n) :\
      \ _n(n) {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n))\
      \ log++;\n        size = 1 << log;\n        d = std::vector<M>(2 * size, M::unit());\n\
      \    }\n\n    template <class... Args> SegmentTree(int n, Args... args)\n  \
      \      : SegmentTree(std::vector<M>(n, M(args...))) {}\n\n    SegmentTree(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1U << log) < (unsigned int)(_n)) log++;\n        size = 1 << log;\n    \
      \    d = std::vector<M>(2 * size, M::unit());\n        for (int i = 0; i < _n;\
      \ i++) d[size + i] = v[i];\n        build();\n    }\n\n    void build() {\n\
      \        assert(!is_built);\n        is_built = true;\n        for (int i =\
      \ size - 1; i >= 1; i--) update(i);\n    }\n\n    template <class... Args> void\
      \ init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n     \
      \   assert(!is_built);\n        d[p + size] = M(args...);\n    }\n\n    using\
      \ Monoid = M;\n\n    static M Op(M l, M r) { return M::op(l, r); }\n\n    static\
      \ M MonoidUnit() { return M::unit(); }\n\n    template <class... Args> void\
      \ set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        d[p] = M(args...);\n        for (int i = 1; i <=\
      \ log; i++) update(p >> i);\n    }\n\n    M get(int p) {\n        assert(0 <=\
      \ p && p < _n);\n        assert(is_built);\n        return d[p + size];\n  \
      \  }\n\n    M prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        assert(is_built);\n        M sml = M::unit(), smr = M::unit();\n\
      \        l += size;\n        r += size;\n\n        while (l < r) {\n       \
      \     if (l & 1) sml = M::op(sml, d[l++]);\n            if (r & 1) smr = M::op(d[--r],\
      \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
      \ M::op(sml, smr);\n    }\n\n    M all_prod() {\n        assert(is_built);\n\
      \        return d[1];\n    }\n\n    template <bool (*f)(M)> int max_right(int\
      \ l) {\n        return max_right(l, [](M x) { return f(x); });\n    }\n\n  \
      \  template <class F> int max_right(int l, F f) {\n        assert(0 <= l &&\
      \ l <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n    \
      \    if (l == _n) return _n;\n        l += size;\n        M sm = M::unit();\n\
      \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(M::op(sm,\
      \ d[l]))) {\n                while (l < size) {\n                    l = (2\
      \ * l);\n                    if (f(M::op(sm, d[l]))) {\n                   \
      \     sm = M::op(sm, d[l]);\n                        l++;\n                \
      \    }\n                }\n                return l - size;\n            }\n\
      \            sm = M::op(sm, d[l]);\n            l++;\n        } while ((l &\
      \ -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(M)> int min_left(int\
      \ r) {\n        return min_left(r, [](M x) { return f(x); });\n    }\n\n   \
      \ template <class F> int min_left(int r, F f) {\n        assert(0 <= r && r\
      \ <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n      \
      \  if (r == 0) return 0;\n        r += size;\n        M sm = M::unit();\n  \
      \      do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
      \            if (!f(M::op(d[r], sm))) {\n                while (r < size) {\n\
      \                    r = (2 * r + 1);\n                    if (f(M::op(d[r],\
      \ sm))) {\n                        sm = M::op(d[r], sm);\n                 \
      \       r--;\n                    }\n                }\n                return\
      \ r + 1 - size;\n            }\n            sm = M::op(d[r], sm);\n        }\
      \ while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n,\
      \ size, log;\n    std::vector<M> d;\n    bool is_built = false;\n\n    void\
      \ update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_SEGMENT_TREE_SEG_HPP\n"
    name: default
  - code: "#line 1 \"segment_tree/seg.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
      \n#line 1 \"type_traits/algebra.hpp\"\n\n\n\n#include <concepts>\n\nnamespace\
      \ kk2 {\n\nnamespace algebra {\n\n// These concepts describe the static interface\
      \ expected by the library.\n// Algebraic laws such as associativity cannot be\
      \ checked by the type system.\n//\n// A user-defined monoid therefore needs\
      \ only:\n//\n//   struct MyMonoid {\n//       static MyMonoid op(const MyMonoid\
      \ &, const MyMonoid &);\n//       static MyMonoid unit();\n//   };\n//\n// The\
      \ return types are intentionally exact, so a typo such as returning the\n//\
      \ underlying scalar instead of MyMonoid is diagnosed at the concept boundary.\n\
      template <class T>\nconcept Semigroup = requires(const T &x, const T &y) {\n\
      \    { T::op(x, y) } -> std::same_as<T>;\n};\n\ntemplate <class T>\nconcept\
      \ Monoid = Semigroup<T> && requires {\n    { T::unit() } -> std::same_as<T>;\n\
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
      } // namespace algebra\n\n} // namespace kk2\n\n\n#line 8 \"segment_tree/seg.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <algebra::Monoid M> struct SegmentTree {\n \
      \ public:\n    SegmentTree() : SegmentTree(0) {}\n\n    SegmentTree(int n) :\
      \ _n(n) {\n        log = 0;\n        while ((1U << log) < (unsigned int)(_n))\
      \ log++;\n        size = 1 << log;\n        d = std::vector<M>(2 * size, M::unit());\n\
      \    }\n\n    template <class... Args> SegmentTree(int n, Args... args)\n  \
      \      : SegmentTree(std::vector<M>(n, M(args...))) {}\n\n    SegmentTree(const\
      \ std::vector<M> &v) : _n(int(v.size())) {\n        log = 0;\n        while\
      \ ((1U << log) < (unsigned int)(_n)) log++;\n        size = 1 << log;\n    \
      \    d = std::vector<M>(2 * size, M::unit());\n        for (int i = 0; i < _n;\
      \ i++) d[size + i] = v[i];\n        build();\n    }\n\n    void build() {\n\
      \        assert(!is_built);\n        is_built = true;\n        for (int i =\
      \ size - 1; i >= 1; i--) update(i);\n    }\n\n    template <class... Args> void\
      \ init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n     \
      \   assert(!is_built);\n        d[p + size] = M(args...);\n    }\n\n    using\
      \ Monoid = M;\n\n    static M Op(M l, M r) { return M::op(l, r); }\n\n    static\
      \ M MonoidUnit() { return M::unit(); }\n\n    template <class... Args> void\
      \ set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        d[p] = M(args...);\n        for (int i = 1; i <=\
      \ log; i++) update(p >> i);\n    }\n\n    M get(int p) {\n        assert(0 <=\
      \ p && p < _n);\n        assert(is_built);\n        return d[p + size];\n  \
      \  }\n\n    M prod(int l, int r) {\n        assert(0 <= l && l <= r && r <=\
      \ _n);\n        assert(is_built);\n        M sml = M::unit(), smr = M::unit();\n\
      \        l += size;\n        r += size;\n\n        while (l < r) {\n       \
      \     if (l & 1) sml = M::op(sml, d[l++]);\n            if (r & 1) smr = M::op(d[--r],\
      \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
      \ M::op(sml, smr);\n    }\n\n    M all_prod() {\n        assert(is_built);\n\
      \        return d[1];\n    }\n\n    template <bool (*f)(M)> int max_right(int\
      \ l) {\n        return max_right(l, [](M x) { return f(x); });\n    }\n\n  \
      \  template <class F> int max_right(int l, F f) {\n        assert(0 <= l &&\
      \ l <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n    \
      \    if (l == _n) return _n;\n        l += size;\n        M sm = M::unit();\n\
      \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(M::op(sm,\
      \ d[l]))) {\n                while (l < size) {\n                    l = (2\
      \ * l);\n                    if (f(M::op(sm, d[l]))) {\n                   \
      \     sm = M::op(sm, d[l]);\n                        l++;\n                \
      \    }\n                }\n                return l - size;\n            }\n\
      \            sm = M::op(sm, d[l]);\n            l++;\n        } while ((l &\
      \ -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(M)> int min_left(int\
      \ r) {\n        return min_left(r, [](M x) { return f(x); });\n    }\n\n   \
      \ template <class F> int min_left(int r, F f) {\n        assert(0 <= r && r\
      \ <= _n);\n        assert(f(M::unit()));\n        assert(is_built);\n      \
      \  if (r == 0) return 0;\n        r += size;\n        M sm = M::unit();\n  \
      \      do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
      \            if (!f(M::op(d[r], sm))) {\n                while (r < size) {\n\
      \                    r = (2 * r + 1);\n                    if (f(M::op(d[r],\
      \ sm))) {\n                        sm = M::op(d[r], sm);\n                 \
      \       r--;\n                    }\n                }\n                return\
      \ r + 1 - size;\n            }\n            sm = M::op(d[r], sm);\n        }\
      \ while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n    int _n,\
      \ size, log;\n    std::vector<M> d;\n    bool is_built = false;\n\n    void\
      \ update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: segment_tree/seg.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/algebra/algebra.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
documentation_of: segment_tree/seg.hpp
layout: document
---
