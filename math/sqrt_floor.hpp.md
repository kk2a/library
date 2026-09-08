---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: frac_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/frac_floor.hpp
    type: Depends on
  - files:
    - filename: convolution_gcd.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_gcd.hpp
    - filename: convolution_lcm.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_lcm.hpp
    - filename: divisor_multiple_transform.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/divisor_multiple_transform.hpp
    - filename: enumerate_quotients.hpp
      icon: LIBRARY_ALL_AC
      path: math/enumerate_quotients.hpp
    - filename: counting_square_free.hpp
      icon: LIBRARY_NO_TESTS
      path: math/multiplicative_function/counting_square_free.hpp
    - filename: prefix_sum.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prefix_sum.hpp
    - filename: prime_counting.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prime_counting.hpp
    - filename: prime_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_table.hpp
    type: Required by
  - files:
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: prime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_table_extend.test.cpp
    - filename: convolution_gcd.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_gcd.test.cpp
    - filename: convolution_lcm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_lcm.test.cpp
    - filename: enumerate_primes.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_primes.test.cpp
    - filename: enumerate_quotients.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_quotients.test.cpp
    - filename: prefix_sum_of_multiplicative_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    - filename: prime_counting.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prime_counting.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    type: Verified with
  dependsOn:
  - math/frac_floor.hpp
  embedded:
  - code: "#ifndef KK2_MATH_SQRT_FLOOR_HPP\n#define KK2_MATH_SQRT_FLOOR_HPP 1\n\n\
      #include <cmath>\n\n#include \"frac_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate\
      \ <typename T> T sqrt_floor(T n) {\n    assert(n >= 0);\n    if (n == T(0))\
      \ return 0;\n    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x\
      \ > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <= kk2::fracfloor(n, x + 1))\
      \ ++x;\n    return x;\n}\n\ntemplate <typename T> T sqrt_ceil(T n) {\n    assert(n\
      \ >= 0);\n    if (n <= T(1)) return n;\n    T x = std::sqrt(n);\n    if (x ==\
      \ T(0)) ++x;\n    while (x < kk2::fracceil(n, x)) ++x;\n    while (x - 1 >=\
      \ kk2::fracceil(n, x - 1)) --x;\n    return x;\n}\n\n} // namespace kk2\n\n\
      #endif // KK2_MATH_SQRT_FLOOR_HPP\n"
    name: default
  - code: "#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\
      \n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for\
      \ all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)          ...(2)\n\
      \n// return floor(a / b)\ntemplate <typename T, typename U> constexpr T fracfloor(T\
      \ a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if\
      \ (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //\
      \          = -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return\
      \ ceil(a / b)\ntemplate <typename T, typename U> constexpr T fracceil(T a, U\
      \ b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >=\
      \ 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return\
      \ -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T n) {\n    assert(n\
      \ >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x ==\
      \ T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <=\
      \ kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename T>\
      \ T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n  \
      \  T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
      \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
      }\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/sqrt_floor.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_gcd.hpp
  - convolution/convolution_lcm.hpp
  - convolution/divisor_multiple_transform.hpp
  - math/enumerate_quotients.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/prefix_sum.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/prime_table.hpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/prime_table_extend.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/yosupo_math/enumerate_primes.test.cpp
  - verify/yosupo_math/enumerate_quotients.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/prime_counting.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/sqrt_floor.hpp
layout: document
---
