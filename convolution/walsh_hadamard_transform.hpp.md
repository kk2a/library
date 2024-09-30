---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convolution/bitxor1.hpp
    title: convolution/bitxor1.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/walsh_hadamard_transform.hpp\"\n\n\n\n#include\
    \ <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void WalshHadamardTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class FPS> void InverseWalshHadamardTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n  \
    \          }\n        }\n    }\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n#define CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\
    \ 1\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void WalshHadamardTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class FPS> void InverseWalshHadamardTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n  \
    \          }\n        }\n    }\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/walsh_hadamard_transform.hpp
  requiredBy:
  - convolution/bitxor1.hpp
  timestamp: '2024-10-01 04:14:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/walsh_hadamard_transform.hpp
layout: document
redirect_from:
- /library/convolution/walsh_hadamard_transform.hpp
- /library/convolution/walsh_hadamard_transform.hpp.html
title: convolution/walsh_hadamard_transform.hpp
---
