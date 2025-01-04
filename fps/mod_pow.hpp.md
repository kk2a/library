---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/find_root.hpp
    title: fps/find_root.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"fps/mod_pow.hpp\"\n\n\n\n#include <cassert>\n#include <functional>\n\
    \nnamespace kk2 {\n\n// return f ^ k mod g\ntemplate <class FPS, class mint =\
    \ typename FPS::value_type, class T>\nFPS mod_pow(T k, const FPS &f, const FPS\
    \ &g) {\n    // assert(!is_signed_v<T> || k >= 0);\n    assert(!g.empty());\n\n\
    \    auto inv = g.rev().inv();\n    auto quo = [&](const FPS &poly) {\n      \
    \  if (poly.size() < g.size()) return FPS{};\n        int n = poly.size() - g.size()\
    \ + 1;\n        return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n    };\n\
    \    FPS res{1}, b(f);\n    while (k) {\n        if (k & 1) {\n            res\
    \ *= b;\n            res -= quo(res) * g;\n            res.shrink();\n       \
    \ }\n        b *= b;\n        b -= quo(b) * g;\n        b.shrink();\n        k\
    \ >>= 1;\n    }\n    return res;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_FPS_MOD_POW_HPP\n#define KK2_FPS_MOD_POW_HPP 1\n\n#include <cassert>\n\
    #include <functional>\n\nnamespace kk2 {\n\n// return f ^ k mod g\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type, class T>\nFPS mod_pow(T k, const\
    \ FPS &f, const FPS &g) {\n    // assert(!is_signed_v<T> || k >= 0);\n    assert(!g.empty());\n\
    \n    auto inv = g.rev().inv();\n    auto quo = [&](const FPS &poly) {\n     \
    \   if (poly.size() < g.size()) return FPS{};\n        int n = poly.size() - g.size()\
    \ + 1;\n        return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n    };\n\
    \    FPS res{1}, b(f);\n    while (k) {\n        if (k & 1) {\n            res\
    \ *= b;\n            res -= quo(res) * g;\n            res.shrink();\n       \
    \ }\n        b *= b;\n        b -= quo(b) * g;\n        b.shrink();\n        k\
    \ >>= 1;\n    }\n    return res;\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_MOD_POW_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/mod_pow.hpp
  requiredBy:
  - fps/find_root.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/mod_pow.hpp
layout: document
redirect_from:
- /library/fps/mod_pow.hpp
- /library/fps/mod_pow.hpp.html
title: fps/mod_pow.hpp
---
