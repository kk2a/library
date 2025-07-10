---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/log.hpp
    title: math_mod/log.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint.hpp
    title: modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
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
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \ \n\n#include \"../../math_mod/log.hpp\"\n#include \"../../modint/modint.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    using mint = kk2::ModInt<0>;\n    int t;\n    kin >> t;\n    rep (t)\
    \ {\n        int xx, yy, m;\n        kin >> xx >> yy >> m;\n        mint::setmod(m);\n\
    \        mint x = xx, y = yy;\n        kout << kk2::discrete_logarithm(x, y) <<\
    \ \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math_mod/log.hpp
  - modint/modint.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_math/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 11:43:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_math/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_math/discrete_logarithm.test.cpp
- /verify/verify/yosupo_math/discrete_logarithm.test.cpp.html
title: verify/yosupo_math/discrete_logarithm.test.cpp
---
