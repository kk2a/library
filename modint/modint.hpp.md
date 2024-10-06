---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/modint.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n#include <utility>\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n#line 5 \"type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 10 \"modint/modint.hpp\"\n\nnamespace kk2 {\n\ntemplate <int p> struct\
    \ ModInt {\n    using mint = ModInt;\n\n  public:\n    static int Mod;\n\n   \
    \ constexpr static unsigned int getmod() {\n        if (p > 0) return p;\n   \
    \     else return Mod;\n    }\n\n    static void setmod(int Mod_) {\n        assert(1\
    \ <= Mod_);\n        Mod = Mod_;\n    }\n\n    static mint raw(int v) {\n    \
    \    mint x;\n        x._v = v;\n        return x;\n    }\n\n    operator int()\
    \ const { return _v; }\n\n    constexpr ModInt() : _v(0) {}\n\n    template <class\
    \ T, std::enable_if_t<is_integral_extended<T>::value> * = nullptr>\n    constexpr\
    \ ModInt(T v) {\n        if constexpr (is_signed_extended<T>::value) {\n     \
    \       v %= getmod();\n            if (v < 0) v += getmod();\n            _v\
    \ = v;\n        } else if constexpr (is_unsigned_extended<T>::value) {\n     \
    \       _v = v %= getmod();\n        } else {\n            ModInt();\n       \
    \ }\n    }\n\n    unsigned int val() const { return _v; }\n\n    mint &operator++()\
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
    \ mint(lhs) += rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator+(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) += mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator+(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n\n    friend mint operator-(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) -= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) -= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) -= rhs;\n    }\n\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) *= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) *= rhs;\n    }\n\n    friend mint operator/(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) /= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) /= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) /= rhs;\n    }\n\n    friend bool operator==(const mint &lhs, const\
    \ mint &rhs) { return lhs._v == rhs._v; }\n\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &mint_) {\n        os << mint_._v;\n\
    \        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &mint_) {\n        long long x;\n        is >> x;\n        mint_ =\
    \ mint(x);\n        return is;\n    }\n\n  private:\n    unsigned int _v;\n};\n\
    \ntemplate <int p> int ModInt<p>::Mod = 998244353;\n\n\nusing mint998 = ModInt<998244353>;\n\
    using mint107 = ModInt<1000000007>;\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MODINT_HPP\n#define MODINT_HPP 1\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n#include <utility>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int p> struct ModInt {\n    using mint = ModInt;\n\
    \n  public:\n    static int Mod;\n\n    constexpr static unsigned int getmod()\
    \ {\n        if (p > 0) return p;\n        else return Mod;\n    }\n\n    static\
    \ void setmod(int Mod_) {\n        assert(1 <= Mod_);\n        Mod = Mod_;\n \
    \   }\n\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n  \
    \      return x;\n    }\n\n    operator int() const { return _v; }\n\n    constexpr\
    \ ModInt() : _v(0) {}\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    constexpr ModInt(T v) {\n        if constexpr (is_signed_extended<T>::value)\
    \ {\n            v %= getmod();\n            if (v < 0) v += getmod();\n     \
    \       _v = v;\n        } else if constexpr (is_unsigned_extended<T>::value)\
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
    \ mint(lhs) += rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator+(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) += mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator+(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n\n    friend mint operator-(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) -= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) -= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator-(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) -= rhs;\n    }\n\n    friend mint operator*(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) *= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) *= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator*(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) *= rhs;\n    }\n\n    friend mint operator/(const mint &lhs, const\
    \ mint &rhs) { return mint(lhs) /= rhs; }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(const mint &lhs, T rhs) {\n        return\
    \ mint(lhs) /= mint(rhs);\n    }\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend mint operator/(T lhs, const mint &rhs) {\n        return\
    \ mint(lhs) /= rhs;\n    }\n\n    friend bool operator==(const mint &lhs, const\
    \ mint &rhs) { return lhs._v == rhs._v; }\n\n    friend bool operator!=(const\
    \ mint &lhs, const mint &rhs) { return lhs._v != rhs._v; }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const mint &mint_) {\n        os << mint_._v;\n\
    \        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &mint_) {\n        long long x;\n        is >> x;\n        mint_ =\
    \ mint(x);\n        return is;\n    }\n\n  private:\n    unsigned int _v;\n};\n\
    \ntemplate <int p> int ModInt<p>::Mod = 998244353;\n\n\nusing mint998 = ModInt<998244353>;\n\
    using mint107 = ModInt<1000000007>;\n\n} // namespace kk2\n\n#endif // MODINT_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: modint/modint.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/modint.hpp
layout: document
redirect_from:
- /library/modint/modint.hpp
- /library/modint/modint.hpp.html
title: modint/modint.hpp
---
