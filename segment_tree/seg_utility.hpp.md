---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  - icon: ':warning:'
    path: segment_tree/lazy_base.hpp
    title: segment_tree/lazy_base.hpp
  - icon: ':warning:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/seg_utility.hpp\"\n\n\n\n#line 1 \"segment_tree/seg.hpp\"\
    \n\n\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegTree {\npublic:\n\
    \    SegTree() : SegTree(0) {}\n    SegTree(int n) : SegTree(std::vector<S>(n,\
    \ e())) {}\n    SegTree(const std::vector<S>& v) : _n(int(v.size())) {\n     \
    \   log = 0;\n        while ((1U << log) < (unsigned int)(_n)) log++;\n      \
    \  size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n        for (int\
    \ i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >=\
    \ 1; i--) {\n            update(i);\n        }\n    }\n\n    using Monoid = S;\n\
    \    static S Op(S l, S r) { return op(l, r); }\n    static S MonoidUnit() { return\
    \ e(); } \n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n \
    \       p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\nprivate:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n\n#line 1 \"segment_tree/lazy.hpp\"\n\
    \n\n\n#line 1 \"segment_tree/lazy_base.hpp\"\n\n\n\ntemplate <class S,\n     \
    \     S (*op)(S, S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F,\
    \ S),\n          F (*composition)(F, F),\n          F (*id)()>\nstruct LazySegTreeBase\
    \ {\n  public:\n    LazySegTreeBase() : LazySegTreeBase(0) {}\n    LazySegTreeBase(int\
    \ n) : LazySegTreeBase(std::vector<S>(n, e())) {}\n    LazySegTreeBase(const std::vector<S>&\
    \ v) : _n(int(v.size())) {\n        log = 0;\n        while ((1ll << log) < _n)\
    \ log++;\n        size = 1 << log;\n        d = vector<S>(2 * size, e());\n  \
    \      lz = vector<F>(size, id());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    using Monoid = S;\n    static S Op(S l, S r) { return\
    \ op(l, r); }\n    static S MonoidUnit() { return e(); }\n    using Hom = F;\n\
    \    static S Map(F f, S x) { return mapping(f, x); }\n    static F Composition(F\
    \ l, F r) { return composition(l, r); }\n    static F HomUnit() { return id();\
    \ } \n\n    virtual ~LazySegTreeBase() = default;\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push(r >> i);\n        }\n\n        S sml = e(), smr\
    \ = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
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
    \    }\n\n  protected:\n    int _n, size, log;\n    std::vector<S> d;\n    std::vector<F>\
    \ lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n    virtual\
    \ void all_apply(int k, F f) = 0;\n    void push(int k) {\n        all_apply(2\
    \ * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n        lz[k] = id();\n\
    \    }\n}; \n\n\n#line 5 \"segment_tree/lazy.hpp\"\n\ntemplate <class S,\n   \
    \       S (*op)(S, S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F,\
    \ S),\n          F (*composition)(F, F),\n          F (*id)()>\nstruct LazySegTree\
    \ : public LazySegTreeBase<S, op, e, F, mapping, composition, id> {\n    using\
    \ LazySegTreeBase<S, op, e, F, mapping, composition, id>::LazySegTreeBase;\n \
    \ protected:\n    void all_apply(int k, F f) override {\n        this->d[k] =\
    \ mapping(f, this->d[k]);\n        if (k < this->size) this->lz[k] = composition(f,\
    \ this->lz[k]);\n    }\n};\n\n\n#line 6 \"segment_tree/seg_utility.hpp\"\n\nnamespace\
    \ seg_utility {\n\ntemplate <class S>\nstruct Sum {\n    S a, size;\n    Sum()\
    \ : a(0), size(0) {}\n    Sum(S a, S size = 1) : a(a), size(size) {}\n    operator\
    \ S() const { return a; }\n    friend ostream& operator<<(ostream& os, const Sum&\
    \ sum) {\n        os << sum.a;\n        return os;\n    }\n\n    Sum& operator+=(const\
    \ S& rhs) {\n        a += rhs * size;\n        return *this;\n    }\n    Sum&\
    \ operator=(const S& rhs) {\n        a = rhs * size;\n        return *this;\n\
    \    }\n    Sum& operator*=(const S& rhs) {\n        a *= rhs;\n        return\
    \ *this;\n    }\n\n    friend Sum operator+(const Sum& lhs, const S& rhs) {\n\
    \        return Sum(lhs) += rhs;\n    }\n    friend Sum operator*(const Sum& lhs,\
    \ const S& rhs) {\n        return Sum(lhs) *= rhs;\n    }\n};\n\ntemplate <class\
    \ S>\nstruct Max {\n    S a;\n    bool minf;\n    Max() : a(0), minf(true) {}\n\
    \    Max (S a_, bool minf_ = false) : a(a_), minf(minf_) {}\n    operator S()\
    \ const { return a; }\n    friend ostream& operator<<(ostream& os, const Max&\
    \ max) {\n        os << (max.minf ? \"minf\" : to_string(max.a));\n        return\
    \ os;\n    }\n\n    Max& operator+=(const S& rhs) {\n        a += rhs;\n     \
    \   return *this;\n    }\n    Max& operator=(const S& rhs) {\n        a = rhs;\n\
    \        minf = false;\n        return *this;\n    }\n\n    friend Max operator+(const\
    \ Max& lhs, const S& rhs) {\n        return Max(lhs) += rhs;\n    }\n\n    bool\
    \ is_minf() const { return minf; }\n};\n\ntemplate <class S>\nstruct Min {\n \
    \   S a;\n    bool inf;\n    Min() : a(0), inf(true) {}\n    Min(S a_, bool inf_\
    \ = false) : a(a_), inf(inf_) {}\n    operator S() const { return a; }\n    friend\
    \ ostream& operator<<(ostream& os, const Min& min) {\n        os << (min.inf ?\
    \ \"inf\" : to_string(min.a));\n        return os;\n    }\n\n    Min& operator+=(const\
    \ S& rhs) {\n        a += rhs;\n        return *this;\n    }\n    Min& operator=(const\
    \ S& rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    friend Min operator+(const Min& lhs, const S& rhs) {\n        return\
    \ Min(lhs) += rhs;\n    }\n\n    bool is_inf() const { return inf; }\n};\n\ntemplate\
    \ <class S>\nstruct Update {\n    S a;\n    bool id;\n    Update() : a(0), id(true)\
    \ {}\n    Update(S a_, bool id_ = false) : a(a_), id(id_) {}\n    operator S()\
    \ const { return a; }\n    friend ostream& operator<<(ostream& os, const Update&\
    \ update) {\n        os << (update.id ? \"id\" : to_string(update.a));\n     \
    \   return os;\n    }\n};\n\ntemplate <class S>\nstruct Affine {\n    S a, b;\
    \ // x \\mapsto ax + b\n    Affine() : a(1), b(0) {};\n    Affine(S a, S b) :\
    \ a(a), b(b) {}\n    friend ostream& operator<<(ostream& os, const Affine& aff)\
    \ {\n        os << aff.a << \" \" << aff.b;\n        return os;\n    }\n};\n\n\
    template <class S>\nMax<S> MaxOp(Max<S> l, Max<S> r) {\n    return l.minf ? r\
    \ : (r.minf ? l : Max<S>(max(l.a, r.a)));\n}\n\ntemplate <class S>\nMin<S> MinOp(Min<S>\
    \ l, Min<S> r) {\n    return l.inf ? r : (r.inf ? l : Min<S>(min(l.a, r.a)));\n\
    }\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l, Sum<S> r) {\n    return Sum<S>(l.a\
    \ + r.a, l.size + r.size);\n}\n\ntemplate <class Add, class T>\nT AddMap(Add f,\
    \ T x) {\n    return x + f;\n}\n\ntemplate <class Add>\nAdd AddComposition(Add\
    \ l, Add r) {\n    return l + r;\n}\n\ntemplate <class S, class T>\nT UpdMap(Update<S>\
    \ f, T x) {\n    return f.id ? x : x = f.a;\n}\n\ntemplate <class S>\nUpdate<S>\
    \ UpdComposition(Update<S> l, Update<S> r) {\n    return l.id ? r : l;\n}\n\n\
    template <class S, class T>\nT AffMap(Affine<S> f, T x) {\n    return x * f.a\
    \ + f.b;\n}\n\ntemplate <class S>\nAffine<S> AffComposition(Affine<S> l, Affine<S>\
    \ r) {\n    return Affine<S>(l.a * r.a, l.a * r.b + l.b);\n}\n\ntemplate <class\
    \ S>\nS Unit() { return S(); }\n\n// seg\ntemplate <class S>\nusing MaxSeg = SegTree<Max<S>,\
    \ MaxOp<S>, Unit<Max<S>>>;\ntemplate <class S>\nusing MinSeg = SegTree<Min<S>,\
    \ MinOp<S>, Unit<Min<S>>>;\ntemplate <class S>\nusing SumSeg = SegTree<Sum<S>,\
    \ SumOp<S>, Unit<Sum<S>>>;\n\n// lazy\ntemplate <class S>\nusing AddMax = LazySegTree<Max<S>,\
    \ MaxOp<S>, Unit<Max<S>>,\n                           S, AddMap<S, Max<S>>, AddComposition<S>,\
    \ Unit<S>>;\ntemplate <class S>\nusing AddMin = LazySegTree<Min<S>, MinOp<S>,\
    \ Unit<Min<S>>,\n                           S, AddMap<S, Min<S>>, AddComposition<S>,\
    \ Unit<S>>;\ntemplate <class S>\nusing AddSum = LazySegTree<Sum<S>, SumOp<S>,\
    \ Unit<Sum<S>>,\n                           S, AddMap<S, Sum<S>>, AddComposition<S>,\
    \ Unit<S>>;\ntemplate <class S>\nusing UpdateMax = LazySegTree<Max<S>, MaxOp<S>,\
    \ Unit<Max<S>>,\n                              Update<S>, UpdMap<S, Max<S>>, UpdComposition<S>,\
    \ Unit<Update<S>>>;\ntemplate <class S>\nusing UpdateMin = LazySegTree<Min<S>,\
    \ MinOp<S>, Unit<Min<S>>,\n                              Update<S>, UpdMap<S,\
    \ Min<S>>, UpdComposition<S>, Unit<Update<S>>>;\ntemplate <class S>\nusing UpdateSum\
    \ = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,\n                            \
    \  Update<S>, UpdMap<S, Sum<S>>, UpdComposition<S>, Unit<Update<S>>>;\ntemplate\
    \ <class S>\nusing AffineSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,\n \
    \                             Affine<S>, AffMap<S, Sum<S>>, AffComposition<S>,\
    \ Unit<Affine<S>>>;\n\ntemplate <class S, class... Args>\nvector<S> GetVector(int\
    \ n, Args... args) { return vector<S>(n, S(args...)); }\n\ntemplate <class S,\
    \ class... Args>\nvector<Max<S>> GetVectorMax(int n, Args... args) { return vector<Max<S>>(n,\
    \ Max<S>(args...)); }\n\ntemplate <class S, class... Args>\nvector<Min<S>> GetVectorMin(int\
    \ n, Args... args) { return vector<Min<S>>(n, Min<S>(args...)); }\n\ntemplate\
    \ <class S, class... Args>\nvector<Sum<S>> GetVectorSum(int n, Args... args) {\
    \ return vector<Sum<int>>(n, Sum<S>(args...)); }\n\n} // namespace seg_utility\n\
    \nusing seg_utility::MaxSeg;\nusing seg_utility::MinSeg;\nusing seg_utility::SumSeg;\n\
    \nusing seg_utility::AddMax;\nusing seg_utility::AddMin;\nusing seg_utility::AddSum;\n\
    using seg_utility::UpdateMax;\nusing seg_utility::UpdateMin;\nusing seg_utility::UpdateSum;\n\
    using seg_utility::AffineSum;\n\n\n\n\n"
  code: "#ifndef SEG_UTILITY_HPP\n#define SEG_UTILITY_HPP 1\n\n#include \"seg.hpp\"\
    \n#include \"lazy.hpp\"\n\nnamespace seg_utility {\n\ntemplate <class S>\nstruct\
    \ Sum {\n    S a, size;\n    Sum() : a(0), size(0) {}\n    Sum(S a, S size = 1)\
    \ : a(a), size(size) {}\n    operator S() const { return a; }\n    friend ostream&\
    \ operator<<(ostream& os, const Sum& sum) {\n        os << sum.a;\n        return\
    \ os;\n    }\n\n    Sum& operator+=(const S& rhs) {\n        a += rhs * size;\n\
    \        return *this;\n    }\n    Sum& operator=(const S& rhs) {\n        a =\
    \ rhs * size;\n        return *this;\n    }\n    Sum& operator*=(const S& rhs)\
    \ {\n        a *= rhs;\n        return *this;\n    }\n\n    friend Sum operator+(const\
    \ Sum& lhs, const S& rhs) {\n        return Sum(lhs) += rhs;\n    }\n    friend\
    \ Sum operator*(const Sum& lhs, const S& rhs) {\n        return Sum(lhs) *= rhs;\n\
    \    }\n};\n\ntemplate <class S>\nstruct Max {\n    S a;\n    bool minf;\n   \
    \ Max() : a(0), minf(true) {}\n    Max (S a_, bool minf_ = false) : a(a_), minf(minf_)\
    \ {}\n    operator S() const { return a; }\n    friend ostream& operator<<(ostream&\
    \ os, const Max& max) {\n        os << (max.minf ? \"minf\" : to_string(max.a));\n\
    \        return os;\n    }\n\n    Max& operator+=(const S& rhs) {\n        a +=\
    \ rhs;\n        return *this;\n    }\n    Max& operator=(const S& rhs) {\n   \
    \     a = rhs;\n        minf = false;\n        return *this;\n    }\n\n    friend\
    \ Max operator+(const Max& lhs, const S& rhs) {\n        return Max(lhs) += rhs;\n\
    \    }\n\n    bool is_minf() const { return minf; }\n};\n\ntemplate <class S>\n\
    struct Min {\n    S a;\n    bool inf;\n    Min() : a(0), inf(true) {}\n    Min(S\
    \ a_, bool inf_ = false) : a(a_), inf(inf_) {}\n    operator S() const { return\
    \ a; }\n    friend ostream& operator<<(ostream& os, const Min& min) {\n      \
    \  os << (min.inf ? \"inf\" : to_string(min.a));\n        return os;\n    }\n\n\
    \    Min& operator+=(const S& rhs) {\n        a += rhs;\n        return *this;\n\
    \    }\n    Min& operator=(const S& rhs) {\n        a = rhs;\n        inf = false;\n\
    \        return *this;\n    }\n\n    friend Min operator+(const Min& lhs, const\
    \ S& rhs) {\n        return Min(lhs) += rhs;\n    }\n\n    bool is_inf() const\
    \ { return inf; }\n};\n\ntemplate <class S>\nstruct Update {\n    S a;\n    bool\
    \ id;\n    Update() : a(0), id(true) {}\n    Update(S a_, bool id_ = false) :\
    \ a(a_), id(id_) {}\n    operator S() const { return a; }\n    friend ostream&\
    \ operator<<(ostream& os, const Update& update) {\n        os << (update.id ?\
    \ \"id\" : to_string(update.a));\n        return os;\n    }\n};\n\ntemplate <class\
    \ S>\nstruct Affine {\n    S a, b; // x \\mapsto ax + b\n    Affine() : a(1),\
    \ b(0) {};\n    Affine(S a, S b) : a(a), b(b) {}\n    friend ostream& operator<<(ostream&\
    \ os, const Affine& aff) {\n        os << aff.a << \" \" << aff.b;\n        return\
    \ os;\n    }\n};\n\ntemplate <class S>\nMax<S> MaxOp(Max<S> l, Max<S> r) {\n \
    \   return l.minf ? r : (r.minf ? l : Max<S>(max(l.a, r.a)));\n}\n\ntemplate <class\
    \ S>\nMin<S> MinOp(Min<S> l, Min<S> r) {\n    return l.inf ? r : (r.inf ? l :\
    \ Min<S>(min(l.a, r.a)));\n}\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l, Sum<S>\
    \ r) {\n    return Sum<S>(l.a + r.a, l.size + r.size);\n}\n\ntemplate <class Add,\
    \ class T>\nT AddMap(Add f, T x) {\n    return x + f;\n}\n\ntemplate <class Add>\n\
    Add AddComposition(Add l, Add r) {\n    return l + r;\n}\n\ntemplate <class S,\
    \ class T>\nT UpdMap(Update<S> f, T x) {\n    return f.id ? x : x = f.a;\n}\n\n\
    template <class S>\nUpdate<S> UpdComposition(Update<S> l, Update<S> r) {\n   \
    \ return l.id ? r : l;\n}\n\ntemplate <class S, class T>\nT AffMap(Affine<S> f,\
    \ T x) {\n    return x * f.a + f.b;\n}\n\ntemplate <class S>\nAffine<S> AffComposition(Affine<S>\
    \ l, Affine<S> r) {\n    return Affine<S>(l.a * r.a, l.a * r.b + l.b);\n}\n\n\
    template <class S>\nS Unit() { return S(); }\n\n// seg\ntemplate <class S>\nusing\
    \ MaxSeg = SegTree<Max<S>, MaxOp<S>, Unit<Max<S>>>;\ntemplate <class S>\nusing\
    \ MinSeg = SegTree<Min<S>, MinOp<S>, Unit<Min<S>>>;\ntemplate <class S>\nusing\
    \ SumSeg = SegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>>;\n\n// lazy\ntemplate <class\
    \ S>\nusing AddMax = LazySegTree<Max<S>, MaxOp<S>, Unit<Max<S>>,\n           \
    \                S, AddMap<S, Max<S>>, AddComposition<S>, Unit<S>>;\ntemplate\
    \ <class S>\nusing AddMin = LazySegTree<Min<S>, MinOp<S>, Unit<Min<S>>,\n    \
    \                       S, AddMap<S, Min<S>>, AddComposition<S>, Unit<S>>;\ntemplate\
    \ <class S>\nusing AddSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,\n    \
    \                       S, AddMap<S, Sum<S>>, AddComposition<S>, Unit<S>>;\ntemplate\
    \ <class S>\nusing UpdateMax = LazySegTree<Max<S>, MaxOp<S>, Unit<Max<S>>,\n \
    \                             Update<S>, UpdMap<S, Max<S>>, UpdComposition<S>,\
    \ Unit<Update<S>>>;\ntemplate <class S>\nusing UpdateMin = LazySegTree<Min<S>,\
    \ MinOp<S>, Unit<Min<S>>,\n                              Update<S>, UpdMap<S,\
    \ Min<S>>, UpdComposition<S>, Unit<Update<S>>>;\ntemplate <class S>\nusing UpdateSum\
    \ = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,\n                            \
    \  Update<S>, UpdMap<S, Sum<S>>, UpdComposition<S>, Unit<Update<S>>>;\ntemplate\
    \ <class S>\nusing AffineSum = LazySegTree<Sum<S>, SumOp<S>, Unit<Sum<S>>,\n \
    \                             Affine<S>, AffMap<S, Sum<S>>, AffComposition<S>,\
    \ Unit<Affine<S>>>;\n\ntemplate <class S, class... Args>\nvector<S> GetVector(int\
    \ n, Args... args) { return vector<S>(n, S(args...)); }\n\ntemplate <class S,\
    \ class... Args>\nvector<Max<S>> GetVectorMax(int n, Args... args) { return vector<Max<S>>(n,\
    \ Max<S>(args...)); }\n\ntemplate <class S, class... Args>\nvector<Min<S>> GetVectorMin(int\
    \ n, Args... args) { return vector<Min<S>>(n, Min<S>(args...)); }\n\ntemplate\
    \ <class S, class... Args>\nvector<Sum<S>> GetVectorSum(int n, Args... args) {\
    \ return vector<Sum<int>>(n, Sum<S>(args...)); }\n\n} // namespace seg_utility\n\
    \nusing seg_utility::MaxSeg;\nusing seg_utility::MinSeg;\nusing seg_utility::SumSeg;\n\
    \nusing seg_utility::AddMax;\nusing seg_utility::AddMin;\nusing seg_utility::AddSum;\n\
    using seg_utility::UpdateMax;\nusing seg_utility::UpdateMin;\nusing seg_utility::UpdateSum;\n\
    using seg_utility::AffineSum;\n\n\n\n#endif // SEG_UTILITY_HPP\n"
  dependsOn:
  - segment_tree/seg.hpp
  - segment_tree/lazy.hpp
  - segment_tree/lazy_base.hpp
  isVerificationFile: false
  path: segment_tree/seg_utility.hpp
  requiredBy: []
  timestamp: '2024-07-03 14:09:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/seg_utility.hpp
layout: document
redirect_from:
- /library/segment_tree/seg_utility.hpp
- /library/segment_tree/seg_utility.hpp.html
title: segment_tree/seg_utility.hpp
---
