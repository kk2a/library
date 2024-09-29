---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':warning:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  - icon: ':warning:'
    path: math_mod/inv.hpp
    title: math_mod/inv.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/convo_arb.hpp\"\n\n\n\n#include <vector>\n\n\
    #line 1 \"math_mod/garner.hpp\"\n\n\n\n#line 5 \"math_mod/garner.hpp\"\n\n#line\
    \ 1 \"math_mod/inv.hpp\"\n\n\n\nnamespace kk2 {\n\n// require: modulo >= 1\ntemplate\
    \ <class T> constexpr T mod_inversion(T a, T modulo) {\n    a %= modulo;\n   \
    \ if (a < 0) a += modulo;\n    T s = modulo, t = a;\n    T m0 = 0, m1 = 1;\n \
    \   while (t) {\n        T u = s / t;\n        std::swap(s -= t * u, t);\n   \
    \     std::swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n   \
    \ return m0;\n}\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/garner.hpp\"\n\n\
    namespace kk2 {\n\n// d.size() + 1 == p.size()\nlong long garner(const std::vector<long\
    \ long> &d,\n                 const std::vector<long long> &p) {\n    int nm =\
    \ d.size();\n    std::vector<long long> kp(nm + 1, 0), rmult(nm + 1, 1);\n   \
    \ for (int ii = 0; ii < nm; ii++) {\n        long long x =\n            (d[ii]\
    \ - kp[ii]) * mod_inversion(rmult[ii], p[ii]) % p[ii];\n        if (x < 0) x +=\
    \ p[ii];\n        for (int iii = ii + 1; iii < nm + 1; iii++) {\n            kp[iii]\
    \ = (kp[iii] + rmult[iii] * x) % p[iii];\n            rmult[iii] = (rmult[iii]\
    \ * p[ii]) % p[iii];\n        }\n    }\n    return kp[nm];\n}\n\n} // namespace\
    \ kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#include <cassert>\n#include <cstdint>\n\
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
    \ T,\n              std::enable_if_t<kk2::is_integral_extended<T>::value> * =\
    \ nullptr>\n    constexpr LazyMontgomeryModInt(T b) : _v(reduce(u64(b % p + p)\
    \ * n2)) {}\n\n    static constexpr u32 reduce(const u64 &b) {\n        return\
    \ (b + u64(u32(b) * u32(-r)) * p) >> 32;\n    }\n\n    constexpr mint &operator++()\
    \ { return *this += 1; }\n\n    constexpr mint &operator--() { return *this -=\
    \ 1; }\n\n    constexpr mint operator++(int) {\n        mint ret = *this;\n  \
    \      *this += 1;\n        return ret;\n    }\n\n    constexpr mint operator--(int)\
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
    \ constexpr mint operator+(const mint &a, const mint &b) {\n        return mint(a)\
    \ += b;\n    }\n\n    template <class T,\n              std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator+(const mint &a, T b) {\n  \
    \      return mint(a) += mint(b);\n    }\n\n    template <class T,\n         \
    \     std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n   \
    \ friend constexpr mint operator+(T a, const mint &b) {\n        return mint(a)\
    \ += b;\n    }\n\n    friend constexpr mint operator-(const mint &a, const mint\
    \ &b) {\n        return mint(a) -= b;\n    }\n\n    template <class T,\n     \
    \         std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n\
    \    friend constexpr mint operator-(const mint &a, T b) {\n        return mint(a)\
    \ -= mint(b);\n    }\n\n    template <class T,\n              std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator-(T a, const mint &b) {\n  \
    \      return mint(a) -= b;\n    }\n\n    friend constexpr mint operator*(const\
    \ mint &a, const mint &b) {\n        return mint(a) *= b;\n    }\n\n    template\
    \ <class T,\n              std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator*(const mint &a, T b) {\n  \
    \      return mint(a) *= mint(b);\n    }\n\n    template <class T,\n         \
    \     std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n   \
    \ friend constexpr mint operator*(T a, const mint &b) {\n        return mint(a)\
    \ *= b;\n    }\n\n    friend constexpr mint operator/(const mint &a, const mint\
    \ &b) {\n        return mint(a) /= b;\n    }\n\n    template <class T,\n     \
    \         std::enable_if_t<kk2::is_integral_extended<T>::value> * = nullptr>\n\
    \    friend constexpr mint operator/(const mint &a, T b) {\n        return mint(a)\
    \ /= mint(b);\n    }\n\n    template <class T,\n              std::enable_if_t<kk2::is_integral_extended<T>::value>\
    \ * = nullptr>\n    friend constexpr mint operator/(T a, const mint &b) {\n  \
    \      return mint(a) /= b;\n    }\n\n    template <class T> constexpr mint pow(T\
    \ n) const {\n        mint ret(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const { return\
    \ pow(p - 2); }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ mint &x) {\n        return os << x.val();\n    }\n\n    friend std::istream\
    \ &operator>>(std::istream &is, mint &x) {\n        i64 t;\n        is >> t;\n\
    \        x = mint(t);\n        return (is);\n    }\n\n    constexpr u32 val()\
    \ const {\n        u32 ret = reduce(_v);\n        return ret >= p ? ret - p :\
    \ ret;\n    }\n\n    static constexpr u32 getmod() { return p; }\n};\n\ntemplate\
    \ <int p> using Mont = LazyMontgomeryModInt<p>;\n\n\nusing mont998 = Mont<998244353>;\n\
    using mont107 = Mont<1000000007>;\n\n} // namespace kk2\n\n\n#line 1 \"convolution/convolution.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"convolution/convolution.hpp\"\n\n#line\
    \ 1 \"convolution/butterfly.hpp\"\n\n\n\n#line 5 \"convolution/butterfly.hpp\"\
    \n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
    \n\n\n\n#line 6 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ S, class T, class U>\nconstexpr S pow_mod(T x, U n, T m) {\n    assert(!is_signed_extended<U>::value\
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
    \        if (ok) return g;\n    }\n}\n\ntemplate <int m>\nstatic constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\n#line\
    \ 7 \"convolution/butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nvoid butterfly(FPS &a) {\n    static int g\
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
    \  if (s + 1 != (1 << len))\n                    rot *= sum_e2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n    \
    \        for (int s = 0; s < (1 << len); s++) {\n                mint rot2 = rot\
    \ * rot;\n                mint rot3 = rot2 * rot;\n                int offset\
    \ = s << (h - len);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto a0 = a[i + offset];\n                    auto a1 = a[i + offset\
    \ + p] * rot;\n                    auto a2 = a[i + offset + p * 2] * rot2;\n \
    \                   auto a3 = a[i + offset + p * 3] * rot3;\n                \
    \    auto a1na3imag = (a1 - a3) * imag;\n                    a[i + offset] = a0\
    \ + a2 + a1 + a3;\n                    a[i + offset + p] = a0 + a2 - a1 - a3;\n\
    \                    a[i + offset + p * 2] = a0 - a2 + a1na3imag;\n          \
    \          a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n                }\n \
    \               if (s + 1 != (1 << len))\n                    rot *= sum_e3[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nvoid butterfly_inv(FPS &a)\
    \ {\n    static constexpr int g = primitive_root<mint::getmod()>;\n    int n =\
    \ int(a.size());\n    int h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n\
    \    static bool first = true;\n    static mint sum_ie2[30]; // sum_ie[i] = es[0]\
    \ * ... * es[i - 1] * ies[i]\n    static mint sum_ie3[30];\n    static mint es[30],\
    \ ies[30]; // es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n    if (first)\
    \ {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() -\
    \ 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
    \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n    \
    \        es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n \
    \           ie *= ie;\n        }\n        mint now = 1;\n        for (int i =\
    \ 0; i <= cnt2 - 2; i++) {\n            sum_ie2[i] = ies[i] * now;\n         \
    \   now *= es[i];\n        }\n        now = 1;\n        for (int i = 0; i <= cnt2\
    \ - 3; i++) {\n            sum_ie3[i] = ies[i + 1] * now;\n            now *=\
    \ es[i + 1];\n        }\n\n        invn[0] = 1;\n        invn[1] = mint::getmod()\
    \ / 2 + 1;\n        for (int i = 2; i < 30; i++) invn[i] = invn[i - 1] * invn[1];\n\
    \    }\n    int len = h;\n    while (len) {\n        if (len == 1) {\n       \
    \     int p = 1 << (h - len);\n            mint irot = 1;\n            for (int\
    \ s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s << (h -\
    \ len + 1);\n                for (int i = 0; i < p; i++) {\n                 \
    \   auto l = a[i + offset];\n                    auto r = a[i + offset + p];\n\
    \                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = (l - r) * irot;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= sum_ie2[__builtin_ctz(~(unsigned int)(s))];\n\
    \            }\n            len--;\n        } else {\n            int p = 1 <<\
    \ (h - len);\n            mint irot = 1, iimag = ies[0];\n            for (int\
    \ s = 0; s < (1 << ((len - 2))); s++) {\n                mint irot2 = irot * irot;\n\
    \                mint irot3 = irot2 * irot;\n                int offset = s <<\
    \ (h - len + 2);\n                for (int i = 0; i < p; i++) {\n            \
    \        auto a0 = a[i + offset];\n                    auto a1 = a[i + offset\
    \ + p];\n                    auto a2 = a[i + offset + p * 2];\n              \
    \      auto a3 = a[i + offset + p * 3];\n                    auto a2na3iimag =\
    \ (a2 - a3) * iimag;\n\n                    a[i + offset] = a0 + a1 + a2 + a3;\n\
    \                    a[i + offset + p] = (a0 - a1 + a2na3iimag) * irot;\n    \
    \                a[i + offset + p * 2] = (a0 + a1 - a2 - a3) * irot2;\n      \
    \              a[i + offset + p * 3] = (a0 - a1 - a2na3iimag) * irot3;\n     \
    \           }\n                if (s + 1 != (1 << (len - 2)))\n              \
    \      irot *= sum_ie3[__builtin_ctz(~(unsigned int)(s))];\n            }\n  \
    \          len -= 2;\n        }\n    }\n\n    for (int i = 0; i < n; i++) a[i]\
    \ *= invn[h];\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    void doubling(FPS &a) {\n    int n = a.size();\n    auto b = a;\n    int z = 1;\n\
    \    butterfly_inv(b);\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>)\n\
    \                           .pow((mint::getmod() - 1) / (n << 1));\n    for (int\
    \ i = 0; i < n; i++) {\n        b[i] *= r;\n        r *= zeta;\n    }\n    butterfly(b);\n\
    \    std::copy(b.begin(), b.end(), std::back_inserter(a));\n}\n\n} // namespace\
    \ kk2\n\n\n#line 8 \"convolution/convolution.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution(FPS &a,\
    \ const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n ||\
    \ !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m - 1);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ { res[i + j] += a[i] * b[j]; }\n        }\n        a = res;\n        return\
    \ a;\n    }\n    int z = 1;\n    while (z < n + m - 1) z <<= 1;\n    if (a ==\
    \ b) {\n        a.resize(z);\n        butterfly(a);\n        for (int i = 0; i\
    \ < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n        butterfly(a);\n\
    \        FPS t(b.begin(), b.end());\n        t.resize(z);\n        butterfly(t);\n\
    \        for (int i = 0; i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    return a;\n}\n\n} // namespace kk2\n\n\n#line 9\
    \ \"convolution/convo_arb.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS convolution_arb(FPS &a, const FPS &b,\
    \ mint mod) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m)\
    \ return {};\n    static constexpr long long MOD1 = 754974721; // 2^24\n    static\
    \ constexpr long long MOD2 = 167772161; // 2^25\n    static constexpr long long\
    \ MOD3 = 469762049; // 2^26\n    using mint1 = LazyMontgomeryModInt<MOD1>;\n \
    \   using mint2 = LazyMontgomeryModInt<MOD2>;\n    using mint3 = LazyMontgomeryModInt<MOD3>;\n\
    \n    std::vector<long long> a0(a.begin(), a.end()), b0(b.begin(), b.end());\n\
    \    auto a1 = std::vector<mint1>(a0.begin(), a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(),\
    \ b0.end());\n    convolution(a1, b1);\n    auto a2 = std::vector<mint2>(a0.begin(),\
    \ a0.end());\n    auto b2 = std::vector<mint2>(b0.begin(), b0.end());\n    convolution(a2,\
    \ b2);\n    auto a3 = std::vector<mint3>(a0.begin(), a0.end());\n    auto b3 =\
    \ std::vector<mint3>(b0.begin(), b0.end());\n    convolution(a3, b3);\n    static\
    \ const std::vector<long long> ps = {MOD1, MOD2, MOD3, (long long)mod};\n    a.resize(n\
    \ + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        a[i] = mint(garner({a1[i].val(),\
    \ a2[i].val(), a3[i].val()}, ps));\n    }\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef CONVO_ARB_HPP\n#define CONVO_ARB_HPP 1\n\n#include <vector>\n\n#include\
    \ \"../math_mod/garner.hpp\"\n#include \"../modint/mont.hpp\"\n#include \"convolution.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS convolution_arb(FPS &a, const FPS &b, mint mod) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n    static constexpr long\
    \ long MOD1 = 754974721; // 2^24\n    static constexpr long long MOD2 = 167772161;\
    \ // 2^25\n    static constexpr long long MOD3 = 469762049; // 2^26\n    using\
    \ mint1 = LazyMontgomeryModInt<MOD1>;\n    using mint2 = LazyMontgomeryModInt<MOD2>;\n\
    \    using mint3 = LazyMontgomeryModInt<MOD3>;\n\n    std::vector<long long> a0(a.begin(),\
    \ a.end()), b0(b.begin(), b.end());\n    auto a1 = std::vector<mint1>(a0.begin(),\
    \ a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(), b0.end());\n    convolution(a1,\
    \ b1);\n    auto a2 = std::vector<mint2>(a0.begin(), a0.end());\n    auto b2 =\
    \ std::vector<mint2>(b0.begin(), b0.end());\n    convolution(a2, b2);\n    auto\
    \ a3 = std::vector<mint3>(a0.begin(), a0.end());\n    auto b3 = std::vector<mint3>(b0.begin(),\
    \ b0.end());\n    convolution(a3, b3);\n    static const std::vector<long long>\
    \ ps = {MOD1, MOD2, MOD3, (long long)mod};\n    a.resize(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        a[i] = mint(garner({a1[i].val(),\
    \ a2[i].val(), a3[i].val()}, ps));\n    }\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n#endif // CONVO_ARB_HPP\n"
  dependsOn:
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: convolution/convo_arb.hpp
  requiredBy:
  - fps/fps_arb.hpp
  timestamp: '2024-09-29 16:53:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/convo_arb.hpp
layout: document
redirect_from:
- /library/convolution/convo_arb.hpp
- /library/convolution/convo_arb.hpp.html
title: convolution/convo_arb.hpp
---
