---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj-0560.test.cpp
    title: verify/aoj/aoj-0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/prefix_sum_2d.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class T> struct PrefixSum2D\
    \ {\n    std::vector<std::vector<T>> acc;\n    int h, w;\n\n    constexpr PrefixSum2D()\
    \ = default;\n\n    constexpr PrefixSum2D(const std::vector<std::vector<T>> &a)\n\
    \        : acc(a.size() + 1, std::vector<T>(a[0].size() + 1)),\n          h((int)a.size()),\n\
    \          w((int)a[0].size()) {\n        for (int i = 0; i < h; ++i) {\n    \
    \        for (int j = 0; j < w; ++j) {\n                acc[i + 1][j + 1] = acc[i\
    \ + 1][j] + acc[i][j + 1] - acc[i][j] + a[i][j];\n            }\n        }\n \
    \   }\n\n    constexpr T sum(int li, int lj, int ri, int rj) const {\n       \
    \ assert(0 <= li && li <= ri && ri <= h);\n        assert(0 <= lj && lj <= rj\
    \ && rj <= w);\n        return acc[ri][rj] - acc[li][rj] - acc[ri][lj] + acc[li][lj];\n\
    \    }\n\n    constexpr T get(int i, int j) const {\n        assert(0 <= i &&\
    \ i < h);\n        assert(0 <= j && j < w);\n        return acc[i + 1][j + 1]\
    \ - acc[i][j + 1] - acc[i + 1][j] + acc[i][j];\n    }\n\n    constexpr T operator()(int\
    \ li, int lj, int ri, int rj) const {\n        assert(0 <= li && li <= ri && ri\
    \ <= h);\n        assert(0 <= lj && lj <= rj && rj <= w);\n        return acc[ri][rj]\
    \ - acc[li][rj] - acc[ri][lj] + acc[li][lj];\n    }\n\n    constexpr T operator()(int\
    \ i, int j) const {\n        assert(0 <= i && i < h);\n        assert(0 <= j &&\
    \ j < w);\n        return acc[i + 1][j + 1] - acc[i][j + 1] - acc[i + 1][j] +\
    \ acc[i][j];\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef DATA_STRUCTURE_PREFIX_SUM_2D_HPP\n#define DATA_STRUCTURE_PREFIX_SUM_2D_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ T> struct PrefixSum2D {\n    std::vector<std::vector<T>> acc;\n    int h, w;\n\
    \n    constexpr PrefixSum2D() = default;\n\n    constexpr PrefixSum2D(const std::vector<std::vector<T>>\
    \ &a)\n        : acc(a.size() + 1, std::vector<T>(a[0].size() + 1)),\n       \
    \   h((int)a.size()),\n          w((int)a[0].size()) {\n        for (int i = 0;\
    \ i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n                acc[i\
    \ + 1][j + 1] = acc[i + 1][j] + acc[i][j + 1] - acc[i][j] + a[i][j];\n       \
    \     }\n        }\n    }\n\n    constexpr T sum(int li, int lj, int ri, int rj)\
    \ const {\n        assert(0 <= li && li <= ri && ri <= h);\n        assert(0 <=\
    \ lj && lj <= rj && rj <= w);\n        return acc[ri][rj] - acc[li][rj] - acc[ri][lj]\
    \ + acc[li][lj];\n    }\n\n    constexpr T get(int i, int j) const {\n       \
    \ assert(0 <= i && i < h);\n        assert(0 <= j && j < w);\n        return acc[i\
    \ + 1][j + 1] - acc[i][j + 1] - acc[i + 1][j] + acc[i][j];\n    }\n\n    constexpr\
    \ T operator()(int li, int lj, int ri, int rj) const {\n        assert(0 <= li\
    \ && li <= ri && ri <= h);\n        assert(0 <= lj && lj <= rj && rj <= w);\n\
    \        return acc[ri][rj] - acc[li][rj] - acc[ri][lj] + acc[li][lj];\n    }\n\
    \n    constexpr T operator()(int i, int j) const {\n        assert(0 <= i && i\
    \ < h);\n        assert(0 <= j && j < w);\n        return acc[i + 1][j + 1] -\
    \ acc[i][j + 1] - acc[i + 1][j] + acc[i][j];\n    }\n};\n\n} // namespace kk2\n\
    \n#endif // DATA_STRUCTURE_PREFIX_SUM_2D_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/prefix_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-10-11 23:42:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj-0560.test.cpp
documentation_of: data_structure/prefix_sum_2d.hpp
layout: document
redirect_from:
- /library/data_structure/prefix_sum_2d.hpp
- /library/data_structure/prefix_sum_2d.hpp.html
title: data_structure/prefix_sum_2d.hpp
---
