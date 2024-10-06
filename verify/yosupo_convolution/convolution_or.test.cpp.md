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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../convolution/or1.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \ \n\n#include \"../../convolution/or1.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vc<kk2::mont998> a(1 << n), b(1 << n);\n \
    \   rep (i, 1 << n) cin >> a[~i & ((1 << n) - 1)];\n    rep (i, 1 << n) cin >>\
    \ b[~i & ((1 << n) - 1)];\n    kk2::convolution_or(a, b);\n    vc<kk2::mont998>\
    \ c(1 << n);\n    rep (i, 1 << n) c[~i & ((1 << n) - 1)] = a[i];\n    rep (i,\
    \ 1 << n) cout << c[i] << \" \\n\"[i == (1 << n) - 1];\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_or.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_or.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_or.test.cpp
- /verify/verify/yosupo_convolution/convolution_or.test.cpp.html
title: verify/yosupo_convolution/convolution_or.test.cpp
---
