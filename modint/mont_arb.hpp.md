---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':x:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':warning:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/factrize.test.cpp
    title: verify/yosupo_math/factrize.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/primality_test.test.cpp
    title: verify/yosupo_math/primality_test.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  code: "#ifndef MODINT_MONT_ARB_HPP\n#define MODINT_MONT_ARB_HPP 1\n\n#include <cassert>\n\
    #include <iostream>\n#include <utility>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename Int, typename UInt, typename Long, typename\
    \ ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using mint =\
    \ ArbitraryLazyMontgomeryModIntBase;\n\n    inline static UInt mod;\n    inline\
    \ static UInt r;\n    inline static UInt n2;\n    static constexpr int bit_length\
    \ = sizeof(UInt) * 8;\n\n    static UInt get_r() {\n        UInt ret = mod;\n\
    \        while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n        return ret;\n\
    \    }\n\n    static void setmod(UInt m) {\n        assert(m < (UInt(1u) << (bit_length\
    \ - 2)));\n        assert((m & 1) == 1);\n        mod = m, n2 = -ULong(m) % m,\
    \ r = get_r();\n    }\n\n    UInt _v;\n\n    operator Int() const { return val();\
    \ }\n\n    ArbitraryLazyMontgomeryModIntBase() : _v(0) {}\n\n    template <class\
    \ T, std::enable_if_t<is_integral_extended<T>::value> * = nullptr>\n    ArbitraryLazyMontgomeryModIntBase(const\
    \ T &b) : _v(reduce(ULong(b % mod + mod) * n2)) {}\n\n    static UInt reduce(const\
    \ ULong &b) {\n        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \    }\n\n    mint &operator+=(const mint &b) {\n        if (Int(_v += b._v -\
    \ 2 * mod) < 0) _v += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
    \ mint &b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return\
    \ *this;\n    }\n\n    mint &operator*=(const mint &b) {\n        _v = reduce(ULong(_v)\
    \ * b._v);\n        return *this;\n    }\n\n    mint &operator/=(const mint &b)\
    \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n    friend mint\
    \ operator+(const mint &a, const mint &b) { return mint(a) += b; }\n\n    template\
    \ <class T, std::enable_if_t<is_integral_extended<T>::value> * = nullptr>\n  \
    \  friend mint operator+(const mint &a, T b) {\n        return mint(a) += mint(b);\n\
    \    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator+(T a, const mint &b) {\n        return\
    \ mint(a) += b;\n    }\n\n    friend mint operator-(const mint &a, const mint\
    \ &b) { return mint(a) -= b; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(const mint &a, T b) {\n        return\
    \ mint(a) -= mint(b);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(T a, const mint &b) {\n        return\
    \ mint(a) -= b;\n    }\n\n    friend mint operator*(const mint &a, const mint\
    \ &b) { return mint(a) *= b; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(const mint &a, T b) {\n        return\
    \ mint(a) *= mint(b);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(T a, const mint &b) {\n        return\
    \ mint(a) *= b;\n    }\n\n    friend mint operator/(const mint &a, const mint\
    \ &b) { return mint(a) /= b; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(const mint &a, T b) {\n        return\
    \ mint(a) /= mint(b);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(T a, const mint &b) {\n        return\
    \ mint(a) /= b;\n    }\n\n    bool operator==(const mint &b) const {\n       \
    \ return (_v >= mod ? _v - mod : _v) == (b._v >= mod ? b._v - mod : b._v);\n \
    \   }\n\n    bool operator!=(const mint &b) const {\n        return (_v >= mod\
    \ ? _v - mod : _v) != (b._v >= mod ? b._v - mod : b._v);\n    }\n\n    mint operator-()\
    \ const { return mint(0) - mint(*this); }\n\n    mint operator+() const { return\
    \ mint(*this); }\n\n    template <class T> mint pow(T n) const {\n        mint\
    \ ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1) ret *=\
    \ mul;\n            mul *= mul;\n            n >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    mint inv() const {\n        Int s = getmod(), t = val(),\
    \ m0 = 0, m1 = 1;\n        while (t) {\n            Int u = s / t;\n         \
    \   std::swap(s -= t * u, t);\n            std::swap(m0 -= m1 * u, m1);\n    \
    \    }\n        if (m0 < 0) m0 += getmod();\n        return mint(m0);\n    }\n\
    \n    template <class OStream> friend OStream &operator<<(OStream &os, const mint\
    \ &x) {\n        return os << x.val();\n    }\n\n    template <class IStream>\
    \ friend IStream &operator>>(IStream &is, mint &x) {\n        Long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return (is);\n    }\n\n    UInt val()\
    \ const {\n        UInt ret = reduce(_v);\n        return ret >= mod ? ret - mod\
    \ : ret;\n    }\n\n    static UInt getmod() { return mod; }\n};\n\ntemplate <int\
    \ id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long, unsigned long long, id>;\n\ntemplate <int id>\nusing\
    \ ArbitraryLazyMontgomeryModInt64bit =\n    ArbitraryLazyMontgomeryModIntBase<long\
    \ long, unsigned long long, __int128_t, __uint128_t, id>;\n\n} // namespace kk2\n\
    \n#endif // MODINT_MONT_ARB_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: modint/mont_arb.hpp
  requiredBy:
  - math/is_prime.hpp
  - math/prime_factorize.hpp
  - math_mod/mod_sqrt.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2024-10-14 04:02:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/factrize.test.cpp
documentation_of: modint/mont_arb.hpp
layout: document
redirect_from:
- /library/modint/mont_arb.hpp
- /library/modint/mont_arb.hpp.html
title: modint/mont_arb.hpp
---
