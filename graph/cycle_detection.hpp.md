---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    title: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle_detection.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <optional>\n#include <type_traits>\n#include <vector>\n\nnamespace kk2\
    \ {\n\nnamespace cycle_detection_impl {\n\nstruct result {\n    std::vector<int>\
    \ edges;\n    std::vector<int> vertices;\n\n    int size() const { return edges.size();\
    \ }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed::value> * = nullptr>\n\
    std::optional<result> cycle_detection(const G &g) {\n    std::vector<int> edges,\
    \ vertices;\n    std::vector<int> buf(g.num_vertices(), -1);\n    auto dfs = [&](auto\
    \ self, int now, int ei, int dep) -> int {\n        buf[now] = dep;\n        for\
    \ (auto &&e : g[now]) {\n            if (e.id == ei) continue;\n            if\
    \ (buf[e.to] >= 0) {\n                edges.resize(dep - buf[e.to] + 1);\n   \
    \             vertices.resize(dep - buf[e.to] + 1);\n                edges.back()\
    \ = e.id;\n                vertices.back() = now;\n                return buf[e.to];\n\
    \            }\n\n            int r = self(self, e.to, e.id, dep + 1);\n     \
    \       if (r >= 0) {\n                if (dep < r) return r;\n              \
    \  edges[dep - r] = e.id;\n                vertices[dep - r] = now;\n        \
    \        return r;\n            }\n        }\n\n        return -1;\n    };\n\n\
    \    for (int i = 0; i < g.num_vertices(); ++i) {\n        if (buf[i] != -1) continue;\n\
    \        if (dfs(dfs, i, -1, 0) >= 0) return result{edges, vertices};\n    }\n\
    \n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges, vertices;\n\n    // buf[i] = x\n    // x >= 0 : \u4ECA\u898B\u3089\u308C\
    \u3066\u3044\u308B\u9802\u70B9dfs\u306E\u6DF1\u3055\u306Fx\n    // x = -1 : \u672A\
    \u8A2A\u554F\n    // x = -2 : \u8A2A\u554F\u6E08\u307F\uFF0E\u9589\u8DEF\u306B\
    \u542B\u307E\u308C\u306A\u3044\n    std::vector<int> buf(g.num_vertices(), -1);\n\
    \n    // \u8FD4\u308A\u5024 x\n    // x = -1 : \u9589\u8DEF\u306A\u3057\n    //\
    \ x >= 0 : \u9589\u8DEF\u3042\u308A\uFF0C\u304B\u3064\uFF0C\u305D\u306E\u9589\u8DEF\
    \u306E\u59CB\u70B9\u306E\u6DF1\u3055\n    auto dfs = [&](auto self, int now, int\
    \ dep) -> int {\n        buf[now] = dep;\n        for (auto &&e : g[now]) {\n\
    \            if (buf[e.to] == -2) continue;\n            if (buf[e.to] >= 0) {\n\
    \                edges.resize(dep - buf[e.to] + 1);\n                vertices.resize(dep\
    \ - buf[e.to] + 1);\n                edges.back() = e.id;\n                vertices.back()\
    \ = now;\n                return buf[e.to];\n            }\n\n            int\
    \ r = self(self, e.to, dep + 1);\n            if (r >= 0) {\n                if\
    \ (dep < r) return r;\n                edges[dep - r] = e.id;\n              \
    \  vertices[dep - r] = now;\n                return r;\n            }\n      \
    \  }\n        buf[now] = -2;\n        return -1;\n    };\n\n    for (int i = 0;\
    \ i < g.num_vertices(); ++i) {\n        if (buf[i] == -2) continue;\n        if\
    \ (dfs(dfs, i, 0) >= 0) return result{edges, vertices};\n    }\n\n    return {};\n\
    }\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_GRAPH_CYCLE_DETECTION_HPP\n#define KK2_GRAPH_CYCLE_DETECTION_HPP\
    \ 1\n\n#include <algorithm>\n#include <optional>\n#include <type_traits>\n#include\
    \ <vector>\n\nnamespace kk2 {\n\nnamespace cycle_detection_impl {\n\nstruct result\
    \ {\n    std::vector<int> edges;\n    std::vector<int> vertices;\n\n    int size()\
    \ const { return edges.size(); }\n};\n\ntemplate <class G, std::enable_if_t<!G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges, vertices;\n    std::vector<int> buf(g.num_vertices(), -1);\n    auto\
    \ dfs = [&](auto self, int now, int ei, int dep) -> int {\n        buf[now] =\
    \ dep;\n        for (auto &&e : g[now]) {\n            if (e.id == ei) continue;\n\
    \            if (buf[e.to] >= 0) {\n                edges.resize(dep - buf[e.to]\
    \ + 1);\n                vertices.resize(dep - buf[e.to] + 1);\n             \
    \   edges.back() = e.id;\n                vertices.back() = now;\n           \
    \     return buf[e.to];\n            }\n\n            int r = self(self, e.to,\
    \ e.id, dep + 1);\n            if (r >= 0) {\n                if (dep < r) return\
    \ r;\n                edges[dep - r] = e.id;\n                vertices[dep - r]\
    \ = now;\n                return r;\n            }\n        }\n\n        return\
    \ -1;\n    };\n\n    for (int i = 0; i < g.num_vertices(); ++i) {\n        if\
    \ (buf[i] != -1) continue;\n        if (dfs(dfs, i, -1, 0) >= 0) return result{edges,\
    \ vertices};\n    }\n\n    return {};\n}\n\ntemplate <class G, std::enable_if_t<G::directed::value>\
    \ * = nullptr>\nstd::optional<result> cycle_detection(const G &g) {\n    std::vector<int>\
    \ edges, vertices;\n\n    // buf[i] = x\n    // x >= 0 : \u4ECA\u898B\u3089\u308C\
    \u3066\u3044\u308B\u9802\u70B9dfs\u306E\u6DF1\u3055\u306Fx\n    // x = -1 : \u672A\
    \u8A2A\u554F\n    // x = -2 : \u8A2A\u554F\u6E08\u307F\uFF0E\u9589\u8DEF\u306B\
    \u542B\u307E\u308C\u306A\u3044\n    std::vector<int> buf(g.num_vertices(), -1);\n\
    \n    // \u8FD4\u308A\u5024 x\n    // x = -1 : \u9589\u8DEF\u306A\u3057\n    //\
    \ x >= 0 : \u9589\u8DEF\u3042\u308A\uFF0C\u304B\u3064\uFF0C\u305D\u306E\u9589\u8DEF\
    \u306E\u59CB\u70B9\u306E\u6DF1\u3055\n    auto dfs = [&](auto self, int now, int\
    \ dep) -> int {\n        buf[now] = dep;\n        for (auto &&e : g[now]) {\n\
    \            if (buf[e.to] == -2) continue;\n            if (buf[e.to] >= 0) {\n\
    \                edges.resize(dep - buf[e.to] + 1);\n                vertices.resize(dep\
    \ - buf[e.to] + 1);\n                edges.back() = e.id;\n                vertices.back()\
    \ = now;\n                return buf[e.to];\n            }\n\n            int\
    \ r = self(self, e.to, dep + 1);\n            if (r >= 0) {\n                if\
    \ (dep < r) return r;\n                edges[dep - r] = e.id;\n              \
    \  vertices[dep - r] = now;\n                return r;\n            }\n      \
    \  }\n        buf[now] = -2;\n        return -1;\n    };\n\n    for (int i = 0;\
    \ i < g.num_vertices(); ++i) {\n        if (buf[i] == -2) continue;\n        if\
    \ (dfs(dfs, i, 0) >= 0) return result{edges, vertices};\n    }\n\n    return {};\n\
    }\n\n} // namespace cycle_detection_impl\n\nusing cycle_detection_impl::cycle_detection;\n\
    \n} // namespace kk2\n\n#endif // KK2_GRAPH_CYCLE_DETECTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/cycle_detection.hpp
  requiredBy: []
  timestamp: '2025-01-02 22:13:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
