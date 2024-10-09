---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/my_bitset.hpp
    title: data_structure/my_bitset.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/matrix_F2.hpp
    title: matrix/matrix_F2.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    title: verify/yosupo_linalg/matrix_det_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    title: verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    title: verify/yosupo_linalg/matrix_product_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bit/bitcount.hpp\"\n\n\n\n#include <cassert>\n\n#line 1\
    \ \"type_traits/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace kk2\
    \ {\n\ntemplate <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> int\
    \ ctz(T x) {\n    static_assert(is_integral_extended<T>::value);\n    assert(x\
    \ != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
    \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
    \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
    \ long long)(x >> 64));\n    }\n}\n\ntemplate <typename T> int clz(T x) {\n  \
    \  static_assert(is_integral_extended<T>::value);\n    assert(x != T(0));\n\n\
    \    if constexpr (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n \
    \   } else {\n        if (x >> 64) return __builtin_clzll((unsigned long long)(x\
    \ >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> int popcount(T x) {\n    static_assert(is_integral_extended<T>::value);\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_popcount(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_popcountll(x);\n\
    \    } else {\n        return __builtin_popcountll((unsigned long long)(x >> 64))\n\
    \               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\n}; // namespace kk2\n\n\n"
  code: "#ifndef BIT_BITCOUNT_HPP\n#define BIT_BITCOUNT_HPP 1\n\n#include <cassert>\n\
    \n#include \"../type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ T> int ctz(T x) {\n    static_assert(is_integral_extended<T>::value);\n    assert(x\
    \ != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
    \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
    \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
    \ long long)(x >> 64));\n    }\n}\n\ntemplate <typename T> int clz(T x) {\n  \
    \  static_assert(is_integral_extended<T>::value);\n    assert(x != T(0));\n\n\
    \    if constexpr (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n \
    \   } else {\n        if (x >> 64) return __builtin_clzll((unsigned long long)(x\
    \ >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> int popcount(T x) {\n    static_assert(is_integral_extended<T>::value);\n\
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
  - data_structure/my_bitset.hpp
  - matrix/matrix_F2.hpp
  timestamp: '2024-10-09 14:51:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
