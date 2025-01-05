---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/walsh_hadamard_transform.hpp
    title: convolution/walsh_hadamard_transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_convolution/convolution_xor.test.cpp
    title: verify/yosupo_convolution/convolution_xor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/convolution_xor.hpp\"\n\n\n\n#include <cassert>\n\
    \n#line 1 \"convolution/walsh_hadamard_transform.hpp\"\n\n\n\n#line 5 \"convolution/walsh_hadamard_transform.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS> void walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <class FPS> void inverse_walsh_hadamard_transform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) {\n                auto x = a[j], y =\
    \ a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n  \
    \          }\n        }\n    }\n}\n\n} // namespace kk2\n\n\n#line 7 \"convolution/convolution_xor.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS> FPS convolution_xor(FPS &a, const\
    \ FPS &b) {\n    assert(size(a) == size(b));\n    int n = int(size(a)); // ==\
    \ int(size(b)\n    if (!n) return {};\n    assert((n & -n) == n);\n    FPS c(b.begin(),\
    \ b.end());\n\n    walsh_hadamard_transform(a);\n    walsh_hadamard_transform(c);\n\
    \    for (int i = 0; i < n; i++) a[i] *= c[i];\n    inverse_walsh_hadamard_transform(a);\n\
    \n    return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_XOR_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_XOR_HPP\
    \ 1\n\n#include <cassert>\n\n#include \"walsh_hadamard_transform.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS> FPS convolution_xor(FPS &a, const FPS &b) {\n\
    \    assert(size(a) == size(b));\n    int n = int(size(a)); // == int(size(b)\n\
    \    if (!n) return {};\n    assert((n & -n) == n);\n    FPS c(b.begin(), b.end());\n\
    \n    walsh_hadamard_transform(a);\n    walsh_hadamard_transform(c);\n    for\
    \ (int i = 0; i < n; i++) a[i] *= c[i];\n    inverse_walsh_hadamard_transform(a);\n\
    \n    return a;\n}\n\n} // namespace kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_XOR_HPP\n"
  dependsOn:
  - convolution/walsh_hadamard_transform.hpp
  isVerificationFile: false
  path: convolution/convolution_xor.hpp
  requiredBy: []
  timestamp: '2025-01-06 05:33:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_convolution/convolution_xor.test.cpp
documentation_of: convolution/convolution_xor.hpp
layout: document
redirect_from:
- /library/convolution/convolution_xor.hpp
- /library/convolution/convolution_xor.hpp.html
title: convolution/convolution_xor.hpp
---
