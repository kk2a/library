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
  - icon: ':warning:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/monoid.test.cpp
    title: verify/unit_test/monoid.test.cpp
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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_RANDOM_HASH_HPP\n#define KK2_RANDOM_HASH_HPP 1\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n\n#include \"../math_mod/primitive_root_64bit.hpp\"\
    \n#include \"../modint/modint_2_61m1.hpp\"\n#include \"gen.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\ntemplate <int NUM> struct Hash : std::array<ModInt2_61m1,\
    \ NUM> {\n    using mint = ModInt2_61m1;\n    using std::array<mint, NUM>::operator[];\n\
    \    using u64 = unsigned long long;\n\n    Hash() : std::array<mint, NUM>() {}\n\
    \n    template <class T, is_integral_t<T> * = nullptr> Hash(T x) {\n        std::fill(this->begin(),\
    \ this->end(), mint(x));\n    }\n\n    static Hash get_base() {\n        Hash\
    \ base;\n        for (int i = 0; i < NUM; i++) base[i] = primitive_root_mint<ModInt2_61m1>();\n\
    \        return base;\n    }\n\n    Hash &operator+=(const Hash &rhs) {\n    \
    \    for (int i = 0; i < NUM; i++) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n    Hash &operator-=(const Hash &rhs) {\n        for (int i = 0; i < NUM;\
    \ i++) (*this)[i] -= rhs[i];\n        return *this;\n    }\n    Hash &operator*=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < NUM; i++) (*this)[i] *= rhs[i];\n\
    \        return *this;\n    }\n    Hash &operator/=(const Hash &rhs) {\n     \
    \   for (int i = 0; i < NUM; i++) (*this)[i] /= rhs[i];\n        return *this;\n\
    \    }\n\n    Hash operator+(const Hash &rhs) const { return Hash(*this) += rhs;\
    \ }\n    Hash operator-(const Hash &rhs) const { return Hash(*this) -= rhs; }\n\
    \    Hash operator*(const Hash &rhs) const { return Hash(*this) *= rhs; }\n  \
    \  Hash operator/(const Hash &rhs) const { return Hash(*this) /= rhs; }\n    Hash\
    \ operator+() const { return *this; }\n    Hash operator-() const { return Hash(0)\
    \ - *this; }\n\n    Hash pow(u64 n) const {\n        Hash r;\n        for (int\
    \ i = 0; i < NUM; i++) r[i] = (*this)[i].pow(n);\n        return r;\n    }\n\n\
    \    Hash inv() const {\n        Hash r;\n        for (int i = 0; i < NUM; i++)\
    \ r[i] = (*this)[i].inv();\n        return r;\n    }\n};\n\n} // namespace random\n\
    \n} // namespace kk2\n\n#endif // KK2_RANDOM_HASH_HPP\n"
  dependsOn:
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
  isVerificationFile: false
  path: random/hash.hpp
  requiredBy:
  - string/static_rolling_hash.hpp
  - string/dynamic_rolling_hash.hpp
  - math/group/rolling_hash.hpp
  timestamp: '2025-06-06 16:34:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/unit_test/monoid.test.cpp
documentation_of: random/hash.hpp
layout: document
redirect_from:
- /library/random/hash.hpp
- /library/random/hash.hpp.html
title: random/hash.hpp
---
