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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../modint/modint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../modint/modint.hpp\"\n#include \"../../math_mod/comb_large.hpp\"\n#include\
    \ \"../../math_mod/comb.hpp\"\n#include \"../../random/gen.hpp\"\n#include \"\
    ../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    kk2::Comb<kk2::mint107>::set_upper(1e7);\n\
    \    int up = 2000001, lw = 1e7;\n    int t = 2;\n    rep (t) {\n        int n\
    \ = kk2::random::rng(up, lw);\n        auto a = kk2::Comb<kk2::mint107>::fact(n);\n\
    \        auto b = kk2::CombLarge<kk2::mint107>::fact(n);\n        // \u58CA\u308C\
    \u3066\u3044\u308B\u306E\u3067false\u3092\u8FD4\u3059\n        // assert(a ==\
    \ b);\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
- /verify/verify/unit_test/math_mod/large_fact_arb_mod.test.cpp.html
title: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
---
