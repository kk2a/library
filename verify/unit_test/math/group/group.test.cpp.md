---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/add.hpp
    title: math/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
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
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash.hpp
    title: random/hash.hpp
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
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../math/group/add.hpp\"\n#include \"../../../../math/group/rolling_hash.hpp\"\
    \n#include \"../../../../math/group/sum_with_size.hpp\"\n#include \"../../../../random/gen.hpp\"\
    \n#include \"../../../../template/template.hpp\"\nusing namespace std;\n\nvoid\
    \ test_group() {\n    // Add group test\n    {\n        using G = kk2::group::Add<int>;\n\
    \        G unit = G::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(-1000,\
    \ 1001);\n            int val2 = kk2::random::rng(-1000, 1001);\n            G\
    \ a(val1), b(val2);\n\n            assert(G::op(unit, a) == a);\n            assert(G::op(a,\
    \ unit) == a);\n            assert(G::op(a, b).a == val1 + val2);\n\n        \
    \    auto inv_a = G::inv(a);\n            assert(inv_a.a == -val1);\n        \
    \    assert(G::op(a, inv_a) == unit);\n            assert(G::op(inv_a, a) == unit);\n\
    \        }\n        cerr << \"Add: 10000 random tests passed!\" << endl;\n   \
    \ }\n\n    // SumWithSize group test\n    {\n        using G = kk2::group::SumWithSize<int>;\n\
    \        G unit = G::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(-1000,\
    \ 1001);\n            int val2 = kk2::random::rng(-1000, 1001);\n            G\
    \ a(val1), b(val2);\n\n            auto ab = G::op(a, b);\n            assert(ab.a\
    \ == val1 + val2 && ab.size == 2);\n\n            auto inv_a = G::inv(a);\n  \
    \          assert(inv_a.a == -val1 && inv_a.size == -1);\n\n            auto cancel\
    \ = G::op(a, inv_a);\n            assert(cancel == unit);\n        }\n       \
    \ cerr << \"SumWithSize: 10000 random tests passed!\" << endl;\n    }\n\n    //\
    \ RollingHash group test\n    {\n        using RH = kk2::group::RollingHash<2>;\n\
    \        RH unit = RH::unit();\n\n        // \u4E71\u6570\u3092\u4F7F\u3063\u305F\
    \u8907\u6570\u56DE\u30C6\u30B9\u30C8\n        rep(10000) {\n            // \u30E9\
    \u30F3\u30C0\u30E0\u306A\u6574\u6570\u3067\u306E\u30C6\u30B9\u30C8\n         \
    \   int val1 = kk2::random::rng(1, 1001);\n            int val2 = kk2::random::rng(1,\
    \ 1001);\n            RH a(val1), b(val2);\n\n            assert(RH::op(unit,\
    \ a) == a);\n            assert(RH::op(a, unit) == a);\n\n            // \u9006\
    \u5143\u306E\u30C6\u30B9\u30C8\n            auto inv_a = RH::inv(a);\n       \
    \     auto cancel = RH::op(a, inv_a);\n            assert(cancel == unit);\n\n\
    \            // \u30E9\u30F3\u30C0\u30E0\u306A\u6587\u5B57\u5217\u3067\u306E\u30C6\
    \u30B9\u30C8\n            string s1, s2;\n            int len1 = kk2::random::rng(1,\
    \ 11);\n            int len2 = kk2::random::rng(1, 11);\n\n            rep(len1)\
    \ { s1 += char('a' + kk2::random::rng(0, 26)); }\n            rep(len2) { s2 +=\
    \ char('a' + kk2::random::rng(0, 26)); }\n\n            RH h1(s1), h2(s2);\n \
    \           RH h12 = RH::op(h1, h2); // s1 + s2\n            RH h_concat(s1 +\
    \ s2);\n            assert(h12.a == h_concat.a);\n\n            // \u9006\u5143\
    \u3067\u306E\u9023\u7D50\u30C6\u30B9\u30C8\n            auto inv_h2 = RH::inv(h2);\n\
    \            auto result = RH::op(h12, inv_h2);\n            assert(result.a ==\
    \ h1.a);\n\n            // \u7D50\u5408\u5F8B\u306E\u30C6\u30B9\u30C8\uFF083\u3064\
    \u306E\u6587\u5B57\u5217\uFF09\n            string s3;\n            int len3 =\
    \ kk2::random::rng(1, 11);\n            rep(len3) { s3 += char('a' + kk2::random::rng(0,\
    \ 26)); }\n            RH h3(s3);\n\n            RH h123_left = RH::op(RH::op(h1,\
    \ h2), h3);\n            RH h123_right = RH::op(h1, RH::op(h2, h3));\n       \
    \     RH h123_direct(s1 + s2 + s3);\n\n            assert(h123_left.a == h123_right.a);\n\
    \            assert(h123_left.a == h123_direct.a);\n        }\n\n        cerr\
    \ << \"RollingHash: 10000 random tests passed!\" << endl;\n    }\n}\n\nvoid test()\
    \ {\n    test_group();\n    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n  \
    \  cerr << \"All group tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - math/group/add.hpp
  - type_traits/io.hpp
  - math/group/rolling_hash.hpp
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - random/gen.hpp
  - math_mod/pow_mod.hpp
  - modint/modint_2_61m1.hpp
  - random/gen.hpp
  - type_traits/container_traits.hpp
  - math/group/sum_with_size.hpp
  - random/gen.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math/group/group.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:03:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/group/group.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/group/group.test.cpp
- /verify/verify/unit_test/math/group/group.test.cpp.html
title: verify/unit_test/math/group/group.test.cpp
---
