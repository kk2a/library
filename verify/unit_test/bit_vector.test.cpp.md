---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/bitcount.hpp
    title: bit/bitcount.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
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
    ../../data_structure/bit_vector.hpp\"\n#include \"../../random/gen.hpp\"\n#include\
    \ \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ a, b;\n    kin >> a >> b;\n    kout << a + b << kendl;\n\n    rep (2000) {\n\
    \        int n = kk2::random::rng(1, 1e4);\n        auto a = kk2::random::random_vector<int>(n,\
    \ 0, 2);\n    \n        if (!kk2::random::rng(0, 10)) {\n            a.assign(n,\
    \ 0);\n        }\n        if (!kk2::random::rng(0, 10)) {\n            a.assign(n,\
    \ 1);\n        }\n    \n        kk2::BitVector bv(n);\n        rep (i, n) if (a[i]\
    \ == 1) bv.set(i);\n        bv.build();\n    \n        vc<int> zero, one;\n  \
    \      vc<int> zero_acc(n + 1), one_acc(n + 1);\n        rep (i, n) {\n      \
    \      if (a[i] == 0) zero.push_back(i);\n            else one.push_back(i);\n\
    \            zero_acc[i + 1] = zero_acc[i] + (a[i] == 0);\n            one_acc[i\
    \ + 1] = one_acc[i] + (a[i] == 1);\n        }\n    \n        int q = 1000;\n \
    \       rep (q) {\n            int i = kk2::random::rng(0, n);\n            int\
    \ naive_rank0 = zero_acc[i];\n            int naive_rank1 = one_acc[i];\n    \
    \        int naive_select0 = -1;\n            int naive_select1 = -1;\n      \
    \      if (i < (int)zero.size()) naive_select0 = zero[i];\n            if (i <\
    \ (int)one.size()) naive_select1 = one[i];\n            if (naive_rank0 != bv.rank0(i))\
    \ {\n                cerr << \"rank0\" << endl;\n                exit(1);\n  \
    \          }\n            if (naive_rank1 != bv.rank1(i)) {\n                cerr\
    \ << \"rank1\" << endl;\n                exit(1);\n            }\n           \
    \ if (naive_select0 != bv.select0(i)) {\n                cerr << \"select0\" <<\
    \ endl;\n                exit(1);\n            }\n            if (naive_select1\
    \ != bv.select1(i)) {\n                cerr << \"select1\" << endl;\n        \
    \        exit(1);\n            }\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/bit_vector.hpp
  - bit/bitcount.hpp
  - type_traits/type_traits.hpp
  - random/gen.hpp
  - random/seed.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/type_alias.hpp
  - template/fastio.hpp
  - template/io_util.hpp
  - template/macros.hpp
  isVerificationFile: true
  path: verify/unit_test/bit_vector.test.cpp
  requiredBy: []
  timestamp: '2025-03-28 03:34:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/bit_vector.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/bit_vector.test.cpp
- /verify/verify/unit_test/bit_vector.test.cpp.html
title: verify/unit_test/bit_vector.test.cpp
---
