---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':question:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root_64bit.hpp
    title: math_mod/primitive_root_64bit.hpp
  - icon: ':question:'
    path: modint/modint_2_61m1.hpp
    title: modint/modint_2_61m1.hpp
  - icon: ':question:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/hash.hpp
    title: random/hash.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':heavy_check_mark:'
    path: string/dynamic_rolling_hash.hpp
    title: "\u6587\u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\
      \u5217\u306B\u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\
      \u30CF\u30C3\u30B7\u30E5"
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/container_traits.hpp
    title: type_traits/container_traits.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/string/dynamic_rolling_hash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#line 1 \"string/dynamic_rolling_hash.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"bit/bitcount.hpp\"\n\
    \n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\
    \n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
    \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
    \n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\n\
    template <typename T> constexpr int ctz(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
    \ __builtin_ctz(x);\n    } else if constexpr (sizeof(T) <= 8) {\n        return\
    \ __builtin_ctzll(x);\n    } else {\n        if (x & 0xffffffffffffffff)\n   \
    \         return __builtin_ctzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \        return 64 + __builtin_ctzll((unsigned long long)(x >> 64));\n    }\n\
    }\n\ntemplate <typename T> constexpr int lsb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <typename T> constexpr\
    \ int clz(T x) {\n    static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n \
    \   } else {\n        if (x >> 64) return __builtin_clzll((unsigned long long)(x\
    \ >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> constexpr int msb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate\
    \ <typename T> constexpr int popcount(T x) {\n    static_assert(is_integral<T>::value);\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_popcount(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_popcountll(x);\n\
    \    } else {\n        return __builtin_popcountll((unsigned long long)(x >> 64))\n\
    \               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 1 \"random/hash.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <array>\n#line 7 \"random/hash.hpp\"\n\n#line 1 \"math_mod/primitive_root_64bit.hpp\"\
    \n\n\n\n#line 1 \"math/prime_factorize.hpp\"\n\n\n\n#line 5 \"math/prime_factorize.hpp\"\
    \n#include <map>\n#include <numeric>\n#include <utility>\n#line 9 \"math/prime_factorize.hpp\"\
    \n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m\
    \ = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n \
    \       if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n\
    \    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont_arb.hpp\"\
    \n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n#line 7 \"modint/mont_arb.hpp\"\
    \n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
    #line 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\
    \nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
    \ntemplate <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 10 \"modint/mont_arb.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename\
    \ Int, typename UInt, typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\n    inline static\
    \ UInt mod;\n    inline static UInt r;\n    inline static UInt n2;\n    static\
    \ constexpr int bit_length = sizeof(UInt) * 8;\n\n    static UInt get_r() {\n\
    \        UInt ret = mod;\n        while (mod * ret != 1) ret *= UInt(2) - mod\
    \ * ret;\n        return ret;\n    }\n\n    static void setmod(UInt m) {\n   \
    \     assert(m < (UInt(1u) << (bit_length - 2)));\n        assert(m & 1);\n  \
    \      mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n\n    UInt _v;\n\n  \
    \  ArbitraryLazyMontgomeryModIntBase() : _v(0) {}\n\n    template <class T, is_integral_t<T>\
    \ * = nullptr> ArbitraryLazyMontgomeryModIntBase(const T &b)\n        : _v(reduce(ULong(b\
    \ % (Int)mod + mod) * n2)) {}\n\n    static UInt reduce(const ULong &b) {\n  \
    \      return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n    }\n\n\
    \    mint &operator+=(const mint &b) {\n        if (Int(_v += b._v - 2 * mod)\
    \ < 0) _v += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
    \ mint &b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return\
    \ *this;\n    }\n\n    mint &operator*=(const mint &b) {\n        _v = reduce(ULong(_v)\
    \ * b._v);\n        return *this;\n    }\n\n    mint &operator/=(const mint &b)\
    \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n    mint operator-()\
    \ const { return mint(0) - mint(*this); }\n    mint operator+() const { return\
    \ mint(*this); }\n    friend mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n    friend mint operator-(const mint &a, const mint &b) { return\
    \ mint(a) -= b; }\n    friend mint operator*(const mint &a, const mint &b) { return\
    \ mint(a) *= b; }\n    friend mint operator/(const mint &a, const mint &b) { return\
    \ mint(a) /= b; }\n\n    bool operator==(const mint &b) const {\n        return\
    \ (_v >= mod ? _v - mod : _v) == (b._v >= mod ? b._v - mod : b._v);\n    }\n\n\
    \    bool operator!=(const mint &b) const {\n        return (_v >= mod ? _v -\
    \ mod : _v) != (b._v >= mod ? b._v - mod : b._v);\n    }\n\n    template <class\
    \ T> mint pow(T n) const {\n        mint ret(1), mul(*this);\n        n %= (Long)getmod()\
    \ - 1;\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n        \
    \    if (n >>= 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    mint\
    \ inv() const {\n        Int s = getmod(), t = val(), m0 = 0, m1 = 1;\n      \
    \  while (t) {\n            Int u = s / t;\n            std::swap(s -= t * u,\
    \ t);\n            std::swap(m0 -= m1 * u, m1);\n        }\n        if (m0 < 0)\
    \ m0 += getmod();\n        return mint(m0);\n    }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream &os,\
    \ const mint &x) {\n        return os << x.val();\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        Long t;\n        is >> t;\n        x = mint(t);\n \
    \       return (is);\n    }\n\n    UInt val() const {\n        UInt ret = reduce(_v);\n\
    \        return ret >= mod ? ret - mod : ret;\n    }\n\n    static UInt getmod()\
    \ { return mod; }\n};\n\ntemplate <int id> using ArbitraryLazyMontgomeryModInt\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long, unsigned\
    \ long long, id>;\n\ntemplate <int id> using ArbitraryLazyMontgomeryModInt64bit\
    \ =\n    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\
    \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\
    \n#line 7 \"random/gen.hpp\"\n#include <random>\n#include <unordered_set>\n#line\
    \ 10 \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\
    \nnamespace kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\n\
    inline u64 non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
    \                   std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\ninline u64 deterministic_seed() { return 5801799128519729247ull;\
    \ }\n\ninline u64 seed() {\n#if defined(KK2_RANDOM_DETERMINISTIC)\n    return\
    \ deterministic_seed();\n#else\n    return non_deterministic_seed();\n#endif\n\
    }\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 12 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\ninline u64 rng() {\n    static std::mt19937_64 mt(kk2::random::seed());\n\
    \    return mt();\n}\n\n// [l, r)\ninline i64 rng(i64 l, i64 r) {\n    assert(l\
    \ < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\ntemplate <class T> std::vector<T>\
    \ random_vector(int n, T l, T r) {\n    std::vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n}\n\n// [l, r)\nstd::vector<i64>\
    \ distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l < r and n <= r - l);\n   \
    \ std::unordered_set<i64> st;\n    for (i64 i = n; i; --i) {\n        i64 m =\
    \ rng(l, r + 1 - i);\n        if (st.find(m) != st.end()) m = r - i;\n       \
    \ st.insert(m);\n    }\n    std::vector<i64> res(st.begin(), st.end());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class Iter> void shuffle(Iter first,\
    \ Iter last) {\n    if (first == last) return;\n    int len = 1;\n    for (auto\
    \ it = first + 1; it != last; ++it) {\n        len++;\n        int j = rng(0,\
    \ len);\n        if (j != len - 1) std::iter_swap(first + j, it);\n    }\n}\n\n\
    template <class T> std::vector<T> perm(int n) {\n    std::vector<T> res(n);\n\
    \    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(), res.end());\n\
    \    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int l, int r,\
    \ int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r - l);\n\
    \    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(), res.end());\n\
    \    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"math/is_prime.hpp\"\n\n\n\n#line 5 \"math/is_prime.hpp\"\n\
    \n#line 8 \"math/is_prime.hpp\"\n\nnamespace kk2 {\n\nnamespace number_theory\
    \ {\n\ntemplate <class T, class U> bool miller_rabin(const T &n, const std::vector<T>\
    \ &ws) {\n    if (n <= 2) return n == 2;\n    if (~n & 1) return false;\n\n  \
    \  T d = n - 1;\n    while (~d & 1) d >>= 1;\n    U e = 1, rev = n - 1;\n    for\
    \ (T w : ws) {\n        if (w % n == 0) continue;\n        T t = d;\n        U\
    \ y = pow_mod<T, T, U>(w, t, n);\n        while (t != n - 1 and y != e and y !=\
    \ rev) {\n            y = y * y % n;\n            t <<= 1;\n        }\n      \
    \  if (y != rev and ~t & 1) return false;\n    }\n    return true;\n}\n\nbool\
    \ miller_rabin_u64(unsigned long long n) {\n    return miller_rabin<unsigned long\
    \ long, __uint128_t>(\n        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n\
    }\n\ntemplate <class mint>\nbool miller_rabin_mont(unsigned long long n, const\
    \ std::vector<unsigned long long> &ws) {\n    if (n <= 2) return n == 2;\n   \
    \ if (~n & 1) return false;\n\n    if (mint::getmod() != n) mint::setmod(n);\n\
    \    unsigned long long d = n - 1;\n    while (~d & 1) d >>= 1;\n    mint e =\
    \ 1, rev = n - 1;\n    for (unsigned long long w : ws) {\n        if (w % n ==\
    \ 0) continue;\n        unsigned long long t = d;\n        mint y = mint(w).pow(t);\n\
    \        while (t != n - 1 and y != e and y != rev) {\n            y *= y;\n \
    \           t <<= 1;\n        }\n        if (y != rev and ~t & 1) return false;\n\
    \    }\n    return true;\n}\n\nbool is_prime(unsigned long long n) {\n    using\
    \ mint32 = ArbitraryLazyMontgomeryModInt<54305750>;\n    using mint64 = ArbitraryLazyMontgomeryModInt64bit<54305750>;\n\
    \n    if (n <= 2) return n == 2;\n    if (~n & 1) return false;\n    if (n < (1ull\
    \ << 30)) {\n        return miller_rabin_mont<mint32>(n, {2, 7, 61});\n    } else\
    \ if (n < (1ull << 62)) {\n        return miller_rabin_mont<mint64>(n, {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022});\n    } else {\n        return miller_rabin_u64(n);\n\
    \    }\n}\n\n}; // namespace number_theory\n\nusing number_theory::is_prime;\n\
    \n}; // namespace kk2\n\n\n#line 14 \"math/prime_factorize.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace number_theory {\n\nusing i64 = long long;\nusing u64 = unsigned\
    \ long long;\n\ntemplate <class mint, class T> T pollard_rho(T n) {\n    if (~n\
    \ & 1) return 2;\n    if (is_prime(n)) return n;\n    if (mint::getmod() != n)\
    \ mint::setmod(n);\n\n    mint R, one = 1;\n    auto f = [&](mint x) {\n     \
    \   return x * x + R;\n    };\n    auto _rng = [&]() {\n        return kk2::random::rng(2,\
    \ n);\n    };\n    while (true) {\n        mint x, y, ys, q = one;\n        R\
    \ = _rng(), y = _rng();\n        T g = 1;\n        constexpr int m = 128;\n  \
    \      for (int r = 1; g == 1; r <<= 1) {\n            x = y;\n            for\
    \ (int i = 0; i < r; i++) y = f(y);\n            for (int k = 0; k < r && g ==\
    \ 1; k += m) {\n                ys = y;\n                for (int i = 0; i < std::min(m,\
    \ r - k); i++) {\n                    y = f(y);\n                    q *= x -\
    \ y;\n                }\n                g = std::gcd(q.val(), n);\n         \
    \   }\n        }\n        if (g == n) do {\n                ys = f(ys);\n    \
    \            g = std::gcd((x - ys).val(), n);\n            } while (g == 1);\n\
    \        if (g != n) return g;\n    }\n    exit(1);\n}\n\nstd::vector<i64> inner_factorize(i64\
    \ n) {\n    using mint32 = ArbitraryLazyMontgomeryModInt<54355165>;\n    using\
    \ mint64 = ArbitraryLazyMontgomeryModInt64bit<54355165>;\n    assert(n);\n   \
    \ if (n < 0) n = -n;\n    if (n == 1) return {};\n    u64 p;\n    if (n <= (1ll\
    \ << 30)) {\n        p = pollard_rho<mint32, unsigned int>(n);\n    } else if\
    \ (n <= (1ll << 62)) {\n        p = pollard_rho<mint64, unsigned long long>(n);\n\
    \    } else {\n        exit(1);\n    }\n    if (i64(p) == n) return {i64(p)};\n\
    \    auto l = inner_factorize(p);\n    auto r = inner_factorize(n / p);\n    std::copy(r.begin(),\
    \ r.end(), std::back_inserter(l));\n    return l;\n}\n\nstd::vector<std::pair<i64,\
    \ int>> factorize(i64 n) {\n    auto tmp = inner_factorize(n);\n    std::sort(tmp.begin(),\
    \ tmp.end());\n    std::vector<std::pair<i64, int>> res;\n    for (int i = 0;\
    \ i < (int)tmp.size(); i++) {\n        if (i == 0 or res.back().first != tmp[i])\
    \ {\n            res.emplace_back(tmp[i], 1);\n        } else {\n            res.back().second++;\n\
    \        }\n    }\n    return res;\n}\n\nstd::map<i64, int> factorize_map(i64\
    \ n) {\n    auto tmp = inner_factorize(n);\n    std::map<i64, int> res;\n    for\
    \ (auto x : tmp) res[x]++;\n    return res;\n}\n\nstd::vector<i64> divisors(i64\
    \ n) {\n    if (n == 0) return {};\n\n    auto f = factorize(n);\n    std::vector<i64>\
    \ res = {1};\n    for (auto [p, k] : f) {\n        int sz = res.size();\n    \
    \    i64 x = 1;\n        for (int i = 0; i < k; i++) {\n            x *= p;\n\
    \            for (int j = 0; j < sz; j++) { res.emplace_back(res[j] * x); }\n\
    \        }\n    }\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\
    \n} // namespace number_theory\n\nusing number_theory::divisors;\nusing number_theory::factorize;\n\
    using number_theory::factorize_map;\n\n} // namespace kk2\n\n\n\n#line 7 \"math_mod/primitive_root_64bit.hpp\"\
    \n\nnamespace kk2 {\n\nlong long primitive_root_64bit(long long p) {\n    if (p\
    \ == 2) return 1;\n    if (p == 3) return 2;\n\n    auto f = factorize(p - 1);\n\
    \    for (long long g{}; g = random::rng(2, p - 1), 1;) {\n        if ([&]() {\n\
    \                for (auto &&[q, e] : f)\n                    if (pow_mod<__int128_t>(g,\
    \ (p - 1) / q, p) == 1) return false;\n                return true;\n        \
    \    }())\n            return g;\n    }\n    return -1;\n}\n\ntemplate <class\
    \ mint> long long primitive_root_mint() {\n    if (mint::getmod() == 2u) return\
    \ 1;\n    if (mint::getmod() == 3u) return 2;\n\n    long long p = mint::getmod();\n\
    \n    auto f = factorize(p - 1);\n    for (mint g; g = random::rng(2, p - 1),\
    \ 1;) {\n        if ([&]() {\n                for (auto &&[q, e] : f)\n      \
    \              if (g.pow((p - 1) / q) == mint(1)) return false;\n            \
    \    return true;\n            }())\n            return g.val();\n    }\n    return\
    \ -1;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/modint_2_61m1.hpp\"\n\n\n\
    \n#line 5 \"modint/modint_2_61m1.hpp\"\n\n#line 8 \"modint/modint_2_61m1.hpp\"\
    \n\nnamespace kk2 {\n\nstruct ModInt2_61m1 {\n    using mint = ModInt2_61m1;\n\
    \    using u64 = unsigned long long;\n    constexpr static u64 mod = (1ULL <<\
    \ 61) - 1;\n    constexpr static u64 getmod() { return mod; }\n\n    constexpr\
    \ ModInt2_61m1() : _v(0) {}\n\n    template <class T, is_integral_t<T> * = nullptr>\
    \ constexpr ModInt2_61m1(T x_) {\n        if (x_ < 0) {\n            _v = -x_;\n\
    \            chmod(_v);\n            _v = mod - _v;\n        } else {\n      \
    \      _v = x_;\n            chmod(_v);\n        }\n    }\n\n    constexpr mint\
    \ &operator++() {\n        ++_v;\n        if (_v == mod) _v = 0;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator--() {\n        if (_v == 0) _v\
    \ = mod;\n        --_v;\n        return *this;\n    }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        ++*this;\n        return ret;\n    }\n\
    \n    constexpr mint operator--(int) {\n        mint ret = *this;\n        --*this;\n\
    \        return ret;\n    }\n\n    constexpr mint &operator+=(const mint &x) {\n\
    \        _v += x._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &x) {\n        _v += mod -\
    \ x._v;\n        if (_v >= mod) _v -= mod;\n        return *this;\n    }\n\n \
    \   constexpr mint &operator*=(const mint &x) {\n        _v = mulmod(_v, x._v);\n\
    \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &x)\
    \ { return *this *= x.inv(); }\n    constexpr mint operator+() const { return\
    \ *this; }\n    constexpr mint operator-() const { return mint() - *this; }\n\
    \    constexpr bool operator==(const mint &x) const { return _v == x._v; }\n \
    \   constexpr bool operator!=(const mint &x) const { return _v != x._v; }\n  \
    \  friend constexpr mint operator+(const mint &x, const mint &y) { return mint(x)\
    \ += y; }\n    friend constexpr mint operator-(const mint &x, const mint &y) {\
    \ return mint(x) -= y; }\n    friend constexpr mint operator*(const mint &x, const\
    \ mint &y) { return mint(x) *= y; }\n    friend constexpr mint operator/(const\
    \ mint &x, const mint &y) { return mint(x) /= y; }\n\n    template <class T, is_integral_t<T>\
    \ * = nullptr> constexpr mint pow(T n) const {\n        assert(n >= 0);\n    \
    \    mint x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *=\
    \ x;\n            if (n >>= 1) x *= x;\n        }\n        return r;\n    }\n\n\
    \    constexpr mint inv() const { return pow(mod - 2); }\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x._v;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        u64 y;\n        is >> y;\n        x = mint(y);\n  \
    \      return is;\n    }\n\n    constexpr u64 val() const { return _v; }\n\n \
    \   static constexpr mint mulplus(const mint &a, const mint &b, const mint &c)\
    \ {\n        // a * b + c\n        u64 ah = a._v >> 31, al = a._v & mask31;\n\
    \        u64 bh = b._v >> 31, bl = b._v & mask31;\n        u64 m = ah * bl + al\
    \ * bh;\n        u64 t = 2 * ah * bh + al * bl + (m >> 30) + ((m & mask30) <<\
    \ 31) + c._v;\n        mint ret;\n        ret._v = chmod(t);\n        return ret;\n\
    \    }\n\n    static constexpr mint plusmul(const mint &a, const mint &b, const\
    \ mint &c) {\n        // a + b * c\n        u64 bh = b._v >> 31, bl = b._v & mask31;\n\
    \        u64 ch = c._v >> 31, cl = c._v & mask31;\n        u64 m = bh * cl + bl\
    \ * ch;\n        u64 t = 2 * bh * ch + bl * cl + (m >> 30) + ((m & mask30) <<\
    \ 31) + a._v;\n        mint ret;\n        ret._v = chmod(t);\n        return ret;\n\
    \    }\n\n  private:\n    u64 _v;\n\n    constexpr static u64 chmod(u64 &x) {\n\
    \        x = (x & mod) + (x >> 61);\n        if (x >= mod) x -= mod;\n       \
    \ return x;\n    }\n\n    constexpr static u64 mask30 = (1ULL << 30) - 1;\n  \
    \  constexpr static u64 mask31 = (1ULL << 31) - 1;\n\n    constexpr static u64\
    \ mulmod(u64 x, u64 y) {\n        /*\n        A = 2^61 - 1, B = 2^31, C = 2^30\n\
    \        0 <= x, y < A\n        x = xh * B + xl\n        y = yh * B + yl\n   \
    \     0 <= xh, yh < C\n        0 <= xl, yl < B\n\n        m = xh * yl + xl * yh\n\
    \        m = mh * C + ml\n        m * B = mh + ml * B mod A\n        0 <= mh <\
    \ 2B\n        0 <= ml < C\n\n        x * y\n        = xh * yh * B^2 + m * B +\
    \ xl * yl\n        = xh * yh * 2 + mh + ml * B + xl * yl mod A\n\n        xh *\
    \ yh * 2 <= 2(C - 1)^2 = 2^61 - 2^32 + 2\n        mh + ml * B <= 2B - 1 + (C -\
    \ 1) * B = 2^61 + 2^31 - 1\n        xl * yl <= (B - 1)^2 = 2^62 - 2^32 + 1\n\n\
    \        xh * yh * 2 + mh + ml * B + xl * yl\n        <= 2^63 - 2^33 + 2^31 +\
    \ 2\n        */\n        u64 xh = x >> 31, xl = x & mask31;\n        u64 yh =\
    \ y >> 31, yl = y & mask31;\n        u64 m = xh * yl + xl * yh;\n        u64 t\
    \ = 2 * xh * yh + xl * yl + (m >> 30) + ((m & mask30) << 31);\n        return\
    \ chmod(t);\n    }\n};\n\n} // namespace kk2\n\n\n#line 11 \"random/hash.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\ntemplate <int NUM> struct Hash :\
    \ std::array<ModInt2_61m1, NUM> {\n    using mint = ModInt2_61m1;\n    using std::array<mint,\
    \ NUM>::operator[];\n    using u64 = unsigned long long;\n\n    Hash() : std::array<mint,\
    \ NUM>() {}\n\n    template <class T, is_integral_t<T> * = nullptr> Hash(T x)\
    \ {\n        std::fill(this->begin(), this->end(), mint(x));\n    }\n\n    static\
    \ Hash get_base() {\n        Hash base;\n        for (int i = 0; i < NUM; i++)\
    \ base[i] = primitive_root_mint<ModInt2_61m1>();\n        return base;\n    }\n\
    \n    Hash &operator+=(const Hash &rhs) {\n        for (int i = 0; i < NUM; i++)\
    \ (*this)[i] += rhs[i];\n        return *this;\n    }\n    Hash &operator-=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < NUM; i++) (*this)[i] -= rhs[i];\n\
    \        return *this;\n    }\n    Hash &operator*=(const Hash &rhs) {\n     \
    \   for (int i = 0; i < NUM; i++) (*this)[i] *= rhs[i];\n        return *this;\n\
    \    }\n    Hash &operator/=(const Hash &rhs) {\n        for (int i = 0; i < NUM;\
    \ i++) (*this)[i] /= rhs[i];\n        return *this;\n    }\n\n    Hash operator+(const\
    \ Hash &rhs) const { return Hash(*this) += rhs; }\n    Hash operator-(const Hash\
    \ &rhs) const { return Hash(*this) -= rhs; }\n    Hash operator*(const Hash &rhs)\
    \ const { return Hash(*this) *= rhs; }\n    Hash operator/(const Hash &rhs) const\
    \ { return Hash(*this) /= rhs; }\n    Hash operator+() const { return *this; }\n\
    \    Hash operator-() const { return Hash(0) - *this; }\n\n    Hash pow(u64 n)\
    \ const {\n        Hash r;\n        for (int i = 0; i < NUM; i++) r[i] = (*this)[i].pow(n);\n\
    \        return r;\n    }\n\n    Hash inv() const {\n        Hash r;\n       \
    \ for (int i = 0; i < NUM; i++) r[i] = (*this)[i].inv();\n        return r;\n\
    \    }\n\n    static Hash mulplus(const Hash &a, const Hash &b, const Hash &c)\
    \ {\n        Hash res;\n        for (int i = 0; i < NUM; i++) res[i] = mint::mulplus(a[i],\
    \ b[i], c[i]);\n        return res;\n    }\n\n    static Hash plusmul(const Hash\
    \ &a, const Hash &b, const Hash &c) {\n        Hash res;\n        for (int i =\
    \ 0; i < NUM; i++) res[i] = mint::plusmul(a[i], b[i], c[i]);\n        return res;\n\
    \    }\n};\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/container_traits.hpp\"\
    \n\n\n\n#line 5 \"type_traits/container_traits.hpp\"\n#include <deque>\n#include\
    \ <list>\n#include <string>\n#line 10 \"type_traits/container_traits.hpp\"\n\n\
    namespace kk2 {\n\ntemplate <typename T> struct is_vector : std::false_type {};\n\
    template <typename T, typename Alloc> struct is_vector<std::vector<T, Alloc>>\
    \ : std::true_type {};\n\ntemplate <typename T> struct is_container : std::false_type\
    \ {};\ntemplate <typename T, typename Alloc> struct is_container<std::vector<T,\
    \ Alloc>> : std::true_type {\n};\ntemplate <typename CharT, typename Traits, typename\
    \ Alloc>\nstruct is_container<std::basic_string<CharT, Traits, Alloc>> : std::true_type\
    \ {};\ntemplate <typename T, std::size_t N> struct is_container<std::array<T,\
    \ N>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct is_container<std::deque<T,\
    \ Alloc>> : std::true_type {};\ntemplate <typename T, typename Alloc> struct is_container<std::list<T,\
    \ Alloc>> : std::true_type {};\ntemplate <typename T> using is_container_t = typename\
    \ std::enable_if_t<is_container<T>::value>;\n\n} // namespace kk2\n\n\n#line 10\
    \ \"string/dynamic_rolling_hash.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief \u6587\
    \u5B57\u306E\u4E00\u70B9\u66F4\u65B0\u304C\u53EF\u80FD\u6587\u5B57\u5217\u306B\
    \u5BFE\u3059\u308B\u52D5\u7684\u306A\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\
    \u30B7\u30E5\n *\n * @tparam NUM\n */\ntemplate <int NUM> struct DynamicRollingHash\
    \ {\n    using H = random::Hash<NUM>;\n    int _n, lg, siz;\n    std::vector<H>\
    \ d;\n    std::vector<int> dsz;\n    bool is_built = false;\n\n    DynamicRollingHash()\
    \ : DynamicRollingHash(0) {}\n    DynamicRollingHash(int n) : _n(n) {\n      \
    \  extend_base(_n);\n        lg = 0;\n        while ((1 << lg) < _n) lg++;\n \
    \       siz = 1 << lg;\n        d.resize(2 * siz);\n        dsz.resize(2 * siz);\n\
    \    }\n    template <class C, is_container_t<C> * = nullptr> DynamicRollingHash(const\
    \ C &c) {\n        _n = c.size();\n        lg = 0;\n        extend_base(_n);\n\
    \        while ((1 << lg) < _n) lg++;\n        siz = 1 << lg;\n        d.resize(2\
    \ * siz);\n        dsz.resize(2 * siz);\n        for (int i = 0; i < _n; i++)\
    \ d[siz + i] = H(c[i]), dsz[siz + i] = 1;\n        build();\n    }\n\n    inline\
    \ int size() const { return _n; }\n\n    void build() {\n        assert(!is_built);\n\
    \        is_built = true;\n        for (int i = siz - 1; i >= 1; --i) dsz[i] =\
    \ dsz[2 * i] + dsz[2 * i + 1];\n        for (int i = siz - 1; i >= 1; --i) update(i);\n\
    \    }\n\n    template <class T> void init_set(int p, T x) {\n        assert(0\
    \ <= p && p < _n);\n        assert(!is_built);\n        d[siz + p] = H(x);\n \
    \       dsz[siz + p] = 1;\n    }\n\n    template <class T> void set(int p, T x)\
    \ {\n        assert(0 <= p && p < _n);\n        assert(is_built);\n        p +=\
    \ siz;\n        d[p] = H(x);\n        for (int i = 1; i <= lg; i++) update(p >>\
    \ i);\n    }\n\n    H get(int i) const {\n        assert(0 <= i && i < _n);\n\
    \        assert(is_built);\n        return d[siz + i];\n    }\n\n    /**\n   \
    \  * @brief `[l, r)`\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF: `O(log(r - l))`\n     *\n\
    \     * @return `[l, r)`\u306E\u30CF\u30C3\u30B7\u30E5\u5024\n     */\n    H get(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        assert(is_built);\n\
    \        H sml = H(0), smr = H(0);\n        l += siz, r += siz;\n        int l_siz\
    \ = 0;\n\n        while (l < r) {\n            if (l & 1) sml = H::plusmul(sml,\
    \ d[l], pw[l_siz]), l_siz += dsz[l++];\n            if (r & 1) --r, smr = H::plusmul(d[r],\
    \ smr, pw[dsz[r]]);\n            l >>= 1, r >>= 1;\n        }\n        return\
    \ H::plusmul(sml, smr, pw[l_siz]);\n    }\n\n    H all_prod() const {\n      \
    \  assert(is_built);\n        return d[1];\n    }\n\n    /**\n     * @brief \u6587\
    \u5B57\u5217`lhs[l1, r1)`\u3068`rhs[l2, r2)`\u306E\u6700\u9577\u5171\u901A\u63A5\
    \u982D\u8F9E\u3092\u6C42\u3081\u308B\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF\
    : `O(log^2(min(r1 - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\
    \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\
    \u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\
    \u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\
    \u5217`rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n    \
    \ * @param l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  \
    \   * @param r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \     * @return `lhs[l1, l1 + lcp)`\u3068`rhs[l2, l2 + lcp)`\u306E\u6700\u9577\
    \u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\n     */\n    static int lcp(const\
    \ DynamicRollingHash &lhs,\n                   int l1,\n                   int\
    \ r1,\n                   const DynamicRollingHash &rhs,\n                   int\
    \ l2,\n                   int r2) {\n        int len = std::min(r1 - l1, r2 -\
    \ l2);\n        if (lhs.get(l1, l1 + len) == rhs.get(l2, l2 + len)) return len;\n\
    \        int ok = 0, ng = len;\n        while (ng - ok > 1) {\n            int\
    \ mid = (ok + ng) / 2;\n            if (lhs.get(l1, l1 + mid) == rhs.get(l2, l2\
    \ + mid)) {\n                ok = mid;\n            } else {\n               \
    \ ng = mid;\n            }\n        }\n        return ok;\n    }\n\n    /**\n\
    \     * @brief \u6587\u5B57\u5217`lhs[l1, r1)`\u3068`rhs[l2, r2)`\u306E\u8F9E\u66F8\
    \u9806\u6BD4\u8F03\u3092\u884C\u3046\n     *\n     * \u6642\u9593\u8A08\u7B97\u91CF\
    : `O(log^2(min(r1 - l1, r2 - l2)))`\n     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\
    \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @param l1 `lhs`\u306E\
    \u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param r1 `lhs`\u306E\
    \u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param rhs \u6587\u5B57\
    \u5217`rhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n    \
    \ * @param l2 `rhs`\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  \
    \   *  @param r2 `rhs`\u306E\u7D42\u4E86\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \     * @return `-1: lhs < rhs, 0: lhs == rhs, 1: lhs > rhs`\n     */\n    static\
    \ int strcmp(const DynamicRollingHash &lhs,\n                      int l1,\n \
    \                     int r1,\n                      const DynamicRollingHash\
    \ &rhs,\n                      int l2,\n                      int r2) {\n    \
    \    int lcp_ = lcp(lhs, l1, r1, rhs, l2, r2);\n        if (lcp_ == r1 - l1 and\
    \ lcp_ == r2 - l2) return 0;\n        else if (lcp_ == r1 - l1) return -1;\n \
    \       else if (lcp_ == r2 - l2) return 1;\n        else {\n            auto\
    \ c1 = lhs.get(l1 + lcp_, l1 + lcp_ + 1)[0].val();\n            auto c2 = rhs.get(l2\
    \ + lcp_, l2 + lcp_ + 1)[0].val();\n            return c1 < c2 ? -1 : 1;\n   \
    \     }\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217`lhs`\u3068`rhs`\u3092\
    \u7D50\u5408\u3057\u3066\u65B0\u3057\u3044\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\
    \u30C3\u30B7\u30E5\u3092\u4F5C\u6210\u3059\u308B\n     *\n     * \u6642\u9593\u8A08\
    \u7B97\u91CF: `O(n + m)` (n: lhs\u306E\u9577\u3055, m: rhs\u306E\u9577\u3055)\n\
    \     * @param lhs \u6587\u5B57\u5217`lhs`\u306E\u30ED\u30FC\u30EA\u30F3\u30B0\
    \u30CF\u30C3\u30B7\u30E5\n     * @param rhs \u6587\u5B57\u5217`rhs`\u306E\u30ED\
    \u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     * @return \u7D50\u5408\u5F8C\
    \u306E\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n     */\n    static\
    \ DynamicRollingHash merge(const DynamicRollingHash &lhs, const DynamicRollingHash\
    \ &rhs) {\n        if (lhs._n == 0) return rhs;\n        if (rhs._n == 0) return\
    \ lhs;\n        DynamicRollingHash res(lhs._n + rhs._n);\n        for (int i =\
    \ 0; i < lhs._n; i++) res.init_set(i, lhs.get(i));\n        for (int i = 0; i\
    \ < rhs._n; i++) res.init_set(lhs._n + i, rhs.get(i));\n        res.build();\n\
    \        return res;\n    }\n\n  private:\n    static inline std::vector<H> pw;\n\
    \    static void extend_base(int m) {\n        if (pw.size() == 0u) pw = {H(1),\
    \ H::get_base()};\n\n        int n = pw.size();\n        if (n > m) return;\n\
    \        pw.resize(m + 1);\n        for (int i = n; i <= m; ++i) pw[i] = pw[i\
    \ - 1] * pw[1];\n    }\n\n    inline void update(int k) { d[k] = H::plusmul(d[2\
    \ * k], d[2 * k + 1], pw[dsz[2 * k]]); }\n};\n\nusing DRoliha = DynamicRollingHash<2>;\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 6 \"\
    template/template.hpp\"\n#include <bitset>\n#line 9 \"template/template.hpp\"\n\
    #include <cmath>\n#line 11 \"template/template.hpp\"\n#include <functional>\n\
    #include <iterator>\n#include <limits>\n#line 16 \"template/template.hpp\"\n#include\
    \ <optional>\n#include <queue>\n#line 19 \"template/template.hpp\"\n#include <set>\n\
    #include <stack>\n#line 22 \"template/template.hpp\"\n#include <unordered_map>\n\
    #line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n\
    #line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
    \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include\
    \ <cctype>\n#include <cstdint>\n#include <cstdio>\n#include <fstream>\n#line 10\
    \ \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n\
    \    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n\
    \    bool is_eof = false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n\
    \  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file,\
    \ \"r\")) {}\n\n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\
    \n    char now() {\n        if (is_eof) return '\\0';\n        if (pos == end)\
    \ {\n            end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF)\
    \ buf[end] = '\\0';\n            if (end == 0) is_eof = true;\n            pos\
    \ = 0;\n        }\n        return buf[pos];\n    }\n\n    void skip_space() {\n\
    \        while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> T next_unsigned_integral() {\n        skip_space();\n        T\
    \ res{};\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    template\
    \ <class T, is_signed_t<T> * = nullptr> T next_signed_integral() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 8 \"verify/unit_test/string/dynamic_rolling_hash.test.cpp\"\
    \nusing namespace std;\n\nvoid test_basic_and_edge_cases() {\n    // Test default\
    \ constructor\n    kk2::DRoliha rh_default;\n    assert(rh_default.size() == 0);\n\
    \    \n    // Test size constructor\n    kk2::DRoliha rh_size(5);\n    assert(rh_size.size()\
    \ == 5);\n    \n    // Test container constructor with string\n    string s =\
    \ \"hello\";\n    kk2::DRoliha rh_str(s);\n    assert(rh_str.size() == 5);\n \
    \   assert(rh_str.get(0) == kk2::DRoliha::H('h'));\n    assert(rh_str.get(4) ==\
    \ kk2::DRoliha::H('o'));\n    \n    // Test container constructor with vector\n\
    \    vector<int> v = {1, 2, 3, 4, 5};\n    kk2::DRoliha rh_vec(v);\n    assert(rh_vec.size()\
    \ == 5);\n    assert(rh_vec.get(0) == kk2::DRoliha::H(1));\n    assert(rh_vec.get(4)\
    \ == kk2::DRoliha::H(5));\n    \n    // Test empty container\n    string empty\
    \ = \"\";\n    kk2::DRoliha rh_empty(empty);\n    assert(rh_empty.size() == 0);\n\
    \    \n    // Test empty vector\n    vector<int> empty_vec;\n    kk2::DRoliha\
    \ rh_empty_vec(empty_vec);\n    assert(rh_empty_vec.size() == 0);\n    \n    //\
    \ Test range get operations\n    assert(rh_str.get(0, 5) == rh_str.all_prod());\n\
    \    assert(rh_str.get(1, 4) != rh_str.get(0, 3));\n    assert(rh_str.get(2, 2)\
    \ == kk2::DRoliha::H(0)); // empty range\n    \n    // Test single character operations\n\
    \    kk2::DRoliha rh_single(1);\n    rh_single.init_set(0, 'A');\n    rh_single.build();\n\
    \    assert(rh_single.size() == 1);\n    assert(rh_single.get(0) == kk2::DRoliha::H('A'));\n\
    \    assert(rh_single.get(0, 1) == rh_single.all_prod());\n}\n\nvoid test_init_set_and_build()\
    \ {\n    // Test init_set and build workflow\n    kk2::DRoliha rh(5);\n    \n\
    \    // Initialize with values\n    rh.init_set(0, 'a');\n    rh.init_set(1, 'b');\n\
    \    rh.init_set(2, 'c');\n    rh.init_set(3, 'd');\n    rh.init_set(4, 'e');\n\
    \    \n    // Build the hash\n    rh.build();\n    \n    // Verify values\n  \
    \  assert(rh.get(0) == kk2::DRoliha::H('a'));\n    assert(rh.get(1) == kk2::DRoliha::H('b'));\n\
    \    assert(rh.get(2) == kk2::DRoliha::H('c'));\n    assert(rh.get(3) == kk2::DRoliha::H('d'));\n\
    \    assert(rh.get(4) == kk2::DRoliha::H('e'));\n    \n    // Test range operations\n\
    \    string expected = \"abcde\";\n    kk2::DRoliha rh_expected(expected);\n \
    \   assert(rh.get(0, 5) == rh_expected.get(0, 5));\n    assert(rh.get(1, 4) ==\
    \ rh_expected.get(1, 4));\n    assert(rh.all_prod() == rh_expected.all_prod());\n\
    }\n\nvoid test_set_operations() {\n    // Test dynamic set operations\n    string\
    \ s = \"hello\";\n    kk2::DRoliha rh(s);\n    \n    // Change 'h' to 'H'\n  \
    \  rh.set(0, 'H');\n    assert(rh.get(0) == kk2::DRoliha::H('H'));\n    \n   \
    \ // Verify that the change affected range queries\n    string expected = \"Hello\"\
    ;\n    kk2::DRoliha rh_expected(expected);\n    assert(rh.get(0, 5) == rh_expected.get(0,\
    \ 5));\n    assert(rh.all_prod() == rh_expected.all_prod());\n    \n    // Change\
    \ multiple characters\n    rh.set(1, 'E'); // \"HEllo\"\n    rh.set(4, 'O'); //\
    \ \"HEllO\"\n    \n    assert(rh.get(1) == kk2::DRoliha::H('E'));\n    assert(rh.get(4)\
    \ == kk2::DRoliha::H('O'));\n    \n    string expected2 = \"HEllO\";\n    kk2::DRoliha\
    \ rh_expected2(expected2);\n    assert(rh.all_prod() == rh_expected2.all_prod());\n\
    }\n\nvoid test_lcp_and_strcmp() {\n    // Test LCP operations\n    string s1 =\
    \ \"abcdef\", s2 = \"abcxyz\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n   \
    \ assert(kk2::DRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3); // \"abc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 1, 6, rh2, 1, 6) == 2); // \"bc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 3) == 3); // \"abc\" == \"abc\"\
    \n    \n    // Test LCP with empty ranges\n    assert(kk2::DRoliha::lcp(rh1, 0,\
    \ 0, rh2, 0, 0) == 0);\n    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 0) ==\
    \ 0);\n    \n    // Test strcmp operations\n    string s3 = \"abc\", s4 = \"abd\"\
    ;\n    kk2::DRoliha rh3(s3), rh4(s4);\n    \n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh4, 0, 3) == -1); // abc < abd\n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh3, 0, 3) == 0);  // abc == abc\n    assert(kk2::DRoliha::strcmp(rh4,\
    \ 0, 3, rh3, 0, 3) == 1);  // abd > abc\n    \n    // Test strcmp edge cases\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 0) == 0); // empty == empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 3) == -1); // empty < non-empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh4, 0, 0) == 1); // non-empty > empty\n\
    }\n\nvoid test_merge_operations() {\n    // Test basic merge\n    string s1 =\
    \ \"hello\", s2 = \"world\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n    auto\
    \ merged = kk2::DRoliha::merge(rh1, rh2);\n    assert(merged.size() == 10);\n\
    \    \n    // Verify merged result\n    string expected = \"helloworld\";\n  \
    \  kk2::DRoliha rh_expected(expected);\n    assert(merged.all_prod() == rh_expected.all_prod());\n\
    \    assert(merged.get(0, 10) == rh_expected.get(0, 10));\n    \n    // Test partial\
    \ ranges\n    assert(merged.get(0, 5) == rh1.get(0, 5));\n    assert(merged.get(5,\
    \ 10) == rh2.get(0, 5));\n    \n    // Test merge with empty\n    kk2::DRoliha\
    \ rh_empty;\n    auto merged_empty1 = kk2::DRoliha::merge(rh_empty, rh1);\n  \
    \  assert(merged_empty1.size() == 5);\n    assert(merged_empty1.get(0, 5) == rh1.get(0,\
    \ 5));\n    \n    auto merged_empty2 = kk2::DRoliha::merge(rh1, rh_empty);\n \
    \   assert(merged_empty2.size() == 5);\n    assert(merged_empty2.get(0, 5) ==\
    \ rh1.get(0, 5));\n}\n\nvoid test_random_comprehensive() {\n    // Test random\
    \ operations with dynamic updates\n    rep(1000) {\n        int len = kk2::random::rng(1,\
    \ 51);\n        string s;\n        rep(len) s += char('a' + kk2::random::rng(0,\
    \ 26));\n        \n        kk2::DRoliha rh(s);\n        assert(rh.size() == len);\n\
    \        \n        // Test random single point get\n        int idx = kk2::random::rng(0,\
    \ len);\n        assert(rh.get(idx) == kk2::DRoliha::H(s[idx]));\n        \n \
    \       // Test random range get\n        int l = kk2::random::rng(0, len);\n\
    \        int r = kk2::random::rng(l, len + 1);\n        \n        if (l < r) {\n\
    \            string sub = s.substr(l, r - l);\n            kk2::DRoliha rh_sub(sub);\n\
    \            assert(rh.get(l, r) == rh_sub.get(0, r - l));\n        }\n      \
    \  \n        // Test random set operation\n        int pos = kk2::random::rng(0,\
    \ len);\n        char new_char = char('a' + kk2::random::rng(0, 26));\n      \
    \  rh.set(pos, new_char);\n        assert(rh.get(pos) == kk2::DRoliha::H(new_char));\n\
    \        \n        // Update original string and verify consistency\n        s[pos]\
    \ = new_char;\n        kk2::DRoliha rh_updated(s);\n        assert(rh.all_prod()\
    \ == rh_updated.all_prod());\n    }\n}\n\nvoid test_random_lcp_strcmp() {\n  \
    \  // Test LCP and strcmp with random strings\n    rep(300) {\n        int len1\
    \ = kk2::random::rng(1, 31);\n        int len2 = kk2::random::rng(1, 31);\n  \
    \      \n        string s1, s2;\n        rep(len1) s1 += char('a' + kk2::random::rng(0,\
    \ 26));\n        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));\n      \
    \  \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n        // Test LCP\n \
    \       int l1 = kk2::random::rng(0, len1);\n        int r1 = kk2::random::rng(l1,\
    \ len1 + 1);\n        int l2 = kk2::random::rng(0, len2);\n        int r2 = kk2::random::rng(l2,\
    \ len2 + 1);\n        \n        int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2,\
    \ l2, r2);\n        \n        // Verify LCP manually\n        int expected_lcp\
    \ = 0;\n        int min_len = min(r1 - l1, r2 - l2);\n        for (int i = 0;\
    \ i < min_len; i++) {\n            if (l1 + i < len1 && l2 + i < len2 && s1[l1\
    \ + i] == s2[l2 + i]) {\n                expected_lcp++;\n            } else {\n\
    \                break;\n            }\n        }\n        assert(lcp_len == expected_lcp);\n\
    \        \n        // Test strcmp\n        int cmp_result = kk2::DRoliha::strcmp(rh1,\
    \ l1, r1, rh2, l2, r2);\n        string sub1 = s1.substr(l1, r1 - l1);\n     \
    \   string sub2 = s2.substr(l2, r2 - l2);\n        int expected_cmp = (sub1 <\
    \ sub2) ? -1 : (sub1 > sub2) ? 1 : 0;\n        assert(cmp_result == expected_cmp);\n\
    \    }\n}\n\n// Performance test configuration\nstruct PerformanceConfig {\n \
    \   // Test sizes\n    static constexpr int LARGE_SIZE = 100000;\n    static constexpr\
    \ int MEDIUM_SIZE = 50000;\n    static constexpr int SMALL_SIZE = 10000;\n   \
    \ \n    // Test iterations\n    static constexpr int MANY_QUERIES = 100000;\n\
    \    static constexpr int MEDIUM_QUERIES = 50000;\n    static constexpr int FEW_QUERIES\
    \ = 1000;\n    \n    // Hash collision test settings\n    static constexpr int\
    \ COLLISION_TEST_SIZE = 50000;\n    static constexpr int STRING_MAX_LENGTH = 21;\n\
    \    static constexpr int DYNAMIC_UPDATE_COUNT = 10000;\n    \n    // Value ranges\n\
    \    static constexpr int ALPHABET_SIZE = 26;\n    static constexpr int LARGE_VALUE_RANGE\
    \ = 1000000;\n};\n\nvoid test_performance() {\n    // Large size performance test\
    \ for dynamic rolling hash\n    cerr << \"Starting DynamicRollingHash performance\
    \ tests...\" << endl;\n    cerr << \"Configuration:\" << endl;\n    cerr << \"\
    \  Large size: \" << PerformanceConfig::LARGE_SIZE << endl;\n    cerr << \"  Medium\
    \ size: \" << PerformanceConfig::MEDIUM_SIZE << endl;\n    cerr << \"  Many queries:\
    \ \" << PerformanceConfig::MANY_QUERIES << endl;\n    cerr << \"  Medium queries:\
    \ \" << PerformanceConfig::MEDIUM_QUERIES << endl;\n    cerr << endl;\n    \n\
    \    // Test 1: Large string construction and query performance\n    {\n     \
    \   int n = PerformanceConfig::LARGE_SIZE;\n        string large_str;\n      \
    \  large_str.reserve(n);\n        for (int i = 0; i < n; i++) {\n            large_str\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \    }\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(large_str);\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto construction_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << \"Construction time for \" << n << \" characters:\
    \ \" << construction_time << \" microseconds\" << endl;\n        \n        //\
    \ Test many substring queries\n        start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {\n       \
    \     int l = kk2::random::rng(0, n);\n            int r = kk2::random::rng(l,\
    \ n + 1);\n            auto h = rh.get(l, r);\n            (void)h; // suppress\
    \ unused variable warning\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" substring queries time:\
    \ \" << query_time << \" microseconds\" << endl;\n    }\n    \n    // Test 2:\
    \ Large size construction and set operations performance\n    {\n        int n\
    \ = PerformanceConfig::MEDIUM_SIZE;\n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(n);\n        \n        // Initialize with random values\n\
    \        for (int i = 0; i < n; i++) {\n            rh.init_set(i, kk2::random::rng(0,\
    \ PerformanceConfig::LARGE_VALUE_RANGE));\n        }\n        rh.build();\n  \
    \      auto end = chrono::high_resolution_clock::now();\n        auto init_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << \"Init_set and build time for \" << n << \" elements: \" << init_time\
    \ << \" microseconds\" << endl;\n        \n        // Test many set operations\n\
    \        start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MANY_QUERIES; i++) {\n            int idx = kk2::random::rng(0,\
    \ n);\n            int new_val = kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE);\n\
    \            rh.set(idx, new_val);\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto set_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" set operations time: \"\
    \ << set_time << \" microseconds\" << endl;\n    }\n    \n    // Test 3: Many\
    \ single point queries performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        vector<int> large_vec;\n        large_vec.reserve(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));\n\
    \        }\n        \n        kk2::DRoliha rh(large_vec);\n        \n        auto\
    \ start = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            int idx = kk2::random::rng(0, n);\n            auto h =\
    \ rh.get(idx);\n            (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << PerformanceConfig::MANY_QUERIES << \" single\
    \ point queries time: \" << point_query_time << \" microseconds\" << endl;\n \
    \   }\n    \n    // Test 4: LCP operations performance\n    {\n        int n =\
    \ PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n        s1.reserve(n);\n\
    \        s2.reserve(n);\n        for (int i = 0; i < n; i++) {\n            s1\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \        s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2, l2, r2);\n    \
    \        (void)lcp_len;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" LCP operations time:\
    \ \" << lcp_time << \" microseconds\" << endl;\n    }\n    \n    // Test 5: Merge\
    \ operations performance\n    {\n        int n = PerformanceConfig::SMALL_SIZE;\n\
    \        auto start = chrono::high_resolution_clock::now();\n        for (int\
    \ i = 0; i < PerformanceConfig::FEW_QUERIES; i++) {\n            int len1 = kk2::random::rng(1,\
    \ n / 100);\n            int len2 = kk2::random::rng(1, n / 100);\n          \
    \  \n            string s1, s2;\n            s1.reserve(len1);\n            s2.reserve(len2);\n\
    \            for (int j = 0; j < len1; j++) s1 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n            for (int j = 0; j < len2; j++)\
    \ s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n \
    \           \n            kk2::DRoliha rh1(s1), rh2(s2);\n            auto merged\
    \ = kk2::DRoliha::merge(rh1, rh2);\n            (void)merged;\n        }\n   \
    \     auto end = chrono::high_resolution_clock::now();\n        auto merge_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::FEW_QUERIES << \" merge operations time: \" << merge_time\
    \ << \" microseconds\" << endl;\n    }\n    \n    // Test 6: strcmp performance\n\
    \    {\n        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n\
    \        s1.reserve(n);\n        s2.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) {\n            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int cmp_result = kk2::DRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);\n\
    \            (void)cmp_result;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end -\
    \ start).count();\n        cerr << PerformanceConfig::MEDIUM_QUERIES << \" strcmp\
    \ operations time: \" << strcmp_time << \" microseconds\" << endl;\n    }\n  \
    \  \n    // Test 7: Dynamic update performance with mixed operations\n    {\n\
    \        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s;\n        s.reserve(n);\n\
    \        for (int i = 0; i < n; i++) {\n            s += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n        }\n        \n        kk2::DRoliha\
    \ rh(s);\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n     \
    \       // Random set operation\n            int pos = kk2::random::rng(0, n);\n\
    \            char new_char = char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            rh.set(pos, new_char);\n            \n            // Random query\
    \ operation\n            int l = kk2::random::rng(0, n);\n            int r =\
    \ kk2::random::rng(l, n + 1);\n            auto h = rh.get(l, r);\n          \
    \  (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto mixed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" mixed set+query operations\
    \ time: \" << mixed_time << \" microseconds\" << endl;\n    }\n    \n    // Test\
    \ 9: all_prod() performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        string s;\n        s.reserve(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            s += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh(s);\n        \n        auto start\
    \ = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            auto h = rh.all_prod();\n            (void)h;\n        }\n\
    \        auto end = chrono::high_resolution_clock::now();\n        auto all_prod_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::MANY_QUERIES << \" all_prod() operations time: \"\
    \ << all_prod_time << \" microseconds\" << endl;\n    }\n    \n    cerr << \"\
    DynamicRollingHash performance tests completed!\" << endl;\n}\n\nvoid test() {\n\
    \    test_basic_and_edge_cases();\n    test_init_set_and_build();\n    test_set_operations();\n\
    \    test_lcp_and_strcmp();\n    test_merge_operations();\n    test_random_comprehensive();\n\
    \    test_random_lcp_strcmp();\n    test_performance();\n    \n    cerr << \"\
    All DynamicRollingHash tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../string/dynamic_rolling_hash.hpp\"\n#include \"../../../random/gen.hpp\"\
    \n#include \"../../../template/template.hpp\"\n#include <chrono>\n#include <set>\n\
    using namespace std;\n\nvoid test_basic_and_edge_cases() {\n    // Test default\
    \ constructor\n    kk2::DRoliha rh_default;\n    assert(rh_default.size() == 0);\n\
    \    \n    // Test size constructor\n    kk2::DRoliha rh_size(5);\n    assert(rh_size.size()\
    \ == 5);\n    \n    // Test container constructor with string\n    string s =\
    \ \"hello\";\n    kk2::DRoliha rh_str(s);\n    assert(rh_str.size() == 5);\n \
    \   assert(rh_str.get(0) == kk2::DRoliha::H('h'));\n    assert(rh_str.get(4) ==\
    \ kk2::DRoliha::H('o'));\n    \n    // Test container constructor with vector\n\
    \    vector<int> v = {1, 2, 3, 4, 5};\n    kk2::DRoliha rh_vec(v);\n    assert(rh_vec.size()\
    \ == 5);\n    assert(rh_vec.get(0) == kk2::DRoliha::H(1));\n    assert(rh_vec.get(4)\
    \ == kk2::DRoliha::H(5));\n    \n    // Test empty container\n    string empty\
    \ = \"\";\n    kk2::DRoliha rh_empty(empty);\n    assert(rh_empty.size() == 0);\n\
    \    \n    // Test empty vector\n    vector<int> empty_vec;\n    kk2::DRoliha\
    \ rh_empty_vec(empty_vec);\n    assert(rh_empty_vec.size() == 0);\n    \n    //\
    \ Test range get operations\n    assert(rh_str.get(0, 5) == rh_str.all_prod());\n\
    \    assert(rh_str.get(1, 4) != rh_str.get(0, 3));\n    assert(rh_str.get(2, 2)\
    \ == kk2::DRoliha::H(0)); // empty range\n    \n    // Test single character operations\n\
    \    kk2::DRoliha rh_single(1);\n    rh_single.init_set(0, 'A');\n    rh_single.build();\n\
    \    assert(rh_single.size() == 1);\n    assert(rh_single.get(0) == kk2::DRoliha::H('A'));\n\
    \    assert(rh_single.get(0, 1) == rh_single.all_prod());\n}\n\nvoid test_init_set_and_build()\
    \ {\n    // Test init_set and build workflow\n    kk2::DRoliha rh(5);\n    \n\
    \    // Initialize with values\n    rh.init_set(0, 'a');\n    rh.init_set(1, 'b');\n\
    \    rh.init_set(2, 'c');\n    rh.init_set(3, 'd');\n    rh.init_set(4, 'e');\n\
    \    \n    // Build the hash\n    rh.build();\n    \n    // Verify values\n  \
    \  assert(rh.get(0) == kk2::DRoliha::H('a'));\n    assert(rh.get(1) == kk2::DRoliha::H('b'));\n\
    \    assert(rh.get(2) == kk2::DRoliha::H('c'));\n    assert(rh.get(3) == kk2::DRoliha::H('d'));\n\
    \    assert(rh.get(4) == kk2::DRoliha::H('e'));\n    \n    // Test range operations\n\
    \    string expected = \"abcde\";\n    kk2::DRoliha rh_expected(expected);\n \
    \   assert(rh.get(0, 5) == rh_expected.get(0, 5));\n    assert(rh.get(1, 4) ==\
    \ rh_expected.get(1, 4));\n    assert(rh.all_prod() == rh_expected.all_prod());\n\
    }\n\nvoid test_set_operations() {\n    // Test dynamic set operations\n    string\
    \ s = \"hello\";\n    kk2::DRoliha rh(s);\n    \n    // Change 'h' to 'H'\n  \
    \  rh.set(0, 'H');\n    assert(rh.get(0) == kk2::DRoliha::H('H'));\n    \n   \
    \ // Verify that the change affected range queries\n    string expected = \"Hello\"\
    ;\n    kk2::DRoliha rh_expected(expected);\n    assert(rh.get(0, 5) == rh_expected.get(0,\
    \ 5));\n    assert(rh.all_prod() == rh_expected.all_prod());\n    \n    // Change\
    \ multiple characters\n    rh.set(1, 'E'); // \"HEllo\"\n    rh.set(4, 'O'); //\
    \ \"HEllO\"\n    \n    assert(rh.get(1) == kk2::DRoliha::H('E'));\n    assert(rh.get(4)\
    \ == kk2::DRoliha::H('O'));\n    \n    string expected2 = \"HEllO\";\n    kk2::DRoliha\
    \ rh_expected2(expected2);\n    assert(rh.all_prod() == rh_expected2.all_prod());\n\
    }\n\nvoid test_lcp_and_strcmp() {\n    // Test LCP operations\n    string s1 =\
    \ \"abcdef\", s2 = \"abcxyz\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n   \
    \ assert(kk2::DRoliha::lcp(rh1, 0, 6, rh2, 0, 6) == 3); // \"abc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 1, 6, rh2, 1, 6) == 2); // \"bc\" common prefix\n\
    \    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 3) == 3); // \"abc\" == \"abc\"\
    \n    \n    // Test LCP with empty ranges\n    assert(kk2::DRoliha::lcp(rh1, 0,\
    \ 0, rh2, 0, 0) == 0);\n    assert(kk2::DRoliha::lcp(rh1, 0, 3, rh2, 0, 0) ==\
    \ 0);\n    \n    // Test strcmp operations\n    string s3 = \"abc\", s4 = \"abd\"\
    ;\n    kk2::DRoliha rh3(s3), rh4(s4);\n    \n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh4, 0, 3) == -1); // abc < abd\n    assert(kk2::DRoliha::strcmp(rh3,\
    \ 0, 3, rh3, 0, 3) == 0);  // abc == abc\n    assert(kk2::DRoliha::strcmp(rh4,\
    \ 0, 3, rh3, 0, 3) == 1);  // abd > abc\n    \n    // Test strcmp edge cases\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 0) == 0); // empty == empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 0, rh4, 0, 3) == -1); // empty < non-empty\n\
    \    assert(kk2::DRoliha::strcmp(rh3, 0, 3, rh4, 0, 0) == 1); // non-empty > empty\n\
    }\n\nvoid test_merge_operations() {\n    // Test basic merge\n    string s1 =\
    \ \"hello\", s2 = \"world\";\n    kk2::DRoliha rh1(s1), rh2(s2);\n    \n    auto\
    \ merged = kk2::DRoliha::merge(rh1, rh2);\n    assert(merged.size() == 10);\n\
    \    \n    // Verify merged result\n    string expected = \"helloworld\";\n  \
    \  kk2::DRoliha rh_expected(expected);\n    assert(merged.all_prod() == rh_expected.all_prod());\n\
    \    assert(merged.get(0, 10) == rh_expected.get(0, 10));\n    \n    // Test partial\
    \ ranges\n    assert(merged.get(0, 5) == rh1.get(0, 5));\n    assert(merged.get(5,\
    \ 10) == rh2.get(0, 5));\n    \n    // Test merge with empty\n    kk2::DRoliha\
    \ rh_empty;\n    auto merged_empty1 = kk2::DRoliha::merge(rh_empty, rh1);\n  \
    \  assert(merged_empty1.size() == 5);\n    assert(merged_empty1.get(0, 5) == rh1.get(0,\
    \ 5));\n    \n    auto merged_empty2 = kk2::DRoliha::merge(rh1, rh_empty);\n \
    \   assert(merged_empty2.size() == 5);\n    assert(merged_empty2.get(0, 5) ==\
    \ rh1.get(0, 5));\n}\n\nvoid test_random_comprehensive() {\n    // Test random\
    \ operations with dynamic updates\n    rep(1000) {\n        int len = kk2::random::rng(1,\
    \ 51);\n        string s;\n        rep(len) s += char('a' + kk2::random::rng(0,\
    \ 26));\n        \n        kk2::DRoliha rh(s);\n        assert(rh.size() == len);\n\
    \        \n        // Test random single point get\n        int idx = kk2::random::rng(0,\
    \ len);\n        assert(rh.get(idx) == kk2::DRoliha::H(s[idx]));\n        \n \
    \       // Test random range get\n        int l = kk2::random::rng(0, len);\n\
    \        int r = kk2::random::rng(l, len + 1);\n        \n        if (l < r) {\n\
    \            string sub = s.substr(l, r - l);\n            kk2::DRoliha rh_sub(sub);\n\
    \            assert(rh.get(l, r) == rh_sub.get(0, r - l));\n        }\n      \
    \  \n        // Test random set operation\n        int pos = kk2::random::rng(0,\
    \ len);\n        char new_char = char('a' + kk2::random::rng(0, 26));\n      \
    \  rh.set(pos, new_char);\n        assert(rh.get(pos) == kk2::DRoliha::H(new_char));\n\
    \        \n        // Update original string and verify consistency\n        s[pos]\
    \ = new_char;\n        kk2::DRoliha rh_updated(s);\n        assert(rh.all_prod()\
    \ == rh_updated.all_prod());\n    }\n}\n\nvoid test_random_lcp_strcmp() {\n  \
    \  // Test LCP and strcmp with random strings\n    rep(300) {\n        int len1\
    \ = kk2::random::rng(1, 31);\n        int len2 = kk2::random::rng(1, 31);\n  \
    \      \n        string s1, s2;\n        rep(len1) s1 += char('a' + kk2::random::rng(0,\
    \ 26));\n        rep(len2) s2 += char('a' + kk2::random::rng(0, 26));\n      \
    \  \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n        // Test LCP\n \
    \       int l1 = kk2::random::rng(0, len1);\n        int r1 = kk2::random::rng(l1,\
    \ len1 + 1);\n        int l2 = kk2::random::rng(0, len2);\n        int r2 = kk2::random::rng(l2,\
    \ len2 + 1);\n        \n        int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2,\
    \ l2, r2);\n        \n        // Verify LCP manually\n        int expected_lcp\
    \ = 0;\n        int min_len = min(r1 - l1, r2 - l2);\n        for (int i = 0;\
    \ i < min_len; i++) {\n            if (l1 + i < len1 && l2 + i < len2 && s1[l1\
    \ + i] == s2[l2 + i]) {\n                expected_lcp++;\n            } else {\n\
    \                break;\n            }\n        }\n        assert(lcp_len == expected_lcp);\n\
    \        \n        // Test strcmp\n        int cmp_result = kk2::DRoliha::strcmp(rh1,\
    \ l1, r1, rh2, l2, r2);\n        string sub1 = s1.substr(l1, r1 - l1);\n     \
    \   string sub2 = s2.substr(l2, r2 - l2);\n        int expected_cmp = (sub1 <\
    \ sub2) ? -1 : (sub1 > sub2) ? 1 : 0;\n        assert(cmp_result == expected_cmp);\n\
    \    }\n}\n\n// Performance test configuration\nstruct PerformanceConfig {\n \
    \   // Test sizes\n    static constexpr int LARGE_SIZE = 100000;\n    static constexpr\
    \ int MEDIUM_SIZE = 50000;\n    static constexpr int SMALL_SIZE = 10000;\n   \
    \ \n    // Test iterations\n    static constexpr int MANY_QUERIES = 100000;\n\
    \    static constexpr int MEDIUM_QUERIES = 50000;\n    static constexpr int FEW_QUERIES\
    \ = 1000;\n    \n    // Hash collision test settings\n    static constexpr int\
    \ COLLISION_TEST_SIZE = 50000;\n    static constexpr int STRING_MAX_LENGTH = 21;\n\
    \    static constexpr int DYNAMIC_UPDATE_COUNT = 10000;\n    \n    // Value ranges\n\
    \    static constexpr int ALPHABET_SIZE = 26;\n    static constexpr int LARGE_VALUE_RANGE\
    \ = 1000000;\n};\n\nvoid test_performance() {\n    // Large size performance test\
    \ for dynamic rolling hash\n    cerr << \"Starting DynamicRollingHash performance\
    \ tests...\" << endl;\n    cerr << \"Configuration:\" << endl;\n    cerr << \"\
    \  Large size: \" << PerformanceConfig::LARGE_SIZE << endl;\n    cerr << \"  Medium\
    \ size: \" << PerformanceConfig::MEDIUM_SIZE << endl;\n    cerr << \"  Many queries:\
    \ \" << PerformanceConfig::MANY_QUERIES << endl;\n    cerr << \"  Medium queries:\
    \ \" << PerformanceConfig::MEDIUM_QUERIES << endl;\n    cerr << endl;\n    \n\
    \    // Test 1: Large string construction and query performance\n    {\n     \
    \   int n = PerformanceConfig::LARGE_SIZE;\n        string large_str;\n      \
    \  large_str.reserve(n);\n        for (int i = 0; i < n; i++) {\n            large_str\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \    }\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(large_str);\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto construction_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << \"Construction time for \" << n << \" characters:\
    \ \" << construction_time << \" microseconds\" << endl;\n        \n        //\
    \ Test many substring queries\n        start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MANY_QUERIES; i++) {\n       \
    \     int l = kk2::random::rng(0, n);\n            int r = kk2::random::rng(l,\
    \ n + 1);\n            auto h = rh.get(l, r);\n            (void)h; // suppress\
    \ unused variable warning\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto query_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" substring queries time:\
    \ \" << query_time << \" microseconds\" << endl;\n    }\n    \n    // Test 2:\
    \ Large size construction and set operations performance\n    {\n        int n\
    \ = PerformanceConfig::MEDIUM_SIZE;\n        auto start = chrono::high_resolution_clock::now();\n\
    \        kk2::DRoliha rh(n);\n        \n        // Initialize with random values\n\
    \        for (int i = 0; i < n; i++) {\n            rh.init_set(i, kk2::random::rng(0,\
    \ PerformanceConfig::LARGE_VALUE_RANGE));\n        }\n        rh.build();\n  \
    \      auto end = chrono::high_resolution_clock::now();\n        auto init_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << \"Init_set and build time for \" << n << \" elements: \" << init_time\
    \ << \" microseconds\" << endl;\n        \n        // Test many set operations\n\
    \        start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MANY_QUERIES; i++) {\n            int idx = kk2::random::rng(0,\
    \ n);\n            int new_val = kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE);\n\
    \            rh.set(idx, new_val);\n        }\n        end = chrono::high_resolution_clock::now();\n\
    \        auto set_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MANY_QUERIES << \" set operations time: \"\
    \ << set_time << \" microseconds\" << endl;\n    }\n    \n    // Test 3: Many\
    \ single point queries performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        vector<int> large_vec;\n        large_vec.reserve(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            large_vec.push_back(kk2::random::rng(0, PerformanceConfig::LARGE_VALUE_RANGE));\n\
    \        }\n        \n        kk2::DRoliha rh(large_vec);\n        \n        auto\
    \ start = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            int idx = kk2::random::rng(0, n);\n            auto h =\
    \ rh.get(idx);\n            (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto point_query_time = chrono::duration_cast<chrono::microseconds>(end\
    \ - start).count();\n        cerr << PerformanceConfig::MANY_QUERIES << \" single\
    \ point queries time: \" << point_query_time << \" microseconds\" << endl;\n \
    \   }\n    \n    // Test 4: LCP operations performance\n    {\n        int n =\
    \ PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n        s1.reserve(n);\n\
    \        s2.reserve(n);\n        for (int i = 0; i < n; i++) {\n            s1\
    \ += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n    \
    \        s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int lcp_len = kk2::DRoliha::lcp(rh1, l1, r1, rh2, l2, r2);\n    \
    \        (void)lcp_len;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto lcp_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" LCP operations time:\
    \ \" << lcp_time << \" microseconds\" << endl;\n    }\n    \n    // Test 5: Merge\
    \ operations performance\n    {\n        int n = PerformanceConfig::SMALL_SIZE;\n\
    \        auto start = chrono::high_resolution_clock::now();\n        for (int\
    \ i = 0; i < PerformanceConfig::FEW_QUERIES; i++) {\n            int len1 = kk2::random::rng(1,\
    \ n / 100);\n            int len2 = kk2::random::rng(1, n / 100);\n          \
    \  \n            string s1, s2;\n            s1.reserve(len1);\n            s2.reserve(len2);\n\
    \            for (int j = 0; j < len1; j++) s1 += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n            for (int j = 0; j < len2; j++)\
    \ s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n \
    \           \n            kk2::DRoliha rh1(s1), rh2(s2);\n            auto merged\
    \ = kk2::DRoliha::merge(rh1, rh2);\n            (void)merged;\n        }\n   \
    \     auto end = chrono::high_resolution_clock::now();\n        auto merge_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::FEW_QUERIES << \" merge operations time: \" << merge_time\
    \ << \" microseconds\" << endl;\n    }\n    \n    // Test 6: strcmp performance\n\
    \    {\n        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s1, s2;\n\
    \        s1.reserve(n);\n        s2.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) {\n            s1 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            s2 += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh1(s1), rh2(s2);\n        \n     \
    \   auto start = chrono::high_resolution_clock::now();\n        for (int i = 0;\
    \ i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n            int l1 = kk2::random::rng(0,\
    \ n);\n            int r1 = kk2::random::rng(l1, n + 1);\n            int l2 =\
    \ kk2::random::rng(0, n);\n            int r2 = kk2::random::rng(l2, n + 1);\n\
    \            int cmp_result = kk2::DRoliha::strcmp(rh1, l1, r1, rh2, l2, r2);\n\
    \            (void)cmp_result;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto strcmp_time = chrono::duration_cast<chrono::microseconds>(end -\
    \ start).count();\n        cerr << PerformanceConfig::MEDIUM_QUERIES << \" strcmp\
    \ operations time: \" << strcmp_time << \" microseconds\" << endl;\n    }\n  \
    \  \n    // Test 7: Dynamic update performance with mixed operations\n    {\n\
    \        int n = PerformanceConfig::MEDIUM_SIZE;\n        string s;\n        s.reserve(n);\n\
    \        for (int i = 0; i < n; i++) {\n            s += char('a' + kk2::random::rng(0,\
    \ PerformanceConfig::ALPHABET_SIZE));\n        }\n        \n        kk2::DRoliha\
    \ rh(s);\n        \n        auto start = chrono::high_resolution_clock::now();\n\
    \        for (int i = 0; i < PerformanceConfig::MEDIUM_QUERIES; i++) {\n     \
    \       // Random set operation\n            int pos = kk2::random::rng(0, n);\n\
    \            char new_char = char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \            rh.set(pos, new_char);\n            \n            // Random query\
    \ operation\n            int l = kk2::random::rng(0, n);\n            int r =\
    \ kk2::random::rng(l, n + 1);\n            auto h = rh.get(l, r);\n          \
    \  (void)h;\n        }\n        auto end = chrono::high_resolution_clock::now();\n\
    \        auto mixed_time = chrono::duration_cast<chrono::microseconds>(end - start).count();\n\
    \        cerr << PerformanceConfig::MEDIUM_QUERIES << \" mixed set+query operations\
    \ time: \" << mixed_time << \" microseconds\" << endl;\n    }\n    \n    // Test\
    \ 9: all_prod() performance\n    {\n        int n = PerformanceConfig::LARGE_SIZE;\n\
    \        string s;\n        s.reserve(n);\n        for (int i = 0; i < n; i++)\
    \ {\n            s += char('a' + kk2::random::rng(0, PerformanceConfig::ALPHABET_SIZE));\n\
    \        }\n        \n        kk2::DRoliha rh(s);\n        \n        auto start\
    \ = chrono::high_resolution_clock::now();\n        for (int i = 0; i < PerformanceConfig::MANY_QUERIES;\
    \ i++) {\n            auto h = rh.all_prod();\n            (void)h;\n        }\n\
    \        auto end = chrono::high_resolution_clock::now();\n        auto all_prod_time\
    \ = chrono::duration_cast<chrono::microseconds>(end - start).count();\n      \
    \  cerr << PerformanceConfig::MANY_QUERIES << \" all_prod() operations time: \"\
    \ << all_prod_time << \" microseconds\" << endl;\n    }\n    \n    cerr << \"\
    DynamicRollingHash performance tests completed!\" << endl;\n}\n\nvoid test() {\n\
    \    test_basic_and_edge_cases();\n    test_init_set_and_build();\n    test_set_operations();\n\
    \    test_lcp_and_strcmp();\n    test_merge_operations();\n    test_random_comprehensive();\n\
    \    test_random_lcp_strcmp();\n    test_performance();\n    \n    cerr << \"\
    All DynamicRollingHash tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - string/dynamic_rolling_hash.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - random/hash.hpp
  - math_mod/primitive_root_64bit.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - random/gen.hpp
  - math_mod/pow_mod.hpp
  - modint/modint_2_61m1.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - type_traits/container_traits.hpp
  - random/gen.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/string/dynamic_rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp
- /verify/verify/unit_test/string/dynamic_rolling_hash.test.cpp.html
title: verify/unit_test/string/dynamic_rolling_hash.test.cpp
---
