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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_MATH_MOD_PRIMITIVE_ROOT_HPP\n#define KK2_MATH_MOD_PRIMITIVE_ROOT_HPP\
    \ 1\n\n#include \"pow_mod.hpp\"\n\nnamespace kk2 {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {};\n   \
    \ divs[0] = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 ==\
    \ 0) x /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if\
    \ (x % i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0)\
    \ { x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
    \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt;\
    \ i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n#endif\
    \ // KK2_MATH_MOD_PRIMITIVE_ROOT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/primitive_root.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/primitive_root.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_root.hpp
- /library/math_mod/primitive_root.hpp.html
title: math_mod/primitive_root.hpp
---
