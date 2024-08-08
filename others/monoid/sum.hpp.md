---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/addsum.hpp
    title: segment_tree/utility/addsum.hpp
  - icon: ':warning:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  - icon: ':warning:'
    path: segment_tree/utility/sumseg.hpp
    title: segment_tree/utility/sumseg.hpp
  - icon: ':warning:'
    path: segment_tree/utility/updatesum.hpp
    title: segment_tree/utility/updatesum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/monoid/sum.hpp\"\n\n\n\nnamespace monoid {\n\ntemplate\
    \ <class S>\nstruct Sum {\n    S a, size;\n    Sum() : a(0), size(0) {}\n    Sum(S\
    \ a, S size = 1) : a(a), size(size) {}\n    operator S() const { return a; }\n\
    \    friend ostream& operator<<(ostream& os, const Sum& sum) {\n        os <<\
    \ sum.a;\n        return os;\n    }\n    friend istream& operator>>(istream& is,\
    \ Sum& sum) {\n        is >> sum.a;\n        sum.size = 1;\n        return is;\n\
    \    }\n    Sum& operator=(const S& rhs) {\n        a = rhs;\n        size = 1;\n\
    \        return *this;\n    }\n\n    Sum& add(const S& rhs) {\n        a += rhs\
    \ * size;\n        return *this;\n    }\n    Sum& update(const S& rhs) {\n   \
    \     a = rhs * size;\n        return *this;\n    }\n    Sum& multiply(const S&\
    \ rhs) {\n        a *= rhs;\n        return *this;\n    }\n    Sum& op(const Sum&\
    \ rhs) {\n        a += rhs.a;\n        size += rhs.size;\n        return *this;\n\
    \    }\n};\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l, Sum<S> r) { return l.op(r);\
    \ }\n\ntemplate <class S>\nSum<S> SumUnit() { return Sum<S>(); }\n\n} // namespace\
    \ monoid\n\ntemplate <class S, class... Args>\nvector<monoid::Sum<S>> GetVecSum(int\
    \ n, Args... args) {\n    return vector<monoid::Sum<S>>(n, monoid::Sum<S>(args...));\n\
    }\n\n\n"
  code: "#ifndef OTHERS_MONOID_SUM_HPP\n#define OTHERS_MONOID_SUM_HPP 1\n\nnamespace\
    \ monoid {\n\ntemplate <class S>\nstruct Sum {\n    S a, size;\n    Sum() : a(0),\
    \ size(0) {}\n    Sum(S a, S size = 1) : a(a), size(size) {}\n    operator S()\
    \ const { return a; }\n    friend ostream& operator<<(ostream& os, const Sum&\
    \ sum) {\n        os << sum.a;\n        return os;\n    }\n    friend istream&\
    \ operator>>(istream& is, Sum& sum) {\n        is >> sum.a;\n        sum.size\
    \ = 1;\n        return is;\n    }\n    Sum& operator=(const S& rhs) {\n      \
    \  a = rhs;\n        size = 1;\n        return *this;\n    }\n\n    Sum& add(const\
    \ S& rhs) {\n        a += rhs * size;\n        return *this;\n    }\n    Sum&\
    \ update(const S& rhs) {\n        a = rhs * size;\n        return *this;\n   \
    \ }\n    Sum& multiply(const S& rhs) {\n        a *= rhs;\n        return *this;\n\
    \    }\n    Sum& op(const Sum& rhs) {\n        a += rhs.a;\n        size += rhs.size;\n\
    \        return *this;\n    }\n};\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l,\
    \ Sum<S> r) { return l.op(r); }\n\ntemplate <class S>\nSum<S> SumUnit() { return\
    \ Sum<S>(); }\n\n} // namespace monoid\n\ntemplate <class S, class... Args>\n\
    vector<monoid::Sum<S>> GetVecSum(int n, Args... args) {\n    return vector<monoid::Sum<S>>(n,\
    \ monoid::Sum<S>(args...));\n}\n\n#endif // OTHERS_MONOID_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: others/monoid/sum.hpp
  requiredBy:
  - segment_tree/utility/affinesum.hpp
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/sumseg.hpp
  - segment_tree/utility/addsum.hpp
  timestamp: '2024-07-07 23:50:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/monoid/sum.hpp
layout: document
redirect_from:
- /library/others/monoid/sum.hpp
- /library/others/monoid/sum.hpp.html
title: others/monoid/sum.hpp
---
