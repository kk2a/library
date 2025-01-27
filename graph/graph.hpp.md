---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    title: verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_scc.test.cpp
    title: verify/yosupo_graph/graph_scc.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/tree_lca.test.cpp
    title: verify/yosupo_graph/tree_lca.test.cpp
  - icon: ':x:'
    path: verify/yuki/yuki_1326.test.cpp
    title: verify/yuki/yuki_1326.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_GRAPH_GRAPH_HPP\n#define KK2_GRAPH_GRAPH_HPP 1\n\n#include <cassert>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n#include \"edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\ntemplate <class\
    \ T, bool is_directed> struct AdjacencyList {\n    using value_type = T;\n   \
    \ using edge_type = _Edge<T>;\n    using edge_container = _Edges<T>;\n\n    using\
    \ directed = std::integral_constant<bool, is_directed>;\n    using weighted =\
    \ std::integral_constant<bool, !std::is_same_v<T, empty>>;\n    using adjacency_list\
    \ = std::true_type;\n    using adjacency_matrix = std::false_type;\n    using\
    \ static_graph = std::false_type;\n\n    AdjacencyList() = default;\n\n    AdjacencyList(int\
    \ n_) : data(n_) {}\n\n    // input \u3092\u4F7F\u3046\u3053\u3068\u304C\u524D\
    \u63D0\n    AdjacencyList(int n_, int m_) : data(n_), edges(m_) {}\n\n    AdjacencyList(int\
    \ n_, const _Edges<T> &edges_) : data(n_), edges(edges_) {\n        for (auto\
    \ &&e : edges) {\n            data[e.from].emplace_back(e);\n            if constexpr\
    \ (!is_directed) {\n                if (e.from != e.to) data[e.to].emplace_back(e.rev());\n\
    \            }\n        }\n    }\n\n    std::vector<_Edges<T>> data;\n    _Edges<T>\
    \ edges;\n\n    int num_vertices() const { return data.size(); }\n\n    int size()\
    \ const { return data.size(); }\n\n    int num_edges() const { return edges.size();\
    \ }\n\n    _Edges<T> &operator[](int k) { return data[k]; }\n\n    const _Edges<T>\
    \ &operator[](int k) const { return data[k]; }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    AdjacencyList &input(IStream &is, bool\
    \ oneindexed = false) {\n        for (int i = 0; i < num_edges(); i++) {\n   \
    \         int u, v;\n            T w{};\n            is >> u >> v;\n         \
    \   if constexpr (!std::is_same_v<T, empty>) is >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge<true>(u, v, w, i);\n        }\n        return\
    \ *this;\n    }\n\n    void edge_clear() {\n        for (auto &v : data) v.clear();\n\
    \        edges.clear();\n    }\n\n    void add_edge(int from, int to, T cost =\
    \ T{}) { _add_edge<false>(from, to, cost, num_edges()); }\n\n    void add_vertex(int\
    \ n = 1) { data.insert(data.end(), n, _Edges<T>()); }\n\n  private:\n    template\
    \ <bool update = false> void _add_edge(int from, int to, T cost, int id) {\n \
    \       data[from].emplace_back(to, cost, from, id);\n        if constexpr (!is_directed)\
    \ {\n            if (from != to) data[to].emplace_back(from, cost, to, id);\n\
    \        }\n        if constexpr (update) edges[id] = _Edge<T>(to, cost, from,\
    \ id);\n        else edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n\
    \    AdjacencyList reverse() const {\n        AdjacencyList res(num_vertices(),\
    \ num_edges());\n        for (auto &&e : edges) { res._add_edge<true>(e.to, e.from,\
    \ e.cost, e.id); }\n        return res;\n    }\n};\n\ntemplate <class T, bool\
    \ is_directed> struct AdjacencyMatrix {\n    using value_type = T;\n    using\
    \ edge_type = _pair<T>;\n    using edge_container = _Edges<T>;\n\n    using directed\
    \ = std::integral_constant<bool, is_directed>;\n    using weighted = std::integral_constant<bool,\
    \ !std::is_same_v<T, empty>>;\n    using adjacency_list = std::false_type;\n \
    \   using adjacency_matrix = std::true_type;\n    using static_graph = std::false_type;\n\
    \n    AdjacencyMatrix() = default;\n\n    AdjacencyMatrix(int n_) : data(n_, _pairs<T>(n_))\
    \ {}\n\n    // input \u3092\u4F7F\u3046\u3053\u3068\u304C\u524D\u63D0\n    AdjacencyMatrix(int\
    \ n_, int m_) : data(n_, _pairs<T>(n_)), edges(m_) {}\n\n    AdjacencyMatrix(int\
    \ n_, const _Edges<T> &edges_) : data(n_, _pairs<T>(n_)), edges(edges_) {\n  \
    \      for (auto &&e : edges) {\n            data[e.from][e.to] = _pair<T>(e.cost,\
    \ e.id);\n            if constexpr (!is_directed) data[e.to][e.from] = _pair<T>(e.cost,\
    \ e.id);\n        }\n    }\n\n    std::vector<_pairs<T>> data;\n    _Edges<T>\
    \ edges;\n\n    int num_vertices() const { return data.size(); }\n\n    int size()\
    \ const { return data.size(); }\n\n    int num_edges() const { return edges.size();\
    \ }\n\n    _pairs<T> &operator[](int k) { return data[k]; }\n\n    const _pairs<T>\
    \ &operator[](int k) const { return data[k]; }\n\n    template <class IStream,\
    \ is_istream_t<IStream> * = nullptr>\n    AdjacencyMatrix &input(IStream &is,\
    \ bool oneindexed = false) {\n        for (int i = 0; i < num_edges(); i++) {\n\
    \            int u, v;\n            T w{};\n            is >> u >> v;\n      \
    \      if constexpr (!std::is_same_v<T, empty>) is >> w;\n            if (oneindexed)\
    \ --u, --v;\n            _add_edge<true>(u, v, w, i);\n        }\n        return\
    \ *this;\n    }\n\n    void edge_clear() {\n        for (auto &&e : edges) {\n\
    \            data[e.from][e.to] = _pair<T>();\n            if constexpr (!is_directed)\
    \ data[e.to][e.from] = _pair<T>();\n        }\n        edges.clear();\n    }\n\
    \n    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from, to,\
    \ cost, num_edges()); }\n\n    void add_vertex(int n = 1) {\n        data.insert(data.end(),\
    \ n, _pairs<T>());\n        for (int i = 0; i < n; i++) data[i].insert(data[i].end(),\
    \ n, _pair<T>());\n    }\n\n  private:\n    template <bool update = false> void\
    \ _add_edge(int from, int to, T cost, int id) {\n        data[from][to] = _pair<T>(cost,\
    \ id);\n        if constexpr (!is_directed) data[to][from] = _pair<T>(cost, id);\n\
    \        if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);\n   \
    \     else edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n    AdjacencyMatrix\
    \ reverse() const {\n        AdjacencyMatrix res(num_vertices(), num_edges());\n\
    \        for (auto &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n\
    \        return res;\n    }\n};\n\ntemplate <class G> G reverse(const G &g) {\n\
    \    return g.reverse();\n}\n\n} // namespace graph\n\ntemplate <typename T> using\
    \ WAdjList = graph::AdjacencyList<T, false>;\ntemplate <typename T> using DWAdjList\
    \ = graph::AdjacencyList<T, true>;\nusing AdjList = graph::AdjacencyList<graph::empty,\
    \ false>;\nusing DAdjList = graph::AdjacencyList<graph::empty, true>;\n\ntemplate\
    \ <typename T> using WAdjMat = graph::AdjacencyMatrix<T, false>;\ntemplate <typename\
    \ T> using DWAdjMat = graph::AdjacencyMatrix<T, true>;\nusing AdjMat = graph::AdjacencyMatrix<graph::empty,\
    \ false>;\nusing DAdjMat = graph::AdjacencyMatrix<graph::empty, true>;\n\nusing\
    \ graph::reverse;\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_GRAPH_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - random/graph.hpp
  timestamp: '2025-01-06 00:03:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yuki/yuki_1326.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
