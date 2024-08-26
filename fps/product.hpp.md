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
  bundledCode: "#line 1 \"fps/product.hpp\"\n\n\n\nnamespace kk2 {\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nFPS all_prod(const vector<FPS>\
    \ &a) {\n    return inner_all_prod(a, 0, (int)a.size());\n}\n\ntemplate <class\
    \ FPS, class mint = typename FPS::value_type>\nFPS inner_all_prod(const vector<FPS>\
    \ &a, int l, int r) {\n    if (l == r) return FPS{1};\n    if (l + 1 == r) return\
    \ a[l];\n    int m = (l + r) >> 1;\n    return inner_all_prod(a, l, m) * inner_all_prod(a,\
    \ m, r);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef FPS_PRODUCT_HPP\n#define FPS_PRODUCT_HPP 1\n\nnamespace kk2 {\n\n\
    template <class FPS, class mint = typename FPS::value_type>\nFPS all_prod(const\
    \ vector<FPS> &a) {\n    return inner_all_prod(a, 0, (int)a.size());\n}\n\ntemplate\
    \ <class FPS, class mint = typename FPS::value_type>\nFPS inner_all_prod(const\
    \ vector<FPS> &a, int l, int r) {\n    if (l == r) return FPS{1};\n    if (l +\
    \ 1 == r) return a[l];\n    int m = (l + r) >> 1;\n    return inner_all_prod(a,\
    \ l, m) * inner_all_prod(a, m, r);\n}\n\n} // namespace kk2\n\n#endif // FPS_PRODUCT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/product.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/product.hpp
layout: document
redirect_from:
- /library/fps/product.hpp
- /library/fps/product.hpp.html
title: fps/product.hpp
---
