---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_0560_2.test.cpp
    title: verify/aoj/aoj_0560_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/prefix_sum_arbitrary.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate\
    \ <class T> struct PrefixSumArbitrary {\n  private:\n    std::vector<int> base;\n\
    \    std::vector<T> acc;\n    int dim;\n\n    std::vector<int> inner_base;\n \
    \   int n;\n\n    constexpr void build() {\n        inner_base.resize(dim + 1,\
    \ 1);\n        for (int i = 1; i < dim + 1; ++i) { inner_base[i] = inner_base[i\
    \ - 1] * base[i - 1]; }\n        n = 1;\n        for (int x : base) n *= x;\n\n\
    \        for (int i = 0; i < dim; ++i) {\n            for (int coord = 0; coord\
    \ < n; ++coord) {\n                if (coord / inner_base[i + 1] == (coord + inner_base[i])\
    \ / inner_base[i + 1]) {\n                    acc[coord + inner_base[i]] += acc[coord];\n\
    \                }\n            }\n        }\n    }\n\n  public:\n    constexpr\
    \ PrefixSumArbitrary() = default;\n\n    constexpr PrefixSumArbitrary(const std::vector<int>\
    \ &base_, const std::vector<T> &a)\n        : base(base_),\n          acc(a),\n\
    \          dim(int(base_.size())) {\n        build();\n    }\n\n    constexpr\
    \ T sum(const std::vector<int> &l, const std::vector<int> &r) const {\n      \
    \  assert(int(l.size()) == dim and int(r.size()) == dim);\n        for (int i\
    \ = 0; i < dim; ++i) {\n            if (r[i] == 0) return T{};\n        }\n\n\
    \        T res{};\n        for (int bit = 0; bit < (1 << dim); ++bit) {\n    \
    \        int coord = 0;\n            bool bad = false;\n            for (int i\
    \ = 0; i < dim; ++i) {\n                if (bit >> i & 1) {\n                \
    \    if (l[i] == 0) {\n                        bad = true;\n                 \
    \       break;\n                    }\n                    coord += (l[i] - 1)\
    \ * inner_base[i];\n                } else {\n                    coord += (r[i]\
    \ - 1) * inner_base[i];\n                }\n            }\n            if (bad)\
    \ continue;\n            res += (__builtin_popcount(bit) & 1 ? -1 : 1) * acc[coord];\n\
    \        }\n        return res;\n    }\n\n    constexpr T operator()(const std::vector<int>\
    \ &l, const std::vector<int> &r) const {\n        return sum(l, r);\n    }\n};\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP\n#define DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\ntemplate <class T> struct PrefixSumArbitrary {\n  private:\n    std::vector<int>\
    \ base;\n    std::vector<T> acc;\n    int dim;\n\n    std::vector<int> inner_base;\n\
    \    int n;\n\n    constexpr void build() {\n        inner_base.resize(dim + 1,\
    \ 1);\n        for (int i = 1; i < dim + 1; ++i) { inner_base[i] = inner_base[i\
    \ - 1] * base[i - 1]; }\n        n = 1;\n        for (int x : base) n *= x;\n\n\
    \        for (int i = 0; i < dim; ++i) {\n            for (int coord = 0; coord\
    \ < n; ++coord) {\n                if (coord / inner_base[i + 1] == (coord + inner_base[i])\
    \ / inner_base[i + 1]) {\n                    acc[coord + inner_base[i]] += acc[coord];\n\
    \                }\n            }\n        }\n    }\n\n  public:\n    constexpr\
    \ PrefixSumArbitrary() = default;\n\n    constexpr PrefixSumArbitrary(const std::vector<int>\
    \ &base_, const std::vector<T> &a)\n        : base(base_),\n          acc(a),\n\
    \          dim(int(base_.size())) {\n        build();\n    }\n\n    constexpr\
    \ T sum(const std::vector<int> &l, const std::vector<int> &r) const {\n      \
    \  assert(int(l.size()) == dim and int(r.size()) == dim);\n        for (int i\
    \ = 0; i < dim; ++i) {\n            if (r[i] == 0) return T{};\n        }\n\n\
    \        T res{};\n        for (int bit = 0; bit < (1 << dim); ++bit) {\n    \
    \        int coord = 0;\n            bool bad = false;\n            for (int i\
    \ = 0; i < dim; ++i) {\n                if (bit >> i & 1) {\n                \
    \    if (l[i] == 0) {\n                        bad = true;\n                 \
    \       break;\n                    }\n                    coord += (l[i] - 1)\
    \ * inner_base[i];\n                } else {\n                    coord += (r[i]\
    \ - 1) * inner_base[i];\n                }\n            }\n            if (bad)\
    \ continue;\n            res += (__builtin_popcount(bit) & 1 ? -1 : 1) * acc[coord];\n\
    \        }\n        return res;\n    }\n\n    constexpr T operator()(const std::vector<int>\
    \ &l, const std::vector<int> &r) const {\n        return sum(l, r);\n    }\n};\n\
    \n} // namespace kk2\n\n#endif // DARA_STRUCTURE_PREFIX_SUM_ARBITRARY_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/prefix_sum_arbitrary.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:18:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_0560_2.test.cpp
documentation_of: data_structure/prefix_sum_arbitrary.hpp
layout: document
redirect_from:
- /library/data_structure/prefix_sum_arbitrary.hpp
- /library/data_structure/prefix_sum_arbitrary.hpp.html
title: data_structure/prefix_sum_arbitrary.hpp
---
