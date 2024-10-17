---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/cycle_detection.hpp
    title: graph/cycle_detection.hpp
  - icon: ':x:'
    path: graph/graph.hpp
    title: graph/graph.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \ \n\n#include \"../../graph/graph.hpp\"\n#include \"../../graph/cycle_detection.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::AdjList g(n, m, false);\n   \
    \ g.input(kin);\n    if (const auto res = kk2::cycle_detection(g); res) {\n  \
    \      kout << res->size() << '\\n';\n        kout << res->vertices << '\\n';\n\
    \        kout << res->edges << '\\n';\n    } else kout << -1 << '\\n';\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - graph/cycle_detection.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/graph_cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2024-10-17 14:04:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_graph/graph_cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/graph_cycle_detection.test.cpp
- /verify/verify/yosupo_graph/graph_cycle_detection.test.cpp.html
title: verify/yosupo_graph/graph_cycle_detection.test.cpp
---
