---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/induced_subgraph.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class G> G induced_subgraph(const\
    \ G &g, const std::vector<int> &vs) {\n    G res(g.num_vertices());\n\n    std::vector<bool>\
    \ used(g.num_vertices(), false);\n    for (int v : vs) used[v] = true;\n\n   \
    \ for (auto e : g.edges)\n        if (used[e.from] and used[e.to]) res.add_edge(e.from,\
    \ e.to, e.cost);\n\n    if constexpr (G::static_graph) res.build();\n\n    return\
    \ res;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_INDUCED_SUBGRAPH_HPP\n#define KK2_GRAPH_INDUCED_SUBGRAPH_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G> G induced_subgraph(const G &g, const std::vector<int> &vs) {\n    G res(g.num_vertices());\n\
    \n    std::vector<bool> used(g.num_vertices(), false);\n    for (int v : vs) used[v]\
    \ = true;\n\n    for (auto e : g.edges)\n        if (used[e.from] and used[e.to])\
    \ res.add_edge(e.from, e.to, e.cost);\n\n    if constexpr (G::static_graph) res.build();\n\
    \n    return res;\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_INDUCED_SUBGRAPH_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/induced_subgraph.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/induced_subgraph.hpp
layout: document
redirect_from:
- /library/graph/induced_subgraph.hpp
- /library/graph/induced_subgraph.hpp.html
title: graph/induced_subgraph.hpp
---
