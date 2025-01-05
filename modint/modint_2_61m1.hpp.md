---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
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
  - icon: ':x:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MODINT_MODINT_2_61M1_HPP\n#define KK2_MODINT_MODINT_2_61M1_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../type_traits/type_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\nstruct ModInt2_61m1 {\n    using mint = ModInt2_61m1;\n    using u64\
    \ = unsigned long long;\n\n    constexpr static u64 mod = (1ULL << 61) - 1;\n\n\
    \    constexpr static u64 getmod() { return mod; }\n\n    constexpr ModInt2_61m1()\
    \ : _v(0) {}\n\n    template <class T, is_integral_t<T> * = nullptr> constexpr\
    \ ModInt2_61m1(T x_) {\n        if (x_ < 0) {\n            _v = -x_;\n       \
    \     chmod(_v);\n            _v = mod - _v;\n        } else {\n            _v\
    \ = x_;\n            chmod(_v);\n        }\n    }\n\n    constexpr mint &operator++()\
    \ {\n        ++_v;\n        if (_v == mod) _v = 0;\n        return *this;\n  \
    \  }\n\n    constexpr mint &operator--() {\n        if (_v == 0) _v = mod;\n \
    \       --_v;\n        return *this;\n    }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        ++*this;\n        return ret;\n    }\n\
    \n    constexpr mint operator--(int) {\n        mint ret = *this;\n        --*this;\n\
    \        return ret;\n    }\n\n    constexpr mint &operator+=(const mint &x) {\n\
    \        _v += x._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &x) {\n        _v += mod -\
    \ x._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n    }\n\n \
    \   constexpr mint &operator*=(const mint &x) {\n        _v = mulmod(_v, x._v);\n\
    \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &x)\
    \ { return *this *= x.inv(); }\n\n    constexpr mint operator+() const { return\
    \ *this; }\n\n    constexpr mint operator-() const { return mint() - *this; }\n\
    \n    constexpr bool operator==(const mint &x) const { return _v == x._v; }\n\n\
    \    constexpr bool operator!=(const mint &x) const { return _v != x._v; }\n\n\
    \    friend constexpr mint operator+(const mint &x, const mint &y) { return mint(x)\
    \ += y; }\n\n    friend constexpr mint operator-(const mint &x, const mint &y)\
    \ { return mint(x) -= y; }\n\n    friend constexpr mint operator*(const mint &x,\
    \ const mint &y) { return mint(x) *= y; }\n\n    friend constexpr mint operator/(const\
    \ mint &x, const mint &y) { return mint(x) /= y; }\n\n    template <class T, is_integral_t<T>\
    \ * = nullptr> constexpr mint pow(T n) const {\n        assert(n >= 0);\n    \
    \    mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            x *= x;\n            n >>= 1;\n        }\n        return r;\n\
    \    }\n\n    constexpr mint inv() const { return pow(mod - 2); }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x._v;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        u64 y;\n        is >> y;\n        x = mint(y);\n  \
    \      return is;\n    }\n\n    constexpr u64 val() const { return _v; }\n\n \
    \ private:\n    u64 _v;\n\n    constexpr static u64 chmod(u64 &x) {\n        x\
    \ = (x & mod) + (x >> 61);\n        if (x >= mod) x -= mod;\n        return x;\n\
    \    }\n\n    constexpr static u64 mask30 = (1ULL << 30) - 1;\n    constexpr static\
    \ u64 mask31 = (1ULL << 31) - 1;\n\n    constexpr static u64 mulmod(u64 x, u64\
    \ y) {\n        u64 xh = x >> 31, xl = x & mask31;\n        u64 yh = y >> 31,\
    \ yl = y & mask31;\n        u64 m = xh * yl + xl * yh;\n        u64 t = 2 * xh\
    \ * yh + xl * yl + (m >> 30) + ((m & mask30) << 31);\n        return chmod(t);\n\
    \    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MODINT_MODINT_2_61M1_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: modint/modint_2_61m1.hpp
  requiredBy:
  - random/hash.hpp
  - string/rolling_hash.hpp
  timestamp: '2025-01-06 00:03:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
documentation_of: modint/modint_2_61m1.hpp
layout: document
redirect_from:
- /library/modint/modint_2_61m1.hpp
- /library/modint/modint_2_61m1.hpp.html
title: modint/modint_2_61m1.hpp
---
