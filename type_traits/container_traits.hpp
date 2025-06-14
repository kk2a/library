#ifndef KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP
#define KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP 1

#pragma once // oj-verify

#include <array>
#include <deque>
#include <list>
#include <string>
#include <type_traits>
#include <vector>

namespace kk2 {

template <typename T> struct is_vector : std::false_type {};
template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>> : std::true_type {};

// コンテナかどうかを判定するtraits
template <typename T> struct is_container : std::false_type {};

// 基本的なコンテナ型の特殊化
template <typename T, typename Alloc> struct is_container<std::vector<T, Alloc>> : std::true_type {
};

template <typename CharT, typename Traits, typename Alloc>
struct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type {};

template <typename T, std::size_t N> struct is_container<std::array<T, N>> : std::true_type {};

template <typename T, typename Alloc> struct is_container<std::deque<T, Alloc>> : std::true_type {};

template <typename T, typename Alloc> struct is_container<std::list<T, Alloc>> : std::true_type {};

// SFINAEでコンテナを判定するためのヘルパー
template <typename T> using is_container_t =
    typename std::enable_if_t<is_container<T>::value, std::nullptr_t>;

} // namespace kk2

#endif // KK2_TYPE_TRAITS_CONTAINER_TRAITS_HPP
