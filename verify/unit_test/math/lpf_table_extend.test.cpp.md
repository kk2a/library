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
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
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
    ../../../math/lpf_table.hpp\"\n#include \"../../../math/multiplicative_function/prime_counting.hpp\"\
    \n#include \"../../../math/prime_factorize.hpp\"\n#include \"../../../random/gen.hpp\"\
    \n#include \"../../../template/template.hpp\"\nusing namespace std;\n\nvoid test_basic_functionality()\
    \ {\n    // Test small primes\n    assert(kk2::LPFTable::lpf(2) == 2);\n    assert(kk2::LPFTable::lpf(3)\
    \ == 3);\n    assert(kk2::LPFTable::lpf(4) == 2);\n    assert(kk2::LPFTable::lpf(5)\
    \ == 5);\n    assert(kk2::LPFTable::lpf(6) == 2);\n    assert(kk2::LPFTable::lpf(7)\
    \ == 7);\n    assert(kk2::LPFTable::lpf(8) == 2);\n    assert(kk2::LPFTable::lpf(9)\
    \ == 3);\n    assert(kk2::LPFTable::lpf(10) == 2);\n    \n    // Test isprime\n\
    \    assert(kk2::LPFTable::isprime(2));\n    assert(kk2::LPFTable::isprime(3));\n\
    \    assert(!kk2::LPFTable::isprime(4));\n    assert(kk2::LPFTable::isprime(5));\n\
    \    assert(!kk2::LPFTable::isprime(6));\n    assert(kk2::LPFTable::isprime(7));\n\
    \    assert(!kk2::LPFTable::isprime(8));\n    assert(!kk2::LPFTable::isprime(9));\n\
    \    assert(!kk2::LPFTable::isprime(10));\n    assert(!kk2::LPFTable::isprime(1));\n\
    \    \n    // Test lpf_pow\n    assert(kk2::LPFTable::lpf_pow(2) == 2);\n    assert(kk2::LPFTable::lpf_pow(3)\
    \ == 3);\n    assert(kk2::LPFTable::lpf_pow(4) == 4);  // 2^2\n    assert(kk2::LPFTable::lpf_pow(5)\
    \ == 5);\n    assert(kk2::LPFTable::lpf_pow(6) == 2);  // 2*3\n    assert(kk2::LPFTable::lpf_pow(7)\
    \ == 7);\n    assert(kk2::LPFTable::lpf_pow(8) == 8);  // 2^3\n    assert(kk2::LPFTable::lpf_pow(9)\
    \ == 9);  // 3^2\n    assert(kk2::LPFTable::lpf_pow(12) == 4); // 2^2*3\n    assert(kk2::LPFTable::lpf_pow(16)\
    \ == 16); // 2^4\n    assert(kk2::LPFTable::lpf_pow(18) == 2);  // 2*3^2\n   \
    \ assert(kk2::LPFTable::lpf_pow(27) == 27); // 3^3\n    \n    // Test v_lpf\n\
    \    assert(kk2::LPFTable::v_lpf(2) == 1);\n    assert(kk2::LPFTable::v_lpf(3)\
    \ == 1);\n    assert(kk2::LPFTable::v_lpf(4) == 2);  // 2^2\n    assert(kk2::LPFTable::v_lpf(5)\
    \ == 1);\n    assert(kk2::LPFTable::v_lpf(6) == 1);  // 2*3\n    assert(kk2::LPFTable::v_lpf(7)\
    \ == 1);\n    assert(kk2::LPFTable::v_lpf(8) == 3);  // 2^3\n    assert(kk2::LPFTable::v_lpf(9)\
    \ == 2);  // 3^2\n    assert(kk2::LPFTable::v_lpf(12) == 2); // 2^2*3\n    assert(kk2::LPFTable::v_lpf(16)\
    \ == 4); // 2^4\n    assert(kk2::LPFTable::v_lpf(18) == 1); // 2*3^2\n    assert(kk2::LPFTable::v_lpf(27)\
    \ == 3); // 3^3\n}\n\nvoid test_prime_generation() {\n    // Test prime generation\
    \ up to 100\n    auto primes_100 = kk2::LPFTable::primes(100);\n    vector<int>\
    \ expected_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,\
    \ 59, 61, 67, 71, 73, 79, 83, 89, 97};\n    assert(primes_100.size() == (int)expected_primes.size());\n\
    \    for (int i = 0; i < (int)expected_primes.size(); i++) {\n        assert(primes_100[i]\
    \ == expected_primes[i]);\n    }\n    \n    // Test prime counting consistency\n\
    \    assert((int)kk2::LPFTable::primes(10).size() == 4);  // 2, 3, 5, 7\n    assert((int)kk2::LPFTable::primes(20).size()\
    \ == 8);  // 2, 3, 5, 7, 11, 13, 17, 19\n    assert((int)kk2::LPFTable::primes(30).size()\
    \ == 10); // + 23, 29\n}\n\nvoid test_factorization_consistency() {\n    // Test\
    \ consistency with prime factorization\n    for (int n = 2; n <= 1000; n++) {\n\
    \        auto factors = kk2::factorize(n);\n        assert(kk2::LPFTable::lpf(n)\
    \ == factors[0].first);\n        \n        // Check if lpf_pow and v_lpf are consistent\n\
    \        int expected_lpf_pow = 1;\n        int expected_v_lpf = 0;\n        for\
    \ (auto [p, e] : factors) {\n            if (p == kk2::LPFTable::lpf(n)) {\n \
    \               expected_v_lpf = e;\n                for (int i = 0; i < e; i++)\
    \ {\n                    expected_lpf_pow *= p;\n                }\n         \
    \       break;\n            }\n        }\n        assert(kk2::LPFTable::lpf_pow(n)\
    \ == expected_lpf_pow);\n        assert(kk2::LPFTable::v_lpf(n) == expected_v_lpf);\n\
    \    }\n}\n\nvoid test_large_numbers() {\n    // Test with larger numbers\n  \
    \  int iter = 200;\n    rep (iter) {\n        int n = kk2::random::rng(2, 1000000);\n\
    \        assert((int)kk2::LPFTable::primes(n).size() == kk2::prime_counting(n));\n\
    \        assert(kk2::LPFTable::lpf(n) == kk2::factorize(n)[0].first);\n      \
    \  \n        // Additional consistency checks\n        auto factors = kk2::factorize(n);\n\
    \        int lpf = kk2::LPFTable::lpf(n);\n        int v_lpf = kk2::LPFTable::v_lpf(n);\n\
    \        int lpf_pow = kk2::LPFTable::lpf_pow(n);\n        \n        // Check\
    \ v_lpf\n        int expected_v = 0;\n        for (auto [p, e] : factors) {\n\
    \            if (p == lpf) {\n                expected_v = e;\n              \
    \  break;\n            }\n        }\n        assert(v_lpf == expected_v);\n  \
    \      \n        // Check lpf_pow\n        int expected_pow = 1;\n        for\
    \ (int i = 0; i < v_lpf; i++) {\n            expected_pow *= lpf;\n        }\n\
    \        assert(lpf_pow == expected_pow);\n        \n        // Check that n is\
    \ divisible by lpf_pow\n        assert(n % lpf_pow == 0);\n        \n        //\
    \ Check that n/lpf_pow is not divisible by lpf\n        if (n / lpf_pow > 1) {\n\
    \            assert((n / lpf_pow) % lpf != 0);\n        }\n    }\n}\n\nvoid test_edge_cases()\
    \ {\n    // Test perfect powers\n    assert(kk2::LPFTable::lpf_pow(32) == 32);\
    \  // 2^5\n    assert(kk2::LPFTable::v_lpf(32) == 5);\n    \n    assert(kk2::LPFTable::lpf_pow(243)\
    \ == 243); // 3^5\n    assert(kk2::LPFTable::v_lpf(243) == 5);\n    \n    // Test\
    \ products of different primes\n    assert(kk2::LPFTable::lpf_pow(30) == 2); \
    \   // 2*3*5\n    assert(kk2::LPFTable::v_lpf(30) == 1);\n    \n    assert(kk2::LPFTable::lpf_pow(210)\
    \ == 2);   // 2*3*5*7\n    assert(kk2::LPFTable::v_lpf(210) == 1);\n    \n   \
    \ // Test large primes\n    int large_prime = 1000003;\n    assert(kk2::LPFTable::isprime(large_prime));\n\
    \    assert(kk2::LPFTable::lpf(large_prime) == large_prime);\n    assert(kk2::LPFTable::lpf_pow(large_prime)\
    \ == large_prime);\n    assert(kk2::LPFTable::v_lpf(large_prime) == 1);\n}\n\n\
    int main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\
    \n    test_basic_functionality();\n    test_prime_generation();\n    test_factorization_consistency();\n\
    \    test_large_numbers();\n    test_edge_cases();\n\n    return 0;\n}\n"
  dependsOn:
  - math/lpf_table.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/prime_table.hpp
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
  path: verify/unit_test/math/lpf_table_extend.test.cpp
  requiredBy: []
  timestamp: '2025-07-10 13:49:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/lpf_table_extend.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/lpf_table_extend.test.cpp
- /verify/verify/unit_test/math/lpf_table_extend.test.cpp.html
title: verify/unit_test/math/lpf_table_extend.test.cpp
---
