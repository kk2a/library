---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_b.test.cpp
    title: verify/aoj/aoj_grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/bellman_ford.hpp\"\n\n\n\n#include <limits>\n\
    #include <vector>\n\nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate\
    \ <class T>\nstruct bf_edge {\n    int to, id;\n};\n\ntemplate <class T>\nstruct\
    \ bf_len {\n    T len;\n    bool inf, minf;\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        if (minf)\
    \ os << \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n\
    \    }\n};\n\ntemplate <class T>\nstruct bf_result {\n    std::vector<bf_len<T>>\
    \ dist;\n    std::vector<bf_edge<T>> prev;\n};\n\ntemplate <class WG, class T\
    \ = typename WG::value_type>\nbf_result<T> bellman_ford(const WG &g, int start)\
    \ {\n    static_assert(WG::weighted::value, \"bellman_ford requires weighted graph\"\
    );\n    static_assert(WG::directed::value, \"bellman_ford requires directed graph\"\
    );\n\n    std::vector<bf_len<T>> dist(g.num_vertices(), {0, true, false});\n \
    \   std::vector<bf_edge<T>> prev(g.num_vertices(), {-1, -1});\n    dist[start]\
    \ = {0, false, false};\n\n    int iter = g.num_vertices();\n    while (iter--)\
    \ {\n        bool update = false;\n        for (int i = 0; i < g.num_edges();\
    \ i++) {\n            auto e = g.edges[i];\n            if (dist[e.from].inf)\
    \ continue;\n            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len\
    \ + e.cost) {\n                update = true;\n                dist[e.to].len\
    \ = dist[e.from].len + e.cost;\n                dist[e.to].inf = false;\n    \
    \            prev[e.to] = {e.from, i};\n            }\n        }\n        if (!update)\
    \ return {dist, prev};\n    }\n\n    iter = g.num_vertices();\n    while (iter--)\
    \ {\n        for (int i = 0; i < g.num_edges(); i++) {\n            auto e = g.edges[i];\n\
    \            if (dist[e.from].inf) continue;\n            if (dist[e.to].inf or\
    \ dist[e.to].len > dist[e.from].len + e.cost) {\n                dist[e.to].minf\
    \ = true;\n                dist[e.to].len = dist[e.from].len + e.cost;\n     \
    \       }\n            if (dist[e.from].minf) dist[e.to].minf = true;\n      \
    \  }\n    }\n\n    return {dist, prev};\n}\n\n} // namespace shortest_path_impl\n\
    \nusing shortest_path_impl::bellman_ford;\n\n} // namespace kk2\n\n\n\n"
  code: "#ifndef KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\n#define KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\
    \ 1\n\n#include <limits>\n#include <vector>\n\nnamespace kk2 {\n\nnamespace shortest_path_impl\
    \ {\n\ntemplate <class T>\nstruct bf_edge {\n    int to, id;\n};\n\ntemplate <class\
    \ T>\nstruct bf_len {\n    T len;\n    bool inf, minf;\n\n    template <class\
    \ OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream &os)\
    \ const {\n        if (minf) os << \"MINF\";\n        else if (inf) os << \"INF\"\
    ;\n        else os << len;\n    }\n};\n\ntemplate <class T>\nstruct bf_result\
    \ {\n    std::vector<bf_len<T>> dist;\n    std::vector<bf_edge<T>> prev;\n};\n\
    \ntemplate <class WG, class T = typename WG::value_type>\nbf_result<T> bellman_ford(const\
    \ WG &g, int start) {\n    static_assert(WG::weighted::value, \"bellman_ford requires\
    \ weighted graph\");\n    static_assert(WG::directed::value, \"bellman_ford requires\
    \ directed graph\");\n\n    std::vector<bf_len<T>> dist(g.num_vertices(), {0,\
    \ true, false});\n    std::vector<bf_edge<T>> prev(g.num_vertices(), {-1, -1});\n\
    \    dist[start] = {0, false, false};\n\n    int iter = g.num_vertices();\n  \
    \  while (iter--) {\n        bool update = false;\n        for (int i = 0; i <\
    \ g.num_edges(); i++) {\n            auto e = g.edges[i];\n            if (dist[e.from].inf)\
    \ continue;\n            if (dist[e.to].inf or dist[e.to].len > dist[e.from].len\
    \ + e.cost) {\n                update = true;\n                dist[e.to].len\
    \ = dist[e.from].len + e.cost;\n                dist[e.to].inf = false;\n    \
    \            prev[e.to] = {e.from, i};\n            }\n        }\n        if (!update)\
    \ return {dist, prev};\n    }\n\n    iter = g.num_vertices();\n    while (iter--)\
    \ {\n        for (int i = 0; i < g.num_edges(); i++) {\n            auto e = g.edges[i];\n\
    \            if (dist[e.from].inf) continue;\n            if (dist[e.to].inf or\
    \ dist[e.to].len > dist[e.from].len + e.cost) {\n                dist[e.to].minf\
    \ = true;\n                dist[e.to].len = dist[e.from].len + e.cost;\n     \
    \       }\n            if (dist[e.from].minf) dist[e.to].minf = true;\n      \
    \  }\n    }\n\n    return {dist, prev};\n}\n\n} // namespace shortest_path_impl\n\
    \nusing shortest_path_impl::bellman_ford;\n\n} // namespace kk2\n\n\n#endif //\
    \ KK2_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/bellman_ford.hpp
  requiredBy: []
  timestamp: '2025-02-15 18:31:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_b.test.cpp
documentation_of: graph/shortest_path/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/bellman_ford.hpp
- /library/graph/shortest_path/bellman_ford.hpp.html
title: graph/shortest_path/bellman_ford.hpp
---
