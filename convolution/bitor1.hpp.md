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
  bundledCode: "#line 1 \"convolution/bitor1.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution_or(FPS&\
    \ a, FPS b) {\n    int n = int(size(a));  // == int(size(b)\n    if (!n) return\
    \ {};\n    int log = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n\
    \    a.resize(n, 0), b.resize(n, 0);\n\n    auto fzt = [&](FPS& a) -> void {\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((i & j) != 0) a[j] += a[i ^ j];\n            }\n\
    \        }\n    };\n    auto ifzt = [&](FPS& a) -> void {\n        for (int i\
    \ = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j++) {\n        \
    \        if ((i & j) != 0) a[j] -= a[i ^ j];\n            }\n        }\n    };\n\
    \n    fzt(a);\n    fzt(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n \
    \   ifzt(a);\n\n    return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_OR\n#define CONVOLUTION_OR 1\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution_or(FPS&\
    \ a, FPS b) {\n    int n = int(size(a));  // == int(size(b)\n    if (!n) return\
    \ {};\n    int log = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n\
    \    a.resize(n, 0), b.resize(n, 0);\n\n    auto fzt = [&](FPS& a) -> void {\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((i & j) != 0) a[j] += a[i ^ j];\n            }\n\
    \        }\n    };\n    auto ifzt = [&](FPS& a) -> void {\n        for (int i\
    \ = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j++) {\n        \
    \        if ((i & j) != 0) a[j] -= a[i ^ j];\n            }\n        }\n    };\n\
    \n    fzt(a);\n    fzt(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n \
    \   ifzt(a);\n\n    return a;\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_OR\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitor1.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/bitor1.hpp
layout: document
redirect_from:
- /library/convolution/bitor1.hpp
- /library/convolution/bitor1.hpp.html
title: convolution/bitor1.hpp
---
