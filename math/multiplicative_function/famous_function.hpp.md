---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: type_alias.hpp
      icon: LIBRARY_ALL_AC
      path: common/type_alias.hpp
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
  - common/type_alias.hpp
  - math/pow.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n#define KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\
      \ 1\n\n#include \"../../common/type_alias.hpp\"\n#include \"../pow.hpp\"\n\n\
      namespace kk2 {\n\nnamespace mf {\n\ni32 mobius(u32, u32 e) { return e == 1\
      \ ? -1 : 0; }\n\nu32 sigma0(u32, u32 e) { return e + 1; }\n\nu64 sigma1(u32\
      \ p, u32 e) {\n    u64 p_e = pow<u64>(p, e);\n    return p_e + (p_e - 1) / (p\
      \ - 1);\n}\n\nu64 euler_phi(u32 p, u32 e) {\n    u64 p_e = pow<u64>(p, e);\n\
      \    return p_e - p_e / p;\n}\n\n} // namespace mf\n\n} // namespace kk2\n\n\
      #endif // KK2_MATH_MULTIPLICATIVE_FUNCTION_FAMOUS_FUNCTION_HPP\n"
    name: default
  - code: "#line 1 \"math/multiplicative_function/famous_function.hpp\"\n\n\n\n#line\
      \ 1 \"common/type_alias.hpp\"\n\n\n\n#include <cstddef>\n#include <cstdint>\n\
      \nnamespace kk2 {\n\nusing usize = std::size_t;\nusing i8 = std::int8_t;\nusing\
      \ u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\n\
      using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
      using u64 = std::uint64_t;\n\n#ifndef _MSC_VER\nusing i128 = __int128_t;\nusing\
      \ u128 = __uint128_t;\n#endif\n\n} // namespace kk2\n\n\n#line 1 \"math/pow.hpp\"\
      \n\n\n\n#include <cassert>\n\nnamespace kk2 {\n\ntemplate <class S, class T,\
      \ class U> constexpr S pow(T x, U n) {\n    assert(n >= 0);\n    S r = 1, y\
      \ = x;\n    while (n) {\n        if (n & 1) r *= y;\n        if (n >>= 1) y\
      \ *= y;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 6 \"math/multiplicative_function/famous_function.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace mf {\n\ni32 mobius(u32, u32 e) { return e ==\
      \ 1 ? -1 : 0; }\n\nu32 sigma0(u32, u32 e) { return e + 1; }\n\nu64 sigma1(u32\
      \ p, u32 e) {\n    u64 p_e = pow<u64>(p, e);\n    return p_e + (p_e - 1) / (p\
      \ - 1);\n}\n\nu64 euler_phi(u32 p, u32 e) {\n    u64 p_e = pow<u64>(p, e);\n\
      \    return p_e - p_e / p;\n}\n\n} // namespace mf\n\n} // namespace kk2\n\n\
      \n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math/multiplicative_function/famous_function.hpp
  pathExtension: hpp
  requiredBy: []
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
documentation_of: math/multiplicative_function/famous_function.hpp
layout: document
---
