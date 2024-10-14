---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    title: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"functional/rev.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class R, class T1, class T2, R (*f)(T1, T2)> R rev(T2 x, T1 y) {\n    return\
    \ f(y, x);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FUNCTIONAL_REV_HPP\n#define FUNCTIONAL_REV_HPP 1\n\nnamespace kk2\
    \ {\n\ntemplate <class R, class T1, class T2, R (*f)(T1, T2)> R rev(T2 x, T1 y)\
    \ {\n    return f(y, x);\n}\n\n} // namespace kk2\n\n#endif // FUNCTIONAL_REV_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: functional/rev.hpp
  requiredBy: []
  timestamp: '2024-10-14 15:56:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
documentation_of: functional/rev.hpp
layout: document
redirect_from:
- /library/functional/rev.hpp
- /library/functional/rev.hpp.html
title: functional/rev.hpp
---
