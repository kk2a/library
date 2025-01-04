#ifndef KK2_MODINT_MODINT_2_61M1_HPP
#define KK2_MODINT_MODINT_2_61M1_HPP 1

#include <cassert>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

struct ModInt2_61m1 {
    using mint = ModInt2_61m1;
    using u64 = unsigned long long;

    constexpr static u64 mod = (1ULL << 61) - 1;

    constexpr static u64 getmod() { return mod; }

    constexpr ModInt2_61m1() : _v(0) {}

    template <class T, is_integral_t<T> * = nullptr> constexpr ModInt2_61m1(T x_) {
        if (x_ < 0) {
            _v = -x_;
            chmod(_v);
            _v = mod - _v;
        } else {
            _v = x_;
            chmod(_v);
        }
    }

    constexpr mint &operator++() {
        ++_v;
        if (_v == mod) _v = 0;
        return *this;
    }

    constexpr mint &operator--() {
        if (_v == 0) _v = mod;
        --_v;
        return *this;
    }

    constexpr mint operator++(int) {
        mint ret = *this;
        ++*this;
        return ret;
    }

    constexpr mint operator--(int) {
        mint ret = *this;
        --*this;
        return ret;
    }

    constexpr mint &operator+=(const mint &x) {
        _v += x._v;
        if (_v >= mod) _v -= mod;
        return *this;
    }

    constexpr mint &operator-=(const mint &x) {
        _v += mod - x._v;
        if (_v >= mod) _v -= mod;
        return *this;
    }

    constexpr mint &operator*=(const mint &x) {
        _v = mulmod(_v, x._v);
        return *this;
    }

    constexpr mint &operator/=(const mint &x) { return *this *= x.inv(); }

    constexpr mint operator+() const { return *this; }

    constexpr mint operator-() const { return mint() - *this; }

    constexpr bool operator==(const mint &x) const { return _v == x._v; }

    constexpr bool operator!=(const mint &x) const { return _v != x._v; }

    friend constexpr mint operator+(const mint &x, const mint &y) { return mint(x) += y; }

    friend constexpr mint operator-(const mint &x, const mint &y) { return mint(x) -= y; }

    friend constexpr mint operator*(const mint &x, const mint &y) { return mint(x) *= y; }

    friend constexpr mint operator/(const mint &x, const mint &y) { return mint(x) /= y; }

    template <class T, is_integral_t<T> * = nullptr> constexpr mint pow(T n) const {
        assert(n >= 0);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    constexpr mint inv() const { return pow(mod - 2); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const mint &x) {
        return os << x._v;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, mint &x) {
        u64 y;
        is >> y;
        x = mint(y);
        return is;
    }

    constexpr u64 val() const { return _v; }

  private:
    u64 _v;

    constexpr static u64 chmod(u64 &x) {
        x = (x & mod) + (x >> 61);
        if (x >= mod) x -= mod;
        return x;
    }

    constexpr static u64 mask30 = (1ULL << 30) - 1;
    constexpr static u64 mask31 = (1ULL << 31) - 1;

    constexpr static u64 mulmod(u64 x, u64 y) {
        u64 xh = x >> 31, xl = x & mask31;
        u64 yh = y >> 31, yl = y & mask31;
        u64 m = xh * yl + xl * yh;
        u64 t = 2 * xh * yh + xl * yl + (m >> 30) + ((m & mask30) << 31);
        return chmod(t);
    }
};

} // namespace kk2

#endif // KK2_MODINT_MODINT_2_61M1_HPP
