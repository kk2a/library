---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/binom_table.hpp
    title: math_mod/binom_table.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
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
    ../../../math_mod/binom_table.hpp\"\n#include \"../../../math_mod/comb.hpp\"\n\
    #include \"../../../modint/modint.hpp\"\n#include \"../../../random/gen.hpp\"\n\
    #include \"../../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    //\
    \ alias\u306E\u5B9A\u7FA9\n    using mint = kk2::mint998;\n    using BTable =\
    \ kk2::BinomTable<mint>;\n    using Comb = kk2::Comb<mint>;\n\n    // binom_table\u306E\
    \u30C6\u30B9\u30C8\n    rep (1000) {\n        int max_n = kk2::random::rng(1,\
    \ 1000);\n        BTable::set_upper(max_n);\n        \n        rep (1000) {\n\
    \            int n = kk2::random::rng(0, max_n + 1);\n            int k = kk2::random::rng(-10,\
    \ n + 10);\n            \n            auto table_result = BTable::binom(n, k);\n\
    \            auto comb_result = Comb::binom(n, k);\n            \n           \
    \ if (table_result != comb_result) {\n                cerr << \"binom mismatch:\
    \ n=\" << n << \", k=\" << k << endl;\n                cerr << \"table: \" <<\
    \ table_result << \", comb: \" << comb_result << endl;\n                exit(1);\n\
    \            }\n        }\n        \n        // \u30A8\u30C3\u30B8\u30B1\u30FC\
    \u30B9\u306E\u30C6\u30B9\u30C8\n        if (BTable::binom(0, 0) != 1) {\n    \
    \        cerr << \"binom(0,0) should be 1\" << endl;\n            exit(1);\n \
    \       }\n        if (BTable::binom(max_n, 0) != 1) {\n            cerr << \"\
    binom(n,0) should be 1\" << endl;\n            exit(1);\n        }\n        if\
    \ (BTable::binom(max_n, max_n) != 1) {\n            cerr << \"binom(n,n) should\
    \ be 1\" << endl;\n            exit(1);\n        }\n        if (BTable::binom(max_n,\
    \ -1) != 0) {\n            cerr << \"binom(n,-1) should be 0\" << endl;\n    \
    \        exit(1);\n        }\n        if (BTable::binom(max_n, max_n + 1) != 0)\
    \ {\n            cerr << \"binom(n,n+1) should be 0\" << endl;\n            exit(1);\n\
    \        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math_mod/binom_table.hpp
  - math_mod/comb.hpp
  - type_traits/integral.hpp
  - modint/modint.hpp
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
  path: verify/unit_test/math_mod/binom_table.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math_mod/binom_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math_mod/binom_table.test.cpp
- /verify/verify/unit_test/math_mod/binom_table.test.cpp.html
title: verify/unit_test/math_mod/binom_table.test.cpp
---
