---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: stirling_number.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/stirling_number.hpp
    type: Required by
  - files:
    - filename: fps_product_of_polynomial_sequence.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_FPS_PRODUCT_HPP\n#define KK2_FPS_PRODUCT_HPP 1\n\n#include\
      \ <vector>\n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename\
      \ FPS::value_type>\nFPS all_prod(const std::vector<FPS> &a) {\n    return inner_all_prod(a,\
      \ 0, (int)a.size());\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS inner_all_prod(const std::vector<FPS> &a, int l, int r) {\n    if (l ==\
      \ r) return FPS{1};\n    if (l + 1 == r) return a[l];\n    int m = (l + r) >>\
      \ 1;\n    return inner_all_prod(a, l, m) * inner_all_prod(a, m, r);\n}\n\n}\
      \ // namespace kk2\n\n#endif // KK2_FPS_PRODUCT_HPP\n"
    name: default
  - code: "#line 1 \"fps/product.hpp\"\n\n\n\n#include <vector>\n\nnamespace kk2 {\n\
      \ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS all_prod(const\
      \ std::vector<FPS> &a) {\n    return inner_all_prod(a, 0, (int)a.size());\n\
      }\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS inner_all_prod(const\
      \ std::vector<FPS> &a, int l, int r) {\n    if (l == r) return FPS{1};\n   \
      \ if (l + 1 == r) return a[l];\n    int m = (l + r) >> 1;\n    return inner_all_prod(a,\
      \ l, m) * inner_all_prod(a, m, r);\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/product.hpp
  pathExtension: hpp
  requiredBy:
  - math_mod/stirling_number.hpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
documentation_of: fps/product.hpp
layout: document
---
