---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
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
    - filename: lpf_power_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/lpf_power_table.hpp
    - filename: lpf_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/lpf_table.hpp
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
    - filename: mobius.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/mobius.hpp
    - filename: pow_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/pow_table.hpp
    - filename: prime_factorize_table.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_factorize_table.hpp
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
    - filename: inv_table.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv_table.hpp
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
    - filename: lpf_power_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_power_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    - filename: pow_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/pow_table.test.cpp
    - filename: prime_factorize_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_factorize_table.test.cpp
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
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    - filename: sum_of_exponential_times_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: '#ifndef KK2_COMMON_TYPE_ALIAS_HPP

      #define KK2_COMMON_TYPE_ALIAS_HPP 1


      #include <cstddef>

      #include <cstdint>


      namespace kk2 {


      using usize = std::size_t;

      using i8 = std::int8_t;

      using u8 = std::uint8_t;

      using i16 = std::int16_t;

      using u16 = std::uint16_t;

      using i32 = std::int32_t;

      using u32 = std::uint32_t;

      using i64 = std::int64_t;

      using u64 = std::uint64_t;


      #ifndef _MSC_VER

      using i128 = __int128_t;

      using u128 = __uint128_t;

      #endif


      } // namespace kk2


      #endif // KK2_COMMON_TYPE_ALIAS_HPP

      '
    name: default
  - code: '#line 1 "common/type_alias.hpp"




      #include <cstddef>

      #include <cstdint>


      namespace kk2 {


      using usize = std::size_t;

      using i8 = std::int8_t;

      using u8 = std::uint8_t;

      using i16 = std::int16_t;

      using u16 = std::uint16_t;

      using i32 = std::int32_t;

      using u32 = std::uint32_t;

      using i64 = std::int64_t;

      using u64 = std::uint64_t;


      #ifndef _MSC_VER

      using i128 = __int128_t;

      using u128 = __uint128_t;

      #endif


      } // namespace kk2



      '
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: common/type_alias.hpp
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
  - math/lpf_power_table.hpp
  - math/lpf_table.hpp
  - math/multiplicative_function/arbitrary_table.hpp
  - math/multiplicative_function/counting_square_free.hpp
  - math/multiplicative_function/famous_function.hpp
  - math/multiplicative_function/famous_function_table.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/pow_table.hpp
  - math/prime_factorize_table.hpp
  - math_mod/bell_number.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/comb.hpp
  - math_mod/comb_large.hpp
  - math_mod/inv_table.hpp
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
  - verify/unit_test/math/lpf_power_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/pow_table.test.cpp
  - verify/unit_test/math/prime_factorize_table.test.cpp
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
  - verify/yosupo_math/sum_of_totient_function.test.cpp
  - verify/yosupo_others/sum_of_exponential_times_polynomial.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: common/type_alias.hpp
layout: document
---
