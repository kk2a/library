---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':question:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    title: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/prefix_sum.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <vector>\n\n#line 1 \"math/prime_table.hpp\"\n\n\n\n#line\
    \ 6 \"math/prime_table.hpp\"\n\n#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#include\
    \ <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x)\
    \ = -ceil(-x)   (for all x)          ...(2)\n\n// return floor(a / b)\ntemplate\
    \ <typename T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b !=\
    \ 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n  \
    \  // floor(x) = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by (1)\n\
    \    return -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T,\
    \ typename U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a\
    \ % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x)\
    \ = -floor(-x)      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\
    \n\n#line 7 \"math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T>\
    \ T sqrt_floor(T n) {\n    assert(n >= 0);\n    if (n == T(0)) return 0;\n   \
    \ T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x > kk2::fracfloor(n,\
    \ x)) --x;\n    while (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n\
    }\n\ntemplate <typename T> T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n\
    \ <= T(1)) return n;\n    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while\
    \ (x < kk2::fracceil(n, x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1))\
    \ --x;\n    return x;\n}\n\n} // namespace kk2\n\n\n#line 8 \"math/prime_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct PrimeTable {\n  private:\n    static inline int\
    \ _n = 30;\n    static inline std::vector<int> _primes{2, 3, 5, 7, 11, 13, 17,\
    \ 23, 29};\n\n  public:\n    PrimeTable() = delete;\n\n    // wheel sieve\n  \
    \  // reference: https://37zigen.com/wheel-sieve/\n    static void set_upper(int\
    \ m, int reserve_size = 26355867) {\n        if (m <= _n) return;\n        _n\
    \ = std::max(m, 2 * _n);\n        int sqrt_n = sqrt_floor(_n);\n        int w\
    \ = 1;\n        std::vector<bool> iscoprime(sqrt_n, true);\n        for (int i\
    \ = 0; i < 9; i++) {\n            if (w * _primes[i] > sqrt_n) break;\n      \
    \      w *= _primes[i];\n            for (int j = _primes[i]; j < sqrt_n; j +=\
    \ _primes[i]) iscoprime[j] = false;\n        }\n\n        std::vector<int> idx_(w,\
    \ -1);\n        int s = 0;\n        for (int i = 1; i < w; i++) {\n          \
    \  if (iscoprime[i]) idx_[i] = s++;\n        }\n        std::vector<int> coprimes(s);\n\
    \        for (int i = 1; i < w; i++) {\n            if (idx_[i] != -1) coprimes[idx_[i]]\
    \ = i;\n        }\n\n        auto idx = [&](long long x) -> long long {\n    \
    \        if (idx_[x % w] == -1) return -1;\n            return x / w * s + idx_[x\
    \ % w];\n        };\n\n        auto val = [&](int i) {\n            return i /\
    \ s * w + coprimes[i % s];\n        };\n\n        int n = (_n + w - 1) / w * s;\n\
    \        std::vector<int> _primes2;\n        _primes2.reserve(reserve_size);\n\
    \        std::vector<int> lpf(n, 0);\n        for (int i = 1; i < n; i++) {\n\
    \            int v = val(i);\n            if (lpf[i] == 0) {\n               \
    \ lpf[i] = v;\n                _primes2.push_back(lpf[i]);\n            }\n\n\
    \            for (const long long p : _primes2) {\n                long long j\
    \ = idx(p * v);\n                if (j >= n) break;\n                if (lpf[i]\
    \ < p) break;\n                lpf[j] = p;\n            }\n        }\n\n     \
    \   std::vector<int> tmp;\n        tmp.reserve(_primes.size() + _primes2.size());\n\
    \        std::set_union(_primes.begin(),\n                       _primes.end(),\n\
    \                       _primes2.begin(),\n                       _primes2.end(),\n\
    \                       std::back_inserter(tmp));\n        _primes = std::move(tmp);\n\
    \    }\n\n    static const std::vector<int> &primes() { return _primes; }\n\n\
    \    template <typename It>\n    struct PrimeIt {\n        It bg, ed;\n\n    \
    \    PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}\n\n        It begin() const\
    \ { return bg; }\n\n        It end() const { return ed; }\n\n        int size()\
    \ const { return ed - bg; }\n\n        int operator[](int i) const { return bg[i];\
    \ }\n\n        std::vector<int> to_vec() const { return std::vector<int>(bg, ed);\
    \ }\n    };\n\n    static auto primes(int n) {\n        if (n >= _n) set_upper(n);\n\
    \        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(),\
    \ n));\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/enumerate_quotients.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"math/enumerate_quotients.hpp\"\n\n#line\
    \ 8 \"math/enumerate_quotients.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T>\n\
    struct EnumerateQuotients {\n    T n;\n    int sqrt_n;\n    std::vector<T> res;\n\
    \n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n)) {\n        res.resize(sqrt_n\
    \ + n / (sqrt_n + 1));\n        std::iota(res.begin(), res.begin() + sqrt_n, 1);\n\
    \        for (T i = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j) res[j] = n / i;\n\
    \    }\n\n    const std::vector<T> &get() const { return res; }\n\n    int size()\
    \ const { return res.size(); }\n\n    const T &operator[](int i) const { return\
    \ res[i]; }\n\n    int idx(T x) const {\n        if (x <= sqrt_n) return x - 1;\n\
    \        return size() - n / x;\n    }\n};\n\n} // namespace kk2\n\n\n#line 9\
    \ \"math/multiplicative_function/prefix_sum.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class T>\nstruct PrefixSumOfMultiplicationFunction {\n    long long n;\n  \
    \  EnumerateQuotients<long long> eq;\n    std::vector<T> prefix_sum_only_prime;\n\
    \    std::vector<T> prefix_sum;\n\n    PrefixSumOfMultiplicationFunction(long\
    \ long n)\n        : n(n),\n          eq(n),\n          prefix_sum_only_prime(eq.size()),\n\
    \          prefix_sum(eq.size()) {}\n\n    int size() const { return eq.size();\
    \ }\n\n    template <T (*f)(long long)>\n    void LucyDP(std::vector<T> &dp, T\
    \ a) {\n        LucyDP([](long long x) { return f(x); }, dp);\n    }\n\n    //\
    \ f is completely multiplicative function\n    template <class F>\n    void LucyDP(const\
    \ F &f, std::vector<T> &dp) {\n        assert((int)dp.size() == eq.size());\n\
    \        PrimeTable::set_upper(eq.sqrt_n);\n        for (const long long p : PrimeTable::primes())\
    \ {\n            if (p > eq.sqrt_n) break;\n            T fp = f(p);\n       \
    \     for (int i = eq.size() - 1;; --i) {\n                if (eq[i] < p * p)\
    \ break;\n                dp[i] -= (dp[eq.idx(eq[i] / p)] - dp[p - 2]) * fp;\n\
    \            }\n        }\n    }\n\n    template <T (*f)(long long, long long)>\n\
    \    void Min_25Sieve() {\n        Min_25Sieve([](long long x, long long y) {\
    \ return f(x, y); });\n    }\n\n    // f is multiplicative function\n    template\
    \ <class F>\n    void Min_25Sieve(const F &f) {\n        PrimeTable::set_upper(eq.sqrt_n);\n\
    \        std::copy(prefix_sum_only_prime.begin(), prefix_sum_only_prime.end(),\
    \ prefix_sum.begin());\n        const auto &primes = PrimeTable::primes();\n \
    \       std::vector<T> tmp(eq.size());\n        for (int i = std::upper_bound(primes.begin(),\
    \ primes.end(), eq.sqrt_n) - primes.begin() - 1;\n             i >= 0;\n     \
    \        --i) {\n            const long long p = primes[i];\n            T pk\
    \ = f(p, 1);\n            T pk1;\n            for (long long p_pw = p, k = 1;\
    \ n / p >= p_pw; ++k, p_pw *= p) {\n                T pk1 = f(p, k + 1);\n   \
    \             for (int j = eq.size() - 1;; --j) {\n                    if (eq[j]\
    \ < p_pw * p) break;\n                    tmp[j] += pk * (prefix_sum[eq.idx(eq[j]\
    \ / p_pw)] - prefix_sum_only_prime[p - 1])\n                              + pk1;\n\
    \                }\n                pk = pk1;\n            }\n            for\
    \ (int j = eq.size() - 1;; --j) {\n                if (eq[j] < p * p) break;\n\
    \                prefix_sum[j] += tmp[j];\n                tmp[j] = T();\n   \
    \         }\n        }\n        for (int i = 0; i < eq.size(); ++i) ++prefix_sum[i];\n\
    \    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\n#include \"../prime_table.hpp\"\
    \n#include \"../enumerate_quotients.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ T>\nstruct PrefixSumOfMultiplicationFunction {\n    long long n;\n    EnumerateQuotients<long\
    \ long> eq;\n    std::vector<T> prefix_sum_only_prime;\n    std::vector<T> prefix_sum;\n\
    \n    PrefixSumOfMultiplicationFunction(long long n)\n        : n(n),\n      \
    \    eq(n),\n          prefix_sum_only_prime(eq.size()),\n          prefix_sum(eq.size())\
    \ {}\n\n    int size() const { return eq.size(); }\n\n    template <T (*f)(long\
    \ long)>\n    void LucyDP(std::vector<T> &dp, T a) {\n        LucyDP([](long long\
    \ x) { return f(x); }, dp);\n    }\n\n    // f is completely multiplicative function\n\
    \    template <class F>\n    void LucyDP(const F &f, std::vector<T> &dp) {\n \
    \       assert((int)dp.size() == eq.size());\n        PrimeTable::set_upper(eq.sqrt_n);\n\
    \        for (const long long p : PrimeTable::primes()) {\n            if (p >\
    \ eq.sqrt_n) break;\n            T fp = f(p);\n            for (int i = eq.size()\
    \ - 1;; --i) {\n                if (eq[i] < p * p) break;\n                dp[i]\
    \ -= (dp[eq.idx(eq[i] / p)] - dp[p - 2]) * fp;\n            }\n        }\n   \
    \ }\n\n    template <T (*f)(long long, long long)>\n    void Min_25Sieve() {\n\
    \        Min_25Sieve([](long long x, long long y) { return f(x, y); });\n    }\n\
    \n    // f is multiplicative function\n    template <class F>\n    void Min_25Sieve(const\
    \ F &f) {\n        PrimeTable::set_upper(eq.sqrt_n);\n        std::copy(prefix_sum_only_prime.begin(),\
    \ prefix_sum_only_prime.end(), prefix_sum.begin());\n        const auto &primes\
    \ = PrimeTable::primes();\n        std::vector<T> tmp(eq.size());\n        for\
    \ (int i = std::upper_bound(primes.begin(), primes.end(), eq.sqrt_n) - primes.begin()\
    \ - 1;\n             i >= 0;\n             --i) {\n            const long long\
    \ p = primes[i];\n            T pk = f(p, 1);\n            T pk1;\n          \
    \  for (long long p_pw = p, k = 1; n / p >= p_pw; ++k, p_pw *= p) {\n        \
    \        T pk1 = f(p, k + 1);\n                for (int j = eq.size() - 1;; --j)\
    \ {\n                    if (eq[j] < p_pw * p) break;\n                    tmp[j]\
    \ += pk * (prefix_sum[eq.idx(eq[j] / p_pw)] - prefix_sum_only_prime[p - 1])\n\
    \                              + pk1;\n                }\n                pk =\
    \ pk1;\n            }\n            for (int j = eq.size() - 1;; --j) {\n     \
    \           if (eq[j] < p * p) break;\n                prefix_sum[j] += tmp[j];\n\
    \                tmp[j] = T();\n            }\n        }\n        for (int i =\
    \ 0; i < eq.size(); ++i) ++prefix_sum[i];\n    }\n};\n\n} // namespace kk2\n\n\
    #endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_PREFIX_SUM_HPP\n"
  dependsOn:
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/enumerate_quotients.hpp
  isVerificationFile: false
  path: math/multiplicative_function/prefix_sum.hpp
  requiredBy: []
  timestamp: '2025-02-08 14:53:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
documentation_of: math/multiplicative_function/prefix_sum.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/prefix_sum.hpp
- /library/math/multiplicative_function/prefix_sum.hpp.html
title: math/multiplicative_function/prefix_sum.hpp
---
