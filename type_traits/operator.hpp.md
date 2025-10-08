---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"type_traits/operator.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_BINARY_OP(op, op_name)\
    \                                                                 \\\n    template\
    \ <typename LHS, typename RHS> struct has_binary_op_##op_name##_impl {       \
    \           \\\n        template <typename LHS2, typename RHS2>              \
    \                                      \\\n        static std::true_type check(decltype(std::declval<LHS2>()\
    \ op std::declval<RHS2>()) *);     \\\n        template <typename, typename> static\
    \ std::false_type check(...);                           \\\n        using type\
    \ = decltype(check<LHS, RHS>(nullptr));                                      \
    \     \\\n    };                                                             \
    \                                \\\n    template <typename LHS, typename RHS\
    \ = LHS> struct has_binary_op_##op_name                     \\\n        : has_binary_op_##op_name##_impl<LHS,\
    \ RHS>::type {};                                       \\\n    template <typename\
    \ LHS, typename RHS = LHS> using has_binary_op_##op_name##_t =               \
    \ \\\n        std::enable_if_t<has_binary_op_##op_name<LHS, RHS>::value>;\n\n\
    #define HAS_UNARY_OP(op, op_name)                                            \
    \                      \\\n    template <typename T> struct has_unary_op_##op_name##_impl\
    \ {                                   \\\n        template <typename U> static\
    \ std::true_type check(decltype(op std::declval<T>()) *);       \\\n        template\
    \ <typename U> static std::false_type check(...);                            \
    \       \\\n        using type = decltype(check<T>(nullptr));                \
    \                                  \\\n    };                                \
    \                                                             \\\n    template\
    \ <typename T> struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
    \ { \\\n    };                                                               \
    \                              \\\n    template <typename T> using has_unary_op_##op_name##_t\
    \ =                                       \\\n        std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\
    \nHAS_UNARY_OP(-, negation)\nHAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\n\
    HAS_BINARY_OP(*, multiplies)\nHAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\
    \nHAS_UNARY_OP(~, bit_not)\nHAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\n\
    HAS_BINARY_OP(^, bit_xor)\n\nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&, logical_and)\n\
    HAS_BINARY_OP(||, logical_or)\n\nHAS_BINARY_OP(==, equal_to)\nHAS_BINARY_OP(!=,\
    \ not_equal_to)\nHAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\nHAS_BINARY_OP(<=,\
    \ less_equal)\nHAS_BINARY_OP(>=, greater_equal)\n\n// END_PRESERVE_NEWLINES\n\n\
    #undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_TYPE_TRAITS_OPERATOR_HPP\n#define KK2_TYPE_TRAITS_OPERATOR_HPP\
    \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\
    \n#define HAS_BINARY_OP(op, op_name)                                         \
    \                        \\\n    template <typename LHS, typename RHS> struct\
    \ has_binary_op_##op_name##_impl {                  \\\n        template <typename\
    \ LHS2, typename RHS2>                                                    \\\n\
    \        static std::true_type check(decltype(std::declval<LHS2>() op std::declval<RHS2>())\
    \ *);     \\\n        template <typename, typename> static std::false_type check(...);\
    \                           \\\n        using type = decltype(check<LHS, RHS>(nullptr));\
    \                                           \\\n    };                       \
    \                                                                      \\\n  \
    \  template <typename LHS, typename RHS = LHS> struct has_binary_op_##op_name\
    \                     \\\n        : has_binary_op_##op_name##_impl<LHS, RHS>::type\
    \ {};                                       \\\n    template <typename LHS, typename\
    \ RHS = LHS> using has_binary_op_##op_name##_t =                \\\n        std::enable_if_t<has_binary_op_##op_name<LHS,\
    \ RHS>::value>;\n\n#define HAS_UNARY_OP(op, op_name)                         \
    \                                         \\\n    template <typename T> struct\
    \ has_unary_op_##op_name##_impl {                                   \\\n     \
    \   template <typename U> static std::true_type check(decltype(op std::declval<T>())\
    \ *);       \\\n        template <typename U> static std::false_type check(...);\
    \                                   \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T> struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
    \ { \\\n    };                                                               \
    \                              \\\n    template <typename T> using has_unary_op_##op_name##_t\
    \ =                                       \\\n        std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\
    \nHAS_UNARY_OP(-, negation)\nHAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\n\
    HAS_BINARY_OP(*, multiplies)\nHAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\
    \nHAS_UNARY_OP(~, bit_not)\nHAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\n\
    HAS_BINARY_OP(^, bit_xor)\n\nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&, logical_and)\n\
    HAS_BINARY_OP(||, logical_or)\n\nHAS_BINARY_OP(==, equal_to)\nHAS_BINARY_OP(!=,\
    \ not_equal_to)\nHAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\nHAS_BINARY_OP(<=,\
    \ less_equal)\nHAS_BINARY_OP(>=, greater_equal)\n\n// END_PRESERVE_NEWLINES\n\n\
    #undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n} // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_OPERATOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/operator.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type_traits/operator.hpp
layout: document
redirect_from:
- /library/type_traits/operator.hpp
- /library/type_traits/operator.hpp.html
title: type_traits/operator.hpp
---
