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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/operator.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef TYPE_TRAITS_OPERATOR_HPP\n#define TYPE_TRAITS_OPERATOR_HPP 1\n\n\
    #pragma once\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#define HAS_BINARY_OP(op,\
    \ op_name)                                                                 \\\n\
    \    template <typename LHS, typename RHS> struct has_binary_op_##op_name##_impl\
    \ {                  \\\n        template <typename LHS2, typename RHS2>     \
    \                                               \\\n        static std::true_type\
    \ check(decltype(std::declval<LHS2>() op std::declval<RHS2>()) *);     \\\n  \
    \      template <typename, typename> static std::false_type check(...);      \
    \                     \\\n        using type = decltype(check<LHS, RHS>(nullptr));\
    \                                           \\\n    };                       \
    \                                                                      \\\n  \
    \  template <typename LHS, typename RHS = LHS>                               \
    \                     \\\n    struct has_binary_op_##op_name : has_binary_op_##op_name##_impl<LHS,\
    \ RHS>::type {};            \\\n    template <typename LHS, typename RHS = LHS>\
    \                                                    \\\n    using has_binary_op_##op_name##_t\
    \ =                                                            \\\n        std::enable_if_t<has_binary_op_##op_name<LHS,\
    \ RHS>::value>;\n\n#define HAS_UNARY_OP(op, op_name)                         \
    \                                         \\\n    template <typename T> struct\
    \ has_unary_op_##op_name##_impl {                                   \\\n     \
    \   template <typename U> static std::true_type check(decltype(op std::declval<T>())\
    \ *);       \\\n        template <typename U> static std::false_type check(...);\
    \                                   \\\n        using type = decltype(check<T>(nullptr));\
    \                                                  \\\n    };                \
    \                                                                            \
    \ \\\n    template <typename T>                                              \
    \                            \\\n    struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type\
    \ {};                     \\\n    template <typename T>                      \
    \                                                    \\\n    using has_unary_op_##op_name##_t\
    \ = std::enable_if_t<has_unary_op_##op_name<T>::value>;\n\nHAS_UNARY_OP(-, negation)\n\
    HAS_BINARY_OP(+, plus)\nHAS_BINARY_OP(-, minus)\nHAS_BINARY_OP(*, multiplies)\n\
    HAS_BINARY_OP(/, divides)\nHAS_BINARY_OP(%, modulus)\n\nHAS_UNARY_OP(~, bit_not)\n\
    HAS_BINARY_OP(&, bit_and)\nHAS_BINARY_OP(|, bit_or)\nHAS_BINARY_OP(^, bit_xor)\n\
    \nHAS_UNARY_OP(!, logical_not)\nHAS_BINARY_OP(&&, logical_and)\nHAS_BINARY_OP(||,\
    \ logical_or)\n\nHAS_BINARY_OP(==, equal_to)\nHAS_BINARY_OP(!=, not_equal_to)\n\
    HAS_BINARY_OP(<, less)\nHAS_BINARY_OP(>, greater)\nHAS_BINARY_OP(<=, less_equal)\n\
    HAS_BINARY_OP(>=, greater_equal)\n#undef HAS_BINARY_OP\n#undef HAS_UNARY_OP\n\
    } // namespace kk2\n\n#endif // TYPE_TRAITS_OPERATOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: type_traits/operator.hpp
  requiredBy: []
  timestamp: '2025-01-02 20:45:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: type_traits/operator.hpp
layout: document
redirect_from:
- /library/type_traits/operator.hpp
- /library/type_traits/operator.hpp.html
title: type_traits/operator.hpp
---
