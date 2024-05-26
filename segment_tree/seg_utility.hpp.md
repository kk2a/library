---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/seg_utility.hpp\"\n\n\n\n#line 1 \"segment_tree/lazy.hpp\"\
    \n\n\n\ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n  \
    \        class F,\n          S (*mapping)(F, S),\n          F (*composition)(F,\
    \ F),\n          F (*id)()>\nstruct LazySegTree {\n  public:\n    LazySegTree()\
    \ : LazySegTree(0) {}\n    LazySegTree(int n) : LazySegTree(std::vector<S>(n,\
    \ e())) {}\n    LazySegTree(const std::vector<S>& v) : _n(int(v.size())) {\n \
    \       log = 0;\n        while ((1ll << log) < _n) log++;\n        size = 1 <<\
    \ log;\n        d = vector<S>(2 * size, e());\n        lz = vector<F>(size, id());\n\
    \        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i\
    \ = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n   \
    \ void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n   \
    \     for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S get(int p)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        return d[p];\n    }\n\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sml\
    \ = e(), smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n  \
    \  S all_prod() { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n    \
    \    assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n   \
    \     l += size;\n        r += size;\n\n        for (int i = log; i >= 1; i--)\
    \ {\n            if (((l >> i) << i) != l) push(l >> i);\n            if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n            int\
    \ l2 = l, r2 = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ f);\n                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l\
    \ >> i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
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
    \   }\n    template <class G> int min_left(int r, G g) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        for (int i = log; i >= 1; i--) push((r - 1) >> i);\n\
    \        S sm = e();\n        do {\n            r--;\n            while (r > 1\
    \ && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n                while\
    \ (r < size) {\n                    push(r);\n                    r = (2 * r +\
    \ 1);\n                    if (g(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    void\
    \ all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size)\
    \ lz[k] = composition(f, lz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n};\n\n\n#line 5 \"segment_tree/seg_utility.hpp\"\n\nnamespace seg_utility\
    \ {\n\ntemplate <class S>\nstruct Sum {\n    S a, size;\n    Sum() = default;\n\
    \    Sum(S a, S size) : a(a), size(size) {}\n    operator S() const { return a;\
    \ }\n    friend ostream& operator<<(ostream& os, const Sum& aff) {\n        os\
    \ << aff.a;\n        return os;\n    }\n};\n\ntemplate <class S>\nSum<S> gen_sum(S\
    \ a) {\n    return Sum<S>(a, 1);\n}\n\ntemplate <class S>\nSum<S> gen_sum() {\n\
    \    return Sum<S>(0, 0);\n}\n\ntemplate <class S>\nvector<Sum<S>> gen_sum(vector<S>\
    \ a) {\n    vector<Sum<S>> res;\n    for (auto x : a) res.push_back(gen_sum(x));\n\
    \    return res;\n}\n\ntemplate <class S>\nstruct Affine {\n    S a, b;\n    Affine()\
    \ = default;\n    Affine(S a, S b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
    \ os, const Affine& aff) {\n        os << aff.a << \" \" << aff.b;\n        return\
    \ os;\n    }\n};\n\ntemplate <class S>\nAffine<S> gen_aff(S a, S b) {\n    return\
    \ Affine<S>(a, b);\n}\n\ntemplate <class S>\nAffine<S> gen_aff() {\n    return\
    \ Affine<S>(1, 0);\n}\n\ntemplate <class S>\nS Mx(S a, S b) {\n    return max(a,\
    \ b);\n}\n\ntemplate <class S>\nS Mn(S a, S b) {\n    return min(a, b);\n}\n\n\
    template <class S>\nSum<S> Sm(Sum<S> a, Sum<S> b) {\n    return Sum<S>(a.a + b.a,\
    \ a.size + b.size);\n}\n\ntemplate <class S>\nS Add(S a, S b) {\n    return a\
    \ + b;\n}\n\ntemplate <class S, S ID>\nS Update(S a, S b) {\n    return a == ID\
    \ ? b : a;\n}\n\ntemplate <class S>\nS Aff(Affine<S> aff, S x) {\n    return aff.a\
    \ * x + aff.b;\n}\n\ntemplate <class S>\nAffine<S> AffCompositon(Affine<S> a,\
    \ Affine<S> b) {\n    return Affine<S>(a.a * b.a, a.a * b.b + a.b);\n}\n\ntemplate\
    \ <class S>\nSum<S> AddSm(S a, Sum<S> b) {\n    return Sum<S>(b.a + a * b.size,\
    \ b.size);\n}\n\ntemplate <class S, S ID>\nSum<S> UpdateSm(S a, Sum<S> b) {\n\
    \    return Sum<S>(a == ID ? b.a : a, b.size);\n}\n\ntemplate <class S>\nSum<S>\
    \ AffSm(Affine<S> aff, Sum<S> x) {\n    return Sum<S>(aff.a * x.a + aff.b * x.size,\
    \ x.size);\n}\n\ntemplate <class S, S e>\nS Const() { return e; }\n\ntemplate\
    \ <class S>\nS Zero() { return S(); }\n\ntemplate <class S>\nAffine<S> Id() {\
    \ return Affine<S>(1, 0); }\n\ntemplate <class S, S MINF>\nusing AddMax = LazySegTree<S,\
    \ Mx<S>, Const<S, MINF>,\n    S, Add<S>, Add<S>, Zero<S>>;\n\ntemplate <class\
    \ S, S MINF, S ID>\nusing UpdateMax = LazySegTree<S, Mx<S>, Const<S, MINF>,\n\
    \    S, Update<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S, S MINF>\n\
    using AffineMax = LazySegTree<S, Mx<S>, Const<S, MINF>,\n    Affine<S>, Aff<S>,\
    \ AffCompositon<S>, Id<S>>;\n\ntemplate <class S, S INF>\nusing AddMin = LazySegTree<S,\
    \ Mn<S>, Const<S, INF>,\n    S, Add<S>, Add<S>, Zero<S>>;\n\ntemplate <class S,\
    \ S INF, S ID>\nusing UpdateMin = LazySegTree<S, Mn<S>, Const<S, INF>,\n    S,\
    \ Update<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S, S INF>\n\
    using AffineMin = LazySegTree<S, Mn<S>, Const<S, INF>,\n    Affine<S>, Aff<S>,\
    \ AffCompositon<S>, Id<S>>;\n\ntemplate <class S>\nusing AddSum = LazySegTree<Sum<S>,\
    \ Sm<S>, Zero<Sum<S>>,\n    S, AddSm<S>, Add<S>, Zero<S>>;\n\ntemplate <class\
    \ S, S ID>\nusing UpdateSum = LazySegTree<Sum<S>, Sm<S>, Zero<Sum<S>>,\n    S,\
    \ UpdateSm<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S>\nusing\
    \ AffineSum = LazySegTree<Sum<S>, Sm<S>, Zero<Sum<S>>,\n    Affine<S>, AffSm<S>,\
    \ AffCompositon<S>, Id<S>>;\n\n} // namespace seg_utility\n\nusing seg_utility::AddMax;\n\
    using seg_utility::UpdateMax;\nusing seg_utility::AffineMax;\nusing seg_utility::AddMin;\n\
    using seg_utility::UpdateMin;\nusing seg_utility::AffineMin;\nusing seg_utility::AddSum;\n\
    using seg_utility::UpdateSum;\nusing seg_utility::AffineSum;\nusing seg_utility::gen_sum;\n\
    using seg_utility::gen_aff;\n\n\n"
  code: "#ifndef SEG_UTILITY_HPP\n#define SEG_UTILITY_HPP 1\n\n#include \"lazy.hpp\"\
    \n\nnamespace seg_utility {\n\ntemplate <class S>\nstruct Sum {\n    S a, size;\n\
    \    Sum() = default;\n    Sum(S a, S size) : a(a), size(size) {}\n    operator\
    \ S() const { return a; }\n    friend ostream& operator<<(ostream& os, const Sum&\
    \ aff) {\n        os << aff.a;\n        return os;\n    }\n};\n\ntemplate <class\
    \ S>\nSum<S> gen_sum(S a) {\n    return Sum<S>(a, 1);\n}\n\ntemplate <class S>\n\
    Sum<S> gen_sum() {\n    return Sum<S>(0, 0);\n}\n\ntemplate <class S>\nvector<Sum<S>>\
    \ gen_sum(vector<S> a) {\n    vector<Sum<S>> res;\n    for (auto x : a) res.push_back(gen_sum(x));\n\
    \    return res;\n}\n\ntemplate <class S>\nstruct Affine {\n    S a, b;\n    Affine()\
    \ = default;\n    Affine(S a, S b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
    \ os, const Affine& aff) {\n        os << aff.a << \" \" << aff.b;\n        return\
    \ os;\n    }\n};\n\ntemplate <class S>\nAffine<S> gen_aff(S a, S b) {\n    return\
    \ Affine<S>(a, b);\n}\n\ntemplate <class S>\nAffine<S> gen_aff() {\n    return\
    \ Affine<S>(1, 0);\n}\n\ntemplate <class S>\nS Mx(S a, S b) {\n    return max(a,\
    \ b);\n}\n\ntemplate <class S>\nS Mn(S a, S b) {\n    return min(a, b);\n}\n\n\
    template <class S>\nSum<S> Sm(Sum<S> a, Sum<S> b) {\n    return Sum<S>(a.a + b.a,\
    \ a.size + b.size);\n}\n\ntemplate <class S>\nS Add(S a, S b) {\n    return a\
    \ + b;\n}\n\ntemplate <class S, S ID>\nS Update(S a, S b) {\n    return a == ID\
    \ ? b : a;\n}\n\ntemplate <class S>\nS Aff(Affine<S> aff, S x) {\n    return aff.a\
    \ * x + aff.b;\n}\n\ntemplate <class S>\nAffine<S> AffCompositon(Affine<S> a,\
    \ Affine<S> b) {\n    return Affine<S>(a.a * b.a, a.a * b.b + a.b);\n}\n\ntemplate\
    \ <class S>\nSum<S> AddSm(S a, Sum<S> b) {\n    return Sum<S>(b.a + a * b.size,\
    \ b.size);\n}\n\ntemplate <class S, S ID>\nSum<S> UpdateSm(S a, Sum<S> b) {\n\
    \    return Sum<S>(a == ID ? b.a : a, b.size);\n}\n\ntemplate <class S>\nSum<S>\
    \ AffSm(Affine<S> aff, Sum<S> x) {\n    return Sum<S>(aff.a * x.a + aff.b * x.size,\
    \ x.size);\n}\n\ntemplate <class S, S e>\nS Const() { return e; }\n\ntemplate\
    \ <class S>\nS Zero() { return S(); }\n\ntemplate <class S>\nAffine<S> Id() {\
    \ return Affine<S>(1, 0); }\n\ntemplate <class S, S MINF>\nusing AddMax = LazySegTree<S,\
    \ Mx<S>, Const<S, MINF>,\n    S, Add<S>, Add<S>, Zero<S>>;\n\ntemplate <class\
    \ S, S MINF, S ID>\nusing UpdateMax = LazySegTree<S, Mx<S>, Const<S, MINF>,\n\
    \    S, Update<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S, S MINF>\n\
    using AffineMax = LazySegTree<S, Mx<S>, Const<S, MINF>,\n    Affine<S>, Aff<S>,\
    \ AffCompositon<S>, Id<S>>;\n\ntemplate <class S, S INF>\nusing AddMin = LazySegTree<S,\
    \ Mn<S>, Const<S, INF>,\n    S, Add<S>, Add<S>, Zero<S>>;\n\ntemplate <class S,\
    \ S INF, S ID>\nusing UpdateMin = LazySegTree<S, Mn<S>, Const<S, INF>,\n    S,\
    \ Update<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S, S INF>\n\
    using AffineMin = LazySegTree<S, Mn<S>, Const<S, INF>,\n    Affine<S>, Aff<S>,\
    \ AffCompositon<S>, Id<S>>;\n\ntemplate <class S>\nusing AddSum = LazySegTree<Sum<S>,\
    \ Sm<S>, Zero<Sum<S>>,\n    S, AddSm<S>, Add<S>, Zero<S>>;\n\ntemplate <class\
    \ S, S ID>\nusing UpdateSum = LazySegTree<Sum<S>, Sm<S>, Zero<Sum<S>>,\n    S,\
    \ UpdateSm<S, ID>, Update<S, ID>, Const<S, ID>>;\n\ntemplate <class S>\nusing\
    \ AffineSum = LazySegTree<Sum<S>, Sm<S>, Zero<Sum<S>>,\n    Affine<S>, AffSm<S>,\
    \ AffCompositon<S>, Id<S>>;\n\n} // namespace seg_utility\n\nusing seg_utility::AddMax;\n\
    using seg_utility::UpdateMax;\nusing seg_utility::AffineMax;\nusing seg_utility::AddMin;\n\
    using seg_utility::UpdateMin;\nusing seg_utility::AffineMin;\nusing seg_utility::AddSum;\n\
    using seg_utility::UpdateSum;\nusing seg_utility::AffineSum;\nusing seg_utility::gen_sum;\n\
    using seg_utility::gen_aff;\n\n#endif // SEG_UTILITY_HPP\n"
  dependsOn:
  - segment_tree/lazy.hpp
  isVerificationFile: false
  path: segment_tree/seg_utility.hpp
  requiredBy: []
  timestamp: '2024-05-26 14:20:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/seg_utility.hpp
layout: document
redirect_from:
- /library/segment_tree/seg_utility.hpp
- /library/segment_tree/seg_utility.hpp.html
title: segment_tree/seg_utility.hpp
---
