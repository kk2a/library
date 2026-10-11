#ifndef KK2_TYPE_TRAITS_MEMBER_HPP
#define KK2_TYPE_TRAITS_MEMBER_HPP 1

#include <utility>

namespace kk2 {

template <class T, class... Ts> concept HasDebugOutput = requires { std::declval<T>().debug_output(std::declval<Ts>()...); };
template <class T, class... Ts> concept HasVal = requires { std::declval<T>().val(std::declval<Ts>()...); };
} // namespace kk2

#endif // KK2_TYPE_TRAITS_MEMBER_HPP
