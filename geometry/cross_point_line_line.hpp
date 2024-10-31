#ifndef GEOMETRY_CROSS_POINT_LINE_LINE_HPP
#define GEOMETRY_CROSS_POINT_LINE_LINE_HPP 1

#include <optional>

#include "line.hpp"
#include "../math/rational.hpp"

namespace kk2 {

template <typename T>
std::optional<Point<Rational<T>>> cross_point(const Line<T> &l, const Line<T> &m) {
    // Cramer's rule
    T det = l.a * m.b - l.b * m.a;
    if (det == 0) return std::nullopt;
    T x = l.b * m.c - l.c * m.b;
    T y = l.c * m.a - l.a * m.c;
    return Point<T>(Rational<T>(x, det), Rational<T>(y, det));
}

}

#endif // GEOMETRY_CROSS_POINT_LINE_LINE_HPP
