---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':question:'
    path: fps/fps_base.hpp
    title: fps/fps_base.hpp
  - icon: ':question:'
    path: fps/fps_ntt_friendly.hpp
    title: fps/fps_ntt_friendly.hpp
  - icon: ':question:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':question:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':question:'
    path: math_mod/inv_table.hpp
    title: "`[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\
      \u30D6\u30EB"
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
  bundledCode: "#line 1 \"fps/fps_multivariate.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <vector>\n\n#line 1 \"convolution/multi_convolution_truncated.hpp\"\
    \n\n\n\n#line 5 \"convolution/multi_convolution_truncated.hpp\"\n\n#line 1 \"\
    convolution/convolution.hpp\"\n\n\n\n#line 6 \"convolution/convolution.hpp\"\n\
    \n#line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\n\n#line 1 \"bit/bitcount.hpp\"\
    \n\n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\
    \n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
    \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value\n         \
    \                         or std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <typename T> using is_signed =\n    typename\
    \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <typename T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
    \n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\n\
    template <typename T> constexpr int ctz(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
    \ __builtin_ctz(x);\n    } else if constexpr (sizeof(T) <= 8) {\n        return\
    \ __builtin_ctzll(x);\n    } else {\n        if (x & 0xffffffffffffffff)\n   \
    \         return __builtin_ctzll((unsigned long long)(x & 0xffffffffffffffff));\n\
    \        return 64 + __builtin_ctzll((unsigned long long)(x >> 64));\n    }\n\
    }\n\ntemplate <typename T> constexpr int lsb(T x) {\n    static_assert(is_integral<T>::value);\n\
    \    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <typename T> constexpr\
    \ int clz(T x) {\n    static_assert(is_integral<T>::value);\n    assert(x != T(0));\n\
    \n    if constexpr (sizeof(T) <= 4) {\n        return __builtin_clz(x);\n    }\
    \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_clzll(x);\n \
    \   } else {\n        if (x >> 64) return __builtin_clzll((unsigned long long)(x\
    \ >> 64));\n        return 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n\
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
    \ m - 1);\n    return a;\n}\n\n} // namespace kk2\n\n\n#line 7 \"convolution/multi_convolution_truncated.hpp\"\
    \n\nnamespace kk2 {\n\n// reference: https://rushcheyo.blog.uoj.ac/blog/6547\n\
    // \u65E5\u672C\u8A9E:\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
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
    \    return a;\n}\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\n\n\
    \n\n#include <istream>\n#include <ostream>\n#line 7 \"type_traits/io.hpp\"\n\n\
    namespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct ostream_tag\
    \ {};\n\n} // namespace type_traits\n\ntemplate <typename T> using is_standard_istream\
    \ =\n    typename std::conditional<std::is_same<T, std::istream>::value\n    \
    \                              || std::is_same<T, std::ifstream>::value,\n   \
    \                           std::true_type,\n                              std::false_type>::type;\n\
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
    \ kk2\n\n\n#line 1 \"fps/fps_ntt_friendly.hpp\"\n\n\n\n#line 7 \"fps/fps_ntt_friendly.hpp\"\
    \n#include <utility>\n#line 9 \"fps/fps_ntt_friendly.hpp\"\n\n#line 1 \"fps/fps_base.hpp\"\
    \n\n\n\n#line 9 \"fps/fps_base.hpp\"\n\n#line 1 \"math_mod/inv_table.hpp\"\n\n\
    \n\n#line 5 \"math_mod/inv_table.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief `[1,\
    \ n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\u30D6\u30EB\
    \n *\n * @tparam mint\n */\ntemplate <class mint> struct InvTable {\n    static\
    \ inline std::vector<mint> _invs{0, 1};\n    static inline auto _mod = mint::getmod();\n\
    \    InvTable() = delete;\n\n    static void set_upper(int m) {\n        if ((int)_invs.size()\
    \ > m) return;\n        int start = _invs.size();\n        _invs.resize(m + 1);\n\
    \        // p = q * i + r\n        // - q / r = 1 / i (mod p)\n        for (int\
    \ i = start; i <= m; ++i) _invs[i] = (-_invs[_mod % i]) * (_mod / i);\n    }\n\
    \n    static inline mint inv(int n) {\n        bool neg = n < 0;\n        if (neg)\
    \ n = -n;\n        if (n >= (int)_invs.size()) set_upper(n);\n        return neg\
    \ ? -_invs[n] : _invs[n];\n    }\n};\n\n} // namespace kk2\n\n\n#line 12 \"fps/fps_base.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class Derived, class mint> struct FormalPowerSeriesBase\
    \ : std::vector<mint> {\n    using std::vector<mint>::vector;\n    using FPS =\
    \ Derived;\n    using ivta = InvTable<mint>;\n\n    // CRTP\u3092\u4F7F\u3063\u3066\
    \u6D3E\u751F\u30AF\u30E9\u30B9\u306E\u53C2\u7167\u3092\u53D6\u5F97\n    Derived\
    \ &derived() { return static_cast<Derived &>(*this); }\n    const Derived &derived()\
    \ const { return static_cast<const Derived &>(*this); }\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream &os)\
    \ const {\n        os << \"[\";\n        for (size_t i = 0; i < this->size();\
    \ i++) {\n            os << (*this)[i] << (i + 1 == this->size() ? \"\" : \",\
    \ \");\n        }\n        os << \"]\";\n    }\n\n    template <class OStream,\
    \ is_ostream_t<OStream> * = nullptr> void output(OStream &os) const {\n      \
    \  for (size_t i = 0; i < this->size(); i++) {\n            os << (*this)[i] <<\
    \ (i + 1 == this->size() ? \"\\n\" : \" \");\n        }\n    }\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const FPS &fps_) {\n        for (size_t i = 0; i < fps_.size(); i++) {\n\
    \            os << fps_[i] << (i + 1 == fps_.size() ? \"\" : \" \");\n       \
    \ }\n        return os;\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr> FPS &input(IStream &is) {\n        for (size_t i = 0; i < this->size();\
    \ i++) is >> (*this)[i];\n        return derived();\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream\
    \ &is, FPS &fps_) {\n        for (auto &x : fps_) is >> x;\n        return is;\n\
    \    }\n    FPS &operator+=(const FPS &r) {\n        if (this->size() < r.size())\
    \ this->resize(r.size());\n        for (size_t i = 0; i < r.size(); i++) (*this)[i]\
    \ += r[i];\n        return derived();\n    }\n\n    FPS &operator+=(const mint\
    \ &r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += r;\n\
    \        return derived();\n    }\n\n    FPS &operator-=(const FPS &r) {\n   \
    \     if (this->size() < r.size()) this->resize(r.size());\n        for (size_t\
    \ i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        return derived();\n \
    \   }\n\n    FPS &operator-=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] -= r;\n        return derived();\n    }\n\n    FPS &operator*=(const\
    \ mint &r) {\n        for (size_t i = 0; i < this->size(); i++) { (*this)[i] *=\
    \ r; }\n        return derived();\n    }\n    FPS &operator/=(const FPS &r) {\n\
    \        assert(!r.empty());\n        if (this->size() < r.size()) {\n       \
    \     this->clear();\n            return derived();\n        }\n        int n\
    \ = this->size() - r.size() + 1;\n        if (r.size() <= 64) {\n            FPS\
    \ f(derived()), g(r);\n            g.shrink();\n            mint coeff = g.back().inv();\n\
    \            for (auto &x : g) x *= coeff;\n            int deg = (int)f.size()\
    \ - (int)g.size() + 1;\n            int gs = g.size();\n            FPS quo(deg);\n\
    \            for (int i = deg - 1; i >= 0; i--) {\n                quo[i] = f[i\
    \ + gs - 1];\n                for (int j = 0; j < gs; j++) f[i + j] -= quo[i]\
    \ * g[j];\n            }\n            *this = quo * coeff;\n            this->resize(n,\
    \ mint(0));\n            return derived();\n        }\n        return derived()\
    \ = (derived().rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n    }\n\n    FPS\
    \ &operator%=(const FPS &r) {\n        derived() -= derived() / r * r;\n     \
    \   shrink();\n        return derived();\n    }\n\n    FPS &operator>>=(int n)\
    \ {\n        if (n >= (int)this->size()) {\n            this->clear();\n     \
    \   } else {\n            this->erase(this->begin(), this->begin() + n);\n   \
    \     }\n        return derived();\n    }\n\n    FPS &operator<<=(int n) {\n \
    \       this->insert(this->begin(), n, mint(0));\n        return derived();\n\
    \    }\n\n    // CRTP\u3092\u4F7F\u3063\u3066\u6D3E\u751F\u30AF\u30E9\u30B9\u306E\
    \u30E1\u30BD\u30C3\u30C9\u3092\u5229\u7528\u3057\u305F\u6F14\u7B97\u5B50\u306E\
    \u81EA\u52D5\u5B9F\u88C5\n    FPS operator+(const FPS &r) const { return FPS(derived())\
    \ += r; }\n    FPS operator+(const mint &r) const { return FPS(derived()) += r;\
    \ }\n    FPS operator-(const FPS &r) const { return FPS(derived()) -= r; }\n \
    \   FPS operator-(const mint &r) const { return FPS(derived()) -= r; }\n    //\
    \ \u639B\u3051\u7B97\u306F\u6D3E\u751F\u30AF\u30E9\u30B9\u3067\u5B9A\u7FA9\u3055\
    \u308C\u308B\n    FPS operator*(const FPS &r) const { return FPS(derived()) *=\
    \ r; }\n    FPS operator*(const mint &r) const { return FPS(derived()) *= r; }\n\
    \    FPS operator/(const FPS &r) const { return FPS(derived()) /= r; }\n    FPS\
    \ operator%(const FPS &r) const { return FPS(derived()) %= r; }\n    FPS operator>>(int\
    \ n) const { return FPS(derived()) >>= n; }\n    FPS operator<<(int n) const {\
    \ return FPS(derived()) <<= n; }\n\n    FPS operator-() const {\n        FPS ret(this->size());\n\
    \        for (size_t i = 0; i < this->size(); i++) ret[i] = -(*this)[i];\n   \
    \     return ret;\n    }\n    FPS &shrink() {\n        while (this->size() &&\
    \ this->back() == mint(0)) this->pop_back();\n        return derived();\n    }\n\
    \n    FPS &inplace_rev() {\n        std::reverse(this->begin(), this->end());\n\
    \        return derived();\n    }\n\n    FPS &inplace_dot(const FPS &r) {\n  \
    \      this->resize(std::min(this->size(), r.size()));\n        for (size_t i\
    \ = 0; i < this->size(); i++) (*this)[i] *= r[i];\n        return derived();\n\
    \    }\n\n    FPS &inplace_pre(int n) {\n        this->resize(n);\n        return\
    \ derived();\n    }\n\n    FPS &inplace_diff() {\n        if (this->empty()) return\
    \ derived();\n        this->erase(this->begin());\n        for (size_t i = 1;\
    \ i <= this->size(); i++) (*this)[i - 1] *= mint(i);\n        return derived();\n\
    \    }\n\n    FPS &inplace_int() {\n        ivta::set_upper(this->size());\n \
    \       this->insert(this->begin(), mint(0));\n        for (size_t i = 1; i <\
    \ this->size(); i++) (*this)[i] *= ivta::inv(i);\n        return derived();\n\
    \    }\n\n    // CRTP\u3092\u4F7F\u3063\u305F\u4FBF\u5229\u95A2\u6570\u306E\u81EA\
    \u52D5\u5B9F\u88C5\n    FPS rev() const { return FPS(derived()).inplace_rev();\
    \ }\n    FPS dot(const FPS &r) const { return FPS(derived()).inplace_dot(r); }\n\
    \    FPS pre(int n) const { return FPS(derived()).inplace_pre(n); }\n    FPS diff()\
    \ const { return FPS(derived()).inplace_diff(); }\n    FPS integral() const {\
    \ return FPS(derived()).inplace_int(); }\n\n    mint eval(mint x) const {\n  \
    \      mint r = 0, w = 1;\n        for (auto &v : *this) {\n            r += w\
    \ * v;\n            w *= x;\n        }\n        return r;\n    }\n\n    FPS log(int\
    \ deg = -1) const {\n        assert(!this->empty() && (*this)[0] == mint(1));\n\
    \        // sparsity check\n        return derived().dense_log(deg);\n    }\n\n\
    \    template <class T> FPS pow(T k, int deg = -1) const {\n        // sparsity\
    \ check\n        return derived().dense_pow(k, deg);\n    }\n\n    FPS div(const\
    \ FPS &r, int deg = -1) const {\n        // sparsity check\n        return (FPS(derived()).pre(deg)\
    \ * r.inv(deg)).pre(deg);\n    }\n\n    FPS inv(int deg = -1) const {\n      \
    \  assert(!this->empty() && (*this)[0] != mint(0));\n        // sparsity check\n\
    \        return derived().dense_inv(deg);\n    }\n\n    FPS exp(int deg = -1)\
    \ const {\n        assert(this->empty() || (*this)[0] == mint(0));\n        //\
    \ sparsity check\n        return derived().dense_exp(deg);\n    }\n\n    FPS dense_log(int\
    \ deg = -1) const {\n        if (deg == -1) deg = this->size();\n        return\
    \ (derived().diff() * derived().inv(deg)).pre(deg - 1).integral();\n    }\n  \
    \  FPS sparse_log(int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        std::vector<std::pair<int, mint>> fs;\n        for (int i = 1; i < int(this->size());\
    \ i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n\
    \        }\n        ivta::set_upper(deg);\n\n        FPS g(deg);\n        for\
    \ (int k = 0; k < deg - 1; k++) {\n            for (auto &[j, fj] : fs) {\n  \
    \              if (k < j) break;\n                int i = k - j;\n           \
    \     g[k + 1] -= g[i + 1] * fj * (i + 1);\n            }\n            g[k + 1]\
    \ *= ivta::inv(k + 1);\n            if (k + 1 < int(this->size())) g[k + 1] +=\
    \ (*this)[k + 1];\n        }\n\n        return g;\n    }\n\n    template <class\
    \ T> FPS dense_pow(T k, int deg = -1) const {\n        const int n = this->size();\n\
    \        if (deg == -1) deg = n;\n        if (k == 0) {\n            FPS ret(deg);\n\
    \            if (deg > 0) ret[0] = mint(1);\n            return ret;\n       \
    \ }\n        for (int i = 0; i < n; i++) {\n            if ((*this)[i] != mint(0))\
    \ {\n                mint rev = mint(1) / (*this)[i];\n                FPS ret\
    \ = ((derived() * rev) >> i).log(deg) * k;\n                ret = ret.exp(deg);\n\
    \                ret *= (*this)[i].pow(k);\n                ret = (ret << (i *\
    \ k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \                return ret;\n            }\n            if (__int128_t(i + 1)\
    \ * k >= deg) return FPS(deg, mint(0));\n        }\n        return FPS(deg, mint(0));\n\
    \    }\n    template <class T> FPS sparse_pow(T k, int deg = -1) const {\n   \
    \     if (deg == -1) deg = this->size();\n        if (k == 0) {\n            FPS\
    \ ret(deg);\n            if (deg > 0) ret[0] = mint(1);\n            return ret;\n\
    \        }\n\n        int zero = 0;\n        while (zero != int(this->size())\
    \ && (*this)[zero] == mint(0)) zero++;\n        if (zero == int(this->size())\
    \ || __int128_t(zero) * k >= deg) { return FPS(deg, mint(0)); }\n        if (zero\
    \ != 0) {\n            FPS suf(this->begin() + zero, this->end());\n         \
    \   auto g = suf.sparse_pow(k, deg - zero * k);\n            FPS ret(zero * k,\
    \ mint(0));\n            std::copy(std::begin(g), std::end(g), std::back_inserter(ret));\n\
    \            return ret;\n        }\n\n        int mod = mint::getmod();\n   \
    \     static std::vector<mint> inv{1, 1};\n        while ((int)inv.size() <= deg)\
    \ {\n            int i = inv.size();\n            inv.push_back(-inv[mod % i]\
    \ * (mod / i));\n        }\n\n        std::vector<std::pair<int, mint>> fs;\n\
    \        for (int i = 1; i < int(this->size()); i++) {\n            if ((*this)[i]\
    \ != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\n        FPS g(deg);\n\
    \        g[0] = (*this)[0].pow(k);\n        mint denom = (*this)[0].inv();\n \
    \       k %= mod;\n        for (int a = 1; a < deg; a++) {\n            for (auto\
    \ &[i, f_i] : fs) {\n                if (a < i) break;\n                g[a] +=\
    \ g[a - i] * f_i * (mint(i) * (k + 1) - a);\n            }\n            g[a] *=\
    \ denom * inv[a];\n        }\n        return g;\n    } // return this / r\n  \
    \  FPS sparse_div(const FPS &r, int deg = -1) const {\n        assert(!r.empty()\
    \ && r[0] != mint(0));\n        if (deg == -1) deg = this->size();\n        mint\
    \ ir0 = r[0].inv();\n        FPS ret = derived() * ir0;\n        ret.resize(deg);\n\
    \        std::vector<std::pair<int, mint>> gs;\n        for (int i = 1; i < (int)r.size();\
    \ i++) {\n            if (r[i] != mint(0)) gs.emplace_back(i, r[i] * ir0);\n \
    \       }\n        for (int i = 0; i < deg; i++) {\n            for (auto &[j,\
    \ g_j] : gs) {\n                if (i + j >= deg) break;\n                ret[i\
    \ + j] -= ret[i] * g_j;\n            }\n        }\n        return ret;\n    }\n\
    \n    FPS sparse_inv(int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        std::vector<std::pair<int, mint>> fs;\n        for (int i = 1; i < int(this->size());\
    \ i++) {\n            if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n\
    \        }\n        FPS ret(deg);\n        mint if0 = (*this)[0].inv();\n    \
    \    if (0 < deg) ret[0] = if0;\n        for (int k = 1; k < deg; k++) {\n   \
    \         for (auto &[j, fj] : fs) {\n                if (k < j) break;\n    \
    \            ret[k] += ret[k - j] * fj;\n            }\n            ret[k] *=\
    \ -if0;\n        }\n        return ret;\n    }\n\n    FPS sparse_exp(int deg =\
    \ -1) const {\n        if (deg == -1) deg = this->size();\n        std::vector<std::pair<int,\
    \ mint>> fs;\n        for (int i = 1; i < int(this->size()); i++) {\n        \
    \    if ((*this)[i] != mint(0)) fs.emplace_back(i, (*this)[i]);\n        }\n\n\
    \        int mod = mint::getmod();\n        static std::vector<mint> inv{1, 1};\n\
    \        int now = inv.size();\n        inv.resize(std::max(now, deg + 1));\n\
    \        for (int i = now; i <= deg; i++) inv[i] = -inv[mod % i] * (mod / i);\n\
    \n        FPS g(deg);\n        if (deg) g[0] = 1;\n        for (int k = 0; k <\
    \ deg - 1; k++) {\n            for (auto &[ip1, fip1] : fs) {\n              \
    \  int i = ip1 - 1;\n                if (k < i) break;\n                g[k +\
    \ 1] += g[k - i] * fip1 * (i + 1);\n            }\n            g[k + 1] *= inv[k\
    \ + 1];\n        }\n\n        return g;\n    }\n    FPS &inplace_imos(int n) {\n\
    \        inplace_pre(n);\n        for (int i = 0; i < n - 1; i++) (*this)[i +\
    \ 1] += (*this)[i];\n        return derived();\n    }\n\n    FPS &inplace_iimos(int\
    \ n) {\n        inplace_pre(n);\n        for (int i = 0; i < n - 1; i++) (*this)[i\
    \ + 1] -= (*this)[i];\n        return derived();\n    }\n    FPS imos(int n) const\
    \ { return FPS(derived()).inplace_imos(n); }\n    FPS iimos(int n) const { return\
    \ FPS(derived()).inplace_iimos(n); }\n};\n\n} // namespace kk2\n\n\n#line 12 \"\
    fps/fps_ntt_friendly.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint> struct\
    \ FormalPowerSeriesNTTFriendly\n    : FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>,\
    \ mint> {\n    using base = FormalPowerSeriesBase<FormalPowerSeriesNTTFriendly<mint>,\
    \ mint>;\n    using FPS = FormalPowerSeriesNTTFriendly<mint>;\n    using base::FormalPowerSeriesBase;\n\
    \    using base::operator*=; // \u57FA\u5E95\u30AF\u30E9\u30B9\u306Eoperator*=\u3092\
    \u7D99\u627F\n    static constexpr bool is_ntt_friendly = true;\n\n    // CRTP\u3092\
    \u4F7F\u3063\u305F\u5B9F\u88C5 - override\u306F\u4E0D\u8981\n    FPS &operator*=(const\
    \ FPS &r) {\n        convolution(*this, r);\n        return *this;\n    }\n  \
    \  void but() { butterfly(*this); }\n    void ibut() { butterfly_inv(*this); }\n\
    \    void db() { doubling(*this); }\n    static int but_pr() { return primitive_root<mint::getmod()>;\
    \ }\n\n    FPS dense_inv(int deg = -1) const {\n        if (deg == -1) deg = (int)this->size();\n\
    \        FPS res(deg);\n        res[0] = {mint(1) / (*this)[0]};\n        for\
    \ (int d = 1; d < deg; d <<= 1) {\n            FPS f(2 * d), g(2 * d);\n     \
    \       std::copy(std::begin(*this),\n                      std::begin(*this)\
    \ + std::min((int)this->size(), 2 * d),\n                      std::begin(f));\n\
    \            std::copy(std::begin(res), std::begin(res) + d, std::begin(g));\n\
    \            f.but();\n            g.but();\n            f.inplace_dot(g);\n \
    \           f.ibut();\n            std::fill(std::begin(f), std::begin(f) + d,\
    \ mint(0));\n            f.but();\n            f.inplace_dot(g);\n           \
    \ f.ibut();\n            for (int j = d; j < std::min(2 * d, deg); j++) res[j]\
    \ = -f[j];\n        }\n        return res.pre(deg);\n    }\n\n    FPS dense_exp(int\
    \ deg = -1) const {\n        if (deg == -1) deg = (int)this->size();\n\n     \
    \   FPS b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};\n        FPS c{1},\
    \ z1, z2{1, 1};\n        for (int m = 2; m < deg; m <<= 1) {\n            auto\
    \ y = b;\n            y.resize(m << 1);\n            y.but();\n            z1\
    \ = z2;\n            FPS z(m);\n            z = y.dot(z1);\n            z.ibut();\n\
    \            std::fill(std::begin(z), std::begin(z) + (m >> 1), mint(0));\n  \
    \          z.but();\n            z.inplace_dot(-z1);\n            z.ibut();\n\
    \            c.insert(std::end(c), std::begin(z) + (m >> 1), std::end(z));\n \
    \           z2 = c;\n            z2.resize(m << 1);\n            z2.but();\n\n\
    \            FPS x(this->begin(), this->begin() + std::min<int>(this->size(),\
    \ m));\n            x.resize(m);\n            x.inplace_diff();\n            x.push_back(mint(0));\n\
    \            x.but();\n            x.inplace_dot(y);\n            x.ibut();\n\
    \            x -= b.diff();\n            x.resize(m << 1);\n            for (int\
    \ i = 0; i < m - 1; i++) {\n                x[m + i] = x[i];\n               \
    \ x[i] = mint(0);\n            }\n            x.but();\n            x.inplace_dot(z2);\n\
    \            x.ibut();\n            x.pop_back();\n            x.inplace_int();\n\
    \            for (int i = m; i < std::min<int>(this->size(), m << 1); i++) x[i]\
    \ += (*this)[i];\n            std::fill(std::begin(x), std::begin(x) + m, mint(0));\n\
    \            x.but();\n            x.inplace_dot(y);\n            x.ibut();\n\
    \            b.insert(std::end(b), std::begin(x) + m, std::end(x));\n        }\n\
    \        return FPS(std::begin(b), std::begin(b) + deg);\n    }\n};\n\ntemplate\
    \ <class mint> using FPSNTT = FormalPowerSeriesNTTFriendly<mint>;\n\n} // namespace\
    \ kk2\n\n\n#line 12 \"fps/fps_multivariate.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename mint> struct MultivariateFormalPowerSeries {\n    using mfps = MultivariateFormalPowerSeries;\n\
    \    using fps = FormalPowerSeriesNTTFriendly<mint>;\n    using value_type = mint;\n\
    \n    std::vector<int> base;\n    fps f;\n\n    MultivariateFormalPowerSeries()\
    \ = default;\n\n    MultivariateFormalPowerSeries(const std::vector<int> &base_)\
    \ : base(base_) {\n        int n = 1;\n        for (int x : base) n *= x;\n  \
    \      f.resize(n);\n    }\n\n    MultivariateFormalPowerSeries(const std::vector<int>\
    \ &base_, const fps &f_)\n        : base(base_),\n          f(f_) {}\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream &operator<<(OStream\
    \ &os, const mfps &mfps_) {\n        for (int i = 0; i < (int)mfps_.f.size();\
    \ i++)\n            os << mfps_.f[i] << (i + 1 == (int)mfps_.f.size() ? \"\" :\
    \ \" \");\n        return os;\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr> void output(OStream &os) const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) os << f[i] << (i + 1 == (int)f.size() ? \"\\n\" : \" \");\n    }\n\n  \
    \  template <class IStream, is_istream_t<IStream> * = nullptr> mfps &input(IStream\
    \ &is) {\n        for (auto &x : f) is >> x;\n        return *this;\n    }\n\n\
    \    template <class IStream, is_istream_t<IStream> * = nullptr>\n    friend IStream\
    \ &operator>>(IStream &is, mfps &mfps_) {\n        for (auto &x : mfps_.f) is\
    \ >> x;\n        return is;\n    }\n\n    template <typename T, typename... Ts>\
    \ int _id(int x, T y, Ts... ys) {\n        assert(x < (int)base.size() && (int)y\
    \ < base[x]);\n        if constexpr (sizeof...(Ts) == 0) return y;\n        else\
    \ return y + base[x] * _id(x + 1, ys...);\n    }\n\n    template <typename...\
    \ Args> int id(Args... args) {\n        static_assert(sizeof...(Args) > 0);\n\
    \        return _id(0, args...);\n    }\n\n    template <typename... Args> mint\
    \ &operator()(Args... args) { return f[id(args...)]; }\n\n    mint &operator[](int\
    \ i) { return f[i]; }\n\n    template <class OStream, is_ostream_t<OStream> *\
    \ = nullptr> void display(OStream &os) const {\n        for (int i = 0; i < (int)f.size();\
    \ i++) {\n            int x = i;\n            os << \"f(\";\n            for (int\
    \ j = 0; j < (int)base.size(); j++) {\n                os << x % base[j] << (j\
    \ + 1 == (int)base.size() ? \") = \" : \", \");\n                x /= base[j];\n\
    \            }\n            os << f[i] << \"\\n\";\n        }\n    }\n\n    mfps\
    \ &operator+=(const mfps &rhs) {\n        assert(base == rhs.base && f.size()\
    \ == rhs.f.size());\n        for (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];\n\
    \        return *this;\n    }\n\n    mfps &operator-=(const mfps &rhs) {\n   \
    \     assert(base == rhs.base && f.size() == rhs.f.size());\n        for (int\
    \ i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];\n        return *this;\n  \
    \  }\n\n    mfps &operator*=(const mfps &rhs) {\n        assert(base == rhs.base\
    \ && f.size() == rhs.f.size());\n        multi_convolution_truncated(f, rhs.f,\
    \ base);\n        return *this;\n    }\n\n    mfps &operator+=(const mint &rhs)\
    \ {\n        assert(!f.empty());\n        f[0] += rhs;\n        return *this;\n\
    \    }\n\n    mfps &operator-=(const mint &rhs) {\n        assert(!f.empty());\n\
    \        f[0] -= rhs;\n        return *this;\n    }\n\n    mfps &operator*=(const\
    \ mint &rhs) {\n        for (auto &x : f) x *= rhs;\n        return *this;\n \
    \   }\n\n    mfps &operator/=(const mint &rhs) {\n        for (auto &x : f) x\
    \ /= rhs;\n        return *this;\n    }\n\n    mfps operator+(const mfps &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mfps &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mfps &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator+(const mint &rhs)\
    \ const { return mfps(*this) += rhs; }\n\n    mfps operator-(const mint &rhs)\
    \ const { return mfps(*this) -= rhs; }\n\n    mfps operator*(const mint &rhs)\
    \ const { return mfps(*this) *= rhs; }\n\n    mfps operator/(const mint &rhs)\
    \ const { return mfps(*this) /= rhs; }\n\n    mfps operator+() const { return\
    \ mfps(*this); }\n\n    mfps operator-() const { return mfps(base, -f); }\n\n\
    \    friend bool operator==(const mfps &lhs, const mfps &rhs) {\n        return\
    \ lhs.f == rhs.f && lhs.base == rhs.base;\n    }\n\n    friend bool operator!=(const\
    \ mfps &lhs, const mfps &rhs) { return !(lhs == rhs); }\n\n    mfps diff() const\
    \ {\n        mfps ret(*this);\n        for (int i = 0; i < (int)ret.f.size();\
    \ i++) ret.f[i] *= i;\n        return ret;\n    }\n\n    mfps &inplace_diff()\
    \ {\n        for (int i = 0; i < (int)f.size(); i++) f[i] *= i;\n        return\
    \ *this;\n    }\n\n    static std::vector<mint> _inv;\n\n    static void ensure_inv(int\
    \ n) {\n        while ((int)_inv.size() <= n) {\n            int i = _inv.size();\n\
    \            _inv.push_back((-_inv[mint::getmod() % i]) * (mint::getmod() / i));\n\
    \        }\n    }\n\n    mfps integral() const {\n        ensure_inv(f.size());\n\
    \        mfps ret(*this);\n        for (int i = 1; i < (int)ret.f.size(); i++)\
    \ ret.f[i] *= _inv[i];\n        return ret;\n    }\n\n    mfps &inplace_int()\
    \ {\n        ensure_inv(f.size());\n        for (int i = 1; i < (int)f.size();\
    \ i++) f[i] *= _inv[i];\n        return *this;\n    }\n\n    mfps inv() const\
    \ {\n        assert(!f.empty() && f[0] != mint(0));\n        if (base.empty())\
    \ return mfps(base, fps{f[0].inv()});\n\n        int n = f.size(), k = base.size();\n\
    \        int z = 1;\n        while (z < 2 * n - 1) z <<= 1;\n        std::vector<int>\
    \ chi(z);\n        for (int i = 0; i < n; i++) {\n            int x = i;\n   \
    \         for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        \
    \    chi[i] %= k;\n        }\n        auto naive_and_dot = [&k](const std::vector<fps>\
    \ &a,\n                                  const std::vector<fps> &b,\n        \
    \                          std::vector<fps> &c) -> void {\n            std::vector<mint>\
    \ tmp(k);\n            for (int ii = 0; ii < (int)a[0].size(); ii++) {\n     \
    \           for (int i = 0; i < k; i++) {\n                    for (int j = 0;\
    \ j < k; j++) {\n                        tmp[i + j - (i + j >= k ? k : 0)] +=\
    \ a[i][ii] * b[j][ii];\n                    }\n                }\n           \
    \     for (int i = 0; i < k; i++) c[i][ii] = tmp[i], tmp[i] = mint{0};\n     \
    \       }\n        };\n\n        // reference:\n        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    \        // Let g_k := f_k^{-1} mod x^k, \\deg g_k < k.\n        // Then we obtain\
    \ g_1, g_2, g_4, ... by using the following recurrence:\n        // - g_1 = (f_0)^{-1}\
    \ ...(1)\n        // - g_{2k} = 2g_k - g_k^2 f mod x^2k ...(2)\n        // - [x^{k\
    \ + i}]g_{2k} = [x^{k + i}](-g_k^2 f) ...(3)\n        fps g(z);\n        g[0]\
    \ = f[0].inv(); // by (1)\n        for (int d = 1; d < n; d <<= 1) {\n       \
    \     std::vector<fps> a(k, fps(2 * d)), b(k, fps(2 * d)), c(k, fps(2 * d));\n\
    \            for (int i = 0; i < std::min((int)f.size(), 2 * d); i++) a[chi[i]][i]\
    \ = f[i];\n            for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];\n    \
    \        for (auto &x : a) x.but();\n            for (auto &x : b) x.but();\n\
    \            naive_and_dot(a, b, c);\n            for (auto &x : c) x.ibut();\n\
    \            // compute g_d f\n\n            for (auto &x : a) std::fill(std::begin(x),\
    \ std::end(x), mint(0));\n\n            for (int i = d; i < 2 * d; i++) a[chi[i]][i]\
    \ = c[chi[i]][i];\n            for (auto &x : a) x.but();\n            naive_and_dot(a,\
    \ b, c);\n            for (auto &x : c) x.ibut();\n            // compute g_d^2\
    \ f\n\n            // by (2), (3)\n            for (int i = d; i < 2 * d; i++)\
    \ g[i] = -c[chi[i]][i];\n        }\n        mfps res(*this);\n        res.f =\
    \ fps(std::begin(g), std::begin(g) + n);\n        return res;\n    }\n\n    mfps\
    \ log() const {\n        assert(!f.empty() && f[0] == mint(1));\n        return\
    \ ((*this).diff() * (*this).inv()).integral();\n    }\n\n    mfps exp() const\
    \ {\n        assert(!f.empty() && f[0] == mint(0));\n        int n = f.size();\n\
    \        mfps res(base, fps{1});\n        for (int d = 1; d < n; d <<= 1) {\n\
    \            int s = std::min(n, 2 * d);\n            res.f.resize(s, mint(0));\n\
    \            res *= mfps(base, fps(std::begin(f), std::begin(f) + s)) - res.log()\
    \ + 1;\n        }\n        return res;\n    }\n\n    mfps pow(long long e) const\
    \ {\n        assert(!f.empty());\n        if (f[0] != mint(0)) {\n           \
    \ mint f0inv = f[0].inv(), coef = f[0].pow(e);\n            return (((*this) *\
    \ f0inv).log() * e).exp() * coef;\n        }\n        int n = f.size();\n    \
    \    long long base_sum = 0;\n        for (auto &b : base) base_sum += b - 1;\n\
    \        if (e > base_sum) return mfps(base, fps(n));\n        mfps res(base,\
    \ fps(n)), a(*this);\n        res.f[0] = 1;\n        while (e) {\n           \
    \ if (e & 1) res *= a;\n            if (e >>= 1) a *= a;\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate <typename mint> std::vector<mint> MultivariateFormalPowerSeries<mint>::_inv\
    \ = {0, 1};\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_FPS_MULTIVARIATE_HPP\n#define KK2_FPS_FPS_MULTIVARIATE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"../convolution/multi_convolution_truncated.hpp\"\n#include\
    \ \"../type_traits/io.hpp\"\n#include \"fps_ntt_friendly.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <typename mint> struct MultivariateFormalPowerSeries {\n    using\
    \ mfps = MultivariateFormalPowerSeries;\n    using fps = FormalPowerSeriesNTTFriendly<mint>;\n\
    \    using value_type = mint;\n\n    std::vector<int> base;\n    fps f;\n\n  \
    \  MultivariateFormalPowerSeries() = default;\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_) : base(base_) {\n        int n = 1;\n        for (int\
    \ x : base) n *= x;\n        f.resize(n);\n    }\n\n    MultivariateFormalPowerSeries(const\
    \ std::vector<int> &base_, const fps &f_)\n        : base(base_),\n          f(f_)\
    \ {}\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend\
    \ OStream &operator<<(OStream &os, const mfps &mfps_) {\n        for (int i =\
    \ 0; i < (int)mfps_.f.size(); i++)\n            os << mfps_.f[i] << (i + 1 ==\
    \ (int)mfps_.f.size() ? \"\" : \" \");\n        return os;\n    }\n\n    template\
    \ <class OStream, is_ostream_t<OStream> * = nullptr> void output(OStream &os)\
    \ const {\n        for (int i = 0; i < (int)f.size(); i++) os << f[i] << (i +\
    \ 1 == (int)f.size() ? \"\\n\" : \" \");\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr> mfps &input(IStream &is) {\n        for (auto\
    \ &x : f) is >> x;\n        return *this;\n    }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    friend IStream &operator>>(IStream &is,\
    \ mfps &mfps_) {\n        for (auto &x : mfps_.f) is >> x;\n        return is;\n\
    \    }\n\n    template <typename T, typename... Ts> int _id(int x, T y, Ts...\
    \ ys) {\n        assert(x < (int)base.size() && (int)y < base[x]);\n        if\
    \ constexpr (sizeof...(Ts) == 0) return y;\n        else return y + base[x] *\
    \ _id(x + 1, ys...);\n    }\n\n    template <typename... Args> int id(Args...\
    \ args) {\n        static_assert(sizeof...(Args) > 0);\n        return _id(0,\
    \ args...);\n    }\n\n    template <typename... Args> mint &operator()(Args...\
    \ args) { return f[id(args...)]; }\n\n    mint &operator[](int i) { return f[i];\
    \ }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr> void display(OStream\
    \ &os) const {\n        for (int i = 0; i < (int)f.size(); i++) {\n          \
    \  int x = i;\n            os << \"f(\";\n            for (int j = 0; j < (int)base.size();\
    \ j++) {\n                os << x % base[j] << (j + 1 == (int)base.size() ? \"\
    ) = \" : \", \");\n                x /= base[j];\n            }\n            os\
    \ << f[i] << \"\\n\";\n        }\n    }\n\n    mfps &operator+=(const mfps &rhs)\
    \ {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n        for\
    \ (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];\n        return *this;\n\
    \    }\n\n    mfps &operator-=(const mfps &rhs) {\n        assert(base == rhs.base\
    \ && f.size() == rhs.f.size());\n        for (int i = 0; i < (int)f.size(); i++)\
    \ f[i] -= rhs.f[i];\n        return *this;\n    }\n\n    mfps &operator*=(const\
    \ mfps &rhs) {\n        assert(base == rhs.base && f.size() == rhs.f.size());\n\
    \        multi_convolution_truncated(f, rhs.f, base);\n        return *this;\n\
    \    }\n\n    mfps &operator+=(const mint &rhs) {\n        assert(!f.empty());\n\
    \        f[0] += rhs;\n        return *this;\n    }\n\n    mfps &operator-=(const\
    \ mint &rhs) {\n        assert(!f.empty());\n        f[0] -= rhs;\n        return\
    \ *this;\n    }\n\n    mfps &operator*=(const mint &rhs) {\n        for (auto\
    \ &x : f) x *= rhs;\n        return *this;\n    }\n\n    mfps &operator/=(const\
    \ mint &rhs) {\n        for (auto &x : f) x /= rhs;\n        return *this;\n \
    \   }\n\n    mfps operator+(const mfps &rhs) const { return mfps(*this) += rhs;\
    \ }\n\n    mfps operator-(const mfps &rhs) const { return mfps(*this) -= rhs;\
    \ }\n\n    mfps operator*(const mfps &rhs) const { return mfps(*this) *= rhs;\
    \ }\n\n    mfps operator+(const mint &rhs) const { return mfps(*this) += rhs;\
    \ }\n\n    mfps operator-(const mint &rhs) const { return mfps(*this) -= rhs;\
    \ }\n\n    mfps operator*(const mint &rhs) const { return mfps(*this) *= rhs;\
    \ }\n\n    mfps operator/(const mint &rhs) const { return mfps(*this) /= rhs;\
    \ }\n\n    mfps operator+() const { return mfps(*this); }\n\n    mfps operator-()\
    \ const { return mfps(base, -f); }\n\n    friend bool operator==(const mfps &lhs,\
    \ const mfps &rhs) {\n        return lhs.f == rhs.f && lhs.base == rhs.base;\n\
    \    }\n\n    friend bool operator!=(const mfps &lhs, const mfps &rhs) { return\
    \ !(lhs == rhs); }\n\n    mfps diff() const {\n        mfps ret(*this);\n    \
    \    for (int i = 0; i < (int)ret.f.size(); i++) ret.f[i] *= i;\n        return\
    \ ret;\n    }\n\n    mfps &inplace_diff() {\n        for (int i = 0; i < (int)f.size();\
    \ i++) f[i] *= i;\n        return *this;\n    }\n\n    static std::vector<mint>\
    \ _inv;\n\n    static void ensure_inv(int n) {\n        while ((int)_inv.size()\
    \ <= n) {\n            int i = _inv.size();\n            _inv.push_back((-_inv[mint::getmod()\
    \ % i]) * (mint::getmod() / i));\n        }\n    }\n\n    mfps integral() const\
    \ {\n        ensure_inv(f.size());\n        mfps ret(*this);\n        for (int\
    \ i = 1; i < (int)ret.f.size(); i++) ret.f[i] *= _inv[i];\n        return ret;\n\
    \    }\n\n    mfps &inplace_int() {\n        ensure_inv(f.size());\n        for\
    \ (int i = 1; i < (int)f.size(); i++) f[i] *= _inv[i];\n        return *this;\n\
    \    }\n\n    mfps inv() const {\n        assert(!f.empty() && f[0] != mint(0));\n\
    \        if (base.empty()) return mfps(base, fps{f[0].inv()});\n\n        int\
    \ n = f.size(), k = base.size();\n        int z = 1;\n        while (z < 2 * n\
    \ - 1) z <<= 1;\n        std::vector<int> chi(z);\n        for (int i = 0; i <\
    \ n; i++) {\n            int x = i;\n            for (int j = 0; j < k - 1; j++)\
    \ chi[i] += (x /= base[j]);\n            chi[i] %= k;\n        }\n        auto\
    \ naive_and_dot = [&k](const std::vector<fps> &a,\n                          \
    \        const std::vector<fps> &b,\n                                  std::vector<fps>\
    \ &c) -> void {\n            std::vector<mint> tmp(k);\n            for (int ii\
    \ = 0; ii < (int)a[0].size(); ii++) {\n                for (int i = 0; i < k;\
    \ i++) {\n                    for (int j = 0; j < k; j++) {\n                \
    \        tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];\n         \
    \           }\n                }\n                for (int i = 0; i < k; i++)\
    \ c[i][ii] = tmp[i], tmp[i] = mint{0};\n            }\n        };\n\n        //\
    \ reference:\n        // https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
    \        // Let g_k := f_k^{-1} mod x^k, \\deg g_k < k.\n        // Then we obtain\
    \ g_1, g_2, g_4, ... by using the following recurrence:\n        // - g_1 = (f_0)^{-1}\
    \ ...(1)\n        // - g_{2k} = 2g_k - g_k^2 f mod x^2k ...(2)\n        // - [x^{k\
    \ + i}]g_{2k} = [x^{k + i}](-g_k^2 f) ...(3)\n        fps g(z);\n        g[0]\
    \ = f[0].inv(); // by (1)\n        for (int d = 1; d < n; d <<= 1) {\n       \
    \     std::vector<fps> a(k, fps(2 * d)), b(k, fps(2 * d)), c(k, fps(2 * d));\n\
    \            for (int i = 0; i < std::min((int)f.size(), 2 * d); i++) a[chi[i]][i]\
    \ = f[i];\n            for (int i = 0; i < d; i++) b[chi[i]][i] = g[i];\n    \
    \        for (auto &x : a) x.but();\n            for (auto &x : b) x.but();\n\
    \            naive_and_dot(a, b, c);\n            for (auto &x : c) x.ibut();\n\
    \            // compute g_d f\n\n            for (auto &x : a) std::fill(std::begin(x),\
    \ std::end(x), mint(0));\n\n            for (int i = d; i < 2 * d; i++) a[chi[i]][i]\
    \ = c[chi[i]][i];\n            for (auto &x : a) x.but();\n            naive_and_dot(a,\
    \ b, c);\n            for (auto &x : c) x.ibut();\n            // compute g_d^2\
    \ f\n\n            // by (2), (3)\n            for (int i = d; i < 2 * d; i++)\
    \ g[i] = -c[chi[i]][i];\n        }\n        mfps res(*this);\n        res.f =\
    \ fps(std::begin(g), std::begin(g) + n);\n        return res;\n    }\n\n    mfps\
    \ log() const {\n        assert(!f.empty() && f[0] == mint(1));\n        return\
    \ ((*this).diff() * (*this).inv()).integral();\n    }\n\n    mfps exp() const\
    \ {\n        assert(!f.empty() && f[0] == mint(0));\n        int n = f.size();\n\
    \        mfps res(base, fps{1});\n        for (int d = 1; d < n; d <<= 1) {\n\
    \            int s = std::min(n, 2 * d);\n            res.f.resize(s, mint(0));\n\
    \            res *= mfps(base, fps(std::begin(f), std::begin(f) + s)) - res.log()\
    \ + 1;\n        }\n        return res;\n    }\n\n    mfps pow(long long e) const\
    \ {\n        assert(!f.empty());\n        if (f[0] != mint(0)) {\n           \
    \ mint f0inv = f[0].inv(), coef = f[0].pow(e);\n            return (((*this) *\
    \ f0inv).log() * e).exp() * coef;\n        }\n        int n = f.size();\n    \
    \    long long base_sum = 0;\n        for (auto &b : base) base_sum += b - 1;\n\
    \        if (e > base_sum) return mfps(base, fps(n));\n        mfps res(base,\
    \ fps(n)), a(*this);\n        res.f[0] = 1;\n        while (e) {\n           \
    \ if (e & 1) res *= a;\n            if (e >>= 1) a *= a;\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate <typename mint> std::vector<mint> MultivariateFormalPowerSeries<mint>::_inv\
    \ = {0, 1};\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_MULTIVARIATE_HPP\n"
  dependsOn:
  - convolution/multi_convolution_truncated.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/io.hpp
  - fps/fps_ntt_friendly.hpp
  - convolution/convolution.hpp
  - fps/fps_base.hpp
  - math_mod/inv_table.hpp
  isVerificationFile: false
  path: fps/fps_multivariate.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fps_multivariate.hpp
layout: document
redirect_from:
- /library/fps/fps_multivariate.hpp
- /library/fps/fps_multivariate.hpp.html
title: fps/fps_multivariate.hpp
---
