---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: zeta_mobius_transfrom.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/zeta_mobius_transfrom.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: convolution_or.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_or.test.cpp
    type: Verified with
  dependsOn:
  - convolution/zeta_mobius_transfrom.hpp
  embedded:
  - code: "#ifndef KK2_CONVOLUTION_CONVOLUTION_OR_HPP\n#define KK2_CONVOLUTION_CONVOLUTION_OR_HPP\
      \ 1\n\n#include <cassert>\n\n#include \"zeta_mobius_transfrom.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class FPS> FPS convolution_or(FPS &a, const FPS &b) {\n\
      \    assert(size(a) == size(b));\n    int n = int(size(a)); // == int(size(b)\n\
      \    if (!n) return {};\n    assert((n & -n) == n); // n is a power of 2\n \
      \   FPS c(b.begin(), b.end());\n\n    subset_zeta_transform(a);\n    subset_zeta_transform(c);\n\
      \    for (int i = 0; i < n; i++) a[i] *= c[i];\n    inverse_subset_zeta_transform(a);\n\
      \n    return a;\n}\n\n} // namespace kk2\n\n#endif // KK2_CONVOLUTION_CONVOLUTION_OR_HPP\n"
    name: default
  - code: "#line 1 \"convolution/convolution_or.hpp\"\n\n\n\n#include <cassert>\n\n\
      #line 1 \"convolution/zeta_mobius_transfrom.hpp\"\n\n\n\n#line 5 \"convolution/zeta_mobius_transfrom.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class FPS> void superset_zeta_transform(FPS\
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
      \ != 0) a[j] -= a[i ^ j];\n        }\n    }\n}\n\n} // namespace kk2\n\n\n#line\
      \ 7 \"convolution/convolution_or.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ FPS> FPS convolution_or(FPS &a, const FPS &b) {\n    assert(size(a) == size(b));\n\
      \    int n = int(size(a)); // == int(size(b)\n    if (!n) return {};\n    assert((n\
      \ & -n) == n); // n is a power of 2\n    FPS c(b.begin(), b.end());\n\n    subset_zeta_transform(a);\n\
      \    subset_zeta_transform(c);\n    for (int i = 0; i < n; i++) a[i] *= c[i];\n\
      \    inverse_subset_zeta_transform(a);\n\n    return a;\n}\n\n} // namespace\
      \ kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: convolution/convolution_or.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-09 02:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_convolution/convolution_or.test.cpp
documentation_of: convolution/convolution_or.hpp
layout: document
---
