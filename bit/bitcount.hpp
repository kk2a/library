#ifndef KK2_BIT_BITCOUNT_HPP
#define KK2_BIT_BITCOUNT_HPP 1

#include <cassert>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <typename T> int ctz(T x) {
    static_assert(is_integral<T>::value);
    assert(x != T(0));

    if constexpr (sizeof(T) <= 4) {
        return __builtin_ctz(x);
    } else if constexpr (sizeof(T) <= 8) {
        return __builtin_ctzll(x);
    } else {
        if (x & 0xffffffffffffffff)
            return __builtin_ctzll((unsigned long long)(x & 0xffffffffffffffff));
        return 64 + __builtin_ctzll((unsigned long long)(x >> 64));
    }
}

template <typename T> int lsb(T x) {
    static_assert(is_integral<T>::value);
    assert(x != T(0));

    return ctz(x);
}

template <typename T> int clz(T x) {
    static_assert(is_integral<T>::value);
    assert(x != T(0));

    if constexpr (sizeof(T) <= 4) {
        return __builtin_clz(x);
    } else if constexpr (sizeof(T) <= 8) {
        return __builtin_clzll(x);
    } else {
        if (x >> 64) return __builtin_clzll((unsigned long long)(x >> 64));
        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));
    }
}

template <typename T> int msb(T x) {
    static_assert(is_integral<T>::value);
    assert(x != T(0));

    return sizeof(T) * 8 - 1 - clz(x);
}

template <typename T> int popcount(T x) {
    static_assert(is_integral<T>::value);

    if constexpr (sizeof(T) <= 4) {
        return __builtin_popcount(x);
    } else if constexpr (sizeof(T) <= 8) {
        return __builtin_popcountll(x);
    } else {
        return __builtin_popcountll((unsigned long long)(x >> 64))
               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));
    }
}

}; // namespace kk2

#endif // KK2_BIT_BITCOUNT_HPP
