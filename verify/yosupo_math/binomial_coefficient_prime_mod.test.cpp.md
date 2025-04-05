---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \ \n\n#include \"../../math_mod/comb.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nusing mint\
    \ = kk2::ModInt<0>;\n\nint main() {\n    int t, m;\n    kin >> t >> m;\n    mint::setmod(m);\n\
    \    kk2::Comb<mint>::set_upper(1e7);\n    rep (t) {\n        int n, k;\n    \
    \    kin >> n >> k;\n        kout << kk2::Comb<mint>::binom(n, k) << \"\\n\";\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
- /verify/verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp.html
title: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
---
