---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
    title: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MODINT_HPP\n#define MODINT_HPP 1\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n#include <utility>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int p> struct ModInt {\n    using mint = ModInt;\n\
    \n  public:\n    static int Mod;\n\n    constexpr static unsigned int getmod()\
    \ {\n        if (p > 0) return p;\n        else return Mod;\n    }\n\n    static\
    \ void setmod(int Mod_) {\n        assert(1 <= Mod_);\n        Mod = Mod_;\n \
    \   }\n\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n  \
    \      return x;\n    }\n\n    constexpr ModInt() : _v(0) {}\n\n    template <class\
    \ T, is_integral_t<T> * = nullptr> constexpr ModInt(T v) {\n        if constexpr\
    \ (is_signed<T>::value) {\n            v %= getmod();\n            if (v < 0)\
    \ v += getmod();\n            _v = v;\n        } else if constexpr (is_unsigned<T>::value)\
    \ {\n            _v = v %= getmod();\n        } else {\n            ModInt();\n\
    \        }\n    }\n\n    unsigned int val() const { return _v; }\n\n    mint &operator++()\
    \ {\n        _v++;\n        if (_v == getmod()) _v = 0;\n        return *this;\n\
    \    }\n\n    mint &operator--() {\n        if (_v == 0) _v = getmod();\n    \
    \    _v--;\n        return *this;\n    }\n\n    mint operator++(int) {\n     \
    \   mint result = *this;\n        ++*this;\n        return result;\n    }\n\n\
    \    mint operator--(int) {\n        mint result = *this;\n        --*this;\n\
    \        return result;\n    }\n\n    mint &operator+=(const mint &rhs) {\n  \
    \      _v += rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n        return\
    \ *this;\n    }\n\n    mint &operator-=(const mint &rhs) {\n        _v += getmod()\
    \ - rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n        return *this;\n\
    \    }\n\n    mint &operator*=(const mint &rhs) {\n        unsigned long long\
    \ z = _v;\n        z *= rhs._v;\n        z %= getmod();\n        _v = z;\n   \
    \     return *this;\n    }\n\n    mint &operator/=(const mint &rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n\n \
    \   mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n\n    mint inv() const {\n\
    \        long long s = getmod(), t = _v;\n        long long m0 = 0, m1 = 1;\n\n\
    \        while (t) {\n            long long u = s / t;\n            s -= t * u;\n\
    \            m0 -= m1 * u;\n\n            std::swap(s, t);\n            std::swap(m0,\
    \ m1);\n        }\n        if (m0 < 0) m0 += getmod() / s;\n        return m0;\n\
    \    }\n\n    friend mint operator+(const mint &lhs, const mint &rhs) { return\
    \ mint(lhs) += rhs; }\n\n    friend mint operator-(const mint &lhs, const mint\
    \ &rhs) { return mint(lhs) -= rhs; }\n\n    friend mint operator*(const mint &lhs,\
    \ const mint &rhs) { return mint(lhs) *= rhs; }\n\n    friend mint operator/(const\
    \ mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }\n\n    friend bool\
    \ operator==(const mint &lhs, const mint &rhs) { return lhs._v == rhs._v; }\n\n\
    \    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs._v\
    \ != rhs._v; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const mint &mint_) {\n        os\
    \ << mint_._v;\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, mint &mint_) {\n \
    \       long long x;\n        is >> x;\n        mint_ = mint(x);\n        return\
    \ is;\n    }\n\n  private:\n    unsigned int _v;\n};\n\ntemplate <int p> int ModInt<p>::Mod\
    \ = 998244353;\n\n\nusing mint998 = ModInt<998244353>;\nusing mint107 = ModInt<1000000007>;\n\
    \n} // namespace kk2\n\n#endif // MODINT_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: modint/modint.hpp
  requiredBy: []
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
documentation_of: modint/modint.hpp
layout: document
redirect_from:
- /library/modint/modint.hpp
- /library/modint/modint.hpp.html
title: modint/modint.hpp
---
