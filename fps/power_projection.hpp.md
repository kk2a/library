---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/fps_com_inv.hpp
    title: fps/fps_com_inv.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/power_projection.hpp\"\n\n\n\n// n = \\deg f - 1\n//\
    \ [X ^ n] f(X) ^ i g(X)  enumerate for i = 0, ... , m \ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS power_projection(FPS f, FPS g = {1}, int\
    \ m = -1) {\n    if (f.empty() || g.empty()) return {};\n    int n = int(size(f))\
    \ - 1, k = 1;\n    g.resize(n + 1);\n    if (m == -1) m = n;\n    int h = 1;\n\
    \    while (h < n + 1) h <<= 1;\n    FPS p((n + 1) * k), q((n + 1) * k),\n   \
    \     np, nq, buf, buf2;\n    for (int i = 0; i <= n; i++) p[i * k] = g[i];\n\
    \    for (int i = 0; i <= n; i++) q[i * k] = -f[i];\n    q[0] += 1;\n    mint\
    \ inv2 = mint(2).inv();\n    mint invk = mint(k).inv();\n    mint invh = mint(h).inv();\n\
    \    while (n) {\n        mint w = mint(FPS::but_pr()).\n            pow((mint::getmod()\
    \ - 1) / (k << 1));\n        mint invw = w.inv();\n\n        buf2.resize(k);\n\
    \        auto db = [&]() -> void {\n            copy(begin(buf), end(buf), begin(buf2));\n\
    \            buf2.ibut();\n            buf2 *= invk;\n            mint r = 1;\n\
    \            for (int i = 0; i < k; i++) {\n                buf2[i] *= r;\n  \
    \              r *= w;\n            }\n            buf2.but();\n            copy(begin(buf2),\
    \ end(buf2), back_inserter(buf));\n        };\n\n        np.clear(), nq.clear();\n\
    \        for (int i = 0; i <= n; i++) {\n            buf.resize(k);\n        \
    \    copy(begin(p) + i * k, begin(p) + (i + 1) * k, begin(buf));\n           \
    \ db();\n            copy(begin(buf), end(buf), back_inserter(np));\n\n      \
    \      buf.resize(k);\n            copy(begin(q) + i * k, begin(q) + (i + 1) *\
    \ k, begin(buf));\n            if (i == 0) {\n                for (int j = 0;\
    \ j < k; j++) buf[j] -= 1;\n                db();\n                for (int j\
    \ = 0; j < k; j++) buf[j] += 1;\n                for (int j = 0; j < k; j++) buf[k\
    \ + j] -= 1; \n            }\n            else db();\n\n            copy(begin(buf),\
    \ end(buf), back_inserter(nq));\n        }\n\n        np.resize(2 * h * 2 * k);\n\
    \        nq.resize(2 * h * 2 * k);\n        FPS p1(2 * h), q1(2 * h);\n\n    \
    \    w = mint(FPS::but_pr()).\n            pow((mint::getmod() - 1) / (h << 1));\n\
    \        invw = w.inv();\n        vector<int> btr;\n        if (n & 1) {\n   \
    \         btr.resize(h);\n            for (int i = 0, lg = __builtin_ctz(h); i\
    \ < h; i++) {\n                btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (lg -\
    \ 1));\n            }\n        }\n\n        for (int j = 0; j < 2 * k; j++) {\n\
    \            p1.assign(2 * h, 0);\n            q1.assign(2 * h, 0);\n        \
    \    for (int i = 0; i < h; i++) {\n                p1[i] = np[i * 2 * k + j];\n\
    \                q1[i] = nq[i * 2 * k + j];\n            }\n            p1.but();\
    \ q1.but();\n            for (int i = 0; i < 2 * h; i += 2) swap(q1[i], q1[i +\
    \ 1]);\n            p1.inplace_dot(q1);\n            for (int i = 0; i < h; i++)\
    \ q1[i] = q1[i * 2] * q1[i * 2 + 1];\n            if (n & 1) {\n             \
    \   mint c = inv2;\n                buf.resize(h);\n                for (int i\
    \ : btr) {\n                    buf[i] = (p1[i * 2] - p1[i * 2 + 1]) * c;\n  \
    \                  c *= invw;\n                }\n                swap(p1, buf);\n\
    \            }\n            else {\n                for (int i = 0; i < h; i++)\
    \ p1[i] =\n                    (p1[i * 2] + p1[i * 2 + 1]) * inv2;\n         \
    \   }\n            p1.resize(h); q1.resize(h);\n            p1.ibut(); q1.ibut();\n\
    \            p1 *= invh; q1 *= invh;\n            for (int i = 0; i < h; i++)\
    \ {\n                np[i * 2 * k + j] = p1[i];\n                nq[i * 2 * k\
    \ + j] = q1[i];\n            }\n        }\n\n        np.resize((n / 2 + 1) * 2\
    \ * k);\n        nq.resize((n / 2 + 1) * 2 * k);\n        swap(p, np); swap(q,\
    \ nq);\n        n >>= 1, h >>= 1, k <<= 1;\n        invh *= 2, invk *= inv2;\n\
    \    }\n\n    FPS s(begin(p), begin(p) + k);\n    FPS t(begin(q), begin(q) + k);\n\
    \    s.ibut(); t.ibut();\n    s *= invk; t *= invk;\n    t[0] -= 1;\n    if (f[0]\
    \ == mint(0)) return s.rev().pre(m + 1);\n    return (s.rev() * (t + (FPS{1} <<\
    \ k)).\n           rev().inv(m + 1)).pre(m + 1);\n}\n\n\n"
  code: "#ifndef POWER_PROJECTION_HPP\n#define POWER_PROJECTION_HPP 1\n\n// n = \\\
    deg f - 1\n// [X ^ n] f(X) ^ i g(X)  enumerate for i = 0, ... , m \ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nFPS power_projection(FPS f, FPS\
    \ g = {1}, int m = -1) {\n    if (f.empty() || g.empty()) return {};\n    int\
    \ n = int(size(f)) - 1, k = 1;\n    g.resize(n + 1);\n    if (m == -1) m = n;\n\
    \    int h = 1;\n    while (h < n + 1) h <<= 1;\n    FPS p((n + 1) * k), q((n\
    \ + 1) * k),\n        np, nq, buf, buf2;\n    for (int i = 0; i <= n; i++) p[i\
    \ * k] = g[i];\n    for (int i = 0; i <= n; i++) q[i * k] = -f[i];\n    q[0] +=\
    \ 1;\n    mint inv2 = mint(2).inv();\n    mint invk = mint(k).inv();\n    mint\
    \ invh = mint(h).inv();\n    while (n) {\n        mint w = mint(FPS::but_pr()).\n\
    \            pow((mint::getmod() - 1) / (k << 1));\n        mint invw = w.inv();\n\
    \n        buf2.resize(k);\n        auto db = [&]() -> void {\n            copy(begin(buf),\
    \ end(buf), begin(buf2));\n            buf2.ibut();\n            buf2 *= invk;\n\
    \            mint r = 1;\n            for (int i = 0; i < k; i++) {\n        \
    \        buf2[i] *= r;\n                r *= w;\n            }\n            buf2.but();\n\
    \            copy(begin(buf2), end(buf2), back_inserter(buf));\n        };\n\n\
    \        np.clear(), nq.clear();\n        for (int i = 0; i <= n; i++) {\n   \
    \         buf.resize(k);\n            copy(begin(p) + i * k, begin(p) + (i + 1)\
    \ * k, begin(buf));\n            db();\n            copy(begin(buf), end(buf),\
    \ back_inserter(np));\n\n            buf.resize(k);\n            copy(begin(q)\
    \ + i * k, begin(q) + (i + 1) * k, begin(buf));\n            if (i == 0) {\n \
    \               for (int j = 0; j < k; j++) buf[j] -= 1;\n                db();\n\
    \                for (int j = 0; j < k; j++) buf[j] += 1;\n                for\
    \ (int j = 0; j < k; j++) buf[k + j] -= 1; \n            }\n            else db();\n\
    \n            copy(begin(buf), end(buf), back_inserter(nq));\n        }\n\n  \
    \      np.resize(2 * h * 2 * k);\n        nq.resize(2 * h * 2 * k);\n        FPS\
    \ p1(2 * h), q1(2 * h);\n\n        w = mint(FPS::but_pr()).\n            pow((mint::getmod()\
    \ - 1) / (h << 1));\n        invw = w.inv();\n        vector<int> btr;\n     \
    \   if (n & 1) {\n            btr.resize(h);\n            for (int i = 0, lg =\
    \ __builtin_ctz(h); i < h; i++) {\n                btr[i] = (btr[i >> 1] >> 1)\
    \ + ((i & 1) << (lg - 1));\n            }\n        }\n\n        for (int j = 0;\
    \ j < 2 * k; j++) {\n            p1.assign(2 * h, 0);\n            q1.assign(2\
    \ * h, 0);\n            for (int i = 0; i < h; i++) {\n                p1[i] =\
    \ np[i * 2 * k + j];\n                q1[i] = nq[i * 2 * k + j];\n           \
    \ }\n            p1.but(); q1.but();\n            for (int i = 0; i < 2 * h; i\
    \ += 2) swap(q1[i], q1[i + 1]);\n            p1.inplace_dot(q1);\n           \
    \ for (int i = 0; i < h; i++) q1[i] = q1[i * 2] * q1[i * 2 + 1];\n           \
    \ if (n & 1) {\n                mint c = inv2;\n                buf.resize(h);\n\
    \                for (int i : btr) {\n                    buf[i] = (p1[i * 2]\
    \ - p1[i * 2 + 1]) * c;\n                    c *= invw;\n                }\n \
    \               swap(p1, buf);\n            }\n            else {\n          \
    \      for (int i = 0; i < h; i++) p1[i] =\n                    (p1[i * 2] + p1[i\
    \ * 2 + 1]) * inv2;\n            }\n            p1.resize(h); q1.resize(h);\n\
    \            p1.ibut(); q1.ibut();\n            p1 *= invh; q1 *= invh;\n    \
    \        for (int i = 0; i < h; i++) {\n                np[i * 2 * k + j] = p1[i];\n\
    \                nq[i * 2 * k + j] = q1[i];\n            }\n        }\n\n    \
    \    np.resize((n / 2 + 1) * 2 * k);\n        nq.resize((n / 2 + 1) * 2 * k);\n\
    \        swap(p, np); swap(q, nq);\n        n >>= 1, h >>= 1, k <<= 1;\n     \
    \   invh *= 2, invk *= inv2;\n    }\n\n    FPS s(begin(p), begin(p) + k);\n  \
    \  FPS t(begin(q), begin(q) + k);\n    s.ibut(); t.ibut();\n    s *= invk; t *=\
    \ invk;\n    t[0] -= 1;\n    if (f[0] == mint(0)) return s.rev().pre(m + 1);\n\
    \    return (s.rev() * (t + (FPS{1} << k)).\n           rev().inv(m + 1)).pre(m\
    \ + 1);\n}\n\n#endif // POWER_PROJECTION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/power_projection.hpp
  requiredBy:
  - fps/fps_com_inv.hpp
  timestamp: '2024-05-23 16:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/power_projection.hpp
layout: document
redirect_from:
- /library/fps/power_projection.hpp
- /library/fps/power_projection.hpp.html
title: fps/power_projection.hpp
---
