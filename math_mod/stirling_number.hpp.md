---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: product.hpp
      icon: LIBRARY_ALL_AC
      path: fps/product.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    type: Verified with
  dependsOn:
  - fps/product.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MOD_STIRLING_NUMBER_HPP\n#define KK2_MATH_MOD_STIRLING_NUMBER_HPP\
      \ 1\n\n#include <vector>\n\n#include \"../fps/product.hpp\"\n\nnamespace kk2\
      \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nstd::vector<mint>\
      \ enumerate_stirling_number_of_the_first_kind(int n) {\n    std::vector<FPS>\
      \ a(n);\n    for (int i = 0; i < n; ++i) { a[i] = FPS{-i, 1}; }\n    return\
      \ all_prod(a);\n}\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_STIRLING_NUMBER_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/stirling_number.hpp\"\n\n\n\n#include <vector>\n\n#line\
      \ 1 \"fps/product.hpp\"\n\n\n\n#line 5 \"fps/product.hpp\"\n\nnamespace kk2\
      \ {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS all_prod(const\
      \ std::vector<FPS> &a) {\n    return inner_all_prod(a, 0, (int)a.size());\n\
      }\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS inner_all_prod(const\
      \ std::vector<FPS> &a, int l, int r) {\n    if (l == r) return FPS{1};\n   \
      \ if (l + 1 == r) return a[l];\n    int m = (l + r) >> 1;\n    return inner_all_prod(a,\
      \ l, m) * inner_all_prod(a, m, r);\n}\n\n} // namespace kk2\n\n\n#line 7 \"\
      math_mod/stirling_number.hpp\"\n\nnamespace kk2 {\n\ntemplate <class FPS, class\
      \ mint = typename FPS::value_type>\nstd::vector<mint> enumerate_stirling_number_of_the_first_kind(int\
      \ n) {\n    std::vector<FPS> a(n);\n    for (int i = 0; i < n; ++i) { a[i] =\
      \ FPS{-i, 1}; }\n    return all_prod(a);\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/stirling_number.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
documentation_of: math_mod/stirling_number.hpp
layout: document
---
