#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP 1

#pragma once // oj-verify

#include <type_traits>

namespace kk2 {

template <typename T>
using is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value
                                                       or std::is_same<T, __int128>::value,
                                                   std::true_type,
                                                   std::false_type>::type;

template <typename T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value
                                  or std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T>
using is_integral_extended =
    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value
                                  or is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T>
using is_signed_extended =
    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T>
using is_unsigned_extended =
    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;

template <typename T>
using to_unsigned =
    typename std::conditional<is_signed_int128<T>::value,
                              make_unsigned_int128<T>,
                              typename std::conditional<std::is_signed<T>::value,
                                                        std::make_unsigned<T>,
                                                        std::common_type<T>>::type>::type;

template <typename T>
using is_function_pointer =
    typename std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,
                              std::true_type,
                              std::false_type>::type;

template <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>
struct is_two_args_function_pointer : std::false_type {};

template <typename R, typename T1, typename T2>
struct is_two_args_function_pointer<R(*)(T1, T2)> : std::true_type {};

} // namespace kk2

#endif // TYPE_TRAITS_HPP
