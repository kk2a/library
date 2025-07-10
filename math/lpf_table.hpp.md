---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/arbitrary_table.hpp
    title: math/multiplicative_function/arbitrary_table.hpp
  - icon: ':warning:'
    path: math/multiplicative_function/counting_square_free.hpp
    title: math/multiplicative_function/counting_square_free.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/famous_function_table.hpp
    title: math/multiplicative_function/famous_function_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize_table.hpp
    title: math/prime_factorize_table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/lpf_table_extend.test.cpp
    title: verify/unit_test/math/lpf_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    title: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    title: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/prime_factorize_table.test.cpp
    title: verify/unit_test/math/prime_factorize_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/lpf_table.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <numeric>\n#include <vector>\n\nnamespace kk2 {\n\nstruct\
    \ LPFTable {\n  private:\n    static inline std::vector<int> _primes{2}, _lpf{0,\
    \ 1, 2}, _lpf_pow{0, 1, 2}, _v_lpf{0, 1, 1};\n\n  public:\n    LPFTable() = delete;\n\
    \n    static void set_upper(int m, int reserve_size = 26355867) {\n        if\
    \ ((int)_lpf.size() == 0) _primes.reserve(reserve_size);\n        if ((int)_lpf.size()\
    \ > m) return;\n        m = std::max<int>(2 * _lpf.size(), m);\n        _lpf_pow.resize(m\
    \ + 1);\n        _v_lpf.resize(m + 1);\n        _lpf.resize(m + 1);\n        iota(_lpf.begin(),\
    \ _lpf.end(), 0);\n        for (int i = 2; i <= m; i++) {\n            if (_lpf[i]\
    \ == i and i > (int)_primes.back())\n                _primes.emplace_back(i),\
    \ _lpf_pow[i] = i, _v_lpf[i] = 1;\n            for (const long long p : _primes)\
    \ {\n                if (p * i > m) break;\n                if (_lpf[i] < p) break;\n\
    \                _lpf[p * i] = p;\n                if (_lpf[i] == p) {\n     \
    \               _v_lpf[p * i] = _v_lpf[i] + 1;\n                    _lpf_pow[p\
    \ * i] = _lpf_pow[i] * p;\n                } else {\n                    _v_lpf[p\
    \ * i] = 1;\n                    _lpf_pow[p * i] = p;\n                }\n   \
    \         }\n        }\n    }\n\n    static const std::vector<int> &primes() {\
    \ return _primes; }\n\n    template <typename It> struct PrimeIt {\n        It\
    \ bg, ed;\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}\n        It begin()\
    \ const { return bg; }\n        It end() const { return ed; }\n        int size()\
    \ const { return ed - bg; }\n        int operator[](int i) const { return bg[i];\
    \ }\n        std::vector<int> to_vec() const { return std::vector<int>(bg, ed);\
    \ }\n    };\n\n    static auto primes(int n) {\n        if (n >= (int)_lpf.size())\
    \ set_upper(n);\n        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(),\
    \ _primes.end(), n));\n    }\n\n    static int lpf(int n) {\n        assert(n\
    \ > 1);\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return _lpf[n];\n\
    \    }\n\n    static bool isprime(int n) {\n        assert(n > 0);\n        if\
    \ (n >= (int)_lpf.size()) set_upper(n);\n        return n != 1 and _lpf[n] ==\
    \ n;\n    }\n\n    static int lpf_pow(int n) {\n        assert(n > 1);\n     \
    \   if (n >= (int)_lpf_pow.size()) set_upper(n);\n        return _lpf_pow[n];\n\
    \    }\n\n    static int v_lpf(int n) {\n        assert(n > 1);\n        if (n\
    \ >= (int)_v_lpf.size()) set_upper(n);\n        return _v_lpf[n];\n    }\n};\n\
    \n} // namespace kk2\n\n\n\n"
  code: "#ifndef KK2_MATH_LPF_TABLE_HPP\n#define KK2_MATH_LPF_TABLE_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <numeric>\n#include <vector>\n\nnamespace\
    \ kk2 {\n\nstruct LPFTable {\n  private:\n    static inline std::vector<int> _primes{2},\
    \ _lpf{0, 1, 2}, _lpf_pow{0, 1, 2}, _v_lpf{0, 1, 1};\n\n  public:\n    LPFTable()\
    \ = delete;\n\n    static void set_upper(int m, int reserve_size = 26355867) {\n\
    \        if ((int)_lpf.size() == 0) _primes.reserve(reserve_size);\n        if\
    \ ((int)_lpf.size() > m) return;\n        m = std::max<int>(2 * _lpf.size(), m);\n\
    \        _lpf_pow.resize(m + 1);\n        _v_lpf.resize(m + 1);\n        _lpf.resize(m\
    \ + 1);\n        iota(_lpf.begin(), _lpf.end(), 0);\n        for (int i = 2; i\
    \ <= m; i++) {\n            if (_lpf[i] == i and i > (int)_primes.back())\n  \
    \              _primes.emplace_back(i), _lpf_pow[i] = i, _v_lpf[i] = 1;\n    \
    \        for (const long long p : _primes) {\n                if (p * i > m) break;\n\
    \                if (_lpf[i] < p) break;\n                _lpf[p * i] = p;\n \
    \               if (_lpf[i] == p) {\n                    _v_lpf[p * i] = _v_lpf[i]\
    \ + 1;\n                    _lpf_pow[p * i] = _lpf_pow[i] * p;\n             \
    \   } else {\n                    _v_lpf[p * i] = 1;\n                    _lpf_pow[p\
    \ * i] = p;\n                }\n            }\n        }\n    }\n\n    static\
    \ const std::vector<int> &primes() { return _primes; }\n\n    template <typename\
    \ It> struct PrimeIt {\n        It bg, ed;\n        PrimeIt(It bg_, It ed_) :\
    \ bg(bg_), ed(ed_) {}\n        It begin() const { return bg; }\n        It end()\
    \ const { return ed; }\n        int size() const { return ed - bg; }\n       \
    \ int operator[](int i) const { return bg[i]; }\n        std::vector<int> to_vec()\
    \ const { return std::vector<int>(bg, ed); }\n    };\n\n    static auto primes(int\
    \ n) {\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return PrimeIt(_primes.begin(),\
    \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n\n    static int\
    \ lpf(int n) {\n        assert(n > 1);\n        if (n >= (int)_lpf.size()) set_upper(n);\n\
    \        return _lpf[n];\n    }\n\n    static bool isprime(int n) {\n        assert(n\
    \ > 0);\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return n !=\
    \ 1 and _lpf[n] == n;\n    }\n\n    static int lpf_pow(int n) {\n        assert(n\
    \ > 1);\n        if (n >= (int)_lpf_pow.size()) set_upper(n);\n        return\
    \ _lpf_pow[n];\n    }\n\n    static int v_lpf(int n) {\n        assert(n > 1);\n\
    \        if (n >= (int)_v_lpf.size()) set_upper(n);\n        return _v_lpf[n];\n\
    \    }\n};\n\n} // namespace kk2\n\n\n#endif // KK2_MATH_LPF_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/lpf_table.hpp
  requiredBy:
  - math/prime_factorize_table.hpp
  - math/multiplicative_function/famous_function_table.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/arbitrary_table.hpp
  timestamp: '2025-07-10 13:49:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/prime_factorize_table.test.cpp
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
documentation_of: math/lpf_table.hpp
layout: document
redirect_from:
- /library/math/lpf_table.hpp
- /library/math/lpf_table.hpp.html
title: math/lpf_table.hpp
---
