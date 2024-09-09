---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iterator>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <unordered_set>\n#include <unordered_map>\n#include\
    \ <utility>\n#include <vector>\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <>\nconstexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<i64>) * infty<i64>;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <>\nconstexpr double infty<double> = infty<i64>;\n\
    template <>\nconstexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\ntemplate <class T>\nusing vc = std::vector<T>;\n\
    template <class T>\nusing vvc = std::vector<vc<T>>;\ntemplate <class T>\nusing\
    \ vvvc = std::vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T>\nusing pq = std::priority_queue<T>;\ntemplate <class T>\n\
    using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes>\nauto make_vector(const T &init,\
    \ int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n \
    \       return std::vector<T>(first, init);\n    }\n    else {\n        return\
    \ std::vector<decltype(make_vector(init, sizes...))>(first, make_vector(init,\
    \ sizes...));\n    }\n}\n\ntemplate <class T, class U>\nvoid fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U>\nvoid fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\n\ntemplate\
    \ <class T, class S>\ninline bool chmax(T &a, const S &b) {\n    return (a < b\
    \ ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const\
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n# define rep1(a) for (i64\
    \ _ = 0; _ < (i64)(a); ++_)\n# define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n# define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n# define\
    \ repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)\n# define repi3(i, a, b) for\
    \ (i64 i = (a) - 1; i >= (i64)(b); --i)\n\n# define overload3(a, b, c, d, ...)\
    \ d\n\n# define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    # define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    # define fi first\n# define se second\n# define all(p) std::begin(p), std::end(p)\n\
    \nvoid YES(bool b = 1) { std::cout << (b ? \"YES\" : \"NO\") << '\\n'; }\nvoid\
    \ NO(bool b = 1) { std::cout << (b ? \"NO\" : \"YES\") << '\\n'; }\nvoid YESflush(bool\
    \ b = 1) { std::cout << (b ? \"YES\" : \"NO\") << std::endl; }\nvoid NOflush(bool\
    \ b = 1) { std::cout << (b ? \"NO\" : \"YES\") << std::endl; }\nvoid Yes(bool\
    \ b = 1) { std::cout << (b ? \"Yes\" : \"No\") << '\\n'; }\nvoid No(bool b = 1)\
    \ { std::cout << (b ? \"No\" : \"Yes\") << '\\n'; }\nvoid Yesflush(bool b = 1)\
    \ { std::cout << (b ? \"Yes\" : \"No\") << std::endl; }\nvoid Noflush(bool b =\
    \ 1) { std::cout << (b ? \"No\" : \"Yes\") << std::endl; }\nvoid yes(bool b =\
    \ 1) { std::cout << (b ? \"yes\" : \"no\") << '\\n'; }\nvoid no(bool b = 1) {\
    \ std::cout << (b ? \"no\" : \"yes\") << '\\n'; }\nvoid yesflush(bool b = 1) {\
    \ std::cout << (b ? \"yes\" : \"no\") << std::endl; }\nvoid noflush(bool b = 1)\
    \ { std::cout << (b ? \"no\" : \"yes\") << std::endl; }\n\n\n"
  code: "#ifndef TEMPLATE\n#define TEMPLATE 1\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iterator>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <unordered_set>\n#include <unordered_map>\n#include\
    \ <utility>\n#include <vector>\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <>\nconstexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<i64>) * infty<i64>;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <>\nconstexpr double infty<double> = infty<i64>;\n\
    template <>\nconstexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\ntemplate <class T>\nusing vc = std::vector<T>;\n\
    template <class T>\nusing vvc = std::vector<vc<T>>;\ntemplate <class T>\nusing\
    \ vvvc = std::vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T>\nusing pq = std::priority_queue<T>;\ntemplate <class T>\n\
    using pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes>\nauto make_vector(const T &init,\
    \ int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n \
    \       return std::vector<T>(first, init);\n    }\n    else {\n        return\
    \ std::vector<decltype(make_vector(init, sizes...))>(first, make_vector(init,\
    \ sizes...));\n    }\n}\n\ntemplate <class T, class U>\nvoid fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U>\nvoid fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\n\ntemplate\
    \ <class T, class S>\ninline bool chmax(T &a, const S &b) {\n    return (a < b\
    \ ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const\
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n# define rep1(a) for (i64\
    \ _ = 0; _ < (i64)(a); ++_)\n# define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n# define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n# define\
    \ repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)\n# define repi3(i, a, b) for\
    \ (i64 i = (a) - 1; i >= (i64)(b); --i)\n\n# define overload3(a, b, c, d, ...)\
    \ d\n\n# define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    # define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    # define fi first\n# define se second\n# define all(p) std::begin(p), std::end(p)\n\
    \nvoid YES(bool b = 1) { std::cout << (b ? \"YES\" : \"NO\") << '\\n'; }\nvoid\
    \ NO(bool b = 1) { std::cout << (b ? \"NO\" : \"YES\") << '\\n'; }\nvoid YESflush(bool\
    \ b = 1) { std::cout << (b ? \"YES\" : \"NO\") << std::endl; }\nvoid NOflush(bool\
    \ b = 1) { std::cout << (b ? \"NO\" : \"YES\") << std::endl; }\nvoid Yes(bool\
    \ b = 1) { std::cout << (b ? \"Yes\" : \"No\") << '\\n'; }\nvoid No(bool b = 1)\
    \ { std::cout << (b ? \"No\" : \"Yes\") << '\\n'; }\nvoid Yesflush(bool b = 1)\
    \ { std::cout << (b ? \"Yes\" : \"No\") << std::endl; }\nvoid Noflush(bool b =\
    \ 1) { std::cout << (b ? \"No\" : \"Yes\") << std::endl; }\nvoid yes(bool b =\
    \ 1) { std::cout << (b ? \"yes\" : \"no\") << '\\n'; }\nvoid no(bool b = 1) {\
    \ std::cout << (b ? \"no\" : \"yes\") << '\\n'; }\nvoid yesflush(bool b = 1) {\
    \ std::cout << (b ? \"yes\" : \"no\") << std::endl; }\nvoid noflush(bool b = 1)\
    \ { std::cout << (b ? \"no\" : \"yes\") << std::endl; }\n\n#endif // TEMPLATE\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-09-10 07:56:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
