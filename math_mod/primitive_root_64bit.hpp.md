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
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: unionfind/parallel.hpp
    title: unionfind/parallel.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/group/group.test.cpp
    title: verify/unit_test/math/group/group.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/static_rolling_hash.test.cpp
    title: verify/unit_test/string/static_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    title: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/primitive_root.test.cpp
    title: verify/yosupo_math/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
  code: "#ifndef KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n#define KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\
    \ 1\n\n#include \"../math/prime_factorize.hpp\"\n#include \"../random/gen.hpp\"\
    \n#include \"pow_mod.hpp\"\n\nnamespace kk2 {\n\nlong long primitive_root_64bit(long\
    \ long p) {\n    if (p == 2) return 1;\n    if (p == 3) return 2;\n\n    auto\
    \ f = factorize(p - 1);\n    for (long long g{}; g = random::rng(2, p - 1), 1;)\
    \ {\n        if ([&]() {\n                for (auto &&[q, e] : f)\n          \
    \          if (pow_mod<__int128_t>(g, (p - 1) / q, p) == 1) return false;\n  \
    \              return true;\n            }())\n            return g;\n    }\n\
    \    return -1;\n}\n\ntemplate <class mint> long long primitive_root_mint() {\n\
    \    if (mint::getmod() == 2u) return 1;\n    if (mint::getmod() == 3u) return\
    \ 2;\n\n    long long p = mint::getmod();\n\n    auto f = factorize(p - 1);\n\
    \    for (mint g; g = random::rng(2, p - 1), 1;) {\n        if ([&]() {\n    \
    \            for (auto &&[q, e] : f)\n                    if (g.pow((p - 1) /\
    \ q) == mint(1)) return false;\n                return true;\n            }())\n\
    \            return g.val();\n    }\n    return -1;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n"
  dependsOn:
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
  isVerificationFile: false
  path: math_mod/primitive_root_64bit.hpp
  requiredBy:
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - unionfind/parallel.hpp
  - math/group/rolling_hash.hpp
  timestamp: '2025-06-06 16:34:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
documentation_of: math_mod/primitive_root_64bit.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_root_64bit.hpp
- /library/math_mod/primitive_root_64bit.hpp.html
title: math_mod/primitive_root_64bit.hpp
---
