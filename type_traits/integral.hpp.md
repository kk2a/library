---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files: []
    type: Depends on
  - files:
    - filename: int256.hpp
      icon: LIBRARY_NO_TESTS
      path: bigint/int256.hpp
    - filename: bitcount.hpp
      icon: LIBRARY_ALL_AC
      path: bit/bitcount.hpp
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: convolution_int.hpp
      icon: LIBRARY_NO_TESTS
      path: convolution/convolution_int.hpp
    - filename: bit_vector.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/bit_vector.hpp
    - filename: convex_hull_trick_add_monotone.hpp
      icon: LIBRARY_NO_TESTS
      path: data_structure/convex_hull_trick_add_monotone.hpp
    - filename: my_bitset.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/my_bitset.hpp
    - filename: w_ary_tree.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/w_ary_tree.hpp
    - filename: wavelet_matrix.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/wavelet_matrix.hpp
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: fps_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sqrt.hpp
    - filename: poly_taylor_shift.hpp
      icon: LIBRARY_ALL_AC
      path: fps/poly_taylor_shift.hpp
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
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/mod_sqrt.hpp
    - filename: primitive_root_64bit.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root_64bit.hpp
    - filename: tetration.hpp
      icon: LIBRARY_NO_TESTS
      path: math_mod/tetration.hpp
    - filename: matrix_F2.hpp
      icon: LIBRARY_ALL_AC
      path: matrix/matrix_F2.hpp
    - filename: F2.hpp
      icon: LIBRARY_ALL_AC
      path: modint/F2.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: modint/modint.hpp
    - filename: modint_2_61m1.hpp
      icon: LIBRARY_ALL_AC
      path: modint/modint_2_61m1.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: mont_arb.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont_arb.hpp
    - filename: hash.hpp
      icon: LIBRARY_ALL_AC
      path: random/hash.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
    - filename: static_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/static_rolling_hash.hpp
    - filename: fastio.hpp
      icon: LIBRARY_ALL_AC
      path: template/fastio.hpp
    - filename: template.hpp
      icon: LIBRARY_ALL_AC
      path: template/template.hpp
    - filename: parallel.hpp
      icon: LIBRARY_ALL_AC
      path: unionfind/parallel.hpp
    - filename: aoj_alds1_14_b.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/aoj/aoj_alds1_14_b.test.cpp
    - filename: ds_dynamic_sequence_range_affine_range_sum.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
    - filename: ds_point_set_range_composite_large_2.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
    - filename: ds_potentiailized_uf_non_commutattive.test.cpp
      icon: LIBRARY_ALL_AC
      path: verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
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
    type: Required by
  - files:
    - filename: aoj_0233.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_0233.test.cpp
    - filename: aoj_0560.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_0560.test.cpp
    - filename: aoj_0560_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_0560_2.test.cpp
    - filename: aoj_grl_1_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_b.test.cpp
    - filename: aoj_grl_1_c.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_grl_1_c.test.cpp
    - filename: aoj_ntl_1_d.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_d.test.cpp
    - filename: aoj_ntl_1_e.test.cpp
      icon: TEST_ACCEPTED
      path: verify/aoj/aoj_ntl_1_e.test.cpp
    - filename: bit_vector.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/bit_vector.test.cpp
    - filename: offline_dynamic_connectivity.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
    - filename: wavelet_matrix.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
    - filename: sparsity_boundary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_boundary.test.cpp
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
    - filename: action.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/action/action.test.cpp
    - filename: group.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/group/group.test.cpp
    - filename: isprime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/isprime_table_extend.test.cpp
    - filename: lpf_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/lpf_table_extend.test.cpp
    - filename: monoid.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/monoid/monoid.test.cpp
    - filename: famous_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
    - filename: multiplicative_function_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
    - filename: prime_factorize_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_factorize_table.test.cpp
    - filename: prime_table_extend.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/prime_table_extend.test.cpp
    - filename: rational.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math/rational.test.cpp
    - filename: binom_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/binom_table.test.cpp
    - filename: inv_table.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/inv_table.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: F2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/modint/F2.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
    - filename: static_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/static_rolling_hash.test.cpp
    - filename: algebra.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/algebra/algebra.test.cpp
    - filename: concepts.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/concepts.test.cpp
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    - filename: partial_persitent_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
    - filename: convolution_and.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_and.test.cpp
    - filename: convolution_arbitrary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_arbitrary.test.cpp
    - filename: convolution_gcd.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_gcd.test.cpp
    - filename: convolution_lcm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_lcm.test.cpp
    - filename: convolution_multi_truncated.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_multi_truncated.test.cpp
    - filename: convolution_ntt_friendly.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
    - filename: convolution_or.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_or.test.cpp
    - filename: convolution_subset.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_subset.test.cpp
    - filename: convolution_xor.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_convolution/convolution_xor.test.cpp
    - filename: ds_ordered_set_binary_trie.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
    - filename: ds_ordered_set_max_right.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
    - filename: ds_ordered_set_min_left.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
    - filename: ds_point_add_range_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_add_range_sum_2.test.cpp
    - filename: ds_point_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite.test.cpp
    - filename: ds_point_set_range_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
    - filename: ds_potentialized_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
    - filename: ds_predecessor_problem.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_predecessor_problem.test.cpp
    - filename: ds_range_affine_range_sum.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
    - filename: ds_range_affine_range_sum_large_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
    - filename: ds_range_kth_smallest.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_kth_smallest.test.cpp
    - filename: ds_range_parallel_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
    - filename: ds_range_set_range_composite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_set_range_composite.test.cpp
    - filename: ds_segment_add_get_min.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_segment_add_get_min.test.cpp
    - filename: ds_segment_add_get_min2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_segment_add_get_min2.test.cpp
    - filename: ds_set_xor_min.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_set_xor_min.test.cpp
    - filename: ds_static_range_inversions.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_range_inversions.test.cpp
    - filename: ds_static_range_sum.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_range_sum.test.cpp
    - filename: ds_static_rmq.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq.test.cpp
    - filename: ds_static_rmq_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_static_rmq_2.test.cpp
    - filename: ds_unionfind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_unionfind.test.cpp
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
    - filename: arg_sort.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/arg_sort.test.cpp
    - filename: static_convex_hull.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull.test.cpp
    - filename: static_convex_hull_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_1.test.cpp
    - filename: static_convex_hull_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_2.test.cpp
    - filename: static_convex_hull_3.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_geometry/static_convex_hull_3.test.cpp
    - filename: graph_bcc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_bcc.test.cpp
    - filename: graph_cycle_detection.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection.test.cpp
    - filename: graph_cycle_detection_directed.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
    - filename: graph_enumerate_triangle.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_enumerate_triangle.test.cpp
    - filename: graph_matching_bipartite.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_matching_bipartite.test.cpp
    - filename: graph_minimum_spanning_tree.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
    - filename: graph_scc.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_scc.test.cpp
    - filename: graph_shortest_path.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_shortest_path.test.cpp
    - filename: graph_two_edge_connected_components.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
    - filename: tree_cartesian.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_cartesian.test.cpp
    - filename: tree_diameter.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_diameter.test.cpp
    - filename: tree_lca.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca.test.cpp
    - filename: tree_lca_static.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_lca_static.test.cpp
    - filename: tree_vertex_add_path_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
    - filename: tree_vertex_add_path_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
    - filename: tree_vertex_add_subtree_sum_1.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
    - filename: tree_vertex_add_subtree_sum_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
    - filename: tree_vertex_set_path_composite_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
    - filename: matrix_det.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_det.test.cpp
    - filename: matrix_det_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    - filename: matrix_inv.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_inv.test.cpp
    - filename: matrix_inv_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    - filename: matrix_pow.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_pow.test.cpp
    - filename: matrix_product.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_product.test.cpp
    - filename: matrix_product_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    - filename: matrix_rank.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_rank.test.cpp
    - filename: matrix_rank_F2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_rank_F2.test.cpp
    - filename: solution_of_linear_equations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/solution_of_linear_equations.test.cpp
    - filename: solution_of_linear_equations_F2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    - filename: binomial_coefficient_prime_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
    - filename: discrete_logarithm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/discrete_logarithm.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: enumerate_primes.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_primes.test.cpp
    - filename: enumerate_quotients.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_quotients.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: factrize.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/factrize.test.cpp
    - filename: kth_root_int.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/kth_root_int.test.cpp
    - filename: kth_root_int_ceil.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/kth_root_int_ceil.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: prefix_sum_of_multiplicative_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
    - filename: primality_test.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primality_test.test.cpp
    - filename: prime_counting.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/prime_counting.test.cpp
    - filename: primitive_root.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/primitive_root.test.cpp
    - filename: rational_approximation.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/rational_approximation.test.cpp
    - filename: sqrt_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sqrt_mod.test.cpp
    - filename: stern_brocot_tree.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/stern_brocot_tree.test.cpp
    - filename: sum_of_floor_linear.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_floor_linear.test.cpp
    - filename: sum_of_totient_function.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/sum_of_totient_function.test.cpp
    - filename: longest_increasing_subsequence.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/longest_increasing_subsequence.test.cpp
    - filename: many_a_plus_b.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/many_a_plus_b.test.cpp
    - filename: many_a_plus_b_128bit.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_others/many_a_plus_b_128bit.test.cpp
    - filename: string_number_of_substrings.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_number_of_substrings.test.cpp
    - filename: string_suffix_array.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_suffix_array.test.cpp
    - filename: string_z_algorithm.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_algorithm.test.cpp
    - filename: string_z_roliha.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_string/string_z_roliha.test.cpp
    - filename: yuki_0430.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_0430.test.cpp
    - filename: yuki_0430_2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_0430_2.test.cpp
    - filename: yuki_1326.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1326.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_INTERGRAL_HPP\n#define KK2_TYPE_TRAITS_INTERGRAL_HPP\
      \ 1\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
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
      \n} // namespace kk2\n\n#endif // KK2_TYPE_TRAITS_INTERGRAL_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/integral.hpp\"\n\n\n\n#include <type_traits>\n\n\
      namespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate <typename T>\nusing is_signed_int128\
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
      \n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/integral.hpp
  pathExtension: hpp
  requiredBy:
  - bigint/int256.hpp
  - bit/bitcount.hpp
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - data_structure/bit_vector.hpp
  - data_structure/convex_hull_trick_add_monotone.hpp
  - data_structure/my_bitset.hpp
  - data_structure/w_ary_tree.hpp
  - data_structure/wavelet_matrix.hpp
  - fps/fps_arb.hpp
  - fps/fps_sqrt.hpp
  - fps/poly_taylor_shift.hpp
  - math/group/rolling_hash.hpp
  - math/is_prime.hpp
  - math/multiplicative_function/euler_phi.hpp
  - math/multiplicative_function/mobius.hpp
  - math/multiplicative_function/sigma.hpp
  - math/prime_factorize.hpp
  - math_mod/bell_number.hpp
  - math_mod/bernoulli_number.hpp
  - math_mod/comb.hpp
  - math_mod/comb_large.hpp
  - math_mod/mod_sqrt.hpp
  - math_mod/primitive_root_64bit.hpp
  - math_mod/tetration.hpp
  - matrix/matrix_F2.hpp
  - modint/F2.hpp
  - modint/modint.hpp
  - modint/modint_2_61m1.hpp
  - modint/mont.hpp
  - modint/mont_arb.hpp
  - random/hash.hpp
  - string/dynamic_rolling_hash.hpp
  - string/static_rolling_hash.hpp
  - template/fastio.hpp
  - template/template.hpp
  - unionfind/parallel.hpp
  - verify/aoj/aoj_alds1_14_b.test.cpp
  - verify/yosupo_ds/ds_dynamic_sequence_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_large_2.test.cpp
  - verify/yosupo_ds/ds_potentiailized_uf_non_commutattive.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-11 00:30:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_0233.test.cpp
  - verify/aoj/aoj_0560.test.cpp
  - verify/aoj/aoj_0560_2.test.cpp
  - verify/aoj/aoj_grl_1_b.test.cpp
  - verify/aoj/aoj_grl_1_c.test.cpp
  - verify/aoj/aoj_ntl_1_d.test.cpp
  - verify/aoj/aoj_ntl_1_e.test.cpp
  - verify/unit_test/data_structure/bit_vector.test.cpp
  - verify/unit_test/data_structure/offline_dynamic_connectivity.test.cpp
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/math/action/action.test.cpp
  - verify/unit_test/math/group/group.test.cpp
  - verify/unit_test/math/isprime_table_extend.test.cpp
  - verify/unit_test/math/lpf_table_extend.test.cpp
  - verify/unit_test/math/monoid/monoid.test.cpp
  - verify/unit_test/math/multiplicative_function/famous_function_table.test.cpp
  - verify/unit_test/math/multiplicative_function/multiplicative_function_table.test.cpp
  - verify/unit_test/math/prime_factorize_table.test.cpp
  - verify/unit_test/math/prime_table_extend.test.cpp
  - verify/unit_test/math/rational.test.cpp
  - verify/unit_test/math_mod/binom_table.test.cpp
  - verify/unit_test/math_mod/inv_table.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/modint/F2.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/string/static_rolling_hash.test.cpp
  - verify/unit_test/type_traits/algebra/algebra.test.cpp
  - verify/unit_test/type_traits/concepts.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/unit_test/unionfind/partial_persitent_unionfind.test.cpp
  - verify/yosupo_convolution/convolution_and.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_gcd.test.cpp
  - verify/yosupo_convolution/convolution_lcm.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_convolution/convolution_or.test.cpp
  - verify/yosupo_convolution/convolution_subset.test.cpp
  - verify/yosupo_convolution/convolution_xor.test.cpp
  - verify/yosupo_ds/ds_ordered_set_binary_trie.test.cpp
  - verify/yosupo_ds/ds_ordered_set_max_right.test.cpp
  - verify/yosupo_ds/ds_ordered_set_min_left.test.cpp
  - verify/yosupo_ds/ds_point_add_range_sum_2.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_point_set_range_composite_2.test.cpp
  - verify/yosupo_ds/ds_potentialized_unionfind.test.cpp
  - verify/yosupo_ds/ds_predecessor_problem.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum.test.cpp
  - verify/yosupo_ds/ds_range_affine_range_sum_large_2.test.cpp
  - verify/yosupo_ds/ds_range_kth_smallest.test.cpp
  - verify/yosupo_ds/ds_range_parallel_unionfind.test.cpp
  - verify/yosupo_ds/ds_range_set_range_composite.test.cpp
  - verify/yosupo_ds/ds_segment_add_get_min.test.cpp
  - verify/yosupo_ds/ds_segment_add_get_min2.test.cpp
  - verify/yosupo_ds/ds_set_xor_min.test.cpp
  - verify/yosupo_ds/ds_static_range_inversions.test.cpp
  - verify/yosupo_ds/ds_static_range_sum.test.cpp
  - verify/yosupo_ds/ds_static_rmq.test.cpp
  - verify/yosupo_ds/ds_static_rmq_2.test.cpp
  - verify/yosupo_ds/ds_unionfind.test.cpp
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
  - verify/yosupo_geometry/arg_sort.test.cpp
  - verify/yosupo_geometry/static_convex_hull.test.cpp
  - verify/yosupo_geometry/static_convex_hull_1.test.cpp
  - verify/yosupo_geometry/static_convex_hull_2.test.cpp
  - verify/yosupo_geometry/static_convex_hull_3.test.cpp
  - verify/yosupo_graph/graph_bcc.test.cpp
  - verify/yosupo_graph/graph_cycle_detection.test.cpp
  - verify/yosupo_graph/graph_cycle_detection_directed.test.cpp
  - verify/yosupo_graph/graph_enumerate_triangle.test.cpp
  - verify/yosupo_graph/graph_matching_bipartite.test.cpp
  - verify/yosupo_graph/graph_minimum_spanning_tree.test.cpp
  - verify/yosupo_graph/graph_scc.test.cpp
  - verify/yosupo_graph/graph_shortest_path.test.cpp
  - verify/yosupo_graph/graph_two_edge_connected_components.test.cpp
  - verify/yosupo_graph/tree_cartesian.test.cpp
  - verify/yosupo_graph/tree_diameter.test.cpp
  - verify/yosupo_graph/tree_lca.test.cpp
  - verify/yosupo_graph/tree_lca_static.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_path_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_1.test.cpp
  - verify/yosupo_graph/tree_vertex_add_subtree_sum_2.test.cpp
  - verify/yosupo_graph/tree_vertex_set_path_composite_2.test.cpp
  - verify/yosupo_linalg/matrix_det.test.cpp
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_inv.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - verify/yosupo_linalg/matrix_pow.test.cpp
  - verify/yosupo_linalg/matrix_product.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/matrix_rank.test.cpp
  - verify/yosupo_linalg/matrix_rank_F2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_math/binomial_coefficient_prime_mod.test.cpp
  - verify/yosupo_math/discrete_logarithm.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_primes.test.cpp
  - verify/yosupo_math/enumerate_quotients.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/factrize.test.cpp
  - verify/yosupo_math/kth_root_int.test.cpp
  - verify/yosupo_math/kth_root_int_ceil.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yosupo_math/prefix_sum_of_multiplicative_function.test.cpp
  - verify/yosupo_math/primality_test.test.cpp
  - verify/yosupo_math/prime_counting.test.cpp
  - verify/yosupo_math/primitive_root.test.cpp
  - verify/yosupo_math/rational_approximation.test.cpp
  - verify/yosupo_math/sqrt_mod.test.cpp
  - verify/yosupo_math/stern_brocot_tree.test.cpp
  - verify/yosupo_math/sum_of_floor_linear.test.cpp
  - verify/yosupo_math/sum_of_totient_function.test.cpp
  - verify/yosupo_others/longest_increasing_subsequence.test.cpp
  - verify/yosupo_others/many_a_plus_b.test.cpp
  - verify/yosupo_others/many_a_plus_b_128bit.test.cpp
  - verify/yosupo_string/string_number_of_substrings.test.cpp
  - verify/yosupo_string/string_suffix_array.test.cpp
  - verify/yosupo_string/string_z_algorithm.test.cpp
  - verify/yosupo_string/string_z_roliha.test.cpp
  - verify/yuki/yuki_0430.test.cpp
  - verify/yuki/yuki_0430_2.test.cpp
  - verify/yuki/yuki_1326.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: type_traits/integral.hpp
layout: document
---
