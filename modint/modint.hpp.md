---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/modint.hpp\"\n\n\n\ntemplate <int p> struct ModInt\
    \ {\n    using mint = ModInt;\n\n  public:\n    static int Mod;\n    constexpr\
    \ static int getmod() { \n        if (p > 0) return p;\n        else return Mod;\n\
    \    }\n    static void setmod(int Mod_) {\n        assert(1 <= Mod_);\n     \
    \   Mod = Mod_;\n    }\n    static mint raw(int v) {\n        mint x;\n      \
    \  x._v = v;\n        return x;\n    }\n\n    ModInt() : _v(0) {}\n    template\
    \ <class T> ModInt(T v) {\n        if (is_signed_v<T>) {\n            v %= getmod();\n\
    \            v += getmod();\n            v %= getmod();\n            _v = v;\n\
    \        }\n        else if (is_unsigned_v<T>) {\n            _v = v % getmod();\n\
    \        }\n        else ModInt();\n    } \n\n    unsigned int val() const { return\
    \ _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v == getmod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = getmod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += getmod() - rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n  \
    \      return *this;\n    }\n    mint& operator*=(const mint& rhs) {\n       \
    \ unsigned long long z = _v;\n        z *= rhs._v;\n        z %= getmod();\n \
    \       _v = z;\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n\n    mint operator+() const { return\
    \ *this; }\n    mint operator-() const { return mint() - *this; }\n\n    mint\
    \ pow(long long n) const {\n        assert(0 <= n);\n        mint x = *this, r\
    \ = 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n    mint inv()\
    \ const {\n        long long s = getmod(), t = _v;\n        long long m0 = 0,\
    \ m1 = 1;\n\n        while (t) {\n            long long u = s / t;\n         \
    \   s -= t * u;\n            m0 -= m1 * u;  \n\n            swap(s, t);\n    \
    \        swap(m0, m1);\n        }\n        if (m0 < 0) m0 += getmod() / s;\n \
    \       return m0;\n    }\n\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\n    friend ostream& operator<<(ostream& os, const mint&\
    \ mint_) {\n        os << mint_._v;\n        return os;\n    }\n    friend istream&\
    \ operator>>(istream& is, mint& mint_) {\n        long long x;\n        is >>\
    \ x;\n        mint_ = mint(x);\n        return is;\n    }\n\n  private:\n    unsigned\
    \ int _v;\n};\n\ntemplate<int p>\nint ModInt<p>::Mod = 998244353;\n\nusing mint998\
    \ = ModInt<998244353>;\nusing mint107 = ModInt<1000000007>;\n\n\n"
  code: "#ifndef MODINT_HPP\n#define MODINT_HPP 1\n\ntemplate <int p> struct ModInt\
    \ {\n    using mint = ModInt;\n\n  public:\n    static int Mod;\n    constexpr\
    \ static int getmod() { \n        if (p > 0) return p;\n        else return Mod;\n\
    \    }\n    static void setmod(int Mod_) {\n        assert(1 <= Mod_);\n     \
    \   Mod = Mod_;\n    }\n    static mint raw(int v) {\n        mint x;\n      \
    \  x._v = v;\n        return x;\n    }\n\n    ModInt() : _v(0) {}\n    template\
    \ <class T> ModInt(T v) {\n        if (is_signed_v<T>) {\n            v %= getmod();\n\
    \            v += getmod();\n            v %= getmod();\n            _v = v;\n\
    \        }\n        else if (is_unsigned_v<T>) {\n            _v = v % getmod();\n\
    \        }\n        else ModInt();\n    } \n\n    unsigned int val() const { return\
    \ _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v == getmod())\
    \ _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n        if\
    \ (_v == 0) _v = getmod();\n        _v--;\n        return *this;\n    }\n    mint\
    \ operator++(int) {\n        mint result = *this;\n        ++*this;\n        return\
    \ result;\n    }\n    mint operator--(int) {\n        mint result = *this;\n \
    \       --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v += getmod() - rhs._v;\n        if (_v >= getmod()) _v -= getmod();\n  \
    \      return *this;\n    }\n    mint& operator*=(const mint& rhs) {\n       \
    \ unsigned long long z = _v;\n        z *= rhs._v;\n        z %= getmod();\n \
    \       _v = z;\n        return *this;\n    }\n    mint& operator/=(const mint&\
    \ rhs) { return *this = *this * rhs.inv(); }\n\n    mint operator+() const { return\
    \ *this; }\n    mint operator-() const { return mint() - *this; }\n\n    mint\
    \ pow(long long n) const {\n        assert(0 <= n);\n        mint x = *this, r\
    \ = 1;\n        while (n) {\n            if (n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n    mint inv()\
    \ const {\n        long long s = getmod(), t = _v;\n        long long m0 = 0,\
    \ m1 = 1;\n\n        while (t) {\n            long long u = s / t;\n         \
    \   s -= t * u;\n            m0 -= m1 * u;  \n\n            swap(s, t);\n    \
    \        swap(m0, m1);\n        }\n        if (m0 < 0) m0 += getmod() / s;\n \
    \       return m0;\n    }\n\n    friend mint operator+(const mint& lhs, const\
    \ mint& rhs) {\n        return mint(lhs) += rhs;\n    }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n   \
    \ friend mint operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ *= rhs;\n    }\n    friend mint operator/(const mint& lhs, const mint& rhs)\
    \ {\n        return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n   \
    \ friend bool operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v\
    \ != rhs._v;\n    }\n\n    friend ostream& operator<<(ostream& os, const mint&\
    \ mint_) {\n        os << mint_._v;\n        return os;\n    }\n    friend istream&\
    \ operator>>(istream& is, mint& mint_) {\n        long long x;\n        is >>\
    \ x;\n        mint_ = mint(x);\n        return is;\n    }\n\n  private:\n    unsigned\
    \ int _v;\n};\n\ntemplate<int p>\nint ModInt<p>::Mod = 998244353;\n\nusing mint998\
    \ = ModInt<998244353>;\nusing mint107 = ModInt<1000000007>;\n\n#endif  // MODINT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint.hpp
  requiredBy: []
  timestamp: '2024-07-07 19:14:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/modint.hpp
layout: document
redirect_from:
- /library/modint/modint.hpp
- /library/modint/modint.hpp.html
title: modint/modint.hpp
---
