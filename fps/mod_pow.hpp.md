---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    type: Depends on
  - files:
    - filename: poly_find_root.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_find_root.hpp
    type: Required by
  - files:
    - filename: inplace_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/inplace_operations.test.cpp
    - filename: poly_root_finding.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_root_finding.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_FPS_MOD_POW_HPP\n#define KK2_FPS_MOD_POW_HPP 1\n\n#include\
      \ <cassert>\n\n#include \"../type_traits/integral.hpp\"\n\nnamespace kk2 {\n\
      \n// return f ^ k mod g\ntemplate <class FPS, class mint = typename FPS::value_type,\
      \ Integral T>\nFPS mod_pow(T k, const FPS &f, const FPS &g) {\n    // assert(!is_signed_v<T>\
      \ || k >= 0);\n    assert(!g.empty());\n\n    auto inv = g.rev().inv();\n  \
      \  auto quo = [&](const FPS &poly) {\n        if (poly.size() < g.size()) return\
      \ FPS{};\n        int n = poly.size() - g.size() + 1;\n        return (poly.rev().pre(n)\
      \ * inv.pre(n)).pre(n).rev();\n    };\n    FPS res{1}, b(f);\n    while (k)\
      \ {\n        if (k & 1) {\n            res *= b;\n            res -= quo(res)\
      \ * g;\n            res.shrink();\n        }\n        b *= b;\n        b -=\
      \ quo(b) * g;\n        b.shrink();\n        k >>= 1;\n    }\n    return res;\n\
      }\n\n} // namespace kk2\n\n#endif // KK2_FPS_MOD_POW_HPP\n"
    name: default
  - code: "#line 1 \"fps/mod_pow.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                                     \
      \  or std::is_same<T, __int128>::value,\n                                  \
      \                 std::true_type,\n                                        \
      \           std::false_type>::type;\n\ntemplate <typename T>\nusing is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_integral =\n\
      \    typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_signed = typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                                         \
      \   std::true_type,\n                                            std::false_type>::type;\n\
      \ntemplate <typename T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T>\nusing to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
      \                              make_unsigned_int128<T>,\n                  \
      \            typename std::conditional<std::is_signed<T>::value,\n         \
      \                                               std::make_unsigned<T>,\n   \
      \                                                     std::common_type<T>>::type>::type;\n\
      \n#else\n\ntemplate <typename T> using is_integral = std::enable_if_t<std::is_integral<T>::value>;\n\
      template <typename T> using is_signed = std::enable_if_t<std::is_signed<T>::value>;\n\
      template <typename T> using is_unsigned = std::enable_if_t<std::is_unsigned<T>::value>;\n\
      template <typename T> using to_unsigned = std::make_unsigned<T>;\n\n#endif //\
      \ _MSC_VER\n\ntemplate <typename T> using is_integral_t = std::enable_if_t<is_integral<T>::value>;\n\
      template <typename T> using is_signed_t = std::enable_if_t<is_signed<T>::value>;\n\
      template <typename T> using is_unsigned_t = std::enable_if_t<is_unsigned<T>::value>;\n\
      \ntemplate <class T>\nconcept Integral = is_integral<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept SignedIntegral = is_signed<std::remove_cv_t<T>>::value;\n\
      \ntemplate <class T>\nconcept UnsignedIntegral = is_unsigned<std::remove_cv_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 7 \"fps/mod_pow.hpp\"\n\nnamespace kk2 {\n\n\
      // return f ^ k mod g\ntemplate <class FPS, class mint = typename FPS::value_type,\
      \ Integral T>\nFPS mod_pow(T k, const FPS &f, const FPS &g) {\n    // assert(!is_signed_v<T>\
      \ || k >= 0);\n    assert(!g.empty());\n\n    auto inv = g.rev().inv();\n  \
      \  auto quo = [&](const FPS &poly) {\n        if (poly.size() < g.size()) return\
      \ FPS{};\n        int n = poly.size() - g.size() + 1;\n        return (poly.rev().pre(n)\
      \ * inv.pre(n)).pre(n).rev();\n    };\n    FPS res{1}, b(f);\n    while (k)\
      \ {\n        if (k & 1) {\n            res *= b;\n            res -= quo(res)\
      \ * g;\n            res.shrink();\n        }\n        b *= b;\n        b -=\
      \ quo(b) * g;\n        b.shrink();\n        k >>= 1;\n    }\n    return res;\n\
      }\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/mod_pow.hpp
  pathExtension: hpp
  requiredBy:
  - fps/poly_find_root.hpp
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/inplace_operations.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
documentation_of: fps/mod_pow.hpp
layout: document
---
