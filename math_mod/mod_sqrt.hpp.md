---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/mont_arb.hpp
    title: modint/mont_arb.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps_sqrt.hpp
    title: fps/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_fps/fps_sqrt.test.cpp
    title: verify/yosupo_fps/fps_sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/sqrt_mod.test.cpp
    title: verify/yosupo_math/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef MOD_SQRT_HPP\n#define MOD_SQRT_HPP 1\n\n#include <cassert>\n\n#include\
    \ \"../modint/mont_arb.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T, class U>\
    \ long long mod_sqrt(const T &a, const U &p) {\n    assert(0 <= a && a < p);\n\
    \    if (a < 2) return a;\n    using Mint = ArbitraryLazyMontgomeryModInt<54105064>;\n\
    \    Mint::setmod(p);\n    if (Mint(a).pow((p - 1) >> 1) != Mint(1)) return -1;\n\
    \    Mint b = 1;\n    while (b.pow((p - 1) >> 1) == Mint(1)) b += 1;\n    long\
    \ long m = p - 1, e = 0;\n    while (m % 2 == 0) m >>= 1, e++;\n    Mint x = Mint(a).pow((m\
    \ - 1) >> 1);\n    Mint y = Mint(a) * x * x;\n    x *= a;\n    Mint z = Mint(b).pow(m);\n\
    \    while (y != Mint(1)) {\n        long long j = 0;\n        Mint t = y;\n \
    \       while (t != Mint(1)) {\n            j++;\n            t *= t;\n      \
    \  }\n        z = z.pow(1LL << (e - j - 1));\n        x *= z;\n        z *= z;\n\
    \        y *= z;\n        e = j;\n    }\n    return x.val();\n}\n\n} // namespace\
    \ kk2\n\n#endif // MOD_SQRT_HPP\n"
  dependsOn:
  - modint/mont_arb.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math_mod/mod_sqrt.hpp
  requiredBy:
  - fps/fps_sqrt.hpp
  timestamp: '2024-12-28 13:04:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/sqrt_mod.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
documentation_of: math_mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/math_mod/mod_sqrt.hpp
- /library/math_mod/mod_sqrt.hpp.html
title: math_mod/mod_sqrt.hpp
---
