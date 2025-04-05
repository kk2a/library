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
  code: "#ifndef KK2_FPS_POLY_TAYLOR_SHIFT_HPP\n#define KK2_FPS_POLY_TAYLOR_SHIFT_HPP\
    \ 1\n\n#include <algorithm>\n\n#include \"../math_mod/comb.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS taylor_shift(const\
    \ FPS &f_, mint a) {\n    FPS f(f_);\n    int n = f.size();\n    Comb<mint>::set_upper(n);\n\
    \    for (int i = 0; i < n; i++) f[i] *= Comb<mint>::fact(i);\n    f.inplace_rev();\n\
    \    FPS g(n, mint(1));\n    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a *\
    \ Comb<mint>::inv(i);\n    f = (f * g).pre(n).rev();\n    for (int i = 0; i <\
    \ n; i++) f[i] *= Comb<mint>::ifact(i);\n    return f;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_FPS_POLY_TAYLOR_SHIFT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/poly_taylor_shift.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/poly_taylor_shift.hpp
layout: document
redirect_from:
- /library/fps/poly_taylor_shift.hpp
- /library/fps/poly_taylor_shift.hpp.html
title: fps/poly_taylor_shift.hpp
---
