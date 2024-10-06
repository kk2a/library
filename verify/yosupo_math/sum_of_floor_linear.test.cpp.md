---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/floor_sum.hpp
    title: math/floor_sum.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"verify/yosupo_math/sum_of_floor_linear.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line\
    \ 1 \"math/floor_sum.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace kk2 {\n\n\
    // https://atcoder.jp/contests/practice2/editorial/579\n// sum_{i=0}^{n-1} floor((a\
    \ * i + b) / m)\ntemplate <class T> T sum_of_floor(T n, T m, T a, T b) {\n   \
    \ T res = 0;\n    while (true) {\n        if (a >= m) res += (n - 1) * n / 2 *\
    \ (a / m), a %= m;\n        if (b >= m) res += n * (b / m), b %= m;\n        T\
    \ max = a * n + b;\n        if (max < m) break;\n        n = max / m, b = max\
    \ % m;\n        std::swap(a, m);\n    }\n    return res;\n}\n\ntemplate <class\
    \ T> T sum_of_floor(T n, T m, T a, T b, T start) {\n    return sum_of_floor(n\
    \ - start, m, a, b + a * start);\n}\n\n} // namespace kk2\n\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n\
    #line 8 \"template/template.hpp\"\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <chrono>\n#include <cmath>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <optional>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\nusing u32 = unsigned int;\nusing i64 = long\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\" : \"NO\") << '\\n';\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\" : \"YES\") << '\\n';\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\" : \"No\") << '\\n';\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\" : \"Yes\") << '\\n';\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\" : \"no\") << '\\n';\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\" : \"yes\") << '\\n';\n}\n\n#define rep1(a) for (i64 _ = 0; _\
    \ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define\
    \ rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for\
    \ (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1;\
    \ i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\n#ifdef KK2\nstd::ifstream in(\"in.txt\");\nstd::ofstream out(\"\
    out.txt\");\n#else\n#define in std::cin\n#define out std::cout\n#endif\n\ntemplate\
    \ <class T, class U> std::ostream &operator<<(std::ostream &os, const std::pair<T,\
    \ U> &p) {\n    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate\
    \ <class T, class U> std::istream &operator>>(std::istream &is, std::pair<T, U>\
    \ &p) {\n    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class\
    \ T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {\n \
    \   for (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class T> std::istream &operator>>(std::istream\
    \ &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n    return is;\n\
    }\n\n\n#line 5 \"verify/yosupo_math/sum_of_floor_linear.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int t;\n    cin >> t;\n    rep (t) {\n        i64\
    \ n, m, a, b;\n        cin >> n >> m >> a >> b;\n        cout << kk2::sum_of_floor(n,\
    \ m, a, b) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"../../math/floor_sum.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int t;\n    cin >> t;\n    rep (t)\
    \ {\n        i64 n, m, a, b;\n        cin >> n >> m >> a >> b;\n        cout <<\
    \ kk2::sum_of_floor(n, m, a, b) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/floor_sum.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_math/sum_of_floor_linear.test.cpp
  requiredBy: []
  timestamp: '2024-10-07 04:00:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_math/sum_of_floor_linear.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/sum_of_floor_linear.test.cpp
- /verify/verify/yosupo_math/sum_of_floor_linear.test.cpp.html
title: verify/yosupo_math/sum_of_floor_linear.test.cpp
---
