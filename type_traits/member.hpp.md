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
  bundledCode: "#line 1 \"type_traits/member.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_MEMBER_FUNC(member)\
    \                                                                    \\\n    template\
    \ <typename T, typename... Ts> struct has_member_func_##member##_impl {      \
    \           \\\n        template <typename U>                                \
    \                                      \\\n        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...))\
    \ *);  \\\n        template <typename U> static std::false_type check(...);  \
    \                                 \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T, typename... Ts> struct has_member_func_##member\
    \                          \\\n        : has_member_func_##member##_impl<T, Ts...>::type\
    \ {};                                      \\\n    template <typename T, typename...\
    \ Ts> using has_member_func_##member##_t =                     \\\n        std::enable_if_t<has_member_func_##member<T,\
    \ Ts...>::value>;                               \\\n    template <typename T,\
    \ typename... Ts> using not_has_member_func_##member##_t =                 \\\n\
    \        std::enable_if_t<!has_member_func_##member<T, Ts...>::value>;\n\n#define\
    \ HAS_MEMBER_VAR(member)                                                     \
    \                \\\n    template <typename T> struct has_member_var_##member##_impl\
    \ {                                  \\\n        template <typename U> static\
    \ std::true_type check(decltype(std::declval<U>().member) *);   \\\n        template\
    \ <typename U> static std::false_type check(...);                            \
    \       \\\n        using type = decltype(check<T>(nullptr));                \
    \                                  \\\n    };                                \
    \                                                             \\\n    template\
    \ <typename T> struct has_member_var_##member                                \
    \           \\\n        : has_member_var_##member##_impl<T>::type {};        \
    \                                      \\\n    template <typename T> using has_member_var_##member##_t\
    \ =                                      \\\n        std::enable_if_t<has_member_var_##member<T>::value>;\
    \                                       \\\n    template <typename T> using not_has_member_var_##member##_t\
    \ =                                  \\\n        std::enable_if_t<!has_member_var_##member<T>::value>;\n\
    \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\n// END_PRESERVE_NEWLINES\n\
    \n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_TYPE_TRAITS_MEMBER_HPP\n#define KK2_TYPE_TRAITS_MEMBER_HPP 1\n\
    \n#include <type_traits>\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define\
    \ HAS_MEMBER_FUNC(member)                                                    \
    \                \\\n    template <typename T, typename... Ts> struct has_member_func_##member##_impl\
    \ {                 \\\n        template <typename U>                        \
    \                                              \\\n        static std::true_type\
    \ check(decltype(std::declval<U>().member(std::declval<Ts>()...)) *);  \\\n  \
    \      template <typename U> static std::false_type check(...);              \
    \                     \\\n        using type = decltype(check<T>(nullptr));  \
    \                                                \\\n    };                  \
    \                                                                           \\\
    \n    template <typename T, typename... Ts> struct has_member_func_##member  \
    \                        \\\n        : has_member_func_##member##_impl<T, Ts...>::type\
    \ {};                                      \\\n    template <typename T, typename...\
    \ Ts> using has_member_func_##member##_t =                     \\\n        std::enable_if_t<has_member_func_##member<T,\
    \ Ts...>::value>;                               \\\n    template <typename T,\
    \ typename... Ts> using not_has_member_func_##member##_t =                 \\\n\
    \        std::enable_if_t<!has_member_func_##member<T, Ts...>::value>;\n\n#define\
    \ HAS_MEMBER_VAR(member)                                                     \
    \                \\\n    template <typename T> struct has_member_var_##member##_impl\
    \ {                                  \\\n        template <typename U> static\
    \ std::true_type check(decltype(std::declval<U>().member) *);   \\\n        template\
    \ <typename U> static std::false_type check(...);                            \
    \       \\\n        using type = decltype(check<T>(nullptr));                \
    \                                  \\\n    };                                \
    \                                                             \\\n    template\
    \ <typename T> struct has_member_var_##member                                \
    \           \\\n        : has_member_var_##member##_impl<T>::type {};        \
    \                                      \\\n    template <typename T> using has_member_var_##member##_t\
    \ =                                      \\\n        std::enable_if_t<has_member_var_##member<T>::value>;\
    \                                       \\\n    template <typename T> using not_has_member_var_##member##_t\
    \ =                                  \\\n        std::enable_if_t<!has_member_var_##member<T>::value>;\n\
    \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\n// END_PRESERVE_NEWLINES\n\
    \n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n} // namespace kk2\n\n#endif\
    \ // KK2_TYPE_TRAITS_MEMBER_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/member.hpp
  requiredBy:
  - template/debug.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type_traits/member.hpp
layout: document
redirect_from:
- /library/type_traits/member.hpp
- /library/type_traits/member.hpp.html
title: type_traits/member.hpp
---
