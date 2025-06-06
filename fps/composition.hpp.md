---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_composition.test.cpp
    title: verify/yosupo_fps/fps_composition.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/composition.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
    namespace kk2 {\n\n// calculate (g \\circ f) (X)\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nFPS composition(const FPS &f_, const FPS &g_, int\
    \ deg = -1) {\n    if (f_.empty() || g_.empty()) return {};\n    if (deg == -1)\
    \ deg = std::max(size(f_), size(g_));\n    FPS f(f_.begin(), f_.end()), g(g_.begin(),\
    \ g_.end());\n    f.resize(deg), g.resize(deg);\n\n    auto rec = [&](auto self,\
    \ FPS q, int n, int h, int k) -> FPS {\n        if (n == 0) {\n            FPS\
    \ t(std::begin(q), std::begin(q) + k);\n            t.push_back(1);\n        \
    \    FPS u = g * t.rev().inv().rev();\n            FPS p(h * k);\n           \
    \ for (int i = 0; i < (int)size(g); i++) { p[k - 1 - i] = u[i + k]; }\n      \
    \      return p;\n        }\n        FPS nq(4 * h * k), nr(2 * h * k);\n     \
    \   for (int i = 0; i < k; i++) {\n            std::copy(\n                std::begin(q)\
    \ + i * h, std::begin(q) + i * h + n + 1, std::begin(nq) + i * 2 * h);\n     \
    \   }\n        nq[k * 2 * h] += 1;\n        nq.but();\n        for (int i = 0;\
    \ i < 4 * h * k; i += 2) std::swap(nq[i], nq[i + 1]);\n        for (int i = 0;\
    \ i < 2 * h * k; i++) { nr[i] = nq[i * 2] * nq[i * 2 + 1]; }\n        nr.ibut();\n\
    \        nr[0] -= 1;\n        q.assign(h * k, 0);\n        for (int i = 0; i <\
    \ 2 * k; i++) {\n            for (int j = 0; j <= n / 2; j++) { q[i * h / 2 +\
    \ j] = nr[i * h + j]; }\n        }\n        auto p = self(self, q, n / 2, h /\
    \ 2, k * 2);\n        FPS np(4 * h * k);\n        for (int i = 0; i < 2 * k; i++)\
    \ {\n            for (int j = 0; j <= n / 2; j++) { np[i * 2 * h + j * 2 + n %\
    \ 2] = p[i * h / 2 + j]; }\n        }\n        np.but();\n        for (int i =\
    \ 1; i < 4 * h * k; i <<= 1) {\n            std::reverse(std::begin(nq) + i, std::begin(nq)\
    \ + i * 2);\n        }\n        for (int i = 0; i < 4 * h * k; i++) { np[i] *=\
    \ nq[i]; }\n        np.ibut();\n        p.assign(h * k, 0);\n        for (int\
    \ i = 0; i < k; i++) {\n            std::copy(std::begin(np) + i * 2 * h,\n  \
    \                    std::begin(np) + i * 2 * h + n + 1,\n                   \
    \   std::begin(p) + i * h);\n        }\n        return p;\n    };\n\n    int n\
    \ = int(size(f)) - 1, k = 1;\n    int h = 1;\n    while (h < n + 1) h <<= 1;\n\
    \    FPS q(h * k);\n    for (int i = 0; i <= n; i++) q[i] = -f[i];\n    FPS p\
    \ = rec(rec, q, n, h, k);\n    return p.pre(n + 1).rev();\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_FPS_COMPOSITION_HPP\n#define KK2_FPS_COMPOSITION_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <utility>\n\
    #include <vector>\n\nnamespace kk2 {\n\n// calculate (g \\circ f) (X)\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS composition(const FPS\
    \ &f_, const FPS &g_, int deg = -1) {\n    if (f_.empty() || g_.empty()) return\
    \ {};\n    if (deg == -1) deg = std::max(size(f_), size(g_));\n    FPS f(f_.begin(),\
    \ f_.end()), g(g_.begin(), g_.end());\n    f.resize(deg), g.resize(deg);\n\n \
    \   auto rec = [&](auto self, FPS q, int n, int h, int k) -> FPS {\n        if\
    \ (n == 0) {\n            FPS t(std::begin(q), std::begin(q) + k);\n         \
    \   t.push_back(1);\n            FPS u = g * t.rev().inv().rev();\n          \
    \  FPS p(h * k);\n            for (int i = 0; i < (int)size(g); i++) { p[k - 1\
    \ - i] = u[i + k]; }\n            return p;\n        }\n        FPS nq(4 * h *\
    \ k), nr(2 * h * k);\n        for (int i = 0; i < k; i++) {\n            std::copy(\n\
    \                std::begin(q) + i * h, std::begin(q) + i * h + n + 1, std::begin(nq)\
    \ + i * 2 * h);\n        }\n        nq[k * 2 * h] += 1;\n        nq.but();\n \
    \       for (int i = 0; i < 4 * h * k; i += 2) std::swap(nq[i], nq[i + 1]);\n\
    \        for (int i = 0; i < 2 * h * k; i++) { nr[i] = nq[i * 2] * nq[i * 2 +\
    \ 1]; }\n        nr.ibut();\n        nr[0] -= 1;\n        q.assign(h * k, 0);\n\
    \        for (int i = 0; i < 2 * k; i++) {\n            for (int j = 0; j <= n\
    \ / 2; j++) { q[i * h / 2 + j] = nr[i * h + j]; }\n        }\n        auto p =\
    \ self(self, q, n / 2, h / 2, k * 2);\n        FPS np(4 * h * k);\n        for\
    \ (int i = 0; i < 2 * k; i++) {\n            for (int j = 0; j <= n / 2; j++)\
    \ { np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j]; }\n        }\n        np.but();\n\
    \        for (int i = 1; i < 4 * h * k; i <<= 1) {\n            std::reverse(std::begin(nq)\
    \ + i, std::begin(nq) + i * 2);\n        }\n        for (int i = 0; i < 4 * h\
    \ * k; i++) { np[i] *= nq[i]; }\n        np.ibut();\n        p.assign(h * k, 0);\n\
    \        for (int i = 0; i < k; i++) {\n            std::copy(std::begin(np) +\
    \ i * 2 * h,\n                      std::begin(np) + i * 2 * h + n + 1,\n    \
    \                  std::begin(p) + i * h);\n        }\n        return p;\n   \
    \ };\n\n    int n = int(size(f)) - 1, k = 1;\n    int h = 1;\n    while (h < n\
    \ + 1) h <<= 1;\n    FPS q(h * k);\n    for (int i = 0; i <= n; i++) q[i] = -f[i];\n\
    \    FPS p = rec(rec, q, n, h, k);\n    return p.pre(n + 1).rev();\n}\n\n} //\
    \ namespace kk2\n\n#endif /* KK2_FPS_COMPOSITION_HPP */\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/composition.hpp
  requiredBy: []
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_composition.test.cpp
documentation_of: fps/composition.hpp
layout: document
redirect_from:
- /library/fps/composition.hpp
- /library/fps/composition.hpp.html
title: fps/composition.hpp
---
