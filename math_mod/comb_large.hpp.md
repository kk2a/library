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
    path: fps/fps_base.hpp
    title: fps/fps_base.hpp
  - icon: ':question:'
    path: fps/fps_ntt_friendly.hpp
    title: fps/fps_ntt_friendly.hpp
  - icon: ':question:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':question:'
    path: fps/poly_sample_point_shift.hpp
    title: fps/poly_sample_point_shift.hpp
  - icon: ':question:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':question:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
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
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    title: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/comb_large.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <vector>\n\n#line 1 \"fps/fps_ntt_friendly.hpp\"\
    \n\n\n\n#line 6 \"fps/fps_ntt_friendly.hpp\"\n#include <iostream>\n#include <utility>\n\
    #line 9 \"fps/fps_ntt_friendly.hpp\"\n\n#line 1 \"convolution/convolution.hpp\"\
    \n\n\n\n#line 6 \"convolution/convolution.hpp\"\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\
    \n\n\n\n#line 1 \"bit/bitcount.hpp\"\n\n\n\n#line 5 \"bit/bitcount.hpp\"\n\n#line\
    \ 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace kk2\
    \ {\n\n#ifndef _MSC_VER\n\ntemplate <typename T> using is_signed_int128 =\n  \
    \  typename std::conditional<std::is_same<T, __int128_t>::value\n            \
    \                      or std::is_same<T, __int128>::value,\n                \
    \              std::true_type,\n                              std::false_type>::type;\n\
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
    \ m - 1);\n    return a;\n}\n\n} // namespace kk2\n\n\n#line 1 \"fps/fps_base.hpp\"\
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
    \ ? -_invs[n] : _invs[n];\n    }\n};\n\n} // namespace kk2\n\n\n#line 1 \"type_traits/io.hpp\"\
    \n\n\n\n#include <istream>\n#include <ostream>\n#line 7 \"type_traits/io.hpp\"\
    \n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag {};\nstruct\
    \ ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename T> using\
    \ is_standard_istream =\n    typename std::conditional<std::is_same<T, std::istream>::value\n\
    \                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 12 \"fps/fps_base.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ Derived, class mint> struct FormalPowerSeriesBase : std::vector<mint> {\n  \
    \  using std::vector<mint>::vector;\n    using FPS = Derived;\n    using ivta\
    \ = InvTable<mint>;\n\n    // CRTP\u3092\u4F7F\u3063\u3066\u6D3E\u751F\u30AF\u30E9\
    \u30B9\u306E\u53C2\u7167\u3092\u53D6\u5F97\n    Derived &derived() { return static_cast<Derived\
    \ &>(*this); }\n    const Derived &derived() const { return static_cast<const\
    \ Derived &>(*this); }\n\n    template <class OStream, is_ostream_t<OStream> *\
    \ = nullptr>\n    void debug_output(OStream &os) const {\n        os << \"[\"\
    ;\n        for (size_t i = 0; i < this->size(); i++) {\n            os << (*this)[i]\
    \ << (i + 1 == this->size() ? \"\" : \", \");\n        }\n        os << \"]\"\
    ;\n    }\n\n    template <class OStream, is_ostream_t<OStream> * = nullptr> void\
    \ output(OStream &os) const {\n        for (size_t i = 0; i < this->size(); i++)\
    \ {\n            os << (*this)[i] << (i + 1 == this->size() ? \"\\n\" : \" \"\
    );\n        }\n    }\n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n\
    \    friend OStream &operator<<(OStream &os, const FPS &fps_) {\n        for (size_t\
    \ i = 0; i < fps_.size(); i++) {\n            os << fps_[i] << (i + 1 == fps_.size()\
    \ ? \"\" : \" \");\n        }\n        return os;\n    }\n\n    template <class\
    \ IStream, is_istream_t<IStream> * = nullptr> FPS &input(IStream &is) {\n    \
    \    for (size_t i = 0; i < this->size(); i++) is >> (*this)[i];\n        return\
    \ derived();\n    }\n\n    template <class IStream, is_istream_t<IStream> * =\
    \ nullptr>\n    friend IStream &operator>>(IStream &is, FPS &fps_) {\n       \
    \ for (auto &x : fps_) is >> x;\n        return is;\n    }\n    FPS &operator+=(const\
    \ FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n  \
    \      for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        return\
    \ derived();\n    }\n\n    FPS &operator+=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += r;\n        return derived();\n    }\n\
    \n    FPS &operator-=(const FPS &r) {\n        if (this->size() < r.size()) this->resize(r.size());\n\
    \        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        return\
    \ derived();\n    }\n\n    FPS &operator-=(const mint &r) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= r;\n        return derived();\n    }\n\
    \n    FPS &operator*=(const mint &r) {\n        for (size_t i = 0; i < this->size();\
    \ i++) { (*this)[i] *= r; }\n        return derived();\n    }\n    FPS &operator/=(const\
    \ FPS &r) {\n        assert(!r.empty());\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return derived();\n        }\n  \
    \      int n = this->size() - r.size() + 1;\n        if (r.size() <= 64) {\n \
    \           FPS f(derived()), g(r);\n            g.shrink();\n            mint\
    \ coeff = g.back().inv();\n            for (auto &x : g) x *= coeff;\n       \
    \     int deg = (int)f.size() - (int)g.size() + 1;\n            int gs = g.size();\n\
    \            FPS quo(deg);\n            for (int i = deg - 1; i >= 0; i--) {\n\
    \                quo[i] = f[i + gs - 1];\n                for (int j = 0; j <\
    \ gs; j++) f[i + j] -= quo[i] * g[j];\n            }\n            *this = quo\
    \ * coeff;\n            this->resize(n, mint(0));\n            return derived();\n\
    \        }\n        return derived() = (derived().rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS &operator%=(const FPS &r) {\n        derived() -= derived()\
    \ / r * r;\n        shrink();\n        return derived();\n    }\n\n    FPS &operator>>=(int\
    \ n) {\n        if (n >= (int)this->size()) {\n            this->clear();\n  \
    \      } else {\n            this->erase(this->begin(), this->begin() + n);\n\
    \        }\n        return derived();\n    }\n\n    FPS &operator<<=(int n) {\n\
    \        this->insert(this->begin(), n, mint(0));\n        return derived();\n\
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
    \ kk2\n\n\n#line 1 \"fps/poly_sample_point_shift.hpp\"\n\n\n\n#line 6 \"fps/poly_sample_point_shift.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    std::vector<mint> sample_point_shift(std::vector<mint> &y, mint t, int m = -1)\
    \ {\n    if (m == -1) m = y.size();\n    long long tval = t.val();\n    int k\
    \ = (int)y.size() - 1;\n    if (tval <= k) {\n        std::vector<mint> ret(m);\n\
    \        int ptr = 0;\n        for (long long i = tval; i <= k and ptr < m; i++)\
    \ { ret[ptr++] = y[i]; }\n        if (k + 1 < tval + m) {\n            auto suf\
    \ = sample_point_shift<FPS>(y, mint(k + 1), m - ptr);\n            for (int i\
    \ = k + 1; i < tval + m; i++) { ret[ptr++] = suf[i - (k + 1)]; }\n        }\n\
    \        return ret;\n    }\n    if (tval + m > mint::getmod()) {\n        auto\
    \ pref = sample_point_shift<FPS>(y, t, mint::getmod() - tval);\n        auto suf\
    \ = sample_point_shift<FPS>(y, mint(0), m + tval - (int)mint::getmod());\n   \
    \     std::copy(std::begin(suf), std::end(suf), std::back_inserter(pref));\n \
    \       return pref;\n    }\n\n    std::vector<mint> inv(k + 1, 1);\n    FPS d(k\
    \ + 1);\n    for (int i = 2; i <= k; i++) inv[k] *= i;\n    inv[k] = inv[k].inv();\n\
    \    for (int i = k; i >= 1; i--) inv[i - 1] = inv[i] * i;\n    for (int i = 0;\
    \ i <= k; i++) {\n        d[i] = inv[i] * inv[k - i] * y[i];\n        if ((k -\
    \ i) & 1) d[i] = -d[i];\n    }\n\n    FPS h(m + k);\n    for (int i = 0; i < m\
    \ + k; i++) { h[i] = (t - k + i).inv(); }\n\n    FPS dh = d * h;\n\n    std::vector<mint>\
    \ ret(m);\n    mint cur = t;\n    for (int i = 1; i <= k; i++) cur *= t - i;\n\
    \    for (int i = 0; i < m; i++) {\n        ret[i] = cur * dh[k + i];\n      \
    \  cur *= t + i + 1;\n        cur *= h[i];\n    }\n    return ret;\n}\n\n} //\
    \ namespace kk2\n\n\n#line 1 \"math_mod/comb.hpp\"\n\n\n\n#line 7 \"math_mod/comb.hpp\"\
    \n\n#line 9 \"math_mod/comb.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint>\
    \ struct Comb {\n    static inline std::vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\
    \n    Comb() = delete;\n\n    static void set_upper(int m = -1) {\n        int\
    \ n = (int)_fact.size();\n        if (m == -1) m = n << 1;\n        if (n > m)\
    \ return;\n        m = std::min<long long>(m, mint::getmod() - 1);\n        _fact.resize(m\
    \ + 1);\n        _ifact.resize(m + 1);\n        _inv.resize(m + 1);\n        for\
    \ (int i = n; i <= m; i++) _fact[i] = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n\
    \        _inv[m] = _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--)\
    \ {\n            _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i\
    \ - 1] * _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n  \
    \      if (n < 0) return 0;\n        if ((int)_fact.size() <= n) set_upper(n);\n\
    \        return _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if\
    \ (n < 0) return 0;\n        if ((int)_ifact.size() <= n) set_upper(n);\n    \
    \    return _ifact[n];\n    }\n\n    static mint inv(int n) {\n        if (n <\
    \ 0) return -inv(-n);\n        if ((int)_inv.size() <= n) set_upper(n);\n    \
    \    return _inv[n];\n    }\n\n    static mint binom(int n, int k) {\n       \
    \ if (k < 0 || k > n) return 0;\n        return fact(n) * ifact(k) * ifact(n -\
    \ k);\n    }\n\n    template <class T> static mint multinomial(const std::vector<T>\
    \ &r) {\n        static_assert(is_integral<T>::value, \"T must be integral\");\n\
    \        int n = 0;\n        for (auto &x : r) {\n            if (x < 0) return\
    \ 0;\n            n += x;\n        }\n        mint res = fact(n);\n        for\
    \ (auto &x : r) res *= ifact(x);\n        return res;\n    }\n\n    static mint\
    \ binom_naive(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
    \        mint res = 1;\n        k = std::min(k, n - k);\n        for (int i =\
    \ 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    static\
    \ mint permu(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
    \        return fact(n) * ifact(n - k);\n    }\n\n    static mint homo(int n,\
    \ int k) {\n        if (n < 0 || k < 0) return 0;\n        return k == 0 ? 1 :\
    \ binom(n + k - 1, k);\n    }\n};\n\n} // namespace kk2\n\n\n#line 13 \"math_mod/comb_large.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class mint> struct CombLarge {\n    using FPS\
    \ = FormalPowerSeriesNTTFriendly<mint>;\n    static constexpr int LOG_BLOCK_SIZE\
    \ = 9;\n    static constexpr int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;\n    static\
    \ constexpr int BLOCK_NUM = mint::getmod() >> LOG_BLOCK_SIZE;\n\n    static inline\
    \ int threshold = 2000000;\n\n    CombLarge() = delete;\n\n    static mint fact(int\
    \ n) { return n <= threshold ? Comb<mint>::fact(n) : _large_fact(n); }\n\n   \
    \ static mint ifact(int n) {\n        return n <= threshold ? Comb<mint>::ifact(n)\
    \ : _large_fact(n).inv();\n    }\n\n    static mint inv(int n) { return n <= threshold\
    \ ? Comb<mint>::inv(n) : mint(n).inv(); }\n\n    static mint binom(int n, int\
    \ r) {\n        if (r < 0 || r > n) return mint(0);\n        return fact(n) *\
    \ ifact(r) * ifact(n - r);\n    }\n\n    template <class T> static mint multinomial(std::vector<T>\
    \ r) {\n        static_assert(is_integral<T>::value, \"T must be integral\");\n\
    \        long long n = 0;\n        for (auto &x : r) {\n            assert(x >=\
    \ 0);\n            n += x;\n        }\n        if (n >= mint::getmod()) return\
    \ 0;\n        mint res = fact(n);\n        for (auto &x : r) res *= ifact(x);\n\
    \        return res;\n    }\n\n    static mint permu(int n, int r) {\n       \
    \ if (r < 0 || r > n) return mint(0);\n        return fact(n) * ifact(n - r);\n\
    \    }\n\n    static mint homo(int n, int r) {\n        if (n < 0 || r < 0) return\
    \ mint(0);\n        return r == 0 ? 1 : binom(n + r - 1, r);\n    }\n\n  private:\n\
    \    static inline std::vector<mint> _block_fact{};\n\n    static void _build()\
    \ {\n        if (_block_fact.size()) return;\n        std::vector<mint> f{1};\n\
    \        f.reserve(BLOCK_SIZE);\n        for (int i = 0; i < LOG_BLOCK_SIZE; i++)\
    \ {\n            std::vector<mint> g = sample_point_shift<FPS>(f, mint(1 << i),\
    \ 3 << i);\n            const auto get = [&](int j) {\n                return\
    \ j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n            f.resize(2\
    \ << i);\n            for (int j = 0; j < 2 << i; j++) {\n                f[j]\
    \ = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n            }\n       \
    \ }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            std::vector<mint> g\
    \ =\n                sample_point_shift<FPS>(f, mint(BLOCK_SIZE), BLOCK_NUM -\
    \ BLOCK_SIZE);\n            std::move(std::begin(g), std::end(g), std::back_inserter(f));\n\
    \        } else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM; i++)\
    \ { f[i] *= mint(i + 1) * BLOCK_SIZE; }\n        // f[i] = prod_{j = 1} ^ (BLOCK_SIZE)\
    \ (i * BLOCK_SIZE + j)\n\n        f.insert(std::begin(f), 1);\n        for (int\
    \ i = 1; i <= BLOCK_NUM; i++) { f[i] *= f[i - 1]; }\n        _block_fact = std::move(f);\n\
    \    }\n\n    static mint _large_fact(int n) {\n        _build();\n        mint\
    \ res;\n        int q = n / BLOCK_SIZE, r = n % BLOCK_SIZE;\n        if (2 * r\
    \ <= BLOCK_SIZE) {\n            res = _block_fact[q];\n            for (int i\
    \ = 0; i < r; i++) { res *= n - i; }\n        } else if (q != BLOCK_NUM) {\n \
    \           res = _block_fact[q + 1];\n            mint den = 1;\n           \
    \ for (int i = 1; i <= BLOCK_SIZE - r; i++) { den *= n + i; }\n            res\
    \ /= den;\n        } else {\n            res = -1;\n            mint den = 1;\n\
    \            for (int i = mint::getmod() - 1; i > n; i++) { den *= i; }\n    \
    \        res /= den;\n        }\n        return res;\n    }\n};\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_MATH_MOD_COMB_LARGE_HPP\n#define KK2_MATH_MOD_COMB_LARGE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\n#include \"../fps/fps_ntt_friendly.hpp\"\n#include \"../fps/poly_sample_point_shift.hpp\"\
    \n#include \"../type_traits/integral.hpp\"\n#include \"comb.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class mint> struct CombLarge {\n    using FPS = FormalPowerSeriesNTTFriendly<mint>;\n\
    \    static constexpr int LOG_BLOCK_SIZE = 9;\n    static constexpr int BLOCK_SIZE\
    \ = 1 << LOG_BLOCK_SIZE;\n    static constexpr int BLOCK_NUM = mint::getmod()\
    \ >> LOG_BLOCK_SIZE;\n\n    static inline int threshold = 2000000;\n\n    CombLarge()\
    \ = delete;\n\n    static mint fact(int n) { return n <= threshold ? Comb<mint>::fact(n)\
    \ : _large_fact(n); }\n\n    static mint ifact(int n) {\n        return n <= threshold\
    \ ? Comb<mint>::ifact(n) : _large_fact(n).inv();\n    }\n\n    static mint inv(int\
    \ n) { return n <= threshold ? Comb<mint>::inv(n) : mint(n).inv(); }\n\n    static\
    \ mint binom(int n, int r) {\n        if (r < 0 || r > n) return mint(0);\n  \
    \      return fact(n) * ifact(r) * ifact(n - r);\n    }\n\n    template <class\
    \ T> static mint multinomial(std::vector<T> r) {\n        static_assert(is_integral<T>::value,\
    \ \"T must be integral\");\n        long long n = 0;\n        for (auto &x : r)\
    \ {\n            assert(x >= 0);\n            n += x;\n        }\n        if (n\
    \ >= mint::getmod()) return 0;\n        mint res = fact(n);\n        for (auto\
    \ &x : r) res *= ifact(x);\n        return res;\n    }\n\n    static mint permu(int\
    \ n, int r) {\n        if (r < 0 || r > n) return mint(0);\n        return fact(n)\
    \ * ifact(n - r);\n    }\n\n    static mint homo(int n, int r) {\n        if (n\
    \ < 0 || r < 0) return mint(0);\n        return r == 0 ? 1 : binom(n + r - 1,\
    \ r);\n    }\n\n  private:\n    static inline std::vector<mint> _block_fact{};\n\
    \n    static void _build() {\n        if (_block_fact.size()) return;\n      \
    \  std::vector<mint> f{1};\n        f.reserve(BLOCK_SIZE);\n        for (int i\
    \ = 0; i < LOG_BLOCK_SIZE; i++) {\n            std::vector<mint> g = sample_point_shift<FPS>(f,\
    \ mint(1 << i), 3 << i);\n            const auto get = [&](int j) {\n        \
    \        return j < (1 << i) ? f[j] : g[j - (1 << i)];\n            };\n     \
    \       f.resize(2 << i);\n            for (int j = 0; j < 2 << i; j++) {\n  \
    \              f[j] = get(2 * j) * get(2 * j + 1) * ((2 * j + 1) << i);\n    \
    \        }\n        }\n\n        if (BLOCK_NUM > BLOCK_SIZE) {\n            std::vector<mint>\
    \ g =\n                sample_point_shift<FPS>(f, mint(BLOCK_SIZE), BLOCK_NUM\
    \ - BLOCK_SIZE);\n            std::move(std::begin(g), std::end(g), std::back_inserter(f));\n\
    \        } else f.resize(BLOCK_NUM);\n        for (int i = 0; i < BLOCK_NUM; i++)\
    \ { f[i] *= mint(i + 1) * BLOCK_SIZE; }\n        // f[i] = prod_{j = 1} ^ (BLOCK_SIZE)\
    \ (i * BLOCK_SIZE + j)\n\n        f.insert(std::begin(f), 1);\n        for (int\
    \ i = 1; i <= BLOCK_NUM; i++) { f[i] *= f[i - 1]; }\n        _block_fact = std::move(f);\n\
    \    }\n\n    static mint _large_fact(int n) {\n        _build();\n        mint\
    \ res;\n        int q = n / BLOCK_SIZE, r = n % BLOCK_SIZE;\n        if (2 * r\
    \ <= BLOCK_SIZE) {\n            res = _block_fact[q];\n            for (int i\
    \ = 0; i < r; i++) { res *= n - i; }\n        } else if (q != BLOCK_NUM) {\n \
    \           res = _block_fact[q + 1];\n            mint den = 1;\n           \
    \ for (int i = 1; i <= BLOCK_SIZE - r; i++) { den *= n + i; }\n            res\
    \ /= den;\n        } else {\n            res = -1;\n            mint den = 1;\n\
    \            for (int i = mint::getmod() - 1; i > n; i++) { den *= i; }\n    \
    \        res /= den;\n        }\n        return res;\n    }\n};\n\n} // namespace\
    \ kk2\n\n#endif // KK2_MATH_MOD_COMB_LARGE_HPP\n"
  dependsOn:
  - fps/fps_ntt_friendly.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - fps/fps_base.hpp
  - math_mod/inv_table.hpp
  - type_traits/io.hpp
  - fps/poly_sample_point_shift.hpp
  - type_traits/integral.hpp
  - math_mod/comb.hpp
  isVerificationFile: false
  path: math_mod/comb_large.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
documentation_of: math_mod/comb_large.hpp
layout: document
redirect_from:
- /library/math_mod/comb_large.hpp
- /library/math_mod/comb_large.hpp.html
title: math_mod/comb_large.hpp
---
