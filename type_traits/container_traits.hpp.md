---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':question:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/procon.hpp
    title: template/procon.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    title: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
    title: verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  code: "#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP\n#define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP\
    \ 1\n\n#pragma once // oj-verify\n\n#include <array>\n#include <deque>\n#include\
    \ <list>\n#include <string>\n#include <type_traits>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <typename T> struct is_vector : std::false_type {};\ntemplate\
    \ <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>> : std::true_type\
    \ {};\n\n// \u30B3\u30F3\u30C6\u30CA\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\
    \u3059\u308Btraits\ntemplate <typename T> struct is_container : std::false_type\
    \ {};\n\n// \u57FA\u672C\u7684\u306A\u30B3\u30F3\u30C6\u30CA\u578B\u306E\u7279\
    \u6B8A\u5316\ntemplate <typename T, typename Alloc> struct is_container<std::vector<T,\
    \ Alloc>> : std::true_type {\n};\n\ntemplate <typename CharT, typename Traits,\
    \ typename Alloc>\nstruct is_container<std::basic_string<CharT, Traits, Alloc>>\
    \ : std::true_type {};\n\ntemplate <typename T, std::size_t N> struct is_container<std::array<T,\
    \ N>> : std::true_type {};\n\ntemplate <typename T, typename Alloc> struct is_container<std::deque<T,\
    \ Alloc>> : std::true_type {};\n\ntemplate <typename T, typename Alloc> struct\
    \ is_container<std::list<T, Alloc>> : std::true_type {};\n\n// SFINAE\u3067\u30B3\
    \u30F3\u30C6\u30CA\u3092\u5224\u5B9A\u3059\u308B\u305F\u3081\u306E\u30D8\u30EB\
    \u30D1\u30FC\ntemplate <typename T> using is_container_t =\n    typename std::enable_if_t<is_container<T>::value,\
    \ std::nullptr_t>;\n\n} // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/container_traits.hpp
  requiredBy:
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - template/function_util.hpp
  - template/procon.hpp
  - unionfind/parallel.hpp
  - math/group/rolling_hash.hpp
  timestamp: '2025-06-06 17:43:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/yosupo_others/many_a_plus_b_128bit_2.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
documentation_of: type_traits/container_traits.hpp
layout: document
redirect_from:
- /library/type_traits/container_traits.hpp
- /library/type_traits/container_traits.hpp.html
title: type_traits/container_traits.hpp
---
