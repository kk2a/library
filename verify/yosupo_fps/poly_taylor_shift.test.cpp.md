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
  - icon: ':heavy_check_mark:'
    path: fps/poly_taylor_shift.hpp
    title: fps/poly_taylor_shift.hpp
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
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_taylor_shift
    links:
    - https://judge.yosupo.jp/problem/polynomial_taylor_shift
  bundledCode: "#line 1 \"verify/yosupo_fps/poly_taylor_shift.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\" \n\n#line\
    \ 1 \"fps/fps_ntt_friendly.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"convolution/convolution.hpp\"\
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
    \ kk2\n\n\n#line 1 \"fps/poly_taylor_shift.hpp\"\n\n\n\n#line 5 \"fps/poly_taylor_shift.hpp\"\
    \n\n#line 1 \"math_mod/comb.hpp\"\n\n\n\n#line 7 \"math_mod/comb.hpp\"\n\n#line\
    \ 9 \"math_mod/comb.hpp\"\n\nnamespace kk2 {\n\ntemplate <class mint> struct Comb\
    \ {\n    static inline std::vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n   \
    \ Comb() = delete;\n\n    static void set_upper(int m = -1) {\n        int n =\
    \ (int)_fact.size();\n        if (m == -1) m = n << 1;\n        if (n > m) return;\n\
    \        m = std::min<long long>(m, mint::getmod() - 1);\n        _fact.resize(m\
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
    \ binom(n + k - 1, k);\n    }\n};\n\n} // namespace kk2\n\n\n#line 7 \"fps/poly_taylor_shift.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS taylor_shift(const FPS &f_, mint a) {\n    FPS f(f_);\n    int n = f.size();\n\
    \    Comb<mint>::set_upper(n);\n    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::fact(i);\n\
    \    f.inplace_rev();\n    FPS g(n, mint(1));\n    for (int i = 1; i < n; i++)\
    \ g[i] = g[i - 1] * a * Comb<mint>::inv(i);\n    f = (f * g).pre(n).rev();\n \
    \   for (int i = 0; i < n; i++) f[i] *= Comb<mint>::ifact(i);\n    return f;\n\
    }\n\n} // namespace kk2\n\n\n#line 1 \"modint/mont.hpp\"\n\n\n\n#line 5 \"modint/mont.hpp\"\
    \n#include <cstdint>\n#line 8 \"modint/mont.hpp\"\n\n#line 11 \"modint/mont.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <int p> struct LazyMontgomeryModInt {\n    using\
    \ mint = LazyMontgomeryModInt;\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static constexpr\
    \ u32 get_r() {\n        u32 ret = p;\n        for (int i = 0; i < 4; ++i) ret\
    \ *= 2 - p * ret;\n        return ret;\n    }\n\n    static constexpr u32 r =\
    \ get_r();\n    static constexpr u32 n2 = -u64(p) % p;\n    static_assert(r *\
    \ p == 1, \"invalid, r * p != 1\");\n    static_assert(p < (1 << 30), \"invalid,\
    \ p >= 2 ^ 30\");\n    static_assert((p & 1) == 1, \"invalid, p % 2 == 0\");\n\
    \n    u32 _v;\n\n    constexpr LazyMontgomeryModInt() : _v(0) {}\n\n    template\
    \ <typename T, is_integral_t<T> * = nullptr> constexpr LazyMontgomeryModInt(T\
    \ b)\n        : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr u32\
    \ reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * p) >> 32; }\n   \
    \ constexpr mint &operator++() { return *this += 1; }\n    constexpr mint &operator--()\
    \ { return *this -= 1; }\n\n    constexpr mint operator++(int) {\n        mint\
    \ ret = *this;\n        *this += 1;\n        return ret;\n    }\n\n    constexpr\
    \ mint operator--(int) {\n        mint ret = *this;\n        *this -= 1;\n   \
    \     return ret;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n\
    \        if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n\
    \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(_v\
    \ -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr mint\
    \ &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n       \
    \ return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b) {\n  \
    \      *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr bool\
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
    \ namespace kk2\n\n\n#line 1 \"template/template.hpp\"\n\n\n\n#line 5 \"template/template.hpp\"\
    \n#include <array>\n#include <bitset>\n#line 8 \"template/template.hpp\"\n#include\
    \ <chrono>\n#include <cmath>\n#include <deque>\n#include <functional>\n#include\
    \ <iterator>\n#include <limits>\n#include <map>\n#include <numeric>\n#include\
    \ <optional>\n#include <queue>\n#include <random>\n#include <set>\n#include <stack>\n\
    #include <string>\n#include <unordered_map>\n#include <unordered_set>\n#line 26\
    \ \"template/template.hpp\"\n\n#line 1 \"template/constant.hpp\"\n\n\n\n#line\
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
    \ { return (a > b ? a = b, 1 : 0); }\n\n\n#line 7 \"verify/yosupo_fps/poly_taylor_shift.test.cpp\"\
    \nusing namespace std;\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\nint main()\
    \ {\n    int n;\n    kk2::mont998 c;\n    kin >> n >> c;\n    FPS f(n);\n    kin\
    \ >> f;\n    kout << kk2::taylor_shift(f, c) << kendl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_taylor_shift\"\
    \ \n\n#include \"../../fps/fps_ntt_friendly.hpp\"\n#include \"../../fps/poly_taylor_shift.hpp\"\
    \n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nusing FPS = kk2::FPSNTT<kk2::mont998>;\n\nint main()\
    \ {\n    int n;\n    kk2::mont998 c;\n    kin >> n >> c;\n    FPS f(n);\n    kin\
    \ >> f;\n    kout << kk2::taylor_shift(f, c) << kendl;\n\n    return 0;\n}\n"
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
  - fps/poly_taylor_shift.hpp
  - math_mod/comb.hpp
  - type_traits/integral.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_fps/poly_taylor_shift.test.cpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_fps/poly_taylor_shift.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_fps/poly_taylor_shift.test.cpp
- /verify/verify/yosupo_fps/poly_taylor_shift.test.cpp.html
title: verify/yosupo_fps/poly_taylor_shift.test.cpp
---
