---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  - icon: ':question:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
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
  bundledCode: "#line 1 \"fps/fps_sqrt.hpp\"\n\n\n\n#include <cassert>\n\n#line 1\
    \ \"math_mod/mod_sqrt.hpp\"\n\n\n\n#line 5 \"math_mod/mod_sqrt.hpp\"\n\n#line\
    \ 1 \"modint/mont_arb.hpp\"\n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n\
    #include <utility>\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value\n           \
    \                                            or std::is_same<T, __int128>::value,\n\
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
    \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/mod_sqrt.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, class U> long long mod_sqrt(const T\
    \ &a, const U &p) {\n    assert(0 <= a && a < p);\n    if (a < 2) return a;\n\
    \    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n    Mint::setmod(p);\n\
    \    if (Mint(a).pow((p - 1) >> 1) != Mint(1)) return -1;\n    Mint b = 1;\n \
    \   while (b.pow((p - 1) >> 1) == Mint(1)) b += 1;\n    long long m = p - 1, e\
    \ = 0;\n    while (m % 2 == 0) m >>= 1, e++;\n    Mint x = Mint(a).pow((m - 1)\
    \ >> 1);\n    Mint y = Mint(a) * x * x;\n    x *= a;\n    Mint z = Mint(b).pow(m);\n\
    \    while (y != Mint(1)) {\n        long long j = 0;\n        Mint t = y;\n \
    \       while (t != Mint(1)) {\n            j++;\n            t *= t;\n      \
    \  }\n        z = z.pow(1LL << (e - j - 1));\n        x *= z;\n        z *= z;\n\
    \        y *= z;\n        e = j;\n    }\n    return x.val();\n}\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"fps/fps_sqrt.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type> FPS sqrt(const FPS &f, int deg =\
    \ -1) {\n    // using mint = typename FPS::value_type;\n    if (deg == -1) deg\
    \ = (int)f.size();\n    if ((int)f.size() == 0) return FPS(deg, mint(0));\n  \
    \  if (f[0] == mint(0)) {\n        for (int i = 1; i < (int)f.size(); i++) {\n\
    \            if (f[i] != mint(0)) {\n                if (i & 1) return {};\n \
    \               if (deg - i / 2 <= 0) break;\n                auto ret = sqrt(f\
    \ >> i, deg - i / 2);\n                if (ret.empty()) return {};\n         \
    \       ret = ret << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, mint(0));\n    }\n\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    assert(sqr * sqr % mint::getmod() == f[0].val());\n\
    \    FPS ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i =\
    \ 1; i < deg; i <<= 1) { ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\
    \ }\n    return ret.pre(deg);\n}\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS sparse_sqrt(const FPS &f, int deg = -1) {\n    // using\
    \ mint = typename FPS::value_type;\n    if (deg == -1) deg = (int)f.size();\n\
    \    if ((int)f.size() == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0))\
    \ {\n        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] !=\
    \ mint(0)) {\n                if (i & 1) return {};\n                if (deg -\
    \ i / 2 <= 0) break;\n                auto ret = sparse_sqrt(f >> i, deg - i /\
    \ 2);\n                if (ret.empty()) return {};\n                ret = ret\
    \ << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \                return ret;\n            }\n        }\n        return FPS(deg,\
    \ mint(0));\n    }\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    return f.sparse_pow(((mint::getmod() + 1)\
    \ >> 1), deg) * mint(sqr).inv();\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_SQRT_HPP\n#define FPS_SQRT_HPP 1\n\n#include <cassert>\n\n#include\
    \ \"../math_mod/mod_sqrt.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type> FPS sqrt(const FPS &f, int deg = -1) {\n  \
    \  // using mint = typename FPS::value_type;\n    if (deg == -1) deg = (int)f.size();\n\
    \    if ((int)f.size() == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0))\
    \ {\n        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] !=\
    \ mint(0)) {\n                if (i & 1) return {};\n                if (deg -\
    \ i / 2 <= 0) break;\n                auto ret = sqrt(f >> i, deg - i / 2);\n\
    \                if (ret.empty()) return {};\n                ret = ret << (i\
    \ / 2);\n                if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \                return ret;\n            }\n        }\n        return FPS(deg,\
    \ mint(0));\n    }\n\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    assert(sqr * sqr % mint::getmod() == f[0].val());\n\
    \    FPS ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i =\
    \ 1; i < deg; i <<= 1) { ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\
    \ }\n    return ret.pre(deg);\n}\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS sparse_sqrt(const FPS &f, int deg = -1) {\n    // using\
    \ mint = typename FPS::value_type;\n    if (deg == -1) deg = (int)f.size();\n\
    \    if ((int)f.size() == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0))\
    \ {\n        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] !=\
    \ mint(0)) {\n                if (i & 1) return {};\n                if (deg -\
    \ i / 2 <= 0) break;\n                auto ret = sparse_sqrt(f >> i, deg - i /\
    \ 2);\n                if (ret.empty()) return {};\n                ret = ret\
    \ << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \                return ret;\n            }\n        }\n        return FPS(deg,\
    \ mint(0));\n    }\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    return f.sparse_pow(((mint::getmod() + 1)\
    \ >> 1), deg) * mint(sqr).inv();\n}\n\n} // namespace kk2\n\n#endif // FPS_SQRT_HPP\n"
  dependsOn:
  - math_mod/mod_sqrt.hpp
  - modint/mont_arb.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: fps/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_sqrt.hpp
layout: document
redirect_from:
- /library/fps/fps_sqrt.hpp
- /library/fps/fps_sqrt.hpp.html
title: fps/fps_sqrt.hpp
---
