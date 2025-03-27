---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convolution/convolution_gcd.hpp
    title: convolution/convolution_gcd.hpp
  - icon: ':x:'
    path: convolution/convolution_lcm.hpp
    title: convolution/convolution_lcm.hpp
  - icon: ':x:'
    path: convolution/divisor_multiple_transform.hpp
    title: convolution/divisor_multiple_transform.hpp
  - icon: ':warning:'
    path: data_structure/convex_hull_trick_add_monotone.hpp
    title: data_structure/convex_hull_trick_add_monotone.hpp
  - icon: ':question:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/counting_square_free.hpp
    title: math/multiplicative_function/counting_square_free.hpp
  - icon: ':x:'
    path: math/multiplicative_function/prefix_sum.hpp
    title: math/multiplicative_function/prefix_sum.hpp
  - icon: ':question:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
  - icon: ':question:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/isprime_table_extend.test.cpp
    title: verify/unit_test/isprime_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/lpf_table_extend.test.cpp
    title: verify/unit_test/lpf_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/prime_table_extend.test.cpp
    title: verify/unit_test/prime_table_extend.test.cpp
  - icon: ':x:'
    path: verify/yosupo_convolution/convolution_gcd.test.cpp
    title: verify/yosupo_convolution/convolution_gcd.test.cpp
  - icon: ':x:'
    path: verify/yosupo_convolution/convolution_lcm.test.cpp
    title: verify/yosupo_convolution/convolution_lcm.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/enumerate_primes.test.cpp
    title: verify/yosupo_math/enumerate_primes.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/enumerate_primes.test.cpp
    title: verify/yosupo_math/enumerate_primes.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/enumerate_quotients.test.cpp
    title: verify/yosupo_math/enumerate_quotients.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    title: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/prime_counting.test.cpp
    title: verify/yosupo_math/prime_counting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x)\
    \ = -ceil(-x)   (for all x)          ...(2)\n\n// return floor(a / b)\ntemplate\
    \ <typename T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b !=\
    \ 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n  \
    \  // floor(x) = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by (1)\n\
    \    return -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T,\
    \ typename U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a\
    \ % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x)\
    \ = -floor(-x)      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef KK2_MATH_FRAC_FLOOR_HPP\n#define KK2_MATH_FRAC_FLOOR_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in\
    \ Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return\
    \ floor(a / b)\ntemplate <typename T, typename U> constexpr T fracfloor(T a, U\
    \ b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0)\
    \ return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //          =\
    \ -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return ceil(a /\
    \ b)\ntemplate <typename T, typename U> constexpr T fracceil(T a, U b) {\n   \
    \ assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a\
    \ / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return -((-a) / b);\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_MATH_FRAC_FLOOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/frac_floor.hpp
  requiredBy:
  - convolution/convolution_gcd.hpp
  - convolution/divisor_multiple_transform.hpp
  - convolution/convolution_lcm.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/multiplicative_function/prefix_sum.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/enumerate_quotients.hpp
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  - data_structure/convex_hull_trick_add_monotone.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_math/prime_counting.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/enumerate_quotients.test.cpp
  - verify/yosupo_math/enumerate_primes.test.cpp
  - verify/yosupo_math/enumerate_primes.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/unit_test/prime_table_extend.test.cpp
  - verify/unit_test/lpf_table_extend.test.cpp
  - verify/unit_test/isprime_table_extend.test.cpp
documentation_of: math/frac_floor.hpp
layout: document
redirect_from:
- /library/math/frac_floor.hpp
- /library/math/frac_floor.hpp.html
title: math/frac_floor.hpp
---
