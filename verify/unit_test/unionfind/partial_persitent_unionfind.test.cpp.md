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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../unionfind/partial_persistent.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../unionfind/partial_persistent.hpp\"\n#include \"../../unionfind/unionfind.hpp\"\
    \n#include \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\n\
    using namespace std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout\
    \ << a + b << kendl;\n\n    rep (200) {\n        int n = kk2::random::rng(1, 1e4);\n\
    \        kk2::PartialPersistentUnionFind ppu(n);\n        kk2::UnionFind uf(n);\n\
    \    \n        int q = 1e3;\n        vc<int> ask_size(q);\n        vc<pi> ask_same(q);\n\
    \        vc<int> res_size(q), res_same(q);\n        rep (t, q) {\n           \
    \ int num = kk2::random::rng(1, 101);\n            rep (num) {\n             \
    \   int a = kk2::random::rng(0, n);\n                int b = kk2::random::rng(0,\
    \ n);\n                assert(ppu.unite(a, b, t) == uf.unite(a, b));\n       \
    \     }\n            ask_size[t] = kk2::random::rng(0, n);\n            res_size[t]\
    \ = uf.size(ask_size[t]);\n            ask_same[t] = {kk2::random::rng(0, n),\
    \ kk2::random::rng(0, n)};\n            res_same[t] = uf.same(ask_same[t].first,\
    \ ask_same[t].second);\n        }\n    \n        rep (t, q) {\n            assert(ppu.size(ask_size[t],\
    \ t) == res_size[t]);\n            assert(ppu.same(ask_same[t].first, ask_same[t].second,\
    \ t) == res_same[t]);\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
- /verify/verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp.html
title: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
---
