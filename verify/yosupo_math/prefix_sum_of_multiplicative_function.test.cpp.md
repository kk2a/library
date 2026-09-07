---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_multiplicative_function\n\
      \n#include \"../../math/multiplicative_function/prefix_sum.hpp\"\n#include \"\
      ../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
      \ std;\n\nusing mint = kk2::Mont<469762049>;\n\nint main() {\n    int t;\n \
      \   kin >> t;\n    rep (t) {\n        i64 n;\n        mint a, b;\n        kin\
      \ >> n >> a >> b;\n        auto f = [&](i64 p, i64 e) -> mint { return a * e\
      \ + b * p; };\n        auto g1 = [&](i64) -> mint { return 1; };\n        auto\
      \ g2 = [&](i64 p) -> mint { return p; };\n        kk2::PrefixSumOfMultiplicativeFunction<mint>\
      \ ps(n);\n        vc<mint> init1(ps.size()), init2(ps.size());\n        const\
      \ mint inv2 = mint(2).inv();\n        rep (i, ps.size()) {\n            init1[i]\
      \ = ps.eq[i] - 1;\n            init2[i] = mint(ps.eq[i]) * (ps.eq[i] + 1) *\
      \ inv2 - 1;\n        }\n        ps.LucyDP(g1, init1);\n        ps.LucyDP(g2,\
      \ init2);\n        rep (i, ps.size()) ps.prefix_sum_only_prime[i] = a * init1[i]\
      \ + b * init2[i];\n        ps.Min_25Sieve(f);\n        kout << ps.prefix_sum.back()\
      \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
    name: default
  - code: "#line 1 \"verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp\"\
      \n// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_multiplicative_function\n\
      \n#line 1 \"math/multiplicative_function/prefix_sum.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <vector>\n\n#line 1 \"math/enumerate_quotients.hpp\"\n\n\n\n#include\
      \ <numeric>\n#line 6 \"math/enumerate_quotients.hpp\"\n\n#line 1 \"math/sqrt_floor.hpp\"\
      \n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include\
      \ <cassert>\n\nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in\
      \ Z) ...(1)\n// floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return\
      \ floor(a / b)\ntemplate <typename T, typename U> constexpr T fracfloor(T a,\
      \ U b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a\
      \ >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)      by (2)\n    //   \
      \       = -floor(-x) - 1 by (1)\n    return -((-a) / b) - 1;\n}\n\n// return\
      \ ceil(a / b)\ntemplate <typename T, typename U> constexpr T fracceil(T a, U\
      \ b) {\n    assert(b != 0);\n    if (a % b == 0) return a / b;\n    if (a >=\
      \ 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by (2)\n    return\
      \ -((-a) / b);\n}\n\n} // namespace kk2\n\n\n#line 7 \"math/sqrt_floor.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <typename T> T sqrt_floor(T n) {\n    assert(n\
      \ >= 0);\n    if (n == T(0)) return 0;\n    T x = std::sqrt(n);\n    if (x ==\
      \ T(0)) ++x;\n    while (x > kk2::fracfloor(n, x)) --x;\n    while (x + 1 <=\
      \ kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n}\n\ntemplate <typename T>\
      \ T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n <= T(1)) return n;\n  \
      \  T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x < kk2::fracceil(n,\
      \ x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1)) --x;\n    return x;\n\
      }\n\n} // namespace kk2\n\n\n#line 8 \"math/enumerate_quotients.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class T> struct EnumerateQuotients {\n    T n;\n    int\
      \ sqrt_n;\n    std::vector<T> res;\n\n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n))\
      \ {\n        res.resize(sqrt_n + n / (sqrt_n + 1));\n        std::iota(res.begin(),\
      \ res.begin() + sqrt_n, 1);\n        for (T i = n / (sqrt_n + 1), j = sqrt_n;\
      \ i; --i, ++j) res[j] = n / i;\n    }\n\n    const std::vector<T> &get() const\
      \ { return res; }\n\n    int size() const { return res.size(); }\n\n    const\
      \ T &operator[](int i) const { return res[i]; }\n\n    int idx(T x) const {\n\
      \        if (x <= sqrt_n) return x - 1;\n        return size() - n / x;\n  \
      \  }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/prime_table.hpp\"\n\n\n\n\
      #line 6 \"math/prime_table.hpp\"\n\n#line 8 \"math/prime_table.hpp\"\n\nnamespace\
      \ kk2 {\n\nstruct PrimeTable {\n  private:\n    static inline int _n = 30;\n\
      \    static inline std::vector<int> _primes{2, 3, 5, 7, 11, 13, 17, 19, 23,\
      \ 29};\n\n  public:\n    PrimeTable() = delete;\n\n    // wheel sieve\n    //\
      \ reference: https://37zigen.com/wheel-sieve/\n    static void set_upper(int\
      \ m, int reserve_size = 26355867) {\n        if (m <= _n) return;\n        _n\
      \ = std::max(m, 2 * _n);\n        int sqrt_n = sqrt_floor(_n);\n        int\
      \ w = 1;\n        std::vector<bool> iscoprime(sqrt_n, true);\n        for (int\
      \ i = 0; i < 9; i++) {\n            if (w * _primes[i] > sqrt_n) break;\n  \
      \          w *= _primes[i];\n            for (int j = _primes[i]; j < sqrt_n;\
      \ j += _primes[i]) iscoprime[j] = false;\n        }\n\n        std::vector<int>\
      \ idx_(w, -1);\n        int s = 0;\n        for (int i = 1; i < w; i++) {\n\
      \            if (iscoprime[i]) idx_[i] = s++;\n        }\n        std::vector<int>\
      \ coprimes(s);\n        for (int i = 1; i < w; i++) {\n            if (idx_[i]\
      \ != -1) coprimes[idx_[i]] = i;\n        }\n\n        auto idx = [&](long long\
      \ x) -> long long {\n            if (idx_[x % w] == -1) return -1;\n       \
      \     return x / w * s + idx_[x % w];\n        };\n\n        auto val = [&](int\
      \ i) {\n            return i / s * w + coprimes[i % s];\n        };\n\n    \
      \    int n = (_n + w - 1) / w * s;\n        std::vector<int> _primes2;\n   \
      \     _primes2.reserve(reserve_size);\n        std::vector<int> lpf(n, 0);\n\
      \        for (int i = 1; i < n; i++) {\n            int v = val(i);\n      \
      \      if (lpf[i] == 0) {\n                lpf[i] = v;\n                _primes2.push_back(lpf[i]);\n\
      \            }\n\n            for (const long long p : _primes2) {\n       \
      \         long long j = idx(p * v);\n                if (j >= n) break;\n  \
      \              if (lpf[i] < p) break;\n                lpf[j] = p;\n       \
      \     }\n        }\n\n        std::vector<int> tmp;\n        tmp.reserve(_primes.size()\
      \ + _primes2.size());\n        std::set_union(_primes.begin(),\n           \
      \            _primes.end(),\n                       _primes2.begin(),\n    \
      \                   _primes2.end(),\n                       std::back_inserter(tmp));\n\
      \        _primes = std::move(tmp);\n    }\n\n    static const std::vector<int>\
      \ &primes() { return _primes; }\n\n    template <typename It> struct PrimeIt\
      \ {\n        It bg, ed;\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_)\
      \ {}\n        It begin() const { return bg; }\n        It end() const { return\
      \ ed; }\n        int size() const { return ed - bg; }\n        int operator[](int\
      \ i) const { return bg[i]; }\n        std::vector<int> to_vec() const { return\
      \ std::vector<int>(bg, ed); }\n    };\n\n    static auto primes(int n) {\n \
      \       if (n >= _n) set_upper(n);\n        return PrimeIt(_primes.begin(),\
      \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n};\n\n} // namespace\
      \ kk2\n\n\n#line 9 \"math/multiplicative_function/prefix_sum.hpp\"\n\nnamespace\
      \ kk2 {\n\n\n// f: multiplicative function\n// f = a * g_1 + b * g_2 + ...\n\
      // g_i: completely multiplicative function\n// there exists s.t. h_i(p) = g(p)\
      \ and can compute sum_x h_i(x)\ntemplate <class T> struct PrefixSumOfMultiplicativeFunction\
      \ {\n    long long n;\n    EnumerateQuotients<long long> eq;\n    std::vector<T>\
      \ prefix_sum_only_prime;\n    std::vector<T> prefix_sum;\n\n    PrefixSumOfMultiplicativeFunction(long\
      \ long n)\n        : n(n),\n          eq(n),\n          prefix_sum_only_prime(eq.size()),\n\
      \          prefix_sum(eq.size()) {}\n\n    int size() const { return eq.size();\
      \ }\n\n    template <T (*f)(long long)> void LucyDP(std::vector<T> &dp) {\n\
      \        LucyDP([](long long x) { return f(x); }, dp);\n    }\n\n    // f is\
      \ completely multiplicative function\n    template <class F> void LucyDP(const\
      \ F &f, std::vector<T> &dp) {\n        assert((int)dp.size() == eq.size());\n\
      \        PrimeTable::set_upper(eq.sqrt_n);\n        for (const long long p :\
      \ PrimeTable::primes()) {\n            if (p > eq.sqrt_n) break;\n         \
      \   T fp = f(p);\n            for (int i = eq.size() - 1;; --i) {\n        \
      \        if (eq[i] < p * p) break;\n                dp[i] -= (dp[eq.idx(eq[i]\
      \ / p)] - dp[p - 2]) * fp;\n            }\n        }\n    }\n\n    template\
      \ <T (*f)(long long, long long)> void Min_25Sieve() {\n        Min_25Sieve([](long\
      \ long x, long long y) { return f(x, y); });\n    }\n\n    // f is multiplicative\
      \ function\n    template <class F> void Min_25Sieve(const F &f) {\n        PrimeTable::set_upper(eq.sqrt_n);\n\
      \        std::copy(prefix_sum_only_prime.begin(), prefix_sum_only_prime.end(),\
      \ prefix_sum.begin());\n        const auto &primes = PrimeTable::primes();\n\
      \        std::vector<T> tmp(eq.size());\n        for (int i = std::upper_bound(primes.begin(),\
      \ primes.end(), eq.sqrt_n) - primes.begin() - 1;\n             i >= 0;\n   \
      \          --i) {\n            const long long p = primes[i];\n            T\
      \ pk = f(p, 1);\n            T pk1;\n            for (long long p_pw = p, k\
      \ = 1; n / p >= p_pw; ++k, p_pw *= p) {\n                T pk1 = f(p, k + 1);\n\
      \                for (int j = eq.size() - 1;; --j) {\n                    if\
      \ (eq[j] < p_pw * p) break;\n                    tmp[j] += pk * (prefix_sum[eq.idx(eq[j]\
      \ / p_pw)] - prefix_sum_only_prime[p - 1])\n                              +\
      \ pk1;\n                }\n                pk = pk1;\n            }\n      \
      \      for (int j = eq.size() - 1;; --j) {\n                if (eq[j] < p *\
      \ p) break;\n                prefix_sum[j] += tmp[j];\n                tmp[j]\
      \ = T();\n            }\n        }\n        for (int i = 0; i < eq.size(); ++i)\
      \ ++prefix_sum[i];\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\
      \n\n\n\n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n#include <iostream>\n\
      #include <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line\
      \ 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\n\
      template <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
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
      \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
      template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
      \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
      \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
      \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n      \
      \  return ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr\
      \ u32 n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\"\
      );\n    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
      \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
      \ : _v(0) {}\n\n    template <Integral T> constexpr LazyMontgomeryModInt(T b)\n\
      \        : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr u32 reduce(const\
      \ u64 &b) { return (b + u64(u32(b) * u32(-r)) * p) >> 32; }\n    constexpr mint\
      \ &operator++() { return *this += 1; }\n    constexpr mint &operator--() { return\
      \ *this -= 1; }\n\n    constexpr mint operator++(int) {\n        mint ret =\
      \ *this;\n        *this += 1;\n        return ret;\n    }\n\n    constexpr mint\
      \ operator--(int) {\n        mint ret = *this;\n        *this -= 1;\n      \
      \  return ret;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n \
      \       if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n\
      \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(_v\
      \ -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
      \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n\
      \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b)\
      \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr\
      \ bool operator==(const mint &b) const {\n        return (_v >= p ? _v - p :\
      \ _v) == (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
      \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
      \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
      \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
      \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
      \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const\
      \ mint &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const\
      \ mint &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint\
      \ operator/(const mint &a, const mint &b) { return mint(a) /= b; }\n\n    template\
      \ <class T> constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n\
      \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            if\
      \ (n >>= 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    constexpr\
      \ mint inv() const {\n        assert(*this != mint(0));\n        return pow(p\
      \ - 2);\n    }\n\n    template <OutputStream OStream>\n    friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream>\n    friend IStream &operator>>(IStream &is, mint &x)\
      \ {\n        i64 t;\n        is >> t;\n        x = mint(t);\n        return\
      \ (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n\
      \        return ret >= p ? ret - p : ret;\n    }\n\n    static constexpr u32\
      \ getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
      \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
      \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
      \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
      \ <chrono>\n#line 10 \"template/template.hpp\"\n#include <deque>\n#include <functional>\n\
      #include <iterator>\n#include <limits>\n#include <map>\n#line 16 \"template/template.hpp\"\
      \n#include <optional>\n#include <queue>\n#include <random>\n#include <set>\n\
      #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
      #include <utility>\n#line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\
      \n\n\n\n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
      \n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned\
      \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi\
      \ = std::pair<int, int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int,\
      \ i64>;\nusing pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
      template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using\
      \ vvvc = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
      \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T>\
      \ using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n\
      #line 5 \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty =\
      \ 0;\ntemplate <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr\
      \ i64 infty<i64> = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128>\
      \ = (i128(1) << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32>\
      \ = infty<int>;\ntemplate <> constexpr u64 infty<u64> = infty<i64>;\ntemplate\
      \ <> constexpr u128 infty<u128> = infty<i128>;\ntemplate <> constexpr double\
      \ infty<double> = infty<i64>;\ntemplate <> constexpr long double infty<long\
      \ double> = infty<i64>;\n\nconstexpr int mod = 998244353;\nconstexpr int modu\
      \ = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\n\n#line\
      \ 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#line 6 \"template/fastio.hpp\"\
      \n#include <cstdio>\n#line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag\
      \ {\n  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t\
      \ pos = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n\
      \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
      \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
      \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
      \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
      \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if\
      \ (end == 0) is_eof = true;\n            pos = 0;\n        }\n        return\
      \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
      \ ++pos;\n    }\n\n    template <UnsignedIntegral T> T next_unsigned_integral()\
      \ {\n        skip_space();\n        T res{};\n        while (isdigit(now()))\
      \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n     \
      \   }\n        return res;\n    }\n\n    template <SignedIntegral T> T next_signed_integral()\
      \ {\n        skip_space();\n        if (now() == '-') {\n            ++pos;\n\
      \            return T(-next_unsigned_integral<typename to_unsigned<T>::type>());\n\
      \        } else return (T)next_unsigned_integral<typename to_unsigned<T>::type>();\n\
      \    }\n\n    char next_char() {\n        skip_space();\n        auto res =\
      \ now();\n        ++pos;\n        return res;\n    }\n\n    std::string next_string()\
      \ {\n        skip_space();\n        std::string res;\n        while (true) {\n\
      \            char c = now();\n            if (isspace(c) or c == '\\0') break;\n\
      \            res.push_back(now());\n            ++pos;\n        }\n        return\
      \ res;\n    }\n\n    template <UnsignedIntegral T> Scanner &operator>>(T &x)\
      \ {\n        x = next_unsigned_integral<T>();\n        return *this;\n    }\n\
      \n    template <SignedIntegral T> Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n\
      \        return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n      \
      \  x = next_char();\n        return *this;\n    }\n\n    Scanner &operator>>(std::string\
      \ &x) {\n        x = next_string();\n        return *this;\n    }\n};\n\nstruct\
      \ endl_struct_t {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n\
      \    static char helper[10000][5];\n    static char leading_zero[10000][5];\n\
      \    constexpr static size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n\
      \    size_t pos = 0;\n    FILE *fp;\n\n    template <class T> static constexpr\
      \ void div_mod(T &a, T &b, T mod) {\n        a = b / mod;\n        b -= a *\
      \ mod;\n    }\n\n    static void init() {\n        buf[0] = '\\0';\n       \
      \ for (size_t i = 0; i < 10000; ++i) {\n            leading_zero[i][0] = i /\
      \ 1000 + '0';\n            leading_zero[i][1] = i / 100 % 10 + '0';\n      \
      \      leading_zero[i][2] = i / 10 % 10 + '0';\n            leading_zero[i][3]\
      \ = i % 10 + '0';\n            leading_zero[i][4] = '\\0';\n\n            size_t\
      \ j = 0;\n            if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n    \
      \        if (i >= 100) helper[i][j++] = i / 100 % 10 + '0';\n            if\
      \ (i >= 10) helper[i][j++] = i / 10 % 10 + '0';\n            helper[i][j++]\
      \ = i % 10 + '0';\n            helper[i][j] = '\\0';\n        }\n    }\n\n \
      \ public:\n    Printer() : fp(stdout) { init(); }\n\n    Printer(const char\
      \ *file) : fp(fopen(file, \"w\")) { init(); }\n\n    ~Printer() {\n        write();\n\
      \        if (fp != stdout) fclose(fp);\n    }\n\n    void write() {\n      \
      \  fwrite(buf, 1, pos, fp);\n        pos = 0;\n    }\n\n    void flush() {\n\
      \        write();\n        fflush(fp);\n    }\n\n    void put_char(char c) {\n\
      \        if (pos == OUTPUT_BUF) write();\n        buf[pos++] = c;\n    }\n\n\
      \    void put_cstr(const char *s) {\n        while (*s) put_char(*(s++));\n\
      \    }\n\n    void put_u32(uint32_t x) {\n        uint32_t y;\n        if (x\
      \ >= 100000000) { // 10^8\n            div_mod<uint32_t>(y, x, 100000000);\n\
      \            put_cstr(helper[y]);\n            div_mod<uint32_t>(y, x, 10000);\n\
      \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y,\
      \ x, 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
      \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
      \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n     \
      \   uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n           \
      \ div_mod<uint64_t>(y, x, 1000000000000ull);\n            put_u32(y);\n    \
      \        div_mod<uint64_t>(y, x, 100000000ull);\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<uint64_t>(y, x, 10000ull);\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= 10000ull) {\
      \ // 10^4\n            div_mod<uint64_t>(y, x, 10000ull);\n            put_u32(y);\n\
      \            put_cstr(leading_zero[x]);\n        } else put_cstr(helper[x]);\n\
      \    }\n\n    void put_i64(int64_t x) {\n        if (x < 0) {\n            put_char('-');\n\
      \            put_u64(-x);\n        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t\
      \ x) {\n        constexpr static __uint128_t pow10_10 = 10000000000ull;\n  \
      \      constexpr static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n    \
      \    __uint128_t y;\n        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y,\
      \ x, pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
      \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
      \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n  \
      \          put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
      \ __uint128_t(100000000ull));\n            put_cstr(leading_zero[y]);\n    \
      \        div_mod<__uint128_t>(y, x, __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n\
      \            put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000))\
      \ { // 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n \
      \           put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n\
      \        } else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t\
      \ x) {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
      \        } else put_u128(x);\n    }\n\n    template <UnsignedIntegral T> Printer\
      \ &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4) put_u32(x);\n  \
      \      else if constexpr (sizeof(T) <= 8) put_u64(x);\n        else put_u128(x);\n\
      \        return *this;\n    }\n\n    template <SignedIntegral T> Printer &operator<<(T\
      \ x) {\n        if constexpr (sizeof(T) <= 4) put_i32(x);\n        else if constexpr\
      \ (sizeof(T) <= 8) put_i64(x);\n        else put_i128(x);\n        return *this;\n\
      \    }\n\n    Printer &operator<<(char x) {\n        put_char(x);\n        return\
      \ *this;\n    }\n\n    Printer &operator<<(const std::string &x) {\n       \
      \ for (char c : x) put_char(c);\n        return *this;\n    }\n\n    Printer\
      \ &operator<<(const char *x) {\n        put_cstr(x);\n        return *this;\n\
      \    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\u30DD\u30A4\u30F3\
      \u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\n    Printer &operator<<(endl_struct_t)\
      \ {\n        put_char('\\n');\n        flush();\n        return *this;\n   \
      \ }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar Printer::buf[Printer::OUTPUT_BUF];\n\
      char Printer::helper[10000][5];\nchar Printer::leading_zero[10000][5];\n\n}\
      \ // namespace fastio\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\nauto\
      \ &kin = std::cin;\nauto &kout = std::cout;\nauto (*kendl)(std::ostream &) =\
      \ std::endl<char, std::char_traits<char>>;\n#else\nfastio::Scanner kin;\nfastio::Printer\
      \ kout;\nfastio::endl_struct_t kendl;\n#endif\n\n} // namespace kk2\n\n\n#line\
      \ 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\n\n#line\
      \ 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\u30ED\
      \u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace impl\
      \ {\n\nstruct read {\n    template <class IStream, class T> inline static void\
      \ all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream, class\
      \ T, class U>\n    inline static void all_read(IStream &is, std::pair<T, U>\
      \ &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n \
      \   }\n\n    template <class IStream, class T> inline static void all_read(IStream\
      \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\
      \n    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
      \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n   \
      \ }\n};\n\nstruct write {\n    template <class OStream, class T> inline static\
      \ void all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n   \
      \ template <class OStream, class T, class U>\n    inline static void all_write(OStream\
      \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n      \
      \  all_write(os, ' ');\n        all_write(os, p.second);\n    }\n\n    template\
      \ <class OStream, class T>\n    inline static void all_write(OStream &os, const\
      \ std::vector<T> &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n\
      \            if (i) all_write(os, ' ');\n            all_write(os, v[i]);\n\
      \        }\n    }\n\n    template <class OStream, class T, size_t F>\n    inline\
      \ static void all_write(OStream &os, const std::array<T, F> &a) {\n        for\
      \ (int i = 0; i < (int)F; ++i) {\n            if (i) all_write(os, ' ');\n \
      \           all_write(os, a[i]);\n        }\n    }\n};\n\n} // namespace impl\n\
      \ntemplate <kk2::InputStream IStream, class T, class U>\nIStream &operator>>(IStream\
      \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T>\nIStream &operator>>(IStream\
      \ &is, std::vector<T> &v) {\n    impl::read::all_read(is, v);\n    return is;\n\
      }\n\ntemplate <kk2::InputStream IStream, class T, size_t F>\nIStream &operator>>(IStream\
      \ &is, std::array<T, F> &a) {\n    impl::read::all_read(is, a);\n    return\
      \ is;\n}\n\ntemplate <kk2::OutputStream OStream, class T, class U>\nOStream\
      \ &operator<<(OStream &os, const std::pair<T, U> &p) {\n    impl::write::all_write(os,\
      \ p);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T>\n\
      OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    impl::write::all_write(os,\
      \ v);\n    return os;\n}\n\ntemplate <kk2::OutputStream OStream, class T, size_t\
      \ F>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n    impl::write::all_write(os,\
      \ a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\n\n\n\n#define\
      \ rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define rep2(i, a)\
      \ for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a, b) for\
      \ (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for (long\
      \ long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long i =\
      \ (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
      #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
      \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
      \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32\
      \ \"template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
      \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
      \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
      \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"\
      NO\\n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"\
      no\\n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\n\
      template <class T, class S> inline bool chmax(T &a, const S &b) { return (a\
      \ < b ? a = b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a,\
      \ const S &b) { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp\"\
      \nusing namespace std;\n\nusing mint = kk2::Mont<469762049>;\n\nint main() {\n\
      \    int t;\n    kin >> t;\n    rep (t) {\n        i64 n;\n        mint a, b;\n\
      \        kin >> n >> a >> b;\n        auto f = [&](i64 p, i64 e) -> mint { return\
      \ a * e + b * p; };\n        auto g1 = [&](i64) -> mint { return 1; };\n   \
      \     auto g2 = [&](i64 p) -> mint { return p; };\n        kk2::PrefixSumOfMultiplicativeFunction<mint>\
      \ ps(n);\n        vc<mint> init1(ps.size()), init2(ps.size());\n        const\
      \ mint inv2 = mint(2).inv();\n        rep (i, ps.size()) {\n            init1[i]\
      \ = ps.eq[i] - 1;\n            init2[i] = mint(ps.eq[i]) * (ps.eq[i] + 1) *\
      \ inv2 - 1;\n        }\n        ps.LucyDP(g1, init1);\n        ps.LucyDP(g2,\
      \ init2);\n        rep (i, ps.size()) ps.prefix_sum_only_prime[i] = a * init1[i]\
      \ + b * init2[i];\n        ps.Min_25Sieve(f);\n        kout << ps.prefix_sum.back()\
      \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
    name: bundled
  isFailed: false
  isVerificationFile: true
  path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  pathExtension: cpp
  requiredBy: []
  testcases:
  - elapsed: 13.633110581000011
    environment: g++
    memory: 20.544
    name: boundaryA_00
    status: AC
  - elapsed: 9.22368176500001
    environment: g++
    memory: 16.212
    name: boundaryA_01
    status: AC
  - elapsed: 9.51246224900001
    environment: g++
    memory: 16.676
    name: boundaryA_02
    status: AC
  - elapsed: 7.869781324000002
    environment: g++
    memory: 15.0
    name: boundaryA_03
    status: AC
  - elapsed: 4.694027841999997
    environment: g++
    memory: 11.236
    name: boundaryA_04
    status: AC
  - elapsed: 13.60796926399999
    environment: g++
    memory: 20.544
    name: boundaryB_00
    status: AC
  - elapsed: 9.434573314000005
    environment: g++
    memory: 16.324
    name: boundaryB_01
    status: AC
  - elapsed: 9.501167379999998
    environment: g++
    memory: 16.672
    name: boundaryB_02
    status: AC
  - elapsed: 7.87407600200001
    environment: g++
    memory: 14.936
    name: boundaryB_03
    status: AC
  - elapsed: 4.688582564000001
    environment: g++
    memory: 11.284
    name: boundaryB_04
    status: AC
  - elapsed: 0.0024184910000144555
    environment: g++
    memory: 3.748
    name: example_00
    status: AC
  - elapsed: 0.0023514459999773862
    environment: g++
    memory: 3.788
    name: example_01
    status: AC
  - elapsed: 13.679099234000006
    environment: g++
    memory: 20.696
    name: example_02
    status: AC
  - elapsed: 0.194822586999976
    environment: g++
    memory: 3.748
    name: hack_wrong_zky_method_00
    status: AC
  - elapsed: 0.22048796799998627
    environment: g++
    memory: 3.756
    name: hack_wrong_zky_method_01
    status: AC
  - elapsed: 0.18787211600005094
    environment: g++
    memory: 3.88
    name: hack_wrong_zky_method_02
    status: AC
  - elapsed: 13.70636445499997
    environment: g++
    memory: 20.676
    name: hack_wrong_zky_method_03
    status: AC
  - elapsed: 13.787852324000028
    environment: g++
    memory: 20.732
    name: hack_wrong_zky_method_04
    status: AC
  - elapsed: 11.896420696999996
    environment: g++
    memory: 19.084
    name: hack_wrong_zky_method_05
    status: AC
  - elapsed: 13.798540687000013
    environment: g++
    memory: 20.752
    name: max_00
    status: AC
  - elapsed: 13.717437963000009
    environment: g++
    memory: 20.82
    name: max_01
    status: AC
  - elapsed: 13.760165319999999
    environment: g++
    memory: 20.696
    name: max_02
    status: AC
  - elapsed: 13.741559127000016
    environment: g++
    memory: 20.692
    name: max_03
    status: AC
  - elapsed: 13.715984963999972
    environment: g++
    memory: 20.692
    name: max_04
    status: AC
  - elapsed: 13.600519998999971
    environment: g++
    memory: 20.668
    name: random_00
    status: AC
  - elapsed: 9.243007232000025
    environment: g++
    memory: 16.388
    name: random_01
    status: AC
  - elapsed: 9.49592686799997
    environment: g++
    memory: 16.664
    name: random_02
    status: AC
  - elapsed: 7.871275220999962
    environment: g++
    memory: 14.924
    name: random_03
    status: AC
  - elapsed: 4.694196178000027
    environment: g++
    memory: 11.228
    name: random_04
    status: AC
  - elapsed: 0.003236302000004798
    environment: g++
    memory: 3.768
    name: small_00
    status: AC
  timestamp: '2026-09-07 22:25:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
layout: document
---
