---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/poly_taylor_shift.hpp
    title: fps/poly_taylor_shift.hpp
  - icon: ':x:'
    path: math_mod/bell_number.hpp
    title: math_mod/bell_number.hpp
  - icon: ':warning:'
    path: math_mod/bernoulli_number.hpp
    title: math_mod/bernoulli_number.hpp
  - icon: ':x:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/poly_taylor_shift.test.cpp
    title: verify/yosupo_fps/poly_taylor_shift.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
    title: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/enumerate_bell_number.test.cpp
    title: verify/yosupo_math/enumerate_bell_number.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MOD_COMB_HPP\n#define KK2_MATH_MOD_COMB_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class mint> struct Comb {\n    static inline\
    \ std::vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n    Comb() = delete;\n\n\
    \    static void set_upper(int m = -1) {\n        int n = (int)_fact.size();\n\
    \        if (m == -1) m = n << 1;\n        if (n > m) return;\n        m = std::min<int>(m,\
    \ mint::getmod() - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m\
    \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i]\
    \ = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m] =\
    \ _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n         \
    \   _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i - 1] *\
    \ _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n        if\
    \ (n < 0) return 0;\n        if ((int)_fact.size() <= n) set_upper(n);\n     \
    \   return _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if (n <\
    \ 0) return 0;\n        if ((int)_ifact.size() <= n) set_upper(n);\n        return\
    \ _ifact[n];\n    }\n\n    static mint inv(int n) {\n        if (n < 0) return\
    \ -inv(-n);\n        if ((int)_inv.size() <= n) set_upper(n);\n        return\
    \ _inv[n];\n    }\n\n    static mint binom(int n, int k) {\n        if (k < 0\
    \ || k > n) return 0;\n        return fact(n) * ifact(k) * ifact(n - k);\n   \
    \ }\n\n    template <class T> static mint multinomial(const std::vector<T> &r)\
    \ {\n        static_assert(is_integral<T>::value, \"T must be integral\");\n \
    \       int n = 0;\n        for (auto &x : r) {\n            if (x < 0) return\
    \ 0;\n            n += x;\n        }\n        mint res = fact(n);\n        for\
    \ (auto &x : r) res *= ifact(x);\n        return res;\n    }\n\n    static mint\
    \ binom_naive(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
    \        mint res = 1;\n        k = std::min(k, n - k);\n        for (int i =\
    \ 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    static\
    \ mint permu(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
    \        return fact(n) * ifact(n - k);\n    }\n\n    static mint homo(int n,\
    \ int k) {\n        if (n < 0 || k < 0) return 0;\n        return k == 0 ? 1 :\
    \ binom(n + k - 1, k);\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_COMB_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math_mod/comb.hpp
  requiredBy:
  - fps/poly_taylor_shift.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/bell_number.hpp
  - math_mod/comb_large.hpp
  timestamp: '2025-02-08 14:53:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
documentation_of: math_mod/comb.hpp
layout: document
redirect_from:
- /library/math_mod/comb.hpp
- /library/math_mod/comb.hpp.html
title: math_mod/comb.hpp
---
