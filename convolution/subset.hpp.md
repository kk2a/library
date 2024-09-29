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
  bundledCode: "#line 1 \"convolution/subset.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
    \ mint = typename FPS::value_type>\nFPS convolution_subset(FPS &a, const FPS &b)\
    \ {\n    int n = int(size(a)); // == int(size(b)\n    if (!n) return {};\n   \
    \ int h = __builtin_ctz(n);\n\n    assert((n & (-n)) == n);\n    std::vector<int>\
    \ chi(n, 0);\n    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;\n\
    \    std::vector<std::vector<mint>> f(n, std::vector<mint>(h + 1)), g(n, std::vector<mint>(h\
    \ + 1));\n    for (int i = 0; i < n; i++) {\n        f[i][chi[i]] = a[i];\n  \
    \      g[i][chi[i]] = b[i];\n    }\n    auto rfzt = [&](std::vector<std::vector<mint>>\
    \ &c) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++)\
    \ {\n                    int t = s | i;\n                    for (int d = 0; d\
    \ <= h; ++d) { c[t][d] += c[s][d]; }\n                }\n            }\n     \
    \   }\n    };\n    auto rifzt = [&](std::vector<std::vector<mint>> &c) -> void\
    \ {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j\
    \ < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++) {\n    \
    \                int t = s | i;\n                    for (int d = 0; d <= h; d++)\
    \ { c[t][d] -= c[s][d]; }\n                }\n            }\n        }\n    };\n\
    \    rfzt(f);\n    rfzt(g);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ d = h; d >= 0; d--) {\n            mint x{};\n            for (int j = 0; j\
    \ < d + 1; j++) { x += f[i][j] * g[i][d - j]; }\n            f[i][d] = x;\n  \
    \      }\n    }\n    rifzt(f);\n    for (int i = 0; i < n; i++) a[i] = f[i][chi[i]];\n\
    \    return a;\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef CONVOLUTION_SUBSET\n#define CONVOLUTION_SUBSET 1\n\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nFPS convolution_subset(FPS &a,\
    \ const FPS &b) {\n    int n = int(size(a)); // == int(size(b)\n    if (!n) return\
    \ {};\n    int h = __builtin_ctz(n);\n\n    assert((n & (-n)) == n);\n    std::vector<int>\
    \ chi(n, 0);\n    for (int i = 1; i < n; i++) chi[i] = chi[i - (i & -i)] + 1;\n\
    \    std::vector<std::vector<mint>> f(n, std::vector<mint>(h + 1)), g(n, std::vector<mint>(h\
    \ + 1));\n    for (int i = 0; i < n; i++) {\n        f[i][chi[i]] = a[i];\n  \
    \      g[i][chi[i]] = b[i];\n    }\n    auto rfzt = [&](std::vector<std::vector<mint>>\
    \ &c) -> void {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int\
    \ j = 0; j < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++)\
    \ {\n                    int t = s | i;\n                    for (int d = 0; d\
    \ <= h; ++d) { c[t][d] += c[s][d]; }\n                }\n            }\n     \
    \   }\n    };\n    auto rifzt = [&](std::vector<std::vector<mint>> &c) -> void\
    \ {\n        for (int i = 1; i < n; i <<= 1) {\n            for (int j = 0; j\
    \ < n; j += 2 * i) {\n                for (int s = j; s < j + i; s++) {\n    \
    \                int t = s | i;\n                    for (int d = 0; d <= h; d++)\
    \ { c[t][d] -= c[s][d]; }\n                }\n            }\n        }\n    };\n\
    \    rfzt(f);\n    rfzt(g);\n    for (int i = 0; i < n; i++) {\n        for (int\
    \ d = h; d >= 0; d--) {\n            mint x{};\n            for (int j = 0; j\
    \ < d + 1; j++) { x += f[i][j] * g[i][d - j]; }\n            f[i][d] = x;\n  \
    \      }\n    }\n    rifzt(f);\n    for (int i = 0; i < n; i++) a[i] = f[i][chi[i]];\n\
    \    return a;\n}\n\n} // namespace kk2\n\n#endif // CONVOLUTION_SUBSET\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/subset.hpp
  requiredBy: []
  timestamp: '2024-09-29 19:28:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/subset.hpp
layout: document
redirect_from:
- /library/convolution/subset.hpp
- /library/convolution/subset.hpp.html
title: convolution/subset.hpp
---
