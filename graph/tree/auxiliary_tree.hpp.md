---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/tree/heavy_light_decomposition.hpp
    title: graph/tree/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/auxiliary_tree.hpp\"\n\n\n\n#line 1 \"graph/tree/heavy_light_decomposition.hpp\"\
    \n\n\n\nnamespace kk2 {\n\ntemplate <typename G>\nstruct HeavyLightDecomposition\
    \ {\n    G& g;\n    int root, id;\n    vector<int> sz, in, out, head, par, dep;\n\
    \    HeavyLightDecomposition(G& g_, int root_ = 0) \n        : g(g_),\n      \
    \    root(root_),\n          id(0),\n          sz(g.size(), 0),\n          in(g.size(),\
    \ -1),\n          out(g.size(), -1),\n          head(g.size(), root),\n      \
    \    par(g.size(), root),\n          dep(g.size(), 0) {\n        init();\n   \
    \ }\n\n    int lca(int u, int v) const {\n        while (head[u] != head[v]) {\n\
    \            if (in[u] < in[v]) swap(u, v);\n            u = par[head[u]];\n \
    \       }\n        return dep[u] < dep[v] ? u : v;\n    }\n\n    int dist(int\
    \ u, int v) const {\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n  \
    \  }\n\n  private:\n    void init() {\n        auto dfs_sz = [&](auto self, int\
    \ now) -> void {\n            sz[now] = 1;\n            for (auto& e : g[now])\
    \ {\n                if ((int)e == par[now]) {\n                    if (g[now].size()\
    \ >= 2 and e == g[now][0])\n                        swap(e, g[now][1]);\n    \
    \                else \n                        continue;\n                }\n\
    \                par[(int)e] = now;\n                dep[(int)e] = dep[now] +\
    \ 1;\n                self(self, (int)e);\n                sz[now] += sz[(int)e];\n\
    \                if (sz[(int)e] > sz[(int)g[now][0]])\n                    swap(e,\
    \ g[now][0]);\n            }\n        };\n        dfs_sz(dfs_sz, root);\n\n  \
    \      auto dfs_hld = [&](auto self, int now) -> void {\n            in[now] =\
    \ id++;\n            for (auto& e : g[now]) {\n                if ((int)e == par[now])\
    \ continue;\n                head[(int)e] = ((int)e == (int)g[now][0] ? head[now]\
    \ : (int)e);\n                self(self, (int)e);\n            }\n           \
    \ out[now] = id;\n        };\n        dfs_hld(dfs_hld, root);\n    }\n};\n\n}\
    \ // namespace kk2\n\n\n#line 5 \"graph/tree/auxiliary_tree.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <typename G>\nstruct AuxiliaryTree {\n    G g;\n    HeavyLightDecomposition<G>\
    \ hld;\n    AuxiliaryTree(const G& g_, int root_ = 0) : g(g_), hld(g, root_) {}\n\
    \n    pair<vector<vector<int>>, vector<int>> get(vector<int> ps) {\n        if\
    \ (ps.empty()) return {};\n        sort(begin(ps), end(ps), [&](int i, int j){\n\
    \            return hld.in[i] < hld.in[j]; });\n        for (int i = 0, ps_size\
    \ = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
    \ ps[i + 1]));\n        }\n        sort(begin(ps), end(ps), [&](int i, int j){\n\
    \            return hld.in[i] < hld.in[j]; });\n        ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n\n        vector<vector<int>> aux(ps.size());\n       \
    \ stack<int> st;\n        st.emplace(0);\n        for (int i = 1; i < (int)ps.size();\
    \ i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n            while\
    \ (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
    \            st.emplace(i);\n        }\n        return make_pair(aux, ps);\n \
    \   }\n}; \n\n} // namespace kk2\n\n\n"
  code: "#ifndef GRAPH_TREE_AUXILIARY_TREE_HPP\n#define GRAPH_TREE_AUXILIARY_TREE_HPP\
    \ 1\n\n#include \"heavy_light_decomposition.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <typename G>\nstruct AuxiliaryTree {\n    G g;\n    HeavyLightDecomposition<G>\
    \ hld;\n    AuxiliaryTree(const G& g_, int root_ = 0) : g(g_), hld(g, root_) {}\n\
    \n    pair<vector<vector<int>>, vector<int>> get(vector<int> ps) {\n        if\
    \ (ps.empty()) return {};\n        sort(begin(ps), end(ps), [&](int i, int j){\n\
    \            return hld.in[i] < hld.in[j]; });\n        for (int i = 0, ps_size\
    \ = ps.size(); i < ps_size - 1; i++) {\n            ps.push_back(hld.lca(ps[i],\
    \ ps[i + 1]));\n        }\n        sort(begin(ps), end(ps), [&](int i, int j){\n\
    \            return hld.in[i] < hld.in[j]; });\n        ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n\n        vector<vector<int>> aux(ps.size());\n       \
    \ stack<int> st;\n        st.emplace(0);\n        for (int i = 1; i < (int)ps.size();\
    \ i++) {\n            int l = hld.lca(ps[i], ps[st.top()]);\n            while\
    \ (ps[st.top()] != l) st.pop();\n            aux[st.top()].emplace_back(i);\n\
    \            st.emplace(i);\n        }\n        return make_pair(aux, ps);\n \
    \   }\n}; \n\n} // namespace kk2\n\n#endif // GRAPH_TREE_AUXILIARY_TREE_HPP\n"
  dependsOn:
  - graph/tree/heavy_light_decomposition.hpp
  isVerificationFile: false
  path: graph/tree/auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/auxiliary_tree.hpp
layout: document
redirect_from:
- /library/graph/tree/auxiliary_tree.hpp
- /library/graph/tree/auxiliary_tree.hpp.html
title: graph/tree/auxiliary_tree.hpp
---
