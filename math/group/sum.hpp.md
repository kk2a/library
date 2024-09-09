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
  bundledCode: "#line 1 \"math/group/sum.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S>\nstruct\
    \ Sum {\n    S a, size;\n    Sum() : a(S()), size(0) {}\n    Sum(S a, S size =\
    \ 1) : a(a), size(size) {}\n    operator S() const { return a; }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Sum& sum) {\n        os << sum.a;\n     \
    \   return os;\n    }\n    friend std::istream& operator>>(std::istream& is, Sum&\
    \ sum) {\n        is >> sum.a;\n        sum.size = 1;\n        return is;\n  \
    \  }\n    Sum& operator=(const S& rhs) {\n        a = rhs;\n        size = 1;\n\
    \        return *this;\n    }\n\n    Sum& add(const S& rhs) {\n        a += rhs\
    \ * size;\n        return *this;\n    }\n    Sum& update(const S& rhs) {\n   \
    \     a = rhs * size;\n        return *this;\n    }\n    Sum& multiply(const S&\
    \ rhs) {\n        a *= rhs;\n        return *this;\n    }\n    Sum& op(const Sum&\
    \ rhs) {\n        a += rhs.a;\n        size += rhs.size;\n        return *this;\n\
    \    }\n};\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l, Sum<S> r) { return l.op(r);\
    \ }\n\ntemplate <class S>\nSum<S> SumUnit() { return Sum<S>(); }\n\ntemplate <class\
    \ S>\nSum<S> SumInv(Sum<S> x) { return Sum<S>(-x.a, -x.size); }\n\n} // namespace\
    \ group\n\ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>> GetVecSum(int\
    \ n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_GROUP_SUM_HPP\n#define MATH_GROUP_SUM_HPP 1\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S>\n\
    struct Sum {\n    S a, size;\n    Sum() : a(S()), size(0) {}\n    Sum(S a, S size\
    \ = 1) : a(a), size(size) {}\n    operator S() const { return a; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Sum& sum) {\n        os <<\
    \ sum.a;\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, Sum& sum) {\n        is >> sum.a;\n        sum.size = 1;\n        return\
    \ is;\n    }\n    Sum& operator=(const S& rhs) {\n        a = rhs;\n        size\
    \ = 1;\n        return *this;\n    }\n\n    Sum& add(const S& rhs) {\n       \
    \ a += rhs * size;\n        return *this;\n    }\n    Sum& update(const S& rhs)\
    \ {\n        a = rhs * size;\n        return *this;\n    }\n    Sum& multiply(const\
    \ S& rhs) {\n        a *= rhs;\n        return *this;\n    }\n    Sum& op(const\
    \ Sum& rhs) {\n        a += rhs.a;\n        size += rhs.size;\n        return\
    \ *this;\n    }\n};\n\ntemplate <class S>\nSum<S> SumOp(Sum<S> l, Sum<S> r) {\
    \ return l.op(r); }\n\ntemplate <class S>\nSum<S> SumUnit() { return Sum<S>();\
    \ }\n\ntemplate <class S>\nSum<S> SumInv(Sum<S> x) { return Sum<S>(-x.a, -x.size);\
    \ }\n\n} // namespace group\n\ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>>\
    \ GetVecSum(int n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\n} // namespace kk2\n\n#endif // MATH_GROUP_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/group/sum.hpp
  requiredBy:
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/affinesum.hpp
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/sumseg.hpp
  timestamp: '2024-09-10 07:56:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/group/sum.hpp
layout: document
redirect_from:
- /library/math/group/sum.hpp
- /library/math/group/sum.hpp.html
title: math/group/sum.hpp
---
