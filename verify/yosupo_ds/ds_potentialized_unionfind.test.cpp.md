---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../unionfind/potentialized.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../template/template.hpp\"\
    \n#include \"../../unionfind/potentialized.hpp\"\nusing namespace std;\n\nint\
    \ main() {\n    int n, q;\n    cin >> n >> q;\n    kk2::PotentializedUnionfind<kk2::mont998>\
    \ puf(n);\n\n    rep (q) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int u, v;\n            kk2::mont998 w;\n            cin >>\
    \ u >> v >> w;\n            if (puf.same(u, v)) {\n                cout << (puf.diff(u,\
    \ v) == w) << \"\\n\";\n            } else {\n                cout << \"1\\n\"\
    ;\n                puf.unite(u, v, w);\n            }\n        }\n        if (t\
    \ == 1) {\n            int u, v;\n            cin >> u >> v;\n            if (puf.same(u,\
    \ v)) {\n                cout << puf.diff(u, v) << \"\\n\";\n            } else\
    \ cout << \"-1\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
- /verify/verify/yosupo_ds/ds_potentialized_unionfind.test.cpp.html
title: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
---
