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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../math_mod/inv_table.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../math_mod/inv_table.hpp\"\n#include \"../../modint/modint.hpp\"\n#include\
    \ \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
    \ std;\n\nvoid test_inv_table() {\n    using mint = kk2::mint998;\n    using InvTab\
    \ = kk2::InvTable<mint>;\n    \n    // \u57FA\u672C\u7684\u306A\u9006\u5143\u306E\
    \u30C6\u30B9\u30C8\n    {\n        rep(100) {\n            int i = kk2::random::rng(1,\
    \ 1001);\n            mint inv_i = InvTab::inv(i);\n            assert(mint(i)\
    \ * inv_i == mint(1));\n        }\n        cerr << \"Basic inverse: 100 random\
    \ tests passed!\" << endl;\n    }\n    \n    // \u5927\u304D\u306A\u5024\u3067\
    \u306E\u81EA\u52D5\u62E1\u5F35\u30C6\u30B9\u30C8\n    {\n        rep(1000) {\n\
    \            int i = kk2::random::rng(1, 50001);\n            mint inv_i = InvTab::inv(i);\n\
    \            assert(mint(i) * inv_i == mint(1));\n        }\n        cerr << \"\
    Auto expansion: 1000 random tests passed!\" << endl;\n    }\n    \n    // \u8CA0\
    \u306E\u6570\u306E\u30C6\u30B9\u30C8\n    {\n        rep(1000) {\n           \
    \ int i = kk2::random::rng(1, 10001);\n            mint inv_pos = InvTab::inv(i);\n\
    \            mint inv_neg = InvTab::inv(-i);\n            assert(inv_pos == -inv_neg);\n\
    \            assert(mint(-i) * inv_neg == mint(1));\n        }\n        cerr <<\
    \ \"Negative numbers: 1000 random tests passed!\" << endl;\n    }\n    \n    //\
    \ set_upper\u306E\u52D5\u4F5C\u30C6\u30B9\u30C8\n    {\n        InvTab::set_upper(20000);\n\
    \        rep(1000) {\n            int i = kk2::random::rng(1, 20001);\n      \
    \      mint inv_i = InvTab::inv(i);\n            assert(mint(i) * inv_i == mint(1));\n\
    \        }\n        cerr << \"set_upper: 1000 random tests passed!\" << endl;\n\
    \    }\n    \n    // \u4E00\u81F4\u6027\u30C6\u30B9\u30C8\uFF08\u8907\u6570\u56DE\
    \u547C\u3073\u51FA\u3057\u3067\u540C\u3058\u7D50\u679C\uFF09\n    {\n        rep(100)\
    \ {\n            int i = kk2::random::rng(1, 10001);\n            mint inv1 =\
    \ InvTab::inv(i);\n            mint inv2 = InvTab::inv(i);\n            assert(inv1\
    \ == inv2);\n        }\n        cerr << \"Consistency: 100 random tests passed!\"\
    \ << endl;\n    }\n}\n\nvoid test() {\n    test_inv_table();\n    \n    // \u5168\
    \u30C6\u30B9\u30C8\u901A\u904E\n    cerr << \"All InvTable tests passed!\" <<\
    \ endl;\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a +\
    \ b << kendl;\n\n    test();\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/math_mod/inv_table.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/inv_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math_mod/inv_table.test.cpp
- /verify/verify/unit_test/math_mod/inv_table.test.cpp.html
title: verify/unit_test/math_mod/inv_table.test.cpp
---
