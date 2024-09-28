---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':warning:'
    path: graph/tree/euler_tour.hpp
    title: graph/tree/euler_tour.hpp
  - icon: ':warning:'
    path: segment_tree/utility/addmin.hpp
    title: segment_tree/utility/addmin.hpp
  - icon: ':warning:'
    path: segment_tree/utility/minseg.hpp
    title: segment_tree/utility/minseg.hpp
  - icon: ':warning:'
    path: segment_tree/utility/minseg2d.hpp
    title: segment_tree/utility/minseg2d.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatemin.hpp
    title: segment_tree/utility/updatemin.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/min.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate\
    \ <class S> struct Min {\n    S a;\n    bool inf;\n\n    constexpr Min() : a(S()),\
    \ inf(true) {}\n\n    constexpr Min(S a_, bool inf_ = false) : a(a_), inf(inf_)\
    \ {}\n\n    operator S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Min &min) {\n        if (min.inf) os << \"inf\";\n        else os\
    \ << min.a;\n        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Min &min) {\n        is >> min.a;\n        min.inf = false;\n        return\
    \ is;\n    }\n\n    constexpr Min &operator=(const S &rhs) {\n        a = rhs;\n\
    \        inf = false;\n        return *this;\n    }\n\n    constexpr Min &add(const\
    \ S &rhs) {\n        if (inf) return *this;\n        a += rhs;\n        return\
    \ *this;\n    }\n\n    constexpr Min &update(const S &rhs) {\n        a = rhs;\n\
    \        inf = false;\n        return *this;\n    }\n\n    constexpr bool is_inf()\
    \ { return inf; }\n};\n\ntemplate <class S> constexpr Min<S> MinOp(Min<S> l, Min<S>\
    \ r) {\n    if (r.inf) return l;\n    if (l.inf) return r;\n    l.a = std::min(l.a,\
    \ r.a);\n    return l;\n}\n\ntemplate <class S> constexpr Min<S> MinUnit() {\n\
    \    constexpr static Min<S> e = Min<S>();\n    return e;\n}\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nconstexpr std::vector<monoid::Min<S>>\
    \ GetVecMin(int n, Args... args) {\n    return std::vector<monoid::Min<S>>(n,\
    \ monoid::Min<S>(args...));\n}\n\ntemplate <class S, class... Args>\nconstexpr\
    \ std::vector<std::vector<monoid::Min<S>>>\nGetVecMin2D(int h, int w, Args...\
    \ args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h, GetVecMin(w,\
    \ args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_MONOID_MIN_HPP\n#define MATH_MONOID_MIN_HPP 1\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid\
    \ {\n\ntemplate <class S> struct Min {\n    S a;\n    bool inf;\n\n    constexpr\
    \ Min() : a(S()), inf(true) {}\n\n    constexpr Min(S a_, bool inf_ = false) :\
    \ a(a_), inf(inf_) {}\n\n    operator S() const { return a; }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Min &min) {\n        if (min.inf) os <<\
    \ \"inf\";\n        else os << min.a;\n        return os;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Min &min) {\n        is >> min.a;\n\
    \        min.inf = false;\n        return is;\n    }\n\n    constexpr Min &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    constexpr Min &add(const S &rhs) {\n        if (inf) return *this;\n\
    \        a += rhs;\n        return *this;\n    }\n\n    constexpr Min &update(const\
    \ S &rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n\n    constexpr bool is_inf() { return inf; }\n};\n\ntemplate <class S>\
    \ constexpr Min<S> MinOp(Min<S> l, Min<S> r) {\n    if (r.inf) return l;\n   \
    \ if (l.inf) return r;\n    l.a = std::min(l.a, r.a);\n    return l;\n}\n\ntemplate\
    \ <class S> constexpr Min<S> MinUnit() {\n    constexpr static Min<S> e = Min<S>();\n\
    \    return e;\n}\n\n} // namespace monoid\n\ntemplate <class S, class... Args>\n\
    constexpr std::vector<monoid::Min<S>> GetVecMin(int n, Args... args) {\n    return\
    \ std::vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n}\n\ntemplate <class\
    \ S, class... Args>\nconstexpr std::vector<std::vector<monoid::Min<S>>>\nGetVecMin2D(int\
    \ h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
    \ GetVecMin(w, args...));\n}\n\n} // namespace kk2\n\n#endif // MATH_MONOID_MIN_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/min.hpp
  requiredBy:
  - data_structure/static_rmq.hpp
  - graph/tree/euler_tour.hpp
  - segment_tree/utility/minseg.hpp
  - segment_tree/utility/minseg2d.hpp
  - segment_tree/utility/updatemin.hpp
  - segment_tree/utility/addmin.hpp
  timestamp: '2024-09-26 15:55:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/min.hpp
layout: document
redirect_from:
- /library/math/monoid/min.hpp
- /library/math/monoid/min.hpp.html
title: math/monoid/min.hpp
---
