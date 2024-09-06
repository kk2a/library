---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data_structure/convex_hull_trick_add_monotone.hpp
    title: data_structure/convex_hull_trick_add_monotone.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/frac_floor.hpp\"\n\n\n\nnamespace kk2 {\n\n// floor(x)\
    \ = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)   (for all\
    \ x)          ...(2)\n\n// return floor(a / b)\ntemplate <typename T, typename\
    \ U>\nconstexpr T fracfloor(T a, U b) {\n    assert(b != 0);\n    if (a % b ==\
    \ 0) return a / b;\n    if (a >= 0) return a / b;\n\n    // floor(x) = -ceil(-x)\
    \      by (2)\n    //          = -floor(-x) - 1 by (1)\n    return -((-a) / b)\
    \ - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T, typename U>\nconstexpr\
    \ T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a % b == 0) return a /\
    \ b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)      by\
    \ (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\n\n"
  code: "#ifndef MATH_FLOOR_CEIL_HPP\n#define MATH_FLOOR_CEIL_HPP 1\n\nnamespace kk2\
    \ {\n\n// floor(x) = ceil(x) - 1 (for all x not in Z) ...(1)\n// floor(x) = -ceil(-x)\
    \   (for all x)          ...(2)\n\n// return floor(a / b)\ntemplate <typename\
    \ T, typename U>\nconstexpr T fracfloor(T a, U b) {\n    assert(b != 0);\n   \
    \ if (a % b == 0) return a / b;\n    if (a >= 0) return a / b;\n\n    // floor(x)\
    \ = -ceil(-x)      by (2)\n    //          = -floor(-x) - 1 by (1)\n    return\
    \ -((-a) / b) - 1;\n}\n\n// return ceil(a / b)\ntemplate <typename T, typename\
    \ U>\nconstexpr T fracceil(T a, U b) {\n    assert(b != 0);\n    if (a % b ==\
    \ 0) return a / b;\n    if (a >= 0) return a / b + 1;\n\n    // ceil(x) = -floor(-x)\
    \      by (2)\n    return -((-a) / b);\n}\n\n} // namespace kk2\n\n#endif // MATH_FLOOR_CEIL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: math/frac_floor.hpp
  requiredBy:
  - data_structure/convex_hull_trick_add_monotone.hpp
  timestamp: '2024-09-05 03:39:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/frac_floor.hpp
layout: document
redirect_from:
- /library/math/frac_floor.hpp
- /library/math/frac_floor.hpp.html
title: math/frac_floor.hpp
---