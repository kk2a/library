---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/addsum.hpp
    title: segment_tree/utility/addsum.hpp
  - icon: ':x:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/utility/sumseg.hpp
    title: segment_tree/utility/sumseg.hpp
  - icon: ':warning:'
    path: segment_tree/utility/sumseg2d.hpp
    title: segment_tree/utility/sumseg2d.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatesum.hpp
    title: segment_tree/utility/updatesum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
    title: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/group/sum.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S> struct\
    \ Sum {\n    S a;\n    int size;\n\n    constexpr Sum() : a(S{}), size(0) {}\n\
    \n    constexpr Sum(S a, S size = 1) : a(a), size(size) {}\n\n    operator S()\
    \ const { return a; }\n\n    template <class OStream>\n    friend OStream &operator<<(OStream\
    \ &os, const Sum &sum) {\n        os << sum.a;\n        return os;\n    }\n\n\
    \    template <class IStream>\n    friend IStream &operator>>(IStream &is, Sum\
    \ &sum) {\n        is >> sum.a;\n        sum.size = 1;\n        return is;\n \
    \   }\n\n    constexpr Sum &operator=(const S &rhs) {\n        a = rhs;\n    \
    \    size = 1;\n        return *this;\n    }\n\n    constexpr Sum &add(const S\
    \ &rhs) {\n        a += rhs * size;\n        return *this;\n    }\n\n    constexpr\
    \ Sum &update(const S &rhs) {\n        a = rhs * size;\n        return *this;\n\
    \    }\n\n    constexpr Sum &multiply(const S &rhs) {\n        a *= rhs;\n   \
    \     return *this;\n    }\n};\n\ntemplate <class S> constexpr Sum<S> SumOp(Sum<S>\
    \ l, Sum<S> r) {\n    l.a += r.a;\n    l.size += r.size;\n    return l;\n}\n\n\
    template <class S> Sum<S> SumUnit() {\n    constexpr static Sum<S> e = Sum<S>();\n\
    \    return e;\n}\n\ntemplate <class S> constexpr Sum<S> SumInv(Sum<S> x) {\n\
    \    x.a = -x.a;\n    x.size = -x.size;\n    return x;\n}\n\n} // namespace group\n\
    \ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>> GetVecSum(int\
    \ n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<group::Sum<S>>>\
    \ GetVecSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_GROUP_SUM_HPP\n#define KK2_MATH_GROUP_SUM_HPP 1\n\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate\
    \ <class S> struct Sum {\n    S a;\n    int size;\n\n    constexpr Sum() : a(S{}),\
    \ size(0) {}\n\n    constexpr Sum(S a, S size = 1) : a(a), size(size) {}\n\n \
    \   operator S() const { return a; }\n\n    template <class OStream>\n    friend\
    \ OStream &operator<<(OStream &os, const Sum &sum) {\n        os << sum.a;\n \
    \       return os;\n    }\n\n    template <class IStream>\n    friend IStream\
    \ &operator>>(IStream &is, Sum &sum) {\n        is >> sum.a;\n        sum.size\
    \ = 1;\n        return is;\n    }\n\n    constexpr Sum &operator=(const S &rhs)\
    \ {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\n   \
    \ constexpr Sum &add(const S &rhs) {\n        a += rhs * size;\n        return\
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
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_GROUP_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/group/sum.hpp
  requiredBy:
  - segment_tree/utility/sumseg.hpp
  - segment_tree/utility/sumseg2d.hpp
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/affinesum.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_point_add_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
documentation_of: math/group/sum.hpp
layout: document
redirect_from:
- /library/math/group/sum.hpp
- /library/math/group/sum.hpp.html
title: math/group/sum.hpp
---
