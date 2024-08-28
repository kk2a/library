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
  bundledCode: "#line 1 \"geometry/argument.hpp\"\n\n\n\n#line 1 \"geometry/point.hpp\"\
    \n\n\n\nnamespace kk2 {\n\nstruct Point {\n    using i64 = long long;\n    i64\
    \ x, y;\n    Point(i64 x = 0, i64 y = 0) : x(x), y(y) {}\n    bool operator<(const\
    \ Point& p) const {\n        return x != p.x ? x < p.x : y < p.y;\n    }\n   \
    \ bool operator<=(const Point& p) const {\n        return x != p.x ? x < p.x :\
    \ y <= p.y;\n    }\n    bool operator>(const Point& p) const {\n        return\
    \ x != p.x ? x > p.x : y > p.y;\n    }\n    bool operator>=(const Point& p) const\
    \ {\n        return x != p.x ? x > p.x : y >= p.y;\n    }\n    bool operator==(const\
    \ Point& p) const {\n        return x == p.x && y == p.y;\n    }\n    bool operator!=(const\
    \ Point& p) const {\n        return x != p.x || y != p.y;\n    }\n\n    Point&\
    \ operator+=(const Point& p) {\n        x += p.x;\n        y += p.y;\n       \
    \ return *this;\n    }\n    Point& operator-=(const Point& p) {\n        x -=\
    \ p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point& operator*=(i64\
    \ k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n    Point&\
    \ operator/=(i64 k) {\n        x /= k;\n        y /= k;\n        return *this;\n\
    \    }\n\n    Point operator+(const Point& p) const {\n        return Point(*this)\
    \ += p;\n    }\n    Point operator-(const Point& p) const {\n        return Point(*this)\
    \ -= p;\n    }\n    Point operator*(i64 k) const {\n        return Point(*this)\
    \ *= k;\n    }\n    Point operator/(i64 k) const {\n        return Point(*this)\
    \ /= k;\n    }\n\n    i64 dot(const Point& p) const {\n        return x * p.x\
    \ + y * p.y;\n    }\n    i64 cross(const Point& p) const {\n        return x *\
    \ p.y - y * p.x;\n    }\n    i64 cross(const Point& p, const Point& O) const {\n\
    \        return (*this - O).cross(p - O);\n    }\n    i64 norm() const {\n   \
    \     return x * x + y * y;\n    }\n    i64 norm(const Point& p) const {\n   \
    \     return (p - *this).norm();\n    }\n    long double abs() const {\n     \
    \   return sqrt(norm());\n    }\n    long double dist(const Point& p) const {\n\
    \        return (p - *this).abs();\n    }\n    long double argument() const {\n\
    \        return atan2(y, x);\n    }\n    long double argument(const Point& p)\
    \ const {\n        long double res = argument() - p.argument();\n        if (res\
    \ < -PI) res += 2 * PI;\n        if (res > PI) res -= 2 * PI;\n        return\
    \ res;\n    }\n    long double argument(const Point& p, const Point& O) const\
    \ {\n        return (*this - O).argument(p - O);\n    }\n\n    Point inplace_rotate90()\
    \ {\n        swap(x, y);\n        x = -x;\n        return *this;\n    }\n    Point\
    \ inplace_rotate90(Point O) {\n        *this -= O;\n        inplace_rotate90();\n\
    \        return *this += O;\n    }\n    Point rotate90() const {\n        return\
    \ Point(-y, x);\n    }\n    Point rotate90(Point O) const {\n        return (*this\
    \ - O).rotate90() + O;\n    }\n    Point inplace_rotate180() {\n        x = -x;\n\
    \        y = -y;\n        return *this;\n    }\n    Point inplace_rotate180(Point\
    \ O) {\n        *this -= O;\n        inplace_rotate180();\n        return *this\
    \ += O;\n    }\n    Point rotate180() const {\n        return Point(-x, -y);\n\
    \    }\n    Point rotate180(Point O) const {\n        return (*this - O).rotate180()\
    \ + O;\n    }\n    Point inplace_rotate270() {\n        swap(x, y);\n        y\
    \ = -y;\n        return *this;\n    }\n    Point inplace_rotate270(Point O) {\n\
    \        *this -= O;\n        inplace_rotate270();\n        return *this += O;\n\
    \    }\n    Point rotate270() const {\n        return Point(y, -x);\n    }\n \
    \   Point rotate270(Point O) const {\n        return (*this - O).rotate270() +\
    \ O;\n    }\n\n    friend i64 dot(const Point& p, const Point& q) {\n        return\
    \ p.dot(q);\n    }\n    friend i64 cross(const Point& p, const Point& q) {\n \
    \       return p.cross(q);\n    }\n    friend i64 cross(const Point& p, const\
    \ Point& q, const Point& O) {\n        return p.cross(q, O);\n    }\n    friend\
    \ i64 norm(const Point& p) {\n        return p.norm();\n    }\n    friend i64\
    \ norm(const Point& p, const Point& q) {\n        return p.norm(q);\n    }\n \
    \   friend long double abs(const Point& p) {\n        return p.abs();\n    }\n\
    \    friend long double dist(const Point& p, const Point& q) {\n        return\
    \ (p - q).abs();\n    }\n    friend long double argument(const Point& p) {\n \
    \       return p.argument();\n    }\n    friend long double argument(const Point&\
    \ p, const Point& q) {\n        return p.argument(q);\n    }\n    friend long\
    \ double argument(const Point& p, const Point& q, const Point& O) {\n        return\
    \ p.argument(q, O);\n    }\n    friend Point rotate90(const Point& p) {\n    \
    \    return p.rotate90();\n    }\n    friend Point rotate90(const Point& p, const\
    \ Point& O) {\n        return p.rotate90(O);\n    }\n    friend Point rotate180(const\
    \ Point& p) {\n        return p.rotate180();\n    }\n    friend Point rotate180(const\
    \ Point& p, const Point& O) {\n        return p.rotate180(O);\n    }\n    friend\
    \ Point rotate270(const Point& p) {\n        return p.rotate270();\n    }\n  \
    \  friend Point rotate270(const Point& p, const Point& O) {\n        return p.rotate270(O);\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, const Point& p) {\n    \
    \    return os << p.x << \" \" << p.y;\n    }\n    friend istream& operator>>(istream&\
    \ is, Point& p) {\n        return is >> p.x >> p.y;\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"geometry/argument.hpp\"\n\nnamespace kk2 {\n\ntemplate <int\
    \ id>\nstruct ArgumentSort {\n    using i64 = long long;\n    static Point O;\n\
    \    static void setO(const Point& p) { O = p; }\n\n  private:\n    // p - O =\
    \ (x, y) \n    // 1 : y < 0\n    // 2 : y >= 0 and x >= 0\n    // 3 : otherwise\n\
    \    static int location(const Point& p) {\n        Point q = p - O;\n       \
    \ return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;\n    }\n\n    static bool cmp(const Point&\
    \ a, const Point& b) {\n        int loc_a = location(a), loc_b = location(b);\n\
    \        i64 cr = cross(a, b, O);\n        return loc_a != loc_b ? loc_a < loc_b\
    \ :\n               cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;\n    }\n\n  public:\n\
    \    static void argument_sort(vector<Point>& ps) {\n        sort(begin(ps), end(ps),\
    \ cmp);\n    }\n\n    template <class ForwardIt>\n    static ForwardIt min_up_argument(ForwardIt\
    \ first, ForwardIt last, const Point& p) {\n        return lower_bound(first,\
    \ last, p, cmp);\n    }\n};\ntemplate <int id>\nPoint ArgumentSort<id>::O(0, 0);\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef GEOMETRY_ARGUMENT_HPP\n#define GEOMETRY_ARGUMENT_HPP 1\n\n#include\
    \ \"point.hpp\"\n\nnamespace kk2 {\n\ntemplate <int id>\nstruct ArgumentSort {\n\
    \    using i64 = long long;\n    static Point O;\n    static void setO(const Point&\
    \ p) { O = p; }\n\n  private:\n    // p - O = (x, y) \n    // 1 : y < 0\n    //\
    \ 2 : y >= 0 and x >= 0\n    // 3 : otherwise\n    static int location(const Point&\
    \ p) {\n        Point q = p - O;\n        return q.y < 0 ? 1 : q.x >= 0 ? 2 :\
    \ 3;\n    }\n\n    static bool cmp(const Point& a, const Point& b) {\n       \
    \ int loc_a = location(a), loc_b = location(b);\n        i64 cr = cross(a, b,\
    \ O);\n        return loc_a != loc_b ? loc_a < loc_b :\n               cr == 0\
    \ ? norm(a, O) < norm(b, O) : cr > 0;\n    }\n\n  public:\n    static void argument_sort(vector<Point>&\
    \ ps) {\n        sort(begin(ps), end(ps), cmp);\n    }\n\n    template <class\
    \ ForwardIt>\n    static ForwardIt min_up_argument(ForwardIt first, ForwardIt\
    \ last, const Point& p) {\n        return lower_bound(first, last, p, cmp);\n\
    \    }\n};\ntemplate <int id>\nPoint ArgumentSort<id>::O(0, 0);\n\n} // namespace\
    \ kk2\n\n#endif // GEOMETRY_ARGUMENT_HPP\n"
  dependsOn:
  - geometry/point.hpp
  isVerificationFile: false
  path: geometry/argument.hpp
  requiredBy: []
  timestamp: '2024-08-29 01:45:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/argument.hpp
layout: document
redirect_from:
- /library/geometry/argument.hpp
- /library/geometry/argument.hpp.html
title: geometry/argument.hpp
---
