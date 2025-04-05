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
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/functional.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../functional/reverse_args.hpp\"\n#include \"../../math/monoid/affine.hpp\"\
    \n#include \"../../modint/mont.hpp\"\n#include \"../../segment_tree/seg.hpp\"\n\
    #include \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n\
    \    int n, q;\n    kin >> n >> q;\n    using M = kk2::monoid::Affine<kk2::mont998>;\n\
    \    vc<M> a(n);\n    kin >> a;\n    kk2::SegmentTree<M, kk2::reverse_args<M::op>,\
    \ M::unit> seg(a);\n\n    rep (q) {\n        int t;\n        kin >> t;\n     \
    \   if (t == 0) {\n            int p;\n            kk2::mont998 c, d;\n      \
    \      kin >> p >> c >> d;\n            seg.set(p, c, d);\n        }\n       \
    \ if (t == 1) {\n            int l, r;\n            kk2::mont998 x; \n       \
    \     kin >> l >> r >> x;\n            kout << seg.prod(l, r).eval(x) << \"\\\
    n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp.html
title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
---
