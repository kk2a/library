---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/power_projection.hpp
    title: fps/power_projection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_composition_inv.test.cpp
    title: verify/yosupo_fps/fps_composition_inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/compositional_inv.hpp\"\n\n\n\n#include <cassert>\n\n\
    #line 1 \"fps/power_projection.hpp\"\n\n\n\n#include <algorithm>\n#include <functional>\n\
    #include <vector>\n\nnamespace kk2 {\n\n// n = \\deg f\n// [X ^ n] f(X) ^ i g(X)\
    \  enumerate for i = 0, ... , m\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    FPS power_projection(const FPS &f, const FPS &g = {1}, int m = -1) {\n    if (f.empty()\
    \ || g.empty()) return {};\n    int n = int(size(f)) - 1, k = 1;\n    if (m ==\
    \ -1) m = n;\n    int h = 1;\n    while (h < n + 1) h <<= 1;\n    FPS p((n + 1)\
    \ * k), q((n + 1) * k), np, nq, buf, buf2;\n    for (int i = 0; i <= n; i++) p[i\
    \ * k] = i < (int)g.size() ? g[i] : mint(0);\n    for (int i = 0; i <= n; i++)\
    \ q[i * k] = -f[i];\n    q[0] += 1;\n    mint inv2 = mint::getmod() / 2 + 1;\n\
    \    while (n) {\n        mint w = mint(FPS::but_pr()).pow((mint::getmod() - 1)\
    \ / (k << 1));\n        mint invw = w.inv();\n\n        buf2.resize(k);\n    \
    \    auto db = [&]() -> void {\n            std::copy(std::begin(buf), std::end(buf),\
    \ std::begin(buf2));\n            buf2.ibut();\n            mint r = 1;\n    \
    \        for (int i = 0; i < k; i++) {\n                buf2[i] *= r;\n      \
    \          r *= w;\n            }\n            buf2.but();\n            std::copy(std::begin(buf2),\
    \ std::end(buf2), std::back_inserter(buf));\n        };\n\n        np.clear(),\
    \ nq.clear();\n        for (int i = 0; i <= n; i++) {\n            buf.resize(k);\n\
    \            std::copy(std::begin(p) + i * k, std::begin(p) + (i + 1) * k, std::begin(buf));\n\
    \            db();\n            std::copy(std::begin(buf), std::end(buf), std::back_inserter(np));\n\
    \n            buf.resize(k);\n            std::copy(std::begin(q) + i * k, std::begin(q)\
    \ + (i + 1) * k, std::begin(buf));\n            if (i == 0) {\n              \
    \  for (int j = 0; j < k; j++) buf[j] -= 1;\n                db();\n         \
    \       for (int j = 0; j < k; j++) buf[j] += 1;\n                for (int j =\
    \ 0; j < k; j++) buf[k + j] -= 1;\n            } else db();\n\n            std::copy(std::begin(buf),\
    \ std::end(buf), std::back_inserter(nq));\n        }\n\n        np.resize(2 *\
    \ h * 2 * k);\n        nq.resize(2 * h * 2 * k);\n        FPS p1(2 * h), q1(2\
    \ * h);\n\n        w = mint(FPS::but_pr()).pow((mint::getmod() - 1) / (h << 1));\n\
    \        invw = w.inv();\n        std::vector<int> btr;\n        if (n & 1) {\n\
    \            btr.resize(h);\n            for (int i = 0, lg = __builtin_ctz(h);\
    \ i < h; i++) {\n                btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg\
    \ - 1));\n            }\n        }\n\n        for (int j = 0; j < 2 * k; j++)\
    \ {\n            p1.assign(2 * h, 0);\n            q1.assign(2 * h, 0);\n    \
    \        for (int i = 0; i < h; i++) {\n                p1[i] = np[i * 2 * k +\
    \ j];\n                q1[i] = nq[i * 2 * k + j];\n            }\n           \
    \ p1.but();\n            q1.but();\n            for (int i = 0; i < 2 * h; i +=\
    \ 2) std::swap(q1[i], q1[i + 1]);\n            p1.inplace_dot(q1);\n         \
    \   for (int i = 0; i < h; i++) q1[i] = q1[i * 2] * q1[i * 2 + 1];\n         \
    \   if (n & 1) {\n                mint c = inv2;\n                buf.resize(h);\n\
    \                for (int i : btr) {\n                    buf[i] = (p1[i * 2]\
    \ - p1[i * 2 + 1]) * c;\n                    c *= invw;\n                }\n \
    \               std::swap(p1, buf);\n            } else {\n                for\
    \ (int i = 0; i < h; i++) p1[i] = (p1[i * 2] + p1[i * 2 + 1]) * inv2;\n      \
    \      }\n            p1.resize(h);\n            q1.resize(h);\n            p1.ibut();\n\
    \            q1.ibut();\n            for (int i = 0; i < h; i++) {\n         \
    \       np[i * 2 * k + j] = p1[i];\n                nq[i * 2 * k + j] = q1[i];\n\
    \            }\n        }\n\n        np.resize((n / 2 + 1) * 2 * k);\n       \
    \ nq.resize((n / 2 + 1) * 2 * k);\n        std::swap(p, np);\n        std::swap(q,\
    \ nq);\n        n >>= 1, h >>= 1, k <<= 1;\n    }\n\n    FPS s(std::begin(p),\
    \ std::begin(p) + k);\n    FPS t(std::begin(q), std::begin(q) + k);\n    s.ibut();\n\
    \    t.ibut();\n    t[0] -= 1;\n    if (f[0] == mint(0)) return s.rev().pre(m\
    \ + 1);\n    return (s.rev() * (t + (FPS{1} << k)).rev().inv(m + 1)).pre(m + 1);\n\
    }\n\n} // namespace kk2\n\n\n#line 7 \"fps/compositional_inv.hpp\"\n\nnamespace\
    \ kk2 {\n\n// calculate f ^ {-1} (X)  mod X ^ deg\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS compositional_inv(const FPS &f, int deg\
    \ = -1) {\n    assert(size(f) >= 2 and f[1] != mint(0));\n    if (deg == -1) deg\
    \ = int(size(f));\n    if (deg < 2) return FPS{0, f[1].inv()}.pre(deg);\n    int\
    \ n = deg - 1;\n    FPS h = power_projection(f) * n;\n\n    for (int k = 1; k\
    \ <= n; k++) h[k] /= k;\n    h.inplace_rev();\n    h *= h[0].inv();\n    FPS g\
    \ = (h.log() * mint(-n).inv()).exp();\n    g *= f[1].inv();\n    return (g <<\
    \ 1).pre(deg);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_COMPOSITIONAL_INV_HPP\n#define KK2_FPS_COMPOSITIONAL_INV_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"power_projection.hpp\"\n\nnamespace kk2\
    \ {\n\n// calculate f ^ {-1} (X)  mod X ^ deg\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nFPS compositional_inv(const FPS &f, int deg = -1)\
    \ {\n    assert(size(f) >= 2 and f[1] != mint(0));\n    if (deg == -1) deg = int(size(f));\n\
    \    if (deg < 2) return FPS{0, f[1].inv()}.pre(deg);\n    int n = deg - 1;\n\
    \    FPS h = power_projection(f) * n;\n\n    for (int k = 1; k <= n; k++) h[k]\
    \ /= k;\n    h.inplace_rev();\n    h *= h[0].inv();\n    FPS g = (h.log() * mint(-n).inv()).exp();\n\
    \    g *= f[1].inv();\n    return (g << 1).pre(deg);\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_FPS_COMPOSITIONAL_INV_HPP\n"
  dependsOn:
  - fps/power_projection.hpp
  isVerificationFile: false
  path: fps/compositional_inv.hpp
  requiredBy: []
  timestamp: '2025-07-08 15:03:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_composition_inv.test.cpp
documentation_of: fps/compositional_inv.hpp
layout: document
redirect_from:
- /library/fps/compositional_inv.hpp
- /library/fps/compositional_inv.hpp.html
title: fps/compositional_inv.hpp
---
