---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_static_rmq.test.cpp
    title: verify/yosupo_ds/ds_static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/static_rmq.hpp\"\n\n\n\n#line 1 \"math/monoid/min.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct Min {\n    S a;\n \
    \   bool inf;\n\n    constexpr Min() : a(S()), inf(true) {}\n\n    constexpr Min(S\
    \ a_, bool inf_ = false) : a(a_), inf(inf_) {}\n\n    operator S() const { return\
    \ a; }\n\n    template <class OStream>\n    friend OStream &operator<<(OStream\
    \ &os, const Min &min) {\n        if (min.inf) os << \"inf\";\n        else os\
    \ << min.a;\n        return os;\n    }\n\n    template <class IStream>\n    friend\
    \ IStream &operator>>(IStream &is, Min &min) {\n        is >> min.a;\n       \
    \ min.inf = false;\n        return is;\n    }\n\n    constexpr Min &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    constexpr Min &add(const S &rhs) {\n        if (inf) return *this;\n\
    \        a += rhs;\n        return *this;\n    }\n\n    constexpr Min &update(const\
    \ S &rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    constexpr bool is_inf() { return inf; }\n};\n\ntemplate <class S>\
    \ constexpr Min<S> MinOp(Min<S> l, Min<S> r) {\n    if (r.inf) return l;\n   \
    \ if (l.inf) return r;\n    l.a = std::min(l.a, r.a);\n    return l;\n}\n\ntemplate\
    \ <class S> Min<S> MinUnit() {\n    constexpr static Min<S> e = Min<S>();\n  \
    \  return e;\n}\n\n} // namespace monoid\n\ntemplate <class S, class... Args>\n\
    std::vector<monoid::Min<S>> GetVecMin(int n, Args... args) {\n    return std::vector<monoid::Min<S>>(n,\
    \ monoid::Min<S>(args...));\n}\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Min<S>>>\
    \ GetVecMin2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
    \ GetVecMin(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"data_structure/sparse_table.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"data_structure/sparse_table.hpp\"\n\nnamespace\
    \ kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct SparseTable {\n    SparseTable() = default;\n\n    SparseTable(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1\
    \ << log) < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n \
    \       for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        for (int i =\
    \ 1; i <= log; i++) {\n            for (int j = 0; j + (1 << i) <= _n; j++) {\n\
    \                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n\n    using Monoid = S;\n\n    static\
    \ S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit() { return e();\
    \ }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r\
    \ <= _n);\n        if (l == r) return e();\n        int i = 31 ^ __builtin_clz(r\
    \ - l);\n        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n  \
    \  S get(int i) const {\n        assert(0 <= i && i < _n);\n        return table[0][i];\n\
    \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
    \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
    \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        int left = l - 1, right = _n;\n    \
    \    while (right - left > 1) {\n            int mid = (left + right) >> 1;\n\
    \            if (f(prod(l, mid))) left = mid;\n            else right = mid;\n\
    \        }\n        return right;\n    }\n\n    // return l s.t.\n    // l = r\
    \ or f(op(a[l], a[l+1], ..., a[r-1])) == false\n    // l = 0 or f(op(a[l], a[l+1],\
    \ ..., a[r]))   == true\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        int left = -1,\
    \ right = r;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n            else\
    \ left = mid;\n        }\n        return right;\n    }\n\n  private:\n    int\
    \ _n, log;\n    std::vector<std::vector<S>> table;\n};\n\n} // namespace kk2\n\
    \n\n#line 6 \"data_structure/static_rmq.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S>\nusing StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;\n\
    \n} // namespace kk2\n\n\n"
  code: '#ifndef DATA_STRUCTURE_STATIC_RMQ_HPP

    #define DATA_STRUCTURE_STATIC_RMQ_HPP 1


    #include "../math/monoid/min.hpp"

    #include "sparse_table.hpp"


    namespace kk2 {


    template <class S>

    using StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;


    } // namespace kk2


    #endif // DATA_STRUCTURE_STATIC_RMQ_HPP

    '
  dependsOn:
  - math/monoid/min.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: data_structure/static_rmq.hpp
  requiredBy:
  - graph/tree/euler_tour.hpp
  timestamp: '2024-10-13 03:33:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_rmq.test.cpp
documentation_of: data_structure/static_rmq.hpp
layout: document
redirect_from:
- /library/data_structure/static_rmq.hpp
- /library/data_structure/static_rmq.hpp.html
title: data_structure/static_rmq.hpp
---
