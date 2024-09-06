---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/composition.hpp\"\n\n\n\nnamespace kk2 {\n\n// calculate\
    \ (g \\circ f) (X)\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS composition(FPS f, FPS g, int deg = -1) {\n    if (f.empty() || g.empty())\
    \ return {};\n    \n    auto rec = [&](auto self, FPS q,\n                   int\
    \ n, int h, int k) -> FPS {\n        if (n == 0) {\n            FPS t(begin(q),\
    \ begin(q) + k);\n            t.push_back(1);\n            FPS u = g * t.rev().inv().rev();\n\
    \            FPS p(h * k);\n            for (int i = 0; i < (int)size(g); i++)\
    \ {\n                p[k - 1 - i] = u[i + k];\n            }\n            return\
    \ p;\n        }\n        FPS nq(4 * h * k), nr(2 * h * k);\n        for (int i\
    \ = 0; i < k; i++) {\n            copy(begin(q) + i * h, begin(q) + i * h + n\
    \ + 1,\n                 begin(nq) + i * 2 * h);\n        }\n        nq[k * 2\
    \ * h] += 1;\n        int z = 1;\n        while (z < 2 * h * k) z <<= 1;\n   \
    \     mint invz = mint(z).inv(), invz2 = invz * mint(2).inv();\n        nq.resize(z\
    \ << 1);\n        nq.but();\n        for (int i = 0; i < 4 * h * k; i += 2) swap(nq[i],\
    \ nq[i + 1]);\n        for (int i = 0; i < 2 * h * k; i++) {\n            nr[i]\
    \ = nq[i * 2] * nq[i * 2 + 1];\n        }\n        nr.resize(z);\n        nr.ibut();\n\
    \        for (int i = 0; i < 2 * h * k; i++) nr[i] *= invz;\n        nr[0] -=\
    \ 1;\n        q.assign(h * k, 0);\n        for (int i = 0; i < 2 * k; i++) {\n\
    \            for (int j = 0; j <= n / 2; j++) {\n                q[i * h / 2 +\
    \ j] = nr[i * h + j];\n            }\n        }\n        auto p = self(self, q,\
    \ n / 2, h / 2, k * 2);\n        FPS np(4 * h * k);\n        for (int i = 0; i\
    \ < 2 * k; i++) {\n            for (int j = 0; j <= n / 2; j++) {\n          \
    \      np[i * 2 * h + j * 2 + n % 2] = p[i * h / 2 + j];\n            }\n    \
    \    }\n        np.resize(z << 1);\n        np.but();\n        for (int i = 1;\
    \ i < 4 * h * k; i <<= 1) {\n            reverse(begin(nq) + i, begin(nq) + i\
    \ * 2);\n        }\n        for (int i = 0; i < 4 * h * k; i++) {\n          \
    \  np[i] *= nq[i];\n        }\n        np.ibut();\n        for (int i = 0; i <\
    \ 4 * h * k; i++) np[i] *= invz2;\n        p.assign(h * k, 0);\n        for (int\
    \ i = 0; i < k; i++) {\n            copy(begin(np) + i * 2 * h, begin(np) + i\
    \ * 2 * h + n + 1,\n                 begin(p) + i * h);\n        }\n        return\
    \ p;\n    }; \n\n    if (deg == -1) deg = max(size(f), size(g));\n    f.resize(deg),\
    \ g.resize(deg);\n    int n = int(size(f)) - 1, k = 1;\n    int h = 1;\n    while\
    \ (h < n + 1) h <<= 1;\n    FPS q(h * k);\n    for (int i = 0; i <= n; i++) q[i]\
    \ = -f[i];\n    FPS p = rec(rec, q, n, h, k);\n    return p.pre(n + 1).rev();\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_COMPOSITION_HPP\n#define FPS_COMPOSITION_HPP 1\n\nnamespace kk2\
    \ {\n\n// calculate (g \\circ f) (X)\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS composition(FPS f, FPS g, int deg = -1) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    \n    auto rec = [&](auto self, FPS q,\n     \
    \              int n, int h, int k) -> FPS {\n        if (n == 0) {\n        \
    \    FPS t(begin(q), begin(q) + k);\n            t.push_back(1);\n           \
    \ FPS u = g * t.rev().inv().rev();\n            FPS p(h * k);\n            for\
    \ (int i = 0; i < (int)size(g); i++) {\n                p[k - 1 - i] = u[i + k];\n\
    \            }\n            return p;\n        }\n        FPS nq(4 * h * k), nr(2\
    \ * h * k);\n        for (int i = 0; i < k; i++) {\n            copy(begin(q)\
    \ + i * h, begin(q) + i * h + n + 1,\n                 begin(nq) + i * 2 * h);\n\
    \        }\n        nq[k * 2 * h] += 1;\n        int z = 1;\n        while (z\
    \ < 2 * h * k) z <<= 1;\n        mint invz = mint(z).inv(), invz2 = invz * mint(2).inv();\n\
    \        nq.resize(z << 1);\n        nq.but();\n        for (int i = 0; i < 4\
    \ * h * k; i += 2) swap(nq[i], nq[i + 1]);\n        for (int i = 0; i < 2 * h\
    \ * k; i++) {\n            nr[i] = nq[i * 2] * nq[i * 2 + 1];\n        }\n   \
    \     nr.resize(z);\n        nr.ibut();\n        for (int i = 0; i < 2 * h * k;\
    \ i++) nr[i] *= invz;\n        nr[0] -= 1;\n        q.assign(h * k, 0);\n    \
    \    for (int i = 0; i < 2 * k; i++) {\n            for (int j = 0; j <= n / 2;\
    \ j++) {\n                q[i * h / 2 + j] = nr[i * h + j];\n            }\n \
    \       }\n        auto p = self(self, q, n / 2, h / 2, k * 2);\n        FPS np(4\
    \ * h * k);\n        for (int i = 0; i < 2 * k; i++) {\n            for (int j\
    \ = 0; j <= n / 2; j++) {\n                np[i * 2 * h + j * 2 + n % 2] = p[i\
    \ * h / 2 + j];\n            }\n        }\n        np.resize(z << 1);\n      \
    \  np.but();\n        for (int i = 1; i < 4 * h * k; i <<= 1) {\n            reverse(begin(nq)\
    \ + i, begin(nq) + i * 2);\n        }\n        for (int i = 0; i < 4 * h * k;\
    \ i++) {\n            np[i] *= nq[i];\n        }\n        np.ibut();\n       \
    \ for (int i = 0; i < 4 * h * k; i++) np[i] *= invz2;\n        p.assign(h * k,\
    \ 0);\n        for (int i = 0; i < k; i++) {\n            copy(begin(np) + i *\
    \ 2 * h, begin(np) + i * 2 * h + n + 1,\n                 begin(p) + i * h);\n\
    \        }\n        return p;\n    }; \n\n    if (deg == -1) deg = max(size(f),\
    \ size(g));\n    f.resize(deg), g.resize(deg);\n    int n = int(size(f)) - 1,\
    \ k = 1;\n    int h = 1;\n    while (h < n + 1) h <<= 1;\n    FPS q(h * k);\n\
    \    for (int i = 0; i <= n; i++) q[i] = -f[i];\n    FPS p = rec(rec, q, n, h,\
    \ k);\n    return p.pre(n + 1).rev();\n}\n\n} // namespace kk2\n\n#endif /* FPS_COMPOSITION_HPP\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: fps/composition.hpp
  requiredBy: []
  timestamp: '2024-09-06 14:29:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/composition.hpp
layout: document
redirect_from:
- /library/fps/composition.hpp
- /library/fps/composition.hpp.html
title: fps/composition.hpp
---
