---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    \ T> T AddMap(Add<S> f, T x) {\n    return x.add(f);\n}\n\ntemplate <class S>\
    \ Add<S> AddComposition(Add<S> l, Add<S> r) {\n    return l + r;\n}\n\ntemplate\
    \ <class S> Add<S> AddUnit() {\n    return Add<S>();\n}\n\n} // namespace homomorphism\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_HOMOMORPHISM_ADD_HPP\n#define MATH_HOMOMORPHISM_ADD_HPP 1\n\n\
    namespace kk2 {\n\nnamespace homomorphism {\n\ntemplate <class S> using Add =\
    \ S;\n\ntemplate <class S, class T> T AddMap(Add<S> f, T x) {\n    return x.add(f);\n\
    }\n\ntemplate <class S> Add<S> AddComposition(Add<S> l, Add<S> r) {\n    return\
    \ l + r;\n}\n\ntemplate <class S> Add<S> AddUnit() {\n    return Add<S>();\n}\n\
    \n} // namespace homomorphism\n\n} // namespace kk2\n\n#endif // MATH_HOMOMORPHISM_ADD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/add.hpp
  requiredBy:
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/addmin.hpp
  - segment_tree/utility/addmax.hpp
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/homomorphism/add.hpp
layout: document
redirect_from:
- /library/math/homomorphism/add.hpp
- /library/math/homomorphism/add.hpp.html
title: math/homomorphism/add.hpp
---
