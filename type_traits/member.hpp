#ifndef TYPE_TRAITS_MEMBER_HPP
#define TYPE_TRAITS_MEMBER_HPP 1

#pragma once

#include <type_traits>

namespace kk2 {

#define HAS_MEMBER_FUNC(member)                                                                    \
    template <typename T, typename... Ts> struct has_member_func_##member##_impl {                 \
        template <typename U>                                                                      \
        static std::true_type check(decltype(std::declval<U>().member(std::declval<Ts>()...)) *);  \
        template <typename U> static std::false_type check(...);                                   \
        using type = decltype(check<T>(nullptr));                                                  \
    };                                                                                             \
    template <typename T, typename... Ts>                                                          \
    struct has_member_func_##member : has_member_func_##member##_impl<T, Ts...>::type {};          \
    template <typename T, typename... Ts>                                                          \
    using has_member_func_##member##_t =                                                           \
        std::enable_if_t<has_member_func_##member<T, Ts...>::value>;                               \
    template <typename T, typename... Ts>                                                          \
    using not_has_member_func_##member##_t =                                                       \
        std::enable_if_t<!has_member_func_##member<T, Ts...>::value>;

#define HAS_MEMBER_VAR(member)                                                                     \
    template <typename T> struct has_member_var_##member##_impl {                                  \
        template <typename U> static std::true_type check(decltype(std::declval<U>().member) *);   \
        template <typename U> static std::false_type check(...);                                   \
        using type = decltype(check<T>(nullptr));                                                  \
    };                                                                                             \
    template <typename T>                                                                          \
    struct has_member_var_##member : has_member_var_##member##_impl<T>::type {};                   \
    template <typename T>                                                                          \
    using has_member_var_##member##_t = std::enable_if_t<has_member_var_##member<T>::value>;       \
    template <typename T>                                                                          \
    using not_has_member_var_##member##_t = std::enable_if_t<!has_member_var_##member<T>::value>;

HAS_MEMBER_FUNC(debug_output)


#undef HAS_MEMBER_FUNC
#undef HAS_MEMBER_VAR
} // namespace kk2

#endif // TYPE_TRAITS_MEMBER_HPP
