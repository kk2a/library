---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
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
  - files:
    - filename: rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/rolling_hash.hpp
    - filename: euler_phi.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/euler_phi.hpp
    - filename: mobius.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/mobius.hpp
    - filename: sigma.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/sigma.hpp
    - filename: prime_factorize.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_factorize.hpp
    - filename: primitive_root_64bit.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root_64bit.hpp
    - filename: tetration.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/tetration.hpp
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
    type: Required by
  - files:
    - filename: aoj_alds1_14_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    - filename: aoj_ntl_1_d.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_d.test.cpp
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: prime_factorize_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_factorize_table.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: factrize.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/factrize.test.cpp
    - filename: primality_test.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primality_test.test.cpp
    - filename: primitive_root.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primitive_root.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    type: Verified with
  dependsOn:
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  embedded:
  - code: "#ifndef KK2_MATH_IS_PRIME_HPP\n#define KK2_MATH_IS_PRIME_HPP 1\n\n#include\
      \ <vector>\n\n#include \"../math_mod/pow_mod.hpp\"\n#include \"../modint/mont_arb.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace number_theory {\n\ntemplate <class T, class\
      \ U> bool miller_rabin(const T &n, const std::vector<T> &ws) {\n    if (n <=\
      \ 2) return n == 2;\n    if (~n & 1) return false;\n\n    T d = n - 1;\n   \
      \ while (~d & 1) d >>= 1;\n    U e = 1, rev = n - 1;\n    for (T w : ws) {\n\
      \        if (w % n == 0) continue;\n        T t = d;\n        U y = pow_mod<T,\
      \ T, U>(w, t, n);\n        while (t != n - 1 and y != e and y != rev) {\n  \
      \          y = y * y % n;\n            t <<= 1;\n        }\n        if (y !=\
      \ rev and ~t & 1) return false;\n    }\n    return true;\n}\n\nbool miller_rabin_u64(unsigned\
      \ long long n) {\n    return miller_rabin<unsigned long long, __uint128_t>(\n\
      \        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate\
      \ <class mint>\nbool miller_rabin_mont(unsigned long long n, const std::vector<unsigned\
      \ long long> &ws) {\n    if (n <= 2) return n == 2;\n    if (~n & 1) return\
      \ false;\n\n    if (mint::getmod() != n) mint::setmod(n);\n    unsigned long\
      \ long d = n - 1;\n    while (~d & 1) d >>= 1;\n    mint e = 1, rev = n - 1;\n\
      \    for (unsigned long long w : ws) {\n        if (w % n == 0) continue;\n\
      \        unsigned long long t = d;\n        mint y = mint(w).pow(t);\n     \
      \   while (t != n - 1 and y != e and y != rev) {\n            y *= y;\n    \
      \        t <<= 1;\n        }\n        if (y != rev and ~t & 1) return false;\n\
      \    }\n    return true;\n}\n\nbool is_prime(unsigned long long n) {\n    using\
      \ mint32 = ArbitraryLazyMontgomeryModInt<54305750>;\n    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54305750>;\n\
      \n    if (n <= 2) return n == 2;\n    if (~n & 1) return false;\n    if (n <\
      \ (1ull << 30)) {\n        return miller_rabin_mont<mint32>(n, {2, 7, 61});\n\
      \    } else if (n < (1ull << 62)) {\n        return miller_rabin_mont<mint64>(n,\
      \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n    } else {\n     \
      \   return miller_rabin_u64(n);\n    }\n}\n\n}; // namespace number_theory\n\
      \nusing number_theory::is_prime;\n\n}; // namespace kk2\n\n#endif // KK2_MATH_IS_PRIME_HPP\n"
    name: default
  - code: "#line 1 \"math/is_prime.hpp\"\n\n\n\n#include <vector>\n\n#line 1 \"math_mod/pow_mod.hpp\"\
      \n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class S, class T,\
      \ class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(n >= 0);\n    if\
      \ (m == 1) return S(0);\n    S _m = m, r = 1;\n    S y = x % _m;\n    if (y\
      \ < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n   \
      \     if (n >>= 1) y = (y * y) % _m;\n    }\n    return r;\n}\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"modint/mont_arb.hpp\"\n\n\n\n#line 5 \"modint/mont_arb.hpp\"\
      \n#include <iostream>\n#include <utility>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_integral =\n \
      \   typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T> using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
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
      \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T> using\
      \ is_standard_istream =\n    typename std::conditional<std::is_same<T, std::istream>::value\n\
      \                                  || std::is_same<T, std::ifstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_standard_ostream\
      \ =\n    typename std::conditional<std::is_same<T, std::ostream>::value\n  \
      \                                || std::is_same<T, std::ofstream>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
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
      \ <Integral T> ArbitraryLazyMontgomeryModIntBase(const T &b)\n        : _v(reduce(ULong(b\
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
      \ mint(m0);\n    }\n\n    template <OutputStream OStream>\n    friend OStream\
      \ &operator<<(OStream &os, const mint &x) {\n        return os << x.val();\n\
      \    }\n\n    template <InputStream IStream>\n    friend IStream &operator>>(IStream\
      \ &is, mint &x) {\n        Long t;\n        is >> t;\n        x = mint(t);\n\
      \        return (is);\n    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n\
      \        return ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod()\
      \ { return mod; }\n};\n\ntemplate <int id> using ArbitraryLazyMontgomeryModInt\
      \ =\n    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
      \ long long, id>;\n\ntemplate <int id> using ArbitraryLazyMontgomeryModInt64bit\
      \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
      \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 8 \"math/is_prime.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace number_theory {\n\ntemplate <class T, class\
      \ U> bool miller_rabin(const T &n, const std::vector<T> &ws) {\n    if (n <=\
      \ 2) return n == 2;\n    if (~n & 1) return false;\n\n    T d = n - 1;\n   \
      \ while (~d & 1) d >>= 1;\n    U e = 1, rev = n - 1;\n    for (T w : ws) {\n\
      \        if (w % n == 0) continue;\n        T t = d;\n        U y = pow_mod<T,\
      \ T, U>(w, t, n);\n        while (t != n - 1 and y != e and y != rev) {\n  \
      \          y = y * y % n;\n            t <<= 1;\n        }\n        if (y !=\
      \ rev and ~t & 1) return false;\n    }\n    return true;\n}\n\nbool miller_rabin_u64(unsigned\
      \ long long n) {\n    return miller_rabin<unsigned long long, __uint128_t>(\n\
      \        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate\
      \ <class mint>\nbool miller_rabin_mont(unsigned long long n, const std::vector<unsigned\
      \ long long> &ws) {\n    if (n <= 2) return n == 2;\n    if (~n & 1) return\
      \ false;\n\n    if (mint::getmod() != n) mint::setmod(n);\n    unsigned long\
      \ long d = n - 1;\n    while (~d & 1) d >>= 1;\n    mint e = 1, rev = n - 1;\n\
      \    for (unsigned long long w : ws) {\n        if (w % n == 0) continue;\n\
      \        unsigned long long t = d;\n        mint y = mint(w).pow(t);\n     \
      \   while (t != n - 1 and y != e and y != rev) {\n            y *= y;\n    \
      \        t <<= 1;\n        }\n        if (y != rev and ~t & 1) return false;\n\
      \    }\n    return true;\n}\n\nbool is_prime(unsigned long long n) {\n    using\
      \ mint32 = ArbitraryLazyMontgomeryModInt<54305750>;\n    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54305750>;\n\
      \n    if (n <= 2) return n == 2;\n    if (~n & 1) return false;\n    if (n <\
      \ (1ull << 30)) {\n        return miller_rabin_mont<mint32>(n, {2, 7, 61});\n\
      \    } else if (n < (1ull << 62)) {\n        return miller_rabin_mont<mint64>(n,\
      \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n    } else {\n     \
      \   return miller_rabin_u64(n);\n    }\n}\n\n}; // namespace number_theory\n\
      \nusing number_theory::is_prime;\n\n}; // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/is_prime.hpp
  pathExtension: hpp
  requiredBy:
  - math/group/rolling_hash.hpp
  - math/multiplicative_function/euler_phi.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/sigma.hpp
  - math/prime_factorize.hpp
  - math_mod/primitive_root_64bit.hpp
  - math_mod/tetration.hpp
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - unionfind/parallel.hpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/prime_factorize_table.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
documentation_of: math/is_prime.hpp
layout: document
---
