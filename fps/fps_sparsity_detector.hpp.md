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
    - filename: fps_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sqrt.hpp
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
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
    - filename: sparsity_boundary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_boundary.test.cpp
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
    - filename: large_fact_arb_mod.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
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
  dependsOn: []
  embedded:
  - code: "#ifndef KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\n#define KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\
      \ 1\n\n#include <algorithm>\n#include <bit>\n#include <cstdint>\n#include <memory>\n\
      \nnamespace kk2 {\n\nenum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n\
      \    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n\
      \    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n// E(n): the leading FFT\
      \ evaluation cost, up to the common field-operation\n// constant that cancels\
      \ when dense and sparse leading terms are compared.\ninline std::int64_t evaluation_work(int\
      \ n) {\n    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
      \    return static_cast<std::int64_t>(z) * std::countr_zero(z);\n}\n\ninline\
      \ int transform_size(int n, int m) {\n    if (n <= 0 || m <= 0) return 0;\n\
      \    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));\n\
      }\n\ninline std::int64_t convolution_dense_work(int n, int m, bool same, bool\
      \ ntt_friendly) {\n    const int z = transform_size(n, m);\n    if (z == 0)\
      \ return 0;\n\n    // A different pair needs two forward and one inverse transform.\
      \ Squaring\n    // reuses the forward transform and needs only one forward transform.\n\
      \    const int transforms = same ? 2 : 3;\n    // Arbitrary-modulus convolution\
      \ uses three NTT-friendly moduli.\n    const int moduli = ntt_friendly ? 1 :\
      \ 3;\n    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);\n\
      }\n\ninline std::int64_t inverse_dense_work(int deg, bool ntt_friendly) {\n\
      \    if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // NTT-friendly uses five transforms per Newton level, whose geometric\n\
      \    // sum has leading term 10 E(z). The arbitrary-modulus implementation\n\
      \    // performs two fresh convolutions per level, giving 60 E(z).\n    return\
      \ (ntt_friendly ? 10 : 60) * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::max(0, n - 1), deg, false, ntt_friendly);\n\
      }\n\ninline long double exp_dense_work(int deg, bool ntt_friendly) {\n    if\
      \ (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    if (ntt_friendly) {\n        if (deg <= 2) return 0;\n        // Bostan--Schost,\
      \ Theorem 1: (33/2) E(z) + (97/4) z.  Only\n        // the leading E(z) term\
      \ matters for the sparsity threshold.\n        return 16.5L * evaluation_work(z);\n\
      \    }\n    // FPSArb recomputes a logarithm and a product at every Newton level.\n\
      \    return 192 * evaluation_work(z);\n}\n\ninline long double power_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return log_dense_work(n, deg, ntt_friendly)\
      \ + exp_dense_work(deg, ntt_friendly);\n}\n\ninline std::int64_t division_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::min(n, deg), deg, false, ntt_friendly);\n\
      }\n\ninline std::int64_t polynomial_division_dense_work(int quotient_size, bool\
      \ ntt_friendly) {\n    return inverse_dense_work(quotient_size, ntt_friendly)\n\
      \           + convolution_dense_work(quotient_size, quotient_size, false, ntt_friendly);\n\
      }\n\ninline std::int64_t sqrt_dense_work(int deg, bool ntt_friendly) {\n   \
      \ if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // Newton uses an inverse and one product at every level. The implementation\n\
      \    // computes the complete next power-of-two block even at the last level.\n\
      \    return (ntt_friendly ? 32 : 156) * evaluation_work(z);\n}\n\ninline long\
      \ double sparse_leading_work(FPSOperation op, long double support_output_pairs)\
      \ {\n    switch (op) {\n    case FPSOperation::LOG:\n        return 3 * support_output_pairs;\n\
      \    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n        return\
      \ 4 * support_output_pairs;\n    case FPSOperation::CONVOLUTION:\n    case FPSOperation::DIVISION:\n\
      \    case FPSOperation::POLYNOMIAL_DIVISION:\n    case FPSOperation::INVERSE:\n\
      \    case FPSOperation::EXP:\n        return 2 * support_output_pairs;\n   \
      \ }\n    return 0;\n}\n\ninline long double sparse_runtime_factor(FPSOperation\
      \ op) {\n    // Conversion from the field-operation model above to observed\
      \ running\n    // time. Calibrated on powers of two from 256 through 4096 while\
      \ keeping\n    // the threshold conservative when the two implementations are\
      \ close.\n    switch (op) {\n    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n\
      \        return 0.60L;\n    case FPSOperation::DIVISION:\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        return 0.75L;\n    case FPSOperation::CONVOLUTION:\n        return\
      \ 1.50L;\n    case FPSOperation::LOG:\n        return 1.25L;\n    case FPSOperation::INVERSE:\n\
      \        return 0.90L;\n    case FPSOperation::EXP:\n        return 1.00L;\n\
      \    }\n    return 1.00L;\n}\n\n} // namespace fps::sparsity_detail\n\ntemplate\
      \ <class FPS, class mint = typename FPS::value_type>\nbool is_sparse_operation(\n\
      \    FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(),\
      \ int deg = -1) {\n    const int n = a.size(), m = b.size();\n    if (n + m\
      \ == 0) return false;\n\n    const bool convolution = op == FPSOperation::CONVOLUTION;\n\
      \    const bool division = op == FPSOperation::DIVISION;\n    const bool polynomial_division\
      \ = op == FPSOperation::POLYNOMIAL_DIVISION;\n    const int target = deg < 0\
      \ ? n : std::max(0, deg);\n    std::int64_t nonzero_a = 0, nonzero_b = 0;\n\
      \    long double pair_work = 0;\n\n    const int limit_a = convolution     \
      \                  ? n :\n                        (division || polynomial_division)\
      \ ? 0 :\n                                                            std::min(n,\
      \ target);\n    for (int i = 0; i < limit_a; ++i) {\n        if (a[i] == mint(0))\
      \ continue;\n        ++nonzero_a;\n        if (!convolution && i > 0) {\n  \
      \          const int terms = op == FPSOperation::LOG ? target - 1 - i : target\
      \ - i;\n            if (terms > 0) pair_work += terms;\n        }\n    }\n\n\
      \    const int limit_b = convolution         ? m :\n                       \
      \ division            ? std::min(m, target) :\n                        polynomial_division\
      \ ? m :\n                                              0;\n    for (int i =\
      \ 0; i < limit_b; ++i) {\n        if (b[i] == mint(0)) continue;\n        ++nonzero_b;\n\
      \        if (division && i > 0) pair_work += target - i;\n        if (polynomial_division\
      \ && i + 1 < m) {\n            const int terms = target - (m - 1 - i);\n   \
      \         if (terms > 0) pair_work += terms;\n        }\n    }\n\n    if (convolution)\
      \ { pair_work = static_cast<long double>(nonzero_a) * nonzero_b; }\n\n    long\
      \ double dense_work = 0;\n    switch (op) {\n    case FPSOperation::CONVOLUTION:\n\
      \        dense_work = fps::sparsity_detail::convolution_dense_work(\n      \
      \      n, m, std::addressof(a) == std::addressof(b), is_ntt_friendly);\n   \
      \     break;\n    case FPSOperation::LOG:\n        dense_work = fps::sparsity_detail::log_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POWER:\n\
      \        dense_work = fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::DIVISION:\n        dense_work = fps::sparsity_detail::division_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        dense_work = fps::sparsity_detail::polynomial_division_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::INVERSE:\n     \
      \   dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::EXP:\n        dense_work = fps::sparsity_detail::exp_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::SQRT:\n        dense_work\
      \ = fps::sparsity_detail::sqrt_dense_work(target, is_ntt_friendly);\n      \
      \  break;\n    }\n\n    // Count the leading field operations executed for each\
      \ support/output\n    // pair. Linear scans, initialization and per-output normalization\
      \ are\n    // intentionally omitted on both the sparse and dense sides.\n  \
      \  const long double sparse_work = fps::sparsity_detail::sparse_leading_work(op,\
      \ pair_work);\n    return dense_work > fps::sparsity_detail::sparse_runtime_factor(op)\
      \ * sparse_work;\n}\n\n} // namespace kk2\n\n#endif // KK2_FPS_FPS_SPARSITY_DETECTOR_HPP\n"
    name: default
  - code: "#line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <bit>\n#include <cstdint>\n#include <memory>\n\nnamespace kk2 {\n\n\
      enum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n    POWER,\n    DIVISION,\n\
      \    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n    SQRT\n};\n\nnamespace\
      \ fps::sparsity_detail {\n\n// E(n): the leading FFT evaluation cost, up to\
      \ the common field-operation\n// constant that cancels when dense and sparse\
      \ leading terms are compared.\ninline std::int64_t evaluation_work(int n) {\n\
      \    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
      \    return static_cast<std::int64_t>(z) * std::countr_zero(z);\n}\n\ninline\
      \ int transform_size(int n, int m) {\n    if (n <= 0 || m <= 0) return 0;\n\
      \    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));\n\
      }\n\ninline std::int64_t convolution_dense_work(int n, int m, bool same, bool\
      \ ntt_friendly) {\n    const int z = transform_size(n, m);\n    if (z == 0)\
      \ return 0;\n\n    // A different pair needs two forward and one inverse transform.\
      \ Squaring\n    // reuses the forward transform and needs only one forward transform.\n\
      \    const int transforms = same ? 2 : 3;\n    // Arbitrary-modulus convolution\
      \ uses three NTT-friendly moduli.\n    const int moduli = ntt_friendly ? 1 :\
      \ 3;\n    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);\n\
      }\n\ninline std::int64_t inverse_dense_work(int deg, bool ntt_friendly) {\n\
      \    if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // NTT-friendly uses five transforms per Newton level, whose geometric\n\
      \    // sum has leading term 10 E(z). The arbitrary-modulus implementation\n\
      \    // performs two fresh convolutions per level, giving 60 E(z).\n    return\
      \ (ntt_friendly ? 10 : 60) * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::max(0, n - 1), deg, false, ntt_friendly);\n\
      }\n\ninline long double exp_dense_work(int deg, bool ntt_friendly) {\n    if\
      \ (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    if (ntt_friendly) {\n        if (deg <= 2) return 0;\n        // Bostan--Schost,\
      \ Theorem 1: (33/2) E(z) + (97/4) z.  Only\n        // the leading E(z) term\
      \ matters for the sparsity threshold.\n        return 16.5L * evaluation_work(z);\n\
      \    }\n    // FPSArb recomputes a logarithm and a product at every Newton level.\n\
      \    return 192 * evaluation_work(z);\n}\n\ninline long double power_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return log_dense_work(n, deg, ntt_friendly)\
      \ + exp_dense_work(deg, ntt_friendly);\n}\n\ninline std::int64_t division_dense_work(int\
      \ n, int deg, bool ntt_friendly) {\n    return inverse_dense_work(deg, ntt_friendly)\n\
      \           + convolution_dense_work(std::min(n, deg), deg, false, ntt_friendly);\n\
      }\n\ninline std::int64_t polynomial_division_dense_work(int quotient_size, bool\
      \ ntt_friendly) {\n    return inverse_dense_work(quotient_size, ntt_friendly)\n\
      \           + convolution_dense_work(quotient_size, quotient_size, false, ntt_friendly);\n\
      }\n\ninline std::int64_t sqrt_dense_work(int deg, bool ntt_friendly) {\n   \
      \ if (deg <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(deg)));\n\
      \    // Newton uses an inverse and one product at every level. The implementation\n\
      \    // computes the complete next power-of-two block even at the last level.\n\
      \    return (ntt_friendly ? 32 : 156) * evaluation_work(z);\n}\n\ninline long\
      \ double sparse_leading_work(FPSOperation op, long double support_output_pairs)\
      \ {\n    switch (op) {\n    case FPSOperation::LOG:\n        return 3 * support_output_pairs;\n\
      \    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n        return\
      \ 4 * support_output_pairs;\n    case FPSOperation::CONVOLUTION:\n    case FPSOperation::DIVISION:\n\
      \    case FPSOperation::POLYNOMIAL_DIVISION:\n    case FPSOperation::INVERSE:\n\
      \    case FPSOperation::EXP:\n        return 2 * support_output_pairs;\n   \
      \ }\n    return 0;\n}\n\ninline long double sparse_runtime_factor(FPSOperation\
      \ op) {\n    // Conversion from the field-operation model above to observed\
      \ running\n    // time. Calibrated on powers of two from 256 through 4096 while\
      \ keeping\n    // the threshold conservative when the two implementations are\
      \ close.\n    switch (op) {\n    case FPSOperation::POWER:\n    case FPSOperation::SQRT:\n\
      \        return 0.60L;\n    case FPSOperation::DIVISION:\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        return 0.75L;\n    case FPSOperation::CONVOLUTION:\n        return\
      \ 1.50L;\n    case FPSOperation::LOG:\n        return 1.25L;\n    case FPSOperation::INVERSE:\n\
      \        return 0.90L;\n    case FPSOperation::EXP:\n        return 1.00L;\n\
      \    }\n    return 1.00L;\n}\n\n} // namespace fps::sparsity_detail\n\ntemplate\
      \ <class FPS, class mint = typename FPS::value_type>\nbool is_sparse_operation(\n\
      \    FPSOperation op, bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(),\
      \ int deg = -1) {\n    const int n = a.size(), m = b.size();\n    if (n + m\
      \ == 0) return false;\n\n    const bool convolution = op == FPSOperation::CONVOLUTION;\n\
      \    const bool division = op == FPSOperation::DIVISION;\n    const bool polynomial_division\
      \ = op == FPSOperation::POLYNOMIAL_DIVISION;\n    const int target = deg < 0\
      \ ? n : std::max(0, deg);\n    std::int64_t nonzero_a = 0, nonzero_b = 0;\n\
      \    long double pair_work = 0;\n\n    const int limit_a = convolution     \
      \                  ? n :\n                        (division || polynomial_division)\
      \ ? 0 :\n                                                            std::min(n,\
      \ target);\n    for (int i = 0; i < limit_a; ++i) {\n        if (a[i] == mint(0))\
      \ continue;\n        ++nonzero_a;\n        if (!convolution && i > 0) {\n  \
      \          const int terms = op == FPSOperation::LOG ? target - 1 - i : target\
      \ - i;\n            if (terms > 0) pair_work += terms;\n        }\n    }\n\n\
      \    const int limit_b = convolution         ? m :\n                       \
      \ division            ? std::min(m, target) :\n                        polynomial_division\
      \ ? m :\n                                              0;\n    for (int i =\
      \ 0; i < limit_b; ++i) {\n        if (b[i] == mint(0)) continue;\n        ++nonzero_b;\n\
      \        if (division && i > 0) pair_work += target - i;\n        if (polynomial_division\
      \ && i + 1 < m) {\n            const int terms = target - (m - 1 - i);\n   \
      \         if (terms > 0) pair_work += terms;\n        }\n    }\n\n    if (convolution)\
      \ { pair_work = static_cast<long double>(nonzero_a) * nonzero_b; }\n\n    long\
      \ double dense_work = 0;\n    switch (op) {\n    case FPSOperation::CONVOLUTION:\n\
      \        dense_work = fps::sparsity_detail::convolution_dense_work(\n      \
      \      n, m, std::addressof(a) == std::addressof(b), is_ntt_friendly);\n   \
      \     break;\n    case FPSOperation::LOG:\n        dense_work = fps::sparsity_detail::log_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POWER:\n\
      \        dense_work = fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::DIVISION:\n        dense_work = fps::sparsity_detail::division_dense_work(n,\
      \ target, is_ntt_friendly);\n        break;\n    case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \        dense_work = fps::sparsity_detail::polynomial_division_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::INVERSE:\n     \
      \   dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);\n\
      \        break;\n    case FPSOperation::EXP:\n        dense_work = fps::sparsity_detail::exp_dense_work(target,\
      \ is_ntt_friendly);\n        break;\n    case FPSOperation::SQRT:\n        dense_work\
      \ = fps::sparsity_detail::sqrt_dense_work(target, is_ntt_friendly);\n      \
      \  break;\n    }\n\n    // Count the leading field operations executed for each\
      \ support/output\n    // pair. Linear scans, initialization and per-output normalization\
      \ are\n    // intentionally omitted on both the sparse and dense sides.\n  \
      \  const long double sparse_work = fps::sparsity_detail::sparse_leading_work(op,\
      \ pair_work);\n    return dense_work > fps::sparsity_detail::sparse_runtime_factor(op)\
      \ * sparse_work;\n}\n\n} // namespace kk2\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/fps_sparsity_detector.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/convolution.hpp
  - convolution/convolution_arb.hpp
  - convolution/convolution_int.hpp
  - convolution/multi_convolution_truncated.hpp
  - fps/fps_arb.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/fps_sqrt.hpp
  - math_mod/comb_large.hpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-11 01:16:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
  - verify/yosupo_convolution/convolution_arbitrary.test.cpp
  - verify/yosupo_convolution/convolution_multi_truncated.test.cpp
  - verify/yosupo_convolution/convolution_ntt_friendly.test.cpp
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
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: fps/fps_sparsity_detector.hpp
layout: document
---
