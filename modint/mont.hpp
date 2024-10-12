#ifndef MODINT_MONT_HPP
#define MODINT_MONT_HPP 1

#include <cassert>
#include <cstdint>
#include <iostream>
#include <type_traits>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <int p> struct LazyMontgomeryModInt {
    using mint = LazyMontgomeryModInt;
    using i32 = int32_t;
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    static constexpr u32 get_r() {
        u32 ret = p;
        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;
        return ret;
    }

    static constexpr u32 r = get_r();
    static constexpr u32 n2 = -u64(p) % p;
    static_assert(r * p == 1, "invalid, r * p != 1");
    static_assert(p < (1 << 30), "invalid, p >= 2 ^ 30");
    static_assert((p & 1) == 1, "invalid, p % 2 == 0");

    u32 _v;

    operator int() const { return val(); }

    constexpr LazyMontgomeryModInt() : _v(0) {}

    template <typename T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p) * n2)) {}

    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * p) >> 32; }

    constexpr mint &operator++() { return *this += 1; }

    constexpr mint &operator--() { return *this -= 1; }

    constexpr mint operator++(int) {
        mint ret = *this;
        *this += 1;
        return ret;
    }

    constexpr mint operator--(int) {
        mint ret = *this;
        *this -= 1;
        return ret;
    }

    constexpr mint &operator+=(const mint &b) {
        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;
        return *this;
    }

    constexpr mint &operator-=(const mint &b) {
        if (i32(_v -= b._v) < 0) _v += 2 * p;
        return *this;
    }

    constexpr mint &operator*=(const mint &b) {
        _v = reduce(u64(_v) * b._v);
        return *this;
    }

    constexpr mint &operator/=(const mint &b) {
        *this *= b.inv();
        return *this;
    }

    constexpr mint operator-() const { return mint() - mint(*this); }

    constexpr bool operator==(const mint &b) const {
        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);
    }

    constexpr bool operator!=(const mint &b) const {
        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);
    }

    friend constexpr mint operator+(const mint &a, const mint &b) { return mint(a) += b; }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator+(const mint &a, T b) {
        return mint(a) += mint(b);
    }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator+(T a, const mint &b) {
        return mint(a) += b;
    }

    friend constexpr mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator-(const mint &a, T b) {
        return mint(a) -= mint(b);
    }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator-(T a, const mint &b) {
        return mint(a) -= b;
    }

    friend constexpr mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator*(const mint &a, T b) {
        return mint(a) *= mint(b);
    }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator*(T a, const mint &b) {
        return mint(a) *= b;
    }

    friend constexpr mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator/(const mint &a, T b) {
        return mint(a) /= mint(b);
    }

    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>
    friend constexpr mint operator/(T a, const mint &b) {
        return mint(a) /= b;
    }

    template <class T> constexpr mint pow(T n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    constexpr mint inv() const { return pow(p - 2); }

    template <class OStream> friend OStream &operator<<(OStream &os, const mint &x) {
        return os << x.val();
    }

    template <class IStream> friend IStream &operator>>(IStream &is, mint &x) {
        i64 t;
        is >> t;
        x = mint(t);
        return (is);
    }

    constexpr u32 val() const {
        u32 ret = reduce(_v);
        return ret >= p ? ret - p : ret;
    }

    static constexpr u32 getmod() { return p; }
};

template <int p> using Mont = LazyMontgomeryModInt<p>;


using mont998 = Mont<998244353>;
using mont107 = Mont<1000000007>;

} // namespace kk2

#endif // MODINT_MONT_HPP
