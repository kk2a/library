---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: math/pow.hpp
    title: math/pow.hpp
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
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" \n\n#include \"\
    ../../data_structure/wavelet_matrix.hpp\"\n#include \"../../math/pow.hpp\"\n#include\
    \ \"../../random/gen.hpp\"\n#include \"../../template/template.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    int a, b;\n    kin >> a >> b;\n    kout << a + b <<\
    \ kendl;\n\n    rep (200) {\n        int n = kk2::random::rng(1, 1e4);\n     \
    \   int q = 1000;\n        i64 MAX = kk2::pow<i64>(10, kk2::random::rng(1, 19));\n\
    \        vc<i64> a = kk2::random::random_vector<i64>(n, 0, MAX);\n        if (!kk2::random::rng(0,\
    \ 10)) {\n            // kk2::debug::outputln(kout, \"aaaa\");\n            int\
    \ l = 0;\n            while (l < n) {\n                int t = kk2::random::rng(1,\
    \ n - l + 1);\n                fill(a.begin() + l, a.begin() + l + t, kk2::random::rng(0,\
    \ MAX));\n                l += t;\n            }\n        }\n        MAX = *max_element(all(a));\n\
    \        chmax(MAX, 1);\n    \n        kk2::WaveletMatrix<i64> wm(a);\n      \
    \  unordered_map<i64, vc<int>> mp;\n        rep (i, n) mp[a[i]].push_back(i);\n\
    \    \n        vc<pli> rank_query(q);\n        rep (i, q) rank_query[i] = {kk2::random::rng(0,\
    \ MAX), kk2::random::rng(0, n + 1)};\n    \n        rep (i, q) {\n           \
    \ auto [b, pos] = rank_query[i];\n            int simple_rank = 0;\n         \
    \   if (mp.count(b)) simple_rank = lower_bound(all(mp[b]), pos) - mp[b].begin();\n\
    \            if (simple_rank != wm.rank(b, pos)) {\n                cerr << \"\
    rank\" << endl;\n                exit(1);\n            }\n        }\n    \n  \
    \      vc<pli> select_query(q);\n        rep (i, q) select_query[i] = {kk2::random::rng(0,\
    \ MAX), -1};\n        rep (i, q) {\n            select_query[i].second = kk2::random::rng(0,\
    \ min<int>(n, 2 * (mp[select_query[i].first].size() + 10)));\n        }\n    \n\
    \        rep (i, q) {\n            auto [b, k] = select_query[i];\n          \
    \  int simple_select = -1;\n            if (mp.count(b) and k < int(mp[b].size()))\
    \ simple_select = mp[b][k];\n            if (simple_select != wm.select(b, k))\
    \ {\n                cerr << \"select\" << endl;\n                exit(1);\n \
    \           }\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/wavelet_matrix.hpp
  - bit/bitcount.hpp
  - type_traits/integral.hpp
  - data_structure/bit_vector.hpp
  - math/pow.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - type_traits/io.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2025-04-16 11:06:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/wavelet_matrix.test.cpp
- /verify/verify/unit_test/wavelet_matrix.test.cpp.html
title: verify/unit_test/wavelet_matrix.test.cpp
---
