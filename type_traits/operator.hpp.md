---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_OPERATOR_HPP\n#define KK2_TYPE_TRAITS_OPERATOR_HPP\
      \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\
      \n#define HAS_BINARY_OP(op, op_name)                                       \
      \                          \\\n    template <typename LHS, typename RHS> struct\
      \ has_binary_op_##op_name##_impl {                  \\\n        template <typename\
      \ LHS2, typename RHS2>                                                    \\\
      \n        static std::true_type check(decltype(std::declval<LHS2>() op std::declval<RHS2>())\
      \ *);     \\\n        template <typename, typename> static std::false_type check(...);\
      \                           \\\n        using type = decltype(check<LHS, RHS>(nullptr));\
      \                                           \\\n    };                     \
      \                                                                        \\\n\
      \    template <typename LHS, typename RHS = LHS> struct has_binary_op_##op_name\
      \                     \\\n        : has_binary_op_##op_name##_impl<LHS, RHS>::type\
      \ {};                                       \\\n    template <typename LHS,\
      \ typename RHS = LHS> using has_binary_op_##op_name##_t =                \\\n\
      \        std::enable_if_t<has_binary_op_##op_name<LHS, RHS>::value>;\n\n#define\
      \ HAS_UNARY_OP(op, op_name)                                                \
      \                  \\\n    template <typename T> struct has_unary_op_##op_name##_impl\
      \ {                                   \\\n        template <typename U> static\
      \ std::true_type check(decltype(op std::declval<T>()) *);       \\\n       \
      \ template <typename U> static std::false_type check(...);                 \
      \                  \\\n        using type = decltype(check<T>(nullptr));   \
      \                                               \\\n    };                 \
      \                                                                          \
      \  \\\n    template <typename T> struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
      \ { \\\n    };                                                             \
      \                                \\\n    template <typename T> using has_unary_op_##op_name##_t\
      \ =                                       \\\n        std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\
      \nHAS_UNARY_OP(-, negation)\nHAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\n\
      HAS_BINARY_OP(*, multiplies)\nHAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\
      \nHAS_UNARY_OP(~, bit_not)\nHAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\n\
      HAS_BINARY_OP(^, bit_xor)\n\nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&,\
      \ logical_and)\nHAS_BINARY_OP(||, logical_or)\n\nHAS_BINARY_OP(==, equal_to)\n\
      HAS_BINARY_OP(!=, not_equal_to)\nHAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\n\
      HAS_BINARY_OP(<=, less_equal)\nHAS_BINARY_OP(>=, greater_equal)\n\n#define HAS_UNARY_CONCEPT(op,\
      \ name) \\\n    template <class T> concept Has##name = requires(T x) { op x;\
      \ };\n\n#define HAS_BINARY_CONCEPT(op, name) \\\n    template <class LHS, class\
      \ RHS = LHS> concept Has##name = requires(LHS lhs, RHS rhs) { lhs op rhs; };\n\
      \nHAS_UNARY_CONCEPT(-, Negation)\nHAS_BINARY_CONCEPT(+, Plus)\nHAS_BINARY_CONCEPT(-,\
      \ Minus)\nHAS_BINARY_CONCEPT(*, Multiplies)\nHAS_BINARY_CONCEPT(/, Divides)\n\
      HAS_BINARY_CONCEPT(%, Modulus)\nHAS_UNARY_CONCEPT(~, BitNot)\nHAS_BINARY_CONCEPT(&,\
      \ BitAnd)\nHAS_BINARY_CONCEPT(|, BitOr)\nHAS_BINARY_CONCEPT(^, BitXor)\nHAS_UNARY_CONCEPT(!,\
      \ LogicalNot)\nHAS_BINARY_CONCEPT(&&, LogicalAnd)\nHAS_BINARY_CONCEPT(||, LogicalOr)\n\
      HAS_BINARY_CONCEPT(==, EqualTo)\nHAS_BINARY_CONCEPT(!=, NotEqualTo)\nHAS_BINARY_CONCEPT(<,\
      \ Less)\nHAS_BINARY_CONCEPT(>, Greater)\nHAS_BINARY_CONCEPT(<=, LessEqual)\n\
      HAS_BINARY_CONCEPT(>=, GreaterEqual)\n\n#undef HAS_UNARY_CONCEPT\n#undef HAS_BINARY_CONCEPT\n\
      \n// END_PRESERVE_NEWLINES\n\n#undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n} //\
      \ namespace kk2\n\n#endif // KK2_TYPE_TRAITS_OPERATOR_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/operator.hpp\"\n\n\n\n#include <type_traits>\n\n\
      namespace kk2 {\n// BEGIN_PRESERVE_NEWLINES\n\n#define HAS_BINARY_OP(op, op_name)\
      \                                                                 \\\n    template\
      \ <typename LHS, typename RHS> struct has_binary_op_##op_name##_impl {     \
      \             \\\n        template <typename LHS2, typename RHS2>          \
      \                                          \\\n        static std::true_type\
      \ check(decltype(std::declval<LHS2>() op std::declval<RHS2>()) *);     \\\n\
      \        template <typename, typename> static std::false_type check(...);  \
      \                         \\\n        using type = decltype(check<LHS, RHS>(nullptr));\
      \                                           \\\n    };                     \
      \                                                                        \\\n\
      \    template <typename LHS, typename RHS = LHS> struct has_binary_op_##op_name\
      \                     \\\n        : has_binary_op_##op_name##_impl<LHS, RHS>::type\
      \ {};                                       \\\n    template <typename LHS,\
      \ typename RHS = LHS> using has_binary_op_##op_name##_t =                \\\n\
      \        std::enable_if_t<has_binary_op_##op_name<LHS, RHS>::value>;\n\n#define\
      \ HAS_UNARY_OP(op, op_name)                                                \
      \                  \\\n    template <typename T> struct has_unary_op_##op_name##_impl\
      \ {                                   \\\n        template <typename U> static\
      \ std::true_type check(decltype(op std::declval<T>()) *);       \\\n       \
      \ template <typename U> static std::false_type check(...);                 \
      \                  \\\n        using type = decltype(check<T>(nullptr));   \
      \                                               \\\n    };                 \
      \                                                                          \
      \  \\\n    template <typename T> struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
      \ { \\\n    };                                                             \
      \                                \\\n    template <typename T> using has_unary_op_##op_name##_t\
      \ =                                       \\\n        std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\
      \nHAS_UNARY_OP(-, negation)\nHAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\n\
      HAS_BINARY_OP(*, multiplies)\nHAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\
      \nHAS_UNARY_OP(~, bit_not)\nHAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\n\
      HAS_BINARY_OP(^, bit_xor)\n\nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&,\
      \ logical_and)\nHAS_BINARY_OP(||, logical_or)\n\nHAS_BINARY_OP(==, equal_to)\n\
      HAS_BINARY_OP(!=, not_equal_to)\nHAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\n\
      HAS_BINARY_OP(<=, less_equal)\nHAS_BINARY_OP(>=, greater_equal)\n\n#define HAS_UNARY_CONCEPT(op,\
      \ name) \\\n    template <class T> concept Has##name = requires(T x) { op x;\
      \ };\n\n#define HAS_BINARY_CONCEPT(op, name) \\\n    template <class LHS, class\
      \ RHS = LHS> concept Has##name = requires(LHS lhs, RHS rhs) { lhs op rhs; };\n\
      \nHAS_UNARY_CONCEPT(-, Negation)\nHAS_BINARY_CONCEPT(+, Plus)\nHAS_BINARY_CONCEPT(-,\
      \ Minus)\nHAS_BINARY_CONCEPT(*, Multiplies)\nHAS_BINARY_CONCEPT(/, Divides)\n\
      HAS_BINARY_CONCEPT(%, Modulus)\nHAS_UNARY_CONCEPT(~, BitNot)\nHAS_BINARY_CONCEPT(&,\
      \ BitAnd)\nHAS_BINARY_CONCEPT(|, BitOr)\nHAS_BINARY_CONCEPT(^, BitXor)\nHAS_UNARY_CONCEPT(!,\
      \ LogicalNot)\nHAS_BINARY_CONCEPT(&&, LogicalAnd)\nHAS_BINARY_CONCEPT(||, LogicalOr)\n\
      HAS_BINARY_CONCEPT(==, EqualTo)\nHAS_BINARY_CONCEPT(!=, NotEqualTo)\nHAS_BINARY_CONCEPT(<,\
      \ Less)\nHAS_BINARY_CONCEPT(>, Greater)\nHAS_BINARY_CONCEPT(<=, LessEqual)\n\
      HAS_BINARY_CONCEPT(>=, GreaterEqual)\n\n#undef HAS_UNARY_CONCEPT\n#undef HAS_BINARY_CONCEPT\n\
      \n// END_PRESERVE_NEWLINES\n\n#undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n} //\
      \ namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/operator.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/concepts.test.cpp
documentation_of: type_traits/operator.hpp
layout: document
---
