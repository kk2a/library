---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: convolution.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution.hpp
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: convolution_int.hpp
      icon: LIBRARY_NO_TESTS
      path: convolution/convolution_int.hpp
    - filename: multi_convolution_truncated.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/multi_convolution_truncated.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: math/group/rolling_hash.hpp
    - filename: is_prime.hpp
      icon: LIBRARY_ALL_AC
      path: math/is_prime.hpp
    - filename: euler_phi.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/euler_phi.hpp
    - filename: mobius.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/mobius.hpp
    - filename: sigma.hpp
      icon: LIBRARY_ALL_AC
      path: math/multiplicative_function/sigma.hpp
    - filename: prime_factorize.hpp
      icon: LIBRARY_ALL_AC
      path: math/prime_factorize.hpp
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: primitive_root_64bit.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root_64bit.hpp
    - filename: tetration.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/tetration.hpp
    - filename: hash.hpp
      icon: LIBRARY_ALL_AC
      path: random/hash.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
    - filename: static_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/static_rolling_hash.hpp
    - filename: parallel.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/parallel.hpp
    - filename: fps_exp_arb.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_fps/fps_exp_arb.test.cpp
    - filename: kth_term_of_linearly_recurrent_sequence.test.cpp
      icon: LIBRARY_NO_TESTS
      path: verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
    type: Required by
  - files:
    - filename: aoj_alds1_14_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    - filename: aoj_ntl_1_d.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_d.test.cpp
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: prime_factorize_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_factorize_table.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: convolution_arbitrary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    - filename: convolution_multi_truncated.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    - filename: convolution_ntt_friendly.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: fps_composition.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_composition.test.cpp
    - filename: fps_composition_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_composition_inv.test.cpp
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
    - filename: fps_multipoint_evaluation_geometric.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
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
    - filename: poly_interpolation_geometric.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_interpolation_geometric.test.cpp
    - filename: poly_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_inv.test.cpp
    - filename: poly_root_finding.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_root_finding.test.cpp
    - filename: poly_sample_point_shift.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_sample_point_shift.test.cpp
    - filename: poly_taylor_shift.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_taylor_shift.test.cpp
    - filename: poly_to_newton_basis.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_fps/poly_to_newton_basis.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: factrize.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/factrize.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: primality_test.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primality_test.test.cpp
    - filename: primitive_root.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primitive_root.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_MATH_MOD_POW_MOD_HPP\n#define KK2_MATH_MOD_POW_MOD_HPP 1\n\n\
      #include <cassert>\n\nnamespace kk2 {\n\ntemplate <class S, class T, class U>\
      \ constexpr S pow_mod(T x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1)\
      \ return S(0);\n    S _m = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y +=\
      \ _m;\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        if (n\
      \ >>= 1) y = (y * y) % _m;\n    }\n    return r;\n}\n\n} // namespace kk2\n\n\
      #endif // KK2_MATH_MOD_POW_MOD_HPP\n"
    name: default
  - code: "#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
      \ kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T x, U n,\
      \ T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m = m, r\
      \ = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n      \
      \  if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n  \
      \  }\n    return r;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: math_mod/pow_mod.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution.hpp
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - convolution/multi_convolution_truncated.hpp
  - fps/fps_arb.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - math/group/rolling_hash.hpp
  - math/is_prime.hpp
  - math/multiplicative_function/euler_phi.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/sigma.hpp
  - math/prime_factorize.hpp
  - math_mod/butterfly.hpp
  - math_mod/comb_large.hpp
  - math_mod/primitive_root.hpp
  - math_mod/primitive_root_64bit.hpp
  - math_mod/tetration.hpp
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - unionfind/parallel.hpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-09 01:16:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/prime_factorize_table.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp.test.cpp
  - verify/yosupo_fps/fps_inv.test.cpp
  - verify/yosupo_fps/fps_inv_arb.test.cpp
  - verify/yosupo_fps/fps_log.test.cpp
  - verify/yosupo_fps/fps_log_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
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
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_inv.test.cpp
  - verify/yosupo_fps/poly_root_finding.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_taylor_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: math_mod/pow_mod.hpp
layout: document
---
