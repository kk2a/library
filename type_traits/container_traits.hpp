#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP
#define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP 1

#pragma once // oj-verify

#include <type_traits>
#include <vector>

namespace kk2 {

template <typename T> struct is_vector : std::false_type {};
template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>> : std::true_type {};

} // namespace kk2

#endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP
