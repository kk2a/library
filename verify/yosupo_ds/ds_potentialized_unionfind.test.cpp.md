---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/potentialized.hpp
    title: unionfind/potentialized.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/yosupo_ds/ds_potentialized_unionfind.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\n\
    \n#line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n#include <type_traits>\n\n#line 1 \"type_traits/type_traits.hpp\"\
    \n\n\n\n#line 5 \"type_traits/type_traits.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                                       or\
    \ std::is_same<T, __int128>::value,\n                                        \
    \           std::true_type,\n                                                \
    \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n     \
    \                             or std::is_same<T, unsigned __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral_extended\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T>\nusing is_signed_extended =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\n\
    using is_unsigned_extended =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\n} // namespace kk2\n\
    \n\n#line 10 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\ntemplate <int p> struct\
    \ LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n    using i32\
    \ = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64\
    \ = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32 ret = p;\n  \
    \      for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return ret;\n\
    \    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32 n2 =\
    \ -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n    static_assert(p\
    \ < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"\
    invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    operator int() const { return val();\
    \ }\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n    template <typename\
    \ T, std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n    constexpr\
    \ LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static\
    \ constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * p)\
    \ >> 32; }\n\n    constexpr mint &operator++() { return *this += 1; }\n\n    constexpr\
    \ mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n    constexpr mint\
    \ operator-() const { return mint() - mint(*this); }\n\n    constexpr bool operator==(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr bool operator!=(const mint &b) const {\n\
    \        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n  \
    \  }\n\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n\n    template <class T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
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
    \ S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\nvoid Yes(bool b = 1) {\n \
    \   std::cout << (b ? \"Yes\\n\" : \"No\\n\");\n}\n\nvoid No(bool b = 1) {\n \
    \   std::cout << (b ? \"No\\n\" : \"Yes\\n\");\n}\n\nvoid YES(bool b = 1) {\n\
    \    std::cout << (b ? \"YES\\n\" : \"NO\\n\");\n}\n\nvoid NO(bool b = 1) {\n\
    \    std::cout << (b ? \"NO\\n\" : \"YES\\n\");\n}\n\nvoid yes(bool b = 1) {\n\
    \    std::cout << (b ? \"yes\\n\" : \"no\\n\");\n}\n\nvoid no(bool b = 1) {\n\
    \    std::cout << (b ? \"no\\n\" : \"yes\\n\");\n}\n\n#define rep1(a) for (i64\
    \ _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i = 0; i < (i64)(a);\
    \ ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b); ++i)\n#define repi2(i,\
    \ a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (i64 i = (a)\
    \ - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c, d, ...) d\n#define rep(...)\
    \ overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define repi(...) overload3(__VA_ARGS__,\
    \ repi3, repi2, rep1)(__VA_ARGS__)\n\n#define fi first\n#define se second\n#define\
    \ all(p) std::begin(p), std::end(p)\n\nstruct IoSetUp {\n    IoSetUp() {\n   \
    \     std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n    }\n\
    } iosetup;\n\ntemplate <class OStream, class T, class U>\nOStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << ' ' << p.second;\n  \
    \  return os;\n}\n\ntemplate <class IStream, class T, class U> IStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\n\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::vector<T> &v) {\n    for (int i = 0; i < (int)v.size(); i++) { os << v[i]\
    \ << (i + 1 == (int)v.size() ? \"\" : \" \"); }\n    return os;\n}\n\ntemplate\
    \ <class IStream, class T> IStream &operator>>(IStream &is, std::vector<T> &v)\
    \ {\n    for (auto &x : v) is >> x;\n    return is;\n}\n\n\n#line 1 \"unionfind/potentialized.hpp\"\
    \n\n\n\n#line 5 \"unionfind/potentialized.hpp\"\n\nnamespace kk2 {\n\n// require:\n\
    // A is an abelian group\n// A must have operator+ and operator-\n// A() must\
    \ return unit element\ntemplate <class A> struct PotentializedUnionfind {\n  private:\n\
    \    std::vector<int> d;\n    std::vector<A> diff_weight;\n\n  public:\n    PotentializedUnionfind(int\
    \ n = 0) : d(n, -1), diff_weight(n, A()) {}\n\n    // x -> y : w\n    bool unite(int\
    \ x, int y, A w) {\n        w = w + weight(x) - weight(y);\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (d[x] > d[y])\
    \ {\n            std::swap(x, y);\n            w = -w;\n        }\n        d[x]\
    \ += d[y];\n        d[y] = x;\n        diff_weight[y] = w;\n        return true;\n\
    \    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n        int\
    \ r = find(d[x]);\n        diff_weight[x] = diff_weight[x] + diff_weight[d[x]];\n\
    \        return d[x] = r;\n    }\n\n    bool same(int x, int y) { return find(x)\
    \ == find(y); }\n\n    int size(int x) { return -d[find(x)]; }\n\n    // root\
    \ -> x\n    A weight(int x) {\n        find(x);\n        return diff_weight[x];\n\
    \    }\n\n    // a -> b\n    A diff(int a, int b) { return -weight(a) + weight(b);\
    \ }\n};\n\ntemplate <class A, A (*op)(A, A), A (*e)(), A (*inv)(A)> struct EasyAbelianGroup\
    \ {\n    A val;\n\n    EasyAbelianGroup() : val(e()) {}\n\n    template <class...\
    \ Args> EasyAbelianGroup(Args... args) : val(args...) {}\n\n    EasyAbelianGroup\
    \ operator+(const EasyAbelianGroup &rhs) const {\n        return EasyAbelianGroup(op(val,\
    \ rhs.val));\n    }\n\n    EasyAbelianGroup operator-(const EasyAbelianGroup &rhs)\
    \ const {\n        return EasyAbelianGroup(op(val, inv(rhs.val)));\n    }\n\n\
    \    EasyAbelianGroup operator-() const { return EasyAbelianGroup(inv(val)); }\n\
    };\n\n} // namespace kk2\n\n\n#line 6 \"verify/yosupo_ds/ds_potentialized_unionfind.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n  \
    \  kk2::PotentializedUnionfind<kk2::mont998> puf(n);\n\n    rep (q) {\n      \
    \  int t;\n        cin >> t;\n        if (t == 0) {\n            int u, v;\n \
    \           kk2::mont998 w;\n            cin >> u >> v >> w;\n            if (puf.same(u,\
    \ v)) {\n                cout << (puf.diff(u, v) == w) << \"\\n\";\n         \
    \   } else {\n                cout << \"1\\n\";\n                puf.unite(u,\
    \ v, w);\n            }\n        }\n        if (t == 1) {\n            int u,\
    \ v;\n            cin >> u >> v;\n            if (puf.same(u, v)) {\n        \
    \        cout << puf.diff(u, v) << \"\\n\";\n            } else cout << \"-1\\\
    n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../unionfind/potentialized.hpp\"\nusing namespace std;\n\nint\
    \ main() {\n    int n, q;\n    cin >> n >> q;\n    kk2::PotentializedUnionfind<kk2::mont998>\
    \ puf(n);\n\n    rep (q) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int u, v;\n            kk2::mont998 w;\n            cin >>\
    \ u >> v >> w;\n            if (puf.same(u, v)) {\n                cout << (puf.diff(u,\
    \ v) == w) << \"\\n\";\n            } else {\n                cout << \"1\\n\"\
    ;\n                puf.unite(u, v, w);\n            }\n        }\n        if (t\
    \ == 1) {\n            int u, v;\n            cin >> u >> v;\n            if (puf.same(u,\
    \ v)) {\n                cout << puf.diff(u, v) << \"\\n\";\n            } else\
    \ cout << \"-1\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  - unionfind/potentialized.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-10-11 22:57:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp.html
title: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
---
