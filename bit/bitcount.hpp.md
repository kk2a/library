---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: data_structure/my_bitset.hpp
    title: data_structure/my_bitset.hpp
  - icon: ':x:'
    path: matrix/matrix_F2.hpp
    title: matrix/matrix_F2.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    title: verify/yosupo_linalg/matrix_det_f2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    title: verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    title: verify/yosupo_linalg/matrix_product_f2.test.cpp
  - icon: ':x:'
    path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef BIT_BITCOUNT_HPP\n#define BIT_BITCOUNT_HPP 1\n\n#include <cassert>\n\
    \n#include \"../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> int ctz(T x) {\n    static_assert(is_integral<T>::value);\n    assert(x !=\
    \ T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
    \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
    \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
    \ long long)(x >> 64));\n    }\n}\n\ntemplate <typename T> int clz(T x) {\n  \
    \  static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\n    if constexpr\
    \ (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    } else if constexpr\
    \ (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n    } else {\n     \
    \   if (x >> 64) return __builtin_clzll((unsigned long long)(x >> 64));\n    \
    \    return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> int popcount(T x) {\n    static_assert(is_integral<T>::value);\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_popcount(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_popcountll(x);\n\
    \    } else {\n        return __builtin_popcountll((unsigned long long)(x >> 64))\n\
    \               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\n}; // namespace kk2\n\n#endif // BIT_BITCOUNT_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: bit/bitcount.hpp
  requiredBy:
  - matrix/matrix_F2.hpp
  - data_structure/my_bitset.hpp
  timestamp: '2024-10-22 04:14:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
documentation_of: bit/bitcount.hpp
layout: document
redirect_from:
- /library/bit/bitcount.hpp
- /library/bit/bitcount.hpp.html
title: bit/bitcount.hpp
---
