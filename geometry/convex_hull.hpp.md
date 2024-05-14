---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/convex_hull.hpp\"\n\n\n\nstruct Convex_hull {\n\
    \    using i64 = long long;\n  private:\n    struct Point {\n        i64 x, y;\n\
    \        Point(i64 x, i64 y) : x(x), y(y) {}\n        bool operator<(const Point&\
    \ p) const {\n            return x != p.x ? x < p.x : y < p.y;\n        }\n  \
    \      Point operator+(const Point& p) const {\n            return Point(x + p.x,\
    \ y + p.y);\n        }\n        Point operator-(const Point& p) const {\n    \
    \        return Point(x - p.x, y - p.y);\n        }\n        friend ostream& operator<<(ostream&\
    \ os, const Point& p) {\n            os << p.x << \" \" << p.y;\n            return\
    \ os;\n        }\n    };\n    i64 cross(const Point& a, const Point& b) {\n  \
    \      return a.x * b.y - a.y * b.x;\n    }\n  public:\n    vector<Point> ps,\
    \ hull;\n\n    void add_point(i64 x, i64 y) {\n        ps.emplace_back(x, y);\n\
    \    }\n\n    void query() {\n        int _n = size(ps);\n        if (_n == 1)\
    \ {\n            hull = ps;\n            return;\n        }\n        vector<Point>\
    \ res = ps;\n        sort(res.begin(), res.end());\n        vector<Point> up,\
    \ dw;\n        up.emplace_back(res[0]); dw.emplace_back(res[0]);\n        up.emplace_back(res[1]);\
    \ dw.emplace_back(res[1]);\n        for (int i = 2; i < _n; i++) {\n         \
    \   while (size(up) >= 2 && cross(up[size(up) - 1]\n                   - up[size(up)\
    \ - 2], res[i] - up[size(up) - 1]) >= 0) {\n                up.pop_back();\n \
    \           }\n            while (size(dw) >= 2 && cross(dw[size(dw) - 1]\n  \
    \                 - dw[size(dw) - 2], res[i] - dw[size(dw) - 1]) <= 0) {\n   \
    \             dw.pop_back();\n            }\n            up.emplace_back(res[i]);\n\
    \            dw.emplace_back(res[i]);\n        }\n        hull = up;\n       \
    \ for (int i = size(dw) - 2; i > 0; i--) {\n            hull.emplace_back(dw[i]);\n\
    \        }\n    }\n};\n\n\n"
  code: "#ifndef GEOMETRY_CONVEX_HULL_HPP\n#define GEOMETRY_CONVEX_HULL_HPP 1\n\n\
    struct Convex_hull {\n    using i64 = long long;\n  private:\n    struct Point\
    \ {\n        i64 x, y;\n        Point(i64 x, i64 y) : x(x), y(y) {}\n        bool\
    \ operator<(const Point& p) const {\n            return x != p.x ? x < p.x : y\
    \ < p.y;\n        }\n        Point operator+(const Point& p) const {\n       \
    \     return Point(x + p.x, y + p.y);\n        }\n        Point operator-(const\
    \ Point& p) const {\n            return Point(x - p.x, y - p.y);\n        }\n\
    \        friend ostream& operator<<(ostream& os, const Point& p) {\n         \
    \   os << p.x << \" \" << p.y;\n            return os;\n        }\n    };\n  \
    \  i64 cross(const Point& a, const Point& b) {\n        return a.x * b.y - a.y\
    \ * b.x;\n    }\n  public:\n    vector<Point> ps, hull;\n\n    void add_point(i64\
    \ x, i64 y) {\n        ps.emplace_back(x, y);\n    }\n\n    void query() {\n \
    \       int _n = size(ps);\n        if (_n == 1) {\n            hull = ps;\n \
    \           return;\n        }\n        vector<Point> res = ps;\n        sort(res.begin(),\
    \ res.end());\n        vector<Point> up, dw;\n        up.emplace_back(res[0]);\
    \ dw.emplace_back(res[0]);\n        up.emplace_back(res[1]); dw.emplace_back(res[1]);\n\
    \        for (int i = 2; i < _n; i++) {\n            while (size(up) >= 2 && cross(up[size(up)\
    \ - 1]\n                   - up[size(up) - 2], res[i] - up[size(up) - 1]) >= 0)\
    \ {\n                up.pop_back();\n            }\n            while (size(dw)\
    \ >= 2 && cross(dw[size(dw) - 1]\n                   - dw[size(dw) - 2], res[i]\
    \ - dw[size(dw) - 1]) <= 0) {\n                dw.pop_back();\n            }\n\
    \            up.emplace_back(res[i]);\n            dw.emplace_back(res[i]);\n\
    \        }\n        hull = up;\n        for (int i = size(dw) - 2; i > 0; i--)\
    \ {\n            hull.emplace_back(dw[i]);\n        }\n    }\n};\n\n#endif //\
    \ GEOMETRY_CONVEX_HULL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2024-05-14 18:36:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/convex_hull.hpp
- /library/geometry/convex_hull.hpp.html
title: geometry/convex_hull.hpp
---
