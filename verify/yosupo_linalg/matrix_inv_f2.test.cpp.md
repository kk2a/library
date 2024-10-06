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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../matrix/matrix_f2.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix_mod_2\"\
    \ \n\n#include \"../../matrix/matrix_f2.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    kk2::MatrixF2\
    \ a(n, n);\n    rep (i, n) {\n        string s;\n        cin >> s;\n        a[i]\
    \ = s;\n    }\n    if (auto const inv = a.inv()) inv->display();\n    else cout\
    \ << -1 << \"\\n\";\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_linalg/matrix_inv_f2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_linalg/matrix_inv_f2.test.cpp
- /verify/verify/yosupo_linalg/matrix_inv_f2.test.cpp.html
title: verify/yosupo_linalg/matrix_inv_f2.test.cpp
---
