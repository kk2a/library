#ifndef KK2_GEOMETRY_POINT_HPP
#define KK2_GEOMETRY_POINT_HPP 1

#pragma once // oj-verify

#include <algorithm>
#include <cmath>

#include "../type_traits/type_traits.hpp"

namespace kk2 {

template <typename T> struct Point {
    static long double PI;
    T x, y;

    Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }

    bool operator<=(const Point &p) const { return x != p.x ? x < p.x : y <= p.y; }

    bool operator>(const Point &p) const { return x != p.x ? x > p.x : y > p.y; }

    bool operator>=(const Point &p) const { return x != p.x ? x > p.x : y >= p.y; }

    bool operator==(const Point &p) const { return x == p.x && y == p.y; }

    bool operator!=(const Point &p) const { return x != p.x || y != p.y; }

    Point &operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Point &operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Point &operator*=(T k) {
        x *= k;
        y *= k;
        return *this;
    }

    Point &operator/=(T k) {
        x /= k;
        y /= k;
        return *this;
    }

    Point operator+(const Point &p) const { return Point(*this) += p; }

    Point operator-(const Point &p) const { return Point(*this) -= p; }

    Point operator*(T k) const { return Point(*this) *= k; }

    Point operator/(T k) const { return Point(*this) /= k; }

    T dot(const Point &p) const { return x * p.x + y * p.y; }

    T cross(const Point &p) const { return x * p.y - y * p.x; }

    T cross(const Point &p, const Point &O) const { return (*this - O).cross(p - O); }

    T norm() const { return x * x + y * y; }

    T norm(const Point &p) const { return (p - *this).norm(); }

    long double abs() const { return sqrt(norm()); }

    long double dist(const Point &p) const { return (p - *this).abs(); }

    long double argument() const { return atan2(y, x); }

    // this -> p
    long double argument(const Point &p) const {
        long double res = p.argument() - argument();
        if (res < -PI) res += 2 * PI;
        if (res > PI) res -= 2 * PI;
        return res;
    }

    long double argument(const Point &p, const Point &O) const {
        return (*this - O).argument(p - O);
    }

    Point inplace_rotate90() {
        std::swap(x, y);
        x = -x;
        return *this;
    }

    Point inplace_rotate90(const Point &O) {
        *this -= O;
        inplace_rotate90();
        return *this += O;
    }

    Point rotate90() const { return Point(-y, x); }

    Point rotate90(Point O) const { return (*this - O).rotate90() + O; }

    Point inplace_rotate180() {
        x = -x;
        y = -y;
        return *this;
    }

    Point inplace_rotate180(const Point &O) {
        *this -= O;
        inplace_rotate180();
        return *this += O;
    }

    Point rotate180() const { return Point(-x, -y); }

    Point rotate180(const Point &O) const { return (*this - O).rotate180() + O; }

    Point inplace_rotate270() {
        std::swap(x, y);
        y = -y;
        return *this;
    }

    Point inplace_rotate270(const Point &O) {
        *this -= O;
        inplace_rotate270();
        return *this += O;
    }

    Point rotate270() const { return Point(y, -x); }

    Point rotate270(const Point &O) const { return (*this - O).rotate270() + O; }

    friend T dot(const Point &p, const Point &q) { return p.dot(q); }

    friend T cross(const Point &p, const Point &q) { return p.cross(q); }

    friend T cross(const Point &p, const Point &q, const Point &O) { return p.cross(q, O); }

    friend T norm(const Point &p) { return p.norm(); }

    friend T norm(const Point &p, const Point &q) { return p.norm(q); }

    friend long double abs(const Point &p) { return p.abs(); }

    friend long double dist(const Point &p, const Point &q) { return (p - q).abs(); }

    friend long double argument(const Point &p) { return p.argument(); }

    friend long double argument(const Point &p, const Point &q) { return p.argument(q); }

    friend long double argument(const Point &p, const Point &q, const Point &O) {
        return p.argument(q, O);
    }

    friend Point rotate90(const Point &p) { return p.rotate90(); }

    friend Point rotate90(const Point &p, const Point &O) { return p.rotate90(O); }

    friend Point rotate180(const Point &p) { return p.rotate180(); }

    friend Point rotate180(const Point &p, const Point &O) { return p.rotate180(O); }

    friend Point rotate270(const Point &p) { return p.rotate270(); }

    friend Point rotate270(const Point &p, const Point &O) { return p.rotate270(O); }

    template <class OStream, is_ostream_t<OStream> * = nullptr>
    friend OStream &operator<<(OStream &os, const Point &p) {
        return os << p.x << " " << p.y;
    }

    template <class IStream, is_istream_t<IStream> * = nullptr>
    friend IStream &operator>>(IStream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};
template <typename T> long double Point<T>::PI = std::acos(-1.0);

} // namespace kk2

#endif // KK2_GEOMETRY_POINT_HPP
