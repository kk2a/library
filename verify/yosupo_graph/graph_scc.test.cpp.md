---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':x:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':x:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
  - icon: ':x:'
    path: template/constant.hpp
    title: template/constant.hpp
  - icon: ':x:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':x:'
    path: template/function_util.hpp
    title: template/function_util.hpp
  - icon: ':x:'
    path: template/io_util.hpp
    title: template/io_util.hpp
  - icon: ':x:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/type_alias.hpp
    title: template/type_alias.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../graph/graph.hpp\"\
    \n#include \"../../graph/scc.hpp\"\n#include \"../../graph/topological_sort.hpp\"\
    \n#include \"../../template/template.hpp\"\nusing namespace std;\n\nint main()\
    \ {\n    int n, m;\n    kin >> n >> m;\n    kk2::DAdjList g(n, m);\n    g.input(kin);\n\
    \    kk2::SCC<kk2::DAdjList> scc(g);\n    auto perm = kk2::topological_sort(scc.dag);\n\
    \    kout << scc.size() << \"\\n\";\n    for (auto &v : perm) { kout << scc.same_scc(v).size()\
    \ << \" \" << scc.same_scc(v) << \"\\n\"; }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - graph/edge.hpp
  - graph/scc.hpp
  - graph/topological_sort.hpp
  - template/template.hpp
  - template/constant.hpp
  - template/fastio.hpp
  - template/function_util.hpp
  - template/io_util.hpp
  - template/macros.hpp
  - template/type_alias.hpp
  isVerificationFile: true
  path: verify/yosupo_graph/graph_scc.test.cpp
  requiredBy: []
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo_graph/graph_scc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_graph/graph_scc.test.cpp
- /verify/verify/yosupo_graph/graph_scc.test.cpp.html
title: verify/yosupo_graph/graph_scc.test.cpp
---
