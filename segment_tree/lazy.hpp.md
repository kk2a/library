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
    - filename: ds_range_affine_range_sum.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    - filename: ds_range_affine_range_sum_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    - filename: ds_range_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/algebra.hpp
  embedded:
  - code: "#ifndef KK2_SEGMENT_TREE_LAZY_HPP\n#define KK2_SEGMENT_TREE_LAZY_HPP 1\n\
      \n#include <cassert>\n#include <vector>\n\n#include \"../type_traits/algebra.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <algebra::Action Action> struct LazySegmentTree\
      \ {\n    using S = typename Action::S;\n    using F = typename Action::A;\n\n\
      \  public:\n    LazySegmentTree() : LazySegmentTree(0) {}\n\n    LazySegmentTree(int\
      \ n) : _n(n) {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n\
      \        size = 1 << log;\n        d = std::vector<S>(2 * size, S::unit());\n\
      \        lz = std::vector<F>(size, F::unit());\n    }\n\n    template <class...\
      \ Args>\n    LazySegmentTree(int n, Args... args) : LazySegmentTree(std::vector<S>(n,\
      \ S(args...))) {}\n\n    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size()))\
      \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
      \ = 1 << log;\n        d = std::vector<S>(2 * size, S::unit());\n        lz\
      \ = std::vector<F>(size, F::unit());\n        for (int i = 0; i < _n; i++) d[size\
      \ + i] = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
      \    }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
      \ + size] = S(args...);\n    }\n\n    using Monoid = S;\n    static S Op(S l,\
      \ S r) { return S::op(l, r); }\n    static S MonoidUnit() { return S::unit();\
      \ }\n\n    using Hom = F;\n    static S Map(F f, S x) { return Action::act(f,\
      \ x); }\n    static F Composition(F l, F r) { return F::op(l, r); }\n    static\
      \ F HomUnit() { return F::unit(); }\n\n    template <class... Args> void set(int\
      \ p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
      \        d[p] = S(args...);\n        for (int i = 1; i <= log; i++) update(p\
      \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n \
      \       assert(is_built);\n        p += size;\n        for (int i = log; i >=\
      \ 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int\
      \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
      \        if (l == r) return S::unit();\n        l += size;\n        r += size;\n\
      \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
      \ l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n  \
      \      }\n        S sml = S::unit(), smr = S::unit();\n        while (l < r)\
      \ {\n            if (l & 1) sml = S::op(sml, d[l++]);\n            if (r & 1)\
      \ smr = S::op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
      \      }\n        return S::op(sml, smr);\n    }\n\n    S all_prod() {\n   \
      \     assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
      \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p\
      \ < _n);\n        assert(is_built);\n        p += size;\n        for (int i\
      \ = log; i >= 1; i--) push(p >> i);\n        d[p] = Action::act(F(args...),\
      \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
      \    template <class... Args> void apply_range(int l, int r, Args... args) {\n\
      \        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n \
      \       if (l == r) return;\n        F f = F(args...);\n        l += size;\n\
      \        r += size;\n        for (int i = log; i >= 1; i--) {\n            if\
      \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
      \ push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
      \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
      \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n \
      \               r >>= 1;\n            }\n            l = l2;\n            r\
      \ = r2;\n        }\n        for (int i = 1; i <= log; i++) {\n            if\
      \ (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) !=\
      \ r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\
      \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x);\
      \ });\n    }\n\n    template <class G> int max_right(int l, G g) {\n       \
      \ assert(0 <= l && l <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
      \ i >= 1; i--) push(l >> i);\n        S sm = S::unit();\n        do {\n    \
      \        while (l % 2 == 0) l >>= 1;\n            if (!g(S::op(sm, d[l]))) {\n\
      \                while (l < size) {\n                    push(l);\n        \
      \            l = 2 * l;\n                    if (g(S::op(sm, d[l]))) {\n   \
      \                     sm = S::op(sm, d[l]);\n                        l++;\n\
      \                    }\n                }\n                return l - size;\n\
      \            }\n            sm = S::op(sm, d[l]);\n            l++;\n      \
      \  } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
      \ (*g)(S)> int min_left(int r) {\n        return min_left(r, [](S x) { return\
      \ g(x); });\n    }\n\n    template <class G> int min_left(int r, G g) {\n  \
      \      assert(0 <= r && r <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
      \ i >= 1; i--) push((r - 1) >> i);\n        S sm = S::unit();\n        do {\n\
      \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n         \
      \   if (!g(S::op(d[r], sm))) {\n                while (r < size) {\n       \
      \             push(r);\n                    r = 2 * r + 1;\n               \
      \     if (g(S::op(d[r], sm))) {\n                        sm = S::op(d[r], sm);\n\
      \                        r--;\n                    }\n                }\n  \
      \              return r + 1 - size;\n            }\n            sm = S::op(d[r],\
      \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
      \    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n   \
      \ bool is_built = false;\n\n    void update(int k) { d[k] = S::op(d[2 * k],\
      \ d[2 * k + 1]); }\n\n    void all_apply(int k, const F &f) {\n        d[k]\
      \ = Action::act(f, d[k]);\n        if (k < size) lz[k] = F::op(f, lz[k]);\n\
      \    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n       \
      \ all_apply(2 * k + 1, lz[k]);\n        lz[k] = F::unit();\n    }\n};\n\n} //\
      \ namespace kk2\n\n#endif // KK2_SEGMENT_TREE_LAZY_HPP\n"
    name: default
  - code: "#line 1 \"segment_tree/lazy.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
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
      \ propagation structures.\ntemplate <class T>\nconcept Action =\n    requires\
      \ {\n        typename T::A;\n        typename T::S;\n    } && Monoid<typename\
      \ T::A> && Monoid<typename T::S>\n    && requires(const typename T::A &f, const\
      \ typename T::S &x) {\n           { T::act(f, x) } -> std::same_as<typename\
      \ T::S>;\n       };\n\n} // namespace algebra\n\n} // namespace kk2\n\n\n#line\
      \ 8 \"segment_tree/lazy.hpp\"\n\nnamespace kk2 {\n\ntemplate <algebra::Action\
      \ Action> struct LazySegmentTree {\n    using S = typename Action::S;\n    using\
      \ F = typename Action::A;\n\n  public:\n    LazySegmentTree() : LazySegmentTree(0)\
      \ {}\n\n    LazySegmentTree(int n) : _n(n) {\n        log = 0;\n        while\
      \ ((1ll << log) < _n) log++;\n        size = 1 << log;\n        d = std::vector<S>(2\
      \ * size, S::unit());\n        lz = std::vector<F>(size, F::unit());\n    }\n\
      \n    template <class... Args>\n    LazySegmentTree(int n, Args... args) : LazySegmentTree(std::vector<S>(n,\
      \ S(args...))) {}\n\n    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size()))\
      \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
      \ = 1 << log;\n        d = std::vector<S>(2 * size, S::unit());\n        lz\
      \ = std::vector<F>(size, F::unit());\n        for (int i = 0; i < _n; i++) d[size\
      \ + i] = v[i];\n        build();\n    }\n\n    void build() {\n        assert(!is_built);\n\
      \        is_built = true;\n        for (int i = size - 1; i >= 1; i--) update(i);\n\
      \    }\n\n    template <class... Args> void init_set(int p, Args... args) {\n\
      \        assert(0 <= p && p < _n);\n        assert(!is_built);\n        d[p\
      \ + size] = S(args...);\n    }\n\n    using Monoid = S;\n    static S Op(S l,\
      \ S r) { return S::op(l, r); }\n    static S MonoidUnit() { return S::unit();\
      \ }\n\n    using Hom = F;\n    static S Map(F f, S x) { return Action::act(f,\
      \ x); }\n    static F Composition(F l, F r) { return F::op(l, r); }\n    static\
      \ F HomUnit() { return F::unit(); }\n\n    template <class... Args> void set(int\
      \ p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
      \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
      \        d[p] = S(args...);\n        for (int i = 1; i <= log; i++) update(p\
      \ >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n \
      \       assert(is_built);\n        p += size;\n        for (int i = log; i >=\
      \ 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int\
      \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
      \        if (l == r) return S::unit();\n        l += size;\n        r += size;\n\
      \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
      \ l) push(l >> i);\n            if (((r >> i) << i) != r) push(r >> i);\n  \
      \      }\n        S sml = S::unit(), smr = S::unit();\n        while (l < r)\
      \ {\n            if (l & 1) sml = S::op(sml, d[l++]);\n            if (r & 1)\
      \ smr = S::op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n  \
      \      }\n        return S::op(sml, smr);\n    }\n\n    S all_prod() {\n   \
      \     assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
      \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p\
      \ < _n);\n        assert(is_built);\n        p += size;\n        for (int i\
      \ = log; i >= 1; i--) push(p >> i);\n        d[p] = Action::act(F(args...),\
      \ d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n\
      \    template <class... Args> void apply_range(int l, int r, Args... args) {\n\
      \        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n \
      \       if (l == r) return;\n        F f = F(args...);\n        l += size;\n\
      \        r += size;\n        for (int i = log; i >= 1; i--) {\n            if\
      \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
      \ push((r - 1) >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n\
      \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
      \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n \
      \               r >>= 1;\n            }\n            l = l2;\n            r\
      \ = r2;\n        }\n        for (int i = 1; i <= log; i++) {\n            if\
      \ (((l >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) !=\
      \ r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\
      \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x);\
      \ });\n    }\n\n    template <class G> int max_right(int l, G g) {\n       \
      \ assert(0 <= l && l <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
      \ i >= 1; i--) push(l >> i);\n        S sm = S::unit();\n        do {\n    \
      \        while (l % 2 == 0) l >>= 1;\n            if (!g(S::op(sm, d[l]))) {\n\
      \                while (l < size) {\n                    push(l);\n        \
      \            l = 2 * l;\n                    if (g(S::op(sm, d[l]))) {\n   \
      \                     sm = S::op(sm, d[l]);\n                        l++;\n\
      \                    }\n                }\n                return l - size;\n\
      \            }\n            sm = S::op(sm, d[l]);\n            l++;\n      \
      \  } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
      \ (*g)(S)> int min_left(int r) {\n        return min_left(r, [](S x) { return\
      \ g(x); });\n    }\n\n    template <class G> int min_left(int r, G g) {\n  \
      \      assert(0 <= r && r <= _n);\n        assert(g(S::unit()));\n        assert(is_built);\n\
      \        if (r == 0) return 0;\n        r += size;\n        for (int i = log;\
      \ i >= 1; i--) push((r - 1) >> i);\n        S sm = S::unit();\n        do {\n\
      \            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n         \
      \   if (!g(S::op(d[r], sm))) {\n                while (r < size) {\n       \
      \             push(r);\n                    r = 2 * r + 1;\n               \
      \     if (g(S::op(d[r], sm))) {\n                        sm = S::op(d[r], sm);\n\
      \                        r--;\n                    }\n                }\n  \
      \              return r + 1 - size;\n            }\n            sm = S::op(d[r],\
      \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
      \    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n   \
      \ bool is_built = false;\n\n    void update(int k) { d[k] = S::op(d[2 * k],\
      \ d[2 * k + 1]); }\n\n    void all_apply(int k, const F &f) {\n        d[k]\
      \ = Action::act(f, d[k]);\n        if (k < size) lz[k] = F::op(f, lz[k]);\n\
      \    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n       \
      \ all_apply(2 * k + 1, lz[k]);\n        lz[k] = F::unit();\n    }\n};\n\n} //\
      \ namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: segment_tree/lazy.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/algebra/algebra.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_set_range_composite.test.cpp
documentation_of: segment_tree/lazy.hpp
layout: document
---
