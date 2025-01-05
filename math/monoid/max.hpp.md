---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/addmax.hpp
    title: segment_tree/utility/addmax.hpp
  - icon: ':warning:'
    path: segment_tree/utility/maxseg.hpp
    title: segment_tree/utility/maxseg.hpp
  - icon: ':warning:'
    path: segment_tree/utility/maxseg2d.hpp
    title: segment_tree/utility/maxseg2d.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatemax.hpp
    title: segment_tree/utility/updatemax.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/max.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate\
    \ <class S> struct Max {\n    S a;\n    bool minf;\n\n    constexpr Max() : a(S()),\
    \ minf(true) {}\n\n    constexpr Max(S a_, bool minf_ = false) : a(a_), minf(minf_)\
    \ {}\n\n    operator S() const { return a; }\n\n    template <class OStream>\n\
    \    friend OStream &operator<<(OStream &os, const Max &max) {\n        if (max.minf)\
    \ os << \"minf\";\n        else os << max.a;\n        return os;\n    }\n\n  \
    \  template <class IStream>\n    friend IStream &operator>>(IStream &is, Max &max)\
    \ {\n        is >> max.a;\n        max.minf = false;\n        return is;\n   \
    \ }\n\n    constexpr Max &operator=(const S &rhs) {\n        a = rhs;\n      \
    \  minf = false;\n        return *this;\n    }\n\n    constexpr Max &add(const\
    \ S &rhs) {\n        if (minf) return *this;\n        a += rhs;\n        return\
    \ *this;\n    }\n\n    constexpr Max &update(const S &rhs) {\n        a = rhs;\n\
    \        minf = false;\n        return *this;\n    }\n\n    constexpr bool is_minf()\
    \ { return minf; }\n};\n\ntemplate <class S> constexpr Max<S> MaxOp(Max<S> l,\
    \ Max<S> r) {\n    if (r.minf) return l;\n    if (l.minf) return r;\n    l.a =\
    \ std::max(l.a, r.a);\n    return l;\n}\n\ntemplate <class S> Max<S> MaxUnit()\
    \ {\n    constexpr static Max<S> e = Max<S>();\n    return e;\n}\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nstd::vector<monoid::Max<S>> GetVecMax(int\
    \ n, Args... args) {\n    return std::vector<monoid::Max<S>>(n, monoid::Max<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Max<S>>>\
    \ GetVecMax2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Max<S>>>(h,\
    \ GetVecMax<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MONOID_MAX_HPP\n#define KK2_MATH_MONOID_MAX_HPP 1\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S> struct Max {\n    S a;\n    bool minf;\n\n  \
    \  constexpr Max() : a(S()), minf(true) {}\n\n    constexpr Max(S a_, bool minf_\
    \ = false) : a(a_), minf(minf_) {}\n\n    operator S() const { return a; }\n\n\
    \    template <class OStream>\n    friend OStream &operator<<(OStream &os, const\
    \ Max &max) {\n        if (max.minf) os << \"minf\";\n        else os << max.a;\n\
    \        return os;\n    }\n\n    template <class IStream>\n    friend IStream\
    \ &operator>>(IStream &is, Max &max) {\n        is >> max.a;\n        max.minf\
    \ = false;\n        return is;\n    }\n\n    constexpr Max &operator=(const S\
    \ &rhs) {\n        a = rhs;\n        minf = false;\n        return *this;\n  \
    \  }\n\n    constexpr Max &add(const S &rhs) {\n        if (minf) return *this;\n\
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
    \ GetVecMax<S>(w, args...));\n}\n\n} // namespace kk2\n\n#endif // MATH_MONOID_MAX_H\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/max.hpp
  requiredBy:
  - segment_tree/utility/updatemax.hpp
  - segment_tree/utility/maxseg2d.hpp
  - segment_tree/utility/addmax.hpp
  - segment_tree/utility/maxseg.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/max.hpp
layout: document
redirect_from:
- /library/math/monoid/max.hpp
- /library/math/monoid/max.hpp.html
title: math/monoid/max.hpp
---
