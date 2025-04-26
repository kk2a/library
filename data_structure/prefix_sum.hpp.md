---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_static_range_sum.test.cpp
    title: verify/yosupo_ds/ds_static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/prefix_sum.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\n\
    template <class T> struct PrefixSum {\n    std::vector<T> acc;\n    int n;\n\n\
    \    constexpr PrefixSum() = default;\n\n    constexpr PrefixSum(int n_) : acc(n_\
    \ + 1), n(n_) {}\n\n    constexpr PrefixSum(const std::vector<T> &a) : acc(a.size()\
    \ + 1), n((int)a.size()) {\n        for (int i = 0; i < n; ++i) { acc[i + 1] =\
    \ acc[i] + a[i]; }\n    }\n\n    constexpr void build() {\n        for (int i\
    \ = 0; i < n; ++i) { acc[i + 1] += acc[i]; }\n    }\n\n    constexpr void init_set(int\
    \ p, T x) {\n        assert(0 <= p && p < n);\n        acc[p + 1] = x;\n    }\n\
    \n    constexpr T sum(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        return acc[r] - acc[l];\n    }\n\n    constexpr T get(int\
    \ i) const {\n        assert(0 <= i && i < n);\n        return acc[i + 1] - acc[i];\n\
    \    }\n\n    constexpr T operator[](int i) const {\n        assert(0 <= i &&\
    \ i < n);\n        return acc[i + 1] - acc[i];\n    }\n\n    constexpr T operator()(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ acc[r] - acc[l];\n    }\n\n    constexpr int size() const { return n; }\n\n\
    \    // require: acc is non-decreasing\n    // return r s.t.\n    // r = n or\
    \ sum(l, r) >= x\n    // r = l or sum(l, r) < x\n    constexpr int lower(int l,\
    \ T x) const {\n        assert(0 <= l && l <= n);\n        int ng = l - 1, ok\
    \ = n;\n        while (ok - ng > 1) {\n            int mid = (ok + ng) >> 1;\n\
    \            if (acc[mid] - acc[l] < x) ng = mid;\n            else ok = mid;\n\
    \        }\n        return ok;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_PREFIX_SUM_HPP\n#define KK2_DATA_STRUCTURE_PREFIX_SUM_HPP\
    \ 1\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \nnamespace kk2 {\n\ntemplate <class T> struct PrefixSum {\n    std::vector<T>\
    \ acc;\n    int n;\n\n    constexpr PrefixSum() = default;\n\n    constexpr PrefixSum(int\
    \ n_) : acc(n_ + 1), n(n_) {}\n\n    constexpr PrefixSum(const std::vector<T>\
    \ &a) : acc(a.size() + 1), n((int)a.size()) {\n        for (int i = 0; i < n;\
    \ ++i) { acc[i + 1] = acc[i] + a[i]; }\n    }\n\n    constexpr void build() {\n\
    \        for (int i = 0; i < n; ++i) { acc[i + 1] += acc[i]; }\n    }\n\n    constexpr\
    \ void init_set(int p, T x) {\n        assert(0 <= p && p < n);\n        acc[p\
    \ + 1] = x;\n    }\n\n    constexpr T sum(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        return acc[r] - acc[l];\n    }\n\n    constexpr\
    \ T get(int i) const {\n        assert(0 <= i && i < n);\n        return acc[i\
    \ + 1] - acc[i];\n    }\n\n    constexpr T operator[](int i) const {\n       \
    \ assert(0 <= i && i < n);\n        return acc[i + 1] - acc[i];\n    }\n\n   \
    \ constexpr T operator()(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return acc[r] - acc[l];\n    }\n\n    constexpr int size()\
    \ const { return n; }\n\n    // require: acc is non-decreasing\n    // return\
    \ r s.t.\n    // r = n or sum(l, r) >= x\n    // r = l or sum(l, r) < x\n    constexpr\
    \ int lower(int l, T x) const {\n        assert(0 <= l && l <= n);\n        int\
    \ ng = l - 1, ok = n;\n        while (ok - ng > 1) {\n            int mid = (ok\
    \ + ng) >> 1;\n            if (acc[mid] - acc[l] < x) ng = mid;\n            else\
    \ ok = mid;\n        }\n        return ok;\n    }\n};\n\n} // namespace kk2\n\n\
    #endif // KK2_DATA_STRUCTURE_PREFIX_SUM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/prefix_sum.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_static_range_sum.test.cpp
documentation_of: data_structure/prefix_sum.hpp
layout: document
redirect_from:
- /library/data_structure/prefix_sum.hpp
- /library/data_structure/prefix_sum.hpp.html
title: data_structure/prefix_sum.hpp
---
