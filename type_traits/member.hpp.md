---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: debug.hpp
      icon: LIBRARY_NO_TESTS
      path: template/debug.hpp
    type: Required by
  - files:
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_MEMBER_HPP\n#define KK2_TYPE_TRAITS_MEMBER_HPP\
      \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\
      \n#define HAS_MEMBER_FUNC(member)                                          \
      \                          \\\n    template <typename T, typename... Ts> struct\
      \ has_member_func_##member##_impl {                 \\\n        template <typename\
      \ U>                                                                      \\\
      \n        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...))\
      \ *);  \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T, typename... Ts> struct has_member_func_##member\
      \                          \\\n        : has_member_func_##member##_impl<T,\
      \ Ts...>::type {};                                      \\\n    template <typename\
      \ T, typename... Ts> using has_member_func_##member##_t =                  \
      \   \\\n        std::enable_if_t<has_member_func_##member<T, Ts...>::value>;\
      \                               \\\n    template <typename T, typename... Ts>\
      \ using not_has_member_func_##member##_t =                 \\\n        std::enable_if_t<!has_member_func_##member<T,\
      \ Ts...>::value>;\n\n#define HAS_MEMBER_VAR(member)                        \
      \                                             \\\n    template <typename T>\
      \ struct has_member_var_##member##_impl {                                  \\\
      \n        template <typename U> static std::true_type check(decltype(std::declval<U>().member)\
      \ *);   \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T> struct has_member_var_##member         \
      \                                  \\\n        : has_member_var_##member##_impl<T>::type\
      \ {};                                              \\\n    template <typename\
      \ T> using has_member_var_##member##_t =                                   \
      \   \\\n        std::enable_if_t<has_member_var_##member<T>::value>;       \
      \                                \\\n    template <typename T> using not_has_member_var_##member##_t\
      \ =                                  \\\n        std::enable_if_t<!has_member_var_##member<T>::value>;\n\
      \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\ntemplate <class T,\
      \ class... Ts>\nconcept HasDebugOutput = has_member_func_debug_output<T, Ts...>::value;\n\
      \ntemplate <class T, class... Ts>\nconcept HasVal = has_member_func_val<T, Ts...>::value;\n\
      \n// END_PRESERVE_NEWLINES\n\n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n\
      } // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_MEMBER_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/member.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_MEMBER_FUNC(member)     \
      \                                                               \\\n    template\
      \ <typename T, typename... Ts> struct has_member_func_##member##_impl {    \
      \             \\\n        template <typename U>                            \
      \                                          \\\n        static std::true_type\
      \ check(decltype(std::declval<U>().member(std::declval<Ts>()...)) *);  \\\n\
      \        template <typename U> static std::false_type check(...);          \
      \                         \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T, typename... Ts> struct has_member_func_##member\
      \                          \\\n        : has_member_func_##member##_impl<T,\
      \ Ts...>::type {};                                      \\\n    template <typename\
      \ T, typename... Ts> using has_member_func_##member##_t =                  \
      \   \\\n        std::enable_if_t<has_member_func_##member<T, Ts...>::value>;\
      \                               \\\n    template <typename T, typename... Ts>\
      \ using not_has_member_func_##member##_t =                 \\\n        std::enable_if_t<!has_member_func_##member<T,\
      \ Ts...>::value>;\n\n#define HAS_MEMBER_VAR(member)                        \
      \                                             \\\n    template <typename T>\
      \ struct has_member_var_##member##_impl {                                  \\\
      \n        template <typename U> static std::true_type check(decltype(std::declval<U>().member)\
      \ *);   \\\n        template <typename U> static std::false_type check(...);\
      \                                   \\\n        using type = decltype(check<T>(nullptr));\
      \                                                  \\\n    };              \
      \                                                                          \
      \     \\\n    template <typename T> struct has_member_var_##member         \
      \                                  \\\n        : has_member_var_##member##_impl<T>::type\
      \ {};                                              \\\n    template <typename\
      \ T> using has_member_var_##member##_t =                                   \
      \   \\\n        std::enable_if_t<has_member_var_##member<T>::value>;       \
      \                                \\\n    template <typename T> using not_has_member_var_##member##_t\
      \ =                                  \\\n        std::enable_if_t<!has_member_var_##member<T>::value>;\n\
      \nHAS_MEMBER_FUNC(debug_output)\nHAS_MEMBER_FUNC(val)\n\ntemplate <class T,\
      \ class... Ts>\nconcept HasDebugOutput = has_member_func_debug_output<T, Ts...>::value;\n\
      \ntemplate <class T, class... Ts>\nconcept HasVal = has_member_func_val<T, Ts...>::value;\n\
      \n// END_PRESERVE_NEWLINES\n\n#undef HAS_MEMBER_FUNC\n#undef HAS_MEMBER_VAR\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/member.hpp
  pathExtension: hpp
  requiredBy:
  - template/debug.hpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/concepts.test.cpp
documentation_of: type_traits/member.hpp
layout: document
---
