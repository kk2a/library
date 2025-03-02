---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_math/enumerate_bell_number.test.cpp
    title: verify/yosupo_math/enumerate_bell_number.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MOD_BELL_NUMBER_HPP\n#define KK2_MATH_MOD_BELL_NUMBER_HPP\
    \ 1\n\n#include <vector>\n\n#include \"comb.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint> enumerate_bell_number(int\
    \ n) {\n    FPS f(n + 1);\n    f[0] = 0;\n    kk2::Comb<mint>::set_upper(n);\n\
    \    for (int i = 1; i <= n; ++i) f[i] = kk2::Comb<mint>::ifact(i);\n    f = f.exp(n\
    \ + 1);\n    std::vector<mint> res(n + 1);\n    for (int i = 0; i <= n; ++i) res[i]\
    \ = f[i] * kk2::Comb<mint>::fact(i);\n    return res;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MOD_BELL_NUMBER_HPP\n"
  dependsOn:
  - math_mod/comb.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: math_mod/bell_number.hpp
  requiredBy: []
  timestamp: '2025-02-08 14:55:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_math/enumerate_bell_number.test.cpp
documentation_of: math_mod/bell_number.hpp
layout: document
redirect_from:
- /library/math_mod/bell_number.hpp
- /library/math_mod/bell_number.hpp.html
title: math_mod/bell_number.hpp
---
