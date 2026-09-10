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
    - filename: poly_taylor_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_taylor_shift.hpp
    - filename: bell_number.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/bell_number.hpp
    - filename: bernoulli_number.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/bernoulli_number.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    type: Required by
  - files:
    - filename: binom_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/binom_table.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: poly_taylor_shift.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_taylor_shift.test.cpp
    - filename: binomial_coefficient_prime_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MOD_COMB_HPP\n#define KK2_MATH_MOD_COMB_HPP 1\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#include \"../type_traits/integral.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class mint> struct Comb {\n    static inline\
      \ std::vector<mint> _fact{1}, _ifact{1}, _inv{1};\n\n    Comb() = delete;\n\n\
      \    static void set_upper(int m = -1) {\n        int n = (int)_fact.size();\n\
      \        if (m == -1) m = n << 1;\n        if (n > m) return;\n        m = std::min<long\
      \ long>(m, mint::getmod() - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m\
      \ + 1);\n        _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i]\
      \ = _fact[i - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m]\
      \ = _ifact[m] * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n     \
      \       _ifact[i - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i -\
      \ 1] * _fact[i - 2];\n        }\n    }\n\n    static mint fact(int n) {\n  \
      \      if (n < 0) return 0;\n        if ((int)_fact.size() <= n) set_upper(n);\n\
      \        return _fact[n];\n    }\n\n    static mint ifact(int n) {\n       \
      \ if (n < 0) return 0;\n        if ((int)_ifact.size() <= n) set_upper(n);\n\
      \        return _ifact[n];\n    }\n\n    static mint inv(int n) {\n        if\
      \ (n < 0) return -inv(-n);\n        if ((int)_inv.size() <= n) set_upper(n);\n\
      \        return _inv[n];\n    }\n\n    static mint binom(int n, int k) {\n \
      \       if (k < 0 || k > n) return 0;\n        return fact(n) * ifact(k) * ifact(n\
      \ - k);\n    }\n\n    template <Integral T> static mint multinomial(const std::vector<T>\
      \ &r) {\n        int n = 0;\n        for (auto &x : r) {\n            if (x\
      \ < 0) return 0;\n            n += x;\n        }\n        mint res = fact(n);\n\
      \        for (auto &x : r) res *= ifact(x);\n        return res;\n    }\n\n\
      \    static mint binom_naive(int n, int k) {\n        if (n < 0 || k < 0 ||\
      \ k > n) return 0;\n        mint res = 1;\n        k = std::min(k, n - k);\n\
      \        for (int i = 1; i <= k; i++) res *= inv(i) * (n--);\n        return\
      \ res;\n    }\n\n    static mint permu(int n, int k) {\n        if (n < 0 ||\
      \ k < 0 || k > n) return 0;\n        return fact(n) * ifact(n - k);\n    }\n\
      \n    static mint homo(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n\
      \        return k == 0 ? 1 : binom(n + k - 1, k);\n    }\n};\n\n} // namespace\
      \ kk2\n\n#endif // KK2_MATH_MOD_COMB_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/comb.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <vector>\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\
      \nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
      \ = typename std::conditional<std::is_same<T, __int128_t>::value\n         \
      \                                              or std::is_same<T, __int128>::value,\n\
      \                                                   std::true_type,\n      \
      \                                             std::false_type>::type;\n\ntemplate\
      \ <typename T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __uint128_t>::value\n                                  or std::is_same<T,\
      \ unsigned __int128>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
      \ or is_signed_int128<T>::value\n                                  or is_unsigned_int128<T>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T>\nusing is_signed = typename\
      \ std::conditional<std::is_signed<T>::value or is_signed_int128<T>::value,\n\
      \                                            std::true_type,\n             \
      \                               std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
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
      \n} // namespace kk2\n\n\n#line 9 \"math_mod/comb.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <class mint> struct Comb {\n    static inline std::vector<mint> _fact{1},\
      \ _ifact{1}, _inv{1};\n\n    Comb() = delete;\n\n    static void set_upper(int\
      \ m = -1) {\n        int n = (int)_fact.size();\n        if (m == -1) m = n\
      \ << 1;\n        if (n > m) return;\n        m = std::min<long long>(m, mint::getmod()\
      \ - 1);\n        _fact.resize(m + 1);\n        _ifact.resize(m + 1);\n     \
      \   _inv.resize(m + 1);\n        for (int i = n; i <= m; i++) _fact[i] = _fact[i\
      \ - 1] * i;\n        _ifact[m] = _fact[m].inv();\n        _inv[m] = _ifact[m]\
      \ * _fact[m - 1];\n        for (int i = m; i > n; i--) {\n            _ifact[i\
      \ - 1] = _ifact[i] * i;\n            _inv[i - 1] = _ifact[i - 1] * _fact[i -\
      \ 2];\n        }\n    }\n\n    static mint fact(int n) {\n        if (n < 0)\
      \ return 0;\n        if ((int)_fact.size() <= n) set_upper(n);\n        return\
      \ _fact[n];\n    }\n\n    static mint ifact(int n) {\n        if (n < 0) return\
      \ 0;\n        if ((int)_ifact.size() <= n) set_upper(n);\n        return _ifact[n];\n\
      \    }\n\n    static mint inv(int n) {\n        if (n < 0) return -inv(-n);\n\
      \        if ((int)_inv.size() <= n) set_upper(n);\n        return _inv[n];\n\
      \    }\n\n    static mint binom(int n, int k) {\n        if (k < 0 || k > n)\
      \ return 0;\n        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n  \
      \  template <Integral T> static mint multinomial(const std::vector<T> &r) {\n\
      \        int n = 0;\n        for (auto &x : r) {\n            if (x < 0) return\
      \ 0;\n            n += x;\n        }\n        mint res = fact(n);\n        for\
      \ (auto &x : r) res *= ifact(x);\n        return res;\n    }\n\n    static mint\
      \ binom_naive(int n, int k) {\n        if (n < 0 || k < 0 || k > n) return 0;\n\
      \        mint res = 1;\n        k = std::min(k, n - k);\n        for (int i\
      \ = 1; i <= k; i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n \
      \   static mint permu(int n, int k) {\n        if (n < 0 || k < 0 || k > n)\
      \ return 0;\n        return fact(n) * ifact(n - k);\n    }\n\n    static mint\
      \ homo(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n        return\
      \ k == 0 ? 1 : binom(n + k - 1, k);\n    }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/comb.hpp
  pathExtension: hpp
  requiredBy:
  - fps/poly_taylor_shift.hpp
  - math_mod/bell_number.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/comb_large.hpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/math_mod/binom_table.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
documentation_of: math_mod/comb.hpp
layout: document
---
