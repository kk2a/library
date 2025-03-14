---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/debug.hpp
    title: template/debug.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ type_traits/member.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_TYPE_TRAITS_MEMBER_HPP\n#define KK2_TYPE_TRAITS_MEMBER_HPP 1\n\
    \n#pragma once\n\n#include <type_traits>\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\
    \n#define HAS_MEMBER_FUNC(member)                                            \
    \                        \\\n    template <typename T, typename... Ts> struct\
    \ has_member_func_##member##_impl {                 \\\n        template <typename\
    \ U>                                                                      \\\n\
    \        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...))\
    \ *);  \\\n        template <typename U> static std::false_type check(...);  \
    \                                 \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T, typename... Ts>                              \
    \                            \\\n    struct has_member_func_##member : has_member_func_##member##_impl<T,\
    \ Ts...>::type {};          \\\n    template <typename T, typename... Ts>    \
    \                                                      \\\n    using has_member_func_##member##_t\
    \ =                                                           \\\n        std::enable_if_t<has_member_func_##member<T,\
    \ Ts...>::value>;                               \\\n    template <typename T,\
    \ typename... Ts>                                                          \\\n\
    \    using not_has_member_func_##member##_t =                                \
    \                       \\\n        std::enable_if_t<!has_member_func_##member<T,\
    \ Ts...>::value>;\n\n#define HAS_MEMBER_VAR(member)                          \
    \                                           \\\n    template <typename T> struct\
    \ has_member_var_##member##_impl {                                  \\\n     \
    \   template <typename U> static std::true_type check(decltype(std::declval<U>().member)\
    \ *);   \\\n        template <typename U> static std::false_type check(...); \
    \                                  \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T>                                              \
    \                            \\\n    struct has_member_var_##member : has_member_var_##member##_impl<T>::type\
    \ {};                   \\\n    template <typename T>                        \
    \                                                  \\\n    using has_member_var_##member##_t\
    \ = std::enable_if_t<has_member_var_##member<T>::value>;       \\\n    template\
    \ <typename T>                                                               \
    \           \\\n    using not_has_member_var_##member##_t = std::enable_if_t<!has_member_var_##member<T>::value>;\n\
    \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\n// END_PRESERVE_NEWLINES\n\
    \n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n} // namespace kk2\n\n#endif\
    \ // KK2_TYPE_TRAITS_MEMBER_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/member.hpp
  requiredBy:
  - template/debug.hpp
  timestamp: '2025-03-02 17:07:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type_traits/member.hpp
layout: document
redirect_from:
- /library/type_traits/member.hpp
- /library/type_traits/member.hpp.html
title: type_traits/member.hpp
---
