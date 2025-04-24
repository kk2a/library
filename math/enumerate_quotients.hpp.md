---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/multiplicative_function/counting_square_free.hpp
    title: math/multiplicative_function/counting_square_free.hpp
  - icon: ':x:'
    path: math/multiplicative_function/prefix_sum.hpp
    title: math/multiplicative_function/prefix_sum.hpp
  - icon: ':question:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
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
  bundledCode: "#line 1 \"math/enumerate_quotients.hpp\"\n\n\n\n#include <numeric>\n\
    #include <vector>\n\n#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\
    \n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\
    \n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)\
    \   (for all x)          ...(2)\n\n// return floor(a / b)\ntemplate <typename\
    \ T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b != 0);\n    if\
    \ (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n    // floor(x)\
    \ = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by (1)\n    return\
    \ -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T, typename\
    \ U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a % b == 0)\
    \ return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)\
    \      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"\
    math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T\
    \ n) {\n    assert(n >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n\
    \    if (x == T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while\
    \ (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename\
    \ T> T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n \
    \   T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
    \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
    }\n\n} // namespace kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n    int sqrt_n;\n\
    \    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n))\
    \ {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(),\
    \ res.begin() + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n;\
    \ i; --i, ++j) res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const\
    \ { return res; }\n\n    int size() const { return res.size(); }\n\n    const\
    \ T &operator[](int i) const { return res[i]; }\n\n    int idx(T x) const {\n\
    \        if (x <= sqrt_n) return x - 1;\n        return size() - n / x;\n    }\n\
    };\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_ENUMERATE_QUOTIENTS_HPP\n#define KK2_MATH_ENUMERATE_QUOTIENTS_HPP\
    \ 1\n\n#include <numeric>\n#include <vector>\n\n#include \"sqrt_floor.hpp\"\n\n\
    namespace kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n\
    \    int sqrt_n;\n    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n),\
    \ sqrt_n(sqrt_floor(n)) {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n  \
    \      std::iota(res.begin(), res.begin() + sqrt_n, 1);\n        for (T i = n\
    \ / (sqrt_n + 1), j = sqrt_n; i; --i, ++j) res[j] = n / i;\n    }\n\n    const\
    \ std::vector<T> &get() const { return res; }\n\n    int size() const { return\
    \ res.size(); }\n\n    const T &operator[](int i) const { return res[i]; }\n\n\
    \    int idx(T x) const {\n        if (x <= sqrt_n) return x - 1;\n        return\
    \ size() - n / x;\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_ENUMERATE_QUOTIENTS_HPP\n"
  dependsOn:
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  isVerificationFile: false
  path: math/enumerate_quotients.hpp
  requiredBy:
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/prefix_sum.hpp
  - math/multiplicative_function/prime_counting.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_math/prime_counting.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/enumerate_quotients.test.cpp
  - verify/unit_test/lpf_table_extend.test.cpp
  - verify/unit_test/isprime_table_extend.test.cpp
  - verify/unit_test/prime_table_extend.test.cpp
documentation_of: math/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/math/enumerate_quotients.hpp
- /library/math/enumerate_quotients.hpp.html
title: math/enumerate_quotients.hpp
---
