---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/group/sum.hpp
    title: math/group/sum.hpp
  - icon: ':heavy_check_mark:'
    path: math/homomorphism/affine.hpp
    title: math/homomorphism/affine.hpp
  - icon: ':question:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy.hpp
    title: segment_tree/lazy.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/utility/affinesum.hpp
    title: segment_tree/utility/affinesum.hpp
  - icon: ':question:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../modint/mont.hpp\"\n#include \"../../segment_tree/utility/affinesum.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, q;\n    kin >> n >> q;\n    auto a = kk2::GetVecSum<kk2::mont998>(n);\n\
    \    kin >> a;\n    kk2::AffineSum<kk2::mont998> seg(a);\n\n    rep (q) {\n  \
    \      int t;\n        kin >> t;\n        if (t == 0) {\n            int l, r;\n\
    \            kk2::mont998 b, c;\n            kin >> l >> r >> b >> c;\n      \
    \      seg.emplace_apply_range(l, r, b, c);\n        }\n        if (t == 1) {\n\
    \            int l, r;\n            kin >> l >> r;\n            kout << seg.prod(l,\
    \ r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - modint/mont.hpp
  - type_traits/type_traits.hpp
  - segment_tree/utility/affinesum.hpp
  - math/group/sum.hpp
  - math/homomorphism/affine.hpp
  - segment_tree/lazy.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 14:18:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_range_affine_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
---