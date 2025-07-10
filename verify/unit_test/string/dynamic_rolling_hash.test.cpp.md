---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
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
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../string/dynamic_rolling_hash.hpp\"\n#include \"../../../random/gen.hpp\"\
    \n#include \"../../../template/template.hpp\"\n#include <chrono>\n#include <set>\n\
    using namespace std;\n\nvoid test_basic_and_edge_cases() {\n    // Test default\
    \ constructor\n    kk2::DRoliha rh_default;\n    assert(rh_default.size() == 0);\n\
    \    \n    // Test size constructor\n    kk2::DRoliha rh_size(5);\n    assert(rh_size.size()\
    \ == 5);\n    \n    // Test container constructor with string\n    string s =\
    \ \"hello\";\n    kk2::DRoliha rh_str(s);\n    assert(rh_str.size() == 5);\n \
    \   assert(rh_str.get(0) == kk2::DRoliha::H('h'));\n    assert(rh_str.get(4) ==\
    \ kk2::DRoliha::H('o'));\n    \n    // Test container constructor with vector\n\
    \    vector<int> v = {1, 2, 3, 4, 5};\n    kk2::DRoliha rh_vec(v);\n    assert(rh_vec.size()\
    \ == 5);\n    assert(rh_vec.get(0) == kk2::DRoliha::H(1));\n    assert(rh_vec.get(4)\
    \ == kk2::DRoliha::H(5));\n    \n    // Test empty container\n    string empty\
    \ = \"\";\n    kk2::DRoliha rh_empty(empty);\n    assert(rh_empty.size() == 0);\n\
    \    \n    // Test empty vector\n    vector<int> empty_vec;\n    kk2::DRoliha\
    \ rh_empty_vec(empty_vec);\n    assert(rh_empty_vec.size() == 0);\n    \n    //\
    \ Test range get operations\n    assert(rh_str.get(0, 5) == rh_str.all_prod());\n\
    \    assert(rh_str.get(1, 4) != rh_str.get(0, 3));\n    assert(rh_str.get(2, 2)\
    \ == kk2::DRoliha::H(0)); // empty range\n    \n    // Test single character operations\n\
    \    kk2::DRoliha rh_single(1);\n    rh_single.init_set(0, 'A');\n    rh_single.build();\n\
    \    assert(rh_single.size() == 1);\n    assert(rh_single.get(0) == kk2::DRoliha::H('A'));\n\
    \    assert(rh_single.get(0, 1) == rh_single.all_prod());\n}\n\nvoid test_init_set_and_build()\
    \ {\n    // Test init_set and build workflow\n    kk2::DRoliha rh(5);\n    \n\
    \    // Initialize with values\n    rh.init_set(0, 'a');\n    rh.init_set(1, 'b');\n\
    \    rh.init_set(2, 'c');\n    rh.init_set(3, 'd');\n    rh.init_set(4, 'e');\n\
    \    \n    // Build the hash\n    rh.build();\n    \n    // Verify values\n  \
    \  assert(rh.get(0) == kk2::DRoliha::H('a'));\n    assert(rh.get(1) == kk2::DRoliha::H('b'));\n\
    \    assert(rh.get(2) == kk2::DRoliha::H('c'));\n    assert(rh.get(3) == kk2::DRoliha::H('d'));\n\
    \    assert(rh.get(4) == kk2::DRoliha::H('e'));\n    \n    // Test range operations\n\
    \    string expected = \"abcde\";\n    kk2::DRoliha rh_expected(expected);\n \
    \   assert(rh.get(0, 5) == rh_expected.get(0, 5));\n    assert(rh.get(1, 4) ==\
    \ rh_expected.get(1, 4));\n    assert(rh.all_prod() == rh_expected.all_prod());\n\
    }\n\nvoid test_set_operations() {\n    // Test dynamic set operations\n    string\
    \ s = \"hello\";\n    kk2::DRoliha rh(s);\n    \n    // Change 'h' to 'H'\n  \
    \  rh.set(0, 'H');\n    assert(rh.get(0) == kk2::DRoliha::H('H'));\n    \n   \
    \ // Verify that the change affected range queries\n    string expected = \"Hello\"\
    ;\n    kk2::DRoliha rh_expected(expected);\n    assert(rh.get(0, 5) == rh_expected.get(0,\
    \ 5));\n    assert(rh.all_prod() == rh_expected.all_prod());\n    \n    // Change\
    \ multiple characters\n    rh.set(1, 'E'); // \"HEllo\"\n    rh.set(4, 'O'); //\
    \ \"HEllO\"\n    \n    assert(rh.get(1) == kk2::DRoliha::H('E'));\n    assert(rh.get(4)\
    \ == kk2::DRoliha::H('O'));\n    \n    string expected2 = \"HEllO\";\n    kk2::DRoliha\
    \ rh_expected2(expected2);\n    assert(rh.all_prod() == rh_expected2.all_prod());\n\
    }\n\nvoid test_lcp_and_strcmp() {\n    // Test LCP operations\n    string s1 =\
    \ \"abcdef\", s2 = \"abcxyz\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n   \
    \ assert(kk2::DRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3); // \"abc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 1, 6, rh2, 1, 6) == 2); // \"bc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 3) == 3); // \"abc\" == \"abc\"\
    \n    \n    // Test LCP with empty ranges\n    assert(kk2::DRoliha::lcp(rh1, 0,\
    \ 0, rh2, 0, 0) == 0);\n    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 0) ==\
    \ 0);\n    \n    // Test strcmp operations\n    string s3 = \"abc\", s4 = \"abd\"\
    ;\n    kk2::DRoliha rh3(s3), rh4(s4);\n    \n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh4, 0, 3) == -1); // abc < abd\n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh3, 0, 3) == 0);  // abc == abc\n    assert(kk2::DRoliha::strcmp(rh4,\
    \ 0, 3, rh3, 0, 3) == 1);  // abd > abc\n    \n    // Test strcmp edge cases\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 0) == 0); // empty == empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 3) == -1); // empty < non-empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh4, 0, 0) == 1); // non-empty > empty\n\
    }\n\nvoid test_merge_operations() {\n    // Test basic merge\n    string s1 =\
    \ \"hello\", s2 = \"world\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n    auto\
    \ merged = kk2::DRoliha::merge(rh1, rh2);\n    assert(merged.size() == 10);\n\
    \    \n    // Verify merged result\n    string expected = \"helloworld\";\n  \
    \  kk2::DRoliha rh_expected(expected);\n    assert(merged.all_prod() == rh_expected.all_prod());\n\
    \    assert(merged.get(0, 10) == rh_expected.get(0, 10));\n    \n    // Test partial\
    \ ranges\n    assert(merged.get(0, 5) == rh1.get(0, 5));\n    assert(merged.get(5,\
    \ 10) == rh2.get(0, 5));\n    \n    // Test merge with empty\n    kk2::DRoliha\
    \ rh_empty;\n    auto merged_empty1 = kk2::DRoliha::merge(rh_empty, rh1);\n  \
    \  assert(merged_empty1.size() == 5);\n    assert(merged_empty1.get(0, 5) == rh1.get(0,\
    \ 5));\n    \n    auto merged_empty2 = kk2::DRoliha::merge(rh1, rh_empty);\n \
    \   assert(merged_empty2.size() == 5);\n    assert(merged_empty2.get(0, 5) ==\
    \ rh1.get(0, 5));\n}\n\nvoid test_random_comprehensive() {\n    // Test random\
    \ operations with dynamic updates\n    rep(1000) {\n        int len = kk2::random::rng(1,\
    \ 51);\n        string s;\n        rep(len) s += char('a' + kk2::random::rng(0,\
    \ 26));\n        \n        kk2::DRoliha rh(s);\n        assert(rh.size() == len);\n\
    \        \n        // Test random single point get\n        int idx = kk2::random::rng(0,\
    \ len);\n        assert(rh.get(idx) == kk2::DRoliha::H(s[idx]));\n        \n \
    \       // Test random range get\n        int l = kk2::random::rng(0, len);\n\
    \        int r = kk2::random::rng(l, len + 1);\n        \n        if (l < r) {\n\
    \            string sub = s.substr(l, r - l);\n            kk2::DRoliha rh_sub(sub);\n\
    \            assert(rh.get(l, r) == rh_sub.get(0, r - l));\n        }\n      \
    \  \n        // Test random set operation\n        int pos = kk2::random::rng(0,\
    \ len);\n        char new_char = char('a' + kk2::random::rng(0, 26));\n      \
    \  rh.set(pos, new_char);\n        assert(rh.get(pos) == kk2::DRoliha::H(new_char));\n\
    \        \n        // Update original string and verify consistency\n        s[pos]\
    \ = new_char;\n        kk2::DRoliha rh_updated(s);\n        assert(rh.all_prod()\
    \ == rh_updated.all_prod());\n    }\n}\n\nvoid test_random_lcp_strcmp() {\n  \
    \  // Test LCP and strcmp with random strings\n    rep(300) {\n        int len1\
    \ = kk2::random::rng(1, 31);\n        int len2 = kk2::random::rng(1, 31);\n  \
    \      \n        string s1, s2;\n        rep(len1) s1 += char('a' + kk2::random::rng(0,\
    \ 26));\n        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));\n      \
    \  \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n        // Test LCP\n \
    \       int l1 = kk2::random::rng(0, len1);\n        int r1 = kk2::random::rng(l1,\
    \ len1 + 1);\n        int l2 = kk2::random::rng(0, len2);\n        int r2 = kk2::random::rng(l2,\
    \ len2 + 1);\n        \n        int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2,\
    \ l2, r2);\n        \n        // Verify LCP manually\n        int expected_lcp\
    \ = 0;\n        int min_len = min(r1 - l1, r2 - l2);\n        for (int i = 0;\
    \ i < min_len; i++) {\n            if (l1 + i < len1 && l2 + i < len2 && s1[l1\
    \ + i] == s2[l2 + i]) {\n                expected_lcp++;\n            } else {\n\
    \                break;\n            }\n        }\n        assert(lcp_len == expected_lcp);\n\
    \        \n        // Test strcmp\n        int cmp_result = kk2::DRoliha::strcmp(rh1,\
    \ l1, r1, rh2, l2, r2);\n        string sub1 = s1.substr(l1, r1 - l1);\n     \
    \   string sub2 = s2.substr(l2, r2 - l2);\n        int expected_cmp = (sub1 <\
    \ sub2) ? -1 : (sub1 > sub2) ? 1 : 0;\n        assert(cmp_result == expected_cmp);\n\
    \    }\n}\n\n// Performance test configuration\nstruct PerformanceConfig {\n \
    \   // Test sizes\n    static constexpr int LARGE_SIZE = 100000;\n    static constexpr\
    \ int MEDIUM_SIZE = 50000;\n    static constexpr int SMALL_SIZE = 10000;\n   \
    \ \n    // Test iterations\n    static constexpr int MANY_QUERIES = 100000;\n\
    \    static constexpr int MEDIUM_QUERIES = 50000;\n    static constexpr int FEW_QUERIES\
    \ = 1000;\n    \n    // Hash collision test settings\n    static constexpr int\
    \ COLLISION_TEST_SIZE = 50000;\n    static constexpr int STRING_MAX_LENGTH = 21;\n\
    \    static constexpr int DYNAMIC_UPDATE_COUNT = 10000;\n    \n    // Value ranges\n\
    \    static constexpr int ALPHABET_SIZE = 26;\n    static constexpr int LARGE_VALUE_RANGE\
    \ = 1000000;\n};\n\nvoid test_performance() {\n    // Large size performance test\
    \ for dynamic rolling hash\n    cerr << \"Starting DynamicRollingHash performance\
    \ tests...\" << endl;\n    cerr << \"Configuration:\" << endl;\n    cerr << \"\
    \  Large size: \" << PerformanceConfig::LARGE_SIZE << endl;\n    cerr << \"  Medium\
    \ size: \" << PerformanceConfig::MEDIUM_SIZE << endl;\n    cerr << \"  Many queries:\
    \ \" << PerformanceConfig::MANY_QUERIES << endl;\n    cerr << \"  Medium queries:\
    \ \" << PerformanceConfig::MEDIUM_QUERIES << endl;\n    cerr << endl;\n    \n\
    \    // Test 1: Large string construction and query performance\n    {\n     \
    \   int n = PerformanceConfig::LARGE_SIZE;\n        string large_str;\n      \
    \  large_str.reserve(n);\n        for (int i = 0; i < n; i++) {\n            large_str\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \    }\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(large_str);\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto construction_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << \"Construction time for \" << n << \" characters:\
    \ \" << construction_time << \" microseconds\" << endl;\n        \n        //\
    \ Test many substring queries\n        start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {\n       \
    \     int l = kk2::random::rng(0, n);\n            int r = kk2::random::rng(l,\
    \ n + 1);\n            auto h = rh.get(l, r);\n            (void)h; // suppress\
    \ unused variable warning\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" substring queries time:\
    \ \" << query_time << \" microseconds\" << endl;\n    }\n    \n    // Test 2:\
    \ Large size construction and set operations performance\n    {\n        int n\
    \ = PerformanceConfig::MEDIUM_SIZE;\n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(n);\n        \n        // Initialize with random values\n\
    \        for (int i = 0; i < n; i++) {\n            rh.init_set(i, kk2::random::rng(0,\
    \ PerformanceConfig::LARGE_VALUE_RANGE));\n        }\n        rh.build();\n  \
    \      auto end = chrono::high_resolution_clock::now();\n        auto init_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << \"Init_set and build time for \" << n << \" elements: \" << init_time\
    \ << \" microseconds\" << endl;\n        \n        // Test many set operations\n\
    \        start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MANY_QUERIES; i++) {\n            int idx = kk2::random::rng(0,\
    \ n);\n            int new_val = kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE);\n\
    \            rh.set(idx, new_val);\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto set_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" set operations time: \"\
    \ << set_time << \" microseconds\" << endl;\n    }\n    \n    // Test 3: Many\
    \ single point queries performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        vector<int> large_vec;\n        large_vec.reserve(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));\n\
    \        }\n        \n        kk2::DRoliha rh(large_vec);\n        \n        auto\
    \ start = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            int idx = kk2::random::rng(0, n);\n            auto h =\
    \ rh.get(idx);\n            (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << PerformanceConfig::MANY_QUERIES << \" single\
    \ point queries time: \" << point_query_time << \" microseconds\" << endl;\n \
    \   }\n    \n    // Test 4: LCP operations performance\n    {\n        int n =\
    \ PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n        s1.reserve(n);\n\
    \        s2.reserve(n);\n        for (int i = 0; i < n; i++) {\n            s1\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \        s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2, l2, r2);\n    \
    \        (void)lcp_len;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" LCP operations time:\
    \ \" << lcp_time << \" microseconds\" << endl;\n    }\n    \n    // Test 5: Merge\
    \ operations performance\n    {\n        int n = PerformanceConfig::SMALL_SIZE;\n\
    \        auto start = chrono::high_resolution_clock::now();\n        for (int\
    \ i = 0; i < PerformanceConfig::FEW_QUERIES; i++) {\n            int len1 = kk2::random::rng(1,\
    \ n / 100);\n            int len2 = kk2::random::rng(1, n / 100);\n          \
    \  \n            string s1, s2;\n            s1.reserve(len1);\n            s2.reserve(len2);\n\
    \            for (int j = 0; j < len1; j++) s1 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n            for (int j = 0; j < len2; j++)\
    \ s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n \
    \           \n            kk2::DRoliha rh1(s1), rh2(s2);\n            auto merged\
    \ = kk2::DRoliha::merge(rh1, rh2);\n            (void)merged;\n        }\n   \
    \     auto end = chrono::high_resolution_clock::now();\n        auto merge_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::FEW_QUERIES << \" merge operations time: \" << merge_time\
    \ << \" microseconds\" << endl;\n    }\n    \n    // Test 6: strcmp performance\n\
    \    {\n        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n\
    \        s1.reserve(n);\n        s2.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) {\n            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int cmp_result = kk2::DRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);\n\
    \            (void)cmp_result;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end -\
    \ start).count();\n        cerr << PerformanceConfig::MEDIUM_QUERIES << \" strcmp\
    \ operations time: \" << strcmp_time << \" microseconds\" << endl;\n    }\n  \
    \  \n    // Test 7: Dynamic update performance with mixed operations\n    {\n\
    \        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s;\n        s.reserve(n);\n\
    \        for (int i = 0; i < n; i++) {\n            s += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n        }\n        \n        kk2::DRoliha\
    \ rh(s);\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n     \
    \       // Random set operation\n            int pos = kk2::random::rng(0, n);\n\
    \            char new_char = char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            rh.set(pos, new_char);\n            \n            // Random query\
    \ operation\n            int l = kk2::random::rng(0, n);\n            int r =\
    \ kk2::random::rng(l, n + 1);\n            auto h = rh.get(l, r);\n          \
    \  (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto mixed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" mixed set+query operations\
    \ time: \" << mixed_time << \" microseconds\" << endl;\n    }\n    \n    // Test\
    \ 9: all_prod() performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        string s;\n        s.reserve(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            s += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh(s);\n        \n        auto start\
    \ = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            auto h = rh.all_prod();\n            (void)h;\n        }\n\
    \        auto end = chrono::high_resolution_clock::now();\n        auto all_prod_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::MANY_QUERIES << \" all_prod() operations time: \"\
    \ << all_prod_time << \" microseconds\" << endl;\n    }\n    \n    cerr << \"\
    DynamicRollingHash performance tests completed!\" << endl;\n}\n\nvoid test() {\n\
    \    test_basic_and_edge_cases();\n    test_init_set_and_build();\n    test_set_operations();\n\
    \    test_lcp_and_strcmp();\n    test_merge_operations();\n    test_random_comprehensive();\n\
    \    test_random_lcp_strcmp();\n    test_performance();\n    \n    cerr << \"\
    All DynamicRollingHash tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - string/dynamic_rolling_hash.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - random/gen.hpp
  - math_mod/pow_mod.hpp
  - modint/modint_2_61m1.hpp
  - random/gen.hpp
  - type_traits/container_traits.hpp
  - random/gen.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:03:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/dynamic_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp.html
title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
---
