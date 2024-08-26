---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: others/homomorphism/update.hpp
    title: others/homomorphism/update.hpp
  - icon: ':warning:'
    path: others/monoid/sum.hpp
    title: others/monoid/sum.hpp
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
  bundledCode: "#line 1 \"segment_tree/utility/updatesum.hpp\"\n\n\n\n#line 1 \"segment_tree/lazy.hpp\"\
    \n\n\n\n#line 1 \"segment_tree/lazy_base.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class S,\n          S (*op)(S, S),\n          S (*e)(),\n          class F,\n\
    \          S (*mapping)(F, S),\n          F (*composition)(F, F),\n          F\
    \ (*id)()>\nstruct LazySegTreeBase {\n  public:\n    LazySegTreeBase() : LazySegTreeBase(0)\
    \ {}\n    LazySegTreeBase(int n) : LazySegTreeBase(std::vector<S>(n, e())) {}\n\
    \    template <class... Args>\n    LazySegTreeBase(int n, Args... args) : LazySegTreeBase(std::vector<S>(n,\
    \ S(args...))) {}\n    LazySegTreeBase(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        log = 0;\n        while ((1ll << log) < _n) log++;\n        size\
    \ = 1 << log;\n        d = vector<S>(2 * size, e());\n        lz = vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    using Monoid = S;\n    static S Op(S l, S r) { return op(l, r); }\n    static\
    \ S MonoidUnit() { return e(); }\n    using Hom = F;\n    static S Map(F f, S\
    \ x) { return mapping(f, x); }\n    static F Composition(F l, F r) { return composition(l,\
    \ r); }\n    static F HomUnit() { return id(); } \n\n    virtual ~LazySegTreeBase()\
    \ = default;\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n   \
    \ }\n    template <class... Args>\n    void emplace_set(int p, Args... args) {\n\
    \        set(p, S(args...));\n    }\n\n    S get(int p) {\n        assert(0 <=\
    \ p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\n        l +=\
    \ size;\n        r += size;\n\n        for (int i = log; i >= 1; i--) {\n    \
    \        if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) <<\
    \ i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr = e();\n     \
    \   while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n         \
    \   if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod() { return\
    \ d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n    }\n    template <class... Args>\n    void emplace_apply_point(int\
    \ p, Args... args) {\n        apply(p, F(args...));\n    }\n    void apply(int\
    \ l, int r, F f) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l\
    \ == r) return;\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    {\n            int l2 = l, r2 = r;\n            while (l < r) {\n       \
    \         if (l & 1) all_apply(l++, f);\n                if (r & 1) all_apply(--r,\
    \ f);\n                l >>= 1;\n                r >>= 1;\n            }\n   \
    \         l = l2;\n            r = r2;\n        }\n\n        for (int i = 1; i\
    \ <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n    \
    \        if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n \
    \   template <class... Args>\n    void emplace_apply_range(int l, int r, Args...\
    \ args) {\n        apply(l, r, F(args...));\n    }\n\n    template <bool (*g)(S)>\
    \ int max_right(int l) {\n        return max_right(l, [](S x) { return g(x); });\n\
    \    }\n    template <class G> int max_right(int l, G g) {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(g(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        for (int i = log; i >= 1; i--) push(l >> i);\n   \
    \     S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n   \
    \         if (!g(op(sm, d[l]))) {\n                while (l < size) {\n      \
    \              push(l);\n                    l = (2 * l);\n                  \
    \  if (g(op(sm, d[l]))) {\n                        sm = op(sm, d[l]);\n      \
    \                  l++;\n                    }\n                }\n          \
    \      return l - size;\n            }\n            sm = op(sm, d[l]);\n     \
    \       l++;\n        } while ((l & -l) != l);\n        return _n;\n    }\n\n\
    \    template <bool (*g)(S)> int min_left(int r) {\n        return min_left(r,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int min_left(int r,\
    \ G g) {\n        assert(0 <= r && r <= _n);\n        assert(g(e()));\n      \
    \  if (r == 0) return 0;\n        r += size;\n        for (int i = log; i >= 1;\
    \ i--) push((r - 1) >> i);\n        S sm = e();\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm)))\
    \ {\n                while (r < size) {\n                    push(r);\n      \
    \              r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n\
    \                        sm = op(d[r], sm);\n                        r--;\n  \
    \                  }\n                }\n                return r + 1 - size;\n\
    \            }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    virtual void all_apply(int k, F f) = 0;\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n}; \n\n} // namespace kk2\n\n\n#line 5 \"segment_tree/lazy.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S,\n          S (*op)(S, S),\n        \
    \  S (*e)(),\n          class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegTree : public LazySegTreeBase<S, op,\
    \ e, F, mapping, composition, id> {\n    using LazySegTreeBase<S, op, e, F, mapping,\
    \ composition, id>::LazySegTreeBase;\n  protected:\n    void all_apply(int k,\
    \ F f) override {\n        this->d[k] = mapping(f, this->d[k]);\n        if (k\
    \ < this->size) this->lz[k] = composition(f, this->lz[k]);\n    }\n};\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"others/monoid/sum.hpp\"\n\n\n\nnamespace kk2 {\n\
    \nnamespace monoid {\n\ntemplate <class S>\nstruct Sum {\n    S a, size;\n   \
    \ Sum() : a(0), size(0) {}\n    Sum(S a, S size = 1) : a(a), size(size) {}\n \
    \   operator S() const { return a; }\n    friend ostream& operator<<(ostream&\
    \ os, const Sum& sum) {\n        os << sum.a;\n        return os;\n    }\n   \
    \ friend istream& operator>>(istream& is, Sum& sum) {\n        is >> sum.a;\n\
    \        sum.size = 1;\n        return is;\n    }\n    Sum& operator=(const S&\
    \ rhs) {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\n\
    \    Sum& add(const S& rhs) {\n        a += rhs * size;\n        return *this;\n\
    \    }\n    Sum& update(const S& rhs) {\n        a = rhs * size;\n        return\
    \ *this;\n    }\n    Sum& multiply(const S& rhs) {\n        a *= rhs;\n      \
    \  return *this;\n    }\n    Sum& op(const Sum& rhs) {\n        a += rhs.a;\n\
    \        size += rhs.size;\n        return *this;\n    }\n};\n\ntemplate <class\
    \ S>\nSum<S> SumOp(Sum<S> l, Sum<S> r) { return l.op(r); }\n\ntemplate <class\
    \ S>\nSum<S> SumUnit() { return Sum<S>(); }\n\n} // namespace monoid\n\ntemplate\
    \ <class S, class... Args>\nvector<monoid::Sum<S>> GetVecSum(int n, Args... args)\
    \ {\n    return vector<monoid::Sum<S>>(n, monoid::Sum<S>(args...));\n}\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"others/homomorphism/update.hpp\"\n\n\n\nnamespace\
    \ kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S>\nstruct Update {\n \
    \   S a;\n    bool id;\n    Update() : a(0), id(true) {}\n    Update(S a_, bool\
    \ id_ = false) : a(a_), id(id_) {}\n    operator S() const { return a; }\n   \
    \ friend ostream& operator<<(ostream& os, const Update& update) {\n        os\
    \ << (update.id ? \"id\" : to_string(update.a));\n        return os;\n    }\n\n\
    \    Update& composition(const Update& f) {\n        if (f.id) return *this;\n\
    \        return *this = f;\n    }\n};\n\ntemplate <class S, class T>\nT UpdateMap(Update<S>\
    \ f, T x) { return f.id ? x : x.update(f.a); }\n\ntemplate <class S>\nUpdate<S>\
    \ UpdateComposition(Update<S> l, Update<S> r) { return r.composition(l); }\n\n\
    template <class S>\nUpdate<S> UpdateUnit() { return Update<S>(); }\n\n} // namespace\
    \ homomorphism\n\n} // namespace kk2\n\n\n#line 7 \"segment_tree/utility/updatesum.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S>\nusing UpdateSum =\n    LazySegTree<monoid::Sum<S>,\n\
    \                monoid::SumOp<S>,\n                monoid::SumUnit<S>,\n    \
    \            homomorphism::Update<S>,\n                homomorphism::UpdateMap<S,\
    \ monoid::Sum<S>>,\n                homomorphism::UpdateComposition<S>,\n    \
    \            homomorphism::UpdateUnit<S>>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef SEGMENT_TREE_UTILITY_UPDATESUM_HPP\n#define SEGMENT_TREE_UTILITY_UPDATESUM_HPP\
    \ 1\n\n#include \"../lazy.hpp\"\n#include \"../../others/monoid/sum.hpp\"\n#include\
    \ \"../../others/homomorphism/update.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S>\nusing UpdateSum =\n    LazySegTree<monoid::Sum<S>,\n                monoid::SumOp<S>,\n\
    \                monoid::SumUnit<S>,\n                homomorphism::Update<S>,\n\
    \                homomorphism::UpdateMap<S, monoid::Sum<S>>,\n               \
    \ homomorphism::UpdateComposition<S>,\n                homomorphism::UpdateUnit<S>>;\n\
    \n} // namespace kk2\n\n#endif // SEGMENT_TREE_UTILITY_UPDATESUM_HPP\n"
  dependsOn:
  - segment_tree/lazy.hpp
  - segment_tree/lazy_base.hpp
  - others/monoid/sum.hpp
  - others/homomorphism/update.hpp
  isVerificationFile: false
  path: segment_tree/utility/updatesum.hpp
  requiredBy: []
  timestamp: '2024-08-27 04:41:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/updatesum.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/updatesum.hpp
- /library/segment_tree/utility/updatesum.hpp.html
title: segment_tree/utility/updatesum.hpp
---
