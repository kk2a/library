---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':question:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':question:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  - icon: ':question:'
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    title: verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_exp_arb.test.cpp
    title: verify/yosupo_fps/fps_exp_arb.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_inv_arb.test.cpp
    title: verify/yosupo_fps/fps_inv_arb.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_log_arb.test.cpp
    title: verify/yosupo_fps/fps_log_arb.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../math_mod/garner.hpp\"\n#include \"../modint/mont.hpp\"\
    \n#include \"convolution.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS convolution_arb(FPS &a, const FPS &b,\
    \ long long mod) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n\
    \ || !m) return {};\n    static constexpr long long MOD1 = 754974721; // 2^24\n\
    \    static constexpr long long MOD2 = 167772161; // 2^25\n    static constexpr\
    \ long long MOD3 = 469762049; // 2^26\n    using mint1 = LazyMontgomeryModInt<MOD1>;\n\
    \    using mint2 = LazyMontgomeryModInt<MOD2>;\n    using mint3 = LazyMontgomeryModInt<MOD3>;\n\
    \n    std::vector<long long> a0(n), b0(m);\n    for (int i = 0; i < n; i++) a0[i]\
    \ = a[i].val();\n    for (int i = 0; i < m; i++) b0[i] = b[i].val();\n    auto\
    \ a1 = std::vector<mint1>(a0.begin(), a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(),\
    \ b0.end());\n    convolution(a1, b1);\n    auto a2 = std::vector<mint2>(a0.begin(),\
    \ a0.end());\n    auto b2 = std::vector<mint2>(b0.begin(), b0.end());\n    convolution(a2,\
    \ b2);\n    auto a3 = std::vector<mint3>(a0.begin(), a0.end());\n    auto b3 =\
    \ std::vector<mint3>(b0.begin(), b0.end());\n    convolution(a3, b3);\n    static\
    \ const std::vector<long long> ps = {MOD1, MOD2, MOD3, mod};\n    a.resize(n +\
    \ m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        a[i] = mint(garner({a1[i].val(),\
    \ a2[i].val(), a3[i].val()}, ps));\n    }\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_ARB_HPP\n"
  dependsOn:
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - convolution/convolution.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  isVerificationFile: false
  path: convolution/convolution_arb.hpp
  requiredBy:
  - fps/fps_arb.hpp
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
documentation_of: convolution/convolution_arb.hpp
layout: document
redirect_from:
- /library/convolution/convolution_arb.hpp
- /library/convolution/convolution_arb.hpp.html
title: convolution/convolution_arb.hpp
---
