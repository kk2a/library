---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_and.test.cpp
    title: verify/yosupo_convolution/convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    title: verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_gcd.test.cpp
    title: verify/yosupo_convolution/convolution_gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_lcm.test.cpp
    title: verify/yosupo_convolution/convolution_lcm.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    title: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    title: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_or.test.cpp
    title: verify/yosupo_convolution/convolution_or.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_xor.test.cpp
    title: verify/yosupo_convolution/convolution_xor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/shortest_path.test.cpp
    title: verify/yosupo_graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det.test.cpp
    title: verify/yosupo_linalg/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    title: verify/yosupo_linalg/matrix_det_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_inv.test.cpp
    title: verify/yosupo_linalg/matrix_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    title: verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_pow.test.cpp
    title: verify/yosupo_linalg/matrix_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_product.test.cpp
    title: verify/yosupo_linalg/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    title: verify/yosupo_linalg/matrix_product_f2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    title: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/factrize.test.cpp
    title: verify/yosupo_math/factrize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/kth_root_int.test.cpp
    title: verify/yosupo_math/kth_root_int.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/primality_test.test.cpp
    title: verify/yosupo_math/primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/sum_of_floor_linear.test.cpp
    title: verify/yosupo_math/sum_of_floor_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64 _ = 0; _ < (i64)(a);\
    \ ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define rep3(i,\
    \ a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for (i64 i =\
    \ (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define all(p)\
    \ std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n    }\n} iosetup;\n\n#ifdef KK2\n\
    std::ifstream in(\"in.txt\");\nstd::ofstream out(\"out.txt\");\n#else\n#define\
    \ in std::cin\n#define out std::cout\n#endif\n\ntemplate <class OStream, class\
    \ T, class U>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate <class IStream,\
    \ class T, class U> IStream &operator>>(IStream &is, std::pair<T, U> &p) {\n \
    \   is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class OStream,\
    \ class T> OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    for\
    \ (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n\n"
  code: "#ifndef TEMPLATE\n#define TEMPLATE 1\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <cmath>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
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
    \ {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid YES(bool b = 1) {\n    std::cout\
    \ << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n    std::cout\
    \ << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid Yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n    std::cout\
    \ << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid yes(bool b = 1) {\n    std::cout\
    \ << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n    std::cout\
    \ << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64 _ = 0; _ < (i64)(a);\
    \ ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n#define rep3(i,\
    \ a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i, a) for (i64 i =\
    \ (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define all(p)\
    \ std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n    }\n} iosetup;\n\n#ifdef KK2\n\
    std::ifstream in(\"in.txt\");\nstd::ofstream out(\"out.txt\");\n#else\n#define\
    \ in std::cin\n#define out std::cout\n#endif\n\ntemplate <class OStream, class\
    \ T, class U>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    os << p.first << ' ' << p.second;\n    return os;\n}\n\ntemplate <class IStream,\
    \ class T, class U> IStream &operator>>(IStream &is, std::pair<T, U> &p) {\n \
    \   is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <class OStream,\
    \ class T> OStream &operator<<(OStream &os, const std::vector<T> &v) {\n    for\
    \ (int i = 0; i < (int)v.size(); i++) { os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate <class IStream, class T> IStream\
    \ &operator>>(IStream &is, std::vector<T> &v) {\n    for (auto &x : v) is >> x;\n\
    \    return is;\n}\n\n#endif // TEMPLATE\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-10-08 15:42:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_math/kth_root_int.test.cpp
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/sum_of_floor_linear.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/shortest_path.test.cpp
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/matrix_det.test.cpp
  - verify/yosupo_linalg/matrix_pow.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  - verify/yosupo_linalg/matrix_product.test.cpp
  - verify/yosupo_linalg/matrix_inv.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_xor.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_and.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_convolution/convolution_or.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
