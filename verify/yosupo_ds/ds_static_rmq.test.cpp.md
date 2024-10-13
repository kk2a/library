---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_static_rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"data_structure/static_rmq.hpp\"\
    \n\n\n\n#line 1 \"math/monoid/min.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace monoid {\n\ntemplate\
    \ <class S> struct Min {\n    S a;\n    bool inf;\n\n    constexpr Min() : a(S()),\
    \ inf(true) {}\n\n    constexpr Min(S a_, bool inf_ = false) : a(a_), inf(inf_)\
    \ {}\n\n    operator S() const { return a; }\n\n    template <class OStream>\n\
    \    friend OStream &operator<<(OStream &os, const Min &min) {\n        if (min.inf)\
    \ os << \"inf\";\n        else os << min.a;\n        return os;\n    }\n\n   \
    \ template <class IStream>\n    friend IStream &operator>>(IStream &is, Min &min)\
    \ {\n        is >> min.a;\n        min.inf = false;\n        return is;\n    }\n\
    \n    constexpr Min &operator=(const S &rhs) {\n        a = rhs;\n        inf\
    \ = false;\n        return *this;\n    }\n\n    constexpr Min &add(const S &rhs)\
    \ {\n        if (inf) return *this;\n        a += rhs;\n        return *this;\n\
    \    }\n\n    constexpr Min &update(const S &rhs) {\n        a = rhs;\n      \
    \  inf = false;\n        return *this;\n    }\n\n    constexpr bool is_inf() {\
    \ return inf; }\n};\n\ntemplate <class S> constexpr Min<S> MinOp(Min<S> l, Min<S>\
    \ r) {\n    if (r.inf) return l;\n    if (l.inf) return r;\n    l.a = std::min(l.a,\
    \ r.a);\n    return l;\n}\n\ntemplate <class S> Min<S> MinUnit() {\n    constexpr\
    \ static Min<S> e = Min<S>();\n    return e;\n}\n\n} // namespace monoid\n\ntemplate\
    \ <class S, class... Args>\nstd::vector<monoid::Min<S>> GetVecMin(int n, Args...\
    \ args) {\n    return std::vector<monoid::Min<S>>(n, monoid::Min<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<monoid::Min<S>>>\
    \ GetVecMin2D(int h, int w, Args... args) {\n    return std::vector<std::vector<monoid::Min<S>>>(h,\
    \ GetVecMin(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"data_structure/sparse_table.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"data_structure/sparse_table.hpp\"\n\nnamespace\
    \ kk2 {\n\n// require: op(x, x) = x for all x\ntemplate <class S, S (*op)(S, S),\
    \ S (*e)()> struct SparseTable {\n    SparseTable() = default;\n\n    SparseTable(const\
    \ std::vector<S> &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1\
    \ << log) < _n) log++;\n        table.assign(log + 1, std::vector<S>(_n));\n \
    \       for (int i = 0; i < _n; i++) table[0][i] = v[i];\n        for (int i =\
    \ 1; i <= log; i++) {\n            for (int j = 0; j + (1 << i) <= _n; j++) {\n\
    \                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n\n    using Monoid = S;\n\n    static\
    \ S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit() { return e();\
    \ }\n\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r\
    \ <= _n);\n        if (l == r) return e();\n        int i = 31 ^ __builtin_clz(r\
    \ - l);\n        return op(table[i][l], table[i][r - (1 << i)]);\n    }\n\n  \
    \  S get(int i) const {\n        assert(0 <= i && i < _n);\n        return table[0][i];\n\
    \    }\n\n    // return r s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1]))\
    \ == true\n    // r = n or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template\
    \ <bool (*f)(S)> int max_right(int l) const {\n        return max_right(l, [](S\
    \ x) { return f(x); });\n    }\n\n    template <class F> int max_right(int l,\
    \ F f) const {\n        assert(0 <= l && l <= _n);\n        assert(f(e()));\n\
    \        if (l == _n) return _n;\n        int left = l - 1, right = _n;\n    \
    \    while (right - left > 1) {\n            int mid = (left + right) >> 1;\n\
    \            if (f(prod(l, mid))) left = mid;\n            else right = mid;\n\
    \        }\n        return right;\n    }\n\n    // return l s.t.\n    // l = r\
    \ or f(op(a[l], a[l+1], ..., a[r-1])) == false\n    // l = 0 or f(op(a[l], a[l+1],\
    \ ..., a[r]))   == true\n    template <bool (*f)(S)> int min_left(int r) const\
    \ {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template\
    \ <class F> int min_left(int r, F f) const {\n        assert(0 <= r && r <= _n);\n\
    \        assert(f(e()));\n        if (r == 0) return 0;\n        int left = -1,\
    \ right = r;\n        while (right - left > 1) {\n            int mid = (left\
    \ + right) >> 1;\n            if (f(prod(mid, r))) right = mid;\n            else\
    \ left = mid;\n        }\n        return right;\n    }\n\n  private:\n    int\
    \ _n, log;\n    std::vector<std::vector<S>> table;\n};\n\n} // namespace kk2\n\
    \n\n#line 6 \"data_structure/static_rmq.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S>\nusing StaticRMQ = SparseTable<monoid::Min<S>, monoid::MinOp<S>, monoid::MinUnit<S>>;\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC\
    \ optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 36 \"template/template.hpp\"\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> using vc = std::vector<T>;\ntemplate <class T> using vvc =\
    \ std::vector<vc<T>>;\ntemplate <class T> using vvvc = std::vector<vvc<T>>;\n\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define rep1(a) for (i64 _ = 0;\
    \ _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n\
    #define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a)\
    \ for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include <cctype>\n#include\
    \ <cstdint>\n#include <cstdio>\n#line 10 \"template/fastio.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace fastio {\n\n#define INPUT_FILE \"in.txt\"\n#define OUTPUT_FILE\
    \ \"out.txt\"\n\nstruct Scanner {\n  private:\n    static constexpr size_t INPUT_BUF\
    \ = 1 << 17;\n    size_t pos = INPUT_BUF;\n    static char buf[INPUT_BUF];\n \
    \   FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
    \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (pos == INPUT_BUF)\
    \ {\n            size_t len = fread(buf, 1, INPUT_BUF, fp);\n            if (len\
    \ != INPUT_BUF) buf[len] = '\\0';\n            pos = 0;\n        }\n        return\
    \ buf[pos];\n    }\n\n    void skip_space() {\n        while (isspace(now()))\
    \ ++pos;\n    }\n\n    uint32_t next_u32() {\n        skip_space();\n        uint32_t\
    \ res = 0;\n        while (isdigit(now())) {\n            res = res * 10 + (now()\
    \ - '0');\n            ++pos;\n        }\n        return res;\n    }\n\n    int32_t\
    \ next_i32() {\n        skip_space();\n        if (now() == '-') {\n         \
    \   ++pos;\n            return (int32_t)(-next_u32());\n        } else return\
    \ (int32_t)next_u32();\n    }\n\n    uint64_t next_u64() {\n        skip_space();\n\
    \        uint64_t res = 0;\n        while (isdigit(now())) {\n            res\
    \ = res * 10 + (now() - '0');\n            ++pos;\n        }\n        return res;\n\
    \    }\n\n    int64_t next_i64() {\n        skip_space();\n        if (now() ==\
    \ '-') {\n            ++pos;\n            return (int64_t)(-next_u64());\n   \
    \     } else return (int64_t)next_u64();\n    }\n\n    __uint128_t next_u128()\
    \ {\n        skip_space();\n        __uint128_t res = 0;\n        while (isdigit(now()))\
    \ {\n            res = res * 10 + (now() - '0');\n            ++pos;\n       \
    \ }\n        return res;\n    }\n\n    __int128_t next_i128() {\n        skip_space();\n\
    \        if (now() == '-') {\n            ++pos;\n            return (__int128_t)(-next_u128());\n\
    \        } else return (__int128_t)next_u128();\n    }\n\n    char next_char()\
    \ {\n        skip_space();\n        auto res = now();\n        ++pos;\n      \
    \  return res;\n    }\n\n    std::string next_string() {\n        skip_space();\n\
    \        std::string res;\n        while (true) {\n            char c = now();\n\
    \            if (isspace(c) or c == '\\0') break;\n            res.push_back(now());\n\
    \            ++pos;\n        }\n        return res;\n    }\n\n    Scanner &operator>>(int\
    \ &x) {\n        x = next_i32();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned int &x) {\n        x = next_u32();\n        return *this;\n\
    \    }\n\n    Scanner &operator>>(long &x) {\n        x = next_i64();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(long long &x) {\n        x\
    \ = next_i64();\n        return *this;\n    }\n\n    Scanner &operator>>(unsigned\
    \ long &x) {\n        x = next_u64();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(unsigned long long &x) {\n        x = next_u64();\n        return\
    \ *this;\n    }\n\n    Scanner &operator>>(__int128_t &x) {\n        x = next_i128();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(__uint128_t &x) {\n \
    \       x = next_u128();\n        return *this;\n    }\n\n    Scanner &operator>>(char\
    \ &x) {\n        x = next_char();\n        return *this;\n    }\n\n    Scanner\
    \ &operator>>(std::string &x) {\n        x = next_string();\n        return *this;\n\
    \    }\n};\n\nstruct Printer {\n  private:\n    static char helper[1000][4];\n\
    \    static char leading_zero[1000][4];\n    constexpr static size_t OUTPUT_BUF\
    \ = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos = 0;\n    FILE\
    \ *fp;\n\n    static constexpr uint32_t pow10_32(uint32_t n) { return n == 0 ?\
    \ 1 : pow10_32(n - 1) * 10; }\n\n    static constexpr uint64_t pow10_64(uint32_t\
    \ n) { return n == 0 ? 1 : pow10_64(n - 1) * 10; }\n\n    static constexpr __uint128_t\
    \ pow10_128(uint32_t n) {\n        return n == 0 ? 1 : pow10_128(n - 1) * 10;\n\
    \    }\n\n    template <class T, class U> static constexpr void div_mod(T &a,\
    \ U &b, U mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n    static\
    \ void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0; i < 1000;\
    \ ++i) {\n            leading_zero[i][0] = i / 100 + '0';\n            leading_zero[i][1]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][2] = i % 10 + '0';\n     \
    \       leading_zero[i][3] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 100) helper[i][j++] = i / 100 + '0';\n            if (i >= 10) helper[i][j++]\
    \ = i / 10 % 10 + '0';\n            helper[i][j++] = i % 10 + '0';\n         \
    \   helper[i][j] = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout)\
    \ { init(); }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init();\
    \ }\n\n    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n\
    \    }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos =\
    \ 0;\n    }\n\n    void flush() {\n        write();\n        fflush(fp);\n   \
    \ }\n\n    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n\
    \        buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n      \
    \  while (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n   \
    \     uint32_t y;\n        if (x >= pow10_32(9)) {\n            div_mod(y, x,\
    \ pow10_32(9));\n            put_cstr(helper[y]);\n            div_mod(y, x, pow10_32(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_32(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_32(6)) {\n            div_mod(y, x, pow10_32(6));\n\
    \            put_cstr(helper[y]);\n            div_mod(y, x, pow10_32(3));\n \
    \           put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_32(3)) {\n            div_mod(y, x, pow10_32(3));\n\
    \            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n  \
    \      } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n \
    \       if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n \
    \       } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n        uint64_t\
    \ y;\n        if (x >= pow10_64(18)) {\n            div_mod(y, x, pow10_64(18));\n\
    \            put_cstr(helper[y]);\n            div_mod(y, x, pow10_64(15));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(12));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(9));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_64(9)) {\n            div_mod(y, x, pow10_64(9));\n\
    \            put_u32(uint32_t(y));\n            div_mod(y, x, pow10_64(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_64(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_u32(uint32_t(x));\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     __uint128_t y;\n        if (x >= pow10_128(36)) {\n            div_mod(y,\
    \ x, pow10_128(36));\n            put_cstr(helper[y]);\n            div_mod(y,\
    \ x, pow10_128(33));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(30));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(27));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(24));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(21));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(18));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(15));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(12));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(9));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(6));\n            put_cstr(leading_zero[y]);\n            div_mod(y,\
    \ x, pow10_128(3));\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= pow10_128(18)) {\n            div_mod(y, x, pow10_128(18));\n\
    \            put_u64(uint64_t(y));\n            div_mod(y, x, pow10_128(15));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(12));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(9));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(6));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod(y, x, pow10_128(3));\n\
    \            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_u64(uint64_t(x));\n    }\n\n    void put_i128(__int128_t x)\
    \ {\n        if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n\
    \        } else put_u128(x);\n    }\n\n    Printer &operator<<(int x) {\n    \
    \    put_i32(x);\n        return *this;\n    }\n\n    Printer &operator<<(unsigned\
    \ int x) {\n        put_u32(x);\n        return *this;\n    }\n\n    Printer &operator<<(long\
    \ x) {\n        put_i64(x);\n        return *this;\n    }\n\n    Printer &operator<<(long\
    \ long x) {\n        put_i64(x);\n        return *this;\n    }\n\n    Printer\
    \ &operator<<(unsigned long x) {\n        put_u64(x);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(unsigned long long x) {\n        put_u64(x);\n\
    \        return *this;\n    }\n\n    Printer &operator<<(__int128_t x) {\n   \
    \     put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(__uint128_t\
    \ x) {\n        put_u128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\nchar\
    \ Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[1000][4];\nchar Printer::leading_zero[1000][4];\n\
    \n} // namespace fastio\n\n} // namespace kk2\n\n#if defined(INTERACTIVE) || defined(USE_STDIO)\n\
    #define kin std::cin\n#define kout std::cout\n#elif defined(KK2)\nkk2::fastio::Scanner\
    \ kin(INPUT_FILE);\nkk2::fastio::Printer kout(OUTPUT_FILE);\n#define endl '\\\
    n'\n#else\nkk2::fastio::Scanner kin;\nkk2::fastio::Printer kout;\n#define endl\
    \ '\\n'\n#endif\n\n\n#line 119 \"template/template.hpp\"\n\ntemplate <class OStream,\
    \ class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p)\
    \ {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate <class\
    \ IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T, U>\
    \ &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\nvoid Yes(bool b = 1) {\n    kout << (b ? \"Yes\\n\" : \"\
    No\\n\");\n}\n\nvoid No(bool b = 1) {\n    kout << (b ? \"No\\n\" : \"Yes\\n\"\
    );\n}\n\nvoid YES(bool b = 1) {\n    kout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\
    \nvoid NO(bool b = 1) {\n    kout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid\
    \ yes(bool b = 1) {\n    kout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool\
    \ b = 1) {\n    kout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n\n#line 5 \"verify/yosupo_ds/ds_static_rmq.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  auto a = kk2::GetVecMin<int>(n);\n    kin >> a;\n    kk2::StaticRMQ<int> rmq(a);\n\
    \n    rep (q) {\n        int l, r;\n        kin >> l >> r;\n        kout << rmq.prod(l,\
    \ r) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../data_structure/static_rmq.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  auto a = kk2::GetVecMin<int>(n);\n    kin >> a;\n    kk2::StaticRMQ<int> rmq(a);\n\
    \n    rep (q) {\n        int l, r;\n        kin >> l >> r;\n        kout << rmq.prod(l,\
    \ r) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/static_rmq.hpp
  - math/monoid/min.hpp
  - data_structure/sparse_table.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 18:25:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_static_rmq.test.cpp
- /verify/verify/yosupo_ds/ds_static_rmq.test.cpp.html
title: verify/yosupo_ds/ds_static_rmq.test.cpp
---
