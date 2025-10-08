---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    title: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/enumerate_triangle.hpp\"\n\n\n\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\ntemplate <class G, class H, class F> void\
    \ enumerate_triangle(const G &g, const F &f) {\n    static_assert(!G::directed,\
    \ \"enumerate_triangle requires undirected graph\");\n    static_assert(H::directed,\
    \ \"enumerate_triangle requires directed graph\");\n\n    H h(g.num_vertices());\n\
    \    for (auto &&e : g.edges) {\n        int u = e.from, v = e.to;\n        if\
    \ ((g[u].size() == g[v].size() and u > v) or g[u].size() > g[v].size()) std::swap(u,\
    \ v);\n        h.add_edge(u, v);\n    }\n    if constexpr (H::static_graph) h.build();\n\
    \    std::vector<int> buf(g.num_vertices(), -1);\n    for (int i = 0; i < g.num_vertices();\
    \ i++) {\n        for (auto &&e1 : h[i]) buf[e1.to] = i;\n        for (auto &&e1\
    \ : h[i])\n            for (auto &&e2 : h[e1.to])\n                if (buf[e2.to]\
    \ == i) f(i, e1.to, e2.to);\n    }\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\n#define KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\
    \ 1\n\n#include <utility>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ G, class H, class F> void enumerate_triangle(const G &g, const F &f) {\n   \
    \ static_assert(!G::directed, \"enumerate_triangle requires undirected graph\"\
    );\n    static_assert(H::directed, \"enumerate_triangle requires directed graph\"\
    );\n\n    H h(g.num_vertices());\n    for (auto &&e : g.edges) {\n        int\
    \ u = e.from, v = e.to;\n        if ((g[u].size() == g[v].size() and u > v) or\
    \ g[u].size() > g[v].size()) std::swap(u, v);\n        h.add_edge(u, v);\n   \
    \ }\n    if constexpr (H::static_graph) h.build();\n    std::vector<int> buf(g.num_vertices(),\
    \ -1);\n    for (int i = 0; i < g.num_vertices(); i++) {\n        for (auto &&e1\
    \ : h[i]) buf[e1.to] = i;\n        for (auto &&e1 : h[i])\n            for (auto\
    \ &&e2 : h[e1.to])\n                if (buf[e2.to] == i) f(i, e1.to, e2.to);\n\
    \    }\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_ENUMERATE_TRIANGLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_triangle.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:18:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
documentation_of: graph/enumerate_triangle.hpp
layout: document
redirect_from:
- /library/graph/enumerate_triangle.hpp
- /library/graph/enumerate_triangle.hpp.html
title: graph/enumerate_triangle.hpp
---
