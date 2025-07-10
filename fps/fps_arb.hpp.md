---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_arb.hpp
    title: convolution/convolution_arb.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_base.hpp
    title: fps/fps_base.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/garner.hpp
    title: math_mod/garner.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/inv.hpp
    title: math_mod/inv.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/inv_table.hpp
    title: "`[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\
      \u30D6\u30EB"
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
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_exp_arb.test.cpp
    title: verify/yosupo_fps/fps_exp_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_inv_arb.test.cpp
    title: verify/yosupo_fps/fps_inv_arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_log_arb.test.cpp
    title: verify/yosupo_fps/fps_log_arb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_FPS_FPS_ARB_HPP\n#define KK2_FPS_FPS_ARB_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#include \"../convolution/convolution_arb.hpp\"\n#include \"fps_base.hpp\"\n\
    \nnamespace kk2 {\n\ntemplate <class mint> struct FormalPowerSeriesArbitrary\n\
    \    : FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint> {\n    using\
    \ base = FormalPowerSeriesBase<FormalPowerSeriesArbitrary<mint>, mint>;\n    using\
    \ FPS = FormalPowerSeriesArbitrary<mint>;\n    using base::FormalPowerSeriesBase;\n\
    \    using base::operator*=; // \u57FA\u5E95\u30AF\u30E9\u30B9\u306Eoperator*=\u3092\
    \u7D99\u627F\n    static constexpr bool is_ntt_friendly = false;\n\n    // CRTP\u3092\
    \u4F7F\u3063\u305F\u5B9F\u88C5 - override\u306F\u4E0D\u8981\n    FPS &operator*=(const\
    \ FPS &r) {\n        convolution_arb(*this, r);\n        return *this;\n    }\n\
    \    void but() { exit(1); }\n    void ibut() { exit(1); }\n    void db() { exit(1);\
    \ }\n    static int but_pr() {\n        exit(1);\n        return 0;\n    }\n\n\
    \    FPS dense_inv(int deg = -1) const {\n        if (deg == -1) deg = this->size();\n\
    \        FPS res{(*this)[0].inv()};\n        for (int i = 1; i < deg; i <<= 1)\
    \ {\n            res = (res + res - this->pre(i << 1) * (res * res)).pre(i <<\
    \ 1);\n        }\n        return res.pre(deg);\n    }\n\n    FPS dense_exp(int\
    \ deg = -1) const {\n        if (deg == -1) deg = this->size();\n        FPS ret{mint(1)};\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i\
    \ << 1) + mint{1} - ret.log(i << 1))).pre(i << 1);\n        }\n        return\
    \ ret.pre(deg);\n    }\n};\n\ntemplate <class mint> using FPSArb = FormalPowerSeriesArbitrary<mint>;\n\
    \n} // namespace kk2\n\n#endif // KK2_FPS_FPS_ARB_HPP\n"
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
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - fps/fps_base.hpp
  - math_mod/inv_table.hpp
  isVerificationFile: false
  path: fps/fps_arb.hpp
  requiredBy: []
  timestamp: '2025-07-08 15:40:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_log_arb.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
documentation_of: fps/fps_arb.hpp
layout: document
redirect_from:
- /library/fps/fps_arb.hpp
- /library/fps/fps_arb.hpp.html
title: fps/fps_arb.hpp
---
