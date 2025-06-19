---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/base/red_black_tree_base.hpp
    title: "\u8D64\u9ED2\u6728\u306E\u57FA\u672C\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: bbst/red_black_tree.hpp
    title: bbst/red_black_tree.hpp
  - icon: ':heavy_check_mark:'
    path: functional/reverse_args.hpp
    title: functional/reverse_args.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: modint/mont.hpp
    title: modint/mont.hpp
  - icon: ':heavy_check_mark:'
    path: others/vector_pool.hpp
    title: others/vector_pool.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':heavy_check_mark:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/functional.hpp
    title: type_traits/functional.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
  - icon: ':heavy_check_mark:'
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \ \n\n#include \"../../bbst/red_black_tree.hpp\"\n#include \"../../functional/reverse_args.hpp\"\
    \n#include \"../../math/monoid/affine.hpp\"\n#include \"../../modint/mont.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nstruct S :\
    \ public kk2::monoid::Affine<kk2::mont998> {\n    using base = kk2::monoid::Affine<kk2::mont998>;\n\
    \    using base::Affine;\n    S(const base &b) : base(b) {}\n    static inline\
    \ S op(S l, S r) {\n        return S{r.a * l.a, r.a * l.b + r.b};\n    }\n};\n\
    \nint main() {\n    int n, q;\n    kin >> n >> q;\n    vc<S> a(n);\n    kin >>\
    \ a;\n    kk2::RedBlackTree<S> rbt(2 * (n + q));\n    auto root = rbt.build(a);\n\
    \n    rep (q) {\n        int type;\n        kin >> type;\n        if (type ==\
    \ 0) {\n            int p;\n            kk2::mont998 c, d;\n            kin >>\
    \ p >> c >> d;\n            rbt.set(root, p, c, d);\n        }\n        if (type\
    \ == 1) {\n            int l, r;\n            kk2::mont998 x;\n            kin\
    \ >> l >> r >> x;\n            kout << rbt.prod(root, l, r).eval(x) << \"\\n\"\
    ;\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - bbst/red_black_tree.hpp
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  - functional/reverse_args.hpp
  - type_traits/functional.hpp
  - math/monoid/affine.hpp
  - modint/mont.hpp
  - type_traits/integral.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  requiredBy: []
  timestamp: '2025-06-19 13:39:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
- /verify/verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp.html
title: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
---
