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
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type_traits/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n#define KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\
    \ 1\n\n#include \"../math/prime_factorize.hpp\"\n#include \"../random/gen.hpp\"\
    \n#include \"pow_mod.hpp\"\n\nnamespace kk2 {\n\nlong long primitive_root_64bit(long\
    \ long p) {\n    if (p == 2) return 1;\n    if (p == 3) return 2;\n\n    auto\
    \ f = factorize(p - 1);\n    while (true) {\n        long long g = random::rng(2,\
    \ p - 1);\n        bool ok = true;\n        for (auto &&[q, e] : f) {\n      \
    \      if (pow_mod<__int128_t>(g, (p - 1) / q, p) == 1) {\n                ok\
    \ = false;\n                break;\n            }\n        }\n        if (ok)\
    \ return g;\n    }\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_PRIMITIVE_ROOT_64BIT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math_mod/primitive_root_64bit.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math_mod/primitive_root_64bit.hpp
layout: document
redirect_from:
- /library/math_mod/primitive_root_64bit.hpp
- /library/math_mod/primitive_root_64bit.hpp.html
title: math_mod/primitive_root_64bit.hpp
---
