---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/lazy.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class S,\n \
    \         S (*op)(S, S),\n          S (*e)(),\n          class F,\n          S\
    \ (*mapping)(F, S),\n          F (*composition)(F, F),\n          F (*id)()>\n\
    struct LazySegmentTree {\n  public:\n    LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n\n    LazySegmentTree(int n) : _n(n) {\n        log = 0;\n        while\
    \ ((1ll << log) < _n) log++;\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n    }\n\n    template\
    \ <class... Args> LazySegmentTree(int n, Args... args)\n        : LazySegmentTree(std::vector<S>(n,\
    \ S(args...))) {}\n\n    LazySegmentTree(const std::vector<S> &v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
    \ = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        build();\n\
    \    }\n\n    void build() {\n        assert(!is_built);\n        is_built = true;\n\
    \        for (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    template\
    \ <class... Args> void init_set(int p, Args... args) {\n        assert(0 <= p\
    \ && p < _n);\n        assert(!is_built);\n        d[p + size] = S(args...);\n\
    \    }\n\n    using Monoid = S;\n\n    static S Op(S l, S r) { return op(l, r);\
    \ }\n\n    static S MonoidUnit() { return e(); }\n\n    using Hom = F;\n\n   \
    \ static S Map(F f, S x) { return mapping(f, x); }\n\n    static F Composition(F\
    \ l, F r) { return composition(l, r); }\n\n    static F HomUnit() { return id();\
    \ }\n\n    template <class... Args> void set(int p, Args... args) {\n        assert(0\
    \ <= p && p < _n);\n        assert(is_built);\n        p += size;\n        for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = S(args...);\n     \
    \   for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <= _n);\n        assert(is_built);\n        if (l == r) return e();\n\n\
    \        l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr = e();\n\
    \        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n    \
    \        if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n           \
    \ r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ {\n        assert(is_built);\n        return d[1];\n    }\n\n    template <class...\
    \ Args> void apply_point(int p, Args... args) {\n        assert(0 <= p && p <\
    \ _n);\n        assert(is_built);\n        p += size;\n        for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n        d[p] = mapping(F(args...), d[p]);\n    \
    \    for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    template <class...\
    \ Args> void apply_range(int l, int r, Args... args) {\n        assert(0 <= l\
    \ && l <= r && r <= _n);\n        assert(is_built);\n        if (l == r) return;\n\
    \        F f = F(args...);\n\n        l += size;\n        r += size;\n\n     \
    \   for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l\
    \ >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\
    \n        {\n            int l2 = l, r2 = r;\n            while (l < r) {\n  \
    \              if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n\
    \    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     assert(is_built);\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return g(x); });\n \
    \   }\n\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        assert(is_built);\n       \
    \ if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n    bool is_built = false;\n\n    void update(int\
    \ k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\n    void all_apply(int k, F f)\
    \ {\n        d[k] = mapping(f, d[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n\n    void push(int k) {\n        all_apply(2 * k, lz[k]);\n\
    \        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n    }\n};\n\ntemplate\
    \ <class A> using LazySegmentTreeS = LazySegmentTree<typename A::S,\n        \
    \                                                    A::S::op,\n             \
    \                                               A::S::unit,\n                \
    \                                            typename A::A,\n                \
    \                                            A::act,\n                       \
    \                                     A::A::op,\n                            \
    \                                A::A::unit>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_SEGMENT_TREE_LAZY_HPP\n#define KK2_SEGMENT_TREE_LAZY_HPP 1\n\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace kk2\
    \ {\n\ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n   \
    \       class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegmentTree {\n  public:\n    LazySegmentTree()\
    \ : LazySegmentTree(0) {}\n\n    LazySegmentTree(int n) : _n(n) {\n        log\
    \ = 0;\n        while ((1ll << log) < _n) log++;\n        size = 1 << log;\n \
    \       d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n    }\n\n    template <class... Args> LazySegmentTree(int n, Args...\
    \ args)\n        : LazySegmentTree(std::vector<S>(n, S(args...))) {}\n\n    LazySegmentTree(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1ll\
    \ << log) < _n) log++;\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        build();\n    }\n\n    void build()\
    \ {\n        assert(!is_built);\n        is_built = true;\n        for (int i\
    \ = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    template <class... Args>\
    \ void init_set(int p, Args... args) {\n        assert(0 <= p && p < _n);\n  \
    \      assert(!is_built);\n        d[p + size] = S(args...);\n    }\n\n    using\
    \ Monoid = S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static\
    \ S MonoidUnit() { return e(); }\n\n    using Hom = F;\n\n    static S Map(F f,\
    \ S x) { return mapping(f, x); }\n\n    static F Composition(F l, F r) { return\
    \ composition(l, r); }\n\n    static F HomUnit() { return id(); }\n\n    template\
    \ <class... Args> void set(int p, Args... args) {\n        assert(0 <= p && p\
    \ < _n);\n        assert(is_built);\n        p += size;\n        for (int i =\
    \ log; i >= 1; i--) push(p >> i);\n        d[p] = S(args...);\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n       \
    \ assert(0 <= p && p < _n);\n        assert(is_built);\n        p += size;\n \
    \       for (int i = log; i >= 1; i--) push(p >> i);\n        return d[p];\n \
    \   }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        assert(is_built);\n        if (l == r) return e();\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push(r >> i);\n        }\n\n        S sml = e(), smr = e();\n        while (l\
    \ < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1)\
    \ smr = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n\n        return op(sml, smr);\n    }\n\n    S all_prod() {\n        assert(is_built);\n\
    \        return d[1];\n    }\n\n    template <class... Args> void apply_point(int\
    \ p, Args... args) {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = mapping(F(args...), d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    template <class... Args> void apply_range(int\
    \ l, int r, Args... args) {\n        assert(0 <= l && l <= r && r <= _n);\n  \
    \      assert(is_built);\n        if (l == r) return;\n        F f = F(args...);\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <bool\
    \ (*g)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ g(x); });\n    }\n\n    template <class G> int max_right(int l, G g) {\n   \
    \     assert(0 <= l && l <= _n);\n        assert(g(e()));\n        assert(is_built);\n\
    \        if (l == _n) return _n;\n        l += size;\n        for (int i = log;\
    \ i >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    push(l);\n                    l = (2\
    \ * l);\n                    if (g(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    template <bool (*g)(S)> int min_left(int r) {\n  \
    \      return min_left(r, [](S x) { return g(x); });\n    }\n\n    template <class\
    \ G> int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n\
    \        assert(is_built);\n        if (r == 0) return 0;\n        r += size;\n\
    \        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < size) {\n   \
    \                 push(r);\n                    r = (2 * r + 1);\n           \
    \         if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n  \
    \  int _n, size, log;\n    std::vector<S> d;\n    std::vector<F> lz;\n    bool\
    \ is_built = false;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k +\
    \ 1]); }\n\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\ntemplate <class A> using LazySegmentTreeS\
    \ = LazySegmentTree<typename A::S,\n                                         \
    \                   A::S::op,\n                                              \
    \              A::S::unit,\n                                                 \
    \           typename A::A,\n                                                 \
    \           A::act,\n                                                        \
    \    A::A::op,\n                                                            A::A::unit>;\n\
    \n} // namespace kk2\n\n#endif // KK2_SEGMENT_TREE_LAZY_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/lazy.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_range_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
documentation_of: segment_tree/lazy.hpp
layout: document
redirect_from:
- /library/segment_tree/lazy.hpp
- /library/segment_tree/lazy.hpp.html
title: segment_tree/lazy.hpp
---
