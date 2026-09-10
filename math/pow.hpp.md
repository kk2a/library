---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: arbitrary_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/arbitrary_table.hpp
    - filename: counting_square_free.hpp
      icon: LIBRARY_NO_TESTS
      path: math/multiplicative_function/counting_square_free.hpp
    - filename: famous_function.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/famous_function.hpp
    - filename: famous_function_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/famous_function_table.hpp
    - filename: sigma.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/sigma.hpp
    type: Required by
  - files:
    - filename: wavelet_matrix.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_POW_HPP\n#define KK2_MATH_POW_HPP 1\n\n#include <cassert>\n\
      \nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow(T\
      \ x, U n) {\n    assert(n >= 0);\n    S r = 1, y = x;\n    while (n) {\n   \
      \     if (n & 1) r *= y;\n        if (n >>= 1) y *= y;\n    }\n    return r;\n\
      }\n\n} // namespace kk2\n\n#endif // KK2_MATH_POW_HPP\n"
    name: default
  - code: "#line 1 \"math/pow.hpp\"\n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\
      \ntemplate <class S, class T, class U> constexpr S pow(T x, U n) {\n    assert(n\
      \ >= 0);\n    S r = 1, y = x;\n    while (n) {\n        if (n & 1) r *= y;\n\
      \        if (n >>= 1) y *= y;\n    }\n    return r;\n}\n\n} // namespace kk2\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/pow.hpp
  pathExtension: hpp
  requiredBy:
  - math/multiplicative_function/arbitrary_table.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/famous_function.hpp
  - math/multiplicative_function/famous_function_table.hpp
  - math/multiplicative_function/sigma.hpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/pow.hpp
layout: document
---
