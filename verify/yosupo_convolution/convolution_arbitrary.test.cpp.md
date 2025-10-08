---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_arb.hpp
    title: convolution/convolution_arb.hpp
  - icon: ':question:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':question:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/inv.hpp
    title: math_mod/inv.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"verify/yosupo_convolution/convolution_arbitrary.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#line 1 \"convolution/convolution_arb.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"math_mod/garner.hpp\"\n\n\n\n#include <cassert>\n\
    #line 6 \"math_mod/garner.hpp\"\n\n#line 1 \"math_mod/inv.hpp\"\n\n\n\n#line 5\
    \ \"math_mod/inv.hpp\"\n\nnamespace kk2 {\n\n// require: modulo >= 1\ntemplate\
    \ <class T> constexpr T mod_inversion(T a, T modulo) {\n    a %= modulo;\n   \
    \ if (a < 0) a += modulo;\n    T s = modulo, t = a;\n    T m0 = 0, m1 = 1;\n \
    \   while (t) {\n        T u = s / t;\n        std::swap(s -= t * u, t);\n   \
    \     std::swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n   \
    \ return m0;\n}\n\n} // namespace kk2\n\n\n#line 8 \"math_mod/garner.hpp\"\n\n\
    namespace kk2 {\n\ntemplate <class T> T garner(const std::vector<T> &d, const\
    \ std::vector<T> &p) {\n    assert(d.size() + 1 == p.size());\n    int nm = d.size();\n\
    \    std::vector<T> kp(nm + 1, 0), rmult(nm + 1, 1);\n    for (int ii = 0; ii\
    \ < nm; ii++) {\n        T x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii], p[ii])\
    \ % p[ii];\n        if (x < 0) x += p[ii];\n        for (int iii = ii + 1; iii\
    \ < nm + 1; iii++) {\n            kp[iii] = (kp[iii] + rmult[iii] * x) % p[iii];\n\
    \            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];\n        }\n    }\n \
    \   return kp[nm];\n}\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\
    \n\n\n#line 5 \"modint/mont.hpp\"\n#include <cstdint>\n#include <iostream>\n#include\
    \ <type_traits>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\
    \n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value\n      \
    \                            or std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value\n                                  or std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <typename T> using is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
    \                                  or is_unsigned_int128<T>::value,\n        \
    \                      std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
    \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
    \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename T>\
    \ using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
    \                              make_unsigned_int128<T>,\n                    \
    \          typename std::conditional<std::is_signed<T>::value,\n             \
    \                                           std::make_unsigned<T>,\n         \
    \                                               std::common_type<T>>::type>::type;\n\
    \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
    template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
    template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
    template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
    \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
    template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
    template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
    \n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n\
    #include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace\
    \ type_traits\n\ntemplate <typename T> using is_standard_istream =\n    typename\
    \ std::conditional<std::is_same<T, std::istream>::value\n                    \
    \              || std::is_same<T, std::ifstream>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_standard_ostream =\n    typename std::conditional<std::is_same<T,\
    \ std::ostream>::value\n                                  || std::is_same<T, std::ofstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
    \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
    \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
    template <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\ntemplate <int p>\
    \ struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n    using\
    \ i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32 ret = p;\n\
    \        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n        return ret;\n\
    \    }\n\n    static constexpr u32 r = get_r();\n    static constexpr u32 n2 =\
    \ -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\");\n    static_assert(p\
    \ < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"\
    invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
    \ : _v(0) {}\n\n    template <typename T, is_integral_t<T> * = nullptr> constexpr\
    \ LazyMontgomeryModInt(T b)\n        : _v(reduce(u64(b % p + p) * n2)) {}\n\n\
    \    static constexpr u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r))\
    \ * p) >> 32; }\n    constexpr mint &operator++() { return *this += 1; }\n   \
    \ constexpr mint &operator--() { return *this -= 1; }\n\n    constexpr mint operator++(int)\
    \ {\n        mint ret = *this;\n        *this += 1;\n        return ret;\n   \
    \ }\n\n    constexpr mint operator--(int) {\n        mint ret = *this;\n     \
    \   *this -= 1;\n        return ret;\n    }\n\n    constexpr mint &operator+=(const\
    \ mint &b) {\n        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return\
    \ *this;\n    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if\
    \ (i32(_v -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
    \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n  \
    \      return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr bool\
    \ operator==(const mint &b) const {\n        return (_v >= p ? _v - p : _v) ==\
    \ (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
    \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
    \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
    \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
    \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
    \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const mint\
    \ &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const mint\
    \ &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint operator/(const\
    \ mint &a, const mint &b) { return mint(a) /= b; }\n\n    template <class T> constexpr\
    \ mint pow(T n) const {\n        mint ret(1), mul(*this);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            if (n >>= 1) mul *= mul;\n\
    \        }\n        return ret;\n    }\n\n    constexpr mint inv() const {\n \
    \       assert(*this != mint(0));\n        return pow(p - 2);\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, mint &x) {\n        i64 t;\n        is >> t;\n        x = mint(t);\n  \
    \      return (is);\n    }\n\n    constexpr u32 val() const {\n        u32 ret\
    \ = reduce(_v);\n        return ret >= p ? ret - p : ret;\n    }\n\n    static\
    \ constexpr u32 getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
    \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#line 6 \"\
    convolution/convolution.hpp\"\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\
    \n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line\
    \ 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\ntemplate <typename T> constexpr\
    \ int ctz(T x) {\n    static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n \
    \   } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
    \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
    \ long long)(x >> 64));\n    }\n}\n\ntemplate <typename T> constexpr int lsb(T\
    \ x) {\n    static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\n\
    \    return ctz(x);\n}\n\ntemplate <typename T> constexpr int clz(T x) {\n   \
    \ static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\n    if constexpr\
    \ (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    } else if constexpr\
    \ (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n    } else {\n     \
    \   if (x >> 64) return __builtin_clzll((unsigned long long)(x >> 64));\n    \
    \    return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\ntemplate <typename T> constexpr int msb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate\
    \ <typename T> constexpr int popcount(T x) {\n    static_assert(is_integral<T>::value);\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_popcount(x);\n\
    \    } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_popcountll(x);\n\
    \    } else {\n        return __builtin_popcountll((unsigned long long)(x >> 64))\n\
    \               + __builtin_popcountll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \    }\n}\n\n}; // namespace kk2\n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\
    \n\nnamespace kk2 {\n\nenum class FPSOperation { CONVOLUTION, EXP };\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> bool\nis_sparse_operation(FPSOperation\
    \ op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS()) {\n    int n =\
    \ a.size(), m = b.size();\n    long long not_zero_a = 0, not_zero_b = 0;\n   \
    \ bool same = a == b;\n    int lg = msb(n + m) + 1;\n    for (int i = 0; i < n;\
    \ i++) not_zero_a += a[i] != mint(0);\n    for (int i = 0; i < m; i++) not_zero_b\
    \ += b[i] != mint(0);\n\n    if (op == FPSOperation::CONVOLUTION) {\n        return\
    \ (n + m) * lg * (is_ntt_friendly ? 3.42 : 20.0) * (same ? 0.5 : 1)\n        \
    \       > double(not_zero_a) * not_zero_b;\n    }\n    if (op == FPSOperation::EXP)\
    \ {\n        return n * lg * (is_ntt_friendly ? 8.2 : 60.0) > double(n) * not_zero_a;\n\
    \    }\n    return false;\n}\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/butterfly.hpp\"\
    \n\n\n\n#line 5 \"math_mod/butterfly.hpp\"\n\n#line 1 \"math_mod/primitive_root.hpp\"\
    \n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m\
    \ = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n \
    \       if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n\
    \    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\
    \n\nnamespace kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if\
    \ (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
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
    \ 7 \"math_mod/butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
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
    \ std::back_inserter(a));\n}\n\n} // namespace kk2\n\n\n#line 9 \"convolution/convolution.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\
    \ FPS convolution(FPS &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) {\n        a.clear();\n        return a;\n    }\n    if (is_sparse_operation(FPSOperation::CONVOLUTION,\
    \ 1, a, b)) {\n        std::vector<int> nza(n), nzb(m);\n        int ai = 0, bi\
    \ = 0;\n        for (int i = 0; i < n; i++)\n            if (a[i] != mint(0))\
    \ nza[ai++] = i;\n        for (int i = 0; i < m; i++)\n            if (b[i] !=\
    \ mint(0)) nzb[bi++] = i;\n        nza.resize(ai), nzb.resize(bi);\n        FPS\
    \ res(n + m - 1);\n        for (int i : nza)\n            for (int j : nzb) res[i\
    \ + j] += a[i] * b[j];\n        return a = res;\n    }\n\n    int z = 1;\n   \
    \ while (z < n + m - 1) z <<= 1;\n    if (a == b) {\n        a.resize(z);\n  \
    \      butterfly(a);\n        for (int i = 0; i < z; i++) a[i] *= a[i];\n    }\
    \ else {\n        a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(),\
    \ b.end());\n        t.resize(z);\n        butterfly(t);\n        for (int i =\
    \ 0; i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(n +\
    \ m - 1);\n    return a;\n}\n\n} // namespace kk2\n\n\n#line 10 \"convolution/convolution_arb.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS convolution_arb(FPS &a, const FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) {\n        a.clear();\n        return a;\n    }\n    if (is_sparse_operation(FPSOperation::CONVOLUTION,\
    \ 0, a, b)) {\n        std::vector<int> nza(n), nzb(m);\n        int ai = 0, bi\
    \ = 0;\n        for (int i = 0; i < n; i++)\n            if (a[i] != mint(0))\
    \ nza[ai++] = i;\n        for (int i = 0; i < m; i++)\n            if (b[i] !=\
    \ mint(0)) nzb[bi++] = i;\n        nza.resize(ai), nzb.resize(bi);\n        FPS\
    \ res(n + m - 1);\n        for (int i : nza)\n            for (int j : nzb) res[i\
    \ + j] += a[i] * b[j];\n        return a = res;\n    }\n\n    static constexpr\
    \ long long MOD1 = 754974721; // 2^24\n    static constexpr long long MOD2 = 167772161;\
    \ // 2^25\n    static constexpr long long MOD3 = 469762049; // 2^26\n    using\
    \ mint1 = LazyMontgomeryModInt<MOD1>;\n    using mint2 = LazyMontgomeryModInt<MOD2>;\n\
    \    using mint3 = LazyMontgomeryModInt<MOD3>;\n\n    std::vector<long long> a0(n),\
    \ b0(m);\n    for (int i = 0; i < n; i++) a0[i] = a[i].val();\n    for (int i\
    \ = 0; i < m; i++) b0[i] = b[i].val();\n    auto a1 = std::vector<mint1>(a0.begin(),\
    \ a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(), b0.end());\n    convolution(a1,\
    \ b1);\n    auto a2 = std::vector<mint2>(a0.begin(), a0.end());\n    auto b2 =\
    \ std::vector<mint2>(b0.begin(), b0.end());\n    convolution(a2, b2);\n    auto\
    \ a3 = std::vector<mint3>(a0.begin(), a0.end());\n    auto b3 = std::vector<mint3>(b0.begin(),\
    \ b0.end());\n    convolution(a3, b3);\n    const std::vector<long long> ps =\
    \ {MOD1, MOD2, MOD3, mint::getmod()};\n    a.resize(n + m - 1);\n    for (int\
    \ i = 0; i < n + m - 1; i++) {\n        a[i] = mint(garner({a1[i].val(), a2[i].val(),\
    \ a3[i].val()}, ps));\n    }\n    return a;\n}\n\n} // namespace kk2\n\n\n#line\
    \ 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\n#include\
    \ <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include <chrono>\n\
    #include <cmath>\n#include <deque>\n#include <functional>\n#include <iterator>\n\
    #include <limits>\n#include <map>\n#include <numeric>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#line\
    \ 26 \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line\
    \ 1 \"template/type_alias.hpp\"\n\n\n\n#line 8 \"template/type_alias.hpp\"\n\n\
    using u32 = unsigned int;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n\nusing pi = std::pair<int,\
    \ int>;\nusing pl = std::pair<i64, i64>;\nusing pil = std::pair<int, i64>;\nusing\
    \ pli = std::pair<i64, int>;\n\ntemplate <class T> using vc = std::vector<T>;\n\
    template <class T> using vvc = std::vector<vc<T>>;\ntemplate <class T> using vvvc\
    \ = std::vector<vvc<T>>;\ntemplate <class T> using vvvvc = std::vector<vvvc<T>>;\n\
    \ntemplate <class T> using pq = std::priority_queue<T>;\ntemplate <class T> using\
    \ pqi = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\n\n#line 5\
    \ \"template/constant.hpp\"\n\ntemplate <class T> constexpr T infty = 0;\ntemplate\
    \ <> constexpr int infty<int> = (1 << 30) - 123;\ntemplate <> constexpr i64 infty<i64>\
    \ = (1ll << 62) - (1ll << 31);\ntemplate <> constexpr i128 infty<i128> = (i128(1)\
    \ << 126) - (i128(1) << 63);\ntemplate <> constexpr u32 infty<u32> = infty<int>;\n\
    template <> constexpr u64 infty<u64> = infty<i64>;\ntemplate <> constexpr u128\
    \ infty<u128> = infty<i128>;\ntemplate <> constexpr double infty<double> = infty<i64>;\n\
    template <> constexpr long double infty<long double> = infty<i64>;\n\nconstexpr\
    \ int mod = 998244353;\nconstexpr int modu = 1e9 + 7;\nconstexpr long double PI\
    \ = 3.14159265358979323846;\n\n\n#line 1 \"template/fastio.hpp\"\n\n\n\n#include\
    \ <cctype>\n#line 6 \"template/fastio.hpp\"\n#include <cstdio>\n#include <fstream>\n\
    #line 10 \"template/fastio.hpp\"\n\n#line 13 \"template/fastio.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace fastio {\n\nstruct Scanner : type_traits::istream_tag {\n\
    \  private:\n    static constexpr size_t INPUT_BUF = 1 << 17;\n    size_t pos\
    \ = 0, end = 0;\n    bool is_eof = false;\n    static char buf[INPUT_BUF];\n \
    \   FILE *fp;\n\n  public:\n    Scanner() : fp(stdin) {}\n\n    Scanner(const\
    \ char *file) : fp(fopen(file, \"r\")) {}\n\n    ~Scanner() {\n        if (fp\
    \ != stdin) fclose(fp);\n    }\n\n    char now() {\n        if (is_eof) return\
    \ '\\0';\n        if (pos == end) {\n            end = fread(buf, 1, INPUT_BUF,\
    \ fp);\n            if (end != INPUT_BUF) buf[end] = '\\0';\n            if (end\
    \ == 0) is_eof = true;\n            pos = 0;\n        }\n        return buf[pos];\n\
    \    }\n\n    void skip_space() {\n        while (isspace(now())) ++pos;\n   \
    \ }\n\n    template <class T, is_unsigned_t<T> * = nullptr> T next_unsigned_integral()\
    \ {\n        skip_space();\n        T res{};\n        while (isdigit(now())) {\n\
    \            res = res * 10 + (now() - '0');\n            ++pos;\n        }\n\
    \        return res;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ T next_signed_integral() {\n        skip_space();\n        if (now() == '-')\
    \ {\n            ++pos;\n            return T(-next_unsigned_integral<typename\
    \ to_unsigned<T>::type>());\n        } else return (T)next_unsigned_integral<typename\
    \ to_unsigned<T>::type>();\n    }\n\n    char next_char() {\n        skip_space();\n\
    \        auto res = now();\n        ++pos;\n        return res;\n    }\n\n   \
    \ std::string next_string() {\n        skip_space();\n        std::string res;\n\
    \        while (true) {\n            char c = now();\n            if (isspace(c)\
    \ or c == '\\0') break;\n            res.push_back(now());\n            ++pos;\n\
    \        }\n        return res;\n    }\n\n    template <class T, is_unsigned_t<T>\
    \ * = nullptr> Scanner &operator>>(T &x) {\n        x = next_unsigned_integral<T>();\n\
    \        return *this;\n    }\n\n    template <class T, is_signed_t<T> * = nullptr>\
    \ Scanner &operator>>(T &x) {\n        x = next_signed_integral<T>();\n      \
    \  return *this;\n    }\n\n    Scanner &operator>>(char &x) {\n        x = next_char();\n\
    \        return *this;\n    }\n\n    Scanner &operator>>(std::string &x) {\n \
    \       x = next_string();\n        return *this;\n    }\n};\n\nstruct endl_struct_t\
    \ {};\n\nstruct Printer : type_traits::ostream_tag {\n  private:\n    static char\
    \ helper[10000][5];\n    static char leading_zero[10000][5];\n    constexpr static\
    \ size_t OUTPUT_BUF = 1 << 17;\n    static char buf[OUTPUT_BUF];\n    size_t pos\
    \ = 0;\n    FILE *fp;\n\n    template <class T> static constexpr void div_mod(T\
    \ &a, T &b, T mod) {\n        a = b / mod;\n        b -= a * mod;\n    }\n\n \
    \   static void init() {\n        buf[0] = '\\0';\n        for (size_t i = 0;\
    \ i < 10000; ++i) {\n            leading_zero[i][0] = i / 1000 + '0';\n      \
    \      leading_zero[i][1] = i / 100 % 10 + '0';\n            leading_zero[i][2]\
    \ = i / 10 % 10 + '0';\n            leading_zero[i][3] = i % 10 + '0';\n     \
    \       leading_zero[i][4] = '\\0';\n\n            size_t j = 0;\n           \
    \ if (i >= 1000) helper[i][j++] = i / 1000 + '0';\n            if (i >= 100) helper[i][j++]\
    \ = i / 100 % 10 + '0';\n            if (i >= 10) helper[i][j++] = i / 10 % 10\
    \ + '0';\n            helper[i][j++] = i % 10 + '0';\n            helper[i][j]\
    \ = '\\0';\n        }\n    }\n\n  public:\n    Printer() : fp(stdout) { init();\
    \ }\n\n    Printer(const char *file) : fp(fopen(file, \"w\")) { init(); }\n\n\
    \    ~Printer() {\n        write();\n        if (fp != stdout) fclose(fp);\n \
    \   }\n\n    void write() {\n        fwrite(buf, 1, pos, fp);\n        pos = 0;\n\
    \    }\n\n    void flush() {\n        write();\n        fflush(fp);\n    }\n\n\
    \    void put_char(char c) {\n        if (pos == OUTPUT_BUF) write();\n      \
    \  buf[pos++] = c;\n    }\n\n    void put_cstr(const char *s) {\n        while\
    \ (*s) put_char(*(s++));\n    }\n\n    void put_u32(uint32_t x) {\n        uint32_t\
    \ y;\n        if (x >= 100000000) { // 10^8\n            div_mod<uint32_t>(y,\
    \ x, 100000000);\n            put_cstr(helper[y]);\n            div_mod<uint32_t>(y,\
    \ x, 10000);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000) { // 10^4\n            div_mod<uint32_t>(y, x,\
    \ 10000);\n            put_cstr(helper[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i32(int32_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u32(-x);\n\
    \        } else put_u32(x);\n    }\n\n    void put_u64(uint64_t x) {\n       \
    \ uint64_t y;\n        if (x >= 1000000000000ull) { // 10^12\n            div_mod<uint64_t>(y,\
    \ x, 1000000000000ull);\n            put_u32(y);\n            div_mod<uint64_t>(y,\
    \ x, 100000000ull);\n            put_cstr(leading_zero[y]);\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_cstr(leading_zero[y]);\n            put_cstr(leading_zero[x]);\n\
    \        } else if (x >= 10000ull) { // 10^4\n            div_mod<uint64_t>(y,\
    \ x, 10000ull);\n            put_u32(y);\n            put_cstr(leading_zero[x]);\n\
    \        } else put_cstr(helper[x]);\n    }\n\n    void put_i64(int64_t x) {\n\
    \        if (x < 0) {\n            put_char('-');\n            put_u64(-x);\n\
    \        } else put_u64(x);\n    }\n\n    void put_u128(__uint128_t x) {\n   \
    \     constexpr static __uint128_t pow10_10 = 10000000000ull;\n        constexpr\
    \ static __uint128_t pow10_20 = pow10_10 * pow10_10;\n\n        __uint128_t y;\n\
    \        if (x >= pow10_20) { // 10^20\n            div_mod<__uint128_t>(y, x,\
    \ pow10_20);\n            put_u64(uint64_t(y));\n            div_mod<__uint128_t>(y,\
    \ x, __uint128_t(10000000000000000ull));\n            put_cstr(leading_zero[y]);\n\
    \            div_mod<__uint128_t>(y, x, __uint128_t(1000000000000ull));\n    \
    \        put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x, __uint128_t(100000000ull));\n\
    \            put_cstr(leading_zero[y]);\n            div_mod<__uint128_t>(y, x,\
    \ __uint128_t(10000ull));\n            put_cstr(leading_zero[y]);\n          \
    \  put_cstr(leading_zero[x]);\n        } else if (x >= __uint128_t(10000)) { //\
    \ 10^4\n            div_mod<__uint128_t>(y, x, __uint128_t(10000));\n        \
    \    put_u64(uint64_t(y));\n            put_cstr(leading_zero[x]);\n        }\
    \ else put_cstr(helper[x]);\n    }\n\n    void put_i128(__int128_t x) {\n    \
    \    if (x < 0) {\n            put_char('-');\n            put_u128(-x);\n   \
    \     } else put_u128(x);\n    }\n\n    template <class T, is_unsigned_t<T> *\
    \ = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <= 4)\
    \ put_u32(x);\n        else if constexpr (sizeof(T) <= 8) put_u64(x);\n      \
    \  else put_u128(x);\n        return *this;\n    }\n\n    template <class T, is_signed_t<T>\
    \ * = nullptr> Printer &operator<<(T x) {\n        if constexpr (sizeof(T) <=\
    \ 4) put_i32(x);\n        else if constexpr (sizeof(T) <= 8) put_i64(x);\n   \
    \     else put_i128(x);\n        return *this;\n    }\n\n    Printer &operator<<(char\
    \ x) {\n        put_char(x);\n        return *this;\n    }\n\n    Printer &operator<<(const\
    \ std::string &x) {\n        for (char c : x) put_char(c);\n        return *this;\n\
    \    }\n\n    Printer &operator<<(const char *x) {\n        put_cstr(x);\n   \
    \     return *this;\n    }\n\n    // std::cout << std::endl; \u306F\u95A2\u6570\
    \u30DD\u30A4\u30F3\u30BF\u3092\u6E21\u3057\u3066\u3044\u308B\u3089\u3057\u3044\
    \n    Printer &operator<<(endl_struct_t) {\n        put_char('\\n');\n       \
    \ flush();\n        return *this;\n    }\n};\n\nchar Scanner::buf[Scanner::INPUT_BUF];\n\
    char Printer::buf[Printer::OUTPUT_BUF];\nchar Printer::helper[10000][5];\nchar\
    \ Printer::leading_zero[10000][5];\n\n} // namespace fastio\n\n#if defined(INTERACTIVE)\
    \ || defined(USE_STDIO)\nauto &kin = std::cin;\nauto &kout = std::cout;\nauto\
    \ (*kendl)(std::ostream &) = std::endl<char, std::char_traits<char>>;\n#else\n\
    fastio::Scanner kin;\nfastio::Printer kout;\nfastio::endl_struct_t kendl;\n#endif\n\
    \n} // namespace kk2\n\n\n#line 1 \"template/io_util.hpp\"\n\n\n\n#line 7 \"template/io_util.hpp\"\
    \n\n#line 9 \"template/io_util.hpp\"\n\n// \u306A\u3093\u304Boj verify\u306F\u30D7\
    \u30ED\u30C8\u30BF\u30A4\u30D7\u5BA3\u8A00\u304C\u843D\u3061\u308B\n\nnamespace\
    \ impl {\n\nstruct read {\n    template <class IStream, class T> inline static\
    \ void all_read(IStream &is, T &x) { is >> x; }\n\n    template <class IStream,\
    \ class T, class U>\n    inline static void all_read(IStream &is, std::pair<T,\
    \ U> &p) {\n        all_read(is, p.first);\n        all_read(is, p.second);\n\
    \    }\n\n    template <class IStream, class T> inline static void all_read(IStream\
    \ &is, std::vector<T> &v) {\n        for (T &x : v) all_read(is, x);\n    }\n\n\
    \    template <class IStream, class T, size_t F>\n    inline static void all_read(IStream\
    \ &is, std::array<T, F> &a) {\n        for (T &x : a) all_read(is, x);\n    }\n\
    };\n\nstruct write {\n    template <class OStream, class T> inline static void\
    \ all_write(OStream &os, const T &x) {\n        os << x;\n    }\n\n    template\
    \ <class OStream, class T, class U>\n    inline static void all_write(OStream\
    \ &os, const std::pair<T, U> &p) {\n        all_write(os, p.first);\n        all_write(os,\
    \ ' ');\n        all_write(os, p.second);\n    }\n\n    template <class OStream,\
    \ class T>\n    inline static void all_write(OStream &os, const std::vector<T>\
    \ &v) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (i)\
    \ all_write(os, ' ');\n            all_write(os, v[i]);\n        }\n    }\n\n\
    \    template <class OStream, class T, size_t F>\n    inline static void all_write(OStream\
    \ &os, const std::array<T, F> &a) {\n        for (int i = 0; i < (int)F; ++i)\
    \ {\n            if (i) all_write(os, ' ');\n            all_write(os, a[i]);\n\
    \        }\n    }\n};\n\n} // namespace impl\n\ntemplate <class IStream, class\
    \ T, class U, kk2::is_istream_t<IStream> * = nullptr>\nIStream &operator>>(IStream\
    \ &is, std::pair<T, U> &p) {\n    impl::read::all_read(is, p);\n    return is;\n\
    }\n\ntemplate <class IStream, class T, kk2::is_istream_t<IStream> * = nullptr>\n\
    IStream &operator>>(IStream &is, std::vector<T> &v) {\n    impl::read::all_read(is,\
    \ v);\n    return is;\n}\n\ntemplate <class IStream, class T, size_t F, kk2::is_istream_t<IStream>\
    \ * = nullptr>\nIStream &operator>>(IStream &is, std::array<T, F> &a) {\n    impl::read::all_read(is,\
    \ a);\n    return is;\n}\n\ntemplate <class OStream, class T, class U, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::pair<T, U> &p) {\n\
    \    impl::write::all_write(os, p);\n    return os;\n}\n\ntemplate <class OStream,\
    \ class T, kk2::is_ostream_t<OStream> * = nullptr>\nOStream &operator<<(OStream\
    \ &os, const std::vector<T> &v) {\n    impl::write::all_write(os, v);\n    return\
    \ os;\n}\n\ntemplate <class OStream, class T, size_t F, kk2::is_ostream_t<OStream>\
    \ * = nullptr>\nOStream &operator<<(OStream &os, const std::array<T, F> &a) {\n\
    \    impl::write::all_write(os, a);\n    return os;\n}\n\n\n#line 1 \"template/macros.hpp\"\
    \n\n\n\n#define rep1(a) for (long long _ = 0; _ < (long long)(a); ++_)\n#define\
    \ rep2(i, a) for (long long i = 0; i < (long long)(a); ++i)\n#define rep3(i, a,\
    \ b) for (long long i = (a); i < (long long)(b); ++i)\n#define repi2(i, a) for\
    \ (long long i = (a) - 1; i >= 0; --i)\n#define repi3(i, a, b) for (long long\
    \ i = (a) - 1; i >= (long long)(b); --i)\n#define overload3(a, b, c, d, ...) d\n\
    #define rep(...) overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)\n#define\
    \ repi(...) overload3(__VA_ARGS__, repi3, repi2, rep1)(__VA_ARGS__)\n\n#define\
    \ fi first\n#define se second\n#define all(p) begin(p), end(p)\n\n\n#line 32 \"\
    template/template.hpp\"\n\nusing kk2::kendl;\nusing kk2::kin;\nusing kk2::kout;\n\
    \nvoid Yes(bool b = 1) { kout << (b ? \"Yes\\n\" : \"No\\n\"); }\nvoid No(bool\
    \ b = 1) { kout << (b ? \"No\\n\" : \"Yes\\n\"); }\nvoid YES(bool b = 1) { kout\
    \ << (b ? \"YES\\n\" : \"NO\\n\"); }\nvoid NO(bool b = 1) { kout << (b ? \"NO\\\
    n\" : \"YES\\n\"); }\nvoid yes(bool b = 1) { kout << (b ? \"yes\\n\" : \"no\\\
    n\"); }\nvoid no(bool b = 1) { kout << (b ? \"no\\n\" : \"yes\\n\"); }\ntemplate\
    \ <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a =\
    \ b, 1 : 0); }\ntemplate <class T, class S> inline bool chmin(T &a, const S &b)\
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 6 \"verify/yosupo_convolution/convolution_arbitrary.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    int n, m;\n    kin >> n >> m;\n  \
    \  vc<kk2::mont107> a(n), b(m);\n    kin >> a >> b;\n    kout << kk2::convolution_arb(a,\
    \ b) << kendl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../../convolution/convolution_arb.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    vc<kk2::mont107> a(n), b(m);\n   \
    \ kin >> a >> b;\n    kout << kk2::convolution_arb(a, b) << kendl;\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - convolution/convolution_arb.hpp
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - modint/mont.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_arbitrary.test.cpp
- /verify/verify/yosupo_convolution/convolution_arbitrary.test.cpp.html
title: verify/yosupo_convolution/convolution_arbitrary.test.cpp
---
