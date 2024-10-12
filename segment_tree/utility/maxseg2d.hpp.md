---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
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
  bundledCode: "#line 1 \"segment_tree/utility/maxseg2d.hpp\"\n\n\n\n#line 1 \"math/monoid/max.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct Max {\n    S a;\n \
    \   bool minf;\n\n    constexpr Max() : a(S()), minf(true) {}\n\n    constexpr\
    \ Max(S a_, bool minf_ = false) : a(a_), minf(minf_) {}\n\n    operator S() const\
    \ { return a; }\n\n    template <class OStream>\n    friend OStream &operator<<(OStream\
    \ &os, const Max &max) {\n        if (max.minf) os << \"minf\";\n        else\
    \ os << max.a;\n        return os;\n    }\n\n    template <class IStream>\n  \
    \  friend IStream &operator>>(IStream &is, Max &max) {\n        is >> max.a;\n\
    \        max.minf = false;\n        return is;\n    }\n\n    constexpr Max &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        minf = false;\n        return *this;\n\
    \    }\n\n    constexpr Max &add(const S &rhs) {\n        if (minf) return *this;\n\
    \        a += rhs;\n        return *this;\n    }\n\n    constexpr Max &update(const\
    \ S &rhs) {\n        a = rhs;\n        minf = false;\n        return *this;\n\
    \    }\n\n    constexpr bool is_minf() { return minf; }\n};\n\ntemplate <class\
    \ S> constexpr Max<S> MaxOp(Max<S> l, Max<S> r) {\n    if (r.minf) return l;\n\
    \    if (l.minf) return r;\n    l.a = std::max(l.a, r.a);\n    return l;\n}\n\n\
    template <class S> Max<S> MaxUnit() {\n    constexpr static Max<S> e = Max<S>();\n\
    \    return e;\n}\n\n} // namespace monoid\n\ntemplate <class S, class... Args>\n\
    std::vector<monoid::Max<S>> GetVecMax(int n, Args... args) {\n    return std::vector<monoid::Max<S>>(n,\
    \ monoid::Max<S>(args...));\n}\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Max<S>>>\
    \ GetVecMax2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Max<S>>>(h,\
    \ GetVecMax<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg2d.hpp\"\
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
    \    }\n\n    S prod(int i1, int i2, int j1, int j2) {\n        assert(0 <= i1\
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
    \  }\n};\n\n} // namespace kk2\n\n\n#line 6 \"segment_tree/utility/maxseg2d.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S> using MaxSeg2D = SegTree2D<monoid::Max<S>,\
    \ monoid::MaxOp<S>, monoid::MaxUnit<S>>;\n\n} // namespace kk2\n\n\n"
  code: '#ifndef SEGMENT_TREE_UTILITY_MAXSEG2D_HPP

    #define SEGMENT_TREE_UTILITY_MAXSEG2D_HPP 1


    #include "../../math/monoid/max.hpp"

    #include "../seg2d.hpp"


    namespace kk2 {


    template <class S> using MaxSeg2D = SegTree2D<monoid::Max<S>, monoid::MaxOp<S>,
    monoid::MaxUnit<S>>;


    } // namespace kk2


    #endif // SEGMENT_TREE_UTILITY_MAXSEG2D_HPP

    '
  dependsOn:
  - math/monoid/max.hpp
  - segment_tree/seg2d.hpp
  isVerificationFile: false
  path: segment_tree/utility/maxseg2d.hpp
  requiredBy: []
  timestamp: '2024-10-13 03:33:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/maxseg2d.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/maxseg2d.hpp
- /library/segment_tree/utility/maxseg2d.hpp.html
title: segment_tree/utility/maxseg2d.hpp
---
