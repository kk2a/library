---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\n\nnamespace kk2 {\n\n\
    namespace shortest_path_impl {\n\ntemplate <typename T> struct edge {\n    T len;\n\
    \    bool is_valid;\n};\n\ntemplate <typename WG, typename T = typename WG::value_type>\n\
    std::vector<std::vector<edge<T>>> warshall_froyd(const WG &g) {\n    static_assert(WG::weighted::value,\
    \ \"warshall_froyd requires weighted graph\");\n    static_assert(WG::adjacency_matrix::value,\
    \ \"warshall_froyd requires adjacency matrix\");\n\n    int n = g.size();\n  \
    \  std::vector<std::vector<edge<T>>> res(n, std::vector<edge<T>>(n, {0, false}));\n\
    \    for (int i = 0; i < n; ++i) res[i][i] = {0, true};\n    for (auto &&e : g.edges)\
    \ {\n        {\n            auto &[len, valid] = res[e.from][e.to];\n        \
    \    if (valid) len = std::min(len, e.cost);\n            else {\n           \
    \     len = e.cost;\n                valid = true;\n            }\n        }\n\
    \        if constexpr (!WG::directed::value) {\n            auto &[len, valid]\
    \ = res[e.to][e.from];\n            if (valid) len = std::min(len, e.cost);\n\
    \            else {\n                len = e.cost;\n                valid = true;\n\
    \            }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n      \
    \  for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                if (!res[i][k].is_valid or !res[k][j].is_valid) continue;\n \
    \               if (res[i][j].is_valid)\n                    res[i][j].len = std::min(res[i][j].len,\
    \ res[i][k].len + res[k][j].len);\n                else {\n                  \
    \  res[i][j].len = res[i][k].len + res[k][j].len;\n                    res[i][j].is_valid\
    \ = true;\n                }\n            }\n        }\n    }\n\n    return res;\n\
    }\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_WARSHALL_FLOYD_HPP\n#define KK2_GRAPH_WARSHALL_FLOYD_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \nnamespace kk2 {\n\nnamespace shortest_path_impl {\n\ntemplate <typename T> struct\
    \ edge {\n    T len;\n    bool is_valid;\n};\n\ntemplate <typename WG, typename\
    \ T = typename WG::value_type>\nstd::vector<std::vector<edge<T>>> warshall_froyd(const\
    \ WG &g) {\n    static_assert(WG::weighted::value, \"warshall_froyd requires weighted\
    \ graph\");\n    static_assert(WG::adjacency_matrix::value, \"warshall_froyd requires\
    \ adjacency matrix\");\n\n    int n = g.size();\n    std::vector<std::vector<edge<T>>>\
    \ res(n, std::vector<edge<T>>(n, {0, false}));\n    for (int i = 0; i < n; ++i)\
    \ res[i][i] = {0, true};\n    for (auto &&e : g.edges) {\n        {\n        \
    \    auto &[len, valid] = res[e.from][e.to];\n            if (valid) len = std::min(len,\
    \ e.cost);\n            else {\n                len = e.cost;\n              \
    \  valid = true;\n            }\n        }\n        if constexpr (!WG::directed::value)\
    \ {\n            auto &[len, valid] = res[e.to][e.from];\n            if (valid)\
    \ len = std::min(len, e.cost);\n            else {\n                len = e.cost;\n\
    \                valid = true;\n            }\n        }\n    }\n\n    for (int\
    \ k = 0; k < n; ++k) {\n        for (int i = 0; i < n; ++i) {\n            for\
    \ (int j = 0; j < n; ++j) {\n                if (!res[i][k].is_valid or !res[k][j].is_valid)\
    \ continue;\n                if (res[i][j].is_valid)\n                    res[i][j].len\
    \ = std::min(res[i][j].len, res[i][k].len + res[k][j].len);\n                else\
    \ {\n                    res[i][j].len = res[i][k].len + res[k][j].len;\n    \
    \                res[i][j].is_valid = true;\n                }\n            }\n\
    \        }\n    }\n\n    return res;\n}\n\n} // namespace shortest_path_impl\n\
    \nusing shortest_path_impl::warshall_froyd;\n\n} // namespace kk2\n\n#endif //\
    \ KK2_GRAPH_WARSHALL_FLOYD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
