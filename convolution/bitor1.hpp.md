---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/zeta_mobius_transfrom.hpp
    title: convolution/zeta_mobius_transfrom.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_convolution/convolution_or.test.cpp
    title: verify/yosupo_convolution/convolution_or.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/bitor1.hpp\"\n\n\n\n#include <cassert>\n\n#line\
    \ 1 \"convolution/zeta_mobius_transfrom.hpp\"\n\n\n\n#line 5 \"convolution/zeta_mobius_transfrom.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS> void SuperSetZetaTransform(FPS &a)\
    \ {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n    }\n}\n\ntemplate\
    \ <class FPS> void InverseSuperSetZetaTransform(FPS &a) {\n    int n = int(a.size());\n\
    \    if (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i\
    \ <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) ==\
    \ 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\ntemplate <class FPS> void SubsetZetaTransform(FPS\
    \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
    \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
    \ j++) {\n            if ((i & j) != 0) a[j] += a[i ^ j];\n        }\n    }\n\
    }\n\ntemplate <class FPS> void InverseSubsetZetaTransform(FPS &a) {\n    int n\
    \ = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for (int\
    \ i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n          \
    \  if ((i & j) != 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\n} // namespace\
    \ kk2\n\n\n#line 7 \"convolution/bitor1.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS>\nFPS convolution_or(FPS &a, const FPS &b) {\n    assert(size(a) == size(b));\n\
    \    int n = int(size(a)); // == int(size(b)\n    if (!n) return {};\n    assert((n\
    \ & -n) == n); // n is a power of 2\n    FPS c(b.begin(), b.end());\n\n    SubsetZetaTransform(a);\n\
    \    SubsetZetaTransform(c);\n    for (int i = 0; i < n; i++) a[i] *= c[i];\n\
    \    InverseSubsetZetaTransform(a);\n\n    return a;\n}\n\n} // namespace kk2\n\
    \n\n"
  code: "#ifndef CONVOLUTION_OR\n#define CONVOLUTION_OR 1\n\n#include <cassert>\n\n\
    #include \"zeta_mobius_transfrom.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS>\n\
    FPS convolution_or(FPS &a, const FPS &b) {\n    assert(size(a) == size(b));\n\
    \    int n = int(size(a)); // == int(size(b)\n    if (!n) return {};\n    assert((n\
    \ & -n) == n); // n is a power of 2\n    FPS c(b.begin(), b.end());\n\n    SubsetZetaTransform(a);\n\
    \    SubsetZetaTransform(c);\n    for (int i = 0; i < n; i++) a[i] *= c[i];\n\
    \    InverseSubsetZetaTransform(a);\n\n    return a;\n}\n\n} // namespace kk2\n\
    \n#endif // CONVOLUTION_OR\n"
  dependsOn:
  - convolution/zeta_mobius_transfrom.hpp
  isVerificationFile: false
  path: convolution/bitor1.hpp
  requiredBy: []
  timestamp: '2024-10-06 17:17:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_or.test.cpp
documentation_of: convolution/bitor1.hpp
layout: document
redirect_from:
- /library/convolution/bitor1.hpp
- /library/convolution/bitor1.hpp.html
title: convolution/bitor1.hpp
---
