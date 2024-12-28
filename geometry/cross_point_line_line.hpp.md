---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':warning:'
    path: math/rational.hpp
    title: math/rational.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GEOMETRY_CROSS_POINT_LINE_LINE_HPP\n#define GEOMETRY_CROSS_POINT_LINE_LINE_HPP\
    \ 1\n\n#include <optional>\n\n#include \"line.hpp\"\n#include \"../math/rational.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T>\nstd::optional<Point<Rational<T>>>\
    \ cross_point(const Line<T> &l, const Line<T> &m) {\n    // Cramer's rule\n  \
    \  T det = l.a * m.b - l.b * m.a;\n    if (det == 0) return std::nullopt;\n  \
    \  T x = l.b * m.c - l.c * m.b;\n    T y = l.c * m.a - l.a * m.c;\n    return\
    \ Point<T>(Rational<T>(x, det), Rational<T>(y, det));\n}\n\n}\n\n#endif // GEOMETRY_CROSS_POINT_LINE_LINE_HPP\n"
  dependsOn:
  - geometry/line.hpp
  - type_traits/type_traits.hpp
  - math/rational.hpp
  isVerificationFile: false
  path: geometry/cross_point_line_line.hpp
  requiredBy: []
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/cross_point_line_line.hpp
layout: document
redirect_from:
- /library/geometry/cross_point_line_line.hpp
- /library/geometry/cross_point_line_line.hpp.html
title: geometry/cross_point_line_line.hpp
---
