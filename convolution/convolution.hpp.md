---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/butterfly.hpp
    title: convolution/butterfly.hpp
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
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_arb.hpp
    title: convolution/convolution_arb.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':warning:'
    path: fps/fps_arb.hpp
    title: fps/fps_arb.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':warning:'
    path: fps/multivariate_fps.hpp
    title: fps/multivariate_fps.hpp
  - icon: ':question:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':x:'
    path: math_mod/comb_large.hpp
    title: math_mod/comb_large.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    title: verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    title: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    title: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
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
  - icon: ':x:'
    path: verify/yosupo_math/many_factrials.test.cpp
    title: verify/yosupo_math/many_factrials.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef CONVOLUTION_HPP\n#define CONVOLUTION_HPP 1\n\n#include <algorithm>\n\
    #include <vector>\n\n#include \"butterfly.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> FPS convolution(FPS &a, const\
    \ FPS &b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m)\
    \ return {};\n    if (std::min(n, m) <= 60) {\n        FPS res(n + m - 1);\n \
    \       for (int i = 0; i < n; i++) {\n            for (int j = 0; j < m; j++)\
    \ { res[i + j] += a[i] * b[j]; }\n        }\n        a = res;\n        return\
    \ a;\n    }\n    int z = 1;\n    while (z < n + m - 1) z <<= 1;\n    if (a ==\
    \ b) {\n        a.resize(z);\n        butterfly(a);\n        for (int i = 0; i\
    \ < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(z);\n        butterfly(a);\n\
    \        FPS t(b.begin(), b.end());\n        t.resize(z);\n        butterfly(t);\n\
    \        for (int i = 0; i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    return a;\n}\n\n} // namespace kk2\n\n#endif //\
    \ CONVOLUTION_HPP\n"
  dependsOn:
  - convolution/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy:
  - convolution/convolution_arb.hpp
  - convolution/multi_convolution_truncated.hpp
  - math_mod/comb_large.hpp
  - fps/multivariate_fps.hpp
  - fps/multivariate_fps.hpp
  - fps/ntt_friendly.hpp
  - fps/fps_arb.hpp
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
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
