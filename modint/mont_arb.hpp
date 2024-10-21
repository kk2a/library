#ifndef MODINT_MONT_ARB_HPP
#define MODINT_MONT_ARB_HPP 1

#include <cassert>
#include <iostream>
#include <utility>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <typename Int, typename UInt, typename Long, typename ULong, int id>
struct ArbitraryLazyMontgomeryModIntBase {
    using mint = ArbitraryLazyMontgomeryModIntBase;

    inline static UInt mod;
    inline static UInt r;
    inline static UInt n2;
    static constexpr int bit_length = sizeof(UInt) * 8;

    static UInt get_r() {
        UInt ret = mod;
        while (mod * ret != 1) ret *= UInt(2) - mod * ret;
        return ret;
    }

    static void setmod(UInt m) {
        assert(m < (UInt(1u) << (bit_length - 2)));
        assert((m & 1) == 1);
        mod = m, n2 = -ULong(m) % m, r = get_r();
    }

    UInt _v;

    ArbitraryLazyMontgomeryModIntBase() : _v(0) {}

    template <class T, is_integral_t<T> * = nullptr>
    ArbitraryLazyMontgomeryModIntBase(const T &b) : _v(reduce(ULong(b % mod + mod) * n2)) {}

    static UInt reduce(const ULong &b) {
        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;
    }

    mint &operator+=(const mint &b) {
        if (Int(_v += b._v - 2 * mod) < 0) _v += 2 * mod;
        return *this;
    }

    mint &operator-=(const mint &b) {
        if (Int(_v -= b._v) < 0) _v += 2 * mod;
        return *this;
    }

    mint &operator*=(const mint &b) {
        _v = reduce(ULong(_v) * b._v);
        return *this;
    }

    mint &operator/=(const mint &b) {
        *this *= b.inv();
        return *this;
    }

    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }

    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }

    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }

    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }

    bool operator==(const mint &b) const {
        return (_v >= mod ? _v - mod : _v) == (b._v >= mod ? b._v - mod : b._v);
    }

    bool operator!=(const mint &b) const {
        return (_v >= mod ? _v - mod : _v) != (b._v >= mod ? b._v - mod : b._v);
    }

    mint operator-() const { return mint(0) - mint(*this); }

    mint operator+() const { return mint(*this); }

    template <class T> mint pow(T n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    mint inv() const {
        Int s = getmod(), t = val(), m0 = 0, m1 = 1;
        while (t) {
            Int u = s / t;
            std::swap(s -= t * u, t);
            std::swap(m0 -= m1 * u, m1);
        }
        if (m0 < 0) m0 += getmod();
        return mint(m0);
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const mint &x) {
        return os << x.val();
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, mint &x) {
        Long t;
        is >> t;
        x = mint(t);
        return (is);
    }

    UInt val() const {
        UInt ret = reduce(_v);
        return ret >= mod ? ret - mod : ret;
    }

    static UInt getmod() { return mod; }
};

template <int id>
using ArbitraryLazyMontgomeryModInt =
    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned long long, id>;

template <int id>
using ArbitraryLazyMontgomeryModInt64bit =
    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t, __uint128_t, id>;

} // namespace kk2

#endif // MODINT_MONT_ARB_HPP
