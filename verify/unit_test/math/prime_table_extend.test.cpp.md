---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':heavy_check_mark:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  - icon: ':heavy_check_mark:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
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
    ../../../math/prime_table.hpp\"\n#include \"../../../math/multiplicative_function/prime_counting.hpp\"\
    \n#include \"../../../random/gen.hpp\"\n#include \"../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_basic_prime_generation() {\n    // Test prime\
    \ generation up to small limits\n    auto primes_10 = kk2::PrimeTable::primes(10);\n\
    \    vector<int> expected_10 = {2, 3, 5, 7};\n    assert(primes_10.size() == expected_10.size());\n\
    \    for (int i = 0; i < (int)expected_10.size(); i++) {\n        assert(primes_10[i]\
    \ == expected_10[i]);\n    }\n    \n    auto primes_20 = kk2::PrimeTable::primes(20);\n\
    \    vector<int> expected_20 = {2, 3, 5, 7, 11, 13, 17, 19};\n    assert(primes_20.size()\
    \ == expected_20.size());\n    for (int i = 0; i < (int)expected_20.size(); i++)\
    \ {\n        assert(primes_20[i] == expected_20[i]);\n    }\n    \n    auto primes_50\
    \ = kk2::PrimeTable::primes(50);\n    vector<int> expected_50 = {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};\n    assert(primes_50.size() == expected_50.size());\n\
    \    for (int i = 0; i < (int)expected_50.size(); i++) {\n        assert(primes_50[i]\
    \ == expected_50[i]);\n    }\n}\n\nvoid test_first_100_primes() {\n    // Test\
    \ first 100 primes up to 541\n    auto primes_541 = kk2::PrimeTable::primes(541);\n\
    \    vector<int> first_100_primes = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,\n        73, 79, 83, 89, 97, 101,\
    \ 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,\n    \
    \    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,\
    \ 263, 269, 271, 277, 281,\n        283, 293, 307, 311, 313, 317, 331, 337, 347,\
    \ 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,\n        419, 421, 431,\
    \ 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,\
    \ 541\n    };\n    \n    assert(primes_541.size() == 100);\n    for (int i = 0;\
    \ i < 100; i++) {\n        assert(primes_541[i] == first_100_primes[i]);\n   \
    \ }\n}\n\nvoid test_prime_counting_properties() {\n    // Test prime counting\
    \ for various ranges\n    assert((int)kk2::PrimeTable::primes(2).size() == 1);\
    \     // \u03C0(2) = 1\n    assert((int)kk2::PrimeTable::primes(3).size() == 2);\
    \     // \u03C0(3) = 2\n    assert((int)kk2::PrimeTable::primes(5).size() == 3);\
    \     // \u03C0(5) = 3\n    assert((int)kk2::PrimeTable::primes(7).size() == 4);\
    \     // \u03C0(7) = 4\n    assert((int)kk2::PrimeTable::primes(11).size() ==\
    \ 5);    // \u03C0(11) = 5\n    assert((int)kk2::PrimeTable::primes(100).size()\
    \ == 25);  // \u03C0(100) = 25\n    assert((int)kk2::PrimeTable::primes(1000).size()\
    \ == 168); // \u03C0(1000) = 168\n}\n\nvoid test_consistency_with_prime_counting()\
    \ {\n    // Test consistency with prime_counting function\n    for (int n = 2;\
    \ n <= 1000; n += 10) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n    \n    // Test some specific larger values\n\
    \    vector<int> test_values = {1000, 2000, 5000, 10000, 20000, 50000, 100000};\n\
    \    for (int n : test_values) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nvoid test_monotonicity() {\n    //\
    \ Test that prime count is monotonically non-decreasing\n    int prev_count =\
    \ 0;\n    for (int n = 2; n <= 1000; n++) {\n        int curr_count = (int)kk2::PrimeTable::primes(n).size();\n\
    \        assert(curr_count >= prev_count);\n        prev_count = curr_count;\n\
    \    }\n}\n\nvoid test_prime_properties() {\n    // Test that all returned numbers\
    \ are actually prime\n    auto primes_1000 = kk2::PrimeTable::primes(1000);\n\
    \    for (int i = 0; i < primes_1000.size(); i++) {\n        int p = primes_1000[i];\n\
    \        \n        // Check basic primality (simple trial division for verification)\n\
    \        bool is_prime = (p > 1);\n        if (p > 2 && p % 2 == 0) is_prime =\
    \ false;\n        for (int d = 3; d * d <= p && is_prime; d += 2) {\n        \
    \    if (p % d == 0) is_prime = false;\n        }\n        assert(is_prime);\n\
    \        \n        // Check ordering (primes should be in ascending order)\n \
    \       if (i > 0) {\n            assert(primes_1000[i] > primes_1000[i-1]);\n\
    \        }\n    }\n}\n\nvoid test_edge_cases() {\n    // Test edge cases\n   \
    \ auto primes_1 = kk2::PrimeTable::primes(1);\n    assert(primes_1.size() == 0);\
    \ // No primes \u2264 1\n    \n    auto primes_2 = kk2::PrimeTable::primes(2);\n\
    \    assert(primes_2.size() == 1 && primes_2[0] == 2);\n    \n    // Test twin\
    \ primes\n    auto primes_100 = kk2::PrimeTable::primes(100);\n    vector<pair<int,\
    \ int>> twin_primes = {{3, 5}, {5, 7}, {11, 13}, {17, 19}, {29, 31}, {41, 43},\
    \ {59, 61}, {71, 73}};\n    for (auto [p1, p2] : twin_primes) {\n        bool\
    \ found_p1 = false, found_p2 = false;\n        for (int i = 0; i < primes_100.size();\
    \ i++) {\n            if (primes_100[i] == p1) found_p1 = true;\n            if\
    \ (primes_100[i] == p2) found_p2 = true;\n        }\n        assert(found_p1 &&\
    \ found_p2);\n    }\n}\n\nvoid test_random_large_numbers() {\n    // Test with\
    \ larger random numbers\n    int iter = 100;\n    rep (iter) {\n        int n\
    \ = kk2::random::rng(2, 1000000);\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nint main() {\n    int a, b;\n    kin\
    \ >> a >> b;\n    kout << a + b << kendl;\n\n    test_basic_prime_generation();\n\
    \    test_first_100_primes();\n    test_prime_counting_properties();\n    test_consistency_with_prime_counting();\n\
    \    test_monotonicity();\n    test_prime_properties();\n    test_edge_cases();\n\
    \    test_random_large_numbers();\n\n    return 0;\n}\n"
  dependsOn:
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/prime_table.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math/prime_table_extend.test.cpp
  requiredBy: []
  timestamp: '2025-07-10 13:49:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/prime_table_extend.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/prime_table_extend.test.cpp
- /verify/verify/unit_test/math/prime_table_extend.test.cpp.html
title: verify/unit_test/math/prime_table_extend.test.cpp
---
