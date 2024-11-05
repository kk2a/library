---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math_mod/comb.hpp
    title: math_mod/comb.hpp
  - icon: ':question:'
    path: type_traits/type_traits.hpp
    title: type_traits/type_traits.hpp
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
    \ type_traits/type_traits.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef FPS_TAYLOR_SHIFT_HPP\n#define FPS_TAYLOR_SHIFT_HPP 1\n\n#include\
    \ <algorithm>\n\n#include \"../math_mod/comb.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type> FPS TaylorShift(const FPS\
    \ &f_, mint a) {\n    FPS f(f_);\n    int n = f.size();\n    for (int i = 0; i\
    \ < n; i++) f[i] *= Comb<mint>::fact(i);\n    std::reverse(std::begin(f), std::end(f));\n\
    \    FPS g(n, mint(1));\n    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a *\
    \ Comb<mint>::inv(i);\n    f = (f * g).pre(n).rev();\n    for (int i = 0; i <\
    \ n; i++) f[i] *= Comb<mint>::ifact(i);\n    return f;\n}\n\n} // namespace kk2\n\
    \n#endif // FPS_TAYLOR_SHIFT_HPP\n"
  dependsOn:
  - math_mod/comb.hpp
  - type_traits/type_traits.hpp
  isVerificationFile: false
  path: fps/taylor_shift.hpp
  requiredBy: []
  timestamp: '2024-10-22 22:13:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/taylor_shift.hpp
layout: document
redirect_from:
- /library/fps/taylor_shift.hpp
- /library/fps/taylor_shift.hpp.html
title: fps/taylor_shift.hpp
---
