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
    - filename: bit_vector.hpp
      icon: LIBRARY_ALL_AC
      path: data_structure/bit_vector.hpp
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
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
    - filename: matrix_F2.hpp
      icon: LIBRARY_ALL_AC
      path: matrix/matrix_F2.hpp
    - filename: dynamic_rolling_hash.hpp
      icon: LIBRARY_ALL_AC
      path: string/dynamic_rolling_hash.hpp
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
    - filename: bit_vector.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/bit_vector.test.cpp
    - filename: wavelet_matrix.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/data_structure/wavelet_matrix.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
    - filename: dynamic_rolling_hash.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/string/dynamic_rolling_hash.test.cpp
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
    - filename: ds_predecessor_problem.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_predecessor_problem.test.cpp
    - filename: ds_range_kth_smallest.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_ds/ds_range_kth_smallest.test.cpp
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
    - filename: matrix_det_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_det_f2.test.cpp
    - filename: matrix_inv_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_inv_f2.test.cpp
    - filename: matrix_product_f2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_product_f2.test.cpp
    - filename: matrix_rank_F2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/matrix_rank_F2.test.cpp
    - filename: solution_of_linear_equations_F2.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
    - filename: enumerate_bell_number.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_bell_number.test.cpp
    - filename: enumerate_stirling_number_of_the_first_kind.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
    - filename: many_factrials.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yosupo_math/many_factrials.test.cpp
    - filename: yuki_1510.test.cpp
      icon: TEST_ACCEPTED
      path: verify/yuki/yuki_1510.test.cpp
    type: Verified with
  dependsOn:
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_BIT_BITCOUNT_HPP\n#define KK2_BIT_BITCOUNT_HPP 1\n\n#include\
      \ <cassert>\n\n#include \"../type_traits/integral.hpp\"\n\nnamespace kk2 {\n\
      \ntemplate <Integral T> constexpr int ctz(T x) {\n    assert(x != T(0));\n\n\
      \    if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n   \
      \ } else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
      \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
      \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
      \ long long)(x >> 64));\n    }\n}\n\ntemplate <Integral T> constexpr int lsb(T\
      \ x) {\n    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <Integral\
      \ T> constexpr int clz(T x) {\n    assert(x != T(0));\n\n    if constexpr (sizeof(T)\
      \ <= 4) {\n        return __builtin_clz(x);\n    } else if constexpr (sizeof(T)\
      \ <= 8) {\n        return __builtin_clzll(x);\n    } else {\n        if (x >>\
      \ 64) return __builtin_clzll((unsigned long long)(x >> 64));\n        return\
      \ 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n    }\n\
      }\n\ntemplate <Integral T> constexpr int msb(T x) {\n    assert(x != T(0));\n\
      \n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate <Integral T> constexpr\
      \ int popcount(T x) {\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
      \ __builtin_popcount(x);\n    } else if constexpr (sizeof(T) <= 8) {\n     \
      \   return __builtin_popcountll(x);\n    } else {\n        return __builtin_popcountll((unsigned\
      \ long long)(x >> 64))\n               + __builtin_popcountll((unsigned long\
      \ long)(x & 0xffffffffffffffff));\n    }\n}\n\n}; // namespace kk2\n\n#endif\
      \ // KK2_BIT_BITCOUNT_HPP\n"
    name: default
  - code: "#line 1 \"bit/bitcount.hpp\"\n\n\n\n#include <cassert>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#include <type_traits>\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\ntemplate\
      \ <typename T> using is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value\n                                  or std::is_same<T, __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_unsigned_int128\
      \ =\n    typename std::conditional<std::is_same<T, __uint128_t>::value\n   \
      \                               or std::is_same<T, unsigned __int128>::value,\n\
      \                              std::true_type,\n                           \
      \   std::false_type>::type;\n\ntemplate <typename T> using is_integral =\n \
      \   typename std::conditional<std::is_integral<T>::value or is_signed_int128<T>::value\n\
      \                                  or is_unsigned_int128<T>::value,\n      \
      \                        std::true_type,\n                              std::false_type>::type;\n\
      \ntemplate <typename T> using is_signed =\n    typename std::conditional<std::is_signed<T>::value\
      \ or is_signed_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_unsigned =\n    typename std::conditional<std::is_unsigned<T>::value\
      \ or is_unsigned_int128<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
      \ __int128_t>::value, __uint128_t, unsigned __int128>;\n\ntemplate <typename\
      \ T> using to_unsigned =\n    typename std::conditional<is_signed_int128<T>::value,\n\
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
      \n} // namespace kk2\n\n\n#line 7 \"bit/bitcount.hpp\"\n\nnamespace kk2 {\n\n\
      template <Integral T> constexpr int ctz(T x) {\n    assert(x != T(0));\n\n \
      \   if constexpr (sizeof(T) <= 4) {\n        return __builtin_ctz(x);\n    }\
      \ else if constexpr (sizeof(T) <= 8) {\n        return __builtin_ctzll(x);\n\
      \    } else {\n        if (x & 0xffffffffffffffff)\n            return __builtin_ctzll((unsigned\
      \ long long)(x & 0xffffffffffffffff));\n        return 64 + __builtin_ctzll((unsigned\
      \ long long)(x >> 64));\n    }\n}\n\ntemplate <Integral T> constexpr int lsb(T\
      \ x) {\n    assert(x != T(0));\n\n    return ctz(x);\n}\n\ntemplate <Integral\
      \ T> constexpr int clz(T x) {\n    assert(x != T(0));\n\n    if constexpr (sizeof(T)\
      \ <= 4) {\n        return __builtin_clz(x);\n    } else if constexpr (sizeof(T)\
      \ <= 8) {\n        return __builtin_clzll(x);\n    } else {\n        if (x >>\
      \ 64) return __builtin_clzll((unsigned long long)(x >> 64));\n        return\
      \ 64 + __builtin_clzll((unsigned long long)(x & 0xffffffffffffffff));\n    }\n\
      }\n\ntemplate <Integral T> constexpr int msb(T x) {\n    assert(x != T(0));\n\
      \n    return sizeof(T) * 8 - 1 - clz(x);\n}\n\ntemplate <Integral T> constexpr\
      \ int popcount(T x) {\n\n    if constexpr (sizeof(T) <= 4) {\n        return\
      \ __builtin_popcount(x);\n    } else if constexpr (sizeof(T) <= 8) {\n     \
      \   return __builtin_popcountll(x);\n    } else {\n        return __builtin_popcountll((unsigned\
      \ long long)(x >> 64))\n               + __builtin_popcountll((unsigned long\
      \ long)(x & 0xffffffffffffffff));\n    }\n}\n\n}; // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: bit/bitcount.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution.hpp
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - convolution/multi_convolution_truncated.hpp
  - data_structure/bit_vector.hpp
  - data_structure/my_bitset.hpp
  - data_structure/w_ary_tree.hpp
  - data_structure/wavelet_matrix.hpp
  - fps/fps_arb.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/fps_sparsity_detector.hpp
  - math_mod/comb_large.hpp
  - matrix/matrix_F2.hpp
  - string/dynamic_rolling_hash.hpp
  - unionfind/parallel.hpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-07 22:58:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/data_structure/bit_vector.test.cpp
  - verify/unit_test/data_structure/wavelet_matrix.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/string/dynamic_rolling_hash.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
  - verify/yosupo_ds/ds_predecessor_problem.test.cpp
  - verify/yosupo_ds/ds_range_kth_smallest.test.cpp
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
  - verify/yosupo_linalg/matrix_det_f2.test.cpp
  - verify/yosupo_linalg/matrix_inv_f2.test.cpp
  - verify/yosupo_linalg/matrix_product_f2.test.cpp
  - verify/yosupo_linalg/matrix_rank_F2.test.cpp
  - verify/yosupo_linalg/solution_of_linear_equations_F2.test.cpp
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: bit/bitcount.hpp
layout: document
---
