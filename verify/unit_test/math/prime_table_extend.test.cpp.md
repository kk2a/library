---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/enumerate_quotients.hpp
    title: math/enumerate_quotients.hpp
  - icon: ':question:'
    path: math/frac_floor.hpp
    title: math/frac_floor.hpp
  - icon: ':question:'
    path: math/multiplicative_function/prime_counting.hpp
    title: math/multiplicative_function/prime_counting.hpp
  - icon: ':question:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':question:'
    path: math/prime_table.hpp
    title: math/prime_table.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  - icon: ':question:'
    path: math/sqrt_floor.hpp
    title: math/sqrt_floor.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
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
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
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
  bundledCode: "#line 1 \"verify/unit_test/math/prime_table_extend.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#line 1 \"math/prime_table.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <vector>\n\n#line 1 \"math/sqrt_floor.hpp\"\
    \n\n\n\n#include <cmath>\n\n#line 1 \"math/frac_floor.hpp\"\n\n\n\n#include <cassert>\n\
    \nnamespace kk2 {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n//\
    \ floor(x) = -ceil(-x)   (for all x)          ...(2)\n\n// return floor(a / b)\n\
    template <typename T, typename U> constexpr T fracfloor(T a, U b) {\n    assert(b\
    \ != 0);\n    if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n\
    \    // floor(x) = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by\
    \ (1)\n    return -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename\
    \ T, typename U> constexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if\
    \ (a % b == 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x)\
    \ = -floor(-x)      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\
    \n\n#line 7 \"math/sqrt_floor.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T>\
    \ T sqrt_floor(T n) {\n    assert(n >= 0);\n    if (n == T(0)) return 0;\n   \
    \ T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while (x > kk2::fracfloor(n,\
    \ x)) --x;\n    while (x + 1 <= kk2::fracfloor(n, x + 1)) ++x;\n    return x;\n\
    }\n\ntemplate <typename T> T sqrt_ceil(T n) {\n    assert(n >= 0);\n    if (n\
    \ <= T(1)) return n;\n    T x = std::sqrt(n);\n    if (x == T(0)) ++x;\n    while\
    \ (x < kk2::fracceil(n, x)) ++x;\n    while (x - 1 >= kk2::fracceil(n, x - 1))\
    \ --x;\n    return x;\n}\n\n} // namespace kk2\n\n\n#line 8 \"math/prime_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct PrimeTable {\n  private:\n    static inline int\
    \ _n = 30;\n    static inline std::vector<int> _primes{2, 3, 5, 7, 11, 13, 17,\
    \ 19, 23, 29};\n\n  public:\n    PrimeTable() = delete;\n\n    // wheel sieve\n\
    \    // reference: https://37zigen.com/wheel-sieve/\n    static void set_upper(int\
    \ m, int reserve_size = 26355867) {\n        if (m <= _n) return;\n        _n\
    \ = std::max(m, 2 * _n);\n        int sqrt_n = sqrt_floor(_n);\n        int w\
    \ = 1;\n        std::vector<bool> iscoprime(sqrt_n, true);\n        for (int i\
    \ = 0; i < 9; i++) {\n            if (w * _primes[i] > sqrt_n) break;\n      \
    \      w *= _primes[i];\n            for (int j = _primes[i]; j < sqrt_n; j +=\
    \ _primes[i]) iscoprime[j] = false;\n        }\n\n        std::vector<int> idx_(w,\
    \ -1);\n        int s = 0;\n        for (int i = 1; i < w; i++) {\n          \
    \  if (iscoprime[i]) idx_[i] = s++;\n        }\n        std::vector<int> coprimes(s);\n\
    \        for (int i = 1; i < w; i++) {\n            if (idx_[i] != -1) coprimes[idx_[i]]\
    \ = i;\n        }\n\n        auto idx = [&](long long x) -> long long {\n    \
    \        if (idx_[x % w] == -1) return -1;\n            return x / w * s + idx_[x\
    \ % w];\n        };\n\n        auto val = [&](int i) {\n            return i /\
    \ s * w + coprimes[i % s];\n        };\n\n        int n = (_n + w - 1) / w * s;\n\
    \        std::vector<int> _primes2;\n        _primes2.reserve(reserve_size);\n\
    \        std::vector<int> lpf(n, 0);\n        for (int i = 1; i < n; i++) {\n\
    \            int v = val(i);\n            if (lpf[i] == 0) {\n               \
    \ lpf[i] = v;\n                _primes2.push_back(lpf[i]);\n            }\n\n\
    \            for (const long long p : _primes2) {\n                long long j\
    \ = idx(p * v);\n                if (j >= n) break;\n                if (lpf[i]\
    \ < p) break;\n                lpf[j] = p;\n            }\n        }\n\n     \
    \   std::vector<int> tmp;\n        tmp.reserve(_primes.size() + _primes2.size());\n\
    \        std::set_union(_primes.begin(),\n                       _primes.end(),\n\
    \                       _primes2.begin(),\n                       _primes2.end(),\n\
    \                       std::back_inserter(tmp));\n        _primes = std::move(tmp);\n\
    \    }\n\n    static const std::vector<int> &primes() { return _primes; }\n\n\
    \    template <typename It> struct PrimeIt {\n        It bg, ed;\n        PrimeIt(It\
    \ bg_, It ed_) : bg(bg_), ed(ed_) {}\n        It begin() const { return bg; }\n\
    \        It end() const { return ed; }\n        int size() const { return ed -\
    \ bg; }\n        int operator[](int i) const { return bg[i]; }\n        std::vector<int>\
    \ to_vec() const { return std::vector<int>(bg, ed); }\n    };\n\n    static auto\
    \ primes(int n) {\n        if (n >= _n) set_upper(n);\n        return PrimeIt(_primes.begin(),\
    \ std::upper_bound(_primes.begin(), _primes.end(), n));\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"math/multiplicative_function/prime_counting.hpp\"\n\n\n\n\
    #line 5 \"math/multiplicative_function/prime_counting.hpp\"\n\n#line 1 \"math/enumerate_quotients.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"math/enumerate_quotients.hpp\"\n\n#line\
    \ 8 \"math/enumerate_quotients.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T>\
    \ struct EnumerateQuotients {\n    T n;\n    int sqrt_n;\n    std::vector<T> res;\n\
    \n    EnumerateQuotients(T n) : n(n), sqrt_n(sqrt_floor(n)) {\n        res.resize(sqrt_n\
    \ + n / (sqrt_n + 1));\n        std::iota(res.begin(), res.begin() + sqrt_n, 1);\n\
    \        for (T i = n / (sqrt_n + 1), j = sqrt_n; i; --i, ++j) res[j] = n / i;\n\
    \    }\n\n    const std::vector<T> &get() const { return res; }\n\n    int size()\
    \ const { return res.size(); }\n\n    const T &operator[](int i) const { return\
    \ res[i]; }\n\n    int idx(T x) const {\n        if (x <= sqrt_n) return x - 1;\n\
    \        return size() - n / x;\n    }\n};\n\n} // namespace kk2\n\n\n#line 8\
    \ \"math/multiplicative_function/prime_counting.hpp\"\n\nnamespace kk2 {\n\nlong\
    \ long prime_counting(long long n) {\n    EnumerateQuotients<long long> eq(n);\n\
    \    PrimeTable::set_upper(eq.sqrt_n);\n    std::vector<long long> dp(eq.size());\n\
    \    for (int i = 0; i < eq.size(); ++i) dp[i] = eq[i] - 1;\n    for (const long\
    \ long p : PrimeTable::primes()) {\n        for (int i = eq.size() - 1;; --i)\
    \ {\n            if (eq[i] < p * p) break;\n            dp[i] -= dp[eq.idx(eq[i]\
    \ / p)] - dp[p - 2];\n        }\n    }\n    return dp.back();\n}\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#line 7 \"random/gen.hpp\"\n#include\
    \ <random>\n#include <unordered_set>\n#line 10 \"random/gen.hpp\"\n\n#line 1 \"\
    random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace kk2 {\n\nnamespace random\
    \ {\n\nusing u64 = unsigned long long;\n\ninline u64 non_deterministic_seed()\
    \ {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n  \
    \                 std::chrono::high_resolution_clock::now().time_since_epoch())\n\
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
    \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 10 \"template/template.hpp\"\n#include\
    \ <deque>\n#include <functional>\n#include <iterator>\n#include <limits>\n#include\
    \ <map>\n#line 16 \"template/template.hpp\"\n#include <optional>\n#include <queue>\n\
    #line 19 \"template/template.hpp\"\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#line 24 \"template/template.hpp\"\n#include\
    \ <utility>\n#line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\
    \n\n\n\n#line 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\
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
    \ <cctype>\n#include <cstdint>\n#include <cstdio>\n#include <fstream>\n#include\
    \ <iostream>\n#line 10 \"template/fastio.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
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
    \ kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\nnamespace fastio\
    \ {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = 0, end = 0;\n    bool is_eof =\
    \ false;\n    static char buf[INPUT_BUF];\n    FILE *fp;\n\n  public:\n    Scanner()\
    \ : fp(stdin) {}\n\n    Scanner(const char *file) : fp(fopen(file, \"r\")) {}\n\
    \n    ~Scanner() {\n        if (fp != stdin) fclose(fp);\n    }\n\n    char now()\
    \ {\n        if (is_eof) return '\\0';\n        if (pos == end) {\n          \
    \  end = fread(buf, 1, INPUT_BUF, fp);\n            if (end != INPUT_BUF) buf[end]\
    \ = '\\0';\n            if (end == 0) is_eof = true;\n            pos = 0;\n \
    \       }\n        return buf[pos];\n    }\n\n    void skip_space() {\n      \
    \  while (isspace(now())) ++pos;\n    }\n\n    template <class T, is_unsigned_t<T>\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/unit_test/math/prime_table_extend.test.cpp\"\
    \nusing namespace std;\n\nvoid test_basic_prime_generation() {\n    // Test prime\
    \ generation up to small limits\n    auto primes_10 = kk2::PrimeTable::primes(10);\n\
    \    vector<int> expected_10 = {2, 3, 5, 7};\n    assert(primes_10.size() == expected_10.size());\n\
    \    for (int i = 0; i < (int)expected_10.size(); i++) {\n        assert(primes_10[i]\
    \ == expected_10[i]);\n    }\n    \n    auto primes_20 = kk2::PrimeTable::primes(20);\n\
    \    vector<int> expected_20 = {2, 3, 5, 7, 11, 13, 17, 19};\n    assert(primes_20.size()\
    \ == expected_20.size());\n    for (int i = 0; i < (int)expected_20.size(); i++)\
    \ {\n        assert(primes_20[i] == expected_20[i]);\n    }\n    \n    auto primes_50\
    \ = kk2::PrimeTable::primes(50);\n    vector<int> expected_50 = {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};\n    assert(primes_50.size() == expected_50.size());\n\
    \    for (int i = 0; i < (int)expected_50.size(); i++) {\n        assert(primes_50[i]\
    \ == expected_50[i]);\n    }\n}\n\nvoid test_first_100_primes() {\n    // Test\
    \ first 100 primes up to 541\n    auto primes_541 = kk2::PrimeTable::primes(541);\n\
    \    vector<int> first_100_primes = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,\n        73, 79, 83, 89, 97, 101,\
    \ 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,\n    \
    \    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,\
    \ 263, 269, 271, 277, 281,\n        283, 293, 307, 311, 313, 317, 331, 337, 347,\
    \ 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,\n        419, 421, 431,\
    \ 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,\
    \ 541\n    };\n    \n    assert(primes_541.size() == 100);\n    for (int i = 0;\
    \ i < 100; i++) {\n        assert(primes_541[i] == first_100_primes[i]);\n   \
    \ }\n}\n\nvoid test_prime_counting_properties() {\n    // Test prime counting\
    \ for various ranges\n    assert((int)kk2::PrimeTable::primes(2).size() == 1);\
    \     // \u03C0(2) = 1\n    assert((int)kk2::PrimeTable::primes(3).size() == 2);\
    \     // \u03C0(3) = 2\n    assert((int)kk2::PrimeTable::primes(5).size() == 3);\
    \     // \u03C0(5) = 3\n    assert((int)kk2::PrimeTable::primes(7).size() == 4);\
    \     // \u03C0(7) = 4\n    assert((int)kk2::PrimeTable::primes(11).size() ==\
    \ 5);    // \u03C0(11) = 5\n    assert((int)kk2::PrimeTable::primes(100).size()\
    \ == 25);  // \u03C0(100) = 25\n    assert((int)kk2::PrimeTable::primes(1000).size()\
    \ == 168); // \u03C0(1000) = 168\n}\n\nvoid test_consistency_with_prime_counting()\
    \ {\n    // Test consistency with prime_counting function\n    for (int n = 2;\
    \ n <= 1000; n += 10) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n    \n    // Test some specific larger values\n\
    \    vector<int> test_values = {1000, 2000, 5000, 10000, 20000, 50000, 100000};\n\
    \    for (int n : test_values) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nvoid test_monotonicity() {\n    //\
    \ Test that prime count is monotonically non-decreasing\n    int prev_count =\
    \ 0;\n    for (int n = 2; n <= 1000; n++) {\n        int curr_count = (int)kk2::PrimeTable::primes(n).size();\n\
    \        assert(curr_count >= prev_count);\n        prev_count = curr_count;\n\
    \    }\n}\n\nvoid test_prime_properties() {\n    // Test that all returned numbers\
    \ are actually prime\n    auto primes_1000 = kk2::PrimeTable::primes(1000);\n\
    \    for (int i = 0; i < primes_1000.size(); i++) {\n        int p = primes_1000[i];\n\
    \        \n        // Check basic primality (simple trial division for verification)\n\
    \        bool is_prime = (p > 1);\n        if (p > 2 && p % 2 == 0) is_prime =\
    \ false;\n        for (int d = 3; d * d <= p && is_prime; d += 2) {\n        \
    \    if (p % d == 0) is_prime = false;\n        }\n        assert(is_prime);\n\
    \        \n        // Check ordering (primes should be in ascending order)\n \
    \       if (i > 0) {\n            assert(primes_1000[i] > primes_1000[i-1]);\n\
    \        }\n    }\n}\n\nvoid test_edge_cases() {\n    // Test edge cases\n   \
    \ auto primes_1 = kk2::PrimeTable::primes(1);\n    assert(primes_1.size() == 0);\
    \ // No primes \u2264 1\n    \n    auto primes_2 = kk2::PrimeTable::primes(2);\n\
    \    assert(primes_2.size() == 1 && primes_2[0] == 2);\n    \n    // Test twin\
    \ primes\n    auto primes_100 = kk2::PrimeTable::primes(100);\n    vector<pair<int,\
    \ int>> twin_primes = {{3, 5}, {5, 7}, {11, 13}, {17, 19}, {29, 31}, {41, 43},\
    \ {59, 61}, {71, 73}};\n    for (auto [p1, p2] : twin_primes) {\n        bool\
    \ found_p1 = false, found_p2 = false;\n        for (int i = 0; i < primes_100.size();\
    \ i++) {\n            if (primes_100[i] == p1) found_p1 = true;\n            if\
    \ (primes_100[i] == p2) found_p2 = true;\n        }\n        assert(found_p1 &&\
    \ found_p2);\n    }\n}\n\nvoid test_random_large_numbers() {\n    // Test with\
    \ larger random numbers\n    int iter = 100;\n    rep (iter) {\n        int n\
    \ = kk2::random::rng(2, 1000000);\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nint main() {\n    int a, b;\n    kin\
    \ >> a >> b;\n    kout << a + b << kendl;\n\n    test_basic_prime_generation();\n\
    \    test_first_100_primes();\n    test_prime_counting_properties();\n    test_consistency_with_prime_counting();\n\
    \    test_monotonicity();\n    test_prime_properties();\n    test_edge_cases();\n\
    \    test_random_large_numbers();\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../math/prime_table.hpp\"\n#include \"../../../math/multiplicative_function/prime_counting.hpp\"\
    \n#include \"../../../random/gen.hpp\"\n#include \"../../../template/template.hpp\"\
    \nusing namespace std;\n\nvoid test_basic_prime_generation() {\n    // Test prime\
    \ generation up to small limits\n    auto primes_10 = kk2::PrimeTable::primes(10);\n\
    \    vector<int> expected_10 = {2, 3, 5, 7};\n    assert(primes_10.size() == expected_10.size());\n\
    \    for (int i = 0; i < (int)expected_10.size(); i++) {\n        assert(primes_10[i]\
    \ == expected_10[i]);\n    }\n    \n    auto primes_20 = kk2::PrimeTable::primes(20);\n\
    \    vector<int> expected_20 = {2, 3, 5, 7, 11, 13, 17, 19};\n    assert(primes_20.size()\
    \ == expected_20.size());\n    for (int i = 0; i < (int)expected_20.size(); i++)\
    \ {\n        assert(primes_20[i] == expected_20[i]);\n    }\n    \n    auto primes_50\
    \ = kk2::PrimeTable::primes(50);\n    vector<int> expected_50 = {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};\n    assert(primes_50.size() == expected_50.size());\n\
    \    for (int i = 0; i < (int)expected_50.size(); i++) {\n        assert(primes_50[i]\
    \ == expected_50[i]);\n    }\n}\n\nvoid test_first_100_primes() {\n    // Test\
    \ first 100 primes up to 541\n    auto primes_541 = kk2::PrimeTable::primes(541);\n\
    \    vector<int> first_100_primes = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23,\
    \ 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,\n        73, 79, 83, 89, 97, 101,\
    \ 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,\n    \
    \    179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,\
    \ 263, 269, 271, 277, 281,\n        283, 293, 307, 311, 313, 317, 331, 337, 347,\
    \ 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,\n        419, 421, 431,\
    \ 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,\
    \ 541\n    };\n    \n    assert(primes_541.size() == 100);\n    for (int i = 0;\
    \ i < 100; i++) {\n        assert(primes_541[i] == first_100_primes[i]);\n   \
    \ }\n}\n\nvoid test_prime_counting_properties() {\n    // Test prime counting\
    \ for various ranges\n    assert((int)kk2::PrimeTable::primes(2).size() == 1);\
    \     // \u03C0(2) = 1\n    assert((int)kk2::PrimeTable::primes(3).size() == 2);\
    \     // \u03C0(3) = 2\n    assert((int)kk2::PrimeTable::primes(5).size() == 3);\
    \     // \u03C0(5) = 3\n    assert((int)kk2::PrimeTable::primes(7).size() == 4);\
    \     // \u03C0(7) = 4\n    assert((int)kk2::PrimeTable::primes(11).size() ==\
    \ 5);    // \u03C0(11) = 5\n    assert((int)kk2::PrimeTable::primes(100).size()\
    \ == 25);  // \u03C0(100) = 25\n    assert((int)kk2::PrimeTable::primes(1000).size()\
    \ == 168); // \u03C0(1000) = 168\n}\n\nvoid test_consistency_with_prime_counting()\
    \ {\n    // Test consistency with prime_counting function\n    for (int n = 2;\
    \ n <= 1000; n += 10) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n    \n    // Test some specific larger values\n\
    \    vector<int> test_values = {1000, 2000, 5000, 10000, 20000, 50000, 100000};\n\
    \    for (int n : test_values) {\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nvoid test_monotonicity() {\n    //\
    \ Test that prime count is monotonically non-decreasing\n    int prev_count =\
    \ 0;\n    for (int n = 2; n <= 1000; n++) {\n        int curr_count = (int)kk2::PrimeTable::primes(n).size();\n\
    \        assert(curr_count >= prev_count);\n        prev_count = curr_count;\n\
    \    }\n}\n\nvoid test_prime_properties() {\n    // Test that all returned numbers\
    \ are actually prime\n    auto primes_1000 = kk2::PrimeTable::primes(1000);\n\
    \    for (int i = 0; i < primes_1000.size(); i++) {\n        int p = primes_1000[i];\n\
    \        \n        // Check basic primality (simple trial division for verification)\n\
    \        bool is_prime = (p > 1);\n        if (p > 2 && p % 2 == 0) is_prime =\
    \ false;\n        for (int d = 3; d * d <= p && is_prime; d += 2) {\n        \
    \    if (p % d == 0) is_prime = false;\n        }\n        assert(is_prime);\n\
    \        \n        // Check ordering (primes should be in ascending order)\n \
    \       if (i > 0) {\n            assert(primes_1000[i] > primes_1000[i-1]);\n\
    \        }\n    }\n}\n\nvoid test_edge_cases() {\n    // Test edge cases\n   \
    \ auto primes_1 = kk2::PrimeTable::primes(1);\n    assert(primes_1.size() == 0);\
    \ // No primes \u2264 1\n    \n    auto primes_2 = kk2::PrimeTable::primes(2);\n\
    \    assert(primes_2.size() == 1 && primes_2[0] == 2);\n    \n    // Test twin\
    \ primes\n    auto primes_100 = kk2::PrimeTable::primes(100);\n    vector<pair<int,\
    \ int>> twin_primes = {{3, 5}, {5, 7}, {11, 13}, {17, 19}, {29, 31}, {41, 43},\
    \ {59, 61}, {71, 73}};\n    for (auto [p1, p2] : twin_primes) {\n        bool\
    \ found_p1 = false, found_p2 = false;\n        for (int i = 0; i < primes_100.size();\
    \ i++) {\n            if (primes_100[i] == p1) found_p1 = true;\n            if\
    \ (primes_100[i] == p2) found_p2 = true;\n        }\n        assert(found_p1 &&\
    \ found_p2);\n    }\n}\n\nvoid test_random_large_numbers() {\n    // Test with\
    \ larger random numbers\n    int iter = 100;\n    rep (iter) {\n        int n\
    \ = kk2::random::rng(2, 1000000);\n        assert((int)kk2::PrimeTable::primes(n).size()\
    \ == kk2::prime_counting(n));\n    }\n}\n\nint main() {\n    int a, b;\n    kin\
    \ >> a >> b;\n    kout << a + b << kendl;\n\n    test_basic_prime_generation();\n\
    \    test_first_100_primes();\n    test_prime_counting_properties();\n    test_consistency_with_prime_counting();\n\
    \    test_monotonicity();\n    test_prime_properties();\n    test_edge_cases();\n\
    \    test_random_large_numbers();\n\n    return 0;\n}\n"
  dependsOn:
  - math/prime_table.hpp
  - math/sqrt_floor.hpp
  - math/frac_floor.hpp
  - math/multiplicative_function/prime_counting.hpp
  - math/enumerate_quotients.hpp
  - math/sqrt_floor.hpp
  - math/prime_table.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/math/prime_table_extend.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/prime_table_extend.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/prime_table_extend.test.cpp
- /verify/verify/unit_test/math/prime_table_extend.test.cpp.html
title: verify/unit_test/math/prime_table_extend.test.cpp
---
