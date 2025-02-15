---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: segment_tree/utility/add_max_min_sum.hpp
    title: segment_tree/utility/add_max_min_sum.hpp
  - icon: ':warning:'
    path: segment_tree/utility/addmax.hpp
    title: segment_tree/utility/addmax.hpp
  - icon: ':warning:'
    path: segment_tree/utility/addmin.hpp
    title: segment_tree/utility/addmin.hpp
  - icon: ':warning:'
    path: segment_tree/utility/addsum.hpp
    title: segment_tree/utility/addsum.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/homomorphism/add.hpp\"\n\n\n\nnamespace kk2 {\n\nnamespace\
    \ homomorphism {\n\ntemplate <class S> using Add = S;\n\ntemplate <class S, class\
    \ T> constexpr T AddMap(Add<S> f, T x) {\n    return x.add(f);\n}\n\ntemplate\
    \ <class S> constexpr Add<S> AddComposition(Add<S> l, Add<S> r) {\n    return\
    \ l + r;\n}\n\ntemplate <class S> Add<S> AddUnit() {\n    constexpr static Add<S>\
    \ e = Add<S>();\n    return e;\n}\n\n} // namespace homomorphism\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_HOMOMORPHISM_ADD_HPP\n#define KK2_MATH_HOMOMORPHISM_ADD_HPP\
    \ 1\n\nnamespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S> using\
    \ Add = S;\n\ntemplate <class S, class T> constexpr T AddMap(Add<S> f, T x) {\n\
    \    return x.add(f);\n}\n\ntemplate <class S> constexpr Add<S> AddComposition(Add<S>\
    \ l, Add<S> r) {\n    return l + r;\n}\n\ntemplate <class S> Add<S> AddUnit()\
    \ {\n    constexpr static Add<S> e = Add<S>();\n    return e;\n}\n\n} // namespace\
    \ homomorphism\n\n} // namespace kk2\n\n#endif // KK2_MATH_HOMOMORPHISM_ADD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/add.hpp
  requiredBy:
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/add_max_min_sum.hpp
  - segment_tree/utility/addmax.hpp
  - segment_tree/utility/addmin.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/homomorphism/add.hpp
layout: document
redirect_from:
- /library/math/homomorphism/add.hpp
- /library/math/homomorphism/add.hpp.html
title: math/homomorphism/add.hpp
---
