---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle_detection.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <optional>\n#include <type_traits>\n#include <vector>\n\nnamespace kk2\
    \ {\n\nnamespace cycle_detection_impl {\n\nstruct result {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n\n    int size() const { return edges.size();\
    \ }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed()> * = nullptr>\n\
    std::optional<result> cycle_detection(const G &g) {\n    std::vector<int> edges;\n\
    \    std::vector<int> vertices;\n    edges.reserve(g.num_vertices());\n    vertices.reserve(g.num_vertices());\n\
    \    std::vector<bool> used(g.num_vertices());\n    auto dfs = [&](auto self,\
    \ int now, int ei) -> bool {\n        for (auto &&e : g[now]) {\n            if\
    \ (e.id == ei) continue;\n            if (used[e.to]) {\n                edges.emplace_back(e.id);\n\
    \                int idx = std::find(vertices.begin(), vertices.end(), e.to) -\
    \ vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + idx, vertices.end());\n                edges = std::vector<int>(edges.begin()\
    \ + idx, edges.end());\n                return true;\n            }\n\n      \
    \      vertices.emplace_back(e.to);\n            edges.emplace_back(e.id);\n \
    \           used[e.to] = true;\n\n            if (self(self, e.to, e.id)) return\
    \ true;\n\n            vertices.pop_back();\n            edges.pop_back();\n \
    \       }\n        return false;\n    };\n\n    for (int i = 0; i < g.num_vertices();\
    \ ++i) {\n        if (used[i]) continue;\n        vertices.emplace_back(i);\n\
    \        if (dfs(dfs, i, -1)) return result{edges, vertices};\n        vertices.pop_back();\n\
    \    }\n\n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed()>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n    std::vector<bool> used(g.num_vertices()),\
    \ now_use(g.num_vertices());\n    edges.reserve(g.num_vertices());\n    vertices.reserve(g.num_vertices());\n\
    \n    auto dfs = [&](auto self, int now) -> bool {\n        used[now] = true;\n\
    \        for (auto &&e : g[now]) {\n            if (used[e.to]) {\n          \
    \      if (!now_use[e.to]) return false;\n                edges.emplace_back(e.id);\n\
    \                int idx = std::find(vertices.begin(), vertices.end(), e.to) -\
    \ vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + idx, vertices.end());\n                edges = std::vector<int>(edges.begin()\
    \ + idx, edges.end());\n                return true;\n            }\n\n      \
    \      vertices.emplace_back(e.to);\n            edges.emplace_back(e.id);\n \
    \           used[e.to] = true;\n            now_use[e.to] = true;\n\n        \
    \    if (self(self, e.to)) return true;\n\n            vertices.pop_back();\n\
    \            edges.pop_back();\n            now_use[e.to] = false;\n        }\n\
    \        return false;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i)\
    \ {\n        if (used[i]) continue;\n        vertices.emplace_back(i);\n     \
    \   now_use[i] = true;\n        if (dfs(dfs, i)) return result{edges, vertices};\n\
    \        vertices.pop_back();\n        now_use[i] = false;\n    }\n\n    return\
    \ {};\n}\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_CYCLE_DETECTION_HPP\n#define KK2_GRAPH_CYCLE_DETECTION_HPP\
    \ 1\n\n#include <algorithm>\n#include <optional>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace cycle_detection_impl {\n\nstruct result\
    \ {\n    std::vector<int> edges;\n    std::vector<int> vertices;\n\n    int size()\
    \ const { return edges.size(); }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed()>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n    edges.reserve(g.num_vertices());\n\
    \    vertices.reserve(g.num_vertices());\n    std::vector<bool> used(g.num_vertices());\n\
    \    auto dfs = [&](auto self, int now, int ei) -> bool {\n        for (auto &&e\
    \ : g[now]) {\n            if (e.id == ei) continue;\n            if (used[e.to])\
    \ {\n                edges.emplace_back(e.id);\n                int idx = std::find(vertices.begin(),\
    \ vertices.end(), e.to) - vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + idx, vertices.end());\n                edges = std::vector<int>(edges.begin()\
    \ + idx, edges.end());\n                return true;\n            }\n\n      \
    \      vertices.emplace_back(e.to);\n            edges.emplace_back(e.id);\n \
    \           used[e.to] = true;\n\n            if (self(self, e.to, e.id)) return\
    \ true;\n\n            vertices.pop_back();\n            edges.pop_back();\n \
    \       }\n        return false;\n    };\n\n    for (int i = 0; i < g.num_vertices();\
    \ ++i) {\n        if (used[i]) continue;\n        vertices.emplace_back(i);\n\
    \        if (dfs(dfs, i, -1)) return result{edges, vertices};\n        vertices.pop_back();\n\
    \    }\n\n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed()>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n    std::vector<bool> used(g.num_vertices()),\
    \ now_use(g.num_vertices());\n    edges.reserve(g.num_vertices());\n    vertices.reserve(g.num_vertices());\n\
    \n    auto dfs = [&](auto self, int now) -> bool {\n        used[now] = true;\n\
    \        for (auto &&e : g[now]) {\n            if (used[e.to]) {\n          \
    \      if (!now_use[e.to]) return false;\n                edges.emplace_back(e.id);\n\
    \                int idx = std::find(vertices.begin(), vertices.end(), e.to) -\
    \ vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + idx, vertices.end());\n                edges = std::vector<int>(edges.begin()\
    \ + idx, edges.end());\n                return true;\n            }\n\n      \
    \      vertices.emplace_back(e.to);\n            edges.emplace_back(e.id);\n \
    \           used[e.to] = true;\n            now_use[e.to] = true;\n\n        \
    \    if (self(self, e.to)) return true;\n\n            vertices.pop_back();\n\
    \            edges.pop_back();\n            now_use[e.to] = false;\n        }\n\
    \        return false;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i)\
    \ {\n        if (used[i]) continue;\n        vertices.emplace_back(i);\n     \
    \   now_use[i] = true;\n        if (dfs(dfs, i)) return result{edges, vertices};\n\
    \        vertices.pop_back();\n        now_use[i] = false;\n    }\n\n    return\
    \ {};\n}\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_CYCLE_DETECTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2024-10-14 19:35:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
documentation_of: graph/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/cycle_detection.hpp
- /library/graph/cycle_detection.hpp.html
title: graph/cycle_detection.hpp
---