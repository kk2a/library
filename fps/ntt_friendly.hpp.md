---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
  - icon: ':question:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':x:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':question:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':question:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef FPS_NTT_FRIENDLY_HPP\n#define FPS_NTT_FRIENDLY_HPP 1\n\n#include\
    \ \"../convolution/convolution.hpp\"\n#include \"fps.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <class mint>\nFormalPowerSeries<mint> &FormalPowerSeries<mint>::operator*=(const\
    \ FormalPowerSeries<mint> &r) {\n    if (this->empty() || r.empty()) {\n     \
    \   this->clear();\n        return *this;\n    }\n    convolution(*this, r);\n\
    \    return *this;\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::but()\
    \ {\n    butterfly(*this);\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::ibut()\
    \ {\n    butterfly_inv(*this);\n}\n\ntemplate <class mint> void FormalPowerSeries<mint>::db()\
    \ {\n    doubling(*this);\n}\n\ntemplate <class mint> int FormalPowerSeries<mint>::but_pr()\
    \ {\n    return primitive_root<mint::getmod()>;\n}\n\ntemplate <class mint> FormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::inv(int deg) const {\n    assert((*this)[0] != mint(0));\n\
    \    if (deg == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> res(deg);\n\
    \    res[0] = {mint(1) / (*this)[0]};\n    for (int d = 1; d < deg; d <<= 1) {\n\
    \        FormalPowerSeries<mint> f(2 * d), g(2 * d);\n        std::copy(std::begin(*this),\n\
    \                  std::begin(*this) + std::min((int)this->size(), 2 * d),\n \
    \                 std::begin(f));\n        std::copy(std::begin(res), std::begin(res)\
    \ + d, std::begin(g));\n        f.but();\n        g.but();\n        f.inplace_dot(g);\n\
    \        f.ibut();\n        std::fill(std::begin(f), std::begin(f) + d, mint(0));\n\
    \        f.but();\n        f.inplace_dot(g);\n        f.ibut();\n        for (int\
    \ j = d; j < std::min(2 * d, deg); j++) res[j] = -f[j];\n    }\n    return res.pre(deg);\n\
    }\n\ntemplate <class mint> FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int\
    \ deg) const {\n    assert(this->empty() || (*this)[0] == mint(0));\n    if (deg\
    \ == -1) deg = (int)this->size();\n    FormalPowerSeries<mint> inv;\n    inv.reserve(deg\
    \ + 1);\n    inv.push_back(mint(0));\n    inv.push_back(mint(1));\n\n    FormalPowerSeries<mint>\
    \ b{1, 1 < (int)this->size() ? (*this)[1] : mint(0)};\n    FormalPowerSeries<mint>\
    \ c{1}, z1, z2{1, 1};\n    for (int m = 2; m < deg; m <<= 1) {\n        auto y\
    \ = b;\n        y.resize(m << 1);\n        y.but();\n        z1 = z2;\n      \
    \  FormalPowerSeries<mint> z(m);\n        z = y.dot(z1);\n        z.ibut();\n\
    \        std::fill(std::begin(z), std::begin(z) + (m >> 1), mint(0));\n      \
    \  z.but();\n        z.inplace_dot(-z1);\n        z.ibut();\n        c.insert(std::end(c),\
    \ std::begin(z) + (m >> 1), std::end(z));\n        z2 = c;\n        z2.resize(m\
    \ << 1);\n        z2.but();\n\n        FormalPowerSeries<mint> x(this->begin(),\
    \ this->begin() + std::min<int>(this->size(), m));\n        x.resize(m);\n   \
    \     x.inplace_diff();\n        x.push_back(mint(0));\n        x.but();\n   \
    \     x.inplace_dot(y);\n        x.ibut();\n        x -= b.diff();\n        x.resize(m\
    \ << 1);\n        for (int i = 0; i < m - 1; i++) {\n            x[m + i] = x[i];\n\
    \            x[i] = mint(0);\n        }\n        x.but();\n        x.inplace_dot(z2);\n\
    \        x.ibut();\n        x.pop_back();\n        x.inplace_int();\n        for\
    \ (int i = m; i < std::min<int>(this->size(), m << 1); i++) x[i] += (*this)[i];\n\
    \        std::fill(std::begin(x), std::begin(x) + m, mint(0));\n        x.but();\n\
    \        x.inplace_dot(y);\n        x.ibut();\n        b.insert(std::end(b), std::begin(x)\
    \ + m, std::end(x));\n    }\n    return FormalPowerSeries<mint>(std::begin(b),\
    \ std::begin(b) + deg);\n}\n\n} // namespace kk2\n\n#endif // FPS_NTT_FRIENDLY_HPP\n"
  dependsOn:
  - convolution/convolution.hpp
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - fps/fps.hpp
  isVerificationFile: false
  path: fps/ntt_friendly.hpp
  requiredBy:
  - math_mod/comb_large.hpp
  - fps/multivariate_fps.hpp
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
documentation_of: fps/ntt_friendly.hpp
layout: document
redirect_from:
- /library/fps/ntt_friendly.hpp
- /library/fps/ntt_friendly.hpp.html
title: fps/ntt_friendly.hpp
---
