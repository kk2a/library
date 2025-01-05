---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/poly_find_root.hpp
    title: fps/poly_find_root.hpp
  - icon: ':x:'
    path: math/euler_phi.hpp
    title: math/euler_phi.hpp
  - icon: ':x:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':x:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':x:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  - icon: ':x:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':x:'
    path: verify/aoj/aoj_ntl_1_d.test.cpp
    title: verify/aoj/aoj_ntl_1_d.test.cpp
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
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\nu64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_RANDOM_SEED_HPP\n#define KK2_RANDOM_SEED_HPP 1\n\n#include <chrono>\n\
    \nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\n\
    u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n#endif // KK2_RANDOM_SEED_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: random/seed.hpp
  requiredBy:
  - random/graph.hpp
  - random/gen.hpp
  - random/hash.hpp
  - string/rolling_hash.hpp
  - math/prime_factorize.hpp
  - math/euler_phi.hpp
  - fps/poly_find_root.hpp
  - math_mod/primitive_root_64bit.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
documentation_of: random/seed.hpp
layout: document
redirect_from:
- /library/random/seed.hpp
- /library/random/seed.hpp.html
title: random/seed.hpp
---
