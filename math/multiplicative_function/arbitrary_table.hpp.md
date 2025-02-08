---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':x:'
    path: math/pow.hpp
    title: math/pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/unit_test/multiplicative_function_table.test.cpp
    title: verify/unit_test/multiplicative_function_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/arbitrary_table.hpp\"\n\n\n\
    \n#include <cassert>\n#include <vector>\n\n#line 1 \"math/lpf_table.hpp\"\n\n\n\
    \n#include <algorithm>\n#line 6 \"math/lpf_table.hpp\"\n#include <numeric>\n#line\
    \ 8 \"math/lpf_table.hpp\"\n\nnamespace kk2 {\n\nstruct LPFTable {\n  private:\n\
    \    static inline std::vector<int> _primes{2}, _lpf{};\n\n  public:\n    LPFTable()\
    \ = delete;\n\n    static void set_upper(int m, int reserve_size = 26355867) {\n\
    \        if ((int)_lpf.size() == 0) _primes.reserve(reserve_size);\n        if\
    \ ((int)_lpf.size() > m) return;\n        m = std::max<int>(2 * _lpf.size(), m);\n\
    \        _lpf.resize(m + 1);\n        iota(_lpf.begin(), _lpf.end(), 0);\n   \
    \     for (int i = 2; i <= m; i++) {\n            if (_lpf[i] == i and _primes.back()\
    \ < i) _primes.emplace_back(i);\n            for (const long long p : _primes)\
    \ {\n                if (p * i > m) break;\n                if (_lpf[i] < p) break;\n\
    \                _lpf[p * i] = p;\n            }\n        }\n    }\n\n    static\
    \ const std::vector<int> &primes() { return _primes; }\n\n    template <typename\
    \ It>\n    struct PrimeIt {\n        It bg, ed;\n\n        PrimeIt(It bg_, It\
    \ ed_) : bg(bg_), ed(ed_) {}\n\n        It begin() const { return bg; }\n\n  \
    \      It end() const { return ed; }\n\n        int size() const { return ed -\
    \ bg; }\n\n        int operator[](int i) const { return bg[i]; }\n\n        std::vector<int>\
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
    \ kk2\n\n\n#line 9 \"math/multiplicative_function/arbitrary_table.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, T (*f)(long long, long long)>\nstruct MultiplicativeFunctionTable\
    \ {\n  private:\n    static inline std::vector<int> _v_lpf{0, 0};\n    static\
    \ inline std::vector<T> _table{0, 1};\n\n  public:\n    MultiplicativeFunctionTable()\
    \ = delete;\n\n    static void set_upper(int m) {\n        if ((int)_table.size()\
    \ > m) return;\n        int start = _table.size();\n\n        LPFTable::set_upper(m);\n\
    \n        _v_lpf.resize(m + 1, 0);\n        _table.resize(m + 1);\n\n        for\
    \ (int n = start; n <= m; ++n) {\n            int p = LPFTable::lpf(n);\n    \
    \        if (p == n) {\n                _v_lpf[n] = 1;\n                _table[n]\
    \ = f(p, 1);\n            } else {\n                if (n / p % p == 0) _v_lpf[n]\
    \ = _v_lpf[n / p] + 1;\n                else _v_lpf[n] = 1;\n\n              \
    \  int p_pw = pow<int>(p, _v_lpf[n]);\n                int q = n / p_pw;\n   \
    \             T p_pw_val = f(p, _v_lpf[n]);\n                if (q == 1) {\n \
    \                   _table[n] = p_pw_val;\n                } else {\n        \
    \            _table[n] = _table[q] * p_pw_val;\n                }\n          \
    \  }\n        }\n    }\n\n    static T val(int n) {\n        assert(n > 0);\n\
    \        if ((int)_table.size() <= n) set_upper(n);\n        return _table[n];\n\
    \    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\n#include \"../lpf_table.hpp\"\n\
    #include \"../pow.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T, T (*f)(long long,\
    \ long long)>\nstruct MultiplicativeFunctionTable {\n  private:\n    static inline\
    \ std::vector<int> _v_lpf{0, 0};\n    static inline std::vector<T> _table{0, 1};\n\
    \n  public:\n    MultiplicativeFunctionTable() = delete;\n\n    static void set_upper(int\
    \ m) {\n        if ((int)_table.size() > m) return;\n        int start = _table.size();\n\
    \n        LPFTable::set_upper(m);\n\n        _v_lpf.resize(m + 1, 0);\n      \
    \  _table.resize(m + 1);\n\n        for (int n = start; n <= m; ++n) {\n     \
    \       int p = LPFTable::lpf(n);\n            if (p == n) {\n               \
    \ _v_lpf[n] = 1;\n                _table[n] = f(p, 1);\n            } else {\n\
    \                if (n / p % p == 0) _v_lpf[n] = _v_lpf[n / p] + 1;\n        \
    \        else _v_lpf[n] = 1;\n\n                int p_pw = pow<int>(p, _v_lpf[n]);\n\
    \                int q = n / p_pw;\n                T p_pw_val = f(p, _v_lpf[n]);\n\
    \                if (q == 1) {\n                    _table[n] = p_pw_val;\n  \
    \              } else {\n                    _table[n] = _table[q] * p_pw_val;\n\
    \                }\n            }\n        }\n    }\n\n    static T val(int n)\
    \ {\n        assert(n > 0);\n        if ((int)_table.size() <= n) set_upper(n);\n\
    \        return _table[n];\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_ARBITRARY_TABLE_HPP\n"
  dependsOn:
  - math/lpf_table.hpp
  - math/pow.hpp
  isVerificationFile: false
  path: math/multiplicative_function/arbitrary_table.hpp
  requiredBy: []
  timestamp: '2025-02-08 19:46:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/unit_test/multiplicative_function_table.test.cpp
documentation_of: math/multiplicative_function/arbitrary_table.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/arbitrary_table.hpp
- /library/math/multiplicative_function/arbitrary_table.hpp.html
title: math/multiplicative_function/arbitrary_table.hpp
---
