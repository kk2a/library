---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/mod_sqrt.hpp\"\n\n\n\n#line 1 \"modint/mont_arb.hpp\"\
    \n\n\n\nnamespace kk2 {\n\ntemplate <typename Int, typename UInt, typename Long,\
    \ typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using\
    \ mint = ArbitraryLazyMontgomeryModIntBase;\n\n    inline static UInt mod;\n \
    \   inline static UInt r;\n    inline static UInt n2;\n    static constexpr int\
    \ bit_length = sizeof(UInt) * 8;\n\n    static UInt get_r() {\n        UInt ret\
    \ = mod;\n        while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n       \
    \ return ret;\n    }\n    static void setmod(UInt m) {\n        assert(m < (UInt(1u)\
    \ << (bit_length - 2)));\n        assert((m & 1) == 1);\n        mod = m, n2 =\
    \ -ULong(m) % m, r = get_r();\n    }\n    UInt _v;\n\n    ArbitraryLazyMontgomeryModIntBase()\
    \ : _v(0) {}\n    ArbitraryLazyMontgomeryModIntBase(const Long &b)\n        :\
    \ _v(reduce(ULong(b % mod + mod) * n2)) {}\n    \n    static UInt reduce(const\
    \ ULong &b) {\n        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \    }\n\n    mint& operator+=(const mint& b) {\n        if (Int(_v += b._v -\
    \ 2 * mod) < 0) _v += 2 * mod;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint& b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& b) {\n        _v = reduce(ULong(_v)\
    \ * b._v);\n        return *this;\n    }\n    mint& operator/=(const mint& b)\
    \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n    mint operator+(const\
    \ mint& b) const { return mint(*this) += b; }\n    mint operator-(const mint&\
    \ b) const { return mint(*this) -= b; }\n    mint operator*(const mint& b) const\
    \ { return mint(*this) *= b; }\n    mint operator/(const mint& b) const { return\
    \ mint(*this) /= b; }\n\n    bool operator==(const mint& b) const {\n        return\
    \ (_v >= mod ? _v - mod : _v) == (b._v >= mod ? b._v - mod : b._v);\n    }\n \
    \   bool operator!=(const mint& b) const {\n        return (_v >= mod ? _v - mod\
    \ : _v) != (b._v >= mod ? b._v - mod : b._v);\n    }\n    mint operator-() const\
    \ { return mint(0) - mint(*this); }\n    mint operator+() const { return mint(*this);\
    \ }\n\n    template <class T>\n    mint pow(T n) const {\n        mint ret(1),\
    \ mul(*this);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n \
    \           mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n\n    mint inv() const {\n        Int s = getmod(), t = val(), m0 = 0,\
    \ m1 = 1;\n        while (t) {\n            Int u = s / t;\n            swap(s\
    \ -= t * u, t);\n            swap(m0 -= m1 * u, m1);\n        }\n        if (m0\
    \ < 0) m0 += getmod();\n        return mint(m0);\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const mint& x) {\n        return os << x.val();\n  \
    \  }\n    friend istream& operator>>(istream& is, mint& x) {\n        Long t;\
    \ is >> t; x = mint(t);\n        return (is);\n    }\n\n    UInt val() const {\n\
    \        UInt ret = reduce(_v);\n        return ret >= mod ? ret - mod : ret;\n\
    \    }\n    static UInt getmod() { return mod; }\n};\n\ntemplate <int id>\nusing\
    \ ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long,\n      \
    \                                __int128_t, __uint128_t, id>;\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math_mod/mod_sqrt.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ T, class U> \nlong long mod_sqrt(const T& a, const U &p) {\n    assert(0 <=\
    \ a && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
    \    Mint::setmod(p);\n    if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n  \
    \  Mint b = 1;\n    while (b.pow((p - 1) >> 1) == 1) b += 1;\n    long long m\
    \ = p - 1, e = 0;\n    while (m % 2 == 0) m >>= 1, e++;\n    Mint x = Mint(a).pow((m\
    \ - 1) >> 1);\n    Mint y = Mint(a) * x * x;\n    x *= a;\n    Mint z = Mint(b).pow(m);\n\
    \    while (y != 1) {\n        long long j = 0;\n        Mint t = y;\n       \
    \ while (t != 1) {\n            j++;\n            t *= t;\n        }\n       \
    \ z = z.pow(1LL << (e - j - 1));\n        x *= z;\n        z *= z;\n        y\
    \ *= z;\n        e = j;\n    }\n    return x.val();\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef MOD_SQRT_HPP\n#define MOD_SQRT_HPP 1\n\n#include \"../modint/mont_arb.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, class U> \nlong long mod_sqrt(const\
    \ T& a, const U &p) {\n    assert(0 <= a && a < p);\n    if (a < 2) return a;\n\
    \    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n    Mint::setmod(p);\n\
    \    if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n    Mint b = 1;\n    while\
    \ (b.pow((p - 1) >> 1) == 1) b += 1;\n    long long m = p - 1, e = 0;\n    while\
    \ (m % 2 == 0) m >>= 1, e++;\n    Mint x = Mint(a).pow((m - 1) >> 1);\n    Mint\
    \ y = Mint(a) * x * x;\n    x *= a;\n    Mint z = Mint(b).pow(m);\n    while (y\
    \ != 1) {\n        long long j = 0;\n        Mint t = y;\n        while (t !=\
    \ 1) {\n            j++;\n            t *= t;\n        }\n        z = z.pow(1LL\
    \ << (e - j - 1));\n        x *= z;\n        z *= z;\n        y *= z;\n      \
    \  e = j;\n    }\n    return x.val();\n}\n\n} // namespace kk2\n\n#endif // MOD_SQRT_HPP\n"
  dependsOn:
  - modint/mont_arb.hpp
  isVerificationFile: false
  path: math_mod/mod_sqrt.hpp
  requiredBy:
  - fps/fps_sqrt.hpp
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math_mod/mod_sqrt.hpp
- /library/math_mod/mod_sqrt.hpp.html
title: math_mod/mod_sqrt.hpp
---
