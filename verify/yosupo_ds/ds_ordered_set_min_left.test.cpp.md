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
    path: math/monoid/update.hpp
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
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
    PROBLEM: https://judge.yosupo.jp/problem/ordered_set
    links:
    - https://judge.yosupo.jp/problem/ordered_set
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/ordered_set\" \n\n#include\
    \ \"../../bbst/red_black_tree.hpp\"\n#include \"../../math/monoid/update.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, q;\n    kin >> n >> q;\n    vc<kk2::monoid::Update<int>> a(n);\n\
    \    kin >> a;\n    kk2::RedBlackTree<kk2::monoid::Update<int>> rb(2 * (n + q));\n\
    \    auto root = rb.build(a);\n    rep (q) {\n        int t, x;\n        kin >>\
    \ t >> x;\n        if (t == 0) {\n            auto [k, a, b] = rb.min_left(root,\
    \ rb.size(root), [&](auto t) { return t.is_unit or x < t.a; });\n            if\
    \ (b and b->val.a == x) continue;\n            rb.insert(root, k, x);\n      \
    \  }\n        if (t == 1) {\n            auto [k, a, b] = rb.min_left(root, rb.size(root),\
    \ [&](auto t) { return t.is_unit or x < t.a; });\n            if (b and b->val.a\
    \ == x) rb.erase(root, k - 1);\n        }\n        if (t == 2) {\n           \
    \ --x;\n            if (rb.size(root) <= x) kout << -1 << \"\\n\";\n         \
    \   else kout << rb.get(root, x) << \"\\n\";\n        }\n        if (t == 3) {\n\
    \            kout << rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit\
    \ or x < t.a; }).s << \"\\n\";\n        }\n        if (t == 4) {\n           \
    \ auto [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit\
    \ or x < t.a; });\n            if (b) kout << b->val << \"\\n\";\n           \
    \ else kout << -1 << \"\\n\";\n        }\n        if (t == 5) {\n            auto\
    \ [k, a, b] = rb.min_left(root, rb.size(root), [&](auto t) { return t.is_unit\
    \ or x <= t.a; });\n            if (a.is_unit) kout << -1 << \"\\n\";\n      \
    \      else kout << a << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - bbst/red_black_tree.hpp
  - type_traits/io.hpp
  - bbst/base/red_black_tree_base.hpp
  - others/vector_pool.hpp
  - math/monoid/update.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/integral.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  requiredBy: []
  timestamp: '2025-06-26 23:23:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
- /verify/verify/yosupo_ds/ds_ordered_set_min_left.test.cpp.html
title: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
---
