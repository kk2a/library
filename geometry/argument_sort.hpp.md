---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_geometry/arg_sort.test.cpp
    title: verify/yosupo_geometry/arg_sort.test.cpp
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
  code: "#ifndef GEOMETRY_ARGUMENT_SORT_HPP\n#define GEOMETRY_ARGUMENT_SORT_HPP 1\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"point.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class T> struct ArgumentSort {\n    using point = Point<T>;\n\
    \    point O;\n\n    ArgumentSort(const point &O_ = point()) : O(O_) {}\n\n  private:\n\
    \    // p - O = (x, y)\n    // 1 : y < 0\n    // 2 : y >= 0 and x >= 0\n    //\
    \ 3 : otherwise\n    int location(const point &p) {\n        point q = p - O;\n\
    \        return q.y < 0 ? 1 : q.x >= 0 ? 2 : 3;\n    }\n\n    bool cmp(const point\
    \ &a, const point &b) {\n        int loc_a = location(a), loc_b = location(b);\n\
    \        T cr = cross(a, b, O);\n        return loc_a != loc_b ? loc_a < loc_b\
    \ : cr == 0 ? norm(a, O) < norm(b, O) : cr > 0;\n    }\n\n  public:\n    void\
    \ argument_sort(std::vector<point> &ps) {\n        std::sort(\n            ps.begin(),\
    \ ps.end(), [this](auto &&a, auto &&b) -> bool { return this->cmp(a, b); });\n\
    \    }\n\n    template <class Iterator>\n    Iterator min_up_argument(Iterator\
    \ first, Iterator last, const point &p) {\n        return std::lower_bound(\n\
    \            first, last, p, [this](auto &&a, auto &&b) -> bool { return this->cmp(a,\
    \ b); });\n    }\n};\n\n} // namespace kk2\n\n#endif // GEOMETRY_ARGUMENT_SORT_HPP\n"
  dependsOn:
  - geometry/point.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: geometry/argument_sort.hpp
  requiredBy: []
  timestamp: '2024-10-31 14:06:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_geometry/arg_sort.test.cpp
documentation_of: geometry/argument_sort.hpp
layout: document
redirect_from:
- /library/geometry/argument_sort.hpp
- /library/geometry/argument_sort.hpp.html
title: geometry/argument_sort.hpp
---
