---
data:
  _extendedDependsOn:
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
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
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
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../string/static_rolling_hash.hpp\"\n#include \"../../../random/gen.hpp\"\
    \n#include \"../../../template/template.hpp\"\nusing namespace std;\n\nvoid test_basic_and_edge_cases()\
    \ {\n    // Test basic constructor and get operations\n    string s = \"hello\"\
    ;\n    kk2::SRoliha rh(s);\n    assert(rh.size() == 5);\n    \n    // Test single\
    \ point get\n    auto h_first = rh.get(0);\n    auto h_second = rh.get(1);\n \
    \   assert(h_first != h_second); // 'h' != 'e'\n    assert(h_first == kk2::SRoliha::H('h'));\n\
    \    assert(h_second == kk2::SRoliha::H('e'));\n    \n    // Test empty range\n\
    \    auto h_empty = rh.get(2, 2);\n    assert(h_empty == kk2::SRoliha::H(0));\n\
    \    \n    // Test single character constructor\n    kk2::SRoliha rh_char(65);\
    \ // 'A'\n    assert(rh_char.size() == 1);\n    assert(rh_char.get(0) == kk2::SRoliha::H(65));\
    \ // single point get\n    \n    // Test vector constructor\n    vector<int> v\
    \ = {1, 2, 3, 4, 5};\n    kk2::SRoliha rh_vec(v);\n    assert(rh_vec.size() ==\
    \ 5);\n    assert(rh_vec.get(0) == kk2::SRoliha::H(1));\n    assert(rh_vec.get(4)\
    \ == kk2::SRoliha::H(5));\n    \n    // Test empty string\n    string empty =\
    \ \"\";\n    kk2::SRoliha rh_empty(empty);\n    assert(rh_empty.size() == 0);\n\
    \    \n    // Test default constructor\n    kk2::SRoliha rh_default;\n    assert(rh_default.size()\
    \ == 0);\n    \n    // Test empty vector\n    vector<int> empty_vec;\n    kk2::SRoliha\
    \ rh_empty_vec(empty_vec);\n    assert(rh_empty_vec.size() == 0);\n    \n    //\
    \ Test basic LCP\n    string s1 = \"abcdef\", s2 = \"abcxyz\";\n    kk2::SRoliha\
    \ rh1(s1), rh2(s2);\n    assert(kk2::SRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3);\
    \ // \"abc\" common prefix\n    \n    // Test LCP with empty ranges\n    assert(kk2::SRoliha::lcp(rh1,\
    \ 0, 0, rh2, 0, 0) == 0);\n    assert(kk2::SRoliha::lcp(rh1, 0, 3, rh2, 0, 0)\
    \ == 0);\n    assert(kk2::SRoliha::lcp(rh_empty, 0, 0, rh1, 0, 3) == 0);\n   \
    \ \n    // Test basic strcmp\n    string s3 = \"abc\", s4 = \"abd\";\n    kk2::SRoliha\
    \ rh3(s3), rh4(s4);\n    assert(kk2::SRoliha::strcmp(rh3, 0, 3, rh4, 0, 3) ==\
    \ -1); // abc < abd\n    \n    // Test strcmp edge cases\n    assert(kk2::SRoliha::strcmp(rh3,\
    \ 0, 0, rh4, 0, 0) == 0); // empty == empty\n    assert(kk2::SRoliha::strcmp(rh3,\
    \ 0, 0, rh4, 0, 3) == -1); // empty < non-empty\n    assert(kk2::SRoliha::strcmp(rh3,\
    \ 0, 3, rh4, 0, 0) == 1); // non-empty > empty\n    assert(kk2::SRoliha::strcmp(rh3,\
    \ 0, 3, rh3, 0, 3) == 0); // same == same\n    \n    // Test basic merge\n   \
    \ string s5 = \"hello\", s6 = \"world\", s7 = \"helloworld\";\n    kk2::SRoliha\
    \ rh5(s5), rh6(s6), rh7(s7);\n    auto merged = kk2::SRoliha::merge(rh5, rh6);\n\
    \    assert(merged.size() == 10);\n    assert(merged.get(0, 10) == rh7.get(0,\
    \ 10)); // merged hash equals direct construction\n    \n    // Test merge with\
    \ empty\n    auto merged_empty1 = kk2::SRoliha::merge(rh_empty, rh5);\n    assert(merged_empty1.size()\
    \ == 5);\n    assert(merged_empty1.get(0, 5) == rh5.get(0, 5));\n    \n    auto\
    \ merged_empty2 = kk2::SRoliha::merge(rh5, rh_empty);\n    assert(merged_empty2.size()\
    \ == 5);\n    assert(merged_empty2.get(0, 5) == rh5.get(0, 5));\n    \n    //\
    \ Test numerical sequence\n    vector<int> nums = {1, 2, 3, 2, 1};\n    kk2::SRoliha\
    \ rh_nums(nums);\n    assert(rh_nums.get(0) == rh_nums.get(4)); // single point\
    \ palindrome\n    assert(rh_nums.get(1) == rh_nums.get(3)); // single point palindrome\n\
    \    \n    // Test large values\n    vector<int> large_nums = {1000000, 999999,\
    \ 1000001};\n    kk2::SRoliha rh_large(large_nums);\n    assert(rh_large.size()\
    \ == 3);\n    assert(rh_large.get(0) == kk2::SRoliha::H(1000000));\n}\nvoid test_random_comprehensive()\
    \ {\n    // Test random strings with all operations\n    rep(2000) {\n       \
    \ int len1 = kk2::random::rng(1, 101);\n        int len2 = kk2::random::rng(1,\
    \ 101);\n        \n        string s1, s2;\n        rep(len1) s1 += char('a' +\
    \ kk2::random::rng(0, 26));\n        rep(len2) s2 += char('a' + kk2::random::rng(0,\
    \ 26));\n        \n        kk2::SRoliha rh1(s1);\n        kk2::SRoliha rh2(s2);\n\
    \        \n        assert(rh1.size() == len1);\n        assert(rh2.size() == len2);\n\
    \        \n        // Test single point get\n        if (len1 > 0) {\n       \
    \     int idx1 = kk2::random::rng(0, len1);\n            assert(rh1.get(idx1)\
    \ == kk2::SRoliha::H(s1[idx1]));\n        }\n        if (len2 > 0) {\n       \
    \     int idx2 = kk2::random::rng(0, len2);\n            assert(rh2.get(idx2)\
    \ == kk2::SRoliha::H(s2[idx2]));\n        }\n        \n        // Test substring\
    \ operations\n        int l1 = kk2::random::rng(0, len1);\n        int r1 = kk2::random::rng(l1,\
    \ len1 + 1);\n        int l2 = kk2::random::rng(0, len2);\n        int r2 = kk2::random::rng(l2,\
    \ len2 + 1);\n        \n        auto h1 = rh1.get(l1, r1);\n        \n       \
    \ // Verify substring hash consistency\n        if (l1 < r1) {\n            string\
    \ sub1 = s1.substr(l1, r1 - l1);\n            kk2::SRoliha rh_sub1(sub1);\n  \
    \          assert(h1 == rh_sub1.get(0, r1 - l1));\n        }\n        \n     \
    \   // Test LCP\n        int lcp_len = kk2::SRoliha::lcp(rh1, l1, r1, rh2, l2,\
    \ r2);\n        int expected_lcp = 0;\n        int min_len = min(r1 - l1, r2 -\
    \ l2);\n        for (int i = 0; i < min_len; i++) {\n            if (l1 + i <\
    \ len1 && l2 + i < len2 && s1[l1 + i] == s2[l2 + i]) {\n                expected_lcp++;\n\
    \            } else {\n                break;\n            }\n        }\n    \
    \    assert(lcp_len == expected_lcp);\n        \n        // Test strcmp\n    \
    \    int cmp_result = kk2::SRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);\n      \
    \  string sub1 = s1.substr(l1, r1 - l1);\n        string sub2 = s2.substr(l2,\
    \ r2 - l2);\n        int expected_cmp = (sub1 < sub2) ? -1 : (sub1 > sub2) ? 1\
    \ : 0;\n        assert(cmp_result == expected_cmp);\n        \n        // Test\
    \ hash collision detection\n        if (s1 == s2) {\n            assert(rh1.get(0,\
    \ len1) == rh2.get(0, len2));\n        } else if (len1 == len2) {\n          \
    \  assert(rh1.get(0, len1) != rh2.get(0, len2));\n        }\n    }\n}\nvoid test_random_merge()\
    \ {\n    // Test merge operation with random strings\n    rep(500) {\n       \
    \ int len1 = kk2::random::rng(1, 51);\n        int len2 = kk2::random::rng(1,\
    \ 51);\n        \n        string s1, s2;\n        rep(len1) s1 += char('a' + kk2::random::rng(0,\
    \ 26));\n        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));\n      \
    \  \n        kk2::SRoliha rh1(s1);\n        kk2::SRoliha rh2(s2);\n        \n\
    \        auto merged = kk2::SRoliha::merge(rh1, rh2);\n        assert(merged.size()\
    \ == len1 + len2);\n        \n        // Test that merged hash equals direct construction\n\
    \        string concatenated = s1 + s2;\n        kk2::SRoliha rh_direct(concatenated);\n\
    \        assert(merged.get(0, len1 + len2) == rh_direct.get(0, len1 + len2));\n\
    \        \n        // Test partial hashes\n        assert(merged.get(0, len1)\
    \ == rh1.get(0, len1));\n        assert(merged.get(len1, len1 + len2) == rh2.get(0,\
    \ len2));\n        \n        // Test single point get on merged\n        if (len1\
    \ + len2 > 0) {\n            int idx = kk2::random::rng(0, len1 + len2);\n   \
    \         assert(merged.get(idx) == rh_direct.get(idx));\n            assert(merged.get(idx)\
    \ == kk2::SRoliha::H(concatenated[idx]));\n        }\n        \n        // Test\
    \ random substrings of merged\n        rep(10) {\n            int l = kk2::random::rng(0,\
    \ len1 + len2);\n            int r = kk2::random::rng(l, len1 + len2 + 1);\n \
    \           \n            auto h_merged = merged.get(l, r);\n            auto\
    \ h_direct = rh_direct.get(l, r);\n            assert(h_merged == h_direct);\n\
    \        }\n    }\n}\n\n// Performance test configuration\nstruct PerformanceConfig\
    \ {\n    // Test sizes\n    static constexpr int LARGE_SIZE = 100000;\n    static\
    \ constexpr int MEDIUM_SIZE = 50000;\n    static constexpr int SMALL_SIZE = 10000;\n\
    \    \n    // Test iterations\n    static constexpr int MANY_QUERIES = 100000;\n\
    \    static constexpr int MEDIUM_QUERIES = 50000;\n    static constexpr int FEW_QUERIES\
    \ = 1000;\n    \n    // Hash collision test settings\n    static constexpr int\
    \ COLLISION_TEST_SIZE = 100000;\n    static constexpr int STRING_MAX_LENGTH =\
    \ 21;\n    \n    // Value ranges\n    static constexpr int ALPHABET_SIZE = 26;\n\
    \    static constexpr int LARGE_VALUE_RANGE = 1000000;\n};\n\nvoid test_performance()\
    \ {\n    // Large size performance test\n    cerr << \"Starting StaticRollingHash\
    \ performance tests...\" << endl;\n    cerr << \"Configuration:\" << endl;\n \
    \   cerr << \"  Large size: \" << PerformanceConfig::LARGE_SIZE << endl;\n   \
    \ cerr << \"  Medium size: \" << PerformanceConfig::MEDIUM_SIZE << endl;\n   \
    \ cerr << \"  Many queries: \" << PerformanceConfig::MANY_QUERIES << endl;\n \
    \   cerr << \"  Medium queries: \" << PerformanceConfig::MEDIUM_QUERIES << endl;\n\
    \    cerr << endl;\n    \n    // Test 1: Large string construction and substring\
    \ queries\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n        string\
    \ large_str;\n        large_str.reserve(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            large_str += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::SRoliha rh(large_str);\n        auto end = chrono::high_resolution_clock::now();\n\
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
    \ Large vector construction and queries\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        vector<int> large_vec;\n        large_vec.reserve(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));\n\
    \        }\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::SRoliha rh(large_vec);\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto construction_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << \"Vector construction time for \" << n <<\
    \ \" elements: \" << construction_time << \" microseconds\" << endl;\n       \
    \ \n        // Test many single point queries\n        start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {\n       \
    \     int idx = kk2::random::rng(0, n);\n            auto h = rh.get(idx);\n \
    \           (void)h;\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << PerformanceConfig::MANY_QUERIES << \" single\
    \ point queries time: \" << point_query_time << \" microseconds\" << endl;\n \
    \   }\n    \n    // Test 3: Many LCP operations\n    {\n        int n = PerformanceConfig::MEDIUM_SIZE;\n\
    \        string s1, s2;\n        s1.reserve(n);\n        s2.reserve(n);\n    \
    \    for (int i = 0; i < n; i++) {\n            s1 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n            s2 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n        }\n        \n        kk2::SRoliha\
    \ rh1(s1), rh2(s2);\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n     \
    \       int l1 = kk2::random::rng(0, n);\n            int r1 = kk2::random::rng(l1,\
    \ n + 1);\n            int l2 = kk2::random::rng(0, n);\n            int r2 =\
    \ kk2::random::rng(l2, n + 1);\n            int lcp_len = kk2::SRoliha::lcp(rh1,\
    \ l1, r1, rh2, l2, r2);\n            (void)lcp_len;\n        }\n        auto end\
    \ = chrono::high_resolution_clock::now();\n        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << PerformanceConfig::MEDIUM_QUERIES << \" LCP\
    \ operations time: \" << lcp_time << \" microseconds\" << endl;\n    }\n    \n\
    \    // Test 4: Many merge operations\n    {\n        int n = PerformanceConfig::SMALL_SIZE;\n\
    \        auto start = chrono::high_resolution_clock::now();\n        for (int\
    \ i = 0; i < PerformanceConfig::FEW_QUERIES; i++) {\n            int len1 = kk2::random::rng(1,\
    \ n / 100);\n            int len2 = kk2::random::rng(1, n / 100);\n          \
    \  \n            string s1, s2;\n            s1.reserve(len1);\n            s2.reserve(len2);\n\
    \            for (int j = 0; j < len1; j++) s1 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n            for (int j = 0; j < len2; j++)\
    \ s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n \
    \           \n            kk2::SRoliha rh1(s1), rh2(s2);\n            auto merged\
    \ = kk2::SRoliha::merge(rh1, rh2);\n            (void)merged;\n        }\n   \
    \     auto end = chrono::high_resolution_clock::now();\n        auto merge_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::FEW_QUERIES << \" merge operations time: \" << merge_time\
    \ << \" microseconds\" << endl;\n    }\n    \n    // Test 5: strcmp performance\n\
    \    {\n        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n\
    \        s1.reserve(n);\n        s2.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) {\n            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::SRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int cmp_result = kk2::SRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);\n\
    \            (void)cmp_result;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end -\
    \ start).count();\n        cerr << PerformanceConfig::MEDIUM_QUERIES << \" strcmp\
    \ operations time: \" << strcmp_time << \" microseconds\" << endl;\n    }\n  \
    \  \n    cerr << \"StaticRollingHash performance tests completed!\" << endl;\n\
    }\n\nvoid test() {\n    test_basic_and_edge_cases();\n    test_random_comprehensive();\n\
    \    test_random_merge();\n    test_performance();\n    \n    cerr << \"All tests\
    \ passed!\" << endl;\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n \
    \   kout << a + b << kendl;\n\n    test();\n\n    return 0;\n}\n"
  dependsOn:
  - string/static_rolling_hash.hpp
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
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
  path: verify/unit_test/string/static_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2025-07-08 15:03:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/static_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/static_rolling_hash.test.cpp
- /verify/verify/unit_test/string/static_rolling_hash.test.cpp.html
title: verify/unit_test/string/static_rolling_hash.test.cpp
---
