---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/convex_hull.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\n#line 1 \"geometry/point.hpp\"\n\n\n\n\
    #line 5 \"geometry/point.hpp\"\n#include <cmath>\n#include <iostream>\n\nnamespace\
    \ kk2 {\n\ntemplate <typename T> struct Point {\n    static constexpr long double\
    \ PI = acos(-1.0);\n    T x, y;\n\n    Point(T x = 0, T y = 0) : x(x), y(y) {}\n\
    \n    bool operator<(const Point &p) const {\n        return x != p.x ? x < p.x\
    \ : y < p.y;\n    }\n\n    bool operator<=(const Point &p) const {\n        return\
    \ x != p.x ? x < p.x : y <= p.y;\n    }\n\n    bool operator>(const Point &p)\
    \ const {\n        return x != p.x ? x > p.x : y > p.y;\n    }\n\n    bool operator>=(const\
    \ Point &p) const {\n        return x != p.x ? x > p.x : y >= p.y;\n    }\n\n\
    \    bool operator==(const Point &p) const { return x == p.x && y == p.y; }\n\n\
    \    bool operator!=(const Point &p) const { return x != p.x || y != p.y; }\n\n\
    \    Point &operator+=(const Point &p) {\n        x += p.x;\n        y += p.y;\n\
    \        return *this;\n    }\n\n    Point &operator-=(const Point &p) {\n   \
    \     x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n\n    Point\
    \ &operator*=(T k) {\n        x *= k;\n        y *= k;\n        return *this;\n\
    \    }\n\n    Point &operator/=(T k) {\n        x /= k;\n        y /= k;\n   \
    \     return *this;\n    }\n\n    Point operator+(const Point &p) const { return\
    \ Point(*this) += p; }\n\n    Point operator-(const Point &p) const { return Point(*this)\
    \ -= p; }\n\n    Point operator*(T k) const { return Point(*this) *= k; }\n\n\
    \    Point operator/(T k) const { return Point(*this) /= k; }\n\n    T dot(const\
    \ Point &p) const { return x * p.x + y * p.y; }\n\n    T cross(const Point &p)\
    \ const { return x * p.y - y * p.x; }\n\n    T cross(const Point &p, const Point\
    \ &O) const {\n        return (*this - O).cross(p - O);\n    }\n\n    T norm()\
    \ const { return x * x + y * y; }\n\n    T norm(const Point &p) const { return\
    \ (p - *this).norm(); }\n\n    long double abs() const { return sqrt(norm());\
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
    \ -y); }\n\n    Point rotate180(const Point &O) const {\n        return (*this\
    \ - O).rotate180() + O;\n    }\n\n    Point inplace_rotate270() {\n        std::swap(x,\
    \ y);\n        y = -y;\n        return *this;\n    }\n\n    Point inplace_rotate270(const\
    \ Point &O) {\n        *this -= O;\n        inplace_rotate270();\n        return\
    \ *this += O;\n    }\n\n    Point rotate270() const { return Point(y, -x); }\n\
    \n    Point rotate270(const Point &O) const {\n        return (*this - O).rotate270()\
    \ + O;\n    }\n\n    friend T dot(const Point &p, const Point &q) { return p.dot(q);\
    \ }\n\n    friend T cross(const Point &p, const Point &q) { return p.cross(q);\
    \ }\n\n    friend T cross(const Point &p, const Point &q, const Point &O) {\n\
    \        return p.cross(q, O);\n    }\n\n    friend T norm(const Point &p) { return\
    \ p.norm(); }\n\n    friend T norm(const Point &p, const Point &q) { return p.norm(q);\
    \ }\n\n    friend long double abs(const Point &p) { return p.abs(); }\n\n    friend\
    \ long double dist(const Point &p, const Point &q) {\n        return (p - q).abs();\n\
    \    }\n\n    friend long double argument(const Point &p) { return p.argument();\
    \ }\n\n    friend long double argument(const Point &p, const Point &q) {\n   \
    \     return p.argument(q);\n    }\n\n    friend long double\n    argument(const\
    \ Point &p, const Point &q, const Point &O) {\n        return p.argument(q, O);\n\
    \    }\n\n    friend Point rotate90(const Point &p) { return p.rotate90(); }\n\
    \n    friend Point rotate90(const Point &p, const Point &O) {\n        return\
    \ p.rotate90(O);\n    }\n\n    friend Point rotate180(const Point &p) { return\
    \ p.rotate180(); }\n\n    friend Point rotate180(const Point &p, const Point &O)\
    \ {\n        return p.rotate180(O);\n    }\n\n    friend Point rotate270(const\
    \ Point &p) { return p.rotate270(); }\n\n    friend Point rotate270(const Point\
    \ &p, const Point &O) {\n        return p.rotate270(O);\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Point &p) {\n        return os << p.x <<\
    \ \" \" << p.y;\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ Point &p) {\n        return is >> p.x >> p.y;\n    }\n};\n\n} // namespace kk2\n\
    \n\n#line 9 \"geometry/convex_hull.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> struct ConvexHull {\n    std::vector<Point<T>> ps, hull;\n    std::vector<int>\
    \ idx;\n\n    ConvexHull() = default;\n\n    ConvexHull(const std::vector<Point<T>>\
    \ &ps) : ps(ps) {}\n\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\
    \n    void add_point(const Point<T> &p) { ps.push_back(p); }\n\n    void build()\
    \ {\n        int _n = size(ps);\n        if (_n == 1) {\n            hull = ps;\n\
    \            return;\n        }\n        std::vector<std::pair<Point<T>, int>>\
    \ tmp(_n);\n        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};\n      \
    \  std::sort(std::begin(tmp), std::end(tmp));\n        std::vector<std::pair<Point<T>,\
    \ int>> up, dw;\n        up.push_back(tmp[0]);\n        dw.push_back(tmp[0]);\n\
    \        up.push_back(tmp[1]);\n        dw.push_back(tmp[1]);\n\n        for (int\
    \ i = 2; i < _n; i++) {\n            while (size(up) >= 2\n                  \
    \ && cross(up[size(up) - 1].first - up[size(up) - 2].first,\n                \
    \            tmp[i].first - up[size(up) - 1].first)\n                        \
    \  >= 0) {\n                up.pop_back();\n            }\n            while (size(dw)\
    \ >= 2\n                   && cross(dw[size(dw) - 1].first - dw[size(dw) - 2].first,\n\
    \                            tmp[i].first - dw[size(dw) - 1].first)\n        \
    \                  <= 0) {\n                dw.pop_back();\n            }\n  \
    \          up.push_back(tmp[i]);\n            dw.push_back(tmp[i]);\n        }\n\
    \        hull.reserve(size(up) + size(dw) - 2);\n        idx.resize(_n, -1);\n\
    \        for (int i = 0; i < (int)size(up); i++) {\n            hull.emplace_back(up[i].first);\n\
    \            idx[up[i].second] = i;\n        }\n        for (int i = size(dw)\
    \ - 2; i > 0; i--) {\n            hull.emplace_back(dw[i].first);\n          \
    \  idx[dw[i].second] = size(hull) - 1;\n        }\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef GEOMETRY_CONVEX_HULL_HPP\n#define GEOMETRY_CONVEX_HULL_HPP 1\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\n#include \"point.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> struct ConvexHull {\n    std::vector<Point<T>>\
    \ ps, hull;\n    std::vector<int> idx;\n\n    ConvexHull() = default;\n\n    ConvexHull(const\
    \ std::vector<Point<T>> &ps) : ps(ps) {}\n\n    void add_point(T x, T y) { ps.emplace_back(x,\
    \ y); }\n\n    void add_point(const Point<T> &p) { ps.push_back(p); }\n\n    void\
    \ build() {\n        int _n = size(ps);\n        if (_n == 1) {\n            hull\
    \ = ps;\n            return;\n        }\n        std::vector<std::pair<Point<T>,\
    \ int>> tmp(_n);\n        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};\n\
    \        std::sort(std::begin(tmp), std::end(tmp));\n        std::vector<std::pair<Point<T>,\
    \ int>> up, dw;\n        up.push_back(tmp[0]);\n        dw.push_back(tmp[0]);\n\
    \        up.push_back(tmp[1]);\n        dw.push_back(tmp[1]);\n\n        for (int\
    \ i = 2; i < _n; i++) {\n            while (size(up) >= 2\n                  \
    \ && cross(up[size(up) - 1].first - up[size(up) - 2].first,\n                \
    \            tmp[i].first - up[size(up) - 1].first)\n                        \
    \  >= 0) {\n                up.pop_back();\n            }\n            while (size(dw)\
    \ >= 2\n                   && cross(dw[size(dw) - 1].first - dw[size(dw) - 2].first,\n\
    \                            tmp[i].first - dw[size(dw) - 1].first)\n        \
    \                  <= 0) {\n                dw.pop_back();\n            }\n  \
    \          up.push_back(tmp[i]);\n            dw.push_back(tmp[i]);\n        }\n\
    \        hull.reserve(size(up) + size(dw) - 2);\n        idx.resize(_n, -1);\n\
    \        for (int i = 0; i < (int)size(up); i++) {\n            hull.emplace_back(up[i].first);\n\
    \            idx[up[i].second] = i;\n        }\n        for (int i = size(dw)\
    \ - 2; i > 0; i--) {\n            hull.emplace_back(dw[i].first);\n          \
    \  idx[dw[i].second] = size(hull) - 1;\n        }\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // GEOMETRY_CONVEX_HULL_HPP\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2024-09-11 09:50:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/convex_hull.hpp
- /library/geometry/convex_hull.hpp.html
title: geometry/convex_hull.hpp
---
