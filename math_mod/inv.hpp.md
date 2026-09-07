---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: convolution_int.hpp
      icon: LIBRARY_NO_TESTS
      path: convolution/convolution_int.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: garner.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/garner.hpp
    - filename: fps_exp_arb.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_fps/fps_exp_arb.test.cpp
    type: Required by
  - files:
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: convolution_arbitrary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    - filename: fps_inv_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_inv_arb.test.cpp
    - filename: fps_log_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_log_arb.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_MOD_INV_HPP\n#define KK2_MATH_MOD_INV_HPP 1\n\n#include\
      \ <algorithm>\n\nnamespace kk2 {\n\n// require: modulo >= 1\ntemplate <class\
      \ T> constexpr T mod_inversion(T a, T modulo) {\n    a %= modulo;\n    if (a\
      \ < 0) a += modulo;\n    T s = modulo, t = a;\n    T m0 = 0, m1 = 1;\n    while\
      \ (t) {\n        T u = s / t;\n        std::swap(s -= t * u, t);\n        std::swap(m0\
      \ -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n    return m0;\n}\n\
      \n} // namespace kk2\n\n#endif // KK2_MATH_MOD_INV_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/inv.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace kk2\
      \ {\n\n// require: modulo >= 1\ntemplate <class T> constexpr T mod_inversion(T\
      \ a, T modulo) {\n    a %= modulo;\n    if (a < 0) a += modulo;\n    T s = modulo,\
      \ t = a;\n    T m0 = 0, m1 = 1;\n    while (t) {\n        T u = s / t;\n   \
      \     std::swap(s -= t * u, t);\n        std::swap(m0 -= m1 * u, m1);\n    }\n\
      \    if (m0 < 0) m0 += modulo;\n    return m0;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/inv.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - fps/fps_arb.hpp
  - math_mod/garner.hpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
documentation_of: math_mod/inv.hpp
layout: document
---
