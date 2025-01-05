---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math_mod/mod_sqrt.hpp
    title: math_mod/mod_sqrt.hpp
  - icon: ':x:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':x:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - icon: ':x:'
    path: verify/yosupo_fps/fps_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sqrt.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_FPS_FPS_SQRT_HPP\n#define KK2_FPS_FPS_SQRT_HPP 1\n\n#include\
    \ <cassert>\n\n#include \"../math_mod/mod_sqrt.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> FPS sqrt(const FPS &f, int\
    \ deg = -1) {\n    // using mint = typename FPS::value_type;\n    if (deg == -1)\
    \ deg = (int)f.size();\n    if ((int)f.size() == 0) return FPS(deg, mint(0));\n\
    \    if (f[0] == mint(0)) {\n        for (int i = 1; i < (int)f.size(); i++) {\n\
    \            if (f[i] != mint(0)) {\n                if (i & 1) return {};\n \
    \               if (deg - i / 2 <= 0) break;\n                auto ret = sqrt(f\
    \ >> i, deg - i / 2);\n                if (ret.empty()) return {};\n         \
    \       ret = ret << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, mint(0));\n    }\n\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    assert(sqr * sqr % mint::getmod() == f[0].val());\n\
    \    FPS ret = {mint(sqr)};\n    mint inv2 = mint(2).inv();\n    for (int i =\
    \ 1; i < deg; i <<= 1) { ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\
    \ }\n    return ret.pre(deg);\n}\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS sparse_sqrt(const FPS &f, int deg = -1) {\n    // using\
    \ mint = typename FPS::value_type;\n    if (deg == -1) deg = (int)f.size();\n\
    \    if ((int)f.size() == 0) return FPS(deg, mint(0));\n    if (f[0] == mint(0))\
    \ {\n        for (int i = 1; i < (int)f.size(); i++) {\n            if (f[i] !=\
    \ mint(0)) {\n                if (i & 1) return {};\n                if (deg -\
    \ i / 2 <= 0) break;\n                auto ret = sparse_sqrt(f >> i, deg - i /\
    \ 2);\n                if (ret.empty()) return {};\n                ret = ret\
    \ << (i / 2);\n                if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \                return ret;\n            }\n        }\n        return FPS(deg,\
    \ mint(0));\n    }\n    long long sqr = mod_sqrt(f[0].val(), mint::getmod());\n\
    \    if (sqr == -1) return {};\n    return f.sparse_pow(((mint::getmod() + 1)\
    \ >> 1), deg) * mint(sqr).inv();\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_SQRT_HPP\n"
  dependsOn:
  - math_mod/mod_sqrt.hpp
  - modint/mont_arb.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: fps/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2025-01-06 00:03:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
documentation_of: fps/fps_sqrt.hpp
layout: document
redirect_from:
- /library/fps/fps_sqrt.hpp
- /library/fps/fps_sqrt.hpp.html
title: fps/fps_sqrt.hpp
---
