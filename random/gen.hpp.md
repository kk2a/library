---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/poly_find_root.hpp
    title: fps/poly_find_root.hpp
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  - icon: ':question:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':question:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/bit_vector.test.cpp
    title: verify/unit_test/bit_vector.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/multiplicative_function_table.test.cpp
    title: verify/unit_test/multiplicative_function_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/offline_dynamic_connectivity.test.cpp
    title: verify/unit_test/offline_dynamic_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/partial_persitent_unionfind.test.cpp
    title: verify/unit_test/partial_persitent_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/prime_table_extend.test.cpp
    title: verify/unit_test/prime_table_extend.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/wavelet_matrix.test.cpp
    title: verify/unit_test/wavelet_matrix.test.cpp
  - icon: ':x:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <numeric>\n#include <random>\n#include <unordered_set>\n#include <vector>\n\
    \n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\n\
    namespace random {\n\nusing u64 = unsigned long long;\n\ninline u64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
    \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
    \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
    }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
    \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
    \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T>\
    \ random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64>\
    \ distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n   \
    \ std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n        i64 m =\
    \ rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r - i;\n       \
    \ st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first,\
    \ Iter last) {\n    if (first == last) return;\n    int len = 1;\n    for (auto\
    \ it = first + 1; it != last; ++it) {\n        len++;\n        int j = rng(0,\
    \ len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\n\
    template <class T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int l, int r,\
    \ int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r - l);\n\
    \    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(), res.end());\n\
    \    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_RANDOM_GEN_HPP\n#define KK2_RANDOM_GEN_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <numeric>\n#include <random>\n#include <unordered_set>\n\
    #include <vector>\n\n#include \"seed.hpp\"\n\nnamespace kk2 {\n\nnamespace random\
    \ {\n\nusing i64 = long long;\nusing u64 = unsigned long long;\n\ninline u64 rng()\
    \ {\n    static std::mt19937_64 mt(kk2::random::seed());\n    return mt();\n}\n\
    \n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l < r);\n    return l\
    \ + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T> random_vector(int\
    \ n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i = 0; i < n; i++)\
    \ res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64\
    \ l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n    std::unordered_set<i64>\
    \ st;\n    for (i64 i = n; i; --i) {\n        i64 m = rng(l, r + 1 - i);\n   \
    \     if (st.find(m) != st.end()) m = r - i;\n        st.insert(m);\n    }\n \
    \   std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first, Iter last)\
    \ {\n    if (first == last) return;\n    int len = 1;\n    for (auto it = first\
    \ + 1; it != last; ++it) {\n        len++;\n        int j = rng(0, len);\n   \
    \     if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\ntemplate <class\
    \ T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n    std::iota(res.begin(),\
    \ res.end(), T(0));\n    shuffle(res.begin(), res.end());\n    return res;\n}\n\
    \ntemplate <class T> std::vector<T> choices(int l, int r, int k) {\n    assert(l\
    \ < r and k <= r - l);\n    std::vector<T> res(r - l);\n    std::iota(res.begin(),\
    \ res.end(), T(l));\n    shuffle(res.begin(), res.end());\n    res.resize(k);\n\
    \    return res;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n#endif //\
    \ KK2_RANDOM_GEN_HPP\n"
  dependsOn:
  - random/seed.hpp
  isVerificationFile: false
  path: random/gen.hpp
  requiredBy:
  - string/rolling_hash.hpp
  - random/graph.hpp
  - random/hash.hpp
  - fps/poly_find_root.hpp
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/prime_table_extend.test.cpp
  - verify/unit_test/monoid.test.cpp
  - verify/unit_test/multiplicative_function_table.test.cpp
  - verify/unit_test/bit_vector.test.cpp
  - verify/unit_test/partial_persitent_unionfind.test.cpp
  - verify/unit_test/offline_dynamic_connectivity.test.cpp
  - verify/unit_test/wavelet_matrix.test.cpp
documentation_of: random/gen.hpp
layout: document
redirect_from:
- /library/random/gen.hpp
- /library/random/gen.hpp.html
title: random/gen.hpp
---
