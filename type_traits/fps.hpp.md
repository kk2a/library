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
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/modint.hpp
    type: Depends on
  - files:
    - filename: multi_convolution_truncated_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/multi_convolution_truncated_arb.hpp
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
    - filename: fps_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sqrt.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/arb/exponential.hpp
    - filename: inverse.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/arb/inverse.hpp
    - filename: multiplication.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/arb/multiplication.hpp
    - filename: division.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/division.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/exponential.hpp
    - filename: inverse.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/inverse.hpp
    - filename: logarithm.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/logarithm.hpp
    - filename: multiplication.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multiplication.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/exponential.hpp
    - filename: inverse.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/inverse.hpp
    - filename: logarithm.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/logarithm.hpp
    - filename: multiplication.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/multiplication.hpp
    - filename: power.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/power.hpp
    - filename: power.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/power.hpp
    - filename: sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/sqrt.hpp
    - filename: power_sum.hpp
      icon: LIBRARY_ALL_AC
      path: fps/power_sum.hpp
      title: Power Sum
    - filename: comb_large.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/comb_large.hpp
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
    - filename: multivariate_convolution.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_convolution.test.cpp
    - filename: multivariate_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_operations.test.cpp
    - filename: sparsity_boundary.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_boundary.test.cpp
    - filename: sparsity_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_performance.test.cpp
    - filename: sparsity_small_performance.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sparsity_small_performance.test.cpp
    - filename: sum_of_polynomial.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/sum_of_polynomial.test.cpp
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
  - type_traits/modint.hpp
  embedded:
  - code: "#ifndef KK2_TYPE_TRAITS_FPS_HPP\n#define KK2_TYPE_TRAITS_FPS_HPP 1\n\n\
      #include <concepts>\n#include <ranges>\n#include <type_traits>\n\n#include \"\
      modint.hpp\"\n\nnamespace kk2::fps {\n\nnamespace category {\n\nstruct arbitrary_modulus\
      \ {};\nstruct ntt_friendly_modulus {};\n\nstruct ordinary {};\nstruct exponential_generating\
      \ {};\nstruct set_power_series {};\n\nstruct univariate {};\nstruct bivariate\
      \ {};\nstruct multivariate {};\n\n} // namespace category\n\n// Compatibility\
      \ forwarding alias. The canonical modint constraint lives in\n// type_traits/modint.hpp;\
      \ keeping this name avoids breaking existing FPS code.\ntemplate <class M>\n\
      concept Modular = modint::Modular<M>;\n\ntemplate <class F>\nconcept FormalPowerSeries\
      \ = requires(const F &f, int i) {\n    typename F::value_type;\n    typename\
      \ F::modulus_category;\n    typename F::series_category;\n    { f.size() } ->\
      \ std::integral;\n    f[i];\n} && std::ranges::range<const F>;\n\ntemplate <class\
      \ F>\nconcept NTTFriendlyFormalPowerSeries =\n    FormalPowerSeries<F>\n   \
      \ && std::same_as<typename F::modulus_category, category::ntt_friendly_modulus>;\n\
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
      \ ModularUnivariateFormalPowerSeries =\n    UnivariateFormalPowerSeries<F> &&\
      \ modint::Modular<typename F::value_type>;\n\ntemplate <class F>\nconcept UnivariateNTTFriendlyFormalPowerSeries\
      \ =\n    NTTFriendlyFormalPowerSeries<F> && UnivariateFormalPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept UnivariateArbitraryModulusFormalPowerSeries =\n\
      \    ArbitraryModulusFormalPowerSeries<F> && UnivariateFormalPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept BivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::bivariate>;\n\ntemplate <class F>\nconcept\
      \ MultivariateFormalPowerSeries = FormalPowerSeries<F> && requires {\n    typename\
      \ F::variable_category;\n} && std::same_as<typename F::variable_category, category::multivariate>;\n\
      \n// Short names for the categories that are commonly used in algorithms.\n\
      template <class F>\nconcept SPS = SetPowerSeries<F>;\n\ntemplate <class F>\n\
      concept EGF = ExponentialGeneratingFunction<F>;\n\ntemplate <class F>\nconcept\
      \ Bivariate = BivariateFormalPowerSeries<F>;\n\ntemplate <class F>\nconcept\
      \ Multivariate = MultivariateFormalPowerSeries<F>;\n\n} // namespace kk2::fps\n\
      \n#endif // KK2_TYPE_TRAITS_FPS_HPP\n"
    name: default
  - code: "#line 1 \"type_traits/fps.hpp\"\n\n\n\n#include <concepts>\n#include <ranges>\n\
      #include <type_traits>\n\n#line 1 \"type_traits/modint.hpp\"\n\n\n\n#line 5\
      \ \"type_traits/modint.hpp\"\n\n#line 1 \"type_traits/integral.hpp\"\n\n\n\n\
      #line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
      \ntemplate <typename T>\nusing is_signed_int128 = typename std::conditional<std::is_same<T,\
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
      \n} // namespace kk2\n\n\n#line 7 \"type_traits/modint.hpp\"\n\nnamespace kk2::modint\
      \ {\n\ntemplate <class M>\nconcept Modular = requires(M x) {\n    requires Integral<decltype(M::getmod())>;\n\
      \    x.val();\n    { x.inv() } -> std::same_as<M>;\n};\n\n} // namespace kk2::modint\n\
      \n\n#line 9 \"type_traits/fps.hpp\"\n\nnamespace kk2::fps {\n\nnamespace category\
      \ {\n\nstruct arbitrary_modulus {};\nstruct ntt_friendly_modulus {};\n\nstruct\
      \ ordinary {};\nstruct exponential_generating {};\nstruct set_power_series {};\n\
      \nstruct univariate {};\nstruct bivariate {};\nstruct multivariate {};\n\n}\
      \ // namespace category\n\n// Compatibility forwarding alias. The canonical\
      \ modint constraint lives in\n// type_traits/modint.hpp; keeping this name avoids\
      \ breaking existing FPS code.\ntemplate <class M>\nconcept Modular = modint::Modular<M>;\n\
      \ntemplate <class F>\nconcept FormalPowerSeries = requires(const F &f, int i)\
      \ {\n    typename F::value_type;\n    typename F::modulus_category;\n    typename\
      \ F::series_category;\n    { f.size() } -> std::integral;\n    f[i];\n} && std::ranges::range<const\
      \ F>;\n\ntemplate <class F>\nconcept NTTFriendlyFormalPowerSeries =\n    FormalPowerSeries<F>\n\
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
      \ ModularUnivariateFormalPowerSeries =\n    UnivariateFormalPowerSeries<F> &&\
      \ modint::Modular<typename F::value_type>;\n\ntemplate <class F>\nconcept UnivariateNTTFriendlyFormalPowerSeries\
      \ =\n    NTTFriendlyFormalPowerSeries<F> && UnivariateFormalPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept UnivariateArbitraryModulusFormalPowerSeries =\n\
      \    ArbitraryModulusFormalPowerSeries<F> && UnivariateFormalPowerSeries<F>;\n\
      \ntemplate <class F>\nconcept BivariateFormalPowerSeries = FormalPowerSeries<F>\
      \ && requires {\n    typename F::variable_category;\n} && std::same_as<typename\
      \ F::variable_category, category::bivariate>;\n\ntemplate <class F>\nconcept\
      \ MultivariateFormalPowerSeries = FormalPowerSeries<F> && requires {\n    typename\
      \ F::variable_category;\n} && std::same_as<typename F::variable_category, category::multivariate>;\n\
      \n// Short names for the categories that are commonly used in algorithms.\n\
      template <class F>\nconcept SPS = SetPowerSeries<F>;\n\ntemplate <class F>\n\
      concept EGF = ExponentialGeneratingFunction<F>;\n\ntemplate <class F>\nconcept\
      \ Bivariate = BivariateFormalPowerSeries<F>;\n\ntemplate <class F>\nconcept\
      \ Multivariate = MultivariateFormalPowerSeries<F>;\n\n} // namespace kk2::fps\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: type_traits/fps.hpp
  pathExtension: hpp
  requiredBy:
  - convolution/multi_convolution_truncated_arb.hpp
  - fps/fps_arb.hpp
  - fps/fps_base.hpp
  - fps/fps_bivariate.hpp
  - fps/fps_egf.hpp
  - fps/fps_multivariate.hpp
  - fps/fps_ntt_friendly.hpp
  - fps/fps_sps.hpp
  - fps/fps_sqrt.hpp
  - fps/operations/arb/exponential.hpp
  - fps/operations/arb/inverse.hpp
  - fps/operations/arb/multiplication.hpp
  - fps/operations/division.hpp
  - fps/operations/exponential.hpp
  - fps/operations/inverse.hpp
  - fps/operations/logarithm.hpp
  - fps/operations/multiplication.hpp
  - fps/operations/multivariate/exponential.hpp
  - fps/operations/multivariate/inverse.hpp
  - fps/operations/multivariate/logarithm.hpp
  - fps/operations/multivariate/multiplication.hpp
  - fps/operations/multivariate/power.hpp
  - fps/operations/power.hpp
  - fps/operations/sqrt.hpp
  - fps/power_sum.hpp
  - math_mod/comb_large.hpp
  - verify/unit_test/math_mod/large_fact_arb_mod.test.cpp
  - verify/yosupo_fps/fps_composition.test.cpp
  - verify/yosupo_fps/fps_composition_inv.test.cpp
  - verify/yosupo_fps/fps_exp_arb.test.cpp
  - verify/yosupo_fps/fps_multipoint_evaluation_geometric.test.cpp
  - verify/yosupo_fps/poly_interpolation_geometric.test.cpp
  - verify/yosupo_fps/poly_to_newton_basis.test.cpp
  - verify/yosupo_math/kth_term_of_linearly_recurrent_sequence.test.cpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/inplace_operations.test.cpp
  - verify/unit_test/fps/multivariate_convolution.test.cpp
  - verify/unit_test/fps/multivariate_operations.test.cpp
  - verify/unit_test/fps/sparsity_boundary.test.cpp
  - verify/unit_test/fps/sparsity_performance.test.cpp
  - verify/unit_test/fps/sparsity_small_performance.test.cpp
  - verify/unit_test/fps/sum_of_polynomial.test.cpp
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
  - verify/yosupo_math/enumerate_bell_number.test.cpp
  - verify/yosupo_math/enumerate_stirling_number_of_the_first_kind.test.cpp
  - verify/yosupo_math/many_factrials.test.cpp
  - verify/yuki/yuki_1510.test.cpp
documentation_of: type_traits/fps.hpp
layout: document
---
