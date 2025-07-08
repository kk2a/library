---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime_factorize_table.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 1 \"math/lpf_table.hpp\"\n\n\n\n\
    #line 6 \"math/lpf_table.hpp\"\n#include <numeric>\n#line 8 \"math/lpf_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct LPFTable {\n  private:\n    static inline std::vector<int>\
    \ _primes{2}, _lpf{};\n\n  public:\n    LPFTable() = delete;\n\n    static void\
    \ set_upper(int m, int reserve_size = 26355867) {\n        if ((int)_lpf.size()\
    \ == 0) _primes.reserve(reserve_size);\n        if ((int)_lpf.size() > m) return;\n\
    \        m = std::max<int>(2 * _lpf.size(), m);\n        _lpf.resize(m + 1);\n\
    \        iota(_lpf.begin(), _lpf.end(), 0);\n        for (int i = 2; i <= m; i++)\
    \ {\n            if (_lpf[i] == i and _primes.back() < i) _primes.emplace_back(i);\n\
    \            for (const long long p : _primes) {\n                if (p * i >\
    \ m) break;\n                if (_lpf[i] < p) break;\n                _lpf[p *\
    \ i] = p;\n            }\n        }\n    }\n\n    static const std::vector<int>\
    \ &primes() { return _primes; }\n\n    template <typename It> struct PrimeIt {\n\
    \        It bg, ed;\n\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}\n\
    \n        It begin() const { return bg; }\n\n        It end() const { return ed;\
    \ }\n\n        int size() const { return ed - bg; }\n\n        int operator[](int\
    \ i) const { return bg[i]; }\n\n        std::vector<int> to_vec() const { return\
    \ std::vector<int>(bg, ed); }\n    };\n\n    static auto primes(int n) {\n   \
    \     if (n >= (int)_lpf.size()) set_upper(n);\n        return PrimeIt(_primes.begin(),\
    \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n\n    static int\
    \ lpf(int n) {\n        assert(n > 1);\n        if (n >= (int)_lpf.size()) set_upper(n);\n\
    \        return _lpf[n];\n    }\n\n    static bool isprime(int n) {\n        assert(n\
    \ > 0);\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return n !=\
    \ 1 and _lpf[n] == n;\n    }\n};\n\n} // namespace kk2\n\n\n\n#line 9 \"math/prime_factorize_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct FactorizeTable {\n  private:\n    static inline\
    \ std::vector<std::vector<std::pair<int, int>>> _factorize{{}};\n\n  public:\n\
    \    FactorizeTable() = delete;\n\n    static void set_upper(int m) {\n      \
    \  if ((int)_factorize.size() > m) return;\n        int start = std::max<int>(2,\
    \ _factorize.size());\n\n        LPFTable::set_upper(m);\n\n        _factorize.resize(m\
    \ + 1);\n        for (int n = start; n <= m; ++n) {\n            int p = LPFTable::lpf(n);\n\
    \            if (p == n) {\n                _factorize[n] = {\n              \
    \      {p, 1}\n                };\n            } else if (n / p % p == 0) {\n\
    \                _factorize[n] = _factorize[n / p];\n                _factorize[n][0].second++;\n\
    \            } else {\n                _factorize[n] = _factorize[n / p];\n  \
    \              _factorize[n].insert(_factorize[n].begin(), {p, 1});\n        \
    \    }\n        }\n    }\n\n    static const std::vector<std::pair<int, int>>\
    \ &factorize(int n) {\n        assert(n > 0);\n        if ((int)_factorize.size()\
    \ <= n) set_upper(n);\n        return _factorize[n];\n    }\n\n    static std::vector<int>\
    \ divisors(int n) {\n        assert(n > 0);\n        if ((int)_factorize.size()\
    \ <= n) set_upper(n);\n        std::vector<int> res = {1};\n        for (auto\
    \ [p, k] : _factorize[n]) {\n            int sz = res.size();\n            for\
    \ (int i = 0; i < sz; ++i) {\n                int mul = 1;\n                for\
    \ (int j = 0; j < k; ++j) {\n                    mul *= p;\n                 \
    \   res.push_back(res[i] * mul);\n                }\n            }\n        }\n\
    \        std::sort(res.begin(), res.end());\n        return res;\n    }\n};\n\n\
    } // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_PRIME_FACTORIZE_TABLE_HPP\n#define KK2_MATH_PRIME_FACTORIZE_TABLE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#include\
    \ \"lpf_table.hpp\"\n\nnamespace kk2 {\n\nstruct FactorizeTable {\n  private:\n\
    \    static inline std::vector<std::vector<std::pair<int, int>>> _factorize{{}};\n\
    \n  public:\n    FactorizeTable() = delete;\n\n    static void set_upper(int m)\
    \ {\n        if ((int)_factorize.size() > m) return;\n        int start = std::max<int>(2,\
    \ _factorize.size());\n\n        LPFTable::set_upper(m);\n\n        _factorize.resize(m\
    \ + 1);\n        for (int n = start; n <= m; ++n) {\n            int p = LPFTable::lpf(n);\n\
    \            if (p == n) {\n                _factorize[n] = {\n              \
    \      {p, 1}\n                };\n            } else if (n / p % p == 0) {\n\
    \                _factorize[n] = _factorize[n / p];\n                _factorize[n][0].second++;\n\
    \            } else {\n                _factorize[n] = _factorize[n / p];\n  \
    \              _factorize[n].insert(_factorize[n].begin(), {p, 1});\n        \
    \    }\n        }\n    }\n\n    static const std::vector<std::pair<int, int>>\
    \ &factorize(int n) {\n        assert(n > 0);\n        if ((int)_factorize.size()\
    \ <= n) set_upper(n);\n        return _factorize[n];\n    }\n\n    static std::vector<int>\
    \ divisors(int n) {\n        assert(n > 0);\n        if ((int)_factorize.size()\
    \ <= n) set_upper(n);\n        std::vector<int> res = {1};\n        for (auto\
    \ [p, k] : _factorize[n]) {\n            int sz = res.size();\n            for\
    \ (int i = 0; i < sz; ++i) {\n                int mul = 1;\n                for\
    \ (int j = 0; j < k; ++j) {\n                    mul *= p;\n                 \
    \   res.push_back(res[i] * mul);\n                }\n            }\n        }\n\
    \        std::sort(res.begin(), res.end());\n        return res;\n    }\n};\n\n\
    } // namespace kk2\n\n#endif // KK2_MATH_PRIME_FACTORIZE_TABLE_HPP\n"
  dependsOn:
  - math/lpf_table.hpp
  isVerificationFile: false
  path: math/prime_factorize_table.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_factorize_table.hpp
layout: document
redirect_from:
- /library/math/prime_factorize_table.hpp
- /library/math/prime_factorize_table.hpp.html
title: math/prime_factorize_table.hpp
---
