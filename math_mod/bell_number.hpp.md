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
  code: "#ifndef KK2_MATH_MOD_BELL_NUMBER_HPP\n#define KK2_MATH_MOD_BELL_NUMBER_HPP\
    \ 1\n\n#include <vector>\n\n#include \"comb.hpp\"\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint> enumerate_bell_number(int\
    \ n) {\n    FPS f(n + 1);\n    f[0] = 0;\n    kk2::Comb<mint>::set_upper(n);\n\
    \    for (int i = 1; i <= n; ++i) f[i] = kk2::Comb<mint>::ifact(i);\n    f = f.exp(n\
    \ + 1);\n    std::vector<mint> res(n + 1);\n    for (int i = 0; i <= n; ++i) res[i]\
    \ = f[i] * kk2::Comb<mint>::fact(i);\n    return res;\n}\n\n} // namespace kk2\n\
    \n#endif // KK2_MATH_MOD_BELL_NUMBER_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/bell_number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/bell_number.hpp
layout: document
redirect_from:
- /library/math_mod/bell_number.hpp
- /library/math_mod/bell_number.hpp.html
title: math_mod/bell_number.hpp
---
