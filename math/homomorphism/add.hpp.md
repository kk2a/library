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
  bundledCode: '#line 1 "math/homomorphism/add.hpp"




    namespace kk2 {


    namespace homomorphism {


    template <class S>

    using Add = S;


    template <class S, class T>

    T AddMap(Add<S> f, T x) { return x.add(f); }


    template <class S>

    Add<S> AddComposition(Add<S> l, Add<S> r) { return l + r; }


    template <class S>

    Add<S> AddUnit() { return Add<S>(); }


    } // namespace homomorphism


    } // namespace kk2



    '
  code: '#ifndef MATH_HOMOMORPHISM_ADD_HPP

    #define MATH_HOMOMORPHISM_ADD_HPP 1


    namespace kk2 {


    namespace homomorphism {


    template <class S>

    using Add = S;


    template <class S, class T>

    T AddMap(Add<S> f, T x) { return x.add(f); }


    template <class S>

    Add<S> AddComposition(Add<S> l, Add<S> r) { return l + r; }


    template <class S>

    Add<S> AddUnit() { return Add<S>(); }


    } // namespace homomorphism


    } // namespace kk2


    #endif // MATH_HOMOMORPHISM_ADD_HPP

    '
  dependsOn: []
  isVerificationFile: false
  path: math/homomorphism/add.hpp
  requiredBy:
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/addmin.hpp
  - segment_tree/utility/addmax.hpp
  timestamp: '2024-08-29 23:32:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/homomorphism/add.hpp
layout: document
redirect_from:
- /library/math/homomorphism/add.hpp
- /library/math/homomorphism/add.hpp.html
title: math/homomorphism/add.hpp
---
