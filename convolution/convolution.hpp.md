---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':x:'
    path: math_mod/pow_expr.hpp
    title: math_mod/pow_expr.hpp
  - icon: ':x:'
    path: math_mod/primitive_rt_expr.hpp
    title: math_mod/primitive_rt_expr.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/convo_arb.hpp
    title: convolution/convo_arb.hpp
  - icon: ':warning:'
    path: convolution/multi_convo_truncated.hpp
    title: convolution/multi_convo_truncated.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':x:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':warning:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_exp.test.cpp
    title: verify/yosupo_fps/fps_exp.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_inv.test.cpp
    title: verify/yosupo_fps/fps_inv.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_log.test.cpp
    title: verify/yosupo_fps/fps_log.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_pow.test.cpp
    title: verify/yosupo_fps/fps_pow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/convolution.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n#line 1 \"convolution/butterfly.hpp\"\n\n\n\n#line 1 \"\
    math_mod/primitive_rt_expr.hpp\"\n\n\n\n#line 1 \"math_mod/pow_expr.hpp\"\n\n\n\
    \nnamespace kk2 {\n\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, long long m) {\n    if (m == 1) return 0;\n    unsigned long long _m = (unsigned\
    \ long long)(m);\n    unsigned long long r = 1;\n    unsigned long long y = (x\
    \ % m + m) % m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n     \
    \   y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n} // namespace\
    \ kk2\n\n\n#line 5 \"math_mod/primitive_rt_expr.hpp\"\n\nnamespace kk2 {\n\nconstexpr\
    \ int primitive_root_constexpr(int m) {\n    if (m == 2) return 1;\n    if (m\
    \ == 167772161) return 3;\n    if (m == 469762049) return 3;\n    if (m == 754974721)\
    \ return 11;\n    if (m == 998244353) return 3;\n    if (m == 1107296257) return\
    \ 10;\n    int divs[20] = {}; \n    divs[0] = 2;\n    int cnt = 1;\n    int x\
    \ = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> static constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\n#line 6 \"convolution/butterfly.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    void butterfly(FPS& a) {\n    static int g = primitive_root<mint::getmod()>;\n\
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
    \ 1;\n    mint invz = mint(z).inv();\n    butterfly_inv(b);\n    for (int i =\
    \ 0; i < b.size(); i++) b[i] *= invz;\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>).\n\
    \                       pow((mint::getmod() - 1) / (n << 1));\n    for (int i\
    \ = 0; i < n; i++) {\n        b[i] *= r;\n        r *= zeta;\n    }\n    butterfly(b);\n\
    \    std::copy(b.begin(), b.end(), std::back_inserter(a));\n}\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"convolution/convolution.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution(FPS& a,\
    \ const FPS& b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n ||\
    \ !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m - 1);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                res[i + j] += a[i] * b[j];\n            }\n        }\n  \
    \      a = res;\n        return a;\n    }\n    int z = 1;\n    while (z < n +\
    \ m - 1) z <<= 1;\n    if (a == b) {\n        a.resize(z);\n        butterfly(a);\n\
    \        for (int i = 0; i < z; i++) a[i] *= a[i];\n    }\n    else {\n      \
    \  a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(), b.end());\n \
    \       t.resize(z);\n        butterfly(t);\n        for (int i = 0; i < z; i++)\
    \ a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n    mint\
    \ iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n \
    \   return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_HPP\n#define CONVOLUTION_HPP 1\n\n#include <vector>\n\
    #include <algorithm>\n#include \"butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution(FPS& a,\
    \ const FPS& b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n ||\
    \ !m) return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m - 1);\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ {\n                res[i + j] += a[i] * b[j];\n            }\n        }\n  \
    \      a = res;\n        return a;\n    }\n    int z = 1;\n    while (z < n +\
    \ m - 1) z <<= 1;\n    if (a == b) {\n        a.resize(z);\n        butterfly(a);\n\
    \        for (int i = 0; i < z; i++) a[i] *= a[i];\n    }\n    else {\n      \
    \  a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(), b.end());\n \
    \       t.resize(z);\n        butterfly(t);\n        for (int i = 0; i < z; i++)\
    \ a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(n + m - 1);\n    mint\
    \ iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n \
    \   return a;\n}\n\n} // namespace kk2\n\n#endif  // CONVOLUTION_HPP\n"
  dependsOn:
  - convolution/butterfly.hpp
  - math_mod/primitive_rt_expr.hpp
  - math_mod/pow_expr.hpp
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - fps/multivariate_fps.hpp
  - fps/multivariate_fps.hpp
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  - convolution/convo_arb.hpp
  - convolution/multi_convo_truncated.hpp
  timestamp: '2024-09-08 23:28:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
documentation_of: convolution/convolution.hpp
layout: document
redirect_from:
- /library/convolution/convolution.hpp
- /library/convolution/convolution.hpp.html
title: convolution/convolution.hpp
---
