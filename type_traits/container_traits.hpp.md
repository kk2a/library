---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':question:'
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':x:'
    path: template/procon.hpp
    title: template/procon.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/parallel.hpp
    title: unionfind/parallel.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/group/group.test.cpp
    title: verify/unit_test/math/group/group.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/static_rolling_hash.test.cpp
    title: verify/unit_test/string/static_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    title: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - icon: ':x:'
    path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "type_traits/container_traits.hpp"




    #include <array>

    #include <deque>

    #include <list>

    #include <string>

    #include <type_traits>

    #include <vector>


    namespace kk2 {


    template <typename T> struct is_vector : std::false_type {};

    template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>
    : std::true_type {};


    template <typename T> struct is_container : std::false_type {};

    template <typename T, typename Alloc> struct is_container<std::vector<T, Alloc>>
    : std::true_type {

    };

    template <typename CharT, typename Traits, typename Alloc>

    struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type
    {};

    template <typename T, std::size_t N> struct is_container<std::array<T, N>> : std::true_type
    {};

    template <typename T, typename Alloc> struct is_container<std::deque<T, Alloc>>
    : std::true_type {};

    template <typename T, typename Alloc> struct is_container<std::list<T, Alloc>>
    : std::true_type {};

    template <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;


    } // namespace kk2



    '
  code: '#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

    #define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP 1


    #include <array>

    #include <deque>

    #include <list>

    #include <string>

    #include <type_traits>

    #include <vector>


    namespace kk2 {


    template <typename T> struct is_vector : std::false_type {};

    template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>
    : std::true_type {};


    template <typename T> struct is_container : std::false_type {};

    template <typename T, typename Alloc> struct is_container<std::vector<T, Alloc>>
    : std::true_type {

    };

    template <typename CharT, typename Traits, typename Alloc>

    struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type
    {};

    template <typename T, std::size_t N> struct is_container<std::array<T, N>> : std::true_type
    {};

    template <typename T, typename Alloc> struct is_container<std::deque<T, Alloc>>
    : std::true_type {};

    template <typename T, typename Alloc> struct is_container<std::list<T, Alloc>>
    : std::true_type {};

    template <typename T> using is_container_t = typename std::enable_if_t<is_container<T>::value>;


    } // namespace kk2


    #endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP

    '
  dependsOn: []
  isVerificationFile: false
  path: type_traits/container_traits.hpp
  requiredBy:
  - string/static_rolling_hash.hpp
  - string/dynamic_rolling_hash.hpp
  - template/procon.hpp
  - template/function_util.hpp
  - math/group/rolling_hash.hpp
  - unionfind/parallel.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/math/group/group.test.cpp
documentation_of: type_traits/container_traits.hpp
layout: document
redirect_from:
- /library/type_traits/container_traits.hpp
- /library/type_traits/container_traits.hpp.html
title: type_traits/container_traits.hpp
---
