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
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':heavy_check_mark:'
    path: math/isprime_table.hpp
    title: math/isprime_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
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
    ../../../math/isprime_table.hpp\"\n#include \"../../../math/multiplicative_function/prime_counting.hpp\"\
    \n#include \"../../../math/is_prime.hpp\"\n#include \"../../../random/gen.hpp\"\
    \n#include \"../../../template/template.hpp\"\nusing namespace std;\n\nvoid test_basic_primality()\
    \ {\n    // Test small numbers\n    assert(!kk2::IsPrimeTable::isprime(1));\n\
    \    assert(kk2::IsPrimeTable::isprime(2));\n    assert(kk2::IsPrimeTable::isprime(3));\n\
    \    assert(!kk2::IsPrimeTable::isprime(4));\n    assert(kk2::IsPrimeTable::isprime(5));\n\
    \    assert(!kk2::IsPrimeTable::isprime(6));\n    assert(kk2::IsPrimeTable::isprime(7));\n\
    \    assert(!kk2::IsPrimeTable::isprime(8));\n    assert(!kk2::IsPrimeTable::isprime(9));\n\
    \    assert(!kk2::IsPrimeTable::isprime(10));\n    \n    // Test first 25 primes\n\
    \    vector<int> first_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,\
    \ 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};\n    for (int p : first_primes)\
    \ {\n        assert(kk2::IsPrimeTable::isprime(p));\n    }\n    \n    // Test\
    \ some composite numbers\n    vector<int> composites = {4, 6, 8, 9, 10, 12, 14,\
    \ 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30};\n    for (int c : composites)\
    \ {\n        assert(!kk2::IsPrimeTable::isprime(c));\n    }\n}\n\nvoid test_prime_generation()\
    \ {\n    // Test prime generation up to 100\n    auto primes_100 = kk2::IsPrimeTable::primes(100);\n\
    \    vector<int> expected_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,\
    \ 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};\n    assert(primes_100.size()\
    \ == expected_primes.size());\n    for (int i = 0; i < (int)expected_primes.size();\
    \ i++) {\n        assert(primes_100[i] == expected_primes[i]);\n    }\n    \n\
    \    // Test prime counting for various ranges\n    assert((int)kk2::IsPrimeTable::primes(10).size()\
    \ == 4);   // 2, 3, 5, 7\n    assert((int)kk2::IsPrimeTable::primes(20).size()\
    \ == 8);   // + 11, 13, 17, 19\n    assert((int)kk2::IsPrimeTable::primes(30).size()\
    \ == 10);  // + 23, 29\n    assert((int)kk2::IsPrimeTable::primes(50).size() ==\
    \ 15);  // + 31, 37, 41, 43, 47\n    assert((int)kk2::IsPrimeTable::primes(100).size()\
    \ == 25); // + 53, 59, 61, 67, 71, 73, 79, 83, 89, 97\n}\n\nvoid test_consistency_with_reference()\
    \ {\n    // Test consistency with reference is_prime function\n    for (int n\
    \ = 1; n <= 1000; n++) {\n        assert(kk2::is_prime(n) == kk2::IsPrimeTable::isprime(n));\n\
    \    }\n}\n\nvoid test_prime_counting_consistency() {\n    // Test prime counting\
    \ consistency\n    for (int n = 2; n <= 10000; n += 100) {\n        assert((int)kk2::IsPrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nvoid test_large_primes() {\n    //\
    \ Test some known large primes\n    vector<int> large_primes = {1009, 1013, 1019,\
    \ 1021, 1031, 1033, 1039, 1049, 1051, 1061,\n                               10007,\
    \ 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093,\n           \
    \                    100003, 100019, 100043, 100049, 100057, 100069, 100103, 100109,\
    \ 100129, 100151};\n    \n    for (int p : large_primes) {\n        assert(kk2::IsPrimeTable::isprime(p));\n\
    \        assert(kk2::is_prime(p)); // Double check with reference\n    }\n}\n\n\
    void test_large_composites() {\n    // Test some large composite numbers\n   \
    \ vector<pair<int, string>> large_composites = {\n        {1000, \"2^3 * 5^3\"\
    },\n        {10000, \"2^4 * 5^4\"},\n        {100000, \"2^5 * 5^5\"},\n      \
    \  {999999, \"3^3 * 7 * 11 * 13 * 37\"},\n        {1000000, \"2^6 * 5^6\"}\n \
    \   };\n    \n    for (auto [n, desc] : large_composites) {\n        assert(!kk2::IsPrimeTable::isprime(n));\n\
    \        assert(!kk2::is_prime(n)); // Double check with reference\n    }\n}\n\
    \nvoid test_random_numbers() {\n    // Test with random numbers\n    int iter\
    \ = 200;\n    rep (iter) {\n        int n = kk2::random::rng(1, 1000000);\n  \
    \      assert(kk2::is_prime(n) == kk2::IsPrimeTable::isprime(n));\n    }\n}\n\n\
    int main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\
    \n    test_basic_primality();\n    test_prime_generation();\n    test_consistency_with_reference();\n\
    \    test_prime_counting_consistency();\n    test_large_primes();\n    test_large_composites();\n\
    \    test_random_numbers();\n\n    return 0;\n}\n"
  dependsOn:
  - math/isprime_table.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/prime_table.hpp
  - math/is_prime.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
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
  path: verify/unit_test/math/isprime_table_extend.test.cpp
  requiredBy: []
  timestamp: '2025-07-10 13:49:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/isprime_table_extend.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/isprime_table_extend.test.cpp
- /verify/verify/unit_test/math/isprime_table_extend.test.cpp.html
title: verify/unit_test/math/isprime_table_extend.test.cpp
---
