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
    path: segment_tree/utility/updatemin.hpp
    title: segment_tree/utility/updatemin.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/monoid/min.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S>\nstruct Min {\n    S a;\n    bool inf;\n    Min()\
    \ : a(S()), inf(true) {}\n    Min(S a_, bool inf_ = false) : a(a_), inf(inf_)\
    \ {}\n    operator S() const { return a; }\n    friend ostream& operator<<(ostream&\
    \ os, const Min& min) {\n        os << (min.inf ? \"inf\" : to_string(min.a));\n\
    \        return os;\n    }\n    friend istream& operator>>(istream& is, Min& min)\
    \ {\n        is >> min.a;\n        min.inf = false;\n        return is;\n    }\n\
    \    Min& operator=(const S& rhs) {\n        a = rhs;\n        inf = false;\n\
    \        return *this;\n    }\n\n    Min& add(const S& rhs) {\n        if (inf)\
    \ return *this;\n        a += rhs;\n        return *this;\n    }\n    Min& update(const\
    \ S& rhs) {\n        a = rhs;\n        inf = false;\n        return *this;\n \
    \   }\n    Min& op(const Min& rhs) {\n        if (rhs.inf) return *this;\n   \
    \     if (inf) return *this = rhs;\n        a = min(a, rhs.a);\n        return\
    \ *this;\n    }\n\n    bool is_inf() const { return inf; }\n};\n\ntemplate <class\
    \ S>\nMin<S> MinOp(Min<S> l, Min<S> r) { return l.op(r); }\n\ntemplate <class\
    \ S>\nMin<S> MinUnit() { return Min<S>(); }\n\n} // namespace monoid\n\ntemplate\
    \ <class S, class... Args>\nvector<monoid::Min<S>> GetVecMin(int n, Args... args)\
    \ {\n    return vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef OTHERS_MONOID_MIN_HPP\n#define OTHERS_MONOID_MIN_HPP 1\n\nnamespace\
    \ kk2 {\n\nnamespace monoid {\n\ntemplate <class S>\nstruct Min {\n    S a;\n\
    \    bool inf;\n    Min() : a(S()), inf(true) {}\n    Min(S a_, bool inf_ = false)\
    \ : a(a_), inf(inf_) {}\n    operator S() const { return a; }\n    friend ostream&\
    \ operator<<(ostream& os, const Min& min) {\n        os << (min.inf ? \"inf\"\
    \ : to_string(min.a));\n        return os;\n    }\n    friend istream& operator>>(istream&\
    \ is, Min& min) {\n        is >> min.a;\n        min.inf = false;\n        return\
    \ is;\n    }\n    Min& operator=(const S& rhs) {\n        a = rhs;\n        inf\
    \ = false;\n        return *this;\n    }\n\n    Min& add(const S& rhs) {\n   \
    \     if (inf) return *this;\n        a += rhs;\n        return *this;\n    }\n\
    \    Min& update(const S& rhs) {\n        a = rhs;\n        inf = false;\n   \
    \     return *this;\n    }\n    Min& op(const Min& rhs) {\n        if (rhs.inf)\
    \ return *this;\n        if (inf) return *this = rhs;\n        a = min(a, rhs.a);\n\
    \        return *this;\n    }\n\n    bool is_inf() const { return inf; }\n};\n\
    \ntemplate <class S>\nMin<S> MinOp(Min<S> l, Min<S> r) { return l.op(r); }\n\n\
    template <class S>\nMin<S> MinUnit() { return Min<S>(); }\n\n} // namespace monoid\n\
    \ntemplate <class S, class... Args>\nvector<monoid::Min<S>> GetVecMin(int n, Args...\
    \ args) {\n    return vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n}\n\
    \n} // namespace kk2\n\n#endif // OTHERS_MONOID_MIN_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/monoid/min.hpp
  requiredBy:
  - graph/tree/euler_tour.hpp
  - segment_tree/utility/updatemin.hpp
  - segment_tree/utility/addmin.hpp
  - segment_tree/utility/minseg.hpp
  - data_structure/static_rmq.hpp
  timestamp: '2024-08-29 22:36:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/monoid/min.hpp
layout: document
redirect_from:
- /library/others/monoid/min.hpp
- /library/others/monoid/min.hpp.html
title: others/monoid/min.hpp
---
