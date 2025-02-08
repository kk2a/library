---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/famous_function_table.test.cpp
    title: verify/unit_test/famous_function_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/multiplicative_function_table.test.cpp
    title: verify/unit_test/multiplicative_function_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/famous_function_table.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 1\
    \ \"math/lpf_table.hpp\"\n\n\n\n#line 6 \"math/lpf_table.hpp\"\n#include <numeric>\n\
    #line 8 \"math/lpf_table.hpp\"\n\nnamespace kk2 {\n\nstruct LPFTable {\n  private:\n\
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
    \ _euler_phi[n];\n    }\n};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP\n#define\
    \ KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#include \"../lpf_table.hpp\"\n#include\
    \ \"../pow.hpp\"\n\nnamespace kk2 {\n\nstruct FamousFunctionTable {\n  private:\n\
    \    static inline std::vector<int> _v_lpf{0, 0}, _mobius{0, 1}, _sigma0{0, 1},\
    \ _euler_phi{0, 1};\n    static inline std::vector<long long> _sigma1{0, 1};\n\
    \n  public:\n    FamousFunctionTable() = delete;\n\n    static void set_upper(int\
    \ m) {\n        if ((int)_mobius.size() > m) return;\n        int start = _mobius.size();\n\
    \n        LPFTable::set_upper(m);\n\n        _v_lpf.resize(m + 1, 0);\n      \
    \  _mobius.resize(m + 1, 1);\n        _sigma0.resize(m + 1, 1);\n        _sigma1.resize(m\
    \ + 1, 1);\n        _euler_phi.resize(m + 1, 1);\n\n        for (int n = start;\
    \ n <= m; ++n) {\n            int p = LPFTable::lpf(n);\n            if (p ==\
    \ n) {\n                _v_lpf[n] = 1;\n                _mobius[n] = -1;\n   \
    \             _sigma0[n] = 2;\n                _sigma1[n] = p + 1;\n         \
    \       _euler_phi[n] = p - 1;\n            } else {\n                if (n /\
    \ p % p == 0) _v_lpf[n] = _v_lpf[n / p] + 1;\n                else _v_lpf[n] =\
    \ 1;\n\n                int p_pw = pow<int>(p, _v_lpf[n]);\n                int\
    \ q = n / p_pw;\n                if (q == 1) {\n                    _mobius[n]\
    \ = 0;\n                    _sigma0[n] = _v_lpf[n] + 1;\n                    _sigma1[n]\
    \ = _sigma1[n / p] + p_pw;\n                    _euler_phi[n] = p_pw - p_pw /\
    \ p;\n                } else {\n                    _mobius[n] = _mobius[q] *\
    \ _mobius[p_pw];\n                    _sigma0[n] = _sigma0[q] * _sigma0[p_pw];\n\
    \                    _sigma1[n] = _sigma1[q] * _sigma1[p_pw];\n              \
    \      _euler_phi[n] = _euler_phi[q] * _euler_phi[p_pw];\n                }\n\
    \            }\n        }\n    }\n\n    static int mobius(int n) {\n        assert(n\
    \ >= 0);\n        if ((int)_mobius.size() <= n) set_upper(n);\n        return\
    \ _mobius[n];\n    }\n\n    static int sigma0(int n) {\n        assert(n > 0);\n\
    \        if ((int)_sigma0.size() <= n) set_upper(n);\n        return _sigma0[n];\n\
    \    }\n\n    static long long sigma1(int n) {\n        assert(n > 0);\n     \
    \   if ((int)_sigma1.size() <= n) set_upper(n);\n        return _sigma1[n];\n\
    \    }\n\n    static int euler_phi(int n) {\n        assert(n > 0);\n        if\
    \ ((int)_euler_phi.size() <= n) set_upper(n);\n        return _euler_phi[n];\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_TABLE_HPP\n"
  dependsOn:
  - math/lpf_table.hpp
  - math/pow.hpp
  isVerificationFile: false
  path: math/multiplicative_function/famous_function_table.hpp
  requiredBy: []
  timestamp: '2025-02-08 19:46:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/famous_function_table.test.cpp
  - verify/unit_test/multiplicative_function_table.test.cpp
documentation_of: math/multiplicative_function/famous_function_table.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/famous_function_table.hpp
- /library/math/multiplicative_function/famous_function_table.hpp.html
title: math/multiplicative_function/famous_function_table.hpp
---
