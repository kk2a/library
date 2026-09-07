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
    - filename: sqrt_floor.hpp
      icon: LIBRARY_ALL_AC
      path: math/sqrt_floor.hpp
    type: Depends on
  - files:
    - filename: counting_square_free.hpp
      icon: LIBRARY_NO_TESTS
      path: math/multiplicative_function/counting_square_free.hpp
    - filename: prefix_sum.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prefix_sum.hpp
    - filename: prime_counting.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/prime_counting.hpp
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
  - math/sqrt_floor.hpp
  embedded:
  - code: "#ifndef KK2_MATH_ENUMERATE_QUOTIENTS_HPP\n#define KK2_MATH_ENUMERATE_QUOTIENTS_HPP\
      \ 1\n\n#include <numeric>\n#include <vector>\n\n#include \"sqrt_floor.hpp\"\n\
      \nnamespace kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n\
      \    int sqrt_n;\n    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n),\
      \ sqrt_n(sqrt_floor(n)) {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n\
      \        std::iota(res.begin(), res.begin() + sqrt_n, 1);\n        for (T i\
      \ = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j) res[j] = n / i;\n    }\n\n  \
      \  const std::vector<T> &get() const { return res; }\n\n    int size() const\
      \ { return res.size(); }\n\n    const T &operator[](int i) const { return res[i];\
      \ }\n\n    int idx(T x) const {\n        if (x <= sqrt_n) return x - 1;\n  \
      \      return size() - n / x;\n    }\n};\n\n} // namespace kk2\n\n#endif //\
      \ KK2_MATH_ENUMERATE_QUOTIENTS_HPP\n"
    name: default
  - code: "#line 1 \"math/enumerate_quotients.hpp\"\n\n\n\n#include <numeric>\n#include\
      \ <vector>\n\n#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\n#line\
      \ 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\n\
      // floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)\
      \   (for all x)          ...(2)\n\n// return floor(a / b)\ntemplate <typename\
      \ T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b != 0);\n  \
      \  if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n    // floor(x)\
      \ = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by (1)\n    return\
      \ -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T, typename\
      \ U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a % b ==\
      \ 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)\
      \      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7\
      \ \"math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T\
      \ n) {\n    assert(n >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n\
      \    if (x == T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while\
      \ (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename\
      \ T> T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n\
      \    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
      \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
      }\n\n} // namespace kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n    int\
      \ sqrt_n;\n    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n))\
      \ {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(),\
      \ res.begin() + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n;\
      \ i; --i, ++j) res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const\
      \ { return res; }\n\n    int size() const { return res.size(); }\n\n    const\
      \ T &operator[](int i) const { return res[i]; }\n\n    int idx(T x) const {\n\
      \        if (x <= sqrt_n) return x - 1;\n        return size() - n / x;\n  \
      \  }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/enumerate_quotients.hpp
  pathExtension: hpp
  requiredBy:
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/prefix_sum.hpp
  - math/multiplicative_function/prime_counting.hpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/prime_table_extend.test.cpp
  - verify/yosupo_math/enumerate_quotients.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/prime_counting.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/enumerate_quotients.hpp
layout: document
---
