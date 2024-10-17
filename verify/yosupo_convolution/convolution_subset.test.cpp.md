---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/subset.hpp
    title: convolution/subset.hpp
  - icon: ':x:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':x:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\" \n\
    \n#include \"../../convolution/subset.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n;\n    kin >> n;\n    vc<kk2::mont998> a(1 << n), b(1 << n);\n \
    \   kin >> a >> b;\n    kout << kk2::convolution_subset(a, b) << endl;\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - convolution/subset.hpp
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_convolution/convolution_subset.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_convolution/convolution_subset.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_convolution/convolution_subset.test.cpp
- /verify/verify/yosupo_convolution/convolution_subset.test.cpp.html
title: verify/yosupo_convolution/convolution_subset.test.cpp
---
