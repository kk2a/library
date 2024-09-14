---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/homomorphism/add.hpp
    title: math/homomorphism/add.hpp
  - icon: ':warning:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':warning:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  - icon: ':warning:'
    path: segment_tree/lazy_base.hpp
    title: segment_tree/lazy_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/utility/addmax.hpp\"\n\n\n\n#line 1 \"math/homomorphism/add.hpp\"\
    \n\n\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S> using\
    \ Add = S;\n\ntemplate <class S, class T> T AddMap(Add<S> f, T x) {\n    return\
    \ x.add(f);\n}\n\ntemplate <class S> Add<S> AddComposition(Add<S> l, Add<S> r)\
    \ {\n    return l + r;\n}\n\ntemplate <class S> Add<S> AddUnit() {\n    return\
    \ Add<S>();\n}\n\n} // namespace homomorphism\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"math/monoid/max.hpp\"\n\n\n\n#include <algorithm>\n#include <iostream>\n\
    #include <string>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\
    \ntemplate <class S> struct Max {\n    S a;\n    bool minf;\n\n    Max() : a(S()),\
    \ minf(true) {}\n\n    Max(S a_, bool minf_ = false) : a(a_), minf(minf_) {}\n\
    \n    operator S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Max &max) {\n        os << (max.minf ? \"minf\" : std::to_string(max.a));\n\
    \        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Max &max) {\n        is >> max.a;\n        max.minf = false;\n        return\
    \ is;\n    }\n\n    Max &operator=(const S &rhs) {\n        a = rhs;\n       \
    \ minf = false;\n        return *this;\n    }\n\n    Max &add(const S &rhs) {\n\
    \        if (minf) return *this;\n        a += rhs;\n        return *this;\n \
    \   }\n\n    Max &update(const S &rhs) {\n        a = rhs;\n        minf = false;\n\
    \        return *this;\n    }\n\n    Max &op(const Max &rhs) {\n        if (rhs.minf)\
    \ return *this;\n        if (minf) return *this = rhs;\n        a = std::max(a,\
    \ rhs.a);\n        return *this;\n    }\n\n    bool is_minf() const { return minf;\
    \ }\n};\n\ntemplate <class S> Max<S> MaxOp(Max<S> l, Max<S> r) {\n    return l.op(r);\n\
    }\n\ntemplate <class S> Max<S> MaxUnit() {\n    return Max<S>();\n}\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nstd::vector<monoid::Max<S>> GetVecMax(int\
    \ n, Args... args) {\n    return std::vector<monoid::Max<S>>(n, monoid::Max<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Max<S>>>\
    \ GetVecMax2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Max<S>>>(h,\
    \ GetVecMax<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/lazy.hpp\"\
    \n\n\n\n#line 1 \"segment_tree/lazy_base.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <functional>\n#line 7 \"segment_tree/lazy_base.hpp\"\n\nnamespace kk2 {\n\n\
    template <class S,\n          S (*op)(S, S),\n          S (*e)(),\n          class\
    \ F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n     \
    \     F (*id)()>\nstruct LazySegTreeBase {\n  public:\n    LazySegTreeBase() :\
    \ LazySegTreeBase(0) {}\n\n    LazySegTreeBase(int n) : LazySegTreeBase(std::vector<S>(n,\
    \ e())) {}\n\n    template <class... Args>\n    LazySegTreeBase(int n, Args...\
    \ args)\n        : LazySegTreeBase(std::vector<S>(n, S(args...))) {}\n\n    LazySegTreeBase(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1ll\
    \ << log) < _n) log++;\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        lz = std::vector<F>(size, id());\n        for (int i\
    \ = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) { update(i); }\n    }\n\n    using Monoid = S;\n\n    static S Op(S l,\
    \ S r) { return op(l, r); }\n\n    static S MonoidUnit() { return e(); }\n\n \
    \   using Hom = F;\n\n    static S Map(F f, S x) { return mapping(f, x); }\n\n\
    \    static F Composition(F l, F r) { return composition(l, r); }\n\n    static\
    \ F HomUnit() { return id(); }\n\n    virtual ~LazySegTreeBase() = default;\n\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    template <class...\
    \ Args> void emplace_set(int p, Args... args) {\n        set(p, S(args...));\n\
    \    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        return\
    \ d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <= _n);\n        if (l == r) return e();\n\n        l += size;\n      \
    \  r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if (((l\
    \ >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push(r\
    \ >> i);\n        }\n\n        S sml = e(), smr = e();\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    template <class... Args> void emplace_apply_point(int p, Args...\
    \ args) {\n        apply(p, F(args...));\n    }\n\n    void apply(int l, int r,\
    \ F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n       \
    \     int l2 = l, r2 = r;\n            while (l < r) {\n                if (l\
    \ & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r, f);\n   \
    \             l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i <= log; i++)\
    \ {\n            if (((l >> i) << i) != l) update(l >> i);\n            if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\n    template <class...\
    \ Args>\n    void emplace_apply_range(int l, int r, Args... args) {\n        apply(l,\
    \ r, F(args...));\n    }\n\n    template <bool (*g)(S)> int max_right(int l) {\n\
    \        return max_right(l, [](S x) { return g(x); });\n    }\n\n    template\
    \ <class G> int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
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
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n\n   \
    \ virtual void all_apply(int k, F f) = 0;\n\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n} // namespace kk2\n\n\n#line 5 \"segment_tree/lazy.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n\
    \          class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegTree\n    : public LazySegTreeBase<S,\
    \ op, e, F, mapping, composition, id> {\n    using LazySegTreeBase<S, op, e, F,\
    \ mapping, composition, id>::\n        LazySegTreeBase;\n\n  protected:\n    void\
    \ all_apply(int k, F f) override {\n        this->d[k] = mapping(f, this->d[k]);\n\
    \        if (k < this->size) this->lz[k] = composition(f, this->lz[k]);\n    }\n\
    };\n\n} // namespace kk2\n\n\n#line 7 \"segment_tree/utility/addmax.hpp\"\n\n\
    namespace kk2 {\n\ntemplate <class S>\nusing AddMax = LazySegTree<monoid::Max<S>,\n\
    \                           monoid::MaxOp<S>,\n                           monoid::MaxUnit<S>,\n\
    \                           homomorphism::Add<S>,\n                          \
    \ homomorphism::AddMap<S, monoid::Max<S>>,\n                           homomorphism::AddComposition<S>,\n\
    \                           homomorphism::AddUnit<S>>;\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef SEGMENT_TREE_UTILITY_ADDMAX_HPP\n#define SEGMENT_TREE_UTILITY_ADDMAX_HPP\
    \ 1\n\n#include \"../../math/homomorphism/add.hpp\"\n#include \"../../math/monoid/max.hpp\"\
    \n#include \"../lazy.hpp\"\n\nnamespace kk2 {\n\ntemplate <class S>\nusing AddMax\
    \ = LazySegTree<monoid::Max<S>,\n                           monoid::MaxOp<S>,\n\
    \                           monoid::MaxUnit<S>,\n                           homomorphism::Add<S>,\n\
    \                           homomorphism::AddMap<S, monoid::Max<S>>,\n       \
    \                    homomorphism::AddComposition<S>,\n                      \
    \     homomorphism::AddUnit<S>>;\n\n} // namespace kk2\n\n#endif // SEGMENT_TREE_UTILITY_ADDMAX_HPP\n"
  dependsOn:
  - math/homomorphism/add.hpp
  - math/monoid/max.hpp
  - segment_tree/lazy.hpp
  - segment_tree/lazy_base.hpp
  isVerificationFile: false
  path: segment_tree/utility/addmax.hpp
  requiredBy: []
  timestamp: '2024-09-14 19:52:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/addmax.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/addmax.hpp
- /library/segment_tree/utility/addmax.hpp.html
title: segment_tree/utility/addmax.hpp
---
