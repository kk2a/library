---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/Eratosthenes.hpp
    title: math/Eratosthenes.hpp
  - icon: ':x:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':x:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':x:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/prime_counting.test.cpp
    title: verify/yosupo_math/prime_counting.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/prime_counting.hpp\"\n\n\n\n\
    #include <vector>\n\n#line 1 \"math/Eratosthenes.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#line 8 \"math/Eratosthenes.hpp\"\n\n\
    namespace kk2 {\n\nstruct Erato {\n    static inline std::vector<bool> _isprime{};\n\
    \    static inline std::vector<int> _minfactor{}, _mobius{}, _primes{};\n\n  \
    \  Erato() = delete;\n\n    static void set_upper(int m) {\n        if ((int)_isprime.size()\
    \ > m) return;\n        int start = std::max<int>(2, _isprime.size());\n\n   \
    \     _isprime.resize(m + 1, true);\n        _minfactor.resize(m + 1, -1);\n \
    \       _mobius.resize(m + 1, 1);\n        _isprime[1] = false;\n        _minfactor[1]\
    \ = 1;\n\n        for (const int &p : _primes) {\n            for (int q = p *\
    \ ((start + p - 1) / p); q <= m; q += p) {\n                _isprime[q] = false;\n\
    \n                if (_minfactor[q] == -1) _minfactor[q] = p;\n              \
    \  if ((q / p) % p == 0) _mobius[q] = 0;\n                else _mobius[q] = -_mobius[q];\n\
    \            }\n        }\n\n        for (int p = start; p <= m; ++p) {\n    \
    \        if (!_isprime[p]) continue;\n\n            _minfactor[p] = p;\n     \
    \       _mobius[p] = -1;\n            _primes.emplace_back(p);\n\n           \
    \ for (int q = p * 2; q <= m; q += p) {\n                _isprime[q] = false;\n\
    \n                if (_minfactor[q] == -1) _minfactor[q] = p;\n              \
    \  if ((q / p) % p == 0) _mobius[q] = 0;\n                else _mobius[q] = -_mobius[q];\n\
    \            }\n        }\n    }\n\n    static bool isprime(int n) {\n       \
    \ assert(n < (int)_isprime.size() && n != 0);\n        return _isprime[n];\n \
    \   }\n\n    static int mobius(int n) {\n        assert(n < (int)_mobius.size()\
    \ && n != 0);\n        return _mobius[n];\n    }\n\n    static int minfactor(int\
    \ n) {\n        assert(n < (int)_minfactor.size() && n != 0);\n        return\
    \ _minfactor[n];\n    }\n\n    static const std::vector<int> &primes() { return\
    \ _primes; }\n\n    static std::vector<std::pair<int, int>> factorize(int n) {\n\
    \        assert(n < (int)_isprime.size() && n != 0);\n        if (n == 1 || n\
    \ == -1) return {};\n        if (n < 0) n = -n;\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (n > 1) {\n            int p = _minfactor[n];\n  \
    \          int exp = 0;\n\n            while (_minfactor[n] == p) {\n        \
    \        n /= p;\n                ++exp;\n            }\n            res.emplace_back(p,\
    \ exp);\n        }\n        return res;\n    }\n\n    static std::vector<int>\
    \ divisors(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n   \
    \     if (n == 1 || n == -1) return {1};\n        if (n < 0) n = -n;\n       \
    \ std::vector<int> res{1};\n        auto pf = factorize(n);\n\n        for (auto\
    \ p : pf) {\n            int s = (int)res.size();\n            for (int i = 0;\
    \ i < s; ++i) {\n                int v = 1;\n                for (int j = 0; j\
    \ < p.second; ++j) {\n                    v *= p.first;\n                    res.push_back(res[i]\
    \ * v);\n                }\n            }\n        }\n        return res;\n  \
    \  }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/enumerate_quotients.hpp\"\n\
    \n\n\n#include <numeric>\n#line 6 \"math/enumerate_quotients.hpp\"\n\n#line 1\
    \ \"math/sqrt_floor.hpp\"\n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\
    \n\n\n\n#line 5 \"math/frac_floor.hpp\"\n\nnamespace kk2 {\n\n// floor(x) = ceil(x)\
    \ - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)     \
    \     ...(2)\n\n// return floor(a / b)\ntemplate <typename T, typename U> constexpr\
    \ T fracfloor(T a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a /\
    \ b;\n    if (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n\
    \    //          = -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n//\
    \ return ceil(a / b)\ntemplate <typename T, typename U> constexpr T fracceil(T\
    \ a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a\
    \ >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return\
    \ -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T n) {\n    assert(n >=\
    \ 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x == T(0))\
    \ ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <= kk2::fracfloor(n,\
    \ x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename T> T sqrt_ceil(T n) {\n\
    \    assert(n >= 0);\n    if (n <= T(1)) return n;\n    T x = std::sqrt(n);\n\
    \    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n, x)) ++x;\n    while\
    \ (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class T>\nstruct EnumerateQuotients {\n    T n;\n    int sqrt_n;\n    std::vector<T>\
    \ res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n)) {\n      \
    \  res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(), res.begin()\
    \ + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j)\
    \ res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const { return res;\
    \ }\n\n    int size() const { return res.size(); }\n\n    const T &operator[](int\
    \ i) const { return res[i]; }\n\n    int idx(T x) const {\n        if (x <= sqrt_n)\
    \ return x - 1;\n        return size() - n / x;\n    }\n};\n\n} // namespace kk2\n\
    \n\n#line 8 \"math/multiplicative_function/prime_counting.hpp\"\n\nnamespace kk2\
    \ {\n\nlong long prime_counting(long long n) {\n    kk2::EnumerateQuotients<long\
    \ long> eq(n);\n    kk2::Erato::set_upper(eq.sqrt_n);\n    std::vector<long long>\
    \ dp(eq.size());\n    for (int i = 0; i < eq.size(); ++i) dp[i] = eq[i] - 1;\n\
    \    for (const long long p : kk2::Erato::primes()) {\n        for (int i = eq.size()\
    \ - 1;; --i) {\n            if (eq[i] < p * p) break;\n            dp[i] -= dp[eq.idx(eq[i]\
    \ / p)] - dp[p - 2];\n        }\n    }\n    return dp.back();\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../Eratosthenes.hpp\"\n#include \"../enumerate_quotients.hpp\"\
    \n\nnamespace kk2 {\n\nlong long prime_counting(long long n) {\n    kk2::EnumerateQuotients<long\
    \ long> eq(n);\n    kk2::Erato::set_upper(eq.sqrt_n);\n    std::vector<long long>\
    \ dp(eq.size());\n    for (int i = 0; i < eq.size(); ++i) dp[i] = eq[i] - 1;\n\
    \    for (const long long p : kk2::Erato::primes()) {\n        for (int i = eq.size()\
    \ - 1;; --i) {\n            if (eq[i] < p * p) break;\n            dp[i] -= dp[eq.idx(eq[i]\
    \ / p)] - dp[p - 2];\n        }\n    }\n    return dp.back();\n}\n\n} // namespace\
    \ kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_PRIME_COUNTING_HPP\n"
  dependsOn:
  - math/Eratosthenes.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  isVerificationFile: false
  path: math/multiplicative_function/prime_counting.hpp
  requiredBy: []
  timestamp: '2025-02-01 17:57:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/prime_counting.test.cpp
documentation_of: math/multiplicative_function/prime_counting.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/prime_counting.hpp
- /library/math/multiplicative_function/prime_counting.hpp.html
title: math/multiplicative_function/prime_counting.hpp
---
