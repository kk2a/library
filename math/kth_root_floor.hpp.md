---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/kth_root_int.test.cpp
    title: verify/yosupo_math/kth_root_int.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/kth_root_int_ceil.test.cpp
    title: verify/yosupo_math/kth_root_int_ceil.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/kth_root_floor.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cmath>\n#include <cstdint>\n#include <functional>\n\nnamespace kk2 {\n\
    \nuint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if (a <= 1 || k == 1)\
    \ return a;\n    if (64 <= k) return 1;\n    auto check = [&](uint64_t x) {\n\
    \        uint64_t p = 1, q = x;\n        for (int b = k; b;) {\n            if\
    \ (b & 1) {\n                if (a / p < q) return false;\n                p *=\
    \ q;\n            }\n            if (b >>= 1) {\n                if (a / q < q)\
    \ return false;\n                q *= q;\n            }\n        }\n        return\
    \ p <= a;\n    };\n    uint64_t x = std::pow(a, 1.0 / k);\n    while (!check(x))\
    \ --x;\n    while (check(x + 1)) ++x;\n    return x;\n}\n\n// return floor(a ^\
    \ {1/k})\ntemplate <class T, class U> uint64_t kth_root_floor(T a, U k) {\n  \
    \  return kth_root_floor_inner((uint64_t)a, (int)k);\n}\n\nuint64_t kth_root_ceil_inner(uint64_t\
    \ a, int k) {\n    if (a <= 1 || k == 1) return a;\n    if (64 <= k) return 2;\n\
    \    auto check = [&](uint64_t x) {\n        uint64_t p = 1, q = x;\n        for\
    \ (int b = k; b;) {\n            if (b & 1) p *= q;\n            if (b >>= 1)\
    \ q *= q;\n        }\n        return p == a;\n    };\n    uint64_t x = kth_root_floor_inner(a,\
    \ k);\n    return check(x) ? x : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate\
    \ <class T, class U> uint64_t kth_root_ceil(T a, U k) {\n    return kth_root_ceil_inner((uint64_t)a,\
    \ (int)k);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_KTH_ROOT_FLOOR_HPP\n#define KK2_MATH_KTH_ROOT_FLOOR_HPP\
    \ 1\n\n#include <algorithm>\n#include <cmath>\n#include <cstdint>\n#include <functional>\n\
    \nnamespace kk2 {\n\nuint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if\
    \ (a <= 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](uint64_t\
    \ x) {\n        uint64_t p = 1, q = x;\n        for (int b = k; b;) {\n      \
    \      if (b & 1) {\n                if (a / p < q) return false;\n          \
    \      p *= q;\n            }\n            if (b >>= 1) {\n                if\
    \ (a / q < q) return false;\n                q *= q;\n            }\n        }\n\
    \        return p <= a;\n    };\n    uint64_t x = std::pow(a, 1.0 / k);\n    while\
    \ (!check(x)) --x;\n    while (check(x + 1)) ++x;\n    return x;\n}\n\n// return\
    \ floor(a ^ {1/k})\ntemplate <class T, class U> uint64_t kth_root_floor(T a, U\
    \ k) {\n    return kth_root_floor_inner((uint64_t)a, (int)k);\n}\n\nuint64_t kth_root_ceil_inner(uint64_t\
    \ a, int k) {\n    if (a <= 1 || k == 1) return a;\n    if (64 <= k) return 2;\n\
    \    auto check = [&](uint64_t x) {\n        uint64_t p = 1, q = x;\n        for\
    \ (int b = k; b;) {\n            if (b & 1) p *= q;\n            if (b >>= 1)\
    \ q *= q;\n        }\n        return p == a;\n    };\n    uint64_t x = kth_root_floor_inner(a,\
    \ k);\n    return check(x) ? x : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate\
    \ <class T, class U> uint64_t kth_root_ceil(T a, U k) {\n    return kth_root_ceil_inner((uint64_t)a,\
    \ (int)k);\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_KTH_ROOT_FLOOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/kth_root_floor.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/kth_root_int_ceil.test.cpp
  - verify/yosupo_math/kth_root_int.test.cpp
documentation_of: math/kth_root_floor.hpp
layout: document
redirect_from:
- /library/math/kth_root_floor.hpp
- /library/math/kth_root_floor.hpp.html
title: math/kth_root_floor.hpp
---
