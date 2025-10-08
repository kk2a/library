---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
  bundledCode: "#line 1 \"graph/shortest_path/warshall_floyd.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\n#line\
    \ 1 \"type_traits/io.hpp\"\n\n\n\n#include <istream>\n#include <ostream>\n#include\
    \ <type_traits>\n\nnamespace kk2 {\n\nnamespace type_traits {\n\nstruct istream_tag\
    \ {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\ntemplate <typename\
    \ T> using is_standard_istream =\n    typename std::conditional<std::is_same<T,\
    \ std::istream>::value\n                                  || std::is_same<T, std::ifstream>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\ntemplate <typename T> using is_standard_ostream =\n\
    \    typename std::conditional<std::is_same<T, std::ostream>::value\n        \
    \                          || std::is_same<T, std::ofstream>::value,\n       \
    \                       std::true_type,\n                              std::false_type>::type;\n\
    template <typename T> using is_user_defined_istream = std::is_base_of<type_traits::istream_tag,\
    \ T>;\ntemplate <typename T> using is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag,\
    \ T>;\n\ntemplate <typename T> using is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
    \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
    \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <typename T>\
    \ using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate <typename\
    \ T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\n} // namespace\
    \ kk2\n\n\n#line 10 \"graph/shortest_path/warshall_floyd.hpp\"\n\nnamespace kk2\
    \ {\n\nnamespace shortest_path_impl {\n\ntemplate <typename T> struct wf_len {\n\
    \    T len;\n    bool inf, minf;\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        if (minf)\
    \ os << \"MINF\";\n        else if (inf) os << \"INF\";\n        else os << len;\n\
    \    }\n};\n\ntemplate <typename WG, typename T = typename WG::value_type>\nstd::vector<std::vector<wf_len<T>>>\
    \ warshall_froyd(const WG &g) {\n    static_assert(WG::weighted, \"warshall_froyd\
    \ requires weighted graph\");\n\n    int n = g.size();\n    std::vector<std::vector<wf_len<T>>>\
    \ res(n, std::vector<wf_len<T>>(n, {0, true, false}));\n    for (int i = 0; i\
    \ < n; ++i) res[i][i] = {0, false, false};\n    for (auto &&e : g.edges) {\n \
    \       {\n            auto &[len, inf, minf] = res[e.from][e.to];\n         \
    \   if (inf or len > e.cost) {\n                len = e.cost;\n              \
    \  inf = false;\n            }\n        }\n        if constexpr (!WG::directed)\
    \ {\n            auto &[len, inf, minf] = res[e.to][e.from];\n            if (inf\
    \ or len > e.cost) {\n                len = e.cost;\n                inf = false;\n\
    \            }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n      \
    \  for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                if (res[i][k].inf or res[k][j].inf) continue;\n             \
    \   if (res[i][j].inf or res[i][j].len > res[i][k].len + res[k][j].len) {\n  \
    \                  res[i][j].len = res[i][k].len + res[k][j].len;\n          \
    \          res[i][j].inf = false;\n                }\n            }\n        }\n\
    \    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len >= 0) continue;\n\
    \        res[k][k].minf = true;\n        for (int i = 0; i < n; ++i) {\n     \
    \       for (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
    \ continue;\n                res[i][j].minf = true;\n            }\n        }\n\
    \    }\n\n    return res;\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_WARSHALL_FLOYD_HPP\n#define KK2_GRAPH_WARSHALL_FLOYD_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../../type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace shortest_path_impl\
    \ {\n\ntemplate <typename T> struct wf_len {\n    T len;\n    bool inf, minf;\n\
    \n    template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        if (minf) os << \"MINF\";\n        else if (inf) os <<\
    \ \"INF\";\n        else os << len;\n    }\n};\n\ntemplate <typename WG, typename\
    \ T = typename WG::value_type>\nstd::vector<std::vector<wf_len<T>>> warshall_froyd(const\
    \ WG &g) {\n    static_assert(WG::weighted, \"warshall_froyd requires weighted\
    \ graph\");\n\n    int n = g.size();\n    std::vector<std::vector<wf_len<T>>>\
    \ res(n, std::vector<wf_len<T>>(n, {0, true, false}));\n    for (int i = 0; i\
    \ < n; ++i) res[i][i] = {0, false, false};\n    for (auto &&e : g.edges) {\n \
    \       {\n            auto &[len, inf, minf] = res[e.from][e.to];\n         \
    \   if (inf or len > e.cost) {\n                len = e.cost;\n              \
    \  inf = false;\n            }\n        }\n        if constexpr (!WG::directed)\
    \ {\n            auto &[len, inf, minf] = res[e.to][e.from];\n            if (inf\
    \ or len > e.cost) {\n                len = e.cost;\n                inf = false;\n\
    \            }\n        }\n    }\n\n    for (int k = 0; k < n; ++k) {\n      \
    \  for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                if (res[i][k].inf or res[k][j].inf) continue;\n             \
    \   if (res[i][j].inf or res[i][j].len > res[i][k].len + res[k][j].len) {\n  \
    \                  res[i][j].len = res[i][k].len + res[k][j].len;\n          \
    \          res[i][j].inf = false;\n                }\n            }\n        }\n\
    \    }\n\n    for (int k = 0; k < n; ++k) {\n        if (res[k][k].len >= 0) continue;\n\
    \        res[k][k].minf = true;\n        for (int i = 0; i < n; ++i) {\n     \
    \       for (int j = 0; j < n; ++j) {\n                if (res[i][k].inf or res[k][j].inf)\
    \ continue;\n                res[i][j].minf = true;\n            }\n        }\n\
    \    }\n\n    return res;\n}\n\n} // namespace shortest_path_impl\n\nusing shortest_path_impl::warshall_froyd;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_WARSHALL_FLOYD_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  isVerificationFile: false
  path: graph/shortest_path/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/shortest_path/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/warshall_floyd.hpp
- /library/graph/shortest_path/warshall_floyd.hpp.html
title: graph/shortest_path/warshall_floyd.hpp
---
