---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/zeta_mobius_transfrom.hpp
    title: convolution/zeta_mobius_transfrom.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_and.test.cpp
    title: verify/yosupo_convolution/convolution_and.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/convolution_and.hpp\"\n\n\n\n#include <cassert>\n\
    \n#line 1 \"convolution/zeta_mobius_transfrom.hpp\"\n\n\n\n#line 5 \"convolution/zeta_mobius_transfrom.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS> void superset_zeta_transform(FPS &a)\
    \ {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n    }\n}\n\ntemplate\
    \ <class FPS> void inverse_superset_zeta_transform(FPS &a) {\n    int n = int(a.size());\n\
    \    if (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i\
    \ <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) ==\
    \ 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\ntemplate <class FPS> void subset_zeta_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) a[j] += a[i ^ j];\n        }\n    }\n\
    }\n\ntemplate <class FPS> void inverse_subset_zeta_transform(FPS &a) {\n    int\
    \ n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for\
    \ (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n     \
    \       if ((i & j) != 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"convolution/convolution_and.hpp\"\n\nnamespace kk2 {\n\n\
    template <class FPS> FPS convolution_and(FPS &a, const FPS &b) {\n    assert(size(a)\
    \ == size(b));\n    int n = int(size(a)); // == int(size(b)\n    if (!n) return\
    \ {};\n    assert((n & -n) == n);\n    FPS c(b.begin(), b.end());\n\n    superset_zeta_transform(a);\n\
    \    superset_zeta_transform(c);\n    for (int i = 0; i < n; i++) a[i] *= c[i];\n\
    \    inverse_superset_zeta_transform(a);\n\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_AND_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_AND_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"zeta_mobius_transfrom.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS> FPS convolution_and(FPS &a, const FPS &b) {\n\
    \    assert(size(a) == size(b));\n    int n = int(size(a)); // == int(size(b)\n\
    \    if (!n) return {};\n    assert((n & -n) == n);\n    FPS c(b.begin(), b.end());\n\
    \n    superset_zeta_transform(a);\n    superset_zeta_transform(c);\n    for (int\
    \ i = 0; i < n; i++) a[i] *= c[i];\n    inverse_superset_zeta_transform(a);\n\n\
    \    return a;\n}\n\n} // namespace kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_AND_HPP\n"
  dependsOn:
  - convolution/zeta_mobius_transfrom.hpp
  isVerificationFile: false
  path: convolution/convolution_and.hpp
  requiredBy: []
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_and.test.cpp
documentation_of: convolution/convolution_and.hpp
layout: document
redirect_from:
- /library/convolution/convolution_and.hpp
- /library/convolution/convolution_and.hpp.html
title: convolution/convolution_and.hpp
---
