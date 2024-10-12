---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/sum.hpp
    title: math/group/sum.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/utility/sumseg.hpp
    title: segment_tree/utility/sumseg.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 1 \"\
    segment_tree/utility/sumseg.hpp\"\n\n\n\n#line 1 \"math/group/sum.hpp\"\n\n\n\n\
    #include <iostream>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace group {\n\
    \ntemplate <class S> struct Sum {\n    S a;\n    int size;\n\n    constexpr Sum()\
    \ : a(S()), size(0) {}\n\n    constexpr Sum(S a, S size = 1) : a(a), size(size)\
    \ {}\n\n    operator S() const { return a; }\n\n    template <class OStream>\n\
    \    friend OStream &operator<<(OStream &os, const Sum &sum) {\n        os <<\
    \ sum.a;\n        return os;\n    }\n\n    template <class IStream>\n    friend\
    \ IStream &operator>>(IStream &is, Sum &sum) {\n        is >> sum.a;\n       \
    \ sum.size = 1;\n        return is;\n    }\n\n    constexpr Sum &operator=(const\
    \ S &rhs) {\n        a = rhs;\n        size = 1;\n        return *this;\n    }\n\
    \n    constexpr Sum &add(const S &rhs) {\n        a += rhs * size;\n        return\
    \ *this;\n    }\n\n    constexpr Sum &update(const S &rhs) {\n        a = rhs\
    \ * size;\n        return *this;\n    }\n\n    constexpr Sum &multiply(const S\
    \ &rhs) {\n        a *= rhs;\n        return *this;\n    }\n};\n\ntemplate <class\
    \ S> constexpr Sum<S> SumOp(Sum<S> l, Sum<S> r) {\n    l.a += r.a;\n    l.size\
    \ += r.size;\n    return l;\n}\n\ntemplate <class S> Sum<S> SumUnit() {\n    constexpr\
    \ static Sum<S> e = Sum<S>();\n    return e;\n}\n\ntemplate <class S> constexpr\
    \ Sum<S> SumInv(Sum<S> x) {\n    x.a = -x.a;\n    x.size = -x.size;\n    return\
    \ x;\n}\n\n} // namespace group\n\ntemplate <class S, class... Args>\nstd::vector<group::Sum<S>>\
    \ GetVecSum(int n, Args... args) {\n    return std::vector<group::Sum<S>>(n, group::Sum<S>(args...));\n\
    }\n\ntemplate <class S, class... Args>\nstd::vector<std::vector<group::Sum<S>>>\
    \ GetVecSum2D(int h, int w, Args... args) {\n    return std::vector<std::vector<group::Sum<S>>>(h,\
    \ GetVecSum<S>(w, args...));\n}\n\n} // namespace kk2\n\n\n#line 1 \"segment_tree/seg.hpp\"\
    \n\n\n\n#include <cassert>\n#include <functional>\n#line 7 \"segment_tree/seg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct SegTree\
    \ {\n  public:\n    SegTree() : SegTree(0) {}\n\n    SegTree(int n) : SegTree(std::vector<S>(n,\
    \ e())) {}\n\n    template <class... Args>\n    SegTree(int n, Args... args) :\
    \ SegTree(std::vector<S>(n, S(args...))){};\n\n    SegTree(const std::vector<S>\
    \ &v) : _n(int(v.size())) {\n        log = 0;\n        while ((1U << log) < (unsigned\
    \ int)(_n)) log++;\n        size = 1 << log;\n        d = std::vector<S>(2 * size,\
    \ e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) { update(i); }\n    }\n\n    using Monoid =\
    \ S;\n\n    static S Op(S l, S r) { return op(l, r); }\n\n    static S MonoidUnit()\
    \ { return e(); }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    template <class... Args> void emplace_set(int\
    \ p, Args... args) { set(p, S(args...)); }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(), smr\
    \ = e();\n        l += size;\n        r += size;\n\n        while (l < r) {\n\
    \            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r],\
    \ smr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n\n    S all_prod() { return d[1]; }\n\n    // return r\
    \ s.t.\n    // r = l or f(op(a[l], a[l+1], ..., a[r-1])) == true\n    // r = n\
    \ or f(op(a[l], a[l+1], ..., a[r]))   == false\n    template <bool (*f)(S)> int\
    \ max_right(int l) {\n        return max_right(l, [](S x) { return f(x); });\n\
    \    }\n\n    template <class F> int max_right(int l, F f) {\n        assert(0\
    \ <= l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n\
    \        l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // return l\
    \ s.t.\n    // l = r or f(op(a[l], a[l], ..., a[r-1]))   == true\n    // l = 0\
    \ or f(op(a[l-1], a[l], ..., a[r-1])) == false\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n} // namespace kk2\n\n\n#line 6 \"segment_tree/utility/sumseg.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S> using SumSeg = SegTree<group::Sum<S>,\
    \ group::SumOp<S>, group::SumUnit<S>>;\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\
    \n#include <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n\
    #include <fstream>\n#line 17 \"template/template.hpp\"\n#include <iomanip>\n#line\
    \ 19 \"template/template.hpp\"\n#include <iterator>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#line 36 \"template/template.hpp\"\n\nusing u32 = unsigned\
    \ int;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\n\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define rep1(a) for (i64 _ = 0;\
    \ _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n\
    #define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a)\
    \ for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdio>\n#line 9 \"template/fastio.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace fastio {\n\n#define INPUT_FILE \"in.txt\"\n#define\
    \ OUTPUT_FILE \"out.txt\"\n\nstruct Scanner {\n  private:\n    static constexpr\
    \ size_t INPUT_BUF = 1 << 17;\n    size_t pos = INPUT_BUF;\n    static char buf[INPUT_BUF];\n\
    \    FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
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
    \ 0;\n    }\n\n    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n\
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
    struct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \    }\n} iosetup;\n#define kin std::cin\n#define kout std::cout\n#elif defined(KK2)\n\
    kk2::fastio::Scanner kin(INPUT_FILE);\nkk2::fastio::Printer kout(OUTPUT_FILE);\n\
    #define endl '\\n'\n#else\nkk2::fastio::Scanner kin;\nkk2::fastio::Printer kout;\n\
    #define endl '\\n'\n#endif\n\n\n#line 112 \"template/template.hpp\"\n\ntemplate\
    \ <class OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\nvoid Yes(bool b = 1) {\n    kout << (b ? \"Yes\\n\" : \"\
    No\\n\");\n}\n\nvoid No(bool b = 1) {\n    kout << (b ? \"No\\n\" : \"Yes\\n\"\
    );\n}\n\nvoid YES(bool b = 1) {\n    kout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\
    \nvoid NO(bool b = 1) {\n    kout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid\
    \ yes(bool b = 1) {\n    kout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool\
    \ b = 1) {\n    kout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n\n#line 5 \"verify/yosupo_ds/ds_point_add_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  auto a = kk2::GetVecSum<i64>(n);\n    kin >> a;\n    kk2::SumSeg<i64> seg(a);\n\
    \n    rep (q) {\n        int t;\n        kin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            kin >> p >> x;\n            seg.emplace_set(p,\
    \ seg.get(p).a + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            kin >> l >> r;\n            kout << seg.prod(l, r).a << \"\\n\";\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../segment_tree/utility/sumseg.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n  \
    \  auto a = kk2::GetVecSum<i64>(n);\n    kin >> a;\n    kk2::SumSeg<i64> seg(a);\n\
    \n    rep (q) {\n        int t;\n        kin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            kin >> p >> x;\n            seg.emplace_set(p,\
    \ seg.get(p).a + x);\n        }\n        if (t == 1) {\n            int l, r;\n\
    \            kin >> l >> r;\n            kout << seg.prod(l, r).a << \"\\n\";\n\
    \        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - segment_tree/utility/sumseg.hpp
  - math/group/sum.hpp
  - segment_tree/seg.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-13 04:00:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_add_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_point_add_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_point_add_range_sum.test.cpp
---
