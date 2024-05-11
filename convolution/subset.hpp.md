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
  bundledCode: "#line 1 \"convolution/subset.hpp\"\n\n\n\ntemplate <class mint, class\
    \ FPS>\nFPS convolution_subset(FPS& a, FPS b) {\n    int n = int(size(a));  //\
    \ == int(size(b)\n    if (!n) return {};\n    int h = 0;\n    while (1 << h <\
    \ n) h++;\n    n = 1 << h;\n    a.resize(n, 0), b.resize(n, 0);\n    vector<int>\
    \ chi(n, 0);\n    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;\n\
    \    vector<vector<mint>> f(n, vector<mint>(h + 1)), g(n, vector<mint>(h + 1));\n\
    \    for (int i = 0; i < n; i++) {\n        f[i][chi[i]] = a[i];\n        g[i][chi[i]]\
    \ = b[i];\n    }\n    auto rfzt = [&] (vector<vector<mint>>& c) -> void {\n  \
    \      for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j\
    \ += 2 * i) {\n                for (int s = j; s < j + i; s++) {\n           \
    \         int t = s | i;\n                    for (int d = 0; d <= h; ++d) {\n\
    \                        c[t][d] += c[s][d];\n                    }\n        \
    \        }\n            }\n        }\n    };\n    auto rifzt = [&] (vector<vector<mint>>&\
    \ c) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++)\
    \ {\n                    int t = s | i;\n                    for (int d = 0; d\
    \ <= h; d++) {\n                        c[t][d] -= c[s][d];\n                \
    \    }\n                }\n            }\n            \n        }\n    };\n  \
    \  rfzt(f);\n    rfzt(g);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ d = h; d >= 0; d--) {\n            mint x;\n            for (int j = 0; j <\
    \ d + 1; j++) {\n                x += f[i][j] * g[i][d - j];\n            }\n\
    \            f[i][d] = x;\n        }\n    }\n    rifzt(f);\n    for (int i = 0;\
    \ i < n; i++) a[i] = f[i][chi[i]];\n    return a;\n}\n\n\n"
  code: "#ifndef CONVOLUTION_SUBSET\n#define CONVOLUTION_SUBSET 1\n\ntemplate <class\
    \ mint, class FPS>\nFPS convolution_subset(FPS& a, FPS b) {\n    int n = int(size(a));\
    \  // == int(size(b)\n    if (!n) return {};\n    int h = 0;\n    while (1 <<\
    \ h < n) h++;\n    n = 1 << h;\n    a.resize(n, 0), b.resize(n, 0);\n    vector<int>\
    \ chi(n, 0);\n    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;\n\
    \    vector<vector<mint>> f(n, vector<mint>(h + 1)), g(n, vector<mint>(h + 1));\n\
    \    for (int i = 0; i < n; i++) {\n        f[i][chi[i]] = a[i];\n        g[i][chi[i]]\
    \ = b[i];\n    }\n    auto rfzt = [&] (vector<vector<mint>>& c) -> void {\n  \
    \      for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j < n; j\
    \ += 2 * i) {\n                for (int s = j; s < j + i; s++) {\n           \
    \         int t = s | i;\n                    for (int d = 0; d <= h; ++d) {\n\
    \                        c[t][d] += c[s][d];\n                    }\n        \
    \        }\n            }\n        }\n    };\n    auto rifzt = [&] (vector<vector<mint>>&\
    \ c) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++)\
    \ {\n                    int t = s | i;\n                    for (int d = 0; d\
    \ <= h; d++) {\n                        c[t][d] -= c[s][d];\n                \
    \    }\n                }\n            }\n            \n        }\n    };\n  \
    \  rfzt(f);\n    rfzt(g);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ d = h; d >= 0; d--) {\n            mint x;\n            for (int j = 0; j <\
    \ d + 1; j++) {\n                x += f[i][j] * g[i][d - j];\n            }\n\
    \            f[i][d] = x;\n        }\n    }\n    rifzt(f);\n    for (int i = 0;\
    \ i < n; i++) a[i] = f[i][chi[i]];\n    return a;\n}\n\n#endif // CONVOLUTION_SUBSET\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/subset.hpp
  requiredBy: []
  timestamp: '2024-05-03 16:15:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/subset.hpp
layout: document
redirect_from:
- /library/convolution/subset.hpp
- /library/convolution/subset.hpp.html
title: convolution/subset.hpp
---
