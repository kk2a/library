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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_MATH_MOD_POW_MOD_HPP\n#define KK2_MATH_MOD_POW_MOD_HPP 1\n\n\
    #include <cassert>\n\n#include \"../type_traits/type_traits.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T x, U n,\
    \ T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m = m, r =\
    \ 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n        if\
    \ (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n \
    \   return r;\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_POW_MOD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/pow_mod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/pow_mod.hpp
layout: document
redirect_from:
- /library/math_mod/pow_mod.hpp
- /library/math_mod/pow_mod.hpp.html
title: math_mod/pow_mod.hpp
---
