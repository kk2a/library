---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':x:'
    path: template/procon.hpp
    title: template/procon.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/container_traits.hpp: line 4: #pragma once found in a non-first\
    \ line\n"
  code: '#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

    #define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP 1


    #pragma once // oj-verify


    #include <type_traits>

    #include <vector>


    namespace kk2 {


    template <typename T> struct is_vector : std::false_type {};

    template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>
    : std::true_type {};


    } // namespace kk2


    #endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

    '
  dependsOn: []
  isVerificationFile: false
  path: type_traits/container_traits.hpp
  requiredBy:
  - template/function_util.hpp
  - template/procon.hpp
  timestamp: '2025-04-06 12:55:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
documentation_of: type_traits/container_traits.hpp
layout: document
redirect_from:
- /library/type_traits/container_traits.hpp
- /library/type_traits/container_traits.hpp.html
title: type_traits/container_traits.hpp
---
