---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: point.hpp
      icon: LIBRARY_ALL_AC
      path: geometry/point.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: static_convex_hull.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull.test.cpp
    - filename: static_convex_hull_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_1.test.cpp
    - filename: static_convex_hull_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_2.test.cpp
    - filename: static_convex_hull_3.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_3.test.cpp
    type: Verified with
  dependsOn:
  - geometry/point.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_GEOMETRY_CONVEX_HULL_HPP\n#define KK2_GEOMETRY_CONVEX_HULL_HPP\
      \ 1\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\n#include\
      \ \"point.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> struct StaticConvexHull\
      \ {\n    using point = Point<T>;\n    std::vector<point> ps, hull;\n    std::vector<point>\
      \ up, dw;\n    std::vector<int> idx_hull, idx_up, idx_dw;\n\n    StaticConvexHull()\
      \ = default;\n\n    StaticConvexHull(const std::vector<point> &ps) : ps(ps)\
      \ {}\n\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\n    void\
      \ add_point(const point &p) { ps.push_back(p); }\n\n    void build() {\n   \
      \     int _n = size(ps);\n        if (_n == 0) return;\n\n        idx_hull.resize(_n,\
      \ -1);\n        idx_up.resize(_n, -1);\n        idx_dw.resize(_n, -1);\n\n \
      \       std::vector<std::pair<point, int>> tmp(_n);\n        for (int i = 0;\
      \ i < _n; i++) tmp[i] = {ps[i], i};\n        std::sort(tmp.begin(), tmp.end());\n\
      \        std::vector<bool> same(_n);\n        for (int i = 1; i < _n; i++) same[i]\
      \ = tmp[i - 1].first == tmp[i].first;\n        std::vector<std::pair<point,\
      \ int>> up_, dw_;\n\n        for (int i = 0; i < _n; i++) {\n            if\
      \ (same[i]) continue;\n            // \u50BE\u304D\u304C\u6E1B\u5C11\n     \
      \       while (size(up_) >= 2u\n                   && cross(up_[size(up_) -\
      \ 1].first - up_[size(up_) - 2].first,\n                            tmp[i].first\
      \ - up_[size(up_) - 1].first)\n                          >= 0) {\n         \
      \       up_.pop_back();\n            }\n\n            // \u50BE\u304D\u304C\u5897\
      \u52A0\n            while (size(dw_) >= 2u\n                   && cross(dw_[size(dw_)\
      \ - 1].first - dw_[size(dw_) - 2].first,\n                            tmp[i].first\
      \ - dw_[size(dw_) - 1].first)\n                          <= 0) {\n         \
      \       dw_.pop_back();\n            }\n            up_.emplace_back(tmp[i]);\n\
      \            dw_.emplace_back(tmp[i]);\n        }\n\n        if (int(size(up_))\
      \ == 1) {\n            hull = up = dw = {up_[0].first};\n            idx_hull[up_[0].second]\
      \ = idx_up[up_[0].second] = idx_dw[up_[0].second] = 0;\n            return;\n\
      \        }\n\n        hull.resize(size(up_) + size(dw_) - 2);\n        up.resize(size(up_));\n\
      \        dw.resize(size(dw_));\n\n        for (int i = 0; i < (int)size(dw_);\
      \ i++) {\n            hull[i] = dw[i] = dw_[i].first;\n            idx_hull[dw_[i].second]\
      \ = idx_dw[dw_[i].second] = i;\n        }\n        up.back() = up_.back().first;\n\
      \        idx_up[up_.back().second] = up_.size() - 1;\n        up[0] = up_[0].first;\n\
      \        idx_up[up_[0].second] = 0;\n        for (int i = size(up_) - 2; i;\
      \ i--) {\n            hull[size(up_) + size(dw_) - 2 - i] = up[i] = up_[i].first;\n\
      \            idx_hull[up_[i].second] = size(up_) + size(dw_) - 2 - i;\n    \
      \        idx_up[up_[i].second] = i;\n        }\n    }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GEOMETRY_CONVEX_HULL_HPP\n"
    name: default
  - code: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/resolver.py\"\
      , line 290, in resolve\n    bundled_code = language.bundle(path, basedir=basedir)\n\
      \                   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus.py\"\
      , line 243, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 478, in update\n    self.update(\n  File \"/home/runner/.local/lib/python3.12/site-packages/competitive_verifier/oj/languages/cplusplus_bundle.py\"\
      , line 354, in update\n    raise BundleErrorAt(\ncompetitive_verifier.oj.languages.cplusplus_bundle.BundleErrorAt:\
      \ geometry/point.hpp: line 4: #pragma once found in an include guard with #ifndef\n"
    name: bundle error
  isFailed: false
  isVerificationFile: false
  path: geometry/static_convex_hull.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-07 23:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_geometry/static_convex_hull.test.cpp
  - verify/yosupo_geometry/static_convex_hull_1.test.cpp
  - verify/yosupo_geometry/static_convex_hull_2.test.cpp
  - verify/yosupo_geometry/static_convex_hull_3.test.cpp
documentation_of: geometry/static_convex_hull.hpp
layout: document
---
