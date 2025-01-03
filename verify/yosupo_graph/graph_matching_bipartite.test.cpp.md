---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maxflow.hpp
    title: graph/maxflow.hpp
  - icon: ':heavy_check_mark:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/function_util.hpp
    title: template/function_util.hpp
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
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\" \n\n\
    #include \"../../graph/graph.hpp\"\n#include \"../../graph/maxflow.hpp\"\n#include\
    \ \"../../template/template.hpp\"\nusing namespace std;\n\nint main() {\n    int\
    \ l, r, m;\n    kin >> l >> r >> m;\n    kk2::DWAdjList<int> g(l + r + 2);\n \
    \   rep (m) {\n        int a, b;\n        kin >> a >> b;\n        g.add_edge(a,\
    \ l + b, 1);\n    }\n    rep (i, l) g.add_edge(l + r, i, 1);\n    rep (i, r) g.add_edge(l\
    \ + i, l + r + 1, 1);\n\n    kk2::MaxFlow<kk2::DWAdjList<int>> mf(g);\n\n    int\
    \ count = mf.flow(l + r, l + r + 1);\n    kout << count << \"\\n\";\n\n    auto\
    \ tmp = mf.get_edges();\n    for (auto &&e : tmp) {\n        if (count == 0) break;\n\
    \        if (e.flow == 0) continue;\n        kout << e.from << \" \" << e.to -\
    \ l << \"\\n\";\n        count--;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - graph/edge.hpp
  - graph/maxflow.hpp
  - template/template.hpp
  - template/fastio.hpp
  - template/type_alias.hpp
  - template/constant.hpp
  - template/function_util.hpp
  - template/macros.hpp
  - template/io_util.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
  requiredBy: []
  timestamp: '2025-01-03 20:28:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_graph/graph_matching_bipartite.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/graph_matching_bipartite.test.cpp
- /verify/verify/yosupo_graph/graph_matching_bipartite.test.cpp.html
title: verify/yosupo_graph/graph_matching_bipartite.test.cpp
---