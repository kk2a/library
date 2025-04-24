#ifndef KK2_MODINT_F2_HPP
#define KK2_MODINT_F2_HPP 1

#include <cassert>

#include "../type_traits/integral.hpp"
#include "../type_traits/io.hpp"

namespace kk2 {

struct F2 {
    bool _v;

    constexpr static unsigned int getmod() { return 2; }
    constexpr F2() : _v(0) {}
    constexpr F2(bool v) : _v(v) {}
    template <class T, is_integral_t<T> * = nullptr> constexpr F2(T v) : _v(v & 1) {}
    unsigned int val() const { return _v; }
    constexpr F2 &operator++() {
        _v = !_v;
        return *this;
    }
    constexpr F2 &operator--() {
        _v = !_v;
        return *this;
    }
    constexpr F2 operator++(int) {
        F2 ret = *this;
        _v = !_v;
        return ret;
    }
    constexpr F2 operator--(int) {
        F2 ret = *this;
        _v = !_v;
        return ret;
    }
    constexpr F2 &operator+=(const F2 &b) {
        _v ^= b._v;
        return *this;
    }
    constexpr F2 &operator-=(const F2 &b) {
        _v ^= b._v;
        return *this;
    }
    constexpr F2 &operator*=(const F2 &b) {
        _v &= b._v;
        return *this;
    }
    constexpr F2 &operator/=(const F2 &b) {
        assert(b._v != 0);
        return *this;
    }
    constexpr F2 operator-() const { return F2(_v); }
    constexpr F2 operator+() const { return F2(_v); }
    friend constexpr F2 operator+(const F2 &a, const F2 &b) { return F2(a) += b; }
    friend constexpr F2 operator-(const F2 &a, const F2 &b) { return F2(a) -= b; }
    friend constexpr F2 operator*(const F2 &a, const F2 &b) { return F2(a) *= b; }
    friend constexpr F2 operator/(const F2 &a, const F2 &b) { return F2(a) /= b; }
    friend constexpr bool operator==(const F2 &a, const F2 &b) { return a._v == b._v; }
    friend constexpr bool operator!=(const F2 &a, const F2 &b) { return a._v != b._v; }
    constexpr F2 pow(long long n) const {
        assert(0 <= n);
        return n ? F2(_v) : F2(1);
    }
    constexpr F2 inv() const {
        assert(_v != 0);
        return F2(_v);
    }
    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const F2 &a) {
        os << a._v;
        return os;
    }
    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, F2 &a) {
        bool x;
        is >> x;
        a = F2(x);
        return is;
    }
};

} // namespace kk2

#endif // KK2_MODINT_F2_HPP
