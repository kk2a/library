---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/monoid/max_min_sum.hpp
    title: math/monoid/max_min_sum.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/utility/max_min_sum_seg.hpp\"\n\n\n\n#line\
    \ 1 \"math/monoid/max_min_sum.hpp\"\n\n\n\n#include <algorithm>\n#include <iostream>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class\
    \ S> struct MaxMinSum {\n    S sum, max, min;\n    int size;\n    bool is_unit;\n\
    \n    constexpr MaxMinSum() : sum(0), max(0), min(0), size(0), is_unit(true) {}\n\
    \n    constexpr MaxMinSum(S a, bool is_unit_ = false)\n        : sum(a),\n   \
    \       max(a),\n          min(a),\n          size(1),\n          is_unit(is_unit_)\
    \ {}\n\n    constexpr MaxMinSum(S sum_, S max_, S min_, int size_)\n        :\
    \ sum(sum_),\n          max(max_),\n          min(min_),\n          size(size_),\n\
    \          is_unit(is_unit_) {}\n\n    template <class OStream>\n    friend OStream\
    \ &operator<<(OStream &os, const MaxMinSum &maxminSum) {\n        os << maxminSum.sum\
    \ << \" \" << maxminSum.max << \" \" << maxminSum.min;\n        return os;\n \
    \   }\n\n    template <class IStream>\n    friend IStream &operator>>(IStream\
    \ &is, MaxMinSum &maxminSum) {\n        S a;\n        is >> a;\n        maxminSum.sum\
    \ = maxminSum.max = maxminSum.min = a;\n        maxminSum.size = 1;\n        return\
    \ is;\n    }\n\n    constexpr MaxMinSum &operator=(const S &rhs) {\n        sum\
    \ = max = min = rhs;\n        size = 1;\n        is_unit = false;\n        return\
    \ *this;\n    }\n\n    constexpr MaxMinSum &add(const S &rhs) {\n        if (is_unit)\
    \ return *this;\n        sum += rhs * size;\n        max += rhs;\n        min\
    \ += rhs;\n        return *this;\n    }\n\n    constexpr MaxMinSum &update(const\
    \ S &rhs) {\n        sum = rhs * size;\n        max = min = rhs;\n        is_unit\
    \ = false;\n        return *this;\n    }\n};\n\ntemplate <class S> constexpr MaxMinSum<S>\
    \ MaxMinSumOp(MaxMinSum<S> l, MaxMinSum<S> r) {\n    if (l.is_unit) return r;\n\
    \    if (r.is_unit) return l;\n    l.sum += r.sum;\n    l.size += r.size;\n  \
    \  l.max = std::max(l.max, r.max);\n    l.min = std::min(l.min, r.min);\n    return\
    \ l;\n}\n\ntemplate <class S> MaxMinSum<S> MaxMinSumUnit() {\n    constexpr static\
    \ MaxMinSum<S> e = MaxMinSum<S>();\n    return e;\n}\n\n} // namespace monoid\n\
    \ntemplate <class S, class... Args>\nstd::vector<monoid::MaxMinSum<S>> GetVecMaxMinSum(int\
    \ n, Args... args) {\n    return std::vector<monoid::MaxMinSum<S>>(n, monoid::MaxMinSum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::MaxMinSum<S>>>\n\
    GetVecMaxMinSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::MaxMinSum<S>>>(h,\
    \ GetVecMaxMinSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg.hpp\"\
    \n\n\n\n#include <cassert>\n#include <functional>\n#line 7 \"segment_tree/seg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegTree\
    \ {\n  public:\n    SegTree() : SegTree(0) {}\n\n    SegTree(int n) : SegTree(std::vector<S>(n,\
    \ e())) {}\n\n    template <class... Args>\n    SegTree(int n, Args... args) :\
    \ SegTree(std::vector<S>(n, S(args...))){};\n\n    SegTree(const std::vector<S>\
    \ &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<S>(2 * size,\
    \ e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    using Monoid =\
    \ S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit()\
    \ { return e(); }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    template <class... Args> void emplace_set(int\
    \ p, Args... args) { set(p, S(args...)); }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr\
    \ = e();\n        l += size;\n        r += size;\n\n        while (l < r) {\n\
    \            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    // return r\
    \ s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true\n    // r = n\
    \ or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template <bool (*f)(S)> int\
    \ max_right(int l) {\n        return max_right(l, [](S x) { return f(x); });\n\
    \    }\n\n    template <class F> int max_right(int l, F f) {\n        assert(0\
    \ <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // return l\
    \ s.t.\n    // l = r or f(op(a[l], a[l], ..., a[r-1]))   == true\n    // l = 0\
    \ or f(op(a[l-1], a[l], ..., a[r-1])) == false\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace kk2\n\n\n#line 6 \"segment_tree/utility/max_min_sum_seg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S>\nusing MaxMinSumSeg =\n    SegTree<monoid::MaxMinSum<S>,\
    \ monoid::MaxMinSumOp<S>, monoid::MaxMinSumUnit<S>>;\n\n} // namespace kk2\n\n\
    \n"
  code: "#ifndef SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP\n#define SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP\
    \ 1\n\n#include \"../../math/monoid/max_min_sum.hpp\"\n#include \"../seg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S>\nusing MaxMinSumSeg =\n    SegTree<monoid::MaxMinSum<S>,\
    \ monoid::MaxMinSumOp<S>, monoid::MaxMinSumUnit<S>>;\n\n} // namespace kk2\n\n\
    #endif // SEGMNET_TREE_UTILITY_MAX_MIN_SUM_HPP\n"
  dependsOn:
  - math/monoid/max_min_sum.hpp
  - segment_tree/seg.hpp
  isVerificationFile: false
  path: segment_tree/utility/max_min_sum_seg.hpp
  requiredBy: []
  timestamp: '2024-10-29 13:49:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/max_min_sum_seg.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/max_min_sum_seg.hpp
- /library/segment_tree/utility/max_min_sum_seg.hpp.html
title: segment_tree/utility/max_min_sum_seg.hpp
---
