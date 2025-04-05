---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  - icon: ':x:'
    path: data_structure/static_rmq.hpp
    title: data_structure/static_rmq.hpp
  - icon: ':question:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_GRAPH_TREE_EULER_TOUR_HPP\n#define KK2_GRAPH_TREE_EULER_TOUR_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../../data_structure/static_rmq.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <typename G> struct EulerTour {\n    static_assert(!G::directed,\
    \ \"EulerTour requires undirected graph\");\n\n    const G &g;\n    int root,\
    \ id;\n    std::vector<int> in, out, par;\n    std::vector<int> edge_in, edge_out;\n\
    \n    EulerTour(const G &g_, int root_ = 0)\n        : g(g_),\n          root(root_),\n\
    \          id(0),\n          in(g.size(), -1),\n          out(g.size(), -1),\n\
    \          par(g.size(), root),\n          edge_in(g.size() - 1, -1),\n      \
    \    edge_out(g.size() - 1, -1) {\n        init();\n    }\n\n    std::pair<int,\
    \ int> get_edge_idx(int i) const {\n        return std::make_pair(edge_in[i],\
    \ edge_out[i]);\n    }\n\n    std::pair<int, int> get_node_idx(int u) const {\
    \ return std::make_pair(in[u], out[u]); }\n\n    int lca(int u, int v) const {\n\
    \        if (in[u] > in[v]) std::swap(u, v);\n        return std::pair<int, int>(rmq.prod(in[u],\
    \ in[v] + 1)).second;\n    }\n\n    int dist(int u, int v) const {\n        int\
    \ depu = std::pair<int, int>(rmq.get(in[u])).first;\n        int depv = std::pair<int,\
    \ int>(rmq.get(in[v])).first;\n        return depu + depv - 2 * std::pair<int,\
    \ int>(rmq.get(in[lca(u, v)])).first;\n    }\n\n    template <typename F> void\
    \ path_query(int u, int v, bool is_node_query, const F &f) {\n        int l =\
    \ lca(u, v);\n        f(in[l] + (int)!is_node_query, in[u] + 1);\n        f(in[l]\
    \ + 1, in[v] + 1);\n    }\n\n    template <typename F> void subtree_query(int\
    \ u, bool is_node_query, const F &f) {\n        f(in[u] + (int)!is_node_query,\
    \ out[u]);\n    }\n\n  private:\n    StaticRMQ<std::pair<int, int>> rmq;\n\n \
    \   void init() {\n        std::vector<typename StaticRMQ<std::pair<int, int>>::Monoid>\
    \ rmq_init(2 * g.size());\n        auto dfs = [&](auto self, int now, int pre,\
    \ int dep) -> void {\n            in[now] = id;\n            rmq_init[id++] =\
    \ {dep, now};\n            for (auto &&e : g[now]) {\n                if ((int)e\
    \ == pre) continue;\n                par[(int)e] = now;\n                edge_in[e.id]\
    \ = id;\n                self(self, e, now, dep + 1);\n                edge_out[e.id]\
    \ = id++;\n            }\n            out[now] = id;\n            rmq_init[id]\
    \ = {dep - 1, pre};\n        };\n        dfs(dfs, root, -1, 0);\n        for (int\
    \ i = 0; i < (int)g.size(); i++) {\n            if (in[i] == -1) dfs(dfs, i, -1,\
    \ 0);\n        }\n        rmq = StaticRMQ<std::pair<int, int>>(rmq_init);\n  \
    \  }\n};\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_EULER_TOUR_HPP\n"
  dependsOn:
  - data_structure/static_rmq.hpp
  - math/monoid/min.hpp
  - type_traits/io.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/euler_tour.hpp
layout: document
redirect_from:
- /library/graph/tree/euler_tour.hpp
- /library/graph/tree/euler_tour.hpp.html
title: graph/tree/euler_tour.hpp
---
