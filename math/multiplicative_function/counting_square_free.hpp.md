---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':heavy_check_mark:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':heavy_check_mark:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/famous_function_table.hpp
    title: math/multiplicative_function/famous_function_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  - icon: ':heavy_check_mark:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/counting_square_free.hpp\"\n\
    \n\n\n#include <cmath>\n\n#line 1 \"math/enumerate_quotients.hpp\"\n\n\n\n#include\
    \ <numeric>\n#include <vector>\n\n#line 1 \"math/sqrt_floor.hpp\"\n\n\n\n#line\
    \ 5 \"math/sqrt_floor.hpp\"\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in\
    \ Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return\
    \ floor(a / b)\ntemplate <typename T, typename U> constexpr T fracfloor(T a, U\
    \ b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0)\
    \ return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //          =\
    \ -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return ceil(a /\
    \ b)\ntemplate <typename T, typename U> constexpr T fracceil(T a, U b) {\n   \
    \ assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a\
    \ / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return -((-a) / b);\n\
    }\n\n} // namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <typename T> T sqrt_floor(T n) {\n    assert(n >= 0);\n    if\
    \ (n == T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n  \
    \  while (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <= kk2::fracfloor(n,\
    \ x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename T> T sqrt_ceil(T n) {\n\
    \    assert(n >= 0);\n    if (n <= T(1)) return n;\n    T x = std::sqrt(n);\n\
    \    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n, x)) ++x;\n    while\
    \ (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class T> struct EnumerateQuotients {\n    T n;\n    int sqrt_n;\n    std::vector<T>\
    \ res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n)) {\n      \
    \  res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(), res.begin()\
    \ + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j)\
    \ res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const { return res;\
    \ }\n\n    int size() const { return res.size(); }\n\n    const T &operator[](int\
    \ i) const { return res[i]; }\n\n    int idx(T x) const {\n        if (x <= sqrt_n)\
    \ return x - 1;\n        return size() - n / x;\n    }\n};\n\n} // namespace kk2\n\
    \n\n#line 1 \"math/multiplicative_function/famous_function_table.hpp\"\n\n\n\n\
    #include <algorithm>\n#line 7 \"math/multiplicative_function/famous_function_table.hpp\"\
    \n\n#line 1 \"math/lpf_table.hpp\"\n\n\n\n#line 8 \"math/lpf_table.hpp\"\n\nnamespace\
    \ kk2 {\n\nstruct LPFTable {\n  private:\n    static inline std::vector<int> _primes{2},\
    \ _lpf{};\n\n  public:\n    LPFTable() = delete;\n\n    static void set_upper(int\
    \ m, int reserve_size = 26355867) {\n        if ((int)_lpf.size() == 0) _primes.reserve(reserve_size);\n\
    \        if ((int)_lpf.size() > m) return;\n        m = std::max<int>(2 * _lpf.size(),\
    \ m);\n        _lpf.resize(m + 1);\n        iota(_lpf.begin(), _lpf.end(), 0);\n\
    \        for (int i = 2; i <= m; i++) {\n            if (_lpf[i] == i and _primes.back()\
    \ < i) _primes.emplace_back(i);\n            for (const long long p : _primes)\
    \ {\n                if (p * i > m) break;\n                if (_lpf[i] < p) break;\n\
    \                _lpf[p * i] = p;\n            }\n        }\n    }\n\n    static\
    \ const std::vector<int> &primes() { return _primes; }\n\n    template <typename\
    \ It> struct PrimeIt {\n        It bg, ed;\n\n        PrimeIt(It bg_, It ed_)\
    \ : bg(bg_), ed(ed_) {}\n\n        It begin() const { return bg; }\n\n       \
    \ It end() const { return ed; }\n\n        int size() const { return ed - bg;\
    \ }\n\n        int operator[](int i) const { return bg[i]; }\n\n        std::vector<int>\
    \ to_vec() const { return std::vector<int>(bg, ed); }\n    };\n\n    static auto\
    \ primes(int n) {\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return\
    \ PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(), _primes.end(), n));\n\
    \    }\n\n    static int lpf(int n) {\n        assert(n > 1);\n        if (n >=\
    \ (int)_lpf.size()) set_upper(n);\n        return _lpf[n];\n    }\n\n    static\
    \ bool isprime(int n) {\n        assert(n > 0);\n        if (n >= (int)_lpf.size())\
    \ set_upper(n);\n        return n != 1 and _lpf[n] == n;\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n\n#line 1 \"math/pow.hpp\"\n\n\n\n#line 5 \"math/pow.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow(T x, U n) {\n\
    \    assert(n >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1)\
    \ r *= y;\n        if (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 10 \"math/multiplicative_function/famous_function_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct FamousFunctionTable {\n  private:\n    static inline\
    \ std::vector<int> _v_lpf{0, 0}, _mobius{0, 1}, _sigma0{0, 1}, _euler_phi{0, 1};\n\
    \    static inline std::vector<long long> _sigma1{0, 1};\n\n  public:\n    FamousFunctionTable()\
    \ = delete;\n\n    static void set_upper(int m) {\n        if ((int)_mobius.size()\
    \ > m) return;\n        int start = _mobius.size();\n\n        LPFTable::set_upper(m);\n\
    \n        _v_lpf.resize(m + 1, 0);\n        _mobius.resize(m + 1, 1);\n      \
    \  _sigma0.resize(m + 1, 1);\n        _sigma1.resize(m + 1, 1);\n        _euler_phi.resize(m\
    \ + 1, 1);\n\n        for (int n = start; n <= m; ++n) {\n            int p =\
    \ LPFTable::lpf(n);\n            if (p == n) {\n                _v_lpf[n] = 1;\n\
    \                _mobius[n] = -1;\n                _sigma0[n] = 2;\n         \
    \       _sigma1[n] = p + 1;\n                _euler_phi[n] = p - 1;\n        \
    \    } else {\n                if (n / p % p == 0) _v_lpf[n] = _v_lpf[n / p] +\
    \ 1;\n                else _v_lpf[n] = 1;\n\n                int p_pw = pow<int>(p,\
    \ _v_lpf[n]);\n                int q = n / p_pw;\n                if (q == 1)\
    \ {\n                    _mobius[n] = 0;\n                    _sigma0[n] = _v_lpf[n]\
    \ + 1;\n                    _sigma1[n] = _sigma1[n / p] + p_pw;\n            \
    \        _euler_phi[n] = p_pw - p_pw / p;\n                } else {\n        \
    \            _mobius[n] = _mobius[q] * _mobius[p_pw];\n                    _sigma0[n]\
    \ = _sigma0[q] * _sigma0[p_pw];\n                    _sigma1[n] = _sigma1[q] *\
    \ _sigma1[p_pw];\n                    _euler_phi[n] = _euler_phi[q] * _euler_phi[p_pw];\n\
    \                }\n            }\n        }\n    }\n\n    static int mobius(int\
    \ n) {\n        assert(n >= 0);\n        if ((int)_mobius.size() <= n) set_upper(n);\n\
    \        return _mobius[n];\n    }\n\n    static int sigma0(int n) {\n       \
    \ assert(n > 0);\n        if ((int)_sigma0.size() <= n) set_upper(n);\n      \
    \  return _sigma0[n];\n    }\n\n    static long long sigma1(int n) {\n       \
    \ assert(n > 0);\n        if ((int)_sigma1.size() <= n) set_upper(n);\n      \
    \  return _sigma1[n];\n    }\n\n    static int euler_phi(int n) {\n        assert(n\
    \ > 0);\n        if ((int)_euler_phi.size() <= n) set_upper(n);\n        return\
    \ _euler_phi[n];\n    }\n};\n\n} // namespace kk2\n\n\n#line 8 \"math/multiplicative_function/counting_square_free.hpp\"\
    \n\nnamespace kk2 {\n\nlong long counting_square_free(long long n) {\n    long\
    \ long I = std::pow(n, 0.2);\n    long long D = kk2::sqrt_floor(n / I);\n}\n\n\
    } // namespace kk2\n\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP\n#define\
    \ KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP 1\n\n#include <cmath>\n\
    \n#include \"../enumerate_quotients.hpp\"\n#include \"famous_function_table.hpp\"\
    \n\nnamespace kk2 {\n\nlong long counting_square_free(long long n) {\n    long\
    \ long I = std::pow(n, 0.2);\n    long long D = kk2::sqrt_floor(n / I);\n}\n\n\
    } // namespace kk2\n\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_COUNTING_SQUARE_FREE_HPP\n"
  dependsOn:
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/multiplicative_function/famous_function_table.hpp
  - math/lpf_table.hpp
  - math/pow.hpp
  isVerificationFile: false
  path: math/multiplicative_function/counting_square_free.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multiplicative_function/counting_square_free.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/counting_square_free.hpp
- /library/math/multiplicative_function/counting_square_free.hpp.html
title: math/multiplicative_function/counting_square_free.hpp
---
