---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/group/add.hpp
    title: math/group/add.hpp
  - icon: ':x:'
    path: math/group/sum_with_size.hpp
    title: math/group/sum_with_size.hpp
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
  code: "#ifndef KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP\n#define KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP\
    \ 1\n\n#include \"../group/add.hpp\"\n#include \"../group/sum_with_size.hpp\"\n\
    \nnamespace kk2 {\n\nnamespace action {\n\ntemplate <class T, class U> struct\
    \ AddSumWithSize {\n    using A = group::Add<T>;\n    using S = group::SumWithSize<T,\
    \ U>;\n\n    inline static S act(A f, S x) { return S(x.a + f.a * x.size, x.size);\
    \ }\n};\n\n} // namespace action\n\n} // namespace kk2\n\n#endif // KK2_MATH_ACTION_ADD_SUMWITHSIZE_HPP\n"
  dependsOn:
  - math/group/add.hpp
  - type_traits/io.hpp
  - math/group/sum_with_size.hpp
  isVerificationFile: false
  path: math/action/add_sumwithsize.hpp
  requiredBy: []
  timestamp: '2025-04-06 13:01:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/action/add_sumwithsize.hpp
layout: document
redirect_from:
- /library/math/action/add_sumwithsize.hpp
- /library/math/action/add_sumwithsize.hpp.html
title: math/action/add_sumwithsize.hpp
---
