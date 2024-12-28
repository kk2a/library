---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/group/sum.hpp
    title: math/group/sum.hpp
  - icon: ':warning:'
    path: segment_tree/seg2d.hpp
    title: segment_tree/seg2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/utility/sumseg2d.hpp\"\n\n\n\n#line 1 \"math/group/sum.hpp\"\
    \n\n\n\n#include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace\
    \ group {\n\ntemplate <class S> struct Sum {\n    S a;\n    int size;\n\n    constexpr\
    \ Sum() : a(S{}), size(0) {}\n\n    constexpr Sum(S a, S size = 1) : a(a), size(size)\
    \ {}\n\n    operator S() const { return a; }\n\n    template <class OStream>\n\
    \    friend OStream &operator<<(OStream &os, const Sum &sum) {\n        os <<\
    \ sum.a;\n        return os;\n    }\n\n    template <class IStream>\n    friend\
    \ IStream &operator>>(IStream &is, Sum &sum) {\n        is >> sum.a;\n       \
    \ sum.size = 1;\n        return is;\n    }\n\n    constexpr Sum &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\
    \n    constexpr Sum &add(const S &rhs) {\n        a += rhs * size;\n        return\
    \ *this;\n    }\n\n    constexpr Sum &update(const S &rhs) {\n        a = rhs\
    \ * size;\n        return *this;\n    }\n\n    constexpr Sum &multiply(const S\
    \ &rhs) {\n        a *= rhs;\n        return *this;\n    }\n};\n\ntemplate <class\
    \ S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n    l.a += r.a;\n    l.size\
    \ += r.size;\n    return l;\n}\n\ntemplate <class S> Sum<S> SumUnit() {\n    constexpr\
    \ static Sum<S> e = Sum<S>();\n    return e;\n}\n\ntemplate <class S> constexpr\
    \ Sum<S> SumInv(Sum<S> x) {\n    x.a = -x.a;\n    x.size = -x.size;\n    return\
    \ x;\n}\n\n} // namespace group\n\ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>>\
    \ GetVecSum(int n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<group::Sum<S>>>\
    \ GetVecSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg2d.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"segment_tree/seg2d.hpp\"\n\nnamespace kk2\
    \ {\n\n// commutative monoid\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ SegTree2D {\n    SegTree2D() = default;\n\n    SegTree2D(int h_, int w_) : _h(h_),\
    \ _w(w_) {\n        size_h = size_w = 1;\n        while (size_h < _h) size_h <<=\
    \ 1;\n        while (size_w < _w) size_w <<= 1;\n        d = std::vector<std::vector<S>>(size_h\
    \ * 2, std::vector<S>(size_w * 2, e()));\n    }\n\n    template <class... Args>\n\
    \    SegTree2D(int h_, int w_, Args... args)\n        : SegTree2D(std::vector<std::vector<S>>(h_,\
    \ std::vector<S>(w_, S(args...)))) {}\n\n    SegTree2D(const std::vector<std::vector<S>>\
    \ &v) : _h(int(v.size())), _w(int(v[0].size())) {\n        size_h = size_w = 1;\n\
    \        while (size_h < _h) size_h <<= 1;\n        while (size_w < _w) size_w\
    \ <<= 1;\n        d = std::vector<std::vector<S>>(size_h * 2, std::vector<S>(size_w\
    \ * 2, e()));\n        for (int i = 0; i < _h; i++) {\n            for (int j\
    \ = 0; j < _w; j++) { d[i + size_h][j + size_w] = v[i][j]; }\n        }\n    \
    \    for (int j = size_w; j < size_w * 2; j++) {\n            for (int i = size_h\
    \ - 1; i; i--) updatei(i, j);\n        }\n        for (int i = 1; i < size_h *\
    \ 2; i++) {\n            for (int j = size_w - 1; j; j--) updatej(i, j);\n   \
    \     }\n    }\n\n    void set(int i, int j, const S &x) {\n        assert(0 <=\
    \ i && i < _h);\n        assert(0 <= j && j < _w);\n        i += size_h;\n   \
    \     j += size_w;\n        d[i][j] = x;\n        for (int ii = i >> 1; ii; ii\
    \ >>= 1) updatei(ii, j);\n        for (int ii = i; ii; ii >>= 1) {\n         \
    \   for (int jj = j >> 1; jj; jj >>= 1) updatej(ii, jj);\n        }\n    }\n\n\
    \    template <class... Args> void emplace_set(int i, int j, Args... args) { set(i,\
    \ j, S(args...)); }\n\n    S get(int i, int j) {\n        assert(0 <= i && i <\
    \ _h);\n        assert(0 <= j && j < _w);\n        return d[i + size_h][j + size_w];\n\
    \    }\n\n    S prod(int i1, int j1, int i2, int j2) {\n        assert(0 <= i1\
    \ && i1 <= i2 && i2 <= _h);\n        assert(0 <= j1 && j1 <= j2 && j2 <= _w);\n\
    \        if (i1 == i2 || j1 == j2) return e();\n        i1 += size_h;\n      \
    \  i2 += size_h;\n        j1 += size_w;\n        j2 += size_w;\n\n        S res\
    \ = e();\n        for (; i1 < i2; i1 >>= 1, i2 >>= 1) {\n            if (i1 &\
    \ 1) res = op(res, inner_prod(i1++, j1, j2));\n            if (i2 & 1) res = op(inner_prod(--i2,\
    \ j1, j2), res);\n        }\n        return res;\n    }\n\n  private:\n    int\
    \ _h, _w, size_h, size_w;\n    std::vector<std::vector<S>> d;\n\n    void updatei(int\
    \ i, int j) { d[i][j] = op(d[i * 2][j], d[i * 2 + 1][j]); }\n\n    void updatej(int\
    \ i, int j) { d[i][j] = op(d[i][j * 2], d[i][j * 2 + 1]); }\n\n    S inner_prod(int\
    \ i, int j1, int j2) {\n        S res = e();\n        for (; j1 < j2; j1 >>= 1,\
    \ j2 >>= 1) {\n            if (j1 & 1) res = op(res, d[i][j1++]);\n          \
    \  if (j2 & 1) res = op(d[i][--j2], res);\n        }\n        return res;\n  \
    \  }\n};\n\n} // namespace kk2\n\n\n#line 6 \"segment_tree/utility/sumseg2d.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S> using SumSeg2D = SegTree2D<group::Sum<S>,\
    \ group::SumOp<S>, group::SumUnit<S>>;\n\n} // namespace kk2\n\n\n"
  code: '#ifndef SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP

    #define SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP 1


    #include "../../math/group/sum.hpp"

    #include "../seg2d.hpp"


    namespace kk2 {


    template <class S> using SumSeg2D = SegTree2D<group::Sum<S>, group::SumOp<S>,
    group::SumUnit<S>>;


    } // namespace kk2


    #endif // SEGMENT_TREE_UTILITIY_SUMSEG2D_HPP

    '
  dependsOn:
  - math/group/sum.hpp
  - segment_tree/seg2d.hpp
  isVerificationFile: false
  path: segment_tree/utility/sumseg2d.hpp
  requiredBy: []
  timestamp: '2024-11-22 18:09:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/sumseg2d.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/sumseg2d.hpp
- /library/segment_tree/utility/sumseg2d.hpp.html
title: segment_tree/utility/sumseg2d.hpp
---
