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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../math/multiplicative_function/famous_function_table.hpp\"\n#include \"../../math/multiplicative_function/mobius.hpp\"\
    \n#include \"../../math/multiplicative_function/sigma.hpp\"\n#include \"../../math/multiplicative_function/euler_phi.hpp\"\
    \n#include \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout\
    \ << a + b << kendl;\n\n    int iter = 1000;\n    rep (iter) {\n        int n\
    \ = kk2::random::rng(2, 1000000);\n        assert(kk2::FamousFunctionTable::euler_phi(n)\
    \ == kk2::euler_phi(n));\n        assert(kk2::FamousFunctionTable::mobius(n) ==\
    \ kk2::mobius(n));\n        assert(kk2::FamousFunctionTable::sigma0(n) == kk2::sigma0(n));\n\
    \        assert(kk2::FamousFunctionTable::sigma1(n) == kk2::sigma1(n));\n    }\n\
    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/famous_function_table.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/famous_function_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/famous_function_table.test.cpp
- /verify/verify/unit_test/famous_function_table.test.cpp.html
title: verify/unit_test/famous_function_table.test.cpp
---
