---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
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
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_d.test.cpp
    title: verify/aoj/aoj_ntl_1_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    title: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../../type_traits/integral.hpp\"\n#include\
    \ \"../prime_factorize.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T, is_integral_t<T>\
    \ * = nullptr> T euler_phi(T n) {\n    assert(n > 0);\n    for (auto [p, k] :\
    \ factorize(static_cast<long long>(n))) n -= n / p;\n    return n;\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\n"
  dependsOn:
  - type_traits/integral.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/multiplicative_function/euler_phi.hpp
  requiredBy: []
  timestamp: '2025-06-04 11:53:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
documentation_of: math/multiplicative_function/euler_phi.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/euler_phi.hpp
- /library/math/multiplicative_function/euler_phi.hpp.html
title: math/multiplicative_function/euler_phi.hpp
---
