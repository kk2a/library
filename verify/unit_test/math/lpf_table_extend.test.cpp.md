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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math/lpf_table.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../math/lpf_table.hpp\"\n#include \"../../math/multiplicative_function/prime_counting.hpp\"\
    \n#include \"../../math/prime_factorize.hpp\"\n#include \"../../random/gen.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    int\
    \ iter = 1000;\n    rep (iter) {\n        int n = kk2::random::rng(2, 10000000);\n\
    \        assert((int)kk2::LPFTable::primes(n).size() == kk2::prime_counting(n));\n\
    \        assert(kk2::LPFTable::lpf(n) == kk2::factorize(n)[0].first);\n    }\n\
    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/math/lpf_table_extend.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math/lpf_table_extend.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/lpf_table_extend.test.cpp
- /verify/verify/unit_test/math/lpf_table_extend.test.cpp.html
title: verify/unit_test/math/lpf_table_extend.test.cpp
---
