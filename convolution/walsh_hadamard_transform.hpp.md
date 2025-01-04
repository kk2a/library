---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/convolution_xor.hpp
    title: convolution/convolution_xor.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_xor.test.cpp
    title: verify/yosupo_convolution/convolution_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/walsh_hadamard_transform.hpp\"\n\n\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class FPS> void inverse_walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n  \
    \          }\n        }\n    }\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n#define KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\
    \ 1\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class FPS> void inverse_walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n  \
    \          }\n        }\n    }\n}\n\n} // namespace kk2\n\n#endif // KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/walsh_hadamard_transform.hpp
  requiredBy:
  - convolution/convolution_xor.hpp
  timestamp: '2025-01-05 04:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_xor.test.cpp
documentation_of: convolution/walsh_hadamard_transform.hpp
layout: document
redirect_from:
- /library/convolution/walsh_hadamard_transform.hpp
- /library/convolution/walsh_hadamard_transform.hpp.html
title: convolution/walsh_hadamard_transform.hpp
---
