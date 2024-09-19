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
    \ <iostream>\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S> struct Min {\n    S a;\n    bool inf;\n\n   \
    \ Min() : a(S()), inf(true) {}\n\n    Min(S a_, bool inf_ = false) : a(a_), inf(inf_)\
    \ {}\n\n    operator S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Min &min) {\n        os << (min.inf ? \"inf\" : std::to_string(min.a));\n\
    \        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Min &min) {\n        is >> min.a;\n        min.inf = false;\n        return\
    \ is;\n    }\n\n    Min &operator=(const S &rhs) {\n        a = rhs;\n       \
    \ inf = false;\n        return *this;\n    }\n\n    Min &add(const S &rhs) {\n\
    \        if (inf) return *this;\n        a += rhs;\n        return *this;\n  \
    \  }\n\n    Min &update(const S &rhs) {\n        a = rhs;\n        inf = false;\n\
    \        return *this;\n    }\n\n    Min &op(const Min &rhs) {\n        if (rhs.inf)\
    \ return *this;\n        if (inf) return *this = rhs;\n        a = std::min(a,\
    \ rhs.a);\n        return *this;\n    }\n\n    bool is_inf() const { return inf;\
    \ }\n};\n\ntemplate <class S> Min<S> MinOp(Min<S> l, Min<S> r) {\n    return l.op(r);\n\
    }\n\ntemplate <class S> Min<S> MinUnit() {\n    return Min<S>();\n}\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nstd::vector<monoid::Min<S>> GetVecMin(int\
    \ n, Args... args) {\n    return std::vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Min<S>>>\
    \ GetVecMin2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
    \ GetVecMin(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_MONOID_MIN_HPP\n#define MATH_MONOID_MIN_HPP 1\n\n#include <algorithm>\n\
    #include <iostream>\n#include <string>\n#include <vector>\n\nnamespace kk2 {\n\
    \nnamespace monoid {\n\ntemplate <class S> struct Min {\n    S a;\n    bool inf;\n\
    \n    Min() : a(S()), inf(true) {}\n\n    Min(S a_, bool inf_ = false) : a(a_),\
    \ inf(inf_) {}\n\n    operator S() const { return a; }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Min &min) {\n        os << (min.inf ? \"\
    inf\" : std::to_string(min.a));\n        return os;\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, Min &min) {\n        is >> min.a;\n        min.inf\
    \ = false;\n        return is;\n    }\n\n    Min &operator=(const S &rhs) {\n\
    \        a = rhs;\n        inf = false;\n        return *this;\n    }\n\n    Min\
    \ &add(const S &rhs) {\n        if (inf) return *this;\n        a += rhs;\n  \
    \      return *this;\n    }\n\n    Min &update(const S &rhs) {\n        a = rhs;\n\
    \        inf = false;\n        return *this;\n    }\n\n    Min &op(const Min &rhs)\
    \ {\n        if (rhs.inf) return *this;\n        if (inf) return *this = rhs;\n\
    \        a = std::min(a, rhs.a);\n        return *this;\n    }\n\n    bool is_inf()\
    \ const { return inf; }\n};\n\ntemplate <class S> Min<S> MinOp(Min<S> l, Min<S>\
    \ r) {\n    return l.op(r);\n}\n\ntemplate <class S> Min<S> MinUnit() {\n    return\
    \ Min<S>();\n}\n\n} // namespace monoid\n\ntemplate <class S, class... Args>\n\
    std::vector<monoid::Min<S>> GetVecMin(int n, Args... args) {\n    return std::vector<monoid::Min<S>>(n,\
    \ monoid::Min<S>(args...));\n}\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Min<S>>>\
    \ GetVecMin2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
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
  timestamp: '2024-09-14 19:52:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/min.hpp
layout: document
redirect_from:
- /library/math/monoid/min.hpp
- /library/math/monoid/min.hpp.html
title: math/monoid/min.hpp
---
