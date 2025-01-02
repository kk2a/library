#ifndef TYPE_TRAITS_OPERATOR_HPP
#define TYPE_TRAITS_OPERATOR_HPP 1

#pragma once

#include <type_traits>

namespace kk2 {

#define HAS_BINARY_OP(op, op_name)                                                                 \
    template <typename LHS, typename RHS> struct has_binary_op_##op_name##_impl {                  \
        template <typename LHS2, typename RHS2>                                                    \
        static std::true_type check(decltype(std::declval<LHS2>() op std::declval<RHS2>()) *);     \
        template <typename, typename> static std::false_type check(...);                           \
        using type = decltype(check<LHS, RHS>(nullptr));                                           \
    };                                                                                             \
    template <typename LHS, typename RHS = LHS>                                                    \
    struct has_binary_op_##op_name : has_binary_op_##op_name##_impl<LHS, RHS>::type {};            \
    template <typename LHS, typename RHS = LHS>                                                    \
    using has_binary_op_##op_name##_t =                                                            \
        std::enable_if_t<has_binary_op_##op_name<LHS, RHS>::value>;

#define HAS_UNARY_OP(op, op_name)                                                                  \
    template <typename T> struct has_unary_op_##op_name##_impl {                                   \
        template <typename U> static std::true_type check(decltype(op std::declval<T>()) *);       \
        template <typename U> static std::false_type check(...);                                   \
        using type = decltype(check<T>(nullptr));                                                  \
    };                                                                                             \
    template <typename T>                                                                          \
    struct has_unary_op_##op_name : has_unary_op_##op_name##_impl<T>::type {};                     \
    template <typename T>                                                                          \
    using has_unary_op_##op_name##_t = std::enable_if_t<has_unary_op_##op_name<T>::value>;

HAS_UNARY_OP(-, negation)
HAS_BINARY_OP(+, plus)
HAS_BINARY_OP(-, minus)
HAS_BINARY_OP(*, multiplies)
HAS_BINARY_OP(/, divides)
HAS_BINARY_OP(%, modulus)

HAS_UNARY_OP(~, bit_not)
HAS_BINARY_OP(&, bit_and)
HAS_BINARY_OP(|, bit_or)
HAS_BINARY_OP(^, bit_xor)

HAS_UNARY_OP(!, logical_not)
HAS_BINARY_OP(&&, logical_and)
HAS_BINARY_OP(||, logical_or)

HAS_BINARY_OP(==, equal_to)
HAS_BINARY_OP(!=, not_equal_to)
HAS_BINARY_OP(<, less)
HAS_BINARY_OP(>, greater)
HAS_BINARY_OP(<=, less_equal)
HAS_BINARY_OP(>=, greater_equal)
#undef HAS_BINARY_OP
#undef HAS_UNARY_OP
} // namespace kk2

#endif // TYPE_TRAITS_OPERATOR_HPP
