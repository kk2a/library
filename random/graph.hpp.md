---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':question:'
    path: random/gen.hpp
    title: random/gen.hpp
  - icon: ':question:'
    path: random/seed.hpp
    title: random/seed.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
  code: "#ifndef RANDOM_GRAPH_HPP\n#define RANDOM_GRAPH_HPP 1\n\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../graph/graph.hpp\"\n#include \"gen.hpp\"\n\n\
    namespace kk2 {\n\nnamespace random {\n\ntemplate <bool is_weighted, bool is_directed,\
    \ class T = int>\nusing adjlist = std::conditional<is_weighted, WAdjList<T, is_directed>,\
    \ AdjList<is_directed>>;\n\ntemplate <bool is_weighted, bool is_directed, class\
    \ T = int>\nvoid add_edge(adjlist<is_weighted, is_directed, T> &g, int from, int\
    \ to, T l = 0, T r = 1e9) {\n    if constexpr (is_weighted) {\n        T w = rng(l,\
    \ r);\n        g.add_edge(from, to, w);\n    } else {\n        g.add_edge(from,\
    \ to);\n    }\n}\n\ntemplate <bool is_weighted, bool is_directed, class T = int>\n\
    adjlist<is_weighted, is_directed, T> Graph(int n, int m, T l = 0, T r = 1e9) {\n\
    \    adjlist<is_weighted, is_directed, T> g(n, false);\n    for (int i = 0; i\
    \ < m; i++) {\n        int u = rng(0, n), v = rng(0, n);\n        add_edge<is_weighted,\
    \ is_directed, T>(g, u, v, l, r);\n    }\n    return g;\n}\n\ntemplate <bool is_weighted,\
    \ class T = int>\nadjlist<is_weighted, false, T> Tree(int n, T l = 0, T r = 1e9)\
    \ {\n    adjlist<is_weighted, false, T> g(n, false);\n    std::vector<int> p =\
    \ perm<int>(n);\n    for (int i = 1; i < n; i++) {\n        int u = rng(0, i),\
    \ v = i;\n        add_edge<is_weighted, false, T>(g, p[u], p[v], l, r);\n    }\n\
    \    return g;\n}\n\n} // namespace random\n\n} // namespace kk2\n\n#endif //\
    \ RANDOM_GRAPH_HPP\n"
  dependsOn:
  - graph/graph.hpp
  - type_traits/type_traits.hpp
  - random/gen.hpp
  - random/seed.hpp
  isVerificationFile: false
  path: random/graph.hpp
  requiredBy: []
  timestamp: '2024-12-17 15:23:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/graph.hpp
layout: document
redirect_from:
- /library/random/graph.hpp
- /library/random/graph.hpp.html
title: random/graph.hpp
---
