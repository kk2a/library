---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/taylor_shift.hpp
    title: fps/taylor_shift.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  - icon: ':warning:'
    path: math_mod/comb_large_arb.hpp
    title: math_mod/comb_large_arb.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/comb.hpp\"\n\n\n\ntemplate <class mint>\nstruct\
    \ Comb {\n    static inline vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n   \
    \ Comb() = delete;\n\n    static void extend(int m = -1) {\n        int n = (int)_fact.size();\n\
    \        if (m == -1) m = n << 1;\n        if (n > m) return;\n        m = min<int>(m,\
    \ mint::getmod() - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i]\
    \ = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m] =\
    \ _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n         \
    \   _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i - 1] *\
    \ _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n        if\
    \ (n < 0) return 0;\n        if ((int)_fact.size() <= n) extend(n);\n        return\
    \ _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if (n < 0) return\
    \ 0;\n        if ((int)_ifact.size() <= n) extend(n);\n        return _ifact[n];\n\
    \    }\n\n    static mint inv(int n) {\n        if (n < 0) return -inv(-n);\n\
    \        if ((int)_inv.size() <= n) extend(n);\n        return _inv[n];\n    }\n\
    \n    static mint binom(int n, int k) {\n        if (k < 0 || k > n) return 0;\n\
    \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <class\
    \ T>\n    static mint multinomial(const vector<T>& r) {\n        static_assert(is_integral_v<T>,\
    \ \"T must be integral\");\n        int n = 0;\n        for (auto &x : r) {\n\
    \            if (x < 0) return 0;\n            n += x;\n        }\n        mint\
    \ res = fact(n);\n        for (auto &x : r) res *= ifact(x);\n        return res;\n\
    \    }\n\n    static mint binom_naive(int n, int k) {\n        if (n < 0 || k\
    \ < 0 || k > n) return 0;\n        mint res = 1;\n        k = min(k, n - k);\n\
    \        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n\
    \    }\n\n    static mint permu(int n, int k) {\n        if (n < 0 || k < 0 ||\
    \ k > n) return 0;\n        return fact(n) * ifact(n - k);\n    }\n\n    static\
    \ mint homo(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        return\
    \ k == 0 ? 1 : binom(n + k - 1, k);\n    }\n};\n\n\n"
  code: "#ifndef MOD_COMB_HPP\n#define MOD_COMB_HPP 1\n\ntemplate <class mint>\nstruct\
    \ Comb {\n    static inline vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n   \
    \ Comb() = delete;\n\n    static void extend(int m = -1) {\n        int n = (int)_fact.size();\n\
    \        if (m == -1) m = n << 1;\n        if (n > m) return;\n        m = min<int>(m,\
    \ mint::getmod() - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i]\
    \ = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m] =\
    \ _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n         \
    \   _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i - 1] *\
    \ _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n        if\
    \ (n < 0) return 0;\n        if ((int)_fact.size() <= n) extend(n);\n        return\
    \ _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if (n < 0) return\
    \ 0;\n        if ((int)_ifact.size() <= n) extend(n);\n        return _ifact[n];\n\
    \    }\n\n    static mint inv(int n) {\n        if (n < 0) return -inv(-n);\n\
    \        if ((int)_inv.size() <= n) extend(n);\n        return _inv[n];\n    }\n\
    \n    static mint binom(int n, int k) {\n        if (k < 0 || k > n) return 0;\n\
    \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <class\
    \ T>\n    static mint multinomial(const vector<T>& r) {\n        static_assert(is_integral_v<T>,\
    \ \"T must be integral\");\n        int n = 0;\n        for (auto &x : r) {\n\
    \            if (x < 0) return 0;\n            n += x;\n        }\n        mint\
    \ res = fact(n);\n        for (auto &x : r) res *= ifact(x);\n        return res;\n\
    \    }\n\n    static mint binom_naive(int n, int k) {\n        if (n < 0 || k\
    \ < 0 || k > n) return 0;\n        mint res = 1;\n        k = min(k, n - k);\n\
    \        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n\
    \    }\n\n    static mint permu(int n, int k) {\n        if (n < 0 || k < 0 ||\
    \ k > n) return 0;\n        return fact(n) * ifact(n - k);\n    }\n\n    static\
    \ mint homo(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        return\
    \ k == 0 ? 1 : binom(n + k - 1, k);\n    }\n};\n\n#endif // MOD_COMB_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/comb.hpp
  requiredBy:
  - fps/taylor_shift.hpp
  - math_mod/comb_large.hpp
  - math_mod/comb_large_arb.hpp
  timestamp: '2024-06-13 21:51:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/comb.hpp
layout: document
redirect_from:
- /library/math_mod/comb.hpp
- /library/math_mod/comb.hpp.html
title: math_mod/comb.hpp
---
