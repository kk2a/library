---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/disjoint_sparse_table.hpp
    title: data_structure/disjoint_sparse_table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../data_structure/disjoint_sparse_table.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nusing S = int;\n\nS op(S a, S b) {\n    return min(a,\
    \ b);\n}\n\nS e() {\n    return 1e9 + 1;\n}\n\nint main() {\n    int n, q;\n \
    \   kin >> n >> q;\n    vc<int> a(n);\n    kin >> a;\n    kk2::DisjointSparseTable<S,\
    \ op, e> dst(a);\n\n    rep (q) {\n        int l, r;\n        kin >> l >> r;\n\
    \        kout << dst.prod(l, r) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/disjoint_sparse_table.hpp
  - template/template.hpp
  - type_traits/type_traits.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_static_rmq_2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_static_rmq_2.test.cpp
- /verify/verify/yosupo_ds/ds_static_rmq_2.test.cpp.html
title: verify/yosupo_ds/ds_static_rmq_2.test.cpp
---
