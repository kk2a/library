---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convolution/bitand1.hpp\"\n\n\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS convolution_and(FPS& a, FPS b) {\n   \
    \ int n = int(size(a));  // == int(size(b)\n    if (!n) return {};\n    int log\
    \ = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n    a.resize(n,\
    \ 0), b.resize(n, 0);\n\n    auto fzt = [&](FPS& a) -> void {\n        for (int\
    \ i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j++) {\n      \
    \          if ((i & j) == 0) a[j] += a[i ^ j];\n            }\n        }\n   \
    \ };\n    auto ifzt = [&](FPS& a) -> void {\n        for (int i = 1; i < n; i\
    \ <<= 1) {\n            for (int j = 0; j < n; j++) {\n                if ((i\
    \ & j) == 0) a[j] -= a[i ^ j];\n            }\n        }\n    };\n\n    fzt(a);\n\
    \    fzt(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n    ifzt(a);\n\n\
    \    return a;\n}\n\n\n"
  code: "#ifndef CONVOLUTION_AND\n#define CONVOLUTION_AND 1\n\ntemplate <class FPS,\
    \ class mint = typename FPS::value_type>\nFPS convolution_and(FPS& a, FPS b) {\n\
    \    int n = int(size(a));  // == int(size(b)\n    if (!n) return {};\n    int\
    \ log = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n    a.resize(n,\
    \ 0), b.resize(n, 0);\n\n    auto fzt = [&](FPS& a) -> void {\n        for (int\
    \ i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j++) {\n      \
    \          if ((i & j) == 0) a[j] += a[i ^ j];\n            }\n        }\n   \
    \ };\n    auto ifzt = [&](FPS& a) -> void {\n        for (int i = 1; i < n; i\
    \ <<= 1) {\n            for (int j = 0; j < n; j++) {\n                if ((i\
    \ & j) == 0) a[j] -= a[i ^ j];\n            }\n        }\n    };\n\n    fzt(a);\n\
    \    fzt(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n    ifzt(a);\n\n\
    \    return a;\n}\n\n#endif // CONVOLUTION_AND\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitand1.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:18:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/bitand1.hpp
layout: document
redirect_from:
- /library/convolution/bitand1.hpp
- /library/convolution/bitand1.hpp.html
title: convolution/bitand1.hpp
---
