---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/binary_indexed_tree.hpp
    title: data_structure/binary_indexed_tree.hpp
  - icon: ':x:'
    path: others/coordinate_compression.hpp
    title: others/coordinate_compression.hpp
  - icon: ':x:'
    path: others/mo.hpp
    title: others/mo.hpp
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \ \n\n#include \"../../others/coordinate_compression.hpp\"\n#include \"../../data_structure/binary_indexed_tree.hpp\"\
    \n#include \"../../others/mo.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    kin >> n >> q;\n    vc<int>\
    \ a(n);\n    kin >> a;\n    vc<pair<int, int>> queries(q);\n    kin >> queries;\n\
    \n    kk2::CC cc(a);\n    vc<int> b = cc(a);\n    kk2::BinaryIndexedTree<int>\
    \ bit(cc.size());\n    kk2::Mo mo(n, queries);\n\n    vc<i64> res(q);\n    i64\
    \ now = 0;\n    auto insert_left = [&](int i) {\n        bit.add(b[i], 1);\n \
    \       now += bit.sum(0, b[i]);\n    };\n    auto insert_right = [&](int i) {\n\
    \        bit.add(b[i], 1);\n        now += bit.sum(b[i] + 1, cc.size());\n   \
    \ };\n    auto erase_left = [&](int i) {\n        now -= bit.sum(0, b[i]);\n \
    \       bit.add(b[i], -1);\n    };\n    auto erase_right = [&](int i) {\n    \
    \    now -= bit.sum(b[i] + 1, cc.size());\n        bit.add(b[i], -1);\n    };\n\
    \    auto f = [&](int i) { res[i] = now; };\n\n    mo.calculate(insert_left, insert_right,\
    \ erase_left, erase_right, f);\n    for (auto x : res) kout << x << \"\\n\";\n\
    \n    return 0;\n}\n"
  dependsOn:
  - others/coordinate_compression.hpp
  - data_structure/binary_indexed_tree.hpp
  - others/mo.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/type_traits.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/yosupo_ds/ds_static_range_inversions.test.cpp
  requiredBy: []
  timestamp: '2025-03-28 03:34:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_ds/ds_static_range_inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_ds/ds_static_range_inversions.test.cpp
- /verify/verify/yosupo_ds/ds_static_range_inversions.test.cpp.html
title: verify/yosupo_ds/ds_static_range_inversions.test.cpp
---
