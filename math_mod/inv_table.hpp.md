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
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    type: Depends on
  - files:
    - filename: poly_sample_point_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/detail/poly_sample_point_shift.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: fps_base.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_base.hpp
    - filename: fps_bivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_bivariate.hpp
    - filename: fps_egf.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_egf.hpp
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: fps_sps.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sps.hpp
    - filename: logarithm.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/logarithm.hpp
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
    - filename: comb.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb.hpp
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
    - filename: fps_composition.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_composition.test.cpp
    - filename: fps_composition_inv.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_composition_inv.test.cpp
    - filename: fps_exp_arb.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_fps/fps_exp_arb.test.cpp
    - filename: fps_multipoint_evaluation_geometric.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
    - filename: poly_interpolation_geometric.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_interpolation_geometric.test.cpp
    - filename: poly_sample_point_shift.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    - filename: poly_to_newton_basis.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_fps/poly_to_newton_basis.test.cpp
    - filename: kth_term_of_linearly_recurrent_sequence.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
    - filename: sum_of_exponential_times_polynomial_limit.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_others/sum_of_exponential_times_polynomial_limit.test.cpp
    type: Required by
  - files:
    - filename: inplace_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/inplace_operations.test.cpp
    - filename: multivariate_convolution.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_convolution.test.cpp
    - filename: multivariate_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_operations.test.cpp
    - filename: poly_sample_point_evaluate.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
    - filename: sparsity_boundary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_boundary.test.cpp
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
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
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: fps_exp.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_exp.test.cpp
    - filename: fps_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_inv.test.cpp
    - filename: fps_inv_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_inv_arb.test.cpp
    - filename: fps_log.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_log.test.cpp
    - filename: fps_log_arb.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_log_arb.test.cpp
    - filename: fps_multipoint_evaluation.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
    - filename: fps_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_pow.test.cpp
    - filename: fps_product_of_polynomial_sequence.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
    - filename: fps_sparse_exp.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_exp.test.cpp
    - filename: fps_sparse_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_inv.test.cpp
    - filename: fps_sparse_log.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_log.test.cpp
    - filename: fps_sparse_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sparse_pow.test.cpp
    - filename: fps_sprase_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sprase_sqrt.test.cpp
    - filename: fps_sqrt.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_sqrt.test.cpp
    - filename: poly_division.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_division.test.cpp
    - filename: poly_interpolation.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_interpolation.test.cpp
    - filename: poly_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_inv.test.cpp
    - filename: poly_root_finding.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_root_finding.test.cpp
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
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: sum_of_exponential_times_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn:
  - common/type_alias.hpp
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_MATH_MOD_INV_TABLE_HPP\n#define KK2_MATH_MOD_INV_TABLE_HPP\
      \ 1\n\n#include <type_traits>\n#include <vector>\n\n#include \"../common/type_alias.hpp\"\
      \n#include \"../type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n/**\n * @brief\
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
      \n#endif // KK2_MATH_MOD_INV_TABLE_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/inv_table.hpp\"\n\n\n\n#include <type_traits>\n#include\
      \ <vector>\n\n#line 1 \"common/type_alias.hpp\"\n\n\n\n#include <cstddef>\n\
      #include <cstdint>\n\nnamespace kk2 {\n\nusing usize = std::size_t;\nusing i8\
      \ = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
      \ u16 = std::uint16_t;\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
      using i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\n#ifndef _MSC_VER\n\
      using i128 = __int128_t;\nusing u128 = __uint128_t;\n#endif\n\n} // namespace\
      \ kk2\n\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n#line 5 \"type_traits/integral.hpp\"\
      \n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
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
      \n} // namespace kk2\n\n\n#line 9 \"math_mod/inv_table.hpp\"\n\nnamespace kk2\
      \ {\n\n/**\n * @brief `[1, n]`\u306Emod\u9006\u5143\u3092\u5217\u6319\u3059\u308B\
      \u30C6\u30FC\u30D6\u30EB\n *\n * @tparam mint\n */\ntemplate <class mint> struct\
      \ InvTable {\n    static inline std::vector<mint> _invs{0, 1};\n    InvTable()\
      \ = delete;\n\n    static void set_upper(usize m) {\n        if (_invs.size()\
      \ > m) return;\n        using index_type = std::make_unsigned_t<std::remove_cv_t<decltype(mint::getmod())>>;\n\
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
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/inv_table.hpp
  pathExtension: hpp
  requiredBy:
  - fps/detail/poly_sample_point_shift.hpp
  - fps/fps_arb.hpp
  - fps/fps_base.hpp
  - fps/fps_bivariate.hpp
  - fps/fps_egf.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/fps_sps.hpp
  - fps/operations/logarithm.hpp
  - fps/poly_sample_point_evaluate.hpp
  - fps/poly_sample_point_shift.hpp
  - fps/poly_taylor_shift.hpp
  - fps/power_sum.hpp
  - math_mod/bell_number.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/comb.hpp
  - math_mod/comb_large.hpp
  - math_mod/power_sum.hpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - verify/yosupo_others/sum_of_exponential_times_polynomial_limit.test.cpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/inplace_operations.test.cpp
  - verify/unit_test/fps/multivariate_convolution.test.cpp
  - verify/unit_test/fps/multivariate_operations.test.cpp
  - verify/unit_test/fps/poly_sample_point_evaluate.test.cpp
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/fps/sum_of_geometric_polynomial_samples.test.cpp
  - verify/unit_test/fps/sum_of_polynomial.test.cpp
  - verify/unit_test/math_mod/binom_table.test.cpp
  - verify/unit_test/math_mod/comb_auto_extend.test.cpp
  - verify/unit_test/math_mod/inv_table.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
  - verify/yosupo_fps/fps_pow.test.cpp
  - verify/yosupo_fps/fps_product_of_polynomial_sequence.test.cpp
  - verify/yosupo_fps/fps_sparse_exp.test.cpp
  - verify/yosupo_fps/fps_sparse_inv.test.cpp
  - verify/yosupo_fps/fps_sparse_log.test.cpp
  - verify/yosupo_fps/fps_sparse_pow.test.cpp
  - verify/yosupo_fps/fps_sprase_sqrt.test.cpp
  - verify/yosupo_fps/fps_sqrt.test.cpp
  - verify/yosupo_fps/poly_division.test.cpp
  - verify/yosupo_fps/poly_interpolation.test.cpp
  - verify/yosupo_fps/poly_inv.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_fps/prefix_sum_of_polynomial.test.cpp
  - verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: math_mod/inv_table.hpp
layout: document
---
