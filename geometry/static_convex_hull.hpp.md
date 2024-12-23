---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_geometry/static_convex_hull.test.cpp
    title: verify/yosupo_geometry/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/point.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GEOMETRY_CONVEX_HULL_HPP\n#define GEOMETRY_CONVEX_HULL_HPP 1\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\n#include \"point.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> struct StaticConvexHull {\n    using\
    \ point = Point<T>;\n    std::vector<point> ps, hull;\n    // \u5404\u9802\u70B9\
    \u306B\u5BFE\u3057\u3066\uFF0Chull\u306Eindex\u3092\u683C\u7D0D\n    // -1\u306A\
    \u3089\u51F8\u5305\u306B\u542B\u307E\u308C\u306A\u3044\n    std::vector<int> idx;\n\
    \n    StaticConvexHull() = default;\n\n    StaticConvexHull(const std::vector<point>\
    \ &ps) : ps(ps) {}\n\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\
    \n    void add_point(const point &p) { ps.push_back(p); }\n\n    void build()\
    \ {\n        int _n = size(ps);\n        if (_n == 0) return;\n        if (_n\
    \ == 1) {\n            hull = ps;\n            idx = {0};\n            return;\n\
    \        }\n\n        idx.resize(_n, -1);\n        std::vector<std::pair<point,\
    \ int>> tmp(_n);\n        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};\n\
    \        std::sort(tmp.begin(), tmp.end());\n        std::vector<bool> same(_n);\n\
    \        for (int i = 1; i < _n; i++) same[i] = tmp[i - 1].first == tmp[i].first;\n\
    \        std::vector<std::pair<point, int>> up, dw;\n\n        for (int i = 0;\
    \ i < _n; i++) {\n            if (same[i]) continue;\n            // \u50BE\u304D\
    \u304C\u6E1B\u5C11\n            while (size(up) >= 2\n                   && cross(up[size(up)\
    \ - 2].first - up[size(up) - 1].first,\n                            up[size(up)\
    \ - 1].first - tmp[i].first)\n                          >= 0) {\n            \
    \    up.pop_back();\n            }\n\n            // \u50BE\u304D\u304C\u5897\u52A0\
    \n            while (size(dw) >= 2\n                   && cross(dw[size(dw) -\
    \ 2].first - dw[size(dw) - 1].first,\n                            dw[size(dw)\
    \ - 1].first - tmp[i].first)\n                          <= 0) {\n            \
    \    dw.pop_back();\n            }\n            up.emplace_back(tmp[i]);\n   \
    \         dw.emplace_back(tmp[i]);\n        }\n\n        if (int(size(up)) ==\
    \ 1) {\n            hull = {up[0].first};\n            idx[up[0].second] = 0;\n\
    \            return;\n        }\n\n        hull.resize(size(up) + size(dw) - 2);\n\
    \n        for (int i = 0; i < (int)size(dw); i++) {\n            hull[i] = dw[i].first;\n\
    \            idx[dw[i].second] = i;\n        }\n        for (int i = size(up)\
    \ - 2; i > 0; i--) {\n            hull[size(up) + size(dw) - 2 - i] = up[i].first;\n\
    \            idx[up[i].second] = size(up) + size(dw) - 2 - i;\n        }\n   \
    \ }\n};\n\n} // namespace kk2\n\n#endif // GEOMETRY_CONVEX_HULL_HPP\n"
  dependsOn:
  - geometry/point.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: geometry/static_convex_hull.hpp
  requiredBy: []
  timestamp: '2024-12-22 00:42:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_geometry/static_convex_hull.test.cpp
documentation_of: geometry/static_convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/static_convex_hull.hpp
- /library/geometry/static_convex_hull.hpp.html
title: geometry/static_convex_hull.hpp
---