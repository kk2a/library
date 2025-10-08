#ifndef KK2_TYPE_TRAITS_IO_HPP
#define KK2_TYPE_TRAITS_IO_HPP 1

#include <istream>
#include <ostream>
#include <type_traits>

namespace kk2 {

namespace type_traits {

struct istream_tag {};
struct ostream_tag {};

} // namespace type_traits

template <typename T> using is_standard_istream =
    typename std::conditional<std::is_same<T, std::istream>::value
                                  || std::is_same<T, std::ifstream>::value,
                              std::true_type,
                              std::false_type>::type;
template <typename T> using is_standard_ostream =
    typename std::conditional<std::is_same<T, std::ostream>::value
                                  || std::is_same<T, std::ofstream>::value,
                              std::true_type,
                              std::false_type>::type;
template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag, T>;
template <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;

template <typename T> using is_istream =
    typename std::conditional<is_standard_istream<T>::value || is_user_defined_istream<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T> using is_ostream =
    typename std::conditional<is_standard_ostream<T>::value || is_user_defined_ostream<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <typename T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;
template <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;

} // namespace kk2

#endif // KK2_TYPE_TRAITS_IO_HPP
