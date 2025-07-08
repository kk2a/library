---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/monoid/min.hpp
    title: math/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: math/monoid/update.hpp
    title: "\u5E38\u306B\u5DE6\u5074\u3092\u4FDD\u6301\u3059\u308B\u30E2\u30CE\u30A4\
      \u30C9"
  - icon: ':question:'
    path: type_traits/io.hpp
    title: type_traits/io.hpp
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
    \ type_traits/io.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#ifndef KK2_MATH_ACTION_UPDATE_MIN_HPP\n#define KK2_MATH_ACTION_UPDATE_MIN_HPP\
    \ 1\n\n#include \"../monoid/min.hpp\"\n#include \"../monoid/update.hpp\"\n\nnamespace\
    \ kk2 {\n\nnamespace action {\n\ntemplate <class T, class Compare = std::less<T>>\
    \ struct UpdateMin {\n    using S = monoid::Min<T, Compare>;\n    using A = monoid::Update<S>;\n\
    \n    inline static S act(A f, S x) { return f.is_unit ? x : f.a; }\n};\n\n} //\
    \ namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_UPDATE_MIN_HPP\n"
  dependsOn:
  - math/monoid/min.hpp
  - type_traits/io.hpp
  - math/monoid/update.hpp
  isVerificationFile: false
  path: math/action/update_min.hpp
  requiredBy: []
  timestamp: '2025-06-06 17:40:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/action/update_min.hpp
layout: document
redirect_from:
- /library/math/action/update_min.hpp
- /library/math/action/update_min.hpp.html
title: math/action/update_min.hpp
---
