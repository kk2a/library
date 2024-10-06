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
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':warning:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':warning:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/math_primality_test.test.cpp
    title: verify/yosupo_math/math_primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/mont_arb.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <utility>\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\
    \n\n#include <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing\
    \ is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\n\
    \                                                       or std::is_same<T, __int128>::value,\n\
    \                                                   std::true_type,\n        \
    \                                           std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 9 \"modint/mont_arb.hpp\"\
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
    \n    friend std::ostream &operator<<(std::ostream &os, const mint &x) { return\
    \ os << x.val(); }\n\n    friend std::istream &operator>>(std::istream &is, mint\
    \ &x) {\n        Long t;\n        is >> t;\n        x = mint(t);\n        return\
    \ (is);\n    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n   \
    \     return ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod()\
    \ { return mod; }\n};\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
    \ long long, id>;\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
    \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n"
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
    \n    friend std::ostream &operator<<(std::ostream &os, const mint &x) { return\
    \ os << x.val(); }\n\n    friend std::istream &operator>>(std::istream &is, mint\
    \ &x) {\n        Long t;\n        is >> t;\n        x = mint(t);\n        return\
    \ (is);\n    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n   \
    \     return ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod()\
    \ { return mod; }\n};\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
    \ long long, id>;\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
    \ __uint128_t, id>;\n\n} // namespace kk2\n\n#endif // MODINT_MONT_ARB_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: modint/mont_arb.hpp
  requiredBy:
  - math_mod/mod_sqrt.hpp
  - math/prime_factorize.hpp
  - math/is_prime.hpp
  - fps/fps_sqrt.hpp
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/math_primality_test.test.cpp
documentation_of: modint/mont_arb.hpp
layout: document
redirect_from:
- /library/modint/mont_arb.hpp
- /library/modint/mont_arb.hpp.html
title: modint/mont_arb.hpp
---
