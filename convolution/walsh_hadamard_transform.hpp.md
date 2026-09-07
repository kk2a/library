---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: convolution_xor.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_xor.hpp
    type: Required by
  - files:
    - filename: convolution_xor.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_xor.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n#define KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\
      \ 1\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class FPS> void walsh_hadamard_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
      \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j <\
      \ n; j++) {\n            if ((i & j) != 0) {\n                auto x = a[j],\
      \ y = a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n        \
      \    }\n        }\n    }\n}\n\ntemplate <class FPS> void inverse_walsh_hadamard_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
      \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j <\
      \ n; j++) {\n            if ((i & j) != 0) {\n                auto x = a[j],\
      \ y = a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n\
      \            }\n        }\n    }\n}\n\n} // namespace kk2\n\n#endif // KK2_CONVOLUTION_WALSH_HADAMARD_TRANSFORM_HPP\n"
    name: default
  - code: "#line 1 \"convolution/walsh_hadamard_transform.hpp\"\n\n\n\n#include <cassert>\n\
      \nnamespace kk2 {\n\ntemplate <class FPS> void walsh_hadamard_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
      \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j <\
      \ n; j++) {\n            if ((i & j) != 0) {\n                auto x = a[j],\
      \ y = a[i ^ j];\n                a[j] = -x + y, a[i ^ j] = x + y;\n        \
      \    }\n        }\n    }\n}\n\ntemplate <class FPS> void inverse_walsh_hadamard_transform(FPS\
      \ &a) {\n    int n = int(a.size());\n    if (!n) return;\n    assert((n & -n)\
      \ == n);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j <\
      \ n; j++) {\n            if ((i & j) != 0) {\n                auto x = a[j],\
      \ y = a[i ^ j];\n                a[j] = (-x + y) / 2, a[i ^ j] = (x + y) / 2;\n\
      \            }\n        }\n    }\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: convolution/walsh_hadamard_transform.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_xor.hpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_xor.test.cpp
documentation_of: convolution/walsh_hadamard_transform.hpp
layout: document
---
