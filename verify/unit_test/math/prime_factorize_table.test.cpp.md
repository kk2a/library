---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize_table.hpp
    title: math/prime_factorize_table.hpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../math/prime_factorize_table.hpp\"\n#include \"../../../math/prime_factorize.hpp\"\
    \n#include \"../../../random/gen.hpp\"\n#include \"../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_basic_factorization() {\n    // Test small\
    \ numbers\n    auto f2 = kk2::FactorizeTable::factorize(2);\n    assert(f2.size()\
    \ == 1 && f2[0].first == 2 && f2[0].second == 1);\n    \n    auto f3 = kk2::FactorizeTable::factorize(3);\n\
    \    assert(f3.size() == 1 && f3[0].first == 3 && f3[0].second == 1);\n    \n\
    \    auto f4 = kk2::FactorizeTable::factorize(4);\n    assert(f4.size() == 1 &&\
    \ f4[0].first == 2 && f4[0].second == 2);\n    \n    auto f6 = kk2::FactorizeTable::factorize(6);\n\
    \    assert(f6.size() == 2 && f6[0].first == 2 && f6[0].second == 1 && f6[1].first\
    \ == 3 && f6[1].second == 1);\n    \n    auto f8 = kk2::FactorizeTable::factorize(8);\n\
    \    assert(f8.size() == 1 && f8[0].first == 2 && f8[0].second == 3);\n    \n\
    \    auto f12 = kk2::FactorizeTable::factorize(12);\n    assert(f12.size() ==\
    \ 2 && f12[0].first == 2 && f12[0].second == 2 && f12[1].first == 3 && f12[1].second\
    \ == 1);\n    \n    auto f30 = kk2::FactorizeTable::factorize(30);\n    assert(f30.size()\
    \ == 3 && f30[0].first == 2 && f30[0].second == 1 && \n           f30[1].first\
    \ == 3 && f30[1].second == 1 && f30[2].first == 5 && f30[2].second == 1);\n}\n\
    \nvoid test_perfect_powers() {\n    // Test perfect powers\n    auto f16 = kk2::FactorizeTable::factorize(16);\
    \ // 2^4\n    assert(f16.size() == 1 && f16[0].first == 2 && f16[0].second ==\
    \ 4);\n    \n    auto f27 = kk2::FactorizeTable::factorize(27); // 3^3\n    assert(f27.size()\
    \ == 1 && f27[0].first == 3 && f27[0].second == 3);\n    \n    auto f125 = kk2::FactorizeTable::factorize(125);\
    \ // 5^3\n    assert(f125.size() == 1 && f125[0].first == 5 && f125[0].second\
    \ == 3);\n    \n    auto f1024 = kk2::FactorizeTable::factorize(1024); // 2^10\n\
    \    assert(f1024.size() == 1 && f1024[0].first == 2 && f1024[0].second == 10);\n\
    }\n\nvoid test_prime_numbers() {\n    // Test prime numbers\n    vector<int> primes\
    \ = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,\
    \ 73, 79, 83, 89, 97};\n    for (int p : primes) {\n        auto fp = kk2::FactorizeTable::factorize(p);\n\
    \        assert(fp.size() == 1 && fp[0].first == p && fp[0].second == 1);\n  \
    \  }\n}\n\nvoid test_consistency_with_reference() {\n    // Test consistency with\
    \ reference implementation\n    for (int n = 2; n <= 1000; n++) {\n        auto\
    \ f = kk2::factorize(n);\n        auto f1 = kk2::FactorizeTable::factorize(n);\n\
    \        assert(f.size() == f1.size());\n        for (int i = 0; i < (int)f.size();\
    \ i++) {\n            assert(f[i].first == f1[i].first);\n            assert(f[i].second\
    \ == f1[i].second);\n        }\n        \n        // Verify that the factorization\
    \ is correct\n        long long product = 1;\n        for (auto [p, e] : f1) {\n\
    \            for (int i = 0; i < e; i++) {\n                product *= p;\n  \
    \          }\n        }\n        assert(product == n);\n    }\n}\n\nvoid test_large_numbers()\
    \ {\n    // Test with larger random numbers\n    int iter = 200;\n    rep (iter)\
    \ {\n        int n = kk2::random::rng(2, 1000000);\n        auto f = kk2::factorize(n);\n\
    \        auto f1 = kk2::FactorizeTable::factorize(n);\n        assert(f.size()\
    \ == f1.size());\n        for (int i = 0; i < (int)f.size(); i++) {\n        \
    \    assert(f[i].first == f1[i].first);\n            assert(f[i].second == f1[i].second);\n\
    \        }\n        \n        // Verify correctness\n        long long product\
    \ = 1;\n        for (auto [p, e] : f1) {\n            for (int i = 0; i < e; i++)\
    \ {\n                product *= p;\n                if (product > n) break; //\
    \ Avoid overflow\n            }\n            if (product > n) break;\n       \
    \ }\n        if (product <= n) assert(product == n);\n    }\n}\n\nvoid test_edge_cases()\
    \ {\n    // Test highly composite numbers\n    auto f60 = kk2::FactorizeTable::factorize(60);\
    \ // 2^2 * 3 * 5\n    assert(f60.size() == 3 && f60[0].first == 2 && f60[0].second\
    \ == 2 && \n           f60[1].first == 3 && f60[1].second == 1 && f60[2].first\
    \ == 5 && f60[2].second == 1);\n    \n    auto f120 = kk2::FactorizeTable::factorize(120);\
    \ // 2^3 * 3 * 5\n    assert(f120.size() == 3 && f120[0].first == 2 && f120[0].second\
    \ == 3 && \n           f120[1].first == 3 && f120[1].second == 1 && f120[2].first\
    \ == 5 && f120[2].second == 1);\n    \n    auto f210 = kk2::FactorizeTable::factorize(210);\
    \ // 2 * 3 * 5 * 7\n    assert(f210.size() == 4 && f210[0].first == 2 && f210[0].second\
    \ == 1 && \n           f210[1].first == 3 && f210[1].second == 1 && f210[2].first\
    \ == 5 && f210[2].second == 1 &&\n           f210[3].first == 7 && f210[3].second\
    \ == 1);\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a\
    \ + b << kendl;\n\n    test_basic_factorization();\n    test_perfect_powers();\n\
    \    test_prime_numbers();\n    test_consistency_with_reference();\n    test_large_numbers();\n\
    \    test_edge_cases();\n\n    return 0;\n}\n"
  dependsOn:
  - math/prime_factorize_table.hpp
  - math/lpf_table.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - random/gen.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math/prime_factorize_table.test.cpp
  requiredBy: []
  timestamp: '2025-07-10 13:49:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/prime_factorize_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/prime_factorize_table.test.cpp
- /verify/verify/unit_test/math/prime_factorize_table.test.cpp.html
title: verify/unit_test/math/prime_factorize_table.test.cpp
---
