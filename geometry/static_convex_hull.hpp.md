---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ geometry/point.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GEOMETRY_CONVEX_HULL_HPP\n#define GEOMETRY_CONVEX_HULL_HPP 1\n\n\
    #include <algorithm>\n#include <utility>\n#include <vector>\n\n#include \"point.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T> struct ConvexHull {\n    using point\
    \ = Point<T>;\n    std::vector<point> ps, hull;\n    std::vector<int> idx;\n\n\
    \    ConvexHull() = default;\n\n    ConvexHull(const std::vector<point> &ps) :\
    \ ps(ps) {}\n\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\n   \
    \ void add_point(const point &p) { ps.push_back(p); }\n\n    void build() {\n\
    \        int _n = size(ps);\n        if (_n == 0) return;\n        if (_n == 1)\
    \ {\n            hull = ps;\n            idx = {0};\n            return;\n   \
    \     }\n\n        idx.resize(_n, -1);\n        std::vector<std::pair<point, int>>\
    \ tmp(_n);\n        for (int i = 0; i < _n; i++) tmp[i] = {ps[i], i};\n      \
    \  std::sort(tmp.begin(), tmp.end());\n        std::vector<bool> same(_n);\n \
    \       for (int i = 1; i < _n; i++) same[i] = tmp[i - 1].first == tmp[i].first;\n\
    \        std::vector<std::pair<point, int>> up, dw;\n\n        for (int i = 0;\
    \ i < _n; i++) {\n            if (same[i]) continue;\n            while (size(up)\
    \ >= 2\n                   && cross(up[size(up) - 1].first - up[size(up) - 2].first,\n\
    \                            tmp[i].first - up[size(up) - 1].first)\n        \
    \                  >= 0) {\n                up.pop_back();\n            }\n  \
    \          while (size(dw) >= 2\n                   && cross(dw[size(dw) - 1].first\
    \ - dw[size(dw) - 2].first,\n                            tmp[i].first - dw[size(dw)\
    \ - 1].first)\n                          <= 0) {\n                dw.pop_back();\n\
    \            }\n            up.emplace_back(tmp[i]);\n            dw.emplace_back(tmp[i]);\n\
    \        }\n\n        if (int(size(up)) == 1) {\n            hull = {up[0].first};\n\
    \            idx[up[0].second] = 0;\n            return;\n        }\n\n      \
    \  hull.resize(size(up) + size(dw) - 2);\n\n        for (int i = 0; i < (int)size(dw);\
    \ i++) {\n            hull[i] = dw[i].first;\n            idx[dw[i].second] =\
    \ i;\n        }\n        for (int i = size(up) - 2; i > 0; i--) {\n          \
    \  hull[size(up) + size(dw) - 2 - i] = up[i].first;\n            idx[up[i].second]\
    \ = size(up) + size(dw) - 2 - i;\n        }\n    }\n};\n\n} // namespace kk2\n\
    \n#endif // GEOMETRY_CONVEX_HULL_HPP\n"
  dependsOn:
  - geometry/point.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: geometry/static_convex_hull.hpp
  requiredBy: []
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_geometry/static_convex_hull.test.cpp
documentation_of: geometry/static_convex_hull.hpp
layout: document
redirect_from:
- /library/geometry/static_convex_hull.hpp
- /library/geometry/static_convex_hull.hpp.html
title: geometry/static_convex_hull.hpp
---
