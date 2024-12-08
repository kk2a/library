---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':x:'
    path: graph/shortest_path.hpp
    title: graph/shortest_path.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../graph/graph.hpp\"\n#include \"../../graph/shortest_path.hpp\"\n#include\
    \ \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ n, m, s, t;\n    kin >> n >> m >> s >> t;\n    kk2::DWAdjList<i64> g(n, m);\n\
    \    g.input(kin);\n    auto [dist, prev] = kk2::ShortestPath(g, s);\n\n    if\
    \ (prev[t].to == -1) {\n        kout << -1 << \"\\n\";\n        return 0;\n  \
    \  }\n\n    std::vector<int> path;\n    for (int now = t; now != -1; now = prev[now].to)\
    \ path.emplace_back(now);\n\n    kout << dist[t] << \" \" << path.size() - 1 <<\
    \ \"\\n\";\n    for (int i = path.size() - 1; i; --i) kout << path[i] << \" \"\
    \ << path[i - 1] << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - graph/shortest_path.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/graph_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 12:34:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_graph/graph_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/graph_shortest_path.test.cpp
- /verify/verify/yosupo_graph/graph_shortest_path.test.cpp.html
title: verify/yosupo_graph/graph_shortest_path.test.cpp
---
