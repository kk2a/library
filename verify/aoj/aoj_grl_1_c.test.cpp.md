---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \ \n\n#include \"../../graph/graph.hpp\"\n#include \"../../graph/warshall_floyd.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::DWAdjMat<int> g(n, m);\n    g.input(kin);\n\
    \    auto dist = kk2::WarshallFroyd(g);\n    rep (i, n) {\n        if (dist[i][i].len\
    \ < 0) {\n            kout << \"NEGATIVE CYCLE\" << kendl;\n            return\
    \ 0;\n        }\n    }\n\n    rep (i, n) {\n        rep (j, n) {\n           \
    \ if (dist[i][j].is_valid) kout << dist[i][j].len;\n            else kout << \"\
    INF\";\n            kout << \" \\n\"[j == n - 1];\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - graph/warshall_floyd.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_grl_1_c.test.cpp
  requiredBy: []
  timestamp: '2024-11-05 16:16:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_1_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_1_c.test.cpp
- /verify/verify/aoj/aoj_grl_1_c.test.cpp.html
title: verify/aoj/aoj_grl_1_c.test.cpp
---