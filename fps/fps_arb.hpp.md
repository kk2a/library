---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_arb.hpp
    title: convolution/convolution_arb.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps.hpp
    title: fps/fps.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_FPS_FPS_ARB_HPP\n#define KK2_FPS_FPS_ARB_HPP 1\n\n#include \"\
    ../convolution/convolution_arb.hpp\"\n#include \"fps.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <class mint> void FormalPowerSeries<mint>::but() {\n    exit(1);\n\
    }\n\ntemplate <class mint> void FormalPowerSeries<mint>::ibut() {\n    exit(1);\n\
    }\n\ntemplate <class mint> void FormalPowerSeries<mint>::db() {\n    exit(1);\n\
    }\n\ntemplate <class mint> int FormalPowerSeries<mint>::but_pr() {\n    return\
    \ 0;\n}\n\ntemplate <class mint>\nFormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint> &r) {\n    if (this->empty() || r.empty()) {\n     \
    \   this->clear();\n        return *this;\n    }\n    convolution_arb(*this, r,\
    \ mint::getmod());\n    return *this;\n}\n\ntemplate <class mint> FormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::inv(int deg) const {\n    assert((*this)[0] != mint(0));\n\
    \    if (deg == -1) deg = this->size();\n    FormalPowerSeries<mint> res{(*this)[0].inv()};\n\
    \    for (int i = 1; i < deg; i <<= 1) {\n        res = (res * mint(2) - this->pre(i\
    \ << 1) * res * res).pre(i << 1);\n    }\n    return res.pre(deg);\n}\n\ntemplate\
    \ <class mint> FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg) const\
    \ {\n    assert(this->empty() || (*this)[0] == mint(0));\n    if (deg == -1) deg\
    \ = this->size();\n    FormalPowerSeries<mint> ret{mint(1)};\n    for (int i =\
    \ 1; i < deg; i <<= 1) {\n        ret = (ret * (pre(i << 1) + mint{1} - ret.log(i\
    \ << 1))).pre(i << 1);\n    }\n    return ret.pre(deg);\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_FPS_FPS_ARB_HPP\n"
  dependsOn:
  - convolution/convolution_arb.hpp
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - convolution/convolution.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - fps/fps.hpp
  isVerificationFile: false
  path: fps/fps_arb.hpp
  requiredBy: []
  timestamp: '2025-01-09 05:34:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
documentation_of: fps/fps_arb.hpp
layout: document
redirect_from:
- /library/fps/fps_arb.hpp
- /library/fps/fps_arb.hpp.html
title: fps/fps_arb.hpp
---
