#ifndef KK2_TYPE_TRAITS_TYPE_TRAITS_HPP
#define KK2_TYPE_TRAITS_TYPE_TRAITS_HPP 1

#pragma once // oj-verify

#include <istream>
#include <ostream>
#include <type_traits>

namespace kk2 {

#ifndef _MSC_VER

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

#else

template <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;
template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;
template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;
template <typename T> using to_unsigned = std::make_unsigned<T>;

#endif // _MSC_VER

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

namespace type_traits {

struct istream_tag {};

struct ostream_tag {};

} // namespace type_traits

template <typename T>
using is_standard_istream = typename std::conditional<std::is_same<T, std::istream>::value
                                                          || std::is_same<T, std::ifstream>::value,
                                                      std::true_type,
                                                      std::false_type>::type;
template <typename T>
using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value
                                                          || std::is_same<T, std::ofstream>::value,
                                                      std::true_type,
                                                      std::false_type>::type;
template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;
template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;

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

#endif // KK2_TYPE_TRAITS_TYPE_TRAITS_HPP
