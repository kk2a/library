---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files:
    - filename: rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/rolling_hash.hpp
    - filename: hash.hpp
      icon: LIBRARY_ALL_AC
      path: random/hash.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
    - filename: static_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/static_rolling_hash.hpp
    - filename: parallel.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/parallel.hpp
    - filename: aoj_alds1_14_b.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    type: Required by
  - files:
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MODINT_MODINT_2_61M1_HPP\n#define KK2_MODINT_MODINT_2_61M1_HPP\
      \ 1\n\n#include <cassert>\n\n#include \"../type_traits/integral.hpp\"\n#include\
      \ \"../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nstruct ModInt2_61m1 {\n  \
      \  using mint = ModInt2_61m1;\n    using u64 = unsigned long long;\n    constexpr\
      \ static u64 mod = (1ULL << 61) - 1;\n    constexpr static u64 getmod() { return\
      \ mod; }\n\n    constexpr ModInt2_61m1() : _v(0) {}\n\n    template <Integral\
      \ T> constexpr ModInt2_61m1(T x_) {\n        if (x_ < 0) {\n            _v =\
      \ -x_;\n            chmod(_v);\n            _v = mod - _v;\n        } else {\n\
      \            _v = x_;\n            chmod(_v);\n        }\n    }\n\n    constexpr\
      \ mint &operator++() {\n        ++_v;\n        if (_v == mod) _v = 0;\n    \
      \    return *this;\n    }\n\n    constexpr mint &operator--() {\n        if\
      \ (_v == 0) _v = mod;\n        --_v;\n        return *this;\n    }\n\n    constexpr\
      \ mint operator++(int) {\n        mint ret = *this;\n        ++*this;\n    \
      \    return ret;\n    }\n\n    constexpr mint operator--(int) {\n        mint\
      \ ret = *this;\n        --*this;\n        return ret;\n    }\n\n    constexpr\
      \ mint &operator+=(const mint &x) {\n        _v += x._v;\n        if (_v >=\
      \ mod) _v -= mod;\n        return *this;\n    }\n\n    constexpr mint &operator-=(const\
      \ mint &x) {\n        _v += mod - x._v;\n        if (_v >= mod) _v -= mod;\n\
      \        return *this;\n    }\n\n    constexpr mint &operator*=(const mint &x)\
      \ {\n        _v = mulmod(_v, x._v);\n        return *this;\n    }\n\n    constexpr\
      \ mint &operator/=(const mint &x) { return *this *= x.inv(); }\n    constexpr\
      \ mint operator+() const { return *this; }\n    constexpr mint operator-() const\
      \ { return mint() - *this; }\n    constexpr bool operator==(const mint &x) const\
      \ { return _v == x._v; }\n    constexpr bool operator!=(const mint &x) const\
      \ { return _v != x._v; }\n    friend constexpr mint operator+(const mint &x,\
      \ const mint &y) { return mint(x) += y; }\n    friend constexpr mint operator-(const\
      \ mint &x, const mint &y) { return mint(x) -= y; }\n    friend constexpr mint\
      \ operator*(const mint &x, const mint &y) { return mint(x) *= y; }\n    friend\
      \ constexpr mint operator/(const mint &x, const mint &y) { return mint(x) /=\
      \ y; }\n\n    template <Integral T> constexpr mint pow(T n) const {\n      \
      \  assert(n >= 0);\n        mint x = *this, r = 1;\n        while (n) {\n  \
      \          if (n & 1) r *= x;\n            if (n >>= 1) x *= x;\n        }\n\
      \        return r;\n    }\n\n    constexpr mint inv() const { return pow(mod\
      \ - 2); }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x._v;\n    }\n\n    template <InputStream\
      \ IStream> friend IStream &operator>>(IStream &is, mint &x) {\n        u64 y;\n\
      \        is >> y;\n        x = mint(y);\n        return is;\n    }\n\n    constexpr\
      \ u64 val() const { return _v; }\n\n    static constexpr mint mulplus(const\
      \ mint &a, const mint &b, const mint &c) {\n        // a * b + c\n        u64\
      \ ah = a._v >> 31, al = a._v & mask31;\n        u64 bh = b._v >> 31, bl = b._v\
      \ & mask31;\n        u64 m = ah * bl + al * bh;\n        u64 t = 2 * ah * bh\
      \ + al * bl + (m >> 30) + ((m & mask30) << 31) + c._v;\n        mint ret;\n\
      \        ret._v = chmod(t);\n        return ret;\n    }\n\n    static constexpr\
      \ mint plusmul(const mint &a, const mint &b, const mint &c) {\n        // a\
      \ + b * c\n        u64 bh = b._v >> 31, bl = b._v & mask31;\n        u64 ch\
      \ = c._v >> 31, cl = c._v & mask31;\n        u64 m = bh * cl + bl * ch;\n  \
      \      u64 t = 2 * bh * ch + bl * cl + (m >> 30) + ((m & mask30) << 31) + a._v;\n\
      \        mint ret;\n        ret._v = chmod(t);\n        return ret;\n    }\n\
      \n  private:\n    u64 _v;\n\n    constexpr static u64 chmod(u64 &x) {\n    \
      \    x = (x & mod) + (x >> 61);\n        if (x >= mod) x -= mod;\n        return\
      \ x;\n    }\n\n    constexpr static u64 mask30 = (1ULL << 30) - 1;\n    constexpr\
      \ static u64 mask31 = (1ULL << 31) - 1;\n\n    constexpr static u64 mulmod(u64\
      \ x, u64 y) {\n        /*\n        A = 2^61 - 1, B = 2^31, C = 2^30\n      \
      \  0 <= x, y < A\n        x = xh * B + xl\n        y = yh * B + yl\n       \
      \ 0 <= xh, yh < C\n        0 <= xl, yl < B\n\n        m = xh * yl + xl * yh\n\
      \        m = mh * C + ml\n        m * B = mh + ml * B mod A\n        0 <= mh\
      \ < 2B\n        0 <= ml < C\n\n        x * y\n        = xh * yh * B^2 + m *\
      \ B + xl * yl\n        = xh * yh * 2 + mh + ml * B + xl * yl mod A\n\n     \
      \   xh * yh * 2 <= 2(C - 1)^2 = 2^61 - 2^32 + 2\n        mh + ml * B <= 2B -\
      \ 1 + (C - 1) * B = 2^61 + 2^31 - 1\n        xl * yl <= (B - 1)^2 = 2^62 - 2^32\
      \ + 1\n\n        xh * yh * 2 + mh + ml * B + xl * yl\n        <= 2^63 - 2^33\
      \ + 2^31 + 2\n        */\n        u64 xh = x >> 31, xl = x & mask31;\n     \
      \   u64 yh = y >> 31, yl = y & mask31;\n        u64 m = xh * yl + xl * yh;\n\
      \        u64 t = 2 * xh * yh + xl * yl + (m >> 30) + ((m & mask30) << 31);\n\
      \        return chmod(t);\n    }\n};\n\n} // namespace kk2\n\n#endif // KK2_MODINT_MODINT_2_61M1_HPP\n"
    name: default
  - code: "#line 1 \"modint/modint_2_61m1.hpp\"\n\n\n\n#include <cassert>\n\n#line\
      \ 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
      \ kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
      \ = typename std::conditional<std::is_same<T, __int128_t>::value\n         \
      \                                              or std::is_same<T, __int128>::value,\n\
      \                                                   std::true_type,\n      \
      \                                             std::false_type>::type;\n\ntemplate\
      \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value\n                                  or std::is_same<T,\
      \ unsigned __int128>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
      \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed = typename\
      \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
      \                                            std::true_type,\n             \
      \                               std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <concepts>\n\
      #include <fstream>\n#include <istream>\n#include <ostream>\n#line 9 \"type_traits/io.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T>\nusing\
      \ is_standard_istream = typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ifstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T>\nusing is_standard_ostream\
      \ = typename std::conditional<std::is_same<T, std::ostream>::value\n       \
      \                                                   || std::is_same<T, std::ofstream>::value,\n\
      \                                                      std::true_type,\n   \
      \                                                   std::false_type>::type;\n\
      template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
      \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
      \ T>;\n\ntemplate <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 8 \"modint/modint_2_61m1.hpp\"\n\nnamespace\
      \ kk2 {\n\nstruct ModInt2_61m1 {\n    using mint = ModInt2_61m1;\n    using\
      \ u64 = unsigned long long;\n    constexpr static u64 mod = (1ULL << 61) - 1;\n\
      \    constexpr static u64 getmod() { return mod; }\n\n    constexpr ModInt2_61m1()\
      \ : _v(0) {}\n\n    template <Integral T> constexpr ModInt2_61m1(T x_) {\n \
      \       if (x_ < 0) {\n            _v = -x_;\n            chmod(_v);\n     \
      \       _v = mod - _v;\n        } else {\n            _v = x_;\n           \
      \ chmod(_v);\n        }\n    }\n\n    constexpr mint &operator++() {\n     \
      \   ++_v;\n        if (_v == mod) _v = 0;\n        return *this;\n    }\n\n\
      \    constexpr mint &operator--() {\n        if (_v == 0) _v = mod;\n      \
      \  --_v;\n        return *this;\n    }\n\n    constexpr mint operator++(int)\
      \ {\n        mint ret = *this;\n        ++*this;\n        return ret;\n    }\n\
      \n    constexpr mint operator--(int) {\n        mint ret = *this;\n        --*this;\n\
      \        return ret;\n    }\n\n    constexpr mint &operator+=(const mint &x)\
      \ {\n        _v += x._v;\n        if (_v >= mod) _v -= mod;\n        return\
      \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &x) {\n       \
      \ _v += mod - x._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
      \    }\n\n    constexpr mint &operator*=(const mint &x) {\n        _v = mulmod(_v,\
      \ x._v);\n        return *this;\n    }\n\n    constexpr mint &operator/=(const\
      \ mint &x) { return *this *= x.inv(); }\n    constexpr mint operator+() const\
      \ { return *this; }\n    constexpr mint operator-() const { return mint() -\
      \ *this; }\n    constexpr bool operator==(const mint &x) const { return _v ==\
      \ x._v; }\n    constexpr bool operator!=(const mint &x) const { return _v !=\
      \ x._v; }\n    friend constexpr mint operator+(const mint &x, const mint &y)\
      \ { return mint(x) += y; }\n    friend constexpr mint operator-(const mint &x,\
      \ const mint &y) { return mint(x) -= y; }\n    friend constexpr mint operator*(const\
      \ mint &x, const mint &y) { return mint(x) *= y; }\n    friend constexpr mint\
      \ operator/(const mint &x, const mint &y) { return mint(x) /= y; }\n\n    template\
      \ <Integral T> constexpr mint pow(T n) const {\n        assert(n >= 0);\n  \
      \      mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r\
      \ *= x;\n            if (n >>= 1) x *= x;\n        }\n        return r;\n  \
      \  }\n\n    constexpr mint inv() const { return pow(mod - 2); }\n\n    template\
      \ <OutputStream OStream> friend OStream &operator<<(OStream &os, const mint\
      \ &x) {\n        return os << x._v;\n    }\n\n    template <InputStream IStream>\
      \ friend IStream &operator>>(IStream &is, mint &x) {\n        u64 y;\n     \
      \   is >> y;\n        x = mint(y);\n        return is;\n    }\n\n    constexpr\
      \ u64 val() const { return _v; }\n\n    static constexpr mint mulplus(const\
      \ mint &a, const mint &b, const mint &c) {\n        // a * b + c\n        u64\
      \ ah = a._v >> 31, al = a._v & mask31;\n        u64 bh = b._v >> 31, bl = b._v\
      \ & mask31;\n        u64 m = ah * bl + al * bh;\n        u64 t = 2 * ah * bh\
      \ + al * bl + (m >> 30) + ((m & mask30) << 31) + c._v;\n        mint ret;\n\
      \        ret._v = chmod(t);\n        return ret;\n    }\n\n    static constexpr\
      \ mint plusmul(const mint &a, const mint &b, const mint &c) {\n        // a\
      \ + b * c\n        u64 bh = b._v >> 31, bl = b._v & mask31;\n        u64 ch\
      \ = c._v >> 31, cl = c._v & mask31;\n        u64 m = bh * cl + bl * ch;\n  \
      \      u64 t = 2 * bh * ch + bl * cl + (m >> 30) + ((m & mask30) << 31) + a._v;\n\
      \        mint ret;\n        ret._v = chmod(t);\n        return ret;\n    }\n\
      \n  private:\n    u64 _v;\n\n    constexpr static u64 chmod(u64 &x) {\n    \
      \    x = (x & mod) + (x >> 61);\n        if (x >= mod) x -= mod;\n        return\
      \ x;\n    }\n\n    constexpr static u64 mask30 = (1ULL << 30) - 1;\n    constexpr\
      \ static u64 mask31 = (1ULL << 31) - 1;\n\n    constexpr static u64 mulmod(u64\
      \ x, u64 y) {\n        /*\n        A = 2^61 - 1, B = 2^31, C = 2^30\n      \
      \  0 <= x, y < A\n        x = xh * B + xl\n        y = yh * B + yl\n       \
      \ 0 <= xh, yh < C\n        0 <= xl, yl < B\n\n        m = xh * yl + xl * yh\n\
      \        m = mh * C + ml\n        m * B = mh + ml * B mod A\n        0 <= mh\
      \ < 2B\n        0 <= ml < C\n\n        x * y\n        = xh * yh * B^2 + m *\
      \ B + xl * yl\n        = xh * yh * 2 + mh + ml * B + xl * yl mod A\n\n     \
      \   xh * yh * 2 <= 2(C - 1)^2 = 2^61 - 2^32 + 2\n        mh + ml * B <= 2B -\
      \ 1 + (C - 1) * B = 2^61 + 2^31 - 1\n        xl * yl <= (B - 1)^2 = 2^62 - 2^32\
      \ + 1\n\n        xh * yh * 2 + mh + ml * B + xl * yl\n        <= 2^63 - 2^33\
      \ + 2^31 + 2\n        */\n        u64 xh = x >> 31, xl = x & mask31;\n     \
      \   u64 yh = y >> 31, yl = y & mask31;\n        u64 m = xh * yl + xl * yh;\n\
      \        u64 t = 2 * xh * yh + xl * yl + (m >> 30) + ((m & mask30) << 31);\n\
      \        return chmod(t);\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: modint/modint_2_61m1.hpp
  pathExtension: hpp
  requiredBy:
  - math/group/rolling_hash.hpp
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - unionfind/parallel.hpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
documentation_of: modint/modint_2_61m1.hpp
layout: document
---
