#ifndef KK2_MATH_RATIONAL_HPP
#define KK2_MATH_RATIONAL_HPP 1

#include <numeric>

#include "../type_traits/io.hpp"

namespace kk2 {

namespace rational {

template <typename T, typename Compare> struct RationalBase {
    using B = RationalBase;
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

    static B raw(T a_, T b_) {
        B res;
        res.a = a_, res.b = b_;
        return res;
    }

    operator bool() const { return a; }
    double to_double() const { return (double)a / b; }
    long double to_ldouble() const { return (long double)a / b; }

    friend B operator+(const B &lhs, const B &rhs) {
        if (lhs.b == rhs.b) return B(lhs.a + rhs.a, lhs.b);
        return B(lhs.a * rhs.b + rhs.a * lhs.b, lhs.b * rhs.b);
    }

    friend B operator-(const B &lhs, const B &rhs) {
        if (lhs.b == rhs.b) return B(lhs.a - rhs.a, lhs.b);
        return B(lhs.a * rhs.b - rhs.a * lhs.b, lhs.b * rhs.b);
    }

    friend B operator*(const B &lhs, const B &rhs) { return B(lhs.a * rhs.a, lhs.b * rhs.b); }
    friend B operator/(const B &lhs, const B &rhs) { return B(lhs.a * rhs.b, lhs.b * rhs.a); }
    B &operator+=(const B &rhs) { return (*this) = (*this) + rhs; }
    B &operator-=(const B &rhs) { return (*this) = (*this) - rhs; }
    B &operator*=(const B &rhs) { return (*this) = (*this) * rhs; }
    B &operator/=(const B &rhs) { return (*this) = (*this) / rhs; }
    B operator-() const { return raw(-a, b); }
    B operator+() const { return *this; }
    B inv() const { return a < 0 ? raw(-b, -a) : raw(b, a); }
    B abs() const { return a < 0 ? raw(-a, b) : *this; }
    friend bool operator==(const B &lhs, const B &rhs) { return lhs.a == rhs.a and lhs.b == rhs.b; }
    friend bool operator!=(const B &lhs, const B &rhs) { return !(lhs == rhs); }
    friend bool operator<(const B &lhs, const B &rhs) {
        return Compare{lhs.a} * rhs.b < Compare{rhs.a} * lhs.b;
    }
    friend bool operator>(const B &lhs, const B &rhs) {
        return Compare{lhs.a} * rhs.b > Compare{rhs.a} * lhs.b;
    }
    friend bool operator<=(const B &lhs, const B &rhs) { return lhs == rhs or lhs < rhs; }
    friend bool operator>=(const B &lhs, const B &rhs) { return lhs == rhs or lhs > rhs; }
    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const B &rhs) {
        return os << rhs.a << " / " << rhs.b;
    }
};

} // namespace rational

template <typename T> using Rational = rational::RationalBase<T, T>;
using RationalInt = rational::RationalBase<int, long long>;
using RationalI64 = rational::RationalBase<long long, __int128>;

} // namespace kk2

#endif // KK2_MATH_RATIONAL_HPP
