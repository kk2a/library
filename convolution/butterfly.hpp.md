---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':warning:'
    path: convolution/multi_convo_truncated.hpp
    title: convolution/multi_convo_truncated.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/butterfly.hpp\"\n\n\n\n#include <algorithm>\n\
    \n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
    \n\n\n\n#include <cassert>\n#line 1 \"type_traits/type_traits.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\ntemplate <typename T>\nusing is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value\n           \
    \                                            or std::is_same<T, __int128>::value,\n\
    \                                                   std::true_type,\n        \
    \                                           std::false_type>::type;\n\ntemplate\
    \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
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
    \ std::false_type>::type;\n\n} // namespace kk2\n\n\n#line 6 \"math_mod/pow_mod.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U>\nconstexpr S pow_mod(T\
    \ x, U n, T m) {\n    assert(!is_signed_extended<U>::value || n >= 0);\n    if\
    \ (m == 1) return S(0);\n    S _m = S(m), r = 1;\n    S y = S(x) % _m;\n    if\
    \ (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n  \
    \      y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace kk2 {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    if (m == 1107296257) return\
    \ 10;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) { x /= i; }\n        }\n    }\n    if (x > 1) {\
    \ divs[cnt++] = x; }\n    for (int g = 2;; g++) {\n        bool ok = true;\n \
    \       for (int i = 0; i < cnt; i++) {\n            if (pow_mod<long long>(g,\
    \ (m - 1) / divs[i], m) == 1) {\n                ok = false;\n               \
    \ break;\n            }\n        }\n        if (ok) return g;\n    }\n}\n\ntemplate\
    \ <int m>\nstatic constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n} // namespace kk2\n\n\n#line 7 \"convolution/butterfly.hpp\"\n\nnamespace kk2\
    \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nvoid butterfly(FPS\
    \ &a) {\n    static int g = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n\
    \    int h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool\
    \ first = true;\n    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i\
    \ - 1] * es[i]\n    static mint sum_e3[30];\n    static mint es[30], ies[30];\
    \ // es[i]^(2^(2+i)) == 1\n    if (first) {\n        first = false;\n        int\
    \ cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint e = mint(g).pow((mint::getmod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_e2[i] =\
    \ es[i] * now;\n            now *= ies[i];\n        }\n        now = 1;\n    \
    \    for (int i = 0; i <= cnt2 - 3; i++) {\n            sum_e3[i] = es[i + 1]\
    \ * now;\n            now *= ies[i + 1];\n        }\n    }\n\n    int len = 0;\n\
    \    while (len < h) {\n        if (h - len == 1) {\n            int p = 1 <<\
    \ (h - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1\
    \ << len); s++) {\n                int offset = s << (h - len);\n            \
    \    for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len))\n                    rot\
    \ *= sum_e2[__builtin_ctz(~(unsigned int)(s))];\n            }\n            len++;\n\
    \        } else {\n            int p = 1 << (h - len - 2);\n            mint rot\
    \ = 1, imag = es[0];\n            for (int s = 0; s < (1 << len); s++) {\n   \
    \             mint rot2 = rot * rot;\n                mint rot3 = rot2 * rot;\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto a0 = a[i + offset];\n              \
    \      auto a1 = a[i + offset + p] * rot;\n                    auto a2 = a[i +\
    \ offset + p * 2] * rot2;\n                    auto a3 = a[i + offset + p * 3]\
    \ * rot3;\n                    auto a1na3imag = (a1 - a3) * imag;\n          \
    \          a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset\
    \ + p] = a0 + a2 - a1 - a3;\n                    a[i + offset + p * 2] = a0 -\
    \ a2 + a1na3imag;\n                    a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n\
    \                }\n                if (s + 1 != (1 << len))\n               \
    \     rot *= sum_e3[__builtin_ctz(~(unsigned int)(s))];\n            }\n     \
    \       len += 2;\n        }\n    }\n}\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nvoid butterfly_inv(FPS &a) {\n    static constexpr int g =\
    \ primitive_root<mint::getmod()>;\n    int n = int(a.size());\n    int h = 0;\n\
    \    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool first = true;\n\
    \    static mint sum_ie2[30]; // sum_ie[i] = es[0] * ... * es[i - 1] * ies[i]\n\
    \    static mint sum_ie3[30];\n    static mint es[30], ies[30]; // es[i]^(2^(2+i))\
    \ == 1\n    static mint invn[30];\n    if (first) {\n        first = false;\n\
    \        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n        mint e = mint(g).pow((mint::getmod()\
    \ - 1) >> cnt2), ie = e.inv();\n        for (int i = cnt2; i >= 2; i--) {\n  \
    \          // e^(2^i) == 1\n            es[i - 2] = e;\n            ies[i - 2]\
    \ = ie;\n            e *= e;\n            ie *= ie;\n        }\n        mint now\
    \ = 1;\n        for (int i = 0; i <= cnt2 - 2; i++) {\n            sum_ie2[i]\
    \ = ies[i] * now;\n            now *= es[i];\n        }\n        now = 1;\n  \
    \      for (int i = 0; i <= cnt2 - 3; i++) {\n            sum_ie3[i] = ies[i +\
    \ 1] * now;\n            now *= es[i + 1];\n        }\n\n        invn[0] = 1;\n\
    \        invn[1] = mint::getmod() / 2 + 1;\n        for (int i = 2; i < 30; i++)\
    \ invn[i] = invn[i - 1] * invn[1];\n    }\n    int len = h;\n    while (len) {\n\
    \        if (len == 1) {\n            int p = 1 << (h - len);\n            mint\
    \ irot = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n      \
    \          int offset = s << (h - len + 1);\n                for (int i = 0; i\
    \ < p; i++) {\n                    auto l = a[i + offset];\n                 \
    \   auto r = a[i + offset + p];\n                    a[i + offset] = l + r;\n\
    \                    a[i + offset + p] = (l - r) * irot;\n                }\n\
    \                if (s + 1 != (1 << (len - 1)))\n                    irot *= sum_ie2[__builtin_ctz(~(unsigned\
    \ int)(s))];\n            }\n            len--;\n        } else {\n          \
    \  int p = 1 << (h - len);\n            mint irot = 1, iimag = ies[0];\n     \
    \       for (int s = 0; s < (1 << ((len - 2))); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = a[i + offset];\n                    auto a1\
    \ = a[i + offset + p];\n                    auto a2 = a[i + offset + p * 2];\n\
    \                    auto a3 = a[i + offset + p * 3];\n                    auto\
    \ a2na3iimag = (a2 - a3) * iimag;\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + p] = (a0 - a1 + a2na3iimag)\
    \ * irot;\n                    a[i + offset + p * 2] = (a0 + a1 - a2 - a3) * irot2;\n\
    \                    a[i + offset + p * 3] = (a0 - a1 - a2na3iimag) * irot3;\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= sum_ie3[__builtin_ctz(~(unsigned int)(s))];\n            }\n\
    \            len -= 2;\n        }\n    }\n\n    for (int i = 0; i < n; i++) a[i]\
    \ *= invn[h];\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    void doubling(FPS &a) {\n    int n = a.size();\n    auto b = a;\n    int z = 1;\n\
    \    butterfly_inv(b);\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>)\n\
    \                           .pow((mint::getmod() - 1) / (n << 1));\n    for (int\
    \ i = 0; i < n; i++) {\n        b[i] *= r;\n        r *= zeta;\n    }\n    butterfly(b);\n\
    \    std::copy(b.begin(), b.end(), std::back_inserter(a));\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef BUTTERFLY_HPP\n#define BUTTERFLY_HPP 1\n\n#include <algorithm>\n\n\
    #include \"../math_mod/primitive_root.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nvoid butterfly(FPS &a) {\n    static\
    \ int g = primitive_root<mint::getmod()>;\n    int n = int(a.size());\n    int\
    \ h = 0;\n    while ((1U << h) < (unsigned int)(n)) h++;\n    static bool first\
    \ = true;\n    static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i - 1]\
    \ * es[i]\n    static mint sum_e3[30];\n    static mint es[30], ies[30]; // es[i]^(2^(2+i))\
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
    \ kk2\n\n#endif // BUTTERFLY_HPP\n"
  dependsOn:
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: convolution/butterfly.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - convolution/convolution.hpp
  - convolution/convo_arb.hpp
  - convolution/multi_convo_truncated.hpp
  - fps/fps_arb.hpp
  - fps/ntt_friendly.hpp
  - fps/multivariate_fps.hpp
  timestamp: '2024-09-29 16:53:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
documentation_of: convolution/butterfly.hpp
layout: document
redirect_from:
- /library/convolution/butterfly.hpp
- /library/convolution/butterfly.hpp.html
title: convolution/butterfly.hpp
---
