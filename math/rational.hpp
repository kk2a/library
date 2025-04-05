#ifndef KK2_MATH_RATIONAL_HPP
#define KK2_MATH_RATIONAL_HPP 1

#include <numeric>

#include "../type_traits/io.hpp"

namespace kk2 {

namespace rational {

template <typename T, typename Compare> struct RationalBase {
    T a, b;

    // a / b

    RationalBase() : a(0), b(1) {}

    RationalBase(T a_) : a(a_), b(1) {}

    RationalBase(T a_, T b_) : a(a_), b(b_) {
        assert(b);
        if (b < 0) a = -a, b = -b;
        T g = std::gcd(a, b);
        a /= g, b /= g;
    }

    static RationalBase raw(T a_, T b_) {
        T res;
        res.a = a_, res.b = b_;
        return res;
    }

    operator bool() const { return a; }

    double to_double() const { return (double)a / b; }

    long double to_ldouble() const { return (long double)a / b; }

    friend RationalBase operator+(const RationalBase &lhs, const RationalBase &rhs) {
        if (lhs.b == rhs.b) return RationalBase(lhs.a + rhs.a, lhs.b);
        return RationalBase(lhs.a * rhs.b + rhs.a * lhs.b, lhs.b * rhs.b);
    }

    friend RationalBase operator-(const RationalBase &lhs, const RationalBase &rhs) {
        if (lhs.b == rhs.b) return RationalBase(lhs.a - rhs.a, lhs.b);
        return RationalBase(lhs.a * rhs.b - rhs.a * lhs.b, lhs.b * rhs.b);
    }

    friend RationalBase operator*(const RationalBase &lhs, const RationalBase &rhs) {
        return RationalBase(lhs.a * rhs.a, lhs.b * rhs.b);
    }

    friend RationalBase operator/(const RationalBase &lhs, const RationalBase &rhs) {
        return RationalBase(lhs.a * rhs.b, lhs.b * rhs.a);
    }

    RationalBase &operator+=(const RationalBase &rhs) { return (*this) = (*this) + rhs; }

    RationalBase &operator-=(const RationalBase &rhs) { return (*this) = (*this) - rhs; }

    RationalBase &operator*=(const RationalBase &rhs) { return (*this) = (*this) * rhs; }

    RationalBase &operator/=(const RationalBase &rhs) { return (*this) = (*this) / rhs; }

    RationalBase operator-() const { return raw(-a, b); }

    RationalBase operator+() const { return *this; }

    RationalBase inv() const { return a < 0 ? raw(-b, -a) : raw(b, a); }

    RationalBase abs() const { return a < 0 ? raw(-a, b) : *this; }

    RationalBase pow(long long k) const {
        RationalBase res(1), base = *this;
        while (k) {
            if (k & 1) res *= base;
            base *= base;
            k >>= 1;
        }
        return res;
    }

    friend bool operator==(const RationalBase &lhs, const RationalBase &rhs) {
        return lhs.a == rhs.a and lhs.b == rhs.b;
    }

    friend bool operator!=(const RationalBase &lhs, const RationalBase &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const RationalBase &lhs, const RationalBase &rhs) {
        return Compare{lhs.a} * rhs.b < Compare{rhs.a} * lhs.b;
    }

    friend bool operator>(const RationalBase &lhs, const RationalBase &rhs) {
        return Compare{lhs.a} * rhs.b > Compare{rhs.a} * lhs.b;
    }

    friend bool operator<=(const RationalBase &lhs, const RationalBase &rhs) {
        return lhs == rhs or lhs < rhs;
    }

    friend bool operator>=(const RationalBase &lhs, const RationalBase &rhs) {
        return lhs == rhs or lhs > rhs;
    }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const RationalBase &rhs) {
        return os << rhs.a << " / " << rhs.b;
    }
};

} // namespace rational

template <typename T> using Rational = rational::RationalBase<T, T>;
using RationalInt = rational::RationalBase<int, long long>;
using RationalI64 = rational::RationalBase<long long, __int128>;

} // namespace kk2

#endif // KK2_MATH_RATIONAL_HPP
