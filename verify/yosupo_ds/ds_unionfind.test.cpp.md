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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../unionfind/unionfind.hpp\"\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    kk2::UnionFind\
    \ uf(n);\n\n    rep (q) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 0) {\n            int u, v;\n            cin >> u >> v;\n            uf.unite(u,\
    \ v);\n        }\n        if (t == 1) {\n            int u, v;\n            cin\
    \ >> u >> v;\n            cout << uf.same(u, v) << \"\\n\";\n        }\n    }\n\
    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_ds/ds_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_unionfind.test.cpp
- /verify/verify/yosupo_ds/ds_unionfind.test.cpp.html
title: verify/yosupo_ds/ds_unionfind.test.cpp
---
