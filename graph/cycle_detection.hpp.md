---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle_detection.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <optional>\n#include <type_traits>\n#include <vector>\n\nnamespace kk2\
    \ {\n\nnamespace cycle_detection_impl {\n\nstruct result {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n\n    int size() const { return edges.size();\
    \ }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed::value> * = nullptr>\n\
    std::optional<result> cycle_detection(const G &g) {\n    std::vector<int> edges(g.num_vertices());\n\
    \    std::vector<int> vertices(g.num_vertices());\n    std::vector<bool> used(g.num_vertices());\n\
    \    auto dfs = [&](auto self, int now, int ei, int idx) -> bool {\n        used[now]\
    \ = true;\n        vertices[idx] = now;\n        for (auto &&e : g[now]) {\n \
    \           if (e.id == ei) continue;\n            edges[idx] = e.id;\n      \
    \      if (used[e.to]) {\n                int start = std::find(vertices.begin(),\
    \ vertices.end(), e.to) - vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + start, vertices.begin() + idx + 1);\n                edges = std::vector<int>(edges.begin()\
    \ + start, edges.begin() + idx + 1);\n                return true;\n         \
    \   }\n\n            if (self(self, e.to, e.id, idx + 1)) return true;\n     \
    \   }\n        return false;\n    };\n\n    for (int i = 0; i < g.num_vertices();\
    \ ++i) {\n        if (used[i]) continue;\n        if (dfs(dfs, i, -1, 0)) return\
    \ result{edges, vertices};\n    }\n\n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges(g.num_vertices());\n    std::vector<int> vertices(g.num_vertices());\n\
    \    // bad[i] \u304C true \u306A\u3089 i \u306F\u9589\u8DEF\u306B\u542B\u307E\
    \u308C\u306A\u3044\n    std::vector<bool> bad(g.num_vertices()), now_use(g.num_vertices());\n\
    \n    auto dfs = [&](auto self, int now, int idx) -> bool {\n        now_use[now]\
    \ = true;\n        vertices[idx] = now;\n        for (auto &&e : g[now]) {\n \
    \           if (bad[e.to]) continue;\n            edges[idx] = e.id;\n       \
    \     if (now_use[e.to]) {\n                int start = std::find(vertices.begin(),\
    \ vertices.end(), e.to) - vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + start, vertices.begin() + idx + 1);\n                edges = std::vector<int>(edges.begin()\
    \ + start, edges.begin() + idx + 1);\n                return true;\n         \
    \   }\n            if (self(self, e.to, idx + 1)) return true;\n        }\n  \
    \      now_use[now] = false;\n        bad[now] = true;\n        return false;\n\
    \    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n        if (bad[i])\
    \ continue;\n        if (dfs(dfs, i, 0)) return result{edges, vertices};\n   \
    \ }\n\n    return {};\n}\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_CYCLE_DETECTION_HPP\n#define KK2_GRAPH_CYCLE_DETECTION_HPP\
    \ 1\n\n#include <algorithm>\n#include <optional>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace cycle_detection_impl {\n\nstruct result\
    \ {\n    std::vector<int> edges;\n    std::vector<int> vertices;\n\n    int size()\
    \ const { return edges.size(); }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges(g.num_vertices());\n    std::vector<int> vertices(g.num_vertices());\n\
    \    std::vector<bool> used(g.num_vertices());\n    auto dfs = [&](auto self,\
    \ int now, int ei, int idx) -> bool {\n        used[now] = true;\n        vertices[idx]\
    \ = now;\n        for (auto &&e : g[now]) {\n            if (e.id == ei) continue;\n\
    \            edges[idx] = e.id;\n            if (used[e.to]) {\n             \
    \   int start = std::find(vertices.begin(), vertices.end(), e.to) - vertices.begin();\n\
    \                vertices = std::vector<int>(vertices.begin() + start, vertices.begin()\
    \ + idx + 1);\n                edges = std::vector<int>(edges.begin() + start,\
    \ edges.begin() + idx + 1);\n                return true;\n            }\n\n \
    \           if (self(self, e.to, e.id, idx + 1)) return true;\n        }\n   \
    \     return false;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i)\
    \ {\n        if (used[i]) continue;\n        if (dfs(dfs, i, -1, 0)) return result{edges,\
    \ vertices};\n    }\n\n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges(g.num_vertices());\n    std::vector<int> vertices(g.num_vertices());\n\
    \    // bad[i] \u304C true \u306A\u3089 i \u306F\u9589\u8DEF\u306B\u542B\u307E\
    \u308C\u306A\u3044\n    std::vector<bool> bad(g.num_vertices()), now_use(g.num_vertices());\n\
    \n    auto dfs = [&](auto self, int now, int idx) -> bool {\n        now_use[now]\
    \ = true;\n        vertices[idx] = now;\n        for (auto &&e : g[now]) {\n \
    \           if (bad[e.to]) continue;\n            edges[idx] = e.id;\n       \
    \     if (now_use[e.to]) {\n                int start = std::find(vertices.begin(),\
    \ vertices.end(), e.to) - vertices.begin();\n                vertices = std::vector<int>(vertices.begin()\
    \ + start, vertices.begin() + idx + 1);\n                edges = std::vector<int>(edges.begin()\
    \ + start, edges.begin() + idx + 1);\n                return true;\n         \
    \   }\n            if (self(self, e.to, idx + 1)) return true;\n        }\n  \
    \      now_use[now] = false;\n        bad[now] = true;\n        return false;\n\
    \    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n        if (bad[i])\
    \ continue;\n        if (dfs(dfs, i, 0)) return result{edges, vertices};\n   \
    \ }\n\n    return {};\n}\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_CYCLE_DETECTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2025-01-02 20:45:27+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
