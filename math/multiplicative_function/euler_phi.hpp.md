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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"../../type_traits/type_traits.hpp\"\n\
    #include \"../prime_factorize.hpp\"\n\nnamespace kk2 {\n\ntemplate <class T, is_integral_t<T>\
    \ * = nullptr> T euler_phi(T n) {\n    assert(n > 0);\n    for (auto [p, k] :\
    \ factorize(static_cast<long long>(n))) n -= n / p;\n    return n;\n}\n\n} //\
    \ namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_EULER_PHI_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/multiplicative_function/euler_phi.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/multiplicative_function/euler_phi.hpp
layout: document
redirect_from:
- /library/math/multiplicative_function/euler_phi.hpp
- /library/math/multiplicative_function/euler_phi.hpp.html
title: math/multiplicative_function/euler_phi.hpp
---
