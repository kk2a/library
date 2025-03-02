---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
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
  - icon: ':heavy_check_mark:'
    path: unionfind/partial_persistent.hpp
    title: unionfind/partial_persistent.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/unionfind.hpp
    title: unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../unionfind/partial_persistent.hpp\"\n#include \"../../unionfind/unionfind.hpp\"\
    \n#include \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout\
    \ << a + b << kendl;\n\n    int n = 1e5;\n    kk2::PartialPersistentUnionFind\
    \ ppu(n);\n    kk2::UnionFind uf(n);\n\n    int q = 1e4;\n    vc<int> ask_size(q);\n\
    \    vc<pi> ask_same(q);\n    vc<int> res_size(q), res_same(q);\n    rep (t, q)\
    \ {\n        int num = kk2::random::rng(1, 101);\n        rep (num) {\n      \
    \      int a = kk2::random::rng(0, n);\n            int b = kk2::random::rng(0,\
    \ n);\n            assert(ppu.unite(a, b, t) == uf.unite(a, b));\n        }\n\
    \        ask_size[t] = kk2::random::rng(0, n);\n        res_size[t] = uf.size(ask_size[t]);\n\
    \        ask_same[t] = {kk2::random::rng(0, n), kk2::random::rng(0, n)};\n   \
    \     res_same[t] = uf.same(ask_same[t].first, ask_same[t].second);\n    }\n\n\
    \    rep (t, q) {\n        assert(ppu.size(ask_size[t], t) == res_size[t]);\n\
    \        assert(ppu.same(ask_same[t].first, ask_same[t].second, t) == res_same[t]);\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - unionfind/partial_persistent.hpp
  - unionfind/unionfind.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/type_traits.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/partial_persitent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 14:51:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/partial_persitent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/partial_persitent_unionfind.test.cpp
- /verify/verify/unit_test/partial_persitent_unionfind.test.cpp.html
title: verify/unit_test/partial_persitent_unionfind.test.cpp
---
