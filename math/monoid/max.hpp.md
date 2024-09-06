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
    path: segment_tree/utility/updatemax.hpp
    title: segment_tree/utility/updatemax.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/monoid/max.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace\
    \ monoid {\n\ntemplate <class S>\nstruct Max {\n    S a;\n    bool minf;\n   \
    \ Max() : a(S()), minf(true) {}\n    Max (S a_, bool minf_ = false) : a(a_), minf(minf_)\
    \ {}\n    operator S() const { return a; }\n    friend ostream& operator<<(ostream&\
    \ os, const Max& max) {\n        os << (max.minf ? \"minf\" : to_string(max.a));\n\
    \        return os;\n    }\n    friend istream& operator>>(istream& is, Max& max)\
    \ {\n        is >> max.a;\n        max.minf = false;\n        return is;\n   \
    \ }\n    Max& operator=(const S& rhs) {\n        a = rhs;\n        minf = false;\n\
    \        return *this;\n    }\n\n    Max& add(const S& rhs) {\n        if (minf)\
    \ return *this;\n        a += rhs;\n        return *this;\n    }\n    Max& update(const\
    \ S& rhs) {\n        a = rhs;\n        minf = false;\n        return *this;\n\
    \    }\n    Max& op(const Max& rhs) {\n        if (rhs.minf) return *this;\n \
    \       if (minf) return *this = rhs;\n        a = max(a, rhs.a);\n        return\
    \ *this;\n    }\n\n    bool is_minf() const { return minf; }\n};\n\ntemplate <class\
    \ S>\nMax<S> MaxOp(Max<S> l, Max<S> r) { return l.op(r); }\n\ntemplate <class\
    \ S>\nMax<S> MaxUnit() { return Max<S>(); }\n\n} // namespace monoid\n\ntemplate\
    \ <class S, class... Args>\nvector<monoid::Max<S>> GetVecMax(int n, Args... args)\
    \ {\n    return vector<monoid::Max<S>>(n, monoid::Max<S>(args...));\n}\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef MATH_MONOID_MAX_HPP\n#define MATH_MONOID_MAX_HPP 1\n\nnamespace kk2\
    \ {\n\nnamespace monoid {\n\ntemplate <class S>\nstruct Max {\n    S a;\n    bool\
    \ minf;\n    Max() : a(S()), minf(true) {}\n    Max (S a_, bool minf_ = false)\
    \ : a(a_), minf(minf_) {}\n    operator S() const { return a; }\n    friend ostream&\
    \ operator<<(ostream& os, const Max& max) {\n        os << (max.minf ? \"minf\"\
    \ : to_string(max.a));\n        return os;\n    }\n    friend istream& operator>>(istream&\
    \ is, Max& max) {\n        is >> max.a;\n        max.minf = false;\n        return\
    \ is;\n    }\n    Max& operator=(const S& rhs) {\n        a = rhs;\n        minf\
    \ = false;\n        return *this;\n    }\n\n    Max& add(const S& rhs) {\n   \
    \     if (minf) return *this;\n        a += rhs;\n        return *this;\n    }\n\
    \    Max& update(const S& rhs) {\n        a = rhs;\n        minf = false;\n  \
    \      return *this;\n    }\n    Max& op(const Max& rhs) {\n        if (rhs.minf)\
    \ return *this;\n        if (minf) return *this = rhs;\n        a = max(a, rhs.a);\n\
    \        return *this;\n    }\n\n    bool is_minf() const { return minf; }\n};\n\
    \ntemplate <class S>\nMax<S> MaxOp(Max<S> l, Max<S> r) { return l.op(r); }\n\n\
    template <class S>\nMax<S> MaxUnit() { return Max<S>(); }\n\n} // namespace monoid\n\
    \ntemplate <class S, class... Args>\nvector<monoid::Max<S>> GetVecMax(int n, Args...\
    \ args) {\n    return vector<monoid::Max<S>>(n, monoid::Max<S>(args...));\n}\n\
    \n} // namespace kk2\n\n#endif // MATH_MONOID_MAX_H\n"
  dependsOn: []
  isVerificationFile: false
  path: math/monoid/max.hpp
  requiredBy:
  - segment_tree/utility/maxseg.hpp
  - segment_tree/utility/updatemax.hpp
  - segment_tree/utility/addmax.hpp
  timestamp: '2024-08-29 23:32:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monoid/max.hpp
layout: document
redirect_from:
- /library/math/monoid/max.hpp
- /library/math/monoid/max.hpp.html
title: math/monoid/max.hpp
---