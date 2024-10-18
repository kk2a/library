#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP 1

#pragma once // oj-verify

#include <istream>
#include <ostream>
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
using is_integral =
    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value
                                  or is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T>
using is_signed = typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,
                                            std::true_type,
                                            std::false_type>::type;

template <typename T>
using is_unsigned =
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

template <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;
template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;
template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;


template <typename T>
using is_function_pointer =
    typename std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>,
                              std::true_type,
                              std::false_type>::type;

template <typename T, std::enable_if_t<is_function_pointer<T>::value> * = nullptr>
struct is_two_args_function_pointer : std::false_type {};

template <typename R, typename T1, typename T2>
struct is_two_args_function_pointer<R (*)(T1, T2)> : std::true_type {};

template <typename T>
using is_two_args_function_pointer_t = std::enable_if_t<is_two_args_function_pointer<T>::value>;

namespace internal {

struct istream_tag {};

struct ostream_tag {};

} // namespace internal

template <typename T> using is_standard_istream = std::is_same<T, std::istream>;
template <typename T> using is_standard_ostream = std::is_same<T, std::ostream>;
template <typename T> using is_user_defined_istream = std::is_base_of<internal::istream_tag, T>;
template <typename T> using is_user_defined_ostream = std::is_base_of<internal::ostream_tag, T>;

template <typename T>
using is_istream =
    typename std::conditional<is_standard_istream<T>::value || is_user_defined_istream<T>::value,
                     std::true_type,
                     std::false_type>::type;

template <typename T>
using is_ostream =
    typename std::conditional<is_standard_ostream<T>::value || is_user_defined_ostream<T>::value,
                     std::true_type,
                     std::false_type>::type;

template <typename T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;
template <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;


} // namespace kk2

#endif // TYPE_TRAITS_HPP
