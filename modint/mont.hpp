#ifndef MODINT_MONT_HPP
#define MODINT_MONT_HPP 1

template <int p>
struct LazyMontgomeryModInt {
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

    constexpr LazyMontgomeryModInt() : _v(0) {}
    constexpr LazyMontgomeryModInt(const i64& b)
         : _v(reduce(u64(b % p + p) * n2)) {}

    static constexpr u32 reduce(const u64& b) {
        return (b + u64(u32(b) * u32(-r)) * p) >> 32;
    }
    constexpr mint& operator+=(const mint& b) {
        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;
        return *this;
    }
    constexpr mint& operator-=(const mint& b) {
        if (i32(_v -= b._v) < 0) _v += 2 * p;
        return *this;
    }
    constexpr mint& operator*=(const mint& b) {
        _v = reduce(u64(_v) * b._v);
        return *this;
    }
    constexpr mint& operator/=(const mint& b) {
        *this *= b.inv();
        return *this;
    }

    constexpr mint operator+(const mint& b) const { return mint(*this) += b; }
    constexpr mint operator-(const mint& b) const { return mint(*this) -= b; }
    constexpr mint operator-() const { return mint() - mint(*this); }
    constexpr mint operator*(const mint& b) const { return mint(*this) *= b; }
    constexpr mint operator/(const mint& b) const { return mint(*this) /= b; }
    constexpr bool operator==(const mint &b) const {
        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);
    }
    constexpr bool operator!=(const mint &b) const {
        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);
    }

    template <class T>
    constexpr mint pow(T n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    constexpr mint inv() const { return pow(p - 2); }

    friend ostream& operator<<(ostream& os, const mint& x) {
        return os << x.val();
    }
    friend istream& operator>>(istream& is, mint& x) {
        i64 t; is >> t; x = mint(t);
        return (is);
    }

    constexpr u32 val() const {
        u32 ret = reduce(_v);
        return ret >= p ? ret - p : ret;
    }
    static constexpr u32 getmod() { return p; }
};

template <int p>
using Mont = LazyMontgomeryModInt<p>;

using Mont998 = Mont<998244353>;
using Mont107 = Mont<1000000007>;

#endif  // MODINT_MONT_HPP
