---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/kth_root_floor.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cmath>\n#include <cstdint>\n#include <functional>\n\nnamespace kk2 {\n\
    \nuint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if (a <= 1 || k == 1)\
    \ return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t x) {\n\
    \        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1, q *= q)\
    \ {\n            if (b & 1) p *= q;\n        }\n        return p <= a;\n    };\n\
    \    uint64_t x = powl(a, (long double)1.0 / k);\n    while (!check(x)) --x;\n\
    \    while (check(x + 1)) ++x;\n    return x;\n}\n\n// return floor(a ^ {1/k})\n\
    template <class return_type = uint64_t, class T, class U> return_type kth_root_floor(T\
    \ a, U k) {\n    return (return_type)kth_root_floor_inner((uint64_t)a, (int)k);\n\
    }\n\nuint64_t kth_root_ceil_inner(uint64_t a, int k) {\n    if (a <= 1 || k ==\
    \ 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t x)\
    \ {\n        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1, q\
    \ *= q) {\n            if (b & 1) p *= q;\n        }\n        return p == a;\n\
    \    };\n    uint64_t x = kth_root_floor_inner(a, k);\n    return check(x) ? x\
    \ : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate <class return_type = uint64_t,\
    \ class T, class U> return_type kth_root_ceil(T a, U k) {\n    return (return_type)kth_root_ceil_inner((uint64_t)a,\
    \ (int)k);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_KTH_ROOT_FLOOR_HPP\n#define MATH_KTH_ROOT_FLOOR_HPP 1\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <cstdint>\n#include <functional>\n\n\
    namespace kk2 {\n\nuint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if\
    \ (a <= 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t\
    \ x) {\n        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1,\
    \ q *= q) {\n            if (b & 1) p *= q;\n        }\n        return p <= a;\n\
    \    };\n    uint64_t x = powl(a, (long double)1.0 / k);\n    while (!check(x))\
    \ --x;\n    while (check(x + 1)) ++x;\n    return x;\n}\n\n// return floor(a ^\
    \ {1/k})\ntemplate <class return_type = uint64_t, class T, class U> return_type\
    \ kth_root_floor(T a, U k) {\n    return (return_type)kth_root_floor_inner((uint64_t)a,\
    \ (int)k);\n}\n\nuint64_t kth_root_ceil_inner(uint64_t a, int k) {\n    if (a\
    \ <= 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t\
    \ x) {\n        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1,\
    \ q *= q) {\n            if (b & 1) p *= q;\n        }\n        return p == a;\n\
    \    };\n    uint64_t x = kth_root_floor_inner(a, k);\n    return check(x) ? x\
    \ : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate <class return_type = uint64_t,\
    \ class T, class U> return_type kth_root_ceil(T a, U k) {\n    return (return_type)kth_root_ceil_inner((uint64_t)a,\
    \ (int)k);\n}\n\n} // namespace kk2\n\n#endif // MATH_KTH_ROOT_FLOOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/kth_root_floor.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/kth_root_floor.hpp
layout: document
redirect_from:
- /library/math/kth_root_floor.hpp
- /library/math/kth_root_floor.hpp.html
title: math/kth_root_floor.hpp
---
