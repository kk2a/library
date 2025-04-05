#ifndef KK2_GEOMETRY_LINE_HPP
#define KK2_GEOMETRY_LINE_HPP 1

#include <numeric>

namespace kk2 {

namespace geometry::line {

template <typename T, typename U> struct LineBase {
    // ax + by + c = 0
    T a, b, c;

    LineBase() : a(0), b(0), c(0) {}

    LineBase(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}

    friend bool operator==(const LineBase &l, const LineBase &m) {
        return U(m.a) * l.b == U(l.a) * m.b and U(m.a) * l.c == U(l.a) * m.c;
    }

    friend bool operator!=(const LineBase &l, const LineBase &m) { return !(l == m); }

    bool operator<(const LineBase &m) {
        if (a != m.a) return a < m.a;
        if (b != m.b) return b < m.b;
        return c < m.c;
    }
};

} // namespace geometry::line

template <typename T> using Line = geometry::line::LineBase<T, T>;
template <> using Line<int> = geometry::line::LineBase<int, long long>;
template <> using Line<long long> = geometry::line::LineBase<long long, __int128_t>;

} // namespace kk2

#endif // KK2_GEOMETRY_LINE_HPP
