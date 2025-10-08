---
data:
  _extendedDependsOn:
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
    path: random/seed.hpp
    title: random/seed.hpp
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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/group/rolling_hash.hpp
    title: math/group/rolling_hash.hpp
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
  bundledCode: "#line 1 \"random/hash.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n\n#line 1 \"math_mod/primitive_root_64bit.hpp\"\
    \n\n\n\n#line 1 \"math/prime_factorize.hpp\"\n\n\n\n#line 5 \"math/prime_factorize.hpp\"\
    \n#include <map>\n#include <numeric>\n#include <utility>\n#include <vector>\n\n\
    #line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T x, U n,\
    \ T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m = m, r =\
    \ 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n        if\
    \ (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n \
    \   return r;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont_arb.hpp\"\n\n\
    \n\n#line 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n#line 7 \"modint/mont_arb.hpp\"\
    \n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
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
    \    }\n};\n\n} // namespace random\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_RANDOM_HASH_HPP\n#define KK2_RANDOM_HASH_HPP 1\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n\n#include \"../math_mod/primitive_root_64bit.hpp\"\
    \n#include \"../modint/modint_2_61m1.hpp\"\n#include \"gen.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\ntemplate <int NUM> struct Hash : std::array<ModInt2_61m1,\
    \ NUM> {\n    using mint = ModInt2_61m1;\n    using std::array<mint, NUM>::operator[];\n\
    \    using u64 = unsigned long long;\n\n    Hash() : std::array<mint, NUM>() {}\n\
    \n    template <class T, is_integral_t<T> * = nullptr> Hash(T x) {\n        std::fill(this->begin(),\
    \ this->end(), mint(x));\n    }\n\n    static Hash get_base() {\n        Hash\
    \ base;\n        for (int i = 0; i < NUM; i++) base[i] = primitive_root_mint<ModInt2_61m1>();\n\
    \        return base;\n    }\n\n    Hash &operator+=(const Hash &rhs) {\n    \
    \    for (int i = 0; i < NUM; i++) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n    Hash &operator-=(const Hash &rhs) {\n        for (int i = 0; i < NUM;\
    \ i++) (*this)[i] -= rhs[i];\n        return *this;\n    }\n    Hash &operator*=(const\
    \ Hash &rhs) {\n        for (int i = 0; i < NUM; i++) (*this)[i] *= rhs[i];\n\
    \        return *this;\n    }\n    Hash &operator/=(const Hash &rhs) {\n     \
    \   for (int i = 0; i < NUM; i++) (*this)[i] /= rhs[i];\n        return *this;\n\
    \    }\n\n    Hash operator+(const Hash &rhs) const { return Hash(*this) += rhs;\
    \ }\n    Hash operator-(const Hash &rhs) const { return Hash(*this) -= rhs; }\n\
    \    Hash operator*(const Hash &rhs) const { return Hash(*this) *= rhs; }\n  \
    \  Hash operator/(const Hash &rhs) const { return Hash(*this) /= rhs; }\n    Hash\
    \ operator+() const { return *this; }\n    Hash operator-() const { return Hash(0)\
    \ - *this; }\n\n    Hash pow(u64 n) const {\n        Hash r;\n        for (int\
    \ i = 0; i < NUM; i++) r[i] = (*this)[i].pow(n);\n        return r;\n    }\n\n\
    \    Hash inv() const {\n        Hash r;\n        for (int i = 0; i < NUM; i++)\
    \ r[i] = (*this)[i].inv();\n        return r;\n    }\n\n    static Hash mulplus(const\
    \ Hash &a, const Hash &b, const Hash &c) {\n        Hash res;\n        for (int\
    \ i = 0; i < NUM; i++) res[i] = mint::mulplus(a[i], b[i], c[i]);\n        return\
    \ res;\n    }\n\n    static Hash plusmul(const Hash &a, const Hash &b, const Hash\
    \ &c) {\n        Hash res;\n        for (int i = 0; i < NUM; i++) res[i] = mint::plusmul(a[i],\
    \ b[i], c[i]);\n        return res;\n    }\n};\n\n} // namespace random\n\n} //\
    \ namespace kk2\n\n#endif // KK2_RANDOM_HASH_HPP\n"
  dependsOn:
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
  isVerificationFile: false
  path: random/hash.hpp
  requiredBy:
  - string/static_rolling_hash.hpp
  - string/dynamic_rolling_hash.hpp
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
documentation_of: random/hash.hpp
layout: document
redirect_from:
- /library/random/hash.hpp
- /library/random/hash.hpp.html
title: random/hash.hpp
---
