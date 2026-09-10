---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files: []
    type: Required by
  - files: []
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP\n#define KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP\
      \ 1\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
      \ kk2 {\n\ntemplate <class Poly, class Matrix, class Field = typename Matrix::value_type>\n\
      Poly characteristic_polynomial(const Matrix &mat) {\n    assert(mat.get_h()\
      \ == mat.get_w());\n    if (mat.get_h() == 0) return Poly{1};\n    if (mat.get_h()\
      \ == 1) return Poly{-mat[0][0], 1};\n    int n = mat.get_h();\n    Matrix tmp(mat);\n\
      \    tmp.to_upper_Hessenberg();\n    std::vector<Poly> p(n + 1);\n    p[0] =\
      \ Poly{1}, p[1] = Poly{-tmp[0][0], 1};\n    for (int i = 2; i <= n; ++i) {\n\
      \        p[i].resize(i + 1);\n        p[i][i] = Field(1), p[i][0] = -tmp[i -\
      \ 1][i - 1] * p[i - 1][0];\n        for (int j = 1; j < i; ++j) p[i][j] = -p[i\
      \ - 1][j] * tmp[i - 1][i - 1] + p[i - 1][j - 1];\n        for (int j = i - 2;\
      \ j >= 0; --j) {\n            if (tmp[j + 1][j] == Field(0)) break;\n      \
      \      if (tmp[j][i - 1] == Field(0)) continue;\n            p[i] -= p[j] *\
      \ tmp[j][i - 1];\n        }\n    }\n    return p[n];\n}\n\n} // namespace kk2\n\
      \n#endif // KK2_MATRIX_CHARACTERISTIC_POLYNOMIAL_HPP\n"
    name: default
  - code: "#line 1 \"matrix/characteristic_polynomial.hpp\"\n\n\n\n#include <cassert>\n\
      #include <utility>\n#include <vector>\n\nnamespace kk2 {\n\ntemplate <class\
      \ Poly, class Matrix, class Field = typename Matrix::value_type>\nPoly characteristic_polynomial(const\
      \ Matrix &mat) {\n    assert(mat.get_h() == mat.get_w());\n    if (mat.get_h()\
      \ == 0) return Poly{1};\n    if (mat.get_h() == 1) return Poly{-mat[0][0], 1};\n\
      \    int n = mat.get_h();\n    Matrix tmp(mat);\n    tmp.to_upper_Hessenberg();\n\
      \    std::vector<Poly> p(n + 1);\n    p[0] = Poly{1}, p[1] = Poly{-tmp[0][0],\
      \ 1};\n    for (int i = 2; i <= n; ++i) {\n        p[i].resize(i + 1);\n   \
      \     p[i][i] = Field(1), p[i][0] = -tmp[i - 1][i - 1] * p[i - 1][0];\n    \
      \    for (int j = 1; j < i; ++j) p[i][j] = -p[i - 1][j] * tmp[i - 1][i - 1]\
      \ + p[i - 1][j - 1];\n        for (int j = i - 2; j >= 0; --j) {\n         \
      \   if (tmp[j + 1][j] == Field(0)) break;\n            if (tmp[j][i - 1] ==\
      \ Field(0)) continue;\n            p[i] -= p[j] * tmp[j][i - 1];\n        }\n\
      \    }\n    return p[n];\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: matrix/characteristic_polynomial.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/characteristic_polynomial.hpp
layout: document
---
