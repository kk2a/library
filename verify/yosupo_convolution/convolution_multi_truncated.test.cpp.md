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
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution
  bundledCode: "#line 1 \"verify/yosupo_convolution/convolution_multi_truncated.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution\"\
    \ \n\n#line 1 \"convolution/multi_convolution_truncated.hpp\"\n\n\n\n#include\
    \ <vector>\n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"convolution/convolution.hpp\"\n\n#line 1 \"convolution/butterfly.hpp\"\
    \n\n\n\n#line 5 \"convolution/butterfly.hpp\"\n\n#line 1 \"math_mod/primitive_root.hpp\"\
    \n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\n#line 1\
    \ \"type_traits/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace kk2\
    \ {\n\ntemplate <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
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
    \n\n#line 7 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class S,\
    \ class T, class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(!is_signed_extended<U>::value\
    \ || n >= 0);\n    if (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y\
    \ = S(x) % _m;\n    if (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r\
    \ = (r * y) % _m;\n        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return\
    \ r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\n\
    namespace kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m\
    \ == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0]\
    \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
    \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x % i\
    \ == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) { x /=\
    \ i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for (int g\
    \ = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) == 1) {\n   \
    \             ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\n#line\
    \ 7 \"convolution/butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type> void butterfly(FPS &a) {\n    static int g\
    \ = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n    int h = 0;\n\
    \    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool first = true;\n\
    \    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n\
    \    static mint sum_e3[30];\n    static mint es[30], ies[30]; // es[i]^(2^(2+i))\
    \ == 1\n    if (first) {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod()\
    \ - 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
    \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n    \
    \        es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n \
    \           ie *= ie;\n        }\n        mint now = 1;\n        for (int i =\
    \ 0; i <= cnt2 - 2; i++) {\n            sum_e2[i] = es[i] * now;\n           \
    \ now *= ies[i];\n        }\n        now = 1;\n        for (int i = 0; i <= cnt2\
    \ - 3; i++) {\n            sum_e3[i] = es[i + 1] * now;\n            now *= ies[i\
    \ + 1];\n        }\n    }\n\n    int len = 0;\n    while (len < h) {\n       \
    \ if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n            mint\
    \ rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n             \
    \   int offset = s << (h - len);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto l = a[i + offset];\n                    auto r =\
    \ a[i + offset + p] * rot;\n                    a[i + offset] = l + r;\n     \
    \               a[i + offset + p] = l - r;\n                }\n              \
    \  if (s + 1 != (1 << len)) rot *= sum_e2[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len++;\n        } else {\n            int p = 1 <<\
    \ (h - len - 2);\n            mint rot = 1, imag = es[0];\n            for (int\
    \ s = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n    \
    \            mint rot3 = rot2 * rot;\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    auto a0 =\
    \ a[i + offset];\n                    auto a1 = a[i + offset + p] * rot;\n   \
    \                 auto a2 = a[i + offset + p * 2] * rot2;\n                  \
    \  auto a3 = a[i + offset + p * 3] * rot3;\n                    auto a1na3imag\
    \ = (a1 - a3) * imag;\n                    a[i + offset] = a0 + a2 + a1 + a3;\n\
    \                    a[i + offset + p] = a0 + a2 - a1 - a3;\n                \
    \    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n                    a[i + offset\
    \ + p * 3] = a0 - a2 - a1na3imag;\n                }\n                if (s +\
    \ 1 != (1 << len)) rot *= sum_e3[__builtin_ctz(~(unsigned int)(s))];\n       \
    \     }\n            len += 2;\n        }\n    }\n}\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type> void butterfly_inv(FPS &a) {\n    static constexpr\
    \ int g = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n    int\
    \ h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool first\
    \ = true;\n    static mint sum_ie2[30]; // sum_ie[i] = es[0] * ... * es[i - 1]\
    \ * ies[i]\n    static mint sum_ie3[30];\n    static mint es[30], ies[30]; //\
    \ es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n    if (first) {\n        first\
    \ = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint\
    \ e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n        for (int\
    \ i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n            es[i - 2]\
    \ = e;\n            ies[i - 2] = ie;\n            e *= e;\n            ie *= ie;\n\
    \        }\n        mint now = 1;\n        for (int i = 0; i <= cnt2 - 2; i++)\
    \ {\n            sum_ie2[i] = ies[i] * now;\n            now *= es[i];\n     \
    \   }\n        now = 1;\n        for (int i = 0; i <= cnt2 - 3; i++) {\n     \
    \       sum_ie3[i] = ies[i + 1] * now;\n            now *= es[i + 1];\n      \
    \  }\n\n        invn[0] = 1;\n        invn[1] = mint::getmod() / 2 + 1;\n    \
    \    for (int i = 2; i < 30; i++) invn[i] = invn[i - 1] * invn[1];\n    }\n  \
    \  int len = h;\n    while (len) {\n        if (len == 1) {\n            int p\
    \ = 1 << (h - len);\n            mint irot = 1;\n            for (int s = 0; s\
    \ < (1 << (len - 1)); s++) {\n                int offset = s << (h - len + 1);\n\
    \                for (int i = 0; i < p; i++) {\n                    auto l = a[i\
    \ + offset];\n                    auto r = a[i + offset + p];\n              \
    \      a[i + offset] = l + r;\n                    a[i + offset + p] = (l - r)\
    \ * irot;\n                }\n                if (s + 1 != (1 << (len - 1))) irot\
    \ *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];\n            }\n            len--;\n\
    \        } else {\n            int p = 1 << (h - len);\n            mint irot\
    \ = 1, iimag = ies[0];\n            for (int s = 0; s < (1 << ((len - 2))); s++)\
    \ {\n                mint irot2 = irot * irot;\n                mint irot3 = irot2\
    \ * irot;\n                int offset = s << (h - len + 2);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto a0 = a[i + offset];\n  \
    \                  auto a1 = a[i + offset + p];\n                    auto a2 =\
    \ a[i + offset + p * 2];\n                    auto a3 = a[i + offset + p * 3];\n\
    \                    auto a2na3iimag = (a2 - a3) * iimag;\n\n                \
    \    a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + p]\
    \ = (a0 - a1 + a2na3iimag) * irot;\n                    a[i + offset + p * 2]\
    \ = (a0 + a1 - a2 - a3) * irot2;\n                    a[i + offset + p * 3] =\
    \ (a0 - a1 - a2na3iimag) * irot3;\n                }\n                if (s +\
    \ 1 != (1 << (len - 2))) irot *= sum_ie3[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len -= 2;\n        }\n    }\n\n    for (int i = 0;\
    \ i < n; i++) a[i] *= invn[h];\n}\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type> void doubling(FPS &a) {\n    int n = a.size();\n    auto b\
    \ = a;\n    int z = 1;\n    butterfly_inv(b);\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>).pow((mint::getmod()\
    \ - 1) / (n << 1));\n    for (int i = 0; i < n; i++) {\n        b[i] *= r;\n \
    \       r *= zeta;\n    }\n    butterfly(b);\n    std::copy(b.begin(), b.end(),\
    \ std::back_inserter(a));\n}\n\n} // namespace kk2\n\n\n#line 8 \"convolution/convolution.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\
    \ FPS convolution(FPS &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n\
    \ + m - 1);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0;\
    \ j < m; j++) { res[i + j] += a[i] * b[j]; }\n        }\n        a = res;\n  \
    \      return a;\n    }\n    int z = 1;\n    while (z < n + m - 1) z <<= 1;\n\
    \    if (a == b) {\n        a.resize(z);\n        butterfly(a);\n        for (int\
    \ i = 0; i < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n     \
    \   butterfly(a);\n        FPS t(b.begin(), b.end());\n        t.resize(z);\n\
    \        butterfly(t);\n        for (int i = 0; i < z; i++) a[i] *= t[i];\n  \
    \  }\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n    return a;\n}\n\n} //\
    \ namespace kk2\n\n\n#line 7 \"convolution/multi_convolution_truncated.hpp\"\n\
    \nnamespace kk2 {\n\n// reference: https://rushcheyo.blog.uoj.ac/blog/6547\n//\
    \ \u65E5\u672C\u8A9E:\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS multi_convolution_truncated(FPS\
    \ &a, const FPS &b, const std::vector<int> &base) {\n    int n = int(a.size());\n\
    \    if (!n) return {};\n    int k = base.size();\n    if (!k) return convolution(a,\
    \ b);\n    // chi[i] = \\sum_{j} \\floor(i / (base[0]...base[j]))\n    std::vector<int>\
    \ chi(n, 0);\n    for (int i = 0; i < n; i++) {\n        int x = i;\n        for\
    \ (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        chi[i] %= k;\n\
    \    }\n    int z = 1;\n    while (z < 2 * n - 1) z <<= 1;\n    std::vector<FPS>\
    \ f(k, FPS(z));\n    std::vector<FPS> g(k, FPS(z));\n    for (int i = 0; i < n;\
    \ i++) f[chi[i]][i] = a[i], g[chi[i]][i] = b[i];\n    for (auto &x : f) butterfly(x);\n\
    \    for (auto &x : g) butterfly(x);\n    std::vector<mint> tmp(k);\n    for (int\
    \ ii = 0; ii < z; ii++) {\n        for (int i = 0; i < k; i++) {\n           \
    \ for (int j = 0; j < k; j++) {\n                tmp[i + j - (i + j >= k ? k :\
    \ 0)] += f[i][ii] * g[j][ii];\n            }\n        }\n        for (int i =\
    \ 0; i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};\n    }\n    for (auto &x\
    \ : f) butterfly_inv(x);\n    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i];\n\
    \    return a;\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\
    \n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n#include <iostream>\n#line\
    \ 8 \"modint/mont.hpp\"\n\n#line 10 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
    template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
    \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
    \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return\
    \ ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32\
    \ n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n\
    \    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
    \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    operator int() const\
    \ { return val(); }\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n   \
    \ template <typename T, std::enable_if_t<kk2::is_integral_extended<T>::value>\
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
    O3,unroll-loops\")\n\n// #include <bits/stdc++.h>\n#line 8 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 11 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#line 19 \"template/template.hpp\"\n\
    #include <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <string>\n#include <tuple>\n#line 32 \"template/template.hpp\"\
    \n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 36 \"template/template.hpp\"\n\nusing u32 = unsigned int;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\n\nusing pi = std::pair<int, int>;\nusing pl = std::pair<i64,\
    \ i64>;\nusing pil = std::pair<int, i64>;\nusing pli = std::pair<i64, int>;\n\n\
    template <class T> constexpr T infty = 0;\ntemplate <> constexpr int infty<int>\
    \ = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64> = (1ll << 62) - (1ll\
    \ << 31);\ntemplate <> constexpr i128 infty<i128> = i128(infty<i64>) * infty<i64>;\n\
    template <> constexpr u32 infty<u32> = infty<int>;\ntemplate <> constexpr u64\
    \ infty<u64> = infty<i64>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\nnamespace\
    \ kk2 {\n\ntemplate <class T, class... Sizes> auto make_vector(const T &init,\
    \ int first, Sizes... sizes) {\n    if constexpr (sizeof...(sizes) == 0) {\n \
    \       return std::vector<T>(first, init);\n    } else {\n        return std::vector<decltype(make_vector(init,\
    \ sizes...))>(first,\n                                                       \
    \           make_vector(init, sizes...));\n    }\n}\n\ntemplate <class T, class\
    \ U> void fill_all(std::vector<T> &v, const U &x) {\n    std::fill(std::begin(v),\
    \ std::end(v), T(x));\n}\n\ntemplate <class T, class U> void fill_all(std::vector<std::vector<T>>\
    \ &v, const U &x) {\n    for (auto &u : v) fill_all(u, x);\n}\n\n} // namespace\
    \ kk2\n\ntemplate <class T, class S> inline bool chmax(T &a, const S &b) {\n \
    \   return (a < b ? a = b, 1 : 0);\n}\n\ntemplate <class T, class S> inline bool\
    \ chmin(T &a, const S &b) {\n    return (a > b ? a = b, 1 : 0);\n}\n\n#define\
    \ rep1(a) for (i64 _ = 0; _ < (i64)(a); ++_)\n#define rep2(i, a) for (i64 i =\
    \ 0; i < (i64)(a); ++i)\n#define rep3(i, a, b) for (i64 i = (a); i < (i64)(b);\
    \ ++i)\n#define repi2(i, a) for (i64 i = (a) - 1; i >= 0; --i)\n#define repi3(i,\
    \ a, b) for (i64 i = (a) - 1; i >= (i64)(b); --i)\n#define overload3(a, b, c,\
    \ d, ...) d\n#define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n\
    #define fi first\n#define se second\n#define all(p) std::begin(p), std::end(p)\n\
    \nstruct IoSetUp {\n    IoSetUp() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \    }\n} iosetup;\n\n#ifdef KK2\nstd::ifstream in(\"in.txt\");\nstd::ofstream\
    \ out(\"out.txt\");\n#else\n#define in std::cin\n#define out std::cout\n#endif\n\
    \nvoid YES(bool b = 1) {\n    std::cout << (b ? \"YES\" : \"NO\") << '\\n';\n\
    }\n\nvoid NO(bool b = 1) {\n    std::cout << (b ? \"NO\" : \"YES\") << '\\n';\n\
    }\n\nvoid Yes(bool b = 1) {\n    std::cout << (b ? \"Yes\" : \"No\") << '\\n';\n\
    }\n\nvoid No(bool b = 1) {\n    std::cout << (b ? \"No\" : \"Yes\") << '\\n';\n\
    }\n\nvoid yes(bool b = 1) {\n    std::cout << (b ? \"yes\" : \"no\") << '\\n';\n\
    }\n\nvoid no(bool b = 1) {\n    std::cout << (b ? \"no\" : \"yes\") << '\\n';\n\
    }\n\n\n#line 6 \"verify/yosupo_convolution/convolution_multi_truncated.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int k;\n    cin >> k;\n    vc<int>\
    \ base(k);\n    rep (i, k) cin >> base[i];\n    int n = 1;\n    rep (i, k) n *=\
    \ base[i];\n    vc<kk2::mont998> a(n), b(n);\n    rep (i, n) cin >> a[i];\n  \
    \  rep (i, n) cin >> b[i];\n    kk2::multi_convolution_truncated(a, b, base);\n\
    \    rep (i, n) cout << a[i] << \" \\n\"[i == n - 1];\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution\"\
    \ \n\n#include \"../../convolution/multi_convolution_truncated.hpp\"\n#include\
    \ \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int k;\n    cin >> k;\n    vc<int> base(k);\n    rep\
    \ (i, k) cin >> base[i];\n    int n = 1;\n    rep (i, k) n *= base[i];\n    vc<kk2::mont998>\
    \ a(n), b(n);\n    rep (i, n) cin >> a[i];\n    rep (i, n) cin >> b[i];\n    kk2::multi_convolution_truncated(a,\
    \ b, base);\n    rep (i, n) cout << a[i] << \" \\n\"[i == n - 1];\n\n    return\
    \ 0;\n}"
  dependsOn:
  - convolution/multi_convolution_truncated.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  requiredBy: []
  timestamp: '2024-10-06 17:17:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_multi_truncated.test.cpp
- /verify/verify/yosupo_convolution/convolution_multi_truncated.test.cpp.html
title: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
---
