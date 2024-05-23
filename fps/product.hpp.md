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
  bundledCode: "#line 1 \"fps/product.hpp\"\n\n\n\n\ntemplate <class FPS, class mint\
    \ = typename FPS::value_type>\nFormalPowerSeries<mint> all_prod(const vector<FPS>\
    \ &a, int l, int r) {\n    if (l == r) return FPS{1};\n    if (l + 1 == r) return\
    \ a[l];\n    int m = (l + r) >> 1;\n    return all_prod(a, l, m) * all_prod(a,\
    \ m, r);\n}\n\n\n"
  code: "#ifndef FPS_PRODUCT_HPP\n#define FPS_PRODUCT_HPP 1\n\n\ntemplate <class FPS,\
    \ class mint = typename FPS::value_type>\nFormalPowerSeries<mint> all_prod(const\
    \ vector<FPS> &a, int l, int r) {\n    if (l == r) return FPS{1};\n    if (l +\
    \ 1 == r) return a[l];\n    int m = (l + r) >> 1;\n    return all_prod(a, l, m)\
    \ * all_prod(a, m, r);\n}\n\n#endif // FPS_PRODUCT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/product.hpp
  requiredBy: []
  timestamp: '2024-05-23 16:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/product.hpp
layout: document
redirect_from:
- /library/fps/product.hpp
- /library/fps/product.hpp.html
title: fps/product.hpp
---
