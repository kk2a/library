#ifndef KK2_TYPE_TRAITS_FUNCTIONAL_HPP
#define KK2_TYPE_TRAITS_FUNCTIONAL_HPP 1

#include <concepts>
#include <type_traits>

#include "integral.hpp"

namespace kk2 {

template <typename T> using is_function_pointer = typename std::conditional<std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>, std::true_type, std::false_type>::type;
template <typename T> struct is_two_args_function_pointer : std::false_type {};
template <typename R, typename T1, typename T2> struct is_two_args_function_pointer<R (*)(T1, T2)> : std::true_type {
    using return_type = R;
    using first_argument_type = T1;
    using second_argument_type = T2;
};
template <typename T> using is_two_args_function_pointer_t = std::enable_if_t<is_two_args_function_pointer<T>::value>;
template <class T> concept FunctionPointer = is_function_pointer<T>::value;
template <class T> concept TwoArgsFunctionPointer = is_two_args_function_pointer<T>::value;
template <class T> concept UnsignedTwoArgsFunctionPointer = TwoArgsFunctionPointer<T> && requires {
    typename is_two_args_function_pointer<T>::first_argument_type;
    typename is_two_args_function_pointer<T>::second_argument_type;
} && UnsignedIntegral<typename is_two_args_function_pointer<T>::first_argument_type> && UnsignedIntegral<typename is_two_args_function_pointer<T>::second_argument_type>;

} // namespace kk2

#endif // KK2_TYPE_TRAITS_FUNCTIONAL_HPP
