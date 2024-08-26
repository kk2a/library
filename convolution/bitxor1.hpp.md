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
  bundledCode: "#line 1 \"convolution/bitxor1.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS convolution_xor(FPS&\
    \ a, FPS b) {\n    int n = int(size(a));  // == int(size(b)\n    if (!n) return\
    \ {};\n    int log = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n\
    \    a.resize(n, 0), b.resize(n, 0);\n\n    auto fwht = [&](FPS& a) -> void {\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((i & j) != 0) {\n                    auto x = a[j],\
    \ y = a[i ^ j];\n                    a[j] = -x + y, a[i ^ j] = x + y;\n      \
    \          }\n            }\n        }\n    };\n    auto ifwht = [&](FPS& a) ->\
    \ void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int j =\
    \ 0; j < n; j++) {\n                if ((i & j) != 0) {\n                    auto\
    \ x = a[j], y = a[i ^ j];\n                    a[j] = (-x + y) / 2, a[i ^ j] =\
    \ (x + y) / 2;\n                }\n            }\n        }\n    };\n\n    fwht(a);\n\
    \    fwht(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n    ifwht(a);\n\
    \n    return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_XOR\n#define CONVOLUTION_XOR 1\n\nnamespace kk2 {\n\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS convolution_xor(FPS&\
    \ a, FPS b) {\n    int n = int(size(a));  // == int(size(b)\n    if (!n) return\
    \ {};\n    int log = 0;\n    while (1ull << log < n) log++;\n    n = 1 << log;\n\
    \    a.resize(n, 0), b.resize(n, 0);\n\n    auto fwht = [&](FPS& a) -> void {\n\
    \        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n;\
    \ j++) {\n                if ((i & j) != 0) {\n                    auto x = a[j],\
    \ y = a[i ^ j];\n                    a[j] = -x + y, a[i ^ j] = x + y;\n      \
    \          }\n            }\n        }\n    };\n    auto ifwht = [&](FPS& a) ->\
    \ void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int j =\
    \ 0; j < n; j++) {\n                if ((i & j) != 0) {\n                    auto\
    \ x = a[j], y = a[i ^ j];\n                    a[j] = (-x + y) / 2, a[i ^ j] =\
    \ (x + y) / 2;\n                }\n            }\n        }\n    };\n\n    fwht(a);\n\
    \    fwht(b);\n    for (int i = 0; i < n; i++) a[i] *= b[i]; \n    ifwht(a);\n\
    \n    return a;\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_XOR\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/bitxor1.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/bitxor1.hpp
layout: document
redirect_from:
- /library/convolution/bitxor1.hpp
- /library/convolution/bitxor1.hpp.html
title: convolution/bitxor1.hpp
---
