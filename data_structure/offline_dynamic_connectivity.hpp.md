---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: unionfind/rollback.hpp
    title: unionfind/rollback.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
    title: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/offline_dynamic_connectivity.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"unionfind/rollback.hpp\"\n\n\n\n#line 6 \"unionfind/rollback.hpp\"\
    \n\nnamespace kk2 {\n\nstruct RollbackableUnionFind {\n    std::vector<int> d;\n\
    \    std::vector<std::pair<int, int>> hist;\n    std::vector<int> snaps;\n\n \
    \   RollbackableUnionFind(int n = 0) : d(n, -1) {}\n\n    bool same(int x, int\
    \ y) { return find(x) == find(y); }\n\n    bool unite(int x, int y) {\n      \
    \  x = find(x), y = find(y);\n        if (x == y) return false;\n        if (d[x]\
    \ > d[y]) std::swap(x, y);\n        hist.emplace_back(x, d[x]);\n        d[x]\
    \ += d[y];\n        hist.emplace_back(y, d[y]);\n        d[y] = x;\n        return\
    \ true;\n    }\n\n    int find(int x) {\n        if (d[x] < 0) return x;\n   \
    \     return find(d[x]);\n    }\n\n    int size(int x) { return -d[find(x)]; }\n\
    \n    void snapshot() { snaps.push_back(hist.size()); }\n\n    void rollback()\
    \ {\n        while (int(hist.size()) > snaps.back()) {\n            auto [i, x]\
    \ = hist.back();\n            hist.pop_back();\n            d[i] = x;\n      \
    \  }\n        snaps.pop_back();\n    }\n};\n\n} // namespace kk2\n\n\n#line 10\
    \ \"data_structure/offline_dynamic_connectivity.hpp\"\n\nnamespace kk2 {\n\nstruct\
    \ OfflineDynamicConnectivity {\n  private:\n    int n, q, sz;\n\n    using E =\
    \ std::pair<int, int>;\n    std::vector<std::pair<E, int>> es;\n    std::vector<E>\
    \ seg;\n    std::vector<int> siz;\n\n    void apply(int l, int r, E e) {\n   \
    \     l += sz, r += sz;\n        while (l < r) {\n            if (l & 1) seg[siz[l++]++]\
    \ = e;\n            if (r & 1) seg[siz[--r]++] = e;\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\n    void apply_pre(int l, int r) {\n        l += sz,\
    \ r += sz;\n        while (l < r) {\n            if (l & 1) siz[l++]++;\n    \
    \        if (r & 1) siz[--r]++;\n            l >>= 1, r >>= 1;\n        }\n  \
    \  }\n\n    void seg_build() {\n        for (int i = 1; i < 2 * sz - 1; i++) siz[i\
    \ + 1] += siz[i];\n        seg.resize(siz[2 * sz - 1]);\n        for (int i =\
    \ 2 * sz - 1; i; --i) siz[i] = siz[i - 1];\n    }\n\n  public:\n    RollbackableUnionFind\
    \ uf;\n\n    OfflineDynamicConnectivity(int n_, int q_) : n(n_), q(q_), sz(1),\
    \ uf(n) {\n        while (sz < n) sz <<= 1;\n        siz.resize(2 * sz, 0);\n\
    \    }\n\n    void add_edge(int t, int a, int b) {\n        es.push_back({\n \
    \           {a, b},\n            2 * t\n        });\n    }\n\n    void del_edge(int\
    \ t, int a, int b) {\n        es.push_back({\n            {a, b},\n          \
    \  2 * t + 1\n        });\n    }\n\n    void build(bool is_sorted = false) {\n\
    \        if (!is_sorted) std::sort(es.begin(), es.end());\n        E pree = {-1,\
    \ -1};\n        int pret = -1;\n        for (auto [e, t] : es) {\n           \
    \ if (pree != e) {\n                if (pret != -1) apply_pre(pret, q);\n    \
    \            pree = e;\n                pret = -1;\n            }\n          \
    \  if (t & 1 and pret != -1) {\n                apply_pre(pret, t / 2);\n    \
    \            pret = -1;\n            } else if (~t & 1 and pret == -1) {\n   \
    \             pret = t / 2;\n            }\n        }\n        if (pret != -1)\
    \ apply_pre(pret, q);\n\n        seg_build();\n        pree = {-1, -1};\n    \
    \    pret = -1;\n        for (auto [e, t] : es) {\n            if (pree != e)\
    \ {\n                if (pret != -1) apply(pret, q, pree);\n                pree\
    \ = e;\n                pret = -1;\n            }\n            if (t & 1 and pret\
    \ != -1) {\n                apply(pret, t / 2, e);\n                pret = -1;\n\
    \            } else if (~t & 1 and pret == -1) {\n                pret = t / 2;\n\
    \            }\n        }\n        if (pret != -1) apply(pret, q, pree);\n   \
    \ }\n\n    template <class Query> void run(const Query &query) {\n        auto\
    \ dfs = [&](auto self, int now) -> void {\n            if (now - sz >= q) return;\n\
    \            uf.snapshot();\n            for (int i = siz[now - 1]; i < siz[now];\
    \ i++) uf.unite(seg[i].first, seg[i].second);\n            if (now >= sz) {\n\
    \                query(now - sz);\n            } else {\n                self(self,\
    \ now * 2);\n                self(self, now * 2 + 1);\n            }\n       \
    \     uf.rollback();\n        };\n        dfs(dfs, 1);\n    }\n};\n\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP\n#define KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP\
    \ 1\n\n#include <algorithm>\n#include <unordered_map>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../unionfind/rollback.hpp\"\n\nnamespace kk2 {\n\nstruct\
    \ OfflineDynamicConnectivity {\n  private:\n    int n, q, sz;\n\n    using E =\
    \ std::pair<int, int>;\n    std::vector<std::pair<E, int>> es;\n    std::vector<E>\
    \ seg;\n    std::vector<int> siz;\n\n    void apply(int l, int r, E e) {\n   \
    \     l += sz, r += sz;\n        while (l < r) {\n            if (l & 1) seg[siz[l++]++]\
    \ = e;\n            if (r & 1) seg[siz[--r]++] = e;\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n\n    void apply_pre(int l, int r) {\n        l += sz,\
    \ r += sz;\n        while (l < r) {\n            if (l & 1) siz[l++]++;\n    \
    \        if (r & 1) siz[--r]++;\n            l >>= 1, r >>= 1;\n        }\n  \
    \  }\n\n    void seg_build() {\n        for (int i = 1; i < 2 * sz - 1; i++) siz[i\
    \ + 1] += siz[i];\n        seg.resize(siz[2 * sz - 1]);\n        for (int i =\
    \ 2 * sz - 1; i; --i) siz[i] = siz[i - 1];\n    }\n\n  public:\n    RollbackableUnionFind\
    \ uf;\n\n    OfflineDynamicConnectivity(int n_, int q_) : n(n_), q(q_), sz(1),\
    \ uf(n) {\n        while (sz < n) sz <<= 1;\n        siz.resize(2 * sz, 0);\n\
    \    }\n\n    void add_edge(int t, int a, int b) {\n        es.push_back({\n \
    \           {a, b},\n            2 * t\n        });\n    }\n\n    void del_edge(int\
    \ t, int a, int b) {\n        es.push_back({\n            {a, b},\n          \
    \  2 * t + 1\n        });\n    }\n\n    void build(bool is_sorted = false) {\n\
    \        if (!is_sorted) std::sort(es.begin(), es.end());\n        E pree = {-1,\
    \ -1};\n        int pret = -1;\n        for (auto [e, t] : es) {\n           \
    \ if (pree != e) {\n                if (pret != -1) apply_pre(pret, q);\n    \
    \            pree = e;\n                pret = -1;\n            }\n          \
    \  if (t & 1 and pret != -1) {\n                apply_pre(pret, t / 2);\n    \
    \            pret = -1;\n            } else if (~t & 1 and pret == -1) {\n   \
    \             pret = t / 2;\n            }\n        }\n        if (pret != -1)\
    \ apply_pre(pret, q);\n\n        seg_build();\n        pree = {-1, -1};\n    \
    \    pret = -1;\n        for (auto [e, t] : es) {\n            if (pree != e)\
    \ {\n                if (pret != -1) apply(pret, q, pree);\n                pree\
    \ = e;\n                pret = -1;\n            }\n            if (t & 1 and pret\
    \ != -1) {\n                apply(pret, t / 2, e);\n                pret = -1;\n\
    \            } else if (~t & 1 and pret == -1) {\n                pret = t / 2;\n\
    \            }\n        }\n        if (pret != -1) apply(pret, q, pree);\n   \
    \ }\n\n    template <class Query> void run(const Query &query) {\n        auto\
    \ dfs = [&](auto self, int now) -> void {\n            if (now - sz >= q) return;\n\
    \            uf.snapshot();\n            for (int i = siz[now - 1]; i < siz[now];\
    \ i++) uf.unite(seg[i].first, seg[i].second);\n            if (now >= sz) {\n\
    \                query(now - sz);\n            } else {\n                self(self,\
    \ now * 2);\n                self(self, now * 2 + 1);\n            }\n       \
    \     uf.rollback();\n        };\n        dfs(dfs, 1);\n    }\n};\n\n\n} // namespace\
    \ kk2\n\n#endif // KK2_DATA_STRUCTURE_OFFLINE_DYNAMIC_CONNECTIVITY_HPP\n"
  dependsOn:
  - unionfind/rollback.hpp
  isVerificationFile: false
  path: data_structure/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2025-04-05 12:46:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
documentation_of: data_structure/offline_dynamic_connectivity.hpp
layout: document
redirect_from:
- /library/data_structure/offline_dynamic_connectivity.hpp
- /library/data_structure/offline_dynamic_connectivity.hpp.html
title: data_structure/offline_dynamic_connectivity.hpp
---
