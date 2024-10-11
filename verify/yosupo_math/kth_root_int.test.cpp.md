---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/kth_root_floor.hpp
    title: math/kth_root_floor.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"verify/yosupo_math/kth_root_int.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#line 1 \"math/kth_root_floor.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cmath>\n#include <cstdint>\n#include <functional>\n\
    \nnamespace kk2 {\n\nuint64_t kth_root_floor_inner(uint64_t a, int k) {\n    if\
    \ (a <= 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t\
    \ x) {\n        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1,\
    \ q *= q) {\n            if (b & 1) p *= q;\n        }\n        return p <= a;\n\
    \    };\n    uint64_t x = powl(a, (long double)1.0 / k);\n    while (!check(x))\
    \ --x;\n    while (check(x + 1)) ++x;\n    return x;\n}\n\n// return floor(a ^\
    \ {1/k})\ntemplate <class return_type = uint64_t, class T, class U> return_type\
    \ kth_root_floor(T a, U k) {\n    return (return_type)kth_root_floor_inner((uint64_t)a,\
    \ (int)k);\n}\n\nuint64_t kth_root_ceil_inner(uint64_t a, int k) {\n    if (a\
    \ <= 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    auto check = [&](__uint128_t\
    \ x) {\n        __uint128_t p = 1, q = x;\n        for (int b = k; b; b >>= 1,\
    \ q *= q) {\n            if (b & 1) p *= q;\n        }\n        return p == a;\n\
    \    };\n    uint64_t x = kth_root_floor_inner(a, k);\n    return check(x) ? x\
    \ : x + 1;\n}\n\n// return ceil(a ^ {1/k})\ntemplate <class return_type = uint64_t,\
    \ class T, class U> return_type kth_root_ceil(T a, U k) {\n    return (return_type)kth_root_ceil_inner((uint64_t)a,\
    \ (int)k);\n}\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\
    \n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n\
    #line 8 \"template/template.hpp\"\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <chrono>\n#line 13 \"template/template.hpp\"\n#include <cstring>\n\
    #include <deque>\n#include <fstream>\n#line 17 \"template/template.hpp\"\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\nusing u32 = unsigned int;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
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
    \    return is;\n}\n\n\n#line 5 \"verify/yosupo_math/kth_root_int.test.cpp\"\n\
    using namespace std;\n\nint main() {\n    int t;\n    cin >> t;\n    rep (t) {\n\
    \        u64 a, k;\n        cin >> a >> k;\n        cout << kk2::kth_root_floor(a,\
    \ k) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include \"../../math/kth_root_floor.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int t;\n    cin >> t;\n    rep (t)\
    \ {\n        u64 a, k;\n        cin >> a >> k;\n        cout << kk2::kth_root_floor(a,\
    \ k) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/kth_root_floor.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_math/kth_root_int.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 14:10:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_math/kth_root_int.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/kth_root_int.test.cpp
- /verify/verify/yosupo_math/kth_root_int.test.cpp.html
title: verify/yosupo_math/kth_root_int.test.cpp
---
