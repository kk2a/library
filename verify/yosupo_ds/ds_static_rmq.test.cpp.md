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
    \ {}\n\n    operator S() const { return a; }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Min &min) {\n        if (min.inf) os << \"inf\";\n        else os\
    \ << min.a;\n        return os;\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Min &min) {\n        is >> min.a;\n        min.inf = false;\n        return\
    \ is;\n    }\n\n    constexpr Min &operator=(const S &rhs) {\n        a = rhs;\n\
    \        inf = false;\n        return *this;\n    }\n\n    constexpr Min &add(const\
    \ S &rhs) {\n        if (inf) return *this;\n        a += rhs;\n        return\
    \ *this;\n    }\n\n    constexpr Min &update(const S &rhs) {\n        a = rhs;\n\
    \        inf = false;\n        return *this;\n    }\n\n    constexpr bool is_inf()\
    \ { return inf; }\n};\n\ntemplate <class S> constexpr Min<S> MinOp(Min<S> l, Min<S>\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64 _ = 0; _ < (i64)(a);\
    \ ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define rep3(i,\
    \ a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for (i64 i =\
    \ (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define all(p)\
    \ std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n    }\n} iosetup;\n\ntemplate <class\
    \ OStream, class T, class U>\nOStream &operator<<(OStream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T, class U> IStream &operator>>(IStream &is, std::pair<T,\
    \ U> &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &v)\
    \ {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_ds/ds_static_rmq.test.cpp\"\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    auto\
    \ a = kk2::GetVecMin<int>(n);\n    cin >> a;\n    kk2::StaticRMQ<int> rmq(a);\n\
    \n    rep (q) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.prod(l,\
    \ r) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../data_structure/static_rmq.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  auto a = kk2::GetVecMin<int>(n);\n    cin >> a;\n    kk2::StaticRMQ<int> rmq(a);\n\
    \n    rep (q) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.prod(l,\
    \ r) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/static_rmq.hpp
  - math/monoid/min.hpp
  - data_structure/sparse_table.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 23:12:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_static_rmq.test.cpp
- /verify/verify/yosupo_ds/ds_static_rmq.test.cpp.html
title: verify/yosupo_ds/ds_static_rmq.test.cpp
---
