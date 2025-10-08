---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: unionfind/unionfind.hpp
    title: unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    title: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/minimum_spanning_tree.hpp\"\n\n\n\n#include <utility>\n\
    \n#line 1 \"unionfind/unionfind.hpp\"\n\n\n\n#line 5 \"unionfind/unionfind.hpp\"\
    \n#include <vector>\n\nnamespace kk2 {\n\nstruct UnionFind {\n    std::vector<int>\
    \ d;\n\n    UnionFind(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int y)\
    \ { return find(x) == find(y); }\n\n    bool unite(int x, int y) {\n        x\
    \ = find(x), y = find(y);\n        if (x == y) return false;\n        if (-d[x]\
    \ < -d[y]) std::swap(x, y);\n        d[x] += d[y];\n        d[y] = x;\n      \
    \  return true;\n    }\n\n    template <class F> bool unite(int x, int y, const\
    \ F &f) {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n\
    \        if (-d[x] < -d[y]) std::swap(x, y);\n        f(x, y);\n        d[x] +=\
    \ d[y];\n        d[y] = x;\n        return true;\n    }\n\n    int find(int x)\
    \ {\n        if (d[x] < 0) return x;\n        return d[x] = find(d[x]);\n    }\n\
    \n    int size(int x) { return -d[find(x)]; }\n};\n\n} // namespace kk2\n\n\n\
    #line 7 \"graph/tree/minimum_spanning_tree.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class G> auto minimum_spanning_tree(const G &g) {\n    static_assert(!G::directed,\
    \ \"minimum_spanning_tree requires undirected graph\");\n    static_assert(G::weighted,\
    \ \"minimum_spanning_tree requires weighted graph\");\n\n    using value_type\
    \ = typename G::value_type;\n\n    auto edges = g.edges;\n    std::sort(edges.begin(),\
    \ edges.end(), [](const auto &e1, const auto &e2) {\n        return e1.cost <\
    \ e2.cost;\n    });\n    UnionFind uf(g.num_vertices());\n    std::vector<int>\
    \ idxs(g.num_vertices() - 1);\n    value_type total_cost = 0;\n    int i = 0;\n\
    \    for (auto &&e : edges) {\n        if (uf.unite(e.from, e.to)) { idxs[i++]\
    \ = e.id, total_cost += e.cost; }\n    }\n\n    return std::make_pair(total_cost,\
    \ idxs);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\n#define KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\
    \ 1\n\n#include <utility>\n\n#include \"../../unionfind/unionfind.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class G> auto minimum_spanning_tree(const G &g) {\n    static_assert(!G::directed,\
    \ \"minimum_spanning_tree requires undirected graph\");\n    static_assert(G::weighted,\
    \ \"minimum_spanning_tree requires weighted graph\");\n\n    using value_type\
    \ = typename G::value_type;\n\n    auto edges = g.edges;\n    std::sort(edges.begin(),\
    \ edges.end(), [](const auto &e1, const auto &e2) {\n        return e1.cost <\
    \ e2.cost;\n    });\n    UnionFind uf(g.num_vertices());\n    std::vector<int>\
    \ idxs(g.num_vertices() - 1);\n    value_type total_cost = 0;\n    int i = 0;\n\
    \    for (auto &&e : edges) {\n        if (uf.unite(e.from, e.to)) { idxs[i++]\
    \ = e.id, total_cost += e.cost; }\n    }\n\n    return std::make_pair(total_cost,\
    \ idxs);\n}\n\n} // namespace kk2\n\n#endif // KK2_GRAPH_TREE_MINIMUM_SPANNING_TREE_HPP\n"
  dependsOn:
  - unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/tree/minimum_spanning_tree.hpp
  requiredBy: []
  timestamp: '2025-10-08 11:18:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
documentation_of: graph/tree/minimum_spanning_tree.hpp
layout: document
redirect_from:
- /library/graph/tree/minimum_spanning_tree.hpp
- /library/graph/tree/minimum_spanning_tree.hpp.html
title: graph/tree/minimum_spanning_tree.hpp
---
