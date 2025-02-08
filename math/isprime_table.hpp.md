---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/isprime_table_extend.test.cpp
    title: verify/unit_test/isprime_table_extend.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/isprime_table.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace kk2 {\n\nstruct IsPrimeTable {\n \
    \ private:\n    static inline std::vector<int> _primes{};\n    static inline std::vector<bool>\
    \ _isprime{};\n\n  public:\n    IsPrimeTable() = delete;\n\n    static void set_upper(int\
    \ m, int reserve_size = 26355867) {\n        if ((int)_isprime.size() == 0) _primes.reserve(reserve_size);\n\
    \        if ((int)_isprime.size() > m) return;\n        int start = std::max<int>(2,\
    \ _isprime.size());\n\n        _isprime.resize(m + 1, true);\n        _isprime[0]\
    \ = _isprime[1] = false;\n\n        for (const int p : _primes) {\n          \
    \  if (p * p > m) break;\n            for (int q = p * ((start + p - 1) / p);\
    \ q <= m; q += p) _isprime[q] = false;\n        }\n\n        for (int p = start;\
    \ p <= m; ++p) {\n            if (!_isprime[p]) continue;\n            _primes.push_back(p);\n\
    \            if (1ll * p * p > m) continue;\n            for (int q = p * p; q\
    \ <= m; q += p) _isprime[q] = false;\n        }\n    }\n\n    static const std::vector<int>\
    \ &primes() { return _primes; }\n\n    template <typename It>\n    struct PrimeIt\
    \ {\n        It bg, ed;\n\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_)\
    \ {}\n\n        It begin() const { return bg; }\n\n        It end() const { return\
    \ ed; }\n\n        int size() const { return ed - bg; }\n\n        int operator[](int\
    \ i) const { return bg[i]; }\n\n        std::vector<int> to_vec() const { return\
    \ std::vector<int>(bg, ed); }\n    };\n\n    static auto primes(int n) {\n   \
    \     if (n >= (int)_isprime.size()) set_upper(n);\n        return PrimeIt(_primes.begin(),\
    \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n\n    static bool\
    \ isprime(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n    \
    \    return _isprime[n];\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_ISPRIME_TABLE_HPP\n#define KK2_MATH_ISPRIME_TABLE_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace kk2\
    \ {\n\nstruct IsPrimeTable {\n  private:\n    static inline std::vector<int> _primes{};\n\
    \    static inline std::vector<bool> _isprime{};\n\n  public:\n    IsPrimeTable()\
    \ = delete;\n\n    static void set_upper(int m, int reserve_size = 26355867) {\n\
    \        if ((int)_isprime.size() == 0) _primes.reserve(reserve_size);\n     \
    \   if ((int)_isprime.size() > m) return;\n        int start = std::max<int>(2,\
    \ _isprime.size());\n\n        _isprime.resize(m + 1, true);\n        _isprime[0]\
    \ = _isprime[1] = false;\n\n        for (const int p : _primes) {\n          \
    \  if (p * p > m) break;\n            for (int q = p * ((start + p - 1) / p);\
    \ q <= m; q += p) _isprime[q] = false;\n        }\n\n        for (int p = start;\
    \ p <= m; ++p) {\n            if (!_isprime[p]) continue;\n            _primes.push_back(p);\n\
    \            if (1ll * p * p > m) continue;\n            for (int q = p * p; q\
    \ <= m; q += p) _isprime[q] = false;\n        }\n    }\n\n    static const std::vector<int>\
    \ &primes() { return _primes; }\n\n    template <typename It>\n    struct PrimeIt\
    \ {\n        It bg, ed;\n\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_)\
    \ {}\n\n        It begin() const { return bg; }\n\n        It end() const { return\
    \ ed; }\n\n        int size() const { return ed - bg; }\n\n        int operator[](int\
    \ i) const { return bg[i]; }\n\n        std::vector<int> to_vec() const { return\
    \ std::vector<int>(bg, ed); }\n    };\n\n    static auto primes(int n) {\n   \
    \     if (n >= (int)_isprime.size()) set_upper(n);\n        return PrimeIt(_primes.begin(),\
    \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n\n    static bool\
    \ isprime(int n) {\n        assert(n < (int)_isprime.size() && n != 0);\n    \
    \    return _isprime[n];\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_ISPRIME_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/isprime_table.hpp
  requiredBy: []
  timestamp: '2025-02-08 14:53:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/isprime_table_extend.test.cpp
documentation_of: math/isprime_table.hpp
layout: document
redirect_from:
- /library/math/isprime_table.hpp
- /library/math/isprime_table.hpp.html
title: math/isprime_table.hpp
---
