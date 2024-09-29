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
    path: segment_tree/utility/sumseg2d.hpp
    title: segment_tree/utility/sumseg2d.hpp
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
    \ <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S> struct\
    \ Sum {\n    S a;\n    int size;\n\n    constexpr Sum() : a(S()), size(0) {}\n\
    \n    constexpr Sum(S a, S size = 1) : a(a), size(size) {}\n\n    operator S()\
    \ const { return a; }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Sum &sum) {\n        os << sum.a;\n        return os;\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Sum &sum) {\n        is >> sum.a;\n\
    \        sum.size = 1;\n        return is;\n    }\n\n    constexpr Sum &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\
    \n    constexpr Sum &add(const S &rhs) {\n        a += rhs * size;\n        return\
    \ *this;\n    }\n\n    constexpr Sum &update(const S &rhs) {\n        a = rhs\
    \ * size;\n        return *this;\n    }\n\n    constexpr Sum &multiply(const S\
    \ &rhs) {\n        a *= rhs;\n        return *this;\n    }\n};\n\ntemplate <class\
    \ S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n    l.a += r.a;\n    l.size\
    \ += r.size;\n    return l;\n}\n\ntemplate <class S> constexpr Sum<S> SumUnit()\
    \ {\n    constexpr static Sum<S> e = Sum<S>();\n    return e;\n}\n\ntemplate <class\
    \ S> constexpr Sum<S> SumInv(Sum<S> x) {\n    x.a = -x.a;\n    x.size = -x.size;\n\
    \    return x;\n}\n\n} // namespace group\n\ntemplate <class S, class... Args>\n\
    constexpr std::vector<group::Sum<S>> GetVecSum(int n, Args... args) {\n    return\
    \ std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n}\n\ntemplate <class\
    \ S, class... Args>\nconstexpr std::vector<std::vector<group::Sum<S>>> GetVecSum2D(int\
    \ h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_GROUP_SUM_HPP\n#define MATH_GROUP_SUM_HPP 1\n\n#include <iostream>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\ntemplate <class S>\
    \ struct Sum {\n    S a;\n    int size;\n\n    constexpr Sum() : a(S()), size(0)\
    \ {}\n\n    constexpr Sum(S a, S size = 1) : a(a), size(size) {}\n\n    operator\
    \ S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Sum &sum) {\n        os << sum.a;\n        return os;\n    }\n\n\
    \    friend std::istream &operator>>(std::istream &is, Sum &sum) {\n        is\
    \ >> sum.a;\n        sum.size = 1;\n        return is;\n    }\n\n    constexpr\
    \ Sum &operator=(const S &rhs) {\n        a = rhs;\n        size = 1;\n      \
    \  return *this;\n    }\n\n    constexpr Sum &add(const S &rhs) {\n        a +=\
    \ rhs * size;\n        return *this;\n    }\n\n    constexpr Sum &update(const\
    \ S &rhs) {\n        a = rhs * size;\n        return *this;\n    }\n\n    constexpr\
    \ Sum &multiply(const S &rhs) {\n        a *= rhs;\n        return *this;\n  \
    \  }\n};\n\ntemplate <class S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n\
    \    l.a += r.a;\n    l.size += r.size;\n    return l;\n}\n\ntemplate <class S>\
    \ constexpr Sum<S> SumUnit() {\n    constexpr static Sum<S> e = Sum<S>();\n  \
    \  return e;\n}\n\ntemplate <class S> constexpr Sum<S> SumInv(Sum<S> x) {\n  \
    \  x.a = -x.a;\n    x.size = -x.size;\n    return x;\n}\n\n} // namespace group\n\
    \ntemplate <class S, class... Args>\nconstexpr std::vector<group::Sum<S>> GetVecSum(int\
    \ n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nconstexpr std::vector<std::vector<group::Sum<S>>>\
    \ GetVecSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n#endif // MATH_GROUP_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/group/sum.hpp
  requiredBy:
  - segment_tree/utility/sumseg2d.hpp
  - segment_tree/utility/sumseg.hpp
  - segment_tree/utility/updatesum.hpp
  - segment_tree/utility/affinesum.hpp
  - segment_tree/utility/addsum.hpp
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/group/sum.hpp
layout: document
redirect_from:
- /library/math/group/sum.hpp
- /library/math/group/sum.hpp.html
title: math/group/sum.hpp
---
