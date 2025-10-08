---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':x:'
    path: math/rational.hpp
    title: math/rational.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/cross_point_line_line.hpp\"\n\n\n\n#include <optional>\n\
    \n#line 1 \"math/rational.hpp\"\n\n\n\n#include <numeric>\n\n#line 1 \"type_traits/io.hpp\"\
    \n\n\n\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
    \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"math/rational.hpp\"\n\nnamespace kk2 {\n\nnamespace rational\
    \ {\n\ntemplate <typename T, typename Compare> struct RationalBase {\n    using\
    \ B = RationalBase;\n    T a, b;\n    // a / b\n    RationalBase() : a(0), b(1)\
    \ {}\n    RationalBase(T a_) : a(a_), b(1) {}\n    RationalBase(T a_, T b_) :\
    \ a(a_), b(b_) {\n        assert(b);\n        if (b < 0) a = -a, b = -b;\n   \
    \     T g = std::gcd(a, b);\n        a /= g, b /= g;\n    }\n\n    static B raw(T\
    \ a_, T b_) {\n        B res;\n        res.a = a_, res.b = b_;\n        return\
    \ res;\n    }\n\n    operator bool() const { return a; }\n    double to_double()\
    \ const { return (double)a / b; }\n    long double to_ldouble() const { return\
    \ (long double)a / b; }\n\n    friend B operator+(const B &lhs, const B &rhs)\
    \ {\n        if (lhs.b == rhs.b) return B(lhs.a + rhs.a, lhs.b);\n        return\
    \ B(lhs.a * rhs.b + rhs.a * lhs.b, lhs.b * rhs.b);\n    }\n\n    friend B operator-(const\
    \ B &lhs, const B &rhs) {\n        if (lhs.b == rhs.b) return B(lhs.a - rhs.a,\
    \ lhs.b);\n        return B(lhs.a * rhs.b - rhs.a * lhs.b, lhs.b * rhs.b);\n \
    \   }\n\n    friend B operator*(const B &lhs, const B &rhs) { return B(lhs.a *\
    \ rhs.a, lhs.b * rhs.b); }\n    friend B operator/(const B &lhs, const B &rhs)\
    \ { return B(lhs.a * rhs.b, lhs.b * rhs.a); }\n    B &operator+=(const B &rhs)\
    \ { return (*this) = (*this) + rhs; }\n    B &operator-=(const B &rhs) { return\
    \ (*this) = (*this) - rhs; }\n    B &operator*=(const B &rhs) { return (*this)\
    \ = (*this) * rhs; }\n    B &operator/=(const B &rhs) { return (*this) = (*this)\
    \ / rhs; }\n    B operator-() const { return raw(-a, b); }\n    B operator+()\
    \ const { return *this; }\n    B inv() const { return a < 0 ? raw(-b, -a) : raw(b,\
    \ a); }\n    B abs() const { return a < 0 ? raw(-a, b) : *this; }\n    friend\
    \ bool operator==(const B &lhs, const B &rhs) { return lhs.a == rhs.a and lhs.b\
    \ == rhs.b; }\n    friend bool operator!=(const B &lhs, const B &rhs) { return\
    \ !(lhs == rhs); }\n    friend bool operator<(const B &lhs, const B &rhs) {\n\
    \        return Compare{lhs.a} * rhs.b < Compare{rhs.a} * lhs.b;\n    }\n    friend\
    \ bool operator>(const B &lhs, const B &rhs) {\n        return Compare{lhs.a}\
    \ * rhs.b > Compare{rhs.a} * lhs.b;\n    }\n    friend bool operator<=(const B\
    \ &lhs, const B &rhs) { return lhs == rhs or lhs < rhs; }\n    friend bool operator>=(const\
    \ B &lhs, const B &rhs) { return lhs == rhs or lhs > rhs; }\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const B &rhs) {\n        return os << rhs.a << \" / \" << rhs.b;\n    }\n\
    };\n\n} // namespace rational\n\ntemplate <typename T> using Rational = rational::RationalBase<T,\
    \ T>;\nusing RationalInt = rational::RationalBase<int, long long>;\nusing RationalI64\
    \ = rational::RationalBase<long long, __int128>;\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"geometry/line.hpp\"\n\n\n\n#line 5 \"geometry/line.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace geometry::line {\n\ntemplate <typename T, typename U> struct\
    \ LineBase {\n    // ax + by + c = 0\n    T a, b, c;\n\n    LineBase() : a(0),\
    \ b(0), c(0) {}\n\n    LineBase(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}\n\n\
    \    friend bool operator==(const LineBase &l, const LineBase &m) {\n        return\
    \ U(m.a) * l.b == U(l.a) * m.b and U(m.a) * l.c == U(l.a) * m.c;\n    }\n\n  \
    \  friend bool operator!=(const LineBase &l, const LineBase &m) { return !(l ==\
    \ m); }\n\n    bool operator<(const LineBase &m) {\n        if (a != m.a) return\
    \ a < m.a;\n        if (b != m.b) return b < m.b;\n        return c < m.c;\n \
    \   }\n};\n\n} // namespace geometry::line\n\ntemplate <typename T> using Line\
    \ = geometry::line::LineBase<T, T>;\ntemplate <> using Line<int> = geometry::line::LineBase<int,\
    \ long long>;\ntemplate <> using Line<long long> = geometry::line::LineBase<long\
    \ long, __int128_t>;\n\n} // namespace kk2\n\n\n#line 8 \"geometry/cross_point_line_line.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T>\nstd::optional<Point<Rational<T>>>\
    \ cross_point(const Line<T> &l, const Line<T> &m) {\n    // Cramer's rule\n  \
    \  T det = l.a * m.b - l.b * m.a;\n    if (det == 0) return std::nullopt;\n  \
    \  T x = l.b * m.c - l.c * m.b;\n    T y = l.c * m.a - l.a * m.c;\n    return\
    \ Point<T>(Rational<T>(x, det), Rational<T>(y, det));\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_GEOMETRY_CROSS_POINT_LINE_LINE_HPP\n#define KK2_GEOMETRY_CROSS_POINT_LINE_LINE_HPP\
    \ 1\n\n#include <optional>\n\n#include \"../math/rational.hpp\"\n#include \"line.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T>\nstd::optional<Point<Rational<T>>>\
    \ cross_point(const Line<T> &l, const Line<T> &m) {\n    // Cramer's rule\n  \
    \  T det = l.a * m.b - l.b * m.a;\n    if (det == 0) return std::nullopt;\n  \
    \  T x = l.b * m.c - l.c * m.b;\n    T y = l.c * m.a - l.a * m.c;\n    return\
    \ Point<T>(Rational<T>(x, det), Rational<T>(y, det));\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_GEOMETRY_CROSS_POINT_LINE_LINE_HPP\n"
  dependsOn:
  - math/rational.hpp
  - type_traits/io.hpp
  - geometry/line.hpp
  isVerificationFile: false
  path: geometry/cross_point_line_line.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/cross_point_line_line.hpp
layout: document
redirect_from:
- /library/geometry/cross_point_line_line.hpp
- /library/geometry/cross_point_line_line.hpp.html
title: geometry/cross_point_line_line.hpp
---
