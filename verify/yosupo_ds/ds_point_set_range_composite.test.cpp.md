---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: functional/reverse_args.hpp
    title: functional/reverse_args.hpp
  - icon: ':heavy_check_mark:'
    path: math/homomorphism/affine.hpp
    title: math/homomorphism/affine.hpp
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
    path: template/function_util.hpp
    title: template/function_util.hpp
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../functional/reverse_args.hpp\"\n#include \"../../math/homomorphism/affine.hpp\"\
    \n#include \"../../modint/mont.hpp\"\n#include \"../../segment_tree/seg.hpp\"\n\
    #include \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n\
    \    int n, q;\n    kin >> n >> q;\n    auto a = kk2::GetVecAffine<kk2::mont998>(n);\n\
    \    kin >> a;\n    kk2::SegTree<kk2::homomorphism::Affine<kk2::mont998>,\n  \
    \               kk2::reverse_args<kk2::homomorphism::AffineComposition<kk2::mont998>>,\n\
    \                 kk2::homomorphism::AffineUnit<kk2::mont998>>\n        seg(a);\n\
    \n    rep (q) {\n        int t;\n        kin >> t;\n        if (t == 0) {\n  \
    \          int p;\n            kk2::mont998 c, d;\n            kin >> p >> c >>\
    \ d;\n            seg.emplace_set(p, c, d);\n        }\n        if (t == 1) {\n\
    \            int l, r;\n            kk2::mont998 x; \n            kin >> l >>\
    \ r >> x;\n            kout << seg.prod(l, r).apply(x) << \"\\n\";\n        }\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - functional/reverse_args.hpp
  - type_traits/type_traits.hpp
  - math/homomorphism/affine.hpp
  - modint/mont.hpp
  - segment_tree/seg.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-12-18 14:57:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp
- /verify/verify/yosupo_ds/ds_point_set_range_composite.test.cpp.html
title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
---
