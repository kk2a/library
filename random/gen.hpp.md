---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: seed.hpp
      icon: LIBRARY_ALL_AC
      path: random/seed.hpp
    type: Depends on
  - files:
    - filename: poly_find_root.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_find_root.hpp
    - filename: rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/rolling_hash.hpp
    - filename: euler_phi.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/euler_phi.hpp
    - filename: mobius.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/mobius.hpp
    - filename: sigma.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/sigma.hpp
    - filename: prime_factorize.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_factorize.hpp
    - filename: primitive_root_64bit.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root_64bit.hpp
    - filename: tetration.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/tetration.hpp
    - filename: graph.hpp
      icon: LIBRARY_NO_TESTS
      path: random/graph.hpp
    - filename: hash.hpp
      icon: LIBRARY_ALL_AC
      path: random/hash.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
    - filename: static_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/static_rolling_hash.hpp
    - filename: parallel.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/parallel.hpp
    - filename: aoj_alds1_14_b.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    type: Required by
  - files:
    - filename: aoj_ntl_1_d.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_d.test.cpp
    - filename: bit_vector.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/bit_vector.test.cpp
    - filename: offline_dynamic_connectivity.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
    - filename: wavelet_matrix.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
    - filename: action.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/action/action.test.cpp
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: monoid.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/monoid/monoid.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    - filename: prime_factorize_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_factorize_table.test.cpp
    - filename: prime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_table_extend.test.cpp
    - filename: rational.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/rational.test.cpp
    - filename: binom_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/binom_table.test.cpp
    - filename: inv_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/inv_table.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: partial_persitent_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: poly_root_finding.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_root_finding.test.cpp
    - filename: factrize.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/factrize.test.cpp
    - filename: primitive_root.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primitive_root.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    type: Verified with
  dependsOn:
  - random/seed.hpp
  embedded:
  - code: "#ifndef KK2_RANDOM_GEN_HPP\n#define KK2_RANDOM_GEN_HPP 1\n\n#include <algorithm>\n\
      #include <cassert>\n#include <numeric>\n#include <random>\n#include <unordered_set>\n\
      #include <vector>\n\n#include \"seed.hpp\"\n\nnamespace kk2 {\n\nnamespace random\
      \ {\n\nusing i64 = long long;\nusing u64 = unsigned long long;\n\ninline u64\
      \ rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n    return mt();\n\
      }\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l < r);\n    return\
      \ l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T> random_vector(int\
      \ n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i = 0; i < n; i++)\
      \ res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64\
      \ l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n    std::unordered_set<i64>\
      \ st;\n    for (i64 i = n; i; --i) {\n        i64 m = rng(l, r + 1 - i);\n \
      \       if (st.find(m) != st.end()) m = r - i;\n        st.insert(m);\n    }\n\
      \    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
      \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter\
      \ first, Iter last) {\n    if (first == last) return;\n    int len = 1;\n  \
      \  for (auto it = first + 1; it != last; ++it) {\n        len++;\n        int\
      \ j = rng(0, len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n\
      \    }\n}\n\ntemplate <class T> std::vector<T> perm(int n) {\n    std::vector<T>\
      \ res(n);\n    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(),\
      \ res.end());\n    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int\
      \ l, int r, int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T>\
      \ res(r - l);\n    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(),\
      \ res.end());\n    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\
      \n} // namespace kk2\n\n#endif // KK2_RANDOM_GEN_HPP\n"
    name: default
  - code: "#line 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <numeric>\n#include <random>\n#include <unordered_set>\n#include <vector>\n\
      \n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\n\
      namespace random {\n\nusing u64 = unsigned long long;\n\ninline u64 non_deterministic_seed()\
      \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
      \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
      \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n \
      \   seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n \
      \   return seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
      \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
      \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
      }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
      \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
      \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
      \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T>\
      \ std::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n\
      \    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n\
      // [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
      \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n;\
      \ i; --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
      \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
      \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\n\
      template <class Iter> void shuffle(Iter first, Iter last) {\n    if (first ==\
      \ last) return;\n    int len = 1;\n    for (auto it = first + 1; it != last;\
      \ ++it) {\n        len++;\n        int j = rng(0, len);\n        if (j != len\
      \ - 1) std::iter_swap(first + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T>\
      \ perm(int n) {\n    std::vector<T> res(n);\n    std::iota(res.begin(), res.end(),\
      \ T(0));\n    shuffle(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
      \ <class T> std::vector<T> choices(int l, int r, int k) {\n    assert(l < r\
      \ and k <= r - l);\n    std::vector<T> res(r - l);\n    std::iota(res.begin(),\
      \ res.end(), T(l));\n    shuffle(res.begin(), res.end());\n    res.resize(k);\n\
      \    return res;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: random/gen.hpp
  pathExtension: hpp
  requiredBy:
  - fps/poly_find_root.hpp
  - math/group/rolling_hash.hpp
  - math/multiplicative_function/euler_phi.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/sigma.hpp
  - math/prime_factorize.hpp
  - math_mod/primitive_root_64bit.hpp
  - math_mod/tetration.hpp
  - random/graph.hpp
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - unionfind/parallel.hpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/unit_test/data_structure/bit_vector.test.cpp
  - verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
  - verify/unit_test/math/action/action.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/unit_test/math/prime_factorize_table.test.cpp
  - verify/unit_test/math/prime_table_extend.test.cpp
  - verify/unit_test/math/rational.test.cpp
  - verify/unit_test/math_mod/binom_table.test.cpp
  - verify/unit_test/math_mod/inv_table.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
documentation_of: random/gen.hpp
layout: document
---
