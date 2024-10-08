---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/add_max_min_sum.hpp
    title: segment_tree/utility/add_max_min_sum.hpp
  - icon: ':warning:'
    path: segment_tree/utility/max_min_sum_seg.hpp
    title: segment_tree/utility/max_min_sum_seg.hpp
  - icon: ':warning:'
    path: segment_tree/utility/update_max_min_sum.hpp
    title: segment_tree/utility/update_max_min_sum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/max_min_sum.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S> struct MaxMinSum {\n    S sum, max, min;\n    int size;\n\
    \    bool is_unit;\n\n    constexpr MaxMinSum() : sum(0), max(0), min(0), size(0),\
    \ is_unit(true) {}\n\n    constexpr MaxMinSum(S a, bool is_unit_ = false)\n  \
    \      : sum(a),\n          max(a),\n          min(a),\n          size(1),\n \
    \         is_unit(is_unit_) {}\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const MaxMinSum &maxminSum) {\n        os << maxminSum.sum << \" \" <<\
    \ maxminSum.max << \" \" << maxminSum.min;\n        return os;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, MaxMinSum &maxminSum) {\n       \
    \ S a;\n        is >> a;\n        maxminSum.sum = maxminSum.max = maxminSum.min\
    \ = a;\n        maxminSum.size = 1;\n        return is;\n    }\n\n    constexpr\
    \ MaxMinSum &operator=(const S &rhs) {\n        sum = max = min = rhs;\n     \
    \   size = 1;\n        is_unit = false;\n        return *this;\n    }\n\n    constexpr\
    \ MaxMinSum &add(const S &rhs) {\n        if (is_unit) return *this;\n       \
    \ sum += rhs * size;\n        max += rhs;\n        min += rhs;\n        return\
    \ *this;\n    }\n\n    constexpr MaxMinSum &update(const S &rhs) {\n        sum\
    \ = rhs * size;\n        max = min = rhs;\n        is_unit = false;\n        return\
    \ *this;\n    }\n};\n\ntemplate <class S> constexpr MaxMinSum<S> MaxMinSumOp(MaxMinSum<S>\
    \ l, MaxMinSum<S> r) {\n    if (l.is_unit) return r;\n    if (r.is_unit) return\
    \ l;\n    l.sum += r.sum;\n    l.size += r.size;\n    l.max = std::max(l.max,\
    \ r.max);\n    l.min = std::min(l.min, r.min);\n    return l;\n}\n\ntemplate <class\
    \ S> constexpr MaxMinSum<S> MaxMinSumUnit() {\n    constexpr static MaxMinSum<S>\
    \ e = MaxMinSum<S>();\n    return e;\n}\n\n} // namespace monoid\n\ntemplate <class\
    \ S, class... Args>\nstd::vector<monoid::MaxMinSum<S>> GetVecMaxMinSum(int n,\
    \ Args... args) {\n    return std::vector<monoid::MaxMinSum<S>>(n, monoid::MaxMinSum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::MaxMinSum<S>>>\n\
    GetVecMaxMinSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::MaxMinSum<S>>>(h,\
    \ GetVecMaxMinSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_MONOID_MAX_MIN_SUM_HPP\n#define MATH_MONOID_MAX_MIN_SUM_HPP\
    \ 1\n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S> struct MaxMinSum {\n    S\
    \ sum, max, min;\n    int size;\n    bool is_unit;\n\n    constexpr MaxMinSum()\
    \ : sum(0), max(0), min(0), size(0), is_unit(true) {}\n\n    constexpr MaxMinSum(S\
    \ a, bool is_unit_ = false)\n        : sum(a),\n          max(a),\n          min(a),\n\
    \          size(1),\n          is_unit(is_unit_) {}\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const MaxMinSum &maxminSum) {\n        os << maxminSum.sum\
    \ << \" \" << maxminSum.max << \" \" << maxminSum.min;\n        return os;\n \
    \   }\n\n    friend std::istream &operator>>(std::istream &is, MaxMinSum &maxminSum)\
    \ {\n        S a;\n        is >> a;\n        maxminSum.sum = maxminSum.max = maxminSum.min\
    \ = a;\n        maxminSum.size = 1;\n        return is;\n    }\n\n    constexpr\
    \ MaxMinSum &operator=(const S &rhs) {\n        sum = max = min = rhs;\n     \
    \   size = 1;\n        is_unit = false;\n        return *this;\n    }\n\n    constexpr\
    \ MaxMinSum &add(const S &rhs) {\n        if (is_unit) return *this;\n       \
    \ sum += rhs * size;\n        max += rhs;\n        min += rhs;\n        return\
    \ *this;\n    }\n\n    constexpr MaxMinSum &update(const S &rhs) {\n        sum\
    \ = rhs * size;\n        max = min = rhs;\n        is_unit = false;\n        return\
    \ *this;\n    }\n};\n\ntemplate <class S> constexpr MaxMinSum<S> MaxMinSumOp(MaxMinSum<S>\
    \ l, MaxMinSum<S> r) {\n    if (l.is_unit) return r;\n    if (r.is_unit) return\
    \ l;\n    l.sum += r.sum;\n    l.size += r.size;\n    l.max = std::max(l.max,\
    \ r.max);\n    l.min = std::min(l.min, r.min);\n    return l;\n}\n\ntemplate <class\
    \ S> constexpr MaxMinSum<S> MaxMinSumUnit() {\n    constexpr static MaxMinSum<S>\
    \ e = MaxMinSum<S>();\n    return e;\n}\n\n} // namespace monoid\n\ntemplate <class\
    \ S, class... Args>\nstd::vector<monoid::MaxMinSum<S>> GetVecMaxMinSum(int n,\
    \ Args... args) {\n    return std::vector<monoid::MaxMinSum<S>>(n, monoid::MaxMinSum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::MaxMinSum<S>>>\n\
    GetVecMaxMinSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::MaxMinSum<S>>>(h,\
    \ GetVecMaxMinSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n#endif // MATH_MONOID_MAX_MIN_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/max_min_sum.hpp
  requiredBy:
  - segment_tree/utility/max_min_sum_seg.hpp
  - segment_tree/utility/add_max_min_sum.hpp
  - segment_tree/utility/update_max_min_sum.hpp
  timestamp: '2024-10-06 18:26:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/max_min_sum.hpp
layout: document
redirect_from:
- /library/math/monoid/max_min_sum.hpp
- /library/math/monoid/max_min_sum.hpp.html
title: math/monoid/max_min_sum.hpp
---
