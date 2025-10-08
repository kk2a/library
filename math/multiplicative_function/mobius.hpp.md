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
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    title: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/multiplicative_function/mobius.hpp\"\n\n\n\n#include\
    \ <cassert>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128\
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
    \n} // namespace kk2\n\n\n#line 1 \"math/prime_factorize.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <map>\n#include <numeric>\n#include <utility>\n#include\
    \ <vector>\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
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
    using number_theory::factorize_map;\n\n} // namespace kk2\n\n\n\n#line 8 \"math/multiplicative_function/mobius.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, is_integral_t<T> * = nullptr> int mobius(T\
    \ n) {\n    assert(n >= 0);\n    if (n == 0) return 0;\n    int res = 1;\n   \
    \ for (auto [p, k] : factorize(static_cast<long long>(n))) {\n        if (k >\
    \ 1) return 0;\n        res = -res;\n    }\n    return res;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../../type_traits/integral.hpp\"\n#include\
    \ \"../prime_factorize.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T, is_integral_t<T>\
    \ * = nullptr> int mobius(T n) {\n    assert(n >= 0);\n    if (n == 0) return\
    \ 0;\n    int res = 1;\n    for (auto [p, k] : factorize(static_cast<long long>(n)))\
    \ {\n        if (k > 1) return 0;\n        res = -res;\n    }\n    return res;\n\
    }\n\n} // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_MOBIUS_HPP\n"
  dependsOn:
  - type_traits/integral.hpp
  - math/prime_factorize.hpp
  - math_mod/pow_mod.hpp
  - modint/mont_arb.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - random/gen.hpp
  - random/seed.hpp
  - math/is_prime.hpp
  isVerificationFile: false
  path: math/multiplicative_function/mobius.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
documentation_of: math/multiplicative_function/mobius.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/mobius.hpp
- /library/math/multiplicative_function/mobius.hpp.html
title: math/multiplicative_function/mobius.hpp
---
