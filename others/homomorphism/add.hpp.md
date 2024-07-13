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
  bundledCode: '#line 1 "others/homomorphism/add.hpp"




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



    '
  code: '#ifndef OTHERS_HOMOMORPHISM_ADD_HPP

    #define OTHERS_HOMOMORPHISM_ADD_HPP 1


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


    #endif // OTHERS_HOMOMORPHISM_ADD_HPP

    '
  dependsOn: []
  isVerificationFile: false
  path: others/homomorphism/add.hpp
  requiredBy:
  - segment_tree/utility/addmax.hpp
  - segment_tree/utility/addsum.hpp
  - segment_tree/utility/addmin.hpp
  timestamp: '2024-07-07 19:16:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/homomorphism/add.hpp
layout: document
redirect_from:
- /library/others/homomorphism/add.hpp
- /library/others/homomorphism/add.hpp.html
title: others/homomorphism/add.hpp
---
