---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/monoid/affine.hpp
    title: math/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: math/monoid/update.hpp
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
  code: "#ifndef KK2_MATH_ACTION_UPDATE_AFFINE_HPP\n#define KK2_MATH_ACTION_UPDATE_AFFINE_HPP\
    \ 1\n\n#include \"../monoid/affine.hpp\"\n#include \"../monoid/update.hpp\"\n\n\
    namespace kk2 {\n\nnamespace action {\n\ntemplate <class T>\nstruct UpdateAffine\
    \ {\n    using A = monoid::Update<monoid::Affine<T>>;\n    using S = monoid::Affine<T>;\n\
    \n    inline static S act(A f, S x) { return f.is_unit ? x : S(f.a); }\n}\n\n\
    } // namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_UPDATE_AFFINE_HPP\n"
  dependsOn:
  - math/monoid/affine.hpp
  - type_traits/type_traits.hpp
  - math/monoid/update.hpp
  isVerificationFile: false
  path: math/action/update_affine.hpp
  requiredBy: []
  timestamp: '2025-03-27 00:23:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/action/update_affine.hpp
layout: document
redirect_from:
- /library/math/action/update_affine.hpp
- /library/math/action/update_affine.hpp.html
title: math/action/update_affine.hpp
---
