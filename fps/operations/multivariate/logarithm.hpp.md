---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  dependencies:
  - files:
    - filename: convolution.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution.hpp
    - filename: convolution_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/convolution_arb.hpp
    - filename: multi_convolution_truncated.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/multi_convolution_truncated.hpp
    - filename: multi_convolution_truncated_arb.hpp
      icon: LIBRARY_ALL_AC
      path: convolution/multi_convolution_truncated_arb.hpp
    - filename: fps_sparsity_detector.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_sparsity_detector.hpp
    - filename: inverse.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/inverse.hpp
    - filename: multiplication.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/multiplication.hpp
    - filename: butterfly.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/butterfly.hpp
    - filename: garner.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/garner.hpp
    - filename: inv.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/inv.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: mont.hpp
      icon: LIBRARY_ALL_AC
      path: modint/mont.hpp
    - filename: fps.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/fps.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
    - filename: io.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/io.hpp
    - filename: modint.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/modint.hpp
    type: Depends on
  - files:
    - filename: fps_multivariate.hpp
      icon: LIBRARY_ALL_AC
      path: fps/fps_multivariate.hpp
    - filename: exponential.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/exponential.hpp
    - filename: power.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/multivariate/power.hpp
    type: Required by
  - files:
    - filename: multivariate_convolution.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_convolution.test.cpp
    - filename: multivariate_operations.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/fps/multivariate_operations.test.cpp
    - filename: fps.test.cpp
      icon: TEST_ACCEPTED
      path: verify/unit_test/type_traits/fps/fps.test.cpp
    type: Verified with
  dependsOn:
  - convolution/convolution.hpp
  - convolution/convolution_arb.hpp
  - convolution/multi_convolution_truncated.hpp
  - convolution/multi_convolution_truncated_arb.hpp
  - fps/fps_sparsity_detector.hpp
  - fps/operations/multivariate/inverse.hpp
  - fps/operations/multivariate/multiplication.hpp
  - math_mod/butterfly.hpp
  - math_mod/garner.hpp
  - math_mod/inv.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - modint/mont.hpp
  - type_traits/fps.hpp
  - type_traits/integral.hpp
  - type_traits/io.hpp
  - type_traits/modint.hpp
  embedded:
  - code: "#ifndef KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP\n#define KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP\
      \ 1\n\n#include <cassert>\n\n#include \"../../../type_traits/fps.hpp\"\n#include\
      \ \"inverse.hpp\"\n\nnamespace kk2::fps::operations {\n\ntemplate <Multivariate\
      \ FPS> FPS dense_log(const FPS &f) {\n    using mint = typename FPS::value_type;\n\
      \    assert(!f.f.empty() && f.f[0] == mint(1));\n    FPS result = dense_mul(f.diff(),\
      \ dense_inv(f)).integral();\n    result.f.resize(f.f.size());\n    return result;\n\
      }\n\ntemplate <Multivariate FPS> FPS &inplace_dense_log(FPS &f) {\n    return\
      \ f = dense_log(std::as_const(f));\n}\n\ntemplate <Multivariate FPS> FPS sparse_log(const\
      \ FPS &f) {\n    using mint = typename FPS::value_type;\n    assert(!f.f.empty()\
      \ && f.f[0] == mint(1));\n    FPS result = sparse_mul(f.diff(), sparse_inv(f)).integral();\n\
      \    result.f.resize(f.f.size());\n    return result;\n}\n\ntemplate <Multivariate\
      \ FPS> FPS &inplace_sparse_log(FPS &f) {\n    return f = sparse_log(std::as_const(f));\n\
      }\n\ntemplate <Multivariate FPS> FPS log(const FPS &f) { return dense_log(f);\
      \ }\n\ntemplate <Multivariate FPS> FPS &inplace_log(FPS &f) { return inplace_dense_log(f);\
      \ }\n\n} // namespace kk2::fps::operations\n\n#endif // KK2_FPS_OPERATIONS_MULTIVARIATE_LOGARITHM_HPP\n"
    name: default
  - code: "#line 1 \"fps/operations/multivariate/logarithm.hpp\"\n\n\n\n#include <cassert>\n\
      \n#line 1 \"type_traits/fps.hpp\"\n\n\n\n#include <concepts>\n#include <ranges>\n\
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
      \n\n#line 1 \"fps/operations/multivariate/inverse.hpp\"\n\n\n\n#include <algorithm>\n\
      #line 7 \"fps/operations/multivariate/inverse.hpp\"\n#include <utility>\n#include\
      \ <vector>\n\n#line 1 \"fps/operations/multivariate/multiplication.hpp\"\n\n\
      \n\n#line 5 \"fps/operations/multivariate/multiplication.hpp\"\n\n#line 1 \"\
      convolution/multi_convolution_truncated.hpp\"\n\n\n\n#line 6 \"convolution/multi_convolution_truncated.hpp\"\
      \n\n#line 1 \"convolution/convolution.hpp\"\n\n\n\n#line 5 \"convolution/convolution.hpp\"\
      \n#include <memory>\n#line 8 \"convolution/convolution.hpp\"\n\n#line 1 \"fps/fps_sparsity_detector.hpp\"\
      \n\n\n\n#line 5 \"fps/fps_sparsity_detector.hpp\"\n#include <bit>\n#include\
      \ <cstdint>\n#line 9 \"fps/fps_sparsity_detector.hpp\"\n\nnamespace kk2 {\n\n\
      enum class FPSOperation {\n    CONVOLUTION,\n    LOG,\n    POWER,\n    DIVISION,\n\
      \    POLYNOMIAL_DIVISION,\n    INVERSE,\n    EXP,\n    SQRT\n};\n\nnamespace\
      \ fps::sparsity_detail {\n\n// E(n): the leading FFT evaluation cost, up to\
      \ the common field-operation\n// constant that cancels when dense and sparse\
      \ leading terms are compared.\ninline std::int64_t evaluation_work(int n) {\n\
      \    if (n <= 1) return 1;\n    const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n\
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
      \ is_ntt_friendly) * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 1 \"math_mod/butterfly.hpp\"\
      \n\n\n\n#line 6 \"math_mod/butterfly.hpp\"\n#include <cstddef>\n#line 8 \"math_mod/butterfly.hpp\"\
      \n\n#line 1 \"math_mod/primitive_root.hpp\"\n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\
      \n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\n\nnamespace kk2 {\n\ntemplate <class\
      \ S, class T, class U> constexpr S pow_mod(T x, U n, T m) {\n    assert(n >=\
      \ 0);\n    if (m == 1) return S(0);\n    S _m = m, r = 1;\n    S y = x % _m;\n\
      \    if (y < 0) y += _m;\n    while (n) {\n        if (n & 1) r = (r * y) %\
      \ _m;\n        if (n >>= 1) y = (y * y) % _m;\n    }\n    return r;\n}\n\n}\
      \ // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\n\nnamespace\
      \ kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n    if (m == 2)\
      \ return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049) return\
      \ 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return 3;\n\
      \    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0] =\
      \ 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x /=\
      \ 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x %\
      \ i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0) {\
      \ x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
      \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i <\
      \ cnt; i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) ==\
      \ 1) {\n                ok = false;\n                break;\n            }\n\
      \        }\n        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr\
      \ int primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\
      \n#line 10 \"math_mod/butterfly.hpp\"\n\nnamespace kk2 {\n\nnamespace detail\
      \ {\n\ntemplate <class mint> int butterfly_log_size(std::size_t n) {\n    assert((n\
      \ > 0 && (n & (n - 1)) == 0) && \"butterfly size must be a power of two\");\n\
      \    assert(n < (std::size_t{1} << 30) && \"butterfly size is too large\");\n\
      \    assert((static_cast<std::uintmax_t>(mint::getmod()) - 1) % n == 0\n   \
      \        && \"butterfly size is not supported by the modulus\");\n    return\
      \ __builtin_ctz(static_cast<unsigned int>(n));\n}\n\n} // namespace detail\n\
      \ntemplate <class FPS, class mint = typename FPS::value_type> void butterfly(FPS\
      \ &a) {\n    int h = detail::butterfly_log_size<mint>(a.size());\n    static\
      \ int g = primitive_root<mint::getmod()>;\n    static bool first = true;\n \
      \   static mint sum_e2[30]; // sum_e[i] = ies[0] * ... * ies[i - 1] * es[i]\n\
      \    static mint sum_e3[30];\n    static mint es[30], ies[30]; // es[i]^(2^(2+i))\
      \ == 1\n    if (first) {\n        first = false;\n        int cnt2 = __builtin_ctz(mint::getmod()\
      \ - 1);\n        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
      \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n  \
      \          es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n\
      \            ie *= ie;\n        }\n        mint now = 1;\n        for (int i\
      \ = 0; i <= cnt2 - 2; i++) {\n            sum_e2[i] = es[i] * now;\n       \
      \     now *= ies[i];\n        }\n        now = 1;\n        for (int i = 0; i\
      \ <= cnt2 - 3; i++) {\n            sum_e3[i] = es[i + 1] * now;\n          \
      \  now *= ies[i + 1];\n        }\n    }\n\n    int len = 0;\n    while (len\
      \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
      \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++)\
      \ {\n                int offset = s << (h - len);\n                for (int\
      \ i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n      \
      \              auto r = a[i + offset + p] * rot;\n                    a[i +\
      \ offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
      \         }\n                if (s + 1 != (1 << len)) rot *= sum_e2[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len++;\n        } else {\n        \
      \    int p = 1 << (h - len - 2);\n            mint rot = 1, imag = es[0];\n\
      \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
      \ = rot * rot;\n                mint rot3 = rot2 * rot;\n                int\
      \ offset = s << (h - len);\n                for (int i = 0; i < p; i++) {\n\
      \                    auto a0 = a[i + offset];\n                    auto a1 =\
      \ a[i + offset + p] * rot;\n                    auto a2 = a[i + offset + p *\
      \ 2] * rot2;\n                    auto a3 = a[i + offset + p * 3] * rot3;\n\
      \                    auto a1na3imag = (a1 - a3) * imag;\n                  \
      \  a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + p]\
      \ = a0 + a2 - a1 - a3;\n                    a[i + offset + p * 2] = a0 - a2\
      \ + a1na3imag;\n                    a[i + offset + p * 3] = a0 - a2 - a1na3imag;\n\
      \                }\n                if (s + 1 != (1 << len)) rot *= sum_e3[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n\
      template <class FPS, class mint = typename FPS::value_type> void butterfly_inv(FPS\
      \ &a) {\n    int n = int(a.size());\n    int h = detail::butterfly_log_size<mint>(a.size());\n\
      \    static constexpr int g = primitive_root<mint::getmod()>;\n    static bool\
      \ first = true;\n    static mint sum_ie2[30]; // sum_ie[i] = es[0] * ... * es[i\
      \ - 1] * ies[i]\n    static mint sum_ie3[30];\n    static mint es[30], ies[30];\
      \ // es[i]^(2^(2+i)) == 1\n    static mint invn[30];\n    if (first) {\n   \
      \     first = false;\n        int cnt2 = __builtin_ctz(mint::getmod() - 1);\n\
      \        mint e = mint(g).pow((mint::getmod() - 1) >> cnt2), ie = e.inv();\n\
      \        for (int i = cnt2; i >= 2; i--) {\n            // e^(2^i) == 1\n  \
      \          es[i - 2] = e;\n            ies[i - 2] = ie;\n            e *= e;\n\
      \            ie *= ie;\n        }\n        mint now = 1;\n        for (int i\
      \ = 0; i <= cnt2 - 2; i++) {\n            sum_ie2[i] = ies[i] * now;\n     \
      \       now *= es[i];\n        }\n        now = 1;\n        for (int i = 0;\
      \ i <= cnt2 - 3; i++) {\n            sum_ie3[i] = ies[i + 1] * now;\n      \
      \      now *= es[i + 1];\n        }\n\n        invn[0] = 1;\n        invn[1]\
      \ = mint::getmod() / 2 + 1;\n        for (int i = 2; i < 30; i++) invn[i] =\
      \ invn[i - 1] * invn[1];\n    }\n    int len = h;\n    while (len) {\n     \
      \   if (len == 1) {\n            int p = 1 << (h - len);\n            mint irot\
      \ = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n         \
      \       int offset = s << (h - len + 1);\n                for (int i = 0; i\
      \ < p; i++) {\n                    auto l = a[i + offset];\n               \
      \     auto r = a[i + offset + p];\n                    a[i + offset] = l + r;\n\
      \                    a[i + offset + p] = (l - r) * irot;\n                }\n\
      \                if (s + 1 != (1 << (len - 1))) irot *= sum_ie2[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len--;\n        } else {\n        \
      \    int p = 1 << (h - len);\n            mint irot = 1, iimag = ies[0];\n \
      \           for (int s = 0; s < (1 << ((len - 2))); s++) {\n               \
      \ mint irot2 = irot * irot;\n                mint irot3 = irot2 * irot;\n  \
      \              int offset = s << (h - len + 2);\n                for (int i\
      \ = 0; i < p; i++) {\n                    auto a0 = a[i + offset];\n       \
      \             auto a1 = a[i + offset + p];\n                    auto a2 = a[i\
      \ + offset + p * 2];\n                    auto a3 = a[i + offset + p * 3];\n\
      \                    auto a2na3iimag = (a2 - a3) * iimag;\n\n              \
      \      a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset\
      \ + p] = (a0 - a1 + a2na3iimag) * irot;\n                    a[i + offset +\
      \ p * 2] = (a0 + a1 - a2 - a3) * irot2;\n                    a[i + offset +\
      \ p * 3] = (a0 - a1 - a2na3iimag) * irot3;\n                }\n            \
      \    if (s + 1 != (1 << (len - 2))) irot *= sum_ie3[__builtin_ctz(~(unsigned\
      \ int)(s))];\n            }\n            len -= 2;\n        }\n    }\n\n   \
      \ for (int i = 0; i < n; i++) a[i] *= invn[h];\n}\n\ntemplate <class FPS, class\
      \ mint = typename FPS::value_type> void doubling(FPS &a) {\n    int n = a.size();\n\
      \    detail::butterfly_log_size<mint>(a.size() * 2);\n    auto b = a;\n    int\
      \ z = 1;\n    butterfly_inv(b);\n    mint r = 1, zeta = mint(primitive_root<mint::getmod()>).pow((mint::getmod()\
      \ - 1) / (n << 1));\n    for (int i = 0; i < n; i++) {\n        b[i] *= r;\n\
      \        r *= zeta;\n    }\n    butterfly(b);\n    std::copy(b.begin(), b.end(),\
      \ std::back_inserter(a));\n}\n\n} // namespace kk2\n\n\n#line 11 \"convolution/convolution.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS &inplace_sparse_convolution(FPS &a, const FPS &b, int deg = -1) {\n    const\
      \ int original_a_size = a.size(), original_b_size = b.size();\n    if (!original_a_size\
      \ || !original_b_size) {\n        a.clear();\n        return a;\n    }\n   \
      \ if (deg == -1) deg = original_a_size + original_b_size - 1;\n    const int\
      \ target = std::min(std::max(0, deg), original_a_size + original_b_size - 1);\n\
      \    if (target == 0) {\n        a.clear();\n        return a;\n    }\n\n  \
      \  std::vector<std::pair<int, mint>> support_b;\n    for (int i = 0; i < std::min(original_b_size,\
      \ target); ++i) {\n        if (b[i] != mint(0)) support_b.emplace_back(i, b[i]);\n\
      \    }\n    a.resize(target);\n    for (int i = std::min(original_a_size, target)\
      \ - 1; i >= 0; --i) {\n        const mint coefficient = a[i];\n        a[i]\
      \ = mint(0);\n        if (coefficient == mint(0)) continue;\n        for (const\
      \ auto &[j, b_j] : support_b) {\n            if (i + j >= target) break;\n \
      \           a[i + j] += coefficient * b_j;\n        }\n    }\n    return a;\n\
      }\n\ntemplate <class FPS> FPS sparse_convolution(const FPS &a, const FPS &b,\
      \ int deg = -1) {\n    FPS result = a;\n    inplace_sparse_convolution(result,\
      \ b, deg);\n    return result;\n}\n\ntemplate <class FPS> FPS &inplace_dense_convolution(FPS\
      \ &a, const FPS &b, int deg = -1) {\n    const int original_a_size = a.size(),\
      \ original_b_size = b.size();\n    if (!original_a_size || !original_b_size)\
      \ {\n        a.clear();\n        return a;\n    }\n    if (deg == -1) deg =\
      \ original_a_size + original_b_size - 1;\n    const int target = std::min(std::max(0,\
      \ deg), original_a_size + original_b_size - 1);\n    if (target == 0) {\n  \
      \      a.clear();\n        return a;\n    }\n\n    const int n = std::min(original_a_size,\
      \ target);\n    const int m = std::min(original_b_size, target);\n\n    int\
      \ z = 1;\n    while (z < n + m - 1) z <<= 1;\n    if (std::addressof(a) == std::addressof(b))\
      \ {\n        a.resize(n);\n        a.resize(z);\n        butterfly(a);\n   \
      \     for (int i = 0; i < z; i++) a[i] *= a[i];\n    } else {\n        a.resize(n);\n\
      \        a.resize(z);\n        butterfly(a);\n        FPS t(b.begin(), b.begin()\
      \ + m);\n        t.resize(z);\n        butterfly(t);\n        for (int i = 0;\
      \ i < z; i++) a[i] *= t[i];\n    }\n    butterfly_inv(a);\n    a.resize(target);\n\
      \    return a;\n}\n\ntemplate <class FPS> FPS dense_convolution(const FPS &a,\
      \ const FPS &b, int deg = -1) {\n    FPS result = a;\n    inplace_dense_convolution(result,\
      \ b, deg);\n    return result;\n}\n\ntemplate <class FPS> FPS &inplace_convolution(FPS\
      \ &a, const FPS &b, int deg = -1) {\n    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION,\
      \ true, a, b, deg);\n    if (use_sparse) return inplace_sparse_convolution(a,\
      \ b, deg);\n    return inplace_dense_convolution(a, b, deg);\n}\n\ntemplate\
      \ <class FPS> FPS convolution(const FPS &a, const FPS &b, int deg = -1) {\n\
      \    if (is_sparse_operation(FPSOperation::CONVOLUTION, true, a, b, deg))\n\
      \        return sparse_convolution(a, b, deg);\n    return dense_convolution(a,\
      \ b, deg);\n}\n\n} // namespace kk2\n\n\n#line 8 \"convolution/multi_convolution_truncated.hpp\"\
      \n\nnamespace kk2 {\n\n// reference: https://rushcheyo.blog.uoj.ac/blog/6547\n\
      // \u65E5\u672C\u8A9E:\n// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
      namespace detail {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS &inplace_multi_convolution_truncated_ntt(FPS &a, const FPS &b, const std::vector<int>\
      \ &base) {\n    int n = int(a.size());\n    if (!n) return a;\n    int k = base.size();\n\
      \    if (!k) return inplace_convolution(a, b);\n    // chi[i] = \\sum_{j} \\\
      floor(i / (base[0]...base[j]))\n    std::vector<int> chi(n, 0);\n    for (int\
      \ i = 0; i < n; i++) {\n        int x = i;\n        for (int j = 0; j < k -\
      \ 1; j++) chi[i] += (x /= base[j]);\n        chi[i] %= k;\n    }\n    int z\
      \ = 1;\n    while (z < 2 * n - 1) z <<= 1;\n    std::vector<FPS> f(k, FPS(z));\n\
      \    std::vector<FPS> g(k, FPS(z));\n    for (int i = 0; i < n; i++) f[chi[i]][i]\
      \ = a[i], g[chi[i]][i] = b[i];\n    for (auto &x : f) butterfly(x);\n    for\
      \ (auto &x : g) butterfly(x);\n    std::vector<mint> tmp(k);\n    for (int ii\
      \ = 0; ii < z; ii++) {\n        for (int i = 0; i < k; i++) {\n            for\
      \ (int j = 0; j < k; j++) {\n                tmp[i + j - (i + j >= k ? k : 0)]\
      \ += f[i][ii] * g[j][ii];\n            }\n        }\n        for (int i = 0;\
      \ i < k; i++) f[i][ii] = tmp[i], tmp[i] = mint{0};\n    }\n    for (auto &x\
      \ : f) butterfly_inv(x);\n    for (int i = 0; i < n; i++) a[i] = f[chi[i]][i];\n\
      \    return a;\n}\n\n} // namespace detail\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nFPS &inplace_multi_convolution_truncated(FPS\
      \ &a, const FPS &b, const std::vector<int> &base) {\n    return detail::inplace_multi_convolution_truncated_ntt(a,\
      \ b, base);\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS &inplace_multi_convolution_truncated_sparse(FPS &a,\n                  \
      \                              const FPS &b,\n                             \
      \                   const std::vector<int> &base) {\n    const int n = int(a.size());\n\
      \    if (!n) return a;\n    if (base.empty()) {\n        a[0] *= b[0];\n   \
      \     return a;\n    }\n\n    std::vector<std::pair<int, mint>> support_b;\n\
      \    for (int j = 0; j < n; ++j) {\n        if (b[j] != mint(0)) support_b.emplace_back(j,\
      \ b[j]);\n    }\n\n    // The mixed-radix index is an order extension of the\
      \ coordinate-wise\n    // order. Therefore contributions from an input index\
      \ i only go to indices\n    // at least i. Processing source indices in descending\
      \ order preserves the\n    // original value of a[i], while propagating it directly\
      \ into the output.\n    std::vector<int> lhs_index(base.size());\n    for (int\
      \ i = n - 1; i >= 0; --i) {\n        const mint coefficient = a[i];\n      \
      \  a[i] = mint(0);\n        if (coefficient == mint(0)) continue;\n\n      \
      \  int x = i;\n        for (int d = 0; d < (int)base.size(); ++d) {\n      \
      \      lhs_index[d] = x % base[d];\n            x /= base[d];\n        }\n\n\
      \        for (const auto &[j, b_j] : support_b) {\n            int y = j, index\
      \ = 0, stride = 1;\n            bool in_range = true;\n            for (int\
      \ d = 0; d < (int)base.size(); ++d) {\n                const int coordinate\
      \ = lhs_index[d] + y % base[d];\n                y /= base[d];\n           \
      \     if (coordinate >= base[d]) {\n                    in_range = false;\n\
      \                    break;\n                }\n                index += coordinate\
      \ * stride;\n                stride *= base[d];\n            }\n           \
      \ if (in_range && index < n) a[index] += coefficient * b_j;\n        }\n   \
      \ }\n    return a;\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS multi_convolution_truncated(const FPS &a, const FPS &b, const std::vector<int>\
      \ &base) {\n    FPS result = a;\n    inplace_multi_convolution_truncated<FPS,\
      \ mint>(result, b, base);\n    return result;\n}\n\n} // namespace kk2\n\n\n\
      #line 1 \"convolution/multi_convolution_truncated_arb.hpp\"\n\n\n\n#line 5 \"\
      convolution/multi_convolution_truncated_arb.hpp\"\n\n#line 1 \"convolution/convolution_arb.hpp\"\
      \n\n\n\n#line 6 \"convolution/convolution_arb.hpp\"\n\n#line 1 \"math_mod/garner.hpp\"\
      \n\n\n\n#line 6 \"math_mod/garner.hpp\"\n\n#line 1 \"math_mod/inv.hpp\"\n\n\n\
      \n#line 5 \"math_mod/inv.hpp\"\n\nnamespace kk2 {\n\n// require: modulo >= 1\n\
      template <class T> constexpr T mod_inversion(T a, T modulo) {\n    a %= modulo;\n\
      \    if (a < 0) a += modulo;\n    T s = modulo, t = a;\n    T m0 = 0, m1 = 1;\n\
      \    while (t) {\n        T u = s / t;\n        std::swap(s -= t * u, t);\n\
      \        std::swap(m0 -= m1 * u, m1);\n    }\n    if (m0 < 0) m0 += modulo;\n\
      \    return m0;\n}\n\n} // namespace kk2\n\n\n#line 8 \"math_mod/garner.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class T> T garner(const std::vector<T> &d,\
      \ const std::vector<T> &p) {\n    assert(d.size() + 1 == p.size());\n    int\
      \ nm = d.size();\n    std::vector<T> kp(nm + 1, 0), rmult(nm + 1, 1);\n    for\
      \ (int ii = 0; ii < nm; ii++) {\n        T x = (d[ii] - kp[ii]) * mod_inversion(rmult[ii],\
      \ p[ii]) % p[ii];\n        if (x < 0) x += p[ii];\n        for (int iii = ii\
      \ + 1; iii < nm + 1; iii++) {\n            kp[iii] = (kp[iii] + rmult[iii] *\
      \ x) % p[iii];\n            rmult[iii] = (rmult[iii] * p[ii]) % p[iii];\n  \
      \      }\n    }\n    return kp[nm];\n}\n\n} // namespace kk2\n\n\n#line 1 \"\
      modint/mont.hpp\"\n\n\n\n#line 6 \"modint/mont.hpp\"\n#include <iostream>\n\
      #line 8 \"modint/mont.hpp\"\n\n#line 1 \"type_traits/io.hpp\"\n\n\n\n#line 5\
      \ \"type_traits/io.hpp\"\n#include <fstream>\n#include <istream>\n#include <ostream>\n\
      #line 9 \"type_traits/io.hpp\"\n\nnamespace kk2 {\n\nnamespace type_traits {\n\
      \nstruct istream_tag {};\nstruct ostream_tag {};\n\n} // namespace type_traits\n\
      \ntemplate <typename T>\nusing is_standard_istream = typename std::conditional<std::is_same<T,\
      \ std::istream>::value\n                                                   \
      \       || std::is_same<T, std::ifstream>::value,\n                        \
      \                              std::true_type,\n                           \
      \                           std::false_type>::type;\ntemplate <typename T>\n\
      using is_standard_ostream = typename std::conditional<std::is_same<T, std::ostream>::value\n\
      \                                                          || std::is_same<T,\
      \ std::ofstream>::value,\n                                                 \
      \     std::true_type,\n                                                    \
      \  std::false_type>::type;\ntemplate <typename T> using is_user_defined_istream\
      \ = std::is_base_of<type_traits::istream_tag, T>;\ntemplate <typename T> using\
      \ is_user_defined_ostream = std::is_base_of<type_traits::ostream_tag, T>;\n\n\
      template <typename T>\nusing is_istream =\n    typename std::conditional<is_standard_istream<T>::value\
      \ || is_user_defined_istream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T>\nusing is_ostream =\n    typename std::conditional<is_standard_ostream<T>::value\
      \ || is_user_defined_ostream<T>::value,\n                              std::true_type,\n\
      \                              std::false_type>::type;\n\ntemplate <typename\
      \ T> using is_istream_t = std::enable_if_t<is_istream<T>::value>;\ntemplate\
      \ <typename T> using is_ostream_t = std::enable_if_t<is_ostream<T>::value>;\n\
      \ntemplate <class T>\nconcept StandardInputStream = is_standard_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept StandardOutputStream = is_standard_ostream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept InputStream = is_istream<std::remove_cvref_t<T>>::value;\n\
      \ntemplate <class T>\nconcept OutputStream = is_ostream<std::remove_cvref_t<T>>::value;\n\
      \n} // namespace kk2\n\n\n#line 11 \"modint/mont.hpp\"\n\nnamespace kk2 {\n\n\
      template <int p> struct LazyMontgomeryModInt {\n    using mint = LazyMontgomeryModInt;\n\
      \    using i32 = int32_t;\n    using i64 = int64_t;\n    using u32 = uint32_t;\n\
      \    using u64 = uint64_t;\n\n    static constexpr u32 get_r() {\n        u32\
      \ ret = p;\n        for (int i = 0; i < 4; ++i) ret *= 2 - p * ret;\n      \
      \  return ret;\n    }\n\n    static constexpr u32 r = get_r();\n    static constexpr\
      \ u32 n2 = -u64(p) % p;\n    static_assert(r * p == 1, \"invalid, r * p != 1\"\
      );\n    static_assert(p < (1 << 30), \"invalid, p >= 2 ^ 30\");\n    static_assert((p\
      \ & 1) == 1, \"invalid, p % 2 == 0\");\n\n    u32 _v;\n\n    constexpr LazyMontgomeryModInt()\
      \ : _v(0) {}\n\n    template <Integral T> constexpr LazyMontgomeryModInt(T b)\
      \ : _v(reduce(u64(b % p + p) * n2)) {}\n\n    static constexpr u32 reduce(const\
      \ u64 &b) { return (b + u64(u32(b) * u32(-r)) * p) >> 32; }\n    constexpr mint\
      \ &operator++() { return *this += 1; }\n    constexpr mint &operator--() { return\
      \ *this -= 1; }\n\n    constexpr mint operator++(int) {\n        mint ret =\
      \ *this;\n        *this += 1;\n        return ret;\n    }\n\n    constexpr mint\
      \ operator--(int) {\n        mint ret = *this;\n        *this -= 1;\n      \
      \  return ret;\n    }\n\n    constexpr mint &operator+=(const mint &b) {\n \
      \       if (i32(_v += b._v - 2 * p) < 0) _v += 2 * p;\n        return *this;\n\
      \    }\n\n    constexpr mint &operator-=(const mint &b) {\n        if (i32(_v\
      \ -= b._v) < 0) _v += 2 * p;\n        return *this;\n    }\n\n    constexpr\
      \ mint &operator*=(const mint &b) {\n        _v = reduce(u64(_v) * b._v);\n\
      \        return *this;\n    }\n\n    constexpr mint &operator/=(const mint &b)\
      \ {\n        *this *= b.inv();\n        return *this;\n    }\n\n\n    constexpr\
      \ bool operator==(const mint &b) const {\n        return (_v >= p ? _v - p :\
      \ _v) == (b._v >= p ? b._v - p : b._v);\n    }\n\n    constexpr bool operator!=(const\
      \ mint &b) const {\n        return (_v >= p ? _v - p : _v) != (b._v >= p ? b._v\
      \ - p : b._v);\n    }\n\n    constexpr mint operator-() const { return mint()\
      \ - mint(*this); }\n    constexpr mint operator+() const { return mint(*this);\
      \ }\n    friend constexpr mint operator+(const mint &a, const mint &b) { return\
      \ mint(a) += b; }\n    friend constexpr mint operator-(const mint &a, const\
      \ mint &b) { return mint(a) -= b; }\n    friend constexpr mint operator*(const\
      \ mint &a, const mint &b) { return mint(a) *= b; }\n    friend constexpr mint\
      \ operator/(const mint &a, const mint &b) { return mint(a) /= b; }\n\n    template\
      \ <class T> constexpr mint pow(T n) const {\n        mint ret(1), mul(*this);\n\
      \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            if\
      \ (n >>= 1) mul *= mul;\n        }\n        return ret;\n    }\n\n    constexpr\
      \ mint inv() const {\n        assert(*this != mint(0));\n        return pow(p\
      \ - 2);\n    }\n\n    template <OutputStream OStream> friend OStream &operator<<(OStream\
      \ &os, const mint &x) {\n        return os << x.val();\n    }\n\n    template\
      \ <InputStream IStream> friend IStream &operator>>(IStream &is, mint &x) {\n\
      \        i64 t;\n        is >> t;\n        x = mint(t);\n        return (is);\n\
      \    }\n\n    constexpr u32 val() const {\n        u32 ret = reduce(_v);\n \
      \       return ret >= p ? ret - p : ret;\n    }\n\n    static constexpr u32\
      \ getmod() { return p; }\n};\n\ntemplate <int p> using Mont = LazyMontgomeryModInt<p>;\n\
      \nusing mont998 = Mont<998244353>;\nusing mont107 = Mont<1000000007>;\n\n} //\
      \ namespace kk2\n\n\n#line 10 \"convolution/convolution_arb.hpp\"\n\nnamespace\
      \ kk2 {\n\ntemplate <class FPS, class mint = typename FPS::value_type>\nFPS\
      \ &inplace_dense_convolution_arb(FPS &a, const FPS &b, int deg = -1) {\n   \
      \ const int original_a_size = a.size(), original_b_size = b.size();\n    if\
      \ (!original_a_size || !original_b_size) {\n        a.clear();\n        return\
      \ a;\n    }\n    if (deg == -1) deg = original_a_size + original_b_size - 1;\n\
      \    const int target = std::min(std::max(0, deg), original_a_size + original_b_size\
      \ - 1);\n    if (target == 0) {\n        a.clear();\n        return a;\n   \
      \ }\n    const int n = std::min(original_a_size, target);\n    const int m =\
      \ std::min(original_b_size, target);\n    static constexpr long long MOD1 =\
      \ 754974721; // 2^24\n    static constexpr long long MOD2 = 167772161; // 2^25\n\
      \    static constexpr long long MOD3 = 469762049; // 2^26\n    using mint1 =\
      \ LazyMontgomeryModInt<MOD1>;\n    using mint2 = LazyMontgomeryModInt<MOD2>;\n\
      \    using mint3 = LazyMontgomeryModInt<MOD3>;\n\n    std::vector<long long>\
      \ a0(n), b0(m);\n    for (int i = 0; i < n; i++) a0[i] = a[i].val();\n    for\
      \ (int i = 0; i < m; i++) b0[i] = b[i].val();\n    auto a1 = std::vector<mint1>(a0.begin(),\
      \ a0.end());\n    auto b1 = std::vector<mint1>(b0.begin(), b0.end());\n    inplace_dense_convolution(a1,\
      \ b1, target);\n    auto a2 = std::vector<mint2>(a0.begin(), a0.end());\n  \
      \  auto b2 = std::vector<mint2>(b0.begin(), b0.end());\n    inplace_dense_convolution(a2,\
      \ b2, target);\n    auto a3 = std::vector<mint3>(a0.begin(), a0.end());\n  \
      \  auto b3 = std::vector<mint3>(b0.begin(), b0.end());\n    inplace_dense_convolution(a3,\
      \ b3, target);\n    const std::vector<long long> ps = {MOD1, MOD2, MOD3, mint::getmod()};\n\
      \    a.resize(target);\n    for (int i = 0; i < target; i++) {\n        a[i]\
      \ = mint(garner({a1[i].val(), a2[i].val(), a3[i].val()}, ps));\n    }\n    return\
      \ a;\n}\n\ntemplate <class FPS> FPS dense_convolution_arb(const FPS &a, const\
      \ FPS &b, int deg = -1) {\n    FPS result = a;\n    inplace_dense_convolution_arb(result,\
      \ b, deg);\n    return result;\n}\n\ntemplate <class FPS> FPS sparse_convolution_arb(const\
      \ FPS &a, const FPS &b, int deg = -1) {\n    return sparse_convolution(a, b,\
      \ deg);\n}\n\ntemplate <class FPS> FPS &inplace_sparse_convolution_arb(FPS &a,\
      \ const FPS &b, int deg = -1) {\n    return inplace_sparse_convolution(a, b,\
      \ deg);\n}\n\ntemplate <class FPS> FPS &inplace_convolution_arb(FPS &a, const\
      \ FPS &b, int deg = -1) {\n    const bool use_sparse = is_sparse_operation(FPSOperation::CONVOLUTION,\
      \ false, a, b, deg);\n    if (use_sparse) return inplace_sparse_convolution_arb(a,\
      \ b, deg);\n    return inplace_dense_convolution_arb(a, b, deg);\n}\n\ntemplate\
      \ <class FPS> FPS convolution_arb(const FPS &a, const FPS &b, int deg = -1)\
      \ {\n    if (is_sparse_operation(FPSOperation::CONVOLUTION, false, a, b, deg))\n\
      \        return sparse_convolution_arb(a, b, deg);\n    return dense_convolution_arb(a,\
      \ b, deg);\n}\n\n} // namespace kk2\n\n\n#line 8 \"convolution/multi_convolution_truncated_arb.hpp\"\
      \n\nnamespace kk2 {\n\nnamespace detail {\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nFPS &inplace_multi_convolution_truncated_arb_impl(FPS\
      \ &a,\n                                                  const FPS &b,\n   \
      \                                               const std::vector<int> &base)\
      \ {\n    const int n = int(a.size());\n    if (!n) return a;\n    const int\
      \ k = base.size();\n    if (!k) return inplace_convolution_arb(a, b);\n\n  \
      \  // The class index records carries between mixed-radix coordinates. Without\n\
      \    // an NTT over the flattened index, convolve every pair of classes and\
      \ keep\n    // the class corresponding to the resulting carry.\n    std::vector<int>\
      \ chi(n, 0);\n    for (int i = 0; i < n; i++) {\n        int x = i;\n      \
      \  for (int j = 0; j < k - 1; j++) chi[i] += (x /= base[j]);\n        chi[i]\
      \ %= k;\n    }\n\n    std::vector<FPS> f(k, FPS(n)), g(k, FPS(n)), result(k,\
      \ FPS(n));\n    for (int i = 0; i < n; i++) {\n        f[chi[i]][i] = a[i];\n\
      \        g[chi[i]][i] = b[i];\n    }\n    for (int i = 0; i < k; i++) {\n  \
      \      for (int j = 0; j < k; j++) {\n            FPS product = dense_convolution_arb(f[i],\
      \ g[j], n);\n            FPS &target = result[(i + j) % k];\n            for\
      \ (int p = 0; p < static_cast<int>(product.size()); p++) target[p] += product[p];\n\
      \        }\n    }\n    for (int i = 0; i < n; i++) a[i] = result[chi[i]][i];\n\
      \    return a;\n}\n\n} // namespace detail\n\ntemplate <class FPS, class mint\
      \ = typename FPS::value_type>\nFPS &inplace_multi_convolution_truncated_arb(FPS\
      \ &a, const FPS &b, const std::vector<int> &base) {\n    return detail::inplace_multi_convolution_truncated_arb_impl(a,\
      \ b, base);\n}\n\ntemplate <class FPS, class mint = typename FPS::value_type>\n\
      FPS multi_convolution_truncated_arb(const FPS &a, const FPS &b, const std::vector<int>\
      \ &base) {\n    FPS result = a;\n    inplace_multi_convolution_truncated_arb(result,\
      \ b, base);\n    return result;\n}\n\n} // namespace kk2\n\n\n#line 9 \"fps/operations/multivariate/multiplication.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <Multivariate FPS> FPS &inplace_dense_mul(FPS\
      \ &lhs, const FPS &rhs) {\n    assert(lhs.base == rhs.base && lhs.f.size() ==\
      \ rhs.f.size());\n    if constexpr (ArbitraryModulusFormalPowerSeries<typename\
      \ FPS::fps>) {\n        inplace_multi_convolution_truncated_arb(lhs.f, rhs.f,\
      \ lhs.base);\n    } else {\n        inplace_multi_convolution_truncated(lhs.f,\
      \ rhs.f, lhs.base);\n    }\n    return lhs;\n}\n\ntemplate <Multivariate FPS>\
      \ FPS dense_mul(const FPS &lhs, const FPS &rhs) {\n    FPS result = lhs;\n \
      \   return inplace_dense_mul(result, rhs);\n}\n\ntemplate <Multivariate FPS>\
      \ FPS &inplace_sparse_mul(FPS &lhs, const FPS &rhs) {\n    assert(lhs.base ==\
      \ rhs.base && lhs.f.size() == rhs.f.size());\n    inplace_multi_convolution_truncated_sparse(lhs.f,\
      \ rhs.f, lhs.base);\n    return lhs;\n}\n\ntemplate <Multivariate FPS> FPS sparse_mul(const\
      \ FPS &lhs, const FPS &rhs) {\n    FPS result = lhs;\n    return inplace_sparse_mul(result,\
      \ rhs);\n}\n\ntemplate <Multivariate FPS> FPS mul(const FPS &lhs, const FPS\
      \ &rhs) { return dense_mul(lhs, rhs); }\n\ntemplate <Multivariate FPS> FPS &inplace_mul(FPS\
      \ &lhs, const FPS &rhs) {\n    return inplace_dense_mul(lhs, rhs);\n}\n\n} //\
      \ namespace kk2::fps::operations\n\n\n#line 12 \"fps/operations/multivariate/inverse.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <Multivariate FPS> FPS dense_inv(const\
      \ FPS &f) {\n    using mint = typename FPS::value_type;\n    using fps_type\
      \ = typename FPS::fps;\n    assert(!f.f.empty() && f.f[0] != mint(0));\n   \
      \ if (f.base.empty()) return FPS(f.base, fps_type{f.f[0].inv()});\n\n    if\
      \ constexpr (ArbitraryModulusFormalPowerSeries<fps_type>) {\n        const int\
      \ n = f.f.size();\n        FPS result(f.base, fps_type(n));\n        result.f[0]\
      \ = f.f[0].inv();\n        for (int d = 1; d < n; d <<= 1) {\n            const\
      \ int precision = std::min(2 * d, n);\n            FPS lhs(f.base, fps_type(precision));\n\
      \            FPS rhs(f.base, fps_type(precision));\n            std::copy_n(f.f.begin(),\
      \ precision, lhs.f.begin());\n            std::copy_n(result.f.begin(), std::min(d,\
      \ precision), rhs.f.begin());\n\n            FPS correction(f.base, fps_type(precision));\n\
      \            correction += mint(2);\n            correction -= dense_mul(lhs,\
      \ rhs);\n            inplace_dense_mul(rhs, correction);\n            std::copy(rhs.f.begin()\
      \ + d, rhs.f.end(), result.f.begin() + d);\n        }\n        return result;\n\
      \    }\n\n    const int n = f.f.size(), k = f.base.size();\n    int z = 1;\n\
      \    while (z < 2 * n - 1) z <<= 1;\n    std::vector<int> chi(z);\n    for (int\
      \ i = 0; i < n; i++) {\n        int x = i;\n        for (int j = 0; j < k -\
      \ 1; j++) chi[i] += (x /= f.base[j]);\n        chi[i] %= k;\n    }\n    auto\
      \ naive_and_dot = [&k](const std::vector<fps_type> &a,\n                   \
      \           const std::vector<fps_type> &b,\n                              std::vector<fps_type>\
      \ &c) -> void {\n        std::vector<mint> tmp(k);\n        for (int ii = 0;\
      \ ii < static_cast<int>(a[0].size()); ii++) {\n            for (int i = 0; i\
      \ < k; i++) {\n                for (int j = 0; j < k; j++) {\n             \
      \       tmp[i + j - (i + j >= k ? k : 0)] += a[i][ii] * b[j][ii];\n        \
      \        }\n            }\n            for (int i = 0; i < k; i++) c[i][ii]\
      \ = tmp[i], tmp[i] = mint{0};\n        }\n    };\n\n    // Reference: https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp\n\
      \    // Let g_k := f_k^{-1} mod x^k, deg g_k < k. Then\n    // g_1 = f_0^{-1},\
      \ g_{2k} = 2g_k - g_k^2 f mod x^{2k}.\n    fps_type g(z);\n    g[0] = f.f[0].inv();\n\
      \    for (int d = 1; d < n; d <<= 1) {\n        std::vector<fps_type> a(k, fps_type(2\
      \ * d)), b(k, fps_type(2 * d)), c(k, fps_type(2 * d));\n        for (int i =\
      \ 0; i < std::min(n, 2 * d); i++) a[chi[i]][i] = f.f[i];\n        for (int i\
      \ = 0; i < d; i++) b[chi[i]][i] = g[i];\n        for (auto &x : a) x.but();\n\
      \        for (auto &x : b) x.but();\n        naive_and_dot(a, b, c);\n     \
      \   for (auto &x : c) x.ibut();\n\n        for (auto &x : a) std::ranges::fill(x,\
      \ mint(0));\n        for (int i = d; i < 2 * d; i++) a[chi[i]][i] = c[chi[i]][i];\n\
      \        for (auto &x : a) x.but();\n        naive_and_dot(a, b, c);\n     \
      \   for (auto &x : c) x.ibut();\n        for (int i = d; i < 2 * d; i++) g[i]\
      \ = -c[chi[i]][i];\n    }\n    FPS result = f;\n    result.f = fps_type(std::begin(g),\
      \ std::begin(g) + n);\n    return result;\n}\n\ntemplate <Multivariate FPS>\
      \ FPS &inplace_dense_inv(FPS &f) {\n    return f = dense_inv(std::as_const(f));\n\
      }\n\ntemplate <Multivariate FPS> FPS sparse_inv(const FPS &f) {\n    using mint\
      \ = typename FPS::value_type;\n    assert(!f.f.empty() && f.f[0] != mint(0));\n\
      \    const int n = f.f.size();\n    FPS result(f.base, typename FPS::fps(n));\n\
      \    result.f[0] = f.f[0].inv();\n    for (int i = 1; i < n; ++i) {\n      \
      \  int x = i;\n        std::vector<int> target(f.base.size());\n        for\
      \ (int d = 0; d < static_cast<int>(f.base.size()); ++d) {\n            target[d]\
      \ = x % f.base[d];\n            x /= f.base[d];\n        }\n\n        mint coefficient\
      \ = 0;\n        for (int j = 1; j < n; ++j) {\n            if (f.f[j] == mint(0))\
      \ continue;\n            int y = j, complement = 0, stride = 1;\n          \
      \  bool in_range = true;\n            for (int d = 0; d < static_cast<int>(f.base.size());\
      \ ++d) {\n                const int coordinate = y % f.base[d];\n          \
      \      y /= f.base[d];\n                if (coordinate > target[d]) {\n    \
      \                in_range = false;\n                    break;\n           \
      \     }\n                complement += (target[d] - coordinate) * stride;\n\
      \                stride *= f.base[d];\n            }\n            if (in_range)\
      \ coefficient += f.f[j] * result.f[complement];\n        }\n        result.f[i]\
      \ = -coefficient * result.f[0];\n    }\n    return result;\n}\n\ntemplate <Multivariate\
      \ FPS> FPS &inplace_sparse_inv(FPS &f) {\n    return f = sparse_inv(std::as_const(f));\n\
      }\n\ntemplate <Multivariate FPS> FPS inv(const FPS &f) { return dense_inv(f);\
      \ }\n\ntemplate <Multivariate FPS> FPS &inplace_inv(FPS &f) { return inplace_dense_inv(f);\
      \ }\n\n} // namespace kk2::fps::operations\n\n\n#line 8 \"fps/operations/multivariate/logarithm.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <Multivariate FPS> FPS dense_log(const\
      \ FPS &f) {\n    using mint = typename FPS::value_type;\n    assert(!f.f.empty()\
      \ && f.f[0] == mint(1));\n    FPS result = dense_mul(f.diff(), dense_inv(f)).integral();\n\
      \    result.f.resize(f.f.size());\n    return result;\n}\n\ntemplate <Multivariate\
      \ FPS> FPS &inplace_dense_log(FPS &f) {\n    return f = dense_log(std::as_const(f));\n\
      }\n\ntemplate <Multivariate FPS> FPS sparse_log(const FPS &f) {\n    using mint\
      \ = typename FPS::value_type;\n    assert(!f.f.empty() && f.f[0] == mint(1));\n\
      \    FPS result = sparse_mul(f.diff(), sparse_inv(f)).integral();\n    result.f.resize(f.f.size());\n\
      \    return result;\n}\n\ntemplate <Multivariate FPS> FPS &inplace_sparse_log(FPS\
      \ &f) {\n    return f = sparse_log(std::as_const(f));\n}\n\ntemplate <Multivariate\
      \ FPS> FPS log(const FPS &f) { return dense_log(f); }\n\ntemplate <Multivariate\
      \ FPS> FPS &inplace_log(FPS &f) { return inplace_dense_log(f); }\n\n} // namespace\
      \ kk2::fps::operations\n\n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/operations/multivariate/logarithm.hpp
  pathExtension: hpp
  requiredBy:
  - fps/fps_multivariate.hpp
  - fps/operations/multivariate/exponential.hpp
  - fps/operations/multivariate/power.hpp
  timestamp: '2026-10-03 23:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/fps/multivariate_convolution.test.cpp
  - verify/unit_test/fps/multivariate_operations.test.cpp
  - verify/unit_test/type_traits/fps/fps.test.cpp
documentation_of: fps/operations/multivariate/logarithm.hpp
layout: document
---
