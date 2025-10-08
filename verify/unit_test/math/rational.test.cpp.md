---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/rational.hpp
    title: math/rational.hpp
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
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/math/rational.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\" \n\n#line 1 \"math/rational.hpp\"\
    \n\n\n\n#include <numeric>\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#include <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits\
    \ {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
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
    \ kk2\n\n\n#line 7 \"math/rational.hpp\"\n\nnamespace kk2 {\n\nnamespace rational\
    \ {\n\ntemplate <typename T, typename Compare> struct RationalBase {\n    using\
    \ B = RationalBase;\n    T a, b;\n    // a / b\n    RationalBase() : a(0), b(1)\
    \ {}\n    RationalBase(T a_) : a(a_), b(1) {}\n    RationalBase(T a_, T b_) :\
    \ a(a_), b(b_) {\n        assert(b);\n        if (b < 0) a = -a, b = -b;\n   \
    \     T g = std::gcd(a, b);\n        a /= g, b /= g;\n    }\n\n    static B raw(T\
    \ a_, T b_) {\n        B res;\n        res.a = a_, res.b = b_;\n        return\
    \ res;\n    }\n\n    operator bool() const { return a; }\n    double to_double()\
    \ const { return (double)a / b; }\n    long double to_ldouble() const { return\
    \ (long double)a / b; }\n\n    friend B operator+(const B &lhs, const B &rhs)\
    \ {\n        if (lhs.b == rhs.b) return B(lhs.a + rhs.a, lhs.b);\n        return\
    \ B(lhs.a * rhs.b + rhs.a * lhs.b, lhs.b * rhs.b);\n    }\n\n    friend B operator-(const\
    \ B &lhs, const B &rhs) {\n        if (lhs.b == rhs.b) return B(lhs.a - rhs.a,\
    \ lhs.b);\n        return B(lhs.a * rhs.b - rhs.a * lhs.b, lhs.b * rhs.b);\n \
    \   }\n\n    friend B operator*(const B &lhs, const B &rhs) { return B(lhs.a *\
    \ rhs.a, lhs.b * rhs.b); }\n    friend B operator/(const B &lhs, const B &rhs)\
    \ { return B(lhs.a * rhs.b, lhs.b * rhs.a); }\n    B &operator+=(const B &rhs)\
    \ { return (*this) = (*this) + rhs; }\n    B &operator-=(const B &rhs) { return\
    \ (*this) = (*this) - rhs; }\n    B &operator*=(const B &rhs) { return (*this)\
    \ = (*this) * rhs; }\n    B &operator/=(const B &rhs) { return (*this) = (*this)\
    \ / rhs; }\n    B operator-() const { return raw(-a, b); }\n    B operator+()\
    \ const { return *this; }\n    B inv() const { return a < 0 ? raw(-b, -a) : raw(b,\
    \ a); }\n    B abs() const { return a < 0 ? raw(-a, b) : *this; }\n    friend\
    \ bool operator==(const B &lhs, const B &rhs) { return lhs.a == rhs.a and lhs.b\
    \ == rhs.b; }\n    friend bool operator!=(const B &lhs, const B &rhs) { return\
    \ !(lhs == rhs); }\n    friend bool operator<(const B &lhs, const B &rhs) {\n\
    \        return Compare{lhs.a} * rhs.b < Compare{rhs.a} * lhs.b;\n    }\n    friend\
    \ bool operator>(const B &lhs, const B &rhs) {\n        return Compare{lhs.a}\
    \ * rhs.b > Compare{rhs.a} * lhs.b;\n    }\n    friend bool operator<=(const B\
    \ &lhs, const B &rhs) { return lhs == rhs or lhs < rhs; }\n    friend bool operator>=(const\
    \ B &lhs, const B &rhs) { return lhs == rhs or lhs > rhs; }\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const B &rhs) {\n        return os << rhs.a << \" / \" << rhs.b;\n    }\n\
    };\n\n} // namespace rational\n\ntemplate <typename T> using Rational = rational::RationalBase<T,\
    \ T>;\nusing RationalInt = rational::RationalBase<int, long long>;\nusing RationalI64\
    \ = rational::RationalBase<long long, __int128>;\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"random/gen.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#line\
    \ 7 \"random/gen.hpp\"\n#include <random>\n#include <unordered_set>\n#include\
    \ <vector>\n\n#line 1 \"random/seed.hpp\"\n\n\n\n#include <chrono>\n\nnamespace\
    \ kk2 {\n\nnamespace random {\n\nusing u64 = unsigned long long;\n\ninline u64\
    \ non_deterministic_seed() {\n    u64 seed = std::chrono::duration_cast<std::chrono::nanoseconds>(\n\
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
    \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
    \ntemplate <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
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
    \n} // namespace kk2\n\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace kk2 {\n\
    \nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n  private:\n\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/unit_test/math/rational.test.cpp\"\
    \nusing namespace std;\nusing namespace kk2;\n\nvoid test_constructor() {\n  \
    \  // \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n    RationalInt r1;\n    assert(r1.a == 0 && r1.b == 1);\n    \n    // \u6574\
    \u6570\u304B\u3089\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    RationalInt\
    \ r2(5);\n    assert(r2.a == 5 && r2.b == 1);\n    \n    // \u5206\u6570\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF08\u65E2\u7D04\u5206\u6570\u306B\u306A\
    \u308B\u3053\u3068\u3092\u78BA\u8A8D\uFF09\n    RationalInt r3(6, 9);\n    assert(r3.a\
    \ == 2 && r3.b == 3);\n    \n    // \u8CA0\u306E\u6570\u306E\u30C6\u30B9\u30C8\
    \n    RationalInt r4(-6, 9);\n    assert(r4.a == -2 && r4.b == 3);\n    \n   \
    \ RationalInt r5(6, -9);\n    assert(r5.a == -2 && r5.b == 3);\n    \n    RationalInt\
    \ r6(-6, -9);\n    assert(r6.a == 2 && r6.b == 3);\n}\n\nvoid test_arithmetic()\
    \ {\n    RationalInt r1(1, 2);  // 1/2\n    RationalInt r2(1, 3);  // 1/3\n  \
    \  \n    // \u8DB3\u3057\u7B97\n    auto sum = r1 + r2;\n    assert(sum.a == 5\
    \ && sum.b == 6);  // 1/2 + 1/3 = 5/6\n    \n    // \u5F15\u304D\u7B97\n    auto\
    \ diff = r1 - r2;\n    assert(diff.a == 1 && diff.b == 6);  // 1/2 - 1/3 = 1/6\n\
    \    \n    // \u639B\u3051\u7B97\n    auto prod = r1 * r2;\n    assert(prod.a\
    \ == 1 && prod.b == 6);  // 1/2 * 1/3 = 1/6\n    \n    // \u5272\u308A\u7B97\n\
    \    auto div = r1 / r2;\n    assert(div.a == 3 && div.b == 2);  // (1/2) / (1/3)\
    \ = 3/2\n    \n    // \u540C\u3058\u5206\u6BCD\u306E\u5834\u5408\n    RationalInt\
    \ r3(2, 7);  // 2/7\n    RationalInt r4(3, 7);  // 3/7\n    auto sum2 = r3 + r4;\n\
    \    assert(sum2.a == 5 && sum2.b == 7);  // 2/7 + 3/7 = 5/7\n}\n\nvoid test_comparison()\
    \ {\n    RationalInt r1(1, 2);  // 1/2\n    RationalInt r2(2, 4);  // 2/4 = 1/2\n\
    \    RationalInt r3(1, 3);  // 1/3\n    \n    // \u7B49\u4FA1\u6027\n    assert(r1\
    \ == r2);\n    assert(!(r1 != r2));\n    \n    // \u5927\u5C0F\u6BD4\u8F03\n \
    \   assert(r1 > r3);\n    assert(r3 < r1);\n    assert(r1 >= r2);\n    assert(r1\
    \ <= r2);\n    assert(r3 <= r1);\n    \n    // \u8CA0\u306E\u6570\u306E\u6BD4\u8F03\
    \n    RationalInt r4(-1, 2);  // -1/2\n    assert(r4 < r3);\n    assert(r3 > r4);\n\
    }\n\nvoid test_unary_operations() {\n    RationalInt r1(3, 4);  // 3/4\n    \n\
    \    // \u5358\u9805\u30DE\u30A4\u30CA\u30B9\n    auto neg = -r1;\n    assert(neg.a\
    \ == -3 && neg.b == 4);\n    \n    // \u5358\u9805\u30D7\u30E9\u30B9\n    auto\
    \ pos = +r1;\n    assert(pos.a == 3 && pos.b == 4);\n    \n    // \u9006\u6570\
    \n    auto inv = r1.inv();\n    assert(inv.a == 4 && inv.b == 3);\n    \n    //\
    \ \u8CA0\u306E\u6570\u306E\u9006\u6570\n    RationalInt r2(-3, 4);\n    auto inv2\
    \ = r2.inv();\n    assert(inv2.a == -4 && inv2.b == 3);\n    \n    // \u7D76\u5BFE\
    \u5024\n    auto abs1 = r1.abs();\n    assert(abs1.a == 3 && abs1.b == 4);\n \
    \   \n    auto abs2 = r2.abs();\n    assert(abs2.a == 3 && abs2.b == 4);\n}\n\n\
    void test_assignment_operators() {\n    RationalInt r1(1, 2);\n    RationalInt\
    \ r2(1, 3);\n    \n    // +=\n    r1 += r2;\n    assert(r1.a == 5 && r1.b == 6);\
    \  // 1/2 + 1/3 = 5/6\n    \n    // -=\n    r1 -= r2;\n    assert(r1.a == 1 &&\
    \ r1.b == 2);  // 5/6 - 1/3 = 1/2\n    \n    // *=\n    r1 *= r2;\n    assert(r1.a\
    \ == 1 && r1.b == 6);  // 1/2 * 1/3 = 1/6\n    \n    // /=\n    r1 /= r2;\n  \
    \  assert(r1.a == 1 && r1.b == 2);  // (1/6) / (1/3) = 1/2\n}\n\nvoid test_boolean_conversion()\
    \ {\n    RationalInt r1(0, 1);  // 0\n    RationalInt r2(1, 2);  // 1/2\n    \n\
    \    assert(!r1);\n    assert(r2);\n}\n\nvoid test_floating_point_conversion()\
    \ {\n    RationalInt r1(1, 2);  // 1/2\n    RationalInt r2(1, 3);  // 1/3\n  \
    \  \n    assert(abs(r1.to_double() - 0.5) < 1e-9);\n    assert(abs(r2.to_double()\
    \ - (1.0/3.0)) < 1e-9);\n    \n    assert(abs(r1.to_ldouble() - 0.5L) < 1e-15L);\n\
    \    assert(abs(r2.to_ldouble() - (1.0L/3.0L)) < 1e-15L);\n}\n\nvoid test_edge_cases()\
    \ {\n    // \u5206\u6BCD\u304C1\u306E\u5834\u5408\n    RationalInt r1(5, 1);\n\
    \    assert(r1.a == 5 && r1.b == 1);\n    \n    // \u5927\u304D\u306AGCD\u306E\
    \u5834\u5408\n    RationalInt r2(1000, 2000);\n    assert(r2.a == 1 && r2.b ==\
    \ 2);\n    \n    // 0\u306E\u5834\u5408\n    RationalInt r3(0, 5);\n    assert(r3.a\
    \ == 0 && r3.b == 1);\n}\n\nvoid test_precision_edge_cases() {\n    // \u975E\u5E38\
    \u306B\u5C0F\u3055\u306A\u5206\u6570\n    RationalInt r1(1LL, 1000000000LL);\n\
    \    assert(r1.a == 1LL && r1.b == 1000000000LL);\n    \n    // \u5206\u5B50\u304C\
    0\u306E\u30B1\u30FC\u30B9\n    RationalInt r2(0, 12345);\n    assert(r2.a == 0\
    \ && r2.b == 1);\n    \n    // \u5206\u5B50\u5206\u6BCD\u304C\u540C\u3058\u7B26\
    \u53F7\n    RationalInt r3(-100, -200);\n    assert(r3.a == 1 && r3.b == 2);\n\
    }\n\nvoid test_random_operations() {\n    // \u30E9\u30F3\u30C0\u30E0\u306A\u5206\
    \u6570\u3067\u306E\u57FA\u672C\u6F14\u7B97\u30C6\u30B9\u30C8\uFF081e6\u56DE\uFF09\
    \n    for (int i = 0; i < 1000000; i++) {\n        int a1 = random::rng(-10000,\
    \ 10001), b1 = random::rng(1, 10001);\n        int a2 = random::rng(-10000, 10001),\
    \ b2 = random::rng(1, 10001);\n        \n        RationalInt r1(a1, b1), r2(a2,\
    \ b2);\n        \n        // \u52A0\u6CD5\u306E\u9006\u5143\u30C6\u30B9\u30C8\
    : r + (-r) = 0\n        assert((r1 + (-r1)).a == 0);\n        \n        // \u4E57\
    \u6CD5\u306E\u9006\u5143\u30C6\u30B9\u30C8: r * r.inv() = 1 (r != 0\u306E\u5834\
    \u5408)\n        if (r1.a != 0) {\n            auto prod = r1 * r1.inv();\n  \
    \          assert(prod.a == 1 && prod.b == 1);\n        }\n        \n        //\
    \ \u4EA4\u63DB\u5F8B\u30C6\u30B9\u30C8: a + b = b + a, a * b = b * a\n       \
    \ assert(r1 + r2 == r2 + r1);\n        assert(r1 * r2 == r2 * r1);\n        \n\
    \        // \u9664\u6CD5\u306E\u5B9A\u7FA9\u30C6\u30B9\u30C8: a / b = a * b.inv()\n\
    \        if (r2.a != 0) {\n            assert(r1 / r2 == r1 * r2.inv());\n   \
    \     }\n    }\n}\n\nvoid test_comparison_consistency() {\n    // \u6BD4\u8F03\
    \u6F14\u7B97\u5B50\u306E\u4E00\u8CAB\u6027\u30C6\u30B9\u30C8\uFF081e6\u56DE\uFF09\
    \n    for (int i = 0; i < 1000000; i++) {\n        int a1 = random::rng(-10000,\
    \ 10001), b1 = random::rng(1, 10001);\n        int a2 = random::rng(-10000, 10001),\
    \ b2 = random::rng(1, 10001);\n        \n        RationalInt r1(a1, b1), r2(a2,\
    \ b2);\n        \n        // \u4E09\u5206\u5F8B: r1 < r2, r1 == r2, r1 > r2 \u306E\
    \u3046\u3061 exactly one \u304C\u771F\n        int count = 0;\n        if (r1\
    \ < r2) count++;\n        if (r1 == r2) count++;\n        if (r1 > r2) count++;\n\
    \        assert(count == 1);\n        \n        // \u63A8\u79FB\u5F8B\u306E\u4E00\
    \u90E8: r1 <= r2 and r2 <= r1 => r1 == r2\n        if (r1 <= r2 && r2 <= r1) {\n\
    \            assert(r1 == r2);\n        }\n        \n        // \u53CD\u5BFE\u79F0\
    \u6027: r1 < r2 <=> r2 > r1\n        assert((r1 < r2) == (r2 > r1));\n       \
    \ assert((r1 <= r2) == (r2 >= r1));\n    }\n}\n\nvoid test_overflow_safety() {\n\
    \    // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3092\u907F\u3051\u308B\u305F\
    \u3081\u306E\u5883\u754C\u5024\u30C6\u30B9\u30C8\n    const int SAFE_MAX = 10000;\
    \  // \u5B89\u5168\u306A\u6700\u5927\u5024\n    \n    RationalInt r1(SAFE_MAX,\
    \ 1);\n    RationalInt r2(1, SAFE_MAX);\n    \n    // \u5927\u304D\u306A\u6570\
    \u540C\u58EB\u306E\u6F14\u7B97\n    auto sum = r1 + r2;  // SAFE_MAX + 1/SAFE_MAX\n\
    \    assert(sum.a == SAFE_MAX * SAFE_MAX + 1);\n    assert(sum.b == SAFE_MAX);\n\
    \    \n    // \u7D04\u5206\u304C\u6B63\u3057\u304F\u884C\u308F\u308C\u308B\u3053\
    \u3068\u3092\u78BA\u8A8D\n    RationalInt r3(SAFE_MAX * 2, SAFE_MAX * 4);\n  \
    \  assert(r3.a == 1 && r3.b == 2);\n}\n\nvoid test_double_conversion_accuracy()\
    \ {\n    // \u6D6E\u52D5\u5C0F\u6570\u70B9\u5909\u63DB\u306E\u7CBE\u5EA6\u30C6\
    \u30B9\u30C8\uFF081e6\u56DE\uFF09\n    for (int i = 0; i < 1000000; i++) {\n \
    \       int a = random::rng(-1000, 1001);\n        int b = random::rng(1, 1001);\n\
    \        \n        RationalInt r(a, b);\n        double expected = (double)a /\
    \ b;\n        \n        assert(abs(r.to_double() - expected) < 1e-12);\n     \
    \   \n        // long double\u7248\u3082\u78BA\u8A8D\n        long double expected_ld\
    \ = (long double)a / b;\n        assert(abs(r.to_ldouble() - expected_ld) < 1e-15L);\n\
    \    }\n}\n\nvoid test_stress_large_numbers() {\n    // \u5927\u304D\u306A\u6570\
    \u3067\u306E\u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\n    const long long BIG\
    \ = 1000000007LL;\n    \n    RationalI64 r1(BIG, 1);\n    RationalI64 r2(1, BIG);\n\
    \    \n    // \u5927\u304D\u306A\u6570\u540C\u58EB\u306E\u6F14\u7B97\n    auto\
    \ sum = r1 + r2;\n    assert(sum.a == BIG * BIG + 1);\n    assert(sum.b == BIG);\n\
    \    \n    auto diff = r1 - r2;\n    assert(diff.a == BIG * BIG - 1);\n    assert(diff.b\
    \ == BIG);\n    \n    auto prod = r1 * r2;\n    assert(prod.a == 1 && prod.b ==\
    \ 1);\n    \n    auto div = r1 / r2;\n    assert(div.a == BIG * BIG && div.b ==\
    \ 1);\n}\n\nvoid test_special_rational_values() {\n    // \u7279\u6B8A\u306A\u6709\
    \u7406\u6570\u5024\u306E\u30C6\u30B9\u30C8\n    \n    // 1/1 = 1\n    RationalInt\
    \ one(1, 1);\n    assert(one.a == 1 && one.b == 1);\n    \n    // \u4EFB\u610F\
    \u306E\u6570\u306B1\u3092\u8DB3\u3059/\u5F15\u304F\n    RationalInt r(3, 7);\n\
    \    auto plus_one = r + one;\n    assert(plus_one.a == 10 && plus_one.b == 7);\
    \  // 3/7 + 1 = 10/7\n    \n    auto minus_one = r - one;\n    assert(minus_one.a\
    \ == -4 && minus_one.b == 7);  // 3/7 - 1 = -4/7\n    \n    // 1/2\u306E\u7D2F\
    \u4E57\n    RationalInt half(1, 2);\n    auto quarter = half * half;\n    assert(quarter.a\
    \ == 1 && quarter.b == 4);  // (1/2)^2 = 1/4\n    \n    auto eighth = quarter\
    \ * half;\n    assert(eighth.a == 1 && eighth.b == 8);  // (1/4) * (1/2) = 1/8\n\
    }\n\nvoid test_chain_operations() {\n    // \u9023\u7D9A\u6F14\u7B97\u306E\u30C6\
    \u30B9\u30C8\uFF081e6\u56DE\uFF09\n    for (int i = 0; i < 1000000; i++) {\n \
    \       RationalInt result(1, 1);  // 1\u304B\u3089\u958B\u59CB\n        \n  \
    \      // \u5404\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306710\u56DE\u306E\u9023\
    \u7D9A\u6F14\u7B97\n        for (int j = 0; j < 10; j++) {\n            int op\
    \ = random::rng(0, 4);  // 0:+, 1:-, 2:*, 3:/\n            int a = random::rng(-10,\
    \ 11);\n            int b = random::rng(1, 11);\n            \n            RationalInt\
    \ operand(a, b);\n            \n            switch (op) {\n                case\
    \ 0: result += operand; break;\n                case 1: result -= operand; break;\n\
    \                case 2: result *= operand; break;\n                case 3:\n\
    \                    if (operand.a != 0) {\n                        result /=\
    \ operand;\n                    }\n                    break;\n            }\n\
    \            \n            // \u7D50\u679C\u304C\u6B63\u898F\u5316\u3055\u308C\
    \u3066\u3044\u308B\u3053\u3068\u3092\u78BA\u8A8D\n            assert(result.b\
    \ > 0);\n            assert(std::gcd(abs(result.a), result.b) == 1);\n       \
    \ }\n    }\n}\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout <<\
    \ a + b << kendl;\n\n    cerr << \"Starting comprehensive rational number tests...\"\
    \ << endl;\n\n    // \u57FA\u672C\u30C6\u30B9\u30C8\u5B9F\u884C\n    cerr << \"\
    Running basic functionality tests...\" << endl;\n    test_constructor();\n   \
    \ test_arithmetic();\n    test_comparison();\n    test_unary_operations();\n \
    \   test_assignment_operators();\n    test_boolean_conversion();\n    test_floating_point_conversion();\n\
    \    test_edge_cases();\n    \n    // \u5883\u754C\u5024\u30FB\u30E9\u30F3\u30C0\
    \u30E0\u30C6\u30B9\u30C8\u5B9F\u884C\n    cerr << \"Running boundary value and\
    \ random tests...\" << endl;\n    test_precision_edge_cases();\n    test_random_operations();\n\
    \    test_comparison_consistency();\n    test_overflow_safety();\n    test_double_conversion_accuracy();\n\
    \    \n    // \u8FFD\u52A0\u306E\u53B3\u5BC6\u30C6\u30B9\u30C8\n    cerr << \"\
    Running stress and edge case tests...\" << endl;\n    test_stress_large_numbers();\n\
    \    test_special_rational_values();\n    test_chain_operations();\n    \n   \
    \ // \u3059\u3079\u3066\u306E\u30C6\u30B9\u30C8\u304C\u901A\u3063\u305F\u5834\u5408\
    \n    cerr << endl << \"=== ALL RATIONAL TESTS PASSED ===\" << endl;\n    cerr\
    \ << \"All tests completed successfully!\" << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../../math/rational.hpp\"\n#include \"../../../random/gen.hpp\"\n#include \"\
    ../../../template/template.hpp\"\nusing namespace std;\nusing namespace kk2;\n\
    \nvoid test_constructor() {\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n    RationalInt r1;\n    assert(r1.a == 0 && r1.b\
    \ == 1);\n    \n    // \u6574\u6570\u304B\u3089\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n    RationalInt r2(5);\n    assert(r2.a == 5 && r2.b == 1);\n  \
    \  \n    // \u5206\u6570\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF08\u65E2\
    \u7D04\u5206\u6570\u306B\u306A\u308B\u3053\u3068\u3092\u78BA\u8A8D\uFF09\n   \
    \ RationalInt r3(6, 9);\n    assert(r3.a == 2 && r3.b == 3);\n    \n    // \u8CA0\
    \u306E\u6570\u306E\u30C6\u30B9\u30C8\n    RationalInt r4(-6, 9);\n    assert(r4.a\
    \ == -2 && r4.b == 3);\n    \n    RationalInt r5(6, -9);\n    assert(r5.a == -2\
    \ && r5.b == 3);\n    \n    RationalInt r6(-6, -9);\n    assert(r6.a == 2 && r6.b\
    \ == 3);\n}\n\nvoid test_arithmetic() {\n    RationalInt r1(1, 2);  // 1/2\n \
    \   RationalInt r2(1, 3);  // 1/3\n    \n    // \u8DB3\u3057\u7B97\n    auto sum\
    \ = r1 + r2;\n    assert(sum.a == 5 && sum.b == 6);  // 1/2 + 1/3 = 5/6\n    \n\
    \    // \u5F15\u304D\u7B97\n    auto diff = r1 - r2;\n    assert(diff.a == 1 &&\
    \ diff.b == 6);  // 1/2 - 1/3 = 1/6\n    \n    // \u639B\u3051\u7B97\n    auto\
    \ prod = r1 * r2;\n    assert(prod.a == 1 && prod.b == 6);  // 1/2 * 1/3 = 1/6\n\
    \    \n    // \u5272\u308A\u7B97\n    auto div = r1 / r2;\n    assert(div.a ==\
    \ 3 && div.b == 2);  // (1/2) / (1/3) = 3/2\n    \n    // \u540C\u3058\u5206\u6BCD\
    \u306E\u5834\u5408\n    RationalInt r3(2, 7);  // 2/7\n    RationalInt r4(3, 7);\
    \  // 3/7\n    auto sum2 = r3 + r4;\n    assert(sum2.a == 5 && sum2.b == 7); \
    \ // 2/7 + 3/7 = 5/7\n}\n\nvoid test_comparison() {\n    RationalInt r1(1, 2);\
    \  // 1/2\n    RationalInt r2(2, 4);  // 2/4 = 1/2\n    RationalInt r3(1, 3);\
    \  // 1/3\n    \n    // \u7B49\u4FA1\u6027\n    assert(r1 == r2);\n    assert(!(r1\
    \ != r2));\n    \n    // \u5927\u5C0F\u6BD4\u8F03\n    assert(r1 > r3);\n    assert(r3\
    \ < r1);\n    assert(r1 >= r2);\n    assert(r1 <= r2);\n    assert(r3 <= r1);\n\
    \    \n    // \u8CA0\u306E\u6570\u306E\u6BD4\u8F03\n    RationalInt r4(-1, 2);\
    \  // -1/2\n    assert(r4 < r3);\n    assert(r3 > r4);\n}\n\nvoid test_unary_operations()\
    \ {\n    RationalInt r1(3, 4);  // 3/4\n    \n    // \u5358\u9805\u30DE\u30A4\u30CA\
    \u30B9\n    auto neg = -r1;\n    assert(neg.a == -3 && neg.b == 4);\n    \n  \
    \  // \u5358\u9805\u30D7\u30E9\u30B9\n    auto pos = +r1;\n    assert(pos.a ==\
    \ 3 && pos.b == 4);\n    \n    // \u9006\u6570\n    auto inv = r1.inv();\n   \
    \ assert(inv.a == 4 && inv.b == 3);\n    \n    // \u8CA0\u306E\u6570\u306E\u9006\
    \u6570\n    RationalInt r2(-3, 4);\n    auto inv2 = r2.inv();\n    assert(inv2.a\
    \ == -4 && inv2.b == 3);\n    \n    // \u7D76\u5BFE\u5024\n    auto abs1 = r1.abs();\n\
    \    assert(abs1.a == 3 && abs1.b == 4);\n    \n    auto abs2 = r2.abs();\n  \
    \  assert(abs2.a == 3 && abs2.b == 4);\n}\n\nvoid test_assignment_operators()\
    \ {\n    RationalInt r1(1, 2);\n    RationalInt r2(1, 3);\n    \n    // +=\n \
    \   r1 += r2;\n    assert(r1.a == 5 && r1.b == 6);  // 1/2 + 1/3 = 5/6\n    \n\
    \    // -=\n    r1 -= r2;\n    assert(r1.a == 1 && r1.b == 2);  // 5/6 - 1/3 =\
    \ 1/2\n    \n    // *=\n    r1 *= r2;\n    assert(r1.a == 1 && r1.b == 6);  //\
    \ 1/2 * 1/3 = 1/6\n    \n    // /=\n    r1 /= r2;\n    assert(r1.a == 1 && r1.b\
    \ == 2);  // (1/6) / (1/3) = 1/2\n}\n\nvoid test_boolean_conversion() {\n    RationalInt\
    \ r1(0, 1);  // 0\n    RationalInt r2(1, 2);  // 1/2\n    \n    assert(!r1);\n\
    \    assert(r2);\n}\n\nvoid test_floating_point_conversion() {\n    RationalInt\
    \ r1(1, 2);  // 1/2\n    RationalInt r2(1, 3);  // 1/3\n    \n    assert(abs(r1.to_double()\
    \ - 0.5) < 1e-9);\n    assert(abs(r2.to_double() - (1.0/3.0)) < 1e-9);\n    \n\
    \    assert(abs(r1.to_ldouble() - 0.5L) < 1e-15L);\n    assert(abs(r2.to_ldouble()\
    \ - (1.0L/3.0L)) < 1e-15L);\n}\n\nvoid test_edge_cases() {\n    // \u5206\u6BCD\
    \u304C1\u306E\u5834\u5408\n    RationalInt r1(5, 1);\n    assert(r1.a == 5 &&\
    \ r1.b == 1);\n    \n    // \u5927\u304D\u306AGCD\u306E\u5834\u5408\n    RationalInt\
    \ r2(1000, 2000);\n    assert(r2.a == 1 && r2.b == 2);\n    \n    // 0\u306E\u5834\
    \u5408\n    RationalInt r3(0, 5);\n    assert(r3.a == 0 && r3.b == 1);\n}\n\n\
    void test_precision_edge_cases() {\n    // \u975E\u5E38\u306B\u5C0F\u3055\u306A\
    \u5206\u6570\n    RationalInt r1(1LL, 1000000000LL);\n    assert(r1.a == 1LL &&\
    \ r1.b == 1000000000LL);\n    \n    // \u5206\u5B50\u304C0\u306E\u30B1\u30FC\u30B9\
    \n    RationalInt r2(0, 12345);\n    assert(r2.a == 0 && r2.b == 1);\n    \n \
    \   // \u5206\u5B50\u5206\u6BCD\u304C\u540C\u3058\u7B26\u53F7\n    RationalInt\
    \ r3(-100, -200);\n    assert(r3.a == 1 && r3.b == 2);\n}\n\nvoid test_random_operations()\
    \ {\n    // \u30E9\u30F3\u30C0\u30E0\u306A\u5206\u6570\u3067\u306E\u57FA\u672C\
    \u6F14\u7B97\u30C6\u30B9\u30C8\uFF081e6\u56DE\uFF09\n    for (int i = 0; i < 1000000;\
    \ i++) {\n        int a1 = random::rng(-10000, 10001), b1 = random::rng(1, 10001);\n\
    \        int a2 = random::rng(-10000, 10001), b2 = random::rng(1, 10001);\n  \
    \      \n        RationalInt r1(a1, b1), r2(a2, b2);\n        \n        // \u52A0\
    \u6CD5\u306E\u9006\u5143\u30C6\u30B9\u30C8: r + (-r) = 0\n        assert((r1 +\
    \ (-r1)).a == 0);\n        \n        // \u4E57\u6CD5\u306E\u9006\u5143\u30C6\u30B9\
    \u30C8: r * r.inv() = 1 (r != 0\u306E\u5834\u5408)\n        if (r1.a != 0) {\n\
    \            auto prod = r1 * r1.inv();\n            assert(prod.a == 1 && prod.b\
    \ == 1);\n        }\n        \n        // \u4EA4\u63DB\u5F8B\u30C6\u30B9\u30C8\
    : a + b = b + a, a * b = b * a\n        assert(r1 + r2 == r2 + r1);\n        assert(r1\
    \ * r2 == r2 * r1);\n        \n        // \u9664\u6CD5\u306E\u5B9A\u7FA9\u30C6\
    \u30B9\u30C8: a / b = a * b.inv()\n        if (r2.a != 0) {\n            assert(r1\
    \ / r2 == r1 * r2.inv());\n        }\n    }\n}\n\nvoid test_comparison_consistency()\
    \ {\n    // \u6BD4\u8F03\u6F14\u7B97\u5B50\u306E\u4E00\u8CAB\u6027\u30C6\u30B9\
    \u30C8\uFF081e6\u56DE\uFF09\n    for (int i = 0; i < 1000000; i++) {\n       \
    \ int a1 = random::rng(-10000, 10001), b1 = random::rng(1, 10001);\n        int\
    \ a2 = random::rng(-10000, 10001), b2 = random::rng(1, 10001);\n        \n   \
    \     RationalInt r1(a1, b1), r2(a2, b2);\n        \n        // \u4E09\u5206\u5F8B\
    : r1 < r2, r1 == r2, r1 > r2 \u306E\u3046\u3061 exactly one \u304C\u771F\n   \
    \     int count = 0;\n        if (r1 < r2) count++;\n        if (r1 == r2) count++;\n\
    \        if (r1 > r2) count++;\n        assert(count == 1);\n        \n      \
    \  // \u63A8\u79FB\u5F8B\u306E\u4E00\u90E8: r1 <= r2 and r2 <= r1 => r1 == r2\n\
    \        if (r1 <= r2 && r2 <= r1) {\n            assert(r1 == r2);\n        }\n\
    \        \n        // \u53CD\u5BFE\u79F0\u6027: r1 < r2 <=> r2 > r1\n        assert((r1\
    \ < r2) == (r2 > r1));\n        assert((r1 <= r2) == (r2 >= r1));\n    }\n}\n\n\
    void test_overflow_safety() {\n    // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3092\u907F\u3051\u308B\u305F\u3081\u306E\u5883\u754C\u5024\u30C6\u30B9\u30C8\
    \n    const int SAFE_MAX = 10000;  // \u5B89\u5168\u306A\u6700\u5927\u5024\n \
    \   \n    RationalInt r1(SAFE_MAX, 1);\n    RationalInt r2(1, SAFE_MAX);\n   \
    \ \n    // \u5927\u304D\u306A\u6570\u540C\u58EB\u306E\u6F14\u7B97\n    auto sum\
    \ = r1 + r2;  // SAFE_MAX + 1/SAFE_MAX\n    assert(sum.a == SAFE_MAX * SAFE_MAX\
    \ + 1);\n    assert(sum.b == SAFE_MAX);\n    \n    // \u7D04\u5206\u304C\u6B63\
    \u3057\u304F\u884C\u308F\u308C\u308B\u3053\u3068\u3092\u78BA\u8A8D\n    RationalInt\
    \ r3(SAFE_MAX * 2, SAFE_MAX * 4);\n    assert(r3.a == 1 && r3.b == 2);\n}\n\n\
    void test_double_conversion_accuracy() {\n    // \u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u5909\u63DB\u306E\u7CBE\u5EA6\u30C6\u30B9\u30C8\uFF081e6\u56DE\uFF09\n    for\
    \ (int i = 0; i < 1000000; i++) {\n        int a = random::rng(-1000, 1001);\n\
    \        int b = random::rng(1, 1001);\n        \n        RationalInt r(a, b);\n\
    \        double expected = (double)a / b;\n        \n        assert(abs(r.to_double()\
    \ - expected) < 1e-12);\n        \n        // long double\u7248\u3082\u78BA\u8A8D\
    \n        long double expected_ld = (long double)a / b;\n        assert(abs(r.to_ldouble()\
    \ - expected_ld) < 1e-15L);\n    }\n}\n\nvoid test_stress_large_numbers() {\n\
    \    // \u5927\u304D\u306A\u6570\u3067\u306E\u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\
    \u30C8\n    const long long BIG = 1000000007LL;\n    \n    RationalI64 r1(BIG,\
    \ 1);\n    RationalI64 r2(1, BIG);\n    \n    // \u5927\u304D\u306A\u6570\u540C\
    \u58EB\u306E\u6F14\u7B97\n    auto sum = r1 + r2;\n    assert(sum.a == BIG * BIG\
    \ + 1);\n    assert(sum.b == BIG);\n    \n    auto diff = r1 - r2;\n    assert(diff.a\
    \ == BIG * BIG - 1);\n    assert(diff.b == BIG);\n    \n    auto prod = r1 * r2;\n\
    \    assert(prod.a == 1 && prod.b == 1);\n    \n    auto div = r1 / r2;\n    assert(div.a\
    \ == BIG * BIG && div.b == 1);\n}\n\nvoid test_special_rational_values() {\n \
    \   // \u7279\u6B8A\u306A\u6709\u7406\u6570\u5024\u306E\u30C6\u30B9\u30C8\n  \
    \  \n    // 1/1 = 1\n    RationalInt one(1, 1);\n    assert(one.a == 1 && one.b\
    \ == 1);\n    \n    // \u4EFB\u610F\u306E\u6570\u306B1\u3092\u8DB3\u3059/\u5F15\
    \u304F\n    RationalInt r(3, 7);\n    auto plus_one = r + one;\n    assert(plus_one.a\
    \ == 10 && plus_one.b == 7);  // 3/7 + 1 = 10/7\n    \n    auto minus_one = r\
    \ - one;\n    assert(minus_one.a == -4 && minus_one.b == 7);  // 3/7 - 1 = -4/7\n\
    \    \n    // 1/2\u306E\u7D2F\u4E57\n    RationalInt half(1, 2);\n    auto quarter\
    \ = half * half;\n    assert(quarter.a == 1 && quarter.b == 4);  // (1/2)^2 =\
    \ 1/4\n    \n    auto eighth = quarter * half;\n    assert(eighth.a == 1 && eighth.b\
    \ == 8);  // (1/4) * (1/2) = 1/8\n}\n\nvoid test_chain_operations() {\n    //\
    \ \u9023\u7D9A\u6F14\u7B97\u306E\u30C6\u30B9\u30C8\uFF081e6\u56DE\uFF09\n    for\
    \ (int i = 0; i < 1000000; i++) {\n        RationalInt result(1, 1);  // 1\u304B\
    \u3089\u958B\u59CB\n        \n        // \u5404\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\
    \u306710\u56DE\u306E\u9023\u7D9A\u6F14\u7B97\n        for (int j = 0; j < 10;\
    \ j++) {\n            int op = random::rng(0, 4);  // 0:+, 1:-, 2:*, 3:/\n   \
    \         int a = random::rng(-10, 11);\n            int b = random::rng(1, 11);\n\
    \            \n            RationalInt operand(a, b);\n            \n        \
    \    switch (op) {\n                case 0: result += operand; break;\n      \
    \          case 1: result -= operand; break;\n                case 2: result *=\
    \ operand; break;\n                case 3:\n                    if (operand.a\
    \ != 0) {\n                        result /= operand;\n                    }\n\
    \                    break;\n            }\n            \n            // \u7D50\
    \u679C\u304C\u6B63\u898F\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\u3092\
    \u78BA\u8A8D\n            assert(result.b > 0);\n            assert(std::gcd(abs(result.a),\
    \ result.b) == 1);\n        }\n    }\n}\n\nint main() {\n    int a, b;\n    kin\
    \ >> a >> b;\n    kout << a + b << kendl;\n\n    cerr << \"Starting comprehensive\
    \ rational number tests...\" << endl;\n\n    // \u57FA\u672C\u30C6\u30B9\u30C8\
    \u5B9F\u884C\n    cerr << \"Running basic functionality tests...\" << endl;\n\
    \    test_constructor();\n    test_arithmetic();\n    test_comparison();\n   \
    \ test_unary_operations();\n    test_assignment_operators();\n    test_boolean_conversion();\n\
    \    test_floating_point_conversion();\n    test_edge_cases();\n    \n    // \u5883\
    \u754C\u5024\u30FB\u30E9\u30F3\u30C0\u30E0\u30C6\u30B9\u30C8\u5B9F\u884C\n   \
    \ cerr << \"Running boundary value and random tests...\" << endl;\n    test_precision_edge_cases();\n\
    \    test_random_operations();\n    test_comparison_consistency();\n    test_overflow_safety();\n\
    \    test_double_conversion_accuracy();\n    \n    // \u8FFD\u52A0\u306E\u53B3\
    \u5BC6\u30C6\u30B9\u30C8\n    cerr << \"Running stress and edge case tests...\"\
    \ << endl;\n    test_stress_large_numbers();\n    test_special_rational_values();\n\
    \    test_chain_operations();\n    \n    // \u3059\u3079\u3066\u306E\u30C6\u30B9\
    \u30C8\u304C\u901A\u3063\u305F\u5834\u5408\n    cerr << endl << \"=== ALL RATIONAL\
    \ TESTS PASSED ===\" << endl;\n    cerr << \"All tests completed successfully!\"\
    \ << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - math/rational.hpp
  - type_traits/io.hpp
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
  path: verify/unit_test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/math/rational.test.cpp
- /verify/verify/unit_test/math/rational.test.cpp.html
title: verify/unit_test/math/rational.test.cpp
---
