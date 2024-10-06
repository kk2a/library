---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/bitxor1.hpp
    title: convolution/bitxor1.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/walsh_hadamard_transform.hpp
    title: convolution/walsh_hadamard_transform.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"verify/yosupo_convolution/convolution_xor.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#line\
    \ 1 \"convolution/bitxor1.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"convolution/walsh_hadamard_transform.hpp\"\
    \n\n\n\n#line 5 \"convolution/walsh_hadamard_transform.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <class FPS> void WalshHadamardTransform(FPS &a) {\n    int n =\
    \ int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for (int\
    \ i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n          \
    \  if ((i & j) != 0) {\n                auto x = a[j], y = a[i ^ j];\n       \
    \         a[j] = -x + y, a[i ^ j] = x + y;\n            }\n        }\n    }\n\
    }\n\ntemplate <class FPS> void InverseWalshHadamardTransform(FPS &a) {\n    int\
    \ n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for\
    \ (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n     \
    \       if ((i & j) != 0) {\n                auto x = a[j], y = a[i ^ j];\n  \
    \              a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n            }\n \
    \       }\n    }\n}\n\n} // namespace kk2\n\n\n#line 7 \"convolution/bitxor1.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS>\nFPS convolution_xor(FPS &a, const\
    \ FPS &b) {\n    assert(size(a) == size(b));\n    int n = int(size(a)); // ==\
    \ int(size(b)\n    if (!n) return {};\n    assert((n & -n) == n);\n    FPS c(b.begin(),\
    \ b.end());\n\n    WalshHadamardTransform(a);\n    WalshHadamardTransform(c);\n\
    \    for (int i = 0; i < n; i++) a[i] *= c[i];\n    InverseWalshHadamardTransform(a);\n\
    \n    return a;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\
    \n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n#include <iostream>\n#include\
    \ <type_traits>\n\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#line 5 \"type_traits/type_traits.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value\n                      \
    \                                 or std::is_same<T, __int128>::value,\n     \
    \                                              std::true_type,\n             \
    \                                      std::false_type>::type;\n\ntemplate <typename\
    \ T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T>\nusing\
    \ is_integral_extended =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed_extended =\n\
    \    typename std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_extended\
    \ =\n    typename std::conditional<std::is_unsigned<T>::value or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 10 \"modint/mont.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using\
    \ mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
    \ u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4; ++i) ret\
    \ *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr u32 r =\
    \ get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r *\
    \ p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
    \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
    \n    u32 _v;\n\n    operator int() const { return val(); }\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p\
    \ + p) * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) { return (b\
    \ + u64(u32(b) * u32(-r)) * p) >> 32; }\n\n    constexpr mint &operator++() {\
    \ return *this += 1; }\n\n    constexpr mint &operator--() { return *this -= 1;\
    \ }\n\n    constexpr mint operator++(int) {\n        mint ret = *this;\n     \
    \   *this += 1;\n        return ret;\n    }\n\n    constexpr mint operator--(int)\
    \ {\n        mint ret = *this;\n        *this -= 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint &operator+=(const mint &b) {\n        if (i32(_v +=\
    \ b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator-=(const mint &b) {\n        if (i32(_v -= b._v) < 0) _v += 2\
    \ * p;\n        return *this;\n    }\n\n    constexpr mint &operator*=(const mint\
    \ &b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n    }\n\n\
    \    constexpr mint &operator/=(const mint &b) {\n        *this *= b.inv();\n\
    \        return *this;\n    }\n\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n\n    constexpr bool operator!=(const mint &b) const {\n        return\
    \ (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n\n    friend\
    \ constexpr mint operator+(const mint &a, const mint &b) { return mint(a) += b;\
    \ }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(const mint &a, T b) {\n  \
    \      return mint(a) += mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(T a, const mint &b) {\n  \
    \      return mint(a) += b;\n    }\n\n    friend constexpr mint operator-(const\
    \ mint &a, const mint &b) { return mint(a) -= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(const mint &a, T b) {\n  \
    \      return mint(a) -= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(T a, const mint &b) {\n  \
    \      return mint(a) -= b;\n    }\n\n    friend constexpr mint operator*(const\
    \ mint &a, const mint &b) { return mint(a) *= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(const mint &a, T b) {\n  \
    \      return mint(a) *= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(T a, const mint &b) {\n  \
    \      return mint(a) *= b;\n    }\n\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(const mint &a, T b) {\n  \
    \      return mint(a) /= mint(b);\n    }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(T a, const mint &b) {\n  \
    \      return mint(a) /= b;\n    }\n\n    template <class T> constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &x) { return os << x.val(); }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \n\nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include <chrono>\n\
    #include <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi\
    \ = std::pair<int, int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int,\
    \ i64>;\nusing pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate <class\
    \ T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int> = (1 << 30)\
    \ - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll << 31);\n\
    template <> constexpr i128 infty<i128> = (i128(1) << 126) - (i128(1) << 63);\n\
    template <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <> constexpr u128 infty<u128> = infty<i128>;\n\
    template <> constexpr double infty<double> = infty<i64>;\ntemplate <> constexpr\
    \ long double infty<long double> = infty<i64>;\n\nconstexpr int mod = 998244353;\n\
    constexpr int modu = 1e9 + 7;\nconstexpr long double PI = 3.14159265358979323846;\n\
    \nnamespace kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(int first,\
    \ Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return\
    \ std::vector<T>(first);\n    } else {\n        return std::vector<decltype(make_vector(sizes...))>(first,\
    \ make_vector(sizes...));\n    }\n}\n\ntemplate <class T, class U> void fill_all(std::vector<T>\
    \ &v, const U &x) {\n    std::fill(std::begin(v), std::end(v), T(x));\n}\n\ntemplate\
    \ <class T, class U> void fill_all(std::vector<std::vector<T>> &v, const U &x)\
    \ {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace kk2\n\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) {\n    return (a < b\
    \ ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool chmin(T &a, const\
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid YES(bool b = 1) {\n \
    \   std::cout << (b ? \"YES\" : \"NO\") << '\\n';\n}\n\nvoid NO(bool b = 1) {\n\
    \    std::cout << (b ? \"NO\" : \"YES\") << '\\n';\n}\n\nvoid Yes(bool b = 1)\
    \ {\n    std::cout << (b ? \"Yes\" : \"No\") << '\\n';\n}\n\nvoid No(bool b =\
    \ 1) {\n    std::cout << (b ? \"No\" : \"Yes\") << '\\n';\n}\n\nvoid yes(bool\
    \ b = 1) {\n    std::cout << (b ? \"yes\" : \"no\") << '\\n';\n}\n\nvoid no(bool\
    \ b = 1) {\n    std::cout << (b ? \"no\" : \"yes\") << '\\n';\n}\n\n#define rep1(a)\
    \ for (i64 _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
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
    }\n\n\n#line 6 \"verify/yosupo_convolution/convolution_xor.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int n;\n    cin >> n;\n    vc<kk2::mont998> a(1 <<\
    \ n), b(1 << n);\n    cin >> a >> b;\n    cout << kk2::convolution_xor(a, b) <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../../convolution/bitxor1.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vc<kk2::mont998> a(1 << n), b(1 << n);\n \
    \   cin >> a >> b;\n    cout << kk2::convolution_xor(a, b) << endl;\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - convolution/bitxor1.hpp
  - convolution/walsh_hadamard_transform.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_xor.test.cpp
  requiredBy: []
  timestamp: '2024-10-07 04:00:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_xor.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_xor.test.cpp
- /verify/verify/yosupo_convolution/convolution_xor.test.cpp.html
title: verify/yosupo_convolution/convolution_xor.test.cpp
---
