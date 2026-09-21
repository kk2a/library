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
    - filename: power.hpp
      icon: LIBRARY_ALL_AC
      path: fps/operations/power.hpp
    - filename: mod_sqrt.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/detail/mod_sqrt.hpp
    - filename: pow_mod.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/pow_mod.hpp
    - filename: primitive_root.hpp
      icon: LIBRARY_ALL_AC
      path: math_mod/primitive_root.hpp
    - filename: fps.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/fps.hpp
    - filename: integral.hpp
      icon: LIBRARY_ALL_AC
      path: type_traits/integral.hpp
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
  - fps/operations/power.hpp
  - math_mod/detail/mod_sqrt.hpp
  - math_mod/pow_mod.hpp
  - math_mod/primitive_root.hpp
  - type_traits/fps.hpp
  - type_traits/integral.hpp
  embedded:
  - code: "#ifndef KK2_FPS_OPERATIONS_SQRT_HPP\n#define KK2_FPS_OPERATIONS_SQRT_HPP\
      \ 1\n\n#include <cassert>\n#include <utility>\n\n#include \"../../math_mod/detail/mod_sqrt.hpp\"\
      \n#include \"../../type_traits/fps.hpp\"\n#include \"../fps_sparsity_detector.hpp\"\
      \n#include \"power.hpp\"\n\nnamespace kk2::fps::operations {\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS dense_sqrt(const FPS &f, int precision = -1) {\n    using mint =\
      \ typename FPS::value_type;\n    if (precision == -1) precision = static_cast<int>(f.size());\n\
      \    if (f.empty()) return FPS(precision, mint(0));\n    if (f[0] == mint(0))\
      \ {\n        for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n      \
      \      if (f[i] == mint(0)) continue;\n            if (i & 1) return {};\n \
      \           if (precision - i / 2 <= 0) break;\n            FPS result = dense_sqrt(f\
      \ >> i, precision - i / 2);\n            if (result.empty()) return {};\n  \
      \          result <<= i / 2;\n            if (static_cast<int>(result.size())\
      \ < precision) result.resize(precision, mint(0));\n            return result;\n\
      \        }\n        return FPS(precision, mint(0));\n    }\n\n    const long\
      \ long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) return {};\n    assert(root * root % mint::getmod() ==\
      \ f[0].val());\n    FPS result{mint(root)};\n    const mint inverse_two = mint(2).inv();\n\
      \    for (int d = 1; d < precision; d <<= 1) {\n        result = (result + f.pre(d\
      \ << 1).dense_mul(result.dense_inv(d << 1))) * inverse_two;\n    }\n    return\
      \ result.pre(precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS\
      \ &inplace_dense_sqrt(FPS &f, int precision = -1) {\n    if (precision == -1)\
      \ precision = static_cast<int>(f.size());\n    return f = dense_sqrt(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  if (precision == -1) precision = static_cast<int>(f.size());\n    if (f.empty())\
      \ {\n        f.assign(precision, mint(0));\n        return f;\n    }\n    if\
      \ (f[0] == mint(0)) {\n        for (int i = 1; i < static_cast<int>(f.size());\
      \ ++i) {\n            if (f[i] == mint(0)) continue;\n            if (i & 1)\
      \ {\n                f.clear();\n                return f;\n            }\n\
      \            if (precision - i / 2 <= 0) break;\n            f >>= i;\n    \
      \        inplace_sparse_sqrt(f, precision - i / 2);\n            if (f.empty())\
      \ return f;\n            f <<= i / 2;\n            if (static_cast<int>(f.size())\
      \ < precision) f.resize(precision, mint(0));\n            return f;\n      \
      \  }\n        f.assign(precision, mint(0));\n        return f;\n    }\n\n  \
      \  const long long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) {\n        f.clear();\n        return f;\n    }\n    return\
      \ inplace_sparse_pow(f, (mint::getmod() + 1) >> 1, precision) *= mint(root).inv();\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sparse_sqrt(const FPS &f,\
      \ int precision = -1) {\n    FPS result = f;\n    return inplace_sparse_sqrt(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sqrt(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    if (!f.empty() && f[0] != mint(0)\n        && is_sparse_operation(\n  \
      \          FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_sqrt(f, precision);\n    return dense_sqrt(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  const bool use_sparse =\n        !f.empty() && f[0] != mint(0)\n        &&\
      \ is_sparse_operation(\n            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>,\
      \ f, FPS(), precision);\n    if (use_sparse) return inplace_sparse_sqrt(f, precision);\n\
      \    return inplace_dense_sqrt(f, precision);\n}\n\n} // namespace kk2::fps::operations\n\
      \n#endif // KK2_FPS_OPERATIONS_SQRT_HPP\n"
    name: default
  - code: "#line 1 \"fps/operations/sqrt.hpp\"\n\n\n\n#include <cassert>\n#include\
      \ <utility>\n\n#line 1 \"math_mod/detail/mod_sqrt.hpp\"\n\n\n\n#line 1 \"math_mod/primitive_root.hpp\"\
      \n\n\n\n#line 1 \"math_mod/pow_mod.hpp\"\n\n\n\n#line 5 \"math_mod/pow_mod.hpp\"\
      \n\nnamespace kk2 {\n\ntemplate <class S, class T, class U> constexpr S pow_mod(T\
      \ x, U n, T m) {\n    assert(n >= 0);\n    if (m == 1) return S(0);\n    S _m\
      \ = m, r = 1;\n    S y = x % _m;\n    if (y < 0) y += _m;\n    while (n) {\n\
      \        if (n & 1) r = (r * y) % _m;\n        if (n >>= 1) y = (y * y) % _m;\n\
      \    }\n    return r;\n}\n\n} // namespace kk2\n\n\n#line 5 \"math_mod/primitive_root.hpp\"\
      \n\nnamespace kk2 {\n\nconstexpr int primitive_root_constexpr(int m) {\n   \
      \ if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
      \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
      \ 3;\n    if (m == 1107296257) return 10;\n    int divs[20] = {};\n    divs[0]\
      \ = 2;\n    int cnt = 1;\n    int x = (m - 1) / 2;\n    while (x % 2 == 0) x\
      \ /= 2;\n    for (int i = 3; (long long)(i)*i <= x; i += 2) {\n        if (x\
      \ % i == 0) {\n            divs[cnt++] = i;\n            while (x % i == 0)\
      \ { x /= i; }\n        }\n    }\n    if (x > 1) { divs[cnt++] = x; }\n    for\
      \ (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i <\
      \ cnt; i++) {\n            if (pow_mod<long long>(g, (m - 1) / divs[i], m) ==\
      \ 1) {\n                ok = false;\n                break;\n            }\n\
      \        }\n        if (ok) return g;\n    }\n}\n\ntemplate <int m> static constexpr\
      \ int primitive_root = primitive_root_constexpr(m);\n\n} // namespace kk2\n\n\
      \n#line 5 \"math_mod/detail/mod_sqrt.hpp\"\n\nnamespace kk2::mod_sqrt_detail\
      \ {\n\ntemplate <class Mint> long long tonelli_shanks(const Mint &a, Mint z,\
      \ long long m, long long e) {\n    Mint x = a.pow((m - 1) / 2);\n    Mint y\
      \ = a * x * x;\n    x *= a;\n    while (y != Mint(1)) {\n        long long j\
      \ = 0;\n        Mint t = y;\n        while (t != Mint(1)) {\n            j++;\n\
      \            t *= t;\n        }\n        z = z.pow(1LL << (e - j - 1));\n  \
      \      x *= z;\n        z *= z;\n        y *= z;\n        e = j;\n    }\n  \
      \  return x.val();\n}\n\ntemplate <bool ntt_friendly = false, class mint> long\
      \ long mod_sqrt(const mint &a) {\n    const auto p = mint::getmod();\n    if\
      \ (a.val() < 2) return a.val();\n\n    // Euler's criterion\n    if (a.pow((p\
      \ - 1) / 2) != mint(1)) return -1;\n\n    mint b;\n    if constexpr (ntt_friendly)\
      \ {\n        b = primitive_root<mint::getmod()>;\n    } else {\n        // Find\
      \ a quadratic non-residue.\n        b = 1;\n        while (b.pow((p - 1) / 2)\
      \ == mint(1)) b += 1;\n    }\n\n    long long m = p - 1, e = 0;\n    while (m\
      \ % 2 == 0) m >>= 1, e++;\n\n    mint z = b.pow(m);\n    return tonelli_shanks(a,\
      \ z, m, e);\n}\n\n} // namespace kk2::mod_sqrt_detail\n\n\n#line 1 \"type_traits/fps.hpp\"\
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
      #include <algorithm>\n#include <bit>\n#include <cstdint>\n#include <memory>\n\
      #line 9 \"fps/fps_sparsity_detector.hpp\"\n\nnamespace kk2 {\n\nenum class FPSOperation\
      \ {\n    CONVOLUTION,\n    LOG,\n    POWER,\n    DIVISION,\n    POLYNOMIAL_DIVISION,\n\
      \    INVERSE,\n    EXP,\n    SQRT\n};\n\nnamespace fps::sparsity_detail {\n\n\
      // E(n): the leading FFT evaluation cost, up to the common field-operation\n\
      // constant that cancels when dense and sparse leading terms are compared.\n\
      inline std::int64_t evaluation_work(int n) {\n    if (n <= 1) return 1;\n  \
      \  const unsigned z = std::bit_ceil(static_cast<unsigned>(n));\n    return static_cast<std::int64_t>(z)\
      \ * std::countr_zero(z);\n}\n\ninline int transform_size(int n, int m) {\n \
      \   if (n <= 0 || m <= 0) return 0;\n    return static_cast<int>(std::bit_ceil(static_cast<unsigned>(n\
      \ + m - 1)));\n}\n\ninline std::int64_t\nconvolution_dense_work(int n, int m,\
      \ int precision, bool same, bool ntt_friendly) {\n    n = std::min(n, precision);\n\
      \    m = std::min(m, precision);\n    const int z = transform_size(n, m);\n\
      \    if (z == 0) return 0;\n\n    // A different pair needs two forward and\
      \ one inverse transform. Squaring\n    // reuses the forward transform and needs\
      \ only one forward transform.\n    const int transforms = same ? 2 : 3;\n  \
      \  // Arbitrary-modulus convolution uses three NTT-friendly moduli.\n    const\
      \ int moduli = ntt_friendly ? 1 : 3;\n    return static_cast<std::int64_t>(transforms)\
      \ * moduli * evaluation_work(z);\n}\n\ninline std::int64_t inverse_dense_work(int\
      \ precision, bool ntt_friendly) {\n    if (precision <= 1) return 0;\n    const\
      \ int z = static_cast<int>(std::bit_ceil(static_cast<unsigned>(precision)));\n\
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
      \ is_ntt_friendly) * sparse_work;\n}\n\n} // namespace kk2\n\n\n#line 1 \"fps/operations/power.hpp\"\
      \n\n\n\n#include <tuple>\n#include <vector>\n\n#line 1 \"type_traits/integral.hpp\"\
      \n\n\n\n#line 5 \"type_traits/integral.hpp\"\n\nnamespace kk2 {\n\n#ifndef _MSC_VER\n\
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
      \n} // namespace kk2\n\n\n#line 10 \"fps/operations/power.hpp\"\n\nnamespace\
      \ kk2::fps::operations {\n\nstruct PowerPreprocessResult {\n    int precision;\n\
      \    int normalized_precision;\n    int shift;\n    bool finished;\n};\n\ntemplate\
      \ <UnivariateFormalPowerSeries FPS, Integral T>\nPowerPreprocessResult inplace_power_preprocess(FPS\
      \ &f, T exponent, int precision) {\n    using mint = typename FPS::value_type;\n\
      \    if (precision == -1) precision = static_cast<int>(f.size());\n    if (exponent\
      \ == 0) {\n        f.assign(precision, mint(0));\n        if (precision > 0)\
      \ f[0] = mint(1);\n        return {precision, 0, 0, true};\n    }\n\n    int\
      \ leading_zeros = 0;\n    while (leading_zeros != static_cast<int>(f.size())\
      \ && f[leading_zeros] == mint(0))\n        ++leading_zeros;\n    if (leading_zeros\
      \ == static_cast<int>(f.size())\n        || __int128_t(leading_zeros) * exponent\
      \ >= precision) {\n        f.assign(precision, mint(0));\n        return {precision,\
      \ 0, 0, true};\n    }\n\n    const int shift = static_cast<int>(__int128_t(leading_zeros)\
      \ * exponent);\n    if (leading_zeros > 0) f.erase(f.begin(), f.begin() + leading_zeros);\n\
      \    return {precision, precision - shift, shift, false};\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS>\nFPS &inplace_power_postprocess(FPS &f, const PowerPreprocessResult &preprocessed)\
      \ {\n    using mint = typename FPS::value_type;\n    if (preprocessed.shift\
      \ > 0) f.insert(f.begin(), preprocessed.shift, mint(0));\n    f.resize(preprocessed.precision);\n\
      \    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\n\
      FPS &inplace_dense_pow_normalized(FPS &f, T exponent, int precision) {\n   \
      \ const auto leading_coefficient = f[0];\n    f *= leading_coefficient.inv();\n\
      \    f.inplace_dense_log(precision);\n    f *= exponent;\n    f.inplace_dense_exp(precision);\n\
      \    f *= leading_coefficient.pow(exponent);\n    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS &inplace_sparse_pow_normalized(FPS &f, T exponent, int\
      \ precision) {\n    using mint = typename FPS::value_type;\n    const int mod\
      \ = mint::getmod();\n    static std::vector<mint> inverse{1, 1};\n    while\
      \ (static_cast<int>(inverse.size()) <= precision) {\n        const int i = inverse.size();\n\
      \        inverse.push_back(-inverse[mod % i] * (mod / i));\n    }\n\n    const\
      \ mint constant_term = f[0].pow(exponent);\n    exponent %= mod;\n    std::vector<std::tuple<int,\
      \ mint, mint>> support;\n    for (int i = 1; i < static_cast<int>(f.size());\
      \ ++i) {\n        if (f[i] != mint(0)) support.emplace_back(i, f[i], f[i] *\
      \ mint(i) * (exponent + 1));\n    }\n\n    const mint constant_inv = f[0].inv();\n\
      \    f.assign(precision, mint(0));\n    f[0] = constant_term;\n    for (int\
      \ degree = 1; degree < precision; ++degree) {\n        for (const auto &[index,\
      \ coefficient, weighted_coefficient] : support) {\n            if (degree <\
      \ index) break;\n            f[degree] += f[degree - index] * (weighted_coefficient\
      \ - coefficient * degree);\n        }\n        f[degree] *= constant_inv * inverse[degree];\n\
      \    }\n    return f;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS>\nbool\
      \ power_uses_sparse(const FPS &normalized, int normalized_precision) {\n   \
      \ return is_sparse_operation(FPSOperation::POWER,\n                        \
      \       NTTFriendlyFormalPowerSeries<FPS>,\n                               normalized,\n\
      \                               FPS(),\n                               normalized_precision);\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\nFPS &inplace_dense_pow(FPS\
      \ &f, T exponent, int precision = -1) {\n    const PowerPreprocessResult preprocessed\
      \ = inplace_power_preprocess(f, exponent, precision);\n    if (preprocessed.finished)\
      \ return f;\n    inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    return inplace_power_postprocess(f, preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS dense_pow(const FPS &f, T exponent, int precision =\
      \ -1) {\n    FPS result = f;\n    inplace_dense_pow(result, exponent, precision);\n\
      \    return result;\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral\
      \ T>\nFPS &inplace_sparse_pow(FPS &f, T exponent, int precision = -1) {\n  \
      \  const PowerPreprocessResult preprocessed = inplace_power_preprocess(f, exponent,\
      \ precision);\n    if (preprocessed.finished) return f;\n    inplace_sparse_pow_normalized(f,\
      \ exponent, preprocessed.normalized_precision);\n    return inplace_power_postprocess(f,\
      \ preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\n\
      FPS sparse_pow(const FPS &f, T exponent, int precision = -1) {\n    FPS result\
      \ = f;\n    inplace_sparse_pow(result, exponent, precision);\n    return result;\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS, Integral T>\nFPS &inplace_pow(FPS\
      \ &f, T exponent, int precision = -1) {\n    const PowerPreprocessResult preprocessed\
      \ = inplace_power_preprocess(f, exponent, precision);\n    if (preprocessed.finished)\
      \ return f;\n    if (power_uses_sparse(f, preprocessed.normalized_precision))\n\
      \        inplace_sparse_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    else inplace_dense_pow_normalized(f, exponent, preprocessed.normalized_precision);\n\
      \    return inplace_power_postprocess(f, preprocessed);\n}\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS, Integral T>\nFPS pow(const FPS &f, T exponent, int precision = -1) {\n\
      \    FPS result = f;\n    inplace_pow(result, exponent, precision);\n    return\
      \ result;\n}\n\n} // namespace kk2::fps::operations\n\n\n#line 11 \"fps/operations/sqrt.hpp\"\
      \n\nnamespace kk2::fps::operations {\n\ntemplate <UnivariateFormalPowerSeries\
      \ FPS> FPS dense_sqrt(const FPS &f, int precision = -1) {\n    using mint =\
      \ typename FPS::value_type;\n    if (precision == -1) precision = static_cast<int>(f.size());\n\
      \    if (f.empty()) return FPS(precision, mint(0));\n    if (f[0] == mint(0))\
      \ {\n        for (int i = 1; i < static_cast<int>(f.size()); ++i) {\n      \
      \      if (f[i] == mint(0)) continue;\n            if (i & 1) return {};\n \
      \           if (precision - i / 2 <= 0) break;\n            FPS result = dense_sqrt(f\
      \ >> i, precision - i / 2);\n            if (result.empty()) return {};\n  \
      \          result <<= i / 2;\n            if (static_cast<int>(result.size())\
      \ < precision) result.resize(precision, mint(0));\n            return result;\n\
      \        }\n        return FPS(precision, mint(0));\n    }\n\n    const long\
      \ long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) return {};\n    assert(root * root % mint::getmod() ==\
      \ f[0].val());\n    FPS result{mint(root)};\n    const mint inverse_two = mint(2).inv();\n\
      \    for (int d = 1; d < precision; d <<= 1) {\n        result = (result + f.pre(d\
      \ << 1).dense_mul(result.dense_inv(d << 1))) * inverse_two;\n    }\n    return\
      \ result.pre(precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS\
      \ &inplace_dense_sqrt(FPS &f, int precision = -1) {\n    if (precision == -1)\
      \ precision = static_cast<int>(f.size());\n    return f = dense_sqrt(std::as_const(f),\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sparse_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  if (precision == -1) precision = static_cast<int>(f.size());\n    if (f.empty())\
      \ {\n        f.assign(precision, mint(0));\n        return f;\n    }\n    if\
      \ (f[0] == mint(0)) {\n        for (int i = 1; i < static_cast<int>(f.size());\
      \ ++i) {\n            if (f[i] == mint(0)) continue;\n            if (i & 1)\
      \ {\n                f.clear();\n                return f;\n            }\n\
      \            if (precision - i / 2 <= 0) break;\n            f >>= i;\n    \
      \        inplace_sparse_sqrt(f, precision - i / 2);\n            if (f.empty())\
      \ return f;\n            f <<= i / 2;\n            if (static_cast<int>(f.size())\
      \ < precision) f.resize(precision, mint(0));\n            return f;\n      \
      \  }\n        f.assign(precision, mint(0));\n        return f;\n    }\n\n  \
      \  const long long root = mod_sqrt_detail::mod_sqrt<NTTFriendlyFormalPowerSeries<FPS>>(f[0]);\n\
      \    if (root == -1) {\n        f.clear();\n        return f;\n    }\n    return\
      \ inplace_sparse_pow(f, (mint::getmod() + 1) >> 1, precision) *= mint(root).inv();\n\
      }\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sparse_sqrt(const FPS &f,\
      \ int precision = -1) {\n    FPS result = f;\n    return inplace_sparse_sqrt(result,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS sqrt(const\
      \ FPS &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n\
      \    if (!f.empty() && f[0] != mint(0)\n        && is_sparse_operation(\n  \
      \          FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>, f, FPS(),\
      \ precision))\n        return sparse_sqrt(f, precision);\n    return dense_sqrt(f,\
      \ precision);\n}\n\ntemplate <UnivariateFormalPowerSeries FPS> FPS &inplace_sqrt(FPS\
      \ &f, int precision = -1) {\n    using mint = typename FPS::value_type;\n  \
      \  const bool use_sparse =\n        !f.empty() && f[0] != mint(0)\n        &&\
      \ is_sparse_operation(\n            FPSOperation::SQRT, NTTFriendlyFormalPowerSeries<FPS>,\
      \ f, FPS(), precision);\n    if (use_sparse) return inplace_sparse_sqrt(f, precision);\n\
      \    return inplace_dense_sqrt(f, precision);\n}\n\n} // namespace kk2::fps::operations\n\
      \n\n"
    name: bundled
  isFailed: false
  isVerificationFile: false
  path: fps/operations/sqrt.hpp
  pathExtension: hpp
  requiredBy:
  - fps/fps_arb.hpp
  - fps/fps_base.hpp
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
documentation_of: fps/operations/sqrt.hpp
layout: document
---
