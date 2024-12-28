---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geometry/argument_sort.hpp
    title: geometry/argument_sort.hpp
  - icon: ':x:'
    path: geometry/static_convex_hull.hpp
    title: geometry/static_convex_hull.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_geometry/arg_sort.test.cpp
    title: verify/yosupo_geometry/arg_sort.test.cpp
  - icon: ':x:'
    path: verify/yosupo_geometry/static_convex_hull.test.cpp
    title: verify/yosupo_geometry/static_convex_hull.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/point.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GEOMETRY_POINT_HPP\n#define GEOMETRY_POINT_HPP 1\n\n#pragma once\
    \ // oj-verify\n\n#include <algorithm>\n#include <cmath>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> struct Point {\n    static constexpr\
    \ long double PI = acos(-1.0);\n    T x, y;\n\n    Point(T x = 0, T y = 0) : x(x),\
    \ y(y) {}\n\n    bool operator<(const Point &p) const { return x != p.x ? x <\
    \ p.x : y < p.y; }\n\n    bool operator<=(const Point &p) const { return x !=\
    \ p.x ? x < p.x : y <= p.y; }\n\n    bool operator>(const Point &p) const { return\
    \ x != p.x ? x > p.x : y > p.y; }\n\n    bool operator>=(const Point &p) const\
    \ { return x != p.x ? x > p.x : y >= p.y; }\n\n    bool operator==(const Point\
    \ &p) const { return x == p.x && y == p.y; }\n\n    bool operator!=(const Point\
    \ &p) const { return x != p.x || y != p.y; }\n\n    Point &operator+=(const Point\
    \ &p) {\n        x += p.x;\n        y += p.y;\n        return *this;\n    }\n\n\
    \    Point &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n\
    \        return *this;\n    }\n\n    Point &operator*=(T k) {\n        x *= k;\n\
    \        y *= k;\n        return *this;\n    }\n\n    Point &operator/=(T k) {\n\
    \        x /= k;\n        y /= k;\n        return *this;\n    }\n\n    Point operator+(const\
    \ Point &p) const { return Point(*this) += p; }\n\n    Point operator-(const Point\
    \ &p) const { return Point(*this) -= p; }\n\n    Point operator*(T k) const {\
    \ return Point(*this) *= k; }\n\n    Point operator/(T k) const { return Point(*this)\
    \ /= k; }\n\n    T dot(const Point &p) const { return x * p.x + y * p.y; }\n\n\
    \    T cross(const Point &p) const { return x * p.y - y * p.x; }\n\n    T cross(const\
    \ Point &p, const Point &O) const { return (*this - O).cross(p - O); }\n\n   \
    \ T norm() const { return x * x + y * y; }\n\n    T norm(const Point &p) const\
    \ { return (p - *this).norm(); }\n\n    long double abs() const { return sqrt(norm());\
    \ }\n\n    long double dist(const Point &p) const { return (p - *this).abs();\
    \ }\n\n    long double argument() const { return atan2(y, x); }\n\n    long double\
    \ argument(const Point &p) const {\n        long double res = argument() - p.argument();\n\
    \        if (res < -PI) res += 2 * PI;\n        if (res > PI) res -= 2 * PI;\n\
    \        return res;\n    }\n\n    long double argument(const Point &p, const\
    \ Point &O) const {\n        return (*this - O).argument(p - O);\n    }\n\n  \
    \  Point inplace_rotate90() {\n        std::swap(x, y);\n        x = -x;\n   \
    \     return *this;\n    }\n\n    Point inplace_rotate90(const Point &O) {\n \
    \       *this -= O;\n        inplace_rotate90();\n        return *this += O;\n\
    \    }\n\n    Point rotate90() const { return Point(-y, x); }\n\n    Point rotate90(Point\
    \ O) const { return (*this - O).rotate90() + O; }\n\n    Point inplace_rotate180()\
    \ {\n        x = -x;\n        y = -y;\n        return *this;\n    }\n\n    Point\
    \ inplace_rotate180(const Point &O) {\n        *this -= O;\n        inplace_rotate180();\n\
    \        return *this += O;\n    }\n\n    Point rotate180() const { return Point(-x,\
    \ -y); }\n\n    Point rotate180(const Point &O) const { return (*this - O).rotate180()\
    \ + O; }\n\n    Point inplace_rotate270() {\n        std::swap(x, y);\n      \
    \  y = -y;\n        return *this;\n    }\n\n    Point inplace_rotate270(const\
    \ Point &O) {\n        *this -= O;\n        inplace_rotate270();\n        return\
    \ *this += O;\n    }\n\n    Point rotate270() const { return Point(y, -x); }\n\
    \n    Point rotate270(const Point &O) const { return (*this - O).rotate270() +\
    \ O; }\n\n    friend T dot(const Point &p, const Point &q) { return p.dot(q);\
    \ }\n\n    friend T cross(const Point &p, const Point &q) { return p.cross(q);\
    \ }\n\n    friend T cross(const Point &p, const Point &q, const Point &O) { return\
    \ p.cross(q, O); }\n\n    friend T norm(const Point &p) { return p.norm(); }\n\
    \n    friend T norm(const Point &p, const Point &q) { return p.norm(q); }\n\n\
    \    friend long double abs(const Point &p) { return p.abs(); }\n\n    friend\
    \ long double dist(const Point &p, const Point &q) { return (p - q).abs(); }\n\
    \n    friend long double argument(const Point &p) { return p.argument(); }\n\n\
    \    friend long double argument(const Point &p, const Point &q) { return p.argument(q);\
    \ }\n\n    friend long double argument(const Point &p, const Point &q, const Point\
    \ &O) {\n        return p.argument(q, O);\n    }\n\n    friend Point rotate90(const\
    \ Point &p) { return p.rotate90(); }\n\n    friend Point rotate90(const Point\
    \ &p, const Point &O) { return p.rotate90(O); }\n\n    friend Point rotate180(const\
    \ Point &p) { return p.rotate180(); }\n\n    friend Point rotate180(const Point\
    \ &p, const Point &O) { return p.rotate180(O); }\n\n    friend Point rotate270(const\
    \ Point &p) { return p.rotate270(); }\n\n    friend Point rotate270(const Point\
    \ &p, const Point &O) { return p.rotate270(O); }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const Point &p) {\n        return os << p.x << \" \" << p.y;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, Point &p) {\n        return is >> p.x >> p.y;\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // GEOMETRY_POINT_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy:
  - geometry/static_convex_hull.hpp
  - geometry/argument_sort.hpp
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_geometry/arg_sort.test.cpp
  - verify/yosupo_geometry/static_convex_hull.test.cpp
documentation_of: geometry/point.hpp
layout: document
redirect_from:
- /library/geometry/point.hpp
- /library/geometry/point.hpp.html
title: geometry/point.hpp
---
