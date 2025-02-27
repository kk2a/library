---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/famous_function_table.test.cpp
    title: verify/unit_test/famous_function_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../pow.hpp\"\n#include \"../prime_factorize.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, is_integral_t<T> * = nullptr>\nT sigma0(T\
    \ n) {\n    assert(n > 0);\n    T res = 1;\n    for (auto [p, k] : factorize(static_cast<long\
    \ long>(n))) res *= k + 1;\n    return res;\n}\n\ntemplate <class T, is_integral_t<T>\
    \ * = nullptr>\nT sigma1(T n) {\n    assert(n > 0);\n    T res = 1;\n    for (auto\
    \ [p, k] : factorize(static_cast<long long>(n))) {\n        T p_k = pow<T>(p,\
    \ k);\n        res *= p_k + (p_k - 1) / (p - 1);\n    }\n    return res;\n}\n\n\
    } // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_SIGMA_HPP\n"
  dependsOn:
  - math/pow.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - modint/mont_arb.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/multiplicative_function/sigma.hpp
  requiredBy: []
  timestamp: '2025-02-08 19:46:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/famous_function_table.test.cpp
documentation_of: math/multiplicative_function/sigma.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/sigma.hpp
- /library/math/multiplicative_function/sigma.hpp.html
title: math/multiplicative_function/sigma.hpp
---
