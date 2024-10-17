---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/bitand1.hpp
    title: convolution/bitand1.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/bitor1.hpp
    title: convolution/bitor1.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_and.test.cpp
    title: verify/yosupo_convolution/convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_or.test.cpp
    title: verify/yosupo_convolution/convolution_or.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/zeta_mobius_transfrom.hpp\"\n\n\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void SuperSetZetaTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n    }\n\
    }\n\ntemplate <class FPS> void InverseSuperSetZetaTransform(FPS &a) {\n    int\
    \ n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for\
    \ (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n     \
    \       if ((i & j) == 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\ntemplate <class\
    \ FPS> void SubsetZetaTransform(FPS &a) {\n    int n = int(a.size());\n    if\
    \ (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1)\
    \ {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) != 0) a[j]\
    \ += a[i ^ j];\n        }\n    }\n}\n\ntemplate <class FPS> void InverseSubsetZetaTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) a[j] -= a[i ^ j];\n        }\n    }\n\
    }\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\n#define CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\
    \ 1\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void SuperSetZetaTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n    }\n\
    }\n\ntemplate <class FPS> void InverseSuperSetZetaTransform(FPS &a) {\n    int\
    \ n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for\
    \ (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n     \
    \       if ((i & j) == 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\ntemplate <class\
    \ FPS> void SubsetZetaTransform(FPS &a) {\n    int n = int(a.size());\n    if\
    \ (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<= 1)\
    \ {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) != 0) a[j]\
    \ += a[i ^ j];\n        }\n    }\n}\n\ntemplate <class FPS> void InverseSubsetZetaTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) a[j] -= a[i ^ j];\n        }\n    }\n\
    }\n\n} // namespace kk2\n\n#endif // CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/zeta_mobius_transfrom.hpp
  requiredBy:
  - convolution/bitor1.hpp
  - convolution/bitand1.hpp
  timestamp: '2024-10-01 04:14:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_and.test.cpp
  - verify/yosupo_convolution/convolution_or.test.cpp
documentation_of: convolution/zeta_mobius_transfrom.hpp
layout: document
redirect_from:
- /library/convolution/zeta_mobius_transfrom.hpp
- /library/convolution/zeta_mobius_transfrom.hpp.html
title: convolution/zeta_mobius_transfrom.hpp
---