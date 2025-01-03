---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
  - icon: ':heavy_check_mark:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':heavy_check_mark:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef RANDOM_HASH_HPP\n#define RANDOM_HASH_HPP 1\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n\n#include \"../modint/modint_2_61m1.hpp\"\
    \n#include \"gen.hpp\"\n\nnamespace kk2 {\n\nnamespace random {\n\ntemplate <int\
    \ NUM> struct Hash : std::array<ModInt2_61m1, NUM> {\n    using mint = ModInt2_61m1;\n\
    \    using std::array<mint, NUM>::operator[];\n    using u64 = unsigned long long;\n\
    \n    Hash() : std::array<mint, NUM>() {}\n\n    template <class T, is_integral_t<T>\
    \ * = nullptr> Hash(T x) {\n        std::fill(this->begin(), this->end(), mint(x));\n\
    \    }\n\n    static Hash get_base() {\n        Hash base;\n        for (int i\
    \ = 0; i < NUM; i++) { base[i] = rng(1, mint::getmod() - 1); }\n        return\
    \ base;\n    }\n\n    Hash &operator+=(const Hash &rhs) {\n        for (int i\
    \ = 0; i < NUM; i++) { (*this)[i] += rhs[i]; }\n        return *this;\n    }\n\
    \n    Hash &operator-=(const Hash &rhs) {\n        for (int i = 0; i < NUM; i++)\
    \ { (*this)[i] -= rhs[i]; }\n        return *this;\n    }\n\n    Hash &operator*=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < NUM; i++) { (*this)[i] *= rhs[i];\
    \ }\n        return *this;\n    }\n\n    Hash &operator/=(const Hash &rhs) {\n\
    \        for (int i = 0; i < NUM; i++) { (*this)[i] /= rhs[i]; }\n        return\
    \ *this;\n    }\n\n    Hash operator+(const Hash &rhs) const { return Hash(*this)\
    \ += rhs; }\n\n    Hash operator-(const Hash &rhs) const { return Hash(*this)\
    \ -= rhs; }\n\n    Hash operator*(const Hash &rhs) const { return Hash(*this)\
    \ *= rhs; }\n\n    Hash operator/(const Hash &rhs) const { return Hash(*this)\
    \ /= rhs; }\n\n    Hash operator-() const {\n        Hash res;\n        for (int\
    \ i = 0; i < NUM; i++) { res[i] = -(*this)[i]; }\n        return res;\n    }\n\
    \n    bool operator==(const Hash &rhs) const {\n        for (int i = 0; i < NUM;\
    \ i++) {\n            if ((*this)[i] != rhs[i]) return false;\n        }\n   \
    \     return true;\n    }\n\n    bool operator!=(const Hash &rhs) const {\n  \
    \      for (int i = 0; i < NUM; i++) {\n            if ((*this)[i] != rhs[i])\
    \ return true;\n        }\n        return false;\n    }\n\n    Hash pow(u64 n)\
    \ const {\n        Hash x = *this, r;\n        for (int i = 0; i < NUM; i++) {\
    \ r[i] = x[i].pow(n); }\n        return r;\n    }\n\n    Hash inv() const {\n\
    \        Hash r;\n        for (int i = 0; i < NUM; i++) { r[i] = (*this)[i].inv();\
    \ }\n        return r;\n    }\n};\n\n} // namespace random\n\n} // namespace kk2\n\
    \n#endif // RANDOM_HASH_HPP\n"
  dependsOn:
  - modint/modint_2_61m1.hpp
  - type_traits/type_traits.hpp
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: random/hash.hpp
  requiredBy:
  - string/rolling_hash.hpp
  timestamp: '2025-01-03 20:28:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
documentation_of: random/hash.hpp
layout: document
redirect_from:
- /library/random/hash.hpp
- /library/random/hash.hpp.html
title: random/hash.hpp
---
