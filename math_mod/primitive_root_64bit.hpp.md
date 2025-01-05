---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':question:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/primitive_root.test.cpp
    title: verify/yosupo_math/primitive_root.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n#define KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\
    \ 1\n\n#include \"../random/gen.hpp\"\n#include \"pow_mod.hpp\"\n#include \"../math/prime_factorize.hpp\"\
    \n\nnamespace kk2 {\n\nlong long primitive_root_64bit(long long p) {\n    if (p\
    \ == 2) return 1;\n    if (p == 3) return 2;\n\n    auto f = factorize(p - 1);\n\
    \    while (true) {\n        long long g = random::rng(2, p - 1);\n        bool\
    \ ok = true;\n        for (auto &&[q, e] : f) {\n            if (pow_mod<__int128_t>(g,\
    \ (p - 1) / q, p) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if (ok) return g;\n    }\n}\n\n}\n\n#endif\
    \ // KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n"
  dependsOn:
  - random/gen.hpp
  - random/seed.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - random/gen.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math_mod/primitive_root_64bit.hpp
  requiredBy: []
  timestamp: '2025-01-06 00:03:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/primitive_root.test.cpp
documentation_of: math_mod/primitive_root_64bit.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_root_64bit.hpp
- /library/math_mod/primitive_root_64bit.hpp.html
title: math_mod/primitive_root_64bit.hpp
---
