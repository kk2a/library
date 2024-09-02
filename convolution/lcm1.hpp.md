---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/Eratosthenes.hpp
    title: math/Eratosthenes.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/lcm1.hpp\"\n\n\n\n#line 1 \"math/Eratosthenes.hpp\"\
    \n\n\n\nnamespace kk2 {\n\nstruct Erato {\n    static inline vector<bool> _isprime{};\n\
    \    static inline vector<int> _minfactor{}, _mobius{}, _primes{};\n\n    Erato()\
    \ = delete;\n\n    constexpr static void set_upper(int m) {\n        _isprime.resize(m\
    \ + 1, true);\n        _minfactor.resize(m + 1, -1);\n        _mobius.resize(m\
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
    \ && n != 0);\n        return _minfactor[n];\n    }\n\n    constexpr static vector<int>\
    \ primes() {\n        return _primes;\n    }\n\n    constexpr static vector<pair<int,\
    \ int>> factorize(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n\
    \        if (n == 1 || n == -1) return {};\n        if (n < 0) n = -n;\n     \
    \   vector<pair<int, int>> res;\n        while (n > 1) {\n            int p =\
    \ _minfactor[n];\n            int exp = 0;\n\n            while (_minfactor[n]\
    \ == p) {\n                n /= p;\n                ++exp;\n            }\n  \
    \          res.emplace_back(p, exp);\n        }\n        return res;\n    }\n\n\
    \    constexpr static vector<int> divisors(int n) {\n        assert(n < (int)_isprime.size()\
    \ && n != 0);\n        if (n == 1 || n == -1) return {1};\n        if (n < 0)\
    \ n = -n;\n        vector<int> res{1};\n        auto pf = factorize(n);\n\n  \
    \      for (auto p : pf) {\n            int s = (int)res.size();\n           \
    \ for (int i = 0; i < s; ++i) {\n                int v = 1;\n                for\
    \ (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n      \
    \              res.push_back(res[i] * v);\n                }\n            }\n\
    \        }\n        return res;\n    }\n};\n\n} // namespace kk2\n\n\n#line 5\
    \ \"convolution/lcm1.hpp\"\n\nnamespace kk2 {\n\n// 1-indexed\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type> \nFPS convolution_lcm(FPS& a, const\
    \ FPS& b) {\n    assert(size(a) == size(b));\n    int n = int(size(a)); // = int(size(b))\n\
    \    if (!n) return {};\n    n--;\n    FPS c(b);\n    Erato::set_upper(n);\n\n\
    \    auto fdt = [&](FPS& a) -> void {\n        for (const auto p : Erato::primes())\
    \ {\n            if (p > n) break;\n            for (int i = 1; i <= n / p; i++)\
    \ a[i * p] += a[i];\n        }\n    };\n    auto ifdt = [&](FPS& a) -> void {\n\
    \        for (const auto p : Erato::primes()) {\n            if (p  > n) break;\n\
    \            for (auto i = n / p; i > 0; i--) a[i * p] -= a[i];\n        }\n \
    \   };\n\n    fdt(a);\n    fdt(c);\n    for (int i = 1; i <= n; i++) a[i] *= c[i];\n\
    \    ifdt(a);\n\n    return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_LCM\n#define CONVOLUTION_LCM 1\n\n#include \"../math/Eratosthenes.hpp\"\
    \n\nnamespace kk2 {\n\n// 1-indexed\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type> \nFPS convolution_lcm(FPS& a, const FPS& b) {\n    assert(size(a)\
    \ == size(b));\n    int n = int(size(a)); // = int(size(b))\n    if (!n) return\
    \ {};\n    n--;\n    FPS c(b);\n    Erato::set_upper(n);\n\n    auto fdt = [&](FPS&\
    \ a) -> void {\n        for (const auto p : Erato::primes()) {\n            if\
    \ (p > n) break;\n            for (int i = 1; i <= n / p; i++) a[i * p] += a[i];\n\
    \        }\n    };\n    auto ifdt = [&](FPS& a) -> void {\n        for (const\
    \ auto p : Erato::primes()) {\n            if (p  > n) break;\n            for\
    \ (auto i = n / p; i > 0; i--) a[i * p] -= a[i];\n        }\n    };\n\n    fdt(a);\n\
    \    fdt(c);\n    for (int i = 1; i <= n; i++) a[i] *= c[i];\n    ifdt(a);\n\n\
    \    return a;\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_LCM\n"
  dependsOn:
  - math/Eratosthenes.hpp
  isVerificationFile: false
  path: convolution/lcm1.hpp
  requiredBy: []
  timestamp: '2024-09-03 00:30:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/lcm1.hpp
layout: document
redirect_from:
- /library/convolution/lcm1.hpp
- /library/convolution/lcm1.hpp.html
title: convolution/lcm1.hpp
---
