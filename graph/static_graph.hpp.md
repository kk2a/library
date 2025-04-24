---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: graph/edge.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_GRAPH_STATIC_GRAPH_HPP\n#define KK2_GRAPH_STATIC_GRAPH_HPP 1\n\
    \n#include <cassert>\n#include <type_traits>\n#include <vector>\n\n#include \"\
    ../type_traits/io.hpp\"\n#include \"edge.hpp\"\n\nnamespace kk2 {\n\nnamespace\
    \ graph {\n\ntemplate <class T, bool is_directed> struct StaticAdjacencyList {\n\
    \    using value_type = T;\n    using out_edge_type = _Edge<T>;\n    using out_edges\
    \ = _Edges<T>;\n    using adjacency_container = _Edges<T>;\n    using edge_type\
    \ = _Edge<T>;\n    using edge_collection = _Edges<T>;\n\n    static constexpr\
    \ bool directed = is_directed;\n    static constexpr bool weighted = !std::is_same_v<T,\
    \ empty>;\n    static constexpr bool adjacency_list = true;\n    static constexpr\
    \ bool adjacency_matrix = false;\n    static constexpr bool static_graph = true;\n\
    \n    std::vector<int> head;\n    edge_collection edges;\n    adjacency_container\
    \ data;\n    bool is_built = false;\n\n    StaticAdjacencyList() = default;\n\
    \    StaticAdjacencyList(int n_) : head(n_) {}\n    StaticAdjacencyList(int n_,\
    \ int m_) : head(n_), edges(m_) {}\n    StaticAdjacencyList(int n_, const edge_collection\
    \ &edges_) : head(n_), edges(edges_.size()) {\n        for (auto &&e : edges)\
    \ _add_edge<true>(e.from, e.to, e.cost, e.id);\n        build();\n    }\n\n  \
    \  inline int num_vertices() const { return head.size(); }\n    inline int size()\
    \ const { return head.size(); }\n    inline int num_edges() const { return edges.size();\
    \ }\n    void add_edge(int from, int to, T cost = T{}) { _add_edge<false>(from,\
    \ to, cost, num_edges()); }\n    void add_vertex(int n = 1) { head.insert(head.end(),\
    \ n, 0); }\n    void edge_clear() { *this = StaticAdjacencyList(num_vertices());\
    \ }\n\n    template <class It> struct Es {\n        It b, e;\n        It begin()\
    \ const { return b; }\n        It end() const { return e; }\n        int size()\
    \ const { return int(e - b); }\n        auto &&operator[](int k) const { return\
    \ b[k]; }\n    };\n\n    Es<typename _Edges<T>::iterator> operator[](int k) {\n\
    \        assert(is_built);\n        if (k == (int)head.size() - 1)\n         \
    \   return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.end()};\n\
    \        return Es<typename _Edges<T>::iterator>{data.begin() + head[k], data.begin()\
    \ + head[k + 1]};\n    }\n\n    const Es<typename _Edges<T>::const_iterator> operator[](int\
    \ k) const {\n        assert(is_built);\n        if (k == (int)head.size() - 1)\n\
    \            return Es<typename _Edges<T>::const_iterator>{data.begin() + head[k],\
    \ data.end()};\n        return Es<typename _Edges<T>::const_iterator>{data.begin()\
    \ + head[k],\n                                                      data.begin()\
    \ + head[k + 1]};\n    }\n\n    template <class IStream, is_istream_t<IStream>\
    \ * = nullptr>\n    StaticAdjacencyList &input(IStream &is, bool oneindexed =\
    \ false) {\n        for (int i = 0; i < num_edges(); i++) {\n            int u,\
    \ v;\n            T w{};\n            is >> u >> v;\n            if constexpr\
    \ (weighted) is >> w;\n            if (oneindexed) --u, --v;\n            _add_edge<true>(u,\
    \ v, w, i);\n        }\n\n        build();\n        return *this;\n    }\n\n \
    \   template <class OStream, is_ostream_t<OStream> * = nullptr>\n    void debug_output(OStream\
    \ &os) const {\n        assert(is_built);\n        os << \"[\\n\";\n        for\
    \ (int i = 0; i < num_vertices(); i++) {\n            os << \"  \" << i << \"\
    : [\";\n            for (int j = 0;\n                 j < (i == num_vertices()\
    \ - 1 ? (int)data.size() : head[i + 1]) - head[i];\n                 j++) {\n\
    \                if (j) os << \", \";\n                data[head[i] + j].debug_output(os);\n\
    \            }\n            os << \"]\\n\";\n        }\n        os << \"]\\n\"\
    ;\n    }\n\n    void build() {\n        is_built = true;\n        for (unsigned\
    \ int i = 1; i < head.size(); ++i) head[i] += head[i - 1];\n        data.resize(head.back());\n\
    \        for (auto &&e : edges) {\n            data[--head[e.from]] = e;\n   \
    \         if constexpr (!is_directed) {\n                if (e.from != e.to) data[--head[e.to]]\
    \ = e.rev();\n            }\n        }\n    }\n\n  private:\n    template <bool\
    \ update = false> void _add_edge(int from, int to, T cost, int id) {\n       \
    \ head[from]++;\n        if (!is_directed and from != to) head[to]++;\n      \
    \  if constexpr (update) edges[id] = _Edge<T>(to, cost, from, id);\n        else\
    \ edges.emplace_back(to, cost, from, id);\n    }\n\n  public:\n    StaticAdjacencyList\
    \ reverse() const {\n        StaticAdjacencyList res(num_vertices(), num_edges());\n\
    \        for (auto &&e : edges) res._add_edge<true>(e.to, e.from, e.cost, e.id);\n\
    \        res.build();\n        return res;\n    }\n};\n\n} // namespace graph\n\
    \ntemplate <typename T> using SWAdjList = graph::StaticAdjacencyList<T, false>;\n\
    template <typename T> using SDWAdjList = graph::StaticAdjacencyList<T, true>;\n\
    using SAdjList = graph::StaticAdjacencyList<graph::empty, false>;\nusing SDAdjList\
    \ = graph::StaticAdjacencyList<graph::empty, true>;\n\n} // namespace kk2\n\n\
    #endif // KK2_GRAPH_STATIC_GRAPH_HPP\n"
  dependsOn:
  - type_traits/io.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/static_graph.hpp
  requiredBy: []
  timestamp: '2025-04-24 20:50:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
documentation_of: graph/static_graph.hpp
layout: document
redirect_from:
- /library/graph/static_graph.hpp
- /library/graph/static_graph.hpp.html
title: graph/static_graph.hpp
---
