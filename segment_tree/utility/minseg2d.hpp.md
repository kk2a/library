---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
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
  bundledCode: "#line 1 \"segment_tree/utility/minseg2d.hpp\"\n\n\n\n#line 1 \"math/monoid/min.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct\
    \ Min {\n    S a;\n    bool inf;\n\n    Min() : a(S()), inf(true) {}\n\n    Min(S\
    \ a_, bool inf_ = false) : a(a_), inf(inf_) {}\n\n    operator S() const { return\
    \ a; }\n\n    friend std::ostream &operator<<(std::ostream &os, const Min &min)\
    \ {\n        os << (min.inf ? \"inf\" : std::to_string(min.a));\n        return\
    \ os;\n    }\n\n    friend std::istream &operator>>(std::istream &is, Min &min)\
    \ {\n        is >> min.a;\n        min.inf = false;\n        return is;\n    }\n\
    \n    Min &operator=(const S &rhs) {\n        a = rhs;\n        inf = false;\n\
    \        return *this;\n    }\n\n    Min &add(const S &rhs) {\n        if (inf)\
    \ return *this;\n        a += rhs;\n        return *this;\n    }\n\n    Min &update(const\
    \ S &rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    Min &op(const Min &rhs) {\n        if (rhs.inf) return *this;\n \
    \       if (inf) return *this = rhs;\n        a = std::min(a, rhs.a);\n      \
    \  return *this;\n    }\n\n    bool is_inf() const { return inf; }\n};\n\ntemplate\
    \ <class S> Min<S> MinOp(Min<S> l, Min<S> r) {\n    return l.op(r);\n}\n\ntemplate\
    \ <class S> Min<S> MinUnit() {\n    return Min<S>();\n}\n\n} // namespace monoid\n\
    \ntemplate <class S, class... Args>\nstd::vector<monoid::Min<S>> GetVecMin(int\
    \ n, Args... args) {\n    return std::vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Min<S>>>\
    \ GetVecMin2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
    \ GetVecMin(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg2d.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"segment_tree/seg2d.hpp\"\n\nnamespace kk2\
    \ {\n\n// commutative monoid\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ SegTree2D {\n    SegTree2D() = default;\n\n    SegTree2D(int h_, int w_) : _h(h_),\
    \ _w(w_) {\n        size_h = size_w = 1;\n        while (size_h < _h) size_h <<=\
    \ 1;\n        while (size_w < _w) size_w <<= 1;\n        d = std::vector<std::vector<S>>(size_h\
    \ * 2,\n                                        std::vector<S>(size_w * 2, e()));\n\
    \    }\n\n    template <class... Args>\n    SegTree2D(int h_, int w_, Args...\
    \ args)\n        : SegTree2D(\n              std::vector<std::vector<S>>(h_, std::vector<S>(w_,\
    \ S(args...)))) {\n    }\n\n    SegTree2D(const std::vector<std::vector<S>> &v)\n\
    \        : _h(int(v.size())),\n          _w(int(v[0].size())) {\n        size_h\
    \ = size_w = 1;\n        while (size_h < _h) size_h <<= 1;\n        while (size_w\
    \ < _w) size_w <<= 1;\n        d = std::vector<std::vector<S>>(size_h * 2,\n \
    \                                       std::vector<S>(size_w * 2, e()));\n  \
    \      for (int i = 0; i < _h; i++) {\n            for (int j = 0; j < _w; j++)\
    \ {\n                d[i + size_h][j + size_w] = v[i][j];\n            }\n   \
    \     }\n        for (int j = size_w; j < size_w * 2; j++) {\n            for\
    \ (int i = size_h - 1; i; i--) updatei(i, j);\n        }\n        for (int i =\
    \ 1; i < size_h * 2; i++) {\n            for (int j = size_w - 1; j; j--) updatej(i,\
    \ j);\n        }\n    }\n\n    void set(int i, int j, const S &x) {\n        assert(0\
    \ <= i && i < _h);\n        assert(0 <= j && j < _w);\n        i += size_h;\n\
    \        j += size_w;\n        d[i][j] = x;\n        for (int ii = i >> 1; ii;\
    \ ii >>= 1) updatei(ii, j);\n        for (int ii = i; ii; ii >>= 1) {\n      \
    \      for (int jj = j >> 1; jj; jj >>= 1) updatej(ii, jj);\n        }\n    }\n\
    \n    template <class... Args> void emplace_set(int i, int j, Args... args) {\n\
    \        set(i, j, S(args...));\n    }\n\n    S get(int i, int j) {\n        assert(0\
    \ <= i && i < _h);\n        assert(0 <= j && j < _w);\n        return d[i + size_h][j\
    \ + size_w];\n    }\n\n    S prod(int i1, int i2, int j1, int j2) {\n        assert(0\
    \ <= i1 && i1 <= i2 && i2 <= _h);\n        assert(0 <= j1 && j1 <= j2 && j2 <=\
    \ _w);\n        if (i1 == i2 || j1 == j2) return e();\n        i1 += size_h;\n\
    \        i2 += size_h;\n        j1 += size_w;\n        j2 += size_w;\n\n     \
    \   S res = e();\n        for (; i1 < i2; i1 >>= 1, i2 >>= 1) {\n            if\
    \ (i1 & 1) res = op(res, inner_prod(i1++, j1, j2));\n            if (i2 & 1) res\
    \ = op(inner_prod(--i2, j1, j2), res);\n        }\n        return res;\n    }\n\
    \n  private:\n    int _h, _w, size_h, size_w;\n    std::vector<std::vector<S>>\
    \ d;\n\n    void updatei(int i, int j) { d[i][j] = op(d[i * 2][j], d[i * 2 + 1][j]);\
    \ }\n\n    void updatej(int i, int j) { d[i][j] = op(d[i][j * 2], d[i][j * 2 +\
    \ 1]); }\n\n    S inner_prod(int i, int j1, int j2) {\n        S res = e();\n\
    \        for (; j1 < j2; j1 >>= 1, j2 >>= 1) {\n            if (j1 & 1) res =\
    \ op(res, d[i][j1++]);\n            if (j2 & 1) res = op(d[i][--j2], res);\n \
    \       }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 6 \"\
    segment_tree/utility/minseg2d.hpp\"\n\nnamespace kk2 {\n\ntemplate <class S>\n\
    using MinSeg2D = SegTree2D<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;\n\
    \n} // namespace kk2\n\n\n"
  code: '#ifndef SEGMENT_TREE_UTILITY_MINSEG2D_HPP

    #define SEGMENT_TREE_UTILITY_MINSEG2D_HPP 1


    #include "../../math/monoid/min.hpp"

    #include "../seg2d.hpp"


    namespace kk2 {


    template <class S>

    using MinSeg2D = SegTree2D<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;


    } // namespace kk2


    #endif // SEGMENT_TREE_UTILITY_MINSEG2D_HPP

    '
  dependsOn:
  - math/monoid/min.hpp
  - segment_tree/seg2d.hpp
  isVerificationFile: false
  path: segment_tree/utility/minseg2d.hpp
  requiredBy: []
  timestamp: '2024-09-14 19:52:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/utility/minseg2d.hpp
layout: document
redirect_from:
- /library/segment_tree/utility/minseg2d.hpp
- /library/segment_tree/utility/minseg2d.hpp.html
title: segment_tree/utility/minseg2d.hpp
---
