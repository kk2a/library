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
    path: convolution/multi_convolution_truncated.hpp
    title: convolution/multi_convolution_truncated.hpp
  - icon: ':heavy_check_mark:'
    path: fps/fps_sparsity_detector.hpp
    title: fps/fps_sparsity_detector.hpp
  - icon: ':heavy_check_mark:'
    path: math_mod/butterfly.hpp
    title: math_mod/butterfly.hpp
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
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution
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
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution\"\
    \n\n#include \"../../convolution/multi_convolution_truncated.hpp\"\n#include \"\
    ../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int k;\n    kin >> k;\n    vc<int> base(k);\n    kin\
    \ >> base;\n    int n = 1;\n    rep (i, k) n *= base[i];\n    vc<kk2::mont998>\
    \ a(n), b(n);\n    kin >> a >> b;\n    kout << kk2::multi_convolution_truncated(a,\
    \ b, base) << kendl;\n\n    return 0;\n}\n"
  dependsOn:
  - convolution/multi_convolution_truncated.hpp
  - convolution/convolution.hpp
  - fps/fps_sparsity_detector.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - math_mod/butterfly.hpp
  - math_mod/primitive_root.hpp
  - math_mod/pow_mod.hpp
  - modint/mont.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  requiredBy: []
  timestamp: '2025-06-26 23:23:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_multi_truncated.test.cpp
- /verify/verify/yosupo_convolution/convolution_multi_truncated.test.cpp.html
title: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
---
