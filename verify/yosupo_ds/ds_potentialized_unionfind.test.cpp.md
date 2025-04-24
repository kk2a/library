---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':question:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  - icon: ':x:'
    path: unionfind/potentialized.hpp
    title: unionfind/potentialized.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../unionfind/potentialized.hpp\"\nusing namespace std;\n\nint\
    \ main() {\n    int n, q;\n    kin >> n >> q;\n    kk2::PotentializedUnionFind<kk2::mont998>\
    \ puf(n);\n\n    rep (q) {\n        int t;\n        kin >> t;\n        if (t ==\
    \ 0) {\n            int u, v;\n            kk2::mont998 w;\n            kin >>\
    \ u >> v >> w;\n            if (puf.same(v, u)) {\n                kout << (puf.diff(v,\
    \ u) == w) << \"\\n\";\n            } else {\n                kout << \"1\\n\"\
    ;\n                puf.unite(v, u, w);\n            }\n        }\n        if (t\
    \ == 1) {\n            int u, v;\n            kin >> u >> v;\n            if (puf.same(v,\
    \ u)) {\n                kout << puf.diff(v, u) << \"\\n\";\n            } else\
    \ kout << \"-1\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - unionfind/potentialized.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 11:43:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp.html
title: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
---
