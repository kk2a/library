---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/product.hpp
    title: fps/product.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    title: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math_mod/stirling_number.hpp\"\n\n\n\n#include <vector>\n\
    \n#line 1 \"fps/product.hpp\"\n\n\n\n#line 5 \"fps/product.hpp\"\n\nnamespace\
    \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS all_prod(const\
    \ std::vector<FPS> &a) {\n    return inner_all_prod(a, 0, (int)a.size());\n}\n\
    \ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS inner_all_prod(const\
    \ std::vector<FPS> &a, int l, int r) {\n    if (l == r) return FPS{1};\n    if\
    \ (l + 1 == r) return a[l];\n    int m = (l + r) >> 1;\n    return inner_all_prod(a,\
    \ l, m) * inner_all_prod(a, m, r);\n}\n\n} // namespace kk2\n\n\n#line 7 \"math_mod/stirling_number.hpp\"\
    \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
    std::vector<mint> enumerate_stirling_number_of_the_first_kind(int n) {\n    std::vector<FPS>\
    \ a(n);\n    for (int i = 0; i < n; ++i) {\n        a[i] = FPS{-i, 1};\n    }\n\
    \    return all_prod(a);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef KK2_MATH_MOD_STIRLING_NUMBER_HPP\n#define KK2_MATH_MOD_STIRLING_NUMBER_HPP\
    \ 1\n\n#include <vector>\n\n#include \"../fps/product.hpp\"\n\nnamespace kk2 {\n\
    \ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
    \ enumerate_stirling_number_of_the_first_kind(int n) {\n    std::vector<FPS> a(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        a[i] = FPS{-i, 1};\n    }\n    return\
    \ all_prod(a);\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_STIRLING_NUMBER_HPP\n"
  dependsOn:
  - fps/product.hpp
  isVerificationFile: false
  path: math_mod/stirling_number.hpp
  requiredBy: []
  timestamp: '2025-02-08 14:55:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
documentation_of: math_mod/stirling_number.hpp
layout: document
redirect_from:
- /library/math_mod/stirling_number.hpp
- /library/math_mod/stirling_number.hpp.html
title: math_mod/stirling_number.hpp
---
