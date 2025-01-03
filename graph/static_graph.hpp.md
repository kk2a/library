---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  code: "#ifndef GRAPH_STATIC_GRAPH_HPP\n#define GRAPH_STATIC_GRAPH_HPP 1\n\n#include\
    \ <cassert>\n#include <type_traits>\n#include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\
    \n#include \"edge.hpp\"\n\nnamespace kk2 {\n\nnamespace graph {\n\ntemplate <class\
    \ T, bool is_directed> struct StaticAdjacencyList {\n    using value_type = T;\n\
    \    using edge_type = _Edge<T>;\n    using edge_container = _Edges<T>;\n\n  \
    \  using directed = std::integral_constant<bool, is_directed>;\n    using weighted\
    \ = std::integral_constant<bool, !std::is_same_v<T, empty>>;\n    using adjacency_list\
    \ = std::true_type;\n    using adjacency_matrix = std::false_type;\n    using\
    \ static_graph = std::true_type;\n\n    StaticAdjacencyList() = default;\n\n \
    \   StaticAdjacencyList(int n_) : head(n_) {}\n\n    StaticAdjacencyList(int n_,\
    \ int m_) : head(n_), edges(m_) {}\n\n    StaticAdjacencyList(int n_, const _Edges<T>\
    \ &edges_) : head(n_), edges(edges_) {\n        for (auto &&e : edges) {\n   \
    \         head[e.from]++;\n            if constexpr (!is_directed) {\n       \
    \         if (e.from != e.to) head[e.to]++;\n            }\n        }\n      \
    \  build();\n    }\n\n    std::vector<int> head;\n    _Edges<T> edges, data;\n\
    \    bool is_built = false;\n\n    int num_vertices() const { return head.size();\
    \ }\n\n    int size() const { return head.size(); }\n\n    int num_edges() const\
    \ { return edges.size(); }\n\n    template <class It> struct Es {\n        It\
    \ b, e;\n\n        It begin() const { return b; }\n\n        It end() const {\
    \ return e; }\n\n        int size() const { return int(e - b); }\n\n        auto\
    \ &&operator[](int k) const { return b[k]; }\n    };\n\n    Es<typename _Edges<T>::iterator>\
    \ operator[](int k) {\n        if (!is_built) build();\n        if (k == (int)head.size()\
    \ - 1)\n            return Es<typename _Edges<T>::iterator>{data.begin() + head[k],\
    \ data.end()};\n        return Es<typename _Edges<T>::iterator>{data.begin() +\
    \ head[k], data.begin() + head[k + 1]};\n    }\n\n    const Es<typename _Edges<T>::const_iterator>\
    \ operator[](int k) const {\n        assert(is_built);\n        if (k == (int)head.size()\
    \ - 1)\n            return Es<typename _Edges<T>::const_iterator>{data.begin()\
    \ + head[k], data.end()};\n        return Es<typename _Edges<T>::const_iterator>{data.begin()\
    \ + head[k],\n                                                      data.begin()\
    \ + head[k + 1]};\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    StaticAdjacencyList &input(IStream &is, bool oneindexed =\
    \ false) {\n        for (int i = 0; i < num_edges(); i++) {\n            int u,\
    \ v;\n            T w{};\n            is >> u >> v;\n            if constexpr\
    \ (!std::is_same_v<T, empty>) is >> w;\n            if (oneindexed) --u, --v;\n\
    \            _add_edge<true>(u, v, w, i);\n        }\n\n        build();\n   \
    \     return *this;\n    }\n\n    void add_edge(int from, int to, T cost = T{})\
    \ { _add_edge<false>(from, to, cost, num_edges()); }\n\n    void add_vertex(int\
    \ n = 1) { head.insert(head.end(), n, 0); }\n\n    void build() {\n        is_built\
    \ = true;\n        for (unsigned int i = 1; i < head.size(); ++i) head[i] += head[i\
    \ - 1];\n        data.resize(head.back());\n        for (auto &&e : edges) {\n\
    \            data[--head[e.from]] = e;\n            if constexpr (!is_directed)\
    \ {\n                if (e.from != e.to) data[--head[e.to]] = e.rev();\n     \
    \       }\n        }\n    }\n\n  private:\n    template <bool update = false>\
    \ void _add_edge(int from, int to, T cost, int id) {\n        head[from]++;\n\
    \        if constexpr (!is_directed) {\n            if (from != to) head[to]++;\n\
    \        }\n        if constexpr (update) edges[id] = _Edge<T>(to, cost, from,\
    \ id);\n        else edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n\
    \    StaticAdjacencyList reverse() const {\n        StaticAdjacencyList res(num_vertices(),\
    \ num_edges());\n        for (auto &&e : edges) { res._add_edge<true>(e.to, e.from,\
    \ e.cost, e.id); }\n        res.build();\n        return res;\n    }\n};\n\ntemplate\
    \ <class G, std::enable_if_t<G::static_graph::value> * = nullptr> G reverse(const\
    \ G &g) {\n    return g.reverse();\n}\n\n} // namespace graph\n\ntemplate <typename\
    \ T> using SWAdjList = graph::StaticAdjacencyList<T, false>;\ntemplate <typename\
    \ T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;\nusing SAdjList =\
    \ graph::StaticAdjacencyList<graph::empty, false>;\nusing SDAdjList = graph::StaticAdjacencyList<graph::empty,\
    \ true>;\n\nusing graph::reverse;\n\n} // namespace kk2\n\n#endif // GRAPH_STATIC_GRAPH_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/static_graph.hpp
  requiredBy: []
  timestamp: '2025-01-03 20:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
documentation_of: graph/static_graph.hpp
layout: document
redirect_from:
- /library/graph/static_graph.hpp
- /library/graph/static_graph.hpp.html
title: graph/static_graph.hpp
---
