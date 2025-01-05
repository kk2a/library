---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/convolution.hpp
    title: convolution/convolution.hpp
  - icon: ':x:'
    path: fps/fps.hpp
    title: fps/fps.hpp
  - icon: ':x:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  - icon: ':x:'
    path: fps/ntt_friendly.hpp
    title: fps/ntt_friendly.hpp
  - icon: ':x:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
  - icon: ':x:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  - icon: ':x:'
    path: math_mod/pow_mod.hpp
    title: math_mod/pow_mod.hpp
  - icon: ':x:'
    path: math_mod/primitive_root.hpp
    title: math_mod/primitive_root.hpp
  - icon: ':x:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':x:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':x:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':x:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':x:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':x:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':x:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse
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
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse\"\
    \ \n\n#include \"../../fps/ntt_friendly.hpp\"\n#include \"../../fps/fps_sqrt.hpp\"\
    \n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nusing FPS = kk2::FormalPowerSeries<kk2::mont998>;\n\n\
    int main() {\n    int n, k;\n    kin >> n >> k;\n    FPS f(n);\n    rep (k) {\n\
    \        int i;\n        kk2::mont998 a;\n        kin >> i >> a;\n        f[i]\
    \ = a;\n    }\n    FPS res = kk2::sparse_sqrt(f);\n    if (res.empty()) kout <<\
    \ -1 << \"\\n\";\n    else res.output(kout);\n\n    return 0;\n}\n"
  dependsOn:
  - fps/ntt_friendly.hpp
  - convolution/convolution.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - type_traits/type_traits.hpp
  - fps/fps.hpp
  - fps/fps_sqrt.hpp
  - math_mod/mod_sqrt.hpp
  - modint/mont_arb.hpp
  - modint/mont.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/function_util.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/type_alias.hpp
  isVerificationFile: true
  path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  requiredBy: []
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_fps/fps_sprase_sqrt.test.cpp
- /verify/verify/yosupo_fps/fps_sprase_sqrt.test.cpp.html
title: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
---
