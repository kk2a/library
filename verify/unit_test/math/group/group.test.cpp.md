---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/add.hpp
    title: math/group/add.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
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
  bundledCode: "#line 1 \"verify/unit_test/math/group/group.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"math/group/add.hpp\"\
    \n\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n\
    #include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct\
    \ istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate\
    \ <typename T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
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
    \ kk2\n\n\n#line 5 \"math/group/add.hpp\"\n\nnamespace kk2 {\n\nnamespace group\
    \ {\n\ntemplate <class S> struct Add {\n    static constexpr bool commutative\
    \ = true;\n    using M = Add;\n    S a;\n\n    Add() : a(S()) {}\n    Add(S a_)\
    \ : a(a_) {}\n    operator S() const { return a; }\n    inline static M op(M l,\
    \ M r) { return M(l.a + r.a); }\n    inline static M inv(M x) { return M(-x.a);\
    \ }\n    inline static M unit() { return M(); }\n    bool operator==(const M &rhs)\
    \ const { return a == rhs.a; }\n    bool operator!=(const M &rhs) const { return\
    \ a != rhs.a; }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const M &x) {\n        return os\
    \ << x.a;\n    }\n\n    template <class IStream, is_istream_t<IStream> * = nullptr>\n\
    \    friend IStream &operator>>(IStream &is, M &x) {\n        return is >> x.a;\n\
    \    }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n\n#line 1 \"math/group/rolling_hash.hpp\"\
    \n\n\n\n#include <vector>\n\n#line 1 \"random/hash.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n\n#line 1 \"math_mod/primitive_root_64bit.hpp\"\
    \n\n\n\n#line 1 \"math/prime_factorize.hpp\"\n\n\n\n#line 5 \"math/prime_factorize.hpp\"\
    \n#include <map>\n#include <numeric>\n#include <utility>\n#line 9 \"math/prime_factorize.hpp\"\
    \n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m\
    \ = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n \
    \       if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n\
    \    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont_arb.hpp\"\
    \n\n\n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n#line 7 \"modint/mont_arb.hpp\"\
    \n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\
    \n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value\n      \
    \                            or std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
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
    \n} // namespace kk2\n\n\n#line 10 \"modint/mont_arb.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <typename Int, typename UInt, typename Long, typename ULong, int id>\n\
    struct ArbitraryLazyMontgomeryModIntBase {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\
    \n    inline static UInt mod;\n    inline static UInt r;\n    inline static UInt\
    \ n2;\n    static constexpr int bit_length = sizeof(UInt) * 8;\n\n    static UInt\
    \ get_r() {\n        UInt ret = mod;\n        while (mod * ret != 1) ret *= UInt(2)\
    \ - mod * ret;\n        return ret;\n    }\n\n    static void setmod(UInt m) {\n\
    \        assert(m < (UInt(1u) << (bit_length - 2)));\n        assert(m & 1);\n\
    \        mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n\n    UInt _v;\n\n\
    \    ArbitraryLazyMontgomeryModIntBase() : _v(0) {}\n\n    template <class T,\
    \ is_integral_t<T> * = nullptr> ArbitraryLazyMontgomeryModIntBase(const T &b)\n\
    \        : _v(reduce(ULong(b % (Int)mod + mod) * n2)) {}\n\n    static UInt reduce(const\
    \ ULong &b) {\n        return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \    }\n\n    mint &operator+=(const mint &b) {\n        if (Int(_v += b._v -\
    \ 2 * mod) < 0) _v += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const\
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
    \ std::enable_if_t<is_container<T>::value>;\n\n} // namespace kk2\n\n\n#line 9\
    \ \"math/group/rolling_hash.hpp\"\n\nnamespace kk2 {\n\nnamespace group {\n\n\
    template <int Num> struct RollingHash {\n    static constexpr bool commutative\
    \ = false;\n    using mint = ModInt2_61m1;\n    using M = RollingHash;\n    using\
    \ H = random::Hash<Num>;\n\n    inline static H base = H::get_base(), inv_base\
    \ = base.inv();\n\n    H a, pw, ipw;\n    RollingHash() : a(0), pw(1), ipw(1)\
    \ {}\n    RollingHash(H a_, H pw_, H ipw_) : a(a_), pw(pw_), ipw(ipw_) {}\n  \
    \  template <class T, is_integral_t<T> * = nullptr> RollingHash(T x)\n       \
    \ : a(x),\n          pw(base),\n          ipw(inv_base) {}\n\n    // s[0] * base^0\
    \ + s[1] * base^1 + ... + s[n-1] * base^(n-1)\n    template <class C, is_container_t<C>\
    \ * = nullptr> RollingHash(const C &s)\n        : a(0),\n          pw(1),\n  \
    \        ipw(inv_base.pow(s.size())) {\n        for (auto x : s) {\n         \
    \   a += pw * H(x);\n            pw *= base;\n        }\n    }\n    operator H()\
    \ const { return a; }\n    inline static M op(M l, M r) { return M(l.a + r.a *\
    \ l.pw, l.pw * r.pw, l.ipw * r.ipw); }\n    inline static M inv(M x) { return\
    \ M(-x.ipw * x.a, x.ipw, x.pw); }\n    inline static M unit() { return M(); }\n\
    \    bool operator==(const M &rhs) const { return a == rhs.a and pw == rhs.pw\
    \ and ipw == rhs.ipw; }\n    bool operator!=(const M &rhs) const { return a !=\
    \ rhs.a or pw != rhs.pw or ipw != rhs.ipw; }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"(\"\
    \ << a << \", \" << pw << \", \" << ipw << \")\";\n    }\n};\n\n} // namespace\
    \ group\n\n} // namespace kk2\n\n\n#line 1 \"math/group/sum_with_size.hpp\"\n\n\
    \n\n#line 5 \"math/group/sum_with_size.hpp\"\n\nnamespace kk2 {\n\nnamespace group\
    \ {\n\ntemplate <class S, class T = S> struct SumWithSize {\n    static constexpr\
    \ bool commutative = true;\n    using M = SumWithSize;\n    S a;\n    T size;\n\
    \n    SumWithSize() : a(S()), size(0) {}\n    SumWithSize(S a_, S size_ = T(1))\
    \ : a(a_), size(size_) {}\n    operator S() const { return a; }\n    inline static\
    \ M op(M l, M r) { return M(l.a + r.a, l.size + r.size); }\n    inline static\
    \ M inv(M x) { return M(-x.a, -x.size); }\n    inline static M unit() { return\
    \ M(); }\n    bool operator==(const M &rhs) const { return a == rhs.a and size\
    \ == rhs.size; }\n    bool operator!=(const M &rhs) const { return a != rhs.a\
    \ or size != rhs.size; }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    friend OStream &operator<<(OStream &os, const M &x) {\n  \
    \      return os << x.a << \" \" << x.size;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ M &x) {\n        is >> x.a;\n        x.size = T(1);\n        return is;\n  \
    \  }\n};\n\n} // namespace group\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#line 6 \"template/template.hpp\"\n#include <bitset>\n#line 9 \"template/template.hpp\"\
    \n#include <cmath>\n#line 11 \"template/template.hpp\"\n#include <functional>\n\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 8 \"verify/unit_test/math/group/group.test.cpp\"\
    \nusing namespace std;\n\nvoid test_group() {\n    // Add group test\n    {\n\
    \        using G = kk2::group::Add<int>;\n        G unit = G::unit();\n\n    \
    \    rep(10000) {\n            int val1 = kk2::random::rng(-1000, 1001);\n   \
    \         int val2 = kk2::random::rng(-1000, 1001);\n            G a(val1), b(val2);\n\
    \n            assert(G::op(unit, a) == a);\n            assert(G::op(a, unit)\
    \ == a);\n            assert(G::op(a, b).a == val1 + val2);\n\n            auto\
    \ inv_a = G::inv(a);\n            assert(inv_a.a == -val1);\n            assert(G::op(a,\
    \ inv_a) == unit);\n            assert(G::op(inv_a, a) == unit);\n        }\n\
    \        cerr << \"Add: 10000 random tests passed!\" << endl;\n    }\n\n    //\
    \ SumWithSize group test\n    {\n        using G = kk2::group::SumWithSize<int>;\n\
    \        G unit = G::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(-1000,\
    \ 1001);\n            int val2 = kk2::random::rng(-1000, 1001);\n            G\
    \ a(val1), b(val2);\n\n            auto ab = G::op(a, b);\n            assert(ab.a\
    \ == val1 + val2 && ab.size == 2);\n\n            auto inv_a = G::inv(a);\n  \
    \          assert(inv_a.a == -val1 && inv_a.size == -1);\n\n            auto cancel\
    \ = G::op(a, inv_a);\n            assert(cancel == unit);\n        }\n       \
    \ cerr << \"SumWithSize: 10000 random tests passed!\" << endl;\n    }\n\n    //\
    \ RollingHash group test\n    {\n        using RH = kk2::group::RollingHash<2>;\n\
    \        RH unit = RH::unit();\n\n        // \u4E71\u6570\u3092\u4F7F\u3063\u305F\
    \u8907\u6570\u56DE\u30C6\u30B9\u30C8\n        rep(10000) {\n            // \u30E9\
    \u30F3\u30C0\u30E0\u306A\u6574\u6570\u3067\u306E\u30C6\u30B9\u30C8\n         \
    \   int val1 = kk2::random::rng(1, 1001);\n            int val2 = kk2::random::rng(1,\
    \ 1001);\n            RH a(val1), b(val2);\n\n            assert(RH::op(unit,\
    \ a) == a);\n            assert(RH::op(a, unit) == a);\n\n            // \u9006\
    \u5143\u306E\u30C6\u30B9\u30C8\n            auto inv_a = RH::inv(a);\n       \
    \     auto cancel = RH::op(a, inv_a);\n            assert(cancel == unit);\n\n\
    \            // \u30E9\u30F3\u30C0\u30E0\u306A\u6587\u5B57\u5217\u3067\u306E\u30C6\
    \u30B9\u30C8\n            string s1, s2;\n            int len1 = kk2::random::rng(1,\
    \ 11);\n            int len2 = kk2::random::rng(1, 11);\n\n            rep(len1)\
    \ { s1 += char('a' + kk2::random::rng(0, 26)); }\n            rep(len2) { s2 +=\
    \ char('a' + kk2::random::rng(0, 26)); }\n\n            RH h1(s1), h2(s2);\n \
    \           RH h12 = RH::op(h1, h2); // s1 + s2\n            RH h_concat(s1 +\
    \ s2);\n            assert(h12.a == h_concat.a);\n\n            // \u9006\u5143\
    \u3067\u306E\u9023\u7D50\u30C6\u30B9\u30C8\n            auto inv_h2 = RH::inv(h2);\n\
    \            auto result = RH::op(h12, inv_h2);\n            assert(result.a ==\
    \ h1.a);\n\n            // \u7D50\u5408\u5F8B\u306E\u30C6\u30B9\u30C8\uFF083\u3064\
    \u306E\u6587\u5B57\u5217\uFF09\n            string s3;\n            int len3 =\
    \ kk2::random::rng(1, 11);\n            rep(len3) { s3 += char('a' + kk2::random::rng(0,\
    \ 26)); }\n            RH h3(s3);\n\n            RH h123_left = RH::op(RH::op(h1,\
    \ h2), h3);\n            RH h123_right = RH::op(h1, RH::op(h2, h3));\n       \
    \     RH h123_direct(s1 + s2 + s3);\n\n            assert(h123_left.a == h123_right.a);\n\
    \            assert(h123_left.a == h123_direct.a);\n        }\n\n        cerr\
    \ << \"RollingHash: 10000 random tests passed!\" << endl;\n    }\n}\n\nvoid test()\
    \ {\n    test_group();\n    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n  \
    \  cerr << \"All group tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../../math/group/add.hpp\"\n#include \"../../../../math/group/rolling_hash.hpp\"\
    \n#include \"../../../../math/group/sum_with_size.hpp\"\n#include \"../../../../random/gen.hpp\"\
    \n#include \"../../../../template/template.hpp\"\nusing namespace std;\n\nvoid\
    \ test_group() {\n    // Add group test\n    {\n        using G = kk2::group::Add<int>;\n\
    \        G unit = G::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(-1000,\
    \ 1001);\n            int val2 = kk2::random::rng(-1000, 1001);\n            G\
    \ a(val1), b(val2);\n\n            assert(G::op(unit, a) == a);\n            assert(G::op(a,\
    \ unit) == a);\n            assert(G::op(a, b).a == val1 + val2);\n\n        \
    \    auto inv_a = G::inv(a);\n            assert(inv_a.a == -val1);\n        \
    \    assert(G::op(a, inv_a) == unit);\n            assert(G::op(inv_a, a) == unit);\n\
    \        }\n        cerr << \"Add: 10000 random tests passed!\" << endl;\n   \
    \ }\n\n    // SumWithSize group test\n    {\n        using G = kk2::group::SumWithSize<int>;\n\
    \        G unit = G::unit();\n\n        rep(10000) {\n            int val1 = kk2::random::rng(-1000,\
    \ 1001);\n            int val2 = kk2::random::rng(-1000, 1001);\n            G\
    \ a(val1), b(val2);\n\n            auto ab = G::op(a, b);\n            assert(ab.a\
    \ == val1 + val2 && ab.size == 2);\n\n            auto inv_a = G::inv(a);\n  \
    \          assert(inv_a.a == -val1 && inv_a.size == -1);\n\n            auto cancel\
    \ = G::op(a, inv_a);\n            assert(cancel == unit);\n        }\n       \
    \ cerr << \"SumWithSize: 10000 random tests passed!\" << endl;\n    }\n\n    //\
    \ RollingHash group test\n    {\n        using RH = kk2::group::RollingHash<2>;\n\
    \        RH unit = RH::unit();\n\n        // \u4E71\u6570\u3092\u4F7F\u3063\u305F\
    \u8907\u6570\u56DE\u30C6\u30B9\u30C8\n        rep(10000) {\n            // \u30E9\
    \u30F3\u30C0\u30E0\u306A\u6574\u6570\u3067\u306E\u30C6\u30B9\u30C8\n         \
    \   int val1 = kk2::random::rng(1, 1001);\n            int val2 = kk2::random::rng(1,\
    \ 1001);\n            RH a(val1), b(val2);\n\n            assert(RH::op(unit,\
    \ a) == a);\n            assert(RH::op(a, unit) == a);\n\n            // \u9006\
    \u5143\u306E\u30C6\u30B9\u30C8\n            auto inv_a = RH::inv(a);\n       \
    \     auto cancel = RH::op(a, inv_a);\n            assert(cancel == unit);\n\n\
    \            // \u30E9\u30F3\u30C0\u30E0\u306A\u6587\u5B57\u5217\u3067\u306E\u30C6\
    \u30B9\u30C8\n            string s1, s2;\n            int len1 = kk2::random::rng(1,\
    \ 11);\n            int len2 = kk2::random::rng(1, 11);\n\n            rep(len1)\
    \ { s1 += char('a' + kk2::random::rng(0, 26)); }\n            rep(len2) { s2 +=\
    \ char('a' + kk2::random::rng(0, 26)); }\n\n            RH h1(s1), h2(s2);\n \
    \           RH h12 = RH::op(h1, h2); // s1 + s2\n            RH h_concat(s1 +\
    \ s2);\n            assert(h12.a == h_concat.a);\n\n            // \u9006\u5143\
    \u3067\u306E\u9023\u7D50\u30C6\u30B9\u30C8\n            auto inv_h2 = RH::inv(h2);\n\
    \            auto result = RH::op(h12, inv_h2);\n            assert(result.a ==\
    \ h1.a);\n\n            // \u7D50\u5408\u5F8B\u306E\u30C6\u30B9\u30C8\uFF083\u3064\
    \u306E\u6587\u5B57\u5217\uFF09\n            string s3;\n            int len3 =\
    \ kk2::random::rng(1, 11);\n            rep(len3) { s3 += char('a' + kk2::random::rng(0,\
    \ 26)); }\n            RH h3(s3);\n\n            RH h123_left = RH::op(RH::op(h1,\
    \ h2), h3);\n            RH h123_right = RH::op(h1, RH::op(h2, h3));\n       \
    \     RH h123_direct(s1 + s2 + s3);\n\n            assert(h123_left.a == h123_right.a);\n\
    \            assert(h123_left.a == h123_direct.a);\n        }\n\n        cerr\
    \ << \"RollingHash: 10000 random tests passed!\" << endl;\n    }\n}\n\nvoid test()\
    \ {\n    test_group();\n    \n    // \u5168\u30C6\u30B9\u30C8\u901A\u904E\n  \
    \  cerr << \"All group tests passed!\" << endl;\n}\n\nint main() {\n    int a,\
    \ b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    test();\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - math/group/add.hpp
  - type_traits/io.hpp
  - math/group/rolling_hash.hpp
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
  - type_traits/integral.hpp
  - math/group/sum_with_size.hpp
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
  path: verify/unit_test/math/group/group.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/group/group.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/group/group.test.cpp
- /verify/verify/unit_test/math/group/group.test.cpp.html
title: verify/unit_test/math/group/group.test.cpp
---
