---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/is_prime.hpp
    title: math/is_prime.hpp
  - icon: ':x:'
    path: math/prime_factorize.hpp
    title: math/prime_factorize.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':x:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':x:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':x:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"verify/yosupo_math/factrize.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/factorize\"\n\n#line 1 \"math/prime_factorize.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <map>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\
    \n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 7 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class S,\
    \ class T, class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(!is_signed_extended<U>::value\
    \ || n >= 0);\n    if (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y\
    \ = S(x) % _m;\n    if (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r\
    \ = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont_arb.hpp\"\n\n\n\n#line\
    \ 5 \"modint/mont_arb.hpp\"\n#include <iostream>\n#line 7 \"modint/mont_arb.hpp\"\
    \n\n#line 9 \"modint/mont_arb.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename Int,\
    \ typename UInt, typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n    using mint = ArbitraryLazyMontgomeryModIntBase;\n\n    inline static\
    \ UInt mod;\n    inline static UInt r;\n    inline static UInt n2;\n    static\
    \ constexpr int bit_length = sizeof(UInt) * 8;\n\n    static UInt get_r() {\n\
    \        UInt ret = mod;\n        while (mod * ret != 1) ret *= UInt(2) - mod\
    \ * ret;\n        return ret;\n    }\n\n    static void setmod(UInt m) {\n   \
    \     assert(m < (UInt(1u) << (bit_length - 2)));\n        assert((m & 1) == 1);\n\
    \        mod = m, n2 = -ULong(m) % m, r = get_r();\n    }\n\n    UInt _v;\n\n\
    \    operator Int() const { return val(); }\n\n    ArbitraryLazyMontgomeryModIntBase()\
    \ : _v(0) {}\n\n    template <class T, std::enable_if_t<is_integral_extended<T>::value>\
    \ * = nullptr>\n    ArbitraryLazyMontgomeryModIntBase(const T &b) : _v(reduce(ULong(b\
    \ % mod + mod) * n2)) {}\n\n    static UInt reduce(const ULong &b) {\n       \
    \ return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n    }\n\n    mint\
    \ &operator+=(const mint &b) {\n        if (Int(_v += b._v - 2 * mod) < 0) _v\
    \ += 2 * mod;\n        return *this;\n    }\n\n    mint &operator-=(const mint\
    \ &b) {\n        if (Int(_v -= b._v) < 0) _v += 2 * mod;\n        return *this;\n\
    \    }\n\n    mint &operator*=(const mint &b) {\n        _v = reduce(ULong(_v)\
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
    \ __uint128_t, id>;\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\
    \n#line 7 \"random/gen.hpp\"\n#include <unordered_set>\n#line 9 \"random/gen.hpp\"\
    \n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\n\
    namespace random {\n\nusing u64 = unsigned long long;\n\nu64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count();\n    seed ^= reinterpret_cast<u64>(&seed);\n   \
    \ seed ^= seed << 5;\n    seed ^= seed >> 41;\n    seed ^= seed << 20;\n    return\
    \ seed;\n}\n\nu64 deterministic_seed() {\n    return 5801799128519729247ull;\n\
    }\n\nu64 seed() {\n#if defined(KK2) && !defined(KK2_RANDOM_NON_DETERMINISTIC)\n\
    \    return deterministic_seed();\n#else\n    return non_deterministic_seed();\n\
    #endif\n}\n\n} // namespace random\n\n} // namespace kk2\n\n\n#line 11 \"random/gen.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace random {\n\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\nu64 xorshift128plus(u64 &x, u64 &y) {\n    u64 t =\
    \ x;\n    t ^= t << 23;\n    t ^= t >> 17;\n    t ^= y ^ (y >> 26);\n    x = y;\n\
    \    y = t;\n    return x + y;\n}\n\nconstexpr int iterations = 100;\n\nvoid warm_up(u64\
    \ &x, u64 &y) {\n    for (int i = 0; i < iterations; i++) xorshift128plus(x, y);\n\
    }\n\nu64 rng() {\n    static bool first = true;\n    static u64 x = seed(), y\
    \ = seed();\n    if (first) {\n        warm_up(x, y);\n        first = false;\n\
    \    }\n    return xorshift128plus(x, y);\n}\n\n// [l, r)\ni64 rng(i64 l, i64\
    \ r) {\n    assert(l < r);\n    return l + rng() % (r - l);\n}\n\n// [l, r)\n\
    template <class T>\nstd::vector<T> random_vector(int n, T l, T r) {\n    std::vector<T>\
    \ res(n);\n    for (int i = 0; i < n; i++) res[i] = rng(l, r);\n    return res;\n\
    }\n\n// [l, r)\nstd::vector<i64> distinct_rng(i64 l, i64 r, i64 n) {\n    assert(l\
    \ < r and n <= r - l);\n    std::unordered_set<i64> st;\n    for (i64 i = n; i;\
    \ --i) {\n        i64 m = rng(l, r + 1 - i);\n        if (st.find(m) != st.end())\
    \ m = r - i;\n        st.insert(m);\n    }\n    std::vector<i64> res(st.begin(),\
    \ st.end());\n    std::sort(res.begin(), res.end());\n    return res;\n}\n\ntemplate\
    \ <class Iter> void shuffle(Iter first, Iter last) {\n    if (first == last) return;\n\
    \    int len = 1;\n    for (auto it = first + 1; it != last; ++it) {\n       \
    \ len++;\n        int j = rng(0, len);\n        if (j != len - 1) std::iter_swap(first\
    \ + j, it);\n    }\n}\n\ntemplate <class T> std::vector<T> perm(int n) {\n   \
    \ std::vector<T> res(n);\n    std::iota(res.begin(), res.end(), T(0));\n    shuffle(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate <class T> std::vector<T> choices(int\
    \ l, int r, int k) {\n    assert(l < r and k <= r - l);\n    std::vector<T> res(r\
    \ - l);\n    std::iota(res.begin(), res.end(), T(l));\n    shuffle(res.begin(),\
    \ res.end());\n    res.resize(k);\n    return res;\n}\n\n} // namespace random\n\
    \n} // namespace kk2\n\n\n#line 1 \"math/is_prime.hpp\"\n\n\n\n#line 5 \"math/is_prime.hpp\"\
    \n\n#line 8 \"math/is_prime.hpp\"\n\nnamespace kk2 {\n\nnamespace number_theory\
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
    \ mint64 = ArbitraryLazyMontgomeryModInt64bit<54355165>;\n    if (n == 1) return\
    \ {};\n    if (n < 0) n = -n;\n    u64 p;\n    if (n <= (1ll << 30)) {\n     \
    \   p = pollard_rho<mint32, unsigned int>(n);\n    } else if (n <= (1ll << 62))\
    \ {\n        p = pollard_rho<mint64, unsigned long long>(n);\n    } else {\n \
    \       exit(1);\n    }\n    if (p == n) return {i64(p)};\n    auto l = inner_factorize(p);\n\
    \    auto r = inner_factorize(n / p);\n    std::copy(r.begin(), r.end(), std::back_inserter(l));\n\
    \    return l;\n}\n\nstd::vector<std::pair<i64, int>> factorize(i64 n) {\n   \
    \ auto tmp = inner_factorize(n);\n    std::sort(tmp.begin(), tmp.end());\n   \
    \ std::vector<std::pair<i64, int>> res;\n    for (int i = 0; i < (int)tmp.size();\
    \ i++) {\n        if (i == 0 or res.back().first != tmp[i]) {\n            res.emplace_back(tmp[i],\
    \ 1);\n        } else {\n            res.back().second++;\n        }\n    }\n\
    \    return res;\n}\n\nstd::map<i64, int> factorize_map(i64 n) {\n    auto tmp\
    \ = inner_factorize(n);\n    std::map<i64, int> res;\n    for (auto x : tmp) res[x]++;\n\
    \    return res;\n}\n\nstd::vector<i64> divisors(i64 n) {\n    if (n == 0) return\
    \ {};\n\n    auto f = factorize(n);\n    std::vector<i64> res = {1};\n    for\
    \ (auto [p, k] : f) {\n        int sz = res.size();\n        i64 x = 1;\n    \
    \    for (int i = 0; i < k; i++) {\n            x *= p;\n            for (int\
    \ j = 0; j < sz; j++) { res.emplace_back(res[j] * x); }\n        }\n    }\n  \
    \  std::sort(res.begin(), res.end());\n    return res;\n}\n\n} // namespace number_theory\n\
    \nusing number_theory::divisors;\nusing number_theory::factorize;\nusing number_theory::factorize_map;\n\
    \n} // namespace kk2\n\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC\
    \ optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 12 \"template/template.hpp\"\n#include\
    \ <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n#line 23 \"template/template.hpp\"\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\
    \n#include <unordered_map>\n#line 36 \"template/template.hpp\"\n\nusing u32 =\
    \ unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\n\
    using pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing pli =\
    \ std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\ntemplate\
    \ <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
    template <class T> using vvvvc = std::vector<vvvc<T>>;\n\ntemplate <class T> using\
    \ pq = std::priority_queue<T>;\ntemplate <class T> using pqi = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate <class T> constexpr T infty =\
    \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
    \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
    \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
    \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
    \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double>\
    \ = infty<i64>;\ntemplate <> constexpr long double infty<long double> = infty<i64>;\n\
    \nconstexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\nnamespace kk2 {\n\ntemplate <class T,\
    \ class... Sizes> auto make_vector(int first, Sizes... sizes) {\n    if constexpr\
    \ (sizeof...(sizes) == 0) {\n        return std::vector<T>(first);\n    } else\
    \ {\n        return std::vector<decltype(make_vector(sizes...))>(first, make_vector(sizes...));\n\
    \    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T> &v, const\
    \ U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate <class\
    \ T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x) {\n  \
    \  for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate <class\
    \ T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b ? a = b,\
    \ 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nenum yes_no_enum { Yes, No, YES,\
    \ NO, yes, no };\n\ntemplate <yes_no_enum YN> void yn(bool b = 1) {\n    if constexpr\
    \ (YN == Yes) std::cout << (b ? \"Yes\" : \"No\") << '\\n';\n    if constexpr\
    \ (YN == No) std::cout << (b ? \"No\" : \"Yes\") << '\\n';\n    if constexpr (YN\
    \ == YES) std::cout << (b ? \"YES\" : \"NO\") << '\\n';\n    if constexpr (YN\
    \ == NO) std::cout << (b ? \"NO\" : \"YES\") << '\\n';\n    if constexpr (YN ==\
    \ yes) std::cout << (b ? \"yes\" : \"no\") << '\\n';\n    if constexpr (YN ==\
    \ no) std::cout << (b ? \"no\" : \"yes\") << '\\n';\n}\n\n#define rep1(a) for\
    \ (i64 _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\n#ifdef KK2\nstd::ifstream in(\"in.txt\");\nstd::ofstream out(\"\
    out.txt\");\n#else\n#define in std::cin\n#define out std::cout\n#endif\n\ntemplate\
    \ <class OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_math/factrize.test.cpp\"\nusing\
    \ namespace std;\n\nint main() {\n    int q;\n    cin >> q;\n    rep (q) {\n \
    \       i64 a;\n        cin >> a;\n        int cnt = 0;\n        auto f = kk2::factorize(a);\n\
    \        for (auto [p, e] : f) cnt += e;\n        cout << cnt << ' ';\n      \
    \  for (auto [p, e] : f)\n            rep (e) cout << p << ' ';\n        cout\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../../math/prime_factorize.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int q;\n    cin >> q;\n    rep (q)\
    \ {\n        i64 a;\n        cin >> a;\n        int cnt = 0;\n        auto f =\
    \ kk2::factorize(a);\n        for (auto [p, e] : f) cnt += e;\n        cout <<\
    \ cnt << ' ';\n        for (auto [p, e] : f)\n            rep (e) cout << p <<\
    \ ' ';\n        cout << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - modint/mont_arb.hpp
  - type_traits/type_traits.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_math/factrize.test.cpp
  requiredBy: []
  timestamp: '2024-10-09 00:31:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_math/factrize.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/factrize.test.cpp
- /verify/verify/yosupo_math/factrize.test.cpp.html
title: verify/yosupo_math/factrize.test.cpp
---
