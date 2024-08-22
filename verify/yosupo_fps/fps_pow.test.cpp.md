---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_expr.hpp
    title: math_mod/pow_expr.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_rt_expr.hpp
    title: math_mod/primitive_rt_expr.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"verify/yosupo_fps/fps_pow.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n\n#line 1 \"template/template.hpp\"\
    \n\n\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n\
    #include <iostream>\n#include <iomanip>\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <iterator>\n#include <random>\n#include <type_traits>\n\
    #include <limits>\n\n#include <cstring>\n#include <string>\n#include <vector>\n\
    #include <numeric>\n#include <queue>\n#include <array>\n#include <map>\n#include\
    \ <unordered_map>\n#include <set>\n#include <unordered_set>\n#include <functional>\n\
    #include <bitset>\n#include <chrono>\n#include <stack>\n\nusing namespace std;\n\
    \nusing u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = pair<int,\
    \ int>;\nusing pl = pair<i64, i64>;\nusing pil = pair<int, i64>;\nusing pli =\
    \ pair<i64, int>;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\n\
    constexpr int infty<int> = (1 << 30) - 123;\ntemplate <>\nconstexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<i64>)\
    \ * infty<i64>;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <>\nconstexpr u64 infty<u64> = infty<i64>;\ntemplate <>\nconstexpr double infty<double>\
    \ = infty<i64>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i64>;\n\
    constexpr int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long\
    \ double PI = 3.14159265358979323846;\n\ntemplate <class T>\nusing vc = vector<T>;\n\
    template <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc\
    \ = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\ntemplate\
    \ <class T, class... Sizes>\nauto make_vector(const T &init, int first, Sizes...\
    \ sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n        return vector<T>(first,\
    \ init);\n    }\n    else {\n        return vector<decltype(make_vector(init,\
    \ sizes...))>(first, make_vector(init, sizes...));\n    }\n}\n\ntemplate <class\
    \ T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqi = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n    return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T,\
    \ class S>\ninline bool chmin(T &a, const S &b) {\n    return (a > b ? a = b,\
    \ 1 : 0);\n}\n\n# define rep1(a) for (i64 _ = 0; _ < (i64)(a); ++_)\n# define\
    \ rep2(i, a) for (i64 i = 0; i < (i64)(a); ++i)\n# define rep3(i, a, b) for (i64\
    \ i = (a); i < (i64)(b); ++i)\n# define repi2(i, a) for (i64 i = (a) - 1; i >=\
    \ 0; --i)\n# define repi3(i, a, b) for (i64 i = (a) - 1; i >= (i64)(b); --i)\n\
    # define overload3(a, b, c, d, ...) d\n# define rep(...) overload3(__VA_ARGS__,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n# define repi(...) overload3(__VA_ARGS__, repi3,\
    \ repi2, rep1)(__VA_ARGS__)\n\n# define fi first\n# define se second\n# define\
    \ all(p) begin(p), end(p)\n\nvoid YES(bool b = 1) { cout << (b ? \"YES\" : \"\
    NO\") << '\\n'; }\nvoid NO(bool b = 1) { cout << (b ? \"NO\" : \"YES\") << '\\\
    n'; }\nvoid YESflush(bool b = 1) { cout << (b ? \"YES\" : \"NO\") << endl; }\n\
    void NOflush(bool b = 1) { cout << (b ? \"NO\" : \"YES\") << endl; }\nvoid Yes(bool\
    \ b = 1) { cout << (b ? \"Yes\" : \"No\") << '\\n'; }\nvoid No(bool b = 1) { cout\
    \ << (b ? \"No\" : \"Yes\") << '\\n'; }\nvoid Yesflush(bool b = 1) { cout << (b\
    \ ? \"Yes\" : \"No\") << endl; }\nvoid Noflush(bool b = 1) { cout << (b ? \"No\"\
    \ : \"Yes\") << endl; }\nvoid yes(bool b = 1) { cout << (b ? \"yes\" : \"no\"\
    ) << '\\n'; }\nvoid no(bool b = 1) { cout << (b ? \"no\" : \"yes\") << '\\n';\
    \ }\nvoid yesflush(bool b = 1) { cout << (b ? \"yes\" : \"no\") << endl; }\nvoid\
    \ noflush(bool b = 1) { cout << (b ? \"no\" : \"yes\") << endl; }\n\n\n#line 1\
    \ \"modint/mont.hpp\"\n\n\n\ntemplate <int p>\nstruct LazyMontgomeryModInt {\n\
    \    using mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64\
    \ = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static\
    \ constexpr u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4;\
    \ ++i) ret *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr\
    \ u32 r = get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r\
    \ * p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
    \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
    \    \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n    constexpr\
    \ LazyMontgomeryModInt(const i64& b)\n         : _v(reduce(u64(b % p + p) * n2))\
    \ {}\n\n    static constexpr u32 reduce(const u64& b) {\n        return (b + u64(u32(b)\
    \ * u32(-r)) * p) >> 32;\n    }\n    constexpr mint& operator+=(const mint& b)\
    \ {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(const mint& b) {\n        if (i32(_v -=\
    \ b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n    constexpr mint& operator*=(const\
    \ mint& b) {\n        _v = reduce(u64(_v) * b._v);\n        return *this;\n  \
    \  }\n    constexpr mint& operator/=(const mint& b) {\n        *this *= b.inv();\n\
    \        return *this;\n    }\n\n    constexpr mint operator+(const mint& b) const\
    \ { return mint(*this) += b; }\n    constexpr mint operator-(const mint& b) const\
    \ { return mint(*this) -= b; }\n    constexpr mint operator-() const { return\
    \ mint() - mint(*this); }\n    constexpr mint operator*(const mint& b) const {\
    \ return mint(*this) *= b; }\n    constexpr mint operator/(const mint& b) const\
    \ { return mint(*this) /= b; }\n    constexpr bool operator==(const mint &b) const\
    \ {\n        return (_v >= p ? _v - p : _v) == (b._v >= p ? b._v - p : b._v);\n\
    \    }\n    constexpr bool operator!=(const mint &b) const {\n        return (_v\
    \ >= p ? _v - p : _v) != (b._v >= p ? b._v - p : b._v);\n    }\n\n    template\
    \ <class T>\n    constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n    constexpr\
    \ mint inv() const { return pow(p - 2); }\n\n    friend ostream& operator<<(ostream&\
    \ os, const mint& x) {\n        return os << x.val();\n    }\n    friend istream&\
    \ operator>>(istream& is, mint& x) {\n        i64 t; is >> t; x = mint(t);\n \
    \       return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n    static constexpr\
    \ u32 getmod() { return p; }\n};\n\ntemplate <int p>\nusing Mont = LazyMontgomeryModInt<p>;\n\
    \nnamespace kk2 {\n\nusing Mont998 = Mont<998244353>;\nusing Mont107 = Mont<1000000007>;\n\
    \n}  // namespace kk2\n\n\n#line 1 \"fps/ntt_friendly.hpp\"\n\n\n\n#line 1 \"\
    convolution/convolution.hpp\"\n\n\n\n#line 1 \"convolution/butterfly.hpp\"\n\n\
    \n\n#line 1 \"math_mod/primitive_rt_expr.hpp\"\n\n\n\n#line 1 \"math_mod/pow_expr.hpp\"\
    \n\n\n\nconstexpr long long pow_mod_constexpr(long long x, long long n, long long\
    \ m) {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned long\
    \ long)(m);\n    unsigned long long r = 1;\n    unsigned long long y = (x % m\
    \ + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y\
    \ = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n\n#line 5 \"math_mod/primitive_rt_expr.hpp\"\
    \n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n\
    \    if (m == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if\
    \ (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n    if (m ==\
    \ 1107296257) return 10;\n    int divs[20] = {}; \n    divs[0] = 2;\n    int cnt\
    \ = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int\
    \ i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n       \
    \     divs[cnt++] = i;\n            while (x % i == 0) {\n                x /=\
    \ i;\n            }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] =\
    \ x;\n    }\n    for (int g = 2;; g++) {\n        bool ok = true;\n        for\
    \ (int i = 0; i < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) /\
    \ divs[i], m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\ntemplate <int m>\
    \ static constexpr int primitive_root = primitive_root_constexpr(m);\n\n\n#line\
    \ 5 \"convolution/butterfly.hpp\"\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nvoid butterfly(FPS& a) {\n    static int g = primitive_root<mint::getmod()>;\n\
    \    int n = int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned\
    \ int)(n)) h++;\n    static bool first = true;\n    static mint sum_e2[30];  //\
    \ sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n    static mint sum_e3[30];\n\
    \    static mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n    if (first) {\n\
    \        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n\
    \        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n \
    \       for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n     \
    \       es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n  \
    \          ie *= ie;\n        }\n        mint now = 1;\n        for (int i = 0;\
    \ i <= cnt2 - 2; i++) {\n            sum_e2[i] = es[i] * now;\n            now\
    \ *= ies[i];\n        }\n        now = 1;\n        for (int i = 0; i <= cnt2 -\
    \ 3; i++) {\n            sum_e3[i] = es[i + 1] * now;\n            now *= ies[i\
    \ + 1];\n        }\n    }\n\n    int len = 0;\n    while (len < h) {\n       \
    \ if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n            mint\
    \ rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n             \
    \   int offset = s << (h - len);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto l = a[i + offset];\n                    auto r =\
    \ a[i + offset + p] * rot;\n                    a[i + offset] = l + r;\n     \
    \               a[i + offset + p] = l - r;\n                }\n              \
    \  if (s + 1 != (1 << len)) \n                    rot *= sum_e2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        }\n        else {\n \
    \           int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot;\n                mint rot3 = rot2 * rot;\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto a0 = a[i + offset];\n                    auto a1 = a[i + offset\
    \ + p] * rot;\n                    auto a2 = a[i + offset + p * 2] * rot2;\n \
    \                   auto a3 = a[i + offset + p * 3] * rot3;\n                \
    \    auto a1na3imag = (a1 - a3) * imag;\n                    a[i + offset] = a0\
    \ + a2 + a1 + a3;\n                    a[i + offset + p] = a0 + a2 - a1 - a3;\n\
    \                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n          \
    \          a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n                }\n \
    \               if (s + 1 != (1 << len))\n                rot *= sum_e3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvoid butterfly_inv(FPS&\
    \ a) {\n    static constexpr int g = primitive_root<mint::getmod()>;\n    int\
    \ n = int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned int)(n))\
    \ h++;\n    static bool first = true;\n    static mint sum_ie2[30];  // sum_ie[i]\
    \ = es[0] * ... * es[i - 1] * ies[i]\n    static mint sum_ie3[30];\n    static\
    \ mint es[30], ies[30];  // es[i]^(2^(2+i)) == 1\n    if (first) {\n        first\
    \ = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint\
    \ e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n        for (int\
    \ i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n            es[i - 2]\
    \ = e;\n            ies[i - 2] = ie;\n            e *= e;\n            ie *= ie;\n\
    \        }\n        mint now = 1;\n        for (int i = 0; i <= cnt2 - 2; i++)\
    \ {\n            sum_ie2[i] = ies[i] * now;\n            now *= es[i];\n     \
    \   }\n        now = 1;\n        for (int i = 0; i <= cnt2 - 3; i++) {\n     \
    \       sum_ie3[i] = ies[i + 1] * now;\n            now *= es[i + 1];\n      \
    \  }\n    }\n    int len = h;\n    while (len) {\n        if (len == 1) {\n  \
    \          int p = 1 << (h - len);\n            mint irot = 1;\n            for\
    \ (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s <<\
    \ (h - len +  1);\n                for (int i = 0; i < p; i++) {\n           \
    \         auto l = a[i + offset];\n                    auto r = a[i + offset +\
    \ p];\n                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = (l - r) * irot;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len--;\n        }\n        else {\n            int\
    \ p = 1 << (h - len);\n            mint irot = 1, iimag = ies[0];\n          \
    \  for (int s = 0; s < (1 << ((len - 2))); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = a[i + offset];\n                    auto a1\
    \ = a[i + offset + p];\n                    auto a2 = a[i + offset + p * 2];\n\
    \                    auto a3 = a[i + offset + p * 3];\n                    auto\
    \ a2na3iimag = (a2 - a3) * iimag;\n                    \n                    a[i\
    \ + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + p] = (a0\
    \ - a1 + a2na3iimag) * irot;\n                    a[i + offset + p * 2] = (a0\
    \ + a1 - a2 - a3) * irot2;\n                    a[i + offset + p * 3] = (a0 -\
    \ a1 - a2na3iimag) * irot3;\n                }\n                if (s + 1 != (1\
    \ << (len - 2)))\n                    irot *= sum_ie3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvoid doubling(FPS &a) {\n\
    \    int n = a.size();\n    auto b = a;\n    int z = 1;\n    while (z < n) z <<=\
    \ 1;\n    mint invz = mint(z).inv();\n    butterfly_inv(b); b *= invz;\n    mint\
    \ r = 1, zeta = mint(primitive_root<mint::getmod()>).\n                      \
    \ pow((mint::getmod() - 1) / (n << 1));\n    for (int i = 0; i < n; i++) {\n \
    \       b[i] *= r;\n        r *= zeta;\n    }\n    butterfly(b);\n    copy(begin(b),\
    \ end(b), back_inserter(a));\n}\n\n\n#line 5 \"convolution/convolution.hpp\"\n\
    \ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS convolution(FPS&\
    \ a, const FPS& b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n\
    \ || !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m -\
    \ 1);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0; j <\
    \ m; j++) {\n                res[i + j] += a[i] * b[j];\n            }\n     \
    \   }\n        a = res;\n        return a;\n    }\n    int z = 1;\n    while (z\
    \ < n + m - 1) z <<= 1;\n    if (a == b) {\n        a.resize(z);\n        butterfly(a);\n\
    \        for (int i = 0; i < z; i++) a[i] *= a[i];\n    }\n    else {\n      \
    \  a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(), b.end());\n \
    \       t.resize(z);\n        butterfly(t);\n        for (int i = 0; i < z; i++)\
    \ a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n    mint\
    \ iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n \
    \   return a;\n}\n\n\n#line 1 \"fps/fps.hpp\"\n\n\n\n\ntemplate <class mint>\n\
    struct FormalPowerSeries : vector<mint> {\n    using vector<mint>::vector;\n \
    \   using FPS = FormalPowerSeries;\n\n    FPS &operator+=(const FPS &r) {\n  \
    \      if (this->size() < r.size()) this->resize(r.size());\n        for (int\
    \ i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n        return *this;\n\
    \    }\n    FPS &operator+=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n    FPS &operator-=(const\
    \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n        return\
    \ *this;\n    }\n    FPS &operator-=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return *this;\n    }\n \
    \   FPS &operator*=(const mint &r) {\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            (*this)[i] *= r;\n        }\n        return *this;\n   \
    \ }\n    FPS &operator/=(const FPS &r) {\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  int n = this->size() - r.size() + 1;\n        if ((int)r.size() <= 64) {\n\
    \            FPS f(*this), g(r);\n            g.shrink();\n            mint coeff\
    \ = g.back().inv();\n            for (auto &x : g) x *= coeff;\n            int\
    \ deg = (int)f.size() - (int)g.size() + 1;\n            int gs = g.size();\n \
    \           FPS quo(deg);\n            for (int i = deg - 1; i >= 0; i--) {\n\
    \                quo[i] = f[i + gs - 1];\n                for (int j = 0; j <\
    \ gs; j++) f[i + j] -= quo[i] * g[j];\n            }\n            *this = quo\
    \ * coeff;\n            this->resize(n, mint(0));\n            return *this;\n\
    \        }\n        return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\
    \        \n    }\n    FPS &operator%=(const FPS &r) {\n        *this -= *this\
    \ / r * r;\n        shrink();\n        return *this;\n    }\n\n    FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n    FPS operator+(const mint &r)\
    \ const { return FPS(*this) += r; }\n    FPS operator-(const FPS &r) const { return\
    \ FPS(*this) -= r; }\n    FPS operator-(const mint &r) const { return FPS(*this)\
    \ -= r; }\n    FPS operator*(const mint &r) const { return FPS(*this) *= r; }\n\
    \    FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n    FPS operator%(const\
    \ FPS &r) const { return FPS(*this) %= r; }\n    FPS operator-() const {\n   \
    \     FPS ret(this->size());\n        for (int i = 0; i < (int)this->size(); i++)\
    \ ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    FPS shrink() {\n  \
    \      while (this->size() && this->back() == mint(0)) this->pop_back();\n   \
    \     return *this;\n    }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n    FPS\
    \ inplace_rev() {\n        reverse(this->begin(), this->end());\n        return\
    \ *this;\n    }\n\n    FPS dot(const FPS &r) const {\n        FPS ret(min(this->size(),\
    \ r.size()));\n        for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n        return ret;\n    }\n\n    FPS inplace_dot(const FPS &r) {\n\
    \        this->resize(min(this->size(), r.size()));\n        for (int i = 0; i\
    \ < (int)this->size(); i++) (*this)[i] *= r[i];\n        return *this;\n    }\n\
    \n    FPS pre(int n) const {\n        FPS ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ n));\n        if ((int)ret.size() < n) ret.resize(n, mint(0));\n        return\
    \ ret;\n    }\n\n    FPS inplace_pre(int n) {\n        this->resize(n);\n    \
    \    return *this;\n    }\n\n    FPS operator>>(int n) const {\n        if (n\
    \ >= (int)this->size()) return {};\n        FPS ret(begin(*this) + n, end(*this));\n\
    \        return ret;\n    }\n    FPS operator<<(int n) const {\n        FPS ret(*this);\n\
    \        ret.insert(begin(ret), n, mint(0));\n        return ret;\n    }\n\n \
    \   FPS diff() const {\n        const int n = (int)this->size();\n        FPS\
    \ ret(max(0, n - 1));\n        for (int i = 1; i < n; i++) {\n            ret[i\
    \ - 1] = (*this)[i] * mint(i);\n        }\n        return ret;\n    }\n\n    FPS\
    \ inplace_diff() {\n        if (this->empty()) return {};\n        this->erase(this->begin());\n\
    \        for (int i = 1; i <= (int)this->size(); i++)\n            (*this)[i -\
    \ 1] *= mint(i);\n        return *this;\n    }\n\n    FPS integral() const {\n\
    \        const int n = (int)this->size();\n        FPS ret(n + 1);\n        ret[0]\
    \ = mint(0);\n        if (n > 0) ret[1] = mint(1);\n        auto mod = mint::getmod();\n\
    \        for (int i = 2; i <= n; i++) {\n            // p = q * i + r\n      \
    \      // - q / r = 1 / i (mod p)\n            ret[i] = (-ret[mod % i]) * (mod\
    \ / i);\n        }\n        for (int i = 0; i < n; i++) {\n            ret[i +\
    \ 1] *= (*this)[i];\n        }\n        return ret;\n    }\n\n    FPS inplace_int()\
    \ {\n        static vector<mint> inv{0, 1};\n        const int n = this->size();\n\
    \        auto mod = mint::getmod();\n        while ((int)inv.size() <= n) {\n\
    \            // p = q * i + r\n            // - q / r = 1 / i (mod p)\n      \
    \      int i = inv.size();\n            inv.push_back((-inv[mod % i]) * (mod /\
    \ i));\n        }\n        this->insert(this->begin(), mint(0));\n        for\
    \ (int i = 1; i <= n; i++) (*this)[i] *= inv[i];\n        return *this;\n    }\n\
    \n    mint eval(mint x) const {\n        mint r = 0, w = 1;\n        for (auto\
    \ &v : *this) {\n            r += w * v;\n            w *= x;\n        }\n   \
    \     return r;\n    }\n\n    FPS log(int deg = -1) const {\n        assert(!this->empty()\
    \ && (*this)[0] == mint(1));\n        if (deg == -1) deg = this->size();\n   \
    \     return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n    }\n\
    \n    FPS sparse_log(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ == mint(1));\n        if (deg == -1) deg = this->size();\n        vector<pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\n\
    \        int mod = mint::getmod();\n        static vector<mint> inv{1, 1};\n \
    \       while ((int)inv.size() <= deg) {\n            int i = inv.size();\n  \
    \          inv.push_back(-inv[mod % i] * (mod / i));\n        }\n\n        FPS\
    \ g(deg);\n        for (int k = 0; k < deg - 1; k++) {\n            for (auto\
    \ &[j, fj] : fs) {\n                if (k < j) break;\n                int i =\
    \ k - j;\n                g[k + 1] -= g[i + 1] * fj * (i + 1);\n            }\n\
    \            g[k + 1] *= inv[k + 1];\n            if (k + 1 < int(this->size()))\
    \ g[k + 1] += (*this)[k + 1];\n        }\n\n        return g;\n    }\n\n    template\
    \ <class T>\n    FPS pow(T k, int deg = -1) const {\n        const int n = this->size();\n\
    \        if (deg == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n\
    \            if (deg > 0) ret[0] = mint(1);\n            return ret;\n       \
    \ }\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0))\
    \ {\n                mint rev = mint(1) / (*this)[i];\n                FPS ret\
    \ = (((*this * rev) >> i).log(deg) * k).exp(deg);\n                ret *= (*this)[i].pow(k);\n\
    \                ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n                return ret;\n            }\n\
    \            if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \     }\n        return FPS(deg, mint(0));\n    }\n\n    template <class T>\n\
    \    FPS sparse_pow(T k, int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        if (k == 0) {\n            FPS ret(deg);\n            if (deg > 0) ret[0]\
    \ = mint(1);\n            return ret;\n        }\n\n        int zero = 0;\n  \
    \      while (zero != int(this->size()) &&\n               (*this)[zero] == mint(0))\
    \ zero++;\n        if (zero == int(this->size()) ||\n            __int128_t(zero)\
    \ * k >= deg) {\n            return FPS(deg, mint(0));\n        }\n        if\
    \ (zero != 0) {\n            FPS suf(this->begin() + zero, this->end());\n   \
    \         auto g = suf.sparse_pow(k, deg - zero * k);\n            FPS ret(zero\
    \ * k, mint(0));\n            copy(begin(g), end(g), back_inserter(ret));\n  \
    \          return ret;\n        }\n\n        int mod = mint::getmod();\n     \
    \   static vector<mint> inv{1, 1};\n        while ((int)inv.size() <= deg) {\n\
    \            int i = inv.size();\n            inv.push_back(-inv[mod % i] * (mod\
    \ / i));\n        }\n\n        vector<pair<int, mint>> fs;\n        for (int i\
    \ = 1; i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        FPS g(deg);\n        g[0] = (*this)[0].pow(k);\n\
    \        mint denom = (*this)[0].inv();\n        k %= mod;\n        for (int a\
    \ = 1; a < deg; a++) {\n            for (auto& [i, f_i] : fs) {\n            \
    \    if (a < i) break;\n                g[a] += g[a - i] * f_i * (mint(i) * (k\
    \ + 1) - a);\n            }\n            g[a] *= denom * inv[a];\n        }\n\
    \        return g;\n    }\n\n    // assume that r is sparse\n    // return this\
    \ / r\n    FPS sparse_div(const FPS &r, int deg = -1) const {\n        assert(!r.empty()\
    \ && r[0] != mint(0));\n        if (deg == -1) deg = this->size();\n        mint\
    \ ir0 = r[0].inv();\n        FPS ret = *this * ir0;\n        ret.resize(deg);\n\
    \        vector<pair<int, mint>> gs;\n        for (int i = 1; i < (int)r.size();\
    \ i++) {\n            if (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);\n \
    \       }\n        for (int i = 0; i < deg; i++) {\n            for (auto &[j,\
    \ g_j] : gs) {\n                if (i + j >= deg) break;\n                ret[i\
    \ + j] -= ret[i] * g_j;\n            }\n        }\n        return ret;\n    }\n\
    \n    FPS sparse_inv(int deg = -1) const {\n        assert(!this->empty() && (*this)[0]\
    \ != mint(0));\n        if (deg == -1) deg = this->size();\n        vector<pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n \
    \       FPS ret(deg);\n        mint if0 = (*this)[0].inv();\n        if (0 < deg)\
    \ ret[0] = if0;\n        for (int k = 1; k < deg; k++) {\n            for (auto\
    \ &[j, fj] : fs) {\n                if (k < j) break;\n                ret[k]\
    \ += ret[k - j] * fj;\n            }\n            ret[k] *= -if0;\n        }\n\
    \        return ret;\n    }\n\n    FPS sparse_exp(int deg = -1) const {\n    \
    \    assert(this->empty() || (*this)[0] == mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        vector<pair<int, mint>> fs;\n        for (int i = 1;\
    \ i < int(this->size()); i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        int mod = mint::getmod();\n        static\
    \ vector<mint> inv{1, 1};\n        while ((int)inv.size() <= deg) {\n        \
    \    int i = inv.size();\n            inv.push_back(-inv[mod % i] * (mod / i));\n\
    \        }\n\n        FPS g(deg);\n        if (deg) g[0] = 1;\n        for (int\
    \ k = 0; k < deg - 1; k++) {\n            for (auto &[ip1, fip1] : fs) {\n   \
    \             int i = ip1 - 1;\n                if (k < i) break;\n          \
    \      g[k + 1] += g[k - i] * fip1 * (i + 1);\n            }\n            g[k\
    \ + 1] *= inv[k + 1];\n        }\n\n        return g;\n    }\n\n    FPS inplace_imos(int\
    \ n) {\n        inplace_pre(n);\n        for (int i = 0; i < n - 1; i++) {\n \
    \           (*this)[i + 1] += (*this)[i];\n        }\n        return *this;\n\
    \    }\n\n    FPS imos(int n) const {\n        FPS ret(*this);\n        return\
    \ ret.inplace_imos(n);\n    }\n\n    FPS inplace_iimos(int n) {\n        inplace_pre(n);\n\
    \        for (int i = 0; i < n - 1; i++) {\n            (*this)[i + 1] -= (*this)[i];\n\
    \        }\n        return *this;\n    }\n\n    FPS iimos(int n) const {\n   \
    \     FPS ret(*this);\n        return ret.inplace_iimos(n);\n    }\n\n    FPS\
    \ &operator*=(const FPS &r);\n    FPS operator*(const FPS &r) const { return FPS(*this)\
    \ *= r; }\n    void but();\n    void ibut();\n    void db();\n    static int but_pr();\n\
    \    FPS inv(int deg = -1) const;\n    FPS exp(int deg = -1) const;\n};\n\nnamespace\
    \ kk2 {\n    template <class mint>\n    using FPS = FormalPowerSeries<mint>;\n\
    }\n\n\n#line 6 \"fps/ntt_friendly.hpp\"\n\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ &FormalPowerSeries<mint>::operator*=(\n        const FormalPowerSeries<mint>\
    \ &r) {\n    if (this->empty() || r.empty()) {\n        this->clear();\n     \
    \   return *this;\n    }\n    convolution(*this, r);\n    return *this;\n}\n\n\
    template <class mint> \nvoid FormalPowerSeries<mint>::but() {\n    butterfly(*this);\n\
    }\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::ibut() {\n    butterfly_inv(*this);\n\
    }\n\ntemplate <class mint>\nvoid FormalPowerSeries<mint>::db() {\n    doubling(*this);\n\
    }\n\ntemplate <class mint>\nint FormalPowerSeries<mint>::but_pr() {\n    return\
    \ primitive_root<mint::getmod()>;\n}\n\ntemplate <class mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::inv(int deg) const {\n    assert((*this)[0] != mint(0));\n\
    \    if (deg == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> res(deg);\n\
    \    res[0] = {mint(1) / (*this)[0]};\n    auto ind = mint{2}.inv(), intwo = mint{2}.inv();\n\
    \    for (int d = 1; d < deg; d <<= 1) {\n        FormalPowerSeries<mint> f(2\
    \ * d), g(2 * d);\n        copy(begin(*this), begin(*this) + min((int)this->size(),\
    \ 2 * d), begin(f));\n        copy(begin(res), begin(res) + d, begin(g));\n  \
    \      f.but(); g.but();\n        f.inplace_dot(g);\n        f.ibut(); f *= ind;\n\
    \        fill(begin(f), begin(f) + d, mint(0));\n        f.but();\n        f.inplace_dot(g);\n\
    \        f.ibut(); f *= ind;\n        for (int j = d; j < min(2 * d, deg); j++)\
    \ res[j] = -f[j];\n        ind *= intwo;\n    }\n    return res.pre(deg);\n}\n\
    \ntemplate <class mint>\nFormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n    assert(this->empty() || (*this)[0] == mint(0));\n    if (deg\
    \ == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> inv;\n    inv.reserve(deg\
    \ + 1);\n    inv.push_back(mint(0));\n    inv.push_back(mint(1));\n\n    FormalPowerSeries<mint>\
    \ b{1, 1 < (int)this->size() ?\n                              (*this)[1] : mint(0)};\n\
    \    FormalPowerSeries<mint> c{1}, z1, z2{1, 1};\n    mint im = mint{2}.inv(),\
    \ intwo = mint{2}.inv();\n    for (int m = 2; m < deg; m <<= 1) {\n        auto\
    \ y = b;\n        y.resize(m << 1);\n        y.but();\n        z1 = z2;\n    \
    \    FormalPowerSeries<mint> z(m);\n        z = y.dot(z1);\n        z.ibut();\
    \ z *= im;\n        fill(begin(z), begin(z) + (m >> 1), mint(0));\n        z.but();\
    \ z.inplace_dot(-z1);\n        z.ibut(); z *= im;\n        c.insert(end(c), begin(z)\
    \ + (m >> 1), end(z));\n        z2 = c;\n        z2.resize(m << 1);\n        z2.but();\n\
    \n        FormalPowerSeries<mint> x(begin(*this), begin(*this) +\n           \
    \                       min<int>(this->size(), m));\n        x.resize(m);\n  \
    \      x.inplace_diff();\n        x.push_back(mint(0));\n        x.but();\n  \
    \      x.inplace_dot(y);\n        x.ibut(); x *= im;\n        x -= b.diff();\n\
    \        x.resize(m << 1);\n        for (int i = 0; i < m - 1; i++) {\n      \
    \      x[m + i] = x[i];\n            x[i] = mint(0);\n        }\n        x.but();\n\
    \        x.inplace_dot(z2);\n        x.ibut(); x *= im * intwo;\n        x.pop_back();\n\
    \        x.inplace_int();\n        for (int i = m; i < min<int>(this->size(),m\
    \ << 1); i++)\n            x[i] += (*this)[i];\n        fill(begin(x), begin(x)\
    \ + m, mint(0));\n        x.but();\n        x.inplace_dot(y);\n        x.ibut();\
    \ x *= im * intwo;\n        b.insert(end(b), begin(x) + m, end(x));\n        im\
    \ *= intwo;\n    }\n    return FormalPowerSeries<mint>(begin(b), begin(b) + deg);\n\
    }\n\n\n\n#line 6 \"verify/yosupo_fps/fps_pow.test.cpp\"\n\nusing mint = Mont<mod>;\n\
    using FPS = FormalPowerSeries<mint>;\n\nint main () {\n    int n;\n    long long\
    \ m;\n    cin >> n >> m;\n    FPS f(n);\n    rep (i, n) cin >> f[i];\n    auto\
    \ g = f.pow(m);\n    for (auto v : g) cout << v << \" \";\n    cout << endl;\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../fps/ntt_friendly.hpp\"\n\nusing mint = Mont<mod>;\nusing FPS\
    \ = FormalPowerSeries<mint>;\n\nint main () {\n    int n;\n    long long m;\n\
    \    cin >> n >> m;\n    FPS f(n);\n    rep (i, n) cin >> f[i];\n    auto g =\
    \ f.pow(m);\n    for (auto v : g) cout << v << \" \";\n    cout << endl;\n\n \
    \   return 0;\n}"
  dependsOn:
  - template/template.hpp
  - modint/mont.hpp
  - fps/ntt_friendly.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_rt_expr.hpp
  - math_mod/pow_expr.hpp
  - fps/fps.hpp
  isVerificationFile: true
  path: verify/yosupo_fps/fps_pow.test.cpp
  requiredBy: []
  timestamp: '2024-08-22 19:31:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_fps/fps_pow.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_fps/fps_pow.test.cpp
- /verify/verify/yosupo_fps/fps_pow.test.cpp.html
title: verify/yosupo_fps/fps_pow.test.cpp
---
