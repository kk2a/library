---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':question:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':question:'
    path: string/static_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u5909\u66F4\u304C\u884C\u308F\u308C\u306A\u3044\u6587\
      \u5B57\u5217\u306B\u5BFE\u3059\u308B\u9759\u7684\u306A\u30ED\u30FC\u30EA\u30F3\
      \u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: unionfind/parallel.hpp
    title: unionfind/parallel.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_alds1_14_b.test.cpp
    title: verify/aoj/aoj_alds1_14_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/group/group.test.cpp
    title: verify/unit_test/math/group/group.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/string/static_rolling_hash.test.cpp
    title: verify/unit_test/string/static_rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    title: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - icon: ':x:'
    path: verify/yosupo_string/string_z_roliha.test.cpp
    title: verify/yosupo_string/string_z_roliha.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"modint/modint_2_61m1.hpp\"\n\n\n\n#include <cassert>\n\n\
    #line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value\n          \
    \                        or std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T> using is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
    \ type_traits\n\ntemplate <typename T> using is_standard_istream =\n    typename\
    \ std::conditional<std::is_same<T, std::istream>::value\n                    \
    \              || std::is_same<T, std::ifstream>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"modint/modint_2_61m1.hpp\"\n\nnamespace kk2 {\n\nstruct ModInt2_61m1\
    \ {\n    using mint = ModInt2_61m1;\n    using u64 = unsigned long long;\n   \
    \ constexpr static u64 mod = (1ULL << 61) - 1;\n    constexpr static u64 getmod()\
    \ { return mod; }\n\n    constexpr ModInt2_61m1() : _v(0) {}\n\n    template <class\
    \ T, is_integral_t<T> * = nullptr> constexpr ModInt2_61m1(T x_) {\n        if\
    \ (x_ < 0) {\n            _v = -x_;\n            chmod(_v);\n            _v =\
    \ mod - _v;\n        } else {\n            _v = x_;\n            chmod(_v);\n\
    \        }\n    }\n\n    constexpr mint &operator++() {\n        ++_v;\n     \
    \   if (_v == mod) _v = 0;\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator--() {\n        if (_v == 0) _v = mod;\n        --_v;\n        return\
    \ *this;\n    }\n\n    constexpr mint operator++(int) {\n        mint ret = *this;\n\
    \        ++*this;\n        return ret;\n    }\n\n    constexpr mint operator--(int)\
    \ {\n        mint ret = *this;\n        --*this;\n        return ret;\n    }\n\
    \n    constexpr mint &operator+=(const mint &x) {\n        _v += x._v;\n     \
    \   if (_v >= mod) _v -= mod;\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator-=(const mint &x) {\n        _v += mod - x._v;\n        if (_v >= mod)\
    \ _v -= mod;\n        return *this;\n    }\n\n    constexpr mint &operator*=(const\
    \ mint &x) {\n        _v = mulmod(_v, x._v);\n        return *this;\n    }\n\n\
    \    constexpr mint &operator/=(const mint &x) { return *this *= x.inv(); }\n\
    \    constexpr mint operator+() const { return *this; }\n    constexpr mint operator-()\
    \ const { return mint() - *this; }\n    constexpr bool operator==(const mint &x)\
    \ const { return _v == x._v; }\n    constexpr bool operator!=(const mint &x) const\
    \ { return _v != x._v; }\n    friend constexpr mint operator+(const mint &x, const\
    \ mint &y) { return mint(x) += y; }\n    friend constexpr mint operator-(const\
    \ mint &x, const mint &y) { return mint(x) -= y; }\n    friend constexpr mint\
    \ operator*(const mint &x, const mint &y) { return mint(x) *= y; }\n    friend\
    \ constexpr mint operator/(const mint &x, const mint &y) { return mint(x) /= y;\
    \ }\n\n    template <class T, is_integral_t<T> * = nullptr> constexpr mint pow(T\
    \ n) const {\n        assert(n >= 0);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            if (n >>= 1) x *=\
    \ x;\n        }\n        return r;\n    }\n\n    constexpr mint inv() const {\
    \ return pow(mod - 2); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const mint &x) {\n\
    \        return os << x._v;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, mint &x) {\n     \
    \   u64 y;\n        is >> y;\n        x = mint(y);\n        return is;\n    }\n\
    \n    constexpr u64 val() const { return _v; }\n\n    static constexpr mint mulplus(const\
    \ mint &a, const mint &b, const mint &c) {\n        // a * b + c\n        u64\
    \ ah = a._v >> 31, al = a._v & mask31;\n        u64 bh = b._v >> 31, bl = b._v\
    \ & mask31;\n        u64 m = ah * bl + al * bh;\n        u64 t = 2 * ah * bh +\
    \ al * bl + (m >> 30) + ((m & mask30) << 31) + c._v;\n        mint ret;\n    \
    \    ret._v = chmod(t);\n        return ret;\n    }\n\n    static constexpr mint\
    \ plusmul(const mint &a, const mint &b, const mint &c) {\n        // a + b * c\n\
    \        u64 bh = b._v >> 31, bl = b._v & mask31;\n        u64 ch = c._v >> 31,\
    \ cl = c._v & mask31;\n        u64 m = bh * cl + bl * ch;\n        u64 t = 2 *\
    \ bh * ch + bl * cl + (m >> 30) + ((m & mask30) << 31) + a._v;\n        mint ret;\n\
    \        ret._v = chmod(t);\n        return ret;\n    }\n\n  private:\n    u64\
    \ _v;\n\n    constexpr static u64 chmod(u64 &x) {\n        x = (x & mod) + (x\
    \ >> 61);\n        if (x >= mod) x -= mod;\n        return x;\n    }\n\n    constexpr\
    \ static u64 mask30 = (1ULL << 30) - 1;\n    constexpr static u64 mask31 = (1ULL\
    \ << 31) - 1;\n\n    constexpr static u64 mulmod(u64 x, u64 y) {\n        /*\n\
    \        A = 2^61 - 1, B = 2^31, C = 2^30\n        0 <= x, y < A\n        x =\
    \ xh * B + xl\n        y = yh * B + yl\n        0 <= xh, yh < C\n        0 <=\
    \ xl, yl < B\n\n        m = xh * yl + xl * yh\n        m = mh * C + ml\n     \
    \   m * B = mh + ml * B mod A\n        0 <= mh < 2B\n        0 <= ml < C\n\n \
    \       x * y\n        = xh * yh * B^2 + m * B + xl * yl\n        = xh * yh *\
    \ 2 + mh + ml * B + xl * yl mod A\n\n        xh * yh * 2 <= 2(C - 1)^2 = 2^61\
    \ - 2^32 + 2\n        mh + ml * B <= 2B - 1 + (C - 1) * B = 2^61 + 2^31 - 1\n\
    \        xl * yl <= (B - 1)^2 = 2^62 - 2^32 + 1\n\n        xh * yh * 2 + mh +\
    \ ml * B + xl * yl\n        <= 2^63 - 2^33 + 2^31 + 2\n        */\n        u64\
    \ xh = x >> 31, xl = x & mask31;\n        u64 yh = y >> 31, yl = y & mask31;\n\
    \        u64 m = xh * yl + xl * yh;\n        u64 t = 2 * xh * yh + xl * yl + (m\
    \ >> 30) + ((m & mask30) << 31);\n        return chmod(t);\n    }\n};\n\n} //\
    \ namespace kk2\n\n\n"
  code: "#ifndef KK2_MODINT_MODINT_2_61M1_HPP\n#define KK2_MODINT_MODINT_2_61M1_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../type_traits/integral.hpp\"\n#include\
    \ \"../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nstruct ModInt2_61m1 {\n    using\
    \ mint = ModInt2_61m1;\n    using u64 = unsigned long long;\n    constexpr static\
    \ u64 mod = (1ULL << 61) - 1;\n    constexpr static u64 getmod() { return mod;\
    \ }\n\n    constexpr ModInt2_61m1() : _v(0) {}\n\n    template <class T, is_integral_t<T>\
    \ * = nullptr> constexpr ModInt2_61m1(T x_) {\n        if (x_ < 0) {\n       \
    \     _v = -x_;\n            chmod(_v);\n            _v = mod - _v;\n        }\
    \ else {\n            _v = x_;\n            chmod(_v);\n        }\n    }\n\n \
    \   constexpr mint &operator++() {\n        ++_v;\n        if (_v == mod) _v =\
    \ 0;\n        return *this;\n    }\n\n    constexpr mint &operator--() {\n   \
    \     if (_v == 0) _v = mod;\n        --_v;\n        return *this;\n    }\n\n\
    \    constexpr mint operator++(int) {\n        mint ret = *this;\n        ++*this;\n\
    \        return ret;\n    }\n\n    constexpr mint operator--(int) {\n        mint\
    \ ret = *this;\n        --*this;\n        return ret;\n    }\n\n    constexpr\
    \ mint &operator+=(const mint &x) {\n        _v += x._v;\n        if (_v >= mod)\
    \ _v -= mod;\n        return *this;\n    }\n\n    constexpr mint &operator-=(const\
    \ mint &x) {\n        _v += mod - x._v;\n        if (_v >= mod) _v -= mod;\n \
    \       return *this;\n    }\n\n    constexpr mint &operator*=(const mint &x)\
    \ {\n        _v = mulmod(_v, x._v);\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator/=(const mint &x) { return *this *= x.inv(); }\n    constexpr\
    \ mint operator+() const { return *this; }\n    constexpr mint operator-() const\
    \ { return mint() - *this; }\n    constexpr bool operator==(const mint &x) const\
    \ { return _v == x._v; }\n    constexpr bool operator!=(const mint &x) const {\
    \ return _v != x._v; }\n    friend constexpr mint operator+(const mint &x, const\
    \ mint &y) { return mint(x) += y; }\n    friend constexpr mint operator-(const\
    \ mint &x, const mint &y) { return mint(x) -= y; }\n    friend constexpr mint\
    \ operator*(const mint &x, const mint &y) { return mint(x) *= y; }\n    friend\
    \ constexpr mint operator/(const mint &x, const mint &y) { return mint(x) /= y;\
    \ }\n\n    template <class T, is_integral_t<T> * = nullptr> constexpr mint pow(T\
    \ n) const {\n        assert(n >= 0);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            if (n >>= 1) x *=\
    \ x;\n        }\n        return r;\n    }\n\n    constexpr mint inv() const {\
    \ return pow(mod - 2); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const mint &x) {\n\
    \        return os << x._v;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    friend IStream &operator>>(IStream &is, mint &x) {\n     \
    \   u64 y;\n        is >> y;\n        x = mint(y);\n        return is;\n    }\n\
    \n    constexpr u64 val() const { return _v; }\n\n    static constexpr mint mulplus(const\
    \ mint &a, const mint &b, const mint &c) {\n        // a * b + c\n        u64\
    \ ah = a._v >> 31, al = a._v & mask31;\n        u64 bh = b._v >> 31, bl = b._v\
    \ & mask31;\n        u64 m = ah * bl + al * bh;\n        u64 t = 2 * ah * bh +\
    \ al * bl + (m >> 30) + ((m & mask30) << 31) + c._v;\n        mint ret;\n    \
    \    ret._v = chmod(t);\n        return ret;\n    }\n\n    static constexpr mint\
    \ plusmul(const mint &a, const mint &b, const mint &c) {\n        // a + b * c\n\
    \        u64 bh = b._v >> 31, bl = b._v & mask31;\n        u64 ch = c._v >> 31,\
    \ cl = c._v & mask31;\n        u64 m = bh * cl + bl * ch;\n        u64 t = 2 *\
    \ bh * ch + bl * cl + (m >> 30) + ((m & mask30) << 31) + a._v;\n        mint ret;\n\
    \        ret._v = chmod(t);\n        return ret;\n    }\n\n  private:\n    u64\
    \ _v;\n\n    constexpr static u64 chmod(u64 &x) {\n        x = (x & mod) + (x\
    \ >> 61);\n        if (x >= mod) x -= mod;\n        return x;\n    }\n\n    constexpr\
    \ static u64 mask30 = (1ULL << 30) - 1;\n    constexpr static u64 mask31 = (1ULL\
    \ << 31) - 1;\n\n    constexpr static u64 mulmod(u64 x, u64 y) {\n        /*\n\
    \        A = 2^61 - 1, B = 2^31, C = 2^30\n        0 <= x, y < A\n        x =\
    \ xh * B + xl\n        y = yh * B + yl\n        0 <= xh, yh < C\n        0 <=\
    \ xl, yl < B\n\n        m = xh * yl + xl * yh\n        m = mh * C + ml\n     \
    \   m * B = mh + ml * B mod A\n        0 <= mh < 2B\n        0 <= ml < C\n\n \
    \       x * y\n        = xh * yh * B^2 + m * B + xl * yl\n        = xh * yh *\
    \ 2 + mh + ml * B + xl * yl mod A\n\n        xh * yh * 2 <= 2(C - 1)^2 = 2^61\
    \ - 2^32 + 2\n        mh + ml * B <= 2B - 1 + (C - 1) * B = 2^61 + 2^31 - 1\n\
    \        xl * yl <= (B - 1)^2 = 2^62 - 2^32 + 1\n\n        xh * yh * 2 + mh +\
    \ ml * B + xl * yl\n        <= 2^63 - 2^33 + 2^31 + 2\n        */\n        u64\
    \ xh = x >> 31, xl = x & mask31;\n        u64 yh = y >> 31, yl = y & mask31;\n\
    \        u64 m = xh * yl + xl * yh;\n        u64 t = 2 * xh * yh + xl * yl + (m\
    \ >> 30) + ((m & mask30) << 31);\n        return chmod(t);\n    }\n};\n\n} //\
    \ namespace kk2\n\n#endif // KK2_MODINT_MODINT_2_61M1_HPP\n"
  dependsOn:
  - type_traits/integral.hpp
  - type_traits/io.hpp
  isVerificationFile: false
  path: modint/modint_2_61m1.hpp
  requiredBy:
  - string/static_rolling_hash.hpp
  - string/dynamic_rolling_hash.hpp
  - random/hash.hpp
  - math/group/rolling_hash.hpp
  - unionfind/parallel.hpp
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/math/group/group.test.cpp
documentation_of: modint/modint_2_61m1.hpp
layout: document
redirect_from:
- /library/modint/modint_2_61m1.hpp
- /library/modint/modint_2_61m1.hpp.html
title: modint/modint_2_61m1.hpp
---
