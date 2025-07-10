---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/max.hpp
    title: math/monoid/max.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':heavy_check_mark:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/math/action/action.test.cpp
    title: verify/unit_test/math/action/action.test.cpp
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_ACTION_UPDATE_MAX_HPP\n#define KK2_MATH_ACTION_UPDATE_MAX_HPP\
    \ 1\n\n#include \"../monoid/max.hpp\"\n#include \"../monoid/update.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace action {\n\ntemplate <class T, class Compare = std::less<T>>\
    \ struct UpdateMax {\n    using S = monoid::Max<T, Compare>;\n    using A = monoid::Update<S>;\n\
    \n    inline static S act(A f, S x) { return f.is_unit ? x : f.a; }\n};\n\n} //\
    \ namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_UPDATE_MAX_HPP\n"
  dependsOn:
  - math/monoid/max.hpp
  - type_traits/io.hpp
  - math/monoid/update.hpp
  isVerificationFile: false
  path: math/action/update_max.hpp
  requiredBy: []
  timestamp: '2025-06-06 17:40:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/action/action.test.cpp
documentation_of: math/action/update_max.hpp
layout: document
redirect_from:
- /library/math/action/update_max.hpp
- /library/math/action/update_max.hpp.html
title: math/action/update_max.hpp
---
