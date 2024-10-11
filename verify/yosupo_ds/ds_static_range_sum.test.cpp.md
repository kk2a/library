---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/prefix_sum.hpp
    title: data_structure/prefix_sum.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"data_structure/prefix_sum.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \nnamespace kk2 {\n\ntemplate <class T> struct PrefixSum {\n    std::vector<T>\
    \ acc;\n    int n;\n\n    constexpr PrefixSum() = default;\n\n    constexpr PrefixSum(const\
    \ std::vector<T> &a) : acc(a.size() + 1), n((int)a.size()) {\n        for (int\
    \ i = 0; i < n; ++i) { acc[i + 1] = acc[i] + a[i]; }\n    }\n\n    constexpr T\
    \ sum(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n   \
    \     return acc[r] - acc[l];\n    }\n\n    constexpr T get(int i) const {\n \
    \       assert(0 <= i && i < n);\n        return acc[i + 1] - acc[i];\n    }\n\
    \n    constexpr T operator[](int i) const {\n        assert(0 <= i && i < n);\n\
    \        return acc[i + 1] - acc[i];\n    }\n\n    constexpr T operator()(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ acc[r] - acc[l];\n    }\n\n    constexpr int size() const { return n; }\n\n\
    \    // require: acc is non-decreasing\n    // return r s.t.\n    // r = n or\
    \ sum(l, r) >= x\n    // r = l or sum(l, r) < x\n    constexpr int lower(int l,\
    \ T x) const {\n        assert(0 <= l && l <= n);\n        int ng = l - 1, ok\
    \ = n;\n        while (ok - ng > 1) {\n            int mid = (ok + ng) >> 1;\n\
    \            if (acc[mid] - acc[l] < x) ng = mid;\n            else ok = mid;\n\
    \        }\n        return ok;\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"\
    template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n//\
    \ #include <bits/stdc++.h>\n#line 9 \"template/template.hpp\"\n#include <bitset>\n\
    #line 11 \"template/template.hpp\"\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <limits>\n#include\
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
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_ds/ds_static_range_sum.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  vc<i64> a(n);\n    cin >> a;\n    kk2::PrefixSum<i64> ps(a);\n\n    rep (q)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << ps.sum(l, r) <<\
    \ \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../data_structure/prefix_sum.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  vc<i64> a(n);\n    cin >> a;\n    kk2::PrefixSum<i64> ps(a);\n\n    rep (q)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << ps.sum(l, r) <<\
    \ \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/prefix_sum.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 16:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_static_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_static_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_static_range_sum.test.cpp
---
