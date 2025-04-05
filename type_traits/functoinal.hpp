#ifndef KK2_TYPE_TRAITS_FUNCTOINAL_HPP
#define KK2_TYPE_TRAITS_FUNCTOINAL_HPP 1

#pragma once // oj-verify

#include <type_traits>

namespace kk2 {

template <typename T> using is_function_pointer =
    typename std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,
                              std::true_type,
                              std::false_type>::type;

template <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>
struct is_two_args_function_pointer : std::false_type {};

template <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R (*)(T1, T2)>
    : std::true_type {};

template <typename T> using is_two_args_function_pointer_t =
    std::enable_if_t<is_two_args_function_pointer<T>::value>;

} // namespace kk2

#endif // KK2_TYPE_TRAITS_FUNCTOINAL_HPP
