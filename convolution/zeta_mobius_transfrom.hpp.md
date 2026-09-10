---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: convolution_and.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_and.hpp
    - filename: convolution_or.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_or.hpp
    type: Required by
  - files:
    - filename: convolution_and.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_and.test.cpp
    - filename: convolution_or.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_or.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\n#define KK2_CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\
      \ 1\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void superset_zeta_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
      \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j <\
      \ n; j++) {\n            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n  \
      \  }\n}\n\ntemplate <class FPS> void inverse_superset_zeta_transform(FPS &a)\
      \ {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n) ==\
      \ n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
      \ j++) {\n            if ((i & j) == 0) a[j] -= a[i ^ j];\n        }\n    }\n\
      }\n\ntemplate <class FPS> void subset_zeta_transform(FPS &a) {\n    int n =\
      \ int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n    for (int\
      \ i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n        \
      \    if ((i & j) != 0) a[j] += a[i ^ j];\n        }\n    }\n}\n\ntemplate <class\
      \ FPS> void inverse_subset_zeta_transform(FPS &a) {\n    int n = int(a.size());\n\
      \    if (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n;\
      \ i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j)\
      \ != 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\n} // namespace kk2\n\n#endif\
      \ // KK2_CONVOLUTION_ZETA_MOBIUS_TRANSFORM_HPP\n"
    name: default
  - code: "#line 1 \"convolution/zeta_mobius_transfrom.hpp\"\n\n\n\n#include <cassert>\n\
      \nnamespace kk2 {\n\ntemplate <class FPS> void superset_zeta_transform(FPS &a)\
      \ {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n) ==\
      \ n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n;\
      \ j++) {\n            if ((i & j) == 0) a[j] += a[i ^ j];\n        }\n    }\n\
      }\n\ntemplate <class FPS> void inverse_superset_zeta_transform(FPS &a) {\n \
      \   int n = int(a.size());\n    if (!n) return;\n    assert((n & -n) == n);\n\
      \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++)\
      \ {\n            if ((i & j) == 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\n\
      template <class FPS> void subset_zeta_transform(FPS &a) {\n    int n = int(a.size());\n\
      \    if (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n;\
      \ i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j)\
      \ != 0) a[j] += a[i ^ j];\n        }\n    }\n}\n\ntemplate <class FPS> void\
      \ inverse_subset_zeta_transform(FPS &a) {\n    int n = int(a.size());\n    if\
      \ (!n) return;\n    assert((n & -n) == n);\n    for (int i = 1; i < n; i <<=\
      \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((i & j) != 0)\
      \ a[j] -= a[i ^ j];\n        }\n    }\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: convolution/zeta_mobius_transfrom.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_and.hpp
  - convolution/convolution_or.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_and.test.cpp
  - verify/yosupo_convolution/convolution_or.test.cpp
documentation_of: convolution/zeta_mobius_transfrom.hpp
layout: document
---
