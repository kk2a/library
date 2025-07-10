---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':heavy_check_mark:'
    path: type_traits/integral.hpp
    title: type_traits/integral.hpp
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
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ type_traits/integral.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_MOD_BERNOULLI_NUMBER_HPP\n#define KK2_MATH_MOD_BERNOULLI_NUMBER_HPP\
    \ 1\n\n#include <vector>\n\n#include \"comb.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint> enumerate_bernoulli_number(int\
    \ n) {\n    FPS f(n + 1);\n    kk2::Comb<mint>::set_upper(n + 1);\n    for (int\
    \ i = 0; i <= n; ++i) f[i] = kk2::Comb<mint>::ifact(i + 1);\n    f = f.inv(n +\
    \ 1);\n    std::vector<mint> res(n + 1);\n    for (int i = 0; i <= n; ++i) res[i]\
    \ = f[i] * kk2::Comb<mint>::fact(i);\n    return res;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MOD_BERNOULLI_NUMBER_HPP\n"
  dependsOn:
  - math_mod/comb.hpp
  - type_traits/integral.hpp
  isVerificationFile: false
  path: math_mod/bernoulli_number.hpp
  requiredBy: []
  timestamp: '2025-04-06 00:09:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/bernoulli_number.hpp
layout: document
redirect_from:
- /library/math_mod/bernoulli_number.hpp
- /library/math_mod/bernoulli_number.hpp.html
title: math_mod/bernoulli_number.hpp
---
