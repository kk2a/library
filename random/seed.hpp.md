---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/poly_find_root.hpp
    title: fps/poly_find_root.hpp
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':question:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':x:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
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
    path: verify/aoj/aoj_ntl_1_d.test.cpp
    title: verify/aoj/aoj_ntl_1_d.test.cpp
  - icon: ':x:'
    path: verify/unit_test/lpf_table_extend.test.cpp
    title: verify/unit_test/lpf_table_extend.test.cpp
  - icon: ':x:'
    path: verify/unit_test/prime_table_extend.test.cpp
    title: verify/unit_test/prime_table_extend.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/poly_root_finding.test.cpp
    title: verify/yosupo_fps/poly_root_finding.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/factrize.test.cpp
    title: verify/yosupo_math/factrize.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/primitive_root.test.cpp
    title: verify/yosupo_math/primitive_root.test.cpp
  - icon: ':x:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\ninline u64\
    \ non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return deterministic_seed();\n\
    #else\n    return non_deterministic_seed();\n#endif\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_RANDOM_SEED_HPP\n#define KK2_RANDOM_SEED_HPP 1\n\n#include <chrono>\n\
    \nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\n\
    inline u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return deterministic_seed();\n\
    #else\n    return non_deterministic_seed();\n#endif\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n#endif // KK2_RANDOM_SEED_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: random/seed.hpp
  requiredBy:
  - math/euler_phi.hpp
  - math/prime_factorize.hpp
  - fps/poly_find_root.hpp
  - math_mod/primitive_root_64bit.hpp
  - random/gen.hpp
  - random/graph.hpp
  - random/hash.hpp
  - string/rolling_hash.hpp
  timestamp: '2025-02-04 23:50:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/unit_test/lpf_table_extend.test.cpp
  - verify/unit_test/prime_table_extend.test.cpp
documentation_of: random/seed.hpp
layout: document
redirect_from:
- /library/random/seed.hpp
- /library/random/seed.hpp.html
title: random/seed.hpp
---
