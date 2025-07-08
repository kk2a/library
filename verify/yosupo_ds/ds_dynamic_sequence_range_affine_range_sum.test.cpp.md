---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: "\u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: bbst/lazy_red_black_tree.hpp
    title: bbst/lazy_red_black_tree.hpp
  - icon: ':heavy_check_mark:'
    path: math/action/affine_sumwithsize.hpp
    title: math/action/affine_sumwithsize.hpp
  - icon: ':heavy_check_mark:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include \"../../bbst/lazy_red_black_tree.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../math/action/affine_sumwithsize.hpp\"\n#include \"../../template/template.hpp\"\
    \nusing namespace std;\n\nusing mint = kk2::mont998;\n\nusing A = kk2::action::AffineSumWithSize<mint,\
    \ mint>;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n    vc<A::S> a(n);\n\
    \    kin >> a;\n    kk2::LazyRedBlackTree<A> rbt(2 * (n + q));\n    auto t = rbt.build(a);\n\
    \    rep (i, q) {\n        int type;\n        kin >> type;\n        if (type ==\
    \ 0) {\n            int p, x;\n            kin >> p >> x;\n            rbt.insert(t,\
    \ p, mint(x), mint(1));\n        }\n        if (type == 1) {\n            int\
    \ p;\n            kin >> p;\n            rbt.erase(t, p);\n        }\n       \
    \ if (type == 2) {\n            int l, r;\n            kin >> l >> r;\n      \
    \      rbt.reverse(t, l, r);\n        }\n        if (type == 3) {\n          \
    \  int l, r;\n            mint b, c;\n            kin >> l >> r >> b >> c;\n \
    \           rbt.apply(t, l, r, b, c);\n        }\n        if (type == 4) {\n \
    \           int l, r;\n            kin >> l >> r;\n            kout << rbt.prod(t,\
    \ l, r).a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - bbst/lazy_red_black_tree.hpp
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - math/action/affine_sumwithsize.hpp
  - math/group/sum_with_size.hpp
  - math/monoid/affine.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-06-26 23:23:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp.html
title: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
---
