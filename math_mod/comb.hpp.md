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
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/modint.hpp
    type: Depends on
  - files:
    - filename: poly_sample_point_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/detail/poly_sample_point_shift.hpp
    - filename: poly_sample_point_evaluate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_sample_point_evaluate.hpp
    - filename: poly_sample_point_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_sample_point_shift.hpp
    - filename: poly_taylor_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_taylor_shift.hpp
    - filename: power_sum.hpp
      icon: LIBRARY_ALL_AC
      path: fps/power_sum.hpp
      title: Power Sum
    - filename: bell_number.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/bell_number.hpp
    - filename: bernoulli_number.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/bernoulli_number.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    - filename: power_sum.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/power_sum.hpp
      title: Power Sum
    - filename: large_fact_arb_mod.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: poly_sample_point_shift.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    - filename: sum_of_exponential_times_polynomial_limit.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_others/sum_of_exponential_times_polynomial_limit.test.cpp
    type: Required by
  - files:
    - filename: poly_sample_point_evaluate.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
    - filename: sum_of_geometric_polynomial_samples.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sum_of_geometric_polynomial_samples.test.cpp
    - filename: sum_of_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sum_of_polynomial.test.cpp
    - filename: binom_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/binom_table.test.cpp
    - filename: comb_auto_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/comb_auto_extend.test.cpp
    - filename: inv_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/inv_table.test.cpp
    - filename: poly_taylor_shift.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_taylor_shift.test.cpp
    - filename: prefix_sum_of_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/prefix_sum_of_polynomial.test.cpp
    - filename: binomial_coefficient_prime_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: sum_of_exponential_times_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
    type: Verified with
  dependsOn:
  - common/type_alias.hpp
  - math_mod/inv_table.hpp
  - type_traits/integral.hpp
  - type_traits/modint.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MOD_COMB_HPP\n#define KK2_MATH_MOD_COMB_HPP 1\n\n#include\
      \ <algorithm>\n#include <cassert>\n#include <vector>\n\n#include \"../common/type_alias.hpp\"\
      \n#include \"../type_traits/integral.hpp\"\n#include \"../type_traits/modint.hpp\"\
      \n#include \"inv_table.hpp\"\n\nnamespace kk2 {\n\ntemplate <modint::Modular\
      \ mint> struct Comb {\n    static inline std::vector<mint> _fact{1}, _ifact{1};\n\
      \n    Comb() = delete;\n\n  private:\n    static void extend(usize m) {\n  \
      \      const usize n = _fact.size();\n        m = std::min<usize>(m, mint::getmod()\
      \ - 1);\n        _fact.reserve(m + 1);\n        _ifact.resize(m + 1);\n    \
      \    auto &_invs = InvTable<mint>::_invs;\n        if (_invs.size() <= m) _invs.resize(m\
      \ + 1);\n        for (usize i = n; i <= m; i++) _fact.emplace_back(_fact.back()\
      \ * i);\n        _ifact[m] = _fact[m].inv();\n        _invs[m] = _ifact[m] *\
      \ _fact[m - 1];\n        for (usize i = m; i > n; i--) {\n            _ifact[i\
      \ - 1] = _ifact[i] * i;\n            _invs[i - 1] = _ifact[i - 1] * _fact[i\
      \ - 2];\n        }\n    }\n\n    static void ensure(usize n) {\n        assert(n\
      \ < mint::getmod());\n        if (_fact.size() > n) return;\n        extend(std::max<usize>(n,\
      \ _fact.size() * 2));\n    }\n\n  public:\n    static void set_upper(usize n)\
      \ {\n        ensure(std::min<usize>(n, static_cast<usize>(mint::getmod() - 1)));\n\
      \    }\n\n    static mint fact(u32 n) {\n        ensure(static_cast<usize>(n));\n\
      \        return _fact[n];\n    }\n\n    static mint ifact(u32 n) {\n       \
      \ ensure(static_cast<usize>(n));\n        return _ifact[n];\n    }\n\n    static\
      \ mint inv(i32 n) {\n        assert(n != 0);\n        return InvTable<mint>::inv(n);\n\
      \    }\n\n    static mint binom(u32 n, u32 k) {\n        if (k > n) return 0;\n\
      \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <UnsignedIntegral\
      \ T> static mint multinomial(const std::vector<T> &r) {\n        u64 n = 0;\n\
      \        for (const T x : r) n += x;\n        assert(n < mint::getmod());\n\
      \        mint res = fact(static_cast<u32>(n));\n        for (const T x : r)\
      \ res *= ifact(static_cast<u32>(x));\n        return res;\n    }\n\n    static\
      \ mint binom_naive(u32 n, u32 k) {\n        if (k > n) return 0;\n        mint\
      \ res = 1;\n        k = std::min(k, n - k);\n        for (u32 i = 1; i <= k;\
      \ i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    static mint\
      \ permu(u32 n, u32 k) {\n        if (k > n) return 0;\n        return fact(n)\
      \ * ifact(n - k);\n    }\n\n    static mint homo(u32 n, u32 k) { return k ==\
      \ 0 ? 1 : binom(n + k - 1, k); }\n};\n\n} // namespace kk2\n\n#endif // KK2_MATH_MOD_COMB_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/comb.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
      #include <vector>\n\n#line 1 \"common/type_alias.hpp\"\n\n\n\n#include <cstddef>\n\
      #include <cstdint>\n\nnamespace kk2 {\n\nusing usize = std::size_t;\nusing i8\
      \ = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
      \ u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
      using i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\n#ifndef _MSC_VER\n\
      using i128 = __int128_t;\nusing u128 = __uint128_t;\n#endif\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\
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
      \n} // namespace kk2\n\n\n#line 1 \"type_traits/modint.hpp\"\n\n\n\n#include\
      \ <concepts>\n\n#line 7 \"type_traits/modint.hpp\"\n\nnamespace kk2::modint\
      \ {\n\ntemplate <class M>\nconcept Modular = requires(M x) {\n    requires Integral<decltype(M::getmod())>;\n\
      \    x.val();\n    { x.inv() } -> std::same_as<M>;\n};\n\n} // namespace kk2::modint\n\
      \n\n#line 1 \"math_mod/inv_table.hpp\"\n\n\n\n#line 6 \"math_mod/inv_table.hpp\"\
      \n\n#line 9 \"math_mod/inv_table.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief\
      \ `[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\u30C6\u30FC\u30D6\
      \u30EB\n *\n * @tparam mint\n */\ntemplate <class mint> struct InvTable {\n\
      \    static inline std::vector<mint> _invs{0, 1};\n    InvTable() = delete;\n\
      \n    static void set_upper(usize m) {\n        if (_invs.size() > m) return;\n\
      \        using index_type = std::make_unsigned_t<std::remove_cv_t<decltype(mint::getmod())>>;\n\
      \        const index_type start = static_cast<index_type>(_invs.size());\n \
      \       const index_type upper = static_cast<index_type>(m);\n        const\
      \ index_type mod = static_cast<index_type>(mint::getmod());\n        _invs.resize(m\
      \ + 1);\n        // p = q * i + r\n        // - q / r = 1 / i (mod p)\n    \
      \    for (index_type i = start; i <= upper; ++i) _invs[i] = (-_invs[mod % i])\
      \ * (mod / i);\n    }\n\n    template <UnsignedIntegral T> static inline mint\
      \ inv(T n) {\n        const usize index = static_cast<usize>(n);\n        if\
      \ (index >= _invs.size()) set_upper(index);\n        return _invs[index];\n\
      \    }\n\n    template <SignedIntegral T> static inline mint inv(T n) {\n  \
      \      using U = std::make_unsigned_t<T>;\n        if (n < 0) {\n          \
      \  // n + 1 is representable even when n is the minimum value.\n           \
      \ const U magnitude = static_cast<U>(-(n + 1)) + U(1);\n            return -inv(magnitude);\n\
      \        }\n        return inv(static_cast<U>(n));\n    }\n\n    static inline\
      \ mint inv_unchecked(usize n) { return _invs[n]; }\n};\n\n} // namespace kk2\n\
      \n\n#line 12 \"math_mod/comb.hpp\"\n\nnamespace kk2 {\n\ntemplate <modint::Modular\
      \ mint> struct Comb {\n    static inline std::vector<mint> _fact{1}, _ifact{1};\n\
      \n    Comb() = delete;\n\n  private:\n    static void extend(usize m) {\n  \
      \      const usize n = _fact.size();\n        m = std::min<usize>(m, mint::getmod()\
      \ - 1);\n        _fact.reserve(m + 1);\n        _ifact.resize(m + 1);\n    \
      \    auto &_invs = InvTable<mint>::_invs;\n        if (_invs.size() <= m) _invs.resize(m\
      \ + 1);\n        for (usize i = n; i <= m; i++) _fact.emplace_back(_fact.back()\
      \ * i);\n        _ifact[m] = _fact[m].inv();\n        _invs[m] = _ifact[m] *\
      \ _fact[m - 1];\n        for (usize i = m; i > n; i--) {\n            _ifact[i\
      \ - 1] = _ifact[i] * i;\n            _invs[i - 1] = _ifact[i - 1] * _fact[i\
      \ - 2];\n        }\n    }\n\n    static void ensure(usize n) {\n        assert(n\
      \ < mint::getmod());\n        if (_fact.size() > n) return;\n        extend(std::max<usize>(n,\
      \ _fact.size() * 2));\n    }\n\n  public:\n    static void set_upper(usize n)\
      \ {\n        ensure(std::min<usize>(n, static_cast<usize>(mint::getmod() - 1)));\n\
      \    }\n\n    static mint fact(u32 n) {\n        ensure(static_cast<usize>(n));\n\
      \        return _fact[n];\n    }\n\n    static mint ifact(u32 n) {\n       \
      \ ensure(static_cast<usize>(n));\n        return _ifact[n];\n    }\n\n    static\
      \ mint inv(i32 n) {\n        assert(n != 0);\n        return InvTable<mint>::inv(n);\n\
      \    }\n\n    static mint binom(u32 n, u32 k) {\n        if (k > n) return 0;\n\
      \        return fact(n) * ifact(k) * ifact(n - k);\n    }\n\n    template <UnsignedIntegral\
      \ T> static mint multinomial(const std::vector<T> &r) {\n        u64 n = 0;\n\
      \        for (const T x : r) n += x;\n        assert(n < mint::getmod());\n\
      \        mint res = fact(static_cast<u32>(n));\n        for (const T x : r)\
      \ res *= ifact(static_cast<u32>(x));\n        return res;\n    }\n\n    static\
      \ mint binom_naive(u32 n, u32 k) {\n        if (k > n) return 0;\n        mint\
      \ res = 1;\n        k = std::min(k, n - k);\n        for (u32 i = 1; i <= k;\
      \ i++) res *= inv(i) * (n--);\n        return res;\n    }\n\n    static mint\
      \ permu(u32 n, u32 k) {\n        if (k > n) return 0;\n        return fact(n)\
      \ * ifact(n - k);\n    }\n\n    static mint homo(u32 n, u32 k) { return k ==\
      \ 0 ? 1 : binom(n + k - 1, k); }\n};\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/comb.hpp
  pathExtension: hpp
  requiredBy:
  - fps/detail/poly_sample_point_shift.hpp
  - fps/poly_sample_point_evaluate.hpp
  - fps/poly_sample_point_shift.hpp
  - fps/poly_taylor_shift.hpp
  - fps/power_sum.hpp
  - math_mod/bell_number.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/comb_large.hpp
  - math_mod/power_sum.hpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_others/sum_of_exponential_times_polynomial_limit.test.cpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
  - verify/unit_test/fps/sum_of_geometric_polynomial_samples.test.cpp
  - verify/unit_test/fps/sum_of_polynomial.test.cpp
  - verify/unit_test/math_mod/binom_table.test.cpp
  - verify/unit_test/math_mod/comb_auto_extend.test.cpp
  - verify/unit_test/math_mod/inv_table.test.cpp
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_fps/prefix_sum_of_polynomial.test.cpp
  - verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
documentation_of: math_mod/comb.hpp
layout: document
---
