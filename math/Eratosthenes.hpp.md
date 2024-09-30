---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/divisor_multiple_transform.hpp
    title: convolution/divisor_multiple_transform.hpp
  - icon: ':warning:'
    path: convolution/gcd1.hpp
    title: convolution/gcd1.hpp
  - icon: ':warning:'
    path: convolution/lcm1.hpp
    title: convolution/lcm1.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Eratosthenes.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct Erato {\n    static\
    \ inline std::vector<bool> _isprime{};\n    static inline std::vector<int> _minfactor{},\
    \ _mobius{}, _primes{};\n\n    Erato() = delete;\n\n    constexpr static void\
    \ set_upper(int m) {\n        if ((int)_isprime.size() > m) return;\n        _isprime.assign(m\
    \ + 1, true);\n        _minfactor.assign(m + 1, -1);\n        _mobius.assign(m\
    \ + 1, 1);\n        _isprime[1] = false;\n        _minfactor[1] = 1;\n\n     \
    \   for (int p = 2; p <= m; ++p) {\n            if (!_isprime[p]) continue;\n\n\
    \            _minfactor[p] = p;\n            _mobius[p] = -1;\n            _primes.emplace_back(p);\n\
    \n            for (int q = p * 2; q <= m; q += p) {\n                _isprime[q]\
    \ = false;\n\n                if (_minfactor[q] == -1) _minfactor[q] = p;\n  \
    \              if ((q / p) % p == 0) _mobius[q] = 0;\n                else _mobius[q]\
    \ = -_mobius[q];\n            }\n        }\n    }\n\n    constexpr static bool\
    \ isprime(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n    \
    \    return _isprime[n];\n    }\n\n    constexpr static int mobius(int n) {\n\
    \        assert(n < (int)_mobius.size() && n != 0);\n        return _mobius[n];\n\
    \    }\n\n    constexpr static int minfactor(int n) {\n        assert(n < (int)_minfactor.size()\
    \ && n != 0);\n        return _minfactor[n];\n    }\n\n    constexpr static const\
    \ std::vector<int>& primes() { return _primes; }\n\n    constexpr static std::vector<std::pair<int,\
    \ int>> factorize(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n\
    \        if (n == 1 || n == -1) return {};\n        if (n < 0) n = -n;\n     \
    \   std::vector<std::pair<int, int>> res;\n        while (n > 1) {\n         \
    \   int p = _minfactor[n];\n            int exp = 0;\n\n            while (_minfactor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }\n\n\
    \    constexpr static std::vector<int> divisors(int n) {\n        assert(n < (int)_isprime.size()\
    \ && n != 0);\n        if (n == 1 || n == -1) return {1};\n        if (n < 0)\
    \ n = -n;\n        std::vector<int> res{1};\n        auto pf = factorize(n);\n\
    \n        for (auto p : pf) {\n            int s = (int)res.size();\n        \
    \    for (int i = 0; i < s; ++i) {\n                int v = 1;\n             \
    \   for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_ERATOSTHENES\n#define MATH_ERATOSTHENES 1\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct Erato {\n \
    \   static inline std::vector<bool> _isprime{};\n    static inline std::vector<int>\
    \ _minfactor{}, _mobius{}, _primes{};\n\n    Erato() = delete;\n\n    constexpr\
    \ static void set_upper(int m) {\n        if ((int)_isprime.size() > m) return;\n\
    \        _isprime.assign(m + 1, true);\n        _minfactor.assign(m + 1, -1);\n\
    \        _mobius.assign(m + 1, 1);\n        _isprime[1] = false;\n        _minfactor[1]\
    \ = 1;\n\n        for (int p = 2; p <= m; ++p) {\n            if (!_isprime[p])\
    \ continue;\n\n            _minfactor[p] = p;\n            _mobius[p] = -1;\n\
    \            _primes.emplace_back(p);\n\n            for (int q = p * 2; q <=\
    \ m; q += p) {\n                _isprime[q] = false;\n\n                if (_minfactor[q]\
    \ == -1) _minfactor[q] = p;\n                if ((q / p) % p == 0) _mobius[q]\
    \ = 0;\n                else _mobius[q] = -_mobius[q];\n            }\n      \
    \  }\n    }\n\n    constexpr static bool isprime(int n) {\n        assert(n <\
    \ (int)_isprime.size() && n != 0);\n        return _isprime[n];\n    }\n\n   \
    \ constexpr static int mobius(int n) {\n        assert(n < (int)_mobius.size()\
    \ && n != 0);\n        return _mobius[n];\n    }\n\n    constexpr static int minfactor(int\
    \ n) {\n        assert(n < (int)_minfactor.size() && n != 0);\n        return\
    \ _minfactor[n];\n    }\n\n    constexpr static const std::vector<int>& primes()\
    \ { return _primes; }\n\n    constexpr static std::vector<std::pair<int, int>>\
    \ factorize(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n  \
    \      if (n == 1 || n == -1) return {};\n        if (n < 0) n = -n;\n       \
    \ std::vector<std::pair<int, int>> res;\n        while (n > 1) {\n           \
    \ int p = _minfactor[n];\n            int exp = 0;\n\n            while (_minfactor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }\n\n\
    \    constexpr static std::vector<int> divisors(int n) {\n        assert(n < (int)_isprime.size()\
    \ && n != 0);\n        if (n == 1 || n == -1) return {1};\n        if (n < 0)\
    \ n = -n;\n        std::vector<int> res{1};\n        auto pf = factorize(n);\n\
    \n        for (auto p : pf) {\n            int s = (int)res.size();\n        \
    \    for (int i = 0; i < s; ++i) {\n                int v = 1;\n             \
    \   for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n#endif\
    \ // MATH_ERATOSTHENES\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Eratosthenes.hpp
  requiredBy:
  - convolution/lcm1.hpp
  - convolution/gcd1.hpp
  - convolution/divisor_multiple_transform.hpp
  timestamp: '2024-10-01 01:36:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Eratosthenes.hpp
layout: document
redirect_from:
- /library/math/Eratosthenes.hpp
- /library/math/Eratosthenes.hpp.html
title: math/Eratosthenes.hpp
---
