---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/mont.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate <int\
    \ p>\nstruct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n    \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n    template <class T>\n    constexpr LazyMontgomeryModInt(const\
    \ T& b)\n         : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr\
    \ u32 reduce(const u64& b) {\n        return (b + u64(u32(b) * u32(-r)) * p) >>\
    \ 32;\n    }\n    constexpr mint& operator+=(const mint& b) {\n        if (i32(_v\
    \ += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n    constexpr\
    \ mint& operator-=(const mint& b) {\n        if (i32(_v -= b._v) < 0) _v += 2\
    \ * p;\n        return *this;\n    }\n    constexpr mint& operator*=(const mint&\
    \ b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n \
    \   constexpr mint& operator/=(const mint& b) {\n        *this *= b.inv();\n \
    \       return *this;\n    }\n\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n    constexpr bool operator!=(const mint &b) const {\n        return (_v\
    \ >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n    friend constexpr\
    \ mint operator+(const mint& a, const mint& b) { return mint(a) += b; }\n    friend\
    \ constexpr mint operator-(const mint& a, const mint& b) { return mint(a) -= b;\
    \ }\n    friend constexpr mint operator*(const mint& a, const mint& b) { return\
    \ mint(a) *= b; }\n    friend constexpr mint operator/(const mint& a, const mint&\
    \ b) { return mint(a) /= b; }\n\n    template <class T>\n    constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend ostream& operator<<(ostream& os, const mint& x)\
    \ {\n        return os << x.val();\n    }\n    friend istream& operator>>(istream&\
    \ is, mint& x) {\n        i64 t; is >> t; x = mint(t);\n        return (is);\n\
    \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n   \
    \     return ret >= p ? ret - p : ret;\n    }\n    static constexpr u32 getmod()\
    \ { return p; }\n};\n\ntemplate <int p>\nusing Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} \
    \ // namespace kk2\n\n\n"
  code: "#ifndef MODINT_MONT_HPP\n#define MODINT_MONT_HPP 1\n\nnamespace kk2 {\n\n\
    template <int p>\nstruct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n    \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n    template <class T>\n    constexpr LazyMontgomeryModInt(const\
    \ T& b)\n         : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr\
    \ u32 reduce(const u64& b) {\n        return (b + u64(u32(b) * u32(-r)) * p) >>\
    \ 32;\n    }\n    constexpr mint& operator+=(const mint& b) {\n        if (i32(_v\
    \ += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n    constexpr\
    \ mint& operator-=(const mint& b) {\n        if (i32(_v -= b._v) < 0) _v += 2\
    \ * p;\n        return *this;\n    }\n    constexpr mint& operator*=(const mint&\
    \ b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n \
    \   constexpr mint& operator/=(const mint& b) {\n        *this *= b.inv();\n \
    \       return *this;\n    }\n\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n    constexpr bool operator!=(const mint &b) const {\n        return (_v\
    \ >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n    friend constexpr\
    \ mint operator+(const mint& a, const mint& b) { return mint(a) += b; }\n    friend\
    \ constexpr mint operator-(const mint& a, const mint& b) { return mint(a) -= b;\
    \ }\n    friend constexpr mint operator*(const mint& a, const mint& b) { return\
    \ mint(a) *= b; }\n    friend constexpr mint operator/(const mint& a, const mint&\
    \ b) { return mint(a) /= b; }\n\n    template <class T>\n    constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend ostream& operator<<(ostream& os, const mint& x)\
    \ {\n        return os << x.val();\n    }\n    friend istream& operator>>(istream&\
    \ is, mint& x) {\n        i64 t; is >> t; x = mint(t);\n        return (is);\n\
    \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n   \
    \     return ret >= p ? ret - p : ret;\n    }\n    static constexpr u32 getmod()\
    \ { return p; }\n};\n\ntemplate <int p>\nusing Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} \
    \ // namespace kk2\n\n#endif  // MODINT_MONT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/mont.hpp
  requiredBy:
  - convolution/convo_arb.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-08-29 01:45:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: modint/mont.hpp
layout: document
redirect_from:
- /library/modint/mont.hpp
- /library/modint/mont.hpp.html
title: modint/mont.hpp
---
