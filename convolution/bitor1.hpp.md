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
  bundledCode: "#line 1 \"convolution/bitor1.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <functional>\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename\
    \ FPS::value_type>\nFPS convolution_or(FPS &a, const FPS &b) {\n    assert(size(a)\
    \ == size(b));\n    int n = int(size(a)); // == int(size(b)\n    if (!n) return\
    \ {};\n    assert((n & -n) == n); // n is a power of 2\n    FPS c(b.begin(), b.end());\n\
    \n    auto fzt = [&](FPS &x) -> void {\n        for (int i = 1; i < n; i <<= 1)\
    \ {\n            for (int j = 0; j < n; j++) {\n                if ((i & j) !=\
    \ 0) x[j] += x[i ^ j];\n            }\n        }\n    };\n    auto ifzt = [&](FPS\
    \ &x) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j++) {\n                if ((i & j) != 0) x[j] -= x[i ^ j];\n\
    \            }\n        }\n    };\n\n    fzt(a);\n    fzt(c);\n    for (int i\
    \ = 0; i < n; i++) a[i] *= c[i];\n    ifzt(a);\n\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n\n"
  code: "#ifndef CONVOLUTION_OR\n#define CONVOLUTION_OR 1\n\n#include <cassert>\n\
    #include <functional>\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint =\
    \ typename FPS::value_type>\nFPS convolution_or(FPS &a, const FPS &b) {\n    assert(size(a)\
    \ == size(b));\n    int n = int(size(a)); // == int(size(b)\n    if (!n) return\
    \ {};\n    assert((n & -n) == n); // n is a power of 2\n    FPS c(b.begin(), b.end());\n\
    \n    auto fzt = [&](FPS &x) -> void {\n        for (int i = 1; i < n; i <<= 1)\
    \ {\n            for (int j = 0; j < n; j++) {\n                if ((i & j) !=\
    \ 0) x[j] += x[i ^ j];\n            }\n        }\n    };\n    auto ifzt = [&](FPS\
    \ &x) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j++) {\n                if ((i & j) != 0) x[j] -= x[i ^ j];\n\
    \            }\n        }\n    };\n\n    fzt(a);\n    fzt(c);\n    for (int i\
    \ = 0; i < n; i++) a[i] *= c[i];\n    ifzt(a);\n\n    return a;\n}\n\n} // namespace\
    \ kk2\n\n#endif // CONVOLUTION_OR\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitor1.hpp
  requiredBy: []
  timestamp: '2024-09-10 08:16:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/bitor1.hpp
layout: document
redirect_from:
- /library/convolution/bitor1.hpp
- /library/convolution/bitor1.hpp.html
title: convolution/bitor1.hpp
---
