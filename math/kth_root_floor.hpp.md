---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: kth_root_int.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/kth_root_int.test.cpp
    - filename: kth_root_int_ceil.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/kth_root_int_ceil.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_KTH_ROOT_FLOOR_HPP\n#define KK2_MATH_KTH_ROOT_FLOOR_HPP\
      \ 1\n\n#include <algorithm>\n#include <cmath>\n#include <cstdint>\n#include\
      \ <functional>\n\nnamespace kk2 {\n\nuint64_t kth_root_floor_inner(uint64_t\
      \ a, int k) {\n    if (a <= 1 || k == 1) return a;\n    if (64 <= k) return\
      \ 1;\n    auto check = [&](uint64_t x) {\n        uint64_t p = 1, q = x;\n \
      \       for (int b = k; b;) {\n            if (b & 1) {\n                if\
      \ (a / p < q) return false;\n                p *= q;\n            }\n      \
      \      if (b >>= 1) {\n                if (a / q < q) return false;\n      \
      \          q *= q;\n            }\n        }\n        return p <= a;\n    };\n\
      \    uint64_t x = std::pow(a, 1.0 / k);\n    while (!check(x)) --x;\n    while\
      \ (check(x + 1)) ++x;\n    return x;\n}\n\n// return floor(a ^ {1/k})\ntemplate\
      \ <class T, class U> uint64_t kth_root_floor(T a, U k) {\n    return kth_root_floor_inner((uint64_t)a,\
      \ (int)k);\n}\n\nuint64_t kth_root_ceil_inner(uint64_t a, int k) {\n    if (a\
      \ <= 1 || k == 1) return a;\n    if (64 <= k) return 2;\n    auto check = [&](uint64_t\
      \ x) {\n        uint64_t p = 1, q = x;\n        for (int b = k; b;) {\n    \
      \        if (b & 1) p *= q;\n            if (b >>= 1) q *= q;\n        }\n \
      \       return p == a;\n    };\n    uint64_t x = kth_root_floor_inner(a, k);\n\
      \    return check(x) ? x : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate\
      \ <class T, class U> uint64_t kth_root_ceil(T a, U k) {\n    return kth_root_ceil_inner((uint64_t)a,\
      \ (int)k);\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_KTH_ROOT_FLOOR_HPP\n"
    name: default
  - code: "#line 1 \"math/kth_root_floor.hpp\"\n\n\n\n#include <algorithm>\n#include\
      \ <cmath>\n#include <cstdint>\n#include <functional>\n\nnamespace kk2 {\n\n\
      uint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if (a <= 1 || k == 1)\
      \ return a;\n    if (64 <= k) return 1;\n    auto check = [&](uint64_t x) {\n\
      \        uint64_t p = 1, q = x;\n        for (int b = k; b;) {\n           \
      \ if (b & 1) {\n                if (a / p < q) return false;\n             \
      \   p *= q;\n            }\n            if (b >>= 1) {\n                if (a\
      \ / q < q) return false;\n                q *= q;\n            }\n        }\n\
      \        return p <= a;\n    };\n    uint64_t x = std::pow(a, 1.0 / k);\n  \
      \  while (!check(x)) --x;\n    while (check(x + 1)) ++x;\n    return x;\n}\n\
      \n// return floor(a ^ {1/k})\ntemplate <class T, class U> uint64_t kth_root_floor(T\
      \ a, U k) {\n    return kth_root_floor_inner((uint64_t)a, (int)k);\n}\n\nuint64_t\
      \ kth_root_ceil_inner(uint64_t a, int k) {\n    if (a <= 1 || k == 1) return\
      \ a;\n    if (64 <= k) return 2;\n    auto check = [&](uint64_t x) {\n     \
      \   uint64_t p = 1, q = x;\n        for (int b = k; b;) {\n            if (b\
      \ & 1) p *= q;\n            if (b >>= 1) q *= q;\n        }\n        return\
      \ p == a;\n    };\n    uint64_t x = kth_root_floor_inner(a, k);\n    return\
      \ check(x) ? x : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate <class T,\
      \ class U> uint64_t kth_root_ceil(T a, U k) {\n    return kth_root_ceil_inner((uint64_t)a,\
      \ (int)k);\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/kth_root_floor.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/kth_root_int.test.cpp
  - verify/yosupo_math/kth_root_int_ceil.test.cpp
documentation_of: math/kth_root_floor.hpp
layout: document
---
