---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':warning:'
    path: random/seed.hpp
    title: random/seed.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/graph.hpp\"\n\n\n\n#line 1 \"random/gen.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <cassert>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\nu64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 10 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\nu64 xorshift128plus(u64 &x, u64 &y) {\n    u64 t =\
    \ x;\n    t ^= t << 23;\n    t ^= t >> 17;\n    t ^= y ^ (y >> 26);\n    x = y;\n\
    \    y = t;\n    return x + y;\n}\n\nvoid warm_up(u64 &x, u64 &y) {\n    for (int\
    \ i = 0; i < 10; i++) xorshift128plus(x, y);\n}\n\nu64 rng() {\n    static bool\
    \ first = true;\n    static u64 x = seed(), y = seed();\n    if (first) {\n  \
    \      warm_up(x, y);\n        first = false;\n    }\n    return xorshift128plus(x,\
    \ y);\n}\n\n// [l, r)\ni64 rng(i64 l, i64 r) {\n    assert(l < r);\n    return\
    \ l + rng() % (r - l);\n}\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64\
    \ r, i64 n) {\n    assert(l < r and n <= r - l);\n    std::unordered_set<i64>\
    \ st;\n    for (i64 i = n; i; --i) {\n        i64 m = rng(l, r + 1 - i);\n   \
    \     if (st.find(m) != st.end()) m = r - i;\n        st.insert(m);\n    }\n \
    \   std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(), res.end());\n\
    \    return res;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line\
    \ 5 \"random/graph.hpp\"\n\nnamespace kk2 {\n\nnamespace random {\n\n\n} // namespace\
    \ random\n\n} // namespace kk2\n\n\n"
  code: '#ifndef RANDOM_GRAPH_HPP

    #define RANDOM_GRAPH_HPP 1


    #include "gen.hpp"


    namespace kk2 {


    namespace random {



    } // namespace random


    } // namespace kk2


    #endif // RANDOM_GRAPH_HPP

    '
  dependsOn:
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: random/graph.hpp
  requiredBy: []
  timestamp: '2024-09-21 15:57:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
redirect_from:
- /library/random/graph.hpp
- /library/random/graph.hpp.html
title: random/graph.hpp
---
