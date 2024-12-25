---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/cross_point_line_line.hpp
    title: geometry/cross_point_line_line.hpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef GEOMETRY_LINE_HPP\n#define GEOMETRY_LINE_HPP 1\n\n#include <numeric>\n\
    \n#include \"../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ geometry::line {\n\ntemplate <typename T, typename U> struct LineBase {\n  \
    \  // ax + by + c = 0\n    T a, b, c;\n\n    LineBase() : a(0), b(0), c(0) {}\n\
    \n    LineBase(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}\n\n    friend bool operator==(const\
    \ LineBase &l, const LineBase &m) {\n        return U(m.a) * l.b == U(l.a) * m.b\
    \ and U(m.a) * l.c == U(l.a) * m.c;\n    }\n\n    friend bool operator!=(const\
    \ LineBase &l, const LineBase &m) { return !(l == m); }\n\n    bool operator<(const\
    \ LineBase &m) {\n        if (a != m.a) return a < m.a;\n        if (b != m.b)\
    \ return b < m.b;\n        return c < m.c;\n    }\n};\n\n} // namespace geometry::line\n\
    \ntemplate <typename T>\nusing Line = geometry::line::LineBase<T, T>;\ntemplate\
    \ <>\nusing Line<int> = geometry::line::LineBase<int, long long>;\ntemplate <>\n\
    using Line<long long> = geometry::line::LineBase<long long, __int128_t>;\n\n}\
    \ // namespace kk2\n\n#endif // GEOMETRY_LINE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/cross_point_line_line.hpp
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/line.hpp
layout: document
redirect_from:
- /library/geometry/line.hpp
- /library/geometry/line.hpp.html
title: geometry/line.hpp
---
