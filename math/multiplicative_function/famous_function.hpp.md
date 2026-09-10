---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: pow.hpp
      icon: LIBRARY_ALL_AC
      path: math/pow.hpp
    type: Depends on
  - files: []
    type: Required by
  - files:
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    type: Verified with
  dependsOn:
  - math/pow.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\
      \ 1\n\n#include \"../pow.hpp\"\n\nnamespace kk2 {\n\nnamespace mf {\n\nusing\
      \ i64 = long long;\n\ni64 mobius(i64, i64 e) { return e == 1 ? -1 : 0; }\n\n\
      i64 sigma0(i64, i64 e) { return e + 1; }\n\ni64 sigma1(i64 p, i64 e) {\n   \
      \ i64 p_e = pow<i64>(p, e);\n    return p_e + (p_e - 1) / (p - 1);\n}\n\ni64\
      \ euler_phi(i64 p, i64 e) {\n    i64 p_e = pow<i64>(p, e);\n    return p_e -\
      \ p_e / p;\n}\n\n} // namespace mf\n\n} // namespace kk2\n\n#endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n"
    name: default
  - code: "#line 1 \"math/multiplicative_function/famous_function.hpp\"\n\n\n\n#line\
      \ 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate\
      \ <class S, class T, class U> constexpr S pow(T x, U n) {\n    assert(n >= 0);\n\
      \    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n        if\
      \ (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line\
      \ 5 \"math/multiplicative_function/famous_function.hpp\"\n\nnamespace kk2 {\n\
      \nnamespace mf {\n\nusing i64 = long long;\n\ni64 mobius(i64, i64 e) { return\
      \ e == 1 ? -1 : 0; }\n\ni64 sigma0(i64, i64 e) { return e + 1; }\n\ni64 sigma1(i64\
      \ p, i64 e) {\n    i64 p_e = pow<i64>(p, e);\n    return p_e + (p_e - 1) / (p\
      \ - 1);\n}\n\ni64 euler_phi(i64 p, i64 e) {\n    i64 p_e = pow<i64>(p, e);\n\
      \    return p_e - p_e / p;\n}\n\n} // namespace mf\n\n} // namespace kk2\n\n\
      \n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/multiplicative_function/famous_function.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/multiplicative_function/famous_function.hpp
layout: document
---
