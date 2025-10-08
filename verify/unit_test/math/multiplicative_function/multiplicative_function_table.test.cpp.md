---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/lpf_table.hpp
    title: math/lpf_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/arbitrary_table.hpp
    title: math/multiplicative_function/arbitrary_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/famous_function.hpp
    title: math/multiplicative_function/famous_function.hpp
  - icon: ':heavy_check_mark:'
    path: math/multiplicative_function/famous_function_table.hpp
    title: math/multiplicative_function/famous_function_table.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
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
  bundledCode: "#line 1 \"verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#line 1 \"math/multiplicative_function/famous_function_table.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n#line 1\
    \ \"math/lpf_table.hpp\"\n\n\n\n#line 6 \"math/lpf_table.hpp\"\n#include <numeric>\n\
    #line 8 \"math/lpf_table.hpp\"\n\nnamespace kk2 {\n\nstruct LPFTable {\n  private:\n\
    \    static inline std::vector<int> _primes{2}, _lpf{0, 1, 2}, _lpf_pow{0, 1,\
    \ 2}, _v_lpf{0, 1, 1};\n\n  public:\n    LPFTable() = delete;\n\n    static void\
    \ set_upper(int m, int reserve_size = 26355867) {\n        if ((int)_lpf.size()\
    \ == 0) _primes.reserve(reserve_size);\n        if ((int)_lpf.size() > m) return;\n\
    \        m = std::max<int>(2 * _lpf.size(), m);\n        _lpf_pow.resize(m + 1);\n\
    \        _v_lpf.resize(m + 1);\n        _lpf.resize(m + 1);\n        iota(_lpf.begin(),\
    \ _lpf.end(), 0);\n        for (int i = 2; i <= m; i++) {\n            if (_lpf[i]\
    \ == i and i > (int)_primes.back())\n                _primes.emplace_back(i),\
    \ _lpf_pow[i] = i, _v_lpf[i] = 1;\n            for (const long long p : _primes)\
    \ {\n                if (p * i > m) break;\n                if (_lpf[i] < p) break;\n\
    \                _lpf[p * i] = p;\n                if (_lpf[i] == p) {\n     \
    \               _v_lpf[p * i] = _v_lpf[i] + 1;\n                    _lpf_pow[p\
    \ * i] = _lpf_pow[i] * p;\n                } else {\n                    _v_lpf[p\
    \ * i] = 1;\n                    _lpf_pow[p * i] = p;\n                }\n   \
    \         }\n        }\n    }\n\n    static const std::vector<int> &primes() {\
    \ return _primes; }\n\n    template <typename It> struct PrimeIt {\n        It\
    \ bg, ed;\n        PrimeIt(It bg_, It ed_) : bg(bg_), ed(ed_) {}\n        It begin()\
    \ const { return bg; }\n        It end() const { return ed; }\n        int size()\
    \ const { return ed - bg; }\n        int operator[](int i) const { return bg[i];\
    \ }\n        std::vector<int> to_vec() const { return std::vector<int>(bg, ed);\
    \ }\n    };\n\n    static auto primes(int n) {\n        if (n >= (int)_lpf.size())\
    \ set_upper(n);\n        return PrimeIt(_primes.begin(), std::upper_bound(_primes.begin(),\
    \ _primes.end(), n));\n    }\n\n    static int lpf(int n) {\n        assert(n\
    \ > 1);\n        if (n >= (int)_lpf.size()) set_upper(n);\n        return _lpf[n];\n\
    \    }\n\n    static bool isprime(int n) {\n        assert(n > 0);\n        if\
    \ (n >= (int)_lpf.size()) set_upper(n);\n        return n != 1 and _lpf[n] ==\
    \ n;\n    }\n\n    static int lpf_pow(int n) {\n        assert(n > 1);\n     \
    \   if (n >= (int)_lpf_pow.size()) set_upper(n);\n        return _lpf_pow[n];\n\
    \    }\n\n    static int v_lpf(int n) {\n        assert(n > 1);\n        if (n\
    \ >= (int)_v_lpf.size()) set_upper(n);\n        return _v_lpf[n];\n    }\n};\n\
    \n} // namespace kk2\n\n\n\n#line 1 \"math/pow.hpp\"\n\n\n\n#line 5 \"math/pow.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow(T\
    \ x, U n) {\n    assert(n >= 0);\n    S r = 1, y = x;\n    while (n) {\n     \
    \   if (n & 1) r *= y;\n        if (n >>= 1) y *= y;\n    }\n    return r;\n}\n\
    \n} // namespace kk2\n\n\n#line 10 \"math/multiplicative_function/famous_function_table.hpp\"\
    \n\nnamespace kk2 {\n\nstruct FamousFunctionTable {\n  private:\n    static inline\
    \ std::vector<int> _mobius{0, 1}, _sigma0{0, 1}, _euler_phi{0, 1};\n    static\
    \ inline std::vector<long long> _sigma1{0, 1};\n\n  public:\n    FamousFunctionTable()\
    \ = delete;\n\n    static void set_upper(int m) {\n        if ((int)_mobius.size()\
    \ > m) return;\n        int start = _mobius.size();\n\n        LPFTable::set_upper(m);\n\
    \n        _mobius.resize(m + 1, 1);\n        _sigma0.resize(m + 1, 1);\n     \
    \   _sigma1.resize(m + 1, 1);\n        _euler_phi.resize(m + 1, 1);\n\n      \
    \  for (int n = start; n <= m; ++n) {\n            int p = LPFTable::lpf(n);\n\
    \            if (p == n) {\n                _mobius[n] = -1;\n               \
    \ _sigma0[n] = 2;\n                _sigma1[n] = p + 1;\n                _euler_phi[n]\
    \ = p - 1;\n            } else {\n                int p_pw = LPFTable::lpf_pow(n);\n\
    \                int q = n / p_pw;\n                if (q == 1) {\n          \
    \          _mobius[n] = 0;\n                    _sigma0[n] = _sigma0[n / p] +\
    \ 1;\n                    _sigma1[n] = _sigma1[n / p] + p_pw;\n              \
    \      _euler_phi[n] = p_pw - p_pw / p;\n                } else {\n          \
    \          _mobius[n] = _mobius[q] * _mobius[p_pw];\n                    _sigma0[n]\
    \ = _sigma0[q] * _sigma0[p_pw];\n                    _sigma1[n] = _sigma1[q] *\
    \ _sigma1[p_pw];\n                    _euler_phi[n] = _euler_phi[q] * _euler_phi[p_pw];\n\
    \                }\n            }\n        }\n    }\n\n    static int mobius(int\
    \ n) {\n        assert(n >= 0);\n        if ((int)_mobius.size() <= n) set_upper(n);\n\
    \        return _mobius[n];\n    }\n\n    static int sigma0(int n) {\n       \
    \ assert(n > 0);\n        if ((int)_sigma0.size() <= n) set_upper(n);\n      \
    \  return _sigma0[n];\n    }\n\n    static long long sigma1(int n) {\n       \
    \ assert(n > 0);\n        if ((int)_sigma1.size() <= n) set_upper(n);\n      \
    \  return _sigma1[n];\n    }\n\n    static int euler_phi(int n) {\n        assert(n\
    \ > 0);\n        if ((int)_euler_phi.size() <= n) set_upper(n);\n        return\
    \ _euler_phi[n];\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"math/multiplicative_function/famous_function.hpp\"\
    \n\n\n\n#line 5 \"math/multiplicative_function/famous_function.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace mf {\n\nusing i64 = long long;\n\ni64 mobius(i64, i64 e)\
    \ { return e == 1 ? -1 : 0; }\n\ni64 sigma0(i64, i64 e) { return e + 1; }\n\n\
    i64 sigma1(i64 p, i64 e) {\n    i64 p_e = pow<i64>(p, e);\n    return p_e + (p_e\
    \ - 1) / (p - 1);\n}\n\ni64 euler_phi(i64 p, i64 e) {\n    i64 p_e = pow<i64>(p,\
    \ e);\n    return p_e - p_e / p;\n}\n\n} // namespace mf\n\n} // namespace kk2\n\
    \n\n#line 1 \"math/multiplicative_function/arbitrary_table.hpp\"\n\n\n\n#line\
    \ 6 \"math/multiplicative_function/arbitrary_table.hpp\"\n\n#line 9 \"math/multiplicative_function/arbitrary_table.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class T, T (*f)(long long, long long)> struct\
    \ MultiplicativeFunctionTable {\n  private:\n    static inline std::vector<T>\
    \ _table{0, 1};\n\n  public:\n    MultiplicativeFunctionTable() = delete;\n\n\
    \    static void set_upper(int m) {\n        if ((int)_table.size() > m) return;\n\
    \        int start = _table.size();\n\n        LPFTable::set_upper(m);\n\n   \
    \     _table.resize(m + 1);\n\n        for (int n = start; n <= m; ++n) {\n  \
    \          int p = LPFTable::lpf(n);\n            if (p == n) {\n            \
    \    _table[n] = f(p, 1);\n            } else {\n                int p_pw = LPFTable::lpf_pow(n);\n\
    \                int q = n / p_pw;\n                if (q == 1) {\n          \
    \          _table[n] = f(p, LPFTable::v_lpf(n));\n                } else {\n \
    \                   _table[n] = _table[q] * _table[p_pw];\n                }\n\
    \            }\n        }\n    }\n\n    static T val(int n) {\n        assert(n\
    \ > 0);\n        if ((int)_table.size() <= n) set_upper(n);\n        return _table[n];\n\
    \    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"random/gen.hpp\"\n\n\n\n#line\
    \ 7 \"random/gen.hpp\"\n#include <random>\n#include <unordered_set>\n#line 10\
    \ \"random/gen.hpp\"\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\
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
    \ kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 9 \"template/template.hpp\"\n#include\
    \ <cmath>\n#include <deque>\n#include <functional>\n#include <iterator>\n#include\
    \ <limits>\n#include <map>\n#line 16 \"template/template.hpp\"\n#include <optional>\n\
    #include <queue>\n#line 19 \"template/template.hpp\"\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <unordered_map>\n#line 24 \"template/template.hpp\"\
    \n#include <utility>\n#line 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 8 \"verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n  \
    \  kout << a + b << kendl;\n\n    int iter = 1000;\n    rep (iter) {\n       \
    \ int n = kk2::random::rng(2, 1000000);\n\n        assert((kk2::MultiplicativeFunctionTable<long\
    \ long, kk2::mf::mobius>::val(n) == kk2::FamousFunctionTable::mobius(n)));\n \
    \       assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::euler_phi>::val(n)\
    \ == kk2::FamousFunctionTable::euler_phi(n)));\n        assert((kk2::MultiplicativeFunctionTable<long\
    \ long, kk2::mf::sigma0>::val(n) == kk2::FamousFunctionTable::sigma0(n)));\n \
    \       assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::sigma1>::val(n)\
    \ == kk2::FamousFunctionTable::sigma1(n)));\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../../math/multiplicative_function/famous_function_table.hpp\"\n#include\
    \ \"../../../../math/multiplicative_function/famous_function.hpp\"\n#include \"\
    ../../../../math/multiplicative_function/arbitrary_table.hpp\"\n#include \"../../../../random/gen.hpp\"\
    \n#include \"../../../../template/template.hpp\"\nusing namespace std;\n\nint\
    \ main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n\
    \    int iter = 1000;\n    rep (iter) {\n        int n = kk2::random::rng(2, 1000000);\n\
    \n        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::mobius>::val(n)\
    \ == kk2::FamousFunctionTable::mobius(n)));\n        assert((kk2::MultiplicativeFunctionTable<long\
    \ long, kk2::mf::euler_phi>::val(n) == kk2::FamousFunctionTable::euler_phi(n)));\n\
    \        assert((kk2::MultiplicativeFunctionTable<long long, kk2::mf::sigma0>::val(n)\
    \ == kk2::FamousFunctionTable::sigma0(n)));\n        assert((kk2::MultiplicativeFunctionTable<long\
    \ long, kk2::mf::sigma1>::val(n) == kk2::FamousFunctionTable::sigma1(n)));\n \
    \   }\n\n    return 0;\n}\n"
  dependsOn:
  - math/multiplicative_function/famous_function_table.hpp
  - math/lpf_table.hpp
  - math/pow.hpp
  - math/multiplicative_function/famous_function.hpp
  - math/multiplicative_function/arbitrary_table.hpp
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
  path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
- /verify/verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp.html
title: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
---
