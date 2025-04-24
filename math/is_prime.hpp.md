---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/euler_phi.hpp
    title: math/multiplicative_function/euler_phi.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/mobius.hpp
    title: math/multiplicative_function/mobius.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/sigma.hpp
    title: math/multiplicative_function/sigma.hpp
  - icon: ':question:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':x:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_d.test.cpp
    title: verify/aoj/aoj_ntl_1_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/famous_function_table.test.cpp
    title: verify/unit_test/famous_function_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/isprime_table_extend.test.cpp
    title: verify/unit_test/isprime_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/lpf_table_extend.test.cpp
    title: verify/unit_test/lpf_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/prime_factorize_table.test.cpp
    title: verify/unit_test/prime_factorize_table.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/factrize.test.cpp
    title: verify/yosupo_math/factrize.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/primality_test.test.cpp
    title: verify/yosupo_math/primality_test.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/primitive_root.test.cpp
    title: verify/yosupo_math/primitive_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_IS_PRIME_HPP\n#define KK2_MATH_IS_PRIME_HPP 1\n\n#include\
    \ <vector>\n\n#include \"../math_mod/pow_mod.hpp\"\n#include \"../modint/mont_arb.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace number_theory {\n\ntemplate <class T, class U>\
    \ bool miller_rabin(const T &n, const std::vector<T> &ws) {\n    if (n <= 2) return\
    \ n == 2;\n    if (~n & 1) return false;\n\n    T d = n - 1;\n    while (~d &\
    \ 1) d >>= 1;\n    U e = 1, rev = n - 1;\n    for (T w : ws) {\n        if (w\
    \ % n == 0) continue;\n        T t = d;\n        U y = pow_mod<T, T, U>(w, t,\
    \ n);\n        while (t != n - 1 and y != e and y != rev) {\n            y = y\
    \ * y % n;\n            t <<= 1;\n        }\n        if (y != rev and ~t & 1)\
    \ return false;\n    }\n    return true;\n}\n\nbool miller_rabin_u64(unsigned\
    \ long long n) {\n    return miller_rabin<unsigned long long, __uint128_t>(\n\
    \        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate\
    \ <class mint>\nbool miller_rabin_mont(unsigned long long n, const std::vector<unsigned\
    \ long long> &ws) {\n    if (n <= 2) return n == 2;\n    if (~n & 1) return false;\n\
    \n    if (mint::getmod() != n) mint::setmod(n);\n    unsigned long long d = n\
    \ - 1;\n    while (~d & 1) d >>= 1;\n    mint e = 1, rev = n - 1;\n    for (unsigned\
    \ long long w : ws) {\n        if (w % n == 0) continue;\n        unsigned long\
    \ long t = d;\n        mint y = mint(w).pow(t);\n        while (t != n - 1 and\
    \ y != e and y != rev) {\n            y *= y;\n            t <<= 1;\n        }\n\
    \        if (y != rev and ~t & 1) return false;\n    }\n    return true;\n}\n\n\
    bool is_prime(unsigned long long n) {\n    using mint32 = ArbitraryLazyMontgomeryModInt<54305750>;\n\
    \    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54305750>;\n\n    if (n\
    \ <= 2) return n == 2;\n    if (~n & 1) return false;\n    if (n < (1ull << 30))\
    \ {\n        return miller_rabin_mont<mint32>(n, {2, 7, 61});\n    } else if (n\
    \ < (1ull << 62)) {\n        return miller_rabin_mont<mint64>(n, {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022});\n    } else {\n        return miller_rabin_u64(n);\n\
    \    }\n}\n\n}; // namespace number_theory\n\nusing number_theory::is_prime;\n\
    \n}; // namespace kk2\n\n#endif // KK2_MATH_IS_PRIME_HPP\n"
  dependsOn:
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  isVerificationFile: false
  path: math/is_prime.hpp
  requiredBy:
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/sigma.hpp
  - math/multiplicative_function/euler_phi.hpp
  timestamp: '2025-04-06 00:09:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/unit_test/lpf_table_extend.test.cpp
  - verify/unit_test/isprime_table_extend.test.cpp
  - verify/unit_test/prime_factorize_table.test.cpp
  - verify/unit_test/famous_function_table.test.cpp
documentation_of: math/is_prime.hpp
layout: document
redirect_from:
- /library/math/is_prime.hpp
- /library/math/is_prime.hpp.html
title: math/is_prime.hpp
---
