---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/inv_table.hpp
    title: "`[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\
      \u30D6\u30EB"
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../math_mod/inv_table.hpp\"\n#include \"../../../modint/modint.hpp\"\n#include\
    \ \"../../../random/gen.hpp\"\n#include \"../../../template/template.hpp\"\nusing\
    \ namespace std;\n\nvoid test_inv_table() {\n    using mint = kk2::mint998;\n\
    \    using InvTab = kk2::InvTable<mint>;\n    \n    // \u57FA\u672C\u7684\u306A\
    \u9006\u5143\u306E\u30C6\u30B9\u30C8\n    {\n        rep(100) {\n            int\
    \ i = kk2::random::rng(1, 1001);\n            mint inv_i = InvTab::inv(i);\n \
    \           assert(mint(i) * inv_i == mint(1));\n        }\n        cerr << \"\
    Basic inverse: 100 random tests passed!\" << endl;\n    }\n    \n    // \u5927\
    \u304D\u306A\u5024\u3067\u306E\u81EA\u52D5\u62E1\u5F35\u30C6\u30B9\u30C8\n   \
    \ {\n        rep(1000) {\n            int i = kk2::random::rng(1, 50001);\n  \
    \          mint inv_i = InvTab::inv(i);\n            assert(mint(i) * inv_i ==\
    \ mint(1));\n        }\n        cerr << \"Auto expansion: 1000 random tests passed!\"\
    \ << endl;\n    }\n    \n    // \u8CA0\u306E\u6570\u306E\u30C6\u30B9\u30C8\n \
    \   {\n        rep(1000) {\n            int i = kk2::random::rng(1, 10001);\n\
    \            mint inv_pos = InvTab::inv(i);\n            mint inv_neg = InvTab::inv(-i);\n\
    \            assert(inv_pos == -inv_neg);\n            assert(mint(-i) * inv_neg\
    \ == mint(1));\n        }\n        cerr << \"Negative numbers: 1000 random tests\
    \ passed!\" << endl;\n    }\n    \n    // set_upper\u306E\u52D5\u4F5C\u30C6\u30B9\
    \u30C8\n    {\n        InvTab::set_upper(20000);\n        rep(1000) {\n      \
    \      int i = kk2::random::rng(1, 20001);\n            mint inv_i = InvTab::inv(i);\n\
    \            assert(mint(i) * inv_i == mint(1));\n        }\n        cerr << \"\
    set_upper: 1000 random tests passed!\" << endl;\n    }\n    \n    // \u4E00\u81F4\
    \u6027\u30C6\u30B9\u30C8\uFF08\u8907\u6570\u56DE\u547C\u3073\u51FA\u3057\u3067\
    \u540C\u3058\u7D50\u679C\uFF09\n    {\n        rep(100) {\n            int i =\
    \ kk2::random::rng(1, 10001);\n            mint inv1 = InvTab::inv(i);\n     \
    \       mint inv2 = InvTab::inv(i);\n            assert(inv1 == inv2);\n     \
    \   }\n        cerr << \"Consistency: 100 random tests passed!\" << endl;\n  \
    \  }\n}\n\nvoid test() {\n    test_inv_table();\n    \n    // \u5168\u30C6\u30B9\
    \u30C8\u901A\u904E\n    cerr << \"All InvTable tests passed!\" << endl;\n}\n\n\
    int main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\
    \n    test();\n\n    return 0;\n}\n"
  dependsOn:
  - math_mod/inv_table.hpp
  - modint/modint.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math_mod/inv_table.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/inv_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math_mod/inv_table.test.cpp
- /verify/verify/unit_test/math_mod/inv_table.test.cpp.html
title: verify/unit_test/math_mod/inv_table.test.cpp
---
