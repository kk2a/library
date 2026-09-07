#ifndef KK2_BIT_BITCOUNT_HPP
#define KK2_BIT_BITCOUNT_HPP 1

#include <cassert>

#include "../type_traits/integral.hpp"

namespace kk2 {

template <Integral T> constexpr int ctz(T x) {
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

template <Integral T> constexpr int lsb(T x) {
    assert(x != T(0));

    return ctz(x);
}

template <Integral T> constexpr int clz(T x) {
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

template <Integral T> constexpr int msb(T x) {
    assert(x != T(0));

    return sizeof(T) * 8 - 1 - clz(x);
}

template <Integral T> constexpr int popcount(T x) {

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
