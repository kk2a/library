---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: graph/static_graph.hpp
    title: graph/static_graph.hpp
  - icon: ':warning:'
    path: random/graph.hpp
    title: random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_bcc.test.cpp
    title: verify/yosupo_graph/graph_bcc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    title: verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_scc.test.cpp
    title: verify/yosupo_graph/graph_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_shortest_path.test.cpp
    title: verify/yosupo_graph/graph_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    title: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_diameter.test.cpp
    title: verify/yosupo_graph/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca.test.cpp
    title: verify/yosupo_graph/tree_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/tree_lca_static.test.cpp
    title: verify/yosupo_graph/tree_lca_static.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yuki/yuki_1326.test.cpp
    title: verify/yuki/yuki_1326.test.cpp
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
  code: "#ifndef GRAPH_EDGE_HPP\n#define GRAPH_EDGE_HPP 1\n\n#include <type_traits>\n\
    #include <vector>\n\n#include \"../type_traits/type_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace graph {\n\nstruct empty {};\n\ntemplate <class T> struct\
    \ _Edge {\n    int from, to, id;\n    T cost;\n\n    _Edge(int to_, T cost_, int\
    \ from_ = -1, int id_ = -1)\n        : from(from_),\n          to(to_),\n    \
    \      id(id_),\n          cost(cost_) {}\n\n    _Edge() : from(-1), to(-1), id(-1),\
    \ cost() {}\n\n    operator int() const { return to; }\n\n    _Edge rev() const\
    \ { return _Edge(from, cost, to, id); }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << '('\
    \ << id << \", \" << from << \"->\" << to;\n        if constexpr (!std::is_same_v<T,\
    \ empty>) os << \":\" << cost;\n        os << ')';\n    }\n};\n\ntemplate <class\
    \ T> struct _Edges : public std::vector<_Edge<T>> {\n    using std::vector<_Edge<T>>::vector;\n\
    \n    template <class IStream, is_istream_t<IStream> * = nullptr>\n    _Edges\
    \ &input(IStream &is, bool is_one_indexed = false) {\n        for (int i = 0;\
    \ i < (int)this->size(); i++) {\n            int u, v;\n            T w{};\n \
    \           is >> u >> v;\n            if (is_one_indexed) --u, --v;\n       \
    \     if constexpr (!std::is_same_v<T, empty>) is >> w;\n            (*this)[i]\
    \ = _Edge<T>(v, w, u, i);\n        }\n        return *this;\n    }\n\n    template\
    \ <class IStream, is_istream_t<IStream> * = nullptr>\n    friend _Edges &input(_Edges\
    \ &edges, IStream &is, bool is_one_indexed = false) {\n        return edges.input(is,\
    \ is_one_indexed);\n    }\n\n    template <class OStream, is_ostream_t<OStream>\
    \ * = nullptr>\n    void debug_output(OStream &os) const {\n        os << '[';\n\
    \        for (int i = 0; i < (int)this->size(); i++) {\n            if (i) os\
    \ << \", \";\n            (*this)[i].debug_output(os);\n        }\n        os\
    \ << ']';\n    }\n\n    _Edges &add_edge(int from, int to, T cost = T{}) {\n \
    \       this->emplace_back(to, cost, from, this->size());\n        return *this;\n\
    \    }\n\n    friend _Edges &add_edge(_Edges &edges, int from, int to, T cost\
    \ = T{}) {\n        edges.emplace_back(to, cost, from, edges.size());\n      \
    \  return edges;\n    }\n};\n\ntemplate <class T> struct _pair {\n    T cost;\n\
    \    int id;\n\n    _pair(T cost_, int id_) : cost(cost_), id(id_) {}\n\n    _pair()\
    \ : cost(), id(-1) {}\n\n    operator bool() const { return id != -1; }\n\n  \
    \  template <class OStream, is_ostream_t<OStream> * = nullptr>\n    friend OStream\
    \ &operator<<(OStream &os, const _pair &p) {\n        if constexpr (std::is_same_v<T,\
    \ empty>) return os;\n        else return os << p.cost;\n    }\n};\ntemplate <class\
    \ T> using _pairs = std::vector<_pair<T>>;\n\n} // namespace graph\n\ntemplate\
    \ <typename T> using WEdge = graph::_Edge<T>;\ntemplate <typename T> using WEdges\
    \ = graph::_Edges<T>;\nusing Edge = graph::_Edge<graph::empty>;\nusing Edges =\
    \ graph::_Edges<graph::empty>;\n\n} // namespace kk2\n\n#endif // GRAPH_EDGE_HPP\n"
  dependsOn:
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: graph/edge.hpp
  requiredBy:
  - random/graph.hpp
  - graph/graph.hpp
  - graph/static_graph.hpp
  timestamp: '2025-01-03 20:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki/yuki_1326.test.cpp
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
documentation_of: graph/edge.hpp
layout: document
redirect_from:
- /library/graph/edge.hpp
- /library/graph/edge.hpp.html
title: graph/edge.hpp
---