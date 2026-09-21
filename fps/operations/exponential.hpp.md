---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: fps.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/fps.hpp
    type: Depends on
  - files:
    - filename: fps_arb.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_arb.hpp
    - filename: fps_base.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_base.hpp
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: fps_ntt_friendly.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_ntt_friendly.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/arb/exponential.hpp
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
    - filename: inplace_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/inplace_operations.test.cpp
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
  dependsOn:
  - fps/fps_sparsity_detector.hpp
  - type_traits/fps.hpp
  embedded:
  - code: "#ifndef KK2_FPS_OPERATIONS_EXPONENTIAL_HPP\n#define KK2_FPS_OPERATIONS_EXPONENTIAL_HPP\
      \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
      \ <vector>\n\n#include \"../../type_traits/fps.hpp\"\n#include \"../fps_sparsity_detector.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <NTTFriendlyFormalPowerSeries\
      \ FPS> FPS dense_exp(const FPS &f, int precision = -1) {\n    using mint = typename\
      \ FPS::value_type;\n    assert(f.empty() || f[0] == mint(0));\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n\n    FPS result{1, 1 < static_cast<int>(f.size())\
      \ ? f[1] : mint(0)};\n    FPS inverse{1}, transformed_inverse, previous_transformed_inverse{1,\
      \ 1};\n    for (int m = 2; m < precision; m <<= 1) {\n        FPS transformed_result\
      \ = result;\n        transformed_result.resize(m << 1);\n        transformed_result.but();\n\
      \        transformed_inverse = previous_transformed_inverse;\n        FPS correction(m);\n\
      \        correction = transformed_result.dot(transformed_inverse);\n       \
      \ correction.ibut();\n        std::fill_n(correction.begin(), m >> 1, mint(0));\n\
      \        correction.but();\n        correction.inplace_dot(-transformed_inverse);\n\
      \        correction.ibut();\n        inverse.insert(inverse.end(), correction.begin()\
      \ + (m >> 1), correction.end());\n        previous_transformed_inverse = inverse;\n\
      \        previous_transformed_inverse.resize(m << 1);\n        previous_transformed_inverse.but();\n\
      \n        FPS delta(f.begin(), f.begin() + std::min(static_cast<int>(f.size()),\
      \ m));\n        delta.resize(m);\n        delta.inplace_diff();\n        delta.push_back(mint(0));\n\
      \        delta.but();\n        delta.inplace_dot(transformed_result);\n    \
      \    delta.ibut();\n        delta -= result.diff();\n        delta.resize(m\
      \ << 1);\n        std::copy_n(delta.begin(), m - 1, delta.begin() + m);\n  \
      \      std::fill_n(delta.begin(), m - 1, mint(0));\n        delta.but();\n \
      \       delta.inplace_dot(previous_transformed_inverse);\n        delta.ibut();\n\
      \        delta.pop_back();\n        delta.inplace_int();\n        for (int i\
      \ = m; i < std::min(static_cast<int>(f.size()), m << 1); ++i) delta[i] += f[i];\n\
      \        std::fill_n(delta.begin(), m, mint(0));\n        delta.but();\n   \
      \     delta.inplace_dot(transformed_result);\n        delta.ibut();\n      \
      \  result.insert(result.end(), delta.begin() + m, delta.end());\n    }\n   \
      \ return FPS(result.begin(), result.begin() + precision);\n}\n\ntemplate <ArbitraryModulusFormalPowerSeries\
      \ FPS> FPS dense_exp(const FPS &f, int precision = -1);\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS &inplace_dense_exp(FPS &f, int precision = -1) {\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n    return f = dense_exp(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    if (precision == -1) precision\
      \ = static_cast<int>(f.size());\n\n    std::vector<std::pair<int, mint>> support;\n\
      \    for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n        if (f[i]\
      \ != mint(0)) support.emplace_back(i, f[i] * i);\n    }\n\n    const int mod\
      \ = mint::getmod();\n    static std::vector<mint> inverse{1, 1};\n    const\
      \ int old_size = inverse.size();\n    inverse.resize(std::max(old_size, precision\
      \ + 1));\n    for (int i = old_size; i <= precision; ++i) inverse[i] = -inverse[mod\
      \ % i] * (mod / i);\n\n    f.assign(precision, mint(0));\n    if (precision\
      \ > 0) f[0] = mint(1);\n    for (int k = 0; k < precision - 1; ++k) {\n    \
      \    for (const auto &[index, derivative_coefficient] : support) {\n       \
      \     const int derivative_index = index - 1;\n            if (k < derivative_index)\
      \ break;\n            f[k + 1] += f[k - derivative_index] * derivative_coefficient;\n\
      \        }\n        f[k + 1] *= inverse[k + 1];\n    }\n    return f;\n}\n\n\
      template <UnivariateFormalPowerSeries FPS> FPS sparse_exp(const FPS &f, int\
      \ precision = -1) {\n    FPS result = f;\n    return inplace_sparse_exp(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS exp(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(f.empty() || f[0] == mint(0));\n    if (is_sparse_operation(\n \
      \           FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_exp(f, precision);\n    return dense_exp(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);\n\
      \    if (use_sparse) return inplace_sparse_exp(f, precision);\n    return inplace_dense_exp(f,\
      \ precision);\n}\n\n} // namespace kk2::fps::operations\n\n#endif // KK2_FPS_OPERATIONS_EXPONENTIAL_HPP\n"
    name: default
  - code: "#line 1 \"fps/operations/exponential.hpp\"\n\n\n\n#include <algorithm>\n\
      #include <cassert>\n#include <utility>\n#include <vector>\n\n#line 1 \"type_traits/fps.hpp\"\
      \n\n\n\n#include <concepts>\n#include <ranges>\n#include <type_traits>\n\nnamespace\
      \ kk2::fps {\n\nnamespace category {\n\nstruct arbitrary_modulus {};\nstruct\
      \ ntt_friendly_modulus {};\n\nstruct ordinary {};\nstruct exponential_generating\
      \ {};\nstruct set_power_series {};\n\nstruct univariate {};\nstruct bivariate\
      \ {};\nstruct multivariate {};\n\n} // namespace category\n\ntemplate <class\
      \ M>\nconcept Modular = requires(M x) {\n    { M::getmod() } -> std::integral;\n\
      \    x.val();\n    { x.inv() } -> std::same_as<M>;\n};\n\ntemplate <class F>\n\
      concept FormalPowerSeries = requires(const F &f, int i) {\n    typename F::value_type;\n\
      \    typename F::modulus_category;\n    typename F::series_category;\n    {\
      \ f.size() } -> std::integral;\n    f[i];\n} && std::ranges::range<const F>;\n\
      \ntemplate <class F>\nconcept NTTFriendlyFormalPowerSeries =\n    FormalPowerSeries<F>\n\
      \    && std::same_as<typename F::modulus_category, category::ntt_friendly_modulus>;\n\
      \ntemplate <class F>\nconcept ArbitraryModulusFormalPowerSeries =\n    FormalPowerSeries<F>\
      \ && std::same_as<typename F::modulus_category, category::arbitrary_modulus>;\n\
      \ntemplate <class F>\nconcept OrdinaryFormalPowerSeries =\n    FormalPowerSeries<F>\
      \ && std::same_as<typename F::series_category, category::ordinary>;\n\ntemplate\
      \ <class F>\nconcept ExponentialGeneratingFunction =\n    FormalPowerSeries<F>\n\
      \    && std::same_as<typename F::series_category, category::exponential_generating>;\n\
      \ntemplate <class F>\nconcept SetPowerSeries =\n    FormalPowerSeries<F> &&\
      \ std::same_as<typename F::series_category, category::set_power_series>;\n\n\
      template <class F>\nconcept UnivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::univariate>;\n\ntemplate <class F>\nconcept\
      \ BivariateFormalPowerSeries = FormalPowerSeries<F> && requires {\n    typename\
      \ F::variable_category;\n} && std::same_as<typename F::variable_category, category::bivariate>;\n\
      \ntemplate <class F>\nconcept MultivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::multivariate>;\n\n// Short names for the categories\
      \ that are commonly used in algorithms.\ntemplate <class F>\nconcept SPS = SetPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept EGF = ExponentialGeneratingFunction<F>;\n\ntemplate\
      \ <class F>\nconcept Bivariate = BivariateFormalPowerSeries<F>;\n\ntemplate\
      \ <class F>\nconcept Multivariate = MultivariateFormalPowerSeries<F>;\n\n} //\
      \ namespace kk2::fps\n\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\n\n\n\n\
      #line 5 \"fps/fps_sparsity_detector.hpp\"\n#include <bit>\n#include <cstdint>\n\
      #include <memory>\n#line 9 \"fps/fps_sparsity_detector.hpp\"\n\nnamespace kk2\
      \ {\n\nenum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n    POWER,\n \
      \   DIVISION,\n    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n    SQRT\n\
      };\n\nnamespace fps::sparsity_detail {\n\n// E(n): the leading FFT evaluation\
      \ cost, up to the common field-operation\n// constant that cancels when dense\
      \ and sparse leading terms are compared.\ninline std::int64_t evaluation_work(int\
      \ n) {\n    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
      \    return static_cast<std::int64_t>(z) * std::countr_zero(z);\n}\n\ninline\
      \ int transform_size(int n, int m) {\n    if (n <= 0 || m <= 0) return 0;\n\
      \    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n + m - 1)));\n\
      }\n\ninline std::int64_t\nconvolution_dense_work(int n, int m, int precision,\
      \ bool same, bool ntt_friendly) {\n    n = std::min(n, precision);\n    m =\
      \ std::min(m, precision);\n    const int z = transform_size(n, m);\n    if (z\
      \ == 0) return 0;\n\n    // A different pair needs two forward and one inverse\
      \ transform. Squaring\n    // reuses the forward transform and needs only one\
      \ forward transform.\n    const int transforms = same ? 2 : 3;\n    // Arbitrary-modulus\
      \ convolution uses three NTT-friendly moduli.\n    const int moduli = ntt_friendly\
      \ ? 1 : 3;\n    return static_cast<std::int64_t>(transforms) * moduli * evaluation_work(z);\n\
      }\n\ninline std::int64_t inverse_dense_work(int precision, bool ntt_friendly)\
      \ {\n    if (precision <= 1) return 0;\n    const int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    // NTT-friendly uses five transforms per Newton level, whose geometric\n\
      \    // sum has leading term 10 E(z). The arbitrary-modulus implementation\n\
      \    // performs two fresh convolutions per level, giving 60 E(z).\n    return\
      \ (ntt_friendly ? 10 : 60) * evaluation_work(z);\n}\n\ninline std::int64_t log_dense_work(int\
      \ n, int precision, bool ntt_friendly) {\n    return inverse_dense_work(precision,\
      \ ntt_friendly)\n           + convolution_dense_work(std::max(0, n - 1), precision,\
      \ precision, false, ntt_friendly);\n}\n\ninline long double exp_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    if (ntt_friendly) {\n        if (precision <= 2) return 0;\n        //\
      \ Bostan--Schost, Theorem 1: (33/2) E(z) + (97/4) z.  Only\n        // the leading\
      \ E(z) term matters for the sparsity threshold.\n        return 16.5L * evaluation_work(z);\n\
      \    }\n    // FPSArb recomputes a logarithm and a product at every Newton level.\n\
      \    return 192 * evaluation_work(z);\n}\n\ninline long double power_dense_work(int\
      \ n, int precision, bool ntt_friendly) {\n    return log_dense_work(n, precision,\
      \ ntt_friendly) + exp_dense_work(precision, ntt_friendly);\n}\n\ninline std::int64_t\
      \ division_dense_work(int n, int precision, bool ntt_friendly) {\n    return\
      \ inverse_dense_work(precision, ntt_friendly)\n           + convolution_dense_work(\n\
      \               std::min(n, precision), precision, precision, false, ntt_friendly);\n\
      }\n\ninline std::int64_t polynomial_division_dense_work(int quotient_size, bool\
      \ ntt_friendly) {\n    return inverse_dense_work(quotient_size, ntt_friendly)\n\
      \           + convolution_dense_work(\n               quotient_size, quotient_size,\
      \ quotient_size, false, ntt_friendly);\n}\n\ninline std::int64_t sqrt_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
      \    // Newton uses an inverse and one product at every level. The implementation\n\
      \    // computes the complete next power-of-two block even at the last level.\n\
      \    return (ntt_friendly ? 32 : 156) * evaluation_work(z);\n}\n\ninline long\
      \ double\nsparse_work(FPSOperation op, int target, std::int64_t nonzero_a, std::int64_t\
      \ nonzero_b) {\n    switch (op) {\n        case FPSOperation::CONVOLUTION:\n\
      \            return static_cast<long double>(nonzero_a) * nonzero_b;\n     \
      \   case FPSOperation::DIVISION:\n        case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \            return static_cast<long double>(target) * nonzero_b;\n        case\
      \ FPSOperation::LOG:\n        case FPSOperation::POWER:\n        case FPSOperation::INVERSE:\n\
      \        case FPSOperation::EXP:\n        case FPSOperation::SQRT:\n       \
      \     return static_cast<long double>(target) * nonzero_a;\n    }\n    return\
      \ 0;\n}\n\ninline long double sparse_work_constant(FPSOperation op, bool ntt_friendly)\
      \ {\n    // Calibrated against the simplified sparse-work model at degrees 1024\n\
      \    // and 4096.  Values are rounded upward near the measured crossover so\
      \ a\n    // close decision favors the dense implementation.\n    switch (op)\
      \ {\n        case FPSOperation::CONVOLUTION:\n            return ntt_friendly\
      \ ? 0.90L : 0.55L;\n        case FPSOperation::DIVISION:\n        case FPSOperation::POLYNOMIAL_DIVISION:\n\
      \            return ntt_friendly ? 0.90L : 0.40L;\n        case FPSOperation::LOG:\n\
      \            return ntt_friendly ? 2.70L : 1.00L;\n        case FPSOperation::POWER:\n\
      \            return ntt_friendly ? 1.35L : 0.70L;\n        case FPSOperation::INVERSE:\n\
      \            return ntt_friendly ? 1.00L : 0.40L;\n        case FPSOperation::EXP:\n\
      \            return ntt_friendly ? 1.05L : 0.45L;\n        case FPSOperation::SQRT:\n\
      \            return ntt_friendly ? 1.40L : 0.65L;\n    }\n    return 1.00L;\n\
      }\n\n} // namespace fps::sparsity_detail\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nbool is_sparse_operation(\n    FPSOperation op,\
      \ bool is_ntt_friendly, const FPS &a, const FPS &b = FPS(), int precision =\
      \ -1) {\n    const int n = a.size(), m = b.size();\n    if (n + m == 0) return\
      \ false;\n\n    const bool convolution = op == FPSOperation::CONVOLUTION;\n\
      \    const bool division = op == FPSOperation::DIVISION;\n    const bool polynomial_division\
      \ = op == FPSOperation::POLYNOMIAL_DIVISION;\n    const int requested =\n  \
      \      precision < 0 ? (convolution ? std::max(0, n + m - 1) : n) : std::max(0,\
      \ precision);\n    const int target = convolution ? std::min(requested, std::max(0,\
      \ n + m - 1)) : requested;\n    const int limit_a = convolution            \
      \           ? std::min(n, target) :\n                        (division || polynomial_division)\
      \ ? 0 :\n                                                            std::min(n,\
      \ target);\n    const int limit_b = convolution         ? std::min(m, target)\
      \ :\n                        division            ? std::min(m, target) :\n \
      \                       polynomial_division ? m :\n                        \
      \                      0;\n    const auto is_nonzero = [](const mint &x) {\n\
      \        return x != mint(0);\n    };\n    const std::int64_t nonzero_a = std::ranges::count_if(a\
      \ | std::views::take(limit_a), is_nonzero);\n    const std::int64_t nonzero_b\
      \ = std::ranges::count_if(b | std::views::take(limit_b), is_nonzero);\n\n  \
      \  long double dense_work = 0;\n    switch (op) {\n        case FPSOperation::CONVOLUTION:\n\
      \            dense_work = fps::sparsity_detail::convolution_dense_work(\n  \
      \              n, m, target, std::addressof(a) == std::addressof(b), is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::LOG:\n            dense_work\
      \ = fps::sparsity_detail::log_dense_work(n, target, is_ntt_friendly);\n    \
      \        break;\n        case FPSOperation::POWER:\n            dense_work =\
      \ fps::sparsity_detail::power_dense_work(n, target, is_ntt_friendly);\n    \
      \        break;\n        case FPSOperation::DIVISION:\n            dense_work\
      \ = fps::sparsity_detail::division_dense_work(n, target, is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::POLYNOMIAL_DIVISION:\n     \
      \       dense_work =\n                fps::sparsity_detail::polynomial_division_dense_work(target,\
      \ is_ntt_friendly);\n            break;\n        case FPSOperation::INVERSE:\n\
      \            dense_work = fps::sparsity_detail::inverse_dense_work(target, is_ntt_friendly);\n\
      \            break;\n        case FPSOperation::EXP:\n            dense_work\
      \ = fps::sparsity_detail::exp_dense_work(target, is_ntt_friendly);\n       \
      \     break;\n        case FPSOperation::SQRT:\n            dense_work = fps::sparsity_detail::sqrt_dense_work(target,\
      \ is_ntt_friendly);\n            break;\n    }\n\n    const long double sparse_work\
      \ =\n        fps::sparsity_detail::sparse_work(op, target, nonzero_a, nonzero_b);\n\
      \    return dense_work\n           > fps::sparsity_detail::sparse_work_constant(op,\
      \ is_ntt_friendly) * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 11 \"\
      fps/operations/exponential.hpp\"\n\nnamespace kk2::fps::operations {\n\ntemplate\
      \ <NTTFriendlyFormalPowerSeries FPS> FPS dense_exp(const FPS &f, int precision\
      \ = -1) {\n    using mint = typename FPS::value_type;\n    assert(f.empty()\
      \ || f[0] == mint(0));\n    if (precision == -1) precision = static_cast<int>(f.size());\n\
      \n    FPS result{1, 1 < static_cast<int>(f.size()) ? f[1] : mint(0)};\n    FPS\
      \ inverse{1}, transformed_inverse, previous_transformed_inverse{1, 1};\n   \
      \ for (int m = 2; m < precision; m <<= 1) {\n        FPS transformed_result\
      \ = result;\n        transformed_result.resize(m << 1);\n        transformed_result.but();\n\
      \        transformed_inverse = previous_transformed_inverse;\n        FPS correction(m);\n\
      \        correction = transformed_result.dot(transformed_inverse);\n       \
      \ correction.ibut();\n        std::fill_n(correction.begin(), m >> 1, mint(0));\n\
      \        correction.but();\n        correction.inplace_dot(-transformed_inverse);\n\
      \        correction.ibut();\n        inverse.insert(inverse.end(), correction.begin()\
      \ + (m >> 1), correction.end());\n        previous_transformed_inverse = inverse;\n\
      \        previous_transformed_inverse.resize(m << 1);\n        previous_transformed_inverse.but();\n\
      \n        FPS delta(f.begin(), f.begin() + std::min(static_cast<int>(f.size()),\
      \ m));\n        delta.resize(m);\n        delta.inplace_diff();\n        delta.push_back(mint(0));\n\
      \        delta.but();\n        delta.inplace_dot(transformed_result);\n    \
      \    delta.ibut();\n        delta -= result.diff();\n        delta.resize(m\
      \ << 1);\n        std::copy_n(delta.begin(), m - 1, delta.begin() + m);\n  \
      \      std::fill_n(delta.begin(), m - 1, mint(0));\n        delta.but();\n \
      \       delta.inplace_dot(previous_transformed_inverse);\n        delta.ibut();\n\
      \        delta.pop_back();\n        delta.inplace_int();\n        for (int i\
      \ = m; i < std::min(static_cast<int>(f.size()), m << 1); ++i) delta[i] += f[i];\n\
      \        std::fill_n(delta.begin(), m, mint(0));\n        delta.but();\n   \
      \     delta.inplace_dot(transformed_result);\n        delta.ibut();\n      \
      \  result.insert(result.end(), delta.begin() + m, delta.end());\n    }\n   \
      \ return FPS(result.begin(), result.begin() + precision);\n}\n\ntemplate <ArbitraryModulusFormalPowerSeries\
      \ FPS> FPS dense_exp(const FPS &f, int precision = -1);\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS &inplace_dense_exp(FPS &f, int precision = -1) {\n    if (precision\
      \ == -1) precision = static_cast<int>(f.size());\n    return f = dense_exp(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    if (precision == -1) precision\
      \ = static_cast<int>(f.size());\n\n    std::vector<std::pair<int, mint>> support;\n\
      \    for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n        if (f[i]\
      \ != mint(0)) support.emplace_back(i, f[i] * i);\n    }\n\n    const int mod\
      \ = mint::getmod();\n    static std::vector<mint> inverse{1, 1};\n    const\
      \ int old_size = inverse.size();\n    inverse.resize(std::max(old_size, precision\
      \ + 1));\n    for (int i = old_size; i <= precision; ++i) inverse[i] = -inverse[mod\
      \ % i] * (mod / i);\n\n    f.assign(precision, mint(0));\n    if (precision\
      \ > 0) f[0] = mint(1);\n    for (int k = 0; k < precision - 1; ++k) {\n    \
      \    for (const auto &[index, derivative_coefficient] : support) {\n       \
      \     const int derivative_index = index - 1;\n            if (k < derivative_index)\
      \ break;\n            f[k + 1] += f[k - derivative_index] * derivative_coefficient;\n\
      \        }\n        f[k + 1] *= inverse[k + 1];\n    }\n    return f;\n}\n\n\
      template <UnivariateFormalPowerSeries FPS> FPS sparse_exp(const FPS &f, int\
      \ precision = -1) {\n    FPS result = f;\n    return inplace_sparse_exp(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS exp(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    assert(f.empty() || f[0] == mint(0));\n    if (is_sparse_operation(\n \
      \           FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_exp(f, precision);\n    return dense_exp(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_exp(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  assert(f.empty() || f[0] == mint(0));\n    const bool use_sparse = is_sparse_operation(\n\
      \        FPSOperation::EXP, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(), precision);\n\
      \    if (use_sparse) return inplace_sparse_exp(f, precision);\n    return inplace_dense_exp(f,\
      \ precision);\n}\n\n} // namespace kk2::fps::operations\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/operations/exponential.hpp
  pathExtension: hpp
  requiredBy:
  - fps/fps_arb.hpp
  - fps/fps_base.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/operations/arb/exponential.hpp
  - math_mod/comb_large.hpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_sample_point_shift.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-09-21 18:50:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/inplace_operations.test.cpp
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
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
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: fps/operations/exponential.hpp
layout: document
---
