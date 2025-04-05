---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':x:'
    path: math/multiplicative_function/prefix_sum.hpp
    title: math/multiplicative_function/prefix_sum.hpp
  - icon: ':question:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \ \n\n#include \"../../math/multiplicative_function/prefix_sum.hpp\"\n#include\
    \ \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
    \ std;\n\nusing mint = kk2::Mont<469762049>;\n\nint main() {\n    int t;\n   \
    \ kin >> t;\n    rep (t) {\n        i64 n;\n        mint a, b;\n        kin >>\
    \ n >> a >> b;\n        auto f = [&](i64 p, i64 e) -> mint { return a * e + b\
    \ * p; };\n        auto g1 = [&](i64) -> mint { return 1; };\n        auto g2\
    \ = [&](i64 p) -> mint { return p; };\n        kk2::PrefixSumOfMultiplicativeFunction<mint>\
    \ ps(n);\n        vc<mint> init1(ps.size()), init2(ps.size());\n        const\
    \ mint inv2 = mint(2).inv();\n        rep (i, ps.size()) {\n            init1[i]\
    \ = ps.eq[i] - 1;\n            init2[i] = mint(ps.eq[i]) * (ps.eq[i] + 1) * inv2\
    \ - 1;\n        }\n        ps.LucyDP(g1, init1);\n        ps.LucyDP(g2, init2);\n\
    \        rep (i, ps.size()) ps.prefix_sum_only_prime[i] = a * init1[i] + b * init2[i];\n\
    \        ps.Min_25Sieve(f);\n        kout << ps.prefix_sum.back() << \"\\n\";\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/multiplicative_function/prefix_sum.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/prime_table.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
- /verify/verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp.html
title: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
---
