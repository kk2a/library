---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: functional/reverse_args.hpp
    title: functional/reverse_args.hpp
  - icon: ':question:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/seg.hpp
    title: segment_tree/seg.hpp
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
  - icon: ':heavy_check_mark:'
    path: type_traits/functional.hpp
    title: type_traits/functional.hpp
  - icon: ':question:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
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
    \ type_traits/functional.hpp: line 4: #pragma once found in a non-first line\n"
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
  dependsOn:
  - functional/reverse_args.hpp
  - type_traits/functional.hpp
  - math/monoid/affine.hpp
  - type_traits/io.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - segment_tree/seg.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2025-06-04 11:53:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp.html
title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
---
