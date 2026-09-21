---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://37zigen.com/tonelli-shanks-algorithm/
  dependencies:
  - files:
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/detail/mod_sqrt.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: mont_arb.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont_arb.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: mod_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/mod_sqrt.test.cpp
    - filename: sqrt_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sqrt_mod.test.cpp
    type: Verified with
  dependsOn:
  - math_mod/detail/mod_sqrt.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MOD_MOD_SQRT_HPP\n#define KK2_MATH_MOD_MOD_SQRT_HPP 1\n\
      \n#include <cassert>\n\n#include \"../modint/mont_arb.hpp\"\n#include \"detail/mod_sqrt.hpp\"\
      \n\nnamespace kk2 {\n\n// ref: https://37zigen.com/tonelli-shanks-algorithm/\n\
      template <class T, class U> long long mod_sqrt(const T &a, const U &p) {\n \
      \   assert(0 <= a && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
      \    Mint::setmod(p);\n    return mod_sqrt_detail::mod_sqrt(Mint(a));\n}\n\n\
      } // namespace kk2\n\n#endif // KK2_MATH_MOD_MOD_SQRT_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/mod_sqrt.hpp\"\n\n\n\n#include <cassert>\n\n#line 1\
      \ \"modint/mont_arb.hpp\"\n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n\
      #include <utility>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\
      \nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
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
      \n} // namespace kk2\n\n\n#line 10 \"modint/mont_arb.hpp\"\n\nnamespace kk2\
      \ {\n\ntemplate <typename Int, typename UInt, typename Long, typename ULong,\
      \ int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\
      \n    inline static UInt mod;\n    inline static UInt r;\n    inline static\
      \ UInt n2;\n    static constexpr int bit_length = sizeof(UInt) * 8;\n\n    static\
      \ UInt get_r() {\n        UInt ret = mod;\n        while (mod * ret != 1) ret\
      \ *= UInt(2) - mod * ret;\n        return ret;\n    }\n\n    static void setmod(UInt\
      \ m) {\n        assert(m < (UInt(1u) << (bit_length - 2)));\n        assert(m\
      \ & 1);\n        mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n\n    UInt\
      \ _v;\n\n    ArbitraryLazyMontgomeryModIntBase() : _v(0) {}\n\n    template\
      \ <Integral T>\n    ArbitraryLazyMontgomeryModIntBase(const T &b) : _v(reduce(ULong(b\
      \ % (Int)mod + mod) * n2)) {}\n\n    static UInt reduce(const ULong &b) {\n\
      \        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n    }\n\
      \n    mint &operator+=(const mint &b) {\n        if (Int(_v += b._v - 2 * mod)\
      \ < 0) _v += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
      \ mint &b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return\
      \ *this;\n    }\n\n    mint &operator*=(const mint &b) {\n        _v = reduce(ULong(_v)\
      \ * b._v);\n        return *this;\n    }\n\n    mint &operator/=(const mint\
      \ &b) {\n        *this *= b.inv();\n        return *this;\n    }\n\n    mint\
      \ operator-() const { return mint(0) - mint(*this); }\n    mint operator+()\
      \ const { return mint(*this); }\n    friend mint operator+(const mint &a, const\
      \ mint &b) { return mint(a) += b; }\n    friend mint operator-(const mint &a,\
      \ const mint &b) { return mint(a) -= b; }\n    friend mint operator*(const mint\
      \ &a, const mint &b) { return mint(a) *= b; }\n    friend mint operator/(const\
      \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    bool operator==(const\
      \ mint &b) const {\n        return (_v >= mod ? _v - mod : _v) == (b._v >= mod\
      \ ? b._v - mod : b._v);\n    }\n\n    bool operator!=(const mint &b) const {\n\
      \        return (_v >= mod ? _v - mod : _v) != (b._v >= mod ? b._v - mod : b._v);\n\
      \    }\n\n    template <class T> mint pow(T n) const {\n        mint ret(1),\
      \ mul(*this);\n        n %= (Long)getmod() - 1;\n        while (n > 0) {\n \
      \           if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n \
      \       }\n        return ret;\n    }\n\n    mint inv() const {\n        Int\
      \ s = getmod(), t = val(), m0 = 0, m1 = 1;\n        while (t) {\n          \
      \  Int u = s / t;\n            std::swap(s -= t * u, t);\n            std::swap(m0\
      \ -= m1 * u, m1);\n        }\n        if (m0 < 0) m0 += getmod();\n        return\
      \ mint(m0);\n    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        Long t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n        return\
      \ ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod() { return\
      \ mod; }\n};\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt =\n \
      \   ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
      \ long long, id>;\n\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit\
      \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
      \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/detail/mod_sqrt.hpp\"\
      \n\n\n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
      \n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ S, class T, class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(n >=\
      \ 0);\n    if (m == 1) return S(0);\n    S _m = m, r = 1;\n    S y = x % _m;\n\
      \    if (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) %\
      \ _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n    return r;\n}\n\n}\
      \ // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace\
      \ kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2)\
      \ return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
      \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
      \    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0] =\
      \ 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
      \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x %\
      \ i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\
      \ x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
      \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i <\
      \ cnt; i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) ==\
      \ 1) {\n                ok = false;\n                break;\n            }\n\
      \        }\n        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr\
      \ int primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\
      \n#line 5 \"math_mod/detail/mod_sqrt.hpp\"\n\nnamespace kk2::mod_sqrt_detail\
      \ {\n\ntemplate <class Mint> long long tonelli_shanks(const Mint &a, Mint z,\
      \ long long m, long long e) {\n    Mint x = a.pow((m - 1) / 2);\n    Mint y\
      \ = a * x * x;\n    x *= a;\n    while (y != Mint(1)) {\n        long long j\
      \ = 0;\n        Mint t = y;\n        while (t != Mint(1)) {\n            j++;\n\
      \            t *= t;\n        }\n        z = z.pow(1LL << (e - j - 1));\n  \
      \      x *= z;\n        z *= z;\n        y *= z;\n        e = j;\n    }\n  \
      \  return x.val();\n}\n\ntemplate <bool ntt_friendly = false, class mint> long\
      \ long mod_sqrt(const mint &a) {\n    const auto p = mint::getmod();\n    if\
      \ (a.val() < 2) return a.val();\n\n    // Euler's criterion\n    if (a.pow((p\
      \ - 1) / 2) != mint(1)) return -1;\n\n    mint b;\n    if constexpr (ntt_friendly)\
      \ {\n        b = primitive_root<mint::getmod()>;\n    } else {\n        // Find\
      \ a quadratic non-residue.\n        b = 1;\n        while (b.pow((p - 1) / 2)\
      \ == mint(1)) b += 1;\n    }\n\n    long long m = p - 1, e = 0;\n    while (m\
      \ % 2 == 0) m >>= 1, e++;\n\n    mint z = b.pow(m);\n    return tonelli_shanks(a,\
      \ z, m, e);\n}\n\n} // namespace kk2::mod_sqrt_detail\n\n\n#line 8 \"math_mod/mod_sqrt.hpp\"\
      \n\nnamespace kk2 {\n\n// ref: https://37zigen.com/tonelli-shanks-algorithm/\n\
      template <class T, class U> long long mod_sqrt(const T &a, const U &p) {\n \
      \   assert(0 <= a && a < p);\n    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
      \    Mint::setmod(p);\n    return mod_sqrt_detail::mod_sqrt(Mint(a));\n}\n\n\
      } // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/mod_sqrt.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math_mod/mod_sqrt.test.cpp
  - verify/yosupo_math/sqrt_mod.test.cpp
documentation_of: math_mod/mod_sqrt.hpp
layout: document
---
