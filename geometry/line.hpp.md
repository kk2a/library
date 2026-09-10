---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: cross_point_line_line.hpp
      icon: LIBRARY_NO_TESTS
      path: geometry/cross_point_line_line.hpp
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_GEOMETRY_LINE_HPP\n#define KK2_GEOMETRY_LINE_HPP 1\n\n#include\
      \ <numeric>\n\nnamespace kk2 {\n\nnamespace geometry::line {\n\ntemplate <typename\
      \ T, typename U> struct LineBase {\n    // ax + by + c = 0\n    T a, b, c;\n\
      \n    LineBase() : a(0), b(0), c(0) {}\n\n    LineBase(T a_, T b_, T c_) : a(a_),\
      \ b(b_), c(c_) {}\n\n    friend bool operator==(const LineBase &l, const LineBase\
      \ &m) {\n        return U(m.a) * l.b == U(l.a) * m.b and U(m.a) * l.c == U(l.a)\
      \ * m.c;\n    }\n\n    friend bool operator!=(const LineBase &l, const LineBase\
      \ &m) { return !(l == m); }\n\n    bool operator<(const LineBase &m) {\n   \
      \     if (a != m.a) return a < m.a;\n        if (b != m.b) return b < m.b;\n\
      \        return c < m.c;\n    }\n};\n\n} // namespace geometry::line\n\ntemplate\
      \ <typename T> using Line = geometry::line::LineBase<T, T>;\ntemplate <> using\
      \ Line<int> = geometry::line::LineBase<int, long long>;\ntemplate <> using Line<long\
      \ long> = geometry::line::LineBase<long long, __int128_t>;\n\n} // namespace\
      \ kk2\n\n#endif // KK2_GEOMETRY_LINE_HPP\n"
    name: default
  - code: "#line 1 \"geometry/line.hpp\"\n\n\n\n#include <numeric>\n\nnamespace kk2\
      \ {\n\nnamespace geometry::line {\n\ntemplate <typename T, typename U> struct\
      \ LineBase {\n    // ax + by + c = 0\n    T a, b, c;\n\n    LineBase() : a(0),\
      \ b(0), c(0) {}\n\n    LineBase(T a_, T b_, T c_) : a(a_), b(b_), c(c_) {}\n\
      \n    friend bool operator==(const LineBase &l, const LineBase &m) {\n     \
      \   return U(m.a) * l.b == U(l.a) * m.b and U(m.a) * l.c == U(l.a) * m.c;\n\
      \    }\n\n    friend bool operator!=(const LineBase &l, const LineBase &m) {\
      \ return !(l == m); }\n\n    bool operator<(const LineBase &m) {\n        if\
      \ (a != m.a) return a < m.a;\n        if (b != m.b) return b < m.b;\n      \
      \  return c < m.c;\n    }\n};\n\n} // namespace geometry::line\n\ntemplate <typename\
      \ T> using Line = geometry::line::LineBase<T, T>;\ntemplate <> using Line<int>\
      \ = geometry::line::LineBase<int, long long>;\ntemplate <> using Line<long long>\
      \ = geometry::line::LineBase<long long, __int128_t>;\n\n} // namespace kk2\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: geometry/line.hpp
  pathExtension: hpp
  requiredBy:
  - geometry/cross_point_line_line.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/line.hpp
layout: document
---
