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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_convolution/convolution_gcd.test.cpp
    title: verify/yosupo_convolution/convolution_gcd.test.cpp
  - icon: ':x:'
    path: verify/yosupo_convolution/convolution_lcm.test.cpp
    title: verify/yosupo_convolution/convolution_lcm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/Eratosthenes.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\nstruct\
    \ Erato {\n    static inline std::vector<bool> _isprime{};\n    static inline\
    \ std::vector<int> _minfactor{}, _mobius{}, _primes{};\n\n    Erato() = delete;\n\
    \n    static void set_upper(int m) {\n        if ((int)_isprime.size() > m) return;\n\
    \        int start = std::max<int>(2, _isprime.size());\n\n        _isprime.resize(m\
    \ + 1, true);\n        _minfactor.resize(m + 1, -1);\n        _mobius.resize(m\
    \ + 1, 1);\n        _isprime[1] = false;\n        _minfactor[1] = 1;\n\n     \
    \   for (const int &p : _primes) {\n            for (int q = p * ((start + p -\
    \ 1) / p); q <= m; q += p) {\n                _isprime[q] = false;\n\n       \
    \         if (_minfactor[q] == -1) _minfactor[q] = p;\n                if ((q\
    \ / p) % p == 0) _mobius[q] = 0;\n                else _mobius[q] = -_mobius[q];\n\
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
    \  }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_ERATOSTHENES_HPP\n#define KK2_MATH_ERATOSTHENES_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace kk2 {\n\nstruct Erato {\n    static inline std::vector<bool> _isprime{};\n\
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
    \  }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_ERATOSTHENES_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/Eratosthenes.hpp
  requiredBy:
  - convolution/convolution_gcd.hpp
  - convolution/divisor_multiple_transform.hpp
  - convolution/convolution_lcm.hpp
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
documentation_of: math/Eratosthenes.hpp
layout: document
redirect_from:
- /library/math/Eratosthenes.hpp
- /library/math/Eratosthenes.hpp.html
title: math/Eratosthenes.hpp
---
